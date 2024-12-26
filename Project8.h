//Dhwanit Kumawat
//Last Modified on: 12/2/24

//online documentation used for this project:
//https://en.cppreference.com/w/cpp/container/map - maps
//https://en.cppreference.com/w/cpp/container/vector - vectors
//https://www.geeksforgeeks.org/convert-string-to-int-in-cpp/ - stoi()

#ifndef _Project8_h
#define _Project8_h

#include <iostream>
#include "SymbolTable.h"

extern map<string, int> vars;  //this map will be used for the whole blip file
extern vector<string> containers; //this vector will be used one line at a time, to parse it

int operatorResult(string op, int a, int b );
int compute(vector<string> &container);
void outputText();
void output();
void run();

#endif /* _Project8_h */