%{
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <tuple>
#include<vector>
#include <fstream>


#define YYSTYPE atributos

using namespace std;


int var_temp_qnt;
int linha = 0;
int label_inicio = 0;
int label_fim = 0;


struct atributos {
    string label;
    string traducao;
    string tipo;
};

struct Simbolo {
    string nome_interno;
    string tipo;
    string temp_associada;

};

struct Simbolos_atuais {
    string tipo;
    string temp_associada;
    
};

map<string, Simbolo> tabela_simbolos;
map<string, string> temporarias;
map<string, Simbolos_atuais> tipos_atuais;
map<string, string> tamanho_string;

map<string, bool> realocar_var_interna;
vector<map<string, Simbolo>> pilha_escopos;
vector<map<string,Simbolo>> escopos_passados;
vector<Simbolo> simbolos_declarados;
// stack<string> pilha_loop_inicio;
// stack<string> pilha_loop_fim;
int var_user_qnt;
bool origem_declarada = false;

int yylex(void);
void yyerror(string);
void entra_escopo();
void sai_escopo();
void verifica_tipo_relacional(string tipo1, string tipo2);
string gentempcode(string);
string adiciona_variavel_na_tabela(string, string, string);
string pega_variavel_na_tabela(string, string);
string resolve_tipo(string, string);
tuple<string, string, string> resolve_coercao(string, string, string);
string getTempId(string variavel);
void verifica_tipo(string, string, string);
void verifica_tipo_logico(string, string);
string getTipo(string);
string realizar_contagem(string, string);
void verifica_operacao_string(string, string, string);
string nova_label(string, string);

%}

%token TK_NUM TK_REAL TK_TRUE TK_FALSE
%token TK_MAIN TK_ID TK_FUNCTION
%token TK_INT TK_FLOAT  TK_BOOLEAN TK_CHAR TK_STRING
%token TK_FIM TK_ERROR TK_PRINT TK_PRINTLN TK_LINHA
%token GREATER_THAN LESS_THAN GREATER_OR_EQUAL LESS_OR_EQUAL EQUAL NOT_EQUAL NOT AND OR
%token TK_IF TK_ELSE TK_FOR TK_WHILE TK_DO TK_SWITCH
%token TK_CONTINUE TK_BREAK

%start S

%left '+' '-'
%left '*' '/' 
%left OR
%left AND
%right NOT

%%

S           : TK_FUNCTION TK_MAIN '(' ')' BLOCO
            {
                string codigo = "/* Compilador hahaha */\n"
                                "#include <iostream>\n"
                                "#include <string.h>\n"
                                "#include <stdio.h>\n"
                                "#include <string.h>\n"
                                "#include <cstdlib>\n"
                                "using namespace std; \n"
                                "int main(void) {\n";
                
                
                 for(auto iterador : temporarias) {
                    if(iterador.second == "boolean") {
                        codigo += "\tint " + iterador.first + ";\n";
                        continue;
                    }

                    if(iterador.second == "string" && iterador.second.length() > 1) {
                        codigo += "\tchar *" + iterador.first + ";\n";
                        continue;
                    }
                    codigo += "\t" + iterador.second + " " + iterador.first + ";\n";
                 }



               for (auto& simbolo : simbolos_declarados) {
                if (simbolo.tipo == "boolean") {
                    codigo += "\tint " + simbolo.nome_interno + ";\n";
                }

                else if(simbolo.tipo == "string") {
                    codigo += "\tchar *" + simbolo.nome_interno + ";\n";
                }
                 else {
                    codigo += "\t" + simbolo.tipo + " " + simbolo.nome_interno + ";\n";
                }
            }

                codigo += $5.traducao;

              

                for(auto iterador : simbolos_declarados) {

                    if(iterador.tipo == "string") {
                        codigo += "\tfree(" + iterador.nome_interno + ")" + ";\n";
                        continue;
                    } 

                }

                 for(auto iterador : temporarias) {
                    if(iterador.second == "string" && iterador.second.length() > 1) {
                        codigo += "\tfree(" + iterador.first + ")" + ";\n";
                        
                    }

                 }

             

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
            |  TK_ID ';'
            {   
                string tipo = getTipo($1.label);
                string nome_interno = pega_variavel_na_tabela($1.label, tipo);
                $$.traducao =   "\t cout << "  + nome_interno + " << endl;\n";   
            } 
            | TK_PRINT '(' E ')' ';' {
                $$.traducao = $1.traducao + $3.traducao +  "\t cout << "  + $3.label + ";\n";
            }
            | TK_PRINTLN '(' E ')' ';' {
                $$.traducao = $1.traducao + $3.traducao +  "\t cout << "  + $3.label + " << endl;\n";
            }
            | BLOCO {
                $$.traducao = $1.traducao;
            } 
            | TK_FOR IDENTIFICADOR_FOR '=' E ':' E BLOCO {
                
                if ($4.tipo != "int") {
                    yyerror("Início do for deve ser numérico (int)");
                }

                if ($6.tipo != "int") {
                    yyerror("Fim do for deve ser numérico (int)");
                }
                
                
                string label_inicio = nova_label("for", "inicio");
                string label_fim = nova_label("for", "fim");

                string nome_variavel = pega_variavel_na_tabela($2.label, "int");

                $$.traducao = ""; 
               
                $$.traducao += $4.traducao + $6.traducao;

                $$.traducao += "\t" + nome_variavel + " = " + $4.label + ";\n";

                string pre_condicao = gentempcode("boolean");
                string condicao = gentempcode("boolean");
                $$.traducao += "\t" + pre_condicao + " = " + $6.label + " - 1;\n"; 
                $$.traducao += label_inicio + ":\n";

                $$.traducao += "\t" + condicao + " = " + nome_variavel + " > " + pre_condicao + ";\n"; 

                // Condição de saída do loop
                $$.traducao += "\tif (" + condicao + ") goto " + label_fim + ";\n";

                // Corpo do for
                $$.traducao += $7.traducao;

                // Incrementa variável do loop
                $$.traducao += "\t" + nome_variavel + " = " + nome_variavel + " + 1;\n";

                // Volta para o início do loop
                $$.traducao += "\tgoto " + label_inicio + ";\n";

                // Label do fim do loop
                $$.traducao += label_fim + ":\n";

           
            } 
            | TK_WHILE
            ;

IDENTIFICADOR_FOR : TK_ID 
                    {
                        string indice_for = gentempcode("int");
                        string nome_variavel = adiciona_variavel_na_tabela($1.label, "int", indice_for);
                        $$.label = $1.label;
                        
                    }
                    ;
                    
           
E           : E '+' E
            {
            string tipo = resolve_tipo($1.tipo, $3.tipo);

            if(tipo == "char") {
                string var_1 = gentempcode("string");
                string var_2 = gentempcode("string");
                $$.tipo = "string";
                $$.traducao = $1.traducao + $3.traducao;
                $$.traducao += "\t" + var_1 + " = (char *) malloc(2);\n";
                $$.traducao += "\t" + var_1 + "[0] = " + $1.label + ";\n";
                $$.traducao += "\t" + var_1 + "[1] = '\\0';\n";
                $$.traducao += "\t" + var_2 + " = (char *) malloc(2);\n";
                $$.traducao += "\t" + var_2 + "[0] = " + $3.label + ";\n";
                $$.traducao += "\t" + var_2 + "[1] = '\\0';\n";
                string temp_tamanho = gentempcode("int");
                $$.label = gentempcode("string");
                $$.traducao += "\t" + temp_tamanho + " = 3;\n";
                $$.traducao += "\t" + $$.label + " = (char *) malloc(" + temp_tamanho + ");\n";
                $$.traducao += "\tstrcpy(" + $$.label + ", " + var_1 + ");\n";
                $$.traducao += "\tstrcat(" + $$.label + ", " + var_2 + ");\n";
                tamanho_string[$$.label] = temp_tamanho;

            }

            else if(tipo == "string") {
            $$.label = gentempcode(tipo);
            $$.tipo = tipo;

           
            bool left_is_char = $1.tipo == "char";
            bool right_is_char = $3.tipo == "char";

            string left_label = $1.label;
            string right_label = $3.label;
            string prep = "";

            if(left_is_char) {
                string var = gentempcode("string");
                prep += "\t" + var + " = (char *) malloc(2);\n";
                prep += "\t" + var + "[0] = " + $1.label + ";\n";
                prep += "\t" + var + "[1] = '\\0';\n";
                left_label = var;
                tamanho_string[var] = "2";
            }

            if(right_is_char) {
                string var = gentempcode("string");
                prep += "\t" + var + " = (char *) malloc(2);\n";
                prep += "\t" + var + "[0] = " + $3.label + ";\n";
                prep += "\t" + var + "[1] = '\\0';\n";
                right_label = var;
                tamanho_string[var] = "2";
            }

            string temp_tamanho = gentempcode("int");
            $$.traducao = $1.traducao + $3.traducao + prep;
            $$.traducao += "\t" + temp_tamanho + " = " + tamanho_string[left_label] + " + " + tamanho_string[right_label] + ";\n";
            $$.traducao += "\t" + temp_tamanho + " = " + temp_tamanho + " + 1;\n";
            $$.traducao += "\t" + $$.label + " = (char *) malloc(" + temp_tamanho + ");\n";
            $$.traducao += "\tstrcpy(" + $$.label + ", " + left_label + ");\n";
            $$.traducao += "\tstrcat(" + $$.label + ", " + right_label + ");\n";

            tamanho_string[$$.label] = temp_tamanho;
        }
        else {
                cout << tipo << endl;
                $$.label = gentempcode(tipo);
                auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, tipo);
                $$.tipo = tipo;
                $$.traducao = $1.traducao + $3.traducao + coercoes + "\t" + $$.label + " = " + t1 + " + " + t2 + ";\n";
            }
            

            }
            | E '-' E 
            {   verifica_operacao_string($1.tipo, $3.tipo, "-");
                string tipo = resolve_tipo($1.tipo, $3.tipo);
                auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, tipo);
                $$.label = gentempcode(tipo);
                $$.tipo = tipo;
                $$.traducao = $1.traducao + $3.traducao + coercoes + "\t" + $$.label + " = " + t1 + " - " + t2 + ";\n";
            }
            | E '*' E
            {   
                verifica_operacao_string($1.tipo, $3.tipo, "*");
                string tipo = resolve_tipo($1.tipo, $3.tipo);
                auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, tipo);
                $$.label = gentempcode(tipo);
                $$.tipo = tipo;
                $$.traducao = $1.traducao + $3.traducao + coercoes + "\t" + $$.label + " = " + t1 + " * " + t2 + ";\n";
            }
            | E '/' E
            {   
                verifica_operacao_string($1.tipo, $3.tipo, "/");
                string tipo = resolve_tipo($1.tipo, $3.tipo);
                auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, tipo);
                $$.label = gentempcode(tipo);
                $$.tipo = tipo;
                $$.traducao = $1.traducao + $3.traducao + coercoes + "\t" + $$.label + " = " + t1 + " / " + t2 + ";\n";
            }
            | '(' E ')'
            {   
                $$.label = $2.label;
                $$.traducao = $2.traducao;
            }
            |   E GREATER_THAN E 
            {   
                string tipo = resolve_tipo($1.tipo, $3.tipo);
                auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, tipo);
                $$.label = gentempcode(tipo);
                $$.tipo = "boolean";
                $$.traducao = $1.traducao + $3.traducao + coercoes + "\t" + $$.label + " = " + t1 + " > " + t2 + ";\n";
            }
            |   E LESS_THAN E 
            {   
                string tipo = resolve_tipo($1.tipo, $3.tipo);
                auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, tipo);
                $$.label = gentempcode(tipo);
                $$.tipo = "boolean";
                $$.traducao = $1.traducao + $3.traducao + coercoes + "\t" + $$.label + " = " + t1 + " < " + t2 + ";\n";
            }
            |   E GREATER_OR_EQUAL E 
            {   
                string tipo = resolve_tipo($1.tipo, $3.tipo);
                auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, tipo);
                $$.label = gentempcode(tipo);
                $$.tipo = "boolean";
                $$.traducao = $1.traducao + $3.traducao + coercoes + "\t" + $$.label + " = " + t1 + " >= " + t2 + ";\n";
            }
            |   E LESS_OR_EQUAL E 
            {   
                string tipo = resolve_tipo($1.tipo, $3.tipo);
                auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, tipo);
                $$.label = gentempcode(tipo);
                $$.tipo = "boolean";
                $$.traducao = $1.traducao + $3.traducao + coercoes + "\t" + $$.label + " = " + t1 + " <= " + t2 + ";\n";
            }
            |   E EQUAL E 
            {   
                string tipo = resolve_tipo($1.tipo, $3.tipo);
                auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, tipo);
                $$.label = gentempcode(tipo);
                $$.tipo = "boolean";
                $$.traducao = $1.traducao + $3.traducao + coercoes + "\t" + $$.label + " = " + t1 + " == " + t2 + ";\n";
            }
            |   E NOT_EQUAL E 
            {   
                string tipo = resolve_tipo($1.tipo, $3.tipo);
                auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, tipo);
                $$.label = gentempcode(tipo);
                $$.tipo = "boolean";
                $$.traducao = $1.traducao + $3.traducao + coercoes + "\t" + $$.label + " = " + t1 + " != " + t2 + ";\n";
            }
            |   NOT E
            {   
                if($2.tipo != "boolean") {
                    yyerror("Erro na linha " + to_string(linha) + ": não é possível usar o operador '!' em uma variável não booleana!");
                }
                $$.label = gentempcode("int");
                $$.tipo = "boolean";
                $$.traducao = $2.traducao + "\t" + $$.label + " = " "!" + $2.label + ";\n";
            }
            |   E AND E
            {   
                verifica_tipo_logico($1.tipo, $3.tipo);
                $$.label = gentempcode("int");
                $$.tipo = "boolean";
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " && " + $3.label + ";\n";
            }
            |   E OR E
            {   
                verifica_tipo_logico($1.tipo, $3.tipo);
                $$.label = gentempcode("int");
                $$.tipo = "boolean";
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " || " + $3.label + ";\n";
            }
            /* |  E TK_MAIOR E
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

            } */

            |  TK_ID '=' E
            {
                string nome_variavel = adiciona_variavel_na_tabela($1.label, $3.tipo, $3.label);
                
                if($3.tipo == "string") {
                    
                    if(realocar_var_interna.count(nome_variavel)){
                         $$.traducao = "\tfree(" + nome_variavel + ");\n";
                    }
                    
                    realocar_var_interna[nome_variavel] = true;
                    $$.traducao += $1.traducao + $3.traducao + "\t" + nome_variavel + " = " + "(char *) malloc(" + tamanho_string[$3.label] + ");\n";
                    $$.traducao += "\tstrcpy(" + nome_variavel + "," + $3.label + ");\n";
                } else {
                    $$.traducao = $1.traducao + $3.traducao + "\t" + nome_variavel + " = " + $3.label + ";\n";
                }
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
            | TK_STRING {

                
                $$.label = gentempcode("string");
                $$.tipo = "string";

                  if (!origem_declarada) {
                    $$.traducao += "\tchar *origem;\n";
                    origem_declarada = true;
                }

                $$.traducao += "\torigem = (char *) malloc(300); \n";
                $$.traducao += "\tstrcpy(origem, " + $1.label + ");\n";
                $$.traducao += realizar_contagem("origem", $$.label);
                $$.traducao += "\tfree(origem);\n";
                string tamanho = gentempcode("int");
                $$.traducao += "\t" + tamanho + " = " + tamanho_string[$$.label]  + " + 1;\n";
                tamanho_string[$$.label] = tamanho;
                $$.traducao += "\t" + $$.label + " = " + "(char *) malloc(" + tamanho + ");\n";
                $$.traducao += "\tstrcpy(" + $$.label + "," + $1.label + ");\n";
            }
            | TK_TRUE
            {
                $$.label = gentempcode("int");
                $$.tipo = "boolean";
                $$.traducao = "\t" + $$.label + " = " + "1" + ";\n";
            }
            | TK_FALSE
            {
                $$.label = gentempcode("int");
                $$.tipo = "boolean";
                $$.traducao = "\t" + $$.label + " = " + "0" + ";\n";
            }
            | TK_CHAR
            {
                $$.label = gentempcode("char");
                $$.tipo = "char";
                $$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
            }
            | TK_ID
            {   
                string tipo = getTipo($1.label); 
                $$.tipo=tipo;
                $$.label = gentempcode(tipo);
                string nome_interno = pega_variavel_na_tabela($1.label, tipo);
                $$.traducao = "\t" + $$.label + " = " + nome_interno + ";\n";

                if(tipo == "string") {
                    $$.traducao = realizar_contagem(nome_interno, $$.label);
                    $$.traducao += "\t" + $$.label + " = " + "(char *) malloc(" + tamanho_string[$$.label] + ");\n";
                    $$.traducao += "\tstrcpy(" + $$.label + "," + nome_interno + ");\n";
                }

                $$.tipo = tipo;

                
            }
            | '('TK_INT')' TK_ID
            {  
                string tipo_atual = getTipo($4.label);
                string novo_tipo = "int";
                $$.label = gentempcode(novo_tipo);
                $$.tipo = novo_tipo;
                string nome_interno = pega_variavel_na_tabela($4.label, tipo_atual);
                $$.traducao = "\t" + $$.label + " = " + "(" + novo_tipo + ")" + " " + nome_interno + ";\n";
            }
            | '('TK_FLOAT')' TK_ID
            {  
                string tipo_atual = getTipo($4.label);
                string novo_tipo = "float";
                $$.label = gentempcode(novo_tipo);
                $$.tipo = novo_tipo;
                string nome_interno = pega_variavel_na_tabela($4.label, tipo_atual);
                $$.traducao = "\t" + $$.label + " = " + "(" + novo_tipo + ")" + " " + nome_interno + ";\n";
            }
            | '('TK_BOOLEAN')' TK_ID
            {  
                yyerror("Erro na linha " + to_string(linha) + ": não é possível transformar a variável em boolean!");
            }
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

    if (tipos_atuais.count(nome_interno)) {
        string tipo = tipos_atuais[nome_interno].tipo;

        if (tipo == "") {
            yyerror("Erro na linha " + to_string(linha) + 
                    ": Ao declarar a variável '" + nome_interno + "', é necessário atribuir um valor inicial.\n" +
                    "Dica: use algo como `a = 0;` para inicializá-la.");
        }

        return tipo;
    }


    for (auto it = escopos_passados.rbegin(); it != escopos_passados.rend(); ++it) {
        if (it->count(nome_interno)) {
            yyerror("Erro na linha " + to_string(linha) + 
                    ": variável '" + nome_interno + "' foi declarada, mas está fora do escopo atual.");
            return it->at(nome_interno).tipo;
        }
    }


    yyerror("Erro na linha " + to_string(linha) + 
            ": variável '" + nome_interno + "' não foi declarada.");
    return "";
}

string getTempId(string variavel) {
      
    return tipos_atuais[variavel].temp_associada;
    
}

string resolve_tipo(string tipo1, string tipo2) {


    if(tipo1 == "float" && tipo2 == "float") {
        return "float";
    }

    if((tipo1 == "int" && tipo2 == "float") || (tipo1 == "float" && tipo2 == "int")) {
        return "float";
    }


    if(tipo1 == "char" && tipo2 == "char") {
         return "char";
    }

    if(tipo1 == "boolean" || tipo2 == "boolean") {
         yyerror("Erro na linha " + to_string(linha) + ": Não é possível realizar operações aritméticas entre tipos " + tipo1 +" e " + tipo2); 
    }

    if(tipo1 == "string" && tipo2 == "string") {
        return "string";
    }

    if((tipo1 == "string" && tipo2 == "char") || (tipo1 == "char" && tipo2 == "string")) {
        return "string";
    }

    return "int";
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


void entra_escopo(){
    pilha_escopos.push_back({});
}

void sai_escopo(){
    escopos_passados.push_back(pilha_escopos.back());
    pilha_escopos.pop_back();
}

string adiciona_variavel_na_tabela(string variavel, string tipo, string temp_associada) {

    string variavel_formatada = variavel + "_" + tipo;
    
    if (pilha_escopos.empty()) entra_escopo();

    auto& escopo_atual = pilha_escopos.back();

  if (escopo_atual.count(variavel_formatada)) {
  
    escopo_atual[variavel_formatada].temp_associada = temp_associada;
    tipos_atuais[variavel].tipo = tipo;
    tipos_atuais[variavel].temp_associada = temp_associada;
    return escopo_atual[variavel_formatada].nome_interno;
}

   
    string nome_interno = "__v" + to_string(var_user_qnt++);

    Simbolo simbolo = { nome_interno, tipo, temp_associada };

    escopo_atual[variavel_formatada] = simbolo;
    simbolos_declarados.push_back(simbolo);  

   
    tipos_atuais[variavel].tipo = tipo;
    tipos_atuais[variavel].temp_associada = temp_associada;


    return nome_interno;
}


void verifica_operacao_string(string tipo1, string tipo2, string operacao) {
    if(tipo1 == "string" || tipo2 == "string") {
        yyerror("Erro na linha " + to_string(linha) + " Não é possível realizar a operação '" + operacao + "' com o tipo string");
    } else if((tipo1 == "char" || tipo2 == "char")) {
        yyerror("Erro na linha " + to_string(linha) + " Não é possível realizar a operação '" + operacao + "' com o tipo char");
    }
}

string nova_label(string comando, string tipo) {

    if(tipo == "inicio") {
        label_inicio++;
        return comando + "_" + tipo + "_" + to_string(label_inicio);
    }

    else if(tipo == "fim") {
        label_fim++;
        return comando + "_" + tipo + "_" + to_string(label_fim);
    }

    return "";
}


string pega_variavel_na_tabela(string nome_variavel, string tipo) {

    string variavel_formatada = nome_variavel + "_" + tipo;

     for (auto it = pilha_escopos.rbegin(); it != pilha_escopos.rend(); ++it) {
        if (it->count(variavel_formatada)) {
            return it->at(variavel_formatada).nome_interno;
        }
    }

   for (auto& escopo : escopos_passados) {
        if (escopo.count(variavel_formatada)) {
            yyerror("Erro na linha " + to_string(linha) + ": variável '" + nome_variavel + "' está fora do escopo atual.");
            return "";
        }
    }

    yyerror("Erro na linha " + to_string(linha) + ": variável '" + nome_variavel + "' não foi declarada.");
    return "";
}

string realizar_contagem(string palavra, string temp) {

   static int count = 0;
   string id = to_string(count++);



    string var_string = palavra;
    string var_i = gentempcode("int");
    string var_tam = gentempcode("int");
    string temp_if = gentempcode("int");
    string label_inicio = "label_inicio_" + id;
    string label_fim = "label_fim_" + id;


    string codigo =
        "\t" + var_i + " = 0;\n" +
        "\t" + var_tam + " = 0;\n" +
        label_inicio + ":\n" +
        "\t" + temp_if + " = " + var_string + "[" + var_i + "] == '\\0';\n" +
        "\tif (" + temp_if +  ") goto " + label_fim + ";\n" +
        "\t" + var_tam + " = " + var_tam + " + 1;\n" +
        "\t" + var_i + " = " + var_i + " + 1;\n" +
        "\tgoto " + label_inicio + ";\n" +
        label_fim + ":\n";
                
    tamanho_string[temp] = var_tam;

    return codigo;
                
}

void verifica_tipo(string tipo1, string tipo2, string mensagem) {
    if(tipo1 == "" || tipo2 == "") {
        yyerror("Erro na linha " + to_string(linha) + ": variável não declarada!");
    }

    else if( tipo1 != tipo2 ) {
        yyerror("Erro na linha " + to_string(linha) + ": "+ mensagem);
    }
}

void verifica_tipo_logico(string tipo1, string tipo2) {
    if(tipo1 != "boolean" || tipo2 != "boolean") {
         yyerror("Erro na linha " + to_string(linha) + ": "+ "Não é possível realizar o operador && entre variáveis não booleanas");
    }
    
}

void yyerror(string MSG) {
    cout << "\033[1;31m" << MSG << "\033[0m" << endl;
    exit (0);
}

int main(int argc, char* argv[]) {
    var_temp_qnt = 0;
    linha = 1;
    yyparse();
    return 0;
}

