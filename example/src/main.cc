#include "BinaryByteCodeImporter.hh"
#include "Tacs.hh"
#include "parser.tab.hh"
#include "BasicBlock.hh"
#include "LocThing.hh"
#include "SymbolTable.hh"
#include "SemanticAnalyser.hh"
#include "errorMandager.hh"
#include <cstdio>
#include <iostream>
#include "TrashCollector.hh"
#include "IntermediateREP.hh"
#include "ByteCodeGenerator.hh"
#include "BinaryByteCodeExporter.hh"
#include "ByteCodePrinter.hh"
#include <cassert>
#include <cstring>
extern Node *root;
extern FILE *yyin;
enum errCodes
{
    SUCCESS         = 0,
    FAILED_GRAMMAR  = 1,
    FAILED_TREE     = 2,
    FAILED_SEMANTIC = 3,
    SEGMENT_FAULT   = 139 
};

int errCode = errCodes::SUCCESS;

void yy::parser::error(const location_type &loc, const string &err)
{
    std::cout << "\nLAST_LINE[" << loc << "]" << std::endl;
    std::cout << "Cannot generate a syntax tree for this input: " << err
              << std::endl;
    errCode = errCodes::FAILED_GRAMMAR;
}

int extracted(int &argc, char **&argv)
{    

    
    LocThing parser;

    if (argc > 1)
    {

        if (!(yyin = fopen(argv[1], "r")))
        {
            perror(argv[1]);
            errCode = errCodes::FAILED_GRAMMAR;
        }
    }

    std::cout << "=============================\n";
    std::cout << "          Parsing\n";
    std::cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n";
    if (!parser.parse())
    {
        root->print_tree();
        root->generate_tree();
        printf("Tree successfully generated\n");

        SymbolTable t(root);        

        t.print();
        

        SemanticAnalyser semanticAnalyser(root, &t);
        semanticAnalyser.startChecking();

        if(errorManager::hasError()){
            errCode = FAILED_SEMANTIC;
        }else{
            printf("\n\n=============================\n");
            printf("=============================\n");
            printf(">> Creating Intermediate Representation, Adds temp variables to Symbol table ");
            IntermediateRepresentation rep(root,&t); 
            rep.printme();
            rep.generate_CFG();
            t.print();
            
            //NOTE: if user sends '-b', compiler will generate byte code, otherwise not...
            if(argc == 3 && std::strcmp(argv[2], "-b") == 0){
                
                ByteCodeGenerator b(rep.getCFGs(),&t);
                printf("\n\n=============================\n");
                printf("=============================\n");
                printf(">> Printing result from Bytecode generation ");
                b.print();

                BinaryByteCodeExporter exporter(b.getProgramByteCode());
                BinaryByteCodeImporter importer("byte.dat");
                importer.readFile();

                printf("\n\n=============================\n");
                printf("=============================\n");
                printf(">> Printing Bytecode that was exported, then imported ");
                ByteCodePrinter::print(*importer.the_program);
            }else{
                 std::cout << "OBS: Compiler does not generate bytecode! \nSend '-b' as argument to generat bytecode." << std::endl; 
            }

            int f = 5;
            
        }     
        
        
        
    }
    else
    {
        if (errCode == errCodes::SUCCESS)
        {
            errCode = errCodes::FAILED_TREE;
        }
    }
    std::cout << "hello this is the end" << std::endl;
    fclose(yyin);
    delete TrashCollector::get_instance();
    delete root;
    return errCode;
}
int main(int argc, char **argv)
{

    // Reads from file if a file name is passed as an argument. Otherwise, reads
    // from stdin.
    return extracted(argc, argv);
}
