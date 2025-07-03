/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sintatico.y"

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


#line 179 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    TK_DEC = 295,                  /* TK_DEC  */
    TK_BREAKALL = 296              /* TK_BREAKALL  */
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
#define TK_BREAKALL 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TK_NUM = 3,                     /* TK_NUM  */
  YYSYMBOL_TK_REAL = 4,                    /* TK_REAL  */
  YYSYMBOL_TK_TRUE = 5,                    /* TK_TRUE  */
  YYSYMBOL_TK_FALSE = 6,                   /* TK_FALSE  */
  YYSYMBOL_TK_MAIN = 7,                    /* TK_MAIN  */
  YYSYMBOL_TK_ID = 8,                      /* TK_ID  */
  YYSYMBOL_TK_FUNCTION = 9,                /* TK_FUNCTION  */
  YYSYMBOL_TK_INT = 10,                    /* TK_INT  */
  YYSYMBOL_TK_FLOAT = 11,                  /* TK_FLOAT  */
  YYSYMBOL_TK_BOOLEAN = 12,                /* TK_BOOLEAN  */
  YYSYMBOL_TK_CHAR = 13,                   /* TK_CHAR  */
  YYSYMBOL_TK_STRING = 14,                 /* TK_STRING  */
  YYSYMBOL_TK_FIM = 15,                    /* TK_FIM  */
  YYSYMBOL_TK_ERROR = 16,                  /* TK_ERROR  */
  YYSYMBOL_TK_PRINT = 17,                  /* TK_PRINT  */
  YYSYMBOL_TK_PRINTLN = 18,                /* TK_PRINTLN  */
  YYSYMBOL_TK_LINHA = 19,                  /* TK_LINHA  */
  YYSYMBOL_GREATER_THAN = 20,              /* GREATER_THAN  */
  YYSYMBOL_LESS_THAN = 21,                 /* LESS_THAN  */
  YYSYMBOL_GREATER_OR_EQUAL = 22,          /* GREATER_OR_EQUAL  */
  YYSYMBOL_LESS_OR_EQUAL = 23,             /* LESS_OR_EQUAL  */
  YYSYMBOL_EQUAL = 24,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 25,                 /* NOT_EQUAL  */
  YYSYMBOL_NOT = 26,                       /* NOT  */
  YYSYMBOL_AND = 27,                       /* AND  */
  YYSYMBOL_OR = 28,                        /* OR  */
  YYSYMBOL_TK_IF = 29,                     /* TK_IF  */
  YYSYMBOL_TK_ELSE = 30,                   /* TK_ELSE  */
  YYSYMBOL_TK_FOR = 31,                    /* TK_FOR  */
  YYSYMBOL_TK_WHILE = 32,                  /* TK_WHILE  */
  YYSYMBOL_TK_DO = 33,                     /* TK_DO  */
  YYSYMBOL_TK_SWITCH = 34,                 /* TK_SWITCH  */
  YYSYMBOL_TK_LOCAL = 35,                  /* TK_LOCAL  */
  YYSYMBOL_TK_DYNAMIC = 36,                /* TK_DYNAMIC  */
  YYSYMBOL_TK_CONTINUE = 37,               /* TK_CONTINUE  */
  YYSYMBOL_TK_BREAK = 38,                  /* TK_BREAK  */
  YYSYMBOL_TK_INC = 39,                    /* TK_INC  */
  YYSYMBOL_TK_DEC = 40,                    /* TK_DEC  */
  YYSYMBOL_TK_BREAKALL = 41,               /* TK_BREAKALL  */
  YYSYMBOL_42_ = 42,                       /* '+'  */
  YYSYMBOL_43_ = 43,                       /* '-'  */
  YYSYMBOL_44_ = 44,                       /* '*'  */
  YYSYMBOL_45_ = 45,                       /* '/'  */
  YYSYMBOL_46_ = 46,                       /* '('  */
  YYSYMBOL_47_ = 47,                       /* ')'  */
  YYSYMBOL_48_ = 48,                       /* '{'  */
  YYSYMBOL_49_ = 49,                       /* '}'  */
  YYSYMBOL_50_ = 50,                       /* ';'  */
  YYSYMBOL_51_ = 51,                       /* '='  */
  YYSYMBOL_52_ = 52,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 53,                  /* $accept  */
  YYSYMBOL_S = 54,                         /* S  */
  YYSYMBOL_LISTA_DECLARACOES = 55,         /* LISTA_DECLARACOES  */
  YYSYMBOL_DECLARACAO = 56,                /* DECLARACAO  */
  YYSYMBOL_57_1 = 57,                      /* $@1  */
  YYSYMBOL_58_2 = 58,                      /* $@2  */
  YYSYMBOL_59_3 = 59,                      /* $@3  */
  YYSYMBOL_60_4 = 60,                      /* $@4  */
  YYSYMBOL_BLOCO = 61,                     /* BLOCO  */
  YYSYMBOL_62_5 = 62,                      /* $@5  */
  YYSYMBOL_COMANDOS = 63,                  /* COMANDOS  */
  YYSYMBOL_COMANDO = 64,                   /* COMANDO  */
  YYSYMBOL_BEGIN_WHILE = 65,               /* BEGIN_WHILE  */
  YYSYMBOL_CLOSE_WHILE = 66,               /* CLOSE_WHILE  */
  YYSYMBOL_IDENTIFICADOR_FOREACH = 67,     /* IDENTIFICADOR_FOREACH  */
  YYSYMBOL_BEGIN_FOR = 68,                 /* BEGIN_FOR  */
  YYSYMBOL_CLOSE_FOR = 69,                 /* CLOSE_FOR  */
  YYSYMBOL_LOOP_START_WHILE = 70,          /* LOOP_START_WHILE  */
  YYSYMBOL_BEGIN_DO = 71,                  /* BEGIN_DO  */
  YYSYMBOL_CLOSE_DO = 72,                  /* CLOSE_DO  */
  YYSYMBOL_CLOSE_BLOCO = 73,               /* CLOSE_BLOCO  */
  YYSYMBOL_E = 74                          /* E  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   405

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      46,    47,    44,    42,     2,    43,     2,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    52,    50,
       2,    51,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   130,   130,   217,   222,   227,   227,   227,   234,   234,
     234,   243,   243,   250,   255,   259,   263,   270,   273,   276,
     280,   296,   315,   366,   411,   439,   469,   477,   485,   498,
     508,   518,   528,   550,   560,   575,   596,   608,   617,   692,
     700,   709,   718,   724,   732,   741,   750,   759,   768,   777,
     786,   793,   802,   860,   866,   872,   893,   899,   905,   911,
     931,   954,   979,   989,   998,  1002,  1007,  1012
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TK_NUM", "TK_REAL",
  "TK_TRUE", "TK_FALSE", "TK_MAIN", "TK_ID", "TK_FUNCTION", "TK_INT",
  "TK_FLOAT", "TK_BOOLEAN", "TK_CHAR", "TK_STRING", "TK_FIM", "TK_ERROR",
  "TK_PRINT", "TK_PRINTLN", "TK_LINHA", "GREATER_THAN", "LESS_THAN",
  "GREATER_OR_EQUAL", "LESS_OR_EQUAL", "EQUAL", "NOT_EQUAL", "NOT", "AND",
  "OR", "TK_IF", "TK_ELSE", "TK_FOR", "TK_WHILE", "TK_DO", "TK_SWITCH",
  "TK_LOCAL", "TK_DYNAMIC", "TK_CONTINUE", "TK_BREAK", "TK_INC", "TK_DEC",
  "TK_BREAKALL", "'+'", "'-'", "'*'", "'/'", "'('", "')'", "'{'", "'}'",
  "';'", "'='", "':'", "$accept", "S", "LISTA_DECLARACOES", "DECLARACAO",
  "$@1", "$@2", "$@3", "$@4", "BLOCO", "$@5", "COMANDOS", "COMANDO",
  "BEGIN_WHILE", "CLOSE_WHILE", "IDENTIFICADOR_FOREACH", "BEGIN_FOR",
  "CLOSE_FOR", "LOOP_START_WHILE", "BEGIN_DO", "CLOSE_DO", "CLOSE_BLOCO",
  "E", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-32)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,    29,     3,   -32,     2,   -31,   -24,   -32,   -32,   -22,
      -9,   -32,   -32,   -16,   -16,   -32,   -32,   -32,   105,   -32,
     -32,   -32,   -32,   -32,   -32,    -5,   -32,   -32,    -7,    -2,
      57,     1,   -32,   -32,   -32,    34,    56,    18,    19,    26,
     144,   -32,    28,   105,    32,    -6,   -16,   172,   -32,   -32,
      35,   -32,    57,    57,    57,    33,    65,    57,    30,    40,
     -32,   -32,   -32,    55,    60,    67,   221,   -32,   -32,    57,
     -32,   105,    61,    48,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,   -32,   -32,   360,   249,
     258,   286,    57,    57,   107,   108,   112,   -32,   -32,   295,
      57,    57,    79,   360,   360,   360,   360,   360,   360,    65,
      74,   -15,   -15,    -4,    -4,    76,    77,   -16,   360,   360,
     -32,   -32,   -32,   -32,   181,   139,    57,   -32,   -32,    99,
     -16,    57,    57,   323,   -16,   -32,   332,   212,    80,   -32,
     -32,   -16,   -32,   -32,   -32,   -32,   -32,   -32
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     2,     4,     0,     0,     1,     3,     0,
       0,     5,     8,     0,     0,    11,     6,     9,    14,     7,
      10,    53,    54,    56,    57,    59,    58,    55,     0,     0,
       0,     0,    32,    29,    35,     0,     0,     0,     0,     0,
       0,    19,     0,    14,     0,     0,     0,     0,    65,    66,
       0,    16,     0,     0,     0,    59,    49,     0,     0,     0,
      27,    26,    28,     0,     0,     0,     0,    37,    13,     0,
      31,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    67,    52,     0,
       0,     0,     0,     0,     0,     0,     0,    42,    12,     0,
       0,     0,     0,    43,    44,    45,    46,    47,    48,    50,
      51,    38,    39,    40,    41,     0,     0,     0,    60,    61,
      62,    63,    64,    34,     0,     0,     0,    17,    18,    20,
       0,     0,     0,     0,     0,    30,     0,     0,     0,    21,
      24,     0,    33,    36,    33,    23,    25,    22
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -32,   -32,   128,   -32,   -32,   -32,   -32,   -32,   -13,   -32,
      90,    64,   -32,   -32,   -32,   -32,     0,   -32,   -32,   -32,
     -32,   -26
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,    13,    19,    14,    20,    41,    18,
      42,    43,    44,   140,    72,    45,   145,   130,    46,   146,
      98,    47
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      16,    17,    70,     7,    56,    74,    75,    76,    77,    78,
      79,     1,    80,    81,    66,     9,    74,    75,    76,    77,
      78,    79,    10,    80,    81,    11,    88,    89,    90,    84,
      85,    91,    15,    73,    48,    49,     5,     6,    12,    53,
      71,    50,    58,    99,    54,    51,    52,    57,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      21,    22,    23,    24,    59,    55,   118,   119,    60,    61,
      26,    27,    48,    49,   124,   125,    62,    67,    69,    50,
     102,    92,    87,    30,    52,    74,    75,    76,    77,    78,
      79,    93,    35,    36,    74,    75,    76,    77,    78,    79,
     133,    80,    94,    40,   129,   136,   137,    95,    21,    22,
      23,    24,   101,    25,    96,   120,   121,   135,    26,    27,
     122,   139,    28,    29,   142,   126,   127,   128,   144,   134,
     143,    30,     8,    68,    31,   100,    32,    33,    34,     0,
      35,    36,    37,    38,   147,     0,    39,    21,    22,    23,
      24,    40,    55,    15,    63,    64,    65,    26,    27,    74,
      75,    76,    77,    78,    79,     0,    80,    81,     0,     0,
      30,     0,     0,     0,     0,     0,     0,     0,     0,    35,
      36,    82,    83,    84,    85,     0,     0,     0,     0,     0,
      40,   132,    74,    75,    76,    77,    78,    79,     0,    80,
      81,    74,    75,    76,    77,    78,    79,     0,    80,    81,
       0,     0,     0,     0,    82,    83,    84,    85,     0,     0,
       0,     0,    86,    82,    83,    84,    85,     0,     0,     0,
       0,   131,    74,    75,    76,    77,    78,    79,     0,    80,
      81,    74,    75,    76,    77,    78,    79,     0,    80,    81,
       0,     0,     0,     0,    82,    83,    84,    85,     0,     0,
      15,     0,     0,    82,    83,    84,    85,     0,    97,    74,
      75,    76,    77,    78,    79,     0,    80,    81,    74,    75,
      76,    77,    78,    79,     0,    80,    81,     0,     0,     0,
       0,    82,    83,    84,    85,     0,   115,     0,     0,     0,
      82,    83,    84,    85,     0,   116,    74,    75,    76,    77,
      78,    79,     0,    80,    81,    74,    75,    76,    77,    78,
      79,     0,    80,    81,     0,     0,     0,     0,    82,    83,
      84,    85,     0,   117,     0,     0,     0,    82,    83,    84,
      85,     0,   123,    74,    75,    76,    77,    78,    79,     0,
      80,    81,    74,    75,    76,    77,    78,    79,     0,    80,
      81,     0,     0,     0,     0,    82,    83,    84,    85,     0,
     138,     0,     0,     0,    82,    83,    84,    85,     0,   141,
      74,    75,    76,    77,    78,    79,     0,    80,    81,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,    83,    84,    85
};

static const yytype_int16 yycheck[] =
{
      13,    14,     8,     0,    30,    20,    21,    22,    23,    24,
      25,     9,    27,    28,    40,    46,    20,    21,    22,    23,
      24,    25,    46,    27,    28,    47,    52,    53,    54,    44,
      45,    57,    48,    46,    39,    40,     7,     8,    47,    46,
      46,    46,     8,    69,    46,    50,    51,    46,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
       3,     4,     5,     6,     8,     8,    92,    93,    50,    50,
      13,    14,    39,    40,   100,   101,    50,    49,    46,    46,
      32,    51,    47,    26,    51,    20,    21,    22,    23,    24,
      25,    51,    35,    36,    20,    21,    22,    23,    24,    25,
     126,    27,    47,    46,   117,   131,   132,    47,     3,     4,
       5,     6,    51,     8,    47,     8,     8,   130,    13,    14,
       8,   134,    17,    18,   137,    46,    50,    50,   141,    30,
      50,    26,     4,    43,    29,    71,    31,    32,    33,    -1,
      35,    36,    37,    38,   144,    -1,    41,     3,     4,     5,
       6,    46,     8,    48,    10,    11,    12,    13,    14,    20,
      21,    22,    23,    24,    25,    -1,    27,    28,    -1,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,
      46,    52,    20,    21,    22,    23,    24,    25,    -1,    27,
      28,    20,    21,    22,    23,    24,    25,    -1,    27,    28,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    50,    42,    43,    44,    45,    -1,    -1,    -1,
      -1,    50,    20,    21,    22,    23,    24,    25,    -1,    27,
      28,    20,    21,    22,    23,    24,    25,    -1,    27,    28,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    -1,    -1,
      48,    -1,    -1,    42,    43,    44,    45,    -1,    47,    20,
      21,    22,    23,    24,    25,    -1,    27,    28,    20,    21,
      22,    23,    24,    25,    -1,    27,    28,    -1,    -1,    -1,
      -1,    42,    43,    44,    45,    -1,    47,    -1,    -1,    -1,
      42,    43,    44,    45,    -1,    47,    20,    21,    22,    23,
      24,    25,    -1,    27,    28,    20,    21,    22,    23,    24,
      25,    -1,    27,    28,    -1,    -1,    -1,    -1,    42,    43,
      44,    45,    -1,    47,    -1,    -1,    -1,    42,    43,    44,
      45,    -1,    47,    20,    21,    22,    23,    24,    25,    -1,
      27,    28,    20,    21,    22,    23,    24,    25,    -1,    27,
      28,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    -1,
      47,    -1,    -1,    -1,    42,    43,    44,    45,    -1,    47,
      20,    21,    22,    23,    24,    25,    -1,    27,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    44,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    54,    55,    56,     7,     8,     0,    55,    46,
      46,    47,    47,    57,    59,    48,    61,    61,    62,    58,
      60,     3,     4,     5,     6,     8,    13,    14,    17,    18,
      26,    29,    31,    32,    33,    35,    36,    37,    38,    41,
      46,    61,    63,    64,    65,    68,    71,    74,    39,    40,
      46,    50,    51,    46,    46,     8,    74,    46,     8,     8,
      50,    50,    50,    10,    11,    12,    74,    49,    63,    46,
       8,    46,    67,    61,    20,    21,    22,    23,    24,    25,
      27,    28,    42,    43,    44,    45,    50,    47,    74,    74,
      74,    74,    51,    51,    47,    47,    47,    47,    73,    74,
      64,    51,    32,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    47,    47,    47,    74,    74,
       8,     8,     8,    47,    74,    74,    46,    50,    50,    61,
      70,    50,    52,    74,    30,    61,    74,    74,    47,    61,
      66,    47,    61,    50,    61,    69,    72,    69
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    55,    55,    57,    58,    56,    59,    60,
      56,    62,    61,    63,    63,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     0,     0,     7,     0,     0,
       7,     0,     5,     2,     0,     2,     2,     5,     5,     1,
       5,     7,     9,     8,     7,     8,     2,     2,     2,     1,
       0,     1,     1,     0,     0,     1,     0,     0,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     2,     2,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* S: LISTA_DECLARACOES  */
#line 131 "sintatico.y"
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
                codigo += yyvsp[0].traducao;             
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
#line 1590 "y.tab.c"
    break;

  case 3: /* LISTA_DECLARACOES: DECLARACAO LISTA_DECLARACOES  */
#line 218 "sintatico.y"
    {
        yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
    }
#line 1598 "y.tab.c"
    break;

  case 4: /* LISTA_DECLARACOES: %empty  */
#line 222 "sintatico.y"
    {
        yyval.traducao = "";
    }
#line 1606 "y.tab.c"
    break;

  case 5: /* $@1: %empty  */
#line 227 "sintatico.y"
                                         {entra_funcao("main");}
#line 1612 "y.tab.c"
    break;

  case 6: /* $@2: %empty  */
#line 227 "sintatico.y"
                                                                       {sai_funcao();}
#line 1618 "y.tab.c"
    break;

  case 7: /* DECLARACAO: TK_FUNCTION TK_MAIN '(' ')' $@1 BLOCO $@2  */
#line 227 "sintatico.y"
                                                                                       {

        yyval.traducao = "label_main:\n";   
        yyval.traducao += yyvsp[-1].traducao;
        

    }
#line 1630 "y.tab.c"
    break;

  case 8: /* $@3: %empty  */
#line 234 "sintatico.y"
                                {entra_funcao("funcao_" + yyvsp[-3].label);}
#line 1636 "y.tab.c"
    break;

  case 9: /* $@4: %empty  */
#line 234 "sintatico.y"
                                                                            {sai_funcao();}
#line 1642 "y.tab.c"
    break;

  case 10: /* DECLARACAO: TK_FUNCTION TK_ID '(' ')' $@3 BLOCO $@4  */
#line 235 "sintatico.y"
    {
        yyval.traducao = "label_" + yyvsp[-5].label + ":\n";
        yyval.traducao += yyvsp[-1].traducao;
        yyval.traducao += "goto end_" + yyvsp[-5].label + ";\n\n";
        
    }
#line 1653 "y.tab.c"
    break;

  case 11: /* $@5: %empty  */
#line 243 "sintatico.y"
                  {entra_escopo();}
#line 1659 "y.tab.c"
    break;

  case 12: /* BLOCO: '{' $@5 COMANDOS '}' CLOSE_BLOCO  */
#line 243 "sintatico.y"
                                                            { 
    
                yyval.traducao = yyvsp[-2].traducao;

            }
#line 1669 "y.tab.c"
    break;

  case 13: /* COMANDOS: COMANDO COMANDOS  */
#line 251 "sintatico.y"
            {
                yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
            }
#line 1677 "y.tab.c"
    break;

  case 14: /* COMANDOS: %empty  */
#line 255 "sintatico.y"
            {
                yyval.traducao = "";
            }
#line 1685 "y.tab.c"
    break;

  case 15: /* COMANDO: E ';'  */
#line 260 "sintatico.y"
            {
                yyval = yyvsp[-1];
            }
#line 1693 "y.tab.c"
    break;

  case 16: /* COMANDO: TK_ID ';'  */
#line 264 "sintatico.y"
            {   
                string escopo_atual = pilha_escopos.back()["__escopo_nome__"].nome_interno;
                string funcao_atual = pilha_funcao.back()["__funcao_nome__"].nome_interno;
                string nome_interno = tipos_atuais[yyvsp[-1].label + "_" + escopo_atual + "_" + funcao_atual].nome_interno;
                yyval.traducao =   "\t cout << "  + nome_interno + " << endl;\n";   
            }
#line 1704 "y.tab.c"
    break;

  case 17: /* COMANDO: TK_PRINT '(' E ')' ';'  */
#line 270 "sintatico.y"
                                     {
                yyval.traducao = yyvsp[-4].traducao + yyvsp[-2].traducao +  "\t cout << "  + yyvsp[-2].label + ";\n";
            }
#line 1712 "y.tab.c"
    break;

  case 18: /* COMANDO: TK_PRINTLN '(' E ')' ';'  */
#line 273 "sintatico.y"
                                       {
                yyval.traducao = yyvsp[-4].traducao + yyvsp[-2].traducao +  "\t cout << "  + yyvsp[-2].label + " << endl;\n";
            }
#line 1720 "y.tab.c"
    break;

  case 19: /* COMANDO: BLOCO  */
#line 276 "sintatico.y"
                    {
                yyval.traducao = yyvsp[0].traducao;
            }
#line 1728 "y.tab.c"
    break;

  case 20: /* COMANDO: TK_IF '(' E ')' BLOCO  */
#line 280 "sintatico.y"
                                   {
                if(yyvsp[-2].tipo!="boolean"){
                    
                    yyerror("No If deve ser operando boolean");
                    yyval.traducao = "";
                    exit(1);
                }
                else {
                string rotulo_if = fim_if();

                yyval.traducao = yyvsp[-2].traducao;  
                yyval.traducao += "if (!" + yyvsp[-2].label + ") goto " + rotulo_if + ";\n";
                yyval.traducao += yyvsp[0].traducao; 
                yyval.traducao += rotulo_if + ":\n";
                }
            }
#line 1749 "y.tab.c"
    break;

  case 21: /* COMANDO: TK_IF '(' E ')' BLOCO TK_ELSE BLOCO  */
#line 296 "sintatico.y"
                                                 {
                if(yyvsp[-4].tipo!="boolean"){
                    yyerror("No if-else deve ser operando boolean");
                    yyval.traducao = "";
                }
                else {
                    string rotulo_if = fim_if();
                    string rotulo_else = fim_else();

                    yyval.traducao = yyvsp[-4].traducao;
                    yyval.traducao += "if (!" + yyvsp[-4].label + ") goto "+ rotulo_else + ";\n";
                    yyval.traducao+= yyvsp[-2].traducao;
                    yyval.traducao += "goto " + rotulo_if +";\n";
                    yyval.traducao += rotulo_else + ":\n";
                    yyval.traducao += yyvsp[0].traducao;
                    yyval.traducao += rotulo_if + ":\n";

                }
            }
#line 1773 "y.tab.c"
    break;

  case 22: /* COMANDO: BEGIN_FOR '(' COMANDO E ';' E ')' BLOCO CLOSE_FOR  */
#line 316 "sintatico.y"
                {
                    // Gera labels e empilha
                    string label_inicio = pilha_loop_inicio.top();
                    string label_fim = pilha_loop_fim.top();
                    string label_incremento = pilha_loop_continue.top();

                    
                    yyval.traducao = yyvsp[-6].traducao;

                    
                    yyval.traducao += label_inicio + ":\n";

                   
                    string temp_cond_pre = gentempcode("boolean");
                    string temp_cond = gentempcode("boolean");

                    
                    yyval.traducao += yyvsp[-5].traducao;                    

                    
                    yyval.traducao += "\t" + temp_cond + " = " + yyvsp[-5].label + ";\n";

                    
                    yyval.traducao += "\tif (!" + temp_cond + ") goto " + label_fim + ";\n";

                    
                    yyval.traducao += yyvsp[-1].traducao;

                   
                    yyval.traducao += label_incremento + ":\n";

                  
                    yyval.traducao += yyvsp[-3].traducao;

                    
                    yyval.traducao += "\tgoto " + label_inicio + ";\n";

                    
                    yyval.traducao += label_fim + ":\n";

                    if (!pilha_loop_inicio.size()) {
                        pilha_fim_loop_mais_externo.pop(); 
                    }
                   
                    if (!pilha_loop_continue.empty()) pilha_loop_continue.pop();
                    if (!pilha_loop_inicio.empty()) pilha_loop_inicio.pop();
                    if (!pilha_loop_fim.empty()) pilha_loop_fim.pop();

                }
#line 1827 "y.tab.c"
    break;

  case 23: /* COMANDO: BEGIN_FOR IDENTIFICADOR_FOREACH '=' E ':' E BLOCO CLOSE_FOR  */
#line 366 "sintatico.y"
                                                                          {

                    if (yyvsp[-4].tipo != "int") {
                        yyerror("Início do foreach deve ser numérico (int)");
                    }

                    if (yyvsp[-2].tipo != "int") {
                        yyerror("Fim do foreach deve ser numérico (int)");
                    }

                    string label_inicio = pilha_loop_inicio.top();
                    string label_fim = pilha_loop_fim.top();
                    string label_incremento = pilha_loop_continue.top();

                    string nome_variavel = pega_variavel_na_tabela(yyvsp[-6].label);

                    yyval.traducao = ""; 
                    yyval.traducao += yyvsp[-4].traducao + yyvsp[-2].traducao;
                    yyval.traducao += "\t" + nome_variavel + " = " + yyvsp[-4].label + ";\n";
                    yyval.traducao += label_inicio + ":\n";

                    string pre_condicao = gentempcode("boolean");
                    string condicao = gentempcode("boolean");

                    yyval.traducao += "\t" + pre_condicao + " = " + yyvsp[-2].label + " - 1;\n"; 
                    yyval.traducao += "\t" + condicao + " = " + nome_variavel + " > " + pre_condicao + ";\n"; 
                    yyval.traducao += "\tif (" + condicao + ") goto " + label_fim + ";\n";

                    yyval.traducao += yyvsp[-1].traducao;  

                    yyval.traducao += label_incremento + ":\n";
                    yyval.traducao += "\t" + nome_variavel + " = " + nome_variavel + " + 1;\n";
                    yyval.traducao += "\tgoto " + label_inicio + ";\n";

                    yyval.traducao += label_fim + ":\n";

                     if (!pilha_loop_inicio.size()) {
                        pilha_fim_loop_mais_externo.pop(); 
                    }

                     if (!pilha_loop_continue.empty()) pilha_loop_continue.pop();
                    if (!pilha_loop_inicio.empty()) pilha_loop_inicio.pop();
                    if (!pilha_loop_fim.empty()) pilha_loop_fim.pop();


                }
#line 1878 "y.tab.c"
    break;

  case 24: /* COMANDO: BEGIN_WHILE '(' E ')' LOOP_START_WHILE BLOCO CLOSE_WHILE  */
#line 411 "sintatico.y"
                                                                             {

                if(yyvsp[-4].tipo != "boolean") {
                    yyerror("Erro na linha " + to_string(linha) + ": é necessária uma operação lógica ao utilizar o while");
                }

                string label_inicio = pilha_loop_inicio.top();
                string label_fim = pilha_loop_fim.top();


                yyval.traducao = "";
                yyval.traducao += label_inicio + ":\n";
                yyval.traducao += yyvsp[-4].traducao;
                string condicao = gentempcode("boolean");
                yyval.traducao += "\t" + condicao + " = !" + yyvsp[-4].label + ";\n";
                yyval.traducao += "\tif (" + condicao + ") goto " + label_fim + ";\n";
                yyval.traducao += yyvsp[-1].traducao;  // $6 é o BLOCO

                yyval.traducao += "\tgoto " + label_inicio + ";\n";
                yyval.traducao += label_fim + ":\n";

                 if (!pilha_loop_inicio.size()) {
                        pilha_fim_loop_mais_externo.pop(); 
                    }

                pilha_loop_inicio.pop();
                pilha_loop_fim.pop();
            }
#line 1911 "y.tab.c"
    break;

  case 25: /* COMANDO: BEGIN_DO BLOCO TK_WHILE '(' E ')' ';' CLOSE_DO  */
#line 440 "sintatico.y"
                {
                    if(yyvsp[-3].tipo != "boolean") {
                        yyerror("Erro: condição do 'do while' deve ser booleana");
                    }

                    string label_inicio = pilha_loop_inicio.top();
                    string label_fim = pilha_loop_fim.top();

                    string condicao = gentempcode("boolean");

                    yyval.traducao = "";
                    yyval.traducao += label_inicio + ":\n";
                    yyval.traducao += yyvsp[-6].traducao;         // BLOCO
                    yyval.traducao += yyvsp[-3].traducao;         // condição
                    yyval.traducao += "\t" + condicao + " = !" + yyvsp[-3].label + ";\n";
                    yyval.traducao += "\tif (" + condicao + ") goto " + label_fim + ";\n";
                    yyval.traducao += "\tgoto " + label_inicio + ";\n";
                    yyval.traducao += label_fim + ":\n";

                    if (!pilha_loop_inicio.size()) {
                        pilha_fim_loop_mais_externo.pop(); 
                    }


                       if (!pilha_loop_inicio.empty()) pilha_loop_inicio.pop();
                        if (!pilha_loop_fim.empty()) pilha_loop_fim.pop();
                        if (!pilha_loop_continue.empty()) pilha_loop_continue.pop();
                }
#line 1944 "y.tab.c"
    break;

  case 26: /* COMANDO: TK_BREAK ';'  */
#line 469 "sintatico.y"
                           {

            if (pilha_loop_fim.empty()) {
                yyerror("Comando 'break' fora de um loop.");
            }

            yyval.traducao = "\tgoto " + pilha_loop_fim.top() + ";\n";
            }
#line 1957 "y.tab.c"
    break;

  case 27: /* COMANDO: TK_CONTINUE ';'  */
#line 477 "sintatico.y"
                              {
                if (pilha_loop_continue.empty()) {
                    yyerror("Comando 'continue' fora de um loop.");
                } else {
                    cout << "DEBUG pilha continue top: " << pilha_loop_continue.top() << endl;
                    yyval.traducao = "\tgoto " + pilha_loop_continue.top() + ";\n";
                }

            }
#line 1971 "y.tab.c"
    break;

  case 28: /* COMANDO: TK_BREAKALL ';'  */
#line 486 "sintatico.y"
                   {
                       if (pilha_fim_loop_mais_externo.empty()) {
                           yyerror("Uso inválido de 'break all' fora de qualquer laço.");
                           exit(1);
                       }
                   
                       string label_fim_externo = pilha_fim_loop_mais_externo.top();
                       yyval.traducao = "\tgoto " + label_fim_externo + ";\n";
                   }
#line 1985 "y.tab.c"
    break;

  case 29: /* BEGIN_WHILE: TK_WHILE  */
#line 499 "sintatico.y"
                    {
                        esta_no_while = true;
                        qtdWhile++;
                        yyval.label = "";
                        
                    }
#line 1996 "y.tab.c"
    break;

  case 30: /* CLOSE_WHILE: %empty  */
#line 508 "sintatico.y"
                    {
                        qtdWhile--;
                        if(qtdWhile == 0) {
                            esta_no_while = false;
                        }
                        yyval.label = "";
                        
                    }
#line 2009 "y.tab.c"
    break;

  case 31: /* IDENTIFICADOR_FOREACH: TK_ID  */
#line 519 "sintatico.y"
                    {
                        string indice_for = gentempcode("int");
                        string escopo_atual = pilha_escopos.back()["__escopo_nome__"].nome_interno;
                        string funcao_atual = pilha_funcao.back()["__funcao_nome__"].nome_interno;
                        string nome_variavel = adiciona_variavel_na_tabela(yyvsp[0].label, "int", indice_for, escopo_atual, funcao_atual);
                        yyval.label = yyvsp[0].label;
                        
                    }
#line 2022 "y.tab.c"
    break;

  case 32: /* BEGIN_FOR: TK_FOR  */
#line 529 "sintatico.y"
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
                       
                       yyval.label = label_inicio + "|" + label_fim + "|" + label_incremento;
                        
                    }
#line 2046 "y.tab.c"
    break;

  case 33: /* CLOSE_FOR: %empty  */
#line 550 "sintatico.y"
                    {
                        qtdFor--;
                        if(qtdFor == 0) {
                            esta_no_for = false;
                        }
                        yyval.label = "";
                        
                    }
#line 2059 "y.tab.c"
    break;

  case 34: /* LOOP_START_WHILE: %empty  */
#line 560 "sintatico.y"
                    {
                        string label_inicio = nova_label("while", "inicio");
                        string label_fim = nova_label("while", "fim");

                        if (pilha_fim_loop_mais_externo.empty()) {
                            pilha_fim_loop_mais_externo.push(label_fim);  
                        }

                        pilha_loop_inicio.push(label_inicio);
                        pilha_loop_fim.push(label_fim);

                        yyval.label = label_inicio + "|" + label_fim;
                        
                    }
#line 2078 "y.tab.c"
    break;

  case 35: /* BEGIN_DO: TK_DO  */
#line 576 "sintatico.y"
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

    yyval.label = label_inicio + "|" + label_fim;
}
#line 2100 "y.tab.c"
    break;

  case 36: /* CLOSE_DO: %empty  */
#line 596 "sintatico.y"
{
  
    qtdDoWhile--;
    if(qtdDoWhile == 0) {

        esta_no_do_while = false;
    }

    yyval.label = "";
}
#line 2115 "y.tab.c"
    break;

  case 37: /* CLOSE_BLOCO: %empty  */
#line 608 "sintatico.y"
             {
    sai_escopo();
}
#line 2123 "y.tab.c"
    break;

  case 38: /* E: E '+' E  */
#line 618 "sintatico.y"
            {
            string tipo = resolve_tipo(yyvsp[-2].tipo, yyvsp[0].tipo);

            if(tipo == "char") {
                string var_1 = gentempcode("string");
                string var_2 = gentempcode("string");
                yyval.tipo = "string";
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao;
                yyval.traducao += "\t" + var_1 + " = (char *) malloc(2);\n";
                yyval.traducao += "\t" + var_1 + "[0] = " + yyvsp[-2].label + ";\n";
                yyval.traducao += "\t" + var_1 + "[1] = '\\0';\n";
                yyval.traducao += "\t" + var_2 + " = (char *) malloc(2);\n";
                yyval.traducao += "\t" + var_2 + "[0] = " + yyvsp[0].label + ";\n";
                yyval.traducao += "\t" + var_2 + "[1] = '\\0';\n";
                string temp_tamanho = gentempcode("int");
                yyval.label = gentempcode("string");
                yyval.traducao += "\t" + temp_tamanho + " = 3;\n";
                yyval.traducao += "\t" + yyval.label + " = (char *) malloc(" + temp_tamanho + ");\n";
                yyval.traducao += "\tstrcpy(" + yyval.label + ", " + var_1 + ");\n";
                yyval.traducao += "\tstrcat(" + yyval.label + ", " + var_2 + ");\n";
                tamanho_string[yyval.label] = temp_tamanho;

            }

            else if(tipo == "string") {
            yyval.label = gentempcode(tipo);
            yyval.tipo = tipo;

           
            bool left_is_char = yyvsp[-2].tipo == "char";
            bool right_is_char = yyvsp[0].tipo == "char";

            string left_label = yyvsp[-2].label;
            string right_label = yyvsp[0].label;
            string prep = "";

            if(left_is_char) {
                string var = gentempcode("string");
                prep += "\t" + var + " = (char *) malloc(2);\n";
                prep += "\t" + var + "[0] = " + yyvsp[-2].label + ";\n";
                prep += "\t" + var + "[1] = '\\0';\n";
                left_label = var;
                tamanho_string[var] = "2";
            }

            if(right_is_char) {
                string var = gentempcode("string");
                prep += "\t" + var + " = (char *) malloc(2);\n";
                prep += "\t" + var + "[0] = " + yyvsp[0].label + ";\n";
                prep += "\t" + var + "[1] = '\\0';\n";
                right_label = var;
                tamanho_string[var] = "2";
            }

            string temp_tamanho = gentempcode("int");
            yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + prep;
            yyval.traducao += "\t" + temp_tamanho + " = " + tamanho_string[left_label] + " + " + tamanho_string[right_label] + ";\n";
            yyval.traducao += "\t" + temp_tamanho + " = " + temp_tamanho + " + 1;\n";
            yyval.traducao += "\t" + yyval.label + " = (char *) malloc(" + temp_tamanho + ");\n";
            yyval.traducao += "\tstrcpy(" + yyval.label + ", " + left_label + ");\n";
            yyval.traducao += "\tstrcat(" + yyval.label + ", " + right_label + ");\n";

            tamanho_string[yyval.label] = temp_tamanho;
        }
        else {
                
                yyval.label = gentempcode(tipo);
                auto [coercoes, t1, t2] = resolve_coercao(yyvsp[-2].label, yyvsp[0].label, tipo);
                yyval.tipo = tipo;
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + coercoes + "\t" + yyval.label + " = " + t1 + " + " + t2 + ";\n";
            }
            

            }
#line 2202 "y.tab.c"
    break;

  case 39: /* E: E '-' E  */
#line 693 "sintatico.y"
            {   verifica_operacao_string(yyvsp[-2].tipo, yyvsp[0].tipo, "-");
                string tipo = resolve_tipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                auto [coercoes, t1, t2] = resolve_coercao(yyvsp[-2].label, yyvsp[0].label, tipo);
                yyval.label = gentempcode(tipo);
                yyval.tipo = tipo;
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + coercoes + "\t" + yyval.label + " = " + t1 + " - " + t2 + ";\n";
            }
#line 2214 "y.tab.c"
    break;

  case 40: /* E: E '*' E  */
#line 701 "sintatico.y"
            {   
                verifica_operacao_string(yyvsp[-2].tipo, yyvsp[0].tipo, "*");
                string tipo = resolve_tipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                auto [coercoes, t1, t2] = resolve_coercao(yyvsp[-2].label, yyvsp[0].label, tipo);
                yyval.label = gentempcode(tipo);
                yyval.tipo = tipo;
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + coercoes + "\t" + yyval.label + " = " + t1 + " * " + t2 + ";\n";
            }
#line 2227 "y.tab.c"
    break;

  case 41: /* E: E '/' E  */
#line 710 "sintatico.y"
            {   
                verifica_operacao_string(yyvsp[-2].tipo, yyvsp[0].tipo, "/");
                string tipo = resolve_tipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                auto [coercoes, t1, t2] = resolve_coercao(yyvsp[-2].label, yyvsp[0].label, tipo);
                yyval.label = gentempcode(tipo);
                yyval.tipo = tipo;
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + coercoes + "\t" + yyval.label + " = " + t1 + " / " + t2 + ";\n";
            }
#line 2240 "y.tab.c"
    break;

  case 42: /* E: '(' E ')'  */
#line 719 "sintatico.y"
            {   
                yyval.label = yyvsp[-1].label;
                yyval.traducao = yyvsp[-1].traducao;
                yyval.tipo = yyvsp[-1].tipo;
            }
#line 2250 "y.tab.c"
    break;

  case 43: /* E: E GREATER_THAN E  */
#line 725 "sintatico.y"
            {   
                string tipo = resolve_tipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                auto [coercoes, t1, t2] = resolve_coercao(yyvsp[-2].label, yyvsp[0].label, tipo);
                yyval.label = gentempcode(tipo);
                yyval.tipo = "boolean";
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + coercoes + "\t" + yyval.label + " = " + t1 + " > " + t2 + ";\n";
            }
#line 2262 "y.tab.c"
    break;

  case 44: /* E: E LESS_THAN E  */
#line 733 "sintatico.y"
            {   
                string tipo = resolve_tipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                auto [coercoes, t1, t2] = resolve_coercao(yyvsp[-2].label, yyvsp[0].label, tipo);
                yyval.label = gentempcode("boolean");
                yyval.tipo = "boolean";
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + coercoes + "\t" + yyval.label + " = " + t1 + " < " + t2 + ";\n";
                  
            }
#line 2275 "y.tab.c"
    break;

  case 45: /* E: E GREATER_OR_EQUAL E  */
#line 742 "sintatico.y"
            {   
                string tipo = resolve_tipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                auto [coercoes, t1, t2] = resolve_coercao(yyvsp[-2].label, yyvsp[0].label, tipo);
                yyval.label = gentempcode(tipo);
                yyval.tipo = "boolean";
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + coercoes + "\t" + yyval.label + " = " + t1 + " >= " + t2 + ";\n";
                
            }
#line 2288 "y.tab.c"
    break;

  case 46: /* E: E LESS_OR_EQUAL E  */
#line 751 "sintatico.y"
            {   
                string tipo = resolve_tipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                auto [coercoes, t1, t2] = resolve_coercao(yyvsp[-2].label, yyvsp[0].label, tipo);
                yyval.label = gentempcode(tipo);
                yyval.tipo = "boolean";
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + coercoes + "\t" + yyval.label + " = " + t1 + " <= " + t2 + ";\n";
               
            }
#line 2301 "y.tab.c"
    break;

  case 47: /* E: E EQUAL E  */
#line 760 "sintatico.y"
            {   
                string tipo = resolve_tipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                auto [coercoes, t1, t2] = resolve_coercao(yyvsp[-2].label, yyvsp[0].label, tipo);
                yyval.label = gentempcode(tipo);
                yyval.tipo = "boolean";
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + coercoes + "\t" + yyval.label + " = " + t1 + " == " + t2 + ";\n";
               
            }
#line 2314 "y.tab.c"
    break;

  case 48: /* E: E NOT_EQUAL E  */
#line 769 "sintatico.y"
            {   
                string tipo = resolve_tipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                auto [coercoes, t1, t2] = resolve_coercao(yyvsp[-2].label, yyvsp[0].label, tipo);
                yyval.label = gentempcode(tipo);
                yyval.tipo = "boolean";
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + coercoes + "\t" + yyval.label + " = " + t1 + " != " + t2 + ";\n";
                
            }
#line 2327 "y.tab.c"
    break;

  case 49: /* E: NOT E  */
#line 778 "sintatico.y"
            {   
                if(yyvsp[0].tipo != "boolean") {
                    yyerror("Erro na linha " + to_string(linha) + ": não é possível usar o operador '!' em uma variável não booleana!");
                }
                yyval.label = gentempcode("int");
                yyval.tipo = "boolean";
                yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label + " = " "!" + yyvsp[0].label + ";\n";
            }
#line 2340 "y.tab.c"
    break;

  case 50: /* E: E AND E  */
#line 787 "sintatico.y"
            {   
                verifica_tipo_logico(yyvsp[-2].tipo, yyvsp[0].tipo);
                yyval.label = gentempcode("int");
                yyval.tipo = "boolean";
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " && " + yyvsp[0].label + ";\n";
            }
#line 2351 "y.tab.c"
    break;

  case 51: /* E: E OR E  */
#line 794 "sintatico.y"
            {   
                
                verifica_tipo_logico(yyvsp[-2].tipo, yyvsp[0].tipo);
                yyval.label = gentempcode("int");
                yyval.tipo = "boolean";
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " || " + yyvsp[0].label + ";\n";
            }
#line 2363 "y.tab.c"
    break;

  case 52: /* E: TK_ID '=' E  */
#line 803 "sintatico.y"
            {
                string escopo_atual = pilha_escopos.back()["__escopo_nome__"].nome_interno;
                string funcao_atual = pilha_funcao.back()["__funcao_nome__"].nome_interno;
                string chave = yyvsp[-2].label + "_" + escopo_atual + funcao_atual;
                string nome_interno;
                bool variavel_local = false;
                bool variavel_global = false;

                
                if (tipos_atuais.count(chave)) {
                    nome_interno = tipos_atuais[chave].nome_interno;
                    variavel_local = true;
                }
                else {
                    string chave_global = yyvsp[-2].label + "_escopo0" + "_" + funcao_atual;
                    if (tipos_atuais.count(chave_global)) {
                        nome_interno = tipos_atuais[chave_global].nome_interno;
                        variavel_global = true;
                    }
                    
                    else {
                        nome_interno = adiciona_variavel_na_tabela(yyvsp[-2].label, yyvsp[0].tipo, yyvsp[0].label, escopo_atual, funcao_atual);
                        variavel_local = true;
                    }
                }

               
                string tipo_atual = getTipo(yyvsp[-2].label);  
                string novo_tipo = yyvsp[0].tipo;

                if (tipo_atual != novo_tipo) {
                    if (variavel_local) {
                        
                        nome_interno = adiciona_variavel_na_tabela(yyvsp[-2].label, novo_tipo, yyvsp[0].label, escopo_atual, funcao_atual);
                    } else if (variavel_global) {
                        
                        yyerror("Erro: não pode alterar tipo da variável global '" + yyvsp[-2].label + "' em escopo diferente.");
                        exit(1);
                    }
                }


                if (novo_tipo == "string") {
                    if (realocar_var_interna.count(nome_interno)) {
                        yyval.traducao = "\tfree(" + nome_interno + ");\n";
                    }
                    realocar_var_interna[nome_interno] = true;

                    yyval.traducao += yyvsp[-2].traducao + yyvsp[0].traducao;
                    yyval.traducao += "\t" + nome_interno + " = (char *) malloc(" + tamanho_string[yyvsp[0].label] + ");\n";
                    yyval.traducao += "\tstrcpy(" + nome_interno + ", " + yyvsp[0].label + ");\n";
                } else {
                    yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao;
                    yyval.traducao += "\t" + nome_interno + " = " + yyvsp[0].label + ";\n";
                }
            }
#line 2424 "y.tab.c"
    break;

  case 53: /* E: TK_NUM  */
#line 861 "sintatico.y"
            {
                yyval.label = gentempcode("int");
                yyval.tipo = "int";
                yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
            }
#line 2434 "y.tab.c"
    break;

  case 54: /* E: TK_REAL  */
#line 867 "sintatico.y"
            {
                yyval.label = gentempcode("float");
                yyval.tipo = "float";
                yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
            }
#line 2444 "y.tab.c"
    break;

  case 55: /* E: TK_STRING  */
#line 872 "sintatico.y"
                        {

                
                yyval.label = gentempcode("string");
                yyval.tipo = "string";

                  if (!origem_declarada) {
                    yyval.traducao += "\tchar *origem;\n";
                    origem_declarada = true;
                }

                yyval.traducao += "\torigem = (char *) malloc(300); \n";
                yyval.traducao += "\tstrcpy(origem, " + yyvsp[0].label + ");\n";
                yyval.traducao += realizar_contagem("origem", yyval.label);
                yyval.traducao += "\tfree(origem);\n";
                string tamanho = gentempcode("int");
                yyval.traducao += "\t" + tamanho + " = " + tamanho_string[yyval.label]  + " + 1;\n";
                tamanho_string[yyval.label] = tamanho;
                yyval.traducao += "\t" + yyval.label + " = " + "(char *) malloc(" + tamanho + ");\n";
                yyval.traducao += "\tstrcpy(" + yyval.label + "," + yyvsp[0].label + ");\n";
            }
#line 2470 "y.tab.c"
    break;

  case 56: /* E: TK_TRUE  */
#line 894 "sintatico.y"
            {
                yyval.label = gentempcode("int");
                yyval.tipo = "boolean";
                yyval.traducao = "\t" + yyval.label + " = " + "1" + ";\n";
            }
#line 2480 "y.tab.c"
    break;

  case 57: /* E: TK_FALSE  */
#line 900 "sintatico.y"
            {
                yyval.label = gentempcode("int");
                yyval.tipo = "boolean";
                yyval.traducao = "\t" + yyval.label + " = " + "0" + ";\n";
            }
#line 2490 "y.tab.c"
    break;

  case 58: /* E: TK_CHAR  */
#line 906 "sintatico.y"
            {
                yyval.label = gentempcode("char");
                yyval.tipo = "char";
                yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
            }
#line 2500 "y.tab.c"
    break;

  case 59: /* E: TK_ID  */
#line 912 "sintatico.y"
            {   string escopo_atual = pilha_escopos.back()["__escopo_nome__"].nome_interno;
                string tipo = getTipo(yyvsp[0].label); 
                yyval.label = gentempcode(tipo);
                string nome_interno = pega_variavel_na_tabela(yyvsp[0].label);
                yyval.traducao = "\t" + yyval.label + " = " + nome_interno + ";\n";
                yyval.tipo=tipo;

                if(tipo == "string") {
                    
                    yyval.traducao = realizar_contagem(nome_interno, yyval.label);
                    string tamanho = gentempcode("int");
                    yyval.traducao += "\t" + tamanho + " = " + tamanho_string[yyval.label]  + " + 1;\n";
                    tamanho_string[yyval.label] = tamanho;
                    yyval.traducao += "\t" + yyval.label + " = " + "(char *) malloc(" + tamanho_string[yyval.label] + ");\n";
                    yyval.traducao += "\tstrcpy(" + yyval.label + "," + nome_interno + ");\n";
                }
  
            }
#line 2523 "y.tab.c"
    break;

  case 60: /* E: TK_LOCAL TK_ID '=' E  */
#line 932 "sintatico.y"
            {
                
                string escopo_atual = pilha_escopos.back()["__escopo_nome__"].nome_interno;
                string funcao_atual = pilha_funcao.back()["__funcao_nome__"].nome_interno;

                string nome_variavel = adiciona_variavel_na_tabela(yyvsp[-2].label, yyvsp[0].tipo, yyvsp[0].label, escopo_atual, funcao_atual);

                variavel_escopo[yyvsp[-2].label + "_" + escopo_atual] = nome_variavel;
                yyval.escopo = escopo_atual;

                if (yyvsp[0].tipo == "string") {
                    if (realocar_var_interna.count(nome_variavel)) {
                        yyval.traducao = "\tfree(" + nome_variavel + ");\n";
                    }
                    realocar_var_interna[nome_variavel] = true;
                    yyval.traducao += yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + nome_variavel + " = (char *) malloc(" + tamanho_string[yyvsp[0].label] + ");\n";
                    yyval.traducao += "\tstrcpy(" + nome_variavel + ", " + yyvsp[0].label + ");\n";
                } else {
                    yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + nome_variavel + " = " + yyvsp[0].label + ";\n";
                }
            }
#line 2549 "y.tab.c"
    break;

  case 61: /* E: TK_DYNAMIC TK_ID '=' E  */
#line 955 "sintatico.y"
            {
               
                string tipo = getTipo(yyvsp[-2].label);
                string nome_interno;
                string escopo_atual = pilha_escopos.back()["__escopo_nome__"].nome_interno;
                string funcao_atual = pilha_funcao.back()["__funcao_nome__"].nome_interno;

                if(tipo != yyvsp[0].tipo) {
                    nome_interno = adiciona_variavel_na_tabela(yyvsp[-2].label, yyvsp[0].tipo, yyvsp[0].label, escopo_atual, funcao_atual);
                } else {
                    nome_interno = pega_variavel_dinamica(yyvsp[-2].label, tipo);
                }

                if (yyvsp[0].tipo == "string") {
                    if (realocar_var_interna.count(nome_interno)) {
                        yyval.traducao = "\tfree(" + nome_interno + ");\n";
                    }
                    realocar_var_interna[nome_interno] = true;
                    yyval.traducao += yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + nome_interno + " = (char *) malloc(" + tamanho_string[yyvsp[0].label] + ");\n";
                    yyval.traducao += "\tstrcpy(" + nome_interno + ", " + yyvsp[0].label + ");\n";
                } else {
                    yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + nome_interno + " = " + yyvsp[0].label + ";\n";
                }
            }
#line 2578 "y.tab.c"
    break;

  case 62: /* E: '(' TK_INT ')' TK_ID  */
#line 980 "sintatico.y"
            {  
                
                string tipo_atual = getTipo(yyvsp[0].label);
                string novo_tipo = "int";
                yyval.label = gentempcode(novo_tipo);
                yyval.tipo = novo_tipo;
                string nome_interno = pega_variavel_na_tabela(yyvsp[0].label);
                yyval.traducao = "\t" + yyval.label + " = " + "(" + novo_tipo + ")" + " " + nome_interno + ";\n";
            }
#line 2592 "y.tab.c"
    break;

  case 63: /* E: '(' TK_FLOAT ')' TK_ID  */
#line 990 "sintatico.y"
            {  
                string tipo_atual = getTipo(yyvsp[0].label);
                string novo_tipo = "float";
                yyval.label = gentempcode(novo_tipo);
                yyval.tipo = novo_tipo;
                string nome_interno = pega_variavel_na_tabela(yyvsp[0].label);
                yyval.traducao = "\t" + yyval.label + " = " + "(" + novo_tipo + ")" + " " + nome_interno + ";\n";
            }
#line 2605 "y.tab.c"
    break;

  case 64: /* E: '(' TK_BOOLEAN ')' TK_ID  */
#line 999 "sintatico.y"
            {  
                yyerror("Erro na linha " + to_string(linha) + ": não é possível transformar a variável em boolean!");
            }
#line 2613 "y.tab.c"
    break;

  case 65: /* E: TK_ID TK_INC  */
#line 1003 "sintatico.y"
            {
                string nome_interno = pega_variavel_na_tabela(yyvsp[-1].label);
                yyval.traducao = "\t" + nome_interno + " = " + nome_interno + " + 1;\n";
            }
#line 2622 "y.tab.c"
    break;

  case 66: /* E: TK_ID TK_DEC  */
#line 1008 "sintatico.y"
            {
                string nome_interno = pega_variavel_na_tabela(yyvsp[-1].label);
                yyval.traducao = "\t" + nome_interno + " = " + nome_interno + " - 1;\n";
            }
#line 2631 "y.tab.c"
    break;

  case 67: /* E: TK_ID '(' ')'  */
#line 1012 "sintatico.y"
                            {
                yyval.traducao = "\tgoto label_" + yyvsp[-2].label + ";\n";
                yyval.traducao += "end_" + yyvsp[-2].label + ":\n";
            }
#line 2640 "y.tab.c"
    break;


#line 2644 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1017 "sintatico.y"


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
