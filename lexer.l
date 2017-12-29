/* scanner for a toy Pascal-like language */
%{
/* need this for the call to atof() below */
#include <iostream>
#include <string>
#include <string.h>
#include <unordered_map>
#include "tree.h"
#include "parser.hpp"
using namespace std;

unsigned int cnt = 0;
unordered_map<string, unsigned int> properties;

%}

letter      [_A-Za-z]
decDigit    [0-9]
octDigit    [0-7]
hexDigit    [0-9a-fA-F]
charVal     '([^\n\\]|(\\.)|(\\{octDigit}{1,3})|(\\[xX]{hexDigit}{1,2}))'
stringVal   \"(\\.|[^\\"\n])*\"
boolVal     ("true"|"false")

identity    {letter}({letter}|{decDigit})*
decimal     (({decDigit}|[1-9]{decDigit}+)(((\.){decDigit}+)?))|(\.){decDigit}+
octal       (0)({octDigit}+)
hex         (0)[xX]({hexDigit}+)
numberSci   (({decDigit}+((\.){decDigit}+)?)|((\.){decDigit}+)|{hex})[eE]([+-]?){decDigit}+
number      {decimal}|{octal}|{hex}|{numberSci}
delimitation    [ \n\t\f\v]
whitespace      {delimitation}+


%%



"//".*      { /* do nothing */ }
"/*"([^\*\/]|"*"[^\/])*"*/" { /* do nothing */ }

"auto"	        {return AUTO;}
"bool"          {return BOOL;}
"break"	        {return BREAK;}
"case"	        {return CASE;}
"char"	        {return CHAR;}
"continue"	    {return CONTINUE;}
"default"	    {return DEFAULT;}
"do"	        {return DO;}
"double"        {return DOUBLE;}
"else"	        {return ELSE;}
"extern"        {return EXTERN;}
"float"	        {return FLOAT;}
"for"	        {return FOR;}
"goto"	        {return GOTO;}
"if"	        {return IF;}
"int"	        {return INT;}
"long"	        {return LONG;}
"register"	    {return REGISTER;}
"return"        {return RETURN;}
"short"	        {return SHORT;}
"static"        {return STATIC;}
"switch"        {return SWITCH;}
"void"	        {return VOID;}
"while"	        {return WHILE;}

">>="			{return RIGHT_ASSIGN;}
"<<="			{return LEFT_ASSIGN;}
"+="			{return ADD_ASSIGN;}
"-="			{return SUB_ASSIGN;}
"*="			{return MUL_ASSIGN;}
"/="			{return DIV_ASSIGN;}
"%="			{return MOD_ASSIGN;}
"&="			{return AND_ASSIGN;}
"^="			{return XOR_ASSIGN;}
"|="			{return OR_ASSIGN;}
">>"			{return RIGHT_OP;}
"<<"			{return LEFT_OP;}
"++"			{return INC_OP;}
"--"			{return DEC_OP;}
"->"			{return PTR_OP;}
"&&"			{return AND_OP;}
"||"			{return OR_OP;}
"<="			{return LE_OP;}
">="			{return GE_OP;}
"=="			{return EQ_OP;}
"!="			{return NE_OP;}
";"			    {return ';';}
("{"|"<%")		{return '{';}
("}"|"%>")		{return '}';}
","			    {return ',';}
":"			    {return ':';}
"="			    {return '=';}
"("			    {return '(';}
")"			    {return ')';}
("["|"<:")		{return ']';}
("]"|":>")		{return '[';}
"."			    {return '.';}
"&"			    {return '&';}
"!"			    {return '!';}
"~"			    {return '~';}
"-"			    {return '-';}
"+"			    {return '+';}
"*"			    {return '*';}
"/"			    {return '/';}
"%"			    {return '%';}
"<"			    {return '<';}
">"			    {return '>';}
"^"			    {return '^';}
"|"			    {return '|';}
"?"			    {return '?';}

{charVal}   {
    yylval.text = strdup(yytext);
    return CONSTANT;
}
{stringVal} {
    yylval.text = strdup(yytext);
    return STR_CONSTANT;
}
{boolVal}   {
    yylval.text = strdup(yytext);
    return CONSTANT;    
}
{number}    {
    yylval.text = strdup(yytext);
    return CONSTANT;
}

{identity}      {
    if(properties.find(yytext) == properties.end())
        properties[yytext] = cnt++;
    yylval.text = strdup(yytext);
    return ID;
    }


{whitespace}    { /* do nothing */}
.               { /* ignore bad characters */ }

%%

int yywrap() {
return 1;
}