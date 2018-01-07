/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

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

#line 82 "parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hpp".  */
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

/* Copy the second part of user declarations.  */

#line 193 "parser.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   299

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  160

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   314

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    45,    45,    53,    56,    59,    64,    67,    70,    75,
      78,    81,    84,    87,    90,    93,    98,   101,   104,   107,
     112,   115,   118,   123,   126,   129,   134,   137,   140,   143,
     146,   151,   154,   157,   162,   165,   168,   171,   176,   179,
     182,   187,   190,   195,   198,   203,   209,   212,   217,   220,
     225,   228,   231,   234,   239,   244,   247,   250,   253,   258,
     259,   260,   261,   262,   263,   264,   265,   268,   271,   276,
     279,   284,   287,   292,   295,   300,   303,   306,   309,   314,
     317,   320,   323,   328,   333
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BOOL", "BREAK", "CASE", "CHAR",
  "CONTINUE", "DEFAULT", "DO", "ELSE", "FOR", "IF", "INT", "RETURN",
  "SWITCH", "VOID", "INPUT", "PRINT", "WHILE", "MAIN", "TRUE", "FALSE",
  "ID", "CONSTCHAR", "NUM", "RIGHT_OP", "LEFT_OP", "AND_OP", "OR_OP",
  "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "ADD", "SUB", "MUL", "DIV", "MOD",
  "LT", "GT", "AND", "XOR", "OR", "INC_OP", "DEC_OP", "NOT", "TLIDE",
  "SEMICOLON", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "COMMA",
  "COLON", "ASSIGN", "LPAREN", "RPAREN", "QUESTION", "IFX", "$accept",
  "program", "primary_expression", "postfix_expression",
  "unary_expression", "multipy_expression", "additive_expression",
  "shift_expression", "relation_expression", "equal_expression",
  "bit_expression", "logical_expression", "assignment_expression",
  "expression", "declaration", "init_declaration_list", "init_declaration",
  "type_define", "identifier", "constant_val", "statement",
  "compound_statement", "statement_list", "expression_statement",
  "condition_statement", "loop_statement", "jump_statement",
  "input_statement", "print_statement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
# endif

#define YYPACT_NINF -77

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-77)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       9,   -20,    72,     0,   -77,    38,    21,   -77,   -77,    53,
     -77,    55,   189,    84,    90,   -77,   195,   -77,    93,   100,
     105,   -77,   -77,   -77,   -77,   -77,    57,    57,    57,    57,
      57,    57,   -77,   -77,    75,   -77,    30,   119,    14,    73,
      85,   -25,    95,    96,   142,   -77,   -35,   -77,   107,   -77,
     -77,   -77,   -77,   141,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   132,    70,    75,   -77,   -31,   107,    75,    75,
      30,    30,    30,    30,    30,    30,   -37,   -77,   -77,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,   -77,    75,
     -22,   -77,   126,   -77,   -77,   128,   225,   225,     5,   -77,
     137,     6,     7,   -77,   -77,   -77,   -77,   -77,   -77,    14,
      14,    73,    73,    85,    85,    85,    85,   -25,   -25,    95,
      95,    95,    96,    96,   -77,   -77,   107,    75,    75,    75,
      75,   189,   -77,   -77,   189,   -77,   -77,    31,    32,    49,
     194,   -77,   151,   189,   189,   189,   -77,   -77,   -77,   -77
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     2,    53,     0,
      51,     0,     0,     0,     0,    52,     0,    50,     0,     0,
       0,    57,    58,    54,    56,    55,     0,     0,     0,     0,
       0,     0,    71,    67,     0,     6,     9,    16,    20,    23,
      26,    31,    34,    38,    41,    43,     0,    66,     0,     3,
       4,    69,    59,     0,    60,    61,    62,    63,    64,    65,
      80,    79,     0,     0,     0,    81,     0,     0,     0,     0,
      12,    13,    10,    11,    15,    14,     0,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    72,     0,
       0,    46,    48,    68,    70,     0,     0,     0,     0,    82,
       0,     0,     0,     5,    42,    17,    18,    19,    16,    21,
      22,    25,    24,    30,    29,    28,    27,    32,    33,    35,
      36,    37,    39,    40,    44,    45,     0,     0,     0,     0,
       0,     0,    83,    84,     0,    47,    49,     0,     0,     0,
      73,    75,     0,     0,     0,     0,    76,    78,    77,    74
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -77,   -77,   -77,   -19,   202,    89,    92,    46,    88,    74,
      86,   -77,   -76,   -15,   146,   -77,    79,   -77,   -46,   -77,
     -12,   216,   -77,   -59,   -77,   -77,   -77,   -77,   -77
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,   100,   101,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      62,    66,   102,   114,   107,    87,    88,    70,    71,    72,
      73,    74,    75,    98,    89,    90,    99,   109,    99,    76,
     113,   110,    99,   134,     8,     9,   135,    10,    11,     1,
      12,   136,    13,    14,    15,    16,     3,    17,    18,    19,
      20,   104,    21,    22,    23,    24,    25,   139,   140,   108,
      80,    81,    82,   111,   112,    26,    27,     5,    99,    99,
      99,   146,   141,   143,   144,    28,    29,    30,    31,    32,
       6,    33,     4,     8,    77,    78,    10,    34,    21,    22,
      23,    24,    25,    15,    99,    99,    17,     6,   152,   153,
     102,    21,    22,    23,    24,    25,    21,    22,    23,    24,
      25,    60,    99,    61,    26,    27,   154,    83,    84,    26,
      27,    85,    86,    34,    28,    29,    30,    31,    32,    28,
      29,    30,    31,   147,   148,   149,    34,    91,    92,   150,
      23,    34,   151,   123,   124,   125,   126,    93,    94,    95,
      63,   157,   158,   159,     8,     9,    64,    10,    11,    67,
      12,   105,    13,    14,    15,    16,    68,    17,    18,    19,
      20,    69,    21,    22,    23,    24,    25,   129,   130,   131,
      96,    97,   119,   120,    79,    26,    27,   121,   122,   127,
     128,   137,   132,   133,   138,    28,    29,    30,    31,    32,
       6,   103,     8,     9,   142,    10,    11,    34,    12,   156,
      13,    14,    15,    16,   155,    17,    18,    19,    20,   106,
      21,    22,    23,    24,    25,   145,    21,    22,    23,    24,
      25,     7,     0,    26,    27,     0,     0,     0,     0,    26,
      27,     0,     0,    28,    29,    30,    31,    32,     6,    28,
      29,    30,    31,    65,     0,    34,    21,    22,    23,    24,
      25,    34,     0,     0,     0,     0,     0,     0,     0,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,    28,
      29,    30,    31,    32,     0,     0,     0,     0,     0,     0,
       0,    34,   115,   116,   117,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118
};

static const yytype_int16 yycheck[] =
{
      12,    16,    48,    79,    63,    30,    31,    26,    27,    28,
      29,    30,    31,    48,    39,    40,    53,    48,    53,    34,
      57,    67,    53,    99,     3,     4,    48,     6,     7,    20,
       9,    53,    11,    12,    13,    14,    56,    16,    17,    18,
      19,    53,    21,    22,    23,    24,    25,   106,   107,    64,
      36,    37,    38,    68,    69,    34,    35,    57,    53,    53,
      53,   137,    57,    57,    57,    44,    45,    46,    47,    48,
      49,    50,     0,     3,    44,    45,     6,    56,    21,    22,
      23,    24,    25,    13,    53,    53,    16,    49,    57,    57,
     136,    21,    22,    23,    24,    25,    21,    22,    23,    24,
      25,    48,    53,    48,    34,    35,    57,    34,    35,    34,
      35,    26,    27,    56,    44,    45,    46,    47,    48,    44,
      45,    46,    47,   138,   139,   140,    56,    32,    33,   141,
      23,    56,   144,    87,    88,    89,    90,    41,    42,    43,
      56,   153,   154,   155,     3,     4,    56,     6,     7,    56,
       9,    19,    11,    12,    13,    14,    56,    16,    17,    18,
      19,    56,    21,    22,    23,    24,    25,    93,    94,    95,
      28,    29,    83,    84,    55,    34,    35,    85,    86,    91,
      92,    55,    96,    97,    56,    44,    45,    46,    47,    48,
      49,    50,     3,     4,    57,     6,     7,    56,     9,    48,
      11,    12,    13,    14,    10,    16,    17,    18,    19,    63,
      21,    22,    23,    24,    25,   136,    21,    22,    23,    24,
      25,     5,    -1,    34,    35,    -1,    -1,    -1,    -1,    34,
      35,    -1,    -1,    44,    45,    46,    47,    48,    49,    44,
      45,    46,    47,    48,    -1,    56,    21,    22,    23,    24,
      25,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    61,    56,     0,    57,    49,    81,     3,     4,
       6,     7,     9,    11,    12,    13,    14,    16,    17,    18,
      19,    21,    22,    23,    24,    25,    34,    35,    44,    45,
      46,    47,    48,    50,    56,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      48,    48,    80,    56,    56,    48,    73,    56,    56,    56,
      63,    63,    63,    63,    63,    63,    73,    44,    45,    55,
      36,    37,    38,    34,    35,    26,    27,    30,    31,    39,
      40,    32,    33,    41,    42,    43,    28,    29,    48,    53,
      75,    76,    78,    50,    80,    19,    74,    83,    73,    48,
      78,    73,    73,    57,    72,    64,    64,    64,    64,    65,
      65,    66,    66,    67,    67,    67,    67,    68,    68,    69,
      69,    69,    70,    70,    72,    48,    53,    55,    56,    83,
      83,    57,    57,    57,    57,    76,    72,    73,    73,    73,
      80,    80,    57,    57,    57,    10,    48,    80,    80,    80
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    62,    62,    62,    63,    63,    63,    64,
      64,    64,    64,    64,    64,    64,    65,    65,    65,    65,
      66,    66,    66,    67,    67,    67,    68,    68,    68,    68,
      68,    69,    69,    69,    70,    70,    70,    70,    71,    71,
      71,    72,    72,    73,    73,    74,    75,    75,    76,    76,
      77,    77,    77,    77,    78,    79,    79,    79,    79,    80,
      80,    80,    80,    80,    80,    80,    80,    81,    81,    82,
      82,    83,    83,    84,    84,    85,    85,    85,    85,    86,
      86,    86,    86,    87,    88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     1,     1,     3,     1,     2,     2,     1,
       2,     2,     2,     2,     2,     2,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     3,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     1,
       2,     1,     2,     5,     7,     5,     7,     7,     7,     2,
       2,     2,     3,     4,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 45 "parser.y" /* yacc.c:1646  */
    { 
      	(yyval) = tree.NewRoot(STMT_NODE,PROGRAM,Notype,0,(yyvsp[0]));
      	tree.type_check_all((yyval));
	  	ofstream out = ofstream("test.asm");
    	tree.gen_code(out);
		}
#line 1420 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 53 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
					}
#line 1428 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 56 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
					}
#line 1436 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 59 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[-1]);
					}
#line 1444 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 64 "parser.y" /* yacc.c:1646  */
    {
						(yyval) = (yyvsp[0]);
					}
#line 1452 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 67 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = tree.NewRoot(EXPR_NODE,POST_INC,(yyvsp[-1])->valuetype,0,(yyvsp[-1]));
					}
#line 1460 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 70 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = tree.NewRoot(EXPR_NODE,POST_DEC,(yyvsp[-1])->valuetype,0,(yyvsp[-1]));
					}
#line 1468 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 75 "parser.y" /* yacc.c:1646  */
    { 
					(yyval) = (yyvsp[0]); 
				}
#line 1476 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 78 "parser.y" /* yacc.c:1646  */
    {
          (yyval) = tree.NewRoot(EXPR_NODE,PRE_INC,(yyvsp[0])->valuetype,0,(yyvsp[0]));
				}
#line 1484 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 81 "parser.y" /* yacc.c:1646  */
    {
          (yyval) = tree.NewRoot(EXPR_NODE,PRE_DEC,(yyvsp[0])->valuetype,0,(yyvsp[0]));
				}
#line 1492 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 84 "parser.y" /* yacc.c:1646  */
    {
          (yyval) = tree.NewRoot(EXPR_NODE,POSITIVE,(yyvsp[0])->valuetype,0,(yyvsp[0]));
				}
#line 1500 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 87 "parser.y" /* yacc.c:1646  */
    {
          (yyval) = tree.NewRoot(EXPR_NODE,NEGATIVE,(yyvsp[0])->valuetype,0,(yyvsp[0]));
				}
#line 1508 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 90 "parser.y" /* yacc.c:1646  */
    {
          (yyval) = tree.NewRoot(EXPR_NODE,BNOT,(yyvsp[0])->valuetype,0,(yyvsp[0]));
				}
#line 1516 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 93 "parser.y" /* yacc.c:1646  */
    {
          (yyval) = tree.NewRoot(EXPR_NODE,LNOT,Boolean,0,(yyvsp[0]));
				}
#line 1524 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 98 "parser.y" /* yacc.c:1646  */
    {
					(yyval) = (yyvsp[0]);
				}
#line 1532 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 101 "parser.y" /* yacc.c:1646  */
    {
          (yyval) = tree.NewRoot(EXPR_NODE,MUL_OP,(yyvsp[-2])->valuetype,0,(yyvsp[-2]),(yyvsp[0]));
				}
#line 1540 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 104 "parser.y" /* yacc.c:1646  */
    {
          (yyval) = tree.NewRoot(EXPR_NODE,DIV_OP,(yyvsp[-2])->valuetype,0,(yyvsp[-2]),(yyvsp[0]));
				}
#line 1548 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 107 "parser.y" /* yacc.c:1646  */
    {
          (yyval) = tree.NewRoot(EXPR_NODE,MOD_OP,(yyvsp[-2])->valuetype,0,(yyvsp[-2]),(yyvsp[0]));
				}
#line 1556 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 112 "parser.y" /* yacc.c:1646  */
    {
					(yyval) = (yyvsp[0]);
				}
#line 1564 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 115 "parser.y" /* yacc.c:1646  */
    {
          (yyval) = tree.NewRoot(EXPR_NODE,ADD_OP,(yyvsp[-2])->valuetype,0,(yyvsp[-2]),(yyvsp[0]));
				}
#line 1572 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 118 "parser.y" /* yacc.c:1646  */
    {
					(yyval) = tree.NewRoot(EXPR_NODE,SUB_OP,(yyvsp[-2])->valuetype,0,(yyvsp[-2]),(yyvsp[0]));
				}
#line 1580 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 123 "parser.y" /* yacc.c:1646  */
    {
					(yyval) = (yyvsp[0]);
				}
#line 1588 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 126 "parser.y" /* yacc.c:1646  */
    {
					(yyval) = tree.NewRoot(EXPR_NODE,LSHIFT,(yyvsp[-2])->valuetype,0,(yyvsp[-2]),(yyvsp[0]));
				}
#line 1596 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 129 "parser.y" /* yacc.c:1646  */
    {
          (yyval) = tree.NewRoot(EXPR_NODE,RSHIFT,(yyvsp[-2])->valuetype,0,(yyvsp[-2]),(yyvsp[0]));
				}
#line 1604 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 134 "parser.y" /* yacc.c:1646  */
    {
					(yyval) = (yyvsp[0]);
				}
#line 1612 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 137 "parser.y" /* yacc.c:1646  */
    {
          (yyval) = tree.NewRoot(EXPR_NODE,GREATER,Boolean,0,(yyvsp[-2]),(yyvsp[0]));
				}
#line 1620 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 140 "parser.y" /* yacc.c:1646  */
    {
          (yyval) = tree.NewRoot(EXPR_NODE,LESS,Boolean,0,(yyvsp[-2]),(yyvsp[0]));
				}
#line 1628 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 143 "parser.y" /* yacc.c:1646  */
    {
          (yyval) = tree.NewRoot(EXPR_NODE,GREATEREQ,Boolean,0,(yyvsp[-2]),(yyvsp[0]));
				}
#line 1636 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 146 "parser.y" /* yacc.c:1646  */
    {
          (yyval) = tree.NewRoot(EXPR_NODE,LESSEQ,Boolean,0,(yyvsp[-2]),(yyvsp[0]));
				}
#line 1644 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 151 "parser.y" /* yacc.c:1646  */
    {
					(yyval) = (yyvsp[0]);
				}
#line 1652 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 154 "parser.y" /* yacc.c:1646  */
    {
          (yyval) = tree.NewRoot(EXPR_NODE,EQUAL,Boolean,0,(yyvsp[-2]),(yyvsp[0]));
				}
#line 1660 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 157 "parser.y" /* yacc.c:1646  */
    {
          (yyval) = tree.NewRoot(EXPR_NODE,NEQUAL,Boolean,0,(yyvsp[-2]),(yyvsp[0]));
				}
#line 1668 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 162 "parser.y" /* yacc.c:1646  */
    {
					(yyval) = (yyvsp[0]);
				}
#line 1676 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 165 "parser.y" /* yacc.c:1646  */
    {
          (yyval) = tree.NewRoot(EXPR_NODE,BAND,(yyvsp[-2])->valuetype,0,(yyvsp[-2]),(yyvsp[0]));
				}
#line 1684 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 168 "parser.y" /* yacc.c:1646  */
    {
          (yyval) = tree.NewRoot(EXPR_NODE,BXOR,(yyvsp[-2])->valuetype,0,(yyvsp[-2]),(yyvsp[0]));
        }
#line 1692 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 171 "parser.y" /* yacc.c:1646  */
    {
          (yyval) = tree.NewRoot(EXPR_NODE,BOR,(yyvsp[-2])->valuetype,0,(yyvsp[-2]),(yyvsp[0]));
        }
#line 1700 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 176 "parser.y" /* yacc.c:1646  */
    {
					(yyval) = (yyvsp[0]);
				}
#line 1708 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 179 "parser.y" /* yacc.c:1646  */
    {
          (yyval) = tree.NewRoot(EXPR_NODE,LAND,Boolean,0,(yyvsp[-2]),(yyvsp[0]));
				}
#line 1716 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 182 "parser.y" /* yacc.c:1646  */
    {
          (yyval) = tree.NewRoot(EXPR_NODE,LOR,Boolean,0,(yyvsp[-2]),(yyvsp[0]));
        }
#line 1724 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 187 "parser.y" /* yacc.c:1646  */
    {
							(yyval) = (yyvsp[0]);
						}
#line 1732 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 190 "parser.y" /* yacc.c:1646  */
    {
              (yyval) = tree.NewRoot(EXPR_NODE,ASSIGN_EXPR,(yyvsp[-2])->valuetype,0,(yyvsp[-2]),(yyvsp[0]));
						}
#line 1740 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 195 "parser.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
			}
#line 1748 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 198 "parser.y" /* yacc.c:1646  */
    {
        (yyval) = tree.NewRoot(EXPR_NODE,COMMA_EXPR,(yyvsp[-2])->valuetype,0,(yyvsp[-2]),(yyvsp[0]));
			}
#line 1756 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 203 "parser.y" /* yacc.c:1646  */
    {
        (yyvsp[-1])->setChildValuetype((yyvsp[-2])->valuetype);
        (yyval) = tree.NewRoot(STMT_NODE,DECLARE,(yyvsp[-2])->valuetype,0,(yyvsp[-2]),(yyvsp[-1]));
			}
#line 1765 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 209 "parser.y" /* yacc.c:1646  */
    {
						(yyval) = (yyvsp[0]);
					}
#line 1773 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 212 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = tree.NewRoot(STMT_NODE,INIT_DECL_LIST,Notype,0,(yyvsp[-2]),(yyvsp[0]));
					}
#line 1781 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 217 "parser.y" /* yacc.c:1646  */
    {
					(yyval) = (yyvsp[0]);
				}
#line 1789 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 220 "parser.y" /* yacc.c:1646  */
    {
          (yyval) = tree.NewRoot(EXPR_NODE,ASSIGN_EXPR,(yyvsp[-2])->valuetype,0,(yyvsp[-2]),(yyvsp[0]));
				}
#line 1797 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 225 "parser.y" /* yacc.c:1646  */
    {
        (yyval) = tree.NewRoot(DECL_NODE,VOID_DECL,Void,0);
			}
#line 1805 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 228 "parser.y" /* yacc.c:1646  */
    {
        (yyval) = tree.NewRoot(DECL_NODE,CHAR_DECL,Character,0);
			}
#line 1813 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 231 "parser.y" /* yacc.c:1646  */
    {
        (yyval) = tree.NewRoot(DECL_NODE,INT_DECL,Integer,0);
			}
#line 1821 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 234 "parser.y" /* yacc.c:1646  */
    {
        (yyval) = tree.NewRoot(DECL_NODE,BOOL_DECL,Boolean,0);
			}
#line 1829 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 239 "parser.y" /* yacc.c:1646  */
    {
        (yyval) = tree.NewRoot(ID_NODE,0,(yyvsp[0])->valuetype,(yyvsp[0])->attr.symbtl_seq);
			}
#line 1837 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 244 "parser.y" /* yacc.c:1646  */
    {
        (yyval) = tree.NewRoot(DECL_NODE,CONST_EXPR,Integer,(yyvsp[0])->attr.vali);
			}
#line 1845 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 247 "parser.y" /* yacc.c:1646  */
    {
        (yyval) = tree.NewRoot(DECL_NODE,CONST_EXPR,Character,(yyvsp[0])->attr.valc);
			}
#line 1853 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 250 "parser.y" /* yacc.c:1646  */
    {
        (yyval) = tree.NewRoot(DECL_NODE,CONST_EXPR,Boolean,true);
			}
#line 1861 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 253 "parser.y" /* yacc.c:1646  */
    {
				(yyval) = tree.NewRoot(DECL_NODE,CONST_EXPR,Boolean,false);
			}
#line 1869 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 258 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1875 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 259 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1881 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 260 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1887 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 261 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1893 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 262 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1899 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 263 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1905 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 264 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1911 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 265 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1917 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 268 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = tree.NewRoot(STMT_NODE,0,Notype,0);
					}
#line 1925 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 271 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = tree.NewRoot(STMT_NODE,COMP_STMT,Notype,0,(yyvsp[-1]));
					}
#line 1933 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 276 "parser.y" /* yacc.c:1646  */
    {
					(yyval) = (yyvsp[0]);
				}
#line 1941 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 279 "parser.y" /* yacc.c:1646  */
    {
          (yyval) = tree.NewRoot(STMT_NODE,STMTS,Notype,0,(yyvsp[-1]),(yyvsp[0]));
				}
#line 1949 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 284 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = tree.NewRoot(STMT_NODE, EXPR_STMT,Notype,0);
					}
#line 1957 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 287 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = tree.NewRoot(STMT_NODE, EXPR_STMT, Notype,0,(yyvsp[-1]));
					}
#line 1965 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 292 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = tree.NewRoot(STMT_NODE,IF_STMT,Notype,0,(yyvsp[-2]),(yyvsp[0]));
					}
#line 1973 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 295 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = tree.NewRoot(STMT_NODE,IF_ELSE_STMT,Notype,0,(yyvsp[-4]),(yyvsp[-2]),(yyvsp[0]));
					}
#line 1981 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 300 "parser.y" /* yacc.c:1646  */
    {
          (yyval) = tree.NewRoot(STMT_NODE,WHILE_STMT,Notype,0,(yyvsp[-2]),(yyvsp[0]));
				}
#line 1989 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 303 "parser.y" /* yacc.c:1646  */
    {
          (yyval) = tree.NewRoot(STMT_NODE,DO_WHILE_STMT,Notype,0,(yyvsp[-5]),(yyvsp[-2]));
				}
#line 1997 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 306 "parser.y" /* yacc.c:1646  */
    {
					(yyval) = tree.NewRoot(STMT_NODE,FOR_STMT,Notype,0,(yyvsp[-4]),(yyvsp[-3]),(yyvsp[-2]),(yyvsp[0]));
				}
#line 2005 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 309 "parser.y" /* yacc.c:1646  */
    {
					(yyval) = tree.NewRoot(STMT_NODE,FOR_STMT,Notype,0,(yyvsp[-4]),(yyvsp[-3]),(yyvsp[-2]),(yyvsp[0]));
				}
#line 2013 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 314 "parser.y" /* yacc.c:1646  */
    {
          (yyval) = tree.NewRoot(STMT_NODE,CONTINUE_OP,Notype,0);
				}
#line 2021 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 317 "parser.y" /* yacc.c:1646  */
    {
          (yyval) = tree.NewRoot(STMT_NODE,BREAK_OP,Notype,0);
				}
#line 2029 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 320 "parser.y" /* yacc.c:1646  */
    {
          (yyval) = tree.NewRoot(STMT_NODE,RETURN_OP,Void,0);
				}
#line 2037 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 323 "parser.y" /* yacc.c:1646  */
    {
          (yyval) = tree.NewRoot(STMT_NODE,RETURN_OP,(yyvsp[-1])->valuetype,0,(yyvsp[-1]));
				}
#line 2045 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 328 "parser.y" /* yacc.c:1646  */
    {
        (yyval) = tree.NewRoot(STMT_NODE,INPUT_OP,Notype,0,(yyvsp[-1]));
			}
#line 2053 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 333 "parser.y" /* yacc.c:1646  */
    {
        (yyval) = tree.NewRoot(STMT_NODE,PRINT_OP,Notype,0,(yyvsp[-1]));
			}
#line 2061 "parser.cpp" /* yacc.c:1646  */
    break;


#line 2065 "parser.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 338 "parser.y" /* yacc.c:1906  */


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
