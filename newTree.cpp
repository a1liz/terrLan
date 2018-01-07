#include <iostream>
#include <string>
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

string nodetypes[] = {"STMT_NODE","EXPR_NODE","DECL_NODE","TYPE_DEFINE_NODE","ID_NODE"};
string subtypes[] = {"NO_SUB_TYPE","PROGRAM","ID_EXPR","CONST_EXPR","COMP_EXPR","POST_INC",
"POST_DEC","PRE_INC","PRE_DEC","POSITIVE",
"NEGATIVE","BNOT","LNOT","MUL_OP","DIV_OP","MOD_OP","ADD_OP",
"SUB_OP","LSHIFT","RSHIFT","GREATER","LESS","GREATEREQ","LESSEQ","EQUAL",
"NEQUAL","BAND","BXOR","BOR","LAND","LOR","ASSIGN_EXPR","COMMA_EXPR","DECLARE",
"INIT_DECL_LIST","INIT_DECL","VOID_DECL","CHAR_DECL","INT_DECL","BOOL_DECL",
"COMP_STMT","STMTS","EXPR_STMT","IF_STMT","IF_ELSE_STMT","WHILE_STMT","DO_WHILE_STMT","FOR_STMT",
"CONTINUE_OP","BREAK_OP","RETURN_OP","INPUT_OP","PRINT_OP"};
string valuetypes[] = {"Notype","Integer","Boolean","Character","Void"};

void Node::output(void) {
    cout.setf(ios_base::left);
	cout.width(2);
	cout << seq << ": ";
    
	
    cout.width(20);
    cout << nodetypes[nodetype] + ',';
    cout.width(10);
    cout << subtypes[subtype] + ',';
    cout.width(10);
    cout << valuetypes[valuetype] + ",";
    cout.width(10);
	

	cout << "Children: ";
	for (int i = 0; i < MAX_CHILDREN; i++) {
		if (NULL == children[i])
			break;
		else
		{
			cout << children[i]->seq << " ";
		}
    }

	cout << endl;
}

void Node::setChildValuetype(int v) {
    valuetype = v;
    int i = 0;
    while(children[i] != NULL) {
        children[i]->setChildValuetype(v);
        i++;
    }
    if (nodetype == ID_NODE) {
        symbtl.settype(attr.symbtl_seq,v);
    }

}


Node* Tree::NewRoot(int nodetype, int subtype, int valuetype, NodeAttr attr, Node* child1, Node* child2, Node* child3, Node* child4) {
    Node *t = new Node();
    if (NULL == t)
        cerr << "Out memory at line %d\n" << lineno;
    else {
        t->nodetype = nodetype;
        t->subtype = subtype;
        t->attr = attr;
        t->valuetype = valuetype;
        t->children.push_back(child1);
        t->children.push_back(child2);
        t->children.push_back(child3);
        t->children.push_back(child4);
        t->lineno = lineno;
        t->seq = Tree::node_seq++;
        t->label.begin_label = "";
		t->label.next_label = "";
		t->label.true_label = "";
		t->label.false_label = "";
        root = t;
        get_temp_var(t);
        
		t->output();
    }
    return t;
}

void Tree::type_check(Node *t) {
    if (t->valuetype != Notype)
        return;
    if (t->nodetype == STMT_NODE) {
        if (t->subtype == IF_STMT || t->subtype == IF_ELSE_STMT || t->subtype == WHILE_STMT)
            if (t->children[0]->valuetype != Boolean) {
                cerr << "Bad boolean type at line: " << t->lineno << endl;
                exit(1);
            } else
                return;
    }
    if ((t->nodetype != EXPR_NODE) && (t->nodetype != ID_NODE))
        return;
    if (t->subtype < POST_INC || t->subtype > ASSIGN_EXPR)
        return;
    switch(t->subtype) {
        case POST_INC:
        case POST_DEC:
        case PRE_INC:
        case PRE_DEC:
        case POSITIVE:
        case NEGATIVE:
        case BNOT:{
            Node *arg1 = t->children[0];
            if (arg1->valuetype != Integer) {
                        cerr << "Bad type at line: " << t->lineno << endl;
                        exit(1);
                    }
            t->valuetype = arg1->valuetype;
            break;
        }
        case LNOT:{
            Node *arg1 = t->children[0];
            if (arg1->valuetype != Boolean) {
                        cerr << "Bad type at line: " << t->lineno << endl;
                        exit(1);
                    }
            t->valuetype = arg1->valuetype;
            break;
        }

        case MUL_OP:
        case DIV_OP:
        case MOD_OP:
        case ADD_OP:
        case SUB_OP:
        case LSHIFT:
        case RSHIFT:
        case GREATER:
        case LESS:
        case GREATEREQ:
        case LESSEQ:
        case EQUAL:
        case NEQUAL:
        case BAND:
        case BXOR:
        case BOR: {
            Node *arg1 = t->children[0];
            Node *arg2 = t->children[1];
            if (arg1->valuetype != Integer || arg2->valuetype != Integer) {
                cerr << "Bad type at line: " << t->lineno << endl;
                exit(1);
            }
            break;
        }
        case LAND:
        case LOR: {
            Node *arg1 = t->children[0];
            Node *arg2 = t->children[1];
            if (arg1->valuetype != Boolean || arg2->valuetype != Boolean) {
                cerr << "Bad type at line: " << t->lineno << endl;
                exit(1);
            }
            break;
        }
        case ASSIGN_EXPR: {
            Node *arg1 = t->children[0];
            Node *arg2 = t->children[1];
            if (arg1->valuetype != arg2->valuetype) {
                cerr << "Bad type at line: " << t->lineno << endl;
                exit(1);
            }
            break;
        }
        default:
            break;
    }
    return;
}

void Tree::get_temp_var(Node* t) {
    if (t->nodetype != EXPR_NODE)
        return;
    
    Node *arg1 = t->children[0];
    Node *arg2 = t->children[1];

    if ((arg1->subtype >= POST_INC) && (arg1->subtype <= LOR))
        Tree::temp_var_seq--;
    if (arg2 && (arg2->subtype >= POST_INC) && (arg2->subtype <= LOR))
        Tree::temp_var_seq--;
    t->temp_var = Tree::temp_var_seq;
    Tree::temp_var_seq++;
}

void Tree::type_check_all(Node* node) {
    int i = 0;
    cout << "type_checking node #" << node->seq << "\n";
    type_check(node);
    while(node->children[i] != NULL) {
        type_check_all(node->children[i]);
        i++;
    }
}


string Tree::new_label(void) {
    char tmp[20];

    sprintf(tmp, "@%d", Tree::label_seq);
    Tree::label_seq++;
    return tmp;
}

void Tree::stmt_get_label(Node *t) {
    switch(t->subtype) {
        case COMP_STMT: {
			Node *s = t->children[0];
			if (t->label.begin_label == "")
				t->label.begin_label = new_label();
			if(t->label.next_label == "")
				t->label.next_label = new_label();
			if (s) {
				s->label.begin_label = t->label.begin_label;
				recursive_get_label(s);
			}
			break;
		}
        case STMTS: {
			Node *s1 = t->children[0];
			Node *s2 = t->children[1];
			if (s1)
				recursive_get_label(s1);
			if (s2)
				recursive_get_label(s2);
			break;
		}
        case EXPR_STMT: {
			Node *s = t->children[0];
			if(s) {
				s->label.true_label = t->label.true_label;
				s->label.false_label = t->label.false_label;
				recursive_get_label(s);
			}
			break;
		}
        case IF_STMT:
        case IF_ELSE_STMT: {
            Node *e = t->children[0];
            Node *s1 = t->children[1];
            Node *s2 = t->children[2];

            e->label.true_label = new_label();
			
            if (t->label.next_label == "")
				t->label.next_label = new_label();
			s1->label.next_label = t->label.next_label;
			
			if (s2)
			{
				e->label.false_label = new_label();
				s2->label.next_label = t->label.next_label;
			}
			else
			{
				e->label.false_label = t->label.next_label;
			}
			recursive_get_label(e);
			recursive_get_label(s1);
			if (s2)
				recursive_get_label(s2);
			break;
        }
        case WHILE_STMT: {
			Node *e = t->children[0];
			Node *s = t->children[1];
			
			if (t->label.begin_label == "")
				t->label.begin_label = new_label();
			if (t->label.next_label == "")
				t->label.next_label = new_label();
			e->label.true_label = new_label();
			e->label.false_label = t->label.next_label;
			s->label.begin_label = e->label.true_label;
			s->label.next_label = t->label.begin_label;
			recursive_get_label(e);
			recursive_get_label(s);
			break;
		}
        case DO_WHILE_STMT: {
			Node *s = t->children[0];
			Node *e = t->children[1];

			
			if (t->label.begin_label == "")
				t->label.begin_label = new_label();
			if (t->label.next_label == "")
				t->label.next_label = new_label();
			e->label.true_label = new_label();
			e->label.false_label = t->label.next_label;
			recursive_get_label(e);
			recursive_get_label(s);
			break;
		}
        case FOR_STMT: {
			Node *s1 = t->children[0];
			Node *e = t->children[1];
			Node *s2 = t->children[2];
			Node *s3 = t->children[3];

			if (t->label.begin_label == "")
				t->label.begin_label = new_label();
			if (t->label.next_label == "")
				t->label.next_label = new_label();
			e->label.true_label = new_label();
			e->label.false_label = t->label.next_label;
			s3->label.begin_label = e->label.true_label;
			
			recursive_get_label(s3);
			recursive_get_label(e);
			recursive_get_label(s1);
			recursive_get_label(s2);
			

			break;
		}
		
       	case PROGRAM: {
			Node *s = t->children[0];
			if (s) {
				recursive_get_label(s);
			}
			break;
		}
    }
}

void Tree::expr_get_label(Node *t) {
    if (t->valuetype != Boolean)
        return;
    Node *e1 = t->children[0];
    Node *e2 = t->children[1];
    switch(t->subtype) {
        case LAND: {
			e1->label.true_label = new_label();
			e2->label.true_label = t->label.true_label;
			e1->label.false_label = e2->label.false_label = t->label.false_label;
			break;
        }
        case LOR: {
			e1->label.true_label = e2->label.true_label = t->label.true_label;
			e1->label.false_label = new_label();
			e2->label.false_label = t->label.false_label;
			break;
        }
        case LNOT: {
			e1->label.true_label = t->label.false_label;
			e1->label.false_label = t->label.true_label;
			break;
		}
		case GREATER:
		case LESS:
		case GREATEREQ:
		case LESSEQ:
		case EQUAL:
		case NEQUAL: {
			break;
		}
	}
	if (e1)
		recursive_get_label(e1);
	if (e2)
		recursive_get_label(e2);
}

void Tree::recursive_get_label(Node *t) {
    if (t->nodetype == STMT_NODE)
        stmt_get_label(t);
    else if (t->nodetype == EXPR_NODE)
        expr_get_label(t);
    
}

void Tree::get_label(void) {
    Node *p = root;

    p->label.begin_label = "start";
    recursive_get_label(p);
}

void Tree::gen_header(ostream &out) {
    out << ".586" << endl;
    out << ".model flat, stdcall" << endl;
    out << "option casemap :none" << endl;
    out << endl;
    out << "__UNICODE__ equ 1" << endl;
    out << "include \\masm32\\include\\windows.inc" << endl;
    out << "include \\masm32\\macros\\macros.asm" << endl;
    out << "include \\masm32\\include\\msvcrt.inc" << endl;
    out << "include \\masm32\\include\\gdi32.inc" << endl;
    out << "include \\masm32\\include\\user32.inc" << endl;
    out << "include \\masm32\\include\\kernel32.inc" << endl;
    out << "include \\masm32\\include\\masm32.inc" << endl;
    out << endl;
    out << "includelib \\masm32\\lib\\gdi32.lib" << endl;
    out << "includelib \\masm32\\lib\\msvcrt.lib" << endl;
    out << "includelib \\masm32\\lib\\user32.lib" << endl;
    out << "includelib \\masm32\\lib\\kernel32.lib" << endl;
    out << "includelib \\masm32\\lib\\masm32.lib" << endl;
}


void Tree::stmt_gen_code(ostream &out, Node *t)
{
	switch(t->subtype) {
		case PROGRAM: {
			out << t->label.begin_label << ":" << endl;
			for (int i = 0; t->children[i]; i++)
			{
				recursive_gen_code(out, t->children[i]);
			}
			break;
		}
		case STMTS:
		case DECLARE:
		case INIT_DECL_LIST:
		case EXPR_STMT: {
			for (int i = 0; t->children[i]; i++)
			{
				recursive_gen_code(out, t->children[i]);
			}
			break;
		}
		case COMP_STMT: {
			out << t->label.begin_label << ":" << endl;
			for (int i = 0; t->children[i]; i++)
			{
				recursive_gen_code(out, t->children[i]);
			}
			break;
		}
		case IF_STMT: {
			recursive_gen_code(out, t->children[0]);
			out << t->children[0]->label.true_label << ":" << endl;
			recursive_gen_code(out, t->children[1]);
			out << t->label.next_label << ":" << endl;
			break;
		}

		case IF_ELSE_STMT: {
			recursive_gen_code(out, t->children[0]);
			out << t->children[0]->label.true_label << ":" << endl;
			recursive_gen_code(out, t->children[1]);
			out << "\tJMP" << t->label.next_label << endl;
			out << t->children[0]->label.false_label << ":" << endl;
			recursive_gen_code(out, t->children[2]);
			out << t->label.next_label << ":" << endl;
			out << endl;
			break;
		}
		case WHILE_STMT: {
			out << t->label.begin_label << ":" << endl;
			recursive_gen_code(out, t->children[0]);
			out << t->children[0]->label.true_label << ":" << endl;
			recursive_gen_code(out, t->children[1]);
			out << "\tJMP " << t->label.begin_label << endl;
			out << t->label.next_label << ":" << endl;
			out << endl;
			break;
		}
		case DO_WHILE_STMT: {
			out << t->label.begin_label << ":" << endl;
			recursive_gen_code(out, t->children[0]);
			recursive_gen_code(out, t->children[1]);
			out << t->label.next_label << ":" << endl;
			out << endl;
			break;
		}
		case FOR_STMT: {
			recursive_gen_code(out, t->children[0]);
			out << t->label.begin_label << ":" << endl;
			recursive_gen_code(out, t->children[1]);
			recursive_gen_code(out, t->children[3]);
			recursive_gen_code(out, t->children[2]);
			out << "\tJMP " << t->label.begin_label << endl;
			out << t->label.next_label << ":" << endl;
			out << endl;
			break;
		}
		case CONTINUE_OP: {
			break;
		}
		case BREAK_OP: {
			break;
		}
		case RETURN_OP: {
			break;
		}
		case PRINT_OP: {
			Node *child = t->children[0];
			if(child->nodetype == ID_NODE) {
				if(child->valuetype == Integer) {
					out << "\tINVOKE crt_printf, ADDR $Int_Fmt_Output, ";
					get_name(out,child);
					out << endl;
				}
				if(child->valuetype == Character) {
					out << "INVOKE crt_printf, ADDR $Char_Fmt_Output, ";
					get_name(out,child);
					out << endl;
				}
			}
			else if (child->subtype == CONST_EXPR){
				// todo : 输出常量
				if(child->valuetype == Integer)
					out << "\tINVOKE crt_printf, ADDR $Int_Fmt_Output, " << child->attr.vali << endl;
				if(child->valuetype == Character)
					out << "\tINVOKE crt_printf, ADDR $Char_Fmt_Output, " << child->attr.valc << endl;
			}
			return;
		}
		case INPUT_OP: {
			Node *child = t->children[0];                
			if(child->valuetype == Integer) {
				out << "\tINVOKE crt_scanf, ADDR $Int_Fmt_Input, ADDR ";
				get_name(out,child);
				out << endl;
				return;
			}
			if(child->valuetype == Character) {
				out << "\tINVOKE crt_scanf, ADDR $Char_Fmt_Input, ADDR ";
				get_name(out,child);
				out << endl;
				return;
			}
			return;
		} 

	}
}

void Tree::expr_gen_code(ostream &out, Node *t)
{
	Node *e1 = t->children[0];
	Node *e2 = t->children[1];
	switch(t->subtype) {
		case POST_INC: {
			Node *child = t->children[0];
			recursive_gen_code(out,child);
			out << "\tMOV eax, " ; get_name(out,child);out << endl;
			out << "\tMOV " ;
			get_name(out,t);
			out << ", eax" << endl;
			out << "\tINC eax" << endl;
			out << "\tMOV ";
			get_name(out,child);
			out << ", eax" << endl;
			out << endl;
			break;
		}
		case POST_DEC: {
			Node *child = t->children[0];
			recursive_gen_code(out,child);
			out << "\tMOV eax, ";get_name(out,child);out << endl;
			out << "\tMOV "; get_name(out,t);out << ", eax" << endl;
			out << "\tDEC eax" << endl;
			out << "\tMOV "; get_name(out,child);out << ", eax" << endl;
			out << endl;
			break;
		}
		case PRE_INC: {
			Node *child = t->children[0];
			recursive_gen_code(out,child);
			out << "\tMOV eax, "; get_name(out,child);out << endl;
			out << "\tINC eax" << endl;
			out << "\tMOV " ;get_name(out,t);out << ", eax" << endl;
			out << "\tMOV " ; get_name(out,child);out << ", eax" << endl;
			out << endl;
			break;
		}
		case PRE_DEC: {
			Node *child = t->children[0];
			recursive_gen_code(out,child);
			out << "\tMOV eax, " ; get_name(out,child);out << endl;
			out << "\tDEC eax" << endl;
			out << "\tMOV " ; get_name(out,t);out << ", eax" << endl;
			out << "\tMOV " ; get_name(out,child);out << ", eax" << endl;
			out << endl;
			break;
		}
		case POSITIVE: {
			Node *child = t->children[0];
			recursive_gen_code(out,child);
			break;
		}
		case NEGATIVE: {
			Node *child = t->children[0];
			recursive_gen_code(out,child);
			out << "\tMOV eax, " ; get_name(out,child);out << endl;
			out << "\tXOR ecx, ecx" << endl;
			out << "\tSUB ecx, eax" << endl;
			out << "\tMOV " ; get_name(out,t);out << ", ecx" << endl;
			out << endl;
			break;
		}
		case BNOT: {
			Node *child = t->children[0];
			recursive_gen_code(out,child);
			out << "\tMOV eax, " ; get_name(out,child);out << endl;
			out << "\tNOT eax" << endl;
			out << "\tMOV " ; get_name(out,t);out << ", eax" << endl;
			out << endl;
			break;
		}
		case MUL_OP: {
			Node *child1 = t->children[0];
			Node *child2 = t->children[1];
			recursive_gen_code(out,child1);
			recursive_gen_code(out,child2);
			out << "\tMOV eax, " ; get_name(out,child1);out << endl;
			out << "\tMOV ebx, " ; get_name(out,child2);out << endl;
			out << "\tIMUL ebx" << endl;
			out << "\tMOV " ; get_name(out,t);out << ", eax" << endl;
			out << endl;
			break;
		}
		case DIV_OP: {
			Node *child1 = t->children[0];
			Node *child2 = t->children[1];
			recursive_gen_code(out,child1);
			recursive_gen_code(out,child2);
			out << "\tMOV eax, " ; get_name(out,child1);out << endl;
			out << "\tMOV ebx, " ; get_name(out,child2);out << endl;
			out << "\tIDIV ebx" << endl;
			out << "\tMOV " ; get_name(out,t);out << ", eax" << endl;
			out << endl;
			break;
		}
		case MOD_OP: {
			Node *child1 = t->children[0];
			Node *child2 = t->children[1];
			recursive_gen_code(out,child1);
			recursive_gen_code(out,child2);
			out << "\tMOV eax, " ; get_name(out,child1);out << endl;
			out << "\tMOV ebx, " ; get_name(out,child2);out << endl;
			out << "\tIMUL ebx" << endl;
			out << "\tMOV " ; get_name(out,t);out << ", edx" << endl;
			out << endl;
			break;
		}
		case ADD_OP: {
			Node *child1 = t->children[0];
			Node *child2 = t->children[1];
			recursive_gen_code(out,child1);
			recursive_gen_code(out,child2);
			out << "\tMOV eax, " ; get_name(out,child1);out << endl;
			out << "\tMOV ecx, " ; get_name(out,child2);out << endl;
			out << "\tADD eax, ecx" << endl;
			out << "\tMOV " ; get_name(out,t);out << ", eax" << endl;
			out << endl;
			break;
		}
		case SUB_OP: {
			Node *child1 = t->children[0];
			Node *child2 = t->children[1];
			recursive_gen_code(out,child1);
			recursive_gen_code(out,child2);
			out << "\tMOV eax, " ; get_name(out,child1);out << endl;
			out << "\tMOV ecx, " ; get_name(out,child2);out << endl;
			out << "\tSUB eax, ecx" << endl;
			out << "\tMOV " ; get_name(out,t);out << ", eax" << endl;
			out << endl;
			break;
		}
		case LSHIFT: {
			Node *child1 = t->children[0];
			Node *child2 = t->children[1];
			recursive_gen_code(out,child1);
			recursive_gen_code(out,child2);
			out << "\tMOV eax, " ; get_name(out,child1);out << endl;
			out << "\tMOV ecx, " ; get_name(out,child2);out << endl;
			out << "\tSAL eax, ecx" << endl;
			out << "\tMOV " ; get_name(out,t);out << ", eax" << endl;
			out << endl;
			break;
		}
		case RSHIFT: {
			Node *child1 = t->children[0];
			Node *child2 = t->children[1];
			recursive_gen_code(out,child1);
			recursive_gen_code(out,child2);
			out << "\tMOV eax, " ; get_name(out,child1);out << endl;
			out << "\tMOV ebx, " ; get_name(out,child2);out << endl;
			out << "\tSAR eax, ecx" << endl;
			out << "\tMOV " ; get_name(out,t);out << ", eax" << endl;
			out << endl;
			break;
		}
		case GREATER: {
			Node *child1 = t->children[0];
			Node *child2 = t->children[1];
			recursive_gen_code(out,child1);
			recursive_gen_code(out,child2);
			out << "\tMOV eax, " ; get_name(out,child1);out << endl;
			out << "\tMOV ecx, " ; get_name(out,child2);out << endl;
			out << "\tCMP eax, ecx" << endl;
			out << "\tJG " << t->label.true_label << endl;
			out << "\tJMP " << t->label.false_label << endl;
			out << endl;
			break;
		}
		case LESS: {
			Node *child1 = t->children[0];
			Node *child2 = t->children[1];
			recursive_gen_code(out,child1);
			recursive_gen_code(out,child2);
			out << "\tMOV eax, " ; get_name(out,child1);out << endl;
			out << "\tMOV ecx, " ; get_name(out,child2);out << endl;
			out << "\tCMP eax, ecx" << endl;
			out << "\tJL " << t->label.true_label << endl;
			out << "\tJMP " << t->label.false_label << endl;
			out << endl;
			break;
		}
		case GREATEREQ: {
			Node *child1 = t->children[0];
			Node *child2 = t->children[1];
			recursive_gen_code(out,child1);
			recursive_gen_code(out,child2);
			out << "\tMOV eax, " ; get_name(out,child1);out << endl;
			out << "\tMOV ecx, " ; get_name(out,child2);out << endl;
			out << "\tCMP eax, ecx" << endl;
			out << "\tJGE " << t->label.true_label << endl;
			out << "\tJMP " << t->label.false_label << endl;
			out << endl;
			break;
		}
		case LESSEQ: {
			Node *child1 = t->children[0];
			Node *child2 = t->children[1];
			recursive_gen_code(out,child1);
			recursive_gen_code(out,child2);
			out << "\tMOV eax, " ; get_name(out,child1);out << endl;
			out << "\tMOV ecx, " ; get_name(out,child2);out << endl;
			out << "\tCMP eax, ecx" << endl;
			out << "\tJLE " << t->label.true_label << endl;
			out << "\tJMP " << t->label.false_label << endl;
			out << endl;
			break;
		}
		case EQUAL: {
			Node *child1 = t->children[0];
			Node *child2 = t->children[1];
			recursive_gen_code(out,child1);
			recursive_gen_code(out,child2);
			out << "\tMOV eax, " ; get_name(out,child1);out << endl;
			out << "\tMOV ecx, " ; get_name(out,child2);out << endl;
			out << "\tCMP eax, ecx" << endl;
			out << "\tJE " << t->label.true_label << endl;
			out << "\tJMP " << t->label.false_label << endl;
			out << endl;
			break;
		}
		case NEQUAL: {
			Node *child1 = t->children[0];
			Node *child2 = t->children[1];
			recursive_gen_code(out,child1);
			recursive_gen_code(out,child2);
			out << "\tMOV eax, " ; get_name(out,child1);out << endl;
			out << "\tMOV ecx, " ; get_name(out,child2);out << endl;
			out << "\tCMP eax, ecx" << endl;
			out << "\tJNE " << t->label.true_label << endl;
			out << "\tJMP " << t->label.false_label << endl;
			out << endl;
			break;
		}
		case BAND: {
			Node *child1 = t->children[0];
			Node *child2 = t->children[1];
			recursive_gen_code(out,child1);
			recursive_gen_code(out,child2);
			out << "\tMOV eax, " ; get_name(out,child1);out << endl;
			out << "\tMOV ecx, " ; get_name(out,child2);out << endl;
			out << "\tAND eax, ecx" << endl;
			out << "\tMOV " ; get_name(out,t);out << ", eax" << endl;
			out << endl;
			break;
		}
		case BXOR: {
			Node *child1 = t->children[0];
			Node *child2 = t->children[1];
			recursive_gen_code(out,child1);
			recursive_gen_code(out,child2);
			out << "\tMOV eax, " ; get_name(out,child1);out << endl;
			out << "\tMOV ecx, " ; get_name(out,child2);out << endl;
			out << "\tXOR eax, ecx" << endl;
			out << "\tMOV " ; get_name(out,t);out << ", eax" << endl;
			out << endl;
			break;
		}
		case BOR: {
			Node *child1 = t->children[0];
			Node *child2 = t->children[1];
			recursive_gen_code(out,child1);
			recursive_gen_code(out,child2);
			out << "\tMOV eax, " ; get_name(out,child1);out << endl;
			out << "\tMOV ecx, " ; get_name(out,child2);out << endl;
			out << "\tOR eax, ecx" << endl;
			out << "\tMOV " ; get_name(out,t);out << ", eax" << endl;
			out << endl;
			break;
		}
		case LAND: {
			Node *child1 = t->children[0];
			Node *child2 = t->children[1];
			recursive_gen_code(out,child1);
			out << child1->label.true_label << ":" << endl;
			recursive_gen_code(out,child2);
			break;
		}
		case LOR: {
			Node *child1 = t->children[0];
			Node *child2 = t->children[1];
			recursive_gen_code(out,child1);
			out << child1->label.false_label << ":" << endl;
			recursive_gen_code(out,child2);
			break;
		}
		case ASSIGN_EXPR: {
			Node *child1 = t->children[0];
			Node *child2 = t->children[1];
			recursive_gen_code(out,child1);
			recursive_gen_code(out,child2);
			out << "\tMOV eax, " ; get_name(out,child2);out << endl;
			out << "\tMOV " ; get_name(out,child1);out << ", eax" << endl;
			out << endl;
			break;
		}
		case COMMA_EXPR: {
			Node *child1 = t->children[0];
			Node *child2 = t->children[1];
			recursive_gen_code(out,child1);
			recursive_gen_code(out,child2);
			break;
		}
	}
}

void Tree::recursive_gen_code(ostream &out, Node *t)
{
	if (t->nodetype == STMT_NODE)
	{
		stmt_gen_code(out, t);
	}
	else if (t->nodetype == EXPR_NODE)
	{
		expr_gen_code(out, t);
	}
}

void Tree::gen_code(ostream &out)
{
	gen_header(out);
	gen_data(out);
	out << endl << endl << ".code" << endl;
	get_label();
	recursive_gen_code(out, root);
	if (root->label.next_label != "")
		out << root->label.next_label << ":" << endl;
	out << "\t;invoke ExitProcess, 0" << endl;
	out << "end " << root->label.begin_label << endl;
}

void Tree::gen_data(ostream &out) {
	out << endl << ".data" << endl;
    out << "\t$Int_Fmt_Input db '%d', 0" << endl;
    out << "\t$Int_Fmt_Output db '%d', 13, 10, 0" << endl;
    out << "\t$Char_Fmt_Input db '%c', 0" << endl;
    out << "\t$Char_Fmt_Output db '%c', 13, 10, 0" << endl;
	for (int i = 0; i < symbtl.getsize(); i++) {
		if (symbtl.gettype(i) == Integer)
			out << "\t$" << symbtl.getname(i) << "$ SDWORD ?" <<endl;
		else if (symbtl.gettype(i) == Character)
			out << "\t$" << symbtl.getname(i) << "$ BYTE ?" << endl;
	}
	for (int i = 0; i < Tree::temp_var_seq; i++) {
		out << "\t$tmp" << i << "$ DWORD ?" << endl;
	}
	out << endl;
}

void Tree::get_name(ostream &out, Node *t) {
	if (t->nodetype == ID_NODE) 
		out <<  "$" << symbtl.getname(t->attr.symbtl_seq) << "$";
	else if (t->subtype == CONST_EXPR && t->valuetype == Integer)
		out << t->attr.vali;
	else {
		out << "$tmp" << t->temp_var << "$";
	}
}