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
    RET_TOK = 1004,
    CALL_TOK = 1005
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
#define CALL_TOK 1005

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

#line 202 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 219 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   224

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  198

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1006

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       2,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,     2,    47,     2,     2,     2,     2,     2,     2,
      44,    45,     2,     2,    41,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    39,    40,
       2,    46,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
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
      33,    34,    35,    36,    37,    38,     2
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   110,   110,   112,   113,   114,   115,   118,   119,   121,
     122,   124,   126,   128,   129,   131,   132,   133,   135,   136,
     138,   139,   141,   143,   144,   146,   147,   149,   150,   152,
     154,   155,   156,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   173,   175,   177,
     178,   179,   181,   183,   184,   186,   187,   189,   190,   192,
     193,   195,   196,   197,   198,   201,   202,   205,   206,   207,
     208,   209,   210,   212,   213,   214,   216,   217,   218,   220,
     221,   224,   225,   227,   229,   230,   232,   233,   234,   235,
     237,   239,   240,   242,   243,   245,   246
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
  "CASE_TOK", "DEF_TOK", "RET_TOK", "CALL_TOK", "':'", "';'", "','", "'['",
  "']'", "'('", "')'", "'='", "'!'", "$accept", "Module", "DeclImpls",
  "Cnst", "Value", "CnstList", "CnstItem", "Decl", "DeclList", "DeclItem",
  "Id", "FuncArgTypes", "Type", "Impl", "FuncArgNames", "Args", "FuncBody",
  "Start", "FuncStmts", "Stmt", "FunAssign", "FuncCall", "Cases", "Loop",
  "Assigns", "IncDecs", "CondExpr", "CondTerm", "CondFactor", "Cond",
  "IncDec", "CondOp", "PutF", "StringLit", "ChrLit", "IntLit",
  "AssignStmt", "Expr", "GetF", "Term", "Factor", "AddOp", "MultOp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,  1006,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,  1000,  1001,  1002,  1003,  1004,  1005,    58,
      59,    44,    91,    93,    40,    41,    61,    33
};
# endif

#define YYPACT_NINF -93

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-93)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      15,    10,    10,    10,    30,   -93,    15,    15,    15,   -93,
       5,     8,   -32,    13,    55,    11,   -93,   -93,   -93,   -93,
     -93,   133,    10,    60,    44,   -93,    26,   100,   105,    10,
     -93,   -93,    78,   -93,   -93,    92,   -93,   -93,   -93,    37,
      77,    37,   -93,   115,   111,   -93,    24,   -93,   127,   -93,
     151,   123,    99,   -93,   124,   -93,   -93,   -93,   138,   160,
      -4,    37,   -93,   -93,   -93,    37,    37,   -93,   -93,    37,
     -93,   -93,   121,   129,   130,   131,   100,   128,   139,    37,
      61,   157,   145,   -93,   -93,   -93,   -93,   -93,   141,   -93,
      12,   -93,   127,   -93,    64,    14,    14,    10,   -93,   -93,
      99,    37,   138,   172,   156,   144,    37,    37,   -93,   -93,
     -93,    99,   -93,   -93,   -93,   143,   146,   148,    14,   150,
      35,   161,   -93,   -93,   159,    53,   -35,   114,   -93,   -93,
       2,   -93,   -93,   -93,   -93,    20,    33,   -93,   138,   -93,
     -93,   -93,   -93,    63,   125,    14,   163,   100,   162,   -93,
     -93,   -93,   -93,   -93,   -93,    37,   100,    37,    14,    10,
     184,   152,   -93,    68,    14,   170,    14,   138,   -93,    50,
     -93,   -93,    37,   -93,   161,   100,   -93,    10,    52,   138,
     -93,   147,   154,   164,   -93,    37,   158,   100,    10,    47,
     100,   -93,   -93,   100,   166,   167,   -93,   -93
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     0,     0,     0,     2,     6,     6,     6,    18,
       0,    14,    15,     0,     0,    10,    11,     1,     5,     3,
       4,     0,     0,     0,     0,    17,     0,     0,     0,     0,
      20,    21,     0,    13,    78,     0,    19,    77,    90,     0,
       0,     0,    23,    88,     0,    92,    26,    91,    82,    85,
      29,     0,    32,     8,     0,     9,    12,    16,    87,     0,
       0,     0,    24,    94,    93,     0,     0,    95,    96,     0,
      28,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    45,    42,    38,    37,     7,     0,    86,
       0,    25,    81,    84,     0,     0,     0,     0,    52,    36,
      32,     0,    46,     0,     0,     0,     0,     0,    48,    33,
      27,    32,    83,    89,    76,     0,     0,     0,     0,     0,
       0,    58,    60,    63,     0,     0,     0,     0,    54,    31,
       0,    65,    66,    34,    35,     0,    88,    47,    79,    30,
      74,    75,    73,     0,     0,     0,     0,     0,     0,    67,
      68,    69,    70,    71,    72,     0,     0,     0,     0,     0,
       0,     0,    61,     0,     0,    41,     0,    64,    39,     0,
      53,    51,     0,    62,    57,     0,    59,     0,     0,    80,
      40,     0,     0,    56,    44,     0,     0,     0,     0,     0,
       0,    43,    55,     0,     0,     0,    50,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -93,   -93,   119,   -93,   -93,   171,   -93,   -93,   179,   -93,
      -1,   -93,   -93,   -93,   189,   149,   -71,   -93,     1,   -93,
     -93,    96,   -93,   -93,   -93,    16,   -92,    45,    42,   -93,
     -68,   -93,   -93,   -93,    23,   106,   -91,   -23,   -93,   153,
     155,   -93,   -93
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    54,    14,    15,     7,    10,    11,
      43,    25,    32,     8,   108,    44,    51,    52,    81,    82,
     109,    83,   178,    99,   127,   182,   120,   121,   122,   123,
      84,   155,    85,   116,    45,    35,    86,   124,    47,    48,
      49,    66,    69
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      12,    13,    16,    46,   125,    98,   128,   106,    63,    64,
      23,   157,    24,     9,    63,    64,    58,     9,    60,     1,
       2,    12,    37,    38,    63,    64,   143,    39,    16,     9,
      17,    40,    63,    64,    37,    38,    63,    64,    90,    39,
       9,    89,    46,    40,    21,    37,    38,   160,     3,    22,
      39,    80,    29,   163,    40,   113,   102,    26,   118,    63,
      64,   119,   184,   161,   146,    65,   169,     9,   170,    34,
      41,    42,    37,   103,   104,    61,   165,    26,   130,   146,
     147,    41,   146,   135,   138,   168,   193,   185,   186,    36,
     177,   114,   146,   115,    28,   144,   126,   146,   156,    80,
     105,   129,     9,   106,   180,    26,   136,   107,   162,   183,
      80,    50,   139,   173,    53,    72,   191,   117,    56,   194,
     183,    59,   195,    73,    74,    18,    19,    20,   133,    75,
      76,    77,   167,    78,   138,    57,    79,    63,    64,    30,
      31,    67,    68,   149,   150,   151,   152,   153,   154,   179,
      63,    64,    37,    34,   158,   159,    62,    61,   126,   103,
     104,    70,   189,    71,    87,    94,    88,   110,   100,   132,
      89,    63,    64,    95,    96,    97,   181,   149,   150,   151,
     152,   153,   154,   101,   131,   111,   112,   181,   140,   148,
     166,   141,   164,   142,   145,   171,   175,   190,   172,   187,
      55,    33,    27,   137,   192,   188,   196,   197,   176,   174,
       0,   134,     0,     0,    91,     0,     0,     0,     0,    92,
       0,     0,     0,     0,    93
};

static const yytype_int16 yycheck[] =
{
       1,     2,     3,    26,    96,    76,    97,    42,    12,    13,
      42,    46,    44,     3,    12,    13,    39,     3,    41,     4,
       5,    22,     8,     9,    12,    13,   118,    13,    29,     3,
       0,    17,    12,    13,     8,     9,    12,    13,    61,    13,
       3,    45,    65,    17,    39,     8,     9,    45,    33,    41,
      13,    52,    41,   145,    17,    43,    79,    44,    44,    12,
      13,    47,    10,    43,    29,    41,   158,     3,   159,     9,
      44,    45,     8,    12,    13,    42,   147,    44,   101,    29,
      45,    44,    29,   106,   107,   156,    39,    35,    36,    45,
      40,    27,    29,    94,    39,   118,    97,    29,    45,   100,
      39,   100,     3,    42,   175,    44,   107,    46,    45,   177,
     111,    11,   111,    45,     9,    16,   187,    94,    40,   190,
     188,    44,   193,    24,    25,     6,     7,     8,   105,    30,
      31,    32,   155,    34,   157,    43,    37,    12,    13,     6,
       7,    14,    15,    18,    19,    20,    21,    22,    23,   172,
      12,    13,     8,     9,    40,    41,    45,    42,   159,    12,
      13,    10,   185,    40,    40,    44,     6,    10,    40,    13,
      45,    12,    13,    44,    44,    44,   177,    18,    19,    20,
      21,    22,    23,    44,    12,    40,    45,   188,    45,    28,
      28,    45,    29,    45,    44,    11,    26,    39,    46,    45,
      29,    22,    13,   107,   188,    41,    40,    40,   166,   164,
      -1,   105,    -1,    -1,    65,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    -1,    -1,    69
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,    33,    49,    50,    51,    55,    61,     3,
      56,    57,    58,    58,    53,    54,    58,     0,    50,    50,
      50,    39,    41,    42,    44,    59,    44,    62,    39,    41,
       6,     7,    60,    56,     9,    83,    45,     8,     9,    13,
      17,    44,    45,    58,    63,    82,    85,    86,    87,    88,
      11,    64,    65,     9,    52,    53,    40,    43,    85,    44,
      85,    42,    45,    12,    13,    41,    89,    14,    15,    90,
      10,    40,    16,    24,    25,    30,    31,    32,    34,    37,
      58,    66,    67,    69,    78,    80,    84,    40,     6,    45,
      85,    63,    87,    88,    44,    44,    44,    44,    64,    71,
      40,    44,    85,    12,    13,    39,    42,    46,    62,    68,
      10,    40,    45,    43,    27,    58,    81,    82,    44,    47,
      74,    75,    76,    77,    85,    74,    58,    72,    84,    66,
      85,    12,    13,    82,    83,    85,    58,    69,    85,    66,
      45,    45,    45,    74,    85,    44,    29,    45,    28,    18,
      19,    20,    21,    22,    23,    79,    45,    46,    40,    41,
      45,    43,    45,    74,    29,    64,    28,    85,    64,    74,
      84,    11,    46,    45,    75,    26,    76,    40,    70,    85,
      64,    58,    73,    78,    10,    35,    36,    45,    41,    85,
      39,    64,    73,    39,    64,    64,    40,    40
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    50,    50,    50,    51,    52,    53,
      53,    54,    55,    56,    56,    57,    57,    57,    58,    59,
      60,    60,    61,    62,    62,    63,    63,    64,    64,    65,
      66,    66,    66,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    68,    69,    70,
      70,    70,    71,    72,    72,    73,    73,    74,    74,    75,
      75,    76,    76,    76,    77,    78,    78,    79,    79,    79,
      79,    79,    79,    80,    80,    80,    81,    82,    83,    84,
      84,    85,    85,    86,    87,    87,    88,    88,    88,    88,
      88,    88,    88,    89,    89,    90,    90
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     0,     5,     1,     3,
       1,     1,     5,     3,     1,     1,     4,     2,     1,     2,
       1,     1,     5,     2,     3,     3,     1,     3,     2,     1,
       3,     3,     0,     2,     3,     3,     2,     1,     1,     5,
       7,     5,     1,     9,     7,     1,     2,     2,     2,     6,
       5,     0,     1,     3,     1,     3,     1,     4,     1,     4,
       1,     3,     4,     1,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     1,     1,     1,     3,
       6,     3,     1,     4,     3,     1,     3,     2,     1,     4,
       1,     1,     1,     1,     1,     1,     1
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
#line 110 "YGrammar.y" /* yacc.c:1646  */
    { Finish(); }
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 112 "YGrammar.y" /* yacc.c:1646  */
    { }
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 113 "YGrammar.y" /* yacc.c:1646  */
    { }
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 114 "YGrammar.y" /* yacc.c:1646  */
    { }
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 115 "YGrammar.y" /* yacc.c:1646  */
    { }
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 118 "YGrammar.y" /* yacc.c:1646  */
    { ProcDecls((yyvsp[-3].IdList),ConstantBaseType,(yyvsp[-1].Text)); }
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 119 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.Text) = strdup(yytext); }
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 121 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.IdList) = AppendIdList((yyvsp[-2].IdList),(yyvsp[0].IdList)); }
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 122 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.IdList) = (yyvsp[0].IdList); }
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 124 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.IdList) = ProcName((yyvsp[0].Text),CnstType,NULL,0); }
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 126 "YGrammar.y" /* yacc.c:1646  */
    { ProcDecls((yyvsp[-3].IdList),(yyvsp[-1].BaseType),0); }
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 128 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.IdList) = AppendIdList((yyvsp[-2].IdList),(yyvsp[0].IdList)); }
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 129 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.IdList) = (yyvsp[0].IdList); }
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 131 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.IdList) = ProcName((yyvsp[0].Text),PrimType,NULL,0); }
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 132 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.IdList) = ProcName((yyvsp[-3].Text),PrimType,(yyvsp[-1].Text),1); }
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 133 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.IdList) = ProcName((yyvsp[-1].Text),FuncType,NULL,0); }
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 135 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.Text) = strdup(yytext); }
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 136 "YGrammar.y" /* yacc.c:1646  */
    {  }
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 138 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = IntBaseType; }
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 139 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = ChrBaseType; }
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 141 "YGrammar.y" /* yacc.c:1646  */
    { ProcFunc((yyvsp[-3].Text),(yyvsp[-1].InstrSeq)); }
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 143 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = NULL; }
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 144 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = (yyvsp[-1].ExprResult); }
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 146 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = AppendArgs((yyvsp[-2].ExprResult),(yyvsp[0].ExprResult)); }
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 147 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = (yyvsp[0].ExprResult); }
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 149 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = (yyvsp[-1].InstrSeq);  DeleteTable(); }
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 150 "YGrammar.y" /* yacc.c:1646  */
    {  }
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 152 "YGrammar.y" /* yacc.c:1646  */
    { NewTable(); }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 154 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = AppendSeq((yyvsp[-2].InstrSeq),(yyvsp[0].InstrSeq));}
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 155 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = AppendBreak((yyvsp[0].InstrSeq)); }
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 156 "YGrammar.y" /* yacc.c:1646  */
    {  (yyval.InstrSeq) = NULL; }
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 158 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = genStoreWord( (yyvsp[-1].Text) , (yyvsp[0].ExprResult)); }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 159 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = LocDecl((yyvsp[-2].Text),(yyvsp[0].Text),ChrBaseType); }
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 160 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = LocDecl((yyvsp[-2].Text),(yyvsp[0].Text),IntBaseType); }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 161 "YGrammar.y" /* yacc.c:1646  */
    { IncLoop(); (yyval.InstrSeq)=(yyvsp[0].InstrSeq);}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 162 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = (yyvsp[0].InstrSeq); }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 163 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = (yyvsp[0].InstrSeq); }
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 164 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = MakeWhile((yyvsp[-2].CondResult),(yyvsp[0].InstrSeq)); }
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 165 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = MakeIf((yyvsp[-4].CondResult),(yyvsp[-2].InstrSeq), IfElseType, (yyvsp[0].InstrSeq)); }
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 166 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = MakeIf((yyvsp[-2].CondResult),(yyvsp[0].InstrSeq), IfType, NULL); }
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 167 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = (yyvsp[0].InstrSeq); }
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 168 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = MakeFor((yyvsp[-6].InstrSeq),(yyvsp[-4].CondResult),(yyvsp[-2].InstrSeq),(yyvsp[0].InstrSeq)); }
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 169 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = MakeSwitch((yyvsp[-4].ExprResult),(yyvsp[-1].CondResult)); }
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 170 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = MakeSeq((yyvsp[0].ExprResult)); }
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 171 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = ReturnVal((yyvsp[0].ExprResult)); }
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 173 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = (yyvsp[0].ExprResult); }
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 175 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = MakeFuncCall((yyvsp[-1].Text), (yyvsp[0].ExprResult)); }
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 177 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = MakeCase((yyvsp[-3].ExprResult),(yyvsp[-1].InstrSeq),(yyvsp[-5].CondResult)); }
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 178 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = MakeCase(NULL,(yyvsp[-1].InstrSeq),(yyvsp[-4].CondResult)); }
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 179 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = NULL; }
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 181 "YGrammar.y" /* yacc.c:1646  */
    { DecLoop();  (yyval.InstrSeq) = MakeLoop((yyvsp[0].InstrSeq));}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 183 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = AppendSeq((yyvsp[-2].InstrSeq),(yyvsp[0].InstrSeq));}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 184 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = (yyvsp[0].InstrSeq);}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 186 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = AppendSeq((yyvsp[-2].InstrSeq),(yyvsp[0].InstrSeq));}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 187 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = (yyvsp[0].InstrSeq);}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 189 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = ConcatenateCond((yyvsp[-3].CondResult), OrType, (yyvsp[0].CondResult)); }
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 190 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = (yyvsp[0].CondResult); }
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 192 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = ConcatenateCond((yyvsp[-3].CondResult), AndType, (yyvsp[0].CondResult)); }
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 193 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = (yyvsp[0].CondResult); }
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 195 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = (yyvsp[-1].CondResult); }
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 196 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = NegateCond((yyvsp[-1].CondResult)); }
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 197 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = (yyvsp[0].CondResult); }
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 198 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.CondResult) = MakeCond((yyvsp[-2].ExprResult),(yyvsp[-1].BaseType),(yyvsp[0].ExprResult)); }
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 201 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = IncDec((yyvsp[-2].Text),PlusType);}
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 202 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = IncDec((yyvsp[-2].Text),MinusType);}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 205 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = NotEqualType; }
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 206 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = EqualType; }
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 207 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = GreaterThanType; }
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 208 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = LessThanType; }
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 209 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = GreaterThanOrEqualType; }
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 210 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = LessThanOrEqualType; }
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 212 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = PutFunc( (yyvsp[-1].Text) , ChrBaseType );}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 213 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = PutFunc( (yyvsp[-1].Text), IntBaseType );}
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 214 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = PutFunc( (yyvsp[-1].Text), StringBaseType );}
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 216 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.Text) = strdup(yytext); }
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 217 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.Text) = strdup(yytext); }
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 218 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.Text) = strdup(yytext); }
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 220 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = genStoreWord( (yyvsp[-2].Text) , (yyvsp[0].ExprResult)); }
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 221 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.InstrSeq) = GenStoreArr( (yyvsp[-5].Text) , (yyvsp[0].ExprResult), (yyvsp[-3].ExprResult)); }
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 224 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = Concatenate((yyvsp[-2].ExprResult),(yyvsp[-1].BaseType),(yyvsp[0].ExprResult)); }
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 225 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = (yyvsp[0].ExprResult); }
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 227 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = GetFunc(); }
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 229 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = Concatenate((yyvsp[-2].ExprResult),(yyvsp[-1].BaseType),(yyvsp[0].ExprResult)); }
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 230 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = (yyvsp[0].ExprResult); }
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 232 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = (yyvsp[-1].ExprResult); }
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 233 "YGrammar.y" /* yacc.c:1646  */
    {  }
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 234 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = loadExprResult( (yyvsp[0].Text) ); }
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 235 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = LoadExprArr( (yyvsp[-3].Text), (yyvsp[-1].ExprResult)); }
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 237 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = createExprResult( strdup( yytext ),
                                                                          IntBaseType); }
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 239 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.ExprResult) = (yyvsp[0].ExprResult); }
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 240 "YGrammar.y" /* yacc.c:1646  */
    {  }
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 242 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = MinusType; }
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 243 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = PlusType; }
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 245 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = TimesType; }
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 246 "YGrammar.y" /* yacc.c:1646  */
    { (yyval.BaseType) = DivideType; }
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2080 "y.tab.c" /* yacc.c:1646  */
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
#line 250 "YGrammar.y" /* yacc.c:1906  */


void
yyerror( char *s)     {
  char msg[MAXLINE];
  sprintf(msg,"ERROR \"%s\" token: \"%s\"",s,yytext);
  PostMessage(GetCurrentColumn(),strlen(yytext),msg);
}
