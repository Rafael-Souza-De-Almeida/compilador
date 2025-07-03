%{
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <tuple>
#include<vector>
#include <fstream>
#include<stack>
#include <unordered_map>


#define YYSTYPE atributos

using namespace std;


int var_temp_qnt;
int linha = 0;
int label_inicio = 0;
int label_fim = 0;
int label_incremento = 0;
int contador_if = 0;
int contador_else=0;
bool esta_no_escopo = false;
int contador_label = 0;
int contador_temp = 0;


struct atributos {
    string label;
    string traducao;
    string tipo;
    string escopo;
};

struct Simbolo {
    string nome_interno;
    string tipo;
    string temp_associada;
    string escopo;

};

struct Simbolos_atuais {
    string tipo;
    string temp_associada;
    string nome_interno;
    string escopo;
    
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
int contador_escopos = 0;


map<string, bool> realocar_var_interna;
vector<unordered_map<string, Simbolo>> pilha_escopos;
vector<unordered_map<string, Simbolo>> pilha_funcao;
vector<unordered_map<string, Simbolo>> escopos_passados;
vector<Simbolo> simbolos_declarados;
stack<string> pilha_loop_inicio;
stack<string> pilha_loop_fim;
stack<string> pilha_loop_continue;
stack<string> pilha_fim_loop_mais_externo;
int var_user_qnt;
bool origem_declarada = false;


int yylex(void);
void yyerror(string);
void entra_escopo();
void entra_funcao(string);
void sai_funcao();
void sai_escopo();
void verifica_tipo_relacional(string tipo1, string tipo2);
string gentempcode(string);
string adiciona_variavel_na_tabela(string, string, string, string, string);
string pega_variavel_na_tabela(string);
string resolve_tipo(string, string);
tuple<string, string, string> resolve_coercao(string, string, string);
void verifica_tipo(string, string, string);
void verifica_tipo_logico(string, string);
string getTipo(string);
string realizar_contagem(string, string);
void verifica_operacao_string(string, string, string);
string nova_label(string, string);
string pega_escopo_da_variavel(string, string);
string pega_variavel_dinamica(string, string);
string pega_variavel_global(string);
string fim_if();
string fim_else();
bool isGlobal(string);
string novo_label(string);

%}

%token TK_NUM TK_REAL TK_TRUE TK_FALSE
%token TK_MAIN TK_ID TK_FUNCTION
%token TK_INT TK_FLOAT  TK_BOOLEAN TK_CHAR TK_STRING
%token TK_FIM TK_ERROR TK_PRINT TK_PRINTLN TK_LINHA
%token GREATER_THAN LESS_THAN GREATER_OR_EQUAL LESS_OR_EQUAL EQUAL NOT_EQUAL NOT AND OR
%token TK_IF TK_ELSE TK_FOR TK_WHILE TK_DO TK_SWITCH TK_LOCAL TK_DYNAMIC
%token TK_CONTINUE TK_BREAK
%token TK_INC TK_DEC
%token TK_BREAKALL


%start S

%left '+' '-'
%left '*' '/' 
%left OR
%left AND
%right NOT

%%

S           : LISTA_DECLARACOES
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

                codigo += "\tgoto label_main;\n";
                codigo += $1.traducao;             
                codigo += "end_main:\n";              

              

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

LISTA_DECLARACOES : DECLARACAO LISTA_DECLARACOES
    {
        $$.traducao = $1.traducao + $2.traducao;
    }
    | /* vazio */
    {
        $$.traducao = "";
    }
    ;

DECLARACAO : TK_FUNCTION TK_MAIN '(' ')' {entra_funcao("main");} BLOCO {sai_funcao();} {

        $$.traducao = "label_main:\n";   
        $$.traducao += $6.traducao;
        

    }
    | TK_FUNCTION TK_ID '(' ')' {entra_funcao("funcao_" + $1.label);} BLOCO {sai_funcao();}
    {
        $$.traducao = "label_" + $2.label + ":\n";
        $$.traducao += $6.traducao;
        $$.traducao += "goto end_" + $2.label + ";\n\n";
        
    }
    ;

BLOCO       : '{' {entra_escopo();} COMANDOS '}' CLOSE_BLOCO{ 
    
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
                string escopo_atual = pilha_escopos.back()["__escopo_nome__"].nome_interno;
                string funcao_atual = pilha_funcao.back()["__funcao_nome__"].nome_interno;
                string nome_interno = tipos_atuais[$1.label + "_" + escopo_atual + "_" + funcao_atual].nome_interno;
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
                | BEGIN_FOR '(' COMANDO E ';' E ')' BLOCO CLOSE_FOR
                {
                    // Gera labels e empilha
                    string label_inicio = pilha_loop_inicio.top();
                    string label_fim = pilha_loop_fim.top();
                    string label_incremento = pilha_loop_continue.top();

                    
                    $$.traducao = $3.traducao;

                    
                    $$.traducao += label_inicio + ":\n";

                   
                    string temp_cond_pre = gentempcode("boolean");
                    string temp_cond = gentempcode("boolean");

                    
                    $$.traducao += $4.traducao;                    

                    
                    $$.traducao += "\t" + temp_cond + " = " + $4.label + ";\n";

                    
                    $$.traducao += "\tif (!" + temp_cond + ") goto " + label_fim + ";\n";

                    
                    $$.traducao += $8.traducao;

                   
                    $$.traducao += label_incremento + ":\n";

                  
                    $$.traducao += $6.traducao;

                    
                    $$.traducao += "\tgoto " + label_inicio + ";\n";

                    
                    $$.traducao += label_fim + ":\n";

                    if (!pilha_loop_inicio.size()) {
                        pilha_fim_loop_mais_externo.pop(); 
                    }
                   
                    if (!pilha_loop_continue.empty()) pilha_loop_continue.pop();
                    if (!pilha_loop_inicio.empty()) pilha_loop_inicio.pop();
                    if (!pilha_loop_fim.empty()) pilha_loop_fim.pop();

                }

            | BEGIN_FOR IDENTIFICADOR_FOREACH '=' E ':' E BLOCO CLOSE_FOR {

                    if ($4.tipo != "int") {
                        yyerror("Início do foreach deve ser numérico (int)");
                    }

                    if ($6.tipo != "int") {
                        yyerror("Fim do foreach deve ser numérico (int)");
                    }

                    string label_inicio = pilha_loop_inicio.top();
                    string label_fim = pilha_loop_fim.top();
                    string label_incremento = pilha_loop_continue.top();

                    string nome_variavel = pega_variavel_na_tabela($2.label);

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

                     if (!pilha_loop_inicio.size()) {
                        pilha_fim_loop_mais_externo.pop(); 
                    }

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

                 if (!pilha_loop_inicio.size()) {
                        pilha_fim_loop_mais_externo.pop(); 
                    }

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
                    $$.traducao += $2.traducao;         // BLOCO
                    $$.traducao += $5.traducao;         // condição
                    $$.traducao += "\t" + condicao + " = !" + $5.label + ";\n";
                    $$.traducao += "\tif (" + condicao + ") goto " + label_fim + ";\n";
                    $$.traducao += "\tgoto " + label_inicio + ";\n";
                    $$.traducao += label_fim + ":\n";

                    if (!pilha_loop_inicio.size()) {
                        pilha_fim_loop_mais_externo.pop(); 
                    }


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

            } | TK_BREAKALL ';'
                   {
                       if (pilha_fim_loop_mais_externo.empty()) {
                           yyerror("Uso inválido de 'break all' fora de qualquer laço.");
                           exit(1);
                       }
                   
                       string label_fim_externo = pilha_fim_loop_mais_externo.top();
                       $$.traducao = "\tgoto " + label_fim_externo + ";\n";
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

IDENTIFICADOR_FOREACH : TK_ID 
                    {
                        string indice_for = gentempcode("int");
                        string escopo_atual = pilha_escopos.back()["__escopo_nome__"].nome_interno;
                        string funcao_atual = pilha_funcao.back()["__funcao_nome__"].nome_interno;
                        string nome_variavel = adiciona_variavel_na_tabela($1.label, "int", indice_for, escopo_atual, funcao_atual);
                        $$.label = $1.label;
                        
                    }
                    ;
BEGIN_FOR : TK_FOR
                    {
                        string label_inicio = nova_label("for", "inicio");
                        string label_fim = nova_label("for", "fim");
                        string label_incremento = nova_label("for", "incremento");

                        if (pilha_fim_loop_mais_externo.empty()) {
                            pilha_fim_loop_mais_externo.push(label_fim);  
                        }

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

                        if (pilha_fim_loop_mais_externo.empty()) {
                            pilha_fim_loop_mais_externo.push(label_fim);  
                        }

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

    if (pilha_fim_loop_mais_externo.empty()) {
        pilha_fim_loop_mais_externo.push(label_fim);  
    }

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

CLOSE_BLOCO: {
    sai_escopo();
}




                    
           
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
                $$.tipo = $2.tipo;
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
                $$.label = gentempcode("boolean");
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

         | TK_ID '=' E
            {
                string escopo_atual = pilha_escopos.back()["__escopo_nome__"].nome_interno;
                string funcao_atual = pilha_funcao.back()["__funcao_nome__"].nome_interno;
                string chave = $1.label + "_" + escopo_atual + funcao_atual;
                string nome_interno;
                bool variavel_local = false;
                bool variavel_global = false;

                
                if (tipos_atuais.count(chave)) {
                    nome_interno = tipos_atuais[chave].nome_interno;
                    variavel_local = true;
                }
                else {
                    string chave_global = $1.label + "_escopo0" + "_" + funcao_atual;
                    if (tipos_atuais.count(chave_global)) {
                        nome_interno = tipos_atuais[chave_global].nome_interno;
                        variavel_global = true;
                    }
                    
                    else {
                        nome_interno = adiciona_variavel_na_tabela($1.label, $3.tipo, $3.label, escopo_atual, funcao_atual);
                        variavel_local = true;
                    }
                }

               
                string tipo_atual = getTipo($1.label);  
                string novo_tipo = $3.tipo;

                if (tipo_atual != novo_tipo) {
                    if (variavel_local) {
                        
                        nome_interno = adiciona_variavel_na_tabela($1.label, novo_tipo, $3.label, escopo_atual, funcao_atual);
                    } else if (variavel_global) {
                        
                        yyerror("Erro: não pode alterar tipo da variável global '" + $1.label + "' em escopo diferente.");
                        exit(1);
                    }
                }


                if (novo_tipo == "string") {
                    if (realocar_var_interna.count(nome_interno)) {
                        $$.traducao = "\tfree(" + nome_interno + ");\n";
                    }
                    realocar_var_interna[nome_interno] = true;

                    $$.traducao += $1.traducao + $3.traducao;
                    $$.traducao += "\t" + nome_interno + " = (char *) malloc(" + tamanho_string[$3.label] + ");\n";
                    $$.traducao += "\tstrcpy(" + nome_interno + ", " + $3.label + ");\n";
                } else {
                    $$.traducao = $1.traducao + $3.traducao;
                    $$.traducao += "\t" + nome_interno + " = " + $3.label + ";\n";
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
            {   string escopo_atual = pilha_escopos.back()["__escopo_nome__"].nome_interno;
                string tipo = getTipo($1.label); 
                $$.label = gentempcode(tipo);
                string nome_interno = pega_variavel_na_tabela($1.label);
                $$.traducao = "\t" + $$.label + " = " + nome_interno + ";\n";
                $$.tipo=tipo;

                if(tipo == "string") {
                    
                    $$.traducao = realizar_contagem(nome_interno, $$.label);
                    string tamanho = gentempcode("int");
                    $$.traducao += "\t" + tamanho + " = " + tamanho_string[$$.label]  + " + 1;\n";
                    tamanho_string[$$.label] = tamanho;
                    $$.traducao += "\t" + $$.label + " = " + "(char *) malloc(" + tamanho_string[$$.label] + ");\n";
                    $$.traducao += "\tstrcpy(" + $$.label + "," + nome_interno + ");\n";
                }
  
            }
           
            | TK_LOCAL TK_ID '=' E
            {
                
                string escopo_atual = pilha_escopos.back()["__escopo_nome__"].nome_interno;
                string funcao_atual = pilha_funcao.back()["__funcao_nome__"].nome_interno;

                string nome_variavel = adiciona_variavel_na_tabela($2.label, $4.tipo, $4.label, escopo_atual, funcao_atual);

                variavel_escopo[$2.label + "_" + escopo_atual] = nome_variavel;
                $$.escopo = escopo_atual;

                if ($4.tipo == "string") {
                    if (realocar_var_interna.count(nome_variavel)) {
                        $$.traducao = "\tfree(" + nome_variavel + ");\n";
                    }
                    realocar_var_interna[nome_variavel] = true;
                    $$.traducao += $2.traducao + $4.traducao + "\t" + nome_variavel + " = (char *) malloc(" + tamanho_string[$4.label] + ");\n";
                    $$.traducao += "\tstrcpy(" + nome_variavel + ", " + $4.label + ");\n";
                } else {
                    $$.traducao = $2.traducao + $4.traducao + "\t" + nome_variavel + " = " + $4.label + ";\n";
                }
            }

             | TK_DYNAMIC TK_ID '=' E
            {
               
                string tipo = getTipo($2.label);
                string nome_interno;
                string escopo_atual = pilha_escopos.back()["__escopo_nome__"].nome_interno;
                string funcao_atual = pilha_funcao.back()["__funcao_nome__"].nome_interno;

                if(tipo != $4.tipo) {
                    nome_interno = adiciona_variavel_na_tabela($2.label, $4.tipo, $4.label, escopo_atual, funcao_atual);
                } else {
                    nome_interno = pega_variavel_dinamica($2.label, tipo);
                }

                if ($4.tipo == "string") {
                    if (realocar_var_interna.count(nome_interno)) {
                        $$.traducao = "\tfree(" + nome_interno + ");\n";
                    }
                    realocar_var_interna[nome_interno] = true;
                    $$.traducao += $2.traducao + $4.traducao + "\t" + nome_interno + " = (char *) malloc(" + tamanho_string[$4.label] + ");\n";
                    $$.traducao += "\tstrcpy(" + nome_interno + ", " + $4.label + ");\n";
                } else {
                    $$.traducao = $2.traducao + $4.traducao + "\t" + nome_interno + " = " + $4.label + ";\n";
                }
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
            | TK_ID TK_INC 
            {
                string nome_interno = pega_variavel_na_tabela($1.label);
                $$.traducao = "\t" + nome_interno + " = " + nome_interno + " + 1;\n";
            }
            | TK_ID TK_DEC
            {
                string nome_interno = pega_variavel_na_tabela($1.label);
                $$.traducao = "\t" + nome_interno + " = " + nome_interno + " - 1;\n";
            } 
            | TK_ID '(' ')' {
                $$.traducao = "\tgoto label_" + $1.label + ";\n";
                $$.traducao += "end_" + $1.label + ":\n";
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

string getTipo(string nome_variavel) {
    for (auto escopo_it = pilha_escopos.rbegin(); escopo_it != pilha_escopos.rend(); ++escopo_it) {
        if (!escopo_it->count("__escopo_nome__")) continue;
        string escopo = escopo_it->at("__escopo_nome__").nome_interno;

        for (auto funcao_it = pilha_funcao.rbegin(); funcao_it != pilha_funcao.rend(); ++funcao_it) {
            if (!funcao_it->count("__funcao_nome__")) continue;
            string funcao = funcao_it->at("__funcao_nome__").nome_interno;

            string chave = nome_variavel + "_" + escopo + "_" + funcao;

            if (escopo_it->count(chave)) {
                string tipo = escopo_it->at(chave).tipo;
                if (tipo == "") {
                    yyerror("Erro: variável '" + nome_variavel + "' não inicializada.");
                    exit(1);
                }
                return tipo;
            }
        }
    }

    // Tenta buscar nos escopos passados
    for (auto& escopo : escopos_passados) {
        if (!escopo.count("__escopo_nome__")) continue;
        string escopo_nome = escopo.at("__escopo_nome__").nome_interno;

        for (auto& funcao_map : pilha_funcao) {
            if (!funcao_map.count("__funcao_nome__")) continue;
            string funcao = funcao_map.at("__funcao_nome__").nome_interno;

            string chave = nome_variavel + "_" + escopo_nome + "_" + funcao;

            if (escopo.count(chave)) {
                string tipo = escopo.at(chave).tipo;
                if (tipo == "") {
                    yyerror("Erro: variável '" + nome_variavel + "' não inicializada.");
                    exit(1);
                }
                return tipo;
            }
        }
    }

    throw std::runtime_error("Erro: variável '" + nome_variavel + "' não foi declarada.");
}

bool isGlobal(string nome_variavel) {
    if (pilha_escopos.empty()) return false;
    auto& escopo_global = pilha_escopos.front(); 
    for (auto& [chave, simbolo] : escopo_global) {
        if (chave.find(nome_variavel + "_") == 0) {
            return true;
        }
    }
    return false;
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


void entra_escopo() {
    string nome_escopo = "escopo" + to_string(contador_escopos++);
    unordered_map<string, Simbolo> novo_escopo;
    
    Simbolo info = { nome_escopo, "", "", "" };
    novo_escopo["__escopo_nome__"] = info;

    pilha_escopos.push_back(novo_escopo);
}

void sai_escopo() {
    escopos_passados.push_back(pilha_escopos.back());
    pilha_escopos.pop_back();
}

void entra_funcao(string nome) {
    unordered_map<string, Simbolo> nova_funcao;
    
    Simbolo info = { nome, "", "", "" };
    nova_funcao["__funcao_nome__"] = info;

    pilha_funcao.push_back(nova_funcao);
}

void sai_funcao() {
    pilha_funcao.pop_back();
}

string adiciona_variavel_na_tabela(string variavel, string tipo, string temp_associada, string escopo, string funcao) {
    string variavel_formatada = variavel + "_" + escopo + "_" + funcao;

    if (pilha_escopos.empty()) entra_escopo();

    auto& escopo_atual = pilha_escopos.back();

    // Já existe a variável no escopo atual?
    if (escopo_atual.count(variavel_formatada)) {
        string tipo_atual = escopo_atual[variavel_formatada].tipo;

        if (tipo_atual != tipo) {
            string nome_interno = "__v" + to_string(var_user_qnt++);
            Simbolo simbolo = { nome_interno, tipo, temp_associada, escopo };

            escopo_atual[variavel_formatada] = simbolo;
            tipos_atuais[variavel_formatada].tipo = tipo;
            tipos_atuais[variavel_formatada].temp_associada = temp_associada;
            tipos_atuais[variavel_formatada].nome_interno = nome_interno;
            tipos_atuais[variavel_formatada].escopo = escopo;

            simbolos_declarados.push_back(simbolo);

            return nome_interno;
        }

        // Tipo é o mesmo: só atualiza valor temporário
        tipos_atuais[variavel_formatada].temp_associada = temp_associada;
        return escopo_atual[variavel_formatada].nome_interno;
    }

    // Não existe ainda: adiciona novo
    string nome_interno = "__v" + to_string(var_user_qnt++);
    Simbolo simbolo = { nome_interno, tipo, temp_associada, escopo };

    escopo_atual[variavel_formatada] = simbolo;
    simbolos_declarados.push_back(simbolo);

    tipos_atuais[variavel_formatada].tipo = tipo;
    tipos_atuais[variavel_formatada].temp_associada = temp_associada;
    tipos_atuais[variavel_formatada].nome_interno = nome_interno;
    tipos_atuais[variavel_formatada].escopo = escopo;

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


string pega_variavel_na_tabela(string nome_variavel) {
    for (auto escopo_it = pilha_escopos.rbegin(); escopo_it != pilha_escopos.rend(); ++escopo_it) {
        if (!escopo_it->count("__escopo_nome__")) continue;
        string escopo = escopo_it->at("__escopo_nome__").nome_interno;

        for (auto funcao_it = pilha_funcao.rbegin(); funcao_it != pilha_funcao.rend(); ++funcao_it) {
            if (!funcao_it->count("__funcao_nome__")) continue;
            string funcao = funcao_it->at("__funcao_nome__").nome_interno;

            string chave = nome_variavel + "_" + escopo + "_" + funcao;

            if (escopo_it->count(chave)) {
                return escopo_it->at(chave).nome_interno;
            }
        }
    }

    throw std::runtime_error("variável local não encontrada");
}



string pega_variavel_global(string nome_variavel) {
    for (auto& escopo : escopos_passados) {
        if (!escopo.count("__escopo_nome__")) continue;

        if (escopo.at("__escopo_nome__").nome_interno == "escopo0") {
            for (auto& [chave, simbolo] : escopo) {
                if (chave.rfind(nome_variavel + "_", 0) == 0) {
                    return simbolo.nome_interno;
                }
            }
        }
    }

    throw std::runtime_error("variável global não encontrada");
}



string pega_variavel_dinamica(string nome_variavel, string tipo) {
    for (auto it = pilha_escopos.rbegin(); it != pilha_escopos.rend(); ++it) {
        for (auto& [chave, simbolo] : *it) {
            // Verifica se a chave começa com o nome da variável e termina com o tipo certo
            if (chave.rfind(nome_variavel + "_", 0) == 0 && simbolo.tipo == tipo) {
                return simbolo.nome_interno;
            }
        }
    }

    for (auto& escopo : escopos_passados) {
        for (auto& [chave, simbolo] : escopo) {
            if (chave.rfind(nome_variavel + "_", 0) == 0 && simbolo.tipo == tipo) {
                return simbolo.nome_interno;
            }
        }
    }

    throw std::runtime_error("variavel dinamica nao encontrada");
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


string novo_label(string base) {
    return base + "_" + to_string(contador_label++);
}

int main(int argc, char* argv[]) {
    var_temp_qnt = 0;
    linha = 1;
    yyparse();
    return 0;
}
