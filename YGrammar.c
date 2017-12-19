/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "YGrammar.y" /* yacc.c:339  */

  #include "IOMngr.h"
  #include "Scanner.h"
  #include "YSemantics.h"
  #include <stdio.h>
  #include <string.h>

  void yyerror(char *s);

#line 76 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENT_TOK = 1,
    DECL_TOK = 2,
    IMPL_TOK = 3,
    INT_TOK = 4,
    CHR_TOK = 5,
    CHRLIT_TOK = 6,
    INTLIT_TOK = 7,
    RB_TOK = 8,
    LB_TOK = 9,
    PLUS_TOK = 10,
    MINUS_TOK = 11,
    TIMES_TOK = 12,
    DIV_TOK = 13,
    PUT_TOK = 14,
    GET_TOK = 15,
    NOTEQ_TOK = 16,
    EQ_TOK = 17,
    GT_TOK = 18,
    LT_TOK = 19,
    GTOE_TOK = 21,
    LTOE_TOK = 22,
    IF_TOK = 23,
    WHILE_TOK = 24,
    ELSE_TOK = 25,
    STRINGLIT_TOK = 26,
    BAND_TOK = 27,
    BOR_TOK = 28,
    FOR_TOK = 29,
    LOOP_TOK = 30,
    BREAK_TOK = 31,
    CNST_TOK = 1000,
    SWITCH_TOK = 1001,
    CASE_TOK = 1002,
    DEF_TOK = 1003,
    RET_TOK = 1004
  };
#endif
/* Tokens.  */
#define IDENT_TOK 1
#define DECL_TOK 2
#define IMPL_TOK 3
#define INT_TOK 4
#define CHR_TOK 5
#define CHRLIT_TOK 6
#define INTLIT_TOK 7
#define RB_TOK 8
#define LB_TOK 9
#define PLUS_TOK 10
#define MINUS_TOK 11
#define TIMES_TOK 12
#define DIV_TOK 13
#define PUT_TOK 14
#define GET_TOK 15
#define NOTEQ_TOK 16
#define EQ_TOK 17
#define GT_TOK 18
#define LT_TOK 19
#define GTOE_TOK 21
#define LTOE_TOK 22
#define IF_TOK 23
#define WHILE_TOK 24
#define ELSE_TOK 25
#define STRINGLIT_TOK 26
#define BAND_TOK 27
#define BOR_TOK 28
#define FOR_TOK 29
#define LOOP_TOK 30
#define BREAK_TOK 31
#define CNST_TOK 1000
#define SWITCH_TOK 1001
#define CASE_TOK 1002
#define DEF_TOK 1003
#define RET_TOK 1004

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 12 "YGrammar.y" /* yacc.c:355  */

  int Integer;
  char * Text;
  struct IdList * IdList;
  enum BaseTypes BaseType;
  struct InstrSeq * InstrSeq;
  struct ExprResult * ExprResult;
  struct CondResult * CondResult;

#line 200 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 217 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   200

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  193

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1005

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       2,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,     2,    46,     2,     2,     2,     2,     2,     2,
      43,    44,     2,     2,    40,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    38,    39,
       2,    45,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    41,     2,    42,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      33,    34,    35,    36,    37,     2
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   108,   108,   110,   111,   112,   113,   116,   117,   119,
     120,   122,   124,   126,   127,   129,   130,   131,   133,   134,
     136,   137,   139,   141,   144,   145,   147,   149,   150,   151,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   168,   170,   172,   173,   174,   176,
     178,   179,   181,   182,   184,   185,   187,   188,   190,   191,
     192,   193,   196,   197,   200,   201,   202,   203,   204,   205,
     207,   208,   209,   211,   212,   213,   215,   216,   219,   220,
     222,   224,   225,   227,   228,   229,   230,   232,   234,   235,
     237,   238,   240,   241
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENT_TOK", "DECL_TOK", "IMPL_TOK",
  "INT_TOK", "CHR_TOK", "CHRLIT_TOK", "INTLIT_TOK", "RB_TOK", "LB_TOK",
  "PLUS_TOK", "MINUS_TOK", "TIMES_TOK", "DIV_TOK", "PUT_TOK", "GET_TOK",
  "NOTEQ_TOK", "EQ_TOK", "GT_TOK", "LT_TOK", "GTOE_TOK", "LTOE_TOK",
  "IF_TOK", "WHILE_TOK", "ELSE_TOK", "STRINGLIT_TOK", "BAND_TOK",
  "BOR_TOK", "FOR_TOK", "LOOP_TOK", "BREAK_TOK", "CNST_TOK", "SWITCH_TOK",
  "CASE_TOK", "DEF_TOK", "RET_TOK", "':'", "';'", "','", "'['", "']'",
  "'('", "')'", "'='", "'!'", "$accept", "Module", "DeclImpls", "Cnst",
  "Value", "CnstList", "CnstItem", "Decl", "DeclList", "DeclItem", "Id",
  "FuncArgTypes", "Type", "Impl", "FuncArgNames", "FuncBody", "Start",
  "FuncStmts", "Stmt", "FunAssign", "FuncCall", "Cases", "Loop", "Assigns",
  "IncDecs", "CondExpr", "CondTerm", "CondFactor", "Cond", "IncDec",
  "CondOp", "PutF", "StringLit", "ChrLit", "IntLit", "AssignStmt", "Expr",
  "GetF", "Term", "Factor", "AddOp", "MultOp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,  1005,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,  1000,  1001,  1002,  1003,  1004,    58,    59,
      44,    91,    93,    40,    41,    61,    33
};
# endif

#define YYPACT_NINF -144

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-144)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      66,     6,     6,     6,    56,  -144,    66,    66,    66,  -144,
      30,    39,    71,    49,    46,    87,  -144,  -144,  -144,  -144,
    -144,   129,     6,   100,    80,  -144,    86,   143,   142,     6,
    -144,  -144,   116,  -144,  -144,   114,  -144,  -144,   147,   119,
      27,  -144,   120,  -144,  -144,  -144,  -144,  -144,   117,   118,
     121,   122,   143,   123,   124,    24,    35,   153,   127,  -144,
    -144,  -144,  -144,  -144,    15,     3,     3,     6,  -144,  -144,
      27,    24,  -144,  -144,    24,   125,    24,   128,  -144,   126,
    -144,   130,  -144,   158,   159,   139,    24,    24,  -144,  -144,
    -144,    27,  -144,   131,   132,   133,     3,   136,    21,   145,
    -144,  -144,    98,    33,    84,   110,  -144,  -144,     1,   126,
     168,    69,    24,  -144,  -144,    24,  -144,  -144,    24,  -144,
    -144,  -144,  -144,    13,    90,  -144,   126,  -144,  -144,  -144,
    -144,    45,    82,     3,   149,   143,   152,  -144,  -144,  -144,
    -144,  -144,  -144,    24,   143,    24,     3,     6,   170,   141,
    -144,    41,   130,  -144,   138,  -144,    79,     3,   160,     3,
     126,  -144,   -22,  -144,  -144,  -144,  -144,    24,  -144,   145,
     143,  -144,     6,    62,   126,  -144,   140,   144,   150,  -144,
      24,   146,   143,     6,    94,   143,  -144,  -144,   143,   148,
     154,  -144,  -144
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     0,     0,     0,     2,     6,     6,     6,    18,
       0,    14,    15,     0,     0,    10,    11,     1,     5,     3,
       4,     0,     0,     0,     0,    17,     0,     0,     0,     0,
      20,    21,     0,    13,    75,     0,    19,    23,    26,     0,
      29,     8,     0,     9,    12,    16,    25,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    42,
      39,    35,    34,     7,     0,     0,     0,     0,    49,    33,
      29,     0,    74,    87,     0,     0,     0,    85,    89,    43,
      88,    79,    82,     0,     0,     0,     0,     0,    45,    30,
      24,    29,    73,     0,     0,     0,     0,     0,     0,    55,
      57,    60,     0,     0,     0,     0,    51,    28,     0,    84,
       0,     0,     0,    91,    90,     0,    92,    93,     0,    62,
      63,    31,    32,     0,    85,    44,    76,    27,    71,    72,
      70,     0,     0,     0,     0,     0,     0,    64,    65,    66,
      67,    68,    69,     0,     0,     0,     0,     0,     0,     0,
      83,     0,    78,    81,     0,    58,     0,     0,    38,     0,
      61,    36,     0,    50,    48,    80,    86,     0,    59,    54,
       0,    56,     0,     0,    77,    37,     0,     0,    53,    41,
       0,     0,     0,     0,     0,     0,    40,    52,     0,     0,
       0,    47,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,   135,  -144,  -144,   162,  -144,  -144,   167,  -144,
      -1,  -144,  -144,  -144,   179,   -48,  -144,   -60,  -144,  -144,
     107,  -144,  -144,  -144,    12,   -58,    40,    37,  -144,  -143,
    -144,  -144,  -144,   -49,   113,   -62,   -52,  -144,    85,    81,
    -144,  -144
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    42,    14,    15,     7,    10,    11,
      77,    25,    32,     8,    88,    39,    40,    57,    58,    89,
      59,   173,    69,   105,   177,    98,    99,   100,   101,    60,
     143,    61,    94,    78,    35,    62,   102,    80,    81,    82,
     115,   118
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      12,    13,    16,    79,    68,   106,     9,   134,   103,     9,
     107,    72,    73,   113,   114,    95,    74,   172,     9,   108,
      75,    12,   109,    72,   111,   113,   114,     9,    16,   178,
       9,   127,    72,    73,   123,   126,   121,    74,   131,    56,
     178,    75,    92,    48,   132,   148,    96,    83,    84,    97,
     134,    49,    50,   113,   114,   154,    17,    51,    52,    53,
     151,    54,   134,    93,    55,   135,   104,    76,    21,    56,
       1,     2,   179,    85,   134,   156,    86,   144,    26,    22,
      87,   113,   114,   166,    28,   163,   124,   158,   162,   155,
      56,   160,    26,   126,   113,   114,   161,   180,   181,     3,
     137,   138,   139,   140,   141,   142,   113,   114,   134,    34,
     113,   114,    23,   150,    24,   174,   137,   138,   139,   140,
     141,   142,   175,   168,    36,    86,   150,    29,   184,   145,
      37,   112,   188,    26,   186,    30,    31,   189,   113,   114,
     190,    18,    19,    20,   116,   117,   104,    72,    34,   146,
     147,    41,    83,    84,    38,    44,    45,    46,    47,    63,
      64,    65,    70,    90,    66,    67,    91,    71,   110,   112,
     119,   176,   120,   136,   149,   128,   129,   130,   157,   133,
     159,   164,   176,   167,   185,   165,   170,   191,   182,    33,
     183,    43,    27,   192,   125,   187,   171,   169,   122,   153,
     152
};

static const yytype_uint8 yycheck[] =
{
       1,     2,     3,    55,    52,    67,     3,    29,    66,     3,
      70,     8,     9,    12,    13,    64,    13,    39,     3,    71,
      17,    22,    74,     8,    76,    12,    13,     3,    29,   172,
       3,    91,     8,     9,    86,    87,    85,    13,    96,    40,
     183,    17,    27,    16,    96,    44,    43,    12,    13,    46,
      29,    24,    25,    12,    13,    42,     0,    30,    31,    32,
     112,    34,    29,    64,    37,    44,    67,    43,    38,    70,
       4,     5,    10,    38,    29,   133,    41,    44,    43,    40,
      45,    12,    13,    42,    38,   147,    87,   135,   146,    44,
      91,   143,    43,   145,    12,    13,   144,    35,    36,    33,
      18,    19,    20,    21,    22,    23,    12,    13,    29,     9,
      12,    13,    41,    44,    43,   167,    18,    19,    20,    21,
      22,    23,   170,    44,    44,    41,    44,    40,   180,    45,
      44,    41,    38,    43,   182,     6,     7,   185,    12,    13,
     188,     6,     7,     8,    14,    15,   147,     8,     9,    39,
      40,     9,    12,    13,    11,    39,    42,    10,    39,    39,
      43,    43,    39,    10,    43,    43,    39,    43,    43,    41,
      12,   172,    13,    28,     6,    44,    44,    44,    29,    43,
      28,    11,   183,    45,    38,    44,    26,    39,    44,    22,
      40,    29,    13,    39,    87,   183,   159,   157,    85,   118,
     115
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,    33,    48,    49,    50,    54,    60,     3,
      55,    56,    57,    57,    52,    53,    57,     0,    49,    49,
      49,    38,    40,    41,    43,    58,    43,    61,    38,    40,
       6,     7,    59,    55,     9,    81,    44,    44,    11,    62,
      63,     9,    51,    52,    39,    42,    10,    39,    16,    24,
      25,    30,    31,    32,    34,    37,    57,    64,    65,    67,
      76,    78,    82,    39,    43,    43,    43,    43,    62,    69,
      39,    43,     8,     9,    13,    17,    43,    57,    80,    83,
      84,    85,    86,    12,    13,    38,    41,    45,    61,    66,
      10,    39,    27,    57,    79,    80,    43,    46,    72,    73,
      74,    75,    83,    72,    57,    70,    82,    64,    83,    83,
      43,    83,    41,    12,    13,    87,    14,    15,    88,    12,
      13,    80,    81,    83,    57,    67,    83,    64,    44,    44,
      44,    72,    83,    43,    29,    44,    28,    18,    19,    20,
      21,    22,    23,    77,    44,    45,    39,    40,    44,     6,
      44,    83,    85,    86,    42,    44,    72,    29,    62,    28,
      83,    62,    72,    82,    11,    44,    42,    45,    44,    73,
      26,    74,    39,    68,    83,    62,    57,    71,    76,    10,
      35,    36,    44,    40,    83,    38,    62,    71,    38,    62,
      62,    39,    39
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    49,    49,    50,    51,    52,
      52,    53,    54,    55,    55,    56,    56,    56,    57,    58,
      59,    59,    60,    61,    62,    62,    63,    64,    64,    64,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    66,    67,    68,    68,    68,    69,
      70,    70,    71,    71,    72,    72,    73,    73,    74,    74,
      74,    75,    76,    76,    77,    77,    77,    77,    77,    77,
      78,    78,    78,    79,    80,    81,    82,    82,    83,    83,
      84,    85,    85,    86,    86,    86,    86,    86,    86,    86,
      87,    87,    88,    88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     0,     5,     1,     3,
       1,     1,     5,     3,     1,     1,     4,     2,     1,     2,
       1,     1,     5,     2,     3,     2,     1,     3,     3,     0,
       2,     3,     3,     2,     1,     1,     5,     7,     5,     1,
       9,     7,     1,     2,     2,     2,     6,     5,     0,     1,
       3,     1,     3,     1,     4,     1,     4,     1,     3,     4,
       1,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     1,     1,     1,     3,     6,     3,     1,
       4,     3,     1,     3,     2,     1,     4,     1,     1,     1,
       1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 108 "YGrammar.y" /* yacc.c:1646  */
    { Finish(); }
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 110 "YGrammar.y" /* yacc.c:1646  */
    { }
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 111 "YGrammar.y" /* yacc.c:1646  */
    { }
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 112 "YGrammar.y" /* yacc.c:1646  */
    { }
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 113 "YGrammar.y" /* yacc.c:1646  */
    { }
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 116 "YGrammar.y" /* yacc.c:1646  */
    { ProcDecls((yyvsp[-3].IdList),ConstantBaseType,(yyvsp[-1].Text)); }
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 117 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.Text) = strdup(yytext); }
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 119 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.IdList) = AppendIdList((yyvsp[-2].IdList),(yyvsp[0].IdList)); }
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 120 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.IdList) = (yyvsp[0].IdList); }
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 122 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.IdList) = ProcName((yyvsp[0].Text),CnstType,NULL,0); }
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 124 "YGrammar.y" /* yacc.c:1646  */
    { ProcDecls((yyvsp[-3].IdList),(yyvsp[-1].BaseType),0); }
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 126 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.IdList) = AppendIdList((yyvsp[-2].IdList),(yyvsp[0].IdList)); }
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 127 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.IdList) = (yyvsp[0].IdList); }
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 129 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.IdList) = ProcName((yyvsp[0].Text),PrimType,NULL,0); }
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 130 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.IdList) = ProcName((yyvsp[-3].Text),PrimType,(yyvsp[-1].Text),1); }
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 131 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.IdList) = ProcName((yyvsp[-1].Text),FuncType,NULL,2); }
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 133 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.Text) = strdup(yytext); }
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 134 "YGrammar.y" /* yacc.c:1646  */
    {  }
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 136 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = IntBaseType; }
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 137 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = ChrBaseType; }
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 139 "YGrammar.y" /* yacc.c:1646  */
    { ProcFunc((yyvsp[-3].Text),(yyvsp[-1].InstrSeq)); }
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 141 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = NULL; }
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 144 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = (yyvsp[-1].InstrSeq);  DeleteTable(); }
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 145 "YGrammar.y" /* yacc.c:1646  */
    {  }
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 147 "YGrammar.y" /* yacc.c:1646  */
    { NewTable(); }
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 149 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = AppendSeq((yyvsp[-2].InstrSeq),(yyvsp[0].InstrSeq));}
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 150 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = AppendBreak((yyvsp[0].InstrSeq)); }
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 151 "YGrammar.y" /* yacc.c:1646  */
    {  (yyval.InstrSeq) = NULL; }
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 153 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = genStoreWord( (yyvsp[-1].Text) , (yyvsp[0].ExprResult)); }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 154 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = LocDecl((yyvsp[-2].Text),(yyvsp[0].Text),ChrBaseType); }
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 155 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = LocDecl((yyvsp[-2].Text),(yyvsp[0].Text),IntBaseType); }
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 156 "YGrammar.y" /* yacc.c:1646  */
    { IncLoop(); (yyval.InstrSeq)=(yyvsp[0].InstrSeq);}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 157 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = (yyvsp[0].InstrSeq); }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 158 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = (yyvsp[0].InstrSeq); }
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 159 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = MakeWhile((yyvsp[-2].CondResult),(yyvsp[0].InstrSeq)); }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 160 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = MakeIf((yyvsp[-4].CondResult),(yyvsp[-2].InstrSeq), IfElseType, (yyvsp[0].InstrSeq)); }
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 161 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = MakeIf((yyvsp[-2].CondResult),(yyvsp[0].InstrSeq), IfType, NULL); }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 162 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = (yyvsp[0].InstrSeq); }
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 163 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = MakeFor((yyvsp[-6].InstrSeq),(yyvsp[-4].CondResult),(yyvsp[-2].InstrSeq),(yyvsp[0].InstrSeq)); }
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 164 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = MakeSwitch((yyvsp[-4].ExprResult),(yyvsp[-1].CondResult)); }
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 165 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = MakeSeq((yyvsp[0].ExprResult)); }
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 166 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = ReturnVal((yyvsp[0].ExprResult)); }
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 168 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = (yyvsp[0].ExprResult); }
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 170 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = MakeFuncCall((yyvsp[-1].Text), (yyvsp[0].ExprResult)); }
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 172 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = MakeCase((yyvsp[-3].ExprResult),(yyvsp[-1].InstrSeq),(yyvsp[-5].CondResult)); }
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 173 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = MakeCase(NULL,(yyvsp[-1].InstrSeq),(yyvsp[-4].CondResult)); }
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 174 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = NULL; }
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 176 "YGrammar.y" /* yacc.c:1646  */
    { DecLoop();  (yyval.InstrSeq) = MakeLoop((yyvsp[0].InstrSeq));}
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 178 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = AppendSeq((yyvsp[-2].InstrSeq),(yyvsp[0].InstrSeq));}
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 179 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = (yyvsp[0].InstrSeq);}
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 181 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = AppendSeq((yyvsp[-2].InstrSeq),(yyvsp[0].InstrSeq));}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 182 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = (yyvsp[0].InstrSeq);}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 184 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = ConcatenateCond((yyvsp[-3].CondResult), OrType, (yyvsp[0].CondResult)); }
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 185 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = (yyvsp[0].CondResult); }
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 187 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = ConcatenateCond((yyvsp[-3].CondResult), AndType, (yyvsp[0].CondResult)); }
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 188 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = (yyvsp[0].CondResult); }
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 190 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = (yyvsp[-1].CondResult); }
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 191 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = NegateCond((yyvsp[-1].CondResult)); }
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 192 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = (yyvsp[0].CondResult); }
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 193 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = MakeCond((yyvsp[-2].ExprResult),(yyvsp[-1].BaseType),(yyvsp[0].ExprResult)); }
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 196 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = IncDec((yyvsp[-2].Text),PlusType);}
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 197 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = IncDec((yyvsp[-2].Text),MinusType);}
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 200 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = NotEqualType; }
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 201 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = EqualType; }
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 202 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = GreaterThanType; }
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 203 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = LessThanType; }
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 204 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = GreaterThanOrEqualType; }
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 205 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = LessThanOrEqualType; }
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 207 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = PutFunc( (yyvsp[-1].Text) , ChrBaseType );}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 208 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = PutFunc( (yyvsp[-1].Text), IntBaseType );}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 209 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = PutFunc( (yyvsp[-1].Text), StringBaseType );}
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 211 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.Text) = strdup(yytext); }
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 212 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.Text) = strdup(yytext); }
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 213 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.Text) = strdup(yytext); }
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 215 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = genStoreWord( (yyvsp[-2].Text) , (yyvsp[0].ExprResult)); }
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 216 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = GenStoreArr( (yyvsp[-5].Text) , (yyvsp[0].ExprResult), (yyvsp[-3].ExprResult)); }
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 219 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = Concatenate((yyvsp[-2].ExprResult),(yyvsp[-1].BaseType),(yyvsp[0].ExprResult)); }
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 220 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = (yyvsp[0].ExprResult); }
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 222 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = GetFunc(); }
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 224 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = Concatenate((yyvsp[-2].ExprResult),(yyvsp[-1].BaseType),(yyvsp[0].ExprResult)); }
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 225 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = (yyvsp[0].ExprResult); }
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 227 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = (yyvsp[-1].ExprResult); }
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 228 "YGrammar.y" /* yacc.c:1646  */
    {  }
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 229 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = loadExprResult( (yyvsp[0].Text) ); }
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 230 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = LoadExprArr( (yyvsp[-3].Text), (yyvsp[-1].ExprResult)); }
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 232 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = createExprResult( strdup( yytext ),
                                                                          IntBaseType); }
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 234 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = (yyvsp[0].ExprResult); }
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 235 "YGrammar.y" /* yacc.c:1646  */
    {  }
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 237 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = MinusType; }
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 238 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = PlusType; }
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 240 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = TimesType; }
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 241 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = DivideType; }
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2056 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 245 "YGrammar.y" /* yacc.c:1906  */


void
yyerror( char *s)     {
  char msg[MAXLINE];
  sprintf(msg,"ERROR \"%s\" token: \"%s\"",s,yytext);
  PostMessage(GetCurrentColumn(),strlen(yytext),msg);
}
