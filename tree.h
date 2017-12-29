#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <vector>
using namespace std;


#ifndef TREE_H
#define TREE_H
union Con{
    char* name;
    int integerNum;
    double doubleNum;
    float floatNum;
    char character;
    char* str;
    bool boolean;    
};


extern const string NodeDescription[];

enum NodeType {
    PROGRAM,TRANSLATION_UNIT,EXTERNAL_DECLARATION,FUNCTION_DEFINITION,DECLARATION_PREFIX,SPECIAL_SPECIFIER,
    TYPE_DEFINE,DECLARATION,INIT_DECLARATION_LIST,INIT_DECLARATION,DECLARATION_ITEM,POINTER,REFER,
    SIMPLE_ITEM,IDENTIFIER_LIST,INITIALIZER,INITIALIZER_LIST,ASSIGNMENT_EXPR,CONDITION_EXPR,LOGICAL_EXPR,BIT_EXPR,
    EQUALITY_EXPR,RELATIONAL_EXPR,SHIFT_EXPR,ADD_EXPR,MUL_EXPR,CAST_EXPR,UNARY_EXPR,UNARY_OP,
    POSTFIX_EXPR,ARGUMENT_EXPR_LIST,PRIMARY_EXPR,IDENTIFIER,CONSTANT_EXPR,STRING_CONSTANT,PARAMETER_LIST,PARAMETER_DECLARATION,
    COMPOUND_STATEMENT,COMPOUND_STATEMENT_LIST,DECLARATION_LIST,STATEMENT_LIST,STATEMENT,LABELED_STATEMENT,
    EXPR_STATEMENT,CONDITION_STATEMENT,EXPR,LOOP_STATEMENT,JUMP_STATEMENT,OPERATOR,KEYWORD,NONE
};

struct NodeAttr{
    int node;
    char *text;
};

class Node {
public:
    int id;
    union Con value;
    NodeType nodeType;
    vector<int> children_id;

    Node();
    Node(int);
    ~Node();
    void addChild(int);
    void print();
};

class Tree {
public:
    vector<Node> t;

    int createNode();
    Node* getNodeById(int);
    int addNode(NodeType, const char* name = NULL);
    void print_tree_node(int);
};
#endif