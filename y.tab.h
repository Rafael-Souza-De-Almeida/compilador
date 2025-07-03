/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TK_NUM = 258,                  /* TK_NUM  */
    TK_REAL = 259,                 /* TK_REAL  */
    TK_TRUE = 260,                 /* TK_TRUE  */
    TK_FALSE = 261,                /* TK_FALSE  */
    TK_MAIN = 262,                 /* TK_MAIN  */
    TK_ID = 263,                   /* TK_ID  */
    TK_FUNCTION = 264,             /* TK_FUNCTION  */
    TK_INT = 265,                  /* TK_INT  */
    TK_FLOAT = 266,                /* TK_FLOAT  */
    TK_BOOLEAN = 267,              /* TK_BOOLEAN  */
    TK_CHAR = 268,                 /* TK_CHAR  */
    TK_STRING = 269,               /* TK_STRING  */
    TK_FIM = 270,                  /* TK_FIM  */
    TK_ERROR = 271,                /* TK_ERROR  */
    TK_PRINT = 272,                /* TK_PRINT  */
    TK_PRINTLN = 273,              /* TK_PRINTLN  */
    TK_LINHA = 274,                /* TK_LINHA  */
    GREATER_THAN = 275,            /* GREATER_THAN  */
    LESS_THAN = 276,               /* LESS_THAN  */
    GREATER_OR_EQUAL = 277,        /* GREATER_OR_EQUAL  */
    LESS_OR_EQUAL = 278,           /* LESS_OR_EQUAL  */
    EQUAL = 279,                   /* EQUAL  */
    NOT_EQUAL = 280,               /* NOT_EQUAL  */
    NOT = 281,                     /* NOT  */
    AND = 282,                     /* AND  */
    OR = 283,                      /* OR  */
    TK_IF = 284,                   /* TK_IF  */
    TK_ELSE = 285,                 /* TK_ELSE  */
    TK_FOR = 286,                  /* TK_FOR  */
    TK_WHILE = 287,                /* TK_WHILE  */
    TK_DO = 288,                   /* TK_DO  */
    TK_SWITCH = 289,               /* TK_SWITCH  */
    TK_LOCAL = 290,                /* TK_LOCAL  */
    TK_DYNAMIC = 291,              /* TK_DYNAMIC  */
    TK_CONTINUE = 292,             /* TK_CONTINUE  */
    TK_BREAK = 293,                /* TK_BREAK  */
    TK_INC = 294,                  /* TK_INC  */
    TK_DEC = 295                   /* TK_DEC  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define TK_NUM 258
#define TK_REAL 259
#define TK_TRUE 260
#define TK_FALSE 261
#define TK_MAIN 262
#define TK_ID 263
#define TK_FUNCTION 264
#define TK_INT 265
#define TK_FLOAT 266
#define TK_BOOLEAN 267
#define TK_CHAR 268
#define TK_STRING 269
#define TK_FIM 270
#define TK_ERROR 271
#define TK_PRINT 272
#define TK_PRINTLN 273
#define TK_LINHA 274
#define GREATER_THAN 275
#define LESS_THAN 276
#define GREATER_OR_EQUAL 277
#define LESS_OR_EQUAL 278
#define EQUAL 279
#define NOT_EQUAL 280
#define NOT 281
#define AND 282
#define OR 283
#define TK_IF 284
#define TK_ELSE 285
#define TK_FOR 286
#define TK_WHILE 287
#define TK_DO 288
#define TK_SWITCH 289
#define TK_LOCAL 290
#define TK_DYNAMIC 291
#define TK_CONTINUE 292
#define TK_BREAK 293
#define TK_INC 294
#define TK_DEC 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
