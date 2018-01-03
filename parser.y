%{
#include <iostream>
#include <string>
#include <fstream>
#include "tree.h"
#include <vector>

using namespace std;

static Tree tree;

extern int yylex();
extern void yyerror(char const *);
extern void setyylVal(char * text);
%}

%define api.value.type {NodeAttr}

%token BOOL BREAK CASE CHAR CONTINUE DEFAULT DO DOUBLE ELSE
%token FLOAT FOR IF INT RETURN SWITCH
%token VOID WHILE TRUE FALSE
%token ID CONSTCHAR NUM 
%token RIGHT_ASSIGN LEFT_ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN
%token MOD_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN
%token RIGHT_OP LEFT_OP INC_OP DEC_OP AND_OP OR_OP LE_OP GE_OP
%token EQ_OP NE_OP

%left COMMA
%right LEFT_ASSIGN RIGHT_ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN 
%right MOD_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN
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
program : translation_unit {
                                
                                }
        ;

translation_unit    :   external_declaration {
                                                
                                                }
                    |   translation_unit external_declaration {
                                                                }
                    ;

external_declaration    :   function_definition {
                                               }
                        |   declaration {
                                         }
                        ;

function_definition     :       type_define identifier LPAREN parameter_list RPAREN compound_statement {
                                                                                                              
                                                                                                }
                        |       type_define identifier LPAREN RPAREN compound_statement {
                                                                                                            
                                                                                                }
                        ;

type_define :   VOID    {}
            |   CHAR    {}
            |   INT     {}
            |   DOUBLE  {}
            |   BOOL    {}
            |   FLOAT   {}
            ;

declaration :  declaration_prefix init_declaration_list SEMICOLON { 
                                                                }
            ;

init_declaration_list   :   init_declaration {}
                        |   init_declaration_list COMMA init_declaration {$$.node = tree.addNode(INIT_DECLARATION_LIST); Node *node = tree.getNodeById($$.node); node->addChild($1.node); node->addChild($3.node); tree.print_tree_node($$.node);}
                        ;

init_declaration    :   declaration_item {$$.node = tree.addNode(INIT_DECLARATION); Node *node = tree.getNodeById($$.node); node->addChild($1.node); tree.print_tree_node($$.node);}
                    |   declaration_item ASSIGN initializer {$$.node = tree.addNode(INIT_DECLARATION); Node *node = tree.getNodeById($$.node); node->addChild($1.node); node->addChild($3.node); tree.print_tree_node($$.node);}

declaration_item    :   pointer simple_item {$$.node = tree.addNode(DECLARATION_ITEM); Node *node = tree.getNodeById($$.node); node->addChild($1.node); tree.print_tree_node($$.node);}
                    |   refer simple_item {$$.node = tree.addNode(DECLARATION_ITEM); Node *node = tree.getNodeById($$.node); node->addChild($1.node); tree.print_tree_node($$.node);}
                    |   simple_item {$$.node = tree.addNode(DECLARATION_ITEM); Node *node = tree.getNodeById($$.node); node->addChild($1.node); tree.print_tree_node($$.node);}
                    ;

simple_item :   identifier      {                                                       
                        }
            |   LPAREN declaration_item RPAREN {                     
                        }
            |   simple_item LBRACKET RBRACKET {                  
                        }
            |   simple_item LBRACKET constant_expr RBRACKET {                       
                        }                       
            |   simple_item LPAREN parameter_list RPAREN {                      
                        }                       
            |   simple_item LPAREN identifier_list RPAREN {                        
                        }                       
            |   simple_item LPAREN RPAREN {                    
                        }                       
            ;

identifier_list :       identifier_list COMMA identifier {
                        }
                |       identifier { 
                        }
                ;
            
initializer :   assignment_expr {                   
                        }                       
            |   LBRACE initializer_list RBRACE {
                                                       
                        }                       
            ;

initializer_list    :   initializer {                     
                        }                       
                    |   initializer_list COMMA initializer {                      
                        }                       
                    ;

assignment_expr :   condition_expr {                     
                        }                       
                |   unary_expr assignment_op assignment_expr {                     
                        }                       
                ;

assignment_op   : ASSIGN 	 { $$.node = tree.addNode(OPERATOR, string("op =").c_str()); tree.print_tree_node($$.node);}
                | ADD_ASSIGN { $$.node = tree.addNode(OPERATOR, string("op +=").c_str()); tree.print_tree_node($$.node);}
                | SUB_ASSIGN { $$.node = tree.addNode(OPERATOR, string("op -=").c_str()); tree.print_tree_node($$.node);}
                | MUL_ASSIGN { $$.node = tree.addNode(OPERATOR, string("op *=").c_str()); tree.print_tree_node($$.node);}
                | DIV_ASSIGN { $$.node = tree.addNode(OPERATOR, string("op /=").c_str()); tree.print_tree_node($$.node);}
                | MOD_ASSIGN { $$.node = tree.addNode(OPERATOR, string("op %=").c_str()); tree.print_tree_node($$.node);}
                | LEFT_ASSIGN { $$.node = tree.addNode(OPERATOR, string("op <<=").c_str()); tree.print_tree_node($$.node);}
                | RIGHT_ASSIGN { $$.node = tree.addNode(OPERATOR, string("op >>=").c_str()); tree.print_tree_node($$.node);}
                | AND_ASSIGN { $$.node = tree.addNode(OPERATOR, string("op &=").c_str()); tree.print_tree_node($$.node);}
                | XOR_ASSIGN { $$.node = tree.addNode(OPERATOR, string("op ^=").c_str()); tree.print_tree_node($$.node);}
                | OR_ASSIGN  { $$.node = tree.addNode(OPERATOR, string("op |=").c_str()); tree.print_tree_node($$.node);}
                ;

condition_expr  :   logical_expr {                       
                        }                       
                |   logical_expr QUESTION expr COLON condition_expr {                      
                        }                       
                ;

logical_expr    :   bit_expr {                       
                        }                       
                |   logical_expr OR_OP bit_expr {                      
                        }                       
                |   logical_expr AND_OP bit_expr {                       
                        }                       
                ;

bit_expr    :   equality_expr {                     
                        }                 
            |   bit_expr AND equality_expr {                     
                        }                 
            |   bit_expr XOR equality_expr {              
                        }                 
            |   bit_expr OR equality_expr {                      
                        }                 
            ;

equality_expr   :   relational_expr {                     
                        }                 
                |   equality_expr EQ_OP relational_expr {                     
                        }                 
                |   equality_expr NE_OP relational_expr {                     
                        }            
                ;

relational_expr :   shift_expr {                      
                        }            
                |   relational_expr LT shift_expr {                    
                        }            
                |   relational_expr GT shift_expr {                      
                        }            
                |   relational_expr LE_OP shift_expr {                     
                        }            
                |   relational_expr GE_OP shift_expr {                    
                        }            
                ;

shift_expr  :   add_expr {                     
                        }            
            |   shift_expr RIGHT_OP add_expr {                    
                        }            
            |   shift_expr LEFT_OP add_expr {                     
                        }            
            ;

add_expr    :   mul_expr {                        
                        }            
            |   add_expr ADD mul_expr {                      
                        }
            |   add_expr SUB mul_expr {                 
                        }
            ;

mul_expr    :   cast_expr {                      
                        }
            |   mul_expr MUL cast_expr {                  
                        }
            |   mul_expr DIV cast_expr {                  
                        }
            |   mul_expr MOD cast_expr {                       
                        }
            ;

cast_expr   :   unary_expr {                     
                        }
            |   LPAREN type_define RPAREN cast_expr {                  
                        }
            ;

unary_expr  :   postfix_expr {                       
                        }
            |   unary_op cast_expr {                     
                        }
            ;

unary_op    :   ADD {       
                }
            |   SUB {  
                }
            |   TLIDE {   
                }
            |   NOT {
                }
            |   INC_OP {
                }
            |   DEC_OP {      
                }
            ;

postfix_expr    :   primary_expr {                     
                        }
                |   postfix_expr LBRACKET expr RBRACKET {                       
                        }
                |   postfix_expr LPAREN RPAREN {                        
                        }
                |   postfix_expr LPAREN argument_expr_list RPAREN {                 
                        }
                |   postfix_expr INC_OP {                      
                        }
                |   postfix_expr DEC_OP {                      
                        }
                ;

argument_expr_list      :       assignment_expr {                                 
                                        }
                        |       argument_expr_list COMMA assignment_expr {                                
                                        }

primary_expr    :   identifier {                   
                        }
                |   constant_expr {              
                        }
                |   LPAREN expr RPAREN {               
                        }
                |   str_constant {                   
                        }
                ;

identifier  :   ID {
		}
            ;

constant_expr   :   CONSTCHAR {
                        }
                |   NUM {

                }
                |   TRUE {
                        }
                |   FALSE {
                        }
                ;


parameter_list  :   parameter_declaration {                                      
                                        }
                |   parameter_list COMMA parameter_declaration {                                    
                                        }
                ;

parameter_declaration   :   declaration_prefix  declaration_item {                                       
                                        }
                        ;

compound_statement  :   LBRACE RBRACE {                                
                        }
                    |   LBRACE compound_statement_list RBRACE {                                      
                                        }
                    ;

compound_statement_list :   statement_list {                                   
                                        }
                        |   declaration_list {                                      
                                        }
                        |   compound_statement_list declaration_list {                                   
                                        }
                        |   compound_statement_list statement_list {                                     
                                        }
                        ;

declaration_list    :   declaration {                                    
                                }
                    |   declaration_list declaration {                                      
                                        }
                    ;

statement_list  :   statement {                                        
                        }
                |   statement_list statement {                                       
                        }
                ;

statement   :   labeled_statement { $$ = $1; }
            |   compound_statement { $$ = $1; }
            |   expr_statement { $$ = $1; }
            |   condition_statement { $$ = $1; }
            |   loop_statement { $$ = $1; }
            |   jump_statement { $$ = $1; }
            ;

labeled_statement   :   identifier COLON statement {                                      
                        }
                    |   CASE constant_expr COLON statement {                                 
                        }
                    |   DEFAULT COLON statement {                                     
                        }
                    ;

expr_statement  :   SEMICOLON {                                       
                        }
                |   expr SEMICOLON {                            
                        }
                ;

condition_statement :   IF LPAREN expr RPAREN statement {                                 
                        }
                    |   IF LPAREN expr RPAREN statement ELSE statement {                     
                        }
                    |   SWITCH LPAREN expr RPAREN statement {                           
                        }
                    ;

expr      :       assignment_expr {
                                }
                | expr COMMA assignment_expr {
                                }
			;

loop_statement : WHILE LPAREN expr RPAREN statement {
                                        }
                | DO statement WHILE LPAREN expr RPAREN SEMICOLON {
                                        }
                | FOR LPAREN expr_statement expr_statement expr RPAREN statement {
                                        }
                ;
				
jump_statement : CONTINUE SEMICOLON {
                        }
                | BREAK SEMICOLON {
                                $1.node = tree.addNode(KEYWORD, "break");
                                tree.print_tree_node($1.node);

                                $$.node = tree.addNode(JUMP_STATEMENT);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                tree.print_tree_node($$.node);
                        }
                | RETURN SEMICOLON {
                                $1.node = tree.addNode(KEYWORD, "return");
                                tree.print_tree_node($1.node);

                                $$.node = tree.addNode(JUMP_STATEMENT);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                tree.print_tree_node($$.node);
                        }
                | RETURN expr SEMICOLON {
                                $1.node = tree.addNode(KEYWORD, "return");
                                tree.print_tree_node($1.node);

                                $$.node = tree.addNode(JUMP_STATEMENT);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($2.node);
                                tree.print_tree_node($$.node);
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