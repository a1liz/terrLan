#include <iostream>
#include <fstream>
#include "symbol.h"
#include "newTree.h"
extern int yyparse();
extern Tree tree;

int main(int argc, char **argv) {
    yyparse();
    
    return 0;
}