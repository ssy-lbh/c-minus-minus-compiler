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
#line 50 "parse.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"

#include "dict.h"
#include "ir.h"
#include "vm.h"

int yylex();
void yyerror(char *s);

ir_program *program = NULL;

ir_func_ctx *f_stack[0x40];
int f_top = -1;

extern long num;
extern char name[0x400];
extern FILE* yyin;

#line 95 "parse.tab.c"

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

#include "parse.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_NAME = 4,                       /* NAME  */
  YYSYMBOL_IF = 5,                         /* IF  */
  YYSYMBOL_WHILE = 6,                      /* WHILE  */
  YYSYMBOL_RETURN = 7,                     /* RETURN  */
  YYSYMBOL_VOID = 8,                       /* VOID  */
  YYSYMBOL_INT = 9,                        /* INT  */
  YYSYMBOL_FLOAT = 10,                     /* FLOAT  */
  YYSYMBOL_STR = 11,                       /* STR  */
  YYSYMBOL_CHAR = 12,                      /* CHAR  */
  YYSYMBOL_LE = 13,                        /* LE  */
  YYSYMBOL_GE = 14,                        /* GE  */
  YYSYMBOL_EQ = 15,                        /* EQ  */
  YYSYMBOL_NE = 16,                        /* NE  */
  YYSYMBOL_SHL = 17,                       /* SHL  */
  YYSYMBOL_SHR = 18,                       /* SHR  */
  YYSYMBOL_AND = 19,                       /* AND  */
  YYSYMBOL_OR = 20,                        /* OR  */
  YYSYMBOL_ARROW = 21,                     /* ARROW  */
  YYSYMBOL_INC = 22,                       /* INC  */
  YYSYMBOL_DEC = 23,                       /* DEC  */
  YYSYMBOL_ADD_ASSIGN = 24,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 25,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 26,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 27,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 28,                /* MOD_ASSIGN  */
  YYSYMBOL_SHL_ASSIGN = 29,                /* SHL_ASSIGN  */
  YYSYMBOL_SHR_ASSIGN = 30,                /* SHR_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 31,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 32,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 33,                 /* OR_ASSIGN  */
  YYSYMBOL_34_ = 34,                       /* ';'  */
  YYSYMBOL_ELSE = 35,                      /* ELSE  */
  YYSYMBOL_36_ = 36,                       /* '('  */
  YYSYMBOL_37_ = 37,                       /* ')'  */
  YYSYMBOL_38_ = 38,                       /* '['  */
  YYSYMBOL_39_ = 39,                       /* ']'  */
  YYSYMBOL_40_ = 40,                       /* '{'  */
  YYSYMBOL_41_ = 41,                       /* '}'  */
  YYSYMBOL_42_ = 42,                       /* ','  */
  YYSYMBOL_43_ = 43,                       /* '='  */
  YYSYMBOL_44_ = 44,                       /* '<'  */
  YYSYMBOL_45_ = 45,                       /* '>'  */
  YYSYMBOL_46_ = 46,                       /* '^'  */
  YYSYMBOL_47_ = 47,                       /* '&'  */
  YYSYMBOL_48_ = 48,                       /* '|'  */
  YYSYMBOL_49_ = 49,                       /* '+'  */
  YYSYMBOL_50_ = 50,                       /* '-'  */
  YYSYMBOL_51_ = 51,                       /* '*'  */
  YYSYMBOL_52_ = 52,                       /* '/'  */
  YYSYMBOL_53_ = 53,                       /* '%'  */
  YYSYMBOL_54_ = 54,                       /* '~'  */
  YYSYMBOL_55_ = 55,                       /* '!'  */
  YYSYMBOL_56_ = 56,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 57,                  /* $accept  */
  YYSYMBOL_program = 58,                   /* program  */
  YYSYMBOL_stmt = 59,                      /* stmt  */
  YYSYMBOL_if = 60,                        /* if  */
  YYSYMBOL_while_cond = 61,                /* while_cond  */
  YYSYMBOL_while_start = 62,               /* while_start  */
  YYSYMBOL_decl = 63,                      /* decl  */
  YYSYMBOL_var_name = 64,                  /* var_name  */
  YYSYMBOL_func_name = 65,                 /* func_name  */
  YYSYMBOL_expr = 66,                      /* expr  */
  YYSYMBOL_constexpr = 67,                 /* constexpr  */
  YYSYMBOL_func_call = 68,                 /* func_call  */
  YYSYMBOL_type_name = 69,                 /* type_name  */
  YYSYMBOL_var_decl = 70,                  /* var_decl  */
  YYSYMBOL_func_decl = 71,                 /* func_decl  */
  YYSYMBOL_para_decl = 72,                 /* para_decl  */
  YYSYMBOL_73_1 = 73,                      /* $@1  */
  YYSYMBOL_para_list = 74                  /* para_list  */
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   781

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  196

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
       2,     2,     2,    55,     2,     2,     2,    53,    47,     2,
      36,    37,    51,    49,    42,    50,    56,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    34,
      44,    43,    45,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,    46,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,    48,    41,    54,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    88,    88,    89,    92,    93,    94,    95,    96,    97,
      98,    99,   102,   105,   108,   111,   112,   115,   121,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   207,   215,
     216,   217,   220,   224,   229,   235,   243,   247,   248,   248,
     252,   255,   256,   257
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
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "NAME", "IF",
  "WHILE", "RETURN", "VOID", "INT", "FLOAT", "STR", "CHAR", "LE", "GE",
  "EQ", "NE", "SHL", "SHR", "AND", "OR", "ARROW", "INC", "DEC",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "SHL_ASSIGN", "SHR_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "';'", "ELSE", "'('", "')'", "'['", "']'", "'{'", "'}'", "','", "'='",
  "'<'", "'>'", "'^'", "'&'", "'|'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'~'", "'!'", "'.'", "$accept", "program", "stmt", "if", "while_cond",
  "while_start", "decl", "var_name", "func_name", "expr", "constexpr",
  "func_call", "type_name", "var_decl", "func_decl", "para_decl", "$@1",
  "para_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-111)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-99)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -111,    81,  -111,  -111,   -28,   -26,  -111,   276,  -111,  -111,
    -111,  -111,   102,   102,  -111,   102,  -111,   102,   102,   102,
     102,   102,   102,  -111,   242,    -9,  -111,   319,     3,     0,
    -111,  -111,   102,  -111,   360,  -111,  -111,   401,   136,   111,
     -20,   -20,    72,  -111,  -111,  -111,   102,   242,   102,   102,
     102,   102,   102,   102,   102,   102,  -111,  -111,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,  -111,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,     5,  -111,   -13,    44,   442,  -111,  -111,  -111,
     483,  -111,   156,   156,   156,   156,   156,   156,   688,   688,
     647,   647,   647,   647,   647,   647,   647,   647,   647,   647,
     524,   647,   156,   156,   111,   111,   111,   -20,   -20,    72,
      72,    72,   606,   -18,  -111,    47,   102,    14,  -111,  -111,
    -111,  -111,   102,  -111,    47,    47,    47,    47,   668,   565,
     -17,    25,    54,   606,   709,    26,  -111,  -111,    47,    47,
      47,    47,    47,    47,    47,    47,    28,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,  -111,   -24,    56,
    -111,   167,   167,   167,   167,   167,   167,   256,   256,  -111,
     167,   167,   -15,   -15,   -15,    26,    26,  -111,  -111,  -111,
      57,  -111,    14,   189,  -111,  -111
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,    19,    21,     0,    14,     0,    90,    89,
      22,    20,     0,     0,    11,     0,     2,     0,     0,     0,
       0,     0,     0,     3,     0,     0,     5,     0,     0,     0,
      15,    16,     0,    10,     0,    48,    49,     0,     0,    61,
      38,    37,    62,    39,    40,     6,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    46,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     4,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,    17,    91,     0,     0,     0,     9,    60,     8,
       0,     7,    31,    32,    33,    34,    35,    36,    44,    45,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
       0,    23,    29,    30,    43,    41,    42,    24,    25,    26,
      27,    28,   101,     0,    92,     0,     0,   100,    12,    13,
      63,    64,     0,    65,     0,     0,     0,     0,     0,     0,
      90,     0,     0,   102,     0,    79,    80,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    93,    96,     0,
      87,    73,    74,    75,    76,    77,    78,    85,    86,    94,
      71,    72,    84,    82,    83,    66,    67,    68,    69,    70,
       0,     2,   100,     0,    99,    95
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,   -16,   -19,  -111,  -111,  -111,  -111,  -111,  -111,    -6,
     615,  -111,  -110,  -111,  -111,   -94,  -111,  -111
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    23,    24,    47,    25,    26,    84,    85,    27,
     138,    28,    29,    30,    31,   142,   190,   123
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      38,    34,    56,    57,    82,    45,    35,    36,   -88,    37,
      32,    39,    40,    41,    42,    43,    44,   141,   -98,   131,
     -97,   124,   140,     9,   132,   125,    86,    46,    91,   168,
     126,    78,    79,    80,   162,   163,   164,   165,   166,    81,
      90,   -18,    92,    93,    94,    95,    96,    97,    98,    99,
     133,    83,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   179,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    83,   164,   165,   166,
     127,     2,   141,   134,     3,     4,     5,     6,     7,     8,
       9,   169,    10,    11,    56,    57,   191,   135,   194,   192,
       0,   136,   137,    12,    13,     3,     4,     0,     0,     0,
       0,     0,     0,    10,    11,    14,     0,    15,     0,     0,
     139,    16,     0,     0,    12,    13,   143,     0,    17,     0,
      18,    19,    20,    56,    57,    21,    22,     0,    15,     3,
       4,     5,     6,     7,     8,     9,     0,    10,    11,    17,
       0,    18,    19,    20,     0,     0,    21,    22,    12,    13,
      76,    77,    78,    79,    80,     0,     0,     0,     0,     0,
      14,     0,    15,     0,     0,   193,    16,    89,    56,    57,
       0,     0,     0,    17,     0,    18,    19,    20,     0,     0,
      21,    22,     3,     4,     5,     6,     7,     8,     9,     0,
      10,    11,    73,    74,    75,    76,    77,    78,    79,    80,
       0,    12,    13,   159,   160,   161,   162,   163,   164,   165,
     166,     0,     0,    14,     0,    15,     0,     0,     0,    16,
     195,     0,     0,     0,     0,     0,    17,     0,    18,    19,
      20,     0,     0,    21,    22,     3,     4,     5,     6,     7,
       8,     9,     0,    10,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,    13,     0,     0,     0,   148,
     149,   150,   151,   152,   153,     0,    14,     0,    15,     3,
       4,     0,    16,     0,     0,     0,     0,    10,    11,    17,
       0,    18,    19,    20,     0,     0,    21,    22,    12,    13,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
      33,     0,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,     0,    18,    19,    20,     0,     0,
      21,    22,    48,    49,    50,    51,    52,    53,    54,    55,
       0,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,     0,     0,    69,     0,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    48,    49,    50,    51,    52,    53,    54,
      55,     0,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    87,     0,     0,     0,    69,     0,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    48,    49,    50,    51,    52,    53,
      54,    55,     0,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,     0,     0,    88,    69,
       0,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    48,    49,    50,    51,    52,
      53,    54,    55,     0,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,     0,     0,   128,
      69,     0,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    48,    49,    50,    51,
      52,    53,    54,    55,     0,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,     0,     0,
     129,    69,     0,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    48,    49,    50,
      51,    52,    53,    54,    55,     0,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,     0,
       0,     0,    69,   130,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    48,    49,
      50,    51,    52,    53,    54,    55,     0,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,   167,
       0,     0,     0,    69,     0,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    48,
      49,    50,    51,    52,    53,    54,    55,     0,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,     0,     0,     0,    69,     0,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      48,    49,    50,    51,    52,    53,    54,    55,     0,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,   148,   149,   150,   151,   152,   153,   154,   155,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    48,    49,    50,    51,    52,    53,   156,     0,     0,
      56,    57,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   148,   149,   150,   151,   152,   153,   154,   155,
       0,     0,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,     0,     0,     0,     0,   170,     0,     0,   144,
     145,   146,   147,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   171,   172,   173,   174,   175,   176,   177,
     178,     0,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189
};

static const yytype_int16 yycheck[] =
{
      16,     7,    22,    23,     4,    24,    12,    13,    36,    15,
      36,    17,    18,    19,    20,    21,    22,   127,    42,    37,
      37,    34,     8,     9,    42,    38,    32,    36,    47,     4,
      43,    51,    52,    53,    49,    50,    51,    52,    53,    36,
      46,    36,    48,    49,    50,    51,    52,    53,    54,    55,
       3,    51,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    34,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    51,    51,    52,    53,
      36,     0,   192,    36,     3,     4,     5,     6,     7,     8,
       9,    37,    11,    12,    22,    23,    40,    50,   192,    42,
      -1,    54,    55,    22,    23,     3,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    11,    12,    34,    -1,    36,    -1,    -1,
     126,    40,    -1,    -1,    22,    23,   132,    -1,    47,    -1,
      49,    50,    51,    22,    23,    54,    55,    -1,    36,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    47,
      -1,    49,    50,    51,    -1,    -1,    54,    55,    22,    23,
      49,    50,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    36,    -1,    -1,   191,    40,    41,    22,    23,
      -1,    -1,    -1,    47,    -1,    49,    50,    51,    -1,    -1,
      54,    55,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    22,    23,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    34,    -1,    36,    -1,    -1,    -1,    40,
      41,    -1,    -1,    -1,    -1,    -1,    47,    -1,    49,    50,
      51,    -1,    -1,    54,    55,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    -1,    -1,    -1,    13,
      14,    15,    16,    17,    18,    -1,    34,    -1,    36,     3,
       4,    -1,    40,    -1,    -1,    -1,    -1,    11,    12,    47,
      -1,    49,    50,    51,    -1,    -1,    54,    55,    22,    23,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      34,    -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    49,    50,    51,    -1,    -1,
      54,    55,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    37,    38,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    37,
      38,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      37,    38,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    38,    39,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    13,    14,    15,    16,    17,    18,    39,    -1,    -1,
      22,    23,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    -1,    -1,    -1,    37,    -1,    -1,   134,
     135,   136,   137,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    58,     0,     3,     4,     5,     6,     7,     8,     9,
      11,    12,    22,    23,    34,    36,    40,    47,    49,    50,
      51,    54,    55,    59,    60,    62,    63,    66,    68,    69,
      70,    71,    36,    34,    66,    66,    66,    66,    58,    66,
      66,    66,    66,    66,    66,    59,    36,    61,    13,    14,
      15,    16,    17,    18,    19,    20,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    38,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    36,     4,    51,    64,    65,    66,    34,    37,    41,
      66,    59,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    74,    34,    38,    43,    36,    37,    37,
      39,    37,    42,     3,    36,    50,    54,    55,    67,    66,
       8,    69,    72,    66,    67,    67,    67,    67,    13,    14,
      15,    16,    17,    18,    19,    20,    39,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    34,     4,    37,
      37,    67,    67,    67,    67,    67,    67,    67,    67,    34,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      73,    40,    42,    58,    72,    41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    58,    59,    59,    59,    59,    59,    59,
      59,    59,    60,    61,    62,    63,    63,    64,    65,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    68,    69,
      69,    69,    70,    70,    70,    71,    72,    72,    73,    72,
      72,    74,    74,    74
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     2,     3,     3,     3,
       2,     1,     4,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     4,     4,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     2,     3,     5,     6,     8,     2,     1,     0,     5,
       0,     1,     3,     0
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
  case 4: /* stmt: expr ';'  */
#line 92 "parse.y"
             {}
#line 1399 "parse.tab.c"
    break;

  case 5: /* stmt: decl  */
#line 93 "parse.y"
           {}
#line 1405 "parse.tab.c"
    break;

  case 6: /* stmt: if stmt  */
#line 94 "parse.y"
              { f_stack[f_top]->f->code[(yyvsp[-1].num)].op1.ival = f_stack[f_top]->f->code_num; }
#line 1411 "parse.tab.c"
    break;

  case 7: /* stmt: while_start while_cond stmt  */
#line 95 "parse.y"
                                  { ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_JMP, (yyvsp[-2].num))); f_stack[f_top]->f->code[(yyvsp[-1].num)].op1.ival = f_stack[f_top]->f->code_num; }
#line 1417 "parse.tab.c"
    break;

  case 8: /* stmt: '{' program '}'  */
#line 96 "parse.y"
                      {}
#line 1423 "parse.tab.c"
    break;

  case 9: /* stmt: RETURN expr ';'  */
#line 97 "parse.y"
                      { ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_RET, (yyvsp[-1].value))); }
#line 1429 "parse.tab.c"
    break;

  case 10: /* stmt: RETURN ';'  */
#line 98 "parse.y"
                 { ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_RET, 0)); }
#line 1435 "parse.tab.c"
    break;

  case 11: /* stmt: ';'  */
#line 99 "parse.y"
          {}
#line 1441 "parse.tab.c"
    break;

  case 12: /* if: IF '(' expr ')'  */
#line 102 "parse.y"
                    { (yyval.num) = f_stack[f_top]->f->code_num; ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_JMPNOT, (yyvsp[-1].value))); }
#line 1447 "parse.tab.c"
    break;

  case 13: /* while_cond: '(' expr ')'  */
#line 105 "parse.y"
                 { (yyval.num) = ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_JMPNOT, (yyvsp[-1].value))); }
#line 1453 "parse.tab.c"
    break;

  case 14: /* while_start: WHILE  */
#line 108 "parse.y"
          { (yyval.num) = f_stack[f_top]->f->code_num; }
#line 1459 "parse.tab.c"
    break;

  case 17: /* var_name: NAME  */
#line 115 "parse.y"
         {
        printf("Declaration: %s\n", name);
        (yyval.name) = strdup(name);
    }
#line 1468 "parse.tab.c"
    break;

  case 18: /* func_name: NAME  */
#line 121 "parse.y"
         {
        printf("Function: %s\n", name);
        f_stack[++f_top] = ir_func_ctx_new(ir_func_new(name, 0));
        ir_program_add_func(program, f_stack[f_top]->f);
    }
#line 1478 "parse.tab.c"
    break;

  case 19: /* expr: NUMBER  */
#line 128 "parse.y"
           { (yyval.value) = ir_expr_imm(num); }
#line 1484 "parse.tab.c"
    break;

  case 20: /* expr: CHAR  */
#line 129 "parse.y"
           { (yyval.value) = ir_expr_imm(num); }
#line 1490 "parse.tab.c"
    break;

  case 21: /* expr: NAME  */
#line 130 "parse.y"
           { (yyval.value) = ir_expr_var(ir_func_ctx_get_local(f_stack[f_top], name)); }
#line 1496 "parse.tab.c"
    break;

  case 22: /* expr: STR  */
#line 131 "parse.y"
          { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_lea((yyval.value), name)); }
#line 1502 "parse.tab.c"
    break;

  case 23: /* expr: expr '=' expr  */
#line 132 "parse.y"
                    { ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 1508 "parse.tab.c"
    break;

  case 24: /* expr: expr '+' expr  */
#line 133 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_ADD, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1514 "parse.tab.c"
    break;

  case 25: /* expr: expr '-' expr  */
#line 134 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SUB, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1520 "parse.tab.c"
    break;

  case 26: /* expr: expr '*' expr  */
#line 135 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_MUL, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1526 "parse.tab.c"
    break;

  case 27: /* expr: expr '/' expr  */
#line 136 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_DIV, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1532 "parse.tab.c"
    break;

  case 28: /* expr: expr '%' expr  */
#line 137 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_MOD, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1538 "parse.tab.c"
    break;

  case 29: /* expr: expr '<' expr  */
#line 138 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_LT, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1544 "parse.tab.c"
    break;

  case 30: /* expr: expr '>' expr  */
#line 139 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_GT, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1550 "parse.tab.c"
    break;

  case 31: /* expr: expr LE expr  */
#line 140 "parse.y"
                   { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_LE, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1556 "parse.tab.c"
    break;

  case 32: /* expr: expr GE expr  */
#line 141 "parse.y"
                   { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_GE, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1562 "parse.tab.c"
    break;

  case 33: /* expr: expr EQ expr  */
#line 142 "parse.y"
                   { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_EQ, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1568 "parse.tab.c"
    break;

  case 34: /* expr: expr NE expr  */
#line 143 "parse.y"
                   { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_NE, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1574 "parse.tab.c"
    break;

  case 35: /* expr: expr SHL expr  */
#line 144 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SHL, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1580 "parse.tab.c"
    break;

  case 36: /* expr: expr SHR expr  */
#line 145 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SHR, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1586 "parse.tab.c"
    break;

  case 37: /* expr: '-' expr  */
#line 146 "parse.y"
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_NEG, (yyval.value), (yyvsp[0].value))); }
#line 1592 "parse.tab.c"
    break;

  case 38: /* expr: '+' expr  */
#line 147 "parse.y"
               { (yyval.value) = (yyvsp[0].value); }
#line 1598 "parse.tab.c"
    break;

  case 39: /* expr: '~' expr  */
#line 148 "parse.y"
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_NOT, (yyval.value), (yyvsp[0].value))); }
#line 1604 "parse.tab.c"
    break;

  case 40: /* expr: '!' expr  */
#line 149 "parse.y"
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_LOGIC_NOT, (yyval.value), (yyvsp[0].value))); }
#line 1610 "parse.tab.c"
    break;

  case 41: /* expr: expr '&' expr  */
#line 150 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_AND, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1616 "parse.tab.c"
    break;

  case 42: /* expr: expr '|' expr  */
#line 151 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_OR, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1622 "parse.tab.c"
    break;

  case 43: /* expr: expr '^' expr  */
#line 152 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_XOR, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1628 "parse.tab.c"
    break;

  case 44: /* expr: expr AND expr  */
#line 153 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_LOGIC_AND, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1634 "parse.tab.c"
    break;

  case 45: /* expr: expr OR expr  */
#line 154 "parse.y"
                   { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_LOGIC_OR, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1640 "parse.tab.c"
    break;

  case 46: /* expr: expr INC  */
#line 155 "parse.y"
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_ADD, (yyvsp[-1].value), (yyvsp[-1].value), ir_expr_imm(1))); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, (yyval.value), (yyvsp[-1].value))); }
#line 1646 "parse.tab.c"
    break;

  case 47: /* expr: expr DEC  */
#line 156 "parse.y"
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SUB, (yyvsp[-1].value), (yyvsp[-1].value), ir_expr_imm(1))); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, (yyval.value), (yyvsp[-1].value))); }
#line 1652 "parse.tab.c"
    break;

  case 48: /* expr: INC expr  */
#line 157 "parse.y"
               { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_ADD, (yyvsp[0].value), (yyvsp[0].value), ir_expr_imm(1))); (yyval.value) = (yyvsp[0].value); }
#line 1658 "parse.tab.c"
    break;

  case 49: /* expr: DEC expr  */
#line 158 "parse.y"
               { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SUB, (yyvsp[0].value), (yyvsp[0].value), ir_expr_imm(1))); (yyval.value) = (yyvsp[0].value); }
#line 1664 "parse.tab.c"
    break;

  case 50: /* expr: expr ADD_ASSIGN expr  */
#line 159 "parse.y"
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_ADD, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 1670 "parse.tab.c"
    break;

  case 51: /* expr: expr SUB_ASSIGN expr  */
#line 160 "parse.y"
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SUB, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 1676 "parse.tab.c"
    break;

  case 52: /* expr: expr MUL_ASSIGN expr  */
#line 161 "parse.y"
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_MUL, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 1682 "parse.tab.c"
    break;

  case 53: /* expr: expr DIV_ASSIGN expr  */
#line 162 "parse.y"
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_DIV, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 1688 "parse.tab.c"
    break;

  case 54: /* expr: expr MOD_ASSIGN expr  */
#line 163 "parse.y"
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_MOD, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 1694 "parse.tab.c"
    break;

  case 55: /* expr: expr SHL_ASSIGN expr  */
#line 164 "parse.y"
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SHL, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 1700 "parse.tab.c"
    break;

  case 56: /* expr: expr SHR_ASSIGN expr  */
#line 165 "parse.y"
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SHR, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 1706 "parse.tab.c"
    break;

  case 57: /* expr: expr AND_ASSIGN expr  */
#line 166 "parse.y"
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_AND, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 1712 "parse.tab.c"
    break;

  case 58: /* expr: expr XOR_ASSIGN expr  */
#line 167 "parse.y"
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_XOR, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 1718 "parse.tab.c"
    break;

  case 59: /* expr: expr OR_ASSIGN expr  */
#line 168 "parse.y"
                          { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_OR, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 1724 "parse.tab.c"
    break;

  case 60: /* expr: '(' expr ')'  */
#line 169 "parse.y"
                   { (yyval.value) = (yyvsp[-1].value); }
#line 1730 "parse.tab.c"
    break;

  case 61: /* expr: '&' expr  */
#line 170 "parse.y"
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); if ((yyvsp[0].value).is_imm){ printf("'&' could not be used on an immediate number\n"); exit(1); } ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_ADDR, (yyval.value), (yyvsp[0].value))); }
#line 1736 "parse.tab.c"
    break;

  case 62: /* expr: '*' expr  */
#line 171 "parse.y"
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_DEREF, (yyval.value), (yyvsp[0].value))); }
#line 1742 "parse.tab.c"
    break;

  case 63: /* expr: expr '[' expr ']'  */
#line 172 "parse.y"
                        { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_ADD, (yyval.value), ir_expr_imm((yyvsp[-3].value).ival), (yyvsp[-1].value))); (yyval.value) = ir_expr_ref((yyval.value).ival); }
#line 1748 "parse.tab.c"
    break;

  case 64: /* expr: func_call '(' para_list ')'  */
#line 173 "parse.y"
                                  {
        (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top]));
        ir i = ir_new1(IR_CALL, (yyval.value));
        i.op = f_stack[f_top]->f->code[(yyvsp[-3].num)].op;
        f_stack[f_top]->f->code[(yyvsp[-3].num)].op = NULL;
        ir_func_add_code(f_stack[f_top]->f, i);
    }
#line 1760 "parse.tab.c"
    break;

  case 65: /* constexpr: NUMBER  */
#line 182 "parse.y"
           { (yyval.num) = num; }
#line 1766 "parse.tab.c"
    break;

  case 66: /* constexpr: constexpr '+' constexpr  */
#line 183 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) + (yyvsp[0].num); }
#line 1772 "parse.tab.c"
    break;

  case 67: /* constexpr: constexpr '-' constexpr  */
#line 184 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) - (yyvsp[0].num); }
#line 1778 "parse.tab.c"
    break;

  case 68: /* constexpr: constexpr '*' constexpr  */
#line 185 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) * (yyvsp[0].num); }
#line 1784 "parse.tab.c"
    break;

  case 69: /* constexpr: constexpr '/' constexpr  */
#line 186 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) / (yyvsp[0].num); }
#line 1790 "parse.tab.c"
    break;

  case 70: /* constexpr: constexpr '%' constexpr  */
#line 187 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) % (yyvsp[0].num); }
#line 1796 "parse.tab.c"
    break;

  case 71: /* constexpr: constexpr '<' constexpr  */
#line 188 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) < (yyvsp[0].num); }
#line 1802 "parse.tab.c"
    break;

  case 72: /* constexpr: constexpr '>' constexpr  */
#line 189 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) > (yyvsp[0].num); }
#line 1808 "parse.tab.c"
    break;

  case 73: /* constexpr: constexpr LE constexpr  */
#line 190 "parse.y"
                             { (yyval.num) = (yyvsp[-2].num) <= (yyvsp[0].num); }
#line 1814 "parse.tab.c"
    break;

  case 74: /* constexpr: constexpr GE constexpr  */
#line 191 "parse.y"
                             { (yyval.num) = (yyvsp[-2].num) >= (yyvsp[0].num); }
#line 1820 "parse.tab.c"
    break;

  case 75: /* constexpr: constexpr EQ constexpr  */
#line 192 "parse.y"
                             { (yyval.num) = (yyvsp[-2].num) == (yyvsp[0].num); }
#line 1826 "parse.tab.c"
    break;

  case 76: /* constexpr: constexpr NE constexpr  */
#line 193 "parse.y"
                             { (yyval.num) = (yyvsp[-2].num) != (yyvsp[0].num); }
#line 1832 "parse.tab.c"
    break;

  case 77: /* constexpr: constexpr SHL constexpr  */
#line 194 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) << (yyvsp[0].num); }
#line 1838 "parse.tab.c"
    break;

  case 78: /* constexpr: constexpr SHR constexpr  */
#line 195 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) >> (yyvsp[0].num); }
#line 1844 "parse.tab.c"
    break;

  case 79: /* constexpr: '-' constexpr  */
#line 196 "parse.y"
                    { (yyval.num) = -(yyvsp[0].num); }
#line 1850 "parse.tab.c"
    break;

  case 80: /* constexpr: '~' constexpr  */
#line 197 "parse.y"
                    { (yyval.num) = ~(yyvsp[0].num); }
#line 1856 "parse.tab.c"
    break;

  case 81: /* constexpr: '!' constexpr  */
#line 198 "parse.y"
                    { (yyval.num) = !(yyvsp[0].num); }
#line 1862 "parse.tab.c"
    break;

  case 82: /* constexpr: constexpr '&' constexpr  */
#line 199 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) & (yyvsp[0].num); }
#line 1868 "parse.tab.c"
    break;

  case 83: /* constexpr: constexpr '|' constexpr  */
#line 200 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) | (yyvsp[0].num); }
#line 1874 "parse.tab.c"
    break;

  case 84: /* constexpr: constexpr '^' constexpr  */
#line 201 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) ^ (yyvsp[0].num); }
#line 1880 "parse.tab.c"
    break;

  case 85: /* constexpr: constexpr AND constexpr  */
#line 202 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) && (yyvsp[0].num); }
#line 1886 "parse.tab.c"
    break;

  case 86: /* constexpr: constexpr OR constexpr  */
#line 203 "parse.y"
                             { (yyval.num) = (yyvsp[-2].num) || (yyvsp[0].num); }
#line 1892 "parse.tab.c"
    break;

  case 87: /* constexpr: '(' constexpr ')'  */
#line 204 "parse.y"
                        { (yyval.num) = (yyvsp[-1].num); }
#line 1898 "parse.tab.c"
    break;

  case 88: /* func_call: NAME  */
#line 207 "parse.y"
         {
        printf("Function Call: %s\n", name);
        ir i = ir_new0(IR_PARAM);
        i.op = strdup(name);
        (yyval.num) = ir_func_add_code(f_stack[f_top]->f, i);
    }
#line 1909 "parse.tab.c"
    break;

  case 92: /* var_decl: type_name var_name ';'  */
#line 220 "parse.y"
                           {
        ir_func_ctx_add_local(f_stack[f_top], (yyvsp[-1].name), 1);
        free((yyvsp[-1].name));
    }
#line 1918 "parse.tab.c"
    break;

  case 93: /* var_decl: type_name var_name '=' expr ';'  */
#line 224 "parse.y"
                                      {
        expr_info id = ir_expr_var(ir_func_ctx_add_local(f_stack[f_top], (yyvsp[-3].name), 1));
        free((yyvsp[-3].name));
        ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, id, (yyvsp[-1].value)));
    }
#line 1928 "parse.tab.c"
    break;

  case 94: /* var_decl: type_name var_name '[' constexpr ']' ';'  */
#line 229 "parse.y"
                                               {
        int length = (int)(yyvsp[-2].num);
        ir_func_ctx_add_local(f_stack[f_top], (yyvsp[-4].name), length);
        free((yyvsp[-4].name));
    }
#line 1938 "parse.tab.c"
    break;

  case 95: /* func_decl: type_name func_name '(' para_decl ')' '{' program '}'  */
#line 235 "parse.y"
                                                          {
        printf("Function End %s\n", f_stack[f_top]->f->name);
        if (f_stack[f_top]->f->code[f_stack[f_top]->f->code_num - 1].ins != IR_RET){
            ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_RET, 0));
        }
        ir_func_ctx_free(f_stack[f_top--]);
    }
#line 1950 "parse.tab.c"
    break;

  case 96: /* para_decl: type_name NAME  */
#line 243 "parse.y"
                   {
        printf("Parameter Declare: %s\n", name);
        ir_func_ctx_add_local(f_stack[f_top], name, 1);
    }
#line 1959 "parse.tab.c"
    break;

  case 98: /* $@1: %empty  */
#line 248 "parse.y"
                     {
        printf("Parameter Declare: %s\n", name);
        ir_func_ctx_add_local(f_stack[f_top], name, 1);
    }
#line 1968 "parse.tab.c"
    break;

  case 100: /* para_decl: %empty  */
#line 252 "parse.y"
      {}
#line 1974 "parse.tab.c"
    break;

  case 101: /* para_list: expr  */
#line 255 "parse.y"
         { ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_PASS, (yyvsp[0].value))); }
#line 1980 "parse.tab.c"
    break;

  case 102: /* para_list: para_list ',' expr  */
#line 256 "parse.y"
                         { ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_PASS, (yyvsp[0].value))); }
#line 1986 "parse.tab.c"
    break;

  case 103: /* para_list: %empty  */
#line 257 "parse.y"
      {}
#line 1992 "parse.tab.c"
    break;


#line 1996 "parse.tab.c"

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

#line 259 "parse.y"


void func_foreach(char* name, void* value){
    printf("Function: %s\n", name);
    ir_func* f = (ir_func*)value;
    for (int i = 0; i < f->code_num; i++){
        ir_print(f->code[i]);
    }
}

int main(int argc, char** argv){
    if (argc > 1){
        yyin = fopen(argv[1], "r");
        if (!yyin){
            printf("Cannot open file %s\n", argv[1]);
            return 1;
        }
        printf("Parsing %s...\n", argv[1]);
    } else {
        printf("Parsing from stdin...\n");
    }

    program = ir_program_new();

    //yydebug = 1;
    yyparse();

    printf("\nParsing finished.\n");
    dict_foreach(program->func_dict, func_foreach);

    vm_add_native(program);
    vm_ctx* ctx = vm_ctx_new();
    int ret = (int)vm_run(ctx, program, "main");
    printf("Process exited with code %d\n", ret);

    ir_program_free(program);

    return 0;
}
