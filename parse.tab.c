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
#line 54 "parse.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"

#include "dict.h"
#include "ir.h"
#include "vm.h"
#include "type.h"

int yylex();
void yyerror(char *s);

extern ir_program *program;

extern ir_func_ctx *f_stack[0x40];
extern int f_top;

extern long num;
extern double real;
extern char name[0x400];
extern FILE* yyin;

#line 97 "parse.tab.c"

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
  YYSYMBOL_REAL = 4,                       /* REAL  */
  YYSYMBOL_NAME = 5,                       /* NAME  */
  YYSYMBOL_FNAME = 6,                      /* FNAME  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_FOR = 10,                       /* FOR  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_VOID = 12,                      /* VOID  */
  YYSYMBOL_INT = 13,                       /* INT  */
  YYSYMBOL_FLOAT = 14,                     /* FLOAT  */
  YYSYMBOL_STR = 15,                       /* STR  */
  YYSYMBOL_CHAR = 16,                      /* CHAR  */
  YYSYMBOL_LE = 17,                        /* LE  */
  YYSYMBOL_GE = 18,                        /* GE  */
  YYSYMBOL_EQ = 19,                        /* EQ  */
  YYSYMBOL_NE = 20,                        /* NE  */
  YYSYMBOL_SHL = 21,                       /* SHL  */
  YYSYMBOL_SHR = 22,                       /* SHR  */
  YYSYMBOL_AND = 23,                       /* AND  */
  YYSYMBOL_OR = 24,                        /* OR  */
  YYSYMBOL_ARROW = 25,                     /* ARROW  */
  YYSYMBOL_INC = 26,                       /* INC  */
  YYSYMBOL_DEC = 27,                       /* DEC  */
  YYSYMBOL_ADD_ASSIGN = 28,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 29,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 30,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 31,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 32,                /* MOD_ASSIGN  */
  YYSYMBOL_SHL_ASSIGN = 33,                /* SHL_ASSIGN  */
  YYSYMBOL_SHR_ASSIGN = 34,                /* SHR_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 35,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 36,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 37,                 /* OR_ASSIGN  */
  YYSYMBOL_38_ = 38,                       /* ';'  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_41_ = 41,                       /* '['  */
  YYSYMBOL_42_ = 42,                       /* ']'  */
  YYSYMBOL_43_ = 43,                       /* '{'  */
  YYSYMBOL_44_ = 44,                       /* '}'  */
  YYSYMBOL_45_ = 45,                       /* ','  */
  YYSYMBOL_46_ = 46,                       /* '='  */
  YYSYMBOL_47_ = 47,                       /* '<'  */
  YYSYMBOL_48_ = 48,                       /* '>'  */
  YYSYMBOL_49_ = 49,                       /* '^'  */
  YYSYMBOL_50_ = 50,                       /* '&'  */
  YYSYMBOL_51_ = 51,                       /* '|'  */
  YYSYMBOL_52_ = 52,                       /* '+'  */
  YYSYMBOL_53_ = 53,                       /* '-'  */
  YYSYMBOL_54_ = 54,                       /* '*'  */
  YYSYMBOL_55_ = 55,                       /* '/'  */
  YYSYMBOL_56_ = 56,                       /* '%'  */
  YYSYMBOL_57_ = 57,                       /* '~'  */
  YYSYMBOL_58_ = 58,                       /* '!'  */
  YYSYMBOL_59_ = 59,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_program = 61,                   /* program  */
  YYSYMBOL_stmt = 62,                      /* stmt  */
  YYSYMBOL_stmt_no_if = 63,                /* stmt_no_if  */
  YYSYMBOL_if = 64,                        /* if  */
  YYSYMBOL_else = 65,                      /* else  */
  YYSYMBOL_while_cond = 66,                /* while_cond  */
  YYSYMBOL_while_start = 67,               /* while_start  */
  YYSYMBOL_decl = 68,                      /* decl  */
  YYSYMBOL_var_name = 69,                  /* var_name  */
  YYSYMBOL_func_name = 70,                 /* func_name  */
  YYSYMBOL_expr = 71,                      /* expr  */
  YYSYMBOL_fexpr = 72,                     /* fexpr  */
  YYSYMBOL_constexpr = 73,                 /* constexpr  */
  YYSYMBOL_func_call = 74,                 /* func_call  */
  YYSYMBOL_ffunc_call = 75,                /* ffunc_call  */
  YYSYMBOL_type_name = 76,                 /* type_name  */
  YYSYMBOL_ftype_name = 77,                /* ftype_name  */
  YYSYMBOL_var_decl = 78,                  /* var_decl  */
  YYSYMBOL_func_decl = 79,                 /* func_decl  */
  YYSYMBOL_para_decl = 80,                 /* para_decl  */
  YYSYMBOL_81_1 = 81,                      /* $@1  */
  YYSYMBOL_82_2 = 82,                      /* $@2  */
  YYSYMBOL_para_list = 83                  /* para_list  */
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
typedef yytype_int16 yy_state_t;

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
#define YYLAST   1457

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  153
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  308

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


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
       2,     2,     2,    58,     2,     2,     2,    56,    50,     2,
      39,    40,    54,    52,    45,    53,    59,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
      47,    46,    48,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    41,     2,    42,    49,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,    51,    44,    57,     2,     2,     2,
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
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    94,    94,    95,    98,    99,   100,   101,   104,   108,
     112,   113,   116,   119,   122,   123,   124,   128,   132,   133,
     136,   139,   142,   148,   154,   159,   164,   165,   168,   174,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   233,   234,   237,   238,
     239,   240,   241,   243,   244,   245,   247,   248,   249,   251,
     252,   253,   255,   256,   257,   259,   260,   261,   262,   264,
     265,   266,   268,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   303,   311,   319,
     320,   321,   324,   325,   328,   332,   337,   342,   346,   351,
     357,   365,   369,   370,   370,   374,   378,   378,   382,   385,
     386,   387,   388,   389
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
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "REAL",
  "NAME", "FNAME", "IF", "ELSE", "WHILE", "FOR", "RETURN", "VOID", "INT",
  "FLOAT", "STR", "CHAR", "LE", "GE", "EQ", "NE", "SHL", "SHR", "AND",
  "OR", "ARROW", "INC", "DEC", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN",
  "DIV_ASSIGN", "MOD_ASSIGN", "SHL_ASSIGN", "SHR_ASSIGN", "AND_ASSIGN",
  "XOR_ASSIGN", "OR_ASSIGN", "';'", "'('", "')'", "'['", "']'", "'{'",
  "'}'", "','", "'='", "'<'", "'>'", "'^'", "'&'", "'|'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'~'", "'!'", "'.'", "$accept", "program", "stmt",
  "stmt_no_if", "if", "else", "while_cond", "while_start", "decl",
  "var_name", "func_name", "expr", "fexpr", "constexpr", "func_call",
  "ffunc_call", "type_name", "ftype_name", "var_decl", "func_decl",
  "para_decl", "$@1", "$@2", "para_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-242)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-147)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -242,   240,  -242,  -242,  -242,   -27,   -21,   -10,  -242,   571,
    -242,    -7,  -242,  -242,    43,   617,   617,  -242,   554,  -242,
     554,   554,   554,   554,   617,   617,  -242,   469,    55,  -242,
     659,   406,    70,    86,     1,     4,  -242,  -242,   617,    -7,
    -242,   617,   617,   617,   617,   617,   699,   554,   554,  -242,
    -242,   739,   461,   301,   206,    12,   105,     2,   105,     2,
      27,  -242,  -242,  -242,   600,    30,  -242,  -242,   129,   469,
      55,   131,   779,   617,   525,   617,   617,   617,   617,   617,
     617,   617,   617,  -242,  -242,   617,   617,   617,   617,   617,
     617,   617,   617,   617,   617,  -242,   617,   617,   617,   617,
     617,   617,   617,   554,   554,   554,   554,   617,   554,   554,
     554,   554,  -242,   617,   554,   554,   554,   554,   554,   554,
     107,  -242,   -13,   109,  -242,  -242,   -11,   819,   859,   323,
     137,   137,    27,  -242,   617,   617,   617,   617,  1099,  1366,
    1370,  -242,  -242,  -242,   136,   899,   357,  -242,   525,   129,
     469,   148,   939,  -242,   269,   269,   269,   269,   269,   269,
    1337,  1337,  1139,  1139,  1139,  1139,  1139,  1139,  1139,  1139,
    1139,  1139,   979,  1139,   269,   269,   323,   323,   323,   105,
       2,   105,     2,    27,  -242,    27,  -242,    27,  1255,  1255,
    1255,  1255,  1019,  1179,     2,  1179,     2,  1219,  -242,  1219,
    -242,  1099,  1402,    -9,    -6,  -242,   155,   617,    57,  -242,
     155,   554,  -242,   137,   137,    27,    27,  -242,  -242,   149,
     154,  -242,   469,  -242,  -242,  -242,  -242,  -242,   554,  -242,
    -242,   155,   155,   155,   155,   155,  1240,  1059,    11,  -242,
       5,     6,   125,  1280,  1374,  -242,  1099,  1402,  1297,   115,
     115,  -242,  -242,   155,   155,   155,   155,   155,   155,   155,
     155,   128,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,  -242,   135,   150,   153,   159,  -242,  -242,   219,
     219,   219,   219,   219,   219,  1321,  1321,  -242,   219,   219,
      67,    67,    67,   115,   115,  -242,  -242,  -242,   156,   158,
    -242,  -242,    57,    57,   413,  -242,  -242,  -242
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    30,    78,    32,    79,     0,    25,     0,
     130,   129,   132,    33,    31,     0,     0,    13,     0,     2,
       0,     0,     0,     0,     0,     0,     3,     0,     0,     6,
       0,     0,     0,     0,     0,     0,    26,    27,     0,     0,
      12,     0,     0,     0,     0,     0,     0,     0,     0,    59,
      60,     0,     0,     0,    72,    99,    49,    81,    48,    80,
      73,   100,    50,    51,     0,    13,     2,     7,     0,     0,
       0,     6,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    57,    58,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     5,     0,     0,     0,     0,     0,   153,   153,
      28,   131,     0,     0,    28,   133,     0,     0,     0,    72,
      49,    48,    73,    11,     0,     0,     0,     0,     0,     0,
       0,    71,    82,    10,    12,     0,     0,    23,     0,     0,
       0,     4,     0,     9,    42,    43,    44,    45,    46,    47,
      55,    56,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,     0,    34,    40,    41,    54,    52,    53,    35,
      85,    36,    88,    37,    91,    38,    94,    39,    95,    96,
      97,    98,     0,    84,    83,    87,    86,    90,    89,    93,
      92,   149,   150,     0,     0,   134,     0,     0,   148,   137,
       0,     0,    22,    35,    36,    37,    38,    76,    77,    11,
      10,     8,     0,    17,    24,    74,   101,    75,     0,   102,
     103,     0,     0,     0,     0,     0,     0,     0,   130,   129,
       0,     0,     0,     0,     0,    16,   151,   152,     0,   118,
     117,   119,   120,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   135,   141,   145,     0,     0,   138,   126,   111,
     112,   113,   114,   115,   116,   124,   125,   136,   109,   110,
     123,   121,   122,   104,   105,   106,   107,   108,     0,     0,
       2,   139,   148,   148,     0,   144,   147,   140
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -242,   -18,   -24,   -67,   -23,    56,   134,   -22,   -20,   174,
    -242,    -1,   120,   -81,  -242,  -242,  -195,  -192,  -242,  -242,
    -241,  -242,  -242,    91
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    26,    68,    27,   148,    74,    28,    29,   122,
     123,   138,    31,   236,    32,    33,    34,    35,    36,    37,
     242,   298,   299,   203
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,    53,   149,    67,    69,    70,   120,    71,    46,   124,
     273,   274,  -127,   240,    49,    50,   241,    51,  -128,    54,
      56,    58,    60,    62,    63,   205,    72,   209,   206,    38,
     210,   227,    47,   207,   229,   211,   228,   127,   -21,   228,
     128,   129,   130,   131,   132,    67,    69,    70,   146,    71,
     153,  -142,    30,    83,    84,   121,   116,   117,   125,   121,
     125,   305,   306,   145,   114,   115,   116,   117,    72,   238,
     239,    12,   152,    30,   154,   155,   156,   157,   158,   159,
     160,   161,    48,   223,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    73,   172,   173,   174,   175,   176,
     177,   178,   179,   181,   183,   185,   187,   240,   240,   118,
     241,   241,   192,   193,   195,   197,   199,   201,   201,   267,
     268,   269,   270,   271,   221,   119,   153,    69,    70,   243,
      71,    83,    84,   213,   214,   215,   216,   147,    52,   -15,
      55,    57,    59,    61,   -20,    30,   -29,    30,   208,    72,
     248,   249,   250,   251,   252,   245,   -14,   -19,   230,   105,
     106,   107,   -18,    83,    84,   275,   287,   139,   140,   269,
     270,   271,   279,   280,   281,   282,   283,   284,   285,   286,
    -143,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   136,   137,   107,   231,  -146,   300,   301,   221,    69,
      70,   302,    71,   303,   150,   222,   237,   232,   233,   126,
     204,     0,   234,   235,     0,     0,     0,     0,     0,     0,
       0,    72,     0,   180,   182,   184,   186,   246,   188,   189,
     190,   191,    83,    84,   194,   196,   198,   200,   202,   202,
       2,     0,     0,     3,     4,     5,     6,     7,     0,     8,
       0,     9,    10,    11,    12,    13,    14,     0,   103,   104,
     105,   106,   107,     0,     0,     0,    15,    16,   264,   265,
     266,   267,   268,   269,   270,   271,     0,     0,    17,    18,
       0,     0,   304,    19,     0,     0,     0,     0,     0,     0,
      20,     0,    21,    22,    23,    83,    84,    24,    25,     0,
       0,     0,     0,    30,     3,     4,     5,     6,     7,     0,
       8,     0,     9,    10,    11,    12,    13,    14,   100,   101,
     102,   134,   135,   136,   137,   107,     0,    15,    16,     0,
       0,   244,     0,     0,     0,     0,     0,     0,     0,    17,
      18,     0,     0,     0,    19,   143,     0,     0,   247,    83,
      84,    20,     0,    21,    22,    23,     0,     0,    24,    25,
       3,     4,     5,     6,     7,     0,     8,     0,     9,    10,
      11,    12,    13,    14,     0,   134,   135,   136,   137,   107,
       0,     0,     0,    15,    16,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,    18,     0,     0,     0,
      19,   220,     0,     0,     0,     0,     0,    20,     0,    21,
      22,    23,     0,     0,    24,    25,     3,     4,     5,     6,
       7,     0,     8,     0,     9,    10,    11,    12,    13,    14,
       0,     0,     0,     0,   108,   109,   110,   111,     0,    15,
      16,     0,     0,     0,   112,     0,     0,   113,     0,     0,
       0,    17,    18,     0,     0,     0,    19,   307,   114,   115,
     116,   117,     0,    20,     0,    21,    22,    23,     0,     0,
      24,    25,     3,     4,     5,     6,     7,     0,     8,     0,
      64,    10,    11,    12,    13,    14,     0,     0,     0,   108,
     109,   110,   111,     0,     0,    15,    16,     0,     0,     0,
       0,   142,   113,     0,     0,     0,     0,    65,    18,     0,
       0,     0,    66,   114,   115,   116,   117,     0,     0,    20,
       0,    21,    22,    23,     0,     0,    24,    25,     3,     4,
       5,     6,     7,     0,     8,     0,     9,    10,    11,    12,
      13,    14,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,    16,     0,     0,     0,     0,     3,     4,     5,
       6,     0,     0,    17,    18,     0,     0,    39,    19,    13,
      14,     0,     0,     0,     3,    20,     5,    21,    22,    23,
      15,    16,    24,    25,    39,     0,    13,    14,     0,     0,
       0,     0,     0,    18,     0,     0,     0,    15,    16,     0,
       0,     0,     0,     3,    20,     5,    21,    22,    23,    40,
      41,    24,    25,    39,     0,    13,    14,     0,     0,     0,
       3,    42,     5,    43,    44,    45,    15,    16,    24,    25,
      39,     0,    13,    14,     0,     0,     0,     0,   144,    41,
       0,     0,     0,    15,    16,     0,     0,     0,     0,     0,
      42,     0,    43,    44,    45,     0,    41,    24,    25,     0,
       0,     0,     0,     0,     0,     0,     0,    42,     0,    43,
      44,    45,     0,     0,    24,    25,    75,    76,    77,    78,
      79,    80,    81,    82,     0,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     0,     0,
      96,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,    75,    76,    77,    78,
      79,    80,    81,    82,     0,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,   133,     0,     0,
      96,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   134,   135,   136,   137,   107,    75,    76,    77,    78,
      79,    80,    81,    82,     0,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,     0,     0,   141,
      96,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,    75,    76,    77,    78,
      79,    80,    81,    82,     0,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,   151,     0,     0,
      96,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,    75,    76,    77,    78,
      79,    80,    81,    82,     0,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,     0,     0,   212,
      96,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   134,   135,   136,   137,   107,    75,    76,    77,    78,
      79,    80,    81,    82,     0,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,     0,     0,   141,
      96,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   134,   135,   136,   137,   107,    75,    76,    77,    78,
      79,    80,    81,    82,     0,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,   219,     0,     0,
      96,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   134,   135,   136,   137,   107,    75,    76,    77,    78,
      79,    80,    81,    82,     0,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,     0,     0,   224,
      96,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   134,   135,   136,   137,   107,    75,    76,    77,    78,
      79,    80,    81,    82,     0,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,     0,     0,     0,
      96,   225,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   134,   135,   136,   137,   107,    75,    76,    77,    78,
      79,    80,    81,    82,     0,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,     0,     0,     0,
      96,   226,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   134,   135,   136,   137,   107,    75,    76,    77,    78,
      79,    80,    81,    82,     0,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,   272,     0,     0,
      96,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   134,   135,   136,   137,   107,    75,    76,    77,    78,
      79,    80,    81,    82,     0,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,     0,     0,     0,
      96,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,    75,    76,    77,    78,
      79,    80,    81,    82,     0,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,     0,     0,     0,
       0,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   134,   135,   136,   137,   107,    75,    76,    77,    78,
      79,    80,    81,    82,     0,    83,    84,     0,     0,     0,
       0,    89,    90,    91,    92,    93,    94,     0,     0,     0,
       0,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,     0,     0,   105,   106,   107,    75,    76,    77,    78,
      79,    80,    81,    82,     0,    83,    84,     0,     0,     0,
       0,    89,    90,    91,    92,    93,    94,   253,   254,   255,
     256,   257,   258,   259,   260,    97,    98,    99,   100,   101,
     102,     0,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,   261,   108,   109,   110,   111,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   253,   254,   255,
     256,   257,   258,   259,   260,     0,     0,   114,   115,   116,
     117,     0,     0,     0,   253,   254,   255,   256,   257,   258,
     259,   260,   276,     0,     0,     0,     0,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   278,   253,   254,
     255,   256,   257,   258,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,    75,    76,    77,    78,    79,    80,
       0,     0,     0,    83,    84,     0,     0,     0,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   134,
     135,   136,   137,   107,   108,   109,   110,   111,   108,   109,
     110,   111,   108,   109,   110,   111,   217,   113,     0,     0,
     218,   113,   277,     0,     0,   113,     0,     0,   114,   115,
     116,   117,   114,   115,   116,   117,   114,   115,   116,   117,
     108,   109,   110,   111,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   114,   115,   116,   117
};

static const yytype_int16 yycheck[] =
{
       1,    19,    69,    27,    27,    27,     5,    27,     9,     5,
       5,     5,    39,   208,    15,    16,   208,    18,    39,    20,
      21,    22,    23,    24,    25,    38,    27,    38,    41,    39,
      41,    40,    39,    46,    40,    46,    45,    38,     8,    45,
      41,    42,    43,    44,    45,    69,    69,    69,    66,    69,
      74,    40,    53,    26,    27,    54,    54,    55,    54,    54,
      54,   302,   303,    64,    52,    53,    54,    55,    69,    12,
      13,    14,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    39,   150,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    39,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   302,   303,    39,
     302,   303,   113,   114,   115,   116,   117,   118,   119,    52,
      53,    54,    55,    56,   148,    39,   150,   150,   150,   210,
     150,    26,    27,   134,   135,   136,   137,     8,    18,     8,
      20,    21,    22,    23,     8,   146,    39,   148,    39,   150,
     231,   232,   233,   234,   235,   222,     8,     8,     3,    54,
      55,    56,     8,    26,    27,    40,    38,    47,    48,    54,
      55,    56,   253,   254,   255,   256,   257,   258,   259,   260,
      45,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,    54,    55,    56,    39,    45,    43,    38,   222,   222,
     222,    45,   222,    45,    70,   149,   207,    52,    53,    35,
     119,    -1,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   222,    -1,   103,   104,   105,   106,   228,   108,   109,
     110,   111,    26,    27,   114,   115,   116,   117,   118,   119,
       0,    -1,    -1,     3,     4,     5,     6,     7,    -1,     9,
      -1,    11,    12,    13,    14,    15,    16,    -1,    52,    53,
      54,    55,    56,    -1,    -1,    -1,    26,    27,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    -1,    38,    39,
      -1,    -1,   300,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    -1,    52,    53,    54,    26,    27,    57,    58,    -1,
      -1,    -1,    -1,   304,     3,     4,     5,     6,     7,    -1,
       9,    -1,    11,    12,    13,    14,    15,    16,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    26,    27,    -1,
      -1,   211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    -1,    -1,    -1,    43,    44,    -1,    -1,   228,    26,
      27,    50,    -1,    52,    53,    54,    -1,    -1,    57,    58,
       3,     4,     5,     6,     7,    -1,     9,    -1,    11,    12,
      13,    14,    15,    16,    -1,    52,    53,    54,    55,    56,
      -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    -1,    -1,    50,    -1,    52,
      53,    54,    -1,    -1,    57,    58,     3,     4,     5,     6,
       7,    -1,     9,    -1,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    -1,    26,
      27,    -1,    -1,    -1,    38,    -1,    -1,    41,    -1,    -1,
      -1,    38,    39,    -1,    -1,    -1,    43,    44,    52,    53,
      54,    55,    -1,    50,    -1,    52,    53,    54,    -1,    -1,
      57,    58,     3,     4,     5,     6,     7,    -1,     9,    -1,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    28,
      29,    30,    31,    -1,    -1,    26,    27,    -1,    -1,    -1,
      -1,    40,    41,    -1,    -1,    -1,    -1,    38,    39,    -1,
      -1,    -1,    43,    52,    53,    54,    55,    -1,    -1,    50,
      -1,    52,    53,    54,    -1,    -1,    57,    58,     3,     4,
       5,     6,     7,    -1,     9,    -1,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,    -1,    38,    39,    -1,    -1,    13,    43,    15,
      16,    -1,    -1,    -1,     3,    50,     5,    52,    53,    54,
      26,    27,    57,    58,    13,    -1,    15,    16,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    26,    27,    -1,
      -1,    -1,    -1,     3,    50,     5,    52,    53,    54,    38,
      39,    57,    58,    13,    -1,    15,    16,    -1,    -1,    -1,
       3,    50,     5,    52,    53,    54,    26,    27,    57,    58,
      13,    -1,    15,    16,    -1,    -1,    -1,    -1,    38,    39,
      -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      50,    -1,    52,    53,    54,    -1,    39,    57,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    52,
      53,    54,    -1,    -1,    57,    58,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      41,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      41,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    40,
      41,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      41,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    40,
      41,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    40,
      41,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      41,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    40,
      41,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      41,    42,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      41,    42,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      41,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      41,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    -1,    -1,    54,    55,    56,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    37,    17,    18,    19,
      20,    21,    22,    23,    24,    46,    47,    48,    49,    50,
      51,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    28,    29,    30,    31,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    52,    53,    54,
      55,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      23,    24,    42,    -1,    -1,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    40,    17,    18,
      19,    20,    21,    22,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    28,    29,    30,    31,    28,    29,
      30,    31,    28,    29,    30,    31,    40,    41,    -1,    -1,
      40,    41,    38,    -1,    -1,    41,    -1,    -1,    52,    53,
      54,    55,    52,    53,    54,    55,    52,    53,    54,    55,
      28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    53,    54,    55
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    61,     0,     3,     4,     5,     6,     7,     9,    11,
      12,    13,    14,    15,    16,    26,    27,    38,    39,    43,
      50,    52,    53,    54,    57,    58,    62,    64,    67,    68,
      71,    72,    74,    75,    76,    77,    78,    79,    39,    13,
      38,    39,    50,    52,    53,    54,    71,    39,    39,    71,
      71,    71,    72,    61,    71,    72,    71,    72,    71,    72,
      71,    72,    71,    71,    11,    38,    43,    62,    63,    64,
      67,    68,    71,    39,    66,    17,    18,    19,    20,    21,
      22,    23,    24,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    41,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    28,    29,
      30,    31,    38,    41,    52,    53,    54,    55,    39,    39,
       5,    54,    69,    70,     5,    54,    69,    71,    71,    71,
      71,    71,    71,    38,    52,    53,    54,    55,    71,    72,
      72,    40,    40,    44,    38,    71,    61,     8,    65,    63,
      66,    38,    71,    62,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      72,    71,    72,    71,    72,    71,    72,    71,    72,    72,
      72,    72,    71,    71,    72,    71,    72,    71,    72,    71,
      72,    71,    72,    83,    83,    38,    41,    46,    39,    38,
      41,    46,    40,    71,    71,    71,    71,    40,    40,    38,
      44,    62,    65,    63,    40,    42,    42,    40,    45,    40,
       3,    39,    52,    53,    57,    58,    73,    71,    12,    13,
      76,    77,    80,    73,    72,    63,    71,    72,    73,    73,
      73,    73,    73,    17,    18,    19,    20,    21,    22,    23,
      24,    42,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    38,     5,     5,    40,    42,    38,    40,    73,
      73,    73,    73,    73,    73,    73,    73,    38,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    81,    82,
      43,    38,    45,    45,    61,    80,    80,    44
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    61,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    63,    63,    63,    63,    63,    63,
      63,    63,    64,    65,    66,    67,    68,    68,    69,    70,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    74,    75,    76,
      76,    76,    77,    77,    78,    78,    78,    78,    78,    78,
      79,    80,    80,    81,    80,    80,    82,    80,    80,    83,
      83,    83,    83,    83
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     1,     2,     4,     3,
       3,     3,     2,     1,     2,     1,     4,     3,     3,     3,
       2,     1,     4,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     4,     4,     4,     4,     1,     1,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     4,     4,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     2,     1,     2,     3,     5,     6,     3,     5,     6,
       8,     2,     1,     0,     5,     2,     0,     5,     0,     1,
       1,     3,     3,     0
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
#line 98 "parse.y"
             {}
#line 1596 "parse.tab.c"
    break;

  case 5: /* stmt: fexpr ';'  */
#line 99 "parse.y"
                {}
#line 1602 "parse.tab.c"
    break;

  case 6: /* stmt: decl  */
#line 100 "parse.y"
           {}
#line 1608 "parse.tab.c"
    break;

  case 7: /* stmt: if stmt  */
#line 101 "parse.y"
              {
        f_stack[f_top]->f->code[(yyvsp[-1].num)].op1.ival = f_stack[f_top]->f->code_num;
    }
#line 1616 "parse.tab.c"
    break;

  case 8: /* stmt: if stmt_no_if else stmt  */
#line 104 "parse.y"
                              {
        f_stack[f_top]->f->code[(yyvsp[-3].num)].op1.ival = (yyvsp[-1].num) + 1;
        f_stack[f_top]->f->code[(yyvsp[-1].num)].op2.ival = f_stack[f_top]->f->code_num;
    }
#line 1625 "parse.tab.c"
    break;

  case 9: /* stmt: while_start while_cond stmt  */
#line 108 "parse.y"
                                  {
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_JMP, (yyvsp[-2].num)));
        f_stack[f_top]->f->code[(yyvsp[-1].num)].op1.ival = f_stack[f_top]->f->code_num;
    }
#line 1634 "parse.tab.c"
    break;

  case 10: /* stmt: '{' program '}'  */
#line 112 "parse.y"
                      {}
#line 1640 "parse.tab.c"
    break;

  case 11: /* stmt: RETURN expr ';'  */
#line 113 "parse.y"
                      {
        ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_RET, (yyvsp[-1].value)));
    }
#line 1648 "parse.tab.c"
    break;

  case 12: /* stmt: RETURN ';'  */
#line 116 "parse.y"
                 {
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_RET, 0));
    }
#line 1656 "parse.tab.c"
    break;

  case 13: /* stmt: ';'  */
#line 119 "parse.y"
          {}
#line 1662 "parse.tab.c"
    break;

  case 14: /* stmt_no_if: expr ';'  */
#line 122 "parse.y"
             {}
#line 1668 "parse.tab.c"
    break;

  case 15: /* stmt_no_if: decl  */
#line 123 "parse.y"
           {}
#line 1674 "parse.tab.c"
    break;

  case 16: /* stmt_no_if: if stmt_no_if else stmt_no_if  */
#line 124 "parse.y"
                                    {
        f_stack[f_top]->f->code[(yyvsp[-3].num)].op1.ival = (yyvsp[-1].num) + 1;
        f_stack[f_top]->f->code[(yyvsp[-1].num)].op2.ival = f_stack[f_top]->f->code_num;
    }
#line 1683 "parse.tab.c"
    break;

  case 17: /* stmt_no_if: while_start while_cond stmt_no_if  */
#line 128 "parse.y"
                                        {
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_JMP, (yyvsp[-2].num)));
        f_stack[f_top]->f->code[(yyvsp[-1].num)].op1.ival = f_stack[f_top]->f->code_num;
    }
#line 1692 "parse.tab.c"
    break;

  case 18: /* stmt_no_if: '{' program '}'  */
#line 132 "parse.y"
                      {}
#line 1698 "parse.tab.c"
    break;

  case 19: /* stmt_no_if: RETURN expr ';'  */
#line 133 "parse.y"
                      {
        ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_RET, (yyvsp[-1].value)));
    }
#line 1706 "parse.tab.c"
    break;

  case 20: /* stmt_no_if: RETURN ';'  */
#line 136 "parse.y"
                 {
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_RET, 0));
    }
#line 1714 "parse.tab.c"
    break;

  case 21: /* stmt_no_if: ';'  */
#line 139 "parse.y"
          {}
#line 1720 "parse.tab.c"
    break;

  case 22: /* if: IF '(' expr ')'  */
#line 142 "parse.y"
                    {
        (yyval.num) = f_stack[f_top]->f->code_num;
        ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_JMPNOT, (yyvsp[-1].value)));
    }
#line 1729 "parse.tab.c"
    break;

  case 23: /* else: ELSE  */
#line 148 "parse.y"
         {
        (yyval.num) = f_stack[f_top]->f->code_num;
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_JMP, 0));
    }
#line 1738 "parse.tab.c"
    break;

  case 24: /* while_cond: '(' expr ')'  */
#line 154 "parse.y"
                 {
        (yyval.num) = ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_JMPNOT, (yyvsp[-1].value)));
    }
#line 1746 "parse.tab.c"
    break;

  case 25: /* while_start: WHILE  */
#line 159 "parse.y"
          {
        (yyval.num) = f_stack[f_top]->f->code_num;
    }
#line 1754 "parse.tab.c"
    break;

  case 28: /* var_name: NAME  */
#line 168 "parse.y"
         {
        printf("Declaration: %s\n", name);
        (yyval.name) = strdup(name);
    }
#line 1763 "parse.tab.c"
    break;

  case 29: /* func_name: NAME  */
#line 174 "parse.y"
         {
        printf("Function: %s\n", name);
        f_stack[++f_top] = ir_func_ctx_new(ir_func_new(name, 0));
        ir_program_add_func(program, f_stack[f_top]->f);
    }
#line 1773 "parse.tab.c"
    break;

  case 30: /* expr: NUMBER  */
#line 181 "parse.y"
           { (yyval.value) = ir_expr_imm(num); }
#line 1779 "parse.tab.c"
    break;

  case 31: /* expr: CHAR  */
#line 182 "parse.y"
           { (yyval.value) = ir_expr_imm(num); }
#line 1785 "parse.tab.c"
    break;

  case 32: /* expr: NAME  */
#line 183 "parse.y"
           { (yyval.value) = ir_expr_var(ir_func_ctx_get_local(f_stack[f_top], name)); }
#line 1791 "parse.tab.c"
    break;

  case 33: /* expr: STR  */
#line 184 "parse.y"
          { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_lea((yyval.value), name)); }
#line 1797 "parse.tab.c"
    break;

  case 34: /* expr: expr '=' expr  */
#line 185 "parse.y"
                    { ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 1803 "parse.tab.c"
    break;

  case 35: /* expr: expr '+' expr  */
#line 186 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_ADD, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1809 "parse.tab.c"
    break;

  case 36: /* expr: expr '-' expr  */
#line 187 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SUB, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1815 "parse.tab.c"
    break;

  case 37: /* expr: expr '*' expr  */
#line 188 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_MUL, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1821 "parse.tab.c"
    break;

  case 38: /* expr: expr '/' expr  */
#line 189 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_DIV, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1827 "parse.tab.c"
    break;

  case 39: /* expr: expr '%' expr  */
#line 190 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_MOD, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1833 "parse.tab.c"
    break;

  case 40: /* expr: expr '<' expr  */
#line 191 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_LT, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1839 "parse.tab.c"
    break;

  case 41: /* expr: expr '>' expr  */
#line 192 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_GT, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1845 "parse.tab.c"
    break;

  case 42: /* expr: expr LE expr  */
#line 193 "parse.y"
                   { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_LE, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1851 "parse.tab.c"
    break;

  case 43: /* expr: expr GE expr  */
#line 194 "parse.y"
                   { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_GE, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1857 "parse.tab.c"
    break;

  case 44: /* expr: expr EQ expr  */
#line 195 "parse.y"
                   { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_EQ, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1863 "parse.tab.c"
    break;

  case 45: /* expr: expr NE expr  */
#line 196 "parse.y"
                   { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_NE, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1869 "parse.tab.c"
    break;

  case 46: /* expr: expr SHL expr  */
#line 197 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SHL, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1875 "parse.tab.c"
    break;

  case 47: /* expr: expr SHR expr  */
#line 198 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SHR, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1881 "parse.tab.c"
    break;

  case 48: /* expr: '-' expr  */
#line 199 "parse.y"
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_NEG, (yyval.value), (yyvsp[0].value))); }
#line 1887 "parse.tab.c"
    break;

  case 49: /* expr: '+' expr  */
#line 200 "parse.y"
               { (yyval.value) = (yyvsp[0].value); }
#line 1893 "parse.tab.c"
    break;

  case 50: /* expr: '~' expr  */
#line 201 "parse.y"
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_NOT, (yyval.value), (yyvsp[0].value))); }
#line 1899 "parse.tab.c"
    break;

  case 51: /* expr: '!' expr  */
#line 202 "parse.y"
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_LOGIC_NOT, (yyval.value), (yyvsp[0].value))); }
#line 1905 "parse.tab.c"
    break;

  case 52: /* expr: expr '&' expr  */
#line 203 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_AND, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1911 "parse.tab.c"
    break;

  case 53: /* expr: expr '|' expr  */
#line 204 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_OR, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1917 "parse.tab.c"
    break;

  case 54: /* expr: expr '^' expr  */
#line 205 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_XOR, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1923 "parse.tab.c"
    break;

  case 55: /* expr: expr AND expr  */
#line 206 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_LOGIC_AND, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1929 "parse.tab.c"
    break;

  case 56: /* expr: expr OR expr  */
#line 207 "parse.y"
                   { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_LOGIC_OR, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 1935 "parse.tab.c"
    break;

  case 57: /* expr: expr INC  */
#line 208 "parse.y"
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_ADD, (yyvsp[-1].value), (yyvsp[-1].value), ir_expr_imm(1))); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, (yyval.value), (yyvsp[-1].value))); }
#line 1941 "parse.tab.c"
    break;

  case 58: /* expr: expr DEC  */
#line 209 "parse.y"
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SUB, (yyvsp[-1].value), (yyvsp[-1].value), ir_expr_imm(1))); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, (yyval.value), (yyvsp[-1].value))); }
#line 1947 "parse.tab.c"
    break;

  case 59: /* expr: INC expr  */
#line 210 "parse.y"
               { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_ADD, (yyvsp[0].value), (yyvsp[0].value), ir_expr_imm(1))); (yyval.value) = (yyvsp[0].value); }
#line 1953 "parse.tab.c"
    break;

  case 60: /* expr: DEC expr  */
#line 211 "parse.y"
               { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SUB, (yyvsp[0].value), (yyvsp[0].value), ir_expr_imm(1))); (yyval.value) = (yyvsp[0].value); }
#line 1959 "parse.tab.c"
    break;

  case 61: /* expr: expr ADD_ASSIGN expr  */
#line 212 "parse.y"
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_ADD, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 1965 "parse.tab.c"
    break;

  case 62: /* expr: expr SUB_ASSIGN expr  */
#line 213 "parse.y"
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SUB, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 1971 "parse.tab.c"
    break;

  case 63: /* expr: expr MUL_ASSIGN expr  */
#line 214 "parse.y"
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_MUL, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 1977 "parse.tab.c"
    break;

  case 64: /* expr: expr DIV_ASSIGN expr  */
#line 215 "parse.y"
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_DIV, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 1983 "parse.tab.c"
    break;

  case 65: /* expr: expr MOD_ASSIGN expr  */
#line 216 "parse.y"
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_MOD, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 1989 "parse.tab.c"
    break;

  case 66: /* expr: expr SHL_ASSIGN expr  */
#line 217 "parse.y"
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SHL, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 1995 "parse.tab.c"
    break;

  case 67: /* expr: expr SHR_ASSIGN expr  */
#line 218 "parse.y"
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SHR, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 2001 "parse.tab.c"
    break;

  case 68: /* expr: expr AND_ASSIGN expr  */
#line 219 "parse.y"
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_AND, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 2007 "parse.tab.c"
    break;

  case 69: /* expr: expr XOR_ASSIGN expr  */
#line 220 "parse.y"
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_XOR, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 2013 "parse.tab.c"
    break;

  case 70: /* expr: expr OR_ASSIGN expr  */
#line 221 "parse.y"
                          { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_OR, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 2019 "parse.tab.c"
    break;

  case 71: /* expr: '(' expr ')'  */
#line 222 "parse.y"
                   { (yyval.value) = (yyvsp[-1].value); }
#line 2025 "parse.tab.c"
    break;

  case 72: /* expr: '&' expr  */
#line 223 "parse.y"
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); if ((yyvsp[0].value).type == EXPR_IMM){ printf("'&' could not be used on an immediate number\n"); exit(1); } ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_ADDR, (yyval.value), (yyvsp[0].value))); }
#line 2031 "parse.tab.c"
    break;

  case 73: /* expr: '*' expr  */
#line 224 "parse.y"
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, (yyval.value), (yyvsp[0].value))); (yyval.value).type = EXPR_PTR; }
#line 2037 "parse.tab.c"
    break;

  case 74: /* expr: expr '[' expr ']'  */
#line 225 "parse.y"
                        { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_ADD, (yyval.value), ir_expr_imm((yyvsp[-3].value).ival), (yyvsp[-1].value))); (yyval.value) = ir_expr_ref((yyval.value).ival); }
#line 2043 "parse.tab.c"
    break;

  case 75: /* expr: func_call '(' para_list ')'  */
#line 226 "parse.y"
                                  {
        (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top]));
        ir i = ir_new1(IR_CALL, (yyval.value));
        i.op = f_stack[f_top]->f->code[(yyvsp[-3].num)].op;
        f_stack[f_top]->f->code[(yyvsp[-3].num)].op = NULL;
        ir_func_add_code(f_stack[f_top]->f, i);
    }
#line 2055 "parse.tab.c"
    break;

  case 76: /* expr: INT '(' fexpr ')'  */
#line 233 "parse.y"
                        { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_F2I, (yyval.value), (yyvsp[-1].value))); }
#line 2061 "parse.tab.c"
    break;

  case 77: /* expr: CHAR '(' fexpr ')'  */
#line 234 "parse.y"
                         { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_F2I, (yyval.value), (yyvsp[-1].value))); }
#line 2067 "parse.tab.c"
    break;

  case 78: /* fexpr: REAL  */
#line 237 "parse.y"
         { (yyval.value) = ir_expr_fimm(real); }
#line 2073 "parse.tab.c"
    break;

  case 79: /* fexpr: FNAME  */
#line 238 "parse.y"
            { (yyval.value) = ir_expr_var(ir_func_ctx_get_local(f_stack[f_top], name)); }
#line 2079 "parse.tab.c"
    break;

  case 80: /* fexpr: '-' fexpr  */
#line 239 "parse.y"
                { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_FNEG, (yyval.value), (yyvsp[0].value))); }
#line 2085 "parse.tab.c"
    break;

  case 81: /* fexpr: '+' fexpr  */
#line 240 "parse.y"
                { (yyval.value) = (yyvsp[0].value); }
#line 2091 "parse.tab.c"
    break;

  case 82: /* fexpr: '(' fexpr ')'  */
#line 241 "parse.y"
                    { (yyval.value) = (yyvsp[-1].value); }
#line 2097 "parse.tab.c"
    break;

  case 83: /* fexpr: fexpr '+' fexpr  */
#line 243 "parse.y"
                      { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FADD, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2103 "parse.tab.c"
    break;

  case 84: /* fexpr: fexpr '+' expr  */
#line 244 "parse.y"
                     { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, (yyval.value), (yyvsp[0].value))); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FADD, (yyval.value), (yyvsp[-2].value), (yyval.value))); }
#line 2109 "parse.tab.c"
    break;

  case 85: /* fexpr: expr '+' fexpr  */
#line 245 "parse.y"
                     { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, (yyval.value), (yyvsp[-2].value))); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FADD, (yyval.value), (yyval.value), (yyvsp[0].value))); }
#line 2115 "parse.tab.c"
    break;

  case 86: /* fexpr: fexpr '-' fexpr  */
#line 247 "parse.y"
                      { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FSUB, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2121 "parse.tab.c"
    break;

  case 87: /* fexpr: fexpr '-' expr  */
#line 248 "parse.y"
                     { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, (yyval.value), (yyvsp[0].value))); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FSUB, (yyval.value), (yyvsp[-2].value), (yyval.value))); }
#line 2127 "parse.tab.c"
    break;

  case 88: /* fexpr: expr '-' fexpr  */
#line 249 "parse.y"
                     { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, (yyval.value), (yyvsp[-2].value))); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FSUB, (yyval.value), (yyval.value), (yyvsp[0].value))); }
#line 2133 "parse.tab.c"
    break;

  case 89: /* fexpr: fexpr '*' fexpr  */
#line 251 "parse.y"
                      { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FMUL, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2139 "parse.tab.c"
    break;

  case 90: /* fexpr: fexpr '*' expr  */
#line 252 "parse.y"
                     { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, (yyval.value), (yyvsp[0].value))); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FMUL, (yyval.value), (yyvsp[-2].value), (yyval.value))); }
#line 2145 "parse.tab.c"
    break;

  case 91: /* fexpr: expr '*' fexpr  */
#line 253 "parse.y"
                     { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, (yyval.value), (yyvsp[-2].value))); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FMUL, (yyval.value), (yyval.value), (yyvsp[0].value))); }
#line 2151 "parse.tab.c"
    break;

  case 92: /* fexpr: fexpr '/' fexpr  */
#line 255 "parse.y"
                      { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FDIV, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2157 "parse.tab.c"
    break;

  case 93: /* fexpr: fexpr '/' expr  */
#line 256 "parse.y"
                     { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, (yyval.value), (yyvsp[0].value))); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FDIV, (yyval.value), (yyvsp[-2].value), (yyval.value))); }
#line 2163 "parse.tab.c"
    break;

  case 94: /* fexpr: expr '/' fexpr  */
#line 257 "parse.y"
                     { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, (yyval.value), (yyvsp[-2].value))); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FDIV, (yyval.value), (yyval.value), (yyvsp[0].value))); }
#line 2169 "parse.tab.c"
    break;

  case 95: /* fexpr: fexpr ADD_ASSIGN fexpr  */
#line 259 "parse.y"
                             { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FADD, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 2175 "parse.tab.c"
    break;

  case 96: /* fexpr: fexpr SUB_ASSIGN fexpr  */
#line 260 "parse.y"
                             { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FSUB, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 2181 "parse.tab.c"
    break;

  case 97: /* fexpr: fexpr MUL_ASSIGN fexpr  */
#line 261 "parse.y"
                             { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FMUL, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 2187 "parse.tab.c"
    break;

  case 98: /* fexpr: fexpr DIV_ASSIGN fexpr  */
#line 262 "parse.y"
                             { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FDIV, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 2193 "parse.tab.c"
    break;

  case 99: /* fexpr: '&' fexpr  */
#line 264 "parse.y"
                { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); if ((yyvsp[0].value).type == EXPR_IMM){ printf("'&' could not be used on an immediate number\n"); exit(1); } ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_ADDR, (yyval.value), (yyvsp[0].value))); }
#line 2199 "parse.tab.c"
    break;

  case 100: /* fexpr: '*' fexpr  */
#line 265 "parse.y"
                { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, (yyval.value), (yyvsp[0].value))); (yyval.value).type = EXPR_PTR; }
#line 2205 "parse.tab.c"
    break;

  case 101: /* fexpr: fexpr '[' expr ']'  */
#line 266 "parse.y"
                         { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_ADD, (yyval.value), ir_expr_imm((yyvsp[-3].value).ival), (yyvsp[-1].value))); (yyval.value) = ir_expr_ref((yyval.value).ival); }
#line 2211 "parse.tab.c"
    break;

  case 102: /* fexpr: ffunc_call '(' para_list ')'  */
#line 268 "parse.y"
                                   {
        (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top]));
        ir i = ir_new1(IR_CALL, (yyval.value));
        i.op = f_stack[f_top]->f->code[(yyvsp[-3].num)].op;
        f_stack[f_top]->f->code[(yyvsp[-3].num)].op = NULL;
        ir_func_add_code(f_stack[f_top]->f, i);
    }
#line 2223 "parse.tab.c"
    break;

  case 103: /* constexpr: NUMBER  */
#line 277 "parse.y"
           { (yyval.num) = num; }
#line 2229 "parse.tab.c"
    break;

  case 104: /* constexpr: constexpr '+' constexpr  */
#line 278 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) + (yyvsp[0].num); }
#line 2235 "parse.tab.c"
    break;

  case 105: /* constexpr: constexpr '-' constexpr  */
#line 279 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) - (yyvsp[0].num); }
#line 2241 "parse.tab.c"
    break;

  case 106: /* constexpr: constexpr '*' constexpr  */
#line 280 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) * (yyvsp[0].num); }
#line 2247 "parse.tab.c"
    break;

  case 107: /* constexpr: constexpr '/' constexpr  */
#line 281 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) / (yyvsp[0].num); }
#line 2253 "parse.tab.c"
    break;

  case 108: /* constexpr: constexpr '%' constexpr  */
#line 282 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) % (yyvsp[0].num); }
#line 2259 "parse.tab.c"
    break;

  case 109: /* constexpr: constexpr '<' constexpr  */
#line 283 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) < (yyvsp[0].num); }
#line 2265 "parse.tab.c"
    break;

  case 110: /* constexpr: constexpr '>' constexpr  */
#line 284 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) > (yyvsp[0].num); }
#line 2271 "parse.tab.c"
    break;

  case 111: /* constexpr: constexpr LE constexpr  */
#line 285 "parse.y"
                             { (yyval.num) = (yyvsp[-2].num) <= (yyvsp[0].num); }
#line 2277 "parse.tab.c"
    break;

  case 112: /* constexpr: constexpr GE constexpr  */
#line 286 "parse.y"
                             { (yyval.num) = (yyvsp[-2].num) >= (yyvsp[0].num); }
#line 2283 "parse.tab.c"
    break;

  case 113: /* constexpr: constexpr EQ constexpr  */
#line 287 "parse.y"
                             { (yyval.num) = (yyvsp[-2].num) == (yyvsp[0].num); }
#line 2289 "parse.tab.c"
    break;

  case 114: /* constexpr: constexpr NE constexpr  */
#line 288 "parse.y"
                             { (yyval.num) = (yyvsp[-2].num) != (yyvsp[0].num); }
#line 2295 "parse.tab.c"
    break;

  case 115: /* constexpr: constexpr SHL constexpr  */
#line 289 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) << (yyvsp[0].num); }
#line 2301 "parse.tab.c"
    break;

  case 116: /* constexpr: constexpr SHR constexpr  */
#line 290 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) >> (yyvsp[0].num); }
#line 2307 "parse.tab.c"
    break;

  case 117: /* constexpr: '-' constexpr  */
#line 291 "parse.y"
                    { (yyval.num) = -(yyvsp[0].num); }
#line 2313 "parse.tab.c"
    break;

  case 118: /* constexpr: '+' constexpr  */
#line 292 "parse.y"
                    { (yyval.num) = (yyvsp[0].num); }
#line 2319 "parse.tab.c"
    break;

  case 119: /* constexpr: '~' constexpr  */
#line 293 "parse.y"
                    { (yyval.num) = ~(yyvsp[0].num); }
#line 2325 "parse.tab.c"
    break;

  case 120: /* constexpr: '!' constexpr  */
#line 294 "parse.y"
                    { (yyval.num) = !(yyvsp[0].num); }
#line 2331 "parse.tab.c"
    break;

  case 121: /* constexpr: constexpr '&' constexpr  */
#line 295 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) & (yyvsp[0].num); }
#line 2337 "parse.tab.c"
    break;

  case 122: /* constexpr: constexpr '|' constexpr  */
#line 296 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) | (yyvsp[0].num); }
#line 2343 "parse.tab.c"
    break;

  case 123: /* constexpr: constexpr '^' constexpr  */
#line 297 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) ^ (yyvsp[0].num); }
#line 2349 "parse.tab.c"
    break;

  case 124: /* constexpr: constexpr AND constexpr  */
#line 298 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) && (yyvsp[0].num); }
#line 2355 "parse.tab.c"
    break;

  case 125: /* constexpr: constexpr OR constexpr  */
#line 299 "parse.y"
                             { (yyval.num) = (yyvsp[-2].num) || (yyvsp[0].num); }
#line 2361 "parse.tab.c"
    break;

  case 126: /* constexpr: '(' constexpr ')'  */
#line 300 "parse.y"
                        { (yyval.num) = (yyvsp[-1].num); }
#line 2367 "parse.tab.c"
    break;

  case 127: /* func_call: NAME  */
#line 303 "parse.y"
         {
        printf("Function Call: %s\n", name);
        ir i = ir_new0(IR_PARAM);
        i.op = strdup(name);
        (yyval.num) = ir_func_add_code(f_stack[f_top]->f, i);
    }
#line 2378 "parse.tab.c"
    break;

  case 128: /* ffunc_call: FNAME  */
#line 311 "parse.y"
          {
        printf("Function Call: %s\n", name);
        ir i = ir_new0(IR_PARAM);
        i.op = strdup(name);
        (yyval.num) = ir_func_add_code(f_stack[f_top]->f, i);
    }
#line 2389 "parse.tab.c"
    break;

  case 134: /* var_decl: type_name var_name ';'  */
#line 328 "parse.y"
                           {
        ir_func_ctx_add_local(f_stack[f_top], (yyvsp[-1].name), 1);
        free((yyvsp[-1].name));
    }
#line 2398 "parse.tab.c"
    break;

  case 135: /* var_decl: type_name var_name '=' expr ';'  */
#line 332 "parse.y"
                                      {
        expr_info id = ir_expr_var(ir_func_ctx_add_local(f_stack[f_top], (yyvsp[-3].name), 1));
        free((yyvsp[-3].name));
        ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, id, (yyvsp[-1].value)));
    }
#line 2408 "parse.tab.c"
    break;

  case 136: /* var_decl: type_name var_name '[' constexpr ']' ';'  */
#line 337 "parse.y"
                                               {
        int length = (int)(yyvsp[-2].num);
        ir_func_ctx_add_local(f_stack[f_top], (yyvsp[-4].name), length);
        free((yyvsp[-4].name));
    }
#line 2418 "parse.tab.c"
    break;

  case 137: /* var_decl: ftype_name var_name ';'  */
#line 342 "parse.y"
                              {
        ir_func_ctx_add_flocal(f_stack[f_top], (yyvsp[-1].name), 1);
        free((yyvsp[-1].name));
    }
#line 2427 "parse.tab.c"
    break;

  case 138: /* var_decl: ftype_name var_name '=' fexpr ';'  */
#line 346 "parse.y"
                                        {
        expr_info id = ir_expr_var(ir_func_ctx_add_flocal(f_stack[f_top], (yyvsp[-3].name), 1));
        free((yyvsp[-3].name));
        ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, id, (yyvsp[-1].value)));
    }
#line 2437 "parse.tab.c"
    break;

  case 139: /* var_decl: ftype_name var_name '[' constexpr ']' ';'  */
#line 351 "parse.y"
                                                {
        int length = (int)(yyvsp[-2].num);
        ir_func_ctx_add_flocal(f_stack[f_top], (yyvsp[-4].name), length);
        free((yyvsp[-4].name));
    }
#line 2447 "parse.tab.c"
    break;

  case 140: /* func_decl: type_name func_name '(' para_decl ')' '{' program '}'  */
#line 357 "parse.y"
                                                          {
        printf("Function End %s\n", f_stack[f_top]->f->name);
        if (f_stack[f_top]->f->code[f_stack[f_top]->f->code_num - 1].ins != IR_RET){
            ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_RET, 0));
        }
        ir_func_ctx_free(f_stack[f_top--]);
    }
#line 2459 "parse.tab.c"
    break;

  case 141: /* para_decl: type_name NAME  */
#line 365 "parse.y"
                   {
        printf("Parameter Declare: %s\n", name);
        ir_func_ctx_add_local(f_stack[f_top], name, 1);
    }
#line 2468 "parse.tab.c"
    break;

  case 143: /* $@1: %empty  */
#line 370 "parse.y"
                     {
        printf("Parameter Declare: %s\n", name);
        ir_func_ctx_add_local(f_stack[f_top], name, 1);
    }
#line 2477 "parse.tab.c"
    break;

  case 145: /* para_decl: ftype_name NAME  */
#line 374 "parse.y"
                      {
        printf("Parameter Declare: %s\n", name);
        ir_func_ctx_add_flocal(f_stack[f_top], name, 1);
    }
#line 2486 "parse.tab.c"
    break;

  case 146: /* $@2: %empty  */
#line 378 "parse.y"
                      {
        printf("Parameter Declare: %s\n", name);
        ir_func_ctx_add_flocal(f_stack[f_top], name, 1);
    }
#line 2495 "parse.tab.c"
    break;

  case 148: /* para_decl: %empty  */
#line 382 "parse.y"
      {}
#line 2501 "parse.tab.c"
    break;

  case 149: /* para_list: expr  */
#line 385 "parse.y"
         { ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_PASS, (yyvsp[0].value))); }
#line 2507 "parse.tab.c"
    break;

  case 150: /* para_list: fexpr  */
#line 386 "parse.y"
            { ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_PASS, (yyvsp[0].value))); }
#line 2513 "parse.tab.c"
    break;

  case 151: /* para_list: para_list ',' expr  */
#line 387 "parse.y"
                         { ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_PASS, (yyvsp[0].value))); }
#line 2519 "parse.tab.c"
    break;

  case 152: /* para_list: para_list ',' fexpr  */
#line 388 "parse.y"
                          { ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_PASS, (yyvsp[0].value))); }
#line 2525 "parse.tab.c"
    break;

  case 153: /* para_list: %empty  */
#line 389 "parse.y"
      {}
#line 2531 "parse.tab.c"
    break;


#line 2535 "parse.tab.c"

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

#line 391 "parse.y"


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
