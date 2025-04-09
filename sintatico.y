%{
#include <iostream>
#include <string>
#include <sstream>
#include <map>

//usar /n do lexico e uma variavel global de numero da linha incrementar quando paarecer /n 



#define YYSTYPE atributos

using namespace std;

int int_temp_qnt;
int float_temp_qnt;
int var_temp_qnt;

struct atributos {
    string label;
    string traducao;
};

struct Simbolo {
    string nome_interno;
    string tipo;
    // string escopo;
};

map<string, Simbolo> tabela_simbolos;
map<string, string> temporarias;
int var_user_qnt;

int yylex(void);
void yyerror(string);
string gentempcode(string);
string gettempcode();
string adiciona_variavel_na_tabela(string, string);
string pega_variavel_na_tabela(string);
string resolve_tipo(string, string);
%}

%token TK_NUM TK_REAL TK_TRUE TK_FALSE
%token TK_MAIN TK_ID TK_FUNCTION
%token TK_INT TK_FLOAT  TK_BOOLEAN 
%token TK_FIM TK_ERROR

%start S

%left '+'

%%

S           : TK_FUNCTION TK_MAIN '(' ')' BLOCO
            {
                string codigo = "/* Compilador hahaha */\n"
                                "#include <iostream>\n"
                                "#include <string.h>\n"
                                "#include <stdio.h>\n"
                                "int main(void) {\n"; 
                
                
                 for(auto iterador : temporarias) {
                     codigo += "\t" + iterador.second + " " + iterador.first + ";\n";
                 }

                for(auto iterador : tabela_simbolos) {
                    codigo += "\t" + iterador.second.tipo + " " + iterador.second.nome_interno + ";\n";
                }

                codigo += $5.traducao;
                codigo += "\treturn 0;"
                          "\n}";

                cout << codigo << endl;

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
            ;

E           : E '+' E
            {
                string tipo = resolve_tipo($1.label, $3.label);
                $$.label = gentempcode(tipo);
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " + " + $3.label + ";\n";
            }
            | E '-' E 
            {   
                string tipo = resolve_tipo($1.label, $3.label);
                $$.label = gentempcode(tipo);
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " - " + $3.label + ";\n";
            }
            | E '*' E
            {   
                string tipo = resolve_tipo($1.label, $3.label);
                $$.label = gentempcode(tipo);
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " * " + $3.label + ";\n";
            }
            | E '/' E
            {   
                string tipo = resolve_tipo($1.label, $3.label);
                $$.label = gentempcode(tipo);
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " / " + $3.label + ";\n";
            }
            |  TK_ID '=' E
            {
                string nome_variavel = pega_variavel_na_tabela($1.label);
                $$.traducao = $1.traducao + $3.traducao + "\t" + nome_variavel + " = " + $3.label + ";\n";
            } | TK_INT TK_ID '=' E
            {
                string nome_interno = adiciona_variavel_na_tabela($2.label, "int");
                $$.traducao = $2.traducao + $4.traducao + "\t" + nome_interno + " = " + $4.label + ";\n";
            }
            | TK_FLOAT TK_ID '=' E
            {
                string nome_interno = adiciona_variavel_na_tabela( $2.label, "float");
                $$.traducao = $2.traducao + $4.traducao + "\t" + nome_interno + " = " + $4.label + ";\n";
            }
            | TK_BOOLEAN TK_ID '=' E
            {
                string nome_interno = adiciona_variavel_na_tabela( $2.label, "int");
                $$.traducao = $2.traducao + $4.traducao + "\t" + nome_interno + " = " + $4.label + ";\n";
            }
            | TK_NUM
            {
                $$.label = gentempcode("int");
                $$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
            }
            | TK_REAL
            {
                $$.label = gentempcode("float");
                $$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
            }
            | TK_TRUE
            {
                $$.label = gentempcode("int");
                $$.traducao = "\t" + $$.label + " = " + "1" + ";\n";
            }
            | TK_FALSE
            {
                $$.label = gentempcode("int");
                $$.traducao = "\t" + $$.label + " = " + "0" + ";\n";
            }
            | TK_ID
            {   
                $$.label = gentempcode("int");
                string nome_interno = adiciona_variavel_na_tabela($1.label, "int");
                $$.traducao = "\t" + $$.label + " = " + nome_interno + ";\n";
            }| TK_INT TK_ID
            {   
                $$.label = gentempcode($1.label);
                string nome_interno = adiciona_variavel_na_tabela($2.label, "int");
                $$.traducao = "\t" + $$.label + " = " + nome_interno + ";\n";
            }
            | TK_FLOAT TK_ID
            {   
                $$.label = gentempcode($1.label);
                string nome_interno = adiciona_variavel_na_tabela( $2.label, "float");
                $$.traducao = "\t" + $$.label + " = " + nome_interno + ";\n";
            }
            | TK_BOOLEAN TK_ID
            {   
                $$.label = gentempcode($1.label);
                string nome_interno = adiciona_variavel_na_tabela($2.label, "int");
                $$.traducao = "\t" + $$.label + " = " + nome_interno + ";\n";
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

string resolve_tipo(string temp1, string temp2) {
    if(temp1 == "float" && temp2 == "float") {
        return "float";
    }

    return "int";
}

string gettempcode() {
    return "t" + to_string(var_temp_qnt);
}

int main(int argc, char* argv[]) {
    var_temp_qnt = 0;
    yyparse();
    return 0;
}

string adiciona_variavel_na_tabela( string variavel, string tipo) {
    if(tabela_simbolos.count(variavel)) {
        return tabela_simbolos[variavel].nome_interno;
    }

    string nome_interno = "__v" + to_string(var_user_qnt++);
    tabela_simbolos[variavel] = { nome_interno, tipo};
    return nome_interno;
}

string pega_variavel_na_tabela(string nome_variavel) {

    return tabela_simbolos[nome_variavel].nome_interno;

}

void yyerror(string MSG) {
    cout << MSG <<endl;
    exit (0);
}


