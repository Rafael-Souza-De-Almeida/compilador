%{
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <tuple>

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

map<string, Simbolo> tabela_simbolos;
map<string, string> temporarias;
map<string, string> tipos_atuais;
int var_user_qnt;

int yylex(void);
void yyerror(string);
string gentempcode(string);
string adiciona_variavel_na_tabela(string, string, string);
string pega_variavel_na_tabela(string, string);
string resolve_tipo(string, string);
tuple<string, string, string> resolve_coercao(string, string, string);
void verifica_tipo(string, string, string);
string getTipo(string);
%}

%token TK_NUM TK_REAL TK_TRUE TK_FALSE
%token TK_MAIN TK_ID TK_FUNCTION
%token TK_INT TK_FLOAT  TK_BOOLEAN TK_CHAR
%token TK_FIM TK_ERROR TK_PRINT TK_PRINTLN

%start S

%left '+'

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

                for(auto iterador : tabela_simbolos) {
                    if(iterador.second.tipo == "boolean") {
                        codigo += "\tint " + iterador.second.nome_interno + ";\n";
                        continue;
                    }
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
            | TK_PRINT '(' E ')' ';' {
                $$.traducao = $1.traducao + $3.traducao +  "\t cout << "  + $3.label + ";\n";
            }
            | TK_PRINTLN '(' E ')' ';' {
                $$.traducao = $1.traducao + $3.traducao +  "\t cout << "  + $3.label + " << endl;\n";
            }
            ;

E           : E '+' E
            {
            string tipo = resolve_tipo($1.label, $3.label);
            auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, tipo);
            $$.label = gentempcode(tipo);
            $$.tipo = tipo;
            $$.traducao = $1.traducao + $3.traducao + coercoes + "\t" + $$.label + " = " + t1 + " + " + t2 + ";\n";

            }
            | E '-' E 
            {   
                string tipo = resolve_tipo($1.label, $3.label);
                auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, tipo);
                $$.label = gentempcode(tipo);
                $$.tipo = tipo;
                $$.traducao = $1.traducao + $3.traducao + coercoes + "\t" + $$.label + " = " + t1 + " - " + t2 + ";\n";
            }
            | E '*' E
            {   
                string tipo = resolve_tipo($1.label, $3.label);
                auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, tipo);
                $$.label = gentempcode(tipo);
                $$.tipo = tipo;
                $$.traducao = $1.traducao + $3.traducao + coercoes + "\t" + $$.label + " = " + t1 + " * " + t2 + ";\n";
            }
            | E '/' E
            {   
                string tipo = resolve_tipo($1.label, $3.label);
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
            |  TK_ID '=' E
            {
                string nome_variavel = adiciona_variavel_na_tabela($1.label, $3.tipo, $3.label);
                $$.traducao = $1.traducao + $3.traducao + "\t" + nome_variavel + " = " + $3.label + ";\n";
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
    string tipo = tipos_atuais[nome_interno];

    if(tipo == "") {
        yyerror("Erro na linha " + to_string(linha) + 
        ": Ao declarar uma variável é necessária atribuí-la \n" + 
        "Dica: Atribua a variável com 0 se você não deseja definir um valor a ela ainda.");
    }
    string variavel_formatada = nome_interno + "_" + tipo;
    return tabela_simbolos[variavel_formatada].tipo;
}

string resolve_tipo(string temp1, string temp2) {

    string tipo1 = temporarias[temp1];
    string tipo2 = temporarias[temp2];

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
        return tabela_simbolos[variavel_formatada].nome_interno;
    }

    string nome_interno = "__v" + to_string(var_user_qnt++);
    tabela_simbolos[variavel_formatada] = { nome_interno, tipo, temp_associada};
    tipos_atuais[variavel] = tipo;
    return nome_interno;
}

string pega_variavel_na_tabela(string nome_variavel, string tipo) {

    string variavel_formatada = nome_variavel + "_" + tipo;

    return tabela_simbolos[variavel_formatada].nome_interno;

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

int main(int argc, char* argv[]) {
    var_temp_qnt = 0;
    linha = 1;
    yyparse();
    return 0;
}

