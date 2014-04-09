Interpreters:
=============

an interpreter is "just" a program

## Parts

* Lexer
* Parser
* AST
* Bytecode-compiler
* Bytecode-interpreter
* Runtime

### Lexer
 - takes your program as a big string and assigns to each part a token from a list of tokens

### Parser
 - gets passed the token stream from the lexer; 'parses' the structure of the program for example BLOCKS, COMPARISONS
 - generate a parser
 -  
 - [A. Gaynor says that writing the parser is most confusing; probably because of all the recursions]



