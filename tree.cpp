#include "tree.h"
#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>

using namespace std;

const string NodeDescription[] = {
    "program","translation_unit","external_declaration","function_definition","declaration_prefix",
    "special_specifier","type_define","declaration","init_declaration_list","init_declaration",
    "declaration_item","pointer","refer","simple_item","identifier_list","initializer","initializer_list","assignment_expr",
    "condition_expr","logical_expr","bit_expr","equality_expr","relational_expr","shift_expr","add_expr","mul_expr",
    "cast_expr","unary_expr","unary_op","postfix_expr","argument_expr_list","primary_expr","identifier","constant_expr","str_constant",
    "parameter_list","parameter_declaration","compound_statement","compound_statement_list","declaration_list",
    "statement_list","statement","labeled_statement","expr_statement","condtion_statement","expr","loop_statement","jump_statement",
    "operator","keyword","none"
};

Node::Node (int i) {
    id = i;
    children_id.clear();
    nodeType = NONE;
}

Node::Node () {
    children_id.clear();
    nodeType = NONE;
}
Node::~Node() {
    children_id.clear();
}

void Node::addChild(int i) {
    children_id.push_back(i);
}

void Node::print() {
    cout << setiosflags(ios::right);
    cout << setw(4) <<id << "|" << setw(24) << NodeDescription[nodeType] << "|";
    if (value.name == NULL)
        cout << setiosflags(ios::right) << setw(20) << "| ";
    else 
        cout << setiosflags(ios::left) << setw(18) << value.name << "| ";
    cout << " Children: ";
    for (size_t i = 0; i < children_id.size(); i++)
        cout << children_id[i] << " ";
    cout << endl;
}

int Tree::createNode() {
    int id = t.size();
    Node node(id);
    t.push_back(node);
    return id;
}

Node* Tree::getNodeById(int id) {
    return &t[id];
}

int Tree::addNode(NodeType nt, const char* n) {
    int id = createNode();
    Node *node = getNodeById(id);
    node->nodeType = nt;
    int length = 0;
    if (n != NULL) {
        node->value.name = new char[strlen(n) + 1];
        strcpy(node->value.name,n);
    } else {
        node->value.name = NULL;
    }
    return node->id;
}

void Tree::print_tree_node(int id) {
    Node *node = getNodeById(id);
    node->print();
}
