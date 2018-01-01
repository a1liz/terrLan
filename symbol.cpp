#include <iostream>
#include <cstring>
#include <symbol.h>
#include <newTree.h>

symbol_table symtbl;

int symbol_table::lookup(char* name) {
    for (int i = 0; i < size; i ++)
        if (strcmp(table[i].name,name) == 0)
            return i;
    return -1;
}

int symbol_table::insert(char* name, int token) {
    if (size >= MAX_ID)
        return -1;
    table[size].name = new char[strlen(name) + 1];
    strcpy(table[size].name,name);
    table[size].toekn = token;
    table[size].type = Notype;
    size++;
    return size - 1;
}

int symbol_table::gettoken(char* name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(table[i].name,name) == 0)
            return table[i].token;
    }
    return -1;
}

char* symbol_table::getname(int pos) {
    return table[pos].name;
}

int symbol_table::settype(int pos, int type) {
    if (pos < 0 || pos >= size) {
        cerr << "Bad identifier" << endl;
        return -1;
    }

    table[pos].type = type;
    return 0;
}

int symbol_table::gettype(int pos) {
    if (pos < 0 || pos >= size) {
        cerr << "Bad identifier" << endl;
        return -1;
    }

    return table[pos].type;
}