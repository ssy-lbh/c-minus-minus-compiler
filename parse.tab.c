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
#line 57 "parse.y"

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

extern loop_info *l_stack[0x40];
extern int l_top;

extern long num;
extern double real;
extern char name[0x400];
extern FILE* yyin;

#line 100 "parse.tab.c"

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
  YYSYMBOL_BREAK = 12,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 13,                  /* CONTINUE  */
  YYSYMBOL_VOID = 14,                      /* VOID  */
  YYSYMBOL_INT = 15,                       /* INT  */
  YYSYMBOL_FLOAT = 16,                     /* FLOAT  */
  YYSYMBOL_STR = 17,                       /* STR  */
  YYSYMBOL_CHAR = 18,                      /* CHAR  */
  YYSYMBOL_LE = 19,                        /* LE  */
  YYSYMBOL_GE = 20,                        /* GE  */
  YYSYMBOL_EQ = 21,                        /* EQ  */
  YYSYMBOL_NE = 22,                        /* NE  */
  YYSYMBOL_SHL = 23,                       /* SHL  */
  YYSYMBOL_SHR = 24,                       /* SHR  */
  YYSYMBOL_AND = 25,                       /* AND  */
  YYSYMBOL_OR = 26,                        /* OR  */
  YYSYMBOL_ARROW = 27,                     /* ARROW  */
  YYSYMBOL_INC = 28,                       /* INC  */
  YYSYMBOL_DEC = 29,                       /* DEC  */
  YYSYMBOL_ADD_ASSIGN = 30,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 31,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 32,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 33,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 34,                /* MOD_ASSIGN  */
  YYSYMBOL_SHL_ASSIGN = 35,                /* SHL_ASSIGN  */
  YYSYMBOL_SHR_ASSIGN = 36,                /* SHR_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 37,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 38,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 39,                 /* OR_ASSIGN  */
  YYSYMBOL_40_ = 40,                       /* ';'  */
  YYSYMBOL_41_ = 41,                       /* '('  */
  YYSYMBOL_42_ = 42,                       /* ')'  */
  YYSYMBOL_43_ = 43,                       /* '['  */
  YYSYMBOL_44_ = 44,                       /* ']'  */
  YYSYMBOL_45_ = 45,                       /* '{'  */
  YYSYMBOL_46_ = 46,                       /* '}'  */
  YYSYMBOL_47_ = 47,                       /* ','  */
  YYSYMBOL_48_ = 48,                       /* '='  */
  YYSYMBOL_49_ = 49,                       /* '<'  */
  YYSYMBOL_50_ = 50,                       /* '>'  */
  YYSYMBOL_51_ = 51,                       /* '^'  */
  YYSYMBOL_52_ = 52,                       /* '&'  */
  YYSYMBOL_53_ = 53,                       /* '|'  */
  YYSYMBOL_54_ = 54,                       /* '+'  */
  YYSYMBOL_55_ = 55,                       /* '-'  */
  YYSYMBOL_56_ = 56,                       /* '*'  */
  YYSYMBOL_57_ = 57,                       /* '/'  */
  YYSYMBOL_58_ = 58,                       /* '%'  */
  YYSYMBOL_59_ = 59,                       /* '~'  */
  YYSYMBOL_60_ = 60,                       /* '!'  */
  YYSYMBOL_61_ = 61,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 62,                  /* $accept  */
  YYSYMBOL_program = 63,                   /* program  */
  YYSYMBOL_stmt = 64,                      /* stmt  */
  YYSYMBOL_stmt_no_if = 65,                /* stmt_no_if  */
  YYSYMBOL_if = 66,                        /* if  */
  YYSYMBOL_else = 67,                      /* else  */
  YYSYMBOL_for = 68,                       /* for  */
  YYSYMBOL_for_var_decl = 69,              /* for_var_decl  */
  YYSYMBOL_for_cond = 70,                  /* for_cond  */
  YYSYMBOL_for_inc = 71,                   /* for_inc  */
  YYSYMBOL_while_cond = 72,                /* while_cond  */
  YYSYMBOL_while_start = 73,               /* while_start  */
  YYSYMBOL_decl = 74,                      /* decl  */
  YYSYMBOL_var_name = 75,                  /* var_name  */
  YYSYMBOL_func_name = 76,                 /* func_name  */
  YYSYMBOL_expr = 77,                      /* expr  */
  YYSYMBOL_fexpr = 78,                     /* fexpr  */
  YYSYMBOL_constexpr = 79,                 /* constexpr  */
  YYSYMBOL_func_call = 80,                 /* func_call  */
  YYSYMBOL_ffunc_call = 81,                /* ffunc_call  */
  YYSYMBOL_type_name = 82,                 /* type_name  */
  YYSYMBOL_ftype_name = 83,                /* ftype_name  */
  YYSYMBOL_var_decl = 84,                  /* var_decl  */
  YYSYMBOL_func_decl = 85,                 /* func_decl  */
  YYSYMBOL_para_decl = 86,                 /* para_decl  */
  YYSYMBOL_87_1 = 87,                      /* $@1  */
  YYSYMBOL_88_2 = 88,                      /* $@2  */
  YYSYMBOL_para_list = 89                  /* para_list  */
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
#define YYLAST   1819

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  177
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  355

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


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
       2,     2,     2,    60,     2,     2,     2,    58,    52,     2,
      41,    42,    56,    54,    47,    55,    61,    57,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    40,
      49,    48,    50,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,    53,    46,    59,     2,     2,     2,
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   100,   100,   101,   104,   105,   106,   107,   110,   114,
     119,   124,   125,   128,   131,   135,   139,   142,   143,   144,
     145,   149,   154,   159,   160,   163,   166,   170,   174,   177,
     183,   189,   197,   202,   209,   215,   220,   226,   227,   230,
     236,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   295,   296,   299,
     300,   301,   302,   303,   305,   306,   307,   309,   310,   311,
     313,   314,   315,   317,   318,   319,   321,   322,   323,   325,
     326,   327,   329,   330,   331,   333,   334,   336,   337,   339,
     340,   342,   343,   345,   346,   347,   349,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   384,   392,   400,   401,   402,   405,   406,   409,   413,
     418,   423,   427,   432,   438,   446,   450,   451,   451,   455,
     459,   459,   463,   466,   467,   468,   469,   470
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
  "NAME", "FNAME", "IF", "ELSE", "WHILE", "FOR", "RETURN", "BREAK",
  "CONTINUE", "VOID", "INT", "FLOAT", "STR", "CHAR", "LE", "GE", "EQ",
  "NE", "SHL", "SHR", "AND", "OR", "ARROW", "INC", "DEC", "ADD_ASSIGN",
  "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "SHL_ASSIGN",
  "SHR_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "';'", "'('",
  "')'", "'['", "']'", "'{'", "'}'", "','", "'='", "'<'", "'>'", "'^'",
  "'&'", "'|'", "'+'", "'-'", "'*'", "'/'", "'%'", "'~'", "'!'", "'.'",
  "$accept", "program", "stmt", "stmt_no_if", "if", "else", "for",
  "for_var_decl", "for_cond", "for_inc", "while_cond", "while_start",
  "decl", "var_name", "func_name", "expr", "fexpr", "constexpr",
  "func_call", "ffunc_call", "type_name", "ftype_name", "var_decl",
  "func_decl", "para_decl", "$@1", "$@2", "para_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-231)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-171)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -231,   373,  -231,  -231,  -231,    28,    35,    42,  -231,    65,
     175,    -5,     0,  -231,    86,  -231,  -231,    88,   750,   750,
    -231,   683,  -231,   683,   683,   683,   683,   750,   750,  -231,
     605,   663,   105,  -231,   792,   740,   109,   111,     1,     5,
    -231,  -231,   750,    -3,    86,  -231,   750,   750,   750,   750,
     750,   832,  -231,  -231,   683,   683,  -231,  -231,   872,  1470,
     431,   140,    17,   210,    24,   210,    24,    22,  -231,  -231,
    -231,   692,    18,    55,   145,  -231,  -231,   147,   605,   605,
     105,   154,   912,  1510,  -231,   750,   663,   750,   750,   750,
     750,   750,   750,   750,   750,  -231,  -231,   750,   750,   750,
     750,   750,   750,   750,   750,   750,   750,  -231,   750,   750,
     750,   750,   750,   750,   750,   683,   683,   683,   683,   683,
     683,   683,   683,   683,   683,   683,   683,   683,  -231,   750,
     683,   683,   683,   683,   683,   683,   683,   683,   683,   123,
    -231,    -6,   124,  -231,  -231,    -4,   952,  -231,   750,    10,
    -231,   992,   204,   241,   241,    22,  -231,   750,   750,   750,
     750,   750,  1232,  1550,  1590,  -231,  -231,  -231,   159,  1032,
     162,   164,   489,  -231,   663,   147,  -231,   605,   167,   169,
    1072,  -231,  1390,  1390,  1390,  1390,  1390,  1390,   291,   291,
    1312,  1312,  1312,  1312,  1312,  1312,  1312,  1312,  1312,  1312,
    1112,  1312,  1390,  1390,   204,   204,   204,   210,    24,   210,
      24,    22,  -231,    22,  -231,    22,  -231,    17,    17,    17,
      17,  1352,  1725,  1352,  1725,  1352,  1725,  1352,  1725,  1152,
      17,    17,  1761,    24,  1761,    24,   369,  -231,   369,  -231,
     369,  -231,  1232,  1670,   -39,    -9,  -231,   146,   750,   195,
    -231,   146,   683,  -231,   134,  1272,   241,   241,    22,    22,
      22,  -231,  -231,   177,   178,  -231,   605,  -231,  -231,  -231,
    -231,  -231,   683,  -231,  -231,   146,   146,   146,   146,   146,
    1373,  1192,   149,    23,    38,   157,  1413,  1630,   750,  -231,
    1232,  1670,  1430,   188,   188,  -231,  -231,   146,   146,   146,
     146,   146,   146,   146,   146,   174,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,  -231,   142,   155,   172,
     185,  -231,   165,  1272,  -231,    87,    87,    87,    87,    87,
      87,  1685,  1685,  -231,    87,    87,   166,   166,   166,   188,
     188,  -231,  -231,  -231,   171,   179,  -231,  -231,  -231,   195,
     195,   547,  -231,  -231,  -231
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    41,    89,    43,    90,     0,    36,     0,
       0,     0,     0,   154,   153,   156,    44,    42,     0,     0,
      16,     0,     2,     0,     0,     0,     0,     0,     0,     3,
       0,     0,     0,     6,     0,     0,     0,     0,     0,     0,
      37,    38,     0,     0,     0,    13,     0,     0,     0,     0,
       0,     0,    14,    15,     0,     0,    70,    71,     0,     0,
       0,    83,   123,    60,    92,    59,    91,    84,   124,    61,
      62,     0,     0,     0,    16,     2,     7,     0,     0,     0,
       0,     6,     0,     0,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    68,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     0,
       0,     0,     0,     0,     0,     0,     0,   177,   177,    39,
     155,     0,     0,    39,   157,     0,     0,   153,     0,     0,
      32,     0,    83,    60,    59,    84,    12,     0,     0,     0,
       0,     0,     0,     0,     0,    82,    93,    11,    13,     0,
      14,    15,     0,    30,     0,     0,    22,     0,     4,     5,
       0,     9,    53,    54,    55,    56,    57,    58,    66,    67,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
       0,    45,    51,    52,    65,    63,    64,    46,    96,    47,
      99,    48,   102,    49,   105,    50,   108,   111,   112,   113,
     114,   116,   115,   118,   117,   120,   119,   122,   121,     0,
     109,   110,    95,    94,    98,    97,   101,   100,   104,   103,
     107,   106,   173,   174,     0,     0,   158,     0,     0,   172,
     161,     0,     0,    29,     0,    33,    46,    47,    48,    49,
      50,    87,    88,    12,    11,     8,     0,    21,    35,    85,
     125,    86,     0,   126,   127,     0,     0,     0,     0,     0,
       0,     0,   154,     0,     0,     0,     0,     0,     0,    20,
     175,   176,     0,   142,   141,   143,   144,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   159,   165,   169,     0,
       0,   162,     0,    34,   150,   135,   136,   137,   138,   139,
     140,   148,   149,   160,   133,   134,   147,   145,   146,   128,
     129,   130,   131,   132,     0,     0,     2,   163,    31,   172,
     172,     0,   168,   171,   164
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -231,   -21,   -26,   -47,   -23,    53,   -16,  -231,  -231,  -231,
     161,   -14,   -11,   203,  -231,    -1,   158,    54,  -231,  -231,
     -41,  -228,   205,  -231,  -230,  -231,  -231,   113
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    29,    77,    30,   174,    31,   148,   254,   322,
      86,    32,    33,   141,   142,   162,    35,   280,    36,    37,
      38,    39,    40,    41,   285,   344,   345,   244
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,    60,   149,   271,    76,    84,   139,    78,   272,    51,
     143,    13,   147,    15,    79,   143,    80,    56,    57,    81,
      58,   284,    61,    63,    65,    67,    69,    70,   317,    82,
      34,   175,   176,   273,   246,    52,   250,   247,   272,   251,
      53,   146,   248,   318,   252,   151,   152,   153,   154,   155,
      95,    96,    76,    84,   172,    78,    78,   140,   170,    34,
     181,   144,    79,    79,    80,    80,   140,    81,    81,  -151,
     169,   132,   133,   134,   135,   136,  -152,    82,    82,   140,
     134,   135,   136,    42,   180,    34,   182,   183,   184,   185,
     186,   187,   188,   189,   144,   171,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,    43,   200,   201,   202,
     203,   204,   205,   206,   207,   209,   211,   213,   215,   352,
     353,   284,   284,   221,   223,   225,   227,    54,   229,    55,
     267,   232,   234,   236,   238,   240,   242,   242,   308,   309,
     310,   311,   312,   313,   314,   315,    85,   255,   265,   274,
     137,   181,   138,   -28,    78,   173,   256,   257,   258,   259,
     260,    79,   -19,    80,   -40,   249,    81,   -25,    95,    96,
     -26,    34,   -27,    34,   288,   -17,    82,   -18,     3,    59,
       5,    62,    64,    66,    68,   -24,   -23,   275,    83,  -167,
      44,  -166,    16,    17,   115,   116,   117,   118,   119,   319,
     276,   277,  -170,    18,    19,   278,   279,   348,   283,   282,
     147,    15,   163,   164,   333,    45,    46,   346,   349,   289,
     311,   312,   313,   314,   315,   347,   350,    47,   266,    48,
      49,    50,    95,    96,    27,    28,    83,    83,    95,    96,
     265,   177,   145,    78,   313,   314,   315,   281,   150,     0,
      79,   245,    80,     0,     0,    81,     0,     0,   157,   158,
     159,   160,   161,     0,     0,    82,   117,   118,   119,    95,
      96,   290,     0,   208,   210,   212,   214,   216,   217,   218,
     219,   220,   222,   224,   226,   228,     0,   323,   230,   231,
     233,   235,   237,   239,   241,   243,   243,   159,   160,   161,
       0,     0,     0,     0,     0,   286,     0,     0,   283,   283,
      87,    88,    89,    90,    91,    92,     0,     0,     0,    95,
      96,     0,     0,     0,     0,   351,     0,     0,     0,   292,
     293,   294,   295,   296,     0,    83,     0,     0,     0,     0,
     110,   111,   112,   113,   114,   157,   158,   159,   160,   161,
      34,   325,   326,   327,   328,   329,   330,   331,   332,     0,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
       0,     0,     0,     2,     0,     0,     3,     4,     5,     6,
       7,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    91,    92,    93,    94,     0,    95,    96,     0,
       0,    18,    19,   101,   102,   103,   104,   105,   106,     0,
     287,     0,     0,    20,    21,     0,     0,   109,    22,     0,
     112,   113,   114,     0,    83,    23,     0,    24,    25,    26,
     291,     0,    27,    28,     3,     4,     5,     6,     7,     0,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
      19,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,    21,     0,     0,     0,    22,   167,     0,     0,
       0,     0,     0,    23,     0,    24,    25,    26,     0,     0,
      27,    28,     3,     4,     5,     6,     7,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    18,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    20,
      21,     0,     0,     0,    22,   264,     0,     0,     0,     0,
       0,    23,     0,    24,    25,    26,     0,     0,    27,    28,
       3,     4,     5,     6,     7,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    20,    21,     0,
       0,     0,    22,   354,     0,     0,     0,     0,     0,    23,
       0,    24,    25,    26,     0,     0,    27,    28,     3,     4,
       5,     6,     7,     0,     8,     9,    71,    72,    73,    13,
      14,    15,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,    21,     0,     0,     0,
      75,     0,     0,     0,     0,     0,     0,    23,     0,    24,
      25,    26,     0,     0,    27,    28,     3,     4,     5,     6,
       7,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     0,     0,     0,     0,     3,     4,     5,     6,
       0,    18,    19,     0,     0,     3,     0,     5,    44,     0,
      16,    17,     0,    20,    21,     0,     0,    44,    22,    16,
      17,    18,    19,     0,     0,    23,     0,    24,    25,    26,
      18,    19,    27,    28,    21,     0,     0,     0,     0,     0,
       0,     0,   168,    46,     0,    23,     0,    24,    25,    26,
       0,     0,    27,    28,    47,     0,    48,    49,    50,     0,
       0,    27,    28,     3,     0,     5,     0,     0,     0,   120,
     121,   122,   123,     0,     0,    44,     0,    16,    17,     0,
     124,   125,   126,   127,     0,     0,     0,     0,    18,    19,
     128,     0,     0,   129,     0,     0,     0,     0,     0,   130,
     131,    46,     0,     0,   132,   133,   134,   135,   136,     0,
       0,     0,    47,     0,    48,    49,    50,     0,     0,    27,
      28,    87,    88,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,     0,     0,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,    87,    88,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   156,     0,     0,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   157,   158,   159,   160,
     161,    87,    88,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,     0,     0,   165,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,    87,    88,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   178,     0,     0,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,    87,    88,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,     0,     0,   253,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   157,   158,   159,   160,
     161,    87,    88,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,     0,     0,   165,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   157,   158,   159,   160,
     161,    87,    88,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   263,     0,     0,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   157,   158,   159,   160,
     161,    87,    88,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,     0,     0,   268,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   157,   158,   159,   160,
     161,    87,    88,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,     0,     0,     0,   108,   269,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   157,   158,   159,   160,
     161,    87,    88,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,     0,     0,     0,   108,   270,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   157,   158,   159,   160,
     161,    87,    88,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   316,     0,     0,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   157,   158,   159,   160,
     161,    87,    88,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,     0,     0,     0,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,    87,    88,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,     0,     0,     0,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   157,   158,   159,   160,
     161,    87,    88,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,     0,     0,     0,     0,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   157,   158,   159,   160,
     161,    87,    88,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   297,   298,   299,   300,   301,   302,   303,   304,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,     0,     0,     0,     0,     0,     0,   305,    95,    96,
       0,     0,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   297,   298,   299,   300,   301,   302,   303,   304,
       0,   112,   113,   114,   157,   158,   159,   160,   161,   297,
     298,   299,   300,   301,   302,   303,   304,   320,     0,     0,
       0,     0,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   324,     0,     0,     0,     0,     0,     0,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   120,
     121,   122,   123,     0,     0,     0,     0,     0,     0,     0,
     124,   125,   126,   127,     0,     0,     0,     0,     0,     0,
       0,     0,   166,   129,     0,     0,     0,     0,     0,   130,
     131,     0,     0,     0,   132,   133,   134,   135,   136,   120,
     121,   122,   123,     0,     0,     0,     0,     0,     0,     0,
     124,   125,   126,   127,     0,     0,     0,     0,     0,     0,
     179,     0,     0,   129,     0,     0,     0,     0,     0,   130,
     131,     0,     0,     0,   132,   133,   134,   135,   136,   120,
     121,   122,   123,     0,     0,     0,     0,     0,     0,     0,
     124,   125,   126,   127,     0,     0,     0,     0,     0,     0,
       0,     0,   261,   129,     0,     0,     0,     0,     0,   130,
     131,     0,     0,     0,   132,   133,   134,   135,   136,   120,
     121,   122,   123,     0,     0,     0,     0,     0,     0,     0,
     124,   125,   126,   127,     0,     0,     0,     0,     0,     0,
       0,     0,   262,   129,     0,     0,     0,     0,     0,   130,
     131,     0,     0,     0,   132,   133,   134,   135,   136,   120,
     121,   122,   123,     0,     0,     0,     0,     0,     0,     0,
     124,   125,   126,   127,     0,     0,     0,     0,     0,     0,
     321,     0,     0,   129,     0,     0,     0,     0,     0,   130,
     131,     0,     0,     0,   132,   133,   134,   135,   136,   120,
     121,   122,   123,     0,     0,     0,     0,     0,     0,     0,
     124,   125,   126,   127,   297,   298,   299,   300,   301,   302,
       0,     0,     0,   129,     0,     0,     0,     0,     0,   130,
     131,     0,     0,     0,   132,   133,   134,   135,   136,     0,
       0,     0,     0,     0,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   120,   121,   122,   123,     0,     0,
       0,     0,     0,     0,     0,   124,   125,   126,   127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   130,   131,     0,     0,     0,   132,
     133,   134,   135,   136,    91,    92,    93,    94,     0,    95,
      96,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,     0,     0,     0,     0,     0,     0,     0,     0,   109,
       0,     0,   112,   113,   114,     0,     0,   117,   118,   119
};

static const yytype_int16 yycheck[] =
{
       1,    22,    43,    42,    30,    31,     5,    30,    47,    10,
       5,    14,    15,    16,    30,     5,    30,    18,    19,    30,
      21,   249,    23,    24,    25,    26,    27,    28,     5,    30,
      31,    78,    79,    42,    40,    40,    40,    43,    47,    43,
      40,    42,    48,     5,    48,    46,    47,    48,    49,    50,
      28,    29,    78,    79,    75,    78,    79,    56,    40,    60,
      86,    56,    78,    79,    78,    79,    56,    78,    79,    41,
      71,    54,    55,    56,    57,    58,    41,    78,    79,    56,
      56,    57,    58,    41,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    56,    40,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,    41,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   349,
     350,   349,   350,   124,   125,   126,   127,    41,   129,    41,
     177,   132,   133,   134,   135,   136,   137,   138,    51,    52,
      53,    54,    55,    56,    57,    58,    41,   148,   174,     3,
      41,   177,    41,     8,   177,     8,   157,   158,   159,   160,
     161,   177,     8,   177,    41,    41,   177,     8,    28,    29,
       8,   172,     8,   174,    40,     8,   177,     8,     3,    21,
       5,    23,    24,    25,    26,     8,     8,    41,    30,    47,
      15,    42,    17,    18,    54,    55,    56,    57,    58,    42,
      54,    55,    47,    28,    29,    59,    60,    42,   249,    14,
      15,    16,    54,    55,    40,    40,    41,    45,    47,   266,
      54,    55,    56,    57,    58,    40,    47,    52,   175,    54,
      55,    56,    28,    29,    59,    60,    78,    79,    28,    29,
     266,    80,    39,   266,    56,    57,    58,   248,    43,    -1,
     266,   138,   266,    -1,    -1,   266,    -1,    -1,    54,    55,
      56,    57,    58,    -1,    -1,   266,    56,    57,    58,    28,
      29,   272,    -1,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,    -1,   288,   130,   131,
     132,   133,   134,   135,   136,   137,   138,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,   251,    -1,    -1,   349,   350,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    28,
      29,    -1,    -1,    -1,    -1,   346,    -1,    -1,    -1,   275,
     276,   277,   278,   279,    -1,   177,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
     351,   297,   298,   299,   300,   301,   302,   303,   304,    -1,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
      -1,    -1,    -1,     0,    -1,    -1,     3,     4,     5,     6,
       7,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    23,    24,    25,    26,    -1,    28,    29,    -1,
      -1,    28,    29,    34,    35,    36,    37,    38,    39,    -1,
     252,    -1,    -1,    40,    41,    -1,    -1,    48,    45,    -1,
      51,    52,    53,    -1,   266,    52,    -1,    54,    55,    56,
     272,    -1,    59,    60,     3,     4,     5,     6,     7,    -1,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    41,    -1,    -1,    -1,    45,    46,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    54,    55,    56,    -1,    -1,
      59,    60,     3,     4,     5,     6,     7,    -1,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      41,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    54,    55,    56,    -1,    -1,    59,    60,
       3,     4,     5,     6,     7,    -1,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,
      -1,    -1,    45,    46,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    54,    55,    56,    -1,    -1,    59,    60,     3,     4,
       5,     6,     7,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    54,
      55,    56,    -1,    -1,    59,    60,     3,     4,     5,     6,
       7,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,    28,    29,    -1,    -1,     3,    -1,     5,    15,    -1,
      17,    18,    -1,    40,    41,    -1,    -1,    15,    45,    17,
      18,    28,    29,    -1,    -1,    52,    -1,    54,    55,    56,
      28,    29,    59,    60,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    41,    -1,    52,    -1,    54,    55,    56,
      -1,    -1,    59,    60,    52,    -1,    54,    55,    56,    -1,
      -1,    59,    60,     3,    -1,     5,    -1,    -1,    -1,    19,
      20,    21,    22,    -1,    -1,    15,    -1,    17,    18,    -1,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    28,    29,
      40,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    49,
      50,    41,    -1,    -1,    54,    55,    56,    57,    58,    -1,
      -1,    -1,    52,    -1,    54,    55,    56,    -1,    -1,    59,
      60,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    19,    20,    21,    22,    23,    24,    25,    26,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    44,    28,    29,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    19,
      20,    21,    22,    23,    24,    25,    26,    44,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,    49,
      50,    -1,    -1,    -1,    54,    55,    56,    57,    58,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    49,
      50,    -1,    -1,    -1,    54,    55,    56,    57,    58,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,    49,
      50,    -1,    -1,    -1,    54,    55,    56,    57,    58,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,    49,
      50,    -1,    -1,    -1,    54,    55,    56,    57,    58,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    49,
      50,    -1,    -1,    -1,    54,    55,    56,    57,    58,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    49,
      50,    -1,    -1,    -1,    54,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    54,
      55,    56,    57,    58,    23,    24,    25,    26,    -1,    28,
      29,    -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    51,    52,    53,    -1,    -1,    56,    57,    58
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    63,     0,     3,     4,     5,     6,     7,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    28,    29,
      40,    41,    45,    52,    54,    55,    56,    59,    60,    64,
      66,    68,    73,    74,    77,    78,    80,    81,    82,    83,
      84,    85,    41,    41,    15,    40,    41,    52,    54,    55,
      56,    77,    40,    40,    41,    41,    77,    77,    77,    78,
      63,    77,    78,    77,    78,    77,    78,    77,    78,    77,
      77,    11,    12,    13,    40,    45,    64,    65,    66,    68,
      73,    74,    77,    78,    64,    41,    72,    19,    20,    21,
      22,    23,    24,    25,    26,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    43,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      19,    20,    21,    22,    30,    31,    32,    33,    40,    43,
      49,    50,    54,    55,    56,    57,    58,    41,    41,     5,
      56,    75,    76,     5,    56,    75,    77,    15,    69,    82,
      84,    77,    77,    77,    77,    77,    40,    54,    55,    56,
      57,    58,    77,    78,    78,    42,    42,    46,    40,    77,
      40,    40,    63,     8,    67,    65,    65,    72,    40,    40,
      77,    64,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    78,    77,
      78,    77,    78,    77,    78,    77,    78,    78,    78,    78,
      78,    77,    78,    77,    78,    77,    78,    77,    78,    77,
      78,    78,    77,    78,    77,    78,    77,    78,    77,    78,
      77,    78,    77,    78,    89,    89,    40,    43,    48,    41,
      40,    43,    48,    42,    70,    77,    77,    77,    77,    77,
      77,    42,    42,    40,    46,    64,    67,    65,    42,    44,
      44,    42,    47,    42,     3,    41,    54,    55,    59,    60,
      79,    77,    14,    82,    83,    86,    79,    78,    40,    65,
      77,    78,    79,    79,    79,    79,    79,    19,    20,    21,
      22,    23,    24,    25,    26,    44,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    40,     5,     5,    42,
      44,    40,    71,    77,    42,    79,    79,    79,    79,    79,
      79,    79,    79,    40,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    87,    88,    45,    40,    42,    47,
      47,    63,    86,    86,    46
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    63,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    74,    75,
      76,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    80,    81,    82,    82,    82,    83,    83,    84,    84,
      84,    84,    84,    84,    85,    86,    86,    87,    86,    86,
      88,    86,    86,    89,    89,    89,    89,    89
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     1,     2,     4,     3,
       2,     3,     3,     2,     2,     2,     1,     2,     2,     1,
       4,     3,     2,     3,     3,     2,     2,     2,     1,     4,
       1,     7,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     4,     4,     4,     4,     1,
       1,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     4,     4,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     2,     1,     2,     3,     5,
       6,     3,     5,     6,     8,     2,     1,     0,     5,     2,
       0,     5,     0,     1,     1,     3,     3,     0
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
#line 104 "parse.y"
             {}
#line 1699 "parse.tab.c"
    break;

  case 5: /* stmt: fexpr ';'  */
#line 105 "parse.y"
                {}
#line 1705 "parse.tab.c"
    break;

  case 6: /* stmt: decl  */
#line 106 "parse.y"
           {}
#line 1711 "parse.tab.c"
    break;

  case 7: /* stmt: if stmt  */
#line 107 "parse.y"
              {
        f_stack[f_top]->f->code[(yyvsp[-1].num)].op1.ival = f_stack[f_top]->f->code_num;
    }
#line 1719 "parse.tab.c"
    break;

  case 8: /* stmt: if stmt_no_if else stmt  */
#line 110 "parse.y"
                              {
        f_stack[f_top]->f->code[(yyvsp[-3].num)].op1.ival = (yyvsp[-1].num) + 1;
        f_stack[f_top]->f->code[(yyvsp[-1].num)].op2.ival = f_stack[f_top]->f->code_num;
    }
#line 1728 "parse.tab.c"
    break;

  case 9: /* stmt: while_start while_cond stmt  */
#line 114 "parse.y"
                                  {
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_JMP, (yyvsp[-2].num)));
        f_stack[f_top]->f->code[(yyvsp[-1].num)].op1.ival = f_stack[f_top]->f->code_num;
        ir_loop_info_apply_and_pop(f_stack[f_top]->f->code_num, (yyvsp[-2].num));
    }
#line 1738 "parse.tab.c"
    break;

  case 10: /* stmt: for stmt  */
#line 119 "parse.y"
               {
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_JMP, (yyvsp[-1].num)));
        f_stack[f_top]->f->code[(yyvsp[-1].num) - 2].op2.ival = f_stack[f_top]->f->code_num;
        ir_loop_info_apply_and_pop(f_stack[f_top]->f->code_num, (yyvsp[-1].num));
    }
#line 1748 "parse.tab.c"
    break;

  case 11: /* stmt: '{' program '}'  */
#line 124 "parse.y"
                      {}
#line 1754 "parse.tab.c"
    break;

  case 12: /* stmt: RETURN expr ';'  */
#line 125 "parse.y"
                      {
        ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_RET, (yyvsp[-1].value)));
    }
#line 1762 "parse.tab.c"
    break;

  case 13: /* stmt: RETURN ';'  */
#line 128 "parse.y"
                 {
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_RET, 0));
    }
#line 1770 "parse.tab.c"
    break;

  case 14: /* stmt: BREAK ';'  */
#line 131 "parse.y"
                {
        ir_loop_info_add(LOOP_BREAK, f_stack[f_top]->f->code_num);
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_JMP, 0));
    }
#line 1779 "parse.tab.c"
    break;

  case 15: /* stmt: CONTINUE ';'  */
#line 135 "parse.y"
                   {
        ir_loop_info_add(LOOP_CONTINUE, f_stack[f_top]->f->code_num);
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_JMP, 0));
    }
#line 1788 "parse.tab.c"
    break;

  case 16: /* stmt: ';'  */
#line 139 "parse.y"
          {}
#line 1794 "parse.tab.c"
    break;

  case 17: /* stmt_no_if: expr ';'  */
#line 142 "parse.y"
             {}
#line 1800 "parse.tab.c"
    break;

  case 18: /* stmt_no_if: fexpr ';'  */
#line 143 "parse.y"
                {}
#line 1806 "parse.tab.c"
    break;

  case 19: /* stmt_no_if: decl  */
#line 144 "parse.y"
           {}
#line 1812 "parse.tab.c"
    break;

  case 20: /* stmt_no_if: if stmt_no_if else stmt_no_if  */
#line 145 "parse.y"
                                    {
        f_stack[f_top]->f->code[(yyvsp[-3].num)].op1.ival = (yyvsp[-1].num) + 1;
        f_stack[f_top]->f->code[(yyvsp[-1].num)].op2.ival = f_stack[f_top]->f->code_num;
    }
#line 1821 "parse.tab.c"
    break;

  case 21: /* stmt_no_if: while_start while_cond stmt_no_if  */
#line 149 "parse.y"
                                        {
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_JMP, (yyvsp[-2].num)));
        f_stack[f_top]->f->code[(yyvsp[-1].num)].op1.ival = f_stack[f_top]->f->code_num;
        ir_loop_info_apply_and_pop(f_stack[f_top]->f->code_num, (yyvsp[-2].num));
    }
#line 1831 "parse.tab.c"
    break;

  case 22: /* stmt_no_if: for stmt_no_if  */
#line 154 "parse.y"
                     {
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_JMP, (yyvsp[-1].num)));
        f_stack[f_top]->f->code[(yyvsp[-1].num) - 2].op2.ival = f_stack[f_top]->f->code_num;
        ir_loop_info_apply_and_pop(f_stack[f_top]->f->code_num, (yyvsp[-1].num));
    }
#line 1841 "parse.tab.c"
    break;

  case 23: /* stmt_no_if: '{' program '}'  */
#line 159 "parse.y"
                      {}
#line 1847 "parse.tab.c"
    break;

  case 24: /* stmt_no_if: RETURN expr ';'  */
#line 160 "parse.y"
                      {
        ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_RET, (yyvsp[-1].value)));
    }
#line 1855 "parse.tab.c"
    break;

  case 25: /* stmt_no_if: RETURN ';'  */
#line 163 "parse.y"
                 {
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_RET, 0));
    }
#line 1863 "parse.tab.c"
    break;

  case 26: /* stmt_no_if: BREAK ';'  */
#line 166 "parse.y"
                {
        ir_loop_info_add(LOOP_BREAK, f_stack[f_top]->f->code_num);
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_JMP, 0));
    }
#line 1872 "parse.tab.c"
    break;

  case 27: /* stmt_no_if: CONTINUE ';'  */
#line 170 "parse.y"
                   {
        ir_loop_info_add(LOOP_CONTINUE, f_stack[f_top]->f->code_num);
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_JMP, 0));
    }
#line 1881 "parse.tab.c"
    break;

  case 28: /* stmt_no_if: ';'  */
#line 174 "parse.y"
          {}
#line 1887 "parse.tab.c"
    break;

  case 29: /* if: IF '(' expr ')'  */
#line 177 "parse.y"
                    {
        (yyval.num) = f_stack[f_top]->f->code_num;
        ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_JMPNOT, (yyvsp[-1].value)));
    }
#line 1896 "parse.tab.c"
    break;

  case 30: /* else: ELSE  */
#line 183 "parse.y"
         {
        (yyval.num) = f_stack[f_top]->f->code_num;
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_JMP, 0));
    }
#line 1905 "parse.tab.c"
    break;

  case 31: /* for: FOR '(' for_var_decl for_cond ';' for_inc ')'  */
#line 189 "parse.y"
                                                  {
        f_stack[f_top]->f->code[(yyvsp[-3].num) - 1].op1.ival = f_stack[f_top]->f->code_num;
        f_stack[f_top]->f->code[(yyvsp[-1].num) - 1].op1.ival = (yyvsp[-4].num);
        (yyval.num) = (yyvsp[-3].num);
        ir_loop_info_push();
    }
#line 1916 "parse.tab.c"
    break;

  case 32: /* for_var_decl: var_decl  */
#line 197 "parse.y"
             {
        (yyval.num) = f_stack[f_top]->f->code_num;
    }
#line 1924 "parse.tab.c"
    break;

  case 33: /* for_cond: expr  */
#line 202 "parse.y"
         {
        ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_JMPNOT, (yyvsp[0].value)));
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_JMP, 0));
        (yyval.num) = f_stack[f_top]->f->code_num;
    }
#line 1934 "parse.tab.c"
    break;

  case 34: /* for_inc: expr  */
#line 209 "parse.y"
         {
        ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_JMP, (yyvsp[0].value)));
        (yyval.num) = f_stack[f_top]->f->code_num;
    }
#line 1943 "parse.tab.c"
    break;

  case 35: /* while_cond: '(' expr ')'  */
#line 215 "parse.y"
                 {
        (yyval.num) = ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_JMPNOT, (yyvsp[-1].value)));
    }
#line 1951 "parse.tab.c"
    break;

  case 36: /* while_start: WHILE  */
#line 220 "parse.y"
          {
        (yyval.num) = f_stack[f_top]->f->code_num;
        ir_loop_info_push();
    }
#line 1960 "parse.tab.c"
    break;

  case 39: /* var_name: NAME  */
#line 230 "parse.y"
         {
        printf("Declaration: %s\n", name);
        (yyval.name) = strdup(name);
    }
#line 1969 "parse.tab.c"
    break;

  case 40: /* func_name: NAME  */
#line 236 "parse.y"
         {
        printf("Function: %s\n", name);
        f_stack[++f_top] = ir_func_ctx_new(ir_func_new(name, 0));
        ir_program_add_func(program, f_stack[f_top]->f);
    }
#line 1979 "parse.tab.c"
    break;

  case 41: /* expr: NUMBER  */
#line 243 "parse.y"
           { (yyval.value) = ir_expr_imm(num); }
#line 1985 "parse.tab.c"
    break;

  case 42: /* expr: CHAR  */
#line 244 "parse.y"
           { (yyval.value) = ir_expr_imm(num); }
#line 1991 "parse.tab.c"
    break;

  case 43: /* expr: NAME  */
#line 245 "parse.y"
           { (yyval.value) = ir_expr_var(ir_func_ctx_get_local(f_stack[f_top], name)); }
#line 1997 "parse.tab.c"
    break;

  case 44: /* expr: STR  */
#line 246 "parse.y"
          { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_lea((yyval.value), name)); }
#line 2003 "parse.tab.c"
    break;

  case 45: /* expr: expr '=' expr  */
#line 247 "parse.y"
                    { ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 2009 "parse.tab.c"
    break;

  case 46: /* expr: expr '+' expr  */
#line 248 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_ADD, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2015 "parse.tab.c"
    break;

  case 47: /* expr: expr '-' expr  */
#line 249 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SUB, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2021 "parse.tab.c"
    break;

  case 48: /* expr: expr '*' expr  */
#line 250 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_MUL, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2027 "parse.tab.c"
    break;

  case 49: /* expr: expr '/' expr  */
#line 251 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_DIV, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2033 "parse.tab.c"
    break;

  case 50: /* expr: expr '%' expr  */
#line 252 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_MOD, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2039 "parse.tab.c"
    break;

  case 51: /* expr: expr '<' expr  */
#line 253 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_LT, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2045 "parse.tab.c"
    break;

  case 52: /* expr: expr '>' expr  */
#line 254 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_GT, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2051 "parse.tab.c"
    break;

  case 53: /* expr: expr LE expr  */
#line 255 "parse.y"
                   { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_LE, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2057 "parse.tab.c"
    break;

  case 54: /* expr: expr GE expr  */
#line 256 "parse.y"
                   { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_GE, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2063 "parse.tab.c"
    break;

  case 55: /* expr: expr EQ expr  */
#line 257 "parse.y"
                   { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_EQ, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2069 "parse.tab.c"
    break;

  case 56: /* expr: expr NE expr  */
#line 258 "parse.y"
                   { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_NE, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2075 "parse.tab.c"
    break;

  case 57: /* expr: expr SHL expr  */
#line 259 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SHL, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2081 "parse.tab.c"
    break;

  case 58: /* expr: expr SHR expr  */
#line 260 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SHR, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2087 "parse.tab.c"
    break;

  case 59: /* expr: '-' expr  */
#line 261 "parse.y"
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_NEG, (yyval.value), (yyvsp[0].value))); }
#line 2093 "parse.tab.c"
    break;

  case 60: /* expr: '+' expr  */
#line 262 "parse.y"
               { (yyval.value) = (yyvsp[0].value); }
#line 2099 "parse.tab.c"
    break;

  case 61: /* expr: '~' expr  */
#line 263 "parse.y"
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_NOT, (yyval.value), (yyvsp[0].value))); }
#line 2105 "parse.tab.c"
    break;

  case 62: /* expr: '!' expr  */
#line 264 "parse.y"
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_LOGIC_NOT, (yyval.value), (yyvsp[0].value))); }
#line 2111 "parse.tab.c"
    break;

  case 63: /* expr: expr '&' expr  */
#line 265 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_AND, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2117 "parse.tab.c"
    break;

  case 64: /* expr: expr '|' expr  */
#line 266 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_OR, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2123 "parse.tab.c"
    break;

  case 65: /* expr: expr '^' expr  */
#line 267 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_XOR, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2129 "parse.tab.c"
    break;

  case 66: /* expr: expr AND expr  */
#line 268 "parse.y"
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_LOGIC_AND, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2135 "parse.tab.c"
    break;

  case 67: /* expr: expr OR expr  */
#line 269 "parse.y"
                   { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_LOGIC_OR, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2141 "parse.tab.c"
    break;

  case 68: /* expr: expr INC  */
#line 270 "parse.y"
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_ADD, (yyvsp[-1].value), (yyvsp[-1].value), ir_expr_imm(1))); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, (yyval.value), (yyvsp[-1].value))); }
#line 2147 "parse.tab.c"
    break;

  case 69: /* expr: expr DEC  */
#line 271 "parse.y"
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SUB, (yyvsp[-1].value), (yyvsp[-1].value), ir_expr_imm(1))); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, (yyval.value), (yyvsp[-1].value))); }
#line 2153 "parse.tab.c"
    break;

  case 70: /* expr: INC expr  */
#line 272 "parse.y"
               { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_ADD, (yyvsp[0].value), (yyvsp[0].value), ir_expr_imm(1))); (yyval.value) = (yyvsp[0].value); }
#line 2159 "parse.tab.c"
    break;

  case 71: /* expr: DEC expr  */
#line 273 "parse.y"
               { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SUB, (yyvsp[0].value), (yyvsp[0].value), ir_expr_imm(1))); (yyval.value) = (yyvsp[0].value); }
#line 2165 "parse.tab.c"
    break;

  case 72: /* expr: expr ADD_ASSIGN expr  */
#line 274 "parse.y"
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_ADD, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 2171 "parse.tab.c"
    break;

  case 73: /* expr: expr SUB_ASSIGN expr  */
#line 275 "parse.y"
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SUB, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 2177 "parse.tab.c"
    break;

  case 74: /* expr: expr MUL_ASSIGN expr  */
#line 276 "parse.y"
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_MUL, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 2183 "parse.tab.c"
    break;

  case 75: /* expr: expr DIV_ASSIGN expr  */
#line 277 "parse.y"
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_DIV, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 2189 "parse.tab.c"
    break;

  case 76: /* expr: expr MOD_ASSIGN expr  */
#line 278 "parse.y"
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_MOD, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 2195 "parse.tab.c"
    break;

  case 77: /* expr: expr SHL_ASSIGN expr  */
#line 279 "parse.y"
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SHL, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 2201 "parse.tab.c"
    break;

  case 78: /* expr: expr SHR_ASSIGN expr  */
#line 280 "parse.y"
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SHR, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 2207 "parse.tab.c"
    break;

  case 79: /* expr: expr AND_ASSIGN expr  */
#line 281 "parse.y"
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_AND, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 2213 "parse.tab.c"
    break;

  case 80: /* expr: expr XOR_ASSIGN expr  */
#line 282 "parse.y"
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_XOR, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 2219 "parse.tab.c"
    break;

  case 81: /* expr: expr OR_ASSIGN expr  */
#line 283 "parse.y"
                          { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_OR, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 2225 "parse.tab.c"
    break;

  case 82: /* expr: '(' expr ')'  */
#line 284 "parse.y"
                   { (yyval.value) = (yyvsp[-1].value); }
#line 2231 "parse.tab.c"
    break;

  case 83: /* expr: '&' expr  */
#line 285 "parse.y"
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); if ((yyvsp[0].value).type == EXPR_IMM){ printf("'&' could not be used on an immediate number\n"); exit(1); } ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_ADDR, (yyval.value), (yyvsp[0].value))); }
#line 2237 "parse.tab.c"
    break;

  case 84: /* expr: '*' expr  */
#line 286 "parse.y"
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, (yyval.value), (yyvsp[0].value))); (yyval.value).type = EXPR_PTR; }
#line 2243 "parse.tab.c"
    break;

  case 85: /* expr: expr '[' expr ']'  */
#line 287 "parse.y"
                        { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_ADD, (yyval.value), ir_expr_imm((yyvsp[-3].value).ival), (yyvsp[-1].value))); (yyval.value) = ir_expr_ref((yyval.value).ival); }
#line 2249 "parse.tab.c"
    break;

  case 86: /* expr: func_call '(' para_list ')'  */
#line 288 "parse.y"
                                  {
        (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top]));
        ir i = ir_new1(IR_CALL, (yyval.value));
        i.op = f_stack[f_top]->f->code[(yyvsp[-3].num)].op;
        f_stack[f_top]->f->code[(yyvsp[-3].num)].op = NULL;
        ir_func_add_code(f_stack[f_top]->f, i);
    }
#line 2261 "parse.tab.c"
    break;

  case 87: /* expr: INT '(' fexpr ')'  */
#line 295 "parse.y"
                        { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_F2I, (yyval.value), (yyvsp[-1].value))); }
#line 2267 "parse.tab.c"
    break;

  case 88: /* expr: CHAR '(' fexpr ')'  */
#line 296 "parse.y"
                         { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_F2I, (yyval.value), (yyvsp[-1].value))); }
#line 2273 "parse.tab.c"
    break;

  case 89: /* fexpr: REAL  */
#line 299 "parse.y"
         { (yyval.value) = ir_expr_fimm(real); }
#line 2279 "parse.tab.c"
    break;

  case 90: /* fexpr: FNAME  */
#line 300 "parse.y"
            { (yyval.value) = ir_expr_var(ir_func_ctx_get_local(f_stack[f_top], name)); }
#line 2285 "parse.tab.c"
    break;

  case 91: /* fexpr: '-' fexpr  */
#line 301 "parse.y"
                { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_FNEG, (yyval.value), (yyvsp[0].value))); }
#line 2291 "parse.tab.c"
    break;

  case 92: /* fexpr: '+' fexpr  */
#line 302 "parse.y"
                { (yyval.value) = (yyvsp[0].value); }
#line 2297 "parse.tab.c"
    break;

  case 93: /* fexpr: '(' fexpr ')'  */
#line 303 "parse.y"
                    { (yyval.value) = (yyvsp[-1].value); }
#line 2303 "parse.tab.c"
    break;

  case 94: /* fexpr: fexpr '+' fexpr  */
#line 305 "parse.y"
                      { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FADD, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2309 "parse.tab.c"
    break;

  case 95: /* fexpr: fexpr '+' expr  */
#line 306 "parse.y"
                     { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, (yyval.value), (yyvsp[0].value))); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FADD, (yyval.value), (yyvsp[-2].value), (yyval.value))); }
#line 2315 "parse.tab.c"
    break;

  case 96: /* fexpr: expr '+' fexpr  */
#line 307 "parse.y"
                     { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, (yyval.value), (yyvsp[-2].value))); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FADD, (yyval.value), (yyval.value), (yyvsp[0].value))); }
#line 2321 "parse.tab.c"
    break;

  case 97: /* fexpr: fexpr '-' fexpr  */
#line 309 "parse.y"
                      { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FSUB, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2327 "parse.tab.c"
    break;

  case 98: /* fexpr: fexpr '-' expr  */
#line 310 "parse.y"
                     { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, (yyval.value), (yyvsp[0].value))); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FSUB, (yyval.value), (yyvsp[-2].value), (yyval.value))); }
#line 2333 "parse.tab.c"
    break;

  case 99: /* fexpr: expr '-' fexpr  */
#line 311 "parse.y"
                     { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, (yyval.value), (yyvsp[-2].value))); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FSUB, (yyval.value), (yyval.value), (yyvsp[0].value))); }
#line 2339 "parse.tab.c"
    break;

  case 100: /* fexpr: fexpr '*' fexpr  */
#line 313 "parse.y"
                      { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FMUL, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2345 "parse.tab.c"
    break;

  case 101: /* fexpr: fexpr '*' expr  */
#line 314 "parse.y"
                     { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, (yyval.value), (yyvsp[0].value))); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FMUL, (yyval.value), (yyvsp[-2].value), (yyval.value))); }
#line 2351 "parse.tab.c"
    break;

  case 102: /* fexpr: expr '*' fexpr  */
#line 315 "parse.y"
                     { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, (yyval.value), (yyvsp[-2].value))); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FMUL, (yyval.value), (yyval.value), (yyvsp[0].value))); }
#line 2357 "parse.tab.c"
    break;

  case 103: /* fexpr: fexpr '/' fexpr  */
#line 317 "parse.y"
                      { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FDIV, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2363 "parse.tab.c"
    break;

  case 104: /* fexpr: fexpr '/' expr  */
#line 318 "parse.y"
                     { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, (yyval.value), (yyvsp[0].value))); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FDIV, (yyval.value), (yyvsp[-2].value), (yyval.value))); }
#line 2369 "parse.tab.c"
    break;

  case 105: /* fexpr: expr '/' fexpr  */
#line 319 "parse.y"
                     { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, (yyval.value), (yyvsp[-2].value))); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FDIV, (yyval.value), (yyval.value), (yyvsp[0].value))); }
#line 2375 "parse.tab.c"
    break;

  case 106: /* fexpr: fexpr '%' fexpr  */
#line 321 "parse.y"
                      { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FMOD, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2381 "parse.tab.c"
    break;

  case 107: /* fexpr: fexpr '%' expr  */
#line 322 "parse.y"
                     { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, (yyval.value), (yyvsp[0].value))); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FMOD, (yyval.value), (yyvsp[-2].value), (yyval.value))); }
#line 2387 "parse.tab.c"
    break;

  case 108: /* fexpr: expr '%' fexpr  */
#line 323 "parse.y"
                     { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, (yyval.value), (yyvsp[-2].value))); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FMOD, (yyval.value), (yyval.value), (yyvsp[0].value))); }
#line 2393 "parse.tab.c"
    break;

  case 109: /* fexpr: fexpr '<' fexpr  */
#line 325 "parse.y"
                      { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FLT, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2399 "parse.tab.c"
    break;

  case 110: /* fexpr: fexpr '>' fexpr  */
#line 326 "parse.y"
                      { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FGT, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2405 "parse.tab.c"
    break;

  case 111: /* fexpr: fexpr LE fexpr  */
#line 327 "parse.y"
                     { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FLE, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2411 "parse.tab.c"
    break;

  case 112: /* fexpr: fexpr GE fexpr  */
#line 329 "parse.y"
                     { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FGE, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2417 "parse.tab.c"
    break;

  case 113: /* fexpr: fexpr EQ fexpr  */
#line 330 "parse.y"
                     { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FEQ, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2423 "parse.tab.c"
    break;

  case 114: /* fexpr: fexpr NE fexpr  */
#line 331 "parse.y"
                     { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FNE, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
#line 2429 "parse.tab.c"
    break;

  case 115: /* fexpr: fexpr ADD_ASSIGN fexpr  */
#line 333 "parse.y"
                             { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FADD, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 2435 "parse.tab.c"
    break;

  case 116: /* fexpr: fexpr ADD_ASSIGN expr  */
#line 334 "parse.y"
                            { ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, (yyvsp[-2].value), (yyvsp[0].value))); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FADD, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[-2].value))); (yyval.value) = (yyvsp[-2].value); }
#line 2441 "parse.tab.c"
    break;

  case 117: /* fexpr: fexpr SUB_ASSIGN fexpr  */
#line 336 "parse.y"
                             { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FSUB, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 2447 "parse.tab.c"
    break;

  case 118: /* fexpr: fexpr SUB_ASSIGN expr  */
#line 337 "parse.y"
                            { ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, (yyvsp[-2].value), (yyvsp[0].value))); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FSUB, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[-2].value))); (yyval.value) = (yyvsp[-2].value); }
#line 2453 "parse.tab.c"
    break;

  case 119: /* fexpr: fexpr MUL_ASSIGN fexpr  */
#line 339 "parse.y"
                             { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FMUL, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 2459 "parse.tab.c"
    break;

  case 120: /* fexpr: fexpr MUL_ASSIGN expr  */
#line 340 "parse.y"
                            { ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, (yyvsp[-2].value), (yyvsp[0].value))); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FMUL, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[-2].value))); (yyval.value) = (yyvsp[-2].value); }
#line 2465 "parse.tab.c"
    break;

  case 121: /* fexpr: fexpr DIV_ASSIGN fexpr  */
#line 342 "parse.y"
                             { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FDIV, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
#line 2471 "parse.tab.c"
    break;

  case 122: /* fexpr: fexpr DIV_ASSIGN expr  */
#line 343 "parse.y"
                            { ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_I2F, (yyvsp[-2].value), (yyvsp[0].value))); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_FDIV, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[-2].value))); (yyval.value) = (yyvsp[-2].value); }
#line 2477 "parse.tab.c"
    break;

  case 123: /* fexpr: '&' fexpr  */
#line 345 "parse.y"
                { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); if ((yyvsp[0].value).type == EXPR_IMM){ printf("'&' could not be used on an immediate number\n"); exit(1); } ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_ADDR, (yyval.value), (yyvsp[0].value))); }
#line 2483 "parse.tab.c"
    break;

  case 124: /* fexpr: '*' fexpr  */
#line 346 "parse.y"
                { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, (yyval.value), (yyvsp[0].value))); (yyval.value).type = EXPR_PTR; }
#line 2489 "parse.tab.c"
    break;

  case 125: /* fexpr: fexpr '[' expr ']'  */
#line 347 "parse.y"
                         { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_ADD, (yyval.value), ir_expr_imm((yyvsp[-3].value).ival), (yyvsp[-1].value))); (yyval.value) = ir_expr_ref((yyval.value).ival); }
#line 2495 "parse.tab.c"
    break;

  case 126: /* fexpr: ffunc_call '(' para_list ')'  */
#line 349 "parse.y"
                                   {
        (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top]));
        ir i = ir_new1(IR_CALL, (yyval.value));
        i.op = f_stack[f_top]->f->code[(yyvsp[-3].num)].op;
        f_stack[f_top]->f->code[(yyvsp[-3].num)].op = NULL;
        ir_func_add_code(f_stack[f_top]->f, i);
    }
#line 2507 "parse.tab.c"
    break;

  case 127: /* constexpr: NUMBER  */
#line 358 "parse.y"
           { (yyval.num) = num; }
#line 2513 "parse.tab.c"
    break;

  case 128: /* constexpr: constexpr '+' constexpr  */
#line 359 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) + (yyvsp[0].num); }
#line 2519 "parse.tab.c"
    break;

  case 129: /* constexpr: constexpr '-' constexpr  */
#line 360 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) - (yyvsp[0].num); }
#line 2525 "parse.tab.c"
    break;

  case 130: /* constexpr: constexpr '*' constexpr  */
#line 361 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) * (yyvsp[0].num); }
#line 2531 "parse.tab.c"
    break;

  case 131: /* constexpr: constexpr '/' constexpr  */
#line 362 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) / (yyvsp[0].num); }
#line 2537 "parse.tab.c"
    break;

  case 132: /* constexpr: constexpr '%' constexpr  */
#line 363 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) % (yyvsp[0].num); }
#line 2543 "parse.tab.c"
    break;

  case 133: /* constexpr: constexpr '<' constexpr  */
#line 364 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) < (yyvsp[0].num); }
#line 2549 "parse.tab.c"
    break;

  case 134: /* constexpr: constexpr '>' constexpr  */
#line 365 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) > (yyvsp[0].num); }
#line 2555 "parse.tab.c"
    break;

  case 135: /* constexpr: constexpr LE constexpr  */
#line 366 "parse.y"
                             { (yyval.num) = (yyvsp[-2].num) <= (yyvsp[0].num); }
#line 2561 "parse.tab.c"
    break;

  case 136: /* constexpr: constexpr GE constexpr  */
#line 367 "parse.y"
                             { (yyval.num) = (yyvsp[-2].num) >= (yyvsp[0].num); }
#line 2567 "parse.tab.c"
    break;

  case 137: /* constexpr: constexpr EQ constexpr  */
#line 368 "parse.y"
                             { (yyval.num) = (yyvsp[-2].num) == (yyvsp[0].num); }
#line 2573 "parse.tab.c"
    break;

  case 138: /* constexpr: constexpr NE constexpr  */
#line 369 "parse.y"
                             { (yyval.num) = (yyvsp[-2].num) != (yyvsp[0].num); }
#line 2579 "parse.tab.c"
    break;

  case 139: /* constexpr: constexpr SHL constexpr  */
#line 370 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) << (yyvsp[0].num); }
#line 2585 "parse.tab.c"
    break;

  case 140: /* constexpr: constexpr SHR constexpr  */
#line 371 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) >> (yyvsp[0].num); }
#line 2591 "parse.tab.c"
    break;

  case 141: /* constexpr: '-' constexpr  */
#line 372 "parse.y"
                    { (yyval.num) = -(yyvsp[0].num); }
#line 2597 "parse.tab.c"
    break;

  case 142: /* constexpr: '+' constexpr  */
#line 373 "parse.y"
                    { (yyval.num) = (yyvsp[0].num); }
#line 2603 "parse.tab.c"
    break;

  case 143: /* constexpr: '~' constexpr  */
#line 374 "parse.y"
                    { (yyval.num) = ~(yyvsp[0].num); }
#line 2609 "parse.tab.c"
    break;

  case 144: /* constexpr: '!' constexpr  */
#line 375 "parse.y"
                    { (yyval.num) = !(yyvsp[0].num); }
#line 2615 "parse.tab.c"
    break;

  case 145: /* constexpr: constexpr '&' constexpr  */
#line 376 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) & (yyvsp[0].num); }
#line 2621 "parse.tab.c"
    break;

  case 146: /* constexpr: constexpr '|' constexpr  */
#line 377 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) | (yyvsp[0].num); }
#line 2627 "parse.tab.c"
    break;

  case 147: /* constexpr: constexpr '^' constexpr  */
#line 378 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) ^ (yyvsp[0].num); }
#line 2633 "parse.tab.c"
    break;

  case 148: /* constexpr: constexpr AND constexpr  */
#line 379 "parse.y"
                              { (yyval.num) = (yyvsp[-2].num) && (yyvsp[0].num); }
#line 2639 "parse.tab.c"
    break;

  case 149: /* constexpr: constexpr OR constexpr  */
#line 380 "parse.y"
                             { (yyval.num) = (yyvsp[-2].num) || (yyvsp[0].num); }
#line 2645 "parse.tab.c"
    break;

  case 150: /* constexpr: '(' constexpr ')'  */
#line 381 "parse.y"
                        { (yyval.num) = (yyvsp[-1].num); }
#line 2651 "parse.tab.c"
    break;

  case 151: /* func_call: NAME  */
#line 384 "parse.y"
         {
        printf("Function Call: %s\n", name);
        ir i = ir_new0(IR_PARAM);
        i.op = strdup(name);
        (yyval.num) = ir_func_add_code(f_stack[f_top]->f, i);
    }
#line 2662 "parse.tab.c"
    break;

  case 152: /* ffunc_call: FNAME  */
#line 392 "parse.y"
          {
        printf("Function Call: %s\n", name);
        ir i = ir_new0(IR_PARAM);
        i.op = strdup(name);
        (yyval.num) = ir_func_add_code(f_stack[f_top]->f, i);
    }
#line 2673 "parse.tab.c"
    break;

  case 158: /* var_decl: type_name var_name ';'  */
#line 409 "parse.y"
                           {
        ir_func_ctx_add_local(f_stack[f_top], (yyvsp[-1].name), 1);
        free((yyvsp[-1].name));
    }
#line 2682 "parse.tab.c"
    break;

  case 159: /* var_decl: type_name var_name '=' expr ';'  */
#line 413 "parse.y"
                                      {
        expr_info id = ir_expr_var(ir_func_ctx_add_local(f_stack[f_top], (yyvsp[-3].name), 1));
        free((yyvsp[-3].name));
        ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, id, (yyvsp[-1].value)));
    }
#line 2692 "parse.tab.c"
    break;

  case 160: /* var_decl: type_name var_name '[' constexpr ']' ';'  */
#line 418 "parse.y"
                                               {
        int length = (int)(yyvsp[-2].num);
        ir_func_ctx_add_local(f_stack[f_top], (yyvsp[-4].name), length);
        free((yyvsp[-4].name));
    }
#line 2702 "parse.tab.c"
    break;

  case 161: /* var_decl: ftype_name var_name ';'  */
#line 423 "parse.y"
                              {
        ir_func_ctx_add_flocal(f_stack[f_top], (yyvsp[-1].name), 1);
        free((yyvsp[-1].name));
    }
#line 2711 "parse.tab.c"
    break;

  case 162: /* var_decl: ftype_name var_name '=' fexpr ';'  */
#line 427 "parse.y"
                                        {
        expr_info id = ir_expr_var(ir_func_ctx_add_flocal(f_stack[f_top], (yyvsp[-3].name), 1));
        free((yyvsp[-3].name));
        ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, id, (yyvsp[-1].value)));
    }
#line 2721 "parse.tab.c"
    break;

  case 163: /* var_decl: ftype_name var_name '[' constexpr ']' ';'  */
#line 432 "parse.y"
                                                {
        int length = (int)(yyvsp[-2].num);
        ir_func_ctx_add_flocal(f_stack[f_top], (yyvsp[-4].name), length);
        free((yyvsp[-4].name));
    }
#line 2731 "parse.tab.c"
    break;

  case 164: /* func_decl: type_name func_name '(' para_decl ')' '{' program '}'  */
#line 438 "parse.y"
                                                          {
        printf("Function End %s\n", f_stack[f_top]->f->name);
        if (f_stack[f_top]->f->code[f_stack[f_top]->f->code_num - 1].ins != IR_RET){
            ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_RET, 0));
        }
        ir_func_ctx_free(f_stack[f_top--]);
    }
#line 2743 "parse.tab.c"
    break;

  case 165: /* para_decl: type_name NAME  */
#line 446 "parse.y"
                   {
        printf("Parameter Declare: %s\n", name);
        ir_func_ctx_add_local(f_stack[f_top], name, 1);
    }
#line 2752 "parse.tab.c"
    break;

  case 167: /* $@1: %empty  */
#line 451 "parse.y"
                     {
        printf("Parameter Declare: %s\n", name);
        ir_func_ctx_add_local(f_stack[f_top], name, 1);
    }
#line 2761 "parse.tab.c"
    break;

  case 169: /* para_decl: ftype_name NAME  */
#line 455 "parse.y"
                      {
        printf("Parameter Declare: %s\n", name);
        ir_func_ctx_add_flocal(f_stack[f_top], name, 1);
    }
#line 2770 "parse.tab.c"
    break;

  case 170: /* $@2: %empty  */
#line 459 "parse.y"
                      {
        printf("Parameter Declare: %s\n", name);
        ir_func_ctx_add_flocal(f_stack[f_top], name, 1);
    }
#line 2779 "parse.tab.c"
    break;

  case 172: /* para_decl: %empty  */
#line 463 "parse.y"
      {}
#line 2785 "parse.tab.c"
    break;

  case 173: /* para_list: expr  */
#line 466 "parse.y"
         { ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_PASS, (yyvsp[0].value))); }
#line 2791 "parse.tab.c"
    break;

  case 174: /* para_list: fexpr  */
#line 467 "parse.y"
            { ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_PASS, (yyvsp[0].value))); }
#line 2797 "parse.tab.c"
    break;

  case 175: /* para_list: para_list ',' expr  */
#line 468 "parse.y"
                         { ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_PASS, (yyvsp[0].value))); }
#line 2803 "parse.tab.c"
    break;

  case 176: /* para_list: para_list ',' fexpr  */
#line 469 "parse.y"
                          { ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_PASS, (yyvsp[0].value))); }
#line 2809 "parse.tab.c"
    break;

  case 177: /* para_list: %empty  */
#line 470 "parse.y"
      {}
#line 2815 "parse.tab.c"
    break;


#line 2819 "parse.tab.c"

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

#line 472 "parse.y"


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
