%{

#include <string>

%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]

DELIM {ESPACO}+
NUM {DIGITO}+
REAL {NUM}+("."{NUM}+)?
CHAR \'({LETRA}|{NUM})\'
ID {LETRA}({LETRA}|{NUM})*

%%

"\n"		{linha++;}

{DELIM} 	{}


"main"		{return TK_MAIN;}

"function"	{return TK_FUNCTION;}

"int"       {return TK_INT;}

"float"     {return TK_FLOAT;}

"print"      {return TK_PRINT;}

"println"      {return TK_PRINTLN;}

"boolean"   {return TK_BOOLEAN;}

"char"      {return TK_CHAR;}

"true"      {return TK_TRUE;}

"false"      {return TK_FALSE;}

[{}[\];,]	{ return *yytext; }

[()+\-*/]    { return *yytext; }

"="          {return '='; }

">="         {return TK_MAIORIGUAL;}

">"         {return TK_MAIOR;}

"<="         {return TK_MENORIGUAL;}

"<"         {return TK_MENOR;}

"=="         {return TK_IGUALDADE;}

"!="         {return TK_DIFERENTE;}

"&&"         {return TK_E;}

"||"            {return TK_OU;}  

"!"           {return TK_NEGATIVO;}

"if"          {return TK_IF;}

"else"        {return TK_ELSE;}

"for"         {return TK_FOR;}

"while"       {return TK_WHILE;}

"do"          {return TK_DO;}

"switch"      {return TK_SWITCH;}

"break"        {return TK_BREAK;}

"continue"    {return TK_CONTINUE;}


{NUM}		{ yylval.label = yytext; return TK_NUM; }
{REAL}      {yylval.label = yytext; return TK_REAL;}
{ID}		{ yylval.label = yytext; return TK_ID; }
{CHAR}      {yylval.label = yytext;return TK_CHAR;} 

.			{ *yytext; }


%%
