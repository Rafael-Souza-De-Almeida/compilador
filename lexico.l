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

"boolean"   {return TK_BOOLEAN;}

"true"      {return TK_TRUE;}

"false"      {return TK_FALSE;}

"print"      {return TK_PRINT;}

"println"      {return TK_PRINTLN;}

[(){}[\];,]	{ return *yytext; }

[+\-*/]		{ return *yytext; }

"="         {   return '='; }

">"         {return GREATER_THAN;}
"<"         {return LESS_THAN;}
">="         {return GREATER_OR_EQUAL;}
"<="         {return LESS_OR_EQUAL;}
"=="         {return EQUAL;}
"!="         {return NOT_EQUAL;}

"!"        { return NOT; }
"&&"        { return AND; }
"||"        { return OR; }

{NUM}		{ yylval.label = yytext; return TK_NUM; }
{REAL}      {yylval.label = yytext; return TK_REAL;}
{ID}		{ yylval.label = yytext; return TK_ID; }
{CHAR}      {yylval.label = yytext; return TK_CHAR;}

.			{ *yytext; }

%%
