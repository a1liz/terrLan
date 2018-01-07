%{
#include <iostream>
#include <string>
#include <fstream>
#include "newTree.h"
#include <vector>

using namespace std;

static Tree tree;

extern int yylex();
extern void yyerror(char const *);
extern void setyylVal(char * text);
%}

%define api.value.type {Node*}

%token BOOL BREAK CASE CHAR CONTINUE DEFAULT DO ELSE
%token FOR IF INT RETURN SWITCH
%token VOID INPUT PRINT WHILE MAIN TRUE FALSE
%token ID CONSTCHAR NUM 
%token RIGHT_OP LEFT_OP AND_OP OR_OP LE_OP GE_OP
%token EQ_OP NE_OP ADD SUB MUL DIV MOD LT GT AND XOR OR
%token INC_OP DEC_OP NOT TLIDE
%token SEMICOLON LBRACE RBRACE LBRACKET RBRACKET COMMA COLON
%token ASSIGN LPAREN RPAREN QUESTION

%nonassoc IFX
%nonassoc ELSE

%left COMMA
%left OR_OP
%left AND_OP
%left OR
%left XOR
%left AND
%left EQ_OP NE_OP
%left LE_OP GE_OP GT LT
%left RIGHT_OP LEFT_OP
%left ADD SUB
%left MUL DIV MOD

%%
program : MAIN LPAREN RPAREN compound_statement { 
      	$$ = tree.NewRoot(STMT_NODE,PROGRAM,Notype,0,$4);
      	tree.type_check_all($$);
	  	ofstream out = ofstream("test.asm");
    	tree.gen_code(out);
		}
		;

primary_expression : identifier {
            $$ = $1;
					}
					| constant_val {
            $$ = $1;
					}
					| LPAREN expression RPAREN {
            $$ = $2;
					}
					;
					
postfix_expression : primary_expression {
						$$ = $1;
					}
					| postfix_expression INC_OP {
            $$ = tree.NewRoot(EXPR_NODE,POST_INC,$1->valuetype,0,$1);
					}
					| postfix_expression DEC_OP {
            $$ = tree.NewRoot(EXPR_NODE,POST_DEC,$1->valuetype,0,$1);
					}
					;
			
unary_expression : postfix_expression { 
					$$ = $1; 
				}
				| INC_OP postfix_expression {
          $$ = tree.NewRoot(EXPR_NODE,PRE_INC,$2->valuetype,0,$2);
				}
				| DEC_OP postfix_expression {
          $$ = tree.NewRoot(EXPR_NODE,PRE_DEC,$2->valuetype,0,$2);
				} 
				| ADD postfix_expression {
          $$ = tree.NewRoot(EXPR_NODE,POSITIVE,$2->valuetype,0,$2);
				}
				| SUB postfix_expression {
          $$ = tree.NewRoot(EXPR_NODE,NEGATIVE,$2->valuetype,0,$2);
				} 
				| TLIDE postfix_expression {
          $$ = tree.NewRoot(EXPR_NODE,BNOT,$2->valuetype,0,$2);
				}
				| NOT postfix_expression {
          $$ = tree.NewRoot(EXPR_NODE,LNOT,Boolean,0,$2);
				} 
				;

multipy_expression : unary_expression {
					$$ = $1;
				}
				| multipy_expression MUL unary_expression {
          $$ = tree.NewRoot(EXPR_NODE,MUL_OP,$1->valuetype,0,$1,$3);
				}
				| multipy_expression DIV unary_expression {
          $$ = tree.NewRoot(EXPR_NODE,DIV_OP,$1->valuetype,0,$1,$3);
				}
				| multipy_expression MOD unary_expression {
          $$ = tree.NewRoot(EXPR_NODE,MOD_OP,$1->valuetype,0,$1,$3);
				}													
				;

additive_expression : multipy_expression {
					$$ = $1;
				}
				| additive_expression ADD multipy_expression {
          $$ = tree.NewRoot(EXPR_NODE,ADD_OP,$1->valuetype,0,$1,$3);
				}
				| additive_expression SUB multipy_expression {
					$$ = tree.NewRoot(EXPR_NODE,SUB_OP,$1->valuetype,0,$1,$3);
				}
				;				

shift_expression : additive_expression {
					$$ = $1;
				}
				| shift_expression LEFT_OP additive_expression {
					$$ = tree.NewRoot(EXPR_NODE,LSHIFT,$1->valuetype,0,$1,$3);
				}
				| shift_expression RIGHT_OP additive_expression {
          $$ = tree.NewRoot(EXPR_NODE,RSHIFT,$1->valuetype,0,$1,$3);
				}
				;

relation_expression : shift_expression {
					$$ = $1;
				}
				| relation_expression GT shift_expression {
          $$ = tree.NewRoot(EXPR_NODE,GREATER,Boolean,0,$1,$3);
				}
				| relation_expression LT shift_expression {
          $$ = tree.NewRoot(EXPR_NODE,LESS,Boolean,0,$1,$3);
				}
				| relation_expression GE_OP shift_expression {
          $$ = tree.NewRoot(EXPR_NODE,GREATEREQ,Boolean,0,$1,$3);
				}
				| relation_expression LE_OP shift_expression {
          $$ = tree.NewRoot(EXPR_NODE,LESSEQ,Boolean,0,$1,$3);
				}
				;

equal_expression : relation_expression {
					$$ = $1;
				}
				| equal_expression EQ_OP relation_expression {
          $$ = tree.NewRoot(EXPR_NODE,EQUAL,Boolean,0,$1,$3);
				}
				| equal_expression NE_OP relation_expression {
          $$ = tree.NewRoot(EXPR_NODE,NEQUAL,Boolean,0,$1,$3);
				}
				;
		
bit_expression : equal_expression {
					$$ = $1;
				}
				| bit_expression AND equal_expression {
          $$ = tree.NewRoot(EXPR_NODE,BAND,$1->valuetype,0,$1,$3);
				}
        | bit_expression XOR equal_expression {
          $$ = tree.NewRoot(EXPR_NODE,BXOR,$1->valuetype,0,$1,$3);
        }
        | bit_expression OR equal_expression {
          $$ = tree.NewRoot(EXPR_NODE,BOR,$1->valuetype,0,$1,$3);
        }
				;

logical_expression : bit_expression {
					$$ = $1;
				}
				| logical_expression AND_OP bit_expression {
          $$ = tree.NewRoot(EXPR_NODE,LAND,Boolean,0,$1,$3);
				}
        | logical_expression OR_OP bit_expression {
          $$ = tree.NewRoot(EXPR_NODE,LOR,Boolean,0,$1,$3);
        }
				;
						
assignment_expression : logical_expression {
							$$ = $1;
						}
						| unary_expression ASSIGN assignment_expression {
              $$ = tree.NewRoot(EXPR_NODE,ASSIGN_EXPR,$1->valuetype,0,$1,$3);
						}
						;
					
expression : assignment_expression {
				$$ = $1;
			}
			| expression COMMA assignment_expression {
        $$ = tree.NewRoot(EXPR_NODE,COMMA_EXPR,$1->valuetype,0,$1,$3);
			}
			;

declaration : type_define init_declaration_list SEMICOLON {
        $2->setChildValuetype($1->valuetype);
        $$ = tree.NewRoot(STMT_NODE,DECLARE,$1->valuetype,0,$1,$2);
			}
			;

init_declaration_list : init_declaration {
						$$ = $1;
					}
					| init_declaration_list COMMA init_declaration {
            $$ = tree.NewRoot(STMT_NODE,INIT_DECL_LIST,Notype,0,$1,$3);
					}
					;
					
init_declaration : identifier {
					$$ = $1;
				}
				| identifier ASSIGN assignment_expression {
          $$ = tree.NewRoot(EXPR_NODE,ASSIGN_EXPR,$1->valuetype,0,$1,$3);
				}
				;
												
type_define : VOID {
        $$ = tree.NewRoot(DECL_NODE,VOID_DECL,Void,0);
			}
			| CHAR {
        $$ = tree.NewRoot(DECL_NODE,CHAR_DECL,Character,0);
			}
			| INT {
        $$ = tree.NewRoot(DECL_NODE,INT_DECL,Integer,0);
			}
			| BOOL {
        $$ = tree.NewRoot(DECL_NODE,BOOL_DECL,Boolean,0);
			}
			;
	
identifier : ID {
        $$ = tree.NewRoot(ID_NODE,0,$1->valuetype,$1->attr.symbtl_seq);
			}
			;
			
constant_val : NUM {
        $$ = tree.NewRoot(DECL_NODE,CONST_EXPR,Integer,$1->attr.vali);
			}
			| CONSTCHAR {
        $$ = tree.NewRoot(DECL_NODE,CONST_EXPR,Character,$1->attr.valc);
			}
			| TRUE {
        $$ = tree.NewRoot(DECL_NODE,CONST_EXPR,Boolean,true);
			}
			| FALSE {
				$$ = tree.NewRoot(DECL_NODE,CONST_EXPR,Boolean,false);
			}
			;
				
statement : compound_statement { $$ = $1; }
			| expression_statement { $$ = $1; }
			| condition_statement { $$ = $1; }
			| loop_statement { $$ = $1; }
			| jump_statement { $$ = $1; }
			| input_statement { $$ = $1; }
			| print_statement { $$ = $1; }
			| declaration { $$ = $1; }
			;
				
compound_statement : LBRACE RBRACE {
            $$ = tree.NewRoot(STMT_NODE,0,Notype,0);
					}
					| LBRACE statement_list RBRACE {
            $$ = tree.NewRoot(STMT_NODE,COMP_STMT,Notype,0,$2);
					}
					;
				
statement_list : statement {
					$$ = $1;
				}
				| statement_list statement {
          $$ = tree.NewRoot(STMT_NODE,STMTS,Notype,0,$1,$2);
				}
				;
	
expression_statement : SEMICOLON	{
            $$ = tree.NewRoot(STMT_NODE, EXPR_STMT,Notype,0);
					}
					| expression SEMICOLON {
            $$ = tree.NewRoot(STMT_NODE, EXPR_STMT, Notype,0,$1);
					}
					;
					
condition_statement : IF LPAREN expression RPAREN statement %prec IFX {
            $$ = tree.NewRoot(STMT_NODE,IF_STMT,Notype,0,$3,$5);
					}
					| IF LPAREN expression RPAREN statement ELSE statement {
            $$ = tree.NewRoot(STMT_NODE,IF_ELSE_STMT,Notype,0,$3,$5,$7);
					} 
					;
					
loop_statement : WHILE LPAREN expression RPAREN statement {
          $$ = tree.NewRoot(STMT_NODE,WHILE_STMT,Notype,0,$3,$5);
				}
				| DO statement WHILE LPAREN expression RPAREN SEMICOLON {
          $$ = tree.NewRoot(STMT_NODE,DO_WHILE_STMT,Notype,0,$2,$5);
				}
				| FOR LPAREN expression_statement expression_statement expression RPAREN statement {
					$$ = tree.NewRoot(STMT_NODE,FOR_STMT,Notype,0,$3,$4,$5,$7);
				}
				| FOR LPAREN declaration expression_statement expression RPAREN statement {
					$$ = tree.NewRoot(STMT_NODE,FOR_STMT,Notype,0,$3,$4,$5,$7);
				}
				;
				
jump_statement : CONTINUE SEMICOLON {
          $$ = tree.NewRoot(STMT_NODE,CONTINUE_OP,Notype,0);
				}
				| BREAK SEMICOLON {
          $$ = tree.NewRoot(STMT_NODE,BREAK_OP,Notype,0);
				}
				| RETURN SEMICOLON {
          $$ = tree.NewRoot(STMT_NODE,RETURN_OP,Void,0);
				}
				| RETURN expression SEMICOLON {
          $$ = tree.NewRoot(STMT_NODE,RETURN_OP,$2->valuetype,0,$2);
				}
				;

input_statement : INPUT LPAREN identifier RPAREN {
        $$ = tree.NewRoot(STMT_NODE,INPUT_OP,Notype,0,$3);
			}
			;

print_statement : PRINT LPAREN expression RPAREN {
        $$ = tree.NewRoot(STMT_NODE,PRINT_OP,Notype,0,$3);
			}
			;

%%

#ifndef YYERROR_FUNC
#define YYERROR_FUNC
#include <stdio.h>

/* Called by yyparse on error.  */
void
yyerror (char const *s)
{
  fprintf (stderr, "%s\n", s);
}
#endif