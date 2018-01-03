#include <iostream>
#include <cstring>
#include "newTree.h"
#include "symbol.h"

using namespace std;

extern int lineno;
extern symbol_table symbtl;

Tree parse_tree;

int Tree::node_seq = 0;
int Tree::temp_var_seq = 0;
int Tree::label_seq = 0;

void Node::output(void) {
    
}

Node* Tree::NewRoot(int nodetype, int subtype, int valuetype, NodeAttr attr, Node* child1, Node* child2, Node* child3, Node* child4) {
    Node *t = new Node();
    if (NULL == t)
        cerr << "Out memory at line %d\n" << lineno;
    else {
        t->nodetype = nodetype;
        t->subtype = subtype;
        t->valuetype = valuetype;
        t->children.push_back(child1);
        t->children.push_back(child2);
        t->children.push_back(child3);
        t->children.push_back(child4);
        t->lineno = lineno;
        t->seq = Tree::node_seq++;
        root = t;
        type_check(t);
        get_temp_var(t);
    }
    return t;
}

void Tree::type_check(Node *t) {
    if (t->valuetype != Notype)
        return;
    if (t->nodetype == STMT_NODE) {
        if (t->type_check == IF_STMT || t->subtype == WHILE_STMT)
            if (t->children[0]->type != Boolean) {
                cerr << "Bad boolean type at line: " << t->lineno << endl;
                exit(1);
            } else
                return;
    }
    if (t->nodetype != EXPR_NODE)
        return;
    if (t->subtype != BINARY_EXPR && t->subtype != UNARY_EXPR)
        return;
    switch(t->subtype) {
        case BINARY_EXPR: {
            Node *arg1 = t->children[0];
            Node *arg2 = t->children[1];
            switch(t->attr.op) {
                case RIGHT_OP:
                case LEFT_OP: {
                    if(arg1->valuetype != Integer || arg2->valuetype != Integer) {
                        cerr << "Bad type at line: " << t->lineno << endl;
                        exit(1);
                    }
                    t->valuetype = arg1->valuetype;
                    break;
                }
                case AND_OP:
                case OR_OP: {
                    if (arg1->valuetype != Boolean || arg2->valuetype != Boolean) {
                        cerr << "Bad type at line: " << t->lineno << endl;
                        exit(1);
                    }
                    t->valuetype = arg1->valuetype;
                    break;
                }
                case LE_OP:
                case GE_OP:
                case EQ_OP:
                case NE_OP: {
                    if (arg1->valuetype != arg2->valuetype) {
                        cerr << "Bad type at line: " << t->lineno << endl;
                        exit(1);
                    }
                    t->valuetype = Boolean;
                    break;
                }
                case AND:
                case XOR:
                case OR:
                case ADD:
                case SUB:
                case MUL:
                case DIV:
                case MOD: {
                    if (arg1->valuetype != Integer || arg2->valuetype != Integer) {
                        cerr << "Bad type at line: " << t->lineno << endl;
                        exit(1);
                    }
                    t->valuetype = arg1->valuetype;
                    break;
                }
                default: {
                    cerr << "Unknown binary operation at line: " << t->lineno << endl;
                    exit(1);
                }
            }
        }
        case UNARY_EXPR: {
            Node *arg1 = t->children[0];
            switch(t->attr.op) {
                case INC_OP:
                case DEC_OP:
                case NOT:
                case TLIDE:
                case SUB: {
                    if (arg1->valuetype != Integer) {
                        cerr << "Bad type at line: " << t->lineno << endl;
                        exit(1);
                    }
                    t->valuetype = arg1.valuetype;
                    break;
                }
                default: {
                    cerr << "Unknown unary operation at line: " << t->lineno << endl;
                    exit(1);
                }
            }
        }
        default:
            return;
    }
    return;
}

void Tree::get_temp_var(Node* t) {
    if (t->nodetype != EXPR_NODE)
        return;
    
    Node *arg1 = t->children[0];
    Node *arg2 = t->children[1];

    if (arg1->subtype == OP_EXPR)
        temp_var_seq--;
    if (arg2 && arg2->subtype == OP_EXPR)
        temp_var_seq--;
    t->temp_var = Tree::temp_var_seq;
    Tree::temp_var_seq++;
}

// char* Tree::new_label(void) {
//     char tmp[20];

//     sprintf(tmp, "@%d", Tree::label_seq);
//     Tree::label_seq++;
//     return tmp;
// }

// void Tree::stmt_get_label(Node *t) {
//     switch(t->subtype) {
//         case COMP_STMT: {

//         }
//         case IF_STMT: {

//         }
//         case WHILE_STMT: {

//         }
//     }
// }

// void Tree::expr_get_label(Node *t) {
//     if (t->valuetype != Boolean)
//         return;
//     Node *e1 = t->children[0];
//     Node *e2 = t->children[1];
//     switch(t->attr.op) {
//         case AND: {

//         }
//         case OR: {

//         }
//         case NOT: {

//         }

//         if (e1)
//             recursive_get_label(e1);
//         if (e2)
//             recursive_get_label(e2);
//     }
// }

// void Tree::recursive_get_label(Node *t) {
//     if (t->nodetype == STMT_NODE)
//         stmt_get_label(t);
//     else if (t->nodetype == EXPR_NODE)
//         expr_get_label(t);
    
// }

// void Tree::get_label(void) {
//     Node *p = root;

//     p->label.begin_label = "_start";
//     recursive_get_label(p);
// }

// void Tree::gen_header(ostream &out) {
//     out << "\t.586" << endl;
//     out << "\t.model flat, stdcall" << endl;
//     out << "\toption casemap :none" << endl;
//     out << endl;
    
// }

// void Tree::gen_decl(ostream &out, Node *t) {
//     out << endl << endl << "\t.data" << endl;

//     for(; t->nodetype == DECL_NODE; t = )
// }