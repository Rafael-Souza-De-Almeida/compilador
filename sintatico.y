%{
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <tuple>
#include <fstream>

// to-do: Gerar rótulos de saída para o if e guardar (Fim_1, fim_2)
//bloco -> sumidoro "{ Comandos }"
//sumidoro -> vazio {crie empilhe rotulos}
//yacc possui uma variavel para isso
// marcador ou tamanho da temp para string
// colocar na tabela de simbolos da string,a string e o tamanho da string para quando passar b = a, fazer t2[3].
// fazer malloc
//strcat para concatenar
/*
    string a = 'oi'
    string b = a;

    char t1*;
    strcpy(t1, 'oi')
    contar(t1) //criar função no codigo intermediario com if t4 = t4 +1;

    t2 = malloc(sizeof(t3))
    strcpy(t2, t1)

    char t1[3];
    strcpy(t1, "oi");
*/

#define YYSTYPE atributos

using namespace std;


int var_temp_qnt;
int linha = 0;

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

struct Simbolos_atuais {
    string tipo;
    string temp_associada;
    
};

map<string, Simbolo> tabela_simbolos;
map<string, string> temporarias;
map<string, Simbolos_atuais> tipos_atuais;
map<string, string> tamanho_string;
int var_user_qnt;
bool origem_declarada = false;

int yylex(void);
void yyerror(string);
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
%}

%token TK_NUM TK_REAL TK_TRUE TK_FALSE
%token TK_MAIN TK_ID TK_FUNCTION
%token TK_INT TK_FLOAT  TK_BOOLEAN TK_CHAR TK_STRING
%token TK_FIM TK_ERROR TK_PRINT TK_PRINTLN TK_LINHA
%token GREATER_THAN LESS_THAN GREATER_OR_EQUAL LESS_OR_EQUAL EQUAL NOT_EQUAL NOT AND OR

%start S

%left '+'
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

                for(auto iterador : tabela_simbolos) {
                    if(iterador.second.tipo == "boolean") {
                        codigo += "\tint " + iterador.second.nome_interno + ";\n";
                        continue;
                    }

                    if(iterador.second.tipo == "string" && iterador.second.tipo.length() > 1) {
                        codigo += "\tchar *" + iterador.second.nome_interno + ";\n";
                        continue;
                    }
                    codigo += "\t" + iterador.second.tipo + " " + iterador.second.nome_interno + ";\n";

                }

                codigo += $5.traducao;

                 for(auto iterador : tamanho_string) {
                    codigo += "\tfree(" + iterador.first + ")" + ";\n";  
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

BLOCO       : '{' COMANDOS '}'
            {
                $$.traducao = $2.traducao;
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
                string temp_associada = getTempId($1.label);
                $$.traducao =   "\t cout << "  + temp_associada + " << endl;\n";   
            } 
            | TK_PRINT '(' E ')' ';' {
                $$.traducao = $1.traducao + $3.traducao +  "\t cout << "  + $3.label + ";\n";
            }
            | TK_PRINTLN '(' E ')' ';' {
                $$.traducao = $1.traducao + $3.traducao +  "\t cout << "  + $3.label + " << endl;\n";
            }
            ;

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
                string tipo = resolve_tipo($1.tipo, $3.tipo);
                auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, tipo);
                $$.label = gentempcode(tipo);
                $$.tipo = tipo;
                $$.traducao = $1.traducao + $3.traducao + coercoes + "\t" + $$.label + " = " + t1 + " - " + t2 + ";\n";
            }
            | E '*' E
            {   
                string tipo = resolve_tipo($1.tipo, $3.tipo);
                auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, tipo);
                $$.label = gentempcode(tipo);
                $$.tipo = tipo;
                $$.traducao = $1.traducao + $3.traducao + coercoes + "\t" + $$.label + " = " + t1 + " * " + t2 + ";\n";
            }
            | E '/' E
            {   
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
            |  TK_ID '=' E
            {
                string nome_variavel = adiciona_variavel_na_tabela($1.label, $3.tipo, $3.label);
                $$.traducao = $1.traducao + $3.traducao + "\t" + nome_variavel + " = " + $3.label + ";\n";
                if($3.tipo == "string") {
                    $$.traducao = $1.traducao + $3.traducao + "\t" + nome_variavel + " = " + "(char *) malloc(" + tamanho_string[$3.label] + ");\n";
                    $$.traducao += "\tstrcpy(" + nome_variavel + "," + $3.label + ");\n";
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

string getTempId(string variavel) {
    return tipos_atuais[variavel].temp_associada;
}

string getTipo(string nome_interno) {
    string tipo = tipos_atuais[nome_interno].tipo;

    if(tipo == "") {
        yyerror("Erro na linha " + to_string(linha) + 
        ": Ao declarar uma variável é necessária atribuí-la \n" + 
        "Dica: Atribua a variável com 0 se você não deseja definir um valor a ela ainda.");
    }
    string variavel_formatada = nome_interno + "_" + tipo;
    return tabela_simbolos[variavel_formatada].tipo;
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



string adiciona_variavel_na_tabela( string variavel, string tipo, string temp_associada) {

    string variavel_formatada = variavel + "_" + tipo;

    if(tabela_simbolos.count(variavel_formatada)) {
        tabela_simbolos[variavel_formatada].temp_associada = temp_associada;
        tipos_atuais[variavel].tipo = tipo;
        tipos_atuais[variavel].temp_associada = temp_associada;
        return tabela_simbolos[variavel_formatada].nome_interno;
    }

    string nome_interno = "__v" + to_string(var_user_qnt++);
    tabela_simbolos[variavel_formatada] = { nome_interno, tipo, temp_associada};
    tipos_atuais[variavel].tipo = tipo;
    tipos_atuais[variavel].temp_associada = temp_associada;
    return nome_interno;
}


string pega_variavel_na_tabela(string nome_variavel, string tipo) {

    string variavel_formatada = nome_variavel + "_" + tipo;

    return tabela_simbolos[variavel_formatada].nome_interno;

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

