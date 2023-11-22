%skeleton "lalr1.cc" 

%defines
//Assignemnt 2 test
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor
%code requires{
    #include <string>
    #include "Node.h"  
    #include "LineStruct.hh"
    
    class LocThing;    

}

%param { LocThing& locThing }

%locations

%code{
    
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

}

/*Operations*/
%token <std::string> EXCLAIMATION DIV EQUEQU MORE_T LESS_T OR AND EQU ADDADD SUBSUB ADD SUB MULT 
/*Terminals*/
%token <std::string> NEW THIS SEMICOLON COMMA
/*Method declarations*/
%token <std::string> LENGTH SYSTEM_O_PRINT RETURN EXTENDS MAIN 
/*Types*/
%token <std::string> BOOLEAN TYPE_INT STRING VOID CLASS
/*Statements*/
%token <std::string> WHILE IF ELSE
/*Expressions*/
%token <std::string> FALSE TRUE 
/*Identifiers*/
%token <std::string> IDENTIFIER  NUMBERS
/*we dont know*/
%token <std::string> C_B O_B STATIC PUBLIC C_M O_M O_P C_P DOT


%token END 0 "end of file"


// definition of the production rules. All production rules are of type Node
%type <Node *> Identifier FunctionBody Param Params Expression Statement Statements Type MethodDeclaration MethodDeclarations VarDeclaration VarDeclarations ClassDeclaration ClassDeclarations MainClass Goal
//%type Identifier Expression Statement //Type MethidDeclaration VarDeclaration ClassDeclaration MainClass Goal

//%type <Node *> expression  addExpression multExpression factor identifier
%type <Node *> Operator_level0 Operator_level1 Operator_level2 Operator_level3 Expression_OP
%type <Node *> Params_decl Param_decl Param_decl_NotEmpty Params_NotEmpty
%type <Node *> ClassBody




%right AND OR LESS_T MORE_T EQUEQU
%left ADD SUB
%left MULT DIV


%%
Goal:
MainClass ClassDeclarations END {
                            if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("Goal\n");}                            
                            $$ = new Node(TYPE_GOAL, "", to_linestruct(@$));
                            $$->children.push_back($1);
                            $$->children.push_back($2);
                            root = $$;
                            if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("r1 ");}
                            
                            }
|MainClass END {
                            if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("Goal\n");}
                            
                            $$ = new Node(TYPE_GOAL, "", to_linestruct(@$));
                            $$->children.push_back($1);
                            root = $$;
                            if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("r1 ");}                            
                            }
;

MainClass:
CLASS Identifier O_M PUBLIC STATIC VOID MAIN O_P STRING O_B C_B Identifier C_P O_M Statement C_M C_M {
                            
                            if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("made a main class\n");}
                            $$ = new Node(TYPE_MAIN_CLASS, "", to_linestruct(@$));
                            $$->children.push_back($2);
                            Node* classBody = new Node(TYPE_CLASSBODY, "", to_linestruct(@$));
                            Node* methods = new Node(TYPE_METHOD_DECLS, "", to_linestruct(@$));
                            Node* method = new Node(TYPE_METHOD_DECL, "", to_linestruct(@$));
                            Node* methodBody = new Node(TYPE_FUNCTIONBODY, "", to_linestruct(@$));
                            Node* vars = new Node(TYPE_VAR_DECLS, "", to_linestruct(@$));
                            Node* paramType = new Node(TYPE_DATATYPE, "STRING[]", to_linestruct(@$));
                            Node* mvars = new Node(TYPE_VAR_DECLS, "", to_linestruct(@$));
                            Node* methodType = new Node(TYPE_DATATYPE, $6, to_linestruct(@$));
                            Node* methodID  = new Node(TYPE_IDENTIFIER, $7, to_linestruct(@$));
                            Node* methodParamDecls  = new Node(TYPE_PARAM_DECLS, "", to_linestruct(@$));
                            Node* methodParamDecl  = new Node(TYPE_PARAM_DECL, "", to_linestruct(@$));
                            Node* methodStatement  = new Node(TYPE_STATEMENTS, "", to_linestruct(@$));
                            Node* returnVoid = new Node(TYPE_VOID, TYPE_VOID, to_linestruct(@$));
                            //method->children.push_back(Statement);
                            Node* emptyReturn = new Node(TYPE_RETURN, "", to_linestruct(@$));

                            method->children.push_back(methodType);
                            method->children.push_back(methodID);
                            method->children.push_back(methodParamDecls);
                            methodParamDecls->children.push_back(methodParamDecl);
                            methodParamDecl->children.push_back(paramType);
                            methodParamDecl->children.push_back($12);

                            emptyReturn->children.push_back(returnVoid);

                            methodBody->children.push_back(vars);
                            methodStatement->children.push_back($15);
                            methodBody->children.push_back(methodStatement);
                            methodBody->children.push_back(emptyReturn);
                            method->children.push_back(methodBody);
                            methods->children.push_back(method);
                            classBody->children.push_back(mvars);
                            classBody->children.push_back(methods);

                            $$->children.push_back(classBody);

                            }
|CLASS Identifier O_M PUBLIC STATIC VOID MAIN O_P STRING O_B C_B Identifier C_P O_M  C_M C_M {
                            if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("made a main class\n");}
                            
                            $$ = new Node(TYPE_MAIN_CLASS, "", to_linestruct(@$));
                            $$->children.push_back($2);                            
                            //$$->children.push_back($12);
                            Node* classBody = new Node(TYPE_CLASSBODY, "", to_linestruct(@$));
                            Node* methods = new Node(TYPE_METHOD_DECLS, "", to_linestruct(@$));
                            Node* method = new Node(TYPE_METHOD_DECL, "", to_linestruct(@$));
                            Node* methodBody = new Node(TYPE_FUNCTIONBODY, "", to_linestruct(@$));
                            Node* emptyReturn = new Node(TYPE_RETURN, "", to_linestruct(@$));
                            Node* returnVoid = new Node(TYPE_VOID, TYPE_VOID, to_linestruct(@$));
                            Node* vars = new Node(TYPE_VAR_DECLS, "", to_linestruct(@$));
                            Node* paramType = new Node(TYPE_DATATYPE, "STRING[]", to_linestruct(@$));
                            Node* mvars = new Node(TYPE_VAR_DECLS, "", to_linestruct(@$));
                            Node* methodType = new Node(TYPE_DATATYPE, $6, to_linestruct(@$));
                            Node* methodID  = new Node(TYPE_IDENTIFIER, $7, to_linestruct(@$));
                            Node* methodParamDecls  = new Node(TYPE_PARAM_DECLS, "", to_linestruct(@$));
                            Node* methodParamDecl  = new Node(TYPE_PARAM_DECL, "", to_linestruct(@$));
                            Node* methodStatement  = new Node(TYPE_STATEMENTS, "", to_linestruct(@$));

                            method->children.push_back(methodType);
                            method->children.push_back(methodID);
                            method->children.push_back(methodParamDecls);
                            methodParamDecls->children.push_back(methodParamDecl);
                            methodParamDecl->children.push_back(paramType);
                            methodParamDecl->children.push_back($12);
    
                            methodBody->children.push_back(vars);
                            methodBody->children.push_back(methodStatement);
                            emptyReturn->children.push_back(returnVoid);
                            methodBody->children.push_back(emptyReturn);
                            

                            method->children.push_back(methodBody);
                            methods->children.push_back(method);
                            classBody->children.push_back(mvars);
                            classBody->children.push_back(methods);

                            $$->children.push_back(classBody);
                            }                            
;

ClassDeclarations: 
ClassDeclaration {$$ = new Node(TYPE_CLASS_DECLS, "", to_linestruct(@$)); $$->children.push_back($1); if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("class decs\n");}}
|ClassDeclarations ClassDeclaration                             
                            {
                            
                            $$ = $1;
                            $$->children.push_back($2);
                          }


ClassBody: 
VarDeclarations MethodDeclarations {
                            $$ = new Node(TYPE_CLASSBODY, "", to_linestruct(@$));
                            $$->children.push_back($1);
                            $$->children.push_back($2);
                            }
|MethodDeclarations {$$ = new Node(TYPE_CLASSBODY, "", to_linestruct(@$));
                    $$->children.push_back(new Node(TYPE_VAR_DECLS,"", to_linestruct(@$)));
                    $$->children.push_back($1);
                            }
;

ClassDeclaration:
CLASS Identifier EXTENDS Identifier O_M ClassBody C_M {
                            if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("class dec extends\n");    }
                  
                            $$ = new Node(TYPE_CLASS_DECL_EXT, "", to_linestruct(@$));
                            $$->children.push_back($2);
                            $$->children.push_back($4);
                            $$->children.push_back($6);
                            }
|CLASS Identifier O_M ClassBody C_M {
                            if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("a class\n");      }
                            
                         
                            // auto ss = to_linestruct(@$);
                            // std::cout << "ss: " <<  ss.start_line << std::endl;                           
                            // std::cout << "ss: " <<  ss.start_column << std::endl;                           
                            // std::cout << "ss: " <<  ss.end_line << std::endl;                           
                            // std::cout << "ss: " <<  ss.end_column << std::endl;                           
                            
                            $$ = new Node(TYPE_CLASS_DEC, "", to_linestruct(@$));
                            $$->children.push_back($2);
                            $$->children.push_back($4);                            
                            
}                                               
;

FunctionBody: RETURN Expression_OP SEMICOLON {

    $$ = new Node(TYPE_EMPTY_FUNCTIONBODY, "", to_linestruct(@$));
    Node* NodePtr = new Node(TYPE_RETURN, "", to_linestruct(@$));
    NodePtr->children.push_back($2);
    $$->children.push_back(new Node(TYPE_VAR_DECLS,"", to_linestruct(@$)));
    $$->children.push_back(NodePtr);}
|VarDeclarations RETURN Expression_OP SEMICOLON{
    $$ = new Node(TYPE_FUNCTIONBODY, "", to_linestruct(@$));
    $$->children.push_back($1);
    Node* NodePtr = new Node(TYPE_RETURN, "", to_linestruct(@$));
    NodePtr->children.push_back($3);
    $$->children.push_back(NodePtr);
}
|Statements RETURN Expression_OP SEMICOLON {
    $$ = new Node(TYPE_FUNCTIONBODY, "", to_linestruct(@$));
    $$->children.push_back(new Node(TYPE_VAR_DECLS,"", to_linestruct(@$)));
    $$->children.push_back($1);
    Node* NodePtr = new Node(TYPE_RETURN, "", to_linestruct(@$));
    NodePtr->children.push_back($3);
    $$->children.push_back(NodePtr);
}
|VarDeclarations Statements RETURN Expression_OP SEMICOLON{
    $$ = new Node(TYPE_FUNCTIONBODY, "", to_linestruct(@$));
    $$->children.push_back($1);
    $$->children.push_back($2);
    Node* NodePtr = new Node(TYPE_RETURN, "", to_linestruct(@$));
    NodePtr->children.push_back($4);
    $$->children.push_back(NodePtr);
}
;


VarDeclarations:
VarDeclaration {$$ = new Node(TYPE_VAR_DECLS, "", to_linestruct(@$)); $$->children.push_back($1); if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("var decs\n");}}
|VarDeclarations VarDeclaration
{
                          $$ = $1;
                          $$->children.push_back($2);}
;
VarDeclaration:
Type Identifier SEMICOLON {

    $$ = new Node(TYPE_VAR_DECL, "", to_linestruct(@$));
    $$->children.push_back($1);
    $$->children.push_back($2);
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("Type Identifier SEMICOLON\n");}    
}
;

MethodDeclarations: %empty {$$ = new Node(TYPE_METHOD_DECLS,"", to_linestruct(@$));} //? maybe remove if cause problems
|MethodDeclarations MethodDeclaration{

                        if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("method decs2\n");}                        
                        $$ = $1;                          
                        $$->children.push_back($2);
}
;
MethodDeclaration: 
PUBLIC Type Identifier O_P Params_decl C_P O_M FunctionBody C_M
{

    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("method dec\n");}
    
    $$ = new Node(TYPE_METHOD_DECL, "", to_linestruct( @$));
    $$->children.push_back($2);
    $$->children.push_back($3);
    
    $$->children.push_back($5);
    
    
    $$->children.push_back($8);
}
;

Param_decl:
Type Identifier 
{ 
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("type identifier\n");}
    
    $$ = new Node(TYPE_PARAM_DECL, "",  to_linestruct(@$));
    $$->children.push_back($1);
    $$->children.push_back($2);
}
;

Params_decl: %empty 
{
    $$ = new Node(TYPE_PARAM_DECLS, "", to_linestruct(@$)); if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("empty param decl\n");}
}
|Param_decl 
{    
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("Param_decls\n"); }
    
    $$ = new Node(TYPE_PARAM_DECLS, "", to_linestruct(@$));
    $$->children.push_back($1);
}
|Param_decl_NotEmpty COMMA Param_decl 
{    
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("Param_decls\n");}    
    $$ = $1; //new Node("param", "", to_linestruct(@$));
    $$->children.push_back($3);
}
;

Param_decl_NotEmpty: 
Param_decl 
{
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("Param_decls\n");}
    
    $$ = new Node(TYPE_PARAM_DECLS, "", to_linestruct(@$));
    $$->children.push_back($1);
}
|Param_decl_NotEmpty COMMA Param_decl 
{    
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("Param_decls\n");}
    
    $$ = $1; //new Node("param", "", to_linestruct(@$));
    $$->children.push_back($3);
}
;

//(1,2,3)
//(PARAM )
//(PARAM , )
//(PARAM , PARAM) => (PARAMS)
//(PARAMS , PARAM) => (PARAMS)
Param:
Expression_OP {
    
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("param\n");}
    
    //$$ = new Node("Param(expression)", "", to_linestruct(@$));
    $$ = $1;
    
    //$$->children.push_back($1);
    }
;

Params: %empty 
{
    $$ = new Node(TYPE_EMPTY_PARAMS, "", to_linestruct(@$)); if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("empty param\n");}
}
|Param 
{    
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("Params\n"); }
    
    $$ = new Node(TYPE_PARAMS, "", to_linestruct(@$)); 
    $$->children.push_back($1);
}
|Params_NotEmpty COMMA Param
{
    
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("Params\n");}
    
    $$ = $1; //new Node("param", "", to_linestruct(@$));
    $$->children.push_back($3);
}
;

Params_NotEmpty: 
Param 
{    
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("Params\n"); }
    
    $$ = new Node(TYPE_PARAMS, "", to_linestruct(@$)); 
    $$->children.push_back($1);
}
|Params_NotEmpty COMMA Param 
{    
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("Params\n");}
    
    $$ = $1; //new Node("param", "", to_linestruct(@$));
    $$->children.push_back($3);
}
;

Type: 
TYPE_INT O_B C_B {$$ = new Node(TYPE_DATATYPE, TYPE_INT_ARR, to_linestruct(@$));}
|BOOLEAN    {$$ = new Node(TYPE_DATATYPE, $1, to_linestruct(@$));}
|TYPE_INT        {$$ = new Node(TYPE_DATATYPE, $1, to_linestruct(@$));}
|STRING     {$$ = new Node(TYPE_DATATYPE, $1, to_linestruct(@$));}
|Identifier
;

Statements:
Statement {
    $$ = new Node(TYPE_STATEMENTS, "", to_linestruct(@$));
    $$->children.push_back($1);
    }
|Statements Statement 
{
    $$ = $1;
    $$->children.push_back($2);
    }
;

Statement:
O_M Statements C_M 
{
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("(Statement)\n"); }    
    
    $$ = new Node(TYPE_OM_STATEMENT_CM, "", to_linestruct(@$));
    $$->children.push_back($2);
}
|O_M C_M 
{    
    $$ = new Node(TYPE_STATEMENTS,"empty");
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("()\n"); }       
}
|SYSTEM_O_PRINT O_P Expression_OP C_P SEMICOLON 
{
  $$ = new Node(TYPE_SYSTEM_PRINT, "", to_linestruct(@$));
  $$->children.push_back($3);
  }
|IF O_P Expression_OP C_P Statement ELSE Statement //statement in end: Right Recursion => cause shift/reduce
{
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("IF ELSE state\n");}        
    
    $$ = new Node(TYPE_IF_ELSE, "", to_linestruct(@$));
    $$->children.push_back($3);
    $$->children.push_back($5);
    $$->children.push_back($7);
}
|WHILE O_P Expression_OP C_P Statement  
{
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("WHILE statement\n");}        
    
    $$ = new Node(TYPE_WHILE, "", to_linestruct(@$));
    $$->children.push_back($3);
    $$->children.push_back($5);
}

|Identifier EQU Expression_OP SEMICOLON 
{
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("id = expression\n");}    
    
    
    $$ = new Node(TYPE_IDENTIFIER_EQU_EXPRESSION, "", to_linestruct(@$));
    $$->children.push_back($1);
    $$->children.push_back($3);
}
|Identifier O_B Expression_OP C_B EQU Expression_OP SEMICOLON 
{    
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("id \n");}    
    
    $$ = new Node(TYPE_IDENTIFIER_OB_EXPRESSION_CB_EQU_EXPRESSION, "", to_linestruct(@$));
    $$->children.push_back($1);
    $$->children.push_back($3);
    $$->children.push_back($6);
}
//|%empty {$$ = new Node("Empty Statement","", to_linestruct(@$));} //?
;

Expression_OP:
Operator_level0
|Expression_OP OR Operator_level0       
{
    $$ = new Node(TYPE_OPERATOR, $2, to_linestruct(@$));if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("AND TYPE_OPERATOR ... \n");}    
    $$->children.push_back($1);
    $$->children.push_back($3);
};

Operator_level0:
Operator_level1
|Operator_level0 AND Operator_level1       
{
    $$ = new Node(TYPE_OPERATOR, $2, to_linestruct(@$));if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("AND TYPE_OPERATOR ... \n");}    
    $$->children.push_back($1);
    $$->children.push_back($3);
};




Operator_level1:
Operator_level2
|Operator_level1 LESS_T Operator_level2  
{
    $$ = new Node(TYPE_OPERATOR, $2, to_linestruct(@$));if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("LESS_T TYPE_OPERATOR ... \n");}    
    $$->children.push_back($1);
    $$->children.push_back($3);
}
|Operator_level1 MORE_T Operator_level2   
{
    $$ = new Node(TYPE_OPERATOR, $2, to_linestruct(@$));if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("MORE_T TYPE_OPERATOR ... \n");}    
    $$->children.push_back($1);
    $$->children.push_back($3);
}
|Operator_level1 EQUEQU Operator_level2   
{
    $$ = new Node(TYPE_OPERATOR, $2, to_linestruct(@$));if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("EQUEQU TYPE_OPERATOR ... \n");}    
    $$->children.push_back($1);
    $$->children.push_back($3);
}
;

Operator_level2:
Operator_level3        
|Operator_level2 ADD Operator_level3      
{
    $$ = new Node(TYPE_OPERATOR, $2, to_linestruct(@$));if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("ADD TYPE_OPERATOR ... \n");}    
    $$->children.push_back($1);
    $$->children.push_back($3);
}
|Operator_level2 SUB Operator_level3       
{
    $$ = new Node(TYPE_OPERATOR, $2, to_linestruct(@$));if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){ printf("SUB TYPE_OPERATOR ... \n");}   
    $$->children.push_back($1);
    $$->children.push_back($3);
}
;


Operator_level3:
Expression                              
|Operator_level3 MULT Expression      
{
    $$ = new Node(TYPE_OPERATOR, $2, to_linestruct(@$));if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("MULT TYPE_OPERATOR ... \n");}    
    $$->children.push_back($1);
    $$->children.push_back($3);
}
|Operator_level3 DIV Expression      
{
    $$ = new Node(TYPE_OPERATOR, $2, to_linestruct(@$));if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("DIV TYPE_OPERATOR ... \n");}    
    $$->children.push_back($1);
    $$->children.push_back($3);
}
;

Expression: 
Expression O_B Expression_OP C_B 
{
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("Expression [Expression]\n");}    
        
    $$ = new Node(TYPE_EXPRESSION_OB_EXPRESSION_CB, "", to_linestruct(@$));
    $$->children.push_back($1);
    $$->children.push_back($3);
}
|Expression DOT LENGTH 
{
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("Ex length\n");}        
    
    $$ = new Node(TYPE_INT, TYPE_DOT_LENGTH, to_linestruct(@$));
    $$->children.push_back($1);    
}
|Expression DOT Identifier O_P Params C_P 
{       
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("DOT Identifier (Params)\n");}        
    
    $$ = new Node(TYPE_VAR_DOT_IDENTIFIER_OP_PARAMS_CP, "", to_linestruct(@$));
    $$->children.push_back($1);
    $$->children.push_back($3);
    $$->children.push_back($5);
}
|NUMBERS {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("a number\n");}         $$ = new Node(TYPE_INT, $1, to_linestruct(@$));}
|TRUE {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("true\n");}        $$ = new Node(TYPE_BOOLEAN, $1, to_linestruct(@$));}
|FALSE {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("false\n");}        $$ = new Node(TYPE_BOOLEAN, $1, to_linestruct(@$));}
|Identifier 
{
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("Identifier_Expression\n");}        
        
    $$ = $1;
}//a id
|THIS {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("this\n");}         $$ = new Node(TYPE_THIS, $1, to_linestruct(@$));}
|NEW TYPE_INT O_B Expression_OP C_B 
{
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("new int\n");}        
    
    $$ = new Node(TYPE_NEW_INT_OB_EXP_CB, $1, to_linestruct(@$));
    $$->children.push_back($4);    
}
|NEW Identifier O_P  C_P 
{
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("new idintifier here\n");}        
    
    $$ = new Node(TYPE_NEW_IDENTIFIER_OP_PARAMS_CP, $1, to_linestruct(@$));
    $$->children.push_back($2);
    //$$->children.push_back($4);    
}//new id
|EXCLAIMATION Expression 
//|EXCLAIMATION Expression_OP
{    
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("not exp\n");}        
    
    $$ = new Node(TYPE_EXCLAIMATION_EXPRESSION, $1, to_linestruct(@$));    
    $$->children.push_back($2);
    
}
|O_P Expression_OP C_P 
{
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("(exp)\n");}    
    
    $$ = new Node(TYPE_OP_EXPRESSION_CP, "", to_linestruct(@$));
    $$->children.push_back($2);
}

;


Identifier: IDENTIFIER 
{ 
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){std::cout << "idenfidier:" << $1 << " LINE["<< locThing.location << "]"  << std::endl;}
    $$ = new Node(TYPE_IDENTIFIER, $1 + "_", to_linestruct(@$));
}//id
%%
