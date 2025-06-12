%{
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <tuple>
#include<vector>
#include <fstream>
#include<stack>


#define YYSTYPE atributos

using namespace std;


int var_temp_qnt;
int linha = 0;
int label_inicio = 0;
int label_fim = 0;
int label_incremento = 0;
int label_tipo = 0; 


struct atributos {
    string label;
    string traducao;
    string tipo;
    string var_original;
};

struct Simbolo {
    string nome_interno;
    string tipo;
    string temp_associada;

};

struct Simbolos_atuais {
    string tipo;
    string temp_associada;
    string nome_interno;
    
};


map<string, Simbolo> tabela_simbolos;
map<string, string> temporarias;
map<string, Simbolos_atuais> tipos_atuais;
map<string, string> tamanho_string;
map<string, string> variavel_escopo;
bool esta_no_while = false;
bool esta_no_for = false;
bool esta_no_do_while = false;
int qtdWhile = 0;
int qtdFor = 0;
int qtdDoWhile = 0;
int contador_if = 0;
int contador_else=0;
int verifica_condição = 0;

map<string, bool> mudou_tipo;

map<string, bool> realocar_var_interna;
vector<map<string, Simbolo>> pilha_escopos;
vector<map<string,Simbolo>> escopos_passados;
vector<Simbolo> simbolos_declarados;
stack<string> pilha_loop_inicio;
stack<string> pilha_loop_fim;
stack<string> pilha_loop_continue;
int var_user_qnt;
bool origem_declarada = false;
bool operacao_logica = false;
bool recebo_id = false;

int yylex(void);
void yyerror(string);
void entra_escopo();
void sai_escopo();
void verifica_tipo_relacional(string tipo1, string tipo2);
bool edita_tipo_na_tabela(string, string, string);
string gentempcode(string);
string adiciona_variavel_na_tabela(string, string, string);
string pega_variavel_na_tabela(string, string);
string resolve_tipo(string, string);
tuple<string, string, string> resolve_coercao(string, string, string);
string getTempId(string variavel);
string fim_if();
string fim_else();
int tipo_var_dinamica(string);
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
%token TK_TYPE
%token TOKEN_STRING_TYPE

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
                "#include <cstdlib>\n"
                "using namespace std;\n"
                "struct Var {\n"
                "    int tipo;\n"
                "    int i;\n"
                "    float f;\n"
                "    int b;\n"
                "    char c;\n"
                "    char *s;\n"
                "};\n"
                "int main(void) {\n";

                
                
                
                 for(auto iterador : temporarias) {
                    if(iterador.second == "boolean") {
                        codigo += "\tint " + iterador.first + ";\n";
                        continue;
                    }

                    if(iterador.second == "Var") {
                        codigo += "\tVar* " + iterador.first + ";\n";
                        continue;
                    }

                    if(iterador.second == "string" && iterador.second.length() > 1) {
                        codigo += "\tchar *" + iterador.first + ";\n";
                        continue;
                    }
                    codigo += "\t" + iterador.second + " " + iterador.first + ";\n";
                 }



               for (auto& simbolo : simbolos_declarados) {
                
                 
                    codigo += "\tVar *" + simbolo.nome_interno + ";\n";
                
            }

                codigo += $5.traducao;

              

                for(auto iterador : simbolos_declarados) {

                    if(iterador.tipo == "string") {
                        codigo += "\tfree(" + iterador.nome_interno + "->s" + ")" + ";\n";
                        continue;
                    } 

                }

                 for(auto iterador : temporarias) {
                    if(iterador.second == "string" && iterador.second.length() > 1) {
                        codigo += "\tfree(" + iterador.first + ")" + ";\n";
                        
                    }

                 }

                  for(auto iterador : simbolos_declarados) {

                    
                        codigo += "\tfree(" + iterador.nome_interno + ")" + ";\n";
                        continue;
                    

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
             | TK_ID ';'
            {   
                string tipo = getTipo($1.label);
                string nome_variavel = pega_variavel_na_tabela($1.label, tipo);
                if(nome_variavel == "") {
                    yyerror("A variável não foi declarada");
                }

                $$.traducao += "\tswitch (" + nome_variavel + "->tipo) {\n";
                $$.traducao += "\t\tcase 1: cout << " + nome_variavel + "->i << endl; break;\n";
                $$.traducao += "\t\tcase 2: cout << " + nome_variavel + "->f << endl; break;\n";
                $$.traducao += "\t\tcase 3: cout << " + nome_variavel + "->b << endl; break;\n";
                $$.traducao += "\t\tcase 4: cout << " + nome_variavel + "->c << endl; break;\n";
                $$.traducao += "\t\tcase 5: cout << " + nome_variavel + "->s << endl; break;\n";
                $$.traducao += "\t\tdefault: cout << \"[ERRO: tipo desconhecido]\" << endl; break;\n";
                $$.traducao += "\t}\n";
            }

            | TK_PRINT '(' E ')' ';' {
                $$.traducao = $1.traducao + $3.traducao +  "\t cout << "  + $3.label + ";\n";
            }
            | TK_PRINTLN '(' E ')' ';' {
                $$.traducao = $1.traducao + $3.traducao +  "\t cout << "  + $3.label + " << endl;\n";
            }
            | BLOCO {
                $$.traducao = $1.traducao;

            } | TK_INT TK_TYPE '(' TK_ID ')' ';'
            {
            
            string temp_associada = gentempcode("int");
            string nome_interno = adiciona_variavel_na_tabela($4.label, "int" , temp_associada);

            string comando_leitura;
            comando_leitura  = "\tcin >> " + nome_interno + ";\n";
            comando_leitura += "\tif (cin.fail()) {\n";
            comando_leitura += "\t\tcerr << \"Entrada inválida para tipo int!\" << endl;\n";
            comando_leitura += "\t\texit(1);\n\t}\n";
        
                    $$.traducao = comando_leitura;
            }
             | TK_FLOAT TK_TYPE '(' TK_ID ')' ';'
            {
            
            string temp_associada = gentempcode("float");
            string nome_interno = adiciona_variavel_na_tabela($4.label, "float" , temp_associada);

            string comando_leitura;
            comando_leitura  = "\tcin >> " + nome_interno + ";\n";
            comando_leitura += "\tif (cin.fail()) {\n";
            comando_leitura += "\t\tcerr << \"Entrada inválida para tipo float!\" << endl;\n";
            comando_leitura += "\t\texit(1);\n\t}\n";
        
            $$.traducao = comando_leitura;
            }
            | TK_BOOLEAN TK_TYPE '(' TK_ID ')' ';'
            {
            
            string temp_associada = gentempcode("boolean");
            string nome_interno = adiciona_variavel_na_tabela($4.label, "boolean" , temp_associada);

            string comando_leitura;
            comando_leitura  = "\tcin >> " + nome_interno + ";\n";
            comando_leitura += "\tif (cin.fail()) {\n";
            comando_leitura += "\t\tcerr << \"Entrada inválida para tipo boolean!\" << endl;\n";
            comando_leitura += "\t\texit(1);\n\t}\n";
        
            $$.traducao = comando_leitura;
            }
            | TK_CHAR TK_TYPE '(' TK_ID ')' ';'
            {
            
            string temp_associada = gentempcode("char");
            string nome_interno = adiciona_variavel_na_tabela($4.label, "char" , temp_associada);

            string comando_leitura;
            comando_leitura  = "\tcin >> " + nome_interno + ";\n";
            comando_leitura += "\tif (cin.fail()) {\n";
            comando_leitura += "\t\tcerr << \"Entrada inválida para tipo char!\" << endl;\n";
            comando_leitura += "\t\texit(1);\n\t}\n";
        
            $$.traducao = comando_leitura;
            }
            | TOKEN_STRING_TYPE TK_TYPE '(' TK_ID ')' ';'
            {
            
            string temp_associada = gentempcode("string");
            string nome_interno = adiciona_variavel_na_tabela($4.label, "string" , temp_associada);

            string comando_leitura;
            comando_leitura  = "\tcin >> " + nome_interno + ";\n";
            comando_leitura += "\tif (cin.fail()) {\n";
            comando_leitura += "\t\tcerr << \"Entrada inválida para tipo string!\" << endl;\n";
            comando_leitura += "\t\texit(1);\n\t}\n";
        
            $$.traducao = comando_leitura;
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
            | BEGIN_FOR IDENTIFICADOR_FOR '=' E ':' E BLOCO CLOSE_FOR {

                    if ($4.tipo != "int") {
                        yyerror("Início do for deve ser numérico (int)");
                    }

                    if ($6.tipo != "int") {
                        yyerror("Fim do for deve ser numérico (int)");
                    }

                    string label_inicio = pilha_loop_inicio.top();
                    string label_fim = pilha_loop_fim.top();
                    string label_incremento = pilha_loop_continue.top();

                    string nome_variavel = pega_variavel_na_tabela($2.label, "int");

                    $$.traducao = ""; 
                    $$.traducao += $4.traducao + $6.traducao;
                    $$.traducao += "\t" + nome_variavel + " = " + $4.label + ";\n";
                    $$.traducao += label_inicio + ":\n";

                    string pre_condicao = gentempcode("boolean");
                    string condicao = gentempcode("boolean");

                    $$.traducao += "\t" + pre_condicao + " = " + $6.label + " - 1;\n"; 
                    $$.traducao += "\t" + condicao + " = " + nome_variavel + " > " + pre_condicao + ";\n"; 
                    $$.traducao += "\tif (" + condicao + ") goto " + label_fim + ";\n";

                    $$.traducao += $7.traducao;  

                    $$.traducao += label_incremento + ":\n";
                    $$.traducao += "\t" + nome_variavel + " = " + nome_variavel + " + 1;\n";
                    $$.traducao += "\tgoto " + label_inicio + ";\n";

                    $$.traducao += label_fim + ":\n";

                     if (!pilha_loop_continue.empty()) pilha_loop_continue.pop();
                    if (!pilha_loop_inicio.empty()) pilha_loop_inicio.pop();
                    if (!pilha_loop_fim.empty()) pilha_loop_fim.pop();


                } | BEGIN_WHILE '(' E ')' LOOP_START_WHILE BLOCO CLOSE_WHILE {

                if($3.tipo != "boolean") {
                    yyerror("Erro na linha " + to_string(linha) + ": é necessária uma operação lógica ao utilizar o while");
                }

                string label_inicio = pilha_loop_inicio.top();
                string label_fim = pilha_loop_fim.top();


                $$.traducao = "";
                $$.traducao += label_inicio + ":\n";
                $$.traducao += $3.traducao;
                string condicao = gentempcode("boolean");
                $$.traducao += "\t" + condicao + " = !" + $3.label + ";\n";
                $$.traducao += "\tif (" + condicao + ") goto " + label_fim + ";\n";
                $$.traducao += $6.traducao;  // $6 é o BLOCO

                $$.traducao += "\tgoto " + label_inicio + ";\n";
                $$.traducao += label_fim + ":\n";

                pilha_loop_inicio.pop();
                pilha_loop_fim.pop();
            }
            | BEGIN_DO BLOCO TK_WHILE '(' E ')' ';' CLOSE_DO
                {
                    if($5.tipo != "boolean") {
                        yyerror("Erro: condição do 'do while' deve ser booleana");
                    }

                    string label_inicio = pilha_loop_inicio.top();
                    string label_fim = pilha_loop_fim.top();

                    string condicao = gentempcode("boolean");

                    $$.traducao = "";
                    $$.traducao += label_inicio + ":\n";
                    $$.traducao += $2.traducao;         
                    $$.traducao += $5.traducao;         
                    $$.traducao += "\t" + condicao + " = !" + $5.label + ";\n";
                    $$.traducao += "\tif (" + condicao + ") goto " + label_fim + ";\n";
                    $$.traducao += "\tgoto " + label_inicio + ";\n";
                    $$.traducao += label_fim + ":\n";

                       if (!pilha_loop_inicio.empty()) pilha_loop_inicio.pop();
                        if (!pilha_loop_fim.empty()) pilha_loop_fim.pop();
                        if (!pilha_loop_continue.empty()) pilha_loop_continue.pop();
                }

            | TK_BREAK ';' {

            if (pilha_loop_fim.empty()) {
                yyerror("Comando 'break' fora de um loop.");
            }

            $$.traducao = "\tgoto " + pilha_loop_fim.top() + ";\n";
            } 
            | TK_CONTINUE ';' {
               if (pilha_loop_continue.empty()) {
                    yyerror("Comando 'continue' fora de um loop.");
                } else {
                    cout << "DEBUG pilha continue top: " << pilha_loop_continue.top() << endl;
                    $$.traducao = "\tgoto " + pilha_loop_continue.top() + ";\n";
                }

            }
            ;


BEGIN_WHILE : TK_WHILE
                    {
                        esta_no_while = true;
                        qtdWhile++;
                        $$.label = "";
                        
                    }
                    ;

CLOSE_WHILE:
                    {
                        qtdWhile--;
                        if(qtdWhile == 0) {
                            esta_no_while = false;
                        }
                        $$.label = "";
                        
                    }
                    ;

IDENTIFICADOR_FOR : TK_ID 
                    {
                        string indice_for = gentempcode("int");
                        string nome_variavel = adiciona_variavel_na_tabela($1.label, "int", indice_for);
                        $$.label = $1.label;
                        
                    }
                    ;
BEGIN_FOR : TK_FOR
                    {
                        string label_inicio = nova_label("for", "inicio");
                        string label_fim = nova_label("for", "fim");
                        string label_incremento = nova_label("for", "incremento");

                        pilha_loop_inicio.push(label_inicio);
                        pilha_loop_fim.push(label_fim);
                        pilha_loop_continue.push(label_incremento);

                        esta_no_for = true;
                        qtdFor++;
                       
                       $$.label = label_inicio + "|" + label_fim + "|" + label_incremento;
                        
                    }
                    ;
CLOSE_FOR:
                    {
                        qtdFor--;
                        if(qtdFor == 0) {
                            esta_no_for = false;
                        }
                        $$.label = "";
                        
                    }
                    ;
LOOP_START_WHILE:
                    {
                        string label_inicio = nova_label("while", "inicio");
                        string label_fim = nova_label("while", "fim");

                        pilha_loop_inicio.push(label_inicio);
                        pilha_loop_fim.push(label_fim);

                        $$.label = label_inicio + "|" + label_fim;
                        
                    }
                    ;
BEGIN_DO: TK_DO
{
    string label_inicio = nova_label("do", "inicio");
    string label_fim = nova_label("do", "fim");

    pilha_loop_inicio.push(label_inicio);
    pilha_loop_fim.push(label_fim);
    pilha_loop_continue.push(label_inicio); 

    esta_no_do_while = true;
    qtdDoWhile++;

    $$.label = label_inicio + "|" + label_fim;
}
;

CLOSE_DO:
{
  
    qtdDoWhile--;
    if(qtdDoWhile == 0) {

        esta_no_do_while = false;
    }

    $$.label = "";
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
                
                if($1.tipo == "Var" || $3.tipo == "Var") {

                if($1.tipo == "Var" && $3.tipo != "Var") {
    
                    string pega_tipo = gentempcode("int");
                    string compara_tipo_int = gentempcode("int");
                    string compara_tipo_float = gentempcode("float");
                    string t_extra = gentempcode("float");
                    
    
                    int label_tipo_int = label_tipo++;
                    int label_tipo_float = label_tipo++;
                    int label_tipo_default = label_tipo++;
                    int fim_tipo = label_tipo++;
                    
                    $$.traducao =  $1.traducao +$3.traducao;         
                    $$.traducao += 
                    "\t" + pega_tipo + " = " + $1.label + "->tipo;\n" +
                    "\t" + compara_tipo_int + " = " + pega_tipo + " == 1;\n" +
                    "\tif (" + compara_tipo_int + ") goto tipo_int_" + to_string(label_tipo_int) + ";\n" +
                    "\t" + compara_tipo_float + " = " + pega_tipo + " == 2;\n" +
                    "\tif (" + compara_tipo_float + ") goto tipo_float_" + to_string(label_tipo_float) + ";\n" +
                    "\tgoto tipo_default_" + to_string(label_tipo_default) + ";\n\n" +
    
                    "tipo_int_" + to_string(label_tipo_int) + ":\n" +
                    "\t" + t_extra  + " = (float)" +  $1.label + "->i;\n" +
                    "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +
    
                    "tipo_float_" + to_string(label_tipo_float) + ":\n" +
                    "\t" + t_extra  + " = " +  $1.label + "->f;\n" +
                    "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +
    
                    "tipo_default_" + to_string(label_tipo_default) + ":\n" +
                    "\t" + t_extra + " = 0.0;\n" +
                    "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +
    
                    "fim_tipo_" + to_string(fim_tipo) + ":\n";
    
                    $$.label = gentempcode("float");
                    auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, "float");
                    $$.tipo = "float";
                    $$.traducao += "\t" + $$.label + " = " + t_extra + " + " + $3.label + ";\n";

                }
    
                 if($3.tipo == "Var" && $1.tipo != "Var") {
                        string pega_tipo = gentempcode("int");
                        string compara_tipo_int = gentempcode("int");
                        string compara_tipo_float = gentempcode("float");
                       
                        string t_extra = gentempcode("float");
                        
    
                        int label_tipo_int = label_tipo++;
                        int label_tipo_float = label_tipo++;
                        
                        int label_tipo_default = label_tipo++;
                        int fim_tipo = label_tipo++;

                        
                        $$.traducao = $1.traducao + $3.traducao;
                        $$.traducao += 
                        "\t" + pega_tipo + " = " + $3.label + "->tipo;\n" +
                        "\t" + compara_tipo_int + " = " + pega_tipo + " == 1;\n" +
                        "\tif (" + compara_tipo_int + ") goto tipo_int_" + to_string(label_tipo_int) + ";\n" +
                        "\t" + compara_tipo_float + " = " + pega_tipo + " == 2;\n" +
                        "\tif (" + compara_tipo_float + ") goto tipo_float_" + to_string(label_tipo_float) + ";\n" +
                        "\tgoto tipo_default_" + to_string(label_tipo_default) + ";\n\n" +
    
                        "tipo_int_" + to_string(label_tipo_int) + ":\n" +
                        "\t" + t_extra  + " = (float)" +  $3.label + "->i;\n" +
                        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +
    
                        "tipo_float_" + to_string(label_tipo_float) + ":\n" +
                        "\t" + t_extra  + " = " +  $3.label + "->f;\n" +
                        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +
    
                        "tipo_default_" + to_string(label_tipo_default) + ":\n" +
                        "\t" + t_extra + " = 0.0;\n" +
                        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +
    
                        "fim_tipo_" + to_string(fim_tipo) + ":\n";
    
                        $$.label = gentempcode("float");
                        auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, "float");
                        $$.tipo = "float";
                        $$.traducao += "\t" + $$.label + " = " + $1.label + " + " + t_extra + ";\n";
    
                 } else if ($1.tipo == "Var" && $3.tipo == "Var") {
                    // Gera labels e temporários para o primeiro operando
                    int label_tipo_int_1 = label_tipo++;
                    int label_tipo_float_1 = label_tipo++;
                    int label_tipo_default_1 = label_tipo++;
                    int fim_tipo_1 = label_tipo++;

                    string pega_tipo_1 = gentempcode("int");
                    string compara_tipo_int_1 = gentempcode("int");
                    string compara_tipo_float_1 = gentempcode("float");
                    string t_extra_1 = gentempcode("float");

                    // Gera labels e temporários para o segundo operando
                    int label_tipo_int_2 = label_tipo++;
                    int label_tipo_float_2 = label_tipo++;
                    int label_tipo_default_2 = label_tipo++;
                    int fim_tipo_2 = label_tipo++;

                    string pega_tipo_2 = gentempcode("int");
                    string compara_tipo_int_2 = gentempcode("int");
                    string compara_tipo_float_2 = gentempcode("float");
                    string t_extra_2 = gentempcode("float");

                    // Tradução do primeiro operando
                    $$.traducao = $1.traducao;
                    $$.traducao +=
                        "\t" + pega_tipo_1 + " = " + $1.label + "->tipo;\n" +
                        "\t" + compara_tipo_int_1 + " = " + pega_tipo_1 + " == 1;\n" +
                        "\tif (" + compara_tipo_int_1 + ") goto tipo_int_" + to_string(label_tipo_int_1) + ";\n" +
                        "\t" + compara_tipo_float_1 + " = " + pega_tipo_1 + " == 2;\n" +
                        "\tif (" + compara_tipo_float_1 + ") goto tipo_float_" + to_string(label_tipo_float_1) + ";\n" +
                        "\tgoto tipo_default_" + to_string(label_tipo_default_1) + ";\n\n" +

                        "tipo_int_" + to_string(label_tipo_int_1) + ":\n" +
                        "\t" + t_extra_1 + " = (float)" + $1.label + "->i;\n" +
                        "\tgoto fim_tipo_" + to_string(fim_tipo_1) + ";\n\n" +

                        "tipo_float_" + to_string(label_tipo_float_1) + ":\n" +
                        "\t" + t_extra_1 + " = " + $1.label + "->f;\n" +
                        "\tgoto fim_tipo_" + to_string(fim_tipo_1) + ";\n\n" +

                        "tipo_default_" + to_string(label_tipo_default_1) + ":\n" +
                        "\t" + t_extra_1 + " = 0.0;\n" +
                        "\tgoto fim_tipo_" + to_string(fim_tipo_1) + ";\n\n" +

                        "fim_tipo_" + to_string(fim_tipo_1) + ":\n";

                    // Tradução do segundo operando
                    $$.traducao += $3.traducao;
                    $$.traducao +=
                        "\t" + pega_tipo_2 + " = " + $3.label + "->tipo;\n" +
                        "\t" + compara_tipo_int_2 + " = " + pega_tipo_2 + " == 1;\n" +
                        "\tif (" + compara_tipo_int_2 + ") goto tipo_int_" + to_string(label_tipo_int_2) + ";\n" +
                        "\t" + compara_tipo_float_2 + " = " + pega_tipo_2 + " == 2;\n" +
                        "\tif (" + compara_tipo_float_2 + ") goto tipo_float_" + to_string(label_tipo_float_2) + ";\n" +
                        "\tgoto tipo_default_" + to_string(label_tipo_default_2) + ";\n\n" +

                        "tipo_int_" + to_string(label_tipo_int_2) + ":\n" +
                        "\t" + t_extra_2 + " = (float)" + $3.label + "->i;\n" +
                        "\tgoto fim_tipo_" + to_string(fim_tipo_2) + ";\n\n" +

                        "tipo_float_" + to_string(label_tipo_float_2) + ":\n" +
                        "\t" + t_extra_2 + " = " + $3.label + "->f;\n" +
                        "\tgoto fim_tipo_" + to_string(fim_tipo_2) + ";\n\n" +

                        "tipo_default_" + to_string(label_tipo_default_2) + ":\n" +
                        "\t" + t_extra_2 + " = 0.0;\n" +
                        "\tgoto fim_tipo_" + to_string(fim_tipo_2) + ";\n\n" +

                        "fim_tipo_" + to_string(fim_tipo_2) + ":\n";

                    // Soma dos dois valores
                    $$.label = gentempcode("float");
                    $$.tipo = "float";
                    $$.traducao += "\t" + $$.label + " = " + t_extra_1 + " + " + t_extra_2 + ";\n";
                }

                 } else {

                     auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, tipo);
                     $$.tipo = tipo;
                     cout << "oi t16 é: " + $3.tipo <<endl; 
                     $$.traducao = $1.traducao + $3.traducao + coercoes + "\t" + $$.label + " = " + t1 + " + " + t2 + ";\n";
                 }

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
                $$.tipo = $2.tipo;
            }
            |   E GREATER_THAN E 
            {   
                string tipo = resolve_tipo($1.tipo, $3.tipo);
                auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, tipo);
                $$.label = gentempcode(tipo);
                $$.tipo = "boolean";
                $$.traducao = $1.traducao + $3.traducao + coercoes + "\t" + $$.label + " = " + t1 + " > " + t2 + ";\n";
                if ($1.var_original != "") $$.var_original = $1.var_original;
                else if ($3.var_original != "") $$.var_original = $3.var_original;
            }
            | E LESS_THAN E 
    {   
                string tipo = resolve_tipo($1.tipo, $3.tipo);
                $$.label = gentempcode("boolean");
                $$.tipo = "boolean";

                string t1 = $1.label;
                string t2 = $3.label;
                string coercoes;

                string bloco1 = "", bloco2 = "";

                
                if ($1.tipo == "Var") {
                    string t_extra1 = gentempcode("float");
                    string pega_tipo = gentempcode("int");
                    string compara_tipo_int = gentempcode("int");
                    string compara_tipo_float = gentempcode("float");
                    string compara_tipo_bool = gentempcode("bool");

                    int label_tipo_int = label_tipo++;
                    int label_tipo_float = label_tipo++;
                    int label_tipo_boolean = label_tipo++;
                    int label_tipo_default = label_tipo++;
                    int fim_tipo = label_tipo++;

                    bloco1 += 
                        "\t" + pega_tipo + " = " + $1.label + "->tipo;\n" +
                        "\t" + compara_tipo_int + " = " + pega_tipo + " == 1;\n" +
                        "\tif (" + compara_tipo_int + ") goto tipo_int_" + to_string(label_tipo_int) + ";\n" +
                        "\t" + compara_tipo_float + " = " + pega_tipo + " == 2;\n" +
                        "\tif (" + compara_tipo_float + ") goto tipo_float_" + to_string(label_tipo_float) + ";\n" +
                        "\tgoto tipo_default_" + to_string(label_tipo_default) + ";\n\n" +

                        "tipo_int_" + to_string(label_tipo_int) + ":\n" +
                        "\t" + t_extra1  + " = (float)" +  $1.label + "->i;\n" +
                        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +

                        "tipo_float_" + to_string(label_tipo_float) + ":\n" +
                        "\t" + t_extra1  + " = " +  $1.label + "->f;\n" +
                        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +

                        "tipo_default_" + to_string(label_tipo_default) + ":\n" +
                        "\t" + t_extra1 + " = 0.0;\n" +
                        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +

                        "fim_tipo_" + to_string(fim_tipo) + ":\n";

                    t1 = t_extra1;
                }

                
                if ($3.tipo == "Var") {
                    string t_extra2 = gentempcode("float");
                    string pega_tipo = gentempcode("int");
                    string compara_tipo_int = gentempcode("int");
                    string compara_tipo_float = gentempcode("float");
                    string compara_tipo_bool = gentempcode("bool");

                    int label_tipo_int = label_tipo++;
                    int label_tipo_float = label_tipo++;
                    int label_tipo_boolean = label_tipo++;
                    int label_tipo_default = label_tipo++;
                    int fim_tipo = label_tipo++;

                    bloco2 += 
                        "\t" + pega_tipo + " = " + $3.label + "->tipo;\n" +
                        "\t" + compara_tipo_int + " = " + pega_tipo + " == 1;\n" +
                        "\tif (" + compara_tipo_int + ") goto tipo_int_" + to_string(label_tipo_int) + ";\n" +
                        "\t" + compara_tipo_float + " = " + pega_tipo + " == 2;\n" +
                        "\tif (" + compara_tipo_float + ") goto tipo_float_" + to_string(label_tipo_float) + ";\n" +
                        "\tgoto tipo_default_" + to_string(label_tipo_default) + ";\n\n" +

                        "tipo_int_" + to_string(label_tipo_int) + ":\n" +
                        "\t" + t_extra2  + " = (float)" +  $3.label + "->i;\n" +
                        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +

                        "tipo_float_" + to_string(label_tipo_float) + ":\n" +
                        "\t" + t_extra2  + " = " +  $3.label + "->f;\n" +
                        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +

                        "tipo_default_" + to_string(label_tipo_default) + ":\n" +
                        "\t" + t_extra2 + " = 0.0;\n" +
                        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +

                        "fim_tipo_" + to_string(fim_tipo) + ":\n";

                    t2 = t_extra2;
                }

                // Se nenhum for Var, faz coerção normalmente
                if ($1.tipo != "Var" && $3.tipo != "Var") {
                    tie(coercoes, t1, t2) = resolve_coercao($1.label, $3.label, tipo);
                }

                $$.traducao = $1.traducao + $3.traducao + bloco1 + bloco2 + coercoes;
                $$.traducao += "\t" + $$.label + " = " + t1 + " < " + t2 + ";\n";

                if ($1.var_original != "") $$.var_original = $1.var_original;
                else if ($3.var_original != "") $$.var_original = $3.var_original;
            }

            |   E GREATER_OR_EQUAL E 
            {   
                string tipo = resolve_tipo($1.tipo, $3.tipo);
                auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, tipo);
                $$.label = gentempcode(tipo);
                $$.tipo = "boolean";
                $$.traducao = $1.traducao + $3.traducao + coercoes + "\t" + $$.label + " = " + t1 + " >= " + t2 + ";\n";
                if ($1.var_original != "") $$.var_original = $1.var_original;
                else if ($3.var_original != "") $$.var_original = $3.var_original;
            }
            |   E LESS_OR_EQUAL E 
            {   
                string tipo = resolve_tipo($1.tipo, $3.tipo);
                auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, tipo);
                $$.label = gentempcode(tipo);
                $$.tipo = "boolean";
                $$.traducao = $1.traducao + $3.traducao + coercoes + "\t" + $$.label + " = " + t1 + " <= " + t2 + ";\n";
                if ($1.var_original != "") $$.var_original = $1.var_original;
                else if ($3.var_original != "") $$.var_original = $3.var_original;
            }
            |   E EQUAL E 
            {   
                string tipo = resolve_tipo($1.tipo, $3.tipo);
                auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, tipo);
                $$.label = gentempcode(tipo);
                $$.tipo = "boolean";
                $$.traducao = $1.traducao + $3.traducao + coercoes + "\t" + $$.label + " = " + t1 + " == " + t2 + ";\n";
                if ($1.var_original != "") $$.var_original = $1.var_original;
                else if ($3.var_original != "") $$.var_original = $3.var_original;
            }
            |   E NOT_EQUAL E 
            {   
                string tipo = resolve_tipo($1.tipo, $3.tipo);
                auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, tipo);
                $$.label = gentempcode(tipo);
                $$.tipo = "boolean";
                $$.traducao = $1.traducao + $3.traducao + coercoes + "\t" + $$.label + " = " + t1 + " != " + t2 + ";\n";
                if ($1.var_original != "") $$.var_original = $1.var_original;
                else if ($3.var_original != "") $$.var_original = $3.var_original;
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

                string nome_variavel = "";

                if(!esta_no_while && !esta_no_for && !esta_no_do_while) {
                    
                      nome_variavel = pega_variavel_na_tabela($1.label, $3.tipo);
                        if(nome_variavel == "") {
                            nome_variavel = adiciona_variavel_na_tabela($1.label, $3.tipo, $3.label);
                            string formata_variavel_escopo = $1.label + "_global";
                            variavel_escopo[formata_variavel_escopo] = nome_variavel;
                            mudou_tipo[nome_variavel] = false;
                    }
                    
                } else {
                    nome_variavel = pega_variavel_na_tabela($1.label, $3.tipo);
                    if(nome_variavel == "") {
                        nome_variavel = adiciona_variavel_na_tabela($1.label, $3.tipo, $3.label);
                        mudou_tipo[nome_variavel] = false;
                    } 
                        string formata_variavel_escopo = $1.label + "_local";
                        variavel_escopo[formata_variavel_escopo] = nome_variavel;
                }
                
                if($3.tipo == "string") {
                    
                    if(realocar_var_interna.count(nome_variavel)){
                         $$.traducao = "\tfree(" + nome_variavel + ");\n";
                    }
                    
                    realocar_var_interna[nome_variavel] = true;
                    $$.traducao = $1.traducao + $3.traducao + "\t" + nome_variavel + " = (Var *) malloc(sizeof(Var));\n";
                    $$.traducao += "\t" + nome_variavel + "->tipo = 5;\n"; 
                    $$.traducao += "\t" + nome_variavel + "->s = (char *) malloc(" + tamanho_string[$3.label] + ");\n"; 
                    $$.traducao += "\tstrcpy(" + nome_variavel + "->s" + "," + $3.label + ");\n";
                    mudou_tipo[nome_variavel] = true;
                    edita_tipo_na_tabela($1.label, "string", $3.label);
                    
                } else {
                    if(esta_no_while || esta_no_for || esta_no_do_while) {
                        if((variavel_escopo.count($1.label + "_global")) && (variavel_escopo.count($1.label + "_local"))) {
                            $$.traducao = $1.traducao + $3.traducao + "\t" + variavel_escopo[$1.label + "_global"] + " = " + $3.label + ";\n";
                        }
                    }
                        if (!mudou_tipo[nome_variavel]) {
                        $$.traducao = $1.traducao + $3.traducao;
                        $$.traducao += "\t" + nome_variavel + " = (Var *) malloc(sizeof(Var));\n";
                        mudou_tipo[nome_variavel] = true;
                    } else {
                        $$.traducao = $1.traducao + $3.traducao;
                    }

                    int tipo = $3.tipo == "int" ? 1 :
                                $3.tipo == "float" ? 2 :
                                $3.tipo == "boolean" ? 3 :
                                $3.tipo == "char" ? 4 : 0;

                    $$.traducao += "\t" + nome_variavel + "->tipo = " + to_string(tipo) + ";\n";

                    switch (tipo) {
                        case 1:
                            $$.traducao += "\t" + nome_variavel + "->i = " + $3.label + ";\n";
                            edita_tipo_na_tabela($1.label, "int", $3.label);
                            break;
                        case 2:
                            $$.traducao += "\t" + nome_variavel + "->f = " + $3.label + ";\n";
                            edita_tipo_na_tabela($1.label, "float", $3.label);
                            break;
                        case 3:
                            $$.traducao += "\t" + nome_variavel + "->b = " + $3.label + ";\n";
                            edita_tipo_na_tabela($1.label, "boolean", $3.label);
                            break;
                        case 4:
                            $$.traducao += "\t" + nome_variavel + "->c = " + $3.label + ";\n";
                            edita_tipo_na_tabela($1.label, "char", $3.label);
                            break;
                    }

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
                $$.label = gentempcode("Var");
                string nome_interno = pega_variavel_na_tabela($1.label, tipo);
                $$.var_original = nome_interno;
                $$.tipo="Var";

                
                    $$.traducao += "\t" + $$.label + " = (Var *) malloc(sizeof(Var));\n";
            

                if(tipo == "string") {
                        $$.traducao = realizar_contagem(nome_interno, $$.label);
                        $$.traducao += "\t" + $$.label + "->s = " + "(char *) malloc(" + tamanho_string[$$.label] + ");\n";
                        $$.traducao += "\tstrcpy(" + $$.label + "->s, " + nome_interno + ");\n";
                } else {

                    if(esta_no_while) {
                        
                        
                        string pega_tipo = gentempcode("int");
                        string compara_tipo_int = gentempcode("int");
                        string compara_tipo_float = gentempcode("float");
                        string compara_tipo_bool = gentempcode("bool");
                        
    
                        int label_tipo_int = label_tipo++;
                        int label_tipo_float = label_tipo++;
                        int label_tipo_boolean = label_tipo++;
                        int label_tipo_default = label_tipo++;
                        int fim_tipo = label_tipo++;
                       
                      
                                           
                       $$.traducao += 
                        "\t" + pega_tipo + " = " + nome_interno + "->tipo;\n" +
                        "\t" + compara_tipo_int + " = " + pega_tipo + " == 1;\n" +
                        "\tif (" + compara_tipo_int + ") goto tipo_int_" + to_string(label_tipo_int) + ";\n" +
                        "\t" + compara_tipo_float + " = " + pega_tipo + " == 2;\n" +
                        "\tif (" + compara_tipo_float + ") goto tipo_float_" + to_string(label_tipo_float) + ";\n" +
                        "\t" + compara_tipo_bool + " = " + pega_tipo + " == 3;\n" +
                        "\tif (" + compara_tipo_bool + ") goto tipo_bool_" + to_string(label_tipo_boolean) + ";\n" +
                        "\tgoto tipo_default_" + to_string(label_tipo_default) + ";\n\n" +
    
                        "tipo_int_" + to_string(label_tipo_int) + ":\n" +
                        "\t" + $$.label + "->tipo = " + nome_interno + "->tipo;\n" +
                        "\t" + $$.label + "->i = " + nome_interno + "->i;\n" +
                        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +
    
                        "tipo_float_" + to_string(label_tipo_float) + ":\n" +
                        "\t" + $$.label + "->tipo = " + nome_interno + "->tipo;\n" +
                        "\t" + $$.label + "->f = " + nome_interno + "->f;\n" +
                        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +
    
                        "tipo_bool_" + to_string(label_tipo_boolean) + ":\n" +
                        "\t" + $$.label + "->tipo = " + nome_interno + "->tipo;\n" + 
                        "\t" + $$.label + "->b = " + nome_interno + "->b;\n" + 
                        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +
    
                        "tipo_default_" + to_string(label_tipo_default) + ":\n" +
                        "\t" + $$.label + "->f = 0.0;\n" +
                        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +
    
                        "fim_tipo_" + to_string(fim_tipo) + ":\n";

                      
    
                    } else {
    
                        int tipo_var = tipo_var_dinamica(tipo);
        
                        switch(tipo_var) {
                            case 1:
                            $$.traducao = "\t" + $$.label + "->i = " + nome_interno + "->i;\n";
                            break;
        
                            case 2:
                            $$.traducao = "\t" + $$.label + "->f = " + nome_interno + "->f;\n";
                            break;
        
                            case 3:
                            $$.traducao = "\t" + $$.label + "->b = " + nome_interno + "->b;\n";
                            break;
        
                            case 4:
                            $$.traducao = "\t" + $$.label + "c = " + nome_interno + "->c;\n";
                            break;
                            
                        }
    
                    }
                    
                }



                
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

    string variavel_formatada = variavel;
    
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
    tipos_atuais[variavel].nome_interno = nome_interno;


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

    else if(tipo == "incremento") {
        label_incremento++;
        return comando + "_" + tipo + "_" + to_string(label_incremento);
    }

    return "";
}


string pega_variavel_na_tabela(string nome_variavel, string tipo) {

    string variavel_formatada = nome_variavel;

     for (auto it = pilha_escopos.rbegin(); it != pilha_escopos.rend(); ++it) {
        if (it->count(variavel_formatada)) {
            return it->at(variavel_formatada).nome_interno;
        }
    }

   for (auto& escopo : escopos_passados) {
        if (escopo.count(variavel_formatada)) {
            if(variavel_escopo.count(nome_variavel + "_global")) {
                return escopo[variavel_formatada].nome_interno;
            }
            yyerror("Erro na linha " + to_string(linha) + ": variável '" + nome_variavel + "' está fora do escopo previamente declarado");
        }
    }

    if(esta_no_while || esta_no_for || esta_no_do_while) {
        return "";
    }

    
    return "";
}

bool edita_tipo_na_tabela(string variavel, string novo_tipo, string novo_temp_associada) {
    if (pilha_escopos.empty()) return false; // não tem escopo ativo

    auto& escopo_atual = pilha_escopos.back();

    if (escopo_atual.count(variavel)) {
        escopo_atual[variavel].tipo = novo_tipo;
        escopo_atual[variavel].temp_associada = novo_temp_associada;

        // Atualiza também o tipos_atuais, se existir
        if (tipos_atuais.count(variavel)) {
            tipos_atuais[variavel].tipo = novo_tipo;
            tipos_atuais[variavel].temp_associada = novo_temp_associada;
        }
        return true;
    }

    return false; // variável não encontrada no escopo atual
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

int tipo_var_dinamica(string tipo) {

    return tipo == "int" ? : tipo == "float" ? 2 : tipo == "boolean" ? 3 : tipo == "char" ? 4 : 5;

}

void verifica_tipo_logico(string tipo1, string tipo2) {
   
    if(tipo1 != "boolean" || tipo2 != "boolean") {
         yyerror("Erro na linha " + to_string(linha) + ": "+ "Não é possível realizar o operador && entre variáveis não booleanas");
    }
    
}

string fim_if(){
    return "fim_if_" + to_string(++contador_if);
}

string fim_else(){
    return "fim_else_" + to_string(++contador_else);
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
