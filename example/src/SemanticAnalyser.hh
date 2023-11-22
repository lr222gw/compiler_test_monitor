#include "SymbolTable.hh"
#include "Node.h"
#include <vector>

enum ExNullWrong{
    Exist, _Null, Wrong
};


class SemanticAnalyser{
public:
    SemanticAnalyser(Node *AST, SymbolTable *symbolTable);
    bool startChecking();

private:
    Node* traverseAST(Node* node, int scope = 0);
    void typeCheck_methodReturnTypes(Record* a, Record* b, Node* node);
    void typeCheck_methodArguments(std::vector<Node*>* a, std::vector<Param*>* b, Node* node, Method* method);
    bool typeChecking(Record* a, Record* b, Node* node);

    ExNullWrong checkIfType(Node* node, std::string type);
    ExNullWrong checkIfTypeEM(Node* node, std::string type);

    std::string expressionToString(Node* node);
    std::string method_signatureToString(Method* method);

    SymbolTable *symbolTable;
    Node *AST_root;

};