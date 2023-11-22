// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 21 "src/parser.yy"

    
    #include "LocThing.hh"
    #include "defs.hh"
    Node* root;

    lineStruct to_linestruct(yy::location loc) {
    return lineStruct {
        loc.begin.line,
        loc.begin.column,
        loc.end.line,
        loc.end.column
    };  
}


#line 63 "src/parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 155 "src/parser.tab.cc"

  /// Build a parser object.
  parser::parser (LocThing& locThing_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      locThing (locThing_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_Goal: // Goal
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_ClassDeclarations: // ClassDeclarations
      case symbol_kind::S_ClassBody: // ClassBody
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_FunctionBody: // FunctionBody
      case symbol_kind::S_VarDeclarations: // VarDeclarations
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_MethodDeclarations: // MethodDeclarations
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_Param_decl: // Param_decl
      case symbol_kind::S_Params_decl: // Params_decl
      case symbol_kind::S_Param_decl_NotEmpty: // Param_decl_NotEmpty
      case symbol_kind::S_Param: // Param
      case symbol_kind::S_Params: // Params
      case symbol_kind::S_Params_NotEmpty: // Params_NotEmpty
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_Statements: // Statements
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_Expression_OP: // Expression_OP
      case symbol_kind::S_Operator_level0: // Operator_level0
      case symbol_kind::S_Operator_level1: // Operator_level1
      case symbol_kind::S_Operator_level2: // Operator_level2
      case symbol_kind::S_Operator_level3: // Operator_level3
      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Identifier: // Identifier
        value.YY_MOVE_OR_COPY< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_EXCLAIMATION: // EXCLAIMATION
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_EQUEQU: // EQUEQU
      case symbol_kind::S_MORE_T: // MORE_T
      case symbol_kind::S_LESS_T: // LESS_T
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_EQU: // EQU
      case symbol_kind::S_ADDADD: // ADDADD
      case symbol_kind::S_SUBSUB: // SUBSUB
      case symbol_kind::S_ADD: // ADD
      case symbol_kind::S_SUB: // SUB
      case symbol_kind::S_MULT: // MULT
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_SYSTEM_O_PRINT: // SYSTEM_O_PRINT
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_EXTENDS: // EXTENDS
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_TYPE_INT: // TYPE_INT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_NUMBERS: // NUMBERS
      case symbol_kind::S_C_B: // C_B
      case symbol_kind::S_O_B: // O_B
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_C_M: // C_M
      case symbol_kind::S_O_M: // O_M
      case symbol_kind::S_O_P: // O_P
      case symbol_kind::S_C_P: // C_P
      case symbol_kind::S_DOT: // DOT
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_Goal: // Goal
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_ClassDeclarations: // ClassDeclarations
      case symbol_kind::S_ClassBody: // ClassBody
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_FunctionBody: // FunctionBody
      case symbol_kind::S_VarDeclarations: // VarDeclarations
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_MethodDeclarations: // MethodDeclarations
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_Param_decl: // Param_decl
      case symbol_kind::S_Params_decl: // Params_decl
      case symbol_kind::S_Param_decl_NotEmpty: // Param_decl_NotEmpty
      case symbol_kind::S_Param: // Param
      case symbol_kind::S_Params: // Params
      case symbol_kind::S_Params_NotEmpty: // Params_NotEmpty
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_Statements: // Statements
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_Expression_OP: // Expression_OP
      case symbol_kind::S_Operator_level0: // Operator_level0
      case symbol_kind::S_Operator_level1: // Operator_level1
      case symbol_kind::S_Operator_level2: // Operator_level2
      case symbol_kind::S_Operator_level3: // Operator_level3
      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Identifier: // Identifier
        value.move< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_EXCLAIMATION: // EXCLAIMATION
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_EQUEQU: // EQUEQU
      case symbol_kind::S_MORE_T: // MORE_T
      case symbol_kind::S_LESS_T: // LESS_T
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_EQU: // EQU
      case symbol_kind::S_ADDADD: // ADDADD
      case symbol_kind::S_SUBSUB: // SUBSUB
      case symbol_kind::S_ADD: // ADD
      case symbol_kind::S_SUB: // SUB
      case symbol_kind::S_MULT: // MULT
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_SYSTEM_O_PRINT: // SYSTEM_O_PRINT
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_EXTENDS: // EXTENDS
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_TYPE_INT: // TYPE_INT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_NUMBERS: // NUMBERS
      case symbol_kind::S_C_B: // C_B
      case symbol_kind::S_O_B: // O_B
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_C_M: // C_M
      case symbol_kind::S_O_M: // O_M
      case symbol_kind::S_O_P: // O_P
      case symbol_kind::S_C_P: // C_P
      case symbol_kind::S_DOT: // DOT
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_Goal: // Goal
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_ClassDeclarations: // ClassDeclarations
      case symbol_kind::S_ClassBody: // ClassBody
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_FunctionBody: // FunctionBody
      case symbol_kind::S_VarDeclarations: // VarDeclarations
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_MethodDeclarations: // MethodDeclarations
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_Param_decl: // Param_decl
      case symbol_kind::S_Params_decl: // Params_decl
      case symbol_kind::S_Param_decl_NotEmpty: // Param_decl_NotEmpty
      case symbol_kind::S_Param: // Param
      case symbol_kind::S_Params: // Params
      case symbol_kind::S_Params_NotEmpty: // Params_NotEmpty
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_Statements: // Statements
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_Expression_OP: // Expression_OP
      case symbol_kind::S_Operator_level0: // Operator_level0
      case symbol_kind::S_Operator_level1: // Operator_level1
      case symbol_kind::S_Operator_level2: // Operator_level2
      case symbol_kind::S_Operator_level3: // Operator_level3
      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Identifier: // Identifier
        value.copy< Node * > (that.value);
        break;

      case symbol_kind::S_EXCLAIMATION: // EXCLAIMATION
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_EQUEQU: // EQUEQU
      case symbol_kind::S_MORE_T: // MORE_T
      case symbol_kind::S_LESS_T: // LESS_T
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_EQU: // EQU
      case symbol_kind::S_ADDADD: // ADDADD
      case symbol_kind::S_SUBSUB: // SUBSUB
      case symbol_kind::S_ADD: // ADD
      case symbol_kind::S_SUB: // SUB
      case symbol_kind::S_MULT: // MULT
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_SYSTEM_O_PRINT: // SYSTEM_O_PRINT
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_EXTENDS: // EXTENDS
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_TYPE_INT: // TYPE_INT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_NUMBERS: // NUMBERS
      case symbol_kind::S_C_B: // C_B
      case symbol_kind::S_O_B: // O_B
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_C_M: // C_M
      case symbol_kind::S_O_M: // O_M
      case symbol_kind::S_O_P: // O_P
      case symbol_kind::S_C_P: // C_P
      case symbol_kind::S_DOT: // DOT
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_Goal: // Goal
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_ClassDeclarations: // ClassDeclarations
      case symbol_kind::S_ClassBody: // ClassBody
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_FunctionBody: // FunctionBody
      case symbol_kind::S_VarDeclarations: // VarDeclarations
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_MethodDeclarations: // MethodDeclarations
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_Param_decl: // Param_decl
      case symbol_kind::S_Params_decl: // Params_decl
      case symbol_kind::S_Param_decl_NotEmpty: // Param_decl_NotEmpty
      case symbol_kind::S_Param: // Param
      case symbol_kind::S_Params: // Params
      case symbol_kind::S_Params_NotEmpty: // Params_NotEmpty
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_Statements: // Statements
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_Expression_OP: // Expression_OP
      case symbol_kind::S_Operator_level0: // Operator_level0
      case symbol_kind::S_Operator_level1: // Operator_level1
      case symbol_kind::S_Operator_level2: // Operator_level2
      case symbol_kind::S_Operator_level3: // Operator_level3
      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Identifier: // Identifier
        value.move< Node * > (that.value);
        break;

      case symbol_kind::S_EXCLAIMATION: // EXCLAIMATION
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_EQUEQU: // EQUEQU
      case symbol_kind::S_MORE_T: // MORE_T
      case symbol_kind::S_LESS_T: // LESS_T
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_EQU: // EQU
      case symbol_kind::S_ADDADD: // ADDADD
      case symbol_kind::S_SUBSUB: // SUBSUB
      case symbol_kind::S_ADD: // ADD
      case symbol_kind::S_SUB: // SUB
      case symbol_kind::S_MULT: // MULT
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_SYSTEM_O_PRINT: // SYSTEM_O_PRINT
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_EXTENDS: // EXTENDS
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_TYPE_INT: // TYPE_INT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_NUMBERS: // NUMBERS
      case symbol_kind::S_C_B: // C_B
      case symbol_kind::S_O_B: // O_B
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_C_M: // C_M
      case symbol_kind::S_O_M: // O_M
      case symbol_kind::S_O_P: // O_P
      case symbol_kind::S_C_P: // C_P
      case symbol_kind::S_DOT: // DOT
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (locThing));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_Goal: // Goal
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_ClassDeclarations: // ClassDeclarations
      case symbol_kind::S_ClassBody: // ClassBody
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_FunctionBody: // FunctionBody
      case symbol_kind::S_VarDeclarations: // VarDeclarations
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_MethodDeclarations: // MethodDeclarations
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_Param_decl: // Param_decl
      case symbol_kind::S_Params_decl: // Params_decl
      case symbol_kind::S_Param_decl_NotEmpty: // Param_decl_NotEmpty
      case symbol_kind::S_Param: // Param
      case symbol_kind::S_Params: // Params
      case symbol_kind::S_Params_NotEmpty: // Params_NotEmpty
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_Statements: // Statements
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_Expression_OP: // Expression_OP
      case symbol_kind::S_Operator_level0: // Operator_level0
      case symbol_kind::S_Operator_level1: // Operator_level1
      case symbol_kind::S_Operator_level2: // Operator_level2
      case symbol_kind::S_Operator_level3: // Operator_level3
      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Identifier: // Identifier
        yylhs.value.emplace< Node * > ();
        break;

      case symbol_kind::S_EXCLAIMATION: // EXCLAIMATION
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_EQUEQU: // EQUEQU
      case symbol_kind::S_MORE_T: // MORE_T
      case symbol_kind::S_LESS_T: // LESS_T
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_EQU: // EQU
      case symbol_kind::S_ADDADD: // ADDADD
      case symbol_kind::S_SUBSUB: // SUBSUB
      case symbol_kind::S_ADD: // ADD
      case symbol_kind::S_SUB: // SUB
      case symbol_kind::S_MULT: // MULT
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_SYSTEM_O_PRINT: // SYSTEM_O_PRINT
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_EXTENDS: // EXTENDS
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_TYPE_INT: // TYPE_INT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_NUMBERS: // NUMBERS
      case symbol_kind::S_C_B: // C_B
      case symbol_kind::S_O_B: // O_B
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_C_M: // C_M
      case symbol_kind::S_O_M: // O_M
      case symbol_kind::S_O_P: // O_P
      case symbol_kind::S_C_P: // C_P
      case symbol_kind::S_DOT: // DOT
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // Goal: MainClass ClassDeclarations "end of file"
#line 78 "src/parser.yy"
                                {
                            if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("Goal\n");}                            
                            yylhs.value.as < Node * > () = new Node(TYPE_GOAL, "", to_linestruct(yylhs.location));
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            root = yylhs.value.as < Node * > ();
                            if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("r1 ");}
                            
                            }
#line 932 "src/parser.tab.cc"
    break;

  case 3: // Goal: MainClass "end of file"
#line 87 "src/parser.yy"
               {
                            if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("Goal\n");}
                            
                            yylhs.value.as < Node * > () = new Node(TYPE_GOAL, "", to_linestruct(yylhs.location));
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            root = yylhs.value.as < Node * > ();
                            if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("r1 ");}                            
                            }
#line 945 "src/parser.tab.cc"
    break;

  case 4: // MainClass: CLASS Identifier O_M PUBLIC STATIC VOID MAIN O_P STRING O_B C_B Identifier C_P O_M Statement C_M C_M
#line 98 "src/parser.yy"
                                                                                                     {
                            
                            if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("made a main class\n");}
                            yylhs.value.as < Node * > () = new Node(TYPE_MAIN_CLASS, "", to_linestruct(yylhs.location));
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[15].value.as < Node * > ());
                            Node* classBody = new Node(TYPE_CLASSBODY, "", to_linestruct(yylhs.location));
                            Node* methods = new Node(TYPE_METHOD_DECLS, "", to_linestruct(yylhs.location));
                            Node* method = new Node(TYPE_METHOD_DECL, "", to_linestruct(yylhs.location));
                            Node* methodBody = new Node(TYPE_FUNCTIONBODY, "", to_linestruct(yylhs.location));
                            Node* vars = new Node(TYPE_VAR_DECLS, "", to_linestruct(yylhs.location));
                            Node* paramType = new Node(TYPE_DATATYPE, "STRING[]", to_linestruct(yylhs.location));
                            Node* mvars = new Node(TYPE_VAR_DECLS, "", to_linestruct(yylhs.location));
                            Node* methodType = new Node(TYPE_DATATYPE, yystack_[11].value.as < std::string > (), to_linestruct(yylhs.location));
                            Node* methodID  = new Node(TYPE_IDENTIFIER, yystack_[10].value.as < std::string > (), to_linestruct(yylhs.location));
                            Node* methodParamDecls  = new Node(TYPE_PARAM_DECLS, "", to_linestruct(yylhs.location));
                            Node* methodParamDecl  = new Node(TYPE_PARAM_DECL, "", to_linestruct(yylhs.location));
                            Node* methodStatement  = new Node(TYPE_STATEMENTS, "", to_linestruct(yylhs.location));
                            Node* returnVoid = new Node(TYPE_VOID, TYPE_VOID, to_linestruct(yylhs.location));
                            //method->children.push_back(Statement);
                            Node* emptyReturn = new Node(TYPE_RETURN, "", to_linestruct(yylhs.location));

                            method->children.push_back(methodType);
                            method->children.push_back(methodID);
                            method->children.push_back(methodParamDecls);
                            methodParamDecls->children.push_back(methodParamDecl);
                            methodParamDecl->children.push_back(paramType);
                            methodParamDecl->children.push_back(yystack_[5].value.as < Node * > ());

                            emptyReturn->children.push_back(returnVoid);

                            methodBody->children.push_back(vars);
                            methodStatement->children.push_back(yystack_[2].value.as < Node * > ());
                            methodBody->children.push_back(methodStatement);
                            methodBody->children.push_back(emptyReturn);
                            method->children.push_back(methodBody);
                            methods->children.push_back(method);
                            classBody->children.push_back(mvars);
                            classBody->children.push_back(methods);

                            yylhs.value.as < Node * > ()->children.push_back(classBody);

                            }
#line 992 "src/parser.tab.cc"
    break;

  case 5: // MainClass: CLASS Identifier O_M PUBLIC STATIC VOID MAIN O_P STRING O_B C_B Identifier C_P O_M C_M C_M
#line 140 "src/parser.yy"
                                                                                             {
                            if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("made a main class\n");}
                            
                            yylhs.value.as < Node * > () = new Node(TYPE_MAIN_CLASS, "", to_linestruct(yylhs.location));
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[14].value.as < Node * > ());                            
                            //$$->children.push_back($12);
                            Node* classBody = new Node(TYPE_CLASSBODY, "", to_linestruct(yylhs.location));
                            Node* methods = new Node(TYPE_METHOD_DECLS, "", to_linestruct(yylhs.location));
                            Node* method = new Node(TYPE_METHOD_DECL, "", to_linestruct(yylhs.location));
                            Node* methodBody = new Node(TYPE_FUNCTIONBODY, "", to_linestruct(yylhs.location));
                            Node* emptyReturn = new Node(TYPE_RETURN, "", to_linestruct(yylhs.location));
                            Node* returnVoid = new Node(TYPE_VOID, TYPE_VOID, to_linestruct(yylhs.location));
                            Node* vars = new Node(TYPE_VAR_DECLS, "", to_linestruct(yylhs.location));
                            Node* paramType = new Node(TYPE_DATATYPE, "STRING[]", to_linestruct(yylhs.location));
                            Node* mvars = new Node(TYPE_VAR_DECLS, "", to_linestruct(yylhs.location));
                            Node* methodType = new Node(TYPE_DATATYPE, yystack_[10].value.as < std::string > (), to_linestruct(yylhs.location));
                            Node* methodID  = new Node(TYPE_IDENTIFIER, yystack_[9].value.as < std::string > (), to_linestruct(yylhs.location));
                            Node* methodParamDecls  = new Node(TYPE_PARAM_DECLS, "", to_linestruct(yylhs.location));
                            Node* methodParamDecl  = new Node(TYPE_PARAM_DECL, "", to_linestruct(yylhs.location));
                            Node* methodStatement  = new Node(TYPE_STATEMENTS, "", to_linestruct(yylhs.location));

                            method->children.push_back(methodType);
                            method->children.push_back(methodID);
                            method->children.push_back(methodParamDecls);
                            methodParamDecls->children.push_back(methodParamDecl);
                            methodParamDecl->children.push_back(paramType);
                            methodParamDecl->children.push_back(yystack_[4].value.as < Node * > ());
    
                            methodBody->children.push_back(vars);
                            methodBody->children.push_back(methodStatement);
                            emptyReturn->children.push_back(returnVoid);
                            methodBody->children.push_back(emptyReturn);
                            

                            method->children.push_back(methodBody);
                            methods->children.push_back(method);
                            classBody->children.push_back(mvars);
                            classBody->children.push_back(methods);

                            yylhs.value.as < Node * > ()->children.push_back(classBody);
                            }
#line 1038 "src/parser.tab.cc"
    break;

  case 6: // ClassDeclarations: ClassDeclaration
#line 184 "src/parser.yy"
                 {yylhs.value.as < Node * > () = new Node(TYPE_CLASS_DECLS, "", to_linestruct(yylhs.location)); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("class decs\n");}}
#line 1044 "src/parser.tab.cc"
    break;

  case 7: // ClassDeclarations: ClassDeclarations ClassDeclaration
#line 186 "src/parser.yy"
                            {
                            
                            yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                          }
#line 1054 "src/parser.tab.cc"
    break;

  case 8: // ClassBody: VarDeclarations MethodDeclarations
#line 194 "src/parser.yy"
                                   {
                            yylhs.value.as < Node * > () = new Node(TYPE_CLASSBODY, "", to_linestruct(yylhs.location));
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            }
#line 1064 "src/parser.tab.cc"
    break;

  case 9: // ClassBody: MethodDeclarations
#line 199 "src/parser.yy"
                    {yylhs.value.as < Node * > () = new Node(TYPE_CLASSBODY, "", to_linestruct(yylhs.location));
                    yylhs.value.as < Node * > ()->children.push_back(new Node(TYPE_VAR_DECLS,"", to_linestruct(yylhs.location)));
                    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            }
#line 1073 "src/parser.tab.cc"
    break;

  case 10: // ClassDeclaration: CLASS Identifier EXTENDS Identifier O_M ClassBody C_M
#line 206 "src/parser.yy"
                                                      {
                            if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("class dec extends\n");    }
                  
                            yylhs.value.as < Node * > () = new Node(TYPE_CLASS_DECL_EXT, "", to_linestruct(yylhs.location));
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            }
#line 1086 "src/parser.tab.cc"
    break;

  case 11: // ClassDeclaration: CLASS Identifier O_M ClassBody C_M
#line 214 "src/parser.yy"
                                    {
                            if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("a class\n");      }
                            
                         
                            // auto ss = to_linestruct(@$);
                            // std::cout << "ss: " <<  ss.start_line << std::endl;                           
                            // std::cout << "ss: " <<  ss.start_column << std::endl;                           
                            // std::cout << "ss: " <<  ss.end_line << std::endl;                           
                            // std::cout << "ss: " <<  ss.end_column << std::endl;                           
                            
                            yylhs.value.as < Node * > () = new Node(TYPE_CLASS_DEC, "", to_linestruct(yylhs.location));
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());                            
                            
}
#line 1106 "src/parser.tab.cc"
    break;

  case 12: // FunctionBody: RETURN Expression_OP SEMICOLON
#line 231 "src/parser.yy"
                                             {

    yylhs.value.as < Node * > () = new Node(TYPE_EMPTY_FUNCTIONBODY, "", to_linestruct(yylhs.location));
    Node* NodePtr = new Node(TYPE_RETURN, "", to_linestruct(yylhs.location));
    NodePtr->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(new Node(TYPE_VAR_DECLS,"", to_linestruct(yylhs.location)));
    yylhs.value.as < Node * > ()->children.push_back(NodePtr);}
#line 1118 "src/parser.tab.cc"
    break;

  case 13: // FunctionBody: VarDeclarations RETURN Expression_OP SEMICOLON
#line 238 "src/parser.yy"
                                               {
    yylhs.value.as < Node * > () = new Node(TYPE_FUNCTIONBODY, "", to_linestruct(yylhs.location));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
    Node* NodePtr = new Node(TYPE_RETURN, "", to_linestruct(yylhs.location));
    NodePtr->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(NodePtr);
}
#line 1130 "src/parser.tab.cc"
    break;

  case 14: // FunctionBody: Statements RETURN Expression_OP SEMICOLON
#line 245 "src/parser.yy"
                                           {
    yylhs.value.as < Node * > () = new Node(TYPE_FUNCTIONBODY, "", to_linestruct(yylhs.location));
    yylhs.value.as < Node * > ()->children.push_back(new Node(TYPE_VAR_DECLS,"", to_linestruct(yylhs.location)));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
    Node* NodePtr = new Node(TYPE_RETURN, "", to_linestruct(yylhs.location));
    NodePtr->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(NodePtr);
}
#line 1143 "src/parser.tab.cc"
    break;

  case 15: // FunctionBody: VarDeclarations Statements RETURN Expression_OP SEMICOLON
#line 253 "src/parser.yy"
                                                          {
    yylhs.value.as < Node * > () = new Node(TYPE_FUNCTIONBODY, "", to_linestruct(yylhs.location));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
    Node* NodePtr = new Node(TYPE_RETURN, "", to_linestruct(yylhs.location));
    NodePtr->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(NodePtr);
}
#line 1156 "src/parser.tab.cc"
    break;

  case 16: // VarDeclarations: VarDeclaration
#line 265 "src/parser.yy"
               {yylhs.value.as < Node * > () = new Node(TYPE_VAR_DECLS, "", to_linestruct(yylhs.location)); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("var decs\n");}}
#line 1162 "src/parser.tab.cc"
    break;

  case 17: // VarDeclarations: VarDeclarations VarDeclaration
#line 267 "src/parser.yy"
{
                          yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1170 "src/parser.tab.cc"
    break;

  case 18: // VarDeclaration: Type Identifier SEMICOLON
#line 272 "src/parser.yy"
                          {

    yylhs.value.as < Node * > () = new Node(TYPE_VAR_DECL, "", to_linestruct(yylhs.location));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("Type Identifier SEMICOLON\n");}    
}
#line 1182 "src/parser.tab.cc"
    break;

  case 19: // MethodDeclarations: %empty
#line 281 "src/parser.yy"
                           {yylhs.value.as < Node * > () = new Node(TYPE_METHOD_DECLS,"", to_linestruct(yylhs.location));}
#line 1188 "src/parser.tab.cc"
    break;

  case 20: // MethodDeclarations: MethodDeclarations MethodDeclaration
#line 282 "src/parser.yy"
                                     {

                        if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("method decs2\n");}                        
                        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();                          
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1199 "src/parser.tab.cc"
    break;

  case 21: // MethodDeclaration: PUBLIC Type Identifier O_P Params_decl C_P O_M FunctionBody C_M
#line 291 "src/parser.yy"
{

    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("method dec\n");}
    
    yylhs.value.as < Node * > () = new Node(TYPE_METHOD_DECL, "", to_linestruct( yylhs.location));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[7].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
    
    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
    
    
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
}
#line 1217 "src/parser.tab.cc"
    break;

  case 22: // Param_decl: Type Identifier
#line 308 "src/parser.yy"
{ 
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("type identifier\n");}
    
    yylhs.value.as < Node * > () = new Node(TYPE_PARAM_DECL, "",  to_linestruct(yylhs.location));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1229 "src/parser.tab.cc"
    break;

  case 23: // Params_decl: %empty
#line 318 "src/parser.yy"
{
    yylhs.value.as < Node * > () = new Node(TYPE_PARAM_DECLS, "", to_linestruct(yylhs.location)); if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("empty param decl\n");}
}
#line 1237 "src/parser.tab.cc"
    break;

  case 24: // Params_decl: Param_decl
#line 322 "src/parser.yy"
{    
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("Param_decls\n"); }
    
    yylhs.value.as < Node * > () = new Node(TYPE_PARAM_DECLS, "", to_linestruct(yylhs.location));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1248 "src/parser.tab.cc"
    break;

  case 25: // Params_decl: Param_decl_NotEmpty COMMA Param_decl
#line 329 "src/parser.yy"
{    
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("Param_decls\n");}    
    yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > (); //new Node("param", "", to_linestruct(@$));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1258 "src/parser.tab.cc"
    break;

  case 26: // Param_decl_NotEmpty: Param_decl
#line 338 "src/parser.yy"
{
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("Param_decls\n");}
    
    yylhs.value.as < Node * > () = new Node(TYPE_PARAM_DECLS, "", to_linestruct(yylhs.location));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1269 "src/parser.tab.cc"
    break;

  case 27: // Param_decl_NotEmpty: Param_decl_NotEmpty COMMA Param_decl
#line 345 "src/parser.yy"
{    
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("Param_decls\n");}
    
    yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > (); //new Node("param", "", to_linestruct(@$));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1280 "src/parser.tab.cc"
    break;

  case 28: // Param: Expression_OP
#line 359 "src/parser.yy"
              {
    
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("param\n");}
    
    //$$ = new Node("Param(expression)", "", to_linestruct(@$));
    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
    
    //$$->children.push_back($1);
    }
#line 1294 "src/parser.tab.cc"
    break;

  case 29: // Params: %empty
#line 371 "src/parser.yy"
{
    yylhs.value.as < Node * > () = new Node(TYPE_EMPTY_PARAMS, "", to_linestruct(yylhs.location)); if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("empty param\n");}
}
#line 1302 "src/parser.tab.cc"
    break;

  case 30: // Params: Param
#line 375 "src/parser.yy"
{    
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("Params\n"); }
    
    yylhs.value.as < Node * > () = new Node(TYPE_PARAMS, "", to_linestruct(yylhs.location)); 
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1313 "src/parser.tab.cc"
    break;

  case 31: // Params: Params_NotEmpty COMMA Param
#line 382 "src/parser.yy"
{
    
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("Params\n");}
    
    yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > (); //new Node("param", "", to_linestruct(@$));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1325 "src/parser.tab.cc"
    break;

  case 32: // Params_NotEmpty: Param
#line 393 "src/parser.yy"
{    
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("Params\n"); }
    
    yylhs.value.as < Node * > () = new Node(TYPE_PARAMS, "", to_linestruct(yylhs.location)); 
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1336 "src/parser.tab.cc"
    break;

  case 33: // Params_NotEmpty: Params_NotEmpty COMMA Param
#line 400 "src/parser.yy"
{    
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("Params\n");}
    
    yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > (); //new Node("param", "", to_linestruct(@$));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1347 "src/parser.tab.cc"
    break;

  case 34: // Type: TYPE_INT O_B C_B
#line 409 "src/parser.yy"
                 {yylhs.value.as < Node * > () = new Node(TYPE_DATATYPE, TYPE_INT_ARR, to_linestruct(yylhs.location));}
#line 1353 "src/parser.tab.cc"
    break;

  case 35: // Type: BOOLEAN
#line 410 "src/parser.yy"
            {yylhs.value.as < Node * > () = new Node(TYPE_DATATYPE, yystack_[0].value.as < std::string > (), to_linestruct(yylhs.location));}
#line 1359 "src/parser.tab.cc"
    break;

  case 36: // Type: TYPE_INT
#line 411 "src/parser.yy"
                 {yylhs.value.as < Node * > () = new Node(TYPE_DATATYPE, yystack_[0].value.as < std::string > (), to_linestruct(yylhs.location));}
#line 1365 "src/parser.tab.cc"
    break;

  case 37: // Type: STRING
#line 412 "src/parser.yy"
            {yylhs.value.as < Node * > () = new Node(TYPE_DATATYPE, yystack_[0].value.as < std::string > (), to_linestruct(yylhs.location));}
#line 1371 "src/parser.tab.cc"
    break;

  case 38: // Type: Identifier
#line 413 "src/parser.yy"
 { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1377 "src/parser.tab.cc"
    break;

  case 39: // Statements: Statement
#line 417 "src/parser.yy"
          {
    yylhs.value.as < Node * > () = new Node(TYPE_STATEMENTS, "", to_linestruct(yylhs.location));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1386 "src/parser.tab.cc"
    break;

  case 40: // Statements: Statements Statement
#line 422 "src/parser.yy"
{
    yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1395 "src/parser.tab.cc"
    break;

  case 41: // Statement: O_M Statements C_M
#line 430 "src/parser.yy"
{
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("(Statement)\n"); }    
    
    yylhs.value.as < Node * > () = new Node(TYPE_OM_STATEMENT_CM, "", to_linestruct(yylhs.location));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
}
#line 1406 "src/parser.tab.cc"
    break;

  case 42: // Statement: O_M C_M
#line 437 "src/parser.yy"
{    
    yylhs.value.as < Node * > () = new Node(TYPE_STATEMENTS,"empty");
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("()\n"); }       
}
#line 1415 "src/parser.tab.cc"
    break;

  case 43: // Statement: SYSTEM_O_PRINT O_P Expression_OP C_P SEMICOLON
#line 442 "src/parser.yy"
{
  yylhs.value.as < Node * > () = new Node(TYPE_SYSTEM_PRINT, "", to_linestruct(yylhs.location));
  yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  }
#line 1424 "src/parser.tab.cc"
    break;

  case 44: // Statement: IF O_P Expression_OP C_P Statement ELSE Statement
#line 447 "src/parser.yy"
{
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("IF ELSE state\n");}        
    
    yylhs.value.as < Node * > () = new Node(TYPE_IF_ELSE, "", to_linestruct(yylhs.location));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1437 "src/parser.tab.cc"
    break;

  case 45: // Statement: WHILE O_P Expression_OP C_P Statement
#line 456 "src/parser.yy"
{
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("WHILE statement\n");}        
    
    yylhs.value.as < Node * > () = new Node(TYPE_WHILE, "", to_linestruct(yylhs.location));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1449 "src/parser.tab.cc"
    break;

  case 46: // Statement: Identifier EQU Expression_OP SEMICOLON
#line 465 "src/parser.yy"
{
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("id = expression\n");}    
    
    
    yylhs.value.as < Node * > () = new Node(TYPE_IDENTIFIER_EQU_EXPRESSION, "", to_linestruct(yylhs.location));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
}
#line 1462 "src/parser.tab.cc"
    break;

  case 47: // Statement: Identifier O_B Expression_OP C_B EQU Expression_OP SEMICOLON
#line 474 "src/parser.yy"
{    
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("id \n");}    
    
    yylhs.value.as < Node * > () = new Node(TYPE_IDENTIFIER_OB_EXPRESSION_CB_EQU_EXPRESSION, "", to_linestruct(yylhs.location));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
}
#line 1475 "src/parser.tab.cc"
    break;

  case 48: // Expression_OP: Operator_level0
#line 486 "src/parser.yy"
{ yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1481 "src/parser.tab.cc"
    break;

  case 49: // Expression_OP: Expression_OP OR Operator_level0
#line 488 "src/parser.yy"
{
    yylhs.value.as < Node * > () = new Node(TYPE_OPERATOR, yystack_[1].value.as < std::string > (), to_linestruct(yylhs.location));if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("AND TYPE_OPERATOR ... \n");}    
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1491 "src/parser.tab.cc"
    break;

  case 50: // Operator_level0: Operator_level1
#line 495 "src/parser.yy"
{ yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1497 "src/parser.tab.cc"
    break;

  case 51: // Operator_level0: Operator_level0 AND Operator_level1
#line 497 "src/parser.yy"
{
    yylhs.value.as < Node * > () = new Node(TYPE_OPERATOR, yystack_[1].value.as < std::string > (), to_linestruct(yylhs.location));if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("AND TYPE_OPERATOR ... \n");}    
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1507 "src/parser.tab.cc"
    break;

  case 52: // Operator_level1: Operator_level2
#line 507 "src/parser.yy"
{ yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1513 "src/parser.tab.cc"
    break;

  case 53: // Operator_level1: Operator_level1 LESS_T Operator_level2
#line 509 "src/parser.yy"
{
    yylhs.value.as < Node * > () = new Node(TYPE_OPERATOR, yystack_[1].value.as < std::string > (), to_linestruct(yylhs.location));if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("LESS_T TYPE_OPERATOR ... \n");}    
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1523 "src/parser.tab.cc"
    break;

  case 54: // Operator_level1: Operator_level1 MORE_T Operator_level2
#line 515 "src/parser.yy"
{
    yylhs.value.as < Node * > () = new Node(TYPE_OPERATOR, yystack_[1].value.as < std::string > (), to_linestruct(yylhs.location));if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("MORE_T TYPE_OPERATOR ... \n");}    
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1533 "src/parser.tab.cc"
    break;

  case 55: // Operator_level1: Operator_level1 EQUEQU Operator_level2
#line 521 "src/parser.yy"
{
    yylhs.value.as < Node * > () = new Node(TYPE_OPERATOR, yystack_[1].value.as < std::string > (), to_linestruct(yylhs.location));if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("EQUEQU TYPE_OPERATOR ... \n");}    
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1543 "src/parser.tab.cc"
    break;

  case 56: // Operator_level2: Operator_level3
#line 529 "src/parser.yy"
{ yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1549 "src/parser.tab.cc"
    break;

  case 57: // Operator_level2: Operator_level2 ADD Operator_level3
#line 531 "src/parser.yy"
{
    yylhs.value.as < Node * > () = new Node(TYPE_OPERATOR, yystack_[1].value.as < std::string > (), to_linestruct(yylhs.location));if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("ADD TYPE_OPERATOR ... \n");}    
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1559 "src/parser.tab.cc"
    break;

  case 58: // Operator_level2: Operator_level2 SUB Operator_level3
#line 537 "src/parser.yy"
{
    yylhs.value.as < Node * > () = new Node(TYPE_OPERATOR, yystack_[1].value.as < std::string > (), to_linestruct(yylhs.location));if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){ printf("SUB TYPE_OPERATOR ... \n");}   
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1569 "src/parser.tab.cc"
    break;

  case 59: // Operator_level3: Expression
#line 546 "src/parser.yy"
{ yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1575 "src/parser.tab.cc"
    break;

  case 60: // Operator_level3: Operator_level3 MULT Expression
#line 548 "src/parser.yy"
{
    yylhs.value.as < Node * > () = new Node(TYPE_OPERATOR, yystack_[1].value.as < std::string > (), to_linestruct(yylhs.location));if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("MULT TYPE_OPERATOR ... \n");}    
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1585 "src/parser.tab.cc"
    break;

  case 61: // Operator_level3: Operator_level3 DIV Expression
#line 554 "src/parser.yy"
{
    yylhs.value.as < Node * > () = new Node(TYPE_OPERATOR, yystack_[1].value.as < std::string > (), to_linestruct(yylhs.location));if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("DIV TYPE_OPERATOR ... \n");}    
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1595 "src/parser.tab.cc"
    break;

  case 62: // Expression: Expression O_B Expression_OP C_B
#line 563 "src/parser.yy"
{
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("Expression [Expression]\n");}    
        
    yylhs.value.as < Node * > () = new Node(TYPE_EXPRESSION_OB_EXPRESSION_CB, "", to_linestruct(yylhs.location));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
}
#line 1607 "src/parser.tab.cc"
    break;

  case 63: // Expression: Expression DOT LENGTH
#line 571 "src/parser.yy"
{
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("Ex length\n");}        
    
    yylhs.value.as < Node * > () = new Node(TYPE_INT, TYPE_DOT_LENGTH, to_linestruct(yylhs.location));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());    
}
#line 1618 "src/parser.tab.cc"
    break;

  case 64: // Expression: Expression DOT Identifier O_P Params C_P
#line 578 "src/parser.yy"
{       
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("DOT Identifier (Params)\n");}        
    
    yylhs.value.as < Node * > () = new Node(TYPE_VAR_DOT_IDENTIFIER_OP_PARAMS_CP, "", to_linestruct(yylhs.location));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
}
#line 1631 "src/parser.tab.cc"
    break;

  case 65: // Expression: NUMBERS
#line 586 "src/parser.yy"
         {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("a number\n");}         yylhs.value.as < Node * > () = new Node(TYPE_INT, yystack_[0].value.as < std::string > (), to_linestruct(yylhs.location));}
#line 1637 "src/parser.tab.cc"
    break;

  case 66: // Expression: TRUE
#line 587 "src/parser.yy"
      {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("true\n");}        yylhs.value.as < Node * > () = new Node(TYPE_BOOLEAN, yystack_[0].value.as < std::string > (), to_linestruct(yylhs.location));}
#line 1643 "src/parser.tab.cc"
    break;

  case 67: // Expression: FALSE
#line 588 "src/parser.yy"
       {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("false\n");}        yylhs.value.as < Node * > () = new Node(TYPE_BOOLEAN, yystack_[0].value.as < std::string > (), to_linestruct(yylhs.location));}
#line 1649 "src/parser.tab.cc"
    break;

  case 68: // Expression: Identifier
#line 590 "src/parser.yy"
{
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("Identifier_Expression\n");}        
        
    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
}
#line 1659 "src/parser.tab.cc"
    break;

  case 69: // Expression: THIS
#line 595 "src/parser.yy"
      {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("this\n");}         yylhs.value.as < Node * > () = new Node(TYPE_THIS, yystack_[0].value.as < std::string > (), to_linestruct(yylhs.location));}
#line 1665 "src/parser.tab.cc"
    break;

  case 70: // Expression: NEW TYPE_INT O_B Expression_OP C_B
#line 597 "src/parser.yy"
{
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("new int\n");}        
    
    yylhs.value.as < Node * > () = new Node(TYPE_NEW_INT_OB_EXP_CB, yystack_[4].value.as < std::string > (), to_linestruct(yylhs.location));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());    
}
#line 1676 "src/parser.tab.cc"
    break;

  case 71: // Expression: NEW Identifier O_P C_P
#line 604 "src/parser.yy"
{
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("new idintifier here\n");}        
    
    yylhs.value.as < Node * > () = new Node(TYPE_NEW_IDENTIFIER_OP_PARAMS_CP, yystack_[3].value.as < std::string > (), to_linestruct(yylhs.location));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    //$$->children.push_back($4);    
}
#line 1688 "src/parser.tab.cc"
    break;

  case 72: // Expression: EXCLAIMATION Expression
#line 613 "src/parser.yy"
{    
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("not exp\n");}        
    
    yylhs.value.as < Node * > () = new Node(TYPE_EXCLAIMATION_EXPRESSION, yystack_[1].value.as < std::string > (), to_linestruct(yylhs.location));    
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    
}
#line 1700 "src/parser.tab.cc"
    break;

  case 73: // Expression: O_P Expression_OP C_P
#line 621 "src/parser.yy"
{
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("(exp)\n");}    
    
    yylhs.value.as < Node * > () = new Node(TYPE_OP_EXPRESSION_CP, "", to_linestruct(yylhs.location));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
}
#line 1711 "src/parser.tab.cc"
    break;

  case 74: // Identifier: IDENTIFIER
#line 632 "src/parser.yy"
{ 
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){std::cout << "idenfidier:" << yystack_[0].value.as < std::string > () << " LINE["<< locThing.location << "]"  << std::endl;}
    yylhs.value.as < Node * > () = new Node(TYPE_IDENTIFIER, yystack_[0].value.as < std::string > () + "_", to_linestruct(yylhs.location));
}
#line 1720 "src/parser.tab.cc"
    break;


#line 1724 "src/parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
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


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
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
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -68;

  const signed char parser::yytable_ninf_ = -34;

  const short
  parser::yypact_[] =
  {
     -25,   -10,    61,    20,   -68,    68,   -68,   -68,   -10,    31,
     -68,    81,   -12,   -68,   -68,    93,   -10,    69,   102,    92,
     -68,   108,   -68,    95,    69,   -68,   112,   -10,   -68,   130,
      69,   121,   -68,   -68,   112,    69,   -68,   151,   131,   129,
     -68,   -10,   -68,   152,   -68,   143,   147,    69,   154,   173,
     149,   175,   -10,   -10,   153,    69,   -68,   155,    76,   177,
     156,   157,    42,   158,   159,    96,   162,    98,   120,   -68,
      53,   118,    42,    42,    39,   -68,   -68,   -68,   -68,    42,
       0,   188,   176,     8,    75,   133,   -68,    42,    42,   -68,
     126,    53,   -68,    42,   142,    42,   -68,    42,    42,   163,
     164,    -5,   133,   168,   165,    -3,    42,   -68,    42,    42,
      42,    42,    42,    42,    42,    42,    42,   -11,     6,     9,
     -68,    74,    42,    91,    97,    34,   -68,   166,   191,    42,
     167,   -68,   188,   176,     8,     8,     8,    75,    75,   133,
     133,    35,   -68,   169,   145,   145,   -68,   104,   -68,   -68,
     200,   -68,   -68,    47,   -68,   -68,    42,   -68,   181,   -68,
      42,   -68,   195,   171,   197,   209,   145,   127,   -68,    42,
     -68,   -68,   199
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,    74,     0,     1,     3,     0,     0,
       6,     0,     0,     2,     7,     0,     0,    19,     0,     0,
      35,    36,    37,     0,    19,    16,     9,     0,    38,     0,
      19,     0,    11,    17,     8,     0,    20,     0,     0,     0,
      34,     0,    18,     0,    10,     0,     0,    23,     0,    24,
       0,     0,     0,     0,     0,     0,    22,     0,     0,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    39,
      38,     0,     0,     0,     0,    69,    67,    66,    65,     0,
       0,    48,    50,    52,    56,    59,    68,     0,     0,    42,
       0,     0,    21,     0,     0,     0,    40,     0,     0,     0,
       0,     0,    72,     0,     0,     0,     0,    12,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      41,     0,     0,     0,     0,     0,     5,     0,     0,     0,
       0,    73,    49,    51,    55,    54,    53,    57,    58,    61,
      60,     0,    63,     0,     0,     0,    13,     0,    14,    46,
       0,     4,    43,     0,    71,    62,    29,    45,     0,    15,
       0,    70,    30,     0,     0,    28,     0,     0,    64,     0,
      44,    47,    31
  };

  const short
  parser::yypgoto_[] =
  {
     -68,   -68,   -68,   -68,   189,   211,   -68,   170,   -23,   198,
     -68,   172,   -68,   -68,    52,   -68,   -68,    33,    16,   -58,
     -60,   117,   116,    79,     1,   -67,    -1
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     2,     3,     9,    23,    10,    66,    24,    25,    26,
      36,    49,    50,    51,   162,   163,   164,    27,    68,    69,
     165,    81,    82,    83,    84,    85,    86
  };

  const short
  parser::yytable_[] =
  {
       5,    33,    80,   106,     1,   106,   102,    12,   106,   142,
      96,    16,   101,   100,   106,    19,    28,   106,   107,   105,
       7,   112,   113,    28,     4,     4,    37,   118,   119,    28,
      17,    13,    96,   121,    28,   123,    96,   124,   125,   128,
      45,   131,   106,   106,    33,    73,    28,   139,   140,     8,
     144,    56,    57,   145,    28,   106,   141,    70,    74,    75,
       8,     6,   147,    97,    91,   103,    70,    91,    41,   153,
      91,   150,   155,   104,     4,    76,    77,     4,    78,   114,
      52,    90,   106,    94,   161,    79,   157,   158,    52,    91,
     115,    98,   146,    91,    20,    21,    22,    61,    62,   106,
     167,    20,    21,    22,     4,   106,    63,    64,   170,   148,
      11,     4,   106,   137,   138,   149,   143,    61,    65,    61,
      93,    15,   159,    20,    21,    22,    63,    64,    63,    64,
      29,     4,    18,     4,    30,   106,    32,    89,    65,    61,
      65,    61,    95,    91,    91,   171,    31,    61,    63,    64,
      63,    64,    35,     4,    38,     4,    63,    64,    40,    99,
      65,     4,    65,    61,   122,    91,    61,   120,    65,    42,
      44,   116,    63,    64,    43,    63,    64,     4,   117,    46,
       4,   109,   110,   111,    65,    48,    47,    65,   134,   135,
     136,    53,   -26,    54,    55,    58,   -27,   108,    71,    60,
      72,    87,    88,    92,   126,   127,   129,   151,   130,   152,
     160,   154,   156,   166,   -32,   168,   169,   106,   -33,    39,
      14,   172,    34,   132,   133,     0,     0,    59,    67
  };

  const short
  parser::yycheck_[] =
  {
       1,    24,    62,     8,    29,     8,    73,     8,     8,    20,
      68,    23,    72,    71,     8,    16,    17,     8,    18,    79,
       0,    13,    14,    24,    35,    35,    27,    87,    88,    30,
      42,     0,    90,    93,    35,    95,    94,    97,    98,    44,
      41,    44,     8,     8,    67,     3,    47,   114,   115,    29,
      44,    52,    53,    44,    55,     8,   116,    58,    16,    17,
      29,     0,   122,    10,    65,    26,    67,    68,    35,   129,
      71,    37,    37,    74,    35,    33,    34,    35,    36,     4,
      47,    65,     8,    67,    37,    43,   144,   145,    55,    90,
      15,    38,    18,    94,    25,    26,    27,    21,    22,     8,
     160,    25,    26,    27,    35,     8,    30,    31,   166,    18,
      42,    35,     8,   112,   113,    18,   117,    21,    42,    21,
      22,    40,    18,    25,    26,    27,    30,    31,    30,    31,
      28,    35,    39,    35,    42,     8,    41,    41,    42,    21,
      42,    21,    22,   144,   145,    18,    38,    21,    30,    31,
      30,    31,    40,    35,    24,    35,    30,    31,    37,    41,
      42,    35,    42,    21,    22,   166,    21,    41,    42,    18,
      41,    38,    30,    31,    43,    30,    31,    35,    45,    27,
      35,     5,     6,     7,    42,    38,    43,    42,   109,   110,
     111,    37,    19,    44,    19,    42,    19,     9,    42,    44,
      43,    43,    43,    41,    41,    41,    38,    41,    43,    18,
      10,    44,    43,    32,    19,    44,    19,     8,    19,    30,
       9,   169,    24,   106,   108,    -1,    -1,    55,    58
  };

  const signed char
  parser::yystos_[] =
  {
       0,    29,    47,    48,    35,    72,     0,     0,    29,    49,
      51,    42,    72,     0,    51,    40,    23,    42,    39,    72,
      25,    26,    27,    50,    53,    54,    55,    63,    72,    28,
      42,    38,    41,    54,    55,    40,    56,    72,    24,    50,
      37,    63,    18,    43,    41,    72,    27,    43,    38,    57,
      58,    59,    63,    37,    44,    19,    72,    72,    42,    57,
      44,    21,    22,    30,    31,    42,    52,    53,    64,    65,
      72,    42,    43,     3,    16,    17,    33,    34,    36,    43,
      66,    67,    68,    69,    70,    71,    72,    43,    43,    41,
      64,    72,    41,    22,    64,    22,    65,    10,    38,    41,
      65,    66,    71,    26,    72,    66,     8,    18,     9,     5,
       6,     7,    13,    14,     4,    15,    38,    45,    66,    66,
      41,    66,    22,    66,    66,    66,    41,    41,    44,    38,
      43,    44,    67,    68,    69,    69,    69,    70,    70,    71,
      71,    66,    20,    72,    44,    44,    18,    66,    18,    18,
      37,    41,    18,    66,    44,    37,    43,    65,    65,    18,
      10,    37,    60,    61,    62,    66,    32,    66,    44,    19,
      65,    18,    60
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    46,    47,    47,    48,    48,    49,    49,    50,    50,
      51,    51,    52,    52,    52,    52,    53,    53,    54,    55,
      55,    56,    57,    58,    58,    58,    59,    59,    60,    61,
      61,    61,    62,    62,    63,    63,    63,    63,    63,    64,
      64,    65,    65,    65,    65,    65,    65,    65,    66,    66,
      67,    67,    68,    68,    68,    68,    69,    69,    69,    70,
      70,    70,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    72
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     3,     2,    17,    16,     1,     2,     2,     1,
       7,     5,     3,     4,     4,     5,     1,     2,     3,     0,
       2,     9,     2,     0,     1,     3,     1,     3,     1,     0,
       1,     3,     1,     3,     3,     1,     1,     1,     1,     1,
       2,     3,     2,     5,     7,     5,     4,     7,     1,     3,
       1,     3,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     4,     3,     6,     1,     1,     1,     1,     1,
       5,     4,     2,     3,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "EXCLAIMATION", "DIV",
  "EQUEQU", "MORE_T", "LESS_T", "OR", "AND", "EQU", "ADDADD", "SUBSUB",
  "ADD", "SUB", "MULT", "NEW", "THIS", "SEMICOLON", "COMMA", "LENGTH",
  "SYSTEM_O_PRINT", "RETURN", "EXTENDS", "MAIN", "BOOLEAN", "TYPE_INT",
  "STRING", "VOID", "CLASS", "WHILE", "IF", "ELSE", "FALSE", "TRUE",
  "IDENTIFIER", "NUMBERS", "C_B", "O_B", "STATIC", "PUBLIC", "C_M", "O_M",
  "O_P", "C_P", "DOT", "$accept", "Goal", "MainClass", "ClassDeclarations",
  "ClassBody", "ClassDeclaration", "FunctionBody", "VarDeclarations",
  "VarDeclaration", "MethodDeclarations", "MethodDeclaration",
  "Param_decl", "Params_decl", "Param_decl_NotEmpty", "Param", "Params",
  "Params_NotEmpty", "Type", "Statements", "Statement", "Expression_OP",
  "Operator_level0", "Operator_level1", "Operator_level2",
  "Operator_level3", "Expression", "Identifier", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    78,    78,    87,    98,   140,   184,   185,   194,   199,
     206,   214,   231,   238,   245,   253,   265,   266,   272,   281,
     282,   290,   307,   317,   321,   328,   337,   344,   359,   370,
     374,   381,   392,   399,   409,   410,   411,   412,   413,   417,
     421,   429,   436,   441,   446,   455,   464,   473,   486,   487,
     495,   496,   507,   508,   514,   520,   529,   530,   536,   546,
     547,   553,   562,   570,   577,   586,   587,   588,   589,   595,
     596,   603,   611,   620,   631
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2314 "src/parser.tab.cc"

#line 636 "src/parser.yy"

