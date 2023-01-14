#include "ByteCodeGenerator.hh"
#include "Byteinfo.hh"
#include "Tacs.hh"
#include <cstdlib>
#include <stack>



ByteCodeGenerator::ByteCodeGenerator(std::vector<CFG*>* CFGs, SymbolTable* symbolTable)
{
    this->symbolTable = symbolTable;
    this->CFGs = CFGs;
    generate_bytecode();
}

void ByteCodeGenerator::print()
{
    
    ByteCodePrinter::print(this->program);

}

Program_byteCode& ByteCodeGenerator::getProgramByteCode()
{
    return this->program;
}


void ByteCodeGenerator::generate_bytecode()
{
    int count = 0;

    for(auto *cfg : *this->CFGs){
        Method_byteCode method;      
        auto method_record = symbolTable->getMethod(cfg->getClass, cfg->fName);
        method.method_blocks.push_back(Block_byteCode());
        method.label = cfg->getClass+"."+cfg->fName;

        for (auto param_of_method : method_record->parameters) {
            method.variables.push_back(*param_of_method->variable);                        
            
            method.method_blocks[0].instructions.insert(
                method.method_blocks[0].instructions.begin(),
                byteInfo{ByteType::iStore,param_of_method->variable->id}
            );
        }
        for (auto var_in_method : method_record->variables) {
            method.variables.push_back(*var_in_method.second);
        }
        subCFG_to_bytecode(*cfg->rootBlock, method, ClassMethod_data{cfg->getClass, cfg->fName});
        this->program.methods.push_back(method);     
        this->program.methods_map.insert(std::make_pair(cfg->fName,&method));     
    }

}

void ByteCodeGenerator::subCFG_to_bytecode(BasicBlock &basicBlock, Method_byteCode& method, ClassMethod_data dat) {                

    static std::vector<std::string> visited;
    //see if we have visited nodes            
    for(auto v : visited){
        if(basicBlock.name == v){
            return;
        }
    }    
    
    bool lastWasParam = false;
    std::string lastTarget;
    
    method.method_blocks.push_back(Block_byteCode());
    Block_byteCode* current = &method.method_blocks.back();
    current->label = basicBlock.name;

    Method* currentMethod = symbolTable->getMethod(dat.Class, dat.Method);
    std::stack<Parameter*> params;
    for(auto *tac : basicBlock.tacInstructions){

        if(tac->id == TacType::MethodCall ){

            int popThisMany = std::atoi(tac->RHS.c_str()) - 1;
            for(int i = 0; i < popThisMany  ;i++){
                params.pop();
            }

            symbolTable->resetTable(); //NOTE: this must be done...
            std::string parset_target;

            if(params.top()->RES == "this" || params.top()->RES == "system"){
                parset_target = dat.Class;
            }else{
                
                auto g = currentMethod->lookUpVariable(params.top()->RES);                                
                assert(g != nullptr && "Uncaught Semantic Error! No support for Class members...");

                parset_target = g->type;
                int pausehere = 0;
            }

            
            dynamic_cast<MethodCall*>(tac)->set_target(parset_target);
            params.pop();
        }       

        if( tac->id == TacType::ArrayCopy || 
            tac->id == TacType::ArrayAccess || 
            tac->id == TacType::New_Array ||
            tac->id == TacType::lenght
         ){

            assert(false && "Uncaught Semantic Error! No support for Arrays...");
        }          

         if( tac->id == TacType::Parameter){
             if(tac->RES == "system"){
                //'system' is not a real parameter so we skip that...
                continue;
             }

            params.push(dynamic_cast<Parameter*>(tac));
        }  

        for(auto byteInfo : tac->getByteInfo()){            
            if(byteInfo.type == ByteType::iLoad && 
                byteInfo.object != "system" &&
                byteInfo.object != "this" &&
                byteInfo.object != "void"){
                auto g = currentMethod->lookUpVariable(byteInfo.object);                 
                if(!g){
                    bool wasParam = false;
                    for(auto p : currentMethod->parameters){
                        if (p->name == byteInfo.object){
                            wasParam = true;
                            break;
                        }
                    }
                    if(!wasParam){
                        assert(g != nullptr && "Uncaught Semantic Error! No support for Class members...");
                    }
                }
            }

            current->instructions.push_back(byteInfo); 
        }         
    }
                
    //add it to the list
    visited.push_back(basicBlock.name);
    if(basicBlock.trueExit){
        
        subCFG_to_bytecode(*basicBlock.trueExit, method, dat);
    }

    if(basicBlock.falseExit){
        subCFG_to_bytecode(*basicBlock.falseExit, method, dat);
    }
    
}


