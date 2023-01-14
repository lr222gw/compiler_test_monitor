#include "BinaryByteCodeImporter.hh"
#include "ByteCodeStructures.hh"
#include "Variable.hh"
#include <utility>

BinaryByteCodeImporter::BinaryByteCodeImporter( std::string  const pathToByteCode):
byteCodePath(pathToByteCode)
{
    
}

Program_byteCode* BinaryByteCodeImporter::readFile()
{
    Program_byteCode* program = new Program_byteCode; 

    std::ifstream rf(this->byteCodePath, std::ios::out | std::ios::binary);
    if (!rf) {
        std::cout << "cannot open" << std::endl;
        assert(false && "byte.dat could not be open or created.");
    }
    else {

        //Program_byteCode From binary ...
        //Read number of Methods of Program_byteCode
        std::int64_t nrOfMethods_vec;
        rf.read((char*)&nrOfMethods_vec, sizeof(nrOfMethods_vec));

        program->methods.resize(nrOfMethods_vec);

        for(int i = 0; i < nrOfMethods_vec; i++ ){
            //program->methods.push_back(Method_byteCode());
            Method_byteCode& currentMethod = program->methods[i];            

            //Read length of Method Label, then read the Method Label 
            int64_t methodLabel_length;
            rf.read((char*)&methodLabel_length, sizeof(methodLabel_length));            

            std::string methodLabel;// = currentMethod.label;            
            methodLabel.resize(methodLabel_length);
            rf.read((char*)methodLabel.data(), methodLabel_length * static_cast<std::int64_t>(sizeof(char))); 
            currentMethod.label = methodLabel.c_str();
            
            //Read Number of Variables in current Method
            std::int64_t nrOfVariables;
            rf.read((char*)&nrOfVariables, sizeof(nrOfVariables));
            currentMethod.variables.resize(nrOfVariables);

            //Fill the map!
            program->methods_map.insert(std::make_pair(currentMethod.label, &program->methods[i]));

            for(int j = 0; j < nrOfVariables; j++ ) {

                //Read length of Variabel ID string, then store ID string 
                int64_t variable_ID_length;
                rf.read((char*)&variable_ID_length, sizeof(variable_ID_length));

                std::string variable_ID;
                variable_ID.resize(variable_ID_length);
                rf.read((char*)variable_ID.data(), variable_ID_length * static_cast<std::int64_t>(sizeof(char))); 

                //Read length of Variabel TYPE string, then store TYPE string
                int64_t variable_TYPE_length;
                rf.read((char*)&variable_TYPE_length, sizeof(variable_TYPE_length));

                std::string variable_TYPE;
                variable_TYPE.resize(variable_TYPE_length);
                rf.read((char*)variable_TYPE.data(), variable_TYPE_length * static_cast<std::int64_t>(sizeof(char))); 

                //Create the Variable and push it to the Variables vector
                currentMethod.variables[j].id   = variable_ID.c_str();  
                currentMethod.variables[j].type = variable_TYPE.c_str();
            }

            //Read Number Of Method Blocks in current Method
            std::int64_t nrOfMethodBlocks;
            rf.read((char*)&nrOfMethodBlocks, sizeof(nrOfMethodBlocks));
            currentMethod.method_blocks.resize(nrOfMethodBlocks);

            for(int j = 0; j < nrOfMethodBlocks; j++ ) {
                Block_byteCode* currentMethodBlock = &currentMethod.method_blocks[j];

                //Read length of Method Block Label string, then store Method Block Label string 
                int64_t MethodBlock_label_length;
                rf.read((char*)&MethodBlock_label_length, sizeof(MethodBlock_label_length));

                std::string MethodBlock_label;
                MethodBlock_label.resize(MethodBlock_label_length);
                rf.read((char*)MethodBlock_label.data(), MethodBlock_label_length * static_cast<std::int64_t>(sizeof(char))); 

                //store the label 
                currentMethodBlock->label = MethodBlock_label.c_str();

                //Read Number Of byteInfo instructions, then store the vector with data
                std::int64_t nrOfByteInfos;
                rf.read((char*)&nrOfByteInfos, sizeof(nrOfByteInfos));
                currentMethodBlock->instructions.resize(nrOfByteInfos);
                
                for(int k = 0; k < nrOfByteInfos; k++){
                    byteInfo* currentInstruction = &currentMethodBlock->instructions[k];

                    //Store length of byteinfo object string, then store byteinfo object string
                    int64_t byteInfo_objectStr_length;
                    rf.read((char*)&byteInfo_objectStr_length, sizeof(byteInfo_objectStr_length));

                    std::string byteInfo_objectStr;
                    byteInfo_objectStr.resize(byteInfo_objectStr_length);
                    rf.read((char*)byteInfo_objectStr.c_str(), byteInfo_objectStr_length * static_cast<std::int64_t>(sizeof(char)));
                    currentInstruction->object = byteInfo_objectStr.c_str();

                    //Store the ByteType 
                    std::int64_t byteType;
                    rf.read((char*)&byteType, sizeof(byteType));

                    currentInstruction->type = static_cast<ByteType>(byteType);                    
                }                
            }           
        }
    }
    this->the_program = program;
    return program;
}


