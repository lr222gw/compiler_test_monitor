#pragma once
#include <iostream>


constexpr const bool RULE_IGNORE_SEMANTIC_DEBUG_PRINT               =false;
constexpr const bool RULE_COMPILER_LINE_ERROR_MESSAGE               =true;

constexpr const char* TYPE_GOAL                                     ="GOAL";
constexpr const char* TYPE_MAIN_CLASS                               ="Main class";
constexpr const char* TYPE_CLASS_DECLS                              ="ClassDeclarations";
constexpr const char* TYPE_CLASSBODY                                ="class body";
constexpr const char* TYPE_CLASS_DECL_EXT                           ="Class Dec EXT";
constexpr const char* TYPE_CLASS_DEC                                ="Class Dec";
constexpr const char* TYPE_VAR_DECLS                                ="VarDeclarations";
constexpr const char* TYPE_VAR_DECL                                 ="VarDeclaration";
constexpr const char* TYPE_METHOD_DECLS                             ="MethodDeclarations";
constexpr const char* TYPE_METHOD_DECL                              ="method dec";
constexpr const char* TYPE_PARAM_DECLS                              ="Param_decls";
constexpr const char* TYPE_PARAM_DECL                               ="Param_decl";
constexpr const char* TYPE_EMPTY_PARAMS                             ="Empty Params";
constexpr const char* TYPE_PARAMS                                   ="Params";
constexpr const char* TYPE_DATATYPE                                 ="TYPE";
constexpr const char* TYPE_STATEMENTS                               ="Statements";
constexpr const char* TYPE_OM_STATEMENT_CM                          ="{Statement}";
constexpr const char* TYPE_SYSTEM_PRINT                             ="SYSTEM_O_PRINT statement";
constexpr const char* TYPE_IF_ELSE                                  ="if else";
constexpr const char* TYPE_WHILE                                    ="while";
constexpr const char* TYPE_IDENTIFIER_EQU_EXPRESSION                ="identifier=expression;"; 
constexpr const char* TYPE_IDENTIFIER_OB_EXPRESSION_CB_EQU_EXPRESSION="identifier[expression]=expression";
constexpr const char* TYPE_EXPRESSION_OB_EXPRESSION_CB              ="Expression[Expression]";
constexpr const char* TYPE_DOT_LENGTH                               ="DOT LENGTH";
constexpr const char* TYPE_VAR_DOT_IDENTIFIER_OP_PARAMS_CP          ="*VAR*.Identifier(Params)";
constexpr const char* TYPE_NEW_INT_OB_EXP_CB                        ="NEW INT [EXP]";
constexpr const char* TYPE_NEW_IDENTIFIER_OP_PARAMS_CP              ="NEW Identifier (params)";
constexpr const char* TYPE_EXCLAIMATION_EXPRESSION                  ="EXCLAIMATION expression";
constexpr const char* TYPE_OP_EXPRESSION_CP                         ="(Expression)";
constexpr const char* TYPE_RETURN                                   ="Return";
constexpr const char* TYPE_THIS                                     ="THIS"; // Different from id 'this'...
constexpr const char* TYPE_CLASS                                    ="CLASS";
constexpr const char* TYPE_INT                                      ="int";
constexpr const char* TYPE_INT_ARR                                  ="int[]";
constexpr const char* TYPE_BOOLEAN                                  ="boolean";
constexpr const char* TYPE_VOID                                     ="void";
constexpr const char* TYPE_OPERATOR                                 ="Operator";
constexpr const char* TYPE_IDENTIFIER                               ="identifier";
constexpr const char* TYPE_EMPTY_FUNCTIONBODY                       ="Empty FunctionBody";
constexpr const char* TYPE_FUNCTIONBODY                             ="FunctionBody";
constexpr const char* OPR_AND                                       ="&&";
constexpr const char* OPR_OR                                        ="||";
constexpr const char* OPR_EQUEQU                                    ="==";
constexpr const char* OPR_LESS_THAN                                 ="<";                                      
constexpr const char* OPR_MORE_THAN                                 =">";
constexpr const char* SPECIAL_ID_THIS                               ="this"; //Different from TYPE_THIS
