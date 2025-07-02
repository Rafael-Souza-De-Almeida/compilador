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
string gerar_traducao_soma_var(
    string, string , string ,
    string , string , string , string
);



#line 175 "y.tab.c"

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
    TK_CONTINUE = 290,             /* TK_CONTINUE  */
    TK_BREAK = 291,                /* TK_BREAK  */
    TK_TYPE = 292,                 /* TK_TYPE  */
    TOKEN_STRING_TYPE = 293        /* TOKEN_STRING_TYPE  */
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
#define TK_CONTINUE 290
#define TK_BREAK 291
#define TK_TYPE 292
#define TOKEN_STRING_TYPE 293

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
  YYSYMBOL_TK_CONTINUE = 35,               /* TK_CONTINUE  */
  YYSYMBOL_TK_BREAK = 36,                  /* TK_BREAK  */
  YYSYMBOL_TK_TYPE = 37,                   /* TK_TYPE  */
  YYSYMBOL_TOKEN_STRING_TYPE = 38,         /* TOKEN_STRING_TYPE  */
  YYSYMBOL_39_ = 39,                       /* '+'  */
  YYSYMBOL_40_ = 40,                       /* '-'  */
  YYSYMBOL_41_ = 41,                       /* '*'  */
  YYSYMBOL_42_ = 42,                       /* '/'  */
  YYSYMBOL_43_ = 43,                       /* '('  */
  YYSYMBOL_44_ = 44,                       /* ')'  */
  YYSYMBOL_45_ = 45,                       /* '{'  */
  YYSYMBOL_46_ = 46,                       /* '}'  */
  YYSYMBOL_47_ = 47,                       /* ';'  */
  YYSYMBOL_48_ = 48,                       /* '='  */
  YYSYMBOL_49_ = 49,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_S = 51,                         /* S  */
  YYSYMBOL_BLOCO = 52,                     /* BLOCO  */
  YYSYMBOL_53_1 = 53,                      /* $@1  */
  YYSYMBOL_COMANDOS = 54,                  /* COMANDOS  */
  YYSYMBOL_COMANDO = 55,                   /* COMANDO  */
  YYSYMBOL_BEGIN_WHILE = 56,               /* BEGIN_WHILE  */
  YYSYMBOL_CLOSE_WHILE = 57,               /* CLOSE_WHILE  */
  YYSYMBOL_IDENTIFICADOR_FOR = 58,         /* IDENTIFICADOR_FOR  */
  YYSYMBOL_BEGIN_FOR = 59,                 /* BEGIN_FOR  */
  YYSYMBOL_CLOSE_FOR = 60,                 /* CLOSE_FOR  */
  YYSYMBOL_LOOP_START_WHILE = 61,          /* LOOP_START_WHILE  */
  YYSYMBOL_BEGIN_DO = 62,                  /* BEGIN_DO  */
  YYSYMBOL_CLOSE_DO = 63,                  /* CLOSE_DO  */
  YYSYMBOL_E = 64                          /* E  */
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   325

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  144

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


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
      43,    44,    41,    39,     2,    40,     2,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    49,    47,
       2,    48,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   125,   125,   221,   221,   227,   232,   236,   240,   258,
     261,   264,   267,   281,   295,   309,   323,   338,   354,   373,
     416,   440,   465,   473,   485,   495,   505,   513,   531,   541,
     552,   569,   583,   736,   744,   753,   762,   768,   778,   880,
     890,   900,  1002,  1012,  1021,  1028,  1037,  1228,  1234,  1240,
    1261,  1267,  1273,  1279,  1412,  1421,  1430
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
  "TK_CONTINUE", "TK_BREAK", "TK_TYPE", "TOKEN_STRING_TYPE", "'+'", "'-'",
  "'*'", "'/'", "'('", "')'", "'{'", "'}'", "';'", "'='", "':'", "$accept",
  "S", "BLOCO", "$@1", "COMANDOS", "COMANDO", "BEGIN_WHILE", "CLOSE_WHILE",
  "IDENTIFICADOR_FOR", "BEGIN_FOR", "CLOSE_FOR", "LOOP_START_WHILE",
  "BEGIN_DO", "CLOSE_DO", "E", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-27)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -7,    18,    26,   -16,   -27,   -15,   -10,   -27,   -27,    54,
     -27,   -27,   -27,   -27,   -26,    -1,     0,     2,     3,   -27,
      11,    12,   111,    13,   -27,   -27,   -27,    14,    16,    33,
      97,   -27,    35,    54,    36,    74,   -10,   121,   -27,   111,
      41,    45,    48,    50,   111,   111,    46,   -27,    53,   111,
     -27,   -27,    52,    68,    69,    77,   158,   -27,   -27,   111,
     -27,    70,    66,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   -27,   260,   114,   118,   120,
     123,   183,   192,   217,   124,   125,   126,   127,   -27,   226,
     111,    86,   260,   260,   260,   260,   260,   260,    53,   292,
     283,   283,   -17,   -17,    92,    94,    95,   103,   104,   105,
     -10,   106,   -27,   -27,   -27,   -27,    -8,   111,   108,   109,
     110,   112,   -27,   -27,   128,   117,   -10,   111,   251,   -27,
     -27,   -27,   -27,   -10,   -27,   -27,   149,   119,   -27,   -27,
     -27,   -27,   -27,   -27
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     3,     2,     6,
      47,    48,    50,    51,    53,     0,     0,     0,    52,    49,
       0,     0,     0,     0,    27,    24,    30,     0,     0,     0,
       0,    11,     0,     6,     0,     0,     0,     0,     8,     0,
       0,     0,     0,     0,     0,     0,    53,    52,    43,     0,
      23,    22,     0,     0,     0,     0,     0,     4,     5,     0,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    36,     0,
       0,     0,    37,    38,    39,    40,    41,    42,    44,    45,
      32,    33,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     0,    54,    55,    56,    29,     0,     0,     0,     0,
       0,     0,     9,    10,    17,     0,     0,     0,     0,    12,
      13,    14,    15,     0,    16,    25,     0,     0,    18,    20,
      28,    31,    19,    21
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -27,   -27,    -6,   -27,   132,   -27,   -27,   -27,   -27,   -27,
     -27,   -27,   -27,   -27,   -21
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,    31,     9,    32,    33,    34,   139,    61,    35,
     142,   126,    36,   143,    37
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       8,    48,     1,    63,    64,    65,    66,    67,    68,    56,
      69,    70,    63,    64,    65,    66,    67,    68,    76,    69,
      70,    38,    39,    81,    82,     3,     4,     5,    83,     6,
      62,    71,    72,    73,    74,     7,    40,    41,    89,    42,
      43,   127,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,    44,    45,    49,    10,    11,    12,
      13,    50,    14,    51,    15,    16,    17,    18,    19,   116,
      52,    20,    21,    63,    64,    65,    66,    67,    68,    59,
      22,    57,    60,    23,    77,    24,    25,    26,    78,    27,
      28,    79,    29,    80,    39,    84,   128,    30,    91,     7,
      10,    11,    12,    13,   124,    46,   136,    53,    54,    55,
      47,    19,    85,    86,    10,    11,    12,    13,    90,    46,
     135,    87,   104,    22,    47,    19,   105,   138,   106,   117,
     140,   107,   111,   112,   113,   114,   118,    22,   119,   120,
      30,    63,    64,    65,    66,    67,    68,   121,    69,    70,
     125,   122,   123,     0,    30,   129,   130,   131,   133,   132,
      71,    72,    73,    74,   134,    58,   141,     0,    75,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    63,    64,
      65,    66,    67,    68,     0,    69,    70,     0,    71,    72,
      73,    74,     0,     0,     7,     0,     0,    71,    72,    73,
      74,     0,    88,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    63,    64,    65,    66,    67,    68,     0,    69,
      70,     0,    71,    72,    73,    74,     0,   108,     0,     0,
       0,    71,    72,    73,    74,     0,   109,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    63,    64,    65,    66,
      67,    68,     0,    69,    70,     0,    71,    72,    73,    74,
       0,   110,     0,     0,     0,    71,    72,    73,    74,     0,
     115,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      63,    64,    65,    66,    67,    68,     0,    69,    70,     0,
      71,    72,    73,    74,     0,   137,     0,     0,     0,    71,
      72,    73,    74,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    63,    64,    65,    66,    67,    68,     0,    69,
       0,     0,     0,     0,    73,    74
};

static const yytype_int16 yycheck[] =
{
       6,    22,     9,    20,    21,    22,    23,    24,    25,    30,
      27,    28,    20,    21,    22,    23,    24,    25,    39,    27,
      28,    47,    48,    44,    45,     7,     0,    43,    49,    44,
      36,    39,    40,    41,    42,    45,    37,    37,    59,    37,
      37,    49,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    43,    43,    43,     3,     4,     5,
       6,    47,     8,    47,    10,    11,    12,    13,    14,    90,
      37,    17,    18,    20,    21,    22,    23,    24,    25,    43,
      26,    46,     8,    29,    43,    31,    32,    33,    43,    35,
      36,    43,    38,    43,    48,    43,   117,    43,    32,    45,
       3,     4,     5,     6,   110,     8,   127,    10,    11,    12,
      13,    14,    44,    44,     3,     4,     5,     6,    48,     8,
     126,    44,     8,    26,    13,    14,     8,   133,     8,    43,
     136,     8,     8,     8,     8,     8,    44,    26,    44,    44,
      43,    20,    21,    22,    23,    24,    25,    44,    27,    28,
      44,    47,    47,    -1,    43,    47,    47,    47,    30,    47,
      39,    40,    41,    42,    47,    33,    47,    -1,    47,    20,
      21,    22,    23,    24,    25,    -1,    27,    28,    20,    21,
      22,    23,    24,    25,    -1,    27,    28,    -1,    39,    40,
      41,    42,    -1,    -1,    45,    -1,    -1,    39,    40,    41,
      42,    -1,    44,    20,    21,    22,    23,    24,    25,    -1,
      27,    28,    20,    21,    22,    23,    24,    25,    -1,    27,
      28,    -1,    39,    40,    41,    42,    -1,    44,    -1,    -1,
      -1,    39,    40,    41,    42,    -1,    44,    20,    21,    22,
      23,    24,    25,    -1,    27,    28,    20,    21,    22,    23,
      24,    25,    -1,    27,    28,    -1,    39,    40,    41,    42,
      -1,    44,    -1,    -1,    -1,    39,    40,    41,    42,    -1,
      44,    20,    21,    22,    23,    24,    25,    -1,    27,    28,
      20,    21,    22,    23,    24,    25,    -1,    27,    28,    -1,
      39,    40,    41,    42,    -1,    44,    -1,    -1,    -1,    39,
      40,    41,    42,    20,    21,    22,    23,    24,    25,    -1,
      27,    28,    20,    21,    22,    23,    24,    25,    -1,    27,
      -1,    -1,    -1,    -1,    41,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    51,     7,     0,    43,    44,    45,    52,    53,
       3,     4,     5,     6,     8,    10,    11,    12,    13,    14,
      17,    18,    26,    29,    31,    32,    33,    35,    36,    38,
      43,    52,    54,    55,    56,    59,    62,    64,    47,    48,
      37,    37,    37,    37,    43,    43,     8,    13,    64,    43,
      47,    47,    37,    10,    11,    12,    64,    46,    54,    43,
       8,    58,    52,    20,    21,    22,    23,    24,    25,    27,
      28,    39,    40,    41,    42,    47,    64,    43,    43,    43,
      43,    64,    64,    64,    43,    44,    44,    44,    44,    64,
      48,    32,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,     8,     8,     8,     8,    44,    44,
      44,     8,     8,     8,     8,    44,    64,    43,    44,    44,
      44,    44,    47,    47,    52,    44,    61,    49,    64,    47,
      47,    47,    47,    30,    47,    52,    64,    44,    52,    57,
      52,    47,    60,    63
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    53,    52,    54,    54,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     0,     4,     2,     0,     2,     2,     5,
       5,     1,     6,     6,     6,     6,     6,     5,     7,     8,
       7,     8,     2,     2,     1,     0,     1,     1,     0,     0,
       1,     0,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4
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
  case 2: /* S: TK_FUNCTION TK_MAIN '(' ')' BLOCO  */
#line 126 "sintatico.y"
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

                codigo += yyvsp[0].traducao;

              

                for(auto iterador : simbolos_declarados) {

                    if(iterador.tipo == "string") {
                        codigo += "\tfree(" + iterador.nome_interno + "->s" + ")" + ";\n";
                        continue;
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
#line 1556 "y.tab.c"
    break;

  case 3: /* $@1: %empty  */
#line 221 "sintatico.y"
                  {entra_escopo();}
#line 1562 "y.tab.c"
    break;

  case 4: /* BLOCO: '{' $@1 COMANDOS '}'  */
#line 221 "sintatico.y"
                                                { sai_escopo();
            
                yyval.traducao = yyvsp[-1].traducao;
            }
#line 1571 "y.tab.c"
    break;

  case 5: /* COMANDOS: COMANDO COMANDOS  */
#line 228 "sintatico.y"
            {
                yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
            }
#line 1579 "y.tab.c"
    break;

  case 6: /* COMANDOS: %empty  */
#line 232 "sintatico.y"
            {
                yyval.traducao = "";
            }
#line 1587 "y.tab.c"
    break;

  case 7: /* COMANDO: E ';'  */
#line 237 "sintatico.y"
            {
                yyval = yyvsp[-1];
            }
#line 1595 "y.tab.c"
    break;

  case 8: /* COMANDO: TK_ID ';'  */
#line 241 "sintatico.y"
            {   
                string tipo = getTipo(yyvsp[-1].label);
                string nome_variavel = pega_variavel_na_tabela(yyvsp[-1].label, tipo);
                if(nome_variavel == "") {
                    yyerror("A variável não foi declarada");
                }

                yyval.traducao += "\tswitch (" + nome_variavel + "->tipo) {\n";
                yyval.traducao += "\t\tcase 1: cout << " + nome_variavel + "->i << endl; break;\n";
                yyval.traducao += "\t\tcase 2: cout << " + nome_variavel + "->f << endl; break;\n";
                yyval.traducao += "\t\tcase 3: cout << " + nome_variavel + "->b << endl; break;\n";
                yyval.traducao += "\t\tcase 4: cout << " + nome_variavel + "->c << endl; break;\n";
                yyval.traducao += "\t\tcase 5: cout << " + nome_variavel + "->s << endl; break;\n";
                yyval.traducao += "\t\tdefault: cout << \"[ERRO: tipo desconhecido]\" << endl; break;\n";
                yyval.traducao += "\t}\n";
            }
#line 1616 "y.tab.c"
    break;

  case 9: /* COMANDO: TK_PRINT '(' E ')' ';'  */
#line 258 "sintatico.y"
                                     {
                yyval.traducao = yyvsp[-4].traducao + yyvsp[-2].traducao +  "\t cout << "  + yyvsp[-2].label + ";\n";
            }
#line 1624 "y.tab.c"
    break;

  case 10: /* COMANDO: TK_PRINTLN '(' E ')' ';'  */
#line 261 "sintatico.y"
                                       {
                yyval.traducao = yyvsp[-4].traducao + yyvsp[-2].traducao +  "\t cout << "  + yyvsp[-2].label + " << endl;\n";
            }
#line 1632 "y.tab.c"
    break;

  case 11: /* COMANDO: BLOCO  */
#line 264 "sintatico.y"
                    {
                yyval.traducao = yyvsp[0].traducao;

            }
#line 1641 "y.tab.c"
    break;

  case 12: /* COMANDO: TK_INT TK_TYPE '(' TK_ID ')' ';'  */
#line 268 "sintatico.y"
            {
            
            string temp_associada = gentempcode("int");
            string nome_interno = adiciona_variavel_na_tabela(yyvsp[-2].label, "int" , temp_associada);

            string comando_leitura;
            comando_leitura  = "\tcin >> " + nome_interno + ";\n";
            comando_leitura += "\tif (cin.fail()) {\n";
            comando_leitura += "\t\tcerr << \"Entrada inválida para tipo int!\" << endl;\n";
            comando_leitura += "\t\texit(1);\n\t}\n";
        
                    yyval.traducao = comando_leitura;
            }
#line 1659 "y.tab.c"
    break;

  case 13: /* COMANDO: TK_FLOAT TK_TYPE '(' TK_ID ')' ';'  */
#line 282 "sintatico.y"
            {
            
            string temp_associada = gentempcode("float");
            string nome_interno = adiciona_variavel_na_tabela(yyvsp[-2].label, "float" , temp_associada);

            string comando_leitura;
            comando_leitura  = "\tcin >> " + nome_interno + ";\n";
            comando_leitura += "\tif (cin.fail()) {\n";
            comando_leitura += "\t\tcerr << \"Entrada inválida para tipo float!\" << endl;\n";
            comando_leitura += "\t\texit(1);\n\t}\n";
        
            yyval.traducao = comando_leitura;
            }
#line 1677 "y.tab.c"
    break;

  case 14: /* COMANDO: TK_BOOLEAN TK_TYPE '(' TK_ID ')' ';'  */
#line 296 "sintatico.y"
            {
            
            string temp_associada = gentempcode("boolean");
            string nome_interno = adiciona_variavel_na_tabela(yyvsp[-2].label, "boolean" , temp_associada);

            string comando_leitura;
            comando_leitura  = "\tcin >> " + nome_interno + ";\n";
            comando_leitura += "\tif (cin.fail()) {\n";
            comando_leitura += "\t\tcerr << \"Entrada inválida para tipo boolean!\" << endl;\n";
            comando_leitura += "\t\texit(1);\n\t}\n";
        
            yyval.traducao = comando_leitura;
            }
#line 1695 "y.tab.c"
    break;

  case 15: /* COMANDO: TK_CHAR TK_TYPE '(' TK_ID ')' ';'  */
#line 310 "sintatico.y"
            {
            
            string temp_associada = gentempcode("char");
            string nome_interno = adiciona_variavel_na_tabela(yyvsp[-2].label, "char" , temp_associada);

            string comando_leitura;
            comando_leitura  = "\tcin >> " + nome_interno + ";\n";
            comando_leitura += "\tif (cin.fail()) {\n";
            comando_leitura += "\t\tcerr << \"Entrada inválida para tipo char!\" << endl;\n";
            comando_leitura += "\t\texit(1);\n\t}\n";
        
            yyval.traducao = comando_leitura;
            }
#line 1713 "y.tab.c"
    break;

  case 16: /* COMANDO: TOKEN_STRING_TYPE TK_TYPE '(' TK_ID ')' ';'  */
#line 324 "sintatico.y"
            {
            
            string temp_associada = gentempcode("string");
            string nome_interno = adiciona_variavel_na_tabela(yyvsp[-2].label, "string" , temp_associada);

            string comando_leitura;
            comando_leitura  = "\tcin >> " + nome_interno + ";\n";
            comando_leitura += "\tif (cin.fail()) {\n";
            comando_leitura += "\t\tcerr << \"Entrada inválida para tipo string!\" << endl;\n";
            comando_leitura += "\t\texit(1);\n\t}\n";
        
            yyval.traducao = comando_leitura;
            }
#line 1731 "y.tab.c"
    break;

  case 17: /* COMANDO: TK_IF '(' E ')' BLOCO  */
#line 338 "sintatico.y"
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
#line 1752 "y.tab.c"
    break;

  case 18: /* COMANDO: TK_IF '(' E ')' BLOCO TK_ELSE BLOCO  */
#line 354 "sintatico.y"
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
#line 1776 "y.tab.c"
    break;

  case 19: /* COMANDO: BEGIN_FOR IDENTIFICADOR_FOR '=' E ':' E BLOCO CLOSE_FOR  */
#line 373 "sintatico.y"
                                                                      {

                    if (yyvsp[-4].tipo != "int") {
                        yyerror("Início do for deve ser numérico (int)");
                    }

                    if (yyvsp[-2].tipo != "int") {
                        yyerror("Fim do for deve ser numérico (int)");
                    }

                    string label_inicio = pilha_loop_inicio.top();
                    string label_fim = pilha_loop_fim.top();
                    string label_incremento = pilha_loop_continue.top();

                    string nome_variavel = pega_variavel_na_tabela(yyvsp[-6].label, "int");

                    yyval.traducao = ""; 
                    yyval.traducao += yyvsp[-4].traducao + yyvsp[-2].traducao;
                    yyval.traducao += "\t" + nome_variavel + " = " + "(Var *) malloc(sizeof(Var));\n";
                    yyval.traducao += "\t" + nome_variavel + "->tipo" + " = 1;\n";
                    yyval.traducao += "\t" + nome_variavel + "->i" + " = " + yyvsp[-4].label + ";\n";
                    yyval.traducao += label_inicio + ":\n";

                    string pre_condicao = gentempcode("boolean");
                    string condicao = gentempcode("boolean");

                    yyval.traducao += "\t" + pre_condicao + " = " + yyvsp[-2].label + " - 1;\n"; 
                    yyval.traducao += "\t" + condicao + " = " + nome_variavel + "->i" + " > " + pre_condicao + ";\n"; 
                    yyval.traducao += "\tif (" + condicao + ") goto " + label_fim + ";\n";

                    yyval.traducao += yyvsp[-1].traducao;  

                    yyval.traducao += label_incremento + ":\n";
                    yyval.traducao += "\t" + nome_variavel + "->i" + " = " + nome_variavel + "->i" + " + 1;\n";
                    yyval.traducao += "\tgoto " + label_inicio + ";\n";

                    yyval.traducao += label_fim + ":\n";

                     if (!pilha_loop_continue.empty()) pilha_loop_continue.pop();
                    if (!pilha_loop_inicio.empty()) pilha_loop_inicio.pop();
                    if (!pilha_loop_fim.empty()) pilha_loop_fim.pop();


                }
#line 1825 "y.tab.c"
    break;

  case 20: /* COMANDO: BEGIN_WHILE '(' E ')' LOOP_START_WHILE BLOCO CLOSE_WHILE  */
#line 416 "sintatico.y"
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

                pilha_loop_inicio.pop();
                pilha_loop_fim.pop();
            }
#line 1854 "y.tab.c"
    break;

  case 21: /* COMANDO: BEGIN_DO BLOCO TK_WHILE '(' E ')' ';' CLOSE_DO  */
#line 441 "sintatico.y"
                {
                    if(yyvsp[-3].tipo != "boolean") {
                        yyerror("Erro: condição do 'do while' deve ser booleana");
                    }

                    string label_inicio = pilha_loop_inicio.top();
                    string label_fim = pilha_loop_fim.top();

                    string condicao = gentempcode("boolean");

                    yyval.traducao = "";
                    yyval.traducao += label_inicio + ":\n";
                    yyval.traducao += yyvsp[-6].traducao;         
                    yyval.traducao += yyvsp[-3].traducao;         
                    yyval.traducao += "\t" + condicao + " = !" + yyvsp[-3].label + ";\n";
                    yyval.traducao += "\tif (" + condicao + ") goto " + label_fim + ";\n";
                    yyval.traducao += "\tgoto " + label_inicio + ";\n";
                    yyval.traducao += label_fim + ":\n";

                       if (!pilha_loop_inicio.empty()) pilha_loop_inicio.pop();
                        if (!pilha_loop_fim.empty()) pilha_loop_fim.pop();
                        if (!pilha_loop_continue.empty()) pilha_loop_continue.pop();
                }
#line 1882 "y.tab.c"
    break;

  case 22: /* COMANDO: TK_BREAK ';'  */
#line 465 "sintatico.y"
                           {

            if (pilha_loop_fim.empty()) {
                yyerror("Comando 'break' fora de um loop.");
            }

            yyval.traducao = "\tgoto " + pilha_loop_fim.top() + ";\n";
            }
#line 1895 "y.tab.c"
    break;

  case 23: /* COMANDO: TK_CONTINUE ';'  */
#line 473 "sintatico.y"
                              {
               if (pilha_loop_continue.empty()) {
                    yyerror("Comando 'continue' fora de um loop.");
                } else {
                    cout << "DEBUG pilha continue top: " << pilha_loop_continue.top() << endl;
                    yyval.traducao = "\tgoto " + pilha_loop_continue.top() + ";\n";
                }

            }
#line 1909 "y.tab.c"
    break;

  case 24: /* BEGIN_WHILE: TK_WHILE  */
#line 486 "sintatico.y"
                    {
                        esta_no_while = true;
                        qtdWhile++;
                        yyval.label = "";
                        
                    }
#line 1920 "y.tab.c"
    break;

  case 25: /* CLOSE_WHILE: %empty  */
#line 495 "sintatico.y"
                    {
                        qtdWhile--;
                        if(qtdWhile == 0) {
                            esta_no_while = false;
                        }
                        yyval.label = "";
                        
                    }
#line 1933 "y.tab.c"
    break;

  case 26: /* IDENTIFICADOR_FOR: TK_ID  */
#line 506 "sintatico.y"
                    {
                        string indice_for = gentempcode("int");
                        string nome_variavel = adiciona_variavel_na_tabela(yyvsp[0].label, "int", indice_for);
                        yyval.label = yyvsp[0].label;
                        
                    }
#line 1944 "y.tab.c"
    break;

  case 27: /* BEGIN_FOR: TK_FOR  */
#line 514 "sintatico.y"
                    {
                        string label_inicio = nova_label("for", "inicio");
                        string label_fim = nova_label("for", "fim");
                        string label_incremento = nova_label("for", "incremento");

                        pilha_loop_inicio.push(label_inicio);
                        pilha_loop_fim.push(label_fim);
                        pilha_loop_continue.push(label_incremento);

                        esta_no_for = true;
                        qtdFor++;
                       
                       yyval.label = label_inicio + "|" + label_fim + "|" + label_incremento;
                        
                    }
#line 1964 "y.tab.c"
    break;

  case 28: /* CLOSE_FOR: %empty  */
#line 531 "sintatico.y"
                    {
                        qtdFor--;
                        if(qtdFor == 0) {
                            esta_no_for = false;
                        }
                        yyval.label = "";
                        
                    }
#line 1977 "y.tab.c"
    break;

  case 29: /* LOOP_START_WHILE: %empty  */
#line 541 "sintatico.y"
                    {
                        string label_inicio = nova_label("while", "inicio");
                        string label_fim = nova_label("while", "fim");

                        pilha_loop_inicio.push(label_inicio);
                        pilha_loop_fim.push(label_fim);

                        yyval.label = label_inicio + "|" + label_fim;
                        
                    }
#line 1992 "y.tab.c"
    break;

  case 30: /* BEGIN_DO: TK_DO  */
#line 553 "sintatico.y"
{
    string label_inicio = nova_label("do", "inicio");
    string label_fim = nova_label("do", "fim");

    pilha_loop_inicio.push(label_inicio);
    pilha_loop_fim.push(label_fim);
    pilha_loop_continue.push(label_inicio); 

    esta_no_do_while = true;
    qtdDoWhile++;

    yyval.label = label_inicio + "|" + label_fim;
}
#line 2010 "y.tab.c"
    break;

  case 31: /* CLOSE_DO: %empty  */
#line 569 "sintatico.y"
{
  
    qtdDoWhile--;
    if(qtdDoWhile == 0) {

        esta_no_do_while = false;
    }

    yyval.label = "";
}
#line 2025 "y.tab.c"
    break;

  case 32: /* E: E '+' E  */
#line 584 "sintatico.y"
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
                
                if(yyvsp[-2].tipo == "Var" || yyvsp[0].tipo == "Var") {

                    if(yyvsp[-2].tipo == "Var" && yyvsp[0].tipo != "Var") {

                        // // CHAR + CHAR → string
                        // string cmp_char_1 = gentempcode("boolean");
                        // string cmp_char_2 = gentempcode("boolean");
                        // string both_char = gentempcode("boolean");

                        // $$.traducao += "\t" + cmp_char_1 + " = " + $1.label + "->tipo == 4;\n";
                        // $$.traducao += "\t" + cmp_char_2 + " = " + tipo_var_direita + "->tipo == 4;\n";
                        // $$.traducao += "\t" + both_char + " = 0;\n";
                        // $$.traducao += "\tif (" + cmp_char_1 + ") if (" + cmp_char_2 + ") " + both_char + " = 1;\n";
                        // $$.traducao += "\tif (" + both_char + ") goto operacao_char_char_" + to_string(label_tipo_char_char) + ";\n";

                        // // CHAR + STRING
                        // string cmp_char_str_1 = gentempcode("boolean");
                        // string cmp_char_str_2 = gentempcode("boolean");
                        // string char_str = gentempcode("boolean");

                        // $$.traducao += "\t" + cmp_char_str_1 + " = " + $1.label + "->tipo == 4;\n";
                        // $$.traducao += "\t" + cmp_char_str_2 + " = " + tipo_var_direita + "->tipo == 5;\n";
                        // $$.traducao += "\t" + char_str + " = 0;\n";
                        // $$.traducao += "\tif (" + cmp_char_str_1 + ") if (" + cmp_char_str_2 + ") " + char_str + " = 1;\n";
                        // $$.traducao += "\tif (" + char_str + ") goto operacao_string_" + to_string(label_tipo_string) + ";\n";

                        // // STRING + CHAR
                        // string cmp_str_char_1 = gentempcode("boolean");
                        // string cmp_str_char_2 = gentempcode("boolean");
                        // string str_char = gentempcode("boolean");

                        // $$.traducao += "\t" + cmp_str_char_1 + " = " + $1.label + "->tipo == 5;\n";
                        // $$.traducao += "\t" + cmp_str_char_2 + " = " + tipo_var_direita + "->tipo == 4;\n";
                        // $$.traducao += "\t" + str_char + " = 0;\n";
                        // $$.traducao += "\tif (" + cmp_str_char_1 + ") if (" + cmp_str_char_2 + ") " + str_char + " = 1;\n";
                        // $$.traducao += "\tif (" + str_char + ") goto operacao_string_" + to_string(label_tipo_string) + ";\n";

                        // DEFAULT (erro de tipo)
                        // $$.traducao += "\tgoto tipo_default_" + to_string(label_tipo_default) + ";\n";

                  
                    yyval.traducao = gerar_traducao_soma_var(yyvsp[-2].label, yyvsp[-2].tipo, yyvsp[-2].traducao, yyvsp[0].label, yyvsp[0].tipo, yyvsp[0].traducao, "esquerda");
                    yyval.label = yyvsp[-2].label;
                    yyval.tipo = "Var";
    
                    // $$.label = gentempcode("Var");
                    // auto [coercoes, t1, t2] = resolve_coercao($1.label, $3.label, "float");
                    // $$.tipo = "Var";
                    // $$.traducao += "\t" + $$.label + " = " + t_extra + " + " + $3.label + ";\n";

                }
    
               if(yyvsp[0].tipo == "Var" && yyvsp[-2].tipo != "Var") {


                    yyval.traducao = gerar_traducao_soma_var(yyvsp[-2].label, yyvsp[-2].tipo, yyvsp[-2].traducao, yyvsp[0].label, yyvsp[0].tipo, yyvsp[0].traducao, "direita");
                    yyval.label = yyvsp[0].label;
                    yyval.tipo = "Var";



    
                 } else if (yyvsp[-2].tipo == "Var" && yyvsp[0].tipo == "Var") {

                    yyval.traducao = gerar_traducao_soma_var(yyvsp[-2].label, yyvsp[-2].tipo, yyvsp[-2].traducao, yyvsp[0].label, yyvsp[0].tipo, yyvsp[0].traducao, "ambos");
                    yyval.label = yyvsp[-2].label;
                    yyval.tipo = "Var";
                }


                 } else {

                     auto [coercoes, t1, t2] = resolve_coercao(yyvsp[-2].label, yyvsp[0].label, tipo);
                     yyval.tipo = tipo;
                     cout << "oi t16 é: " + yyvsp[0].tipo <<endl; 
                     yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + coercoes + "\t" + yyval.label + " = " + t1 + " + " + t2 + ";\n";
                 }

             }

        }
#line 2179 "y.tab.c"
    break;

  case 33: /* E: E '-' E  */
#line 737 "sintatico.y"
            {   verifica_operacao_string(yyvsp[-2].tipo, yyvsp[0].tipo, "-");
                string tipo = resolve_tipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                auto [coercoes, t1, t2] = resolve_coercao(yyvsp[-2].label, yyvsp[0].label, tipo);
                yyval.label = gentempcode(tipo);
                yyval.tipo = tipo;
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + coercoes + "\t" + yyval.label + " = " + t1 + " - " + t2 + ";\n";
            }
#line 2191 "y.tab.c"
    break;

  case 34: /* E: E '*' E  */
#line 745 "sintatico.y"
            {   
                verifica_operacao_string(yyvsp[-2].tipo, yyvsp[0].tipo, "*");
                string tipo = resolve_tipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                auto [coercoes, t1, t2] = resolve_coercao(yyvsp[-2].label, yyvsp[0].label, tipo);
                yyval.label = gentempcode(tipo);
                yyval.tipo = tipo;
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + coercoes + "\t" + yyval.label + " = " + t1 + " * " + t2 + ";\n";
            }
#line 2204 "y.tab.c"
    break;

  case 35: /* E: E '/' E  */
#line 754 "sintatico.y"
            {   
                verifica_operacao_string(yyvsp[-2].tipo, yyvsp[0].tipo, "/");
                string tipo = resolve_tipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                auto [coercoes, t1, t2] = resolve_coercao(yyvsp[-2].label, yyvsp[0].label, tipo);
                yyval.label = gentempcode(tipo);
                yyval.tipo = tipo;
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + coercoes + "\t" + yyval.label + " = " + t1 + " / " + t2 + ";\n";
            }
#line 2217 "y.tab.c"
    break;

  case 36: /* E: '(' E ')'  */
#line 763 "sintatico.y"
            {   
                yyval.label = yyvsp[-1].label;
                yyval.traducao = yyvsp[-1].traducao;
                yyval.tipo = yyvsp[-1].tipo;
            }
#line 2227 "y.tab.c"
    break;

  case 37: /* E: E GREATER_THAN E  */
#line 769 "sintatico.y"
            {   
                string tipo = resolve_tipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                auto [coercoes, t1, t2] = resolve_coercao(yyvsp[-2].label, yyvsp[0].label, tipo);
                yyval.label = gentempcode(tipo);
                yyval.tipo = "boolean";
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + coercoes + "\t" + yyval.label + " = " + t1 + " > " + t2 + ";\n";
                if (yyvsp[-2].var_original != "") yyval.var_original = yyvsp[-2].var_original;
                else if (yyvsp[0].var_original != "") yyval.var_original = yyvsp[0].var_original;
            }
#line 2241 "y.tab.c"
    break;

  case 38: /* E: E LESS_THAN E  */
#line 779 "sintatico.y"
    {   
                string tipo = resolve_tipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                yyval.label = gentempcode("boolean");
                yyval.tipo = "boolean";

                string t1 = yyvsp[-2].label;
                string t2 = yyvsp[0].label;
                string coercoes;

                string bloco1 = "", bloco2 = "";

                
                if (yyvsp[-2].tipo == "Var") {
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
                        "\t" + pega_tipo + " = " + yyvsp[-2].label + "->tipo;\n" +
                        "\t" + compara_tipo_int + " = " + pega_tipo + " == 1;\n" +
                        "\tif (" + compara_tipo_int + ") goto tipo_int_" + to_string(label_tipo_int) + ";\n" +
                        "\t" + compara_tipo_float + " = " + pega_tipo + " == 2;\n" +
                        "\tif (" + compara_tipo_float + ") goto tipo_float_" + to_string(label_tipo_float) + ";\n" +
                        "\tgoto tipo_default_" + to_string(label_tipo_default) + ";\n\n" +

                        "tipo_int_" + to_string(label_tipo_int) + ":\n" +
                        "\t" + t_extra1  + " = (float)" +  yyvsp[-2].label + "->i;\n" +
                        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +

                        "tipo_float_" + to_string(label_tipo_float) + ":\n" +
                        "\t" + t_extra1  + " = " +  yyvsp[-2].label + "->f;\n" +
                        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +

                        "tipo_default_" + to_string(label_tipo_default) + ":\n" +
                        "\t" + t_extra1 + " = 0.0;\n" +
                        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +

                        "fim_tipo_" + to_string(fim_tipo) + ":\n";

                    t1 = t_extra1;
                }

                
                if (yyvsp[0].tipo == "Var") {
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
                        "\t" + pega_tipo + " = " + yyvsp[0].label + "->tipo;\n" +
                        "\t" + compara_tipo_int + " = " + pega_tipo + " == 1;\n" +
                        "\tif (" + compara_tipo_int + ") goto tipo_int_" + to_string(label_tipo_int) + ";\n" +
                        "\t" + compara_tipo_float + " = " + pega_tipo + " == 2;\n" +
                        "\tif (" + compara_tipo_float + ") goto tipo_float_" + to_string(label_tipo_float) + ";\n" +
                        "\tgoto tipo_default_" + to_string(label_tipo_default) + ";\n\n" +

                        "tipo_int_" + to_string(label_tipo_int) + ":\n" +
                        "\t" + t_extra2  + " = (float)" +  yyvsp[0].label + "->i;\n" +
                        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +

                        "tipo_float_" + to_string(label_tipo_float) + ":\n" +
                        "\t" + t_extra2  + " = " +  yyvsp[0].label + "->f;\n" +
                        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +

                        "tipo_default_" + to_string(label_tipo_default) + ":\n" +
                        "\t" + t_extra2 + " = 0.0;\n" +
                        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +

                        "fim_tipo_" + to_string(fim_tipo) + ":\n";

                    t2 = t_extra2;
                }

                // Se nenhum for Var, faz coerção normalmente
                if (yyvsp[-2].tipo != "Var" && yyvsp[0].tipo != "Var") {
                    tie(coercoes, t1, t2) = resolve_coercao(yyvsp[-2].label, yyvsp[0].label, tipo);
                }

                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + bloco1 + bloco2 + coercoes;
                yyval.traducao += "\t" + yyval.label + " = " + t1 + " < " + t2 + ";\n";

                if (yyvsp[-2].var_original != "") yyval.var_original = yyvsp[-2].var_original;
                else if (yyvsp[0].var_original != "") yyval.var_original = yyvsp[0].var_original;
            }
#line 2346 "y.tab.c"
    break;

  case 39: /* E: E GREATER_OR_EQUAL E  */
#line 881 "sintatico.y"
            {   
                string tipo = resolve_tipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                auto [coercoes, t1, t2] = resolve_coercao(yyvsp[-2].label, yyvsp[0].label, tipo);
                yyval.label = gentempcode(tipo);
                yyval.tipo = "boolean";
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + coercoes + "\t" + yyval.label + " = " + t1 + " >= " + t2 + ";\n";
                if (yyvsp[-2].var_original != "") yyval.var_original = yyvsp[-2].var_original;
                else if (yyvsp[0].var_original != "") yyval.var_original = yyvsp[0].var_original;
            }
#line 2360 "y.tab.c"
    break;

  case 40: /* E: E LESS_OR_EQUAL E  */
#line 891 "sintatico.y"
            {   
                string tipo = resolve_tipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                auto [coercoes, t1, t2] = resolve_coercao(yyvsp[-2].label, yyvsp[0].label, tipo);
                yyval.label = gentempcode(tipo);
                yyval.tipo = "boolean";
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + coercoes + "\t" + yyval.label + " = " + t1 + " <= " + t2 + ";\n";
                if (yyvsp[-2].var_original != "") yyval.var_original = yyvsp[-2].var_original;
                else if (yyvsp[0].var_original != "") yyval.var_original = yyvsp[0].var_original;
            }
#line 2374 "y.tab.c"
    break;

  case 41: /* E: E EQUAL E  */
#line 901 "sintatico.y"
            {   

                string tipo = resolve_tipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                yyval.label = gentempcode("boolean");
                yyval.tipo = "boolean";

                string t1 = yyvsp[-2].label;
                string t2 = yyvsp[0].label;
                string coercoes;

                string bloco1 = "", bloco2 = "";

                
                if (yyvsp[-2].tipo == "Var") {
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
                        "\t" + pega_tipo + " = " + yyvsp[-2].label + "->tipo;\n" +
                        "\t" + compara_tipo_int + " = " + pega_tipo + " == 1;\n" +
                        "\tif (" + compara_tipo_int + ") goto tipo_int_" + to_string(label_tipo_int) + ";\n" +
                        "\t" + compara_tipo_float + " = " + pega_tipo + " == 2;\n" +
                        "\tif (" + compara_tipo_float + ") goto tipo_float_" + to_string(label_tipo_float) + ";\n" +
                        "\tgoto tipo_default_" + to_string(label_tipo_default) + ";\n\n" +

                        "tipo_int_" + to_string(label_tipo_int) + ":\n" +
                        "\t" + t_extra1  + " = (float)" +  yyvsp[-2].label + "->i;\n" +
                        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +

                        "tipo_float_" + to_string(label_tipo_float) + ":\n" +
                        "\t" + t_extra1  + " = " +  yyvsp[-2].label + "->f;\n" +
                        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +

                        "tipo_default_" + to_string(label_tipo_default) + ":\n" +
                        "\t" + t_extra1 + " = 0.0;\n" +
                        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +

                        "fim_tipo_" + to_string(fim_tipo) + ":\n";

                    t1 = t_extra1;
                }

                
                if (yyvsp[0].tipo == "Var") {
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
                        "\t" + pega_tipo + " = " + yyvsp[0].label + "->tipo;\n" +
                        "\t" + compara_tipo_int + " = " + pega_tipo + " == 1;\n" +
                        "\tif (" + compara_tipo_int + ") goto tipo_int_" + to_string(label_tipo_int) + ";\n" +
                        "\t" + compara_tipo_float + " = " + pega_tipo + " == 2;\n" +
                        "\tif (" + compara_tipo_float + ") goto tipo_float_" + to_string(label_tipo_float) + ";\n" +
                        "\tgoto tipo_default_" + to_string(label_tipo_default) + ";\n\n" +

                        "tipo_int_" + to_string(label_tipo_int) + ":\n" +
                        "\t" + t_extra2  + " = (float)" +  yyvsp[0].label + "->i;\n" +
                        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +

                        "tipo_float_" + to_string(label_tipo_float) + ":\n" +
                        "\t" + t_extra2  + " = " +  yyvsp[0].label + "->f;\n" +
                        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +

                        "tipo_default_" + to_string(label_tipo_default) + ":\n" +
                        "\t" + t_extra2 + " = 0.0;\n" +
                        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +

                        "fim_tipo_" + to_string(fim_tipo) + ":\n";

                    t2 = t_extra2;
                }

                // Se nenhum for Var, faz coerção normalmente
                if (yyvsp[-2].tipo != "Var" && yyvsp[0].tipo != "Var") {
                    tie(coercoes, t1, t2) = resolve_coercao(yyvsp[-2].label, yyvsp[0].label, tipo);
                }

                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + bloco1 + bloco2 + coercoes;
                yyval.traducao += "\t" + yyval.label + " = " + t1 + " == " + t2 + ";\n";

                if (yyvsp[-2].var_original != "") yyval.var_original = yyvsp[-2].var_original;
                else if (yyvsp[0].var_original != "") yyval.var_original = yyvsp[0].var_original;
            }
#line 2480 "y.tab.c"
    break;

  case 42: /* E: E NOT_EQUAL E  */
#line 1003 "sintatico.y"
            {   
                string tipo = resolve_tipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                auto [coercoes, t1, t2] = resolve_coercao(yyvsp[-2].label, yyvsp[0].label, tipo);
                yyval.label = gentempcode(tipo);
                yyval.tipo = "boolean";
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + coercoes + "\t" + yyval.label + " = " + t1 + " != " + t2 + ";\n";
                if (yyvsp[-2].var_original != "") yyval.var_original = yyvsp[-2].var_original;
                else if (yyvsp[0].var_original != "") yyval.var_original = yyvsp[0].var_original;
            }
#line 2494 "y.tab.c"
    break;

  case 43: /* E: NOT E  */
#line 1013 "sintatico.y"
            {   
                if(yyvsp[0].tipo != "boolean") {
                    yyerror("Erro na linha " + to_string(linha) + ": não é possível usar o operador '!' em uma variável não booleana!");
                }
                yyval.label = gentempcode("int");
                yyval.tipo = "boolean";
                yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label + " = " "!" + yyvsp[0].label + ";\n";
            }
#line 2507 "y.tab.c"
    break;

  case 44: /* E: E AND E  */
#line 1022 "sintatico.y"
            {   
                verifica_tipo_logico(yyvsp[-2].tipo, yyvsp[0].tipo);
                yyval.label = gentempcode("int");
                yyval.tipo = "boolean";
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " && " + yyvsp[0].label + ";\n";
            }
#line 2518 "y.tab.c"
    break;

  case 45: /* E: E OR E  */
#line 1029 "sintatico.y"
            {   
                
                verifica_tipo_logico(yyvsp[-2].tipo, yyvsp[0].tipo);
                yyval.label = gentempcode("int");
                yyval.tipo = "boolean";
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " || " + yyvsp[0].label + ";\n";
            }
#line 2530 "y.tab.c"
    break;

  case 46: /* E: TK_ID '=' E  */
#line 1038 "sintatico.y"
            {
                string nome_variavel = "";

                if(!esta_no_while && !esta_no_for && !esta_no_do_while) {
                    
                      nome_variavel = pega_variavel_na_tabela(yyvsp[-2].label, yyvsp[0].tipo);
                        if(nome_variavel == "") {
                            nome_variavel = adiciona_variavel_na_tabela(yyvsp[-2].label, yyvsp[0].tipo, yyvsp[0].label);
                            string formata_variavel_escopo = yyvsp[-2].label + "_global";
                            variavel_escopo[formata_variavel_escopo] = nome_variavel;
                            mudou_tipo[nome_variavel] = false;
                            cout <<"pega variavel interna fora do esta_no while" + nome_variavel << endl;
                    }
                    
                } else {
                    nome_variavel = pega_variavel_na_tabela(yyvsp[-2].label, yyvsp[0].tipo);
                    if(nome_variavel == "") {
                        nome_variavel = adiciona_variavel_na_tabela(yyvsp[-2].label, yyvsp[0].tipo, yyvsp[0].label);
                        mudou_tipo[nome_variavel] = false;
                    } 
                        string formata_variavel_escopo = yyvsp[-2].label + "_local";
                        variavel_escopo[formata_variavel_escopo] = nome_variavel;
                        cout <<"pega variavel interna no do_no while" + nome_variavel << endl;
                }
                
                if(yyvsp[0].tipo == "string") {
                    
                    if(realocar_var_interna.count(nome_variavel)){
                        yyval.traducao += "\tfree(" + nome_variavel + ");\n";
                    yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + nome_variavel + " = (Var *) malloc(sizeof(Var));\n";
                    yyval.traducao += "\t" + nome_variavel + "->tipo = 5;\n"; 
                    yyval.traducao += "\t" + nome_variavel + "->s = (char *) malloc(" + tamanho_string[yyvsp[0].label] + ");\n"; 
                    yyval.traducao += "\tstrcpy(" + nome_variavel + "->s" + "," + yyvsp[0].label + ");\n";
                    mudou_tipo[nome_variavel] = true;
                    edita_tipo_na_tabela(yyvsp[-2].label, "string", yyvsp[0].label);
                    } else {

                        realocar_var_interna[nome_variavel] = true;
                        yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + nome_variavel + " = (Var *) malloc(sizeof(Var));\n";
                        yyval.traducao += "\t" + nome_variavel + "->tipo = 5;\n"; 
                        yyval.traducao += "\t" + nome_variavel + "->s = (char *) malloc(" + tamanho_string[yyvsp[0].label] + ");\n"; 
                        yyval.traducao += "\tstrcpy(" + nome_variavel + "->s" + "," + yyvsp[0].label + ");\n";
                        mudou_tipo[nome_variavel] = true;
                        edita_tipo_na_tabela(yyvsp[-2].label, "string", yyvsp[0].label);
                    }

                                       
                    
                } else {
                    if(esta_no_while || esta_no_for || esta_no_do_while) {
                        if((variavel_escopo.count(yyvsp[-2].label + "_global")) && (variavel_escopo.count(yyvsp[-2].label + "_local"))) {
                            yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + variavel_escopo[yyvsp[-2].label + "_global"] + " = " + yyvsp[0].label + ";\n";
                        }
                    }
                    if (!mudou_tipo[nome_variavel]) {
                        yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao;
                        yyval.traducao += "\t" + nome_variavel + " = (Var *) malloc(sizeof(Var));\n";
                        mudou_tipo[nome_variavel] = true;
                    } else {
                        yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao;
                    }

                    int tipo = yyvsp[0].tipo == "int" ? 1 :
                                yyvsp[0].tipo == "float" ? 2 :
                                yyvsp[0].tipo == "boolean" ? 3 :
                                yyvsp[0].tipo == "char" ? 4 :
                                yyvsp[0].tipo == "string" ? 5 : 0;


                    yyval.traducao += "\t" + nome_variavel + "->tipo = " + to_string(tipo) + ";\n";

                    switch (tipo) {

                    case 0: {

                    
                    int label_tipo_int = label_tipo++;
                    int label_tipo_float = label_tipo++;
                    int label_tipo_boolean = label_tipo++;
                    int label_tipo_char = label_tipo++;
                    int label_tipo_string = label_tipo++;
                    int fim_tipo = label_tipo++;
                    string pega_tipo = gentempcode("boolean");
                    string pega_tipo_int = gentempcode("boolean");
                    string pega_tipo_float = gentempcode("boolean");
                    string pega_tipo_boolean = gentempcode("boolean");
                    string pega_tipo_char = gentempcode("boolean");
                    string pega_tipo_string = gentempcode("boolean");
                
                    cout << yyvsp[0].label <<endl;
                    yyval.traducao += "\t" + pega_tipo + " = " + yyvsp[0].label + "->tipo" + ";\n" +
                    "\t" + pega_tipo_int + " = " + yyvsp[0].label + "->tipo" + " == 1;\n" +
                    "\tif (" + pega_tipo_int + ") goto tipo_int_" + to_string(label_tipo_int) + ";\n" +
                    "\t" + pega_tipo_float + " = " + pega_tipo + " == 2;\n" +
                    "\tif (" + pega_tipo_float + ") goto tipo_float_" + to_string(label_tipo_float) + ";\n" +
                    "\t" + pega_tipo_boolean + " = " + pega_tipo + " == 3;\n" +
                    "\tif (" + pega_tipo_boolean + ") goto tipo_boolean_" + to_string(label_tipo_boolean) + ";\n" +
                    "\t" + pega_tipo_char + " = " + pega_tipo + " == 4;\n" +
                    "\tif (" + pega_tipo_char + ") goto tipo_char_" + to_string(label_tipo_char) + ";\n" +
                    "\t" + pega_tipo_string + " = " + pega_tipo + " == 5;\n" +
                    "\tif (" + pega_tipo_string + ") goto tipo_string_" + to_string(label_tipo_string) + ";\n" +
                    "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +
    
                    "tipo_int_" + to_string(label_tipo_int) + ":\n" +
                    "\t" + nome_variavel + "->tipo = 1;\n" +
                    "\t" + nome_variavel + "->i" + " = " +  yyvsp[0].label + "->i;\n" +
                    "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +
    
                    "tipo_float_" + to_string(label_tipo_float) + ":\n" +
                   "\t" + nome_variavel + "->tipo = 2;\n" +
                    "\t" + nome_variavel + "->f" + " = " +  yyvsp[0].label + "->f;\n" +
                    "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +
    
                    "tipo_boolean_" + to_string(label_tipo_boolean) + ":\n" +
                    "\t" + nome_variavel + "->tipo = 3;\n" +
                    "\t" + nome_variavel + "->b" + " = " +  yyvsp[0].label + "->b;\n" +
                    "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +

                    "tipo_char_" + to_string(label_tipo_char) + ":\n" +
                    "\t" + nome_variavel + "->tipo = 4;\n" +
                    "\t" + nome_variavel + "->c" + " = " +  yyvsp[0].label + "->c;\n" +
                    "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +

                    "tipo_string_" + to_string(label_tipo_string) + ":\n" +
                    "\t" + nome_variavel + "->tipo = 5;\n" +
                    "\t" + nome_variavel + "->s" + " = " +  yyvsp[0].label + "->s;\n" +
                    "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +
    
                    "fim_tipo_" + to_string(fim_tipo) + ":\n";
                    break;
                    }

                        case 1: {

                        
                        if(yyvsp[0].tipo == "Var") {

                            yyval.traducao += "\t" + nome_variavel + "->i = " + yyvsp[0].label + "->i;\n";
                            edita_tipo_na_tabela(yyvsp[-2].label, "int", yyvsp[0].label);
                        
                        } else {
                             yyval.traducao += "\t" + nome_variavel + "->i = " + yyvsp[0].label + ";\n";
                             edita_tipo_na_tabela(yyvsp[-2].label, "int", yyvsp[0].label);
                        }
                        break;
                        }
                        case 2 : {
                             if(yyvsp[0].tipo == "Var") {

                            yyval.traducao += "\t" + nome_variavel + "->f = " + yyvsp[0].label + "->f;\n";
                            edita_tipo_na_tabela(yyvsp[-2].label, "float", yyvsp[0].label);
                        
                        } else {
                             yyval.traducao += "\t" + nome_variavel + "->f = " + yyvsp[0].label + ";\n";
                             edita_tipo_na_tabela(yyvsp[-2].label, "float", yyvsp[0].label);
                        }
                        break;
                        }
                        case 3: {

                        
                           if(yyvsp[0].tipo == "Var") {

                            yyval.traducao += "\t" + nome_variavel + "->b = " + yyvsp[0].label + "->b;\n";
                            edita_tipo_na_tabela(yyvsp[-2].label, "boolean", yyvsp[0].label);
                        
                        } else {
                             yyval.traducao += "\t" + nome_variavel + "->b = " + yyvsp[0].label + ";\n";
                             edita_tipo_na_tabela(yyvsp[-2].label, "boolean", yyvsp[0].label);
                        }
                        break;
                        }
                        case 4: {

                        
                           if(yyvsp[0].tipo == "Var") {

                            yyval.traducao += "\t" + nome_variavel + "->c = " + yyvsp[0].label + "->c;\n";
                            edita_tipo_na_tabela(yyvsp[-2].label, "char", yyvsp[0].label);
                        
                        } else {
                             yyval.traducao += "\t" + nome_variavel + "->c = " + yyvsp[0].label + ";\n";
                             edita_tipo_na_tabela(yyvsp[-2].label, "char", yyvsp[0].label);
                        }
                        break;
                        }
                    }

                }
            }
#line 2725 "y.tab.c"
    break;

  case 47: /* E: TK_NUM  */
#line 1229 "sintatico.y"
            {
                yyval.label = gentempcode("int");
                yyval.tipo = "int";
                yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
            }
#line 2735 "y.tab.c"
    break;

  case 48: /* E: TK_REAL  */
#line 1235 "sintatico.y"
            {
                yyval.label = gentempcode("float");
                yyval.tipo = "float";
                yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
            }
#line 2745 "y.tab.c"
    break;

  case 49: /* E: TK_STRING  */
#line 1240 "sintatico.y"
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
#line 2771 "y.tab.c"
    break;

  case 50: /* E: TK_TRUE  */
#line 1262 "sintatico.y"
            {
                yyval.label = gentempcode("int");
                yyval.tipo = "boolean";
                yyval.traducao = "\t" + yyval.label + " = " + "1" + ";\n";
            }
#line 2781 "y.tab.c"
    break;

  case 51: /* E: TK_FALSE  */
#line 1268 "sintatico.y"
            {
                yyval.label = gentempcode("int");
                yyval.tipo = "boolean";
                yyval.traducao = "\t" + yyval.label + " = " + "0" + ";\n";
            }
#line 2791 "y.tab.c"
    break;

  case 52: /* E: TK_CHAR  */
#line 1274 "sintatico.y"
            {
                yyval.label = gentempcode("char");
                yyval.tipo = "char";
                yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
            }
#line 2801 "y.tab.c"
    break;

  case 53: /* E: TK_ID  */
#line 1280 "sintatico.y"
            {   
                string tipo = getTipo(yyvsp[0].label); 
                yyval.label = gentempcode("Var");
                string nome_interno = pega_variavel_na_tabela(yyvsp[0].label, tipo);
                yyval.var_original = nome_interno;
                yyval.tipo="Var";

                
                    yyval.traducao += "\t" + yyval.label + " = (Var *) malloc(sizeof(Var));\n";
            

            

                if(esta_no_while || esta_no_for) {
                        
                        
                    string pega_tipo          = gentempcode("int");
                    string compara_tipo_int   = gentempcode("bool");
                    string compara_tipo_float = gentempcode("bool");
                    string compara_tipo_bool  = gentempcode("bool");
                    string compara_tipo_char  = gentempcode("bool");   // novo
                    string compara_tipo_str   = gentempcode("bool");   // novo

                    /* rótulos */
                    int label_tipo_int     = label_tipo++;
                    int label_tipo_float   = label_tipo++;
                    int label_tipo_boolean = label_tipo++;
                    int label_tipo_char    = label_tipo++;   // novo
                    int label_tipo_string  = label_tipo++;   // novo
                    int label_tipo_default = label_tipo++;
                    int fim_tipo           = label_tipo++;

                    /* seleção de tipo */
                    yyval.traducao +=
                        "\t" + pega_tipo + " = " + nome_interno + "->tipo;\n"
                        "\t" + compara_tipo_int   + " = " + pega_tipo + " == 1;\n"
                        "\tif (" + compara_tipo_int   + ") goto tipo_int_"   + to_string(label_tipo_int)     + ";\n"
                        "\t" + compara_tipo_float + " = " + pega_tipo + " == 2;\n"
                        "\tif (" + compara_tipo_float + ") goto tipo_float_" + to_string(label_tipo_float)   + ";\n"
                        "\t" + compara_tipo_bool  + " = " + pega_tipo + " == 3;\n"
                        "\tif (" + compara_tipo_bool  + ") goto tipo_bool_"  + to_string(label_tipo_boolean) + ";\n"
                        "\t" + compara_tipo_char  + " = " + pega_tipo + " == 4;\n"            // novo
                        "\tif (" + compara_tipo_char  + ") goto tipo_char_"  + to_string(label_tipo_char)    + ";\n"
                        "\t" + compara_tipo_str   + " = " + pega_tipo + " == 5;\n"            // novo
                        "\tif (" + compara_tipo_str   + ") goto tipo_str_"   + to_string(label_tipo_string)  + ";\n"
                        "\tgoto tipo_default_" + to_string(label_tipo_default) + ";\n\n"

                        /* int */
                        "tipo_int_" + to_string(label_tipo_int) + ":\n"
                        "\t" + yyval.label + "->tipo = " + nome_interno + "->tipo;\n"
                        "\t" + yyval.label + "->i    = " + nome_interno + "->i;\n"
                        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n"

                        /* float */
                        "tipo_float_" + to_string(label_tipo_float) + ":\n"
                        "\t" + yyval.label + "->tipo = " + nome_interno + "->tipo;\n"
                        "\t" + yyval.label + "->f    = " + nome_interno + "->f;\n"
                        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n"

                        /* bool */
                        "tipo_bool_" + to_string(label_tipo_boolean) + ":\n"
                        "\t" + yyval.label + "->tipo = " + nome_interno + "->tipo;\n"
                        "\t" + yyval.label + "->b    = " + nome_interno + "->b;\n"
                        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n"

                        /* char — NOVO */
                        "tipo_char_" + to_string(label_tipo_char) + ":\n"
                        "\t" + yyval.label + "->tipo = 4;\n"
                        "\t" + yyval.label + "->c    = " + nome_interno + "->c;\n"
                        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n"

                        /* string — NOVO */
                        "tipo_str_" + to_string(label_tipo_string) + ":\n"
                        "\t" + yyval.label + "->tipo = 5;\n";
                        yyval.traducao += realizar_contagem(nome_interno, yyval.label);
                        yyval.traducao += 
                        "\t" + yyval.label + "->s = (char *) malloc(" + tamanho_string[yyval.label] + ");\n"
                        "\t" + "strcpy(" + yyval.label + "->s" + " , " + nome_interno + "->s" + ");\n"
                        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n"

                        "tipo_default_" + to_string(label_tipo_default) + ":\n"
                        "\t/* tratamento de tipo inesperado, se necessário */\n"
                        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n"

                        "fim_tipo_" + to_string(fim_tipo) + ":\n";

                      
    
                    } else {
                  

                    if (tipo == "string") {
                        yyval.traducao += realizar_contagem(nome_interno, yyval.label);
                        yyval.traducao += "\t" + yyval.label + "->tipo = 5;\n";
                        yyval.traducao += "\t" + yyval.label + "->s = (char *) malloc(" + tamanho_string[yyval.label] + ");\n";
                        yyval.traducao += "\tstrcpy(" + yyval.label + "->s, " + nome_interno + "->s);\n";

                    } else if (tipo == "char") {
                        yyval.traducao += "\t" + yyval.label + "->tipo = 4;\n";
                        yyval.traducao += "\t" + yyval.label + "->c = " + nome_interno + "->c;\n";

                    } else {
                        int tipo_var = tipo_var_dinamica(tipo);
                        yyval.traducao += "\t" + yyval.label + "->tipo = " + to_string(tipo_var) + ";\n";

                        switch(tipo_var) {
                            case 1:
                                yyval.traducao += "\t" + yyval.label + "->i = " + nome_interno + "->i;\n";
                                break;
                            case 2:
                                yyval.traducao += "\t" + yyval.label + "->f = " + nome_interno + "->f;\n";
                                break;
                            case 3:
                                yyval.traducao += "\t" + yyval.label + "->b = " + nome_interno + "->b;\n";
                                break;
                            case 4:
                                yyval.traducao += "\t" + yyval.label + "->c = " + nome_interno + "->b;\n";
                                break;
                            case 5:
                                yyval.traducao += "\t" + yyval.label + "->s = " + nome_interno + "->b;\n";
                                break;
                        }
                    }
                }

                    
                }
#line 2933 "y.tab.c"
    break;

  case 54: /* E: '(' TK_INT ')' TK_ID  */
#line 1413 "sintatico.y"
            {  
                string tipo_atual = getTipo(yyvsp[0].label);
                string novo_tipo = "int";
                yyval.label = gentempcode(novo_tipo);
                yyval.tipo = novo_tipo;
                string nome_interno = pega_variavel_na_tabela(yyvsp[0].label, tipo_atual);
                yyval.traducao = "\t" + yyval.label + " = " + "(" + novo_tipo + ")" + " " + nome_interno + ";\n";
            }
#line 2946 "y.tab.c"
    break;

  case 55: /* E: '(' TK_FLOAT ')' TK_ID  */
#line 1422 "sintatico.y"
            {  
                string tipo_atual = getTipo(yyvsp[0].label);
                string novo_tipo = "float";
                yyval.label = gentempcode(novo_tipo);
                yyval.tipo = novo_tipo;
                string nome_interno = pega_variavel_na_tabela(yyvsp[0].label, tipo_atual);
                yyval.traducao = "\t" + yyval.label + " = " + "(" + novo_tipo + ")" + " " + nome_interno + ";\n";
            }
#line 2959 "y.tab.c"
    break;

  case 56: /* E: '(' TK_BOOLEAN ')' TK_ID  */
#line 1431 "sintatico.y"
            {  
                yyerror("Erro na linha " + to_string(linha) + ": não é possível transformar a variável em boolean!");
            }
#line 2967 "y.tab.c"
    break;


#line 2971 "y.tab.c"

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

#line 1435 "sintatico.y"


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

     for (auto it = pilha_escopos.rbegin(); it != pilha_escopos.rend(); ++it) {
         for (const auto& par : *it) {
            if (par.second.nome_interno == nome_variavel) {
                return par.second.nome_interno;
            }
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
   string var_string = "";
   string variavel_interna = pega_variavel_na_tabela(palavra, "Var");

    if(variavel_interna != "") {
         var_string = variavel_interna + "->s";
    } else {
         var_string = palavra;
    }

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

string gerar_traducao_soma_var(
    string label_esquerda, string tipo_esquerda, string traducao_esquerda,
    string label_direita, string tipo_direita, string traducao_direita, string var
) {

    if(var == "esquerda") {

    string traducao = traducao_esquerda + traducao_direita;

    string var_direita = gentempcode("Var");
    int tipo_var = tipo_var_dinamica(tipo_direita);

    traducao += "\t" + var_direita + " = (Var *) malloc(sizeof(Var));\n";
    traducao += "\t" + var_direita + "->tipo = " + to_string(tipo_var) + ";\n";

    switch (tipo_var) {
        case 1: traducao += "\t" + var_direita + "->i = " + label_direita + ";\n"; break;
        case 2: traducao += "\t" + var_direita + "->f = " + label_direita + ";\n"; break;
        case 3: traducao += "\t" + var_direita + "->b = " + label_direita + ";\n"; break;
        case 4: traducao += "\t" + var_direita + "->c = " + label_direita + ";\n"; break;
        case 5: traducao += "\t" + var_direita + "->s = " + label_direita + ";\n"; break;
    }

    // Geração de labels
    int label_tipo_int = label_tipo++;
    int label_tipo_float = label_tipo++;
    int label_tipo_default = label_tipo++;
    int fim_tipo = label_tipo++;

    // Comparações INT + INT
    string cmp_int_1 = gentempcode("boolean");
    string cmp_int_2 = gentempcode("boolean");
    string both_int = gentempcode("boolean");
    string temp1_int = gentempcode("int");
    string temp2_int = gentempcode("int");

    traducao += "\t" + cmp_int_1 + " = " + label_esquerda + "->tipo == 1;\n";
    traducao += "\t" + cmp_int_2 + " = " + var_direita + "->tipo == 1;\n";
    traducao += "\t" + both_int + " = 0;\n";
    traducao += "\tif (" + cmp_int_1 + ") if (" + cmp_int_2 + ") " + both_int + " = 1;\n";
    traducao += "\tif (" + both_int + ") goto operacao_int_" + to_string(label_tipo_int) + ";\n";

    // FLOAT + FLOAT
    string cmp_float_1 = gentempcode("boolean");
    string cmp_float_2 = gentempcode("boolean");
    string both_float = gentempcode("boolean");
    string temp1_float = gentempcode("float");
    string temp2_float = gentempcode("float");

    traducao += "\t" + cmp_float_1 + " = " + label_esquerda + "->tipo == 2;\n";
    traducao += "\t" + cmp_float_2 + " = " + var_direita + "->tipo == 2;\n";
    traducao += "\t" + both_float + " = 0;\n";
    traducao += "\tif (" + cmp_float_1 + ") if (" + cmp_float_2 + ") " + both_float + " = 1;\n";
    traducao += "\tif (" + both_float + ") goto operacao_float_float_" + to_string(label_tipo_float) + ";\n";

    // INT + FLOAT
    string cmp_int_float_1 = gentempcode("boolean");
    string cmp_int_float_2 = gentempcode("boolean");
    string int_float = gentempcode("boolean");
    string temp1_int_float = gentempcode("float");
    string temp2_int_float = gentempcode("float");

    traducao += "\t" + cmp_int_float_1 + " = " + label_esquerda + "->tipo == 1;\n";
    traducao += "\t" + cmp_int_float_2 + " = " + var_direita + "->tipo == 2;\n";
    traducao += "\t" + int_float + " = 0;\n";
    traducao += "\tif (" + cmp_int_float_1 + ") if (" + cmp_int_float_2 + ") " + int_float + " = 1;\n";
    traducao += "\tif (" + int_float + ") goto operacao_int_float_" + to_string(label_tipo_float) + ";\n";

    // FLOAT + INT
    string cmp_float_int_1 = gentempcode("boolean");
    string cmp_float_int_2 = gentempcode("boolean");
    string float_int = gentempcode("boolean");
    string temp1_float_int = gentempcode("float");
    string temp2_float_int = gentempcode("float");

    traducao += "\t" + cmp_float_int_1 + " = " + label_esquerda + "->tipo == 2;\n";
    traducao += "\t" + cmp_float_int_2 + " = " + var_direita + "->tipo == 1;\n";
    traducao += "\t" + float_int + " = 0;\n";
    traducao += "\tif (" + cmp_float_int_1 + ") if (" + cmp_float_int_2 + ") " + float_int + " = 1;\n";
    traducao += "\tif (" + float_int + ") goto operacao_float_int_" + to_string(label_tipo_float) + ";\n";

    // DEFAULT
    traducao += "\tgoto tipo_default_" + to_string(label_tipo_default) + ";\n";

    // Labels finais
    traducao += 
        "operacao_int_" + to_string(label_tipo_int) + ":\n" +
        "\t" + label_esquerda + "->tipo = 1;\n" +
        "\t" + temp1_int + " = " + label_esquerda + "->i;\n" +
        "\t" + temp2_int + " = " + var_direita + "->i;\n" +
        "\t" + label_esquerda + "->i = " + temp1_int + " + " + temp2_int + ";\n" +
        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +

        "operacao_float_float_" + to_string(label_tipo_float) + ":\n" +
        "\t" + label_esquerda + "->tipo = 2;\n" +
        "\t" + temp1_float + " = " + label_esquerda + "->f;\n" +
        "\t" + temp2_float + " = " + var_direita + "->f;\n" +
        "\t" + label_esquerda + "->f = " + temp1_float + " + " + temp2_float + ";\n" +
        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +

        "operacao_int_float_" + to_string(label_tipo_float) + ":\n" +
        "\t" + label_esquerda + "->tipo = 2;\n" +
        "\t" + temp1_int_float + " = (float)" + label_esquerda + "->i;\n" +
        "\t" + temp2_int_float + " = " + var_direita + "->f;\n" +
        "\t" + label_esquerda + "->f = " + temp1_int_float + " + " + temp2_int_float + ";\n" +
        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +

        "operacao_float_int_" + to_string(label_tipo_float) + ":\n" +
        "\t" + label_esquerda + "->tipo = 2;\n" +
        "\t" + temp1_float_int + " = " + label_esquerda + "->f;\n" +
        "\t" + temp2_float_int + " = (float)" + var_direita + "->i;\n" +
        "\t" + label_esquerda + "->f = " + temp1_float_int + " + " + temp2_float_int + ";\n" +
        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +

        "tipo_default_" + to_string(label_tipo_default) + ":\n" +
        "\tprintf(\"Erro: Tipos incompatíveis na soma\\n\");\n" +
        "\texit(1);\n\n" +

        "fim_tipo_" + to_string(fim_tipo) + ":\n";

    return traducao;

    } else if(var == "direita") {

        string traducao = traducao_esquerda + traducao_direita;

    string var_esquerda = gentempcode("Var");
    int tipo_var = tipo_var_dinamica(tipo_esquerda);

    traducao += "\t" + var_esquerda + " = (Var *) malloc(sizeof(Var));\n";
    traducao += "\t" + var_esquerda + "->tipo = " + to_string(tipo_var) + ";\n";

    switch (tipo_var) {
        case 1: traducao += "\t" + var_esquerda + "->i = " + label_esquerda + ";\n"; break;
        case 2: traducao += "\t" + var_esquerda + "->f = " + label_esquerda + ";\n"; break;
        case 3: traducao += "\t" + var_esquerda + "->b = " + label_esquerda + ";\n"; break;
        case 4: traducao += "\t" + var_esquerda + "->c = " + label_esquerda + ";\n"; break;
        case 5: traducao += "\t" + var_esquerda + "->s = " + label_esquerda + ";\n"; break;
    }

    // Labels de controle
    int label_tipo_int = label_tipo++;
    int label_tipo_float = label_tipo++;
    int label_tipo_default = label_tipo++;
    int fim_tipo = label_tipo++;

    // INT + INT
    string cmp_int_1 = gentempcode("boolean");
    string cmp_int_2 = gentempcode("boolean");
    string both_int = gentempcode("boolean");
    string temp1_int = gentempcode("int");
    string temp2_int = gentempcode("int");

    traducao += "\t" + cmp_int_1 + " = " + var_esquerda + "->tipo == 1;\n";
    traducao += "\t" + cmp_int_2 + " = " + label_direita + "->tipo == 1;\n";
    traducao += "\t" + both_int + " = 0;\n";
    traducao += "\tif (" + cmp_int_1 + ") if (" + cmp_int_2 + ") " + both_int + " = 1;\n";
    traducao += "\tif (" + both_int + ") goto operacao_int_" + to_string(label_tipo_int) + ";\n";

    // FLOAT + FLOAT
    string cmp_float_1 = gentempcode("boolean");
    string cmp_float_2 = gentempcode("boolean");
    string both_float = gentempcode("boolean");
    string temp1_float = gentempcode("float");
    string temp2_float = gentempcode("float");

    traducao += "\t" + cmp_float_1 + " = " + var_esquerda + "->tipo == 2;\n";
    traducao += "\t" + cmp_float_2 + " = " + label_direita + "->tipo == 2;\n";
    traducao += "\t" + both_float + " = 0;\n";
    traducao += "\tif (" + cmp_float_1 + ") if (" + cmp_float_2 + ") " + both_float + " = 1;\n";
    traducao += "\tif (" + both_float + ") goto operacao_float_float_" + to_string(label_tipo_float) + ";\n";

    // INT + FLOAT
    string cmp_int_float_1 = gentempcode("boolean");
    string cmp_int_float_2 = gentempcode("boolean");
    string int_float = gentempcode("boolean");
    string temp1_int_float = gentempcode("float");
    string temp2_int_float = gentempcode("float");

    traducao += "\t" + cmp_int_float_1 + " = " + var_esquerda + "->tipo == 1;\n";
    traducao += "\t" + cmp_int_float_2 + " = " + label_direita + "->tipo == 2;\n";
    traducao += "\t" + int_float + " = 0;\n";
    traducao += "\tif (" + cmp_int_float_1 + ") if (" + cmp_int_float_2 + ") " + int_float + " = 1;\n";
    traducao += "\tif (" + int_float + ") goto operacao_int_float_" + to_string(label_tipo_float) + ";\n";

    // FLOAT + INT
    string cmp_float_int_1 = gentempcode("boolean");
    string cmp_float_int_2 = gentempcode("boolean");
    string float_int = gentempcode("boolean");
    string temp1_float_int = gentempcode("float");
    string temp2_float_int = gentempcode("float");

    traducao += "\t" + cmp_float_int_1 + " = " + var_esquerda + "->tipo == 2;\n";
    traducao += "\t" + cmp_float_int_2 + " = " + label_direita + "->tipo == 1;\n";
    traducao += "\t" + float_int + " = 0;\n";
    traducao += "\tif (" + cmp_float_int_1 + ") if (" + cmp_float_int_2 + ") " + float_int + " = 1;\n";
    traducao += "\tif (" + float_int + ") goto operacao_float_int_" + to_string(label_tipo_float) + ";\n";

    // DEFAULT
    traducao += "\tgoto tipo_default_" + to_string(label_tipo_default) + ";\n";

    // Labels finais
    traducao +=
        "operacao_int_" + to_string(label_tipo_int) + ":\n" +
        "\t" + label_direita + "->tipo = 1;\n" +
        "\t" + temp1_int + " = " + var_esquerda + "->i;\n" +
        "\t" + temp2_int + " = " + label_direita + "->i;\n" +
        "\t" + label_direita + "->i = " + temp1_int + " + " + temp2_int + ";\n" +
        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +

        "operacao_float_float_" + to_string(label_tipo_float) + ":\n" +
        "\t" + label_direita + "->tipo = 2;\n" +
        "\t" + temp1_float + " = " + var_esquerda + "->f;\n" +
        "\t" + temp2_float + " = " + label_direita + "->f;\n" +
        "\t" + label_direita + "->f = " + temp1_float + " + " + temp2_float + ";\n" +
        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +

        "operacao_int_float_" + to_string(label_tipo_float) + ":\n" +
        "\t" + label_direita + "->tipo = 2;\n" +
        "\t" + temp1_int_float + " = (float)" + var_esquerda + "->i;\n" +
        "\t" + temp2_int_float + " = " + label_direita + "->f;\n" +
        "\t" + label_direita + "->f = " + temp1_int_float + " + " + temp2_int_float + ";\n" +
        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +

        "operacao_float_int_" + to_string(label_tipo_float) + ":\n" +
        "\t" + label_direita + "->tipo = 2;\n" +
        "\t" + temp1_float_int + " = " + var_esquerda + "->f;\n" +
        "\t" + temp2_float_int + " = (float)" + label_direita + "->i;\n" +
        "\t" + label_direita + "->f = " + temp1_float_int + " + " + temp2_float_int + ";\n" +
        "\tgoto fim_tipo_" + to_string(fim_tipo) + ";\n\n" +

        "tipo_default_" + to_string(label_tipo_default) + ":\n" +
        "\tprintf(\"Erro: Tipos incompatíveis na soma\\n\");\n" +
        "\texit(1);\n\n" +

        "fim_tipo_" + to_string(fim_tipo) + ":\n";

    return traducao;

    } else if(var == "ambos") {

    string traducao = traducao_esquerda + traducao_direita;

    // Labels para controle de fluxo
    int label_int = label_tipo++;
    int label_float = label_tipo++;
    int label_int_float = label_tipo++;
    int label_float_int = label_tipo++;
    int label_string_string = label_tipo++;
    int label_char_string = label_tipo++;
    int label_string_char = label_tipo++;
    int label_default = label_tipo++;
    int label_fim = label_tipo++;

    // Comparações dos tipos esquerda e direita
    string cmp_esq_int = gentempcode("boolean");
    string cmp_dir_int = gentempcode("boolean");
    string cmp_esq_float = gentempcode("boolean");
    string cmp_dir_float = gentempcode("boolean");
    string cmp_esq_string = gentempcode("boolean");
    string cmp_dir_string = gentempcode("boolean");
    string cmp_esq_char = gentempcode("boolean");
    string cmp_dir_char = gentempcode("boolean");

    // Temporários para cálculo
    string temp1_int = gentempcode("int");
    string temp2_int = gentempcode("int");

    string temp1_float = gentempcode("float");
    string temp2_float = gentempcode("float");

    string temp1_int_float = gentempcode("float");
    string temp2_int_float = gentempcode("float");

    string temp1_float_int = gentempcode("float");
    string temp2_float_int = gentempcode("float");

    string temp_result = gentempcode("string");   // para resultado string concatenado
    string temp_size = gentempcode("int");        // para tamanho da string
    string temp_char_str = gentempcode("string"); // para char convertido em string

    // Checa tipos para INT + INT
    traducao += "\t" + cmp_esq_int + " = " + label_esquerda + "->tipo == 1;\n";
    traducao += "\t" + cmp_dir_int + " = " + label_direita + "->tipo == 1;\n";
    traducao += "\tif (" + cmp_esq_int + ") if (" + cmp_dir_int + ") goto op_int_" + to_string(label_int) + ";\n";

    // FLOAT + FLOAT
    traducao += "\t" + cmp_esq_float + " = " + label_esquerda + "->tipo == 2;\n";
    traducao += "\t" + cmp_dir_float + " = " + label_direita + "->tipo == 2;\n";
    traducao += "\tif (" + cmp_esq_float + ") if (" + cmp_dir_float + ") goto op_float_float_" + to_string(label_float) + ";\n";

    // INT + FLOAT
    traducao += "\tif (" + cmp_esq_int + ") if (" + cmp_dir_float + ") goto op_int_float_" + to_string(label_int_float) + ";\n";

    // FLOAT + INT
    traducao += "\tif (" + cmp_esq_float + ") if (" + cmp_dir_int + ") goto op_float_int_" + to_string(label_float_int) + ";\n";

    // STRING + STRING
    traducao += "\t" + cmp_esq_string + " = " + label_esquerda + "->tipo == 5;\n";
    traducao += "\t" + cmp_dir_string + " = " + label_direita + "->tipo == 5;\n";
    traducao += "\tif (" + cmp_esq_string + ") if (" + cmp_dir_string + ") goto op_string_string_" + to_string(label_string_string) + ";\n";

    // CHAR + STRING
    traducao += "\t" + cmp_esq_char + " = " + label_esquerda + "->tipo == 4;\n";
    traducao += "\tif (" + cmp_esq_char + ") if (" + cmp_dir_string + ") goto op_char_string_" + to_string(label_char_string) + ";\n";

    // STRING + CHAR
    traducao += "\t" + cmp_dir_char + " = " + label_direita + "->tipo == 4;\n";
    traducao += "\tif (" + cmp_esq_string + ") if (" + cmp_dir_char + ") goto op_string_char_" + to_string(label_string_char) + ";\n";

    // Caso default (tipos incompatíveis)
    traducao += "\tgoto tipo_default_" + to_string(label_default) + ";\n\n";

    // OPERAÇÕES

    // INT + INT
    traducao += "op_int_" + to_string(label_int) + ":\n";
    traducao += "\t" + label_esquerda + "->tipo = 1;\n";
    traducao += "\t" + temp1_int + " = " + label_esquerda + "->i;\n";
    traducao += "\t" + temp2_int + " = " + label_direita + "->i;\n";
    traducao += "\t" + label_esquerda + "->i = " + temp1_int + " + " + temp2_int + ";\n";
    traducao += "\tgoto fim_" + to_string(label_fim) + ";\n\n";

    // FLOAT + FLOAT
    traducao += "op_float_float_" + to_string(label_float) + ":\n";
    traducao += "\t" + label_esquerda + "->tipo = 2;\n";
    traducao += "\t" + temp1_float + " = " + label_esquerda + "->f;\n";
    traducao += "\t" + temp2_float + " = " + label_direita + "->f;\n";
    traducao += "\t" + label_esquerda + "->f = " + temp1_float + " + " + temp2_float + ";\n";
    traducao += "\tgoto fim_" + to_string(label_fim) + ";\n\n";

    // INT + FLOAT
    traducao += "op_int_float_" + to_string(label_int_float) + ":\n";
    traducao += "\t" + label_esquerda + "->tipo = 2;\n";
    traducao += "\t" + temp1_int_float + " = (float)" + label_esquerda + "->i;\n";
    traducao += "\t" + temp2_int_float + " = " + label_direita + "->f;\n";
    traducao += "\t" + label_esquerda + "->f = " + temp1_int_float + " + " + temp2_int_float + ";\n";
    traducao += "\tgoto fim_" + to_string(label_fim) + ";\n\n";

    // FLOAT + INT
    traducao += "op_float_int_" + to_string(label_float_int) + ":\n";
    traducao += "\t" + label_esquerda + "->tipo = 2;\n";
    traducao += "\t" + temp1_float_int + " = " + label_esquerda + "->f;\n";
    traducao += "\t" + temp2_float_int + " = (float)" + label_direita + "->i;\n";
    traducao += "\t" + label_esquerda + "->f = " + temp1_float_int + " + " + temp2_float_int + ";\n";
    traducao += "\tgoto fim_" + to_string(label_fim) + ";\n\n";

    // STRING + STRING
    traducao += "op_string_string_" + to_string(label_string_string) + ":\n";
    traducao += "\t" + temp_size + " = strlen(" + label_esquerda + "->s) + strlen(" + label_direita + "->s) + 1;\n";
    traducao += "\t" + temp_result + " = (char *) malloc(" + temp_size + ");\n";
    traducao += "\tstrcpy(" + temp_result + ", " + label_esquerda + "->s);\n";
    traducao += "\tstrcat(" + temp_result + ", " + label_direita + "->s);\n";
    traducao += "\tfree(" + label_esquerda + "->s" + ");\n";
    traducao += "\t" + label_esquerda + "->s" + " = (char *) malloc(" + temp_size + ");\n";
    traducao += "\t" + label_esquerda + "->tipo = 5;\n";
    traducao += "\t" + label_esquerda + "->s = " + temp_result + ";\n";
    traducao += "\tgoto fim_" + to_string(label_fim) + ";\n\n";

    // CHAR + STRING
    traducao += "op_char_string_" + to_string(label_char_string) + ":\n";
    traducao += "\t" + temp_char_str + " = (char *) malloc(2);\n";
    traducao += "\t" + temp_char_str + "[0] = " + label_esquerda + "->c;\n";
    traducao += "\t" + temp_char_str + "[1] = '\\0';\n";
    traducao += "\t" + temp_size + " = strlen(" + temp_char_str + ") + strlen(" + label_direita + "->s) + 1;\n";
    traducao += "\t" + temp_result + " = (char *) malloc(" + temp_size + ");\n";
    traducao += "\tstrcpy(" + temp_result + ", " + temp_char_str + ");\n";
    traducao += "\tstrcat(" + temp_result + ", " + label_direita + "->s);\n";
    traducao += "\t" + label_esquerda + "->tipo = 5;\n";
    traducao += "\t" + label_esquerda + "->s = " + temp_result + ";\n";
    traducao += "\tgoto fim_" + to_string(label_fim) + ";\n\n";

    // STRING + CHAR
    traducao += "op_string_char_" + to_string(label_string_char) + ":\n";
    traducao += "\t" + temp_char_str + " = (char *) malloc(2);\n";
    traducao += "\t" + temp_char_str + "[0] = " + label_direita + "->c;\n";
    traducao += "\t" + temp_char_str + "[1] = '\\0';\n";
    traducao += "\t" + temp_size + " = strlen(" + label_esquerda + "->s) + strlen(" + temp_char_str + ") + 1;\n";
    traducao += "\t" + temp_result + " = (char *) malloc(" + temp_size + ");\n";
    traducao += "\tstrcpy(" + temp_result + ", " + label_esquerda + "->s);\n";
    traducao += "\tstrcat(" + temp_result + ", " + temp_char_str + ");\n";
    traducao += "\t" + label_esquerda + "->tipo = 5;\n";
    traducao += "\t" + label_esquerda + "->s = " + temp_result + ";\n";
    traducao += "\tgoto fim_" + to_string(label_fim) + ";\n\n";

    // Tipo incompatível
    traducao += "tipo_default_" + to_string(label_default) + ":\n";
    traducao += "\tprintf(\"Erro: tipos incompatíveis na operação\\n\");\n";
    traducao += "\texit(1);\n\n";

    // Fim da operação
    traducao += "fim_" + to_string(label_fim) + ":\n";

    return traducao;
}


    return "";
}
