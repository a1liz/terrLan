#define MAX_ID 1024
#ifndef SYM_H
#define SYM_H

typedef struct TAG_SYMBOL_ENTRY {
    char *name;
    int token;
    int type;
} symbol_entry;

class symbol_table {
private:
    symbol_entry table[MAX_ID];
    int size;

public:
    int lookup(char* name);
    int insert(char* name, int token);
    int gettoken(char* name);
    char* getname(int pos);
    int settype(int pos, int type);
    int gettype(int pos);
    int getsize();
};

#endif