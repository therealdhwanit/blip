**OVERVIEW** 

This project involves the design and implementation of a toy programming language called Blip. The Blip language is designed to be simple, with straightforward syntax and functionality, making it easy to parse and execute. The goal of this project is to create an interpreter for Blip that can read, parse, and execute Blip programs. The interpreter will support variable declarations, assignments, mathematical and logical expressions, and output operations. 

**BLIP LANGUAGE SPECIFICATION** Blip Supports four types of statements: 

**Text Statements**:** Display messages on the screen. 

- Example: 

text Hello 

text "Hello World" 

**Output Statements**: Display the result of evaluating a numeric expression. 

- Example:** 

output 42 

output + 1 1 

output \* x x 

**Var Statements**: Declare and initialize variables. 

- Example: 

var x 42 

var y + x 1 

**Set Statements**: Assign new values to existing variables. 

- Example: 

set x 42 

set x + x 1 

**EXPRESSION SYNTAX** 

Blip uses prefix notation (Polish notation) for all expressions. Operators precede their operands, making parsing straightforward. Supported operators include: 

- **Arithmetic Operators**: +, -, \*, /, % 
- **Logical Operators**: &&, || 
- **Comparison Operators**: <, >, ==, !=, <=, >= 
- **Unary Operators**: ! (logical NOT), ~ (arithmetic negation) 

**VARIABLES** 

Variables in Blip are always integers. A symbol table will be used to store variable names and their corresponding values. 

**INTERPRETER DESIGN** 

**Input Handling** 

The interpreter reads Blip programs from a file using the Input.cpp module. 

Tokens are extracted using the function read\_next\_token(), which categorizes input into: **NUMBER**: Numeric values. 

**SYMBOL**: Operators or comment markers. 

**NAME**: Keywords or variable names. 

**END**: End of the input file. 

**Symbol Table** 

A map-based data structure will store variable names as keys and their values as integers. Warnings are generated for improper use of variables: 

- Re-declaring an existing variable with a var statement. 
- Assigning a value to an undeclared variable using a set statement. 

**Expression Evaluation** 

Expressions are parsed recursively using prefix notation rules. Logical expressions evaluate to 1 (true) or 0 (false). 

Unary operators like ~ are treated as arithmetic negation. 

**Execution Flow** 

The program is parsed into statements sequentially. Each statement is executed immediately after parsing. 

**Error Handling** 

The interpreter will issue warnings for improper variable usage but will not terminate execution 

**DATA STRUCTURES** 

**Symbol Table** 

Implemented using a map (e.g., std::map<std::string, int> in C++) for efficient lookups and updates. 

**Vector Container** 

Implemented using a vector (e.g., std::vector<int> in C++) for parsing and holding each part of the expression until they are ready to evaluate.  

**EXAMPLE WORKFLOW Input File (‘example.blip’)** 

text "Welcome to Blip!" var x 10 

var y + x 5 

output \* y y 

set x ~x 

output + x y 

**Execution Output** 

Welcome to Blip! 225 

-5 

**CONCLUSION** 

This project provides a comprehensive introduction to designing interpreters for custom programming languages. By implementing Blip, we gain hands-on experience with parsing techniques, data structure design, and recursive algorithms while adhering to strict constraints on library usage for a deeper understanding of low-level implementation details. 
4 
