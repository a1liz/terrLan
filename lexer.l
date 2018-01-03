/* scanner for a toy Pascal-like language */
%{
/* need this for the call to atof() below */
#include <iostream>
#include <string>
#include <string.h>
#include <unordered_map>
#include "newTree.h"
#include "symbol.h"
#include "parser.hpp"
using namespace std;

unsigned int cnt = 0;
unordered_map<string, unsigned int> properties;
extern symbol_table symbtl;

Node dummy;

int lineno = 1;

static void print_token(int token, char* lexeme, int attr = 0);
%}

letter      [_A-Za-z]
decDigit    [0-9]
octDigit    [0-7]
hexDigit    [0-9a-fA-F]
charVal     '([^\n\\]|(\\.)|(\\{octDigit}{1,3})|(\\[xX]{hexDigit}{1,2}))'

identity    {letter}({letter}|{decDigit})*
decimal     (({decDigit}|[1-9]{decDigit}+)(((\.){decDigit}+)?))|(\.){decDigit}+
octal       (0)({octDigit}+)
hex         (0)[xX]({hexDigit}+)
numberSci   (({decDigit}+((\.){decDigit}+)?)|((\.){decDigit}+)|{hex})[eE]([+-]?){decDigit}+
number      {decimal}|{octal}|{hex}|{numberSci}
delimitation    [ \n\t\f\v]
whitespace      {delimitation}+


%%



"/*"        {
                char c;
                LABEL:
                do
                {
                    c = input();
                    if( c == '\n')
                    	lineno++;
                }while(c != '*');
                
                do
                {
                    c = input();
                    if(c == '/')
                        break;
                    if( c == '\n')
                    	lineno++;
                    if(c != '*')
                        goto LABEL;
                }while(c == '*');
            }
"bool"          {print_token(BOOL, yytext); return BOOL;}
"break"	        {print_token(BREAK, yytext); return BREAK;}
"case"	        {print_token(CASE, yytext); return CASE;}
"char"	        {print_token(CHAR, yytext); return CHAR;}
"continue"	    {print_token(CONTINUE, yytext); return CONTINUE;}
"default"	    {print_token(DEFAULT, yytext); return DEFAULT;}
"do"	        {print_token(DO, yytext); return DO;}
"double"        {print_token(DOUBLE, yytext); return DOUBLE;}
"else"	        {print_token(ELSE, yytext); return ELSE;}
"float"	        {print_token(FLOAT, yytext); return FLOAT;}
"for"	        {print_token(FOR, yytext); return FOR;}
"if"	        {print_token(IF, yytext); return IF;}
"int"	        {print_token(INT, yytext); return INT;}
"return"        {print_token(RETURN, yytext); return RETURN;}
"switch"        {print_token(SWITCH, yytext); return SWITCH;}
"void"	        {print_token(VOID, yytext); return VOID;}
"while"	        {print_token(WHILE, yytext); return WHILE;}
"true"          {
    print_token(TRUE, yytext); 
    yylval = &dummy;
    yylval->valb = true;
    return TRUE;
}
"false" {
    print_token(FALSE, yytext);
    yylval = &dummy;
    yylval->valb = false;
    return FALSE;
}

">>="			{print_token(RIGHT_ASSIGN, yytext); return RIGHT_ASSIGN;}
"<<="			{print_token(LEFT_ASSIGN, yytext); return LEFT_ASSIGN;}
"+="			{print_token(ADD_ASSIGN, yytext); return ADD_ASSIGN;}
"-="			{print_token(SUB_ASSIGN, yytext); return SUB_ASSIGN;}
"*="			{print_token(MUL_ASSIGN, yytext); return MUL_ASSIGN;}
"/="			{print_token(DIV_ASSIGN, yytext); return DIV_ASSIGN;}
"%="			{print_token(MOD_ASSIGN, yytext); return MOD_ASSIGN;}
"&="			{print_token(AND_ASSIGN, yytext); return AND_ASSIGN;}
"^="			{print_token(XOR_ASSIGN, yytext); return XOR_ASSIGN;}
"|="			{print_token(OR_ASSIGN, yytext); return OR_ASSIGN;}
">>"			{print_token(RIGHT_OP, yytext); return RIGHT_OP;}
"<<"			{print_token(LEFT_OP, yytext); return LEFT_OP;}
"++"			{print_token(INC_OP, yytext); return INC_OP;}
"--"			{print_token(DEC_OP, yytext); return DEC_OP;}
"&&"			{print_token(AND_OP, yytext); return AND_OP;}
"||"			{print_token(OR_OP, yytext); return OR_OP;}
"<="			{print_token(LE_OP, yytext); return LE_OP;}
">="			{print_token(GE_OP, yytext); return GE_OP;}
"=="			{print_token(EQ_OP, yytext); return EQ_OP;}
"!="			{print_token(NE_OP, yytext); return NE_OP;}
";"			    {print_token(SEMICOLON, yytext); return SEMICOLON;}
("{"|"<%")		{print_token(LBRACE, yytext); return LBRACE;}
("}"|"%>")		{print_token(RBRACE, yytext); return RBRACE;}
("["|"<:")		{print_token(LBRACKET, yytext); return LBRACKET;}
("]"|":>")		{print_token(RBRACKET, yytext); return RBRACE;}
","			    {print_token(COMMA, yytext); return COMMA;}
":"			    {print_token(COLON, yytext); return COLON;}
"="			    {print_token(ASSIGN, yytext); return ASSIGN;}
"("			    {print_token(LPAREN, yytext); return LPAREN;}
")"			    {print_token(RPAREN, yytext); return RPAREN;}
"!"			    {print_token(NOT, yytext); return NOT;}
"~"			    {print_token(TLIDE, yytext); return TLIDE;}
"-"			    {print_token(SUB, yytext); return SUB;}
"+"			    {print_token(ADD, yytext); return ADD;}
"*"			    {print_token(MUL, yytext); return MUL;}
"/"			    {print_token(DIV, yytext); return DIV;}
"%"			    {print_token(MOD, yytext); return MOD;}
"<"			    {print_token(LT, yytext); return LT;}
">"			    {print_token(GT, yytext); return GT;}
"&"			    {print_token(AND, yytext); return AND;}
"^"			    {print_token(XOR, yytext); return XOR;}
"|"			    {print_token(OR, yytext); return OR;}
"?"			    {print_token(QUESTION, yytext); return QUESTION;}

{charVal}   {
    print_token(CONSTCHAR,yytext);
    yylval = &dummy;
    yylval->attr.valc = yytext[0];
    return CONSTCHAR;
}
{number}    {
    print_token(NUM, yytext, atoi(yytext));
    yylval = &dummy;
    yylval->attr.vali = atoi(yytext);
    return NUM;
}

{identity}      {
    int p;

    p = symbtl.lookup(yytext);
    if (p == -1)
        p = symbtl.insert(yytext, ID);
    else
        dummy.type = symbtl.gettype(p);
    print_token(symbtl.gettoken(yytext), yytext, p);
    yylval = &dummy;
    yylval->attr.symbtl.seq = p;

    return ID;
    }


{whitespace}    { /* do nothing */}
.               { /* ignore bad characters */ }

%%

int yywrap() {
return 1;
}

static void print_token(int token, char *lexeme, int attr) {
#ifdef LEX_DEBUG
    cout << "token: " << token << ",\tlexeme: " << lexeme;
    if (token == ID)
        cout << ",\tsymbol table pos: " << attr;
    else if (token == NUM)
        cout << ",\tvalue: " << attr;
    cout << endl;
#endif
}