//Dhwanit Kumawat
//Last Modified on: 12/2/24

//online documentation used for this project:
//https://en.cppreference.com/w/cpp/container/map - maps
//https://en.cppreference.com/w/cpp/container/vector - vectors
//https://www.geeksforgeeks.org/convert-string-to-int-in-cpp/ - stoi()

#include <iostream>
#include "SymbolTable.h"
#include "Project8.h"

using namespace std;

//this function basically gathers all the info that we need from the commands and places them in a container as separate entries
//after this, we can go item by item and figure out what the whole line's commands and inputs are, they are stoed in order in this vector
void SymbolTable::construct(vector<string> &container){
    string next = string(peek_next_token());
    while(next != "text" && next != "output" && next != "var" && next != "set" && next_token_type != END){ //if the token isn't a command or the end
        read_next_token();
        if(next_token() == "//"){ skip_line();} //this is to skip the line with a comment
        container.emplace_back(next_token()); //this places the command or value in the container
        next = string(peek_next_token());
    }
}

//this function creates a new variable in the map and sets it to something
void SymbolTable::set(){
    read_next_token(); //reads next thing (name of the variable in this case)
    string varName = next_token(); //calls next_token to get the name of the variable, and assigns it to our string variable called varName
    //the .find() function returns .end() if the key was not found.
    //we want there to be an error when the variable already exists, so we use !=
    if(vars.find(varName) != vars.end()){ 
        cout << "variable " << varName << " incorrectly re-initialized" << endl;
    }
    //code for when the variable doesn't already exist, meaning we need to add it
    else{
        read_next_token(); //gets the next part of the statement after var
        if(next_token_type == NUMBER){
            vars[varName] = token_number_value;
        } 
        //its not a number, but its some operator so we have to use recursion to evalulate the stuff after the operator and then set it equal tp the var
        else if(next_token_type == SYMBOL){
            containers.emplace_back(next_token());
            construct(containers);
            vars[varName] = compute(containers);
            containers.clear();
        }
    }
}

void SymbolTable::reset(){
    read_next_token(); //reads the name of the variable
    string varName = next_token();
    //same logic as before, but this time we are checking for if the variable doesn't already exist
    if(vars.find(varName) == vars.end()){
        cout << "variable " << varName << " not declared" << endl;
    }
    //code for when the variable does exist, meaning we need to update it
    else{
        read_next_token(); //gets the next part of the statement after var
        if(next_token_type == NUMBER){
            vars[varName] = token_number_value;
        } 
        //its not a number, but its some operator so we have to use recursion to evalulate the stuff after the operator and then set it equal tp the var
        else if(next_token_type == SYMBOL){
            containers.emplace_back(next_token());
            construct(containers);
            vars[varName] = compute(containers);
            containers.clear();
        }
    }
}