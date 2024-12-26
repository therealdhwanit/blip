//Dhwanit Kumawat
//Last Modified on: 12/2/24

//online documentation used for this project:
//https://en.cppreference.com/w/cpp/container/map - maps
//https://en.cppreference.com/w/cpp/container/vector - vectors
//https://www.geeksforgeeks.org/convert-string-to-int-in-cpp/ - stoi()

#include <iostream>
#include "Project8.h"

using namespace std;

map<string, int> vars; //this map will be used for the whole blip file
vector<string> containers; //this vector will be used one line at a time, to parse it

SymbolTable t;

void run(){
    read_next_token();
    while(next_token_type != END){ //we want to keep running commands until the end of the blip is reached
        string command = string(next_token());
        
        if(command == "text"){
            outputText();
        }

        else if(command == "var"){
            t.set();
        }

        else if(command == "set"){
            t.reset();
        }

        else if(command == "output"){
            output();
        }

        else if(command == "//"){
            skip_line();
        }
        read_next_token();
    }
    vars.clear(); //clears the map of variables because we are done with this file
}

void outputText(){
    read_next_token();
    cout << string(next_token()); //this prints out the next statement after text command
}

void output(){
    t.construct(containers); //sets up the vector of items that have been parsed for processing
    cout << compute(containers); //runs our "main" compute function to do all the operations recursiuvely 
    containers.clear(); //clears the container for next command
}

//does the actual operation depending on what the operator is
int operatorResult(string op, int a, int b){
    if(op == "+"){
        return a + b;
    } else if(op == "-"){
        return a - b;
    } else if(op == "*"){
        return a * b;
    } else if(op == "/"){
        return a / b;
    } else if(op == "%"){
        return a % b;
    } else if(op == "&&"){
        return a && b;
    } else if(op == "||"){
        return a || b;
    } else if(op == "<"){
        return a < b;
    } else if(op == ">"){
        return a > b;
    } else if(op == "=="){
        return a == b;
    } else if(op == "!="){
        return a != b;
    } else if(op == "<="){
        return a <= b;
    } else if(op == ">="){
        return a >= b;
    } else if(op == "!"){
        return !a;
    } else if(op == "~"){
        return -a;
    }
}

int compute(vector<string> &container){
    string text = container.front(); //get the first bit of information from the container that we used to store parsed stuff

    //we first check if the text that we got from the container is a variable by checking if it's a letter
    if(text >= "A" && text <= "Z" || text >= "a" && text <= "z"){
        containers.erase(containers.begin()); //this removes the first element from the container because we just finished processing it, so we don't need it
                                              //used online documentation for vectors to write this
        return vars[text]; //this goes into our map storing all the variables and gets the desired element's value
    }

    //this checks if the text that we got from the container is a number -- if it isnt any of these, than its a number
    else if(container.front() != "~" && container.front() != "!" && container.front() != ">=" && container.front() != "<=" && 
            container.front() != "!=" && container.front() != "==" && container.front() != "||" && container.front() != "&&" && 
            container.front() != "<" && container.front() != ">" && container.front() != "+" && container.front() != "-" && 
            container.front() != "*" && container.front() != "/" && container.front() != "%" && container.front() != "&" && container.front() != "|"){
                containers.erase(containers.begin());
                return stoi(text); //the stoi() function converts string to int, used online documentation
    }

    //this checks if the text that we got is a binary math, binary logic, or comparision operator
    else if(text != "!" && text != "~"){
        container.erase(container.begin());
        //recurisve calls to figure out the rest of the function
        int a = compute(container);
        int b = compute(container);
        //return the actual operations in the end
        return operatorResult(text, a, b);
    }

    //if text is a unary operator
    else if(text == "!" || text == "~"){
        container.erase(container.begin());
        int a = compute(container); //gets the value that the unary operation is being performed on
        return operatorResult(text, a, 0); //does the actual operation, 0 is because we don't care what b is since it is unary
    }
}