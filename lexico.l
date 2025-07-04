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
STRING \"([^"]*)\"
ID {LETRA}({LETRA}|{NUM})*

%%

"\n"		{linha++;}

{DELIM} 	{}


"main"		{return TK_MAIN;}

"function"	{return TK_FUNCTION;}

"int"       {return TK_INT;}

"float"     {return TK_FLOAT;}

"boolean"   {return TK_BOOLEAN;}

"char"      {return TK_CHAR;}

"true"      {return TK_TRUE;}

"false"      {return TK_FALSE;}

"print"      {return TK_PRINT;}

"println"      {return TK_PRINTLN;}

"local"         {return TK_LOCAL;}

"dynamic"       {return TK_DYNAMIC;}


[(){}[\];,]	{ return *yytext; }

[()+\-*/]    { return *yytext; }

"="          {return '='; }

":"          {return ':';}

"++"         {return TK_INC;}
"--"         {return TK_DEC;}

"?"       {return '?';} 

"break all"  {return TK_BREAKALL;}

"if"          {return TK_IF;}

"else"        {return TK_ELSE;}

"for"         {return TK_FOR;}

"while"       {return TK_WHILE;}

"do"          {return TK_DO;}

"switch"      {return TK_SWITCH;}

"break"        {return TK_BREAK;}

"continue"    {return TK_CONTINUE;}

"string"    {return TOKEN_STRING_TYPE;}

"type"       {return TK_TYPE;}

"+="           {return TK_MAISCOMPOSTO;}

"-="          {return TK_MENOSCOMPOSTO;}

"*="         {return TK_MULTIPLICACOMPOSTO;}

"/="         {return TK_DIVIDECOMPOSTO;}

"%="       {return TK_MODCOMPOSTO;}



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
{STRING}    {yylval.label = yytext; return TK_STRING;}

.			{ *yytext; }


%%
