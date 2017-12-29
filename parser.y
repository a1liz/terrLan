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

%token AUTO BOOL BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ELSE
%token EXTERN FLOAT FOR GOTO IF INT LONG REGISTER RETURN SHORT
%token SIZEOF STATIC SWITCH
%token VOID WHILE TRUE FALSE
%token ID CONSTANT STR_CONSTANT 
%token RIGHT_ASSIGN LEFT_ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN
%token MOD_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN
%token RIGHT_OP LEFT_OP INC_OP DEC_OP PTR_OP AND_OP OR_OP LE_OP GE_OP
%token EQ_OP NE_OP

%left ','
%right LEFT_ASSIGN RIGHT_ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN 
%right MOD_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN
%left OR_OP
%left AND_OP
%left '|'
%left '^'
%left '&'
%left EQ_OP NE_OP
%left LE_OP GE_OP '>' '<'
%left RIGHT_OP LEFT_OP
%left '+' '-'
%left '*' '/' '%'

%%
program : translation_unit {
                                $$.node = tree.addNode(PROGRAM);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                tree.print_tree_node($$.node);
                                }
        ;

translation_unit    :   external_declaration {
                                                $$.node = tree.addNode(TRANSLATION_UNIT);
                                                Node *node = tree.getNodeById($$.node);
                                                node->addChild($1.node);
                                                tree.print_tree_node($$.node);
                                                }
                    |   translation_unit external_declaration {
                                                                $$.node = tree.addNode(TRANSLATION_UNIT);
                                                                Node *node = tree.getNodeById($$.node);
                                                                node->addChild($1.node);
                                                                node->addChild($2.node);
                                                                tree.print_tree_node($$.node);
                                                                }
                    ;

external_declaration    :   function_definition {
                                                $$.node = tree.addNode(EXTERNAL_DECLARATION); 
                                                Node *node = tree.getNodeById($$.node); 
                                                node->addChild($1.node);
                                                tree.print_tree_node($$.node);
                                                }
                        |   declaration {
                                        $$.node = tree.addNode(EXTERNAL_DECLARATION); 
                                        Node *node = tree.getNodeById($$.node); 
                                        node->addChild($1.node);
                                        tree.print_tree_node($$.node);
                                        }
                        ;

function_definition     :       declaration_prefix identifier '(' parameter_list ')' compound_statement {
                                                                                                        $$.node = tree.addNode(FUNCTION_DEFINITION);
                                                                                                        Node *node = tree.getNodeById($$.node);
                                                                                                        node->addChild($1.node);
                                                                                                        node->addChild($2.node);
                                                                                                        node->addChild($4.node);
                                                                                                        node->addChild($6.node);
                                                                                                        tree.print_tree_node($$.node);       
                                                                                                }
                        |       declaration_prefix identifier '(' ')' compound_statement {
                                                                                                        $$.node = tree.addNode(FUNCTION_DEFINITION);
                                                                                                        Node *node = tree.getNodeById($$.node);
                                                                                                        node->addChild($1.node);
                                                                                                        node->addChild($2.node);
                                                                                                        node->addChild($5.node);
                                                                                                        tree.print_tree_node($$.node);       
                                                                                                }
                        ;

declaration_prefix  :   special_specifier type_define {
                                                        $$.node = tree.addNode(DECLARATION_PREFIX);
                                                        Node *node = tree.getNodeById($$.node);
                                                        node->addChild($1.node);
                                                        node->addChild($2.node);
                                                        tree.print_tree_node($$.node);
                                                }
                    |   type_define {
                                        $$.node = tree.addNode(DECLARATION_PREFIX);
                                        Node *node = tree.getNodeById($$.node);
                                        node->addChild($1.node);
                                        tree.print_tree_node($$.node);
                                }
                    ;

special_specifier   :   EXTERN  {
                                        $$.node = tree.addNode(SPECIAL_SPECIFIER, "extern");
                                        tree.print_tree_node($$.node);                                
                                }
                    |   STATIC {
                                        $$.node = tree.addNode(SPECIAL_SPECIFIER, "static");  
                                        tree.print_tree_node($$.node);       
                                }
                    |   AUTO    {
                                        $$.node = tree.addNode(SPECIAL_SPECIFIER, "auto");
                                        tree.print_tree_node($$.node);
                                }
                    |   REGISTER {
                                        $$.node = tree.addNode(SPECIAL_SPECIFIER, "register");
                                        tree.print_tree_node($$.node);            
                                }
                    ;

type_define :   VOID    {$$.node = tree.addNode(TYPE_DEFINE,string("void").c_str());tree.print_tree_node($$.node);}
            |   CHAR    {$$.node = tree.addNode(TYPE_DEFINE,string("char").c_str());tree.print_tree_node($$.node);}
            |   INT     {$$.node = tree.addNode(TYPE_DEFINE,string("int").c_str());tree.print_tree_node($$.node);}
            |   DOUBLE  {$$.node = tree.addNode(TYPE_DEFINE,string("double").c_str());tree.print_tree_node($$.node);}
            |   BOOL    {$$.node = tree.addNode(TYPE_DEFINE,string("bool").c_str());tree.print_tree_node($$.node);}
            |   FLOAT   {$$.node = tree.addNode(TYPE_DEFINE,string("float").c_str());tree.print_tree_node($$.node);}
            |   LONG    {$$.node = tree.addNode(TYPE_DEFINE,string("long").c_str());tree.print_tree_node($$.node);}
            |   SHORT   {$$.node = tree.addNode(TYPE_DEFINE,string("short").c_str());tree.print_tree_node($$.node);}
            ;

declaration :  declaration_prefix init_declaration_list ';' {
                                                                    $$.node = tree.addNode(DECLARATION);
                                                                    Node *node = tree.getNodeById($$.node);
                                                                    node->addChild($1.node);
                                                                    node->addChild($2.node);
                                                                    tree.print_tree_node($$.node);    
                                                                }
            ;

init_declaration_list   :   init_declaration {$$.node = tree.addNode(INIT_DECLARATION_LIST); Node *node = tree.getNodeById($$.node); node->addChild($1.node); tree.print_tree_node($$.node);}
                        |   init_declaration_list ',' init_declaration {$$.node = tree.addNode(INIT_DECLARATION_LIST); Node *node = tree.getNodeById($$.node); node->addChild($1.node); node->addChild($3.node); tree.print_tree_node($$.node);}
                        ;

init_declaration    :   declaration_item {$$.node = tree.addNode(INIT_DECLARATION); Node *node = tree.getNodeById($$.node); node->addChild($1.node); tree.print_tree_node($$.node);}
                    |   declaration_item '=' initializer {$$.node = tree.addNode(INIT_DECLARATION); Node *node = tree.getNodeById($$.node); node->addChild($1.node); node->addChild($3.node); tree.print_tree_node($$.node);}

declaration_item    :   pointer simple_item {$$.node = tree.addNode(DECLARATION_ITEM); Node *node = tree.getNodeById($$.node); node->addChild($1.node); tree.print_tree_node($$.node);}
                    |   refer simple_item {$$.node = tree.addNode(DECLARATION_ITEM); Node *node = tree.getNodeById($$.node); node->addChild($1.node); tree.print_tree_node($$.node);}
                    |   simple_item {$$.node = tree.addNode(DECLARATION_ITEM); Node *node = tree.getNodeById($$.node); node->addChild($1.node); tree.print_tree_node($$.node);}
                    ;

pointer :   '*' {
                $1.node = tree.addNode(POINTER, "*");
                tree.print_tree_node($1.node);

                $$.node = tree.addNode(POINTER);
                Node *node = tree.getNodeById($$.node);
                node->addChild($1.node);
                tree.print_tree_node($$.node); 
                }
        |   '*' pointer { 
                        $1.node = tree.addNode(POINTER, "*");
                        tree.print_tree_node($1.node);

                        $$.node = tree.addNode(POINTER); 
                        Node *node = tree.getNodeById($$.node);
                        node->addChild($1.node);
                        node->addChild($2.node);
                        tree.print_tree_node($$.node); 
                }
        ;

refer   :   '&' {
                $1.node = tree.addNode(REFER, "&");
                tree.print_tree_node($1.node);

                $$.node = tree.addNode(REFER);
                Node *node = tree.getNodeById($$.node);
                node->addChild($1.node);
                tree.print_tree_node($$.node); 
                }
        |   '&' refer { 
                        $1.node = tree.addNode(REFER, "&");
                        tree.print_tree_node($1.node);

                        $$.node = tree.addNode(REFER); 
                        Node *node = tree.getNodeById($$.node);
                        node->addChild($1.node);
                        node->addChild($2.node);
                        tree.print_tree_node($$.node); 
                }
        ;

simple_item :   identifier      {
                                $$.node = tree.addNode(SIMPLE_ITEM);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                tree.print_tree_node($$.node);                        
                        }
            |   '(' declaration_item ')' {
                                $$.node = tree.addNode(SIMPLE_ITEM);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($2.node);
                                tree.print_tree_node($$.node);                        
                        }
            |   simple_item '[' ']' {
                                $$.node = tree.addNode(SIMPLE_ITEM);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                tree.print_tree_node($$.node);                        
                        }
            |   simple_item '[' constant_expr ']' {
                                $$.node = tree.addNode(SIMPLE_ITEM);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($3.node);
                                tree.print_tree_node($$.node);                        
                        }                       
            |   simple_item '(' parameter_list ')' {
                                $$.node = tree.addNode(SIMPLE_ITEM);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($3.node);
                                tree.print_tree_node($$.node);                        
                        }                       
            |   simple_item '(' identifier_list ')' {
                                $$.node = tree.addNode(SIMPLE_ITEM);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($3.node);
                                tree.print_tree_node($$.node);                        
                        }                       
            |   simple_item '(' ')' {
                                $$.node = tree.addNode(SIMPLE_ITEM);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                tree.print_tree_node($$.node);                        
                        }                       
            ;

identifier_list :       identifier_list ',' identifier {
                                $$.node = tree.addNode(IDENTIFIER_LIST);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($3.node);
                                tree.print_tree_node($$.node);
                        }
                |       identifier { 
                        $$.node = tree.addNode(IDENTIFIER_LIST);
                        Node *node = tree.getNodeById($$.node);
                        node->addChild($1.node);
                        tree.print_tree_node($$.node);
                        }
                ;
            
initializer :   assignment_expr {
                                $$.node = tree.addNode(INITIALIZER);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                tree.print_tree_node($$.node);                        
                        }                       
            |   '{' initializer_list '}' {
                                $$.node = tree.addNode(INITIALIZER);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($2.node);
                                tree.print_tree_node($$.node);                        
                        }                       
            ;

initializer_list    :   initializer {
                                $$.node = tree.addNode(INITIALIZER_LIST);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                tree.print_tree_node($$.node);                        
                        }                       
                    |   initializer_list ',' initializer {
                                $$.node = tree.addNode(INITIALIZER_LIST);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($3.node);
                                tree.print_tree_node($$.node);                        
                        }                       
                    ;

assignment_expr :   condition_expr {
                                $$.node = tree.addNode(ASSIGNMENT_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                tree.print_tree_node($$.node);                        
                        }                       
                |   unary_expr assignment_op assignment_expr {
                                $$.node = tree.addNode(ASSIGNMENT_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($2.node);
                                node->addChild($3.node);
                                tree.print_tree_node($$.node);                        
                        }                       
                ;

assignment_op   : '=' 	 { $$.node = tree.addNode(OPERATOR, string("op =").c_str()); tree.print_tree_node($$.node);}
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
                                $$.node = tree.addNode(CONDITION_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                tree.print_tree_node($$.node);                        
                        }                       
                |   logical_expr '?' expr ':' condition_expr {
                                $$.node = tree.addNode(CONDITION_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($3.node);
                                node->addChild($5.node);
                                tree.print_tree_node($$.node);                        
                        }                       
                ;

logical_expr    :   bit_expr {
                                $$.node = tree.addNode(LOGICAL_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                tree.print_tree_node($$.node);                        
                        }                       
                |   logical_expr OR_OP bit_expr {
                                $2.node = tree.addNode(OPERATOR, string("op ||").c_str());
                                tree.print_tree_node($2.node);

                                $$.node = tree.addNode(LOGICAL_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($2.node);
                                node->addChild($3.node);
                                tree.print_tree_node($$.node);                        
                        }                       
                |   logical_expr AND_OP bit_expr {
                                $2.node = tree.addNode(OPERATOR, string("op &&").c_str());
                                tree.print_tree_node($2.node);

                                $$.node = tree.addNode(LOGICAL_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($2.node);
                                node->addChild($3.node);
                                tree.print_tree_node($$.node);                        
                        }                       
                ;

bit_expr    :   equality_expr {
                                $$.node = tree.addNode(BIT_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                tree.print_tree_node($$.node);                        
                        }                 
            |   bit_expr '&' equality_expr {
                                $2.node = tree.addNode(OPERATOR, string("bit_op &").c_str());
                                tree.print_tree_node($2.node);

                                $$.node = tree.addNode(BIT_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($2.node);
                                node->addChild($3.node);
                                tree.print_tree_node($$.node);                        
                        }                 
            |   bit_expr '^' equality_expr {
                                $2.node = tree.addNode(OPERATOR, string("bit_op ^").c_str());
                                tree.print_tree_node($2.node);

                                $$.node = tree.addNode(BIT_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($2.node);
                                node->addChild($3.node);
                                tree.print_tree_node($$.node);                        
                        }                 
            |   bit_expr '|' equality_expr {
                                $2.node = tree.addNode(OPERATOR, string("bit_op |").c_str());
                                tree.print_tree_node($2.node);

                                $$.node = tree.addNode(BIT_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($2.node);
                                node->addChild($3.node);
                                tree.print_tree_node($$.node);                        
                        }                 
            ;

equality_expr   :   relational_expr {
                                $$.node = tree.addNode(EQUALITY_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                tree.print_tree_node($$.node);                        
                        }                 
                |   equality_expr EQ_OP relational_expr {
                                $2.node = tree.addNode(OPERATOR, string("op =").c_str());
                                tree.print_tree_node($2.node);

                                $$.node = tree.addNode(EQUALITY_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($2.node);
                                node->addChild($3.node);
                                tree.print_tree_node($$.node);                        
                        }                 
                |   equality_expr NE_OP relational_expr {
                                $2.node = tree.addNode(OPERATOR, string("op !=").c_str());
                                tree.print_tree_node($2.node);

                                $$.node = tree.addNode(EQUALITY_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($2.node);
                                node->addChild($3.node);
                                tree.print_tree_node($$.node);                        
                        }            
                ;

relational_expr :   shift_expr {
                                $$.node = tree.addNode(RELATIONAL_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                tree.print_tree_node($$.node);                        
                        }            
                |   relational_expr '<' shift_expr {
                                $2.node = tree.addNode(OPERATOR, string("op <").c_str());
                                tree.print_tree_node($2.node);

                                $$.node = tree.addNode(RELATIONAL_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($2.node);
                                node->addChild($3.node);
                                tree.print_tree_node($$.node);                        
                        }            
                |   relational_expr '>' shift_expr {
                                $2.node = tree.addNode(OPERATOR, string("op >").c_str());
                                tree.print_tree_node($2.node);

                                $$.node = tree.addNode(RELATIONAL_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($2.node);
                                node->addChild($3.node);
                                tree.print_tree_node($$.node);                        
                        }            
                |   relational_expr LE_OP shift_expr {
                                $2.node = tree.addNode(OPERATOR, string("op <=").c_str());
                                tree.print_tree_node($2.node);

                                $$.node = tree.addNode(RELATIONAL_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($2.node);
                                node->addChild($3.node);
                                tree.print_tree_node($$.node);                        
                        }            
                |   relational_expr GE_OP shift_expr {
                                $2.node = tree.addNode(OPERATOR, string("op >=").c_str());
                                tree.print_tree_node($2.node);

                                $$.node = tree.addNode(RELATIONAL_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($2.node);
                                node->addChild($3.node);
                                tree.print_tree_node($$.node);                        
                        }            
                ;

shift_expr  :   add_expr {
                                $$.node = tree.addNode(SHIFT_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                tree.print_tree_node($$.node);                        
                        }            
            |   shift_expr RIGHT_OP add_expr {
                                $2.node = tree.addNode(OPERATOR, string("op >>").c_str());
                                tree.print_tree_node($2.node);

                                $$.node = tree.addNode(SHIFT_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($2.node);
                                node->addChild($3.node);
                                tree.print_tree_node($$.node);                        
                        }            
            |   shift_expr LEFT_OP add_expr {
                                $2.node = tree.addNode(OPERATOR, string("op <<").c_str());
                                tree.print_tree_node($2.node);

                                $$.node = tree.addNode(SHIFT_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($2.node);
                                node->addChild($3.node);
                                tree.print_tree_node($$.node);                        
                        }            
            ;

add_expr    :   mul_expr {
                                $$.node = tree.addNode(ADD_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                tree.print_tree_node($$.node);                        
                        }            
            |   add_expr '+' mul_expr {
                                $2.node = tree.addNode(OPERATOR, string("op +").c_str());
                                tree.print_tree_node($2.node);

                                $$.node = tree.addNode(ADD_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($2.node);
                                node->addChild($3.node);
                                tree.print_tree_node($$.node);                        
                        }
            |   add_expr '-' mul_expr {
                                $2.node = tree.addNode(OPERATOR, string("op -").c_str());
                                tree.print_tree_node($2.node);

                                $$.node = tree.addNode(ADD_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($2.node);
                                node->addChild($3.node);
                                tree.print_tree_node($$.node);                        
                        }
            ;

mul_expr    :   cast_expr {
                                $$.node = tree.addNode(MUL_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                tree.print_tree_node($$.node);                        
                        }
            |   mul_expr '*' cast_expr {
                                $2.node = tree.addNode(OPERATOR, string("op *").c_str());
                                tree.print_tree_node($2.node);

                                $$.node = tree.addNode(MUL_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($2.node);
                                node->addChild($3.node);
                                tree.print_tree_node($$.node);                        
                        }
            |   mul_expr '/' cast_expr {
                                $2.node = tree.addNode(OPERATOR, string("op /").c_str());
                                tree.print_tree_node($2.node);

                                $$.node = tree.addNode(MUL_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($2.node);
                                node->addChild($3.node);
                                tree.print_tree_node($$.node);                        
                        }
            |   mul_expr '%' cast_expr {
                                $2.node = tree.addNode(OPERATOR, string("op %").c_str());
                                tree.print_tree_node($2.node);

                                $$.node = tree.addNode(MUL_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($2.node);
                                node->addChild($3.node);
                                tree.print_tree_node($$.node);                        
                        }
            ;

cast_expr   :   unary_expr {
                                $$.node = tree.addNode(CAST_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                tree.print_tree_node($$.node);                        
                        }
            |   '(' type_define ')' cast_expr {
                                $$.node = tree.addNode(CAST_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($2.node);
                                node->addChild($4.node);
                                tree.print_tree_node($$.node);                        
                        }
            ;

unary_expr  :   postfix_expr {
                                $$.node = tree.addNode(UNARY_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                tree.print_tree_node($$.node);                        
                        }
            |   unary_op cast_expr {
                                $$.node = tree.addNode(UNARY_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($2.node);
                                tree.print_tree_node($$.node);                        
                        }
            ;

unary_op    :   '+' {
                        $$.node = tree.addNode(UNARY_OP, "unary_op +");
                        tree.print_tree_node($$.node);        
                }
            |   '-' {
                        $$.node = tree.addNode(UNARY_OP, "unary_op -");
                        tree.print_tree_node($$.node);        
                }
            |   '~' {
                        $$.node = tree.addNode(UNARY_OP, "unary_op ~");
                        tree.print_tree_node($$.node);        
                }
            |   '!' {
                        $$.node = tree.addNode(UNARY_OP, "unary_op !");
                        tree.print_tree_node($$.node);        
                }
            |   INC_OP {
                        $$.node = tree.addNode(UNARY_OP, "inc_op ++");
                        tree.print_tree_node($$.node);        
                }
            |   DEC_OP {
                        $$.node = tree.addNode(UNARY_OP, "dec_op --");
                        tree.print_tree_node($$.node);        
                }
            ;

postfix_expr    :   primary_expr {
                                $$.node = tree.addNode(POSTFIX_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                tree.print_tree_node($$.node);                        
                        }
                |   postfix_expr '[' expr ']' {
                                $$.node = tree.addNode(POSTFIX_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($3.node);
                                tree.print_tree_node($$.node);                        
                        }
                |   postfix_expr '(' ')' {
                                $$.node = tree.addNode(POSTFIX_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                tree.print_tree_node($$.node);                        
                        }
                |   postfix_expr '(' argument_expr_list ')' {
                                $$.node = tree.addNode(POSTFIX_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($3.node);
                                tree.print_tree_node($$.node);                        
                        }
                |   postfix_expr '.' identifier {
                                $$.node = tree.addNode(POSTFIX_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($3.node);
                                tree.print_tree_node($$.node);                        
                        }
                |   postfix_expr PTR_OP identifier {
                                $2.node = tree.addNode(OPERATOR,string("ptr_op ->").c_str());
                                tree.print_tree_node($2.node);

                                $$.node = tree.addNode(POSTFIX_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($2.node);
                                node->addChild($3.node);
                                tree.print_tree_node($$.node);                        
                        }
                |   postfix_expr INC_OP {
                                $2.node = tree.addNode(OPERATOR,string("inc_op ++").c_str());
                                tree.print_tree_node($2.node);

                                $$.node = tree.addNode(POSTFIX_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($2.node);
                                tree.print_tree_node($$.node);                        
                        }
                |   postfix_expr DEC_OP {
                                $2.node = tree.addNode(OPERATOR,string("dec_op --").c_str());
                                tree.print_tree_node($2.node);

                                $$.node = tree.addNode(POSTFIX_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($2.node);
                                tree.print_tree_node($$.node);                        
                        }
                ;

argument_expr_list      :       assignment_expr {
                                                $$.node = tree.addNode(ARGUMENT_EXPR_LIST);
                                                Node *node = tree.getNodeById($$.node);
                                                node->addChild($1.node);
                                                tree.print_tree_node($$.node);                                    
                                        }
                        |       argument_expr_list ',' assignment_expr {
                                                $$.node = tree.addNode(ARGUMENT_EXPR_LIST);
                                                Node *node = tree.getNodeById($$.node);
                                                node->addChild($1.node);
                                                node->addChild($3.node);
                                                tree.print_tree_node($$.node);                                    
                                        }

primary_expr    :   identifier {
                                $$.node = tree.addNode(PRIMARY_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                tree.print_tree_node($$.node);                        
                        }
                |   constant_expr {
                                $$.node = tree.addNode(PRIMARY_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                tree.print_tree_node($$.node);                        
                        }
                |   '(' expr ')' {
                                $$.node = tree.addNode(PRIMARY_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($2.node);
                                tree.print_tree_node($$.node);                        
                        }
                |   str_constant {
                                $$.node = tree.addNode(PRIMARY_EXPR);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                tree.print_tree_node($$.node);                        
                        }
                ;

identifier  :   ID {
                        string s = string("id ").append($1.text); 
                        $$.node = tree.addNode(IDENTIFIER, strdup(s.c_str())); 
                        tree.print_tree_node($$.node);
		}
            ;

constant_expr   :   CONSTANT {
                                string s = string("constant value ").append($1.text);
                                $$.node = tree.addNode(CONSTANT_EXPR, strdup(s.c_str()));
                                tree.print_tree_node($$.node);
                        }
                |   TRUE {
                                $$.node = tree.addNode(CONSTANT_EXPR, "bool true");
                                tree.print_tree_node($$.node);
                        }
                |   FALSE {
                                $$.node = tree.addNode(CONSTANT_EXPR, "bool false");
                                tree.print_tree_node($$.node);
                        }
                ;

str_constant    :   STR_CONSTANT {
                                string s = string("string ").append($1.text);
                                $$.node = tree.addNode(STRING_CONSTANT, strdup(s.c_str()));
                                tree.print_tree_node($$.node);
                        }
                ;


parameter_list  :   parameter_declaration {
                                                $$.node = tree.addNode(PARAMETER_LIST);
                                                Node *node = tree.getNodeById($$.node);
                                                node->addChild($1.node);
                                                tree.print_tree_node($$.node);                                        
                                        }
                |   parameter_list ',' parameter_declaration {
                                                $$.node = tree.addNode(PARAMETER_LIST);
                                                Node *node = tree.getNodeById($$.node);
                                                node->addChild($1.node);
                                                node->addChild($3.node);
                                                tree.print_tree_node($$.node);                                        
                                        }
                ;

parameter_declaration   :   declaration_prefix  declaration_item {
                                                $$.node = tree.addNode(PARAMETER_DECLARATION);
                                                Node *node = tree.getNodeById($$.node);
                                                node->addChild($1.node);
                                                node->addChild($2.node);
                                                tree.print_tree_node($$.node);                                        
                                        }
                        ;

compound_statement  :   '{' '}' {
                                $$.node = tree.addNode(COMPOUND_STATEMENT);
                                tree.print_tree_node($$.node);                                        
                        }
                    |   '{' compound_statement_list '}' {
                                                $$.node = tree.addNode(COMPOUND_STATEMENT);
                                                Node *node = tree.getNodeById($$.node);
                                                node->addChild($2.node);
                                                tree.print_tree_node($$.node);                                        
                                        }
                    ;

compound_statement_list :   statement_list {
                                                $$.node = tree.addNode(COMPOUND_STATEMENT_LIST);
                                                Node *node = tree.getNodeById($$.node);
                                                node->addChild($1.node);
                                                tree.print_tree_node($$.node);                                        
                                        }
                        |   declaration_list {
                                                $$.node = tree.addNode(COMPOUND_STATEMENT_LIST);
                                                Node *node = tree.getNodeById($$.node);
                                                node->addChild($1.node);
                                                tree.print_tree_node($$.node);                                        
                                        }
                        |   compound_statement_list declaration_list {
                                                $$.node = tree.addNode(COMPOUND_STATEMENT_LIST);
                                                Node *node = tree.getNodeById($$.node);
                                                node->addChild($1.node);
                                                node->addChild($2.node);
                                                tree.print_tree_node($$.node);                                        
                                        }
                        |   compound_statement_list statement_list {
                                                $$.node = tree.addNode(COMPOUND_STATEMENT_LIST);
                                                Node *node = tree.getNodeById($$.node);
                                                node->addChild($1.node);
                                                node->addChild($2.node);
                                                tree.print_tree_node($$.node);                                        
                                        }
                        ;

declaration_list    :   declaration {
                                        $$.node = tree.addNode(DECLARATION_LIST);
                                        Node *node = tree.getNodeById($$.node);
                                        node->addChild($1.node);
                                        tree.print_tree_node($$.node);                                        
                                }
                    |   declaration_list declaration {
                                                $$.node = tree.addNode(DECLARATION_LIST);
                                                Node *node = tree.getNodeById($$.node);
                                                node->addChild($1.node);
                                                node->addChild($2.node);
                                                tree.print_tree_node($$.node);                                        
                                        }
                    ;

statement_list  :   statement {
                                $$.node = tree.addNode(STATEMENT_LIST);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                tree.print_tree_node($$.node);                                        
                        }
                |   statement_list statement {
                                $$.node = tree.addNode(STATEMENT_LIST);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($2.node);
                                tree.print_tree_node($$.node);                                        
                        }
                ;

statement   :   labeled_statement { $$ = $1; }
            |   compound_statement { $$ = $1; }
            |   expr_statement { $$ = $1; }
            |   condition_statement { $$ = $1; }
            |   loop_statement { $$ = $1; }
            |   jump_statement { $$ = $1; }
            ;

labeled_statement   :   identifier ':' statement {
                                $$.node = tree.addNode(LABELED_STATEMENT);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($3.node);
                                tree.print_tree_node($$.node);                                        
                        }
                    |   CASE constant_expr ':' statement {
                                $1.node = tree.addNode(KEYWORD, "case ");
                                tree.print_tree_node($1.node);
                        
                                $$.node = tree.addNode(LABELED_STATEMENT);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($2.node);
                                node->addChild($4.node);
                                tree.print_tree_node($$.node);                                        
                        }
                    |   DEFAULT ':' statement {
                                $1.node = tree.addNode(KEYWORD, "default ");
                                tree.print_tree_node($1.node);
                        
                                $$.node = tree.addNode(LABELED_STATEMENT);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($3.node);
                                tree.print_tree_node($$.node);                                        
                        }
                    ;

expr_statement  :   ';' {
                                $$.node = tree.addNode(EXPR_STATEMENT);
                                tree.print_tree_node($$.node);                                        
                        }
                |   expr ';' {
                                $$.node = tree.addNode(EXPR_STATEMENT);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                tree.print_tree_node($$.node);                                        
                        }
                ;

condition_statement :   IF '(' expr ')' statement {
                                $1.node = tree.addNode(KEYWORD, "if ");
                                tree.print_tree_node($1.node);
                        
                                $$.node = tree.addNode(CONDITION_STATEMENT);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($3.node);
                                node->addChild($5.node);
                                tree.print_tree_node($$.node);                                        
                        }
                    |   IF '(' expr ')' statement ELSE statement {
                                $1.node = tree.addNode(KEYWORD, "if-else ");
                                tree.print_tree_node($1.node);
                        
                                $$.node = tree.addNode(CONDITION_STATEMENT);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($3.node);
                                node->addChild($5.node);
                                node->addChild($7.node);
                                tree.print_tree_node($$.node);                                        
                        }
                    |   SWITCH '(' expr ')' statement {
                                $1.node = tree.addNode(KEYWORD, "switch ");
                                tree.print_tree_node($1.node);
                        
                                $$.node = tree.addNode(CONDITION_STATEMENT);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                node->addChild($3.node);
                                node->addChild($5.node);
                                tree.print_tree_node($$.node);                                        
                        }
                    ;

expr      :       assignment_expr {
                                        $$.node = tree.addNode(EXPR);  
                                        Node *node = tree.getNodeById($$.node);
                                        node->addChild($1.node);
                                        tree.print_tree_node($$.node);
                                }
                | expr ',' assignment_expr {
                                        $$.node = tree.addNode(EXPR);  
                                        Node *node = tree.getNodeById($$.node);
                                        node->addChild($1.node);
                                        node->addChild($3.node);
                                        tree.print_tree_node($$.node);
                                }
			;

loop_statement : WHILE '(' expr ')' statement {
                                                $1.node = tree.addNode(KEYWORD, "while ");
                                                tree.print_tree_node($1.node);

                                                $$.node = tree.addNode(LOOP_STATEMENT);
                                                Node *node = tree.getNodeById($$.node);
                                                node->addChild($1.node);
                                                node->addChild($3.node);
                                                node->addChild($5.node);
                                                tree.print_tree_node($$.node);
                                        }
                | DO statement WHILE '(' expr ')' ';' {
                                                $1.node = tree.addNode(KEYWORD, "do-while ");
                                                tree.print_tree_node($1.node);

                                                $$.node = tree.addNode(LOOP_STATEMENT);
                                                Node *node = tree.getNodeById($$.node);
                                                node->addChild($1.node);
                                                node->addChild($2.node);
                                                node->addChild($5.node);
                                                tree.print_tree_node($$.node);
                                        }
                | FOR '(' expr_statement expr_statement expr ')' statement {
                                                $1.node = tree.addNode(KEYWORD, "for ");
                                                tree.print_tree_node($1.node);

                                                $$.node = tree.addNode(LOOP_STATEMENT);
                                                Node *node = tree.getNodeById($$.node);
                                                node->addChild($1.node);
                                                node->addChild($3.node);
                                                node->addChild($4.node);
                                                node->addChild($5.node);
                                                node->addChild($7.node);
                                                tree.print_tree_node($$.node);
                                        }
                ;
				
jump_statement : GOTO identifier ';' {
                                        $1.node = tree.addNode(KEYWORD, "goto");
                                        tree.print_tree_node($1.node);

                                        $$.node = tree.addNode(JUMP_STATEMENT);
                                        Node *node = tree.getNodeById($$.node);
                                        node->addChild($1.node);
                                        node->addChild($2.node);
                                        tree.print_tree_node($$.node);
                                }
                | CONTINUE ';' {
                                $1.node = tree.addNode(KEYWORD, "continue");
                                tree.print_tree_node($1.node);

                                $$.node = tree.addNode(JUMP_STATEMENT);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                tree.print_tree_node($$.node);
                        }
                | BREAK ';' {
                                $1.node = tree.addNode(KEYWORD, "break");
                                tree.print_tree_node($1.node);

                                $$.node = tree.addNode(JUMP_STATEMENT);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                tree.print_tree_node($$.node);
                        }
                | RETURN ';' {
                                $1.node = tree.addNode(KEYWORD, "return");
                                tree.print_tree_node($1.node);

                                $$.node = tree.addNode(JUMP_STATEMENT);
                                Node *node = tree.getNodeById($$.node);
                                node->addChild($1.node);
                                tree.print_tree_node($$.node);
                        }
                | RETURN expr ';' {
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