#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

#ifndef TREE_H
#define TREE_H


union NodeAttr {
    int op;
    int vali;
    char valc;
    int symbl_seq;

    NodeAttr(void) {op = 0;}
    NodeAttr(int i) {op = i;}
    NodeAttr(char c) {valc = c};
}

union Label {
    struct {
        char* true_label;
        char* false_label;
    };
    struct {
        char* begin_label;
        char* next_label;
    };
}

class Node {
public:
    vector<Node*> children;
    vector<Node*> sibling;
    int lineno;
    int kind;
    int kind_kind;
    NodeAttr attr;
    int type;
    int seq;
    int temp_var;
    Label label;

    void output(void);
};

class tree {
private:
    Node *root;
    static node_seq;
    static temp_var_seq;
    static label_seq;

    void type_check(Node *t);
    void get_temp_var(Node *t);
    char* new_label(void);
    void recursive_get_label(Node *t);
    void stmt_get_label(Node *t);
    void expr_get_label(Node *t);
    void gen_header(ostream &out);
    void gen_decl(ostream &out, Node *t);
    void recursive_gen_code(ostream &out, Node *t);
    void stmt_gen_code(ostream &out, Node *t);
    void expr_gen_code(ostream &out, Node *t);

public:
    Node* NewRoot(int kind, int kind_kind, NodeAttr attr, int type, vector<Node*> children);
    void get_label(void);
    void gen_code(ostream &out);
};

#endif