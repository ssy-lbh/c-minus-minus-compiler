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

ir_program *program = NULL;

ir_func_ctx *f_stack[0x40];
int f_top = -1;

extern long num;
extern char name[0x400];
extern FILE* yyin;

#include "parse.tab.h"

enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      
  YYSYMBOL_YYerror = 1,                    
  YYSYMBOL_YYUNDEF = 2,                    
  YYSYMBOL_NUMBER = 3,                     
  YYSYMBOL_NAME = 4,                       
  YYSYMBOL_IF = 5,                         
  YYSYMBOL_ELSE = 6,                       
  YYSYMBOL_WHILE = 7,                      
  YYSYMBOL_FOR = 8,                        
  YYSYMBOL_RETURN = 9,                     
  YYSYMBOL_VOID = 10,                      
  YYSYMBOL_INT = 11,                       
  YYSYMBOL_FLOAT = 12,                     
  YYSYMBOL_STR = 13,                       
  YYSYMBOL_CHAR = 14,                      
  YYSYMBOL_LE = 15,                        
  YYSYMBOL_GE = 16,                        
  YYSYMBOL_EQ = 17,                        
  YYSYMBOL_NE = 18,                        
  YYSYMBOL_SHL = 19,                       
  YYSYMBOL_SHR = 20,                       
  YYSYMBOL_AND = 21,                       
  YYSYMBOL_OR = 22,                        
  YYSYMBOL_ARROW = 23,                     
  YYSYMBOL_INC = 24,                       
  YYSYMBOL_DEC = 25,                       
  YYSYMBOL_ADD_ASSIGN = 26,                
  YYSYMBOL_SUB_ASSIGN = 27,                
  YYSYMBOL_MUL_ASSIGN = 28,                
  YYSYMBOL_DIV_ASSIGN = 29,                
  YYSYMBOL_MOD_ASSIGN = 30,                
  YYSYMBOL_SHL_ASSIGN = 31,                
  YYSYMBOL_SHR_ASSIGN = 32,                
  YYSYMBOL_AND_ASSIGN = 33,                
  YYSYMBOL_XOR_ASSIGN = 34,                
  YYSYMBOL_OR_ASSIGN = 35,                 
  YYSYMBOL_36_ = 36,                       
  YYSYMBOL_37_ = 37,                       
  YYSYMBOL_38_ = 38,                       
  YYSYMBOL_39_ = 39,                       
  YYSYMBOL_40_ = 40,                       
  YYSYMBOL_41_ = 41,                       
  YYSYMBOL_42_ = 42,                       
  YYSYMBOL_43_ = 43,                       
  YYSYMBOL_44_ = 44,                       
  YYSYMBOL_45_ = 45,                       
  YYSYMBOL_46_ = 46,                       
  YYSYMBOL_47_ = 47,                       
  YYSYMBOL_48_ = 48,                       
  YYSYMBOL_49_ = 49,                       
  YYSYMBOL_50_ = 50,                       
  YYSYMBOL_51_ = 51,                       
  YYSYMBOL_52_ = 52,                       
  YYSYMBOL_53_ = 53,                       
  YYSYMBOL_54_ = 54,                       
  YYSYMBOL_55_ = 55,                       
  YYSYMBOL_56_ = 56,                       
  YYSYMBOL_57_ = 57,                       
  YYSYMBOL_YYACCEPT = 58,                  
  YYSYMBOL_program = 59,                   
  YYSYMBOL_stmt = 60,                      
  YYSYMBOL_stmt_no_if = 61,                
  YYSYMBOL_if = 62,                        
  YYSYMBOL_else = 63,                      
  YYSYMBOL_while_cond = 64,                
  YYSYMBOL_while_start = 65,               
  YYSYMBOL_decl = 66,                      
  YYSYMBOL_var_name = 67,                  
  YYSYMBOL_func_name = 68,                 
  YYSYMBOL_expr = 69,                      
  YYSYMBOL_constexpr = 70,                 
  YYSYMBOL_func_call = 71,                 
  YYSYMBOL_type_name = 72,                 
  YYSYMBOL_var_decl = 73,                  
  YYSYMBOL_func_decl = 74,                 
  YYSYMBOL_para_decl = 75,                 
  YYSYMBOL_76_1 = 76,                      
  YYSYMBOL_para_list = 77                  
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> 
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> 
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
#   include <stddef.h> 
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
#  include <stddef.h> 
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



typedef yytype_uint8 yy_state_t;


typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> 
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


#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) 
#endif


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
# define YY_INITIAL_VALUE(Value) 
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



# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> 
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> 
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> 
      
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   
#  define YYSTACK_FREE(Ptr) do { ; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 
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
#   include <stdlib.h> 
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); 
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); 
#   endif
#  endif
# endif
#endif 

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))


union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};


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
#endif 


#define YYFINAL  2

#define YYLAST   1067

#define YYNTOKENS  58

#define YYNNTS  20

#define YYNRULES  114

#define YYNSTATES  220


#define YYMAXUTOK   290


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
       2,     2,     2,    56,     2,     2,     2,    54,    48,     2,
      37,    38,    52,    50,    43,    51,    57,    53,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
      45,    44,    46,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,    47,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,    49,    42,    55,     2,     2,     2,
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
      35
};

#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#define YYPACT_NINF (-124)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-110)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -124,   108,  -124,  -124,   -12,     1,  -124,   409,  -124,  -124,
    -124,  -124,   467,   467,  -124,   467,  -124,   467,   467,   467,
     467,   467,   467,  -124,   326,     5,  -124,   509,    12,    18,
    -124,  -124,   467,  -124,   549,  -124,  -124,   589,   164,   100,
      77,    77,     3,  -124,  -124,   438,    -4,  -124,  -124,    17,
     326,     5,    26,   629,   467,   380,   467,   467,   467,   467,
     467,   467,   467,   467,  -124,  -124,   467,   467,   467,   467,
     467,   467,   467,   467,   467,   467,  -124,   467,   467,   467,
     467,   467,   467,   467,   467,   467,   467,   467,   467,   467,
      21,  -124,   -15,    49,   669,  -124,  -124,  -124,    34,   709,
     218,  -124,   380,    17,   326,    81,   749,  -124,   186,   186,
     186,   186,   186,   186,   949,   949,   909,   909,   909,   909,
     909,   909,   909,   909,   909,   909,   789,   909,   186,   186,
     100,   100,   100,    77,    77,     3,     3,     3,   869,   -35,
    -124,   135,   467,    36,  -124,    83,    85,  -124,   326,  -124,
    -124,  -124,  -124,   467,  -124,   135,   135,   135,   135,   135,
     930,   829,    54,    33,    56,  -124,   869,   970,   -19,   -19,
    -124,  -124,   135,   135,   135,   135,   135,   135,   135,   135,
      59,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,  -124,    53,    63,  -124,   197,   197,   197,   197,   197,
     197,   994,   994,  -124,   197,   197,   129,   129,   129,   -19,
     -19,  -124,  -124,  -124,    57,  -124,    36,   272,  -124,  -124
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,    29,    31,     0,    24,     0,   101,   100,
      32,    30,     0,     0,    12,     0,     2,     0,     0,     0,
       0,     0,     0,     3,     0,     0,     5,     0,     0,     0,
      25,    26,     0,    11,     0,    58,    59,     0,     0,    71,
      48,    47,    72,    49,    50,     0,    12,     2,     6,     0,
       0,     0,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    56,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   114,
      27,   102,     0,     0,     0,    10,    70,     9,    11,     0,
       0,    22,     0,     0,     0,     4,     0,     8,    41,    42,
      43,    44,    45,    46,    54,    55,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     0,    33,    39,    40,
      53,    51,    52,    34,    35,    36,    37,    38,   112,     0,
     103,     0,     0,   111,    21,    10,     9,     7,     0,    16,
      23,    73,    74,     0,    75,     0,     0,     0,     0,     0,
       0,     0,   101,     0,     0,    15,   113,     0,    90,    89,
      91,    92,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   104,   107,     0,    98,    83,    84,    85,    86,    87,
      88,    96,    97,   105,    81,    82,    95,    93,    94,    76,
      77,    78,    79,    80,     0,     2,   111,     0,   110,   106
};


static const yytype_int16 yypgoto[] =
{
    -124,   -16,   -14,   -45,   -20,     2,    55,    -7,    -5,  -124,
    -124,    -6,   877,  -124,  -123,  -124,  -124,  -109,  -124,  -124
};


static const yytype_uint8 yydefgoto[] =
{
       0,     1,    23,    49,    24,   102,    55,    25,    26,    92,
      93,    27,   160,    28,    29,    30,    31,   164,   214,   139
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      38,    34,   -20,   152,    50,   103,    35,    36,   153,    37,
      48,    39,    40,    41,    42,    43,    44,    51,    53,    52,
     163,   140,    90,   101,   141,   -99,    94,    64,    65,   142,
      50,   100,   -14,   188,   189,   190,    48,   192,    32,    99,
     -19,   107,    54,    51,    53,    52,   162,     9,   106,    89,
     108,   109,   110,   111,   112,   113,   114,   115,   -28,   149,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      91,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,    50,    91,   143,   -13,   147,   -18,
     107,   -17,  -108,   163,   193,   203,  -109,    51,    53,    52,
     216,    64,    65,   165,   215,   148,   104,   218,     2,     0,
       0,     3,     4,     5,     0,     6,     0,     7,     8,     9,
       0,    10,    11,     0,    64,    65,     0,     0,    50,    86,
      87,    88,    12,    13,   147,     0,   161,     0,   154,     0,
       0,    51,    53,    52,    14,    15,     0,   166,     0,    16,
      84,    85,    86,    87,    88,     0,    17,     0,    18,    19,
      20,     0,     0,    21,    22,     0,     0,     3,     4,     5,
       0,     6,   155,     7,     8,     9,     0,    10,    11,   186,
     187,   188,   189,   190,     0,   156,   157,     0,    12,    13,
     158,   159,     0,     0,     0,     0,     0,     0,     0,   217,
      14,    15,     0,     0,     0,    16,    97,     0,     0,     0,
      64,    65,    17,     0,    18,    19,    20,     0,     0,    21,
      22,     3,     4,     5,     0,     6,     0,     7,     8,     9,
       0,    10,    11,    81,    82,    83,    84,    85,    86,    87,
      88,     0,    12,    13,   183,   184,   185,   186,   187,   188,
     189,   190,     0,     0,    14,    15,     0,     0,     0,    16,
     146,     0,     0,     0,     0,     0,    17,     0,    18,    19,
      20,     0,     0,    21,    22,     3,     4,     5,     0,     6,
       0,     7,     8,     9,     0,    10,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    12,    13,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    14,    15,
       0,     0,     0,    16,   219,     0,     0,     0,     0,     0,
      17,     0,    18,    19,    20,     0,     0,    21,    22,     3,
       4,     5,     0,     6,     0,    45,     8,     9,     0,    10,
      11,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      12,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    46,    15,     0,     0,     0,    47,     0,     0,
       0,     0,     0,     0,    17,     0,    18,    19,    20,     0,
       0,    21,    22,     3,     4,     5,     0,     6,     0,     7,
       8,     9,     0,    10,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,    13,     0,     0,     0,     0,
       0,     0,     3,     4,     0,     0,    14,    15,     0,     0,
       0,    16,    10,    11,     0,     0,     0,     0,    17,     0,
      18,    19,    20,    12,    13,    21,    22,     0,     0,     0,
       0,     3,     4,     0,     0,    33,    15,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    17,     0,    18,
      19,    20,    12,    13,    21,    22,     0,     0,     0,     0,
       3,     4,     0,     0,    98,    15,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    17,     0,    18,    19,
      20,    12,    13,    21,    22,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,     0,    18,    19,    20,
       0,     0,    21,    22,    56,    57,    58,    59,    60,    61,
      62,    63,     0,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,     0,     0,    77,     0,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    56,    57,    58,    59,    60,    61,
      62,    63,     0,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    95,     0,     0,    77,     0,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    56,    57,    58,    59,    60,    61,
      62,    63,     0,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,     0,     0,    96,    77,     0,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    56,    57,    58,    59,    60,    61,
      62,    63,     0,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,   105,     0,     0,    77,     0,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    56,    57,    58,    59,    60,    61,
      62,    63,     0,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,     0,     0,   144,    77,     0,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    56,    57,    58,    59,    60,    61,
      62,    63,     0,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,   145,     0,     0,    77,     0,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    56,    57,    58,    59,    60,    61,
      62,    63,     0,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,     0,     0,   150,    77,     0,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    56,    57,    58,    59,    60,    61,
      62,    63,     0,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,     0,     0,     0,    77,   151,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    56,    57,    58,    59,    60,    61,
      62,    63,     0,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,   191,     0,     0,    77,     0,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    56,    57,    58,    59,    60,    61,
      62,    63,     0,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,     0,     0,     0,    77,     0,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    56,    57,    58,    59,    60,    61,
      62,    63,     0,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,   172,   173,   174,   175,   176,
     177,   178,   179,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    56,    57,    58,    59,    60,    61,
     180,     0,     0,    64,    65,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   172,   173,   174,   175,   176,
     177,   178,   179,     0,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,     0,     0,     0,     0,   194,   172,
     173,   174,   175,   176,   177,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,     0,     0,     0,     0,     0,
       0,     0,   167,   168,   169,   170,   171,     0,     0,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   195,
     196,   197,   198,   199,   200,   201,   202,     0,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213
};

static const yytype_int16 yycheck[] =
{
      16,     7,     6,    38,    24,    50,    12,    13,    43,    15,
      24,    17,    18,    19,    20,    21,    22,    24,    24,    24,
     143,    36,     4,     6,    39,    37,    32,    24,    25,    44,
      50,    47,     6,    52,    53,    54,    50,     4,    37,    45,
       6,    55,    37,    50,    50,    50,    10,    11,    54,    37,
      56,    57,    58,    59,    60,    61,    62,    63,    37,   104,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      52,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,   104,    52,    37,     6,   102,     6,
     104,     6,    38,   216,    38,    36,    43,   104,   104,   104,
      43,    24,    25,   148,    41,   103,    51,   216,     0,    -1,
      -1,     3,     4,     5,    -1,     7,    -1,     9,    10,    11,
      -1,    13,    14,    -1,    24,    25,    -1,    -1,   148,    52,
      53,    54,    24,    25,   148,    -1,   142,    -1,     3,    -1,
      -1,   148,   148,   148,    36,    37,    -1,   153,    -1,    41,
      50,    51,    52,    53,    54,    -1,    48,    -1,    50,    51,
      52,    -1,    -1,    55,    56,    -1,    -1,     3,     4,     5,
      -1,     7,    37,     9,    10,    11,    -1,    13,    14,    50,
      51,    52,    53,    54,    -1,    50,    51,    -1,    24,    25,
      55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,
      36,    37,    -1,    -1,    -1,    41,    42,    -1,    -1,    -1,
      24,    25,    48,    -1,    50,    51,    52,    -1,    -1,    55,
      56,     3,     4,     5,    -1,     7,    -1,     9,    10,    11,
      -1,    13,    14,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    24,    25,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    36,    37,    -1,    -1,    -1,    41,
      42,    -1,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    -1,    -1,    55,    56,     3,     4,     5,    -1,     7,
      -1,     9,    10,    11,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      -1,    -1,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    50,    51,    52,    -1,    -1,    55,    56,     3,
       4,     5,    -1,     7,    -1,     9,    10,    11,    -1,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    50,    51,    52,    -1,
      -1,    55,    56,     3,     4,     5,    -1,     7,    -1,     9,
      10,    11,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,    -1,    -1,    36,    37,    -1,    -1,
      -1,    41,    13,    14,    -1,    -1,    -1,    -1,    48,    -1,
      50,    51,    52,    24,    25,    55,    56,    -1,    -1,    -1,
      -1,     3,     4,    -1,    -1,    36,    37,    -1,    -1,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    24,    25,    55,    56,    -1,    -1,    -1,    -1,
       3,     4,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,
      13,    14,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    24,    25,    55,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,    52,
      -1,    -1,    55,    56,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    38,    39,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    38,    39,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    38,    39,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    39,    40,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    15,    16,    17,    18,    19,
      20,    21,    22,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    15,    16,    17,    18,    19,    20,
      40,    -1,    -1,    24,    25,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,    -1,    -1,    38,    15,
      16,    17,    18,    19,    20,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   155,   156,   157,   158,   159,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,   172,
     173,   174,   175,   176,   177,   178,   179,    -1,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    59,     0,     3,     4,     5,     7,     9,    10,    11,
      13,    14,    24,    25,    36,    37,    41,    48,    50,    51,
      52,    55,    56,    60,    62,    65,    66,    69,    71,    72,
      73,    74,    37,    36,    69,    69,    69,    69,    59,    69,
      69,    69,    69,    69,    69,     9,    36,    41,    60,    61,
      62,    65,    66,    69,    37,    64,    15,    16,    17,    18,
      19,    20,    21,    22,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    39,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    37,
       4,    52,    67,    68,    69,    36,    38,    42,    36,    69,
      59,     6,    63,    61,    64,    36,    69,    60,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    77,
      36,    39,    44,    37,    38,    36,    42,    60,    63,    61,
      38,    40,    38,    43,     3,    37,    50,    51,    55,    56,
      70,    69,    10,    72,    75,    61,    69,    70,    70,    70,
      70,    70,    15,    16,    17,    18,    19,    20,    21,    22,
      40,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    36,     4,    38,    38,    70,    70,    70,    70,    70,
      70,    70,    70,    36,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    76,    41,    43,    59,    75,    42
};


static const yytype_int8 yyr1[] =
{
       0,    58,    59,    59,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    61,    61,    61,    61,    61,    61,    61,
      61,    62,    63,    64,    65,    66,    66,    67,    68,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    71,
      72,    72,    72,    73,    73,    73,    74,    75,    75,    76,
      75,    75,    77,    77,    77
};


static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     2,     4,     3,     3,
       3,     2,     1,     2,     1,     4,     3,     3,     3,     2,
       1,     4,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     4,     4,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     2,     3,     5,     6,     8,     2,     1,     0,
       5,     0,     1,     3,     0
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



#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> 
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
#else 
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif 



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



int yychar;


YYSTYPE yylval;

int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  
  int yyresult;
  
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; 

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
# else 
      
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
#endif 


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  

  
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

  
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  
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
  case 4: 
             {}
    break;

  case 5: 
           {}
    break;

  case 6: 
              {
        f_stack[f_top]->f->code[(yyvsp[-1].num)].op1.ival = f_stack[f_top]->f->code_num;
    }
    break;

  case 7: 
                              {
        f_stack[f_top]->f->code[(yyvsp[-3].num)].op1.ival = (yyvsp[-1].num) + 1;
        f_stack[f_top]->f->code[(yyvsp[-1].num)].op2.ival = f_stack[f_top]->f->code_num;
    }
    break;

  case 8: 
                                  {
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_JMP, (yyvsp[-2].num)));
        f_stack[f_top]->f->code[(yyvsp[-1].num)].op1.ival = f_stack[f_top]->f->code_num;
    }
    break;

  case 9: 
                      {}
    break;

  case 10: 
                      {
        ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_RET, (yyvsp[-1].value)));
    }
    break;

  case 11: 
                 {
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_RET, 0));
    }
    break;

  case 12: 
          {}
    break;

  case 13: 
             {}
    break;

  case 14: 
           {}
    break;

  case 15: 
                                    {
        f_stack[f_top]->f->code[(yyvsp[-3].num)].op1.ival = (yyvsp[-1].num) + 1;
        f_stack[f_top]->f->code[(yyvsp[-1].num)].op2.ival = f_stack[f_top]->f->code_num;
    }
    break;

  case 16: 
                                        {
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_JMP, (yyvsp[-2].num)));
        f_stack[f_top]->f->code[(yyvsp[-1].num)].op1.ival = f_stack[f_top]->f->code_num;
    }
    break;

  case 17: 
                      {}
    break;

  case 18: 
                      {
        ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_RET, (yyvsp[-1].value)));
    }
    break;

  case 19: 
                 {
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_RET, 0));
    }
    break;

  case 20: 
          {}
    break;

  case 21: 
                    {
        (yyval.num) = f_stack[f_top]->f->code_num;
        ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_JMPNOT, (yyvsp[-1].value)));
    }
    break;

  case 22: 
         {
        (yyval.num) = f_stack[f_top]->f->code_num;
        ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_JMP, 0));
    }
    break;

  case 23: 
                 {
        (yyval.num) = ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_JMPNOT, (yyvsp[-1].value)));
    }
    break;

  case 24: 
          {
        (yyval.num) = f_stack[f_top]->f->code_num;
    }
    break;

  case 27: 
         {
        printf("Declaration: %s\n", name);
        (yyval.name) = strdup(name);
    }
    break;

  case 28: 
         {
        printf("Function: %s\n", name);
        f_stack[++f_top] = ir_func_ctx_new(ir_func_new(name, 0));
        ir_program_add_func(program, f_stack[f_top]->f);
    }
    break;

  case 29: 
           { (yyval.value) = ir_expr_imm(num); }
    break;

  case 30: 
           { (yyval.value) = ir_expr_imm(num); }
    break;

  case 31: 
           { (yyval.value) = ir_expr_var(ir_func_ctx_get_local(f_stack[f_top], name)); }
    break;

  case 32: 
          { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_lea((yyval.value), name)); }
    break;

  case 33: 
                    { ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
    break;

  case 34: 
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_ADD, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
    break;

  case 35: 
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SUB, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
    break;

  case 36: 
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_MUL, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
    break;

  case 37: 
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_DIV, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
    break;

  case 38: 
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_MOD, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
    break;

  case 39: 
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_LT, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
    break;

  case 40: 
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_GT, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
    break;

  case 41: 
                   { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_LE, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
    break;

  case 42: 
                   { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_GE, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
    break;

  case 43: 
                   { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_EQ, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
    break;

  case 44: 
                   { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_NE, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
    break;

  case 45: 
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SHL, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
    break;

  case 46: 
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SHR, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
    break;

  case 47: 
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_NEG, (yyval.value), (yyvsp[0].value))); }
    break;

  case 48: 
               { (yyval.value) = (yyvsp[0].value); }
    break;

  case 49: 
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_NOT, (yyval.value), (yyvsp[0].value))); }
    break;

  case 50: 
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_LOGIC_NOT, (yyval.value), (yyvsp[0].value))); }
    break;

  case 51: 
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_AND, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
    break;

  case 52: 
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_OR, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
    break;

  case 53: 
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_XOR, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
    break;

  case 54: 
                    { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_LOGIC_AND, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
    break;

  case 55: 
                   { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_LOGIC_OR, (yyval.value), (yyvsp[-2].value), (yyvsp[0].value))); }
    break;

  case 56: 
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_ADD, (yyvsp[-1].value), (yyvsp[-1].value), ir_expr_imm(1))); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, (yyval.value), (yyvsp[-1].value))); }
    break;

  case 57: 
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SUB, (yyvsp[-1].value), (yyvsp[-1].value), ir_expr_imm(1))); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, (yyval.value), (yyvsp[-1].value))); }
    break;

  case 58: 
               { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_ADD, (yyvsp[0].value), (yyvsp[0].value), ir_expr_imm(1))); (yyval.value) = (yyvsp[0].value); }
    break;

  case 59: 
               { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SUB, (yyvsp[0].value), (yyvsp[0].value), ir_expr_imm(1))); (yyval.value) = (yyvsp[0].value); }
    break;

  case 60: 
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_ADD, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
    break;

  case 61: 
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SUB, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
    break;

  case 62: 
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_MUL, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
    break;

  case 63: 
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_DIV, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
    break;

  case 64: 
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_MOD, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
    break;

  case 65: 
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SHL, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
    break;

  case 66: 
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_SHR, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
    break;

  case 67: 
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_AND, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
    break;

  case 68: 
                           { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_XOR, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
    break;

  case 69: 
                          { ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_OR, (yyvsp[-2].value), (yyvsp[-2].value), (yyvsp[0].value))); (yyval.value) = (yyvsp[-2].value); }
    break;

  case 70: 
                   { (yyval.value) = (yyvsp[-1].value); }
    break;

  case 71: 
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); if ((yyvsp[0].value).type == EXPR_IMM){ printf("'&' could not be used on an immediate number\n"); exit(1); } ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_ADDR, (yyval.value), (yyvsp[0].value))); }
    break;

  case 72: 
               { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, (yyval.value), (yyvsp[0].value))); (yyval.value).type = EXPR_PTR; }
    break;

  case 73: 
                        { (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top])); ir_func_add_code(f_stack[f_top]->f, ir_new3(IR_ADD, (yyval.value), ir_expr_imm((yyvsp[-3].value).ival), (yyvsp[-1].value))); (yyval.value) = ir_expr_ref((yyval.value).ival); }
    break;

  case 74: 
                                  {
        (yyval.value) = ir_expr_var(ir_func_ctx_inc_local(f_stack[f_top]));
        ir i = ir_new1(IR_CALL, (yyval.value));
        i.op = f_stack[f_top]->f->code[(yyvsp[-3].num)].op;
        f_stack[f_top]->f->code[(yyvsp[-3].num)].op = NULL;
        ir_func_add_code(f_stack[f_top]->f, i);
    }
    break;

  case 75: 
           { (yyval.num) = num; }
    break;

  case 76: 
                              { (yyval.num) = (yyvsp[-2].num) + (yyvsp[0].num); }
    break;

  case 77: 
                              { (yyval.num) = (yyvsp[-2].num) - (yyvsp[0].num); }
    break;

  case 78: 
                              { (yyval.num) = (yyvsp[-2].num) * (yyvsp[0].num); }
    break;

  case 79: 
                              { (yyval.num) = (yyvsp[-2].num) / (yyvsp[0].num); }
    break;

  case 80: 
                              { (yyval.num) = (yyvsp[-2].num) % (yyvsp[0].num); }
    break;

  case 81: 
                              { (yyval.num) = (yyvsp[-2].num) < (yyvsp[0].num); }
    break;

  case 82: 
                              { (yyval.num) = (yyvsp[-2].num) > (yyvsp[0].num); }
    break;

  case 83: 
                             { (yyval.num) = (yyvsp[-2].num) <= (yyvsp[0].num); }
    break;

  case 84: 
                             { (yyval.num) = (yyvsp[-2].num) >= (yyvsp[0].num); }
    break;

  case 85: 
                             { (yyval.num) = (yyvsp[-2].num) == (yyvsp[0].num); }
    break;

  case 86: 
                             { (yyval.num) = (yyvsp[-2].num) != (yyvsp[0].num); }
    break;

  case 87: 
                              { (yyval.num) = (yyvsp[-2].num) << (yyvsp[0].num); }
    break;

  case 88: 
                              { (yyval.num) = (yyvsp[-2].num) >> (yyvsp[0].num); }
    break;

  case 89: 
                    { (yyval.num) = -(yyvsp[0].num); }
    break;

  case 90: 
                    { (yyval.num) = (yyvsp[0].num); }
    break;

  case 91: 
                    { (yyval.num) = ~(yyvsp[0].num); }
    break;

  case 92: 
                    { (yyval.num) = !(yyvsp[0].num); }
    break;

  case 93: 
                              { (yyval.num) = (yyvsp[-2].num) & (yyvsp[0].num); }
    break;

  case 94: 
                              { (yyval.num) = (yyvsp[-2].num) | (yyvsp[0].num); }
    break;

  case 95: 
                              { (yyval.num) = (yyvsp[-2].num) ^ (yyvsp[0].num); }
    break;

  case 96: 
                              { (yyval.num) = (yyvsp[-2].num) && (yyvsp[0].num); }
    break;

  case 97: 
                             { (yyval.num) = (yyvsp[-2].num) || (yyvsp[0].num); }
    break;

  case 98: 
                        { (yyval.num) = (yyvsp[-1].num); }
    break;

  case 99: 
         {
        printf("Function Call: %s\n", name);
        ir i = ir_new0(IR_PARAM);
        i.op = strdup(name);
        (yyval.num) = ir_func_add_code(f_stack[f_top]->f, i);
    }
    break;

  case 103: 
                           {
        ir_func_ctx_add_local(f_stack[f_top], (yyvsp[-1].name), 1);
        free((yyvsp[-1].name));
    }
    break;

  case 104: 
                                      {
        expr_info id = ir_expr_var(ir_func_ctx_add_local(f_stack[f_top], (yyvsp[-3].name), 1));
        free((yyvsp[-3].name));
        ir_func_add_code(f_stack[f_top]->f, ir_new2(IR_MOV, id, (yyvsp[-1].value)));
    }
    break;

  case 105: 
                                               {
        int length = (int)(yyvsp[-2].num);
        ir_func_ctx_add_local(f_stack[f_top], (yyvsp[-4].name), length);
        free((yyvsp[-4].name));
    }
    break;

  case 106: 
                                                          {
        printf("Function End %s\n", f_stack[f_top]->f->name);
        if (f_stack[f_top]->f->code[f_stack[f_top]->f->code_num - 1].ins != IR_RET){
            ir_func_add_code(f_stack[f_top]->f, ir_imm1(IR_RET, 0));
        }
        ir_func_ctx_free(f_stack[f_top--]);
    }
    break;

  case 107: 
                   {
        printf("Parameter Declare: %s\n", name);
        ir_func_ctx_add_local(f_stack[f_top], name, 1);
    }
    break;

  case 109: 
                     {
        printf("Parameter Declare: %s\n", name);
        ir_func_ctx_add_local(f_stack[f_top], name, 1);
    }
    break;

  case 111: 
      {}
    break;

  case 112: 
         { ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_PASS, (yyvsp[0].value))); }
    break;

  case 113: 
                         { ir_func_add_code(f_stack[f_top]->f, ir_var1(IR_PASS, (yyvsp[0].value))); }
    break;

  case 114: 
      {}
    break;



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
  yyerrstatus = 3;      

  
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
