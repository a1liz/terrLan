/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BOOL = 258,
    BREAK = 259,
    CASE = 260,
    CHAR = 261,
    CONTINUE = 262,
    DEFAULT = 263,
    DO = 264,
    ELSE = 265,
    FOR = 266,
    IF = 267,
    INT = 268,
    RETURN = 269,
    SWITCH = 270,
    VOID = 271,
    INPUT = 272,
    PRINT = 273,
    WHILE = 274,
    MAIN = 275,
    TRUE = 276,
    FALSE = 277,
    ID = 278,
    CONSTCHAR = 279,
    NUM = 280,
    RIGHT_OP = 281,
    LEFT_OP = 282,
    AND_OP = 283,
    OR_OP = 284,
    LE_OP = 285,
    GE_OP = 286,
    EQ_OP = 287,
    NE_OP = 288,
    ADD = 289,
    SUB = 290,
    MUL = 291,
    DIV = 292,
    MOD = 293,
    LT = 294,
    GT = 295,
    AND = 296,
    XOR = 297,
    OR = 298,
    INC_OP = 299,
    DEC_OP = 300,
    NOT = 301,
    TLIDE = 302,
    SEMICOLON = 303,
    LBRACE = 304,
    RBRACE = 305,
    LBRACKET = 306,
    RBRACKET = 307,
    COMMA = 308,
    COLON = 309,
    ASSIGN = 310,
    LPAREN = 311,
    RPAREN = 312,
    QUESTION = 313,
    IFX = 314
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef Node* YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
