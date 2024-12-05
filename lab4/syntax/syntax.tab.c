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
#line 4 "syntax.y"

    #include "parser.h"

#line 75 "syntax.tab.c"

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

#include "syntax.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_VOID = 5,                       /* VOID  */
  YYSYMBOL_CONST = 6,                      /* CONST  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_BREAK = 10,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 11,                  /* CONTINUE  */
  YYSYMBOL_RETURN = 12,                    /* RETURN  */
  YYSYMBOL_ID = 13,                        /* ID  */
  YYSYMBOL_OCTAL_CONST = 14,               /* OCTAL_CONST  */
  YYSYMBOL_HEX_CONST = 15,                 /* HEX_CONST  */
  YYSYMBOL_DEC_CONST = 16,                 /* DEC_CONST  */
  YYSYMBOL_FLOAT_CONST = 17,               /* FLOAT_CONST  */
  YYSYMBOL_ASSIGN = 18,                    /* ASSIGN  */
  YYSYMBOL_NOT = 19,                       /* NOT  */
  YYSYMBOL_OR = 20,                        /* OR  */
  YYSYMBOL_AND = 21,                       /* AND  */
  YYSYMBOL_EQNEQ = 22,                     /* EQNEQ  */
  YYSYMBOL_CMP = 23,                       /* CMP  */
  YYSYMBOL_ADDSUB = 24,                    /* ADDSUB  */
  YYSYMBOL_MULDIVSUR = 25,                 /* MULDIVSUR  */
  YYSYMBOL_26_ = 26,                       /* ';'  */
  YYSYMBOL_27_ = 27,                       /* ','  */
  YYSYMBOL_28_ = 28,                       /* '['  */
  YYSYMBOL_29_ = 29,                       /* ']'  */
  YYSYMBOL_30_ = 30,                       /* '{'  */
  YYSYMBOL_31_ = 31,                       /* '}'  */
  YYSYMBOL_32_ = 32,                       /* '('  */
  YYSYMBOL_33_ = 33,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 34,                  /* $accept  */
  YYSYMBOL_CompUnit = 35,                  /* CompUnit  */
  YYSYMBOL_Decl = 36,                      /* Decl  */
  YYSYMBOL_ConstDecl = 37,                 /* ConstDecl  */
  YYSYMBOL_ConstDefBlock = 38,             /* ConstDefBlock  */
  YYSYMBOL_ConstDef = 39,                  /* ConstDef  */
  YYSYMBOL_ConstExpBlock = 40,             /* ConstExpBlock  */
  YYSYMBOL_ConstInitVal = 41,              /* ConstInitVal  */
  YYSYMBOL_ConstInitFlag = 42,             /* ConstInitFlag  */
  YYSYMBOL_ConstValBlock = 43,             /* ConstValBlock  */
  YYSYMBOL_VarDecl = 44,                   /* VarDecl  */
  YYSYMBOL_VarDefFlag = 45,                /* VarDefFlag  */
  YYSYMBOL_VarDef = 46,                    /* VarDef  */
  YYSYMBOL_InitVal = 47,                   /* InitVal  */
  YYSYMBOL_InitValFlag = 48,               /* InitValFlag  */
  YYSYMBOL_InitValBlock = 49,              /* InitValBlock  */
  YYSYMBOL_FuncDef = 50,                   /* FuncDef  */
  YYSYMBOL_FuncType = 51,                  /* FuncType  */
  YYSYMBOL_FuncFParams = 52,               /* FuncFParams  */
  YYSYMBOL_FuncFParamBlock = 53,           /* FuncFParamBlock  */
  YYSYMBOL_FuncFParam = 54,                /* FuncFParam  */
  YYSYMBOL_ExpBlockFlag = 55,              /* ExpBlockFlag  */
  YYSYMBOL_ExpBlock = 56,                  /* ExpBlock  */
  YYSYMBOL_Block = 57,                     /* Block  */
  YYSYMBOL_BlockItemBlock = 58,            /* BlockItemBlock  */
  YYSYMBOL_BlockItem = 59,                 /* BlockItem  */
  YYSYMBOL_Stmt = 60,                      /* Stmt  */
  YYSYMBOL_ExpFlag = 61,                   /* ExpFlag  */
  YYSYMBOL_StmtFlag = 62,                  /* StmtFlag  */
  YYSYMBOL_Exp = 63,                       /* Exp  */
  YYSYMBOL_Cond = 64,                      /* Cond  */
  YYSYMBOL_LVal = 65,                      /* LVal  */
  YYSYMBOL_PrimaryExp = 66,                /* PrimaryExp  */
  YYSYMBOL_Number = 67,                    /* Number  */
  YYSYMBOL_UnaryExp = 68,                  /* UnaryExp  */
  YYSYMBOL_FuncFParamsFlag = 69,           /* FuncFParamsFlag  */
  YYSYMBOL_FuncRParams = 70,               /* FuncRParams  */
  YYSYMBOL_CommaExpBlock = 71,             /* CommaExpBlock  */
  YYSYMBOL_UNARYOP = 72,                   /* UNARYOP  */
  YYSYMBOL_MulExp = 73,                    /* MulExp  */
  YYSYMBOL_AddExp = 74,                    /* AddExp  */
  YYSYMBOL_RelExp = 75,                    /* RelExp  */
  YYSYMBOL_EqExp = 76,                     /* EqExp  */
  YYSYMBOL_LAndExp = 77,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 78,                    /* LOrExp  */
  YYSYMBOL_ConstExp = 79                   /* ConstExp  */
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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   172

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  151

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   280


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
      32,    33,     2,     2,    27,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    26,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    28,     2,    29,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,    31,     2,     2,     2,     2,
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
      25
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    31,    31,    36,    41,    45,    49,    50,    51,    57,
      62,    66,    72,    78,    82,    83,    89,    93,    97,   102,
     106,   111,   116,   120,   125,   131,   132,   138,   142,   146,
     151,   155,   162,   166,   170,   174,   178,   182,   187,   191,
     196,   202,   206,   212,   216,   222,   226,   230,   233,   236,
     242,   247,   250,   257,   264,   270,   276,   282,   285,   289,
     294,   298,   301,   304,   309,   315,   318,   321,   325,   329,
     333,   339,   342,   349,   353,   356,   360,   364,   369,   373,
     377,   381,   384,   389,   392,   397,   400,   405,   408,   413,
     416,   421,   424,   429
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
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "VOID",
  "CONST", "IF", "ELSE", "WHILE", "BREAK", "CONTINUE", "RETURN", "ID",
  "OCTAL_CONST", "HEX_CONST", "DEC_CONST", "FLOAT_CONST", "ASSIGN", "NOT",
  "OR", "AND", "EQNEQ", "CMP", "ADDSUB", "MULDIVSUR", "';'", "','", "'['",
  "']'", "'{'", "'}'", "'('", "')'", "$accept", "CompUnit", "Decl",
  "ConstDecl", "ConstDefBlock", "ConstDef", "ConstExpBlock",
  "ConstInitVal", "ConstInitFlag", "ConstValBlock", "VarDecl",
  "VarDefFlag", "VarDef", "InitVal", "InitValFlag", "InitValBlock",
  "FuncDef", "FuncType", "FuncFParams", "FuncFParamBlock", "FuncFParam",
  "ExpBlockFlag", "ExpBlock", "Block", "BlockItemBlock", "BlockItem",
  "Stmt", "ExpFlag", "StmtFlag", "Exp", "Cond", "LVal", "PrimaryExp",
  "Number", "UnaryExp", "FuncFParamsFlag", "FuncRParams", "CommaExpBlock",
  "UNARYOP", "MulExp", "AddExp", "RelExp", "EqExp", "LAndExp", "LOrExp",
  "ConstExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-126)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       8,  -126,  -126,  -126,    53,    45,  -126,  -126,  -126,  -126,
       5,    30,  -126,  -126,  -126,    14,    25,  -126,  -126,    53,
     -11,    47,    37,    -9,    -2,    51,    33,  -126,   116,   140,
    -126,    25,  -126,   128,  -126,    30,    41,    40,    44,    42,
    -126,  -126,  -126,  -126,  -126,  -126,   116,   140,  -126,  -126,
    -126,  -126,  -126,  -126,   140,    48,    52,    52,    43,  -126,
     128,  -126,  -126,  -126,    50,  -126,  -126,  -126,    53,   140,
      49,  -126,    57,    56,  -126,   140,   140,  -126,  -126,    59,
    -126,    23,  -126,  -126,    58,  -126,   140,    55,  -126,  -126,
    -126,    48,    65,  -126,    49,    61,    62,    54,    71,   140,
    -126,  -126,    47,  -126,  -126,  -126,    72,  -126,    81,    73,
    -126,    74,   116,   128,   140,   140,  -126,  -126,    75,  -126,
     140,   140,  -126,  -126,  -126,    69,    52,    60,    82,    84,
      86,    79,  -126,    96,  -126,   104,   140,   140,   140,   140,
     104,  -126,   117,    52,    60,    82,    84,  -126,   104,  -126,
    -126
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    33,    34,    32,     0,     0,     4,     6,     7,     5,
       0,     0,     1,     2,     3,    13,    22,    13,    10,    36,
      23,     0,     0,     0,     0,     0,     0,    38,     0,     0,
      13,    22,    20,     0,     8,     0,    41,     0,    35,    43,
      68,    69,    67,    70,    80,    79,    28,     0,    24,    25,
      65,    71,    66,    81,     0,    83,    61,    93,     0,    21,
      17,    11,    14,     9,     0,    39,    46,    31,     0,    75,
      63,    30,     0,     0,    73,     0,     0,    12,    19,     0,
      43,    58,    37,    78,     0,    74,     0,    27,    26,    64,
      82,    84,    16,    15,    40,     0,     0,     0,     0,    58,
      44,    47,     0,    51,    45,    48,     0,    57,    65,    76,
      72,     0,     0,     0,     0,     0,    54,    55,     0,    50,
       0,     0,    42,    29,    18,     0,    85,    87,    89,    91,
      62,     0,    56,     0,    77,    58,     0,     0,     0,     0,
      58,    49,    60,    86,    88,    90,    92,    53,    58,    52,
      59
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -126,  -126,     0,  -126,  -126,    89,   109,   -54,  -126,  -126,
    -126,   106,   118,   -44,  -126,  -126,   122,    -3,  -126,  -126,
      70,  -126,    83,   112,  -126,  -126,  -125,    63,  -126,   -25,
      35,   -73,  -126,  -126,   -34,  -126,  -126,  -126,  -126,    85,
     -29,    28,    13,    27,  -126,   138
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,    24,    18,    20,    61,    79,    92,
       8,    22,    16,    48,    72,    87,     9,    10,    26,    38,
      27,    65,    70,   103,    81,   104,   105,   106,   149,   107,
     125,    50,    51,    52,    53,    84,    85,   109,    54,    55,
      56,   127,   128,   129,   130,    62
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      57,    11,    71,    49,    57,    13,    78,    28,   108,    33,
     142,     1,     2,     3,     4,   147,    25,    29,    15,    29,
      74,    49,    73,   150,    34,    35,     1,     2,     3,     4,
      95,    57,    96,    97,    98,    99,    39,    40,    41,    42,
      43,    90,    44,    17,    83,    12,    19,    45,     1,     2,
       3,     4,    21,    66,   100,    47,     1,     2,     3,   124,
      30,   111,   108,    32,    36,    25,    37,   108,   123,    64,
      66,    68,    77,    75,    69,   108,    76,    86,   102,    80,
     116,   101,   112,   136,    57,   126,   126,    49,    88,    89,
      93,   110,   113,   114,   115,   133,   134,   117,   119,   120,
     121,   132,   135,   122,   137,   138,   139,   143,   126,   126,
     126,    95,   140,    96,    97,    98,    99,    39,    40,    41,
      42,    43,   141,    44,    63,   148,    23,    14,    45,    39,
      40,    41,    42,    43,    66,    44,    47,    59,    82,    31,
      45,    39,    40,    41,    42,    43,    46,    44,    47,    67,
     131,   145,    45,    39,    40,    41,    42,    43,    60,    44,
      47,    91,   118,    94,    45,   144,   146,    58,     0,     0,
       0,     0,    47
};

static const yytype_int16 yycheck[] =
{
      29,     4,    46,    28,    33,     5,    60,    18,    81,    18,
     135,     3,     4,     5,     6,   140,    19,    28,    13,    28,
      54,    46,    47,   148,    26,    27,     3,     4,     5,     6,
       7,    60,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    75,    19,    13,    69,     0,    32,    24,     3,     4,
       5,     6,    27,    30,    31,    32,     3,     4,     5,   113,
      13,    86,   135,    26,    13,    68,    33,   140,   112,    28,
      30,    27,    29,    25,    32,   148,    24,    28,    81,    29,
      26,    81,    27,    23,   113,   114,   115,   112,    31,    33,
      31,    33,    27,    32,    32,   120,   121,    26,    26,    18,
      27,    26,    33,    29,    22,    21,    20,   136,   137,   138,
     139,     7,    33,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    26,    19,    35,     8,    17,     5,    24,    13,
      14,    15,    16,    17,    30,    19,    32,    31,    68,    21,
      24,    13,    14,    15,    16,    17,    30,    19,    32,    37,
     115,   138,    24,    13,    14,    15,    16,    17,    30,    19,
      32,    76,    99,    80,    24,   137,   139,    29,    -1,    -1,
      -1,    -1,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    35,    36,    37,    44,    50,
      51,    51,     0,    36,    50,    13,    46,    13,    39,    32,
      40,    27,    45,    40,    38,    51,    52,    54,    18,    28,
      13,    46,    26,    18,    26,    27,    13,    33,    53,    13,
      14,    15,    16,    17,    19,    24,    30,    32,    47,    63,
      65,    66,    67,    68,    72,    73,    74,    74,    79,    45,
      30,    41,    79,    39,    28,    55,    30,    57,    27,    32,
      56,    47,    48,    63,    68,    25,    24,    29,    41,    42,
      29,    58,    54,    63,    69,    70,    28,    49,    31,    33,
      68,    73,    43,    31,    56,     7,     9,    10,    11,    12,
      31,    36,    51,    57,    59,    60,    61,    63,    65,    71,
      33,    63,    27,    27,    32,    32,    26,    26,    61,    26,
      18,    27,    29,    47,    41,    64,    74,    75,    76,    77,
      78,    64,    26,    63,    63,    33,    23,    22,    21,    20,
      33,    26,    60,    74,    75,    76,    77,    60,     8,    62,
      60
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    35,    35,    35,    36,    36,    37,    38,
      38,    39,    40,    40,    41,    41,    42,    42,    43,    43,
      44,    45,    45,    46,    46,    47,    47,    48,    48,    49,
      49,    50,    51,    51,    51,    52,    52,    53,    53,    54,
      55,    55,    56,    56,    57,    58,    58,    59,    59,    60,
      60,    60,    60,    60,    60,    60,    60,    61,    61,    62,
      62,    63,    64,    65,    66,    66,    66,    67,    67,    67,
      67,    68,    68,    68,    69,    69,    70,    71,    71,    72,
      72,    73,    73,    74,    74,    75,    75,    76,    76,    77,
      77,    78,    78,    79
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     1,     1,     5,     3,
       0,     4,     4,     0,     1,     3,     2,     0,     3,     0,
       4,     3,     0,     2,     4,     1,     3,     2,     0,     3,
       0,     6,     1,     1,     1,     2,     0,     3,     0,     3,
       3,     0,     4,     0,     3,     2,     0,     1,     1,     4,
       2,     1,     6,     5,     2,     2,     3,     1,     0,     2,
       0,     1,     1,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     4,     2,     1,     0,     2,     3,     0,     1,
       1,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1
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
  case 2: /* CompUnit: CompUnit Decl  */
#line 31 "syntax.y"
                                                        {
                                                            connectASTnode(2, (yyvsp[-1].node), (yyvsp[0].node));
                                                            (yyval.node) = newASTnode(TEXT, "CompUnit", 0, NULL, (yyvsp[-1].node));
                                                            ASThead = (yyval.node);
                                                        }
#line 1260 "syntax.tab.c"
    break;

  case 3: /* CompUnit: CompUnit FuncDef  */
#line 36 "syntax.y"
                                                        {
                                                            connectASTnode(2, (yyvsp[-1].node), (yyvsp[0].node));
                                                            (yyval.node) = newASTnode(TEXT, "CompUnit", 0, NULL, (yyvsp[-1].node));
                                                            ASThead = (yyval.node);
                                                        }
#line 1270 "syntax.tab.c"
    break;

  case 4: /* CompUnit: Decl  */
#line 41 "syntax.y"
                                                        {
                                                            (yyval.node) = newASTnode(TEXT, "CompUnit", 0, NULL, (yyvsp[0].node));
                                                            ASThead = (yyval.node);
                                                        }
#line 1279 "syntax.tab.c"
    break;

  case 5: /* CompUnit: FuncDef  */
#line 45 "syntax.y"
                                                        {
                                                            (yyval.node) = newASTnode(TEXT, "CompUnit", 0, NULL, (yyvsp[0].node));
                                                            ASThead = (yyval.node);
                                                        }
#line 1288 "syntax.tab.c"
    break;

  case 6: /* Decl: ConstDecl  */
#line 49 "syntax.y"
                                                        { (yyval.node) = newASTnode(TEXT, "Decl", 0, NULL, (yyvsp[0].node)); }
#line 1294 "syntax.tab.c"
    break;

  case 7: /* Decl: VarDecl  */
#line 50 "syntax.y"
                                                        { (yyval.node) = newASTnode(TEXT, "Decl", 0, NULL, (yyvsp[0].node)); }
#line 1300 "syntax.tab.c"
    break;

  case 8: /* ConstDecl: CONST FuncType ConstDef ConstDefBlock ';'  */
#line 51 "syntax.y"
                                                           {
                                                            ASTnode* n1 = newASTnode(TEXT, (yyvsp[-4].str), 0, NULL, NULL);
                                                            ASTnode* n5 = newASTnode(TEXT, ";", 0, NULL, NULL);
                                                            connectASTnode(5, n1, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), n5);
                                                            (yyval.node) = newASTnode(TEXT, "ConstDecl", 0, NULL, n1);
                                                        }
#line 1311 "syntax.tab.c"
    break;

  case 9: /* ConstDefBlock: ConstDefBlock ',' ConstDef  */
#line 57 "syntax.y"
                                                        {
                                                            ASTnode* n = newASTnode(TEXT, ",", 0, (yyvsp[0].node), NULL);
                                                            connectASTnode(3, (yyvsp[-2].node), n, (yyvsp[0].node));
                                                            (yyval.node) = newASTnode(TEXT, "ConstDefBlock", 0, NULL, (yyvsp[-2].node));
                                                        }
#line 1321 "syntax.tab.c"
    break;

  case 10: /* ConstDefBlock: %empty  */
#line 62 "syntax.y"
                                                         {
                                                            ASTnode* n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            (yyval.node) = newASTnode(TEXT, "ConstDefBlock", 0, NULL, n);
                                                        }
#line 1330 "syntax.tab.c"
    break;

  case 11: /* ConstDef: ID ConstExpBlock ASSIGN ConstInitVal  */
#line 66 "syntax.y"
                                                        {
                                                            ASTnode* n1 = newASTnode(TEXT, (yyvsp[-3].str), 0, NULL, NULL);
                                                            ASTnode* n3 = newASTnode(TEXT, (yyvsp[-1].str), 0, NULL, NULL);
                                                            connectASTnode(4, n1, (yyvsp[-2].node), n3, (yyvsp[0].node));
                                                            (yyval.node) = newASTnode(TEXT, "ConstDef", 0, NULL, n1);
                                                        }
#line 1341 "syntax.tab.c"
    break;

  case 12: /* ConstExpBlock: ConstExpBlock '[' ConstExp ']'  */
#line 72 "syntax.y"
                                                        {
                                                            ASTnode* n2 = newASTnode(TEXT, "[", 0, NULL, NULL);
                                                            ASTnode* n4 = newASTnode(TEXT, "]", 0, NULL, NULL);
                                                            connectASTnode(4, (yyvsp[-3].node), n2, (yyvsp[-1].node), n4);
                                                            (yyval.node) = newASTnode(TEXT, "ConstExpBlock", 0, NULL, (yyvsp[-3].node));
                                                        }
#line 1352 "syntax.tab.c"
    break;

  case 13: /* ConstExpBlock: %empty  */
#line 78 "syntax.y"
                                                         {
                                                            ASTnode* n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            (yyval.node) = newASTnode(TEXT, "ConstExpBlock", 0, NULL, n);
                                                        }
#line 1361 "syntax.tab.c"
    break;

  case 14: /* ConstInitVal: ConstExp  */
#line 82 "syntax.y"
                                                        { (yyval.node) = newASTnode(TEXT, "ConstInitVal", 0, NULL, (yyvsp[0].node)); }
#line 1367 "syntax.tab.c"
    break;

  case 15: /* ConstInitVal: '{' ConstInitFlag '}'  */
#line 83 "syntax.y"
                                                        {
                                                            ASTnode* n1 = newASTnode(TEXT, "{", 0, NULL, NULL);
                                                            ASTnode* n3 = newASTnode(TEXT, "}", 0, NULL, NULL);
                                                            connectASTnode(3, n1, (yyvsp[-1].node), n3);
                                                            (yyval.node) = newASTnode(TEXT, "ConstInitVal", 0, NULL, n1);
                                                        }
#line 1378 "syntax.tab.c"
    break;

  case 16: /* ConstInitFlag: ConstInitVal ConstValBlock  */
#line 89 "syntax.y"
                                                        {
                                                            connectASTnode(2, (yyvsp[-1].node), (yyvsp[0].node));
                                                            (yyval.node) = newASTnode(TEXT, "ConstInitFlag", 0, NULL, (yyvsp[-1].node));
                                                        }
#line 1387 "syntax.tab.c"
    break;

  case 17: /* ConstInitFlag: %empty  */
#line 93 "syntax.y"
                                                         {
                                                            ASTnode*n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            (yyval.node) = newASTnode(TEXT, "ConstInitFlag", 0, NULL, n);
                                                        }
#line 1396 "syntax.tab.c"
    break;

  case 18: /* ConstValBlock: ConstValBlock ',' ConstInitVal  */
#line 97 "syntax.y"
                                                        {
                                                            ASTnode* n2 = newASTnode(TEXT, ",", 0, NULL, NULL);
                                                            connectASTnode(3, (yyvsp[-2].node), n2, (yyvsp[0].node));
                                                            (yyval.node) = newASTnode(TEXT, "ConstValBlock", 0, NULL, (yyvsp[-2].node));    
                                                        }
#line 1406 "syntax.tab.c"
    break;

  case 19: /* ConstValBlock: %empty  */
#line 102 "syntax.y"
                                                         {
                                                            ASTnode* n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            (yyval.node) = newASTnode(TEXT, "ConstValBlock", 0, NULL, n);
                                                        }
#line 1415 "syntax.tab.c"
    break;

  case 20: /* VarDecl: FuncType VarDef VarDefFlag ';'  */
#line 106 "syntax.y"
                                                           {
                                                            ASTnode* n = newASTnode(TEXT, ";", 0, NULL, NULL);
                                                            connectASTnode(4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), n);
                                                            (yyval.node) = newASTnode(TEXT, "VarDecl", 0, NULL, (yyvsp[-3].node));
                                                        }
#line 1425 "syntax.tab.c"
    break;

  case 21: /* VarDefFlag: ',' VarDef VarDefFlag  */
#line 111 "syntax.y"
                                                        {
                                                            ASTnode* n = newASTnode(TEXT, ",", 0, NULL, NULL);
                                                            connectASTnode(3, n, (yyvsp[-1].node), (yyvsp[0].node));
                                                            (yyval.node) = newASTnode(TEXT, "VarDefFlag", 0, NULL, n);
                                                        }
#line 1435 "syntax.tab.c"
    break;

  case 22: /* VarDefFlag: %empty  */
#line 116 "syntax.y"
                                                         {
                                                            ASTnode* n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            (yyval.node) = newASTnode(TEXT, "VarDefFlag", 0, NULL, n);
                                                        }
#line 1444 "syntax.tab.c"
    break;

  case 23: /* VarDef: ID ConstExpBlock  */
#line 120 "syntax.y"
                                                        {
                                                            ASTnode* n = newASTnode(TEXT, (yyvsp[-1].str), 0, NULL, NULL);
                                                            connectASTnode(2, n, (yyvsp[0].node));
                                                            (yyval.node) = newASTnode(TEXT, "VarDef", 0, NULL, n);
                                                        }
#line 1454 "syntax.tab.c"
    break;

  case 24: /* VarDef: ID ConstExpBlock ASSIGN InitVal  */
#line 125 "syntax.y"
                                                        {
                                                            ASTnode* n1 = newASTnode(TEXT, (yyvsp[-3].str), 0, NULL, NULL);
                                                            ASTnode* n3 = newASTnode(TEXT, (yyvsp[-1].str), 0, NULL, NULL);
                                                            connectASTnode(4, n1, (yyvsp[-2].node), n3, (yyvsp[0].node));
                                                            (yyval.node) = newASTnode(TEXT, "VarDef", 0, NULL, n1);
                                                        }
#line 1465 "syntax.tab.c"
    break;

  case 25: /* InitVal: Exp  */
#line 131 "syntax.y"
                                                        { (yyval.node) = newASTnode(TEXT, "InitVal", 0, NULL, (yyvsp[0].node)); }
#line 1471 "syntax.tab.c"
    break;

  case 26: /* InitVal: '{' InitValFlag '}'  */
#line 132 "syntax.y"
                                                      {
                                                            ASTnode* n1 = newASTnode(TEXT, "{", 0, NULL, NULL);
                                                            ASTnode* n3 = newASTnode(TEXT, "}", 0, NULL, NULL);
                                                            connectASTnode(3, n1, (yyvsp[-1].node), n3);
                                                            (yyval.node) = newASTnode(TEXT, "InitVal", 0, NULL, n1);
                                                        }
#line 1482 "syntax.tab.c"
    break;

  case 27: /* InitValFlag: InitVal InitValBlock  */
#line 138 "syntax.y"
                                                        {
                                                            connectASTnode(2, (yyvsp[-1].node), (yyvsp[0].node));
                                                            (yyval.node) = newASTnode(TEXT, "InitValFlag", 0, NULL, (yyvsp[-1].node));
                                                        }
#line 1491 "syntax.tab.c"
    break;

  case 28: /* InitValFlag: %empty  */
#line 142 "syntax.y"
                                                         {
                                                            ASTnode* n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            (yyval.node) = newASTnode(TEXT, "InitValFlag", 0, NULL, n);
                                                        }
#line 1500 "syntax.tab.c"
    break;

  case 29: /* InitValBlock: InitValBlock ',' InitVal  */
#line 146 "syntax.y"
                                                        {
                                                            ASTnode* n = newASTnode(TEXT, ",", 0, NULL, NULL);
                                                            connectASTnode(3, (yyvsp[-2].node), n, (yyvsp[0].node));
                                                            (yyval.node) = newASTnode(TEXT, "InitValBlock", 0, NULL, (yyvsp[-2].node));
                                                        }
#line 1510 "syntax.tab.c"
    break;

  case 30: /* InitValBlock: %empty  */
#line 151 "syntax.y"
                                                         {
                                                            ASTnode* n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            (yyval.node) = newASTnode(TEXT, "InitValBlock", 0, NULL, n);
                                                        }
#line 1519 "syntax.tab.c"
    break;

  case 31: /* FuncDef: FuncType ID '(' FuncFParams ')' Block  */
#line 155 "syntax.y"
                                                        {
                                                            ASTnode* n2 = newASTnode(TEXT, (yyvsp[-4].str), 0, NULL, NULL);
                                                            ASTnode* n3 = newASTnode(TEXT, "(", 0, NULL, NULL);
                                                            ASTnode* n5 = newASTnode(TEXT, ")", 0, NULL, NULL);
                                                            connectASTnode(6, (yyvsp[-5].node), n2, n3, (yyvsp[-2].node), n5, (yyvsp[0].node));
                                                            (yyval.node) = newASTnode(TEXT, "FuncDef", 0, NULL, (yyvsp[-5].node));
                                                        }
#line 1531 "syntax.tab.c"
    break;

  case 32: /* FuncType: VOID  */
#line 162 "syntax.y"
                                                        {
                                                            ASTnode* n = newASTnode(TEXT, (yyvsp[0].str), 0, NULL, NULL);
                                                            (yyval.node) = newASTnode(TEXT, "FuncType", 0, NULL, n);
                                                        }
#line 1540 "syntax.tab.c"
    break;

  case 33: /* FuncType: INT  */
#line 166 "syntax.y"
                                                        {
                                                            ASTnode* n = newASTnode(TEXT, (yyvsp[0].str), 0, NULL, NULL);
                                                            (yyval.node) = newASTnode(TEXT, "FuncType", 0, NULL, n);
                                                        }
#line 1549 "syntax.tab.c"
    break;

  case 34: /* FuncType: FLOAT  */
#line 170 "syntax.y"
                                                        {
                                                            ASTnode* n = newASTnode(TEXT, (yyvsp[0].str), 0, NULL, NULL);
                                                            (yyval.node) = newASTnode(TEXT, "FuncType", 0, NULL, n);
                                                        }
#line 1558 "syntax.tab.c"
    break;

  case 35: /* FuncFParams: FuncFParam FuncFParamBlock  */
#line 174 "syntax.y"
                                                        {
                                                            connectASTnode(2, (yyvsp[-1].node), (yyvsp[0].node));
                                                            (yyval.node) = newASTnode(TEXT, "FuncFParams", 0, NULL, (yyvsp[-1].node));
                                                        }
#line 1567 "syntax.tab.c"
    break;

  case 36: /* FuncFParams: %empty  */
#line 178 "syntax.y"
                                                         {
                                                            ASTnode* n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            (yyval.node) = newASTnode(TEXT, "FuncFParams", 0, NULL, n);
                                                        }
#line 1576 "syntax.tab.c"
    break;

  case 37: /* FuncFParamBlock: FuncFParamBlock ',' FuncFParam  */
#line 182 "syntax.y"
                                                        {
                                                            ASTnode* n = newASTnode(TEXT, ",", 0, NULL, NULL);
                                                            connectASTnode(3, (yyvsp[-2].node), n, (yyvsp[0].node));
                                                            (yyval.node) = newASTnode(TEXT, "FuncFParamBlock", 0, NULL, (yyvsp[-2].node));
                                                        }
#line 1586 "syntax.tab.c"
    break;

  case 38: /* FuncFParamBlock: %empty  */
#line 187 "syntax.y"
                                                         {
                                                            ASTnode* n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            (yyval.node) = newASTnode(TEXT, "FuncFParamBlock", 0, NULL, n);
                                                        }
#line 1595 "syntax.tab.c"
    break;

  case 39: /* FuncFParam: FuncType ID ExpBlockFlag  */
#line 191 "syntax.y"
                                                           {
                                                            ASTnode* n = newASTnode(TEXT, (yyvsp[-1].str), 0, NULL, NULL);
                                                            connectASTnode(3, (yyvsp[-2].node), n, (yyvsp[0].node));
                                                            (yyval.node) = newASTnode(TEXT, "FuncFParam", 0, NULL, (yyvsp[-2].node));
                                                        }
#line 1605 "syntax.tab.c"
    break;

  case 40: /* ExpBlockFlag: '[' ']' ExpBlock  */
#line 196 "syntax.y"
                                                        {
                                                            ASTnode* n1 = newASTnode(TEXT, "[", 0, NULL, NULL);
                                                            ASTnode* n2 = newASTnode(TEXT, "]", 0, NULL, NULL);
                                                            connectASTnode(3, n1, n2, (yyvsp[0].node));
                                                            (yyval.node) = newASTnode(TEXT, "ExpBlockFlag", 0, NULL, n1);
                                                        }
#line 1616 "syntax.tab.c"
    break;

  case 41: /* ExpBlockFlag: %empty  */
#line 202 "syntax.y"
                                                         {
                                                            ASTnode* n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            (yyval.node) = newASTnode(TEXT, "ExpBlockFlag", 0, NULL, n);
                                                        }
#line 1625 "syntax.tab.c"
    break;

  case 42: /* ExpBlock: ExpBlock '[' Exp ']'  */
#line 206 "syntax.y"
                                                        {
                                                            ASTnode* n2 = newASTnode(TEXT, "[", 0, NULL, NULL);
                                                            ASTnode* n4 = newASTnode(TEXT, "]", 0, NULL, NULL);
                                                            connectASTnode(4, (yyvsp[-3].node), n2, (yyvsp[-1].node), n4);
                                                            (yyval.node) = newASTnode(TEXT, "ExpBlock", 0, NULL, (yyvsp[-3].node));
                                                        }
#line 1636 "syntax.tab.c"
    break;

  case 43: /* ExpBlock: %empty  */
#line 212 "syntax.y"
                                                         {
                                                            ASTnode* n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            (yyval.node) = newASTnode(TEXT, "ExpBlock", 0, NULL, n);
                                                        }
#line 1645 "syntax.tab.c"
    break;

  case 44: /* Block: '{' BlockItemBlock '}'  */
#line 216 "syntax.y"
                                                        {
                                                            ASTnode* n1 = newASTnode(TEXT, "{", 0, NULL, NULL);
                                                            ASTnode* n3 = newASTnode(TEXT, "}", 0, NULL, NULL);
                                                            connectASTnode(3, n1, (yyvsp[-1].node), n3);
                                                            (yyval.node) = newASTnode(TEXT, "Block", 0, NULL, n1);
                                                        }
#line 1656 "syntax.tab.c"
    break;

  case 45: /* BlockItemBlock: BlockItemBlock BlockItem  */
#line 222 "syntax.y"
                                                        {
                                                            connectASTnode(2, (yyvsp[-1].node), (yyvsp[0].node));
                                                            (yyval.node) = newASTnode(TEXT, "BlockItemBlock", 0, NULL, (yyvsp[-1].node));
                                                        }
#line 1665 "syntax.tab.c"
    break;

  case 46: /* BlockItemBlock: %empty  */
#line 226 "syntax.y"
                                                         {
                                                            ASTnode* n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            (yyval.node) = newASTnode(TEXT, "BlockItemBlock", 0, NULL, n);
                                                        }
#line 1674 "syntax.tab.c"
    break;

  case 47: /* BlockItem: Decl  */
#line 230 "syntax.y"
                                                        {
                                                            (yyval.node) = newASTnode(TEXT, "BlockItem", 0, NULL, (yyvsp[0].node));
                                                        }
#line 1682 "syntax.tab.c"
    break;

  case 48: /* BlockItem: Stmt  */
#line 233 "syntax.y"
                                                        {
                                                            (yyval.node) = newASTnode(TEXT, "BlockItem", 0, NULL, (yyvsp[0].node));
                                                        }
#line 1690 "syntax.tab.c"
    break;

  case 49: /* Stmt: LVal ASSIGN Exp ';'  */
#line 236 "syntax.y"
                                                        {
                                                            ASTnode* n2 = newASTnode(TEXT, (yyvsp[-2].str), 0, NULL, NULL);
                                                            ASTnode* n4 = newASTnode(TEXT, ";", 0, NULL, NULL);
                                                            connectASTnode(4, (yyvsp[-3].node), n2, (yyvsp[-1].node), n4);
                                                            (yyval.node) = newASTnode(TEXT, "Stmt", 0, NULL, (yyvsp[-3].node));
                                                        }
#line 1701 "syntax.tab.c"
    break;

  case 50: /* Stmt: ExpFlag ';'  */
#line 242 "syntax.y"
                                                        {
                                                            ASTnode* n = newASTnode(TEXT, ";", 0, NULL, NULL);
                                                            connectASTnode(2, (yyvsp[-1].node), n);
                                                            (yyval.node) = newASTnode(TEXT, "Stmt", 0, NULL, (yyvsp[-1].node));
                                                        }
#line 1711 "syntax.tab.c"
    break;

  case 51: /* Stmt: Block  */
#line 247 "syntax.y"
                                                        {
                                                            (yyval.node) = newASTnode(TEXT, "Stmt", 0, NULL, (yyvsp[0].node));
                                                        }
#line 1719 "syntax.tab.c"
    break;

  case 52: /* Stmt: IF '(' Cond ')' Stmt StmtFlag  */
#line 250 "syntax.y"
                                                        {
                                                            ASTnode* n1 = newASTnode(TEXT, (yyvsp[-5].str), 0, NULL, NULL);
                                                            ASTnode* n2 = newASTnode(TEXT, "(", 0, NULL, NULL);
                                                            ASTnode* n4 = newASTnode(TEXT, ")", 0, NULL, NULL);
                                                            connectASTnode(6, n1, n2, (yyvsp[-3].node), n4, (yyvsp[-1].node), (yyvsp[0].node));
                                                            (yyval.node) = newASTnode(TEXT, "Stmt", 0, NULL, n1);
                                                        }
#line 1731 "syntax.tab.c"
    break;

  case 53: /* Stmt: WHILE '(' Cond ')' Stmt  */
#line 257 "syntax.y"
                                                        {
                                                            ASTnode* n1 = newASTnode(TEXT, (yyvsp[-4].str), 0, NULL, NULL);
                                                            ASTnode* n2 = newASTnode(TEXT, "(", 0, NULL, NULL);
                                                            ASTnode* n4 = newASTnode(TEXT, ")", 0, NULL, NULL);
                                                            connectASTnode(5, n1, n2, (yyvsp[-2].node), n4, (yyvsp[0].node));
                                                            (yyval.node) = newASTnode(TEXT, "Stmt", 0, NULL, n1);
                                                        }
#line 1743 "syntax.tab.c"
    break;

  case 54: /* Stmt: BREAK ';'  */
#line 264 "syntax.y"
                                                        {
                                                            ASTnode* n1 = newASTnode(TEXT, (yyvsp[-1].str), 0, NULL, NULL);
                                                            ASTnode* n2 = newASTnode(TEXT, ";", 0, NULL, NULL);
                                                            connectASTnode(2, n1, n2);
                                                            (yyval.node) = newASTnode(TEXT, "Stmt", 0, NULL, n1);
                                                        }
#line 1754 "syntax.tab.c"
    break;

  case 55: /* Stmt: CONTINUE ';'  */
#line 270 "syntax.y"
                                                        {
                                                            ASTnode* n1 = newASTnode(TEXT, (yyvsp[-1].str), 0, NULL, NULL);
                                                            ASTnode* n2 = newASTnode(TEXT, ";", 0, NULL, NULL);
                                                            connectASTnode(2, n1, n2);
                                                            (yyval.node) = newASTnode(TEXT, "Stmt", 0, NULL, n1);
                                                        }
#line 1765 "syntax.tab.c"
    break;

  case 56: /* Stmt: RETURN ExpFlag ';'  */
#line 276 "syntax.y"
                                                        {
                                                            ASTnode* n1 = newASTnode(TEXT, (yyvsp[-2].str), 0, NULL, NULL);
                                                            ASTnode* n3 = newASTnode(TEXT, ";", 0, NULL, NULL);
                                                            connectASTnode(3, n1, (yyvsp[-1].node), n3);
                                                            (yyval.node) = newASTnode(TEXT, "Stmt", 0, NULL, n1);
                                                        }
#line 1776 "syntax.tab.c"
    break;

  case 57: /* ExpFlag: Exp  */
#line 282 "syntax.y"
                                                        {
                                                            (yyval.node) = newASTnode(TEXT, "ExpFlag", 0, NULL, (yyvsp[0].node));
                                                        }
#line 1784 "syntax.tab.c"
    break;

  case 58: /* ExpFlag: %empty  */
#line 285 "syntax.y"
                                                         {
                                                            ASTnode* n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            (yyval.node) = newASTnode(TEXT, "ExpFlag", 0, NULL, n);
                                                        }
#line 1793 "syntax.tab.c"
    break;

  case 59: /* StmtFlag: ELSE Stmt  */
#line 289 "syntax.y"
                                                        {
                                                            ASTnode* n = newASTnode(TEXT, (yyvsp[-1].str), 0, NULL, NULL);
                                                            connectASTnode(2, n, (yyvsp[0].node));
                                                            (yyval.node) = newASTnode(TEXT, "StmtFlag", 0, NULL, n);
                                                        }
#line 1803 "syntax.tab.c"
    break;

  case 60: /* StmtFlag: %empty  */
#line 294 "syntax.y"
                                                         {
                                                            ASTnode* n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            (yyval.node) = newASTnode(TEXT, "StmtFlag", 0, NULL, n);
                                                        }
#line 1812 "syntax.tab.c"
    break;

  case 61: /* Exp: AddExp  */
#line 298 "syntax.y"
                                                        {
                                                            (yyval.node) = newASTnode(TEXT, "Exp", 0, NULL, (yyvsp[0].node));
                                                        }
#line 1820 "syntax.tab.c"
    break;

  case 62: /* Cond: LOrExp  */
#line 301 "syntax.y"
                                                        {
                                                            (yyval.node) = newASTnode(TEXT, "Cond", 0, NULL, (yyvsp[0].node));
                                                        }
#line 1828 "syntax.tab.c"
    break;

  case 63: /* LVal: ID ExpBlock  */
#line 304 "syntax.y"
                                                        {
                                                            ASTnode* n = newASTnode(TEXT, (yyvsp[-1].str), 0, NULL, NULL);
                                                            connectASTnode(2, n, (yyvsp[0].node));
                                                            (yyval.node) = newASTnode(TEXT, "LVal", 0, NULL, n);
                                                        }
#line 1838 "syntax.tab.c"
    break;

  case 64: /* PrimaryExp: '(' Exp ')'  */
#line 309 "syntax.y"
                                                        {
                                                            ASTnode* n1 = newASTnode(TEXT, "(", 0, NULL, NULL);
                                                            ASTnode* n3 = newASTnode(TEXT, ")", 0, NULL, NULL);
                                                            connectASTnode(3, n1, (yyvsp[-1].node), n3);
                                                            (yyval.node) = newASTnode(TEXT, "PrimaryExp", 0, NULL, n1);
                                                        }
#line 1849 "syntax.tab.c"
    break;

  case 65: /* PrimaryExp: LVal  */
#line 315 "syntax.y"
                                                        {
                                                            (yyval.node) = newASTnode(TEXT, "PrimaryExp", 0, NULL, (yyvsp[0].node));
                                                        }
#line 1857 "syntax.tab.c"
    break;

  case 66: /* PrimaryExp: Number  */
#line 318 "syntax.y"
                                                        {
                                                            (yyval.node) = newASTnode(TEXT, "PrimaryExp", 0, NULL, (yyvsp[0].node));
                                                        }
#line 1865 "syntax.tab.c"
    break;

  case 67: /* Number: DEC_CONST  */
#line 321 "syntax.y"
                                                        {
                                                            ASTnode* n = newASTnode(INT_P, NULL, atoi((yyvsp[0].str)), NULL, NULL);
                                                            (yyval.node) = newASTnode(TEXT, "Number", 0, NULL, n);
                                                        }
#line 1874 "syntax.tab.c"
    break;

  case 68: /* Number: OCTAL_CONST  */
#line 325 "syntax.y"
                                                        {
                                                            ASTnode* n = newASTnode(INT_P, NULL, OCT2DEC((yyvsp[0].str)), NULL, NULL);
                                                            (yyval.node) = newASTnode(TEXT, "Number", 0, NULL, n);
                                                        }
#line 1883 "syntax.tab.c"
    break;

  case 69: /* Number: HEX_CONST  */
#line 329 "syntax.y"
                                                        {
                                                            ASTnode* n = newASTnode(INT_P, NULL, HEX2DEC((yyvsp[0].str)), NULL, NULL);
                                                            (yyval.node) = newASTnode(TEXT, "Number", 0, NULL, n);
                                                        }
#line 1892 "syntax.tab.c"
    break;

  case 70: /* Number: FLOAT_CONST  */
#line 333 "syntax.y"
                                                        {
                                                            char* endptr;
                                                            float res = strtof((yyvsp[0].str), &endptr);
                                                            ASTnode* n = newASTnode(FLOAT_P, NULL, res, NULL, NULL);
                                                            (yyval.node) = newASTnode(TEXT, "Number", 0, NULL, n);
                                                        }
#line 1903 "syntax.tab.c"
    break;

  case 71: /* UnaryExp: PrimaryExp  */
#line 339 "syntax.y"
                                                        {
                                                            (yyval.node) = newASTnode(TEXT, "UnaryExp", 0, NULL, (yyvsp[0].node));
                                                        }
#line 1911 "syntax.tab.c"
    break;

  case 72: /* UnaryExp: ID '(' FuncFParamsFlag ')'  */
#line 342 "syntax.y"
                                                        {
                                                            ASTnode* n1 = newASTnode(TEXT, (yyvsp[-3].str), 0, NULL, NULL);
                                                            ASTnode* n2 = newASTnode(TEXT, "(", 0, NULL, NULL);
                                                            ASTnode* n4 = newASTnode(TEXT, ")", 0, NULL, NULL);
                                                            connectASTnode(4, n1, n2, (yyvsp[-1].node), n4);
                                                            (yyval.node) = newASTnode(TEXT, "UnaryExp", 0, NULL, n1);
                                                        }
#line 1923 "syntax.tab.c"
    break;

  case 73: /* UnaryExp: UNARYOP UnaryExp  */
#line 349 "syntax.y"
                                                        {
                                                            connectASTnode(2, (yyvsp[-1].node), (yyvsp[0].node));
                                                            (yyval.node) = newASTnode(TEXT, "UnaryExp", 0, NULL, (yyvsp[-1].node));
                                                        }
#line 1932 "syntax.tab.c"
    break;

  case 74: /* FuncFParamsFlag: FuncRParams  */
#line 353 "syntax.y"
                                                        {
                                                            (yyval.node) = newASTnode(TEXT, "FuncFParamsFlag", 0, NULL, (yyvsp[0].node));
                                                        }
#line 1940 "syntax.tab.c"
    break;

  case 75: /* FuncFParamsFlag: %empty  */
#line 356 "syntax.y"
                                                         {
                                                            ASTnode* n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            (yyval.node) = newASTnode(TEXT, "FuncFParamsFlag", 0, NULL, n);
                                                        }
#line 1949 "syntax.tab.c"
    break;

  case 76: /* FuncRParams: Exp CommaExpBlock  */
#line 360 "syntax.y"
                                                        {
                                                            connectASTnode(2, (yyvsp[-1].node), (yyvsp[0].node));
                                                            (yyval.node) = newASTnode(TEXT, "FuncRParams", 0, NULL, (yyvsp[-1].node));
                                                        }
#line 1958 "syntax.tab.c"
    break;

  case 77: /* CommaExpBlock: CommaExpBlock ',' Exp  */
#line 364 "syntax.y"
                                                        {
                                                            ASTnode* n = newASTnode(TEXT, ",", 0, NULL, NULL);
                                                            connectASTnode(3, (yyvsp[-2].node), n, (yyvsp[0].node));
                                                            (yyval.node) = newASTnode(TEXT, "CommaExpBlock", 0, NULL, (yyvsp[-2].node));
                                                        }
#line 1968 "syntax.tab.c"
    break;

  case 78: /* CommaExpBlock: %empty  */
#line 369 "syntax.y"
                                                         {
                                                            ASTnode* n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            (yyval.node) = newASTnode(TEXT, "CommaExpBlock", 0, NULL, n);
                                                        }
#line 1977 "syntax.tab.c"
    break;

  case 79: /* UNARYOP: ADDSUB  */
#line 373 "syntax.y"
                                                        {
                                                            ASTnode* n = newASTnode(TEXT, (yyvsp[0].str), 0, NULL, NULL);
                                                            (yyval.node) = newASTnode(TEXT, "UNARYOP", 0, NULL, n);
                                                        }
#line 1986 "syntax.tab.c"
    break;

  case 80: /* UNARYOP: NOT  */
#line 377 "syntax.y"
                                                        {
                                                            ASTnode* n = newASTnode(TEXT, (yyvsp[0].str), 0, NULL, NULL);
                                                            (yyval.node) = newASTnode(TEXT, "UNARYOP", 0, NULL, n);
                                                        }
#line 1995 "syntax.tab.c"
    break;

  case 81: /* MulExp: UnaryExp  */
#line 381 "syntax.y"
                                                        {
                                                            (yyval.node) = newASTnode(TEXT, "MulExp", 0, NULL, (yyvsp[0].node));
                                                        }
#line 2003 "syntax.tab.c"
    break;

  case 82: /* MulExp: MulExp MULDIVSUR UnaryExp  */
#line 384 "syntax.y"
                                                        {
                                                            ASTnode* n = newASTnode(TEXT, (yyvsp[-1].str), 0, NULL, NULL);
                                                            connectASTnode(3, (yyvsp[-2].node), n, (yyvsp[0].node));
                                                            (yyval.node) = newASTnode(TEXT, "MulExp", 0, NULL, (yyvsp[-2].node));
                                                        }
#line 2013 "syntax.tab.c"
    break;

  case 83: /* AddExp: MulExp  */
#line 389 "syntax.y"
                                                        {
                                                            (yyval.node) = newASTnode(TEXT, "AddExp", 0, NULL, (yyvsp[0].node));
                                                        }
#line 2021 "syntax.tab.c"
    break;

  case 84: /* AddExp: AddExp ADDSUB MulExp  */
#line 392 "syntax.y"
                                                        {
                                                            ASTnode* n = newASTnode(TEXT, (yyvsp[-1].str), 0, NULL, NULL);
                                                            connectASTnode(3, (yyvsp[-2].node), n, (yyvsp[0].node));
                                                            (yyval.node) = newASTnode(TEXT, "AddExp", 0, NULL, (yyvsp[-2].node));
                                                        }
#line 2031 "syntax.tab.c"
    break;

  case 85: /* RelExp: AddExp  */
#line 397 "syntax.y"
                                                        {
                                                            (yyval.node) = newASTnode(TEXT, "RelExp", 0, NULL, (yyvsp[0].node));
                                                        }
#line 2039 "syntax.tab.c"
    break;

  case 86: /* RelExp: RelExp CMP AddExp  */
#line 400 "syntax.y"
                                                        {
                                                            ASTnode* n = newASTnode(TEXT, (yyvsp[-1].str), 0, NULL, NULL);
                                                            connectASTnode(3, (yyvsp[-2].node), n, (yyvsp[0].node));
                                                            (yyval.node) = newASTnode(TEXT, "RelExp", 0, NULL, (yyvsp[-2].node));
                                                        }
#line 2049 "syntax.tab.c"
    break;

  case 87: /* EqExp: RelExp  */
#line 405 "syntax.y"
                                                        {
                                                            (yyval.node) = newASTnode(TEXT, "EqExp", 0, NULL, (yyvsp[0].node));
                                                        }
#line 2057 "syntax.tab.c"
    break;

  case 88: /* EqExp: EqExp EQNEQ RelExp  */
#line 408 "syntax.y"
                                                        {
                                                            ASTnode* n = newASTnode(TEXT, (yyvsp[-1].str), 0, NULL, NULL);
                                                            connectASTnode(3, (yyvsp[-2].node), n, (yyvsp[0].node));
                                                            (yyval.node) = newASTnode(TEXT, "EqExp", 0, NULL, (yyvsp[-2].node));
                                                        }
#line 2067 "syntax.tab.c"
    break;

  case 89: /* LAndExp: EqExp  */
#line 413 "syntax.y"
                                                        {
                                                            (yyval.node) = newASTnode(TEXT, "LAndExp", 0, NULL, (yyvsp[0].node));
                                                        }
#line 2075 "syntax.tab.c"
    break;

  case 90: /* LAndExp: LAndExp AND EqExp  */
#line 416 "syntax.y"
                                                        {
                                                            ASTnode* n = newASTnode(TEXT, (yyvsp[-1].str), 0, NULL, NULL);
                                                            connectASTnode(3, (yyvsp[-2].node), n, (yyvsp[0].node));
                                                            (yyval.node) = newASTnode(TEXT, "LAndExp", 0, NULL, (yyvsp[-2].node));
                                                        }
#line 2085 "syntax.tab.c"
    break;

  case 91: /* LOrExp: LAndExp  */
#line 421 "syntax.y"
                                                        {
                                                            (yyval.node) = newASTnode(TEXT, "LOrExp", 0, NULL, (yyvsp[0].node));
                                                        }
#line 2093 "syntax.tab.c"
    break;

  case 92: /* LOrExp: LOrExp OR LAndExp  */
#line 424 "syntax.y"
                                                        {
                                                            ASTnode* n = newASTnode(TEXT, (yyvsp[-1].str), 0, NULL, NULL);
                                                            connectASTnode(3, (yyvsp[-2].node), n, (yyvsp[0].node));
                                                            (yyval.node) = newASTnode(TEXT, "LOrExp", 0, NULL, (yyvsp[-2].node));
                                                        }
#line 2103 "syntax.tab.c"
    break;

  case 93: /* ConstExp: AddExp  */
#line 429 "syntax.y"
                                                        {
                                                            (yyval.node) = newASTnode(TEXT, "ConstExp", 0, NULL, (yyvsp[0].node));
                                                        }
#line 2111 "syntax.tab.c"
    break;


#line 2115 "syntax.tab.c"

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

#line 432 "syntax.y"
              
int main(){
    yyparse();
    printAST(ASThead, 0);
    freeAST(ASThead);
    return 0;
}
