#pragma once
// #ifndef NODE_H
// #define NODE_H

#include "location.hh"
#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include "LineStruct.hh"

using namespace std;

class Node {
public:
	int id;
    lineStruct line;
	string type, value;
	vector<Node*> children;
	Node(string t, string v) : type(t), value(v) {}
    Node(string t, string v, lineStruct line) : type(t), value(v), line(line) {}
    virtual ~Node(){
        for(auto c : children){
            if(c){
                delete c; 
            }
        }
    
	}
	Node()
	{
		type = "uninitialised";
		value = "uninitialised"; }   // Bison needs this.
  
	void print_tree(int depth=0) {
		for(int i=0; i<depth; i++)
		    cout << "  ";
		cout << type << ":" << value << endl;
		for(auto i=children.begin(); i!=children.end(); i++)
		(*i)->print_tree(depth+1);
	}
  
	void generate_tree() {
		std::ofstream outStream;
	  	outStream.open("tree.dot");

		int count = 0;
		outStream << "digraph {" << std::endl;
		generate_tree_content(count, &outStream);
		outStream << "}" << std::endl;
		outStream.close();

		std::cout << "\nBuilt a parse-tree:" << std::endl;
  	}

    void generate_tree_content(int &count, ofstream *outStream) {
        id = count++;
        *outStream << "n" << id << " [label=\"" << type << ":" << value << "\"];" << endl;

        for (auto i = children.begin(); i != children.end(); i++)
        {
            (*i)->generate_tree_content(count, outStream);
            *outStream << "n" << id << " -> n" << (*i)->id << endl;
        }
    }
    

};

//#endif
