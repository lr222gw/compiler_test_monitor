#Implicit Rules
#CXX = clang++
CXX = g++
#CXXFLAGS = -glldb -std=c++17
CXXFLAGS = -g -std=c++17
#Explicit rules
SRC := $(wildcard src/*.cc)
SRC := $(filter-out src/parser.tab.cc, $(SRC))	#Needs to be compiled separately
SRC := $(filter-out src/lex.yy.c, $(SRC))	#Needs to be compiled with main.cc
OBJ := $(SRC:.cc=.o)
INTERPRETER_SRC_DEBUG := $(wildcard interpreter_src/*.cc)
INTERPRETER_OBJ_DEBUG := $(INTERPRETER_SRC_DEBUG:.cc=.o)
INTERPRETER_SRC := $(wildcard interpreter_src/*.cc)
INTERPRETER_SRC += src/ByteCodeStructures.cc
INTERPRETER_SRC += src/Record.cc
INTERPRETER_SRC += src/Variable.cc
INTERPRETER_SRC += src/Byteinfo.cc
INTERPRETER_SRC += src/ByteCodePrinter.cc
INTERPRETER_SRC += src/BinaryByteCodeImporter.cc
INTERPRETER_OBJ := $(INTERPRETER_SRC:.cc=.o)

GEN_UNMODIFIED_DB := temp.json
_clang 	:=  clang++ -glldb 
_gpp 	:=  g++ 	-g 
COMPILER := ${_gpp}
src_dir := src/

interpreter: $(INTERPRETER_OBJ) compiler
	$(COMPILER) -w -std=c++17 $(INTERPRETER_OBJ) -ointerpreter	

compiler: ${src_dir}lex.yy.c ${src_dir}parser.tab.o $(OBJ) #Faster, Uses the compiled files
	$(COMPILER) -w -std=c++17 $(OBJ) -ocompiler ${src_dir}parser.tab.o ${src_dir}lex.yy.c 		


${src_dir}parser.tab.o: ${src_dir}parser.tab.cc
	${COMPILER} -w -c ${src_dir}parser.tab.cc -o${src_dir}parser.tab.o -std=c++17		

${src_dir}parser.tab.cc: ${src_dir}parser.yy
	bison ${src_dir}parser.yy -o${src_dir}parser.tab.cc

${src_dir}lex.yy.c: ${src_dir}lexer.flex ${src_dir}parser.tab.cc
	flex -o${src_dir}lex.yy.c ${src_dir}lexer.flex

clean:
		rm -f ${src_dir}parser.tab.* ${src_dir}lex.yy.c* ${src_dir}stack.hh ${src_dir}location.hh ${src_dir}position.hh
		rm -f compiler
		rm -f _compiler
		rm -f .cache/clangd/index/*.idx
		rm -f src/*.o
		rm -f interpreter_src/*.o
		
clean_all: clean
	rm -f *.dot *.json CFGs.pdf tree.pdf	
