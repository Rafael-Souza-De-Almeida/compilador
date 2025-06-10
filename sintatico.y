%{
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include<vector>
#include <fstream>


//usar /n do lexico e uma variavel global de numero da linha incrementar quando paarecer /n 

#define YYSTYPE atributos

using namespace std;


int var_temp_qnt;
int linha;

struct atributos {
    string label;
    string traducao;
    string tipo;
};

struct Simbolo {
    string nome_interno;
    string tipo;
    string temp_associada;
    // string escopo;
};

vector<map<string, Simbolo>> pilha_escopos;
map<string, string> temporarias;

vector<Simbolo> simbolos_declarados;
int var_user_qnt;

int yylex(void);
void yyerror(string);
void entra_escopo();
void sai_escopo();
void verifica_tipo_relacional(string tipo1, string tipo2);
string gentempcode(string);
string adiciona_variavel_na_tabela(string, string, string);
string pega_variavel_na_tabela(string);
string resolve_tipo(string, string);
string fim_if();
string fim_else();
void ver_boolean(string ,string);
void verifica_tipo(string, string, string);
tuple<string, string, string> resolve_coercao(string, string, string);
string getTipo(string);
string getTempId(string);
%}

%token TK_NUM TK_REAL TK_TRUE TK_FALSE
%token TK_MAIN TK_ID TK_FUNCTION
%token TK_INT TK_FLOAT  TK_CHAR TK_BOOLEAN
%token TK_FIM TK_ERROR
%token TK_MAIOR TK_MAIORIGUAL TK_MENOR TK_MENORIGUAL TK_IGUALDADE TK_DIFERENTE
%token  TK_E TK_OU TK_NEGATIVO
%token TK_PRINT TK_PRINTLN
%token TK_IF TK_ELSE TK_FOR TK_WHILE TK_DO TK_SWITCH
%token TK_CONTINUE TK_BREAK

%start S

%left '+' '-'
%left '*' '/' 
%left TK_OU
%left TK_E
%right TK_NEGATIVO

%%

S           : TK_FUNCTION TK_MAIN '(' ')' BLOCO
            {
                string codigo = "/* Compilador hahaha */\n"
                                "#include <iostream>\n"
                                "#include <string.h>\n"
                                "#include <stdio.h>\n"
                                "using namespace std; \n"
                                "int main(void) {\n";
                
                
                for(auto iterador : temporarias) {
                    if(iterador.second == "boolean") {
                        codigo += "\tint " + iterador.first + ";\n";
                        continue;
                    }
                    codigo += "\t" + iterador.second + " " + iterador.first + ";\n";
                 }


               for (auto& simbolo : simbolos_declarados) {
                if (simbolo.tipo == "boolean") {
                    codigo += "\tint " + simbolo.nome_interno + ";\n";
                } else {
                    codigo += "\t" + simbolo.tipo + " " + simbolo.nome_interno + ";\n";
                }
            }

                codigo += $5.traducao;
                codigo += "\treturn 0;"
                          "\n}";

                cout << codigo << endl;
            
                string nome_arquivo = "teste.cpp";

                ofstream arquivo(nome_arquivo, ios::out | ios::trunc);

                if (!arquivo.is_open()) {
                    std::cerr << "Erro ao abrir o arquivo." << std::endl;
                    return 1;
                }

                arquivo << codigo;

                arquivo.close();

            }
            ;

BLOCO       : '{' {entra_escopo();} COMANDOS '}'{ sai_escopo();
            
                $$.traducao = $3.traducao;
            }
            ;

COMANDOS    : COMANDO COMANDOS
            {
                $$.traducao = $1.traducao + $2.traducao;
            }
            |
            {
                $$.traducao = "";
            }
            ;
COMANDO     : E ';'
            {
                $$ = $1;
            }
            | TK_PRINT '(' E ')' ';' {
                $$.traducao = $1.traducao + $3.traducao +  "\t cout << "  + $3.label + ";\n";
            }
            | TK_PRINTLN '(' E ')' ';' {
                $$.traducao = $1.traducao + $3.traducao +  "\t cout << "  + $3.label + " << endl;\n";
            }
           /*  | TK_BREAK{
                string rotulo = get_rotulo_fim_laco();
                $$.traducao = "\tgoto " + rotulo + ";\n";
            }  */
            | BLOCO {
                $$.traducao = $1.traducao;
            }
            | TK_IF '(' E ')' BLOCO{
                if($3.tipo!="boolean"){
                    
                    yyerror("No If deve ser operando boolean");
                    $$.traducao = "";
                    exit(1);
                }
                else {
                string rotulo_if = fim_if();

                $$.traducao = $3.traducao;  
                $$.traducao += "if (!" + $3.label + ") goto " + rotulo_if + ";\n";
                $$.traducao += $5.traducao; 
                $$.traducao += rotulo_if + ":\n";
                }
            }
            | TK_IF '(' E ')' BLOCO TK_ELSE BLOCO{
                if($3.tipo!="boolean"){
                    yyerror("No if-else deve ser operando boolean");
                    $$.traducao = "";
                }
                else {
                    string rotulo_if = fim_if();
                    string rotulo_else = fim_else();

                    $$.traducao = $3.traducao;
                    $$.traducao += "if (!" + $3.label + ") goto "+ rotulo_else + ";\n";
                    $$.traducao+= $5.traducao;
                    $$.traducao += "goto " + rotulo_if +";\n";
                    $$.traducao += rotulo_else + ":\n";
                    $$.traducao += $7.traducao;
                    $$.traducao += rotulo_if + ":\n";

                }
            }

E           : E '+' E
            {
                string tipo = resolve_tipo($1.tipo, $3.tipo);
                auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, tipo);
                $$.label = gentempcode(tipo);
                $$.tipo = tipo;
                $$.traducao = $1.traducao + $3.traducao + coercoes + "\t" + $$.label + " = " + t1 + " + " + t2 + ";\n";
            }
            | E '-' E 
            {   
                /* cout<<"Operation subtraction"<<endl; */
                string tipo = resolve_tipo($1.tipo, $3.tipo);
                auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, tipo);
                $$.label = gentempcode(tipo);
                $$.tipo = tipo;
                $$.traducao = $1.traducao + $3.traducao + coercoes + "\t" + $$.label + " = " + t1 + " - " + t2 + ";\n";
            }
            | E '*' E
            {   
               /*  cout <<"Operation multiplication"<<endl; */
                string tipo = resolve_tipo($1.tipo, $3.tipo);
                auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, tipo);
                $$.label = gentempcode(tipo);
                $$.tipo = tipo;
                $$.traducao = $1.traducao + $3.traducao + coercoes + "\t" + $$.label + " = " + t1 + " * " + t2 + ";\n";
            }
            | E '/' E
            {   
              /*   cout <<"Operation division"<<endl; */
                string tipo = resolve_tipo($1.tipo, $3.tipo);
                auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, tipo);
                $$.label = gentempcode(tipo);
                $$.tipo = tipo;
                $$.traducao = $1.traducao + $3.traducao + coercoes + "\t" + $$.label + " = " + t1 + " / " + t2 + ";\n";
            }
            |  '(' E ')'
            {
                /* cout <<"Operation parenteses"<<endl; */
                $$.label = $2.label;
                $$.tipo = $2.tipo;
                $$.traducao = $2.traducao;
            }
            |  E TK_MAIOR E
            {
                verifica_tipo_relacional($1.tipo, $3.tipo);
                string tipo = resolve_tipo($1.tipo,$3.tipo);
                auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, tipo);
                $$.label=gentempcode(tipo);
                $$.tipo = "boolean";
                $$.traducao = $1.traducao + $3.traducao + coercoes + "\t" + $$.label + "= " + $1.label + ">" +  $3.label + ";\n";  

            }
            |  E TK_MAIORIGUAL E
            {
                verifica_tipo_relacional($1.tipo, $3.tipo);
                string tipo = resolve_tipo($1.tipo,$3.tipo);
                auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, tipo);
                $$.label=gentempcode(tipo);
                $$.tipo = "boolean";
                $$.traducao = $1.traducao + $3.traducao + coercoes + "\t" + $$.label + "= " + $1.label + ">=" +  $3.label + ";\n";  

            }
            |  E TK_MENOR E
            {
                verifica_tipo_relacional($1.tipo, $3.tipo);
                string tipo = resolve_tipo($1.tipo,$3.tipo);
                auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, tipo); 
                $$.label=gentempcode(tipo);
                $$.tipo = "boolean";
                $$.traducao = $1.traducao + $3.traducao + coercoes + "\t" + $$.label + "= " + $1.label + "<" +  $3.label + ";\n";  

            }
            |  E TK_MENORIGUAL E
            {
                  verifica_tipo_relacional($1.tipo, $3.tipo);
                string tipo = resolve_tipo($1.tipo,$3.tipo);
                 auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, tipo);
                $$.label=gentempcode(tipo);
                $$.tipo = "boolean";
                $$.traducao = $1.traducao + $3.traducao + coercoes + "\t" + $$.label + "= " + $1.label + "<=" +  $3.label + ";\n";  

            }
            |  E TK_IGUALDADE E
            {
                ver_boolean($1.tipo,$3.tipo);
                string tipo = resolve_tipo($1.tipo,$3.tipo);
                auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, tipo);
                $$.label=gentempcode(tipo);
                $$.tipo = "boolean";
                $$.traducao = $1.traducao + $3.traducao + coercoes + "\t" + $$.label + "= " + $1.label + "==" +  $3.label + ";\n";  

            }
            |  E TK_DIFERENTE E
            {
                ver_boolean($1.tipo,$3.tipo);
                string tipo = resolve_tipo($1.tipo,$3.tipo);
                auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, tipo);
                $$.label=gentempcode(tipo);
                $$.tipo = "boolean";
                $$.traducao = $1.traducao + $3.traducao + coercoes + "\t" + $$.label + "= " + $1.label + "!=" +  $3.label + ";\n";  

            }
            |  E  TK_OU E
            {
                verifica_tipo($1.tipo,"boolean","Operando esquerdo deve ser do tipo boolean");
                verifica_tipo($3.tipo,"boolean","Operando direita deve ser boolean");

                string tipo = "boolean";
                $$.label=gentempcode(tipo);
                $$.tipo = tipo;
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + "= " + $1.label + "||" +  $3.label + ";\n";  

            }
             |  E TK_E E
            {
                verifica_tipo($1.tipo,"boolean","Operando esquerdo deve ser boolean");
                verifica_tipo($3.tipo,"boolean","Operando direita deve ser boolean");

                string tipo = "boolean";
                $$.label=gentempcode(tipo);
                $$.tipo = tipo;
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + "= " + $1.label + "&&" +  $3.label + ";\n";  

            }
            |   TK_NEGATIVO E
            {
                verifica_tipo($2.tipo,"boolean","Operando esquerdo deve ser boolean");
                

                string tipo = "boolean";
                $$.label=gentempcode(tipo);
                $$.tipo=tipo;
                $$.traducao = $2.traducao + "\t" + $$.label + "= !" + $2.label + ";\n"; 

            }

            |  TK_ID '=' E
            {
                string nome_variavel = pega_variavel_na_tabela($1.label);
                string tipo_var = getTipo($1.label);
                verifica_tipo(tipo_var, $3.tipo, "atribuição incompatível!");
                $$.traducao = $1.traducao + $3.traducao + "\t" + nome_variavel + " = " + $3.label + ";\n";
            } 
            | TK_INT TK_ID '=' E
            {

                
                string nome_interno = adiciona_variavel_na_tabela($2.label, "int", $4.label);
                $$.traducao = $2.traducao + $4.traducao + "\t" + nome_interno + " = " + $4.label + ";\n";
            }
            | TK_FLOAT TK_ID '=' E
            {   
                
                string nome_interno = adiciona_variavel_na_tabela( $2.label, "float", $4.label);
                $$.traducao = $2.traducao + $4.traducao + "\t" + nome_interno + " = " + $4.label + ";\n";
            }
            | TK_CHAR TK_ID '=' E
            {
                
                string nome_interno = adiciona_variavel_na_tabela($2.label,"char", $4.label);
                $$.traducao = $2.traducao + $4.traducao + "\t" + nome_interno + "=" + $4.label + ";\n";
            }
            | TK_BOOLEAN TK_ID '=' E
            {
                string nome_interno = adiciona_variavel_na_tabela( $2.label, "boolean", $4.label);

                $$.traducao = $2.traducao + $4.traducao + "\t" + nome_interno + " = " + $4.label + ";\n";
            }
            | TK_NUM
            {
                $$.label = gentempcode("int");
                $$.tipo = "int";
                $$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
            }
            | TK_REAL
            {
                $$.label = gentempcode("float");
                $$.tipo = "float";
                $$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
            }
            | TK_TRUE
            {
                $$.label = gentempcode("boolean");
                $$.tipo = "boolean";
                $$.traducao = "\t" + $$.label + " = " + "1" + ";\n";
            }
            | TK_FALSE
            {
                $$.label = gentempcode("boolean");
                $$.tipo = "boolean";
                $$.traducao = "\t" + $$.label + " = " + "0" + ";\n";
            }
            | TK_ID
            {   
                string tipo = getTipo($1.label); 
                $$.tipo=tipo;
                $$.label = gentempcode(tipo);
                string nome_interno = pega_variavel_na_tabela($1.label);
                $$.traducao = "\t" + $$.label + " = " + nome_interno + ";\n";
            }
            | TK_CHAR 
            {
                $$.label = gentempcode("char");
                $$.tipo = "char";
                $$.traducao = "\t" + $$.label + " = " + $1.label  + ";\n";

            }
            | TK_INT TK_ID
            {   
                string nome_interno = adiciona_variavel_na_tabela($2.label, "int", "");
                $$.traducao = "";
            }
            | TK_FLOAT TK_ID
            {   
               
                string nome_interno = adiciona_variavel_na_tabela( $2.label, "float", "");
                $$.traducao = "";
            }
            | TK_CHAR TK_ID
            {
                string nome_interno = adiciona_variavel_na_tabela($2.label,"char", "");
                $$.traducao = "";

            }
            | TK_BOOLEAN TK_ID
            {   
                string nome_interno = adiciona_variavel_na_tabela($2.label, "boolean", "");

                $$.traducao = "";
            }
            | '('TK_INT')' TK_ID
            {  
                string tipo_atual = getTipo($4.label);
                string novo_tipo = "int";
                $$.label = gentempcode(novo_tipo);
                $$.tipo = novo_tipo;
                string nome_interno = pega_variavel_na_tabela($4.label);
                $$.traducao = "\t" + $$.label + " = " + "(" + novo_tipo + ")" + " " + nome_interno + ";\n";
            }
            | '('TK_FLOAT')' TK_ID
            {  
                string tipo_atual = getTipo($4.label);
                string novo_tipo = "float";
                $$.label = gentempcode(novo_tipo);
                $$.tipo = novo_tipo;
                string nome_interno = pega_variavel_na_tabela($4.label);
                $$.traducao = "\t" + $$.label + " = " + "(" + novo_tipo + ")" + " " + nome_interno + ";\n";
            }
            | '('TK_BOOLEAN')' TK_ID
            {  
                yyerror("Erro na linha " + to_string(linha) + ": não é possível transformar a variável em boolean!");
            }
            ;             
            ;
%%

#include "lex.yy.c"

int yyparse();


string gentempcode(string tipo) {
    var_temp_qnt++;
    string temp = "t" + to_string(var_temp_qnt); 
    temporarias[temp] = tipo;
    return temp;
}

string getTipo(string nome_interno) {
       for (auto it = pilha_escopos.rbegin(); it != pilha_escopos.rend(); ++it) {
        if (it->count(nome_interno)) {
            return it->at(nome_interno).tipo;
        }
    }
    yyerror("Erro na linha " + to_string(linha) + ": variável '" + nome_interno + "' não declarada ");
    return "";
}

string getTempId(string variavel) {
       for (auto it = pilha_escopos.rbegin(); it != pilha_escopos.rend(); ++it) {
        if (it->count(variavel)) {
            return it->at(variavel).temp_associada;
        }
    }
    yyerror("Erro na linha " + to_string(linha) + ": variável '" + variavel + "' não declarada.");
    return "";
}


void verifica_tipo_relacional(string tipo1, string tipo2) {
    if (tipo1 == "boolean" || tipo2 == "boolean") {
        yyerror("Erro na linha " + to_string(linha) + ": não é permitido fazer operation com booleano , somente int e float!");
    }
}
string resolve_tipo(string tipo1, string tipo2) {


    if(tipo1 == "float" && tipo2 == "float") {
        return "float";
    }

    if(tipo1 == "int" && tipo2 == "float" || tipo1 == "float" && tipo2 == "int") {
        return "float";
    }

    if(tipo1 == "char" || tipo2 == "char") {
         yyerror("Erro na linha " + to_string(linha) + ": Não é possível realizar operações aritméticas entre tipos " + tipo1 +" e " + tipo2); 
    }

    if(tipo1 == "boolean" || tipo2 == "boolean") {
         yyerror("Erro na linha " + to_string(linha) + ": Não é possível realizar operações aritméticas entre tipos " + tipo1 +" e " + tipo2); 
    }

    return "int";
}


void ver_boolean(string tipo1,string tipo3){
    if (tipo1 == "boolean" && tipo3 != "boolean") {
         yyerror("Erro na linha " + to_string(linha) + ": Não é permitido fazer operações entre " + tipo1 + " e " + tipo3);
            }
           if (tipo1 != "boolean" && tipo3 == "boolean") {
              yyerror("Erro na linha " + to_string(linha) + ": Não é permitido fazer operações entre " + tipo1 + " e " + tipo3);
                }

    }

tuple<string, string, string> resolve_coercao(string label1, string label2, string tipo) {

    string t1 = label1;
    string t2 = label2;
    string coercoes = "";

    if(temporarias[t1] == "int" && tipo == "float") {
        string coerced = gentempcode("float");
        coercoes += "\t" + coerced + " = (float) " + t1 + ";\n";
        t1 = coerced;
    }

    if(temporarias[t2] == "int" && tipo == "float") {
        string coerced = gentempcode("float");
        coercoes += "\t" + coerced + " = (float) " + t2 + ";\n";
        t2 = coerced;
    }

    return {coercoes, t1, t2};

}


int main(int argc, char* argv[]) {
    var_temp_qnt = 0;
    linha = 1;
    yyparse();
    return 0;
}

int contador_if = 0;
int contador_else=0;

string fim_if(){
return "fim_if_" + to_string(++contador_if);
}
string fim_else(){
    return "fim_else_" + to_string(++contador_else);

}

void entra_escopo(){
    pilha_escopos.push_back({});
}

void sai_escopo(){
    pilha_escopos.pop_back();
}

string adiciona_variavel_na_tabela(string variavel, string tipo, string temp_associada) {
    if (pilha_escopos.empty()) entra_escopo();
    auto& escopo_atual = pilha_escopos.back();
    if (escopo_atual.count(variavel)) {
        return escopo_atual[variavel].nome_interno;
    }

    string nome_interno = "__v" + to_string(var_user_qnt++);
    Simbolo s = {nome_interno, tipo, temp_associada};
    escopo_atual[variavel] = s;
    simbolos_declarados.push_back(s); // <- adiciona aqui
    return nome_interno;
}

string pega_variavel_na_tabela(string nome_variavel) {

    for (auto it = pilha_escopos.rbegin(); it != pilha_escopos.rend(); ++it) {
        if (it->count(nome_variavel)) {
            return it->at(nome_variavel).nome_interno;
        }
    }
    
    yyerror("Erro na linha " + to_string(linha) + ": variável '" + nome_variavel + "' declarada em escopo local.");
    return "";
}


void verifica_tipo(string tipo1, string tipo2, string mensagem) {
    if(tipo1 == "" || tipo2 == "") {
        yyerror("Erro na linha " + to_string(linha) + ": variável não declaradaaaaa!");
    }

    else if( tipo1 != tipo2 ) {
        yyerror("Erro na linha " + to_string(linha) + ": "+ mensagem);
    }
}

void yyerror(string MSG) {
    cout << "\033[1;31m" << MSG << "\033[0m" << endl;
    exit (0);
}
