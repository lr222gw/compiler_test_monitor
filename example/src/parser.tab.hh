// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file src/parser.tab.hh
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_SRC_PARSER_TAB_HH_INCLUDED
# define YY_YY_SRC_PARSER_TAB_HH_INCLUDED
// "%code requires" blocks.
#line 8 "src/parser.yy"

    #include <string>
    #include "Node.h"  
    #include "LineStruct.hh"
    
    class LocThing;    


#line 58 "src/parser.tab.hh"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"


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

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

namespace yy {
#line 193 "src/parser.tab.hh"




  /// A Bison parser.
  class parser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
    {
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // Goal
      // MainClass
      // ClassDeclarations
      // ClassBody
      // ClassDeclaration
      // FunctionBody
      // VarDeclarations
      // VarDeclaration
      // MethodDeclarations
      // MethodDeclaration
      // Param_decl
      // Params_decl
      // Param_decl_NotEmpty
      // Param
      // Params
      // Params_NotEmpty
      // Type
      // Statements
      // Statement
      // Expression_OP
      // Operator_level0
      // Operator_level1
      // Operator_level2
      // Operator_level3
      // Expression
      // Identifier
      char dummy1[sizeof (Node *)];

      // EXCLAIMATION
      // DIV
      // EQUEQU
      // MORE_T
      // LESS_T
      // OR
      // AND
      // EQU
      // ADDADD
      // SUBSUB
      // ADD
      // SUB
      // MULT
      // NEW
      // THIS
      // SEMICOLON
      // COMMA
      // LENGTH
      // SYSTEM_O_PRINT
      // RETURN
      // EXTENDS
      // MAIN
      // BOOLEAN
      // TYPE_INT
      // STRING
      // VOID
      // CLASS
      // WHILE
      // IF
      // ELSE
      // FALSE
      // TRUE
      // IDENTIFIER
      // NUMBERS
      // C_B
      // O_B
      // STATIC
      // PUBLIC
      // C_M
      // O_M
      // O_P
      // C_P
      // DOT
      char dummy2[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;

    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    END = 0,                       // "end of file"
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    EXCLAIMATION = 258,            // EXCLAIMATION
    DIV = 259,                     // DIV
    EQUEQU = 260,                  // EQUEQU
    MORE_T = 261,                  // MORE_T
    LESS_T = 262,                  // LESS_T
    OR = 263,                      // OR
    AND = 264,                     // AND
    EQU = 265,                     // EQU
    ADDADD = 266,                  // ADDADD
    SUBSUB = 267,                  // SUBSUB
    ADD = 268,                     // ADD
    SUB = 269,                     // SUB
    MULT = 270,                    // MULT
    NEW = 271,                     // NEW
    THIS = 272,                    // THIS
    SEMICOLON = 273,               // SEMICOLON
    COMMA = 274,                   // COMMA
    LENGTH = 275,                  // LENGTH
    SYSTEM_O_PRINT = 276,          // SYSTEM_O_PRINT
    RETURN = 277,                  // RETURN
    EXTENDS = 278,                 // EXTENDS
    MAIN = 279,                    // MAIN
    BOOLEAN = 280,                 // BOOLEAN
    TYPE_INT = 281,                // TYPE_INT
    STRING = 282,                  // STRING
    VOID = 283,                    // VOID
    CLASS = 284,                   // CLASS
    WHILE = 285,                   // WHILE
    IF = 286,                      // IF
    ELSE = 287,                    // ELSE
    FALSE = 288,                   // FALSE
    TRUE = 289,                    // TRUE
    IDENTIFIER = 290,              // IDENTIFIER
    NUMBERS = 291,                 // NUMBERS
    C_B = 292,                     // C_B
    O_B = 293,                     // O_B
    STATIC = 294,                  // STATIC
    PUBLIC = 295,                  // PUBLIC
    C_M = 296,                     // C_M
    O_M = 297,                     // O_M
    O_P = 298,                     // O_P
    C_P = 299,                     // C_P
    DOT = 300                      // DOT
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 46, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_EXCLAIMATION = 3,                      // EXCLAIMATION
        S_DIV = 4,                               // DIV
        S_EQUEQU = 5,                            // EQUEQU
        S_MORE_T = 6,                            // MORE_T
        S_LESS_T = 7,                            // LESS_T
        S_OR = 8,                                // OR
        S_AND = 9,                               // AND
        S_EQU = 10,                              // EQU
        S_ADDADD = 11,                           // ADDADD
        S_SUBSUB = 12,                           // SUBSUB
        S_ADD = 13,                              // ADD
        S_SUB = 14,                              // SUB
        S_MULT = 15,                             // MULT
        S_NEW = 16,                              // NEW
        S_THIS = 17,                             // THIS
        S_SEMICOLON = 18,                        // SEMICOLON
        S_COMMA = 19,                            // COMMA
        S_LENGTH = 20,                           // LENGTH
        S_SYSTEM_O_PRINT = 21,                   // SYSTEM_O_PRINT
        S_RETURN = 22,                           // RETURN
        S_EXTENDS = 23,                          // EXTENDS
        S_MAIN = 24,                             // MAIN
        S_BOOLEAN = 25,                          // BOOLEAN
        S_TYPE_INT = 26,                         // TYPE_INT
        S_STRING = 27,                           // STRING
        S_VOID = 28,                             // VOID
        S_CLASS = 29,                            // CLASS
        S_WHILE = 30,                            // WHILE
        S_IF = 31,                               // IF
        S_ELSE = 32,                             // ELSE
        S_FALSE = 33,                            // FALSE
        S_TRUE = 34,                             // TRUE
        S_IDENTIFIER = 35,                       // IDENTIFIER
        S_NUMBERS = 36,                          // NUMBERS
        S_C_B = 37,                              // C_B
        S_O_B = 38,                              // O_B
        S_STATIC = 39,                           // STATIC
        S_PUBLIC = 40,                           // PUBLIC
        S_C_M = 41,                              // C_M
        S_O_M = 42,                              // O_M
        S_O_P = 43,                              // O_P
        S_C_P = 44,                              // C_P
        S_DOT = 45,                              // DOT
        S_YYACCEPT = 46,                         // $accept
        S_Goal = 47,                             // Goal
        S_MainClass = 48,                        // MainClass
        S_ClassDeclarations = 49,                // ClassDeclarations
        S_ClassBody = 50,                        // ClassBody
        S_ClassDeclaration = 51,                 // ClassDeclaration
        S_FunctionBody = 52,                     // FunctionBody
        S_VarDeclarations = 53,                  // VarDeclarations
        S_VarDeclaration = 54,                   // VarDeclaration
        S_MethodDeclarations = 55,               // MethodDeclarations
        S_MethodDeclaration = 56,                // MethodDeclaration
        S_Param_decl = 57,                       // Param_decl
        S_Params_decl = 58,                      // Params_decl
        S_Param_decl_NotEmpty = 59,              // Param_decl_NotEmpty
        S_Param = 60,                            // Param
        S_Params = 61,                           // Params
        S_Params_NotEmpty = 62,                  // Params_NotEmpty
        S_Type = 63,                             // Type
        S_Statements = 64,                       // Statements
        S_Statement = 65,                        // Statement
        S_Expression_OP = 66,                    // Expression_OP
        S_Operator_level0 = 67,                  // Operator_level0
        S_Operator_level1 = 68,                  // Operator_level1
        S_Operator_level2 = 69,                  // Operator_level2
        S_Operator_level3 = 70,                  // Operator_level3
        S_Expression = 71,                       // Expression
        S_Identifier = 72                        // Identifier
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
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
        value.move< Node * > (std::move (that.value));
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
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Node *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Node *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
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
        value.template destroy< Node * > ();
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
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type (token_kind_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type (token_kind_type (tok), l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {}
    };

    /// Build a parser object.
    parser (LocThing& locThing_yyarg);
    virtual ~parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    parser (const parser&) = delete;
    /// Non copyable.
    parser& operator= (const parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static std::string symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END (location_type l)
      {
        return symbol_type (token::END, std::move (l));
      }
#else
      static
      symbol_type
      make_END (const location_type& l)
      {
        return symbol_type (token::END, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXCLAIMATION (std::string v, location_type l)
      {
        return symbol_type (token::EXCLAIMATION, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EXCLAIMATION (const std::string& v, const location_type& l)
      {
        return symbol_type (token::EXCLAIMATION, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIV (std::string v, location_type l)
      {
        return symbol_type (token::DIV, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DIV (const std::string& v, const location_type& l)
      {
        return symbol_type (token::DIV, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQUEQU (std::string v, location_type l)
      {
        return symbol_type (token::EQUEQU, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EQUEQU (const std::string& v, const location_type& l)
      {
        return symbol_type (token::EQUEQU, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MORE_T (std::string v, location_type l)
      {
        return symbol_type (token::MORE_T, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MORE_T (const std::string& v, const location_type& l)
      {
        return symbol_type (token::MORE_T, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LESS_T (std::string v, location_type l)
      {
        return symbol_type (token::LESS_T, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LESS_T (const std::string& v, const location_type& l)
      {
        return symbol_type (token::LESS_T, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR (std::string v, location_type l)
      {
        return symbol_type (token::OR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::OR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND (std::string v, location_type l)
      {
        return symbol_type (token::AND, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_AND (const std::string& v, const location_type& l)
      {
        return symbol_type (token::AND, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQU (std::string v, location_type l)
      {
        return symbol_type (token::EQU, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EQU (const std::string& v, const location_type& l)
      {
        return symbol_type (token::EQU, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ADDADD (std::string v, location_type l)
      {
        return symbol_type (token::ADDADD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ADDADD (const std::string& v, const location_type& l)
      {
        return symbol_type (token::ADDADD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUBSUB (std::string v, location_type l)
      {
        return symbol_type (token::SUBSUB, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SUBSUB (const std::string& v, const location_type& l)
      {
        return symbol_type (token::SUBSUB, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ADD (std::string v, location_type l)
      {
        return symbol_type (token::ADD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ADD (const std::string& v, const location_type& l)
      {
        return symbol_type (token::ADD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB (std::string v, location_type l)
      {
        return symbol_type (token::SUB, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SUB (const std::string& v, const location_type& l)
      {
        return symbol_type (token::SUB, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MULT (std::string v, location_type l)
      {
        return symbol_type (token::MULT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MULT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::MULT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEW (std::string v, location_type l)
      {
        return symbol_type (token::NEW, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NEW (const std::string& v, const location_type& l)
      {
        return symbol_type (token::NEW, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_THIS (std::string v, location_type l)
      {
        return symbol_type (token::THIS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_THIS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::THIS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMICOLON (std::string v, location_type l)
      {
        return symbol_type (token::SEMICOLON, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SEMICOLON (const std::string& v, const location_type& l)
      {
        return symbol_type (token::SEMICOLON, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (std::string v, location_type l)
      {
        return symbol_type (token::COMMA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const std::string& v, const location_type& l)
      {
        return symbol_type (token::COMMA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LENGTH (std::string v, location_type l)
      {
        return symbol_type (token::LENGTH, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LENGTH (const std::string& v, const location_type& l)
      {
        return symbol_type (token::LENGTH, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SYSTEM_O_PRINT (std::string v, location_type l)
      {
        return symbol_type (token::SYSTEM_O_PRINT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SYSTEM_O_PRINT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::SYSTEM_O_PRINT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RETURN (std::string v, location_type l)
      {
        return symbol_type (token::RETURN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RETURN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RETURN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXTENDS (std::string v, location_type l)
      {
        return symbol_type (token::EXTENDS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EXTENDS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::EXTENDS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAIN (std::string v, location_type l)
      {
        return symbol_type (token::MAIN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MAIN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::MAIN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOLEAN (std::string v, location_type l)
      {
        return symbol_type (token::BOOLEAN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BOOLEAN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::BOOLEAN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPE_INT (std::string v, location_type l)
      {
        return symbol_type (token::TYPE_INT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TYPE_INT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TYPE_INT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING (std::string v, location_type l)
      {
        return symbol_type (token::STRING, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING (const std::string& v, const location_type& l)
      {
        return symbol_type (token::STRING, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOID (std::string v, location_type l)
      {
        return symbol_type (token::VOID, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_VOID (const std::string& v, const location_type& l)
      {
        return symbol_type (token::VOID, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CLASS (std::string v, location_type l)
      {
        return symbol_type (token::CLASS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CLASS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::CLASS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILE (std::string v, location_type l)
      {
        return symbol_type (token::WHILE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_WHILE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::WHILE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF (std::string v, location_type l)
      {
        return symbol_type (token::IF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IF (const std::string& v, const location_type& l)
      {
        return symbol_type (token::IF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE (std::string v, location_type l)
      {
        return symbol_type (token::ELSE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ELSE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::ELSE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FALSE (std::string v, location_type l)
      {
        return symbol_type (token::FALSE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FALSE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FALSE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRUE (std::string v, location_type l)
      {
        return symbol_type (token::TRUE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TRUE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TRUE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENTIFIER (std::string v, location_type l)
      {
        return symbol_type (token::IDENTIFIER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IDENTIFIER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::IDENTIFIER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUMBERS (std::string v, location_type l)
      {
        return symbol_type (token::NUMBERS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NUMBERS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::NUMBERS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_C_B (std::string v, location_type l)
      {
        return symbol_type (token::C_B, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_C_B (const std::string& v, const location_type& l)
      {
        return symbol_type (token::C_B, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_O_B (std::string v, location_type l)
      {
        return symbol_type (token::O_B, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_O_B (const std::string& v, const location_type& l)
      {
        return symbol_type (token::O_B, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STATIC (std::string v, location_type l)
      {
        return symbol_type (token::STATIC, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STATIC (const std::string& v, const location_type& l)
      {
        return symbol_type (token::STATIC, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PUBLIC (std::string v, location_type l)
      {
        return symbol_type (token::PUBLIC, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PUBLIC (const std::string& v, const location_type& l)
      {
        return symbol_type (token::PUBLIC, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_C_M (std::string v, location_type l)
      {
        return symbol_type (token::C_M, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_C_M (const std::string& v, const location_type& l)
      {
        return symbol_type (token::C_M, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_O_M (std::string v, location_type l)
      {
        return symbol_type (token::O_M, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_O_M (const std::string& v, const location_type& l)
      {
        return symbol_type (token::O_M, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_O_P (std::string v, location_type l)
      {
        return symbol_type (token::O_P, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_O_P (const std::string& v, const location_type& l)
      {
        return symbol_type (token::O_P, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_C_P (std::string v, location_type l)
      {
        return symbol_type (token::C_P, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_C_P (const std::string& v, const location_type& l)
      {
        return symbol_type (token::C_P, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOT (std::string v, location_type l)
      {
        return symbol_type (token::DOT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DOT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::DOT, v, l);
      }
#endif


    class context
    {
    public:
      context (const parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    parser (const parser&);
    /// Non copyable.
    parser& operator= (const parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef unsigned char state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *yystr);

    /// For a symbol, its name in clear.
    static const char* const yytname_[];


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const unsigned char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 228,     ///< Last index in yytable_.
      yynnts_ = 27,  ///< Number of nonterminal symbols.
      yyfinal_ = 6 ///< Termination state number.
    };


    // User arguments.
    LocThing& locThing;

  };

  inline
  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
    };
    // Last valid token kind.
    const int code_max = 300;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
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
        value.copy< Node * > (YY_MOVE (that.value));
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
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
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
        value.move< Node * > (YY_MOVE (s.value));
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
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  inline
  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  inline
  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  inline
  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


} // yy
#line 2397 "src/parser.tab.hh"




#endif // !YY_YY_SRC_PARSER_TAB_HH_INCLUDED
