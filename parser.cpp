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
#include "tree.h"
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
    AUTO = 258,
    BOOL = 259,
    BREAK = 260,
    CASE = 261,
    CHAR = 262,
    CONST = 263,
    CONTINUE = 264,
    DEFAULT = 265,
    DO = 266,
    DOUBLE = 267,
    ELSE = 268,
    EXTERN = 269,
    FLOAT = 270,
    FOR = 271,
    GOTO = 272,
    IF = 273,
    INT = 274,
    LONG = 275,
    REGISTER = 276,
    RETURN = 277,
    SHORT = 278,
    SIZEOF = 279,
    STATIC = 280,
    SWITCH = 281,
    VOID = 282,
    WHILE = 283,
    TRUE = 284,
    FALSE = 285,
    ID = 286,
    CONSTANT = 287,
    STR_CONSTANT = 288,
    RIGHT_ASSIGN = 289,
    LEFT_ASSIGN = 290,
    ADD_ASSIGN = 291,
    SUB_ASSIGN = 292,
    MUL_ASSIGN = 293,
    DIV_ASSIGN = 294,
    MOD_ASSIGN = 295,
    AND_ASSIGN = 296,
    XOR_ASSIGN = 297,
    OR_ASSIGN = 298,
    RIGHT_OP = 299,
    LEFT_OP = 300,
    INC_OP = 301,
    DEC_OP = 302,
    PTR_OP = 303,
    AND_OP = 304,
    OR_OP = 305,
    LE_OP = 306,
    GE_OP = 307,
    EQ_OP = 308,
    NE_OP = 309
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef NodeAttr YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 188 "parser.cpp" /* yacc.c:358  */

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
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   695

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  153
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  258

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    77,     2,     2,     2,    65,    58,     2,
      66,    67,    63,    61,    55,    62,    78,    64,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    75,    68,
      60,    69,    59,    74,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    70,     2,    71,    57,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    72,    56,    73,    76,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    44,    44,    52,    58,    67,    73,    81,    90,   100,
     107,   115,   119,   123,   127,   133,   134,   135,   136,   137,
     138,   139,   140,   143,   152,   153,   156,   157,   159,   160,
     161,   164,   173,   185,   194,   206,   212,   218,   224,   231,
     238,   245,   253,   260,   268,   274,   282,   288,   297,   303,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   326,   332,   342,   348,   359,   372,   378,   389,   400,
     413,   419,   430,   443,   449,   460,   471,   482,   495,   501,
     512,   525,   531,   542,   555,   561,   572,   583,   596,   602,
     611,   617,   626,   630,   634,   638,   642,   646,   652,   658,
     665,   671,   678,   685,   696,   706,   718,   724,   732,   738,
     744,   750,   758,   765,   770,   774,   780,   788,   794,   803,
     812,   816,   824,   830,   836,   843,   852,   858,   867,   873,
     882,   883,   884,   885,   886,   887,   890,   897,   908,   920,
     924,   932,   943,   955,   968,   974,   983,   994,  1005,  1020,
    1030,  1039,  1048,  1057
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AUTO", "BOOL", "BREAK", "CASE", "CHAR",
  "CONST", "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "EXTERN",
  "FLOAT", "FOR", "GOTO", "IF", "INT", "LONG", "REGISTER", "RETURN",
  "SHORT", "SIZEOF", "STATIC", "SWITCH", "VOID", "WHILE", "TRUE", "FALSE",
  "ID", "CONSTANT", "STR_CONSTANT", "RIGHT_ASSIGN", "LEFT_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "RIGHT_OP", "LEFT_OP", "INC_OP",
  "DEC_OP", "PTR_OP", "AND_OP", "OR_OP", "LE_OP", "GE_OP", "EQ_OP",
  "NE_OP", "','", "'|'", "'^'", "'&'", "'>'", "'<'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'('", "')'", "';'", "'='", "'['", "']'", "'{'", "'}'",
  "'?'", "':'", "'~'", "'!'", "'.'", "$accept", "program",
  "translation_unit", "external_declaration", "function_definition",
  "declaration_prefix", "special_specifier", "type_define", "declaration",
  "init_declaration_list", "init_declaration", "declaration_item",
  "pointer", "refer", "simple_item", "identifier_list", "initializer",
  "initializer_list", "assignment_expr", "assignment_op", "condition_expr",
  "logical_expr", "bit_expr", "equality_expr", "relational_expr",
  "shift_expr", "add_expr", "mul_expr", "cast_expr", "unary_expr",
  "unary_op", "postfix_expr", "argument_expr_list", "primary_expr",
  "identifier", "constant_expr", "str_constant", "parameter_list",
  "parameter_declaration", "compound_statement", "compound_statement_list",
  "declaration_list", "statement_list", "statement", "labeled_statement",
  "expr_statement", "condition_statement", "expr", "loop_statement",
  "jump_statement", YY_NULLPTR
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
     305,   306,   307,   308,   309,    44,   124,    94,    38,    62,
      60,    43,    45,    42,    47,    37,    40,    41,    59,    61,
      91,    93,   123,   125,    63,    58,   126,    33,    46
};
# endif

#define YYPACT_NINF -206

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-206)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     668,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,    34,   668,  -206,  -206,   -23,   101,  -206,
    -206,  -206,  -206,  -206,   -42,   -25,   -23,   -29,  -206,     5,
      -1,    -1,   -33,     2,  -206,  -206,  -206,    56,  -206,   -23,
    -206,   529,   -33,   -33,   505,   -12,   530,  -206,  -206,  -206,
    -206,  -206,  -206,  -206,  -206,  -206,  -206,   377,   529,  -206,
    -206,  -206,  -206,  -206,   -18,   103,    40,    74,    87,   120,
     109,  -206,   183,   602,     6,  -206,  -206,  -206,  -206,  -206,
     -23,    14,  -206,    15,  -206,  -206,    94,    55,    16,   127,
    -206,    23,  -206,   -27,   602,   602,   602,   602,   602,   602,
     602,   602,   602,   602,   602,   602,   602,   602,   602,   602,
     602,   602,   602,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,  -206,   602,  -206,  -206,  -206,  -206,   139,
     537,   602,   139,  -206,   139,  -206,   668,  -206,  -206,   239,
    -206,    55,   602,   602,  -206,   529,  -206,   103,   103,   -31,
      40,    40,    40,    74,    74,    87,    87,    87,    87,   120,
     120,   109,   109,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
      42,   -30,  -206,  -206,  -206,   108,   126,   131,   125,   439,
     129,   139,   135,   578,   136,   137,  -206,  -206,   -23,  -206,
     132,  -206,   314,   668,   439,  -206,  -206,  -206,  -206,     7,
    -206,  -206,  -206,  -206,  -206,  -206,   602,   602,  -206,  -206,
    -206,   134,  -206,   439,   176,   590,   138,   602,  -206,    11,
     602,   602,   439,  -206,   668,   439,  -206,  -206,  -206,  -206,
    -206,   439,  -206,   144,   590,  -206,    43,  -206,    44,    52,
    -206,  -206,   602,   602,   439,   439,   439,    63,   102,   198,
    -206,  -206,   145,   439,   439,  -206,  -206,  -206
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    13,    19,    16,    18,    11,    20,    17,    21,    14,
      22,    12,    15,     0,     2,     3,     5,     0,     0,    10,
       6,     1,     4,   112,    33,    31,     0,     0,    24,    26,
       0,     0,    30,    35,     9,    34,    32,     0,    35,     0,
      23,     0,    28,    29,     0,     0,     0,    36,    25,   114,
     115,   113,   116,    96,    97,    92,    93,     0,     0,    94,
      95,    27,    44,    48,    61,    63,    66,    70,    73,    78,
      81,    84,    88,     0,    90,    98,   108,   109,   111,    41,
       0,     0,    43,     0,   117,    37,     0,     0,     0,     0,
     144,     0,    46,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    57,    56,    51,    52,    53,    54,    55,
      58,    59,    60,    50,     0,    91,    88,   104,   105,     0,
       0,     0,     0,   119,     0,    40,     0,    39,    38,     0,
       8,     0,     0,     0,   110,     0,    45,    65,    64,     0,
      69,    68,    67,    71,    72,    76,    77,    75,    74,    79,
      80,    82,    83,    85,    86,    87,    49,   103,   100,   106,
       0,     0,   102,    42,   118,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   139,   120,     0,   126,
     108,   131,     0,   123,   122,   128,   130,   132,   133,     0,
     134,   135,     7,    89,   145,    47,     0,     0,   101,    99,
     151,     0,   150,     0,     0,     0,     0,     0,   152,     0,
       0,     0,     0,   121,   124,   125,   127,   129,   140,    62,
     107,     0,   138,     0,     0,   149,     0,   153,     0,     0,
     136,   137,     0,     0,     0,     0,     0,     0,     0,   141,
     143,   146,     0,     0,     0,   147,   148,   142
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -206,  -206,  -206,   201,  -206,     1,  -206,    -6,  -135,  -206,
     173,   -20,   191,   206,   154,  -206,   -53,  -206,   -39,  -206,
      25,  -206,    92,    81,    90,    -2,    86,    89,   -62,    41,
    -206,  -206,  -206,  -206,   -17,   -22,  -206,   186,    97,   -80,
    -206,    46,    47,  -158,  -206,  -205,  -206,   -54,  -206,  -206
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    14,    15,    16,   188,    18,    19,    20,    27,
      28,    29,    30,    31,    32,    81,    61,    93,    90,   124,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,   170,    75,    76,    77,    78,    83,    84,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      33,    17,    62,    91,   189,    92,    37,   140,    23,    38,
     234,   125,    34,    38,    38,    17,    24,    49,    50,    62,
      51,   214,    38,    86,   143,   143,    39,    82,   145,   243,
      23,    94,    95,    44,    21,    24,   227,    45,    25,    40,
      25,   209,   149,    26,   206,    80,   146,    80,   163,   164,
     165,    89,   127,   128,   129,   232,    96,   189,   226,    85,
     133,   202,   143,    38,   240,    26,   143,   227,    46,   134,
     136,   136,   130,   241,    41,   228,   131,   171,   143,   237,
     203,   135,   137,   141,   132,   166,   249,   250,   251,   226,
     144,   169,   205,   100,   101,   256,   257,   207,   143,   143,
     155,   156,   157,   158,   204,     2,    62,   143,     3,   208,
     244,   245,   167,     4,   126,   172,     6,   173,   143,   246,
       7,     8,   190,    47,    10,   102,   103,   139,    12,   219,
     252,   106,   107,   104,   105,   126,   126,    80,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   211,    49,    50,   143,    51,    97,
      98,    99,   190,   236,   216,   138,   238,   239,   230,   253,
      23,    38,   110,   111,   112,   190,   210,   190,   150,   151,
     152,   108,   109,   126,    42,    43,   147,   148,   247,   248,
     153,   154,   159,   160,   142,   215,   190,   161,   162,   212,
     213,   217,   220,   221,   233,   190,   235,   222,   190,   231,
     242,   254,    48,   255,   190,    22,    36,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   190,   190,   190,
      35,   229,    88,   174,     0,     0,   190,   190,   224,   225,
       0,     0,     1,     2,   175,   176,     3,   126,   177,   178,
     179,     4,   123,     5,     6,   180,   181,   182,     7,     8,
       9,   183,    10,     0,    11,   184,    12,   185,    49,    50,
      23,    51,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,    56,     0,     0,     0,    57,     0,   186,     0,     0,
       0,   139,   187,     0,     0,    59,    60,     1,     2,   175,
     176,     3,     0,   177,   178,   179,     4,     0,     5,     6,
     180,   181,   182,     7,     8,     9,   183,    10,     0,    11,
     184,    12,   185,    49,    50,    23,    51,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,    56,     0,     0,     0,
      57,     2,   186,     0,     3,     0,   139,   223,     0,     4,
      59,    60,     6,     0,     0,     0,     7,     8,     0,     0,
      10,     0,     0,     0,    12,     0,    49,    50,    23,    51,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,    56,
       0,     0,     0,    57,   175,   176,     0,     0,   177,   178,
     179,     0,     0,    59,    60,   180,   181,   182,     0,     0,
       0,   183,     0,     0,     0,   184,     0,   185,    49,    50,
      23,    51,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,    56,     0,     0,     0,    57,     0,   186,     1,     2,
       0,   139,     3,     0,     0,    59,    60,     4,     0,     5,
       6,     0,     0,     0,     7,     8,     9,     0,    10,     0,
      11,     0,    12,     1,     2,     0,    23,     3,     0,     0,
       0,     0,     4,     0,     5,     6,     0,     0,     0,     7,
       8,     9,     0,    10,     0,    11,     0,    12,    49,    50,
      23,    51,    52,     0,     0,     0,    49,    50,    23,    51,
      52,     0,    79,     0,     0,    53,    54,     0,     0,     0,
       0,     0,     0,    53,    54,     0,     0,     0,     0,     0,
      55,    56,     0,     0,     0,    57,     0,    87,    55,    56,
       0,    58,     0,    57,   168,    59,    60,    49,    50,    23,
      51,    52,     0,    59,    60,     0,     0,     0,     0,    49,
      50,    23,    51,    52,    53,    54,     0,     0,     0,     0,
       0,    49,    50,    23,    51,    52,    53,    54,     0,    55,
      56,     0,     0,     0,    57,     0,   218,     0,    53,    54,
       0,    55,    56,     0,    59,    60,    57,     0,   186,     0,
       0,     0,     0,    55,    56,     0,    59,    60,    57,     0,
       0,     1,     2,     0,     0,     3,     0,     0,    59,    60,
       4,     0,     5,     6,     0,     0,     0,     7,     8,     9,
       0,    10,     0,    11,     0,    12
};

static const yytype_int16 yycheck[] =
{
      17,     0,    41,    57,   139,    58,    26,    87,    31,    26,
     215,    73,    18,    30,    31,    14,    58,    29,    30,    58,
      32,   179,    39,    45,    55,    55,    55,    44,    55,   234,
      31,    49,    50,    66,     0,    58,   194,    70,    63,    68,
      63,    71,    96,    66,    75,    44,    73,    46,   110,   111,
     112,    57,    46,    47,    48,   213,    74,   192,   193,    71,
      80,   141,    55,    80,   222,    66,    55,   225,    66,    55,
      55,    55,    66,   231,    69,    68,    70,   131,    55,    68,
     142,    67,    67,    67,    78,   124,   244,   245,   246,   224,
      67,   130,   145,    53,    54,   253,   254,    55,    55,    55,
     102,   103,   104,   105,   143,     4,   145,    55,     7,    67,
      67,    67,   129,    12,    73,   132,    15,   134,    55,    67,
      19,    20,   139,    67,    23,    51,    52,    72,    27,   183,
      67,    44,    45,    59,    60,    94,    95,   136,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   176,    29,    30,    55,    32,    56,
      57,    58,   179,   217,   181,    71,   220,   221,   207,    67,
      31,   188,    63,    64,    65,   192,    68,   194,    97,    98,
      99,    61,    62,   142,    30,    31,    94,    95,   242,   243,
     100,   101,   106,   107,    67,    66,   213,   108,   109,    68,
      75,    66,    66,    66,    28,   222,    68,    75,   225,    75,
      66,    13,    39,    68,   231,    14,    25,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,   244,   245,   246,
      24,   206,    46,   136,    -1,    -1,   253,   254,   192,   192,
      -1,    -1,     3,     4,     5,     6,     7,   206,     9,    10,
      11,    12,    69,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    -1,    -1,    -1,    66,    -1,    68,    -1,    -1,
      -1,    72,    73,    -1,    -1,    76,    77,     3,     4,     5,
       6,     7,    -1,     9,    10,    11,    12,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,
      66,     4,    68,    -1,     7,    -1,    72,    73,    -1,    12,
      76,    77,    15,    -1,    -1,    -1,    19,    20,    -1,    -1,
      23,    -1,    -1,    -1,    27,    -1,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      -1,    -1,    -1,    66,     5,     6,    -1,    -1,     9,    10,
      11,    -1,    -1,    76,    77,    16,    17,    18,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    26,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    -1,    -1,    -1,    66,    -1,    68,     3,     4,
      -1,    72,     7,    -1,    -1,    76,    77,    12,    -1,    14,
      15,    -1,    -1,    -1,    19,    20,    21,    -1,    23,    -1,
      25,    -1,    27,     3,     4,    -1,    31,     7,    -1,    -1,
      -1,    -1,    12,    -1,    14,    15,    -1,    -1,    -1,    19,
      20,    21,    -1,    23,    -1,    25,    -1,    27,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    -1,    67,    -1,    -1,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    -1,    -1,    -1,    -1,    -1,
      61,    62,    -1,    -1,    -1,    66,    -1,    67,    61,    62,
      -1,    72,    -1,    66,    67,    76,    77,    29,    30,    31,
      32,    33,    -1,    76,    77,    -1,    -1,    -1,    -1,    29,
      30,    31,    32,    33,    46,    47,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    46,    47,    -1,    61,
      62,    -1,    -1,    -1,    66,    -1,    68,    -1,    46,    47,
      -1,    61,    62,    -1,    76,    77,    66,    -1,    68,    -1,
      -1,    -1,    -1,    61,    62,    -1,    76,    77,    66,    -1,
      -1,     3,     4,    -1,    -1,     7,    -1,    -1,    76,    77,
      12,    -1,    14,    15,    -1,    -1,    -1,    19,    20,    21,
      -1,    23,    -1,    25,    -1,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     7,    12,    14,    15,    19,    20,    21,
      23,    25,    27,    80,    81,    82,    83,    84,    85,    86,
      87,     0,    82,    31,    58,    63,    66,    88,    89,    90,
      91,    92,    93,   113,    86,    92,    91,    90,   113,    55,
      68,    69,    93,    93,    66,    70,    66,    67,    89,    29,
      30,    32,    33,    46,    47,    61,    62,    66,    72,    76,
      77,    95,    97,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   112,   113,   114,   115,    67,
      84,    94,   113,   116,   117,    71,   114,    67,   116,    86,
      97,   126,    95,    96,    49,    50,    74,    56,    57,    58,
      53,    54,    51,    52,    59,    60,    44,    45,    61,    62,
      63,    64,    65,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    69,    98,   107,   108,    46,    47,    48,
      66,    70,    78,    90,    55,    67,    55,    67,    71,    72,
     118,    67,    67,    55,    67,    55,    73,   101,   101,   126,
     102,   102,   102,   103,   103,   104,   104,   104,   104,   105,
     105,   106,   106,   107,   107,   107,    97,   113,    67,    97,
     111,   126,   113,   113,   117,     5,     6,     9,    10,    11,
      16,    17,    18,    22,    26,    28,    68,    73,    84,    87,
     113,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   118,   107,    97,    95,    75,    55,    67,    71,
      68,   114,    68,    75,   122,    66,   113,    66,    68,   126,
      66,    66,    75,    73,   120,   121,    87,   122,    68,    99,
      97,    75,   122,    28,   124,    68,   126,    68,   126,   126,
     122,   122,    66,   124,    67,    67,    67,   126,   126,   122,
     122,   122,    67,    67,    13,    68,   122,   122
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    79,    80,    81,    81,    82,    82,    83,    83,    84,
      84,    85,    85,    85,    85,    86,    86,    86,    86,    86,
      86,    86,    86,    87,    88,    88,    89,    89,    90,    90,
      90,    91,    91,    92,    92,    93,    93,    93,    93,    93,
      93,    93,    94,    94,    95,    95,    96,    96,    97,    97,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    99,    99,   100,   100,   100,   101,   101,   101,   101,
     102,   102,   102,   103,   103,   103,   103,   103,   104,   104,
     104,   105,   105,   105,   106,   106,   106,   106,   107,   107,
     108,   108,   109,   109,   109,   109,   109,   109,   110,   110,
     110,   110,   110,   110,   110,   110,   111,   111,   112,   112,
     112,   112,   113,   114,   114,   114,   115,   116,   116,   117,
     118,   118,   119,   119,   119,   119,   120,   120,   121,   121,
     122,   122,   122,   122,   122,   122,   123,   123,   123,   124,
     124,   125,   125,   125,   126,   126,   127,   127,   127,   128,
     128,   128,   128,   128
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     6,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     3,     2,     2,
       1,     1,     2,     1,     2,     1,     3,     3,     4,     4,
       4,     3,     3,     1,     1,     3,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     1,     3,     3,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     4,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     4,
       3,     4,     3,     3,     2,     2,     1,     3,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       2,     3,     1,     1,     2,     2,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     3,     4,     3,     1,
       2,     5,     7,     5,     1,     3,     5,     7,     7,     3,
       2,     2,     2,     3
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
#line 44 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(PROGRAM);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);
                                }
#line 1558 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 52 "parser.y" /* yacc.c:1646  */
    {
                                                (yyval).node = tree.addNode(TRANSLATION_UNIT);
                                                Node *node = tree.getNodeById((yyval).node);
                                                node->addChild((yyvsp[0]).node);
                                                tree.print_tree_node((yyval).node);
                                                }
#line 1569 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 58 "parser.y" /* yacc.c:1646  */
    {
                                                                (yyval).node = tree.addNode(TRANSLATION_UNIT);
                                                                Node *node = tree.getNodeById((yyval).node);
                                                                node->addChild((yyvsp[-1]).node);
                                                                node->addChild((yyvsp[0]).node);
                                                                tree.print_tree_node((yyval).node);
                                                                }
#line 1581 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 67 "parser.y" /* yacc.c:1646  */
    {
                                                (yyval).node = tree.addNode(EXTERNAL_DECLARATION); 
                                                Node *node = tree.getNodeById((yyval).node); 
                                                node->addChild((yyvsp[0]).node);
                                                tree.print_tree_node((yyval).node);
                                                }
#line 1592 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 73 "parser.y" /* yacc.c:1646  */
    {
                                        (yyval).node = tree.addNode(EXTERNAL_DECLARATION); 
                                        Node *node = tree.getNodeById((yyval).node); 
                                        node->addChild((yyvsp[0]).node);
                                        tree.print_tree_node((yyval).node);
                                        }
#line 1603 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 81 "parser.y" /* yacc.c:1646  */
    {
                                                                                                        (yyval).node = tree.addNode(FUNCTION_DEFINITION);
                                                                                                        Node *node = tree.getNodeById((yyval).node);
                                                                                                        node->addChild((yyvsp[-5]).node);
                                                                                                        node->addChild((yyvsp[-4]).node);
                                                                                                        node->addChild((yyvsp[-2]).node);
                                                                                                        node->addChild((yyvsp[0]).node);
                                                                                                        tree.print_tree_node((yyval).node);       
                                                                                                }
#line 1617 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 90 "parser.y" /* yacc.c:1646  */
    {
                                                                                                        (yyval).node = tree.addNode(FUNCTION_DEFINITION);
                                                                                                        Node *node = tree.getNodeById((yyval).node);
                                                                                                        node->addChild((yyvsp[-4]).node);
                                                                                                        node->addChild((yyvsp[-3]).node);
                                                                                                        node->addChild((yyvsp[0]).node);
                                                                                                        tree.print_tree_node((yyval).node);       
                                                                                                }
#line 1630 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 100 "parser.y" /* yacc.c:1646  */
    {
                                                        (yyval).node = tree.addNode(DECLARATION_PREFIX);
                                                        Node *node = tree.getNodeById((yyval).node);
                                                        node->addChild((yyvsp[-1]).node);
                                                        node->addChild((yyvsp[0]).node);
                                                        tree.print_tree_node((yyval).node);
                                                }
#line 1642 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 107 "parser.y" /* yacc.c:1646  */
    {
                                        (yyval).node = tree.addNode(DECLARATION_PREFIX);
                                        Node *node = tree.getNodeById((yyval).node);
                                        node->addChild((yyvsp[0]).node);
                                        tree.print_tree_node((yyval).node);
                                }
#line 1653 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 115 "parser.y" /* yacc.c:1646  */
    {
                                        (yyval).node = tree.addNode(SPECIAL_SPECIFIER, "extern");
                                        tree.print_tree_node((yyval).node);                                
                                }
#line 1662 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 119 "parser.y" /* yacc.c:1646  */
    {
                                        (yyval).node = tree.addNode(SPECIAL_SPECIFIER, "static");  
                                        tree.print_tree_node((yyval).node);       
                                }
#line 1671 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 123 "parser.y" /* yacc.c:1646  */
    {
                                        (yyval).node = tree.addNode(SPECIAL_SPECIFIER, "auto");
                                        tree.print_tree_node((yyval).node);
                                }
#line 1680 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 127 "parser.y" /* yacc.c:1646  */
    {
                                        (yyval).node = tree.addNode(SPECIAL_SPECIFIER, "register");
                                        tree.print_tree_node((yyval).node);            
                                }
#line 1689 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 133 "parser.y" /* yacc.c:1646  */
    {(yyval).node = tree.addNode(TYPE_DEFINE,string("void").c_str());tree.print_tree_node((yyval).node);}
#line 1695 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 134 "parser.y" /* yacc.c:1646  */
    {(yyval).node = tree.addNode(TYPE_DEFINE,string("char").c_str());tree.print_tree_node((yyval).node);}
#line 1701 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 135 "parser.y" /* yacc.c:1646  */
    {(yyval).node = tree.addNode(TYPE_DEFINE,string("int").c_str());tree.print_tree_node((yyval).node);}
#line 1707 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 136 "parser.y" /* yacc.c:1646  */
    {(yyval).node = tree.addNode(TYPE_DEFINE,string("double").c_str());tree.print_tree_node((yyval).node);}
#line 1713 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 137 "parser.y" /* yacc.c:1646  */
    {(yyval).node = tree.addNode(TYPE_DEFINE,string("bool").c_str());tree.print_tree_node((yyval).node);}
#line 1719 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 138 "parser.y" /* yacc.c:1646  */
    {(yyval).node = tree.addNode(TYPE_DEFINE,string("float").c_str());tree.print_tree_node((yyval).node);}
#line 1725 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 139 "parser.y" /* yacc.c:1646  */
    {(yyval).node = tree.addNode(TYPE_DEFINE,string("long").c_str());tree.print_tree_node((yyval).node);}
#line 1731 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 140 "parser.y" /* yacc.c:1646  */
    {(yyval).node = tree.addNode(TYPE_DEFINE,string("short").c_str());tree.print_tree_node((yyval).node);}
#line 1737 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 143 "parser.y" /* yacc.c:1646  */
    {
                                                                    (yyval).node = tree.addNode(DECLARATION);
                                                                    Node *node = tree.getNodeById((yyval).node);
                                                                    node->addChild((yyvsp[-2]).node);
                                                                    node->addChild((yyvsp[-1]).node);
                                                                    tree.print_tree_node((yyval).node);    
                                                                }
#line 1749 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 152 "parser.y" /* yacc.c:1646  */
    {(yyval).node = tree.addNode(INIT_DECLARATION_LIST); Node *node = tree.getNodeById((yyval).node); node->addChild((yyvsp[0]).node); tree.print_tree_node((yyval).node);}
#line 1755 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 153 "parser.y" /* yacc.c:1646  */
    {(yyval).node = tree.addNode(INIT_DECLARATION_LIST); Node *node = tree.getNodeById((yyval).node); node->addChild((yyvsp[-2]).node); node->addChild((yyvsp[0]).node); tree.print_tree_node((yyval).node);}
#line 1761 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 156 "parser.y" /* yacc.c:1646  */
    {(yyval).node = tree.addNode(INIT_DECLARATION); Node *node = tree.getNodeById((yyval).node); node->addChild((yyvsp[0]).node); tree.print_tree_node((yyval).node);}
#line 1767 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 157 "parser.y" /* yacc.c:1646  */
    {(yyval).node = tree.addNode(INIT_DECLARATION); Node *node = tree.getNodeById((yyval).node); node->addChild((yyvsp[-2]).node); node->addChild((yyvsp[0]).node); tree.print_tree_node((yyval).node);}
#line 1773 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 159 "parser.y" /* yacc.c:1646  */
    {(yyval).node = tree.addNode(DECLARATION_ITEM); Node *node = tree.getNodeById((yyval).node); node->addChild((yyvsp[-1]).node); tree.print_tree_node((yyval).node);}
#line 1779 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 160 "parser.y" /* yacc.c:1646  */
    {(yyval).node = tree.addNode(DECLARATION_ITEM); Node *node = tree.getNodeById((yyval).node); node->addChild((yyvsp[-1]).node); tree.print_tree_node((yyval).node);}
#line 1785 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 161 "parser.y" /* yacc.c:1646  */
    {(yyval).node = tree.addNode(DECLARATION_ITEM); Node *node = tree.getNodeById((yyval).node); node->addChild((yyvsp[0]).node); tree.print_tree_node((yyval).node);}
#line 1791 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 164 "parser.y" /* yacc.c:1646  */
    {
                (yyvsp[0]).node = tree.addNode(POINTER, "*");
                tree.print_tree_node((yyvsp[0]).node);

                (yyval).node = tree.addNode(POINTER);
                Node *node = tree.getNodeById((yyval).node);
                node->addChild((yyvsp[0]).node);
                tree.print_tree_node((yyval).node); 
                }
#line 1805 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 173 "parser.y" /* yacc.c:1646  */
    { 
                        (yyvsp[-1]).node = tree.addNode(POINTER, "*");
                        tree.print_tree_node((yyvsp[-1]).node);

                        (yyval).node = tree.addNode(POINTER); 
                        Node *node = tree.getNodeById((yyval).node);
                        node->addChild((yyvsp[-1]).node);
                        node->addChild((yyvsp[0]).node);
                        tree.print_tree_node((yyval).node); 
                }
#line 1820 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 185 "parser.y" /* yacc.c:1646  */
    {
                (yyvsp[0]).node = tree.addNode(REFER, "&");
                tree.print_tree_node((yyvsp[0]).node);

                (yyval).node = tree.addNode(REFER);
                Node *node = tree.getNodeById((yyval).node);
                node->addChild((yyvsp[0]).node);
                tree.print_tree_node((yyval).node); 
                }
#line 1834 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 194 "parser.y" /* yacc.c:1646  */
    { 
                        (yyvsp[-1]).node = tree.addNode(REFER, "&");
                        tree.print_tree_node((yyvsp[-1]).node);

                        (yyval).node = tree.addNode(REFER); 
                        Node *node = tree.getNodeById((yyval).node);
                        node->addChild((yyvsp[-1]).node);
                        node->addChild((yyvsp[0]).node);
                        tree.print_tree_node((yyval).node); 
                }
#line 1849 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 206 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(SIMPLE_ITEM);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 1860 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 212 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(SIMPLE_ITEM);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-1]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 1871 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 218 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(SIMPLE_ITEM);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-2]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 1882 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 224 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(SIMPLE_ITEM);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-3]).node);
                                node->addChild((yyvsp[-1]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 1894 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 231 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(SIMPLE_ITEM);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-3]).node);
                                node->addChild((yyvsp[-1]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 1906 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 238 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(SIMPLE_ITEM);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-3]).node);
                                node->addChild((yyvsp[-1]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 1918 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 245 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(SIMPLE_ITEM);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-2]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 1929 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 253 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(IDENTIFIER_LIST);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);
                        }
#line 1941 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 260 "parser.y" /* yacc.c:1646  */
    { 
                        (yyval).node = tree.addNode(IDENTIFIER_LIST);
                        Node *node = tree.getNodeById((yyval).node);
                        node->addChild((yyvsp[0]).node);
                        tree.print_tree_node((yyval).node);
                        }
#line 1952 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 268 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(INITIALIZER);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 1963 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 274 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(INITIALIZER);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-1]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 1974 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 282 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(INITIALIZER_LIST);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 1985 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 288 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(INITIALIZER_LIST);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 1997 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 297 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(ASSIGNMENT_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2008 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 303 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(ASSIGNMENT_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[-1]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2021 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 313 "parser.y" /* yacc.c:1646  */
    { (yyval).node = tree.addNode(OPERATOR, string("op =").c_str()); tree.print_tree_node((yyval).node);}
#line 2027 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 314 "parser.y" /* yacc.c:1646  */
    { (yyval).node = tree.addNode(OPERATOR, string("op +=").c_str()); tree.print_tree_node((yyval).node);}
#line 2033 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 315 "parser.y" /* yacc.c:1646  */
    { (yyval).node = tree.addNode(OPERATOR, string("op -=").c_str()); tree.print_tree_node((yyval).node);}
#line 2039 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 316 "parser.y" /* yacc.c:1646  */
    { (yyval).node = tree.addNode(OPERATOR, string("op *=").c_str()); tree.print_tree_node((yyval).node);}
#line 2045 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 317 "parser.y" /* yacc.c:1646  */
    { (yyval).node = tree.addNode(OPERATOR, string("op /=").c_str()); tree.print_tree_node((yyval).node);}
#line 2051 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 318 "parser.y" /* yacc.c:1646  */
    { (yyval).node = tree.addNode(OPERATOR, string("op %=").c_str()); tree.print_tree_node((yyval).node);}
#line 2057 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 319 "parser.y" /* yacc.c:1646  */
    { (yyval).node = tree.addNode(OPERATOR, string("op <<=").c_str()); tree.print_tree_node((yyval).node);}
#line 2063 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 320 "parser.y" /* yacc.c:1646  */
    { (yyval).node = tree.addNode(OPERATOR, string("op >>=").c_str()); tree.print_tree_node((yyval).node);}
#line 2069 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 321 "parser.y" /* yacc.c:1646  */
    { (yyval).node = tree.addNode(OPERATOR, string("op &=").c_str()); tree.print_tree_node((yyval).node);}
#line 2075 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 322 "parser.y" /* yacc.c:1646  */
    { (yyval).node = tree.addNode(OPERATOR, string("op ^=").c_str()); tree.print_tree_node((yyval).node);}
#line 2081 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 323 "parser.y" /* yacc.c:1646  */
    { (yyval).node = tree.addNode(OPERATOR, string("op |=").c_str()); tree.print_tree_node((yyval).node);}
#line 2087 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 326 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(CONDITION_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2098 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 332 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(CONDITION_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-4]).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2111 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 342 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(LOGICAL_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2122 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 348 "parser.y" /* yacc.c:1646  */
    {
                                (yyvsp[-1]).node = tree.addNode(OPERATOR, string("op ||").c_str());
                                tree.print_tree_node((yyvsp[-1]).node);

                                (yyval).node = tree.addNode(LOGICAL_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[-1]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2138 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 359 "parser.y" /* yacc.c:1646  */
    {
                                (yyvsp[-1]).node = tree.addNode(OPERATOR, string("op &&").c_str());
                                tree.print_tree_node((yyvsp[-1]).node);

                                (yyval).node = tree.addNode(LOGICAL_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[-1]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2154 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 372 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(BIT_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2165 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 378 "parser.y" /* yacc.c:1646  */
    {
                                (yyvsp[-1]).node = tree.addNode(OPERATOR, string("bit_op &").c_str());
                                tree.print_tree_node((yyvsp[-1]).node);

                                (yyval).node = tree.addNode(BIT_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[-1]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2181 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 389 "parser.y" /* yacc.c:1646  */
    {
                                (yyvsp[-1]).node = tree.addNode(OPERATOR, string("bit_op ^").c_str());
                                tree.print_tree_node((yyvsp[-1]).node);

                                (yyval).node = tree.addNode(BIT_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[-1]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2197 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 400 "parser.y" /* yacc.c:1646  */
    {
                                (yyvsp[-1]).node = tree.addNode(OPERATOR, string("bit_op |").c_str());
                                tree.print_tree_node((yyvsp[-1]).node);

                                (yyval).node = tree.addNode(BIT_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[-1]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2213 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 413 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(EQUALITY_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2224 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 419 "parser.y" /* yacc.c:1646  */
    {
                                (yyvsp[-1]).node = tree.addNode(OPERATOR, string("op =").c_str());
                                tree.print_tree_node((yyvsp[-1]).node);

                                (yyval).node = tree.addNode(EQUALITY_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[-1]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2240 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 430 "parser.y" /* yacc.c:1646  */
    {
                                (yyvsp[-1]).node = tree.addNode(OPERATOR, string("op !=").c_str());
                                tree.print_tree_node((yyvsp[-1]).node);

                                (yyval).node = tree.addNode(EQUALITY_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[-1]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2256 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 443 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(RELATIONAL_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2267 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 449 "parser.y" /* yacc.c:1646  */
    {
                                (yyvsp[-1]).node = tree.addNode(OPERATOR, string("op <").c_str());
                                tree.print_tree_node((yyvsp[-1]).node);

                                (yyval).node = tree.addNode(RELATIONAL_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[-1]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2283 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 460 "parser.y" /* yacc.c:1646  */
    {
                                (yyvsp[-1]).node = tree.addNode(OPERATOR, string("op >").c_str());
                                tree.print_tree_node((yyvsp[-1]).node);

                                (yyval).node = tree.addNode(RELATIONAL_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[-1]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2299 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 471 "parser.y" /* yacc.c:1646  */
    {
                                (yyvsp[-1]).node = tree.addNode(OPERATOR, string("op <=").c_str());
                                tree.print_tree_node((yyvsp[-1]).node);

                                (yyval).node = tree.addNode(RELATIONAL_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[-1]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2315 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 482 "parser.y" /* yacc.c:1646  */
    {
                                (yyvsp[-1]).node = tree.addNode(OPERATOR, string("op >=").c_str());
                                tree.print_tree_node((yyvsp[-1]).node);

                                (yyval).node = tree.addNode(RELATIONAL_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[-1]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2331 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 495 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(SHIFT_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2342 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 501 "parser.y" /* yacc.c:1646  */
    {
                                (yyvsp[-1]).node = tree.addNode(OPERATOR, string("op >>").c_str());
                                tree.print_tree_node((yyvsp[-1]).node);

                                (yyval).node = tree.addNode(SHIFT_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[-1]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2358 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 512 "parser.y" /* yacc.c:1646  */
    {
                                (yyvsp[-1]).node = tree.addNode(OPERATOR, string("op <<").c_str());
                                tree.print_tree_node((yyvsp[-1]).node);

                                (yyval).node = tree.addNode(SHIFT_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[-1]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2374 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 525 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(ADD_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2385 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 531 "parser.y" /* yacc.c:1646  */
    {
                                (yyvsp[-1]).node = tree.addNode(OPERATOR, string("op +").c_str());
                                tree.print_tree_node((yyvsp[-1]).node);

                                (yyval).node = tree.addNode(ADD_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[-1]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2401 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 542 "parser.y" /* yacc.c:1646  */
    {
                                (yyvsp[-1]).node = tree.addNode(OPERATOR, string("op -").c_str());
                                tree.print_tree_node((yyvsp[-1]).node);

                                (yyval).node = tree.addNode(ADD_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[-1]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2417 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 555 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(MUL_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2428 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 561 "parser.y" /* yacc.c:1646  */
    {
                                (yyvsp[-1]).node = tree.addNode(OPERATOR, string("op *").c_str());
                                tree.print_tree_node((yyvsp[-1]).node);

                                (yyval).node = tree.addNode(MUL_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[-1]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2444 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 572 "parser.y" /* yacc.c:1646  */
    {
                                (yyvsp[-1]).node = tree.addNode(OPERATOR, string("op /").c_str());
                                tree.print_tree_node((yyvsp[-1]).node);

                                (yyval).node = tree.addNode(MUL_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[-1]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2460 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 583 "parser.y" /* yacc.c:1646  */
    {
                                (yyvsp[-1]).node = tree.addNode(OPERATOR, string("op %").c_str());
                                tree.print_tree_node((yyvsp[-1]).node);

                                (yyval).node = tree.addNode(MUL_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[-1]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2476 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 596 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(CAST_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2487 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 602 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(CAST_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2499 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 611 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(UNARY_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2510 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 617 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(UNARY_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-1]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2522 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 626 "parser.y" /* yacc.c:1646  */
    {
                        (yyval).node = tree.addNode(UNARY_OP, "unary_op +");
                        tree.print_tree_node((yyval).node);        
                }
#line 2531 "parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 630 "parser.y" /* yacc.c:1646  */
    {
                        (yyval).node = tree.addNode(UNARY_OP, "unary_op -");
                        tree.print_tree_node((yyval).node);        
                }
#line 2540 "parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 634 "parser.y" /* yacc.c:1646  */
    {
                        (yyval).node = tree.addNode(UNARY_OP, "unary_op ~");
                        tree.print_tree_node((yyval).node);        
                }
#line 2549 "parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 638 "parser.y" /* yacc.c:1646  */
    {
                        (yyval).node = tree.addNode(UNARY_OP, "unary_op !");
                        tree.print_tree_node((yyval).node);        
                }
#line 2558 "parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 642 "parser.y" /* yacc.c:1646  */
    {
                        (yyval).node = tree.addNode(UNARY_OP, "inc_op ++");
                        tree.print_tree_node((yyval).node);        
                }
#line 2567 "parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 646 "parser.y" /* yacc.c:1646  */
    {
                        (yyval).node = tree.addNode(UNARY_OP, "dec_op --");
                        tree.print_tree_node((yyval).node);        
                }
#line 2576 "parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 652 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(POSTFIX_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2587 "parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 658 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(POSTFIX_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-3]).node);
                                node->addChild((yyvsp[-1]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2599 "parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 665 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(POSTFIX_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-2]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2610 "parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 671 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(POSTFIX_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-3]).node);
                                node->addChild((yyvsp[-1]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2622 "parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 678 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(POSTFIX_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2634 "parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 685 "parser.y" /* yacc.c:1646  */
    {
                                (yyvsp[-1]).node = tree.addNode(OPERATOR,string("ptr_op ->").c_str());
                                tree.print_tree_node((yyvsp[-1]).node);

                                (yyval).node = tree.addNode(POSTFIX_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[-1]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2650 "parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 696 "parser.y" /* yacc.c:1646  */
    {
                                (yyvsp[0]).node = tree.addNode(OPERATOR,string("inc_op ++").c_str());
                                tree.print_tree_node((yyvsp[0]).node);

                                (yyval).node = tree.addNode(POSTFIX_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-1]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2665 "parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 706 "parser.y" /* yacc.c:1646  */
    {
                                (yyvsp[0]).node = tree.addNode(OPERATOR,string("dec_op --").c_str());
                                tree.print_tree_node((yyvsp[0]).node);

                                (yyval).node = tree.addNode(POSTFIX_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-1]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2680 "parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 718 "parser.y" /* yacc.c:1646  */
    {
                                                (yyval).node = tree.addNode(ARGUMENT_EXPR_LIST);
                                                Node *node = tree.getNodeById((yyval).node);
                                                node->addChild((yyvsp[0]).node);
                                                tree.print_tree_node((yyval).node);                                    
                                        }
#line 2691 "parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 724 "parser.y" /* yacc.c:1646  */
    {
                                                (yyval).node = tree.addNode(ARGUMENT_EXPR_LIST);
                                                Node *node = tree.getNodeById((yyval).node);
                                                node->addChild((yyvsp[-2]).node);
                                                node->addChild((yyvsp[0]).node);
                                                tree.print_tree_node((yyval).node);                                    
                                        }
#line 2703 "parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 732 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(PRIMARY_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2714 "parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 738 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(PRIMARY_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2725 "parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 744 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(PRIMARY_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-1]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2736 "parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 750 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(PRIMARY_EXPR);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                        
                        }
#line 2747 "parser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 758 "parser.y" /* yacc.c:1646  */
    {
                        string s = string("id ").append((yyvsp[0]).text); 
                        (yyval).node = tree.addNode(IDENTIFIER, strdup(s.c_str())); 
                        tree.print_tree_node((yyval).node);
		}
#line 2757 "parser.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 765 "parser.y" /* yacc.c:1646  */
    {
                                string s = string("constant value ").append((yyvsp[0]).text);
                                (yyval).node = tree.addNode(CONSTANT_EXPR, strdup(s.c_str()));
                                tree.print_tree_node((yyval).node);
                        }
#line 2767 "parser.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 770 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(CONSTANT_EXPR, "bool true");
                                tree.print_tree_node((yyval).node);
                        }
#line 2776 "parser.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 774 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(CONSTANT_EXPR, "bool false");
                                tree.print_tree_node((yyval).node);
                        }
#line 2785 "parser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 780 "parser.y" /* yacc.c:1646  */
    {
                                string s = string("string ").append((yyvsp[0]).text);
                                (yyval).node = tree.addNode(STRING_CONSTANT, strdup(s.c_str()));
                                tree.print_tree_node((yyval).node);
                        }
#line 2795 "parser.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 788 "parser.y" /* yacc.c:1646  */
    {
                                                (yyval).node = tree.addNode(PARAMETER_LIST);
                                                Node *node = tree.getNodeById((yyval).node);
                                                node->addChild((yyvsp[0]).node);
                                                tree.print_tree_node((yyval).node);                                        
                                        }
#line 2806 "parser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 794 "parser.y" /* yacc.c:1646  */
    {
                                                (yyval).node = tree.addNode(PARAMETER_LIST);
                                                Node *node = tree.getNodeById((yyval).node);
                                                node->addChild((yyvsp[-2]).node);
                                                node->addChild((yyvsp[0]).node);
                                                tree.print_tree_node((yyval).node);                                        
                                        }
#line 2818 "parser.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 803 "parser.y" /* yacc.c:1646  */
    {
                                                (yyval).node = tree.addNode(PARAMETER_DECLARATION);
                                                Node *node = tree.getNodeById((yyval).node);
                                                node->addChild((yyvsp[-1]).node);
                                                node->addChild((yyvsp[0]).node);
                                                tree.print_tree_node((yyval).node);                                        
                                        }
#line 2830 "parser.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 812 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(COMPOUND_STATEMENT);
                                tree.print_tree_node((yyval).node);                                        
                        }
#line 2839 "parser.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 816 "parser.y" /* yacc.c:1646  */
    {
                                                (yyval).node = tree.addNode(COMPOUND_STATEMENT);
                                                Node *node = tree.getNodeById((yyval).node);
                                                node->addChild((yyvsp[-1]).node);
                                                tree.print_tree_node((yyval).node);                                        
                                        }
#line 2850 "parser.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 824 "parser.y" /* yacc.c:1646  */
    {
                                                (yyval).node = tree.addNode(COMPOUND_STATEMENT_LIST);
                                                Node *node = tree.getNodeById((yyval).node);
                                                node->addChild((yyvsp[0]).node);
                                                tree.print_tree_node((yyval).node);                                        
                                        }
#line 2861 "parser.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 830 "parser.y" /* yacc.c:1646  */
    {
                                                (yyval).node = tree.addNode(COMPOUND_STATEMENT_LIST);
                                                Node *node = tree.getNodeById((yyval).node);
                                                node->addChild((yyvsp[0]).node);
                                                tree.print_tree_node((yyval).node);                                        
                                        }
#line 2872 "parser.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 836 "parser.y" /* yacc.c:1646  */
    {
                                                (yyval).node = tree.addNode(COMPOUND_STATEMENT_LIST);
                                                Node *node = tree.getNodeById((yyval).node);
                                                node->addChild((yyvsp[-1]).node);
                                                node->addChild((yyvsp[0]).node);
                                                tree.print_tree_node((yyval).node);                                        
                                        }
#line 2884 "parser.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 843 "parser.y" /* yacc.c:1646  */
    {
                                                (yyval).node = tree.addNode(COMPOUND_STATEMENT_LIST);
                                                Node *node = tree.getNodeById((yyval).node);
                                                node->addChild((yyvsp[-1]).node);
                                                node->addChild((yyvsp[0]).node);
                                                tree.print_tree_node((yyval).node);                                        
                                        }
#line 2896 "parser.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 852 "parser.y" /* yacc.c:1646  */
    {
                                        (yyval).node = tree.addNode(DECLARATION_LIST);
                                        Node *node = tree.getNodeById((yyval).node);
                                        node->addChild((yyvsp[0]).node);
                                        tree.print_tree_node((yyval).node);                                        
                                }
#line 2907 "parser.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 858 "parser.y" /* yacc.c:1646  */
    {
                                                (yyval).node = tree.addNode(DECLARATION_LIST);
                                                Node *node = tree.getNodeById((yyval).node);
                                                node->addChild((yyvsp[-1]).node);
                                                node->addChild((yyvsp[0]).node);
                                                tree.print_tree_node((yyval).node);                                        
                                        }
#line 2919 "parser.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 867 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(STATEMENT_LIST);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                                        
                        }
#line 2930 "parser.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 873 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(STATEMENT_LIST);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-1]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                                        
                        }
#line 2942 "parser.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 882 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2948 "parser.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 883 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2954 "parser.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 884 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2960 "parser.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 885 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2966 "parser.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 886 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2972 "parser.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 887 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2978 "parser.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 890 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(LABELED_STATEMENT);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                                        
                        }
#line 2990 "parser.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 897 "parser.y" /* yacc.c:1646  */
    {
                                (yyvsp[-3]).node = tree.addNode(KEYWORD, "case ");
                                tree.print_tree_node((yyvsp[-3]).node);
                        
                                (yyval).node = tree.addNode(LABELED_STATEMENT);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-3]).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                                        
                        }
#line 3006 "parser.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 908 "parser.y" /* yacc.c:1646  */
    {
                                (yyvsp[-2]).node = tree.addNode(KEYWORD, "default ");
                                tree.print_tree_node((yyvsp[-2]).node);
                        
                                (yyval).node = tree.addNode(LABELED_STATEMENT);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                                        
                        }
#line 3021 "parser.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 920 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(EXPR_STATEMENT);
                                tree.print_tree_node((yyval).node);                                        
                        }
#line 3030 "parser.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 924 "parser.y" /* yacc.c:1646  */
    {
                                (yyval).node = tree.addNode(EXPR_STATEMENT);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-1]).node);
                                tree.print_tree_node((yyval).node);                                        
                        }
#line 3041 "parser.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 932 "parser.y" /* yacc.c:1646  */
    {
                                (yyvsp[-4]).node = tree.addNode(KEYWORD, "if ");
                                tree.print_tree_node((yyvsp[-4]).node);
                        
                                (yyval).node = tree.addNode(CONDITION_STATEMENT);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-4]).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                                        
                        }
#line 3057 "parser.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 943 "parser.y" /* yacc.c:1646  */
    {
                                (yyvsp[-6]).node = tree.addNode(KEYWORD, "if-else ");
                                tree.print_tree_node((yyvsp[-6]).node);
                        
                                (yyval).node = tree.addNode(CONDITION_STATEMENT);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-6]).node);
                                node->addChild((yyvsp[-4]).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                                        
                        }
#line 3074 "parser.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 955 "parser.y" /* yacc.c:1646  */
    {
                                (yyvsp[-4]).node = tree.addNode(KEYWORD, "switch ");
                                tree.print_tree_node((yyvsp[-4]).node);
                        
                                (yyval).node = tree.addNode(CONDITION_STATEMENT);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-4]).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[0]).node);
                                tree.print_tree_node((yyval).node);                                        
                        }
#line 3090 "parser.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 968 "parser.y" /* yacc.c:1646  */
    {
                                        (yyval).node = tree.addNode(EXPR);  
                                        Node *node = tree.getNodeById((yyval).node);
                                        node->addChild((yyvsp[0]).node);
                                        tree.print_tree_node((yyval).node);
                                }
#line 3101 "parser.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 974 "parser.y" /* yacc.c:1646  */
    {
                                        (yyval).node = tree.addNode(EXPR);  
                                        Node *node = tree.getNodeById((yyval).node);
                                        node->addChild((yyvsp[-2]).node);
                                        node->addChild((yyvsp[0]).node);
                                        tree.print_tree_node((yyval).node);
                                }
#line 3113 "parser.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 983 "parser.y" /* yacc.c:1646  */
    {
                                                (yyvsp[-4]).node = tree.addNode(KEYWORD, "while ");
                                                tree.print_tree_node((yyvsp[-4]).node);

                                                (yyval).node = tree.addNode(LOOP_STATEMENT);
                                                Node *node = tree.getNodeById((yyval).node);
                                                node->addChild((yyvsp[-4]).node);
                                                node->addChild((yyvsp[-2]).node);
                                                node->addChild((yyvsp[0]).node);
                                                tree.print_tree_node((yyval).node);
                                        }
#line 3129 "parser.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 994 "parser.y" /* yacc.c:1646  */
    {
                                                (yyvsp[-6]).node = tree.addNode(KEYWORD, "do-while ");
                                                tree.print_tree_node((yyvsp[-6]).node);

                                                (yyval).node = tree.addNode(LOOP_STATEMENT);
                                                Node *node = tree.getNodeById((yyval).node);
                                                node->addChild((yyvsp[-6]).node);
                                                node->addChild((yyvsp[-5]).node);
                                                node->addChild((yyvsp[-2]).node);
                                                tree.print_tree_node((yyval).node);
                                        }
#line 3145 "parser.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1005 "parser.y" /* yacc.c:1646  */
    {
                                                (yyvsp[-6]).node = tree.addNode(KEYWORD, "for ");
                                                tree.print_tree_node((yyvsp[-6]).node);

                                                (yyval).node = tree.addNode(LOOP_STATEMENT);
                                                Node *node = tree.getNodeById((yyval).node);
                                                node->addChild((yyvsp[-6]).node);
                                                node->addChild((yyvsp[-4]).node);
                                                node->addChild((yyvsp[-3]).node);
                                                node->addChild((yyvsp[-2]).node);
                                                node->addChild((yyvsp[0]).node);
                                                tree.print_tree_node((yyval).node);
                                        }
#line 3163 "parser.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1020 "parser.y" /* yacc.c:1646  */
    {
                                        (yyvsp[-2]).node = tree.addNode(KEYWORD, "goto");
                                        tree.print_tree_node((yyvsp[-2]).node);

                                        (yyval).node = tree.addNode(JUMP_STATEMENT);
                                        Node *node = tree.getNodeById((yyval).node);
                                        node->addChild((yyvsp[-2]).node);
                                        node->addChild((yyvsp[-1]).node);
                                        tree.print_tree_node((yyval).node);
                                }
#line 3178 "parser.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1030 "parser.y" /* yacc.c:1646  */
    {
                                (yyvsp[-1]).node = tree.addNode(KEYWORD, "continue");
                                tree.print_tree_node((yyvsp[-1]).node);

                                (yyval).node = tree.addNode(JUMP_STATEMENT);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-1]).node);
                                tree.print_tree_node((yyval).node);
                        }
#line 3192 "parser.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1039 "parser.y" /* yacc.c:1646  */
    {
                                (yyvsp[-1]).node = tree.addNode(KEYWORD, "break");
                                tree.print_tree_node((yyvsp[-1]).node);

                                (yyval).node = tree.addNode(JUMP_STATEMENT);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-1]).node);
                                tree.print_tree_node((yyval).node);
                        }
#line 3206 "parser.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1048 "parser.y" /* yacc.c:1646  */
    {
                                (yyvsp[-1]).node = tree.addNode(KEYWORD, "return");
                                tree.print_tree_node((yyvsp[-1]).node);

                                (yyval).node = tree.addNode(JUMP_STATEMENT);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-1]).node);
                                tree.print_tree_node((yyval).node);
                        }
#line 3220 "parser.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1057 "parser.y" /* yacc.c:1646  */
    {
                                (yyvsp[-2]).node = tree.addNode(KEYWORD, "return");
                                tree.print_tree_node((yyvsp[-2]).node);

                                (yyval).node = tree.addNode(JUMP_STATEMENT);
                                Node *node = tree.getNodeById((yyval).node);
                                node->addChild((yyvsp[-2]).node);
                                node->addChild((yyvsp[-1]).node);
                                tree.print_tree_node((yyval).node);
                        }
#line 3235 "parser.cpp" /* yacc.c:1646  */
    break;


#line 3239 "parser.cpp" /* yacc.c:1646  */
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
#line 1068 "parser.y" /* yacc.c:1906  */


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
