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
    TYPE_DEFINE_NODE,
    ID_NODE
};

enum SUB_TYPE{
    NO_SUB_TYPE = 0,PROGRAM,ID_EXPR,CONST_EXPR,COMP_EXPR,POST_INC,POST_DEC,PRE_INC,PRE_DEC,POSITIVE,
    NEGATIVE,BNOT,LNOT,MUL_OP,DIV_OP,MOD_OP,ADD_OP,
    SUB_OP,LSHIFT,RSHIFT,GREATER,LESS,GREATEREQ,LESSEQ,EQUAL,
    NEQUAL,BAND,BXOR,BOR,LAND,LOR,ASSIGN_EXPR,COMMA_EXPR,DECLARE,
    INIT_DECL_LIST,INIT_DECL,VOID_DECL,CHAR_DECL,INT_DECL,BOOL_DECL,
    COMP_STMT,STMTS,EXPR_STMT,IF_STMT,IF_ELSE_STMT,WHILE_STMT,DO_WHILE_STMT,FOR_STMT,
    CONTINUE_OP,BREAK_OP,RETURN_OP,INPUT_OP,PRINT_OP
};


enum {
    Notype = 0,
    Integer,
    Boolean,
    Character,
    Void
};

union NodeAttr {
    int vali;
    char valc;
    bool valb;
    
    int symbtl_seq;

    NodeAttr(void) {vali = 0;}
    NodeAttr(int i) {vali = i;}
    NodeAttr(char c) {valc = c;}
    NodeAttr(bool b) {valb = b;}
};

struct Label {
    string true_label;
    string false_label;
    string begin_label;
    string next_label;
};

class Node {
public:
    vector<Node*> children;
    int lineno;
    int nodetype; // 节点种类
    int subtype; // 节点子种类
    int valuetype; // 结点属性的种类
    NodeAttr attr; // 结点属性的具体值
    int seq; // 节点在语法树中的序号
    int temp_var;
    Label label;

    void output(void);
    void setChildValuetype(int v);
};

class Tree {
private:
    Node *root;
    static int node_seq; 
    static int temp_var_seq;
    static int label_seq;

    
    void type_check(Node *t);
    void get_temp_var(Node *t);
    
    string new_label(void);
    void recursive_get_label(Node *t);
    void stmt_get_label(Node *t);
    void expr_get_label(Node *t);
    void gen_header(ostream &out);
    void gen_data(ostream &out);
    void recursive_gen_code(ostream &out, Node *t);
    void stmt_gen_code(ostream &out, Node *t);
    void expr_gen_code(ostream &out, Node *t);
    void get_name(ostream &out, Node *t);

public:
    Node* NewRoot(int nodetype, int subtype, int valuetype, NodeAttr attr, Node* child1 = NULL, Node* child2 = NULL, Node* child3 = NULL, Node* child4 = NULL);
    void get_label(void);
    void gen_code(ostream &out);
    void type_check_all(Node* node);
};

#endif