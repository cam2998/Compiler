/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 12 "YGrammar.y" /* yacc.c:1909  */

  int Integer;
  char * Text;
  struct IdList * IdList;
  enum BaseTypes BaseType;
  struct InstrSeq * InstrSeq;
  struct ExprResult * ExprResult;
  struct CondResult * CondResult;

#line 136 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
