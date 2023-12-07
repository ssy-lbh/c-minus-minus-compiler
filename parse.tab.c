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
#line 35 "parse.y"

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
  YYSYMBOL_SEMICOLON = 5,                  /* SEMICOLON  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_WHILE = 7,                      /* WHILE  */
  YYSYMBOL_RETURN = 8,                     /* RETURN  */
  YYSYMBOL_VOID = 9,                       /* VOID  */
  YYSYMBOL_INT = 10,                       /* INT  */
  YYSYMBOL_FLOAT = 11,                     /* FLOAT  */
  YYSYMBOL_LE = 12,                        /* LE  */
  YYSYMBOL_GE = 13,                        /* GE  */
  YYSYMBOL_EQ = 14,                        /* EQ  */
  YYSYMBOL_NE = 15,                        /* NE  */
  YYSYMBOL_SHL = 16,                       /* SHL  */
  YYSYMBOL_SHR = 17,                       /* SHR  */
  YYSYMBOL_AND = 18,                       /* AND  */
  YYSYMBOL_OR = 19,                        /* OR  */
  YYSYMBOL_ARROW = 20,                     /* ARROW  */
  YYSYMBOL_ELSE = 21,                      /* ELSE  */
  YYSYMBOL_22_ = 22,                       /* '('  */
  YYSYMBOL_23_ = 23,                       /* ')'  */
  YYSYMBOL_24_ = 24,                       /* '['  */
  YYSYMBOL_25_ = 25,                       /* ']'  */
  YYSYMBOL_26_ = 26,                       /* '{'  */
  YYSYMBOL_27_ = 27,                       /* '}'  */
  YYSYMBOL_28_ = 28,                       /* ','  */
  YYSYMBOL_29_ = 29,                       /* '='  */
  YYSYMBOL_30_ = 30,                       /* '<'  */
  YYSYMBOL_31_ = 31,                       /* '>'  */
  YYSYMBOL_32_ = 32,                       /* '^'  */
  YYSYMBOL_33_ = 33,                       /* '&'  */
  YYSYMBOL_34_ = 34,                       /* '|'  */
  YYSYMBOL_35_ = 35,                       /* '+'  */
  YYSYMBOL_36_ = 36,                       /* '-'  */
  YYSYMBOL_37_ = 37,                       /* '*'  */
  YYSYMBOL_38_ = 38,                       /* '/'  */
  YYSYMBOL_39_ = 39,                       /* '%'  */
  YYSYMBOL_40_ = 40,                       /* '~'  */
  YYSYMBOL_41_ = 41,                       /* '!'  */
  YYSYMBOL_42_ = 42,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_program = 44,                   /* program  */
  YYSYMBOL_stmt = 45,                      /* stmt  */
  YYSYMBOL_if = 46,                        /* if  */
  YYSYMBOL_while_cond = 47,                /* while_cond  */
  YYSYMBOL_while_start = 48,               /* while_start  */
  YYSYMBOL_decl = 49,                      /* decl  */
  YYSYMBOL_var_name = 50,                  /* var_name  */
  YYSYMBOL_func_name = 51,                 /* func_name  */
  YYSYMBOL_expr = 52,                      /* expr  */
  YYSYMBOL_constexpr = 53,                 /* constexpr  */
  YYSYMBOL_func_call = 54,                 /* func_call  */
  YYSYMBOL_para_decl = 55,                 /* para_decl  */
  YYSYMBOL_56_1 = 56,                      /* $@1  */
  YYSYMBOL_para_list = 57                  /* para_list  */
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
#define YYLAST   572

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   276


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
       2,     2,     2,    41,     2,     2,     2,    39,    33,     2,
      22,    23,    37,    35,    28,    36,    42,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      30,    29,    31,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    24,     2,    25,    32,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,    34,    27,    40,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    73,    73,    74,    77,    78,    79,    80,    81,    82,
      83,    84,    87,    90,    93,    96,   100,   105,   110,   118,
     128,   134,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   201,   209,   213,   214,   214,   218,   221,   222,   223
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
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "NAME",
  "SEMICOLON", "IF", "WHILE", "RETURN", "VOID", "INT", "FLOAT", "LE", "GE",
  "EQ", "NE", "SHL", "SHR", "AND", "OR", "ARROW", "ELSE", "'('", "')'",
  "'['", "']'", "'{'", "'}'", "','", "'='", "'<'", "'>'", "'^'", "'&'",
  "'|'", "'+'", "'-'", "'*'", "'/'", "'%'", "'~'", "'!'", "'.'", "$accept",
  "program", "stmt", "if", "while_cond", "while_start", "decl", "var_name",
  "func_name", "expr", "constexpr", "func_call", "para_decl", "$@1",
  "para_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-64)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-75)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -64,    55,   -64,   -64,   -13,   -64,    -1,   -64,   157,    22,
      24,   127,   -64,   127,   127,   127,   -64,   149,     8,   -64,
     229,    32,   127,   -64,   264,   -64,    34,    52,    -2,    53,
     327,    63,   -25,   -64,   -64,   -64,   127,   149,   -64,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   355,
     -64,    43,   -64,    99,   127,    43,   -64,   -64,   383,   -64,
     171,   171,   171,   171,   171,   171,   505,   505,   495,   171,
     171,   -19,   -19,   -19,   -25,   -25,   -64,   -64,   -64,   411,
     -18,   -64,   -64,    72,    56,   -64,    99,    99,    99,    99,
     439,   299,    57,   -64,   -64,   127,    50,    58,   467,   -14,
     -64,   -64,    99,    99,    99,    99,    99,    99,    99,    99,
      77,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,   -64,    60,   411,    59,   -64,   -64,   217,   217,   217,
     217,   217,   217,   533,   533,   -64,   217,   217,   145,   145,
     145,   -14,   -14,   -64,   -64,   -64,   -64,    43,   102,   110,
     -64,   -64,   -64
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,    22,    23,    11,     0,    14,     0,     0,
       0,     0,     2,     0,     0,     0,     3,     0,     0,     5,
       0,     0,     0,    10,     0,    21,     0,    20,     0,     0,
       0,     0,    38,    39,    40,     6,     0,     0,     4,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,     0,
       9,    76,    15,     0,     0,    76,    46,     8,     0,     7,
      32,    33,    34,    35,    36,    37,    44,    45,    24,    30,
      31,    43,    41,    42,    25,    26,    27,    28,    29,    77,
       0,    12,    73,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,    13,    47,     0,    72,     0,     0,    62,
      63,    64,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,     0,    78,     0,     2,    70,    56,    57,    58,
      59,    60,    61,    68,    69,    17,    54,    55,    67,    65,
      66,    49,    50,    51,    52,    53,     2,    76,     0,     0,
      75,    18,    19
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -64,   -12,    -6,   -64,   -64,   -64,   -64,   -64,    73,    -7,
     103,   -64,   -63,   -64,   -64
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    16,    17,    37,    18,    19,    28,    26,    20,
     100,    21,    94,   134,    90
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,    24,   102,    62,    30,   104,    32,    33,    34,   -71,
     105,    35,    55,    56,    57,    59,    53,    54,    55,    56,
      57,    22,    63,   128,   129,   130,    25,    64,    27,    68,
      36,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    92,    93,    58,     2,    61,   101,     3,     4,
       5,     6,     7,     8,     9,    10,     3,     4,     5,     6,
       7,     8,     9,    10,   -21,    65,   106,    11,   -74,   107,
     132,    12,   145,    29,   135,    11,   156,   157,     0,    12,
      67,    13,     0,     0,   160,    14,    15,     0,   133,    13,
       0,     0,    95,    14,    15,     3,     4,     5,     6,     7,
       8,     9,    10,     3,     4,     5,     6,     7,     8,     9,
      10,    96,     0,   158,    11,     0,     0,     0,    12,   161,
       3,     4,    11,     0,     0,    97,    12,   162,    13,    98,
      99,     0,    14,    15,   159,     0,    13,     0,     0,    11,
      14,    15,     3,     4,     5,     6,     7,     8,     9,    10,
       3,     4,    23,    13,     0,     0,     0,    14,    15,     0,
       0,    11,     0,     0,     0,    12,     0,     0,     0,    11,
     126,   127,   128,   129,   130,    13,     0,     0,     0,    14,
      15,     0,     0,    13,     0,     0,     0,    14,    15,   108,
     109,   110,   111,    50,    51,    52,    53,    54,    55,    56,
      57,     0,     0,     0,     0,   137,   138,   139,   140,   141,
     142,   143,   144,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    38,     0,     0,     0,     0,     0,
       0,    39,    40,    41,    42,    43,    44,    45,    46,   123,
     124,   125,   126,   127,   128,   129,   130,     0,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    60,
       0,     0,     0,     0,     0,     0,    39,    40,    41,    42,
      43,    44,    45,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,   131,     0,     0,     0,     0,     0,
       0,    39,    40,    41,    42,    43,    44,    45,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    39,
      40,    41,    42,    43,    44,    45,    46,     0,     0,     0,
      66,     0,     0,     0,     0,     0,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    39,    40,    41,
      42,    43,    44,    45,    46,     0,     0,     0,    91,     0,
       0,     0,     0,     0,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    39,    40,    41,    42,    43,
      44,    45,    46,     0,     0,     0,   103,     0,     0,     0,
       0,     0,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    39,    40,    41,    42,    43,    44,    45,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,   112,   113,   114,   115,   116,   117,   118,   119,     0,
       0,     0,     0,     0,   120,     0,     0,     0,     0,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   112,
     113,   114,   115,   116,   117,   118,   119,     0,     0,     0,
     136,     0,     0,     0,     0,     0,     0,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,    39,    40,    41,
      42,    43,    44,    45,    46,     0,     0,    39,    40,    41,
      42,    43,    44,     0,     0,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,   112,   113,   114,   115,   116,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130
};

static const yytype_int16 yycheck[] =
{
      12,     8,    65,     5,    11,    23,    13,    14,    15,    22,
      28,    17,    37,    38,    39,    22,    35,    36,    37,    38,
      39,    22,    24,    37,    38,    39,     4,    29,     4,    36,
      22,    37,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,     9,    10,    22,     0,    22,    64,     3,     4,
       5,     6,     7,     8,     9,    10,     3,     4,     5,     6,
       7,     8,     9,    10,    22,    22,     4,    22,    28,    23,
      23,    26,     5,    10,    26,    22,    26,    28,    -1,    26,
      27,    36,    -1,    -1,   157,    40,    41,    -1,   105,    36,
      -1,    -1,     3,    40,    41,     3,     4,     5,     6,     7,
       8,     9,    10,     3,     4,     5,     6,     7,     8,     9,
      10,    22,    -1,   135,    22,    -1,    -1,    -1,    26,    27,
       3,     4,    22,    -1,    -1,    36,    26,    27,    36,    40,
      41,    -1,    40,    41,   156,    -1,    36,    -1,    -1,    22,
      40,    41,     3,     4,     5,     6,     7,     8,     9,    10,
       3,     4,     5,    36,    -1,    -1,    -1,    40,    41,    -1,
      -1,    22,    -1,    -1,    -1,    26,    -1,    -1,    -1,    22,
      35,    36,    37,    38,    39,    36,    -1,    -1,    -1,    40,
      41,    -1,    -1,    36,    -1,    -1,    -1,    40,    41,    96,
      97,    98,    99,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,   118,   119,    -1,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    -1,    12,    13,    14,
      15,    16,    17,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    12,    13,    14,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    44,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    22,    26,    36,    40,    41,    45,    46,    48,    49,
      52,    54,    22,     5,    52,     4,    51,     4,    50,    51,
      52,    44,    52,    52,    52,    45,    22,    47,     5,    12,
      13,    14,    15,    16,    17,    18,    19,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    22,    52,
       5,    22,     5,    24,    29,    22,    23,    27,    52,    45,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      57,    23,     9,    10,    55,     3,    22,    36,    40,    41,
      53,    52,    55,    23,    23,    28,     4,    23,    53,    53,
      53,    53,    12,    13,    14,    15,    16,    17,    18,    19,
      25,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,     5,    23,    52,    56,    26,    23,    53,    53,    53,
      53,    53,    53,    53,    53,     5,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    26,    28,    44,    44,
      55,    27,    27
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    44,    45,    45,    45,    45,    45,    45,
      45,    45,    46,    47,    48,    49,    49,    49,    49,    49,
      50,    51,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    54,    55,    55,    56,    55,    55,    57,    57,    57
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     2,     3,     3,     3,
       2,     1,     4,     3,     1,     3,     5,     6,     8,     8,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     4,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     1,     2,     1,     0,     5,     0,     1,     3,     0
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
  case 4: /* stmt: expr SEMICOLON  */
#line 77 "parse.y"
                   {}
#line 1318 "parse.tab.c"
    break;

  case 5: /* stmt: decl  */
#line 78 "parse.y"
           {}
#line 1324 "parse.tab.c"
    break;

  case 6: /* stmt: if stmt  */
#line 79 "parse.y"
              { f_stack[f_top]->f->code[(yyvsp[-1].num)].op2 = f_stack[f_top]->f->code_num; }
#line 1330 "parse.tab.c"
    break;

  case 7: /* stmt: while_start while_cond stmt  */
#line 80 "parse.y"
                                  { ir_func_add_code(f_stack[f_top]->f, ir_new(IR_JMP, (yyvsp[-2].num), 0, 0)); f_stack[f_top]->f->code[(yyvsp[-1].num)].op2 = f_stack[f_top]->f->code_num; }
#line 1336 "parse.tab.c"
    break;

  case 8: /* stmt: '{' program '}'  */
#line 81 "parse.y"
                      {}
#line 1342 "parse.tab.c"
    break;

  case 9: /* stmt: RETURN expr SEMICOLON  */
#line 82 "parse.y"
                            { ir_func_add_code(f_stack[f_top]->f, ir_new(IR_RET, (yyvsp[-1].value).ival, 0, 0)); }
#line 1348 "parse.tab.c"
    break;

  case 10: /* stmt: RETURN SEMICOLON  */
#line 83 "parse.y"
                       { ir_func_add_code(f_stack[f_top]->f, ir_new(IR_RET, 0, 0, 0)); }
#line 1354 "parse.tab.c"
    break;

  case 11: /* stmt: SEMICOLON  */
#line 84 "parse.y"
                {}
#line 1360 "parse.tab.c"
    break;

  case 12: /* if: IF '(' expr ')'  */
#line 87 "parse.y"
                    { (yyval.num) = f_stack[f_top]->f->code_num; ir_func_add_code(f_stack[f_top]->f, ir_new(IR_JMPNOT, (yyvsp[-1].value).ival, 0, 0)); }
#line 1366 "parse.tab.c"
    break;

  case 13: /* while_cond: '(' expr ')'  */
#line 90 "parse.y"
                 { (yyval.num) = ir_func_add_code(f_stack[f_top]->f, ir_new(IR_JMPNOT, (yyvsp[-1].value).ival, 0, 0)); }
#line 1372 "parse.tab.c"
    break;

  case 14: /* while_start: WHILE  */
#line 93 "parse.y"
          { (yyval.num) = f_stack[f_top]->f->code_num; }
#line 1378 "parse.tab.c"
    break;

  case 15: /* decl: INT var_name SEMICOLON  */
#line 96 "parse.y"
                           {
        ir_func_ctx_add_local(f_stack[f_top], (yyvsp[-1].name), 1);
        free((yyvsp[-1].name));
    }
#line 1387 "parse.tab.c"
    break;

  case 16: /* decl: INT var_name '=' expr SEMICOLON  */
#line 100 "parse.y"
                                      {
        int id = ir_func_ctx_add_local(f_stack[f_top], (yyvsp[-3].name), 1);
        free((yyvsp[-3].name));
        ir_func_add_code(f_stack[f_top]->f, ir_new(IR_MOV, id, (yyvsp[-1].value).ival, 0));
    }
#line 1397 "parse.tab.c"
    break;

  case 17: /* decl: INT var_name '[' constexpr ']' SEMICOLON  */
#line 105 "parse.y"
                                               {
        long long length = (yyvsp[-2].num);
        ir_func_ctx_add_local(f_stack[f_top], (yyvsp[-4].name), length);
        free((yyvsp[-4].name));
    }
#line 1407 "parse.tab.c"
    break;

  case 18: /* decl: VOID func_name '(' para_decl ')' '{' program '}'  */
#line 110 "parse.y"
                                                       {
        printf("Function End %s\n", f_stack[f_top]->f->name);
        if (f_stack[f_top]->f->code[f_stack[f_top]->f->code_num - 1].ins != IR_RET){
            ir_func_add_code(f_stack[f_top]->f, ir_new(IR_ASSIGN, 0, 0, 0));
            ir_func_add_code(f_stack[f_top]->f, ir_new(IR_RET, 0, 0, 0));
        }
        ir_func_ctx_free(f_stack[f_top--]);
    }
#line 1420 "parse.tab.c"
    break;

  case 19: /* decl: INT func_name '(' para_decl ')' '{' program '}'  */
#line 118 "parse.y"
                                                      {
        printf("Function End %s\n", f_stack[f_top]->f->name);
        if (f_stack[f_top]->f->code[f_stack[f_top]->f->code_num - 1].ins != IR_RET){
            ir_func_add_code(f_stack[f_top]->f, ir_new(IR_ASSIGN, 0, 0, 0));
            ir_func_add_code(f_stack[f_top]->f, ir_new(IR_RET, 0, 0, 0));
        }
        ir_func_ctx_free(f_stack[f_top--]);
    }
#line 1433 "parse.tab.c"
    break;

  case 20: /* var_name: NAME  */
#line 128 "parse.y"
         {
        printf("Declaration: %s\n", name);
        (yyval.name) = strdup(name);
    }
#line 1442 "parse.tab.c"
    break;

  case 21: /* func_name: NAME  */
#line 134 "parse.y"
         {
        printf("Function: %s\n", name);
        f_stack[++f_top] = ir_func_ctx_new(ir_func_new(name, 0));
        ir_program_add_func(program, f_stack[f_top]->f);
    }
#line 1452 "parse.tab.c"
    break;

  case 22: /* expr: NUMBER  */
#line 141 "parse.y"
           { (yyval.value).ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_ASSIGN, (yyval.value).ival, num, 0)); }
#line 1458 "parse.tab.c"
    break;

  case 23: /* expr: NAME  */
#line 142 "parse.y"
           { (yyval.value).ival = ir_func_ctx_get_local(f_stack[f_top], name); }
#line 1464 "parse.tab.c"
    break;

  case 24: /* expr: expr '=' expr  */
#line 143 "parse.y"
                    { ir_func_add_code(f_stack[f_top]->f, ir_new(IR_MOV, (yyvsp[-2].value).ival, (yyvsp[0].value).ival, 0)); }
#line 1470 "parse.tab.c"
    break;

  case 25: /* expr: expr '+' expr  */
#line 144 "parse.y"
                    { (yyval.value).ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_ADD, (yyval.value).ival, (yyvsp[-2].value).ival, (yyvsp[0].value).ival)); }
#line 1476 "parse.tab.c"
    break;

  case 26: /* expr: expr '-' expr  */
#line 145 "parse.y"
                    { (yyval.value).ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_SUB, (yyval.value).ival, (yyvsp[-2].value).ival, (yyvsp[0].value).ival)); }
#line 1482 "parse.tab.c"
    break;

  case 27: /* expr: expr '*' expr  */
#line 146 "parse.y"
                    { (yyval.value).ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_MUL, (yyval.value).ival, (yyvsp[-2].value).ival, (yyvsp[0].value).ival)); }
#line 1488 "parse.tab.c"
    break;

  case 28: /* expr: expr '/' expr  */
#line 147 "parse.y"
                    { (yyval.value).ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_DIV, (yyval.value).ival, (yyvsp[-2].value).ival, (yyvsp[0].value).ival)); }
#line 1494 "parse.tab.c"
    break;

  case 29: /* expr: expr '%' expr  */
#line 148 "parse.y"
                    { (yyval.value).ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_MOD, (yyval.value).ival, (yyvsp[-2].value).ival, (yyvsp[0].value).ival)); }
#line 1500 "parse.tab.c"
    break;

  case 30: /* expr: expr '<' expr  */
#line 149 "parse.y"
                    { (yyval.value).ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_LT, (yyval.value).ival, (yyvsp[-2].value).ival, (yyvsp[0].value).ival)); }
#line 1506 "parse.tab.c"
    break;

  case 31: /* expr: expr '>' expr  */
#line 150 "parse.y"
                    { (yyval.value).ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_GT, (yyval.value).ival, (yyvsp[-2].value).ival, (yyvsp[0].value).ival)); }
#line 1512 "parse.tab.c"
    break;

  case 32: /* expr: expr LE expr  */
#line 151 "parse.y"
                   { (yyval.value).ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_LE, (yyval.value).ival, (yyvsp[-2].value).ival, (yyvsp[0].value).ival)); }
#line 1518 "parse.tab.c"
    break;

  case 33: /* expr: expr GE expr  */
#line 152 "parse.y"
                   { (yyval.value).ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_GE, (yyval.value).ival, (yyvsp[-2].value).ival, (yyvsp[0].value).ival)); }
#line 1524 "parse.tab.c"
    break;

  case 34: /* expr: expr EQ expr  */
#line 153 "parse.y"
                   { (yyval.value).ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_EQ, (yyval.value).ival, (yyvsp[-2].value).ival, (yyvsp[0].value).ival)); }
#line 1530 "parse.tab.c"
    break;

  case 35: /* expr: expr NE expr  */
#line 154 "parse.y"
                   { (yyval.value).ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_NE, (yyval.value).ival, (yyvsp[-2].value).ival, (yyvsp[0].value).ival)); }
#line 1536 "parse.tab.c"
    break;

  case 36: /* expr: expr SHL expr  */
#line 155 "parse.y"
                    { (yyval.value).ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_SHL, (yyval.value).ival, (yyvsp[-2].value).ival, (yyvsp[0].value).ival)); }
#line 1542 "parse.tab.c"
    break;

  case 37: /* expr: expr SHR expr  */
#line 156 "parse.y"
                    { (yyval.value).ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_SHR, (yyval.value).ival, (yyvsp[-2].value).ival, (yyvsp[0].value).ival)); }
#line 1548 "parse.tab.c"
    break;

  case 38: /* expr: '-' expr  */
#line 157 "parse.y"
               { (yyval.value).ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_NEG, (yyval.value).ival, (yyvsp[0].value).ival, 0)); }
#line 1554 "parse.tab.c"
    break;

  case 39: /* expr: '~' expr  */
#line 158 "parse.y"
               { (yyval.value).ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_NOT, (yyval.value).ival, (yyvsp[0].value).ival, 0)); }
#line 1560 "parse.tab.c"
    break;

  case 40: /* expr: '!' expr  */
#line 159 "parse.y"
               { (yyval.value).ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_LOGIC_NOT, (yyval.value).ival, (yyvsp[0].value).ival, 0)); }
#line 1566 "parse.tab.c"
    break;

  case 41: /* expr: expr '&' expr  */
#line 160 "parse.y"
                    { (yyval.value).ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_AND, (yyval.value).ival, (yyvsp[-2].value).ival, (yyvsp[0].value).ival)); }
#line 1572 "parse.tab.c"
    break;

  case 42: /* expr: expr '|' expr  */
#line 161 "parse.y"
                    { (yyval.value).ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_OR, (yyval.value).ival, (yyvsp[-2].value).ival, (yyvsp[0].value).ival)); }
#line 1578 "parse.tab.c"
    break;

  case 43: /* expr: expr '^' expr  */
#line 162 "parse.y"
                    { (yyval.value).ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_XOR, (yyval.value).ival, (yyvsp[-2].value).ival, (yyvsp[0].value).ival)); }
#line 1584 "parse.tab.c"
    break;

  case 44: /* expr: expr AND expr  */
#line 163 "parse.y"
                    { (yyval.value).ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_LOGIC_AND, (yyval.value).ival, (yyvsp[-2].value).ival, (yyvsp[0].value).ival)); }
#line 1590 "parse.tab.c"
    break;

  case 45: /* expr: expr OR expr  */
#line 164 "parse.y"
                   { (yyval.value).ival = ir_func_ctx_inc_local(f_stack[f_top]); ir_func_add_code(f_stack[f_top]->f, ir_new(IR_LOGIC_OR, (yyval.value).ival, (yyvsp[-2].value).ival, (yyvsp[0].value).ival)); }
#line 1596 "parse.tab.c"
    break;

  case 46: /* expr: '(' expr ')'  */
#line 165 "parse.y"
                   { (yyval.value).ival = (yyvsp[-1].value).ival; }
#line 1602 "parse.tab.c"
    break;

  case 47: /* expr: func_call '(' para_list ')'  */
#line 166 "parse.y"
                                  {
        int id = ir_func_ctx_inc_local(f_stack[f_top]);
        ir i = ir_new(IR_CALL, id, 0, 0);
        i.op = f_stack[f_top]->f->code[(yyvsp[-3].num)].op;
        f_stack[f_top]->f->code[(yyvsp[-3].num)].op = NULL;
        ir_func_add_code(f_stack[f_top]->f, i);
        (yyval.value).ival = id;
    }
#line 1615 "parse.tab.c"
    break;

  case 48: /* constexpr: NUMBER  */
#line 176 "parse.y"
           { (yyval.num) = num; }
#line 1621 "parse.tab.c"
    break;

  case 49: /* constexpr: constexpr '+' constexpr  */
#line 177 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) + (yyvsp[0].num); }
#line 1627 "parse.tab.c"
    break;

  case 50: /* constexpr: constexpr '-' constexpr  */
#line 178 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) - (yyvsp[0].num); }
#line 1633 "parse.tab.c"
    break;

  case 51: /* constexpr: constexpr '*' constexpr  */
#line 179 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) * (yyvsp[0].num); }
#line 1639 "parse.tab.c"
    break;

  case 52: /* constexpr: constexpr '/' constexpr  */
#line 180 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) / (yyvsp[0].num); }
#line 1645 "parse.tab.c"
    break;

  case 53: /* constexpr: constexpr '%' constexpr  */
#line 181 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) % (yyvsp[0].num); }
#line 1651 "parse.tab.c"
    break;

  case 54: /* constexpr: constexpr '<' constexpr  */
#line 182 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) < (yyvsp[0].num); }
#line 1657 "parse.tab.c"
    break;

  case 55: /* constexpr: constexpr '>' constexpr  */
#line 183 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) > (yyvsp[0].num); }
#line 1663 "parse.tab.c"
    break;

  case 56: /* constexpr: constexpr LE constexpr  */
#line 184 "parse.y"
                             { (yyval.num) = (yyvsp[-2].num) <= (yyvsp[0].num); }
#line 1669 "parse.tab.c"
    break;

  case 57: /* constexpr: constexpr GE constexpr  */
#line 185 "parse.y"
                             { (yyval.num) = (yyvsp[-2].num) >= (yyvsp[0].num); }
#line 1675 "parse.tab.c"
    break;

  case 58: /* constexpr: constexpr EQ constexpr  */
#line 186 "parse.y"
                             { (yyval.num) = (yyvsp[-2].num) == (yyvsp[0].num); }
#line 1681 "parse.tab.c"
    break;

  case 59: /* constexpr: constexpr NE constexpr  */
#line 187 "parse.y"
                             { (yyval.num) = (yyvsp[-2].num) != (yyvsp[0].num); }
#line 1687 "parse.tab.c"
    break;

  case 60: /* constexpr: constexpr SHL constexpr  */
#line 188 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) << (yyvsp[0].num); }
#line 1693 "parse.tab.c"
    break;

  case 61: /* constexpr: constexpr SHR constexpr  */
#line 189 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) >> (yyvsp[0].num); }
#line 1699 "parse.tab.c"
    break;

  case 62: /* constexpr: '-' constexpr  */
#line 190 "parse.y"
                    { (yyval.num) = -(yyvsp[0].num); }
#line 1705 "parse.tab.c"
    break;

  case 63: /* constexpr: '~' constexpr  */
#line 191 "parse.y"
                    { (yyval.num) = ~(yyvsp[0].num); }
#line 1711 "parse.tab.c"
    break;

  case 64: /* constexpr: '!' constexpr  */
#line 192 "parse.y"
                    { (yyval.num) = !(yyvsp[0].num); }
#line 1717 "parse.tab.c"
    break;

  case 65: /* constexpr: constexpr '&' constexpr  */
#line 193 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) & (yyvsp[0].num); }
#line 1723 "parse.tab.c"
    break;

  case 66: /* constexpr: constexpr '|' constexpr  */
#line 194 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) | (yyvsp[0].num); }
#line 1729 "parse.tab.c"
    break;

  case 67: /* constexpr: constexpr '^' constexpr  */
#line 195 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) ^ (yyvsp[0].num); }
#line 1735 "parse.tab.c"
    break;

  case 68: /* constexpr: constexpr AND constexpr  */
#line 196 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) && (yyvsp[0].num); }
#line 1741 "parse.tab.c"
    break;

  case 69: /* constexpr: constexpr OR constexpr  */
#line 197 "parse.y"
                             { (yyval.num) = (yyvsp[-2].num) || (yyvsp[0].num); }
#line 1747 "parse.tab.c"
    break;

  case 70: /* constexpr: '(' constexpr ')'  */
#line 198 "parse.y"
                        { (yyval.num) = (yyvsp[-1].num); }
#line 1753 "parse.tab.c"
    break;

  case 71: /* func_call: NAME  */
#line 201 "parse.y"
         {
        printf("Function Call: %s\n", name);
        ir i = ir_new(IR_PARAM, 0, 0, 0);
        i.op = strdup(name);
        (yyval.num) = ir_func_add_code(f_stack[f_top]->f, i);
    }
#line 1764 "parse.tab.c"
    break;

  case 72: /* para_decl: INT NAME  */
#line 209 "parse.y"
             {
        printf("Parameter Declare: %s\n", name);
        ir_func_ctx_add_local(f_stack[f_top], name, 1);
    }
#line 1773 "parse.tab.c"
    break;

  case 74: /* $@1: %empty  */
#line 214 "parse.y"
               {
        printf("Parameter Declare: %s\n", name);
        ir_func_ctx_add_local(f_stack[f_top], name, 1);
    }
#line 1782 "parse.tab.c"
    break;

  case 76: /* para_decl: %empty  */
#line 218 "parse.y"
      {}
#line 1788 "parse.tab.c"
    break;

  case 77: /* para_list: expr  */
#line 221 "parse.y"
         { ir_func_add_code(f_stack[f_top]->f, ir_new(IR_PASS, (yyvsp[0].value).ival, 0, 0)); }
#line 1794 "parse.tab.c"
    break;

  case 78: /* para_list: para_list ',' expr  */
#line 222 "parse.y"
                         { ir_func_add_code(f_stack[f_top]->f, ir_new(IR_PASS, (yyvsp[0].value).ival, 0, 0)); }
#line 1800 "parse.tab.c"
    break;

  case 79: /* para_list: %empty  */
#line 223 "parse.y"
      {}
#line 1806 "parse.tab.c"
    break;


#line 1810 "parse.tab.c"

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

#line 225 "parse.y"


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
