#Implicit Rules
#CXX = clang++
CXX = g++
#CXXFLAGS = -glldb -std=c++17
CXXFLAGS = -g -std=c++17

#Explicit rules
# - SRC: Define what sourcefiles belongs to the compiler
COMPILER_SRC := $(wildcard src/compiler/*.cc)
COMPILER_SRC += $(wildcard src/shared/*.cc)
COMPILER_SRC := $(filter-out src/compiler/parser.tab.cc, $(COMPILER_SRC))	#Needs to be compiled separately
COMPILER_SRC := $(filter-out src/compiler/lex.yy.c, $(COMPILER_SRC))	#Needs to be compiled with main.cc
COMPILER_OBJ := $(COMPILER_SRC:.cc=.o)

# - INTERPRETER_SRC: Define what sourcefiles belongs to the interpreter
# -- Define what folder .cc files can be found, ex below:
INTERPRETER_SRC := $(wildcard src/interpreter/*.cc)
INTERPRETER_SRC += $(wildcard src/shared/*.cc)
INTERPRETER_OBJ := $(INTERPRETER_SRC:.cc=.o)


COMPILER := g++ 	-g
src_dir := src/compiler/

interpreter: $(INTERPRETER_OBJ) compiler
	$(COMPILER) -w -std=c++17 $(INTERPRETER_OBJ) -ointerpreter	

compiler: ${src_dir}lex.yy.c ${src_dir}parser.tab.o $(COMPILER_OBJ)
	$(COMPILER) -w -std=c++17 $(COMPILER_OBJ) -ocompiler ${src_dir}parser.tab.o ${src_dir}lex.yy.c 		


${src_dir}parser.tab.o: ${src_dir}parser.tab.cc
	${COMPILER} -w -c ${src_dir}parser.tab.cc -o${src_dir}parser.tab.o -std=c++17		

${src_dir}parser.tab.cc: ${src_dir}parser.yy
	bison ${src_dir}parser.yy -o${src_dir}parser.tab.cc

${src_dir}lex.yy.c: ${src_dir}lexer.flex ${src_dir}parser.tab.cc
	flex -o${src_dir}lex.yy.c ${src_dir}lexer.flex

clean:
		rm -f ${src_dir}parser.tab.* ${src_dir}lex.yy.c* ${src_dir}stack.hh ${src_dir}location.hh ${src_dir}position.hh
		rm -f compiler
		rm -f .cache/clangd/index/*.idx
		rm -f src/*.o
		rm -f src/shared/*.o
		rm -f src/compiler/*.o
		rm -f src/interpreter/*.o
		
clean_all: clean
	rm -f *.dot *.json CFGs.pdf tree.pdf	
