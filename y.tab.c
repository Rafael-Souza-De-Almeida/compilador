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
#include<vector>
#include <fstream>


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

vector<map<string, Simbolo>> pilha_escopos;
map<string, string> temporarias;

vector<Simbolo> simbolos_declarados;
int var_user_qnt;

int yylex(void);
void yyerror(string);
void entra_escopo();
void sai_escopo();
void verifica_tipo_relacional(string tipo1, string tipo2);
string gentempcode(string);
string adiciona_variavel_na_tabela(string, string, string);
string pega_variavel_na_tabela(string);
string resolve_tipo(string, string);
string fim_if();
string fim_else();
void ver_boolean(string ,string);
void verifica_tipo(string, string, string);
tuple<string, string, string> resolve_coercao(string, string, string);
string getTipo(string);
string getTempId(string);

#line 127 "y.tab.c"

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
    TK_CHAR = 267,                 /* TK_CHAR  */
    TK_BOOLEAN = 268,              /* TK_BOOLEAN  */
    TK_FIM = 269,                  /* TK_FIM  */
    TK_ERROR = 270,                /* TK_ERROR  */
    TK_MAIOR = 271,                /* TK_MAIOR  */
    TK_MAIORIGUAL = 272,           /* TK_MAIORIGUAL  */
    TK_MENOR = 273,                /* TK_MENOR  */
    TK_MENORIGUAL = 274,           /* TK_MENORIGUAL  */
    TK_IGUALDADE = 275,            /* TK_IGUALDADE  */
    TK_DIFERENTE = 276,            /* TK_DIFERENTE  */
    TK_E = 277,                    /* TK_E  */
    TK_OU = 278,                   /* TK_OU  */
    TK_NEGATIVO = 279,             /* TK_NEGATIVO  */
    TK_PRINT = 280,                /* TK_PRINT  */
    TK_PRINTLN = 281,              /* TK_PRINTLN  */
    TK_IF = 282,                   /* TK_IF  */
    TK_ELSE = 283,                 /* TK_ELSE  */
    TK_FOR = 284,                  /* TK_FOR  */
    TK_WHILE = 285,                /* TK_WHILE  */
    TK_DO = 286,                   /* TK_DO  */
    TK_SWITCH = 287,               /* TK_SWITCH  */
    TK_CONTINUE = 288,             /* TK_CONTINUE  */
    TK_BREAK = 289                 /* TK_BREAK  */
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
#define TK_CHAR 267
#define TK_BOOLEAN 268
#define TK_FIM 269
#define TK_ERROR 270
#define TK_MAIOR 271
#define TK_MAIORIGUAL 272
#define TK_MENOR 273
#define TK_MENORIGUAL 274
#define TK_IGUALDADE 275
#define TK_DIFERENTE 276
#define TK_E 277
#define TK_OU 278
#define TK_NEGATIVO 279
#define TK_PRINT 280
#define TK_PRINTLN 281
#define TK_IF 282
#define TK_ELSE 283
#define TK_FOR 284
#define TK_WHILE 285
#define TK_DO 286
#define TK_SWITCH 287
#define TK_CONTINUE 288
#define TK_BREAK 289

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
  YYSYMBOL_TK_CHAR = 12,                   /* TK_CHAR  */
  YYSYMBOL_TK_BOOLEAN = 13,                /* TK_BOOLEAN  */
  YYSYMBOL_TK_FIM = 14,                    /* TK_FIM  */
  YYSYMBOL_TK_ERROR = 15,                  /* TK_ERROR  */
  YYSYMBOL_TK_MAIOR = 16,                  /* TK_MAIOR  */
  YYSYMBOL_TK_MAIORIGUAL = 17,             /* TK_MAIORIGUAL  */
  YYSYMBOL_TK_MENOR = 18,                  /* TK_MENOR  */
  YYSYMBOL_TK_MENORIGUAL = 19,             /* TK_MENORIGUAL  */
  YYSYMBOL_TK_IGUALDADE = 20,              /* TK_IGUALDADE  */
  YYSYMBOL_TK_DIFERENTE = 21,              /* TK_DIFERENTE  */
  YYSYMBOL_TK_E = 22,                      /* TK_E  */
  YYSYMBOL_TK_OU = 23,                     /* TK_OU  */
  YYSYMBOL_TK_NEGATIVO = 24,               /* TK_NEGATIVO  */
  YYSYMBOL_TK_PRINT = 25,                  /* TK_PRINT  */
  YYSYMBOL_TK_PRINTLN = 26,                /* TK_PRINTLN  */
  YYSYMBOL_TK_IF = 27,                     /* TK_IF  */
  YYSYMBOL_TK_ELSE = 28,                   /* TK_ELSE  */
  YYSYMBOL_TK_FOR = 29,                    /* TK_FOR  */
  YYSYMBOL_TK_WHILE = 30,                  /* TK_WHILE  */
  YYSYMBOL_TK_DO = 31,                     /* TK_DO  */
  YYSYMBOL_TK_SWITCH = 32,                 /* TK_SWITCH  */
  YYSYMBOL_TK_CONTINUE = 33,               /* TK_CONTINUE  */
  YYSYMBOL_TK_BREAK = 34,                  /* TK_BREAK  */
  YYSYMBOL_35_ = 35,                       /* '+'  */
  YYSYMBOL_36_ = 36,                       /* '-'  */
  YYSYMBOL_37_ = 37,                       /* '*'  */
  YYSYMBOL_38_ = 38,                       /* '/'  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_41_ = 41,                       /* '{'  */
  YYSYMBOL_42_ = 42,                       /* '}'  */
  YYSYMBOL_43_ = 43,                       /* ';'  */
  YYSYMBOL_44_ = 44,                       /* '='  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_S = 46,                         /* S  */
  YYSYMBOL_BLOCO = 47,                     /* BLOCO  */
  YYSYMBOL_48_1 = 48,                      /* $@1  */
  YYSYMBOL_COMANDOS = 49,                  /* COMANDOS  */
  YYSYMBOL_COMANDO = 50,                   /* COMANDO  */
  YYSYMBOL_E = 51                          /* E  */
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
typedef yytype_int8 yy_state_t;

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
#define YYLAST   243

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  7
/* YYNRULES -- Number of rules.  */
#define YYNRULES  44
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  95

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


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
      39,    40,    37,    35,     2,    36,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
       2,    44,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    77,    77,   126,   126,   132,   137,   141,   145,   148,
     155,   158,   174,   194,   202,   211,   220,   229,   236,   246,
     256,   266,   276,   286,   296,   307,   318,   330,   337,   344,
     350,   356,   362,   368,   374,   380,   386,   394,   401,   406,
     412,   418,   424,   433,   442
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
  "TK_FLOAT", "TK_CHAR", "TK_BOOLEAN", "TK_FIM", "TK_ERROR", "TK_MAIOR",
  "TK_MAIORIGUAL", "TK_MENOR", "TK_MENORIGUAL", "TK_IGUALDADE",
  "TK_DIFERENTE", "TK_E", "TK_OU", "TK_NEGATIVO", "TK_PRINT", "TK_PRINTLN",
  "TK_IF", "TK_ELSE", "TK_FOR", "TK_WHILE", "TK_DO", "TK_SWITCH",
  "TK_CONTINUE", "TK_BREAK", "'+'", "'-'", "'*'", "'/'", "'('", "')'",
  "'{'", "'}'", "';'", "'='", "$accept", "S", "BLOCO", "$@1", "COMANDOS",
  "COMANDO", "E", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-34)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -7,    -4,     4,   -32,   -34,   -31,   -33,   -34,   -34,    40,
     -34,   -34,   -34,   -34,   -30,     3,     5,    11,    12,    65,
     -27,   -16,   -15,    87,   -34,   -21,    40,    96,    65,    19,
      28,    30,    38,    89,    65,    65,    65,    -2,     7,    14,
     124,   -34,   -34,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,   -34,   190,    65,    65,    65,
      65,   132,   157,   165,    29,    41,    75,   -34,   190,   190,
     190,   190,   190,   190,    89,   221,   198,   198,    39,    39,
     190,   190,   190,   190,    42,    43,   -33,   -34,   -34,   -34,
     -34,   -34,    56,   -33,   -34
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     3,     2,     6,
      32,    33,    34,    35,    36,     0,     0,    37,     0,     0,
       0,     0,     0,     0,    10,     0,     6,     0,     0,    38,
      39,    40,    41,    26,     0,     0,     0,     0,     0,     0,
       0,     4,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,    27,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    17,    18,    19,
      20,    21,    22,    23,    25,    24,    13,    14,    15,    16,
      28,    29,    30,    31,     0,     0,     0,    42,    43,    44,
       8,     9,    11,     0,    12
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -34,   -34,    -6,   -34,    62,   -34,   -18
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    24,     9,    25,    26,    27
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       8,    33,     1,     3,     4,    40,    29,     5,     7,     6,
      56,    29,    34,    30,    28,    30,    61,    62,    63,    31,
      32,    41,    32,    35,    36,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    87,    64,    80,
      81,    82,    83,    10,    11,    12,    13,    65,    14,    88,
      15,    16,    17,    18,    66,    43,    44,    45,    46,    47,
      48,    49,    50,    57,    19,    20,    21,    22,    10,    11,
      12,    13,    58,    14,    59,    15,    16,    17,    18,    23,
      92,     7,    60,    89,    93,    90,    91,    94,    42,    19,
      10,    11,    12,    13,     0,    14,     0,    37,    38,    17,
      39,     0,     0,     0,    23,    43,    44,    45,    46,    47,
      48,    19,    43,    44,    45,    46,    47,    48,    49,    50,
       0,     0,     0,     0,     0,     0,    23,     0,     0,     0,
       0,    51,    52,    53,    54,     0,     0,     0,     0,    55,
      43,    44,    45,    46,    47,    48,    49,    50,    43,    44,
      45,    46,    47,    48,    49,    50,     0,     0,     0,    51,
      52,    53,    54,     0,    67,     0,     0,    51,    52,    53,
      54,     0,    84,    43,    44,    45,    46,    47,    48,    49,
      50,    43,    44,    45,    46,    47,    48,    49,    50,     0,
       0,     0,    51,    52,    53,    54,     0,    85,     0,     0,
      51,    52,    53,    54,     0,    86,    43,    44,    45,    46,
      47,    48,    49,    50,    43,    44,    45,    46,    47,    48,
      49,    50,     0,     0,     0,    51,    52,    53,    54,     0,
       0,     0,     0,     0,     0,    53,    54,    43,    44,    45,
      46,    47,    48,    49
};

static const yytype_int8 yycheck[] =
{
       6,    19,     9,     7,     0,    23,     8,    39,    41,    40,
      28,     8,    39,     8,    44,     8,    34,    35,    36,     8,
       8,    42,     8,    39,    39,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,     8,    40,    57,
      58,    59,    60,     3,     4,     5,     6,    40,     8,     8,
      10,    11,    12,    13,    40,    16,    17,    18,    19,    20,
      21,    22,    23,    44,    24,    25,    26,    27,     3,     4,
       5,     6,    44,     8,    44,    10,    11,    12,    13,    39,
      86,    41,    44,     8,    28,    43,    43,    93,    26,    24,
       3,     4,     5,     6,    -1,     8,    -1,    10,    11,    12,
      13,    -1,    -1,    -1,    39,    16,    17,    18,    19,    20,
      21,    24,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    43,
      16,    17,    18,    19,    20,    21,    22,    23,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    35,
      36,    37,    38,    -1,    40,    -1,    -1,    35,    36,    37,
      38,    -1,    40,    16,    17,    18,    19,    20,    21,    22,
      23,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    35,    36,    37,    38,    -1,    40,    -1,    -1,
      35,    36,    37,    38,    -1,    40,    16,    17,    18,    19,
      20,    21,    22,    23,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,    16,    17,    18,
      19,    20,    21,    22
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    46,     7,     0,    39,    40,    41,    47,    48,
       3,     4,     5,     6,     8,    10,    11,    12,    13,    24,
      25,    26,    27,    39,    47,    49,    50,    51,    44,     8,
       8,     8,     8,    51,    39,    39,    39,    10,    11,    13,
      51,    42,    49,    16,    17,    18,    19,    20,    21,    22,
      23,    35,    36,    37,    38,    43,    51,    44,    44,    44,
      44,    51,    51,    51,    40,    40,    40,    40,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    40,    40,    40,     8,     8,     8,
      43,    43,    47,    28,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    48,    47,    49,    49,    50,    50,    50,
      50,    50,    50,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     0,     4,     2,     0,     2,     5,     5,
       1,     5,     7,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     4,     4,
       4,     4,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     4,     4,     4
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
#line 78 "sintatico.y"
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


               for (auto& simbolo : simbolos_declarados) {
                if (simbolo.tipo == "boolean") {
                    codigo += "\tint " + simbolo.nome_interno + ";\n";
                } else {
                    codigo += "\t" + simbolo.tipo + " " + simbolo.nome_interno + ";\n";
                }
            }

                codigo += yyvsp[0].traducao;
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
#line 1401 "y.tab.c"
    break;

  case 3: /* $@1: %empty  */
#line 126 "sintatico.y"
                  {entra_escopo();}
#line 1407 "y.tab.c"
    break;

  case 4: /* BLOCO: '{' $@1 COMANDOS '}'  */
#line 126 "sintatico.y"
                                                { sai_escopo();
            
                yyval.traducao = yyvsp[-1].traducao;
            }
#line 1416 "y.tab.c"
    break;

  case 5: /* COMANDOS: COMANDO COMANDOS  */
#line 133 "sintatico.y"
            {
                yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
            }
#line 1424 "y.tab.c"
    break;

  case 6: /* COMANDOS: %empty  */
#line 137 "sintatico.y"
            {
                yyval.traducao = "";
            }
#line 1432 "y.tab.c"
    break;

  case 7: /* COMANDO: E ';'  */
#line 142 "sintatico.y"
            {
                yyval = yyvsp[-1];
            }
#line 1440 "y.tab.c"
    break;

  case 8: /* COMANDO: TK_PRINT '(' E ')' ';'  */
#line 145 "sintatico.y"
                                     {
                yyval.traducao = yyvsp[-4].traducao + yyvsp[-2].traducao +  "\t cout << "  + yyvsp[-2].label + ";\n";
            }
#line 1448 "y.tab.c"
    break;

  case 9: /* COMANDO: TK_PRINTLN '(' E ')' ';'  */
#line 148 "sintatico.y"
                                       {
                yyval.traducao = yyvsp[-4].traducao + yyvsp[-2].traducao +  "\t cout << "  + yyvsp[-2].label + " << endl;\n";
            }
#line 1456 "y.tab.c"
    break;

  case 10: /* COMANDO: BLOCO  */
#line 155 "sintatico.y"
                    {
                yyval.traducao = yyvsp[0].traducao;
            }
#line 1464 "y.tab.c"
    break;

  case 11: /* COMANDO: TK_IF '(' E ')' BLOCO  */
#line 158 "sintatico.y"
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
#line 1485 "y.tab.c"
    break;

  case 12: /* COMANDO: TK_IF '(' E ')' BLOCO TK_ELSE BLOCO  */
#line 174 "sintatico.y"
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
#line 1509 "y.tab.c"
    break;

  case 13: /* E: E '+' E  */
#line 195 "sintatico.y"
            {
                string tipo = resolve_tipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                auto [coercoes, t1, t2] = resolve_coercao(yyvsp[-2].label, yyvsp[0].label, tipo);
                yyval.label = gentempcode(tipo);
                yyval.tipo = tipo;
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + coercoes + "\t" + yyval.label + " = " + t1 + " + " + t2 + ";\n";
            }
#line 1521 "y.tab.c"
    break;

  case 14: /* E: E '-' E  */
#line 203 "sintatico.y"
            {   
                /* cout<<"Operation subtraction"<<endl; */
                string tipo = resolve_tipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                auto [coercoes, t1, t2] = resolve_coercao(yyvsp[-2].label, yyvsp[0].label, tipo);
                yyval.label = gentempcode(tipo);
                yyval.tipo = tipo;
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + coercoes + "\t" + yyval.label + " = " + t1 + " - " + t2 + ";\n";
            }
#line 1534 "y.tab.c"
    break;

  case 15: /* E: E '*' E  */
#line 212 "sintatico.y"
            {   
               /*  cout <<"Operation multiplication"<<endl; */
                string tipo = resolve_tipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                auto [coercoes, t1, t2] = resolve_coercao(yyvsp[-2].label, yyvsp[0].label, tipo);
                yyval.label = gentempcode(tipo);
                yyval.tipo = tipo;
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + coercoes + "\t" + yyval.label + " = " + t1 + " * " + t2 + ";\n";
            }
#line 1547 "y.tab.c"
    break;

  case 16: /* E: E '/' E  */
#line 221 "sintatico.y"
            {   
              /*   cout <<"Operation division"<<endl; */
                string tipo = resolve_tipo(yyvsp[-2].tipo, yyvsp[0].tipo);
                auto [coercoes, t1, t2] = resolve_coercao(yyvsp[-2].label, yyvsp[0].label, tipo);
                yyval.label = gentempcode(tipo);
                yyval.tipo = tipo;
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + coercoes + "\t" + yyval.label + " = " + t1 + " / " + t2 + ";\n";
            }
#line 1560 "y.tab.c"
    break;

  case 17: /* E: '(' E ')'  */
#line 230 "sintatico.y"
            {
                /* cout <<"Operation parenteses"<<endl; */
                yyval.label = yyvsp[-1].label;
                yyval.tipo = yyvsp[-1].tipo;
                yyval.traducao = yyvsp[-1].traducao;
            }
#line 1571 "y.tab.c"
    break;

  case 18: /* E: E TK_MAIOR E  */
#line 237 "sintatico.y"
            {
                verifica_tipo_relacional(yyvsp[-2].tipo, yyvsp[0].tipo);
                string tipo = resolve_tipo(yyvsp[-2].tipo,yyvsp[0].tipo);
                auto [coercoes, t1, t2] = resolve_coercao(yyvsp[-2].label, yyvsp[0].label, tipo);
                yyval.label=gentempcode(tipo);
                yyval.tipo = "boolean";
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + coercoes + "\t" + yyval.label + "= " + yyvsp[-2].label + ">" +  yyvsp[0].label + ";\n";  

            }
#line 1585 "y.tab.c"
    break;

  case 19: /* E: E TK_MAIORIGUAL E  */
#line 247 "sintatico.y"
            {
                verifica_tipo_relacional(yyvsp[-2].tipo, yyvsp[0].tipo);
                string tipo = resolve_tipo(yyvsp[-2].tipo,yyvsp[0].tipo);
                auto [coercoes, t1, t2] = resolve_coercao(yyvsp[-2].label, yyvsp[0].label, tipo);
                yyval.label=gentempcode(tipo);
                yyval.tipo = "boolean";
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + coercoes + "\t" + yyval.label + "= " + yyvsp[-2].label + ">=" +  yyvsp[0].label + ";\n";  

            }
#line 1599 "y.tab.c"
    break;

  case 20: /* E: E TK_MENOR E  */
#line 257 "sintatico.y"
            {
                verifica_tipo_relacional(yyvsp[-2].tipo, yyvsp[0].tipo);
                string tipo = resolve_tipo(yyvsp[-2].tipo,yyvsp[0].tipo);
                auto [coercoes, t1, t2] = resolve_coercao(yyvsp[-2].label, yyvsp[0].label, tipo); 
                yyval.label=gentempcode(tipo);
                yyval.tipo = "boolean";
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + coercoes + "\t" + yyval.label + "= " + yyvsp[-2].label + "<" +  yyvsp[0].label + ";\n";  

            }
#line 1613 "y.tab.c"
    break;

  case 21: /* E: E TK_MENORIGUAL E  */
#line 267 "sintatico.y"
            {
                  verifica_tipo_relacional(yyvsp[-2].tipo, yyvsp[0].tipo);
                string tipo = resolve_tipo(yyvsp[-2].tipo,yyvsp[0].tipo);
                 auto [coercoes, t1, t2] = resolve_coercao(yyvsp[-2].label, yyvsp[0].label, tipo);
                yyval.label=gentempcode(tipo);
                yyval.tipo = "boolean";
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + coercoes + "\t" + yyval.label + "= " + yyvsp[-2].label + "<=" +  yyvsp[0].label + ";\n";  

            }
#line 1627 "y.tab.c"
    break;

  case 22: /* E: E TK_IGUALDADE E  */
#line 277 "sintatico.y"
            {
                ver_boolean(yyvsp[-2].tipo,yyvsp[0].tipo);
                string tipo = resolve_tipo(yyvsp[-2].tipo,yyvsp[0].tipo);
                auto [coercoes, t1, t2] = resolve_coercao(yyvsp[-2].label, yyvsp[0].label, tipo);
                yyval.label=gentempcode(tipo);
                yyval.tipo = "boolean";
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + coercoes + "\t" + yyval.label + "= " + yyvsp[-2].label + "==" +  yyvsp[0].label + ";\n";  

            }
#line 1641 "y.tab.c"
    break;

  case 23: /* E: E TK_DIFERENTE E  */
#line 287 "sintatico.y"
            {
                ver_boolean(yyvsp[-2].tipo,yyvsp[0].tipo);
                string tipo = resolve_tipo(yyvsp[-2].tipo,yyvsp[0].tipo);
                auto [coercoes, t1, t2] = resolve_coercao(yyvsp[-2].label, yyvsp[0].label, tipo);
                yyval.label=gentempcode(tipo);
                yyval.tipo = "boolean";
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + coercoes + "\t" + yyval.label + "= " + yyvsp[-2].label + "!=" +  yyvsp[0].label + ";\n";  

            }
#line 1655 "y.tab.c"
    break;

  case 24: /* E: E TK_OU E  */
#line 297 "sintatico.y"
            {
                verifica_tipo(yyvsp[-2].tipo,"boolean","Operando esquerdo deve ser do tipo boolean");
                verifica_tipo(yyvsp[0].tipo,"boolean","Operando direita deve ser boolean");

                string tipo = "boolean";
                yyval.label=gentempcode(tipo);
                yyval.tipo = tipo;
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + "= " + yyvsp[-2].label + "||" +  yyvsp[0].label + ";\n";  

            }
#line 1670 "y.tab.c"
    break;

  case 25: /* E: E TK_E E  */
#line 308 "sintatico.y"
            {
                verifica_tipo(yyvsp[-2].tipo,"boolean","Operando esquerdo deve ser boolean");
                verifica_tipo(yyvsp[0].tipo,"boolean","Operando direita deve ser boolean");

                string tipo = "boolean";
                yyval.label=gentempcode(tipo);
                yyval.tipo = tipo;
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + "= " + yyvsp[-2].label + "&&" +  yyvsp[0].label + ";\n";  

            }
#line 1685 "y.tab.c"
    break;

  case 26: /* E: TK_NEGATIVO E  */
#line 319 "sintatico.y"
            {
                verifica_tipo(yyvsp[0].tipo,"boolean","Operando esquerdo deve ser boolean");
                

                string tipo = "boolean";
                yyval.label=gentempcode(tipo);
                yyval.tipo=tipo;
                yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label + "= !" + yyvsp[0].label + ";\n"; 

            }
#line 1700 "y.tab.c"
    break;

  case 27: /* E: TK_ID '=' E  */
#line 331 "sintatico.y"
            {
                string nome_variavel = pega_variavel_na_tabela(yyvsp[-2].label);
                string tipo_var = getTipo(yyvsp[-2].label);
                verifica_tipo(tipo_var, yyvsp[0].tipo, "atribuição incompatível!");
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + nome_variavel + " = " + yyvsp[0].label + ";\n";
            }
#line 1711 "y.tab.c"
    break;

  case 28: /* E: TK_INT TK_ID '=' E  */
#line 338 "sintatico.y"
            {

                
                string nome_interno = adiciona_variavel_na_tabela(yyvsp[-2].label, "int", yyvsp[0].label);
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + nome_interno + " = " + yyvsp[0].label + ";\n";
            }
#line 1722 "y.tab.c"
    break;

  case 29: /* E: TK_FLOAT TK_ID '=' E  */
#line 345 "sintatico.y"
            {   
                
                string nome_interno = adiciona_variavel_na_tabela( yyvsp[-2].label, "float", yyvsp[0].label);
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + nome_interno + " = " + yyvsp[0].label + ";\n";
            }
#line 1732 "y.tab.c"
    break;

  case 30: /* E: TK_CHAR TK_ID '=' E  */
#line 351 "sintatico.y"
            {
                
                string nome_interno = adiciona_variavel_na_tabela(yyvsp[-2].label,"char", yyvsp[0].label);
                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + nome_interno + "=" + yyvsp[0].label + ";\n";
            }
#line 1742 "y.tab.c"
    break;

  case 31: /* E: TK_BOOLEAN TK_ID '=' E  */
#line 357 "sintatico.y"
            {
                string nome_interno = adiciona_variavel_na_tabela( yyvsp[-2].label, "boolean", yyvsp[0].label);

                yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + nome_interno + " = " + yyvsp[0].label + ";\n";
            }
#line 1752 "y.tab.c"
    break;

  case 32: /* E: TK_NUM  */
#line 363 "sintatico.y"
            {
                yyval.label = gentempcode("int");
                yyval.tipo = "int";
                yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
            }
#line 1762 "y.tab.c"
    break;

  case 33: /* E: TK_REAL  */
#line 369 "sintatico.y"
            {
                yyval.label = gentempcode("float");
                yyval.tipo = "float";
                yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
            }
#line 1772 "y.tab.c"
    break;

  case 34: /* E: TK_TRUE  */
#line 375 "sintatico.y"
            {
                yyval.label = gentempcode("boolean");
                yyval.tipo = "boolean";
                yyval.traducao = "\t" + yyval.label + " = " + "1" + ";\n";
            }
#line 1782 "y.tab.c"
    break;

  case 35: /* E: TK_FALSE  */
#line 381 "sintatico.y"
            {
                yyval.label = gentempcode("boolean");
                yyval.tipo = "boolean";
                yyval.traducao = "\t" + yyval.label + " = " + "0" + ";\n";
            }
#line 1792 "y.tab.c"
    break;

  case 36: /* E: TK_ID  */
#line 387 "sintatico.y"
            {   
                string tipo = getTipo(yyvsp[0].label); 
                yyval.tipo=tipo;
                yyval.label = gentempcode(tipo);
                string nome_interno = pega_variavel_na_tabela(yyvsp[0].label);
                yyval.traducao = "\t" + yyval.label + " = " + nome_interno + ";\n";
            }
#line 1804 "y.tab.c"
    break;

  case 37: /* E: TK_CHAR  */
#line 395 "sintatico.y"
            {
                yyval.label = gentempcode("char");
                yyval.tipo = "char";
                yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label  + ";\n";

            }
#line 1815 "y.tab.c"
    break;

  case 38: /* E: TK_INT TK_ID  */
#line 402 "sintatico.y"
            {   
                string nome_interno = adiciona_variavel_na_tabela(yyvsp[0].label, "int", "");
                yyval.traducao = "";
            }
#line 1824 "y.tab.c"
    break;

  case 39: /* E: TK_FLOAT TK_ID  */
#line 407 "sintatico.y"
            {   
               
                string nome_interno = adiciona_variavel_na_tabela( yyvsp[0].label, "float", "");
                yyval.traducao = "";
            }
#line 1834 "y.tab.c"
    break;

  case 40: /* E: TK_CHAR TK_ID  */
#line 413 "sintatico.y"
            {
                string nome_interno = adiciona_variavel_na_tabela(yyvsp[0].label,"char", "");
                yyval.traducao = "";

            }
#line 1844 "y.tab.c"
    break;

  case 41: /* E: TK_BOOLEAN TK_ID  */
#line 419 "sintatico.y"
            {   
                string nome_interno = adiciona_variavel_na_tabela(yyvsp[0].label, "boolean", "");

                yyval.traducao = "";
            }
#line 1854 "y.tab.c"
    break;

  case 42: /* E: '(' TK_INT ')' TK_ID  */
#line 425 "sintatico.y"
            {  
                string tipo_atual = getTipo(yyvsp[0].label);
                string novo_tipo = "int";
                yyval.label = gentempcode(novo_tipo);
                yyval.tipo = novo_tipo;
                string nome_interno = pega_variavel_na_tabela(yyvsp[0].label);
                yyval.traducao = "\t" + yyval.label + " = " + "(" + novo_tipo + ")" + " " + nome_interno + ";\n";
            }
#line 1867 "y.tab.c"
    break;

  case 43: /* E: '(' TK_FLOAT ')' TK_ID  */
#line 434 "sintatico.y"
            {  
                string tipo_atual = getTipo(yyvsp[0].label);
                string novo_tipo = "float";
                yyval.label = gentempcode(novo_tipo);
                yyval.tipo = novo_tipo;
                string nome_interno = pega_variavel_na_tabela(yyvsp[0].label);
                yyval.traducao = "\t" + yyval.label + " = " + "(" + novo_tipo + ")" + " " + nome_interno + ";\n";
            }
#line 1880 "y.tab.c"
    break;

  case 44: /* E: '(' TK_BOOLEAN ')' TK_ID  */
#line 443 "sintatico.y"
            {  
                yyerror("Erro na linha " + to_string(linha) + ": não é possível transformar a variável em boolean!");
            }
#line 1888 "y.tab.c"
    break;


#line 1892 "y.tab.c"

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

#line 448 "sintatico.y"


#include "lex.yy.c"

int yyparse();


string gentempcode(string tipo) {
    var_temp_qnt++;
    string temp = "t" + to_string(var_temp_qnt); 
    temporarias[temp] = tipo;
    return temp;
}

string getTipo(string nome_interno) {
       for (auto it = pilha_escopos.rbegin(); it != pilha_escopos.rend(); ++it) {
        if (it->count(nome_interno)) {
            return it->at(nome_interno).tipo;
        }
    }
    yyerror("Erro na linha " + to_string(linha) + ": variável '" + nome_interno + "' não declarada ");
    return "";
}

string getTempId(string variavel) {
       for (auto it = pilha_escopos.rbegin(); it != pilha_escopos.rend(); ++it) {
        if (it->count(variavel)) {
            return it->at(variavel).temp_associada;
        }
    }
    yyerror("Erro na linha " + to_string(linha) + ": variável '" + variavel + "' não declarada.");
    return "";
}


void verifica_tipo_relacional(string tipo1, string tipo2) {
    if (tipo1 == "boolean" || tipo2 == "boolean") {
        yyerror("Erro na linha " + to_string(linha) + ": não é permitido fazer operation com booleano , somente int e float!");
    }
}
string resolve_tipo(string tipo1, string tipo2) {


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


void ver_boolean(string tipo1,string tipo3){
    if (tipo1 == "boolean" && tipo3 != "boolean") {
         yyerror("Erro na linha " + to_string(linha) + ": Não é permitido fazer operações entre " + tipo1 + " e " + tipo3);
            }
           if (tipo1 != "boolean" && tipo3 == "boolean") {
              yyerror("Erro na linha " + to_string(linha) + ": Não é permitido fazer operações entre " + tipo1 + " e " + tipo3);
                }

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


int main(int argc, char* argv[]) {
    var_temp_qnt = 0;
    linha = 1;
    yyparse();
    return 0;
}

int contador_if = 0;
int contador_else=0;

string fim_if(){
return "fim_if_" + to_string(++contador_if);
}
string fim_else(){
    return "fim_else_" + to_string(++contador_else);

}

void entra_escopo(){
    pilha_escopos.push_back({});
}

void sai_escopo(){
    pilha_escopos.pop_back();
}

string adiciona_variavel_na_tabela(string variavel, string tipo, string temp_associada) {
    if (pilha_escopos.empty()) entra_escopo();
    auto& escopo_atual = pilha_escopos.back();
    if (escopo_atual.count(variavel)) {
        return escopo_atual[variavel].nome_interno;
    }

    string nome_interno = "__v" + to_string(var_user_qnt++);
    Simbolo s = {nome_interno, tipo, temp_associada};
    escopo_atual[variavel] = s;
    simbolos_declarados.push_back(s); // <- adiciona aqui
    return nome_interno;
}

string pega_variavel_na_tabela(string nome_variavel) {

    for (auto it = pilha_escopos.rbegin(); it != pilha_escopos.rend(); ++it) {
        if (it->count(nome_variavel)) {
            return it->at(nome_variavel).nome_interno;
        }
    }
    
    yyerror("Erro na linha " + to_string(linha) + ": variável '" + nome_variavel + "' declarada em escopo local.");
    return "";
}


void verifica_tipo(string tipo1, string tipo2, string mensagem) {
    if(tipo1 == "" || tipo2 == "") {
        yyerror("Erro na linha " + to_string(linha) + ": variável não declaradaaaaa!");
    }

    else if( tipo1 != tipo2 ) {
        yyerror("Erro na linha " + to_string(linha) + ": "+ mensagem);
    }
}

void yyerror(string MSG) {
    cout << "\033[1;31m" << MSG << "\033[0m" << endl;
    exit (0);
}
