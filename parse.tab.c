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
    NUMBER = 258,                  /* NUMBER  */
    NAME = 259,                    /* NAME  */
    IF = 260,                      /* IF  */
    WHILE = 261,                   /* WHILE  */
    RETURN = 262,                  /* RETURN  */
    VOID = 263,                    /* VOID  */
    INT = 264,                     /* INT  */
    FLOAT = 265,                   /* FLOAT  */
    LE = 266,                      /* LE  */
    GE = 267,                      /* GE  */
    EQ = 268,                      /* EQ  */
    NE = 269,                      /* NE  */
    SHL = 270,                     /* SHL  */
    SHR = 271,                     /* SHR  */
    AND = 272,                     /* AND  */
    OR = 273,                      /* OR  */
    ARROW = 274,                   /* ARROW  */
    ELSE = 275                     /* ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 61 "parse.y"

    long long num;
    char* name;
    expr_info value;

#line 168 "parse.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



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
  YYSYMBOL_LE = 11,                        /* LE  */
  YYSYMBOL_GE = 12,                        /* GE  */
  YYSYMBOL_EQ = 13,                        /* EQ  */
  YYSYMBOL_NE = 14,                        /* NE  */
  YYSYMBOL_SHL = 15,                       /* SHL  */
  YYSYMBOL_SHR = 16,                       /* SHR  */
  YYSYMBOL_AND = 17,                       /* AND  */
  YYSYMBOL_OR = 18,                        /* OR  */
  YYSYMBOL_ARROW = 19,                     /* ARROW  */
  YYSYMBOL_20_ = 20,                       /* ';'  */
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
  YYSYMBOL_type_name = 55,                 /* type_name  */
  YYSYMBOL_var_decl = 56,                  /* var_decl  */
  YYSYMBOL_func_decl = 57,                 /* func_decl  */
  YYSYMBOL_para_decl = 58,                 /* para_decl  */
  YYSYMBOL_59_1 = 59,                      /* $@1  */
  YYSYMBOL_para_list = 60                  /* para_list  */
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
#define YYLAST   626

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   275


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,    20,
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
      15,    16,    17,    18,    19,    21
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    73,    73,    74,    77,    78,    79,    80,    81,    82,
      83,    84,    87,    90,    93,    96,    97,   100,   106,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   175,   183,   184,   185,   188,   192,   197,   203,   211,
     215,   216,   216,   220,   223,   224,   225
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
  "WHILE", "RETURN", "VOID", "INT", "FLOAT", "LE", "GE", "EQ", "NE", "SHL",
  "SHR", "AND", "OR", "ARROW", "';'", "ELSE", "'('", "')'", "'['", "']'",
  "'{'", "'}'", "','", "'='", "'<'", "'>'", "'^'", "'&'", "'|'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'~'", "'!'", "'.'", "$accept", "program",
  "stmt", "if", "while_cond", "while_start", "decl", "var_name",
  "func_name", "expr", "constexpr", "func_call", "type_name", "var_decl",
  "func_decl", "para_decl", "$@1", "para_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-96)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-82)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -96,    65,   -96,   -96,   -19,   -16,   -96,   182,   -96,   -96,
     -96,   191,   -96,   191,   191,   191,   191,   191,   -96,   156,
     -10,   -96,   255,    -4,    21,   -96,   -96,   191,   -96,   284,
     313,   104,    -8,    25,   -96,   -96,   -96,   -96,   191,   156,
     191,   191,   191,   191,   191,   191,   191,   191,   -96,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,    -2,   -96,    -7,    11,   342,   -96,   -96,   -96,
     371,   -96,    43,    43,    43,    43,    43,    43,   558,   558,
     400,   487,    43,    43,    -8,    -8,    -8,    25,    25,   -96,
     -96,   -96,   458,    -9,   -96,    20,   191,     7,   -96,   -96,
     -96,   -96,   191,   -96,    20,    20,    20,    20,   516,   429,
      34,    22,    60,   458,   545,    55,   -96,   -96,    20,    20,
      20,    20,    20,    20,    20,    20,    46,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,   -96,    56,    62,
     -96,    82,    82,    82,    82,    82,    82,   587,   587,   -96,
      82,    82,    97,    97,    97,    55,    55,   -96,   -96,   -96,
      58,   -96,     7,   147,   -96,   -96
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,    19,    20,     0,    14,     0,    74,    72,
      11,     0,     2,     0,     0,     0,     0,     0,     3,     0,
       0,     5,     0,     0,     0,    15,    16,     0,    10,     0,
       0,     0,    44,    35,    45,    36,    37,     6,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     4,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    17,    73,     0,     0,     0,     9,    43,     8,
       0,     7,    29,    30,    31,    32,    33,    34,    41,    42,
       0,    21,    27,    28,    40,    38,    39,    22,    23,    24,
      25,    26,    84,     0,    75,     0,     0,    83,    12,    13,
      46,    47,     0,    48,     0,     0,     0,     0,     0,     0,
      74,     0,     0,    85,     0,    62,    63,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    79,     0,
      70,    56,    57,    58,    59,    60,    61,    68,    69,    77,
      54,    55,    67,    65,    66,    49,    50,    51,    52,    53,
       0,     2,    83,     0,    82,    78
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -96,   -12,   -15,   -96,   -96,   -96,   -96,   -96,   -96,    -6,
     129,   -96,   -95,   -96,   -96,   -73,   -96,   -96
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    18,    19,    39,    20,    21,    64,    65,    22,
     108,    23,    24,    25,    26,   112,   160,    93
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,    29,   111,   -71,    37,    30,    27,    32,    33,    34,
      35,    36,    38,    94,   101,   110,     9,    95,    61,   102,
     -18,    66,    96,   103,    71,    62,   138,    56,    57,    58,
      59,    60,    70,    97,    72,    73,    74,    75,    76,    77,
      78,    79,   104,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,   105,   -80,    63,    63,
     106,   107,    58,    59,    60,     2,   149,   111,     3,     4,
       5,     6,     7,     8,     9,    53,    54,    55,    56,    57,
      58,    59,    60,   139,   -81,    10,   162,    11,   161,   164,
     109,    12,   134,   135,   136,     0,   113,     0,    13,     0,
       0,    14,    15,     0,     0,    16,    17,     3,     4,     5,
       6,     7,     8,     9,   129,   130,   131,   132,   133,   134,
     135,   136,     0,     0,    10,     0,    11,     0,     0,     0,
      12,    69,   132,   133,   134,   135,   136,    13,     0,     0,
      14,    15,     0,     0,    16,    17,     0,     0,     0,   163,
       3,     4,     5,     6,     7,     8,     9,     0,     0,     3,
       4,     5,     6,     7,     8,     9,     0,    10,     0,    11,
       0,     0,     0,    12,   165,     0,    10,     0,    11,     0,
      13,     0,    12,    14,    15,     3,     4,    16,    17,    13,
       0,     0,    14,    15,     3,     4,    16,    17,     0,     0,
       0,     0,    28,     0,    11,     0,     0,     0,     0,     0,
       0,     0,     0,    11,     0,    13,     0,     0,    14,    15,
       0,     0,    16,    17,    13,     0,     0,    14,    15,     0,
       0,    16,    17,   114,   115,   116,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   141,   142,   143,
     144,   145,   146,   147,   148,     0,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,    40,    41,    42,    43,
      44,    45,    46,    47,     0,    48,     0,     0,     0,    49,
       0,     0,     0,     0,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    40,    41,    42,    43,    44,
      45,    46,    47,     0,    67,     0,     0,     0,    49,     0,
       0,     0,     0,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    40,    41,    42,    43,    44,    45,
      46,    47,     0,     0,     0,     0,    68,    49,     0,     0,
       0,     0,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    40,    41,    42,    43,    44,    45,    46,
      47,     0,     0,     0,     0,    98,    49,     0,     0,     0,
       0,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    40,    41,    42,    43,    44,    45,    46,    47,
       0,     0,     0,     0,    99,    49,     0,     0,     0,     0,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    40,    41,    42,    43,    44,    45,    46,    47,     0,
       0,     0,     0,     0,    49,   100,     0,     0,     0,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      40,    41,    42,    43,    44,    45,    46,    47,     0,   137,
       0,     0,     0,    49,     0,     0,     0,     0,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    40,
      41,    42,    43,    44,    45,    46,    47,     0,     0,     0,
       0,     0,    49,     0,     0,     0,     0,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    40,    41,
      42,    43,    44,    45,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,   118,   119,   120,
     121,   122,   123,   124,   125,     0,     0,     0,     0,     0,
       0,   126,     0,     0,     0,     0,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   118,   119,   120,   121,
     122,   123,   124,   125,     0,     0,     0,     0,   140,    40,
      41,    42,    43,    44,    45,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,     0,     0,     0,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,   118,   119,
     120,   121,   122,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136
};

static const yytype_int16 yycheck[] =
{
      12,     7,    97,    22,    19,    11,    22,    13,    14,    15,
      16,    17,    22,    20,    23,     8,     9,    24,    22,    28,
      22,    27,    29,     3,    39,     4,     4,    35,    36,    37,
      38,    39,    38,    22,    40,    41,    42,    43,    44,    45,
      46,    47,    22,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    36,    23,    37,    37,
      40,    41,    37,    38,    39,     0,    20,   162,     3,     4,
       5,     6,     7,     8,     9,    32,    33,    34,    35,    36,
      37,    38,    39,    23,    28,    20,    28,    22,    26,   162,
      96,    26,    37,    38,    39,    -1,   102,    -1,    33,    -1,
      -1,    36,    37,    -1,    -1,    40,    41,     3,     4,     5,
       6,     7,     8,     9,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    20,    -1,    22,    -1,    -1,    -1,
      26,    27,    35,    36,    37,    38,    39,    33,    -1,    -1,
      36,    37,    -1,    -1,    40,    41,    -1,    -1,    -1,   161,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    20,    -1,    22,
      -1,    -1,    -1,    26,    27,    -1,    20,    -1,    22,    -1,
      33,    -1,    26,    36,    37,     3,     4,    40,    41,    33,
      -1,    -1,    36,    37,     3,     4,    40,    41,    -1,    -1,
      -1,    -1,    20,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    33,    -1,    -1,    36,    37,
      -1,    -1,    40,    41,    33,    -1,    -1,    36,    37,    -1,
      -1,    40,    41,   104,   105,   106,   107,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    20,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    20,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    23,    24,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    11,    12,    13,    14,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      11,    12,    13,    14,    15,    16,    17,    18,    -1,    20,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    11,
      12,    13,    14,    15,    16,    17,    18,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,    11,
      12,    13,    14,    15,    16,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    44,     0,     3,     4,     5,     6,     7,     8,     9,
      20,    22,    26,    33,    36,    37,    40,    41,    45,    46,
      48,    49,    52,    54,    55,    56,    57,    22,    20,    52,
      52,    44,    52,    52,    52,    52,    52,    45,    22,    47,
      11,    12,    13,    14,    15,    16,    17,    18,    20,    24,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    22,     4,    37,    50,    51,    52,    20,    23,    27,
      52,    45,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    60,    20,    24,    29,    22,    23,    23,
      25,    23,    28,     3,    22,    36,    40,    41,    53,    52,
       8,    55,    58,    52,    53,    53,    53,    53,    11,    12,
      13,    14,    15,    16,    17,    18,    25,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    20,     4,    23,
      23,    53,    53,    53,    53,    53,    53,    53,    53,    20,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      59,    26,    28,    44,    58,    27
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    44,    45,    45,    45,    45,    45,    45,
      45,    45,    46,    47,    48,    49,    49,    50,    51,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    54,    55,    55,    55,    56,    56,    56,    57,    58,
      58,    59,    58,    58,    60,    60,    60
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     2,     3,     3,     3,
       2,     1,     4,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     2,     2,     4,     4,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     1,     1,     2,     1,     3,     5,     6,     8,     2,
       1,     0,     5,     0,     1,     3,     0
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
#line 77 "parse.y"
             {}
#line 1399 "parse.tab.c"
    break;

  case 5: /* stmt: decl  */
#line 78 "parse.y"
           {}
#line 1405 "parse.tab.c"
    break;

  case 6: /* stmt: if stmt  */
#line 79 "parse.y"
              { f_stack[f_top]->f->code[(yyvsp[-1].num)].op1.ival = f_stack[f_top]->f->code_num; }
#line 1411 "parse.tab.c"
    break;

  case 7: /* stmt: while_start while_cond stmt  */
#line 80 "parse.y"
                                  { ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_JMP, (yyvsp[-2].num))); f_stack[f_top]->f->code[(yyvsp[-1].num)].op1.ival = f_stack[f_top]->f->code_num; }
#line 1417 "parse.tab.c"
    break;

  case 8: /* stmt: '{' program '}'  */
#line 81 "parse.y"
                      {}
#line 1423 "parse.tab.c"
    break;

  case 9: /* stmt: RETURN expr ';'  */
#line 82 "parse.y"
                      { ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_RET, (yyvsp[-1].value))); }
#line 1429 "parse.tab.c"
    break;

  case 10: /* stmt: RETURN ';'  */
#line 83 "parse.y"
                 { ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_RET, 0)); }
#line 1435 "parse.tab.c"
    break;

  case 11: /* stmt: ';'  */
#line 84 "parse.y"
          {}
#line 1441 "parse.tab.c"
    break;

  case 12: /* if: IF '(' expr ')'  */
#line 87 "parse.y"
                    { (yyval.num) = f_stack[f_top]->f->code_num; ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_JMPNOT, (yyvsp[-1].value))); }
#line 1447 "parse.tab.c"
    break;

  case 13: /* while_cond: '(' expr ')'  */
#line 90 "parse.y"
                 { (yyval.num) = ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_JMPNOT, (yyvsp[-1].value))); }
#line 1453 "parse.tab.c"
    break;

  case 14: /* while_start: WHILE  */
#line 93 "parse.y"
          { (yyval.num) = f_stack[f_top]->f->code_num; }
#line 1459 "parse.tab.c"
    break;

  case 17: /* var_name: NAME  */
#line 100 "parse.y"
         {
        printf("Declaration: %s\n", name);
        (yyval.name) = strdup(name);
    }
#line 1468 "parse.tab.c"
    break;

  case 18: /* func_name: NAME  */
#line 106 "parse.y"
         {
        printf("Function: %s\n", name);
        f_stack[++f_top] = ir_func_ctx_new(ir_func_new(name, 0));
        ir_program_add_func(program, f_stack[f_top]->f);
    }
#line 1478 "parse.tab.c"
    break;

  case 19: /* expr: NUMBER  */
#line 113 "parse.y"
           { (yyval.value) = ir_expr_imm(num); }
#line 1484 "parse.tab.c"
    break;

  case 20: /* expr: NAME  */
#line 114 "parse.y"
           { (yyval.value) = ir_expr_var(ir_func_ctx_get_local(f_stack[f_top], name)); }
#line 1490 "parse.tab.c"
    break;

  case 21: /* expr: expr '=' expr  */
#line 115 "parse.y"
                    { ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 1496 "parse.tab.c"
    break;

  case 22: /* expr: expr '+' expr  */
#line 116 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_ADD, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1502 "parse.tab.c"
    break;

  case 23: /* expr: expr '-' expr  */
#line 117 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SUB, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1508 "parse.tab.c"
    break;

  case 24: /* expr: expr '*' expr  */
#line 118 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_MUL, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1514 "parse.tab.c"
    break;

  case 25: /* expr: expr '/' expr  */
#line 119 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_DIV, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1520 "parse.tab.c"
    break;

  case 26: /* expr: expr '%' expr  */
#line 120 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_MOD, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1526 "parse.tab.c"
    break;

  case 27: /* expr: expr '<' expr  */
#line 121 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_LT, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1532 "parse.tab.c"
    break;

  case 28: /* expr: expr '>' expr  */
#line 122 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_GT, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1538 "parse.tab.c"
    break;

  case 29: /* expr: expr LE expr  */
#line 123 "parse.y"
                   { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_LE, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1544 "parse.tab.c"
    break;

  case 30: /* expr: expr GE expr  */
#line 124 "parse.y"
                   { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_GE, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1550 "parse.tab.c"
    break;

  case 31: /* expr: expr EQ expr  */
#line 125 "parse.y"
                   { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_EQ, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1556 "parse.tab.c"
    break;

  case 32: /* expr: expr NE expr  */
#line 126 "parse.y"
                   { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_NE, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1562 "parse.tab.c"
    break;

  case 33: /* expr: expr SHL expr  */
#line 127 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SHL, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1568 "parse.tab.c"
    break;

  case 34: /* expr: expr SHR expr  */
#line 128 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SHR, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1574 "parse.tab.c"
    break;

  case 35: /* expr: '-' expr  */
#line 129 "parse.y"
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_NEG, (yyval.value), (yyvsp[0].value))); }
#line 1580 "parse.tab.c"
    break;

  case 36: /* expr: '~' expr  */
#line 130 "parse.y"
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_NOT, (yyval.value), (yyvsp[0].value))); }
#line 1586 "parse.tab.c"
    break;

  case 37: /* expr: '!' expr  */
#line 131 "parse.y"
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_LOGIC_NOT, (yyval.value), (yyvsp[0].value))); }
#line 1592 "parse.tab.c"
    break;

  case 38: /* expr: expr '&' expr  */
#line 132 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_AND, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1598 "parse.tab.c"
    break;

  case 39: /* expr: expr '|' expr  */
#line 133 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_OR, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1604 "parse.tab.c"
    break;

  case 40: /* expr: expr '^' expr  */
#line 134 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_XOR, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1610 "parse.tab.c"
    break;

  case 41: /* expr: expr AND expr  */
#line 135 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_LOGIC_AND, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1616 "parse.tab.c"
    break;

  case 42: /* expr: expr OR expr  */
#line 136 "parse.y"
                   { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_LOGIC_OR, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1622 "parse.tab.c"
    break;

  case 43: /* expr: '(' expr ')'  */
#line 137 "parse.y"
                   { (yyval.value) = (yyvsp[-1].value); }
#line 1628 "parse.tab.c"
    break;

  case 44: /* expr: '&' expr  */
#line 138 "parse.y"
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); if ((yyvsp[0].value).is_imm){ printf("'&' could not be used on an immediate number\n"); exit(1); } ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_ADDR, (yyval.value), (yyvsp[0].value))); }
#line 1634 "parse.tab.c"
    break;

  case 45: /* expr: '*' expr  */
#line 139 "parse.y"
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_DEREF, (yyval.value), (yyvsp[0].value))); }
#line 1640 "parse.tab.c"
    break;

  case 46: /* expr: expr '[' expr ']'  */
#line 140 "parse.y"
                        { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_ADD, (yyval.value), ir_expr_imm((yyvsp[-3].value).ival), (yyvsp[-1].value))); (yyval.value) = ir_expr_ref((yyval.value).ival); }
#line 1646 "parse.tab.c"
    break;

  case 47: /* expr: func_call '(' para_list ')'  */
#line 141 "parse.y"
                                  {
        (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top]));
        ir i = ir_new1(IR_CALL, (yyval.value));
        i.op = f_stack[f_top]->f->code[(yyvsp[-3].num)].op;
        f_stack[f_top]->f->code[(yyvsp[-3].num)].op = NULL;
        ir_func_add_code(f_stack[f_top]->f, i);
    }
#line 1658 "parse.tab.c"
    break;

  case 48: /* constexpr: NUMBER  */
#line 150 "parse.y"
           { (yyval.num) = num; }
#line 1664 "parse.tab.c"
    break;

  case 49: /* constexpr: constexpr '+' constexpr  */
#line 151 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) + (yyvsp[0].num); }
#line 1670 "parse.tab.c"
    break;

  case 50: /* constexpr: constexpr '-' constexpr  */
#line 152 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) - (yyvsp[0].num); }
#line 1676 "parse.tab.c"
    break;

  case 51: /* constexpr: constexpr '*' constexpr  */
#line 153 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) * (yyvsp[0].num); }
#line 1682 "parse.tab.c"
    break;

  case 52: /* constexpr: constexpr '/' constexpr  */
#line 154 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) / (yyvsp[0].num); }
#line 1688 "parse.tab.c"
    break;

  case 53: /* constexpr: constexpr '%' constexpr  */
#line 155 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) % (yyvsp[0].num); }
#line 1694 "parse.tab.c"
    break;

  case 54: /* constexpr: constexpr '<' constexpr  */
#line 156 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) < (yyvsp[0].num); }
#line 1700 "parse.tab.c"
    break;

  case 55: /* constexpr: constexpr '>' constexpr  */
#line 157 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) > (yyvsp[0].num); }
#line 1706 "parse.tab.c"
    break;

  case 56: /* constexpr: constexpr LE constexpr  */
#line 158 "parse.y"
                             { (yyval.num) = (yyvsp[-2].num) <= (yyvsp[0].num); }
#line 1712 "parse.tab.c"
    break;

  case 57: /* constexpr: constexpr GE constexpr  */
#line 159 "parse.y"
                             { (yyval.num) = (yyvsp[-2].num) >= (yyvsp[0].num); }
#line 1718 "parse.tab.c"
    break;

  case 58: /* constexpr: constexpr EQ constexpr  */
#line 160 "parse.y"
                             { (yyval.num) = (yyvsp[-2].num) == (yyvsp[0].num); }
#line 1724 "parse.tab.c"
    break;

  case 59: /* constexpr: constexpr NE constexpr  */
#line 161 "parse.y"
                             { (yyval.num) = (yyvsp[-2].num) != (yyvsp[0].num); }
#line 1730 "parse.tab.c"
    break;

  case 60: /* constexpr: constexpr SHL constexpr  */
#line 162 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) << (yyvsp[0].num); }
#line 1736 "parse.tab.c"
    break;

  case 61: /* constexpr: constexpr SHR constexpr  */
#line 163 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) >> (yyvsp[0].num); }
#line 1742 "parse.tab.c"
    break;

  case 62: /* constexpr: '-' constexpr  */
#line 164 "parse.y"
                    { (yyval.num) = -(yyvsp[0].num); }
#line 1748 "parse.tab.c"
    break;

  case 63: /* constexpr: '~' constexpr  */
#line 165 "parse.y"
                    { (yyval.num) = ~(yyvsp[0].num); }
#line 1754 "parse.tab.c"
    break;

  case 64: /* constexpr: '!' constexpr  */
#line 166 "parse.y"
                    { (yyval.num) = !(yyvsp[0].num); }
#line 1760 "parse.tab.c"
    break;

  case 65: /* constexpr: constexpr '&' constexpr  */
#line 167 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) & (yyvsp[0].num); }
#line 1766 "parse.tab.c"
    break;

  case 66: /* constexpr: constexpr '|' constexpr  */
#line 168 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) | (yyvsp[0].num); }
#line 1772 "parse.tab.c"
    break;

  case 67: /* constexpr: constexpr '^' constexpr  */
#line 169 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) ^ (yyvsp[0].num); }
#line 1778 "parse.tab.c"
    break;

  case 68: /* constexpr: constexpr AND constexpr  */
#line 170 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) && (yyvsp[0].num); }
#line 1784 "parse.tab.c"
    break;

  case 69: /* constexpr: constexpr OR constexpr  */
#line 171 "parse.y"
                             { (yyval.num) = (yyvsp[-2].num) || (yyvsp[0].num); }
#line 1790 "parse.tab.c"
    break;

  case 70: /* constexpr: '(' constexpr ')'  */
#line 172 "parse.y"
                        { (yyval.num) = (yyvsp[-1].num); }
#line 1796 "parse.tab.c"
    break;

  case 71: /* func_call: NAME  */
#line 175 "parse.y"
         {
        printf("Function Call: %s\n", name);
        ir i = ir_new0(IR_PARAM);
        i.op = strdup(name);
        (yyval.num) = ir_func_add_code(f_stack[f_top]->f, i);
    }
#line 1807 "parse.tab.c"
    break;

  case 75: /* var_decl: type_name var_name ';'  */
#line 188 "parse.y"
                           {
        ir_func_ctx_add_local(f_stack[f_top], (yyvsp[-1].name), 1);
        free((yyvsp[-1].name));
    }
#line 1816 "parse.tab.c"
    break;

  case 76: /* var_decl: type_name var_name '=' expr ';'  */
#line 192 "parse.y"
                                      {
        expr_info id = ir_expr_var(ir_func_ctx_add_local(f_stack[f_top], (yyvsp[-3].name), 1));
        free((yyvsp[-3].name));
        ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, id, (yyvsp[-1].value)));
    }
#line 1826 "parse.tab.c"
    break;

  case 77: /* var_decl: type_name var_name '[' constexpr ']' ';'  */
#line 197 "parse.y"
                                               {
        int length = (int)(yyvsp[-2].num);
        ir_func_ctx_add_local(f_stack[f_top], (yyvsp[-4].name), length);
        free((yyvsp[-4].name));
    }
#line 1836 "parse.tab.c"
    break;

  case 78: /* func_decl: type_name func_name '(' para_decl ')' '{' program '}'  */
#line 203 "parse.y"
                                                          {
        printf("Function End %s\n", f_stack[f_top]->f->name);
        if (f_stack[f_top]->f->code[f_stack[f_top]->f->code_num - 1].ins != IR_RET){
            ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_RET, 0));
        }
        ir_func_ctx_free(f_stack[f_top--]);
    }
#line 1848 "parse.tab.c"
    break;

  case 79: /* para_decl: type_name NAME  */
#line 211 "parse.y"
                   {
        printf("Parameter Declare: %s\n", name);
        ir_func_ctx_add_local(f_stack[f_top], name, 1);
    }
#line 1857 "parse.tab.c"
    break;

  case 81: /* $@1: %empty  */
#line 216 "parse.y"
                     {
        printf("Parameter Declare: %s\n", name);
        ir_func_ctx_add_local(f_stack[f_top], name, 1);
    }
#line 1866 "parse.tab.c"
    break;

  case 83: /* para_decl: %empty  */
#line 220 "parse.y"
      {}
#line 1872 "parse.tab.c"
    break;

  case 84: /* para_list: expr  */
#line 223 "parse.y"
         { ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_PASS, (yyvsp[0].value))); }
#line 1878 "parse.tab.c"
    break;

  case 85: /* para_list: para_list ',' expr  */
#line 224 "parse.y"
                         { ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_PASS, (yyvsp[0].value))); }
#line 1884 "parse.tab.c"
    break;

  case 86: /* para_list: %empty  */
#line 225 "parse.y"
      {}
#line 1890 "parse.tab.c"
    break;


#line 1894 "parse.tab.c"

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

#line 227 "parse.y"


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
