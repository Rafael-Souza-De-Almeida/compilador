%{
#include <iostream>
#include <string>
#include <sstream>
#include <map>


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
    // string escopo;
};

map<string, Simbolo> tabela_simbolos;
map<string, string> temporarias;
int var_user_qnt;

int yylex(void);
void yyerror(string);
string gentempcode(string);
string adiciona_variavel_na_tabela(string, string);
string pega_variavel_na_tabela(string);
string resolve_tipo(string, string);
void verifica_tipo(string, string, string);
string getTipo(string);
%}

%token TK_NUM TK_REAL TK_TRUE TK_FALSE
%token TK_MAIN TK_ID TK_FUNCTION
%token TK_INT TK_FLOAT  TK_CHAR TK_BOOLEAN
%token TK_FIM TK_ERROR
%token TK_MAIOR TK_MAIORIGUAL TK_MENOR TK_MENORIGUAL TK_IGUALDADE TK_DIFERENTE
%token  TK_E TK_OU TK_NEGATIVO

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
                /* cout <<"Operation soma" <<endl; */
                string tipo = resolve_tipo($1.label, $3.label);
                $$.label = gentempcode(tipo);
                $$.tipo = tipo;
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " + " + $3.label + ";\n";
            }
            | E '-' E 
            {   
                /* cout<<"Operation subtraction"<<endl; */
                string tipo = resolve_tipo($1.label, $3.label);
                $$.label = gentempcode(tipo);
                $$.tipo = tipo;
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " - " + $3.label + ";\n";
            }
            | E '*' E
            {   
               /*  cout <<"Operation multiplication"<<endl; */
                string tipo = resolve_tipo($1.label, $3.label);
                $$.label = gentempcode(tipo);
                $$.tipo = tipo;
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " * " + $3.label + ";\n";
            }
            | E '/' E
            {   
              /*   cout <<"Operation division"<<endl; */
                string tipo = resolve_tipo($1.label, $3.label);
                $$.label = gentempcode(tipo);
                $$.tipo = tipo;
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " / " + $3.label + ";\n";
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
                string tipo = resolve_tipo($1.label,$3.label);
                $$.label=gentempcode(tipo);
                $$.tipo = tipo;
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + "= " + $1.label + ">" +  $3.label + ";\n";  

            }
            |  E TK_MAIORIGUAL E
            {
                string tipo = resolve_tipo($1.label,$3.label);
                $$.label=gentempcode(tipo);
                $$.tipo = tipo;
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + "= " + $1.label + ">=" +  $3.label + ";\n";  

            }
            |  E TK_MENOR E
            {
                string tipo = resolve_tipo($1.label,$3.label);
                $$.label=gentempcode(tipo);
                $$.tipo = tipo;
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + "= " + $1.label + "<" +  $3.label + ";\n";  

            }
            |  E TK_MENORIGUAL E
            {
                string tipo = resolve_tipo($1.label,$3.label);
                $$.label=gentempcode(tipo);
                $$.tipo = tipo;
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + "= " + $1.label + "<=" +  $3.label + ";\n";  

            }
            |  E TK_IGUALDADE E
            {
                string tipo = resolve_tipo($1.label,$3.label);
                $$.label=gentempcode(tipo);
                $$.tipo = tipo;
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + "= " + $1.label + "==" +  $3.label + ";\n";  

            }
            |  E TK_DIFERENTE E
            {
                string tipo = resolve_tipo($1.label,$3.label);
                $$.label=gentempcode(tipo);
                $$.tipo = tipo;
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + "= " + $1.label + "!=" +  $3.label + ";\n";  

            }
            |  E  TK_OU E
            {
                string tipo = resolve_tipo($1.label,$3.label);
                $$.label=gentempcode(tipo);
                $$.tipo = tipo;
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + "= " + $1.label + "||" +  $3.label + ";\n";  

            }
        
             |  E TK_E E
            {
                verifica_tipo($1.tipo,"int","Operando esquerdo deve ser inteiro");
                verifica_tipo($3.tipo,"int","Operando direita deve ser inteiro");

                string tipo = "int";
                $$.label=gentempcode(tipo);
                $$.tipo = tipo;
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + "= " + $1.label + "&&" +  $3.label + ";\n";  

            }
            |   TK_NEGATIVO E
            {
                 verifica_tipo($2.tipo,"int","Operando esquerdo deve ser int");

                string tipo = "int";
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

                verifica_tipo($4.tipo, "int", "tipo incompatível na atribuição à variável int");
                string nome_interno = adiciona_variavel_na_tabela($2.label, "int");
                $$.traducao = $2.traducao + $4.traducao + "\t" + nome_interno + " = " + $4.label + ";\n";
            }
            | TK_FLOAT TK_ID '=' E
            {   
                verifica_tipo($4.tipo, "float", "tipo incompatível na atribuição à variável float");
                string nome_interno = adiciona_variavel_na_tabela( $2.label, "float");
                $$.traducao = $2.traducao + $4.traducao + "\t" + nome_interno + " = " + $4.label + ";\n";
            }
            | TK_CHAR TK_ID '=' E
            {
                verifica_tipo($4.tipo,"char","tipo incompativel na atribuicao à variável char");
                string nome_interno = adiciona_variavel_na_tabela($2.label,"char");
                $$.traducao = $2.traducao + $4.traducao + "\t" + nome_interno + "=" + $4.label + ";\n";
            }
            | TK_BOOLEAN TK_ID '=' E
            {
                verifica_tipo($4.tipo, "int", "tipo incompatível na atribuição à variável boolean");
                string nome_interno = adiciona_variavel_na_tabela( $2.label, "int");
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
                $$.label = gentempcode("int");
                $$.tipo = "int";
                $$.traducao = "\t" + $$.label + " = " + "1" + ";\n";
            }
            | TK_FALSE
            {
                $$.label = gentempcode("int");
                $$.tipo = "int";
                $$.traducao = "\t" + $$.label + " = " + "0" + ";\n";
            }
            | TK_ID
            {   
                string tipo = getTipo($1.label); 
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
                string nome_interno = adiciona_variavel_na_tabela($2.label, "int");
                $$.traducao = "";
            }
            | TK_FLOAT TK_ID
            {   
               
                string nome_interno = adiciona_variavel_na_tabela( $2.label, "float");
                $$.traducao = "";
            }
            | TK_CHAR TK_ID
            {
                string nome_interno = adiciona_variavel_na_tabela($2.label,"char");
                $$.traducao = "";

            }
            | TK_BOOLEAN TK_ID
            {   
               
                string nome_interno = adiciona_variavel_na_tabela($2.label, "int");
                $$.traducao = "";
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
    return tabela_simbolos[nome_interno].tipo;
}

string resolve_tipo(string temp1, string temp2) {

    string tipo1 = temporarias[temp1];
    string tipo2 = temporarias[temp2];

    if(tipo1 == "float" && tipo2 == "float") {
        return "float";
    }

    return "int";
}


int main(int argc, char* argv[]) {
    var_temp_qnt = 0;
    linha = 1;
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

void verifica_tipo(string tipo1, string tipo2, string mensagem) {
    if(tipo1 == "" || tipo2 == "") {
        yyerror("Erro na linha " + to_string(linha) + ": variável não declarada!");
    }

    else if( tipo1 != tipo2 ) {
        yyerror("Erro na linha " + to_string(linha) + ": "+ mensagem);
    }
}

void yyerror(string MSG) {
    cout << "\033[1;31m" << MSG << "\033[0m" << endl;
    exit (0);
}
