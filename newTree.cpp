#include <iostream>
#include <cstring>
#include "newTree.h"
#include "symbol.h"

using namespace std;

extern int lineno;
extern symbol_table symbtl;

Tree parse_tree;

int tree::node_seq = 0;
int tree::temp_var_seq = 0;
int tree::label_seq = 0;

void Node::output(void) {
    
}

void Tree::type_check(Node* t) {

}

void Tree::get_temp_var(Node* t) {

}

char* Tree::new_label() {

}

void Tree::recursive_get_label(Node *t) {

}

void Tree::stmt_get_label(Node *t) {

}

void Tree::expr_get_label(Node *t) {

}

void Tree::gen_header(ostream &out) {

}

void Tree::gen_decl(ostream &out, Node *t) {

}

void Tree::recursive_gen_code(ostream &out, Node *t) {

}

void Tree::stmt_gen_code(ostream &out, Node *t) {

}

void Tree::expr_gen_code(ostream &out, Node *t) {

}


Node* Tree::NewRoot(int kind, int kind_kind, NodeAttr attr, int type, vector<Node*> children) {

}

void Tree::get_label() {

}

void gen_code(ostream &out) {
    
}