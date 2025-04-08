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

"\n"		{}

{DELIM} 	{}

"main"		{return TK_MAIN;}

"function"	{return TK_FUNCTION;}

"int"       {return TK_INT;}

"float"     {return TK_FLOAT;}

"double"    {return TK_DOUBLE;}

"boolean"   {return TK_BOOLEAN;}

"true"      {return TK_TRUE;}

"false"      {return TK_FALSE;}

[(){}[\];,]	{ return *yytext; }

[+\-*/]		{ return *yytext; }

"="         {   return '='; }

{NUM}		{ yylval.label = yytext; return TK_NUM; }
{REAL}      {yylval.label = yytext; return TK_REAL;}
{ID}		{ yylval.label = yytext; return TK_ID; }

.			{ *yytext; }

%%
