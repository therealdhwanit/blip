//Dhwanit Kumawat
//Last Modified on: 12/2/24

//online documentation used for this project:
//https://en.cppreference.com/w/cpp/container/map - maps
//https://en.cppreference.com/w/cpp/container/vector - vectors
//https://www.geeksforgeeks.org/convert-string-to-int-in-cpp/ - stoi()

#ifndef _SymbolTable_h
#define _SymbolTable_h

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "Parse.h"

using namespace std;

class SymbolTable{
    public:
        void set();
        void reset();
        void construct(vector<string> &container);
};

#endif /* _SymbolTable_h */