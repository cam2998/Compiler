/* Author: Cameron Trim
  Created: 10/20/17
  Resources:
*/

#include <stdbool.h>

#include "IOMngr.h"
#include "RDGrammar.h"
#include "RDTokens.h"

int Debug=0;

bool Prog()
// <Prog>		  :==	Ident { <StmtSeq> }
{
  if(Debug)printf("Entering Prog\n");
  ENTER;
  if (!Match(IDENT_TOK)) return LEAVE_FAIL;
  if (!Match(LBRACE_TOK)) return LEAVE_FAIL;
  if (!StmtSeq()) return LEAVE_FAIL;
  if (!Match(RBRACE_TOK)) return LEAVE_FAIL;

  return LEAVE_SUCC;
}

bool StmtSeq()
// <StmtSeq>  :==	<Stmt> ; <StmtSeq>
// <StmtSeq>	:==
{
  if(Debug)printf("Entering StmtSeq\n");
  ENTER;
  switch (CurrentToken()) {
    case INT_TOK:
    case CHR_TOK:
	  case IDENT_TOK:
      if(!Stmt())return LEAVE_FAIL;
      if(!Match(SEMI_TOK)) return LEAVE_FAIL;
      if(!StmtSeq()) return LEAVE_FAIL;
      break;
	  case RBRACE_TOK:
	    break;
	  default:
      ParseError("Something went wrong in StmtSeq");
	    return LEAVE_FAIL;
		  break;
	}

	return LEAVE_SUCC;
}

bool Stmt()
// <Stmt>    :== <Decl>
// <Stmt>    :== <Assign>
{
  if(Debug)printf("Entering Stmt\n");
  ENTER;
  switch(CurrentToken())
  {
    case INT_TOK:
    case CHR_TOK:
      if(!Decl())return LEAVE_FAIL;
      break;
    case IDENT_TOK:
      if(!Assign()) return LEAVE_FAIL;
      break;
    default:
      ParseError("Something went wrong in Stmt");
	    return LEAVE_FAIL;
  }
  return LEAVE_SUCC;
}

bool Decl()
// <Decl>    :== <Type> <IDLst>              INT CHR
{
  if(Debug)printf("Entering Decl\n");
  ENTER;
  if(!Type())return LEAVE_FAIL;
  if(!IDLst())return LEAVE_FAIL;
  return LEAVE_SUCC;
}

bool Type()
// <Type>    :== INT
// <Type>    :== CHR
{
  if(Debug)printf("Entering Type\n");
  ENTER;
  switch(CurrentToken()){
    case INT_TOK:
      if(!Match(INT_TOK))return LEAVE_FAIL;
      break;
    case CHR_TOK:
      if(!Match(CHR_TOK))return LEAVE_FAIL;
      break;
  default:
    ParseError("Something went wrong in Type");
    return LEAVE_FAIL;
  }
  return LEAVE_SUCC;
}

bool IDLst()
// <IDLst>   :== Ident <MLst>
{
  if(Debug)printf("Entering IDLst\n");
  ENTER;
  if(!Match(IDENT_TOK))return LEAVE_FAIL;
  if(!MLst())return LEAVE_FAIL;
  return LEAVE_SUCC;
}

bool MLst()
// <MLst>    :== , <IDLst>
// <MLst>    :==
{
  if(Debug)printf("Entering MLst\n");
  ENTER;
  switch( CurrentToken() )
  {
      case COMMA_TOK:
        if(!Match(COMMA_TOK))return LEAVE_FAIL;
        if(!IDLst())return LEAVE_FAIL;
        break;
      case SEMI_TOK:
          break;
      default:
          ParseError( "something went wrong in MLst" );
          return LEAVE_FAIL;
  }
  return LEAVE_SUCC;
}

bool Assign()
// <Assign>		:==	Ident := <Expr>
{
    ENTER;
    if( !Match( IDENT_TOK ) ) return LEAVE_FAIL;
    if( !Match( ASSIGN_TOK ) ) return LEAVE_FAIL;
    if( !Expr() ) return LEAVE_FAIL;
    return LEAVE_SUCC;
}

bool Expr()
// <Expr>		:==	<Term> <MExpr>
{
  if(Debug)printf("Entering Expr\n");
    ENTER;
    if( !Term() ) return LEAVE_FAIL;
    if( !MExpr() ) return LEAVE_FAIL;
    return LEAVE_SUCC;
}

bool MExpr()
// <MExpr>		:==	<AddOp> <Term> <MExpr>
// <MExpr>		:==
{
  if(Debug)printf("Entering MExpr\n");
    ENTER;
    switch( CurrentToken() )
    {
        case MINUS_TOK:
        case PLUS_TOK:
            if( !AddOp() ) return LEAVE_FAIL;
            if( !Term() ) return LEAVE_FAIL;
            if( !MExpr() ) return LEAVE_FAIL;
            break;
        case SEMI_TOK:
          break;
        case RPAREN_TOK:
          break;
        default:
            ParseError( "Something went wrong in MExpr" );
            return LEAVE_FAIL;
    }
    return LEAVE_SUCC;
}

bool Term()
//<Term>		:==	<Factor> <MTerm>
{
  if(Debug)printf("Entering Term\n");
  ENTER;
  if( !Factor() ) return LEAVE_FAIL;
  if( !MTerm() ) return LEAVE_FAIL;
  return LEAVE_SUCC;
}

bool MTerm()
//<MTerm>		:==	<MultOp> <Factor> <MTerm>
//<MTerm>		:==
{
  if(Debug)printf("Entering MTerm\n");
  ENTER;
  switch( CurrentToken() )
  {
      case TIMES_TOK:
          if( !MultOp() ) return LEAVE_FAIL;
          if( !Factor() ) return LEAVE_FAIL;
          if( !MTerm() ) return LEAVE_FAIL;
          break;

      case DIV_TOK:
          if( !MultOp() ) return LEAVE_FAIL;
          if( !Factor() ) return LEAVE_FAIL;
          if( !MTerm() ) return LEAVE_FAIL;
          break;

      case MINUS_TOK:
      case PLUS_TOK:
      case SEMI_TOK:
      case RPAREN_TOK:
        break;
        default:
          ParseError( "Something went wrong in MTerm" );
          return LEAVE_FAIL;
  }
  return LEAVE_SUCC;
}

bool Factor()
// <Factor>	:==	( <Expr> )
// <Factor>	:==	- <Factor>
// <Factor>	:==	<IntLit>
// <Factor>	:==	<RealLit>
// <Factor>	:==	<Ident>
{
  if(Debug)printf("Entering Factor\n");
  ENTER;
  switch( CurrentToken() )
  {
      case LPAREN_TOK:
          if( !Match( LPAREN_TOK ) ) return LEAVE_FAIL;
          if( !Expr() ) return LEAVE_FAIL;
          if( !Match( RPAREN_TOK ) ) return LEAVE_FAIL;
          break;

      case MINUS_TOK:
          if( !Match( MINUS_TOK ) ) return LEAVE_FAIL;
          if( !Factor() ) return LEAVE_FAIL;
          break;

      case INTLIT_TOK:
          if( !Match( INTLIT_TOK ) ) return LEAVE_FAIL;
          break;

      case REALLIT_TOK:
          if( !Match( REALLIT_TOK ) ) return LEAVE_FAIL;
          break;

      case IDENT_TOK:
          if( !Match( IDENT_TOK ) ) return LEAVE_FAIL;
          break;

      default:
          ParseError( "Something went wrong in Factor" );
          return LEAVE_FAIL;
  }
  return LEAVE_SUCC;
}

//done
bool AddOp()
// <AddOp>		:==	-
// <AddOp>		:==	+
{
  if(Debug)printf("Entering AddOp\n");
  ENTER;
  switch ( CurrentToken() )
  {
    case MINUS_TOK:
      if(!Match( MINUS_TOK ))return LEAVE_FAIL;
      break;
    case PLUS_TOK:
      if(!Match( PLUS_TOK )) return LEAVE_FAIL;
      break;
    default:
      ParseError( "Something went wrong in AddOp" );
      return LEAVE_FAIL;
  }
  return LEAVE_SUCC;
}

//done
bool MultOp()
// <MultOp>	:==	*
// <MultOp>	:==	/
{
  if(Debug)printf("Entering MultOp\n");
  ENTER;
  switch( CurrentToken() )
  {
    case TIMES_TOK:
      if(!Match( TIMES_TOK ))return LEAVE_FAIL;
      break;
    case DIV_TOK:
      if(!Match( DIV_TOK )) return LEAVE_FAIL;
      break;
    default:
      ParseError( "Something went wrong in MultiOp" );
      return LEAVE_FAIL;
  }
  return LEAVE_SUCC;
}
