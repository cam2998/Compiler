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
    DEF_TOK = 1003
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

#line 198 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 215 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   180

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  169

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1004

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       2,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,     2,    42,     2,     2,     2,     2,     2,     2,
      40,    41,     2,     2,    39,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    37,    38,
       2,    43,     2,     2,     2,     2,     2,     2,     2,     2,
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
      33,    34,    35,    36,     2
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   103,   103,   105,   106,   107,   108,   111,   112,   114,
     115,   117,   119,   121,   122,   124,   125,   127,   128,   130,
     131,   133,   135,   137,   138,   140,   141,   142,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   154,   155,   156,
     158,   160,   161,   163,   164,   166,   167,   169,   170,   172,
     173,   174,   175,   178,   179,   182,   183,   184,   185,   186,
     187,   189,   190,   191,   193,   194,   196,   198,   199,   201,
     203,   204,   206,   207,   208,   209,   211,   212,   214,   215,
     217,   218
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
  "CASE_TOK", "DEF_TOK", "':'", "';'", "','", "'('", "')'", "'!'", "'='",
  "$accept", "Module", "DeclImpls", "Cnst", "Value", "CnstList",
  "CnstItem", "Decl", "DeclList", "DeclItem", "Id", "FuncArgTypes", "Type",
  "Impl", "FuncArgNames", "FuncBody", "FuncStmts", "Stmt", "Cases", "Loop",
  "Assigns", "IncDecs", "CondExpr", "CondTerm", "CondFactor", "Cond",
  "IncDec", "CondOp", "PutF", "StringLit", "ChrLit", "AssignStmt", "Expr",
  "GetF", "Term", "Factor", "AddOp", "MultOp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,  1004,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,  1000,  1001,  1002,  1003,    58,    59,    44,
      40,    41,    33,    61
};
# endif

#define YYPACT_NINF -61

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-61)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      43,     7,     7,     7,    46,   -61,    43,    43,    43,   -61,
     -22,   -13,    23,    29,     2,    48,   -61,   -61,   -61,   -61,
     -61,   105,     7,    49,   -61,    73,   108,   118,     7,   -61,
     -61,   100,   -61,   -61,   -61,    54,   101,   -61,   103,   -61,
     -61,   -61,   104,   106,   107,   109,   108,   113,   114,     1,
     130,   115,   -61,   -61,   -61,   -61,   -61,    50,     3,     3,
       7,   -61,   -61,     6,    15,   131,   129,    15,   -61,     6,
     -61,   -61,   111,   116,   119,   -61,   -61,    15,   121,     3,
     122,   -61,     0,   117,   -61,   -61,   110,   -61,   120,   -61,
      32,   123,    78,   -61,   -61,    15,    39,   -61,   -61,   112,
     -61,   -61,   -61,   -61,   112,   144,    42,    79,     3,   126,
     108,   128,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,
      15,    15,   -61,   -61,    15,   108,     3,     7,    53,   148,
     127,   -61,   -61,    64,     3,   137,     3,   112,   120,   -61,
     -61,     4,   -61,   -61,   -61,   -61,   117,   108,   -61,     7,
      71,   -61,   124,   132,   125,   -61,    15,   133,   108,     7,
      37,   108,   -61,   -61,   108,   134,   136,   -61,   -61
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     0,     0,     0,     2,     6,     6,     6,    17,
       0,    14,    15,     0,     0,    10,    11,     1,     5,     3,
       4,     0,     0,     0,    16,     0,     0,     0,     0,    19,
      20,     0,    13,    18,    22,     0,     0,     8,     0,     9,
      12,    24,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    34,    30,    29,    21,     7,     0,     0,     0,
       0,    40,    28,    27,     0,     0,     0,     0,    23,    27,
      65,    64,     0,     0,     0,    77,    75,     0,     0,     0,
       0,    74,     0,    46,    48,    51,     0,    76,    68,    71,
       0,     0,     0,    42,    26,     0,     0,    53,    54,    66,
      25,    62,    63,    61,    73,     0,     0,     0,     0,     0,
       0,     0,    79,    78,    55,    56,    57,    58,    59,    60,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
       0,    49,    72,     0,     0,    33,     0,    52,    67,    70,
      31,     0,    41,    39,    69,    50,    45,     0,    47,     0,
       0,    32,     0,     0,    44,    36,     0,     0,     0,     0,
       0,     0,    35,    43,     0,     0,     0,    38,    37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -61,   -61,   102,   -61,   -61,   139,   -61,   -61,   143,   -61,
      -1,   -61,   -61,   -61,   -61,   -43,    26,   -61,   -61,   -61,
     -61,    10,   -54,    41,    35,   -61,   -46,   -61,   -61,   -61,
     -61,   -52,   -60,   -61,    55,    56,   -61,   -61
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    38,    14,    15,     7,    10,    11,
      81,    24,    31,     8,    26,    36,    50,    51,   150,    62,
      92,   153,    82,    83,    84,    85,    52,   120,    53,    73,
      74,    54,    86,    87,    88,    89,   121,   124
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      12,    13,    16,    61,    96,    90,     9,    99,    93,     9,
       9,    75,    76,    65,    66,    21,    77,   104,     9,   107,
      78,    12,    42,    75,    76,   106,    22,    16,    77,   109,
      43,    44,    78,   109,    49,   128,    45,    46,    47,    27,
      48,   110,   149,    79,    67,    80,    17,     1,     2,   112,
     113,   112,   113,     9,   133,    95,    72,     9,    70,    91,
     137,   109,    49,    23,    41,   112,   113,   135,    49,    25,
      42,   109,   141,   125,   164,   142,     3,    71,    43,    44,
     129,   155,   140,   131,    45,    46,    47,    28,    48,    94,
      33,   112,   113,   109,   132,   100,   160,   114,   115,   116,
     117,   118,   119,   154,   151,   145,   156,   157,    18,    19,
      20,    29,    30,   154,    34,   162,   126,   127,   165,    35,
     132,   166,   112,   113,   112,   113,    91,    37,   114,   115,
     116,   117,   118,   119,   122,   123,    65,    66,    40,    55,
      68,    56,    98,    97,    57,   111,    58,    59,   152,    60,
     130,    63,   101,    69,    64,   134,   136,   102,   152,   143,
     103,   105,   108,   147,   159,    32,    67,    39,   144,   163,
     161,   148,   167,   158,   168,   146,   138,     0,     0,     0,
     139
};

static const yytype_int16 yycheck[] =
{
       1,     2,     3,    46,    64,    59,     3,    67,    60,     3,
       3,     8,     9,    12,    13,    37,    13,    77,     3,    79,
      17,    22,    16,     8,     9,    79,    39,    28,    13,    29,
      24,    25,    17,    29,    35,    95,    30,    31,    32,    37,
      34,    41,    38,    40,    43,    42,     0,     4,     5,    12,
      13,    12,    13,     3,   108,    40,    57,     3,     8,    60,
     120,    29,    63,    40,    10,    12,    13,   110,    69,    40,
      16,    29,   126,    41,    37,   127,    33,    27,    24,    25,
      41,    10,   125,    41,    30,    31,    32,    39,    34,    63,
      41,    12,    13,    29,    41,    69,   156,    18,    19,    20,
      21,    22,    23,   149,   147,    41,    35,    36,     6,     7,
       8,     6,     7,   159,    41,   158,    38,    39,   161,    11,
      41,   164,    12,    13,    12,    13,   127,     9,    18,    19,
      20,    21,    22,    23,    14,    15,    12,    13,    38,    38,
      10,    38,    13,    12,    40,    28,    40,    40,   149,    40,
       6,    38,    41,    38,    40,    29,    28,    41,   159,    11,
      41,    40,    40,    26,    39,    22,    43,    28,    41,   159,
      37,   136,    38,    41,    38,   134,   121,    -1,    -1,    -1,
     124
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,    33,    45,    46,    47,    51,    57,     3,
      52,    53,    54,    54,    49,    50,    54,     0,    46,    46,
      46,    37,    39,    40,    55,    40,    58,    37,    39,     6,
       7,    56,    52,    41,    41,    11,    59,     9,    48,    49,
      38,    10,    16,    24,    25,    30,    31,    32,    34,    54,
      60,    61,    70,    72,    75,    38,    38,    40,    40,    40,
      40,    59,    63,    38,    40,    12,    13,    43,    10,    38,
       8,    27,    54,    73,    74,     8,     9,    13,    17,    40,
      42,    54,    66,    67,    68,    69,    76,    77,    78,    79,
      66,    54,    64,    75,    60,    40,    76,    12,    13,    76,
      60,    41,    41,    41,    76,    40,    66,    76,    40,    29,
      41,    28,    12,    13,    18,    19,    20,    21,    22,    23,
      71,    80,    14,    15,    81,    41,    38,    39,    76,    41,
       6,    41,    41,    66,    29,    59,    28,    76,    78,    79,
      59,    66,    75,    11,    41,    41,    67,    26,    68,    38,
      62,    59,    54,    65,    70,    10,    35,    36,    41,    39,
      76,    37,    59,    65,    37,    59,    59,    38,    38
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    46,    46,    47,    48,    49,
      49,    50,    51,    52,    52,    53,    53,    54,    55,    56,
      56,    57,    58,    59,    59,    60,    60,    60,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    62,    62,    62,
      63,    64,    64,    65,    65,    66,    66,    67,    67,    68,
      68,    68,    69,    70,    70,    71,    71,    71,    71,    71,
      71,    72,    72,    72,    73,    74,    75,    76,    76,    77,
      78,    78,    79,    79,    79,    79,    79,    79,    80,    80,
      81,    81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     0,     5,     1,     3,
       1,     1,     5,     3,     1,     1,     2,     1,     2,     1,
       1,     5,     2,     3,     2,     3,     3,     0,     2,     1,
       1,     5,     7,     5,     1,     9,     7,     6,     5,     0,
       1,     3,     1,     3,     1,     4,     1,     4,     1,     3,
       4,     1,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     1,     1,     3,     3,     1,     4,
       3,     1,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1
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
#line 103 "YGrammar.y" /* yacc.c:1646  */
    { Finish(); }
#line 1484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 105 "YGrammar.y" /* yacc.c:1646  */
    { }
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 106 "YGrammar.y" /* yacc.c:1646  */
    { }
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 107 "YGrammar.y" /* yacc.c:1646  */
    { }
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 108 "YGrammar.y" /* yacc.c:1646  */
    { }
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 111 "YGrammar.y" /* yacc.c:1646  */
    { ProcDecls((yyvsp[-3].IdList),ConstantBaseType,(yyvsp[-1].Text)); }
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 112 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.Text) = strdup(yytext); }
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 114 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.IdList) = AppendIdList((yyvsp[-2].IdList),(yyvsp[0].IdList)); }
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 115 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.IdList) = (yyvsp[0].IdList); }
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 117 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.IdList) = ProcName((yyvsp[0].Text),CnstType); }
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 119 "YGrammar.y" /* yacc.c:1646  */
    { ProcDecls((yyvsp[-3].IdList),(yyvsp[-1].BaseType),0); }
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 121 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.IdList) = AppendIdList((yyvsp[-2].IdList),(yyvsp[0].IdList)); }
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 122 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.IdList) = (yyvsp[0].IdList); }
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 124 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.IdList) = ProcName((yyvsp[0].Text),PrimType); }
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 125 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.IdList) = ProcName((yyvsp[-1].Text),FuncType); }
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 127 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.Text) = strdup(yytext); }
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 128 "YGrammar.y" /* yacc.c:1646  */
    {  }
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 130 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = IntBaseType; }
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 131 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = ChrBaseType; }
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 133 "YGrammar.y" /* yacc.c:1646  */
    { ProcFunc((yyvsp[-3].Text),(yyvsp[-1].InstrSeq)); }
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 135 "YGrammar.y" /* yacc.c:1646  */
    {  }
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 137 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = (yyvsp[-1].InstrSeq); }
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 138 "YGrammar.y" /* yacc.c:1646  */
    {  }
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 140 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = AppendSeq((yyvsp[-2].InstrSeq),(yyvsp[0].InstrSeq)); }
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 141 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = AppendBreak((yyvsp[0].InstrSeq)); }
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 142 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = NULL; }
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 144 "YGrammar.y" /* yacc.c:1646  */
    { IncLoop(); (yyval.InstrSeq)=(yyvsp[0].InstrSeq);}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 145 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = (yyvsp[0].InstrSeq); }
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 146 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = (yyvsp[0].InstrSeq); }
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 147 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = MakeWhile((yyvsp[-2].CondResult),(yyvsp[0].InstrSeq)); }
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 148 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = MakeIf((yyvsp[-4].CondResult),(yyvsp[-2].InstrSeq), IfElseType, (yyvsp[0].InstrSeq)); }
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 149 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = MakeIf((yyvsp[-2].CondResult),(yyvsp[0].InstrSeq), IfType, NULL); }
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 150 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = (yyvsp[0].InstrSeq); }
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 151 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = MakeFor((yyvsp[-6].InstrSeq),(yyvsp[-4].CondResult),(yyvsp[-2].InstrSeq),(yyvsp[0].InstrSeq)); }
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 152 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = MakeSwitch((yyvsp[-4].ExprResult),(yyvsp[-1].CondResult)); }
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 154 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = MakeCase((yyvsp[-3].ExprResult),(yyvsp[-1].InstrSeq),(yyvsp[-5].CondResult)); }
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 155 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = MakeCase(NULL,(yyvsp[-1].InstrSeq),(yyvsp[-4].CondResult)); }
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 156 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = NULL; }
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 158 "YGrammar.y" /* yacc.c:1646  */
    { DecLoop();  (yyval.InstrSeq) = MakeLoop((yyvsp[0].InstrSeq));}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 160 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = AppendSeq((yyvsp[-2].InstrSeq),(yyvsp[0].InstrSeq));}
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 161 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = (yyvsp[0].InstrSeq);}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 163 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = AppendSeq((yyvsp[-2].InstrSeq),(yyvsp[0].InstrSeq));}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 164 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = (yyvsp[0].InstrSeq);}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 166 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = ConcatenateCond((yyvsp[-3].CondResult), OrType, (yyvsp[0].CondResult)); }
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 167 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = (yyvsp[0].CondResult); }
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 169 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = ConcatenateCond((yyvsp[-3].CondResult), AndType, (yyvsp[0].CondResult)); }
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 170 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = (yyvsp[0].CondResult); }
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 172 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = (yyvsp[-1].CondResult); }
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 173 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = NegateCond((yyvsp[-1].CondResult)); }
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 174 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = (yyvsp[0].CondResult); }
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 175 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = MakeCond((yyvsp[-2].ExprResult),(yyvsp[-1].BaseType),(yyvsp[0].ExprResult)); }
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 178 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = IncDec((yyvsp[-2].Text),PlusType);}
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 179 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = IncDec((yyvsp[-2].Text),MinusType);}
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 182 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = NotEqualType; }
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 183 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = EqualType; }
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 184 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = GreaterThanType; }
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 185 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = LessThanType; }
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 186 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = GreaterThanOrEqualType; }
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 187 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = LessThanOrEqualType; }
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 189 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = PutFunc( (yyvsp[-1].Text) , ChrBaseType );}
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 190 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = PutFunc( (yyvsp[-1].Text), IntBaseType );}
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 191 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = PutFunc( (yyvsp[-1].Text), StringBaseType );}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 193 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.Text) = strdup(yytext); }
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 194 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.Text) = strdup(yytext); }
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 196 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = genStoreWord( (yyvsp[-2].Text) , (yyvsp[0].ExprResult)); }
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 198 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = Concatenate((yyvsp[-2].ExprResult),(yyvsp[-1].BaseType),(yyvsp[0].ExprResult)); }
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 199 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = (yyvsp[0].ExprResult); }
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 201 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = GetFunc(); }
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 203 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = Concatenate((yyvsp[-2].ExprResult),(yyvsp[-1].BaseType),(yyvsp[0].ExprResult)); }
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 204 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = (yyvsp[0].ExprResult); }
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 206 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = (yyvsp[-1].ExprResult); }
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 207 "YGrammar.y" /* yacc.c:1646  */
    {  }
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 208 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = loadExprResult( (yyvsp[0].Text) ); }
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 209 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = createExprResult( strdup( yytext ),
                                                                          IntBaseType); }
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 211 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = (yyvsp[0].ExprResult); }
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 212 "YGrammar.y" /* yacc.c:1646  */
    {  }
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 214 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = MinusType; }
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 215 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = PlusType; }
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 217 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = TimesType; }
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 218 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = DivideType; }
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1963 "y.tab.c" /* yacc.c:1646  */
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
#line 222 "YGrammar.y" /* yacc.c:1906  */


void
yyerror( char *s)     {
  char msg[MAXLINE];
  sprintf(msg,"ERROR \"%s\" token: \"%s\"",s,yytext);
  PostMessage(GetCurrentColumn(),strlen(yytext),msg);
}
