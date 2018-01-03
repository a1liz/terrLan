#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

#ifndef TREE_H
#define TREE_H

#define MAX_CHILDREN 4


enum {
    STMT_NODE = 0,
    EXPR_NODE,
    DECL_NODE,
};

enum {
    LABEL_STMT = 0,
    IF_STMT,
    IF_ELSE_STMT,
    SWITCH_STMT,
    CASE_STMT,
    DEFAULT_STMT,
    RETURN_STMT
};

enum {
    OP_EXPR = 0,
    CONST_EXPR,
};

enum {
    VAR_DECL = 0,
    ARRAY_DECL
};

enum {
    Notype = 0,
    Integer,
    Boolean,
    Character
};

// enum {
//     RIGHT_OP = 0,
//     LEFT_OP,
//     INC_OP,
//     DEC_OP,
//     AND_OP,
//     OR_OP,
//     LE_OP,
//     GE_OP,
//     EQ_OP,
//     NE_OP,
//     AND,
//     XOR,
//     OR,
//     ADD,
//     SUB,
//     MUL,
//     DIV,
//     MOD,
//     NOT,
//     TLIDE,
//     PTR_OP
// };

union NodeAttr {
    int op;
    int vali;
    char valc;
    bool valb;
    
    int symbl_seq;

    NodeAttr(void) {op = 0;}
    NodeAttr(int i) {vali = i;}
    NodeAttr(char c) {valc = c;}
    NodeAttr(bool b) {valb = b;}
};

union Label {
    struct {
        char* true_label;
        char* false_label;
    };
    struct {
        char* begin_label;
        char* next_label;
    };
};

class Node {
public:
    vector<Node*> children;
    vector<Node*> sibling;
    int lineno;
    int nodetype; // 节点种类
    int subtype; // 节点子种类
    int valuetype; // 结点属性的种类
    NodeAttr attr; // 结点属性的具体值
    int seq; // 节点在语法树中的序号
    int temp_var;
    Label label;

    void output(void);
};

class Tree {
private:
    Node *root;
    static int node_seq; 
    static int temp_var_seq;
    static int label_seq;

    
    void type_check(Node *t);
    void get_temp_var(Node *t);
    
    // char* new_label(void);
    // void recursive_get_label(Node *t);
    // void stmt_get_label(Node *t);
    // void expr_get_label(Node *t);
    // void gen_header(ostream &out);
    // void gen_decl(ostream &out, Node *t);
    // void recursive_gen_code(ostream &out, Node *t);
    // void stmt_gen_code(ostream &out, Node *t);
    // void expr_gen_code(ostream &out, Node *t);

public:
    Node* NewRoot(int nodetype, int type_type, int valuetype, NodeAttr attr, Node* child1 = NULL, Node* child2 = NULL, Node* child3 = NULL, Node* child4 = NULL);
    void get_label(void);
    void gen_code(ostream &out);
};

#endif