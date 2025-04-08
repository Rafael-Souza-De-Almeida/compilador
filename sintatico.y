%{
#include <iostream>
#include <string>
#include <sstream>
#include <map>


#define YYSTYPE atributos

using namespace std;

int int_temp_qnt;
int float_temp_qnt;
int doubletemp_qnt;
int var_temp_qnt;

struct atributos {
    string label;
    string traducao;
};

struct Simbolo {
    string nome_temp;
    string nome_interno;
    string tipo;
    // string escopo;
};

map<string, Simbolo> tabela_simbolos;
int var_user_qnt;

int yylex(void);
void yyerror(string);
string gentempcode();
string gettempcode();
string adiciona_variavel_na_tabela(string, string, string);
%}

%token TK_NUM TK_REAL TK_TRUE TK_FALSE
%token TK_MAIN TK_ID TK_FUNCTION
%token TK_INT TK_FLOAT TK_DOUBLE TK_BOOLEAN 
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
                
                
                for(auto iterador : tabela_simbolos) {
                    codigo += "\t" + iterador.second.tipo + " " + iterador.second.nome_temp + ";\n";
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
                $$.label = gentempcode();
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " + " + $3.label + ";\n";
            }
            | E '-' E 
            {
                $$.label = gentempcode();
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " - " + $3.label + ";\n";
            }
            | E '*' E
            {
                $$.label = gentempcode();
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " * " + $3.label + ";\n";
            }
            | E '/' E
            {
                $$.label = gentempcode();
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " / " + $3.label + ";\n";
            }
            | TK_INT TK_ID '=' E
            {
                string nome_interno = adiciona_variavel_na_tabela(gettempcode(),$2.label, "int");
                $$.traducao = $2.traducao + $4.traducao + "\t" + nome_interno + " = " + $4.label + ";\n";
            }
            | TK_FLOAT TK_ID '=' E
            {
                string nome_interno = adiciona_variavel_na_tabela(gettempcode(), $2.label, "float");
                $$.traducao = $2.traducao + $4.traducao + "\t" + nome_interno + " = " + $4.label + ";\n";
            }
            | TK_DOUBLE TK_ID '=' E
            {
                string nome_interno = adiciona_variavel_na_tabela(gettempcode(), $2.label, "double");
                $$.traducao = $2.traducao + $4.traducao + "\t" + nome_interno + " = " + $4.label + ";\n";
            }
            | TK_BOOLEAN TK_ID '=' E
            {
                string nome_interno = adiciona_variavel_na_tabela(gettempcode(), $2.label, "int");
                $$.traducao = $2.traducao + $4.traducao + "\t" + nome_interno + " = " + $4.label + ";\n";
            }
            | TK_NUM
            {
                $$.label = gentempcode();
                $$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
            }
            | TK_REAL
            {
                $$.label = gentempcode();
                $$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
            }
            | TK_TRUE
            {
                $$.label = gentempcode();
                $$.traducao = "\t" + $$.label + " = " + "1" + ";\n";
            }
            | TK_FALSE
            {
                $$.label = gentempcode();
                $$.traducao = "\t" + $$.label + " = " + "0" + ";\n";
            }
            | TK_ID
            {   
                $$.label = gentempcode();
                $$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
            }| TK_INT TK_ID
            {   
                $$.label = gentempcode();
                string nome_interno = adiciona_variavel_na_tabela($$.label, $2.label, "int");
                $$.traducao = "\t" + $$.label + " = " + nome_interno + ";\n";
            }
            | TK_FLOAT TK_ID
            {   
                $$.label = gentempcode();
                string nome_interno = adiciona_variavel_na_tabela($$.label, $2.label, "float");
                $$.traducao = "\t" + $$.label + " = " + nome_interno + ";\n";
            }
            | TK_DOUBLE TK_ID
            {   
                $$.label = gentempcode();
                string nome_interno = adiciona_variavel_na_tabela($$.label, $2.label, "double");
                $$.traducao = "\t" + $$.label + " = " + nome_interno + ";\n";
            }
            | TK_BOOLEAN TK_ID
            {   
                $$.label = gentempcode();
                string nome_interno = adiciona_variavel_na_tabela($$.label, $2.label, "int");
                $$.traducao = "\t" + $$.label + " = " + nome_interno + ";\n";
            }
            ;
%%

#include "lex.yy.c"

int yyparse();

string gentempcode() {
    var_temp_qnt++;
    return "t" + to_string(var_temp_qnt);
}

string gettempcode() {
    return "t" + to_string(var_temp_qnt);
}

int main(int argc, char* argv[]) {
    var_temp_qnt = 0;
    yyparse();
    return 0;
}

string adiciona_variavel_na_tabela(string nome_temp, string variavel, string tipo) {
    if(tabela_simbolos.count(variavel)) {
        return tabela_simbolos[variavel].nome_interno;
    }

    string nome_interno = "__v" + to_string(var_user_qnt++);
    tabela_simbolos[variavel] = {nome_temp, nome_interno, tipo};
    return nome_interno;
}

void yyerror(string MSG) {
    cout << MSG <<endl;
    exit (0);
}


