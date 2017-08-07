/* A Bison parser, made by GNU Bison 2.7.  */

/* Skeleton implementation for Bison GLR parsers in C
   
      Copyright (C) 2002-2012 Free Software Foundation, Inc.
   
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

/* C GLR parser skeleton written by Paul Hilfinger.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.c"

/* Pure parsers.  */
#define YYPURE 1






/* Copy the first part of user declarations.  */
/* Line 207 of glr.c  */
#line 10 "sql.ypp"

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <malloc.h>
#include <boost/format.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>
#include <vector>
using namespace std;
#include "../ast_node/ast_node.h"
#include "../ast_node/ast_select_stmt.h"
#include "../ast_node/ast_expr_node.h"
#include "../ast_node/ast_create_stmt.h"
#include "../ast_node/ast_drop_stmt.h"
#include "../ast_node/ast_insert_stmt.h"
#include "../ast_node/ast_load_stmt.h"
#include "../ast_node/ast_show_stmt.h"
#include "../ast_node/ast_delete_stmt.h"
#include "../ast_node/ast_desc_stmt.h"
#include "../ast_node/ast_update_stmt.h"

void yyerror(struct ParseResult *pp,const char *s, ...);
void emit(char *s, ...);

/* Line 207 of glr.c  */
#line 85 "sql.tab.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

#include "sql.tab.hpp"

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template, here we set
   the default value of $$ to a zeroed-out value.  Since the default
   value is undefined, this behavior is technically correct.  */
static YYSTYPE yyval_default;

/* Copy the second part of user declarations.  */
/* Line 230 of glr.c  */
#line 46 "sql.ypp"

#include "sql.lex.h"

#define YYLEX_PARAM result->yyscan_info_

/*
should replace YYLEX with the following clause in sql.tab.cpp, why so? I don't know

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval)
#endif
*/


/* Line 230 of glr.c  */
#line 131 "sql.tab.cpp"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#define YYSIZEMAX ((size_t) -1)

#ifdef __cplusplus
   typedef bool yybool;
#else
   typedef unsigned char yybool;
#endif
#define yytrue 1
#define yyfalse 0

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(Env) setjmp (Env)
/* Pacify clang.  */
# define YYLONGJMP(Env, Val) (longjmp (Env, Val), YYASSERT (0))
#endif

/*-----------------.
| GCC extensions.  |
`-----------------*/

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

#ifndef YYASSERT
# define YYASSERT(Condition) ((void) ((Condition) || (abort (), 0)))
#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  101
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2713

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  342
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  88
/* YYNRULES -- Number of rules.  */
#define YYNRULES  381
/* YYNRULES -- Number of states.  */
#define YYNSTATES  820
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 13
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYTRANSLATE(X) -- Bison symbol number corresponding to X.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   582

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned short int yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    17,     2,     2,     2,    28,    22,     2,
     339,   340,    26,    24,   338,    25,   341,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   337,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    30,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    21,     2,     2,     2,     2,     2,
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
      15,    16,    18,    19,    20,    23,    29,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     6,    10,    13,    17,    19,    23,    35,
      36,    39,    40,    45,    47,    51,    52,    54,    56,    57,
      60,    61,    64,    65,    69,    72,    77,    78,    81,    86,
      87,    93,   102,   104,   108,   109,   111,   117,   119,   122,
     124,   128,   130,   134,   136,   139,   141,   145,   147,   149,
     152,   157,   161,   165,   166,   168,   171,   173,   174,   180,
     184,   190,   197,   203,   204,   206,   208,   209,   211,   213,
     215,   217,   220,   223,   226,   227,   228,   230,   233,   238,
     242,   244,   246,   250,   254,   256,   258,   260,   262,   266,
     270,   274,   278,   282,   286,   289,   292,   296,   300,   304,
     308,   314,   321,   328,   335,   339,   343,   347,   351,   354,
     357,   361,   365,   369,   374,   378,   383,   389,   391,   395,
     399,   401,   405,   411,   419,   426,   435,   441,   449,   456,
     465,   470,   476,   481,   486,   491,   496,   501,   506,   511,
     516,   521,   526,   531,   538,   545,   554,   563,   568,   576,
     581,   588,   593,   595,   597,   599,   600,   602,   604,   606,
     608,   610,   617,   624,   628,   632,   636,   640,   644,   648,
     652,   656,   660,   665,   672,   676,   682,   687,   693,   697,
     702,   706,   711,   713,   718,   723,   724,   728,   730,   739,
     750,   760,   767,   779,   788,   792,   793,   795,   797,   798,
     800,   802,   806,   810,   816,   821,   826,   832,   838,   839,
     843,   846,   850,   854,   858,   862,   865,   869,   873,   876,
     880,   886,   889,   893,   897,   901,   905,   909,   913,   917,
     921,   925,   929,   931,   933,   935,   937,   939,   943,   947,
     950,   955,   957,   959,   961,   963,   967,   971,   975,   979,
     985,   991,   993,   997,   998,  1002,  1008,  1009,  1011,  1012,
    1015,  1018,  1019,  1024,  1028,  1030,  1041,  1055,  1057,  1068,
    1069,  1071,  1073,  1075,  1076,  1079,  1081,  1083,  1087,  1093,
    1095,  1108,  1118,  1128,  1141,  1143,  1149,  1151,  1156,  1161,
    1162,  1165,  1167,  1174,  1176,  1180,  1184,  1190,  1191,  1193,
    1195,  1197,  1206,  1207,  1213,  1214,  1217,  1220,  1223,  1226,
    1228,  1229,  1230,  1234,  1238,  1244,  1246,  1248,  1252,  1256,
    1264,  1272,  1276,  1280,  1286,  1292,  1294,  1300,  1304,  1312,
    1317,  1322,  1327,  1331,  1335,  1340,  1345,  1349,  1353,  1357,
    1362,  1368,  1372,  1376,  1382,  1385,  1389,  1394,  1400,  1405,
    1410,  1415,  1419,  1423,  1424,  1425,  1428,  1429,  1432,  1433,
    1436,  1437,  1439,  1440,  1442,  1444,  1447,  1449,  1457,  1465,
    1472,  1475,  1478,  1481,  1482,  1485,  1490,  1491,  1494,  1496,
    1502,  1506
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const short int yyrhs[] =
{
     343,     0,    -1,   344,   337,    -1,   343,   344,   337,    -1,
       1,   337,    -1,   343,     1,   337,    -1,   345,    -1,   194,
     357,   359,    -1,   194,   357,   359,   355,   107,   361,   346,
     347,   351,   352,   354,    -1,    -1,   244,   374,    -1,    -1,
     111,    48,   348,   350,    -1,   374,    -1,   374,   338,   348,
      -1,    -1,    40,    -1,    83,    -1,    -1,   246,   189,    -1,
      -1,   112,   374,    -1,    -1,   164,    48,   353,    -1,   374,
     349,    -1,   374,   349,   338,   353,    -1,    -1,   137,   374,
      -1,   137,   374,   338,   374,    -1,    -1,   128,   363,   168,
     159,     3,    -1,   128,   363,   158,    20,     5,   168,   159,
       3,    -1,     3,    -1,     3,   338,   356,    -1,    -1,    86,
      -1,    86,   159,   339,   358,   340,    -1,    33,    -1,    86,
     358,    -1,   374,    -1,   374,   338,   358,    -1,   360,    -1,
     360,   338,   359,    -1,    26,    -1,   374,   365,    -1,   362,
      -1,   362,   338,   361,    -1,   363,    -1,   366,    -1,     3,
     365,    -1,     3,   341,     3,   365,    -1,   373,   364,     3,
      -1,   339,   361,   340,    -1,    -1,    39,    -1,    39,     3,
      -1,     3,    -1,    -1,   362,   367,   130,   363,   371,    -1,
     362,   213,   363,    -1,   362,   213,   363,   159,   374,    -1,
     362,   369,   368,   130,   363,   372,    -1,   362,   155,   370,
     130,   363,    -1,    -1,   121,    -1,    63,    -1,    -1,   166,
      -1,   136,    -1,   188,    -1,   108,    -1,   136,   368,    -1,
     188,   368,    -1,   108,   368,    -1,    -1,    -1,   372,    -1,
     159,   374,    -1,   235,   339,   356,   340,    -1,   339,   345,
     340,    -1,     3,    -1,     8,    -1,     3,   341,     3,    -1,
       3,   341,    26,    -1,     4,    -1,     5,    -1,     7,    -1,
       6,    -1,   374,    24,   374,    -1,   374,    25,   374,    -1,
     374,    26,   374,    -1,   374,    27,   374,    -1,   374,    29,
     374,    -1,   374,    28,   374,    -1,    25,   374,    -1,    24,
     374,    -1,   374,    12,   374,    -1,   374,    10,   374,    -1,
     374,    11,   374,    -1,   374,    20,   374,    -1,   374,    20,
     339,   345,   340,    -1,   374,    20,    37,   339,   345,   340,
      -1,   374,    20,   200,   339,   345,   340,    -1,   374,    20,
      33,   339,   345,   340,    -1,   374,    21,   374,    -1,   374,
      22,   374,    -1,   374,    30,   374,    -1,   374,    23,   374,
      -1,    17,   374,    -1,    18,   374,    -1,     8,     9,   374,
      -1,   339,   374,   340,    -1,   374,    15,   157,    -1,   374,
      15,    18,   157,    -1,   374,    15,     6,    -1,   374,    15,
      18,     6,    -1,   374,    19,   374,    36,   374,    -1,   374,
      -1,   374,   338,   375,    -1,   339,   375,   340,    -1,   375,
      -1,   375,   338,   376,    -1,   374,    16,   339,   375,   340,
      -1,   339,   375,   340,    16,   339,   376,   340,    -1,   374,
      18,    16,   339,   375,   340,    -1,   339,   375,   340,    18,
      16,   339,   375,   340,    -1,   374,    16,   339,   345,   340,
      -1,   339,   375,   340,    16,   339,   345,   340,    -1,   374,
      18,    16,   339,   345,   340,    -1,   339,   375,   340,    18,
      16,   339,   345,   340,    -1,    99,   339,   345,   340,    -1,
      18,    99,   339,   345,   340,    -1,   328,   339,    26,   340,
      -1,   328,   339,   374,   340,    -1,   333,   339,   374,   340,
      -1,   334,   339,   374,   340,    -1,   335,   339,   374,   340,
      -1,   336,   339,   374,   340,    -1,   328,   339,   357,   340,
      -1,   333,   339,   357,   340,    -1,   334,   339,   357,   340,
      -1,   335,   339,   357,   340,    -1,   336,   339,   357,   340,
      -1,   324,   339,   374,   338,   374,   340,    -1,   324,   339,
     374,   107,   374,   340,    -1,   324,   339,   374,   338,   374,
     338,   374,   340,    -1,   324,   339,   374,   107,   374,   104,
     374,   340,    -1,   325,   339,   374,   340,    -1,   325,   339,
     377,   374,   107,   374,   340,    -1,   329,   339,   374,   340,
      -1,   330,   339,   374,    39,   378,   340,    -1,   331,   339,
     375,   340,    -1,   134,    -1,   225,    -1,    47,    -1,    -1,
     126,    -1,     4,    -1,    89,    -1,   103,    -1,    53,    -1,
     326,   339,   374,   338,   379,   340,    -1,   327,   339,   374,
     338,   379,   340,    -1,   127,   374,    73,    -1,   127,   374,
      75,    -1,   127,   374,    76,    -1,   127,   374,    77,    -1,
     127,   374,    74,    -1,   127,   374,   249,    -1,   127,   374,
     248,    -1,   127,   374,   251,    -1,   127,   374,   175,    -1,
      51,   374,   380,    96,    -1,    51,   374,   380,    93,   374,
      96,    -1,    51,   380,    96,    -1,    51,   380,    93,   374,
      96,    -1,   243,   374,   218,   374,    -1,   380,   243,   374,
     218,   374,    -1,   374,    14,   374,    -1,   374,    18,    14,
     374,    -1,   374,    13,   374,    -1,   374,    18,    13,   374,
      -1,   381,    -1,    62,    69,   382,     3,    -1,    62,   191,
     382,     3,    -1,    -1,   117,    18,    99,    -1,   383,    -1,
      62,   386,   214,   382,     3,   339,   387,   340,    -1,    62,
     386,   214,   382,     3,   341,     3,   339,   387,   340,    -1,
      62,   386,   214,   382,     3,   339,   387,   340,   384,    -1,
      62,   386,   214,   382,     3,   384,    -1,    62,   386,   214,
     382,     3,   341,     3,   339,   387,   340,   384,    -1,    62,
     386,   214,   382,     3,   341,     3,   384,    -1,   385,   364,
     345,    -1,    -1,   118,    -1,   183,    -1,    -1,   215,    -1,
     388,    -1,   388,   338,   387,    -1,     3,   390,   389,    -1,
     170,   131,   339,   356,   340,    -1,   131,   339,   356,   340,
      -1,   119,   339,   356,   340,    -1,   109,   119,   339,   356,
     340,    -1,   109,   131,   339,   356,   340,    -1,    -1,   389,
      18,   157,    -1,   389,   157,    -1,   389,    80,     4,    -1,
     389,    80,     5,    -1,   389,    80,     7,    -1,   389,    80,
       6,    -1,   389,    41,    -1,   389,   229,   131,    -1,   389,
     170,   131,    -1,   389,   131,    -1,   389,    57,     4,    -1,
     389,   229,   339,   356,   340,    -1,    45,   392,    -1,   222,
     392,   394,    -1,   199,   392,   394,    -1,   150,   392,   394,
      -1,   125,   392,   394,    -1,   126,   392,   394,    -1,    43,
     392,   394,    -1,   178,   392,   394,    -1,    89,   392,   394,
      -1,   103,   392,   394,    -1,    78,   392,   394,    -1,    71,
      -1,   219,    -1,   220,    -1,    72,    -1,   248,    -1,    53,
     392,   395,    -1,   241,   392,   395,    -1,    44,   392,    -1,
     240,   339,     5,   340,    -1,   221,    -1,    46,    -1,   149,
      -1,   144,    -1,   223,   393,   395,    -1,   216,   393,   395,
      -1,   151,   393,   395,    -1,   145,   393,   395,    -1,    97,
     339,   391,   340,   395,    -1,   197,   339,   391,   340,   395,
      -1,     4,    -1,   391,   338,     4,    -1,    -1,   339,     5,
     340,    -1,   339,     5,   338,     5,   340,    -1,    -1,    44,
      -1,    -1,   394,   231,    -1,   394,   250,    -1,    -1,   395,
      53,   197,     3,    -1,   395,    55,     3,    -1,   396,    -1,
      62,   172,   159,     3,   339,   356,   340,   168,   159,     3,
      -1,    62,   172,   159,     3,   339,   356,   340,   158,    20,
       5,   168,   159,     3,    -1,   397,    -1,    62,   398,   119,
       3,   399,   159,     3,   339,   401,   340,    -1,    -1,   229,
      -1,   109,    -1,   202,    -1,    -1,   235,   400,    -1,   320,
      -1,   321,    -1,     3,   392,   349,    -1,     3,   392,   349,
     338,   401,    -1,   402,    -1,   139,   214,     3,   107,   375,
     246,     4,   338,     4,   190,    20,     7,    -1,   139,   214,
       3,   107,   375,   246,     4,   338,     4,    -1,    38,   214,
       3,   107,   375,   246,     4,   338,     4,    -1,    38,   214,
       3,   107,   375,   246,     4,   338,     4,   190,    20,     7,
      -1,   403,    -1,    90,   119,     3,   159,     3,    -1,   404,
      -1,    90,    69,   405,     3,    -1,    90,   191,   405,     3,
      -1,    -1,   117,    99,    -1,   406,    -1,    90,   386,   214,
     405,   407,   408,    -1,     3,    -1,     3,   341,     3,    -1,
     407,   338,     3,    -1,   407,   338,     3,   341,     3,    -1,
      -1,   185,    -1,    50,    -1,   409,    -1,   124,   411,   412,
       3,   413,   239,   414,   410,    -1,    -1,   159,   160,   131,
     232,   416,    -1,    -1,   411,   147,    -1,   411,    81,    -1,
     411,   113,    -1,   411,   118,    -1,   128,    -1,    -1,    -1,
     339,   356,   340,    -1,   339,   415,   340,    -1,   339,   415,
     340,   338,   414,    -1,   374,    -1,    80,    -1,   374,   338,
     415,    -1,    80,   338,   415,    -1,   124,   411,   412,     3,
     197,   416,   410,    -1,   124,   411,   412,     3,   413,   345,
     410,    -1,     3,    20,   374,    -1,     3,    20,    80,    -1,
     416,   338,     3,    20,   374,    -1,   416,   338,     3,    20,
      80,    -1,   417,    -1,   198,   418,   278,   419,   420,    -1,
     198,   296,   420,    -1,   198,   418,   297,   107,     3,   419,
     420,    -1,   198,    62,    69,     3,    -1,   198,    62,   191,
       3,    -1,   198,    62,   214,     3,    -1,   198,    69,     3,
      -1,   198,   191,     3,    -1,   198,   298,     3,   299,    -1,
     198,   298,     3,   300,    -1,   198,   301,   302,    -1,   198,
     303,   354,    -1,   198,   374,   303,    -1,   198,   304,   104,
       8,    -1,   198,   119,   107,     3,   419,    -1,   198,   305,
     300,    -1,   198,   422,   299,    -1,   198,   323,   278,   419,
     420,    -1,   198,   289,    -1,   198,   418,   306,    -1,   198,
     423,   300,   420,    -1,   198,   214,   300,   419,   420,    -1,
     198,   295,   197,   420,    -1,   198,   307,   419,   421,    -1,
     198,   423,   308,   420,    -1,   198,   309,   354,    -1,   198,
     374,   309,    -1,    -1,    -1,   107,     3,    -1,    -1,    14,
       4,    -1,    -1,    14,   374,    -1,    -1,   322,    -1,    -1,
     281,    -1,   282,    -1,    83,     3,    -1,   424,    -1,    82,
     425,   107,   361,   346,   352,   354,    -1,    82,   425,   107,
     426,   235,   361,   346,    -1,    82,   425,   426,   107,   361,
     346,    -1,   425,   147,    -1,   425,   174,    -1,   425,   118,
      -1,    -1,     3,   427,    -1,   426,   338,     3,   427,    -1,
      -1,   341,    26,    -1,   428,    -1,   232,   363,   197,   429,
     346,    -1,   374,    20,   374,    -1,   429,   338,   374,    20,
     374,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   442,   442,   456,   469,   478,   490,   494,   498,   505,
     506,   509,   510,   515,   516,   518,   519,   520,   523,   524,
     527,   528,   531,   532,   535,   536,   538,   539,   540,   543,
     544,   545,   553,   554,   569,   570,   571,   572,   573,   577,
     578,   582,   583,   584,   588,   591,   592,   596,   597,   601,
     603,   605,   606,   609,   610,   613,   614,   615,   630,   631,
     632,   633,   634,   637,   638,   639,   642,   643,   647,   648,
     649,   653,   654,   655,   656,   659,   660,   668,   669,   674,
     681,   682,   683,   684,   685,   686,   687,   688,   690,   691,
     692,   693,   694,   695,   697,   698,   700,   701,   702,   704,
     705,   706,   707,   708,   710,   711,   712,   713,   715,   716,
     717,   718,   721,   722,   723,   724,   727,   730,   731,   732,
     735,   736,   739,   740,   741,   743,   745,   746,   747,   748,
     750,   751,   761,   762,   763,   764,   765,   766,   767,   768,
     769,   770,   771,   774,   775,   776,   777,   778,   779,   780,
     781,   782,   785,   786,   787,   790,   791,   792,   793,   794,
     795,   798,   799,   803,   804,   805,   806,   807,   808,   809,
     810,   811,   815,   816,   817,   818,   821,   822,   825,   826,
     829,   830,   836,   840,   841,   844,   845,   850,   853,   857,
     861,   866,   870,   875,   879,   883,   884,   885,   888,   889,
     892,   893,   898,   899,   900,   901,   902,   903,   905,   906,
     907,   908,   909,   910,   911,   912,   913,   914,   915,   916,
     917,   921,   922,   923,   924,   925,   926,   927,   928,   929,
     930,   931,   932,   933,   934,   935,   936,   937,   938,   939,
     940,   942,   943,   944,   945,   946,   947,   948,   949,   950,
     951,   953,   954,   957,   958,   959,   962,   963,   966,   967,
     968,   971,   972,   974,   979,   982,   984,   992,   996,  1000,
    1001,  1002,  1003,  1006,  1007,  1010,  1011,  1014,  1015,  1019,
    1022,  1027,  1028,  1029,  1036,  1039,  1043,  1047,  1048,  1051,
    1052,  1056,  1059,  1063,  1064,  1065,  1066,  1069,  1070,  1071,
    1077,  1080,  1086,  1087,  1090,  1091,  1092,  1093,  1094,  1097,
    1097,  1100,  1101,  1104,  1105,  1109,  1110,  1111,  1112,  1115,
    1119,  1124,  1127,  1130,  1133,  1138,  1141,  1142,  1143,  1144,
    1145,  1146,  1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,
    1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,  1163,  1164,
    1165,  1166,  1167,  1169,  1173,  1174,  1177,  1178,  1181,  1182,
    1184,  1185,  1188,  1189,  1190,  1193,  1196,  1198,  1203,  1207,
    1212,  1213,  1214,  1215,  1219,  1220,  1223,  1224,  1227,  1230,
    1233,  1234
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NAME", "STRING", "INTNUM", "BOOL",
  "APPROXNUM", "USERVAR", "ASSIGN", "OR", "XOR", "ANDOP", "REGEXP", "LIKE",
  "IS", "IN", "'!'", "NOT", "BETWEEN", "COMPARISON", "'|'", "'&'", "SHIFT",
  "'+'", "'-'", "'*'", "'/'", "'%'", "MOD", "'^'", "UMINUS", "ADD", "ALL",
  "ALTER", "ANALYZE", "AND", "ANY", "APPEND", "AS", "ASC",
  "AUTO_INCREMENT", "BEFORE", "BIGINT", "BINARY", "BIT", "BLOB", "BOTH",
  "BY", "CALL", "CASCADE", "CASE", "CHANGE", "CHAR", "CHECK", "COLLATE",
  "COLUMN", "COMMENT", "CONDITION", "CONSTRAINT", "CONTINUE", "CONVERT",
  "CREATE", "CROSS", "CURRENT_DATE", "CURRENT_TIME", "CURRENT_TIMESTAMP",
  "CURRENT_USER", "CURSOR", "DATABASE", "DATABASES", "DATE", "DATETIME",
  "DAY_HOUR", "DAY", "DAY_MICROSECOND", "DAY_MINUTE", "DAY_SECOND",
  "DECIMAL", "DECLARE", "DEFAULT", "DELAYED", "DELETE", "DESC", "DESCRIBE",
  "DETERMINISTIC", "DISTINCT", "DISTINCTROW", "DIV", "DOUBLE", "DROP",
  "DUAL", "EACH", "ELSE", "ELSEIF", "ENCLOSED", "END", "ENUM", "ESCAPED",
  "EXISTS", "EXIT", "EXPLAIN", "FETCH", "FLOAT", "FOR", "FORCE", "FOREIGN",
  "FROM", "FULL", "FULLTEXT", "GRANT", "GROUP", "HAVING", "HIGH_PRIORITY",
  "HOUR_MICROSECOND", "HOUR_MINUTE", "HOUR_SECOND", "IF", "IGNORE",
  "INDEX", "INFILE", "INNER", "INOUT", "INSENSITIVE", "INSERT", "INT",
  "INTEGER", "INTERVAL", "INTO", "ITERATE", "JOIN", "KEY", "KEYS", "KILL",
  "LEADING", "LEAVE", "LEFT", "LIMIT", "LINES", "LOAD", "LOCALTIME",
  "LOCALTIMESTAMP", "LOCK", "LONG", "LONGBLOB", "LONGTEXT", "LOOP",
  "LOW_PRIORITY", "MATCH", "MEDIUMBLOB", "MEDIUMINT", "MEDIUMTEXT",
  "MINUTE_MICROSECOND", "MINUTE_SECOND", "MODIFIES", "NATURAL",
  "NO_WRITE_TO_BINLOG", "NULLX", "NUMBER", "ON", "DUPLICATE", "OPTIMIZE",
  "OPTION", "OPTIONALLY", "ORDER", "OUT", "OUTER", "OUTFILE",
  "PARTITIONED", "PRECISION", "PRIMARY", "PROCEDURE", "PROJECTION",
  "PURGE", "QUICK", "QUARTER", "READ", "READS", "REAL", "REFERENCES",
  "RELEASE", "RENAME", "REPEAT", "REPLACE", "REQUIRE", "RESTRICT",
  "RETURN", "REVOKE", "RIGHT", "ROLLUP", "SAMPLE", "SCHEMA", "SCHEMAS",
  "SECOND_MICROSECOND", "SELECT", "SENSITIVE", "SEPARATOR", "SET", "SHOW",
  "SMALLINT", "SOME", "SONAME", "SPATIAL", "SPECIFIC", "SQL",
  "SQLEXCEPTION", "SQLSTATE", "SQLWARNING", "SQL_BIG_RESULT",
  "SQL_CALC_FOUND_ROWS", "SQL_SMALL_RESULT", "SSL", "STARTING",
  "STRAIGHT_JOIN", "TABLE", "TEMPORARY", "TEXT", "TERMINATED", "THEN",
  "TIME", "TIMESTAMP", "TINYBLOB", "TINYINT", "TINYTEXT", "TO", "TRAILING",
  "TRIGGER", "UNDO", "UNION", "UNIQUE", "UNLOCK", "UNSIGNED", "UPDATE",
  "USAGE", "USE", "USING", "UTC_DATE", "UTC_TIME", "UTC_TIMESTAMP",
  "VALUES", "VARBINARY", "VARCHAR", "VARYING", "WHEN", "WHERE", "WHILE",
  "WITH", "WRITE", "YEAR", "YEAR_MONTH", "ZEROFILL", "WEEK", "DO",
  "MAX_QUERIES_PER_HOUR", "MAX_UPDATES_PER_HOUR",
  "MAX_CONNECTIONS_PER_HOUR", "MAX_USER_CONNECTIONS", "USER", "TRUNCATE",
  "FAST", "MEDIUM", "EXTENDED", "CHANGED", "LEAVES", "MASTER", "QUERY",
  "CACHE", "SLAVE", "BEGINT", "COMMIT", "START", "TRANSACTION", "NO",
  "CHAIN", "AUTOCOMMIT", "SAVEPOINT", "ROLLBACK", "LOCAL", "TABLES",
  "ISOLATION", "LEVEL", "GLOBAL", "SESSION", "UNCOMMITTED", "COMMITTED",
  "REPEATABLE", "SERIALIZABLE", "IDENTIFIED", "PASSWORD", "PRIVILEGES",
  "BACKUP", "CHECKSUM", "REPAIR", "USE_FRM", "RESTORE", "CHARACTER",
  "COLLATION", "COLUMNS", "ENGINE", "LOGS", "STATUS", "STORAGE", "ENGINES",
  "ERRORS", "GRANTS", "INNODB", "PROCESSLIST", "TRIGGERS", "VARIABLES",
  "WARNINGS", "FLUSH", "HOSTS", "DES_KEY_FILE", "USER_RESOURCES",
  "CONNECTION", "RESET", "PREPARE", "DEALLOCATE", "EXECUTE", "WORK",
  "BTREE", "HASH", "BDB", "OPEN", "FSUBSTRING", "FTRIM", "FDATE_ADD",
  "FDATE_SUB", "FCOUNT", "FUPPER", "FCAST", "FCOALESCE", "FCONVERT",
  "FSUM", "FAVG", "FMIN", "FMAX", "';'", "','", "'('", "')'", "'.'",
  "$accept", "stmt_list", "stmt", "select_stmt", "opt_where",
  "opt_groupby", "groupby_list", "opt_asc_desc", "opt_with_rollup",
  "opt_having", "opt_orderby", "orderby_list", "opt_limit",
  "opt_into_list", "column_list", "select_opts", "distinct_list",
  "select_expr_list", "select_expr", "table_references", "table_reference",
  "table_factor", "opt_as", "opt_as_alias", "join_table",
  "opt_inner_cross", "opt_outer", "left_right_full",
  "opt_left_or_right_outer", "opt_join_condition", "join_condition",
  "table_subquery", "expr", "expr_list", "opt_expr_list", "trim_ltb",
  "cast_data_type", "interval_exp", "case_list", "create_database_stmt",
  "opt_if_not_exists", "create_table_stmt", "create_select_statement",
  "opt_ignore_replace", "opt_temporary", "create_col_list",
  "create_definition", "column_atts", "data_type", "enum_list",
  "opt_length", "opt_binary", "opt_uz", "opt_csc",
  "create_projection_stmt", "create_index_stmt", "index_att",
  "opt_using_type", "index_type", "index_col_list", "load_table_stmt",
  "drop_index_stmt", "drop_database_stmt", "opt_if_exists",
  "drop_table_stmt", "table_list", "opt_rc", "insert_stmt",
  "opt_ondupupdate", "insert_opts", "opt_into", "opt_col_names",
  "insert_vals_list", "insert_vals", "insert_asgn_list", "show_stmt",
  "opt_full", "opt_from", "opt_like_string", "opt_like_expr", "opt_bdb",
  "opt_trans_level", "delete_stmt", "delete_opts", "delete_list",
  "opt_dot_star", "update_stmt", "update_set_list", YY_NULL
};
#endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short int yyr1[] =
{
       0,   342,   343,   343,   343,   343,   344,   345,   345,   346,
     346,   347,   347,   348,   348,   349,   349,   349,   350,   350,
     351,   351,   352,   352,   353,   353,   354,   354,   354,   355,
     355,   355,   356,   356,   357,   357,   357,   357,   357,   358,
     358,   359,   359,   359,   360,   361,   361,   362,   362,   363,
     363,   363,   363,   364,   364,   365,   365,   365,   366,   366,
     366,   366,   366,   367,   367,   367,   368,   368,   369,   369,
     369,   370,   370,   370,   370,   371,   371,   372,   372,   373,
     374,   374,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   374,   374,   374,   374,   374,   374,   375,   375,   375,
     376,   376,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   374,   377,   377,   377,   378,   378,   378,   378,   378,
     378,   374,   374,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   374,   374,   374,   374,   380,   380,   374,   374,
     374,   374,   344,   381,   381,   382,   382,   344,   383,   383,
     383,   383,   383,   383,   384,   385,   385,   385,   386,   386,
     387,   387,   388,   388,   388,   388,   388,   388,   389,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     389,   390,   390,   390,   390,   390,   390,   390,   390,   390,
     390,   390,   390,   390,   390,   390,   390,   390,   390,   390,
     390,   390,   390,   390,   390,   390,   390,   390,   390,   390,
     390,   391,   391,   392,   392,   392,   393,   393,   394,   394,
     394,   395,   395,   395,   344,   396,   396,   344,   397,   398,
     398,   398,   398,   399,   399,   400,   400,   401,   401,   344,
     402,   402,   402,   402,   344,   403,   344,   404,   404,   405,
     405,   344,   406,   407,   407,   407,   407,   408,   408,   408,
     344,   409,   410,   410,   411,   411,   411,   411,   411,   412,
     412,   413,   413,   414,   414,   415,   415,   415,   415,   409,
     409,   416,   416,   416,   416,   344,   417,   417,   417,   417,
     417,   417,   417,   417,   417,   417,   417,   417,   417,   417,
     417,   417,   417,   417,   417,   417,   417,   417,   417,   417,
     417,   417,   417,   418,   419,   419,   420,   420,   421,   421,
     422,   422,   423,   423,   423,   344,   344,   424,   424,   424,
     425,   425,   425,   425,   426,   426,   427,   427,   344,   428,
     429,   429
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     2,     3,     2,     3,     1,     3,    11,     0,
       2,     0,     4,     1,     3,     0,     1,     1,     0,     2,
       0,     2,     0,     3,     2,     4,     0,     2,     4,     0,
       5,     8,     1,     3,     0,     1,     5,     1,     2,     1,
       3,     1,     3,     1,     2,     1,     3,     1,     1,     2,
       4,     3,     3,     0,     1,     2,     1,     0,     5,     3,
       5,     6,     5,     0,     1,     1,     0,     1,     1,     1,
       1,     2,     2,     2,     0,     0,     1,     2,     4,     3,
       1,     1,     3,     3,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     2,     2,     3,     3,     3,     3,
       5,     6,     6,     6,     3,     3,     3,     3,     2,     2,
       3,     3,     3,     4,     3,     4,     5,     1,     3,     3,
       1,     3,     5,     7,     6,     8,     5,     7,     6,     8,
       4,     5,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     6,     6,     8,     8,     4,     7,     4,
       6,     4,     1,     1,     1,     0,     1,     1,     1,     1,
       1,     6,     6,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     6,     3,     5,     4,     5,     3,     4,
       3,     4,     1,     4,     4,     0,     3,     1,     8,    10,
       9,     6,    11,     8,     3,     0,     1,     1,     0,     1,
       1,     3,     3,     5,     4,     4,     5,     5,     0,     3,
       2,     3,     3,     3,     3,     2,     3,     3,     2,     3,
       5,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     3,     3,     2,
       4,     1,     1,     1,     1,     3,     3,     3,     3,     5,
       5,     1,     3,     0,     3,     5,     0,     1,     0,     2,
       2,     0,     4,     3,     1,    10,    13,     1,    10,     0,
       1,     1,     1,     0,     2,     1,     1,     3,     5,     1,
      12,     9,     9,    12,     1,     5,     1,     4,     4,     0,
       2,     1,     6,     1,     3,     3,     5,     0,     1,     1,
       1,     8,     0,     5,     0,     2,     2,     2,     2,     1,
       0,     0,     3,     3,     5,     1,     1,     3,     3,     7,
       7,     3,     3,     5,     5,     1,     5,     3,     7,     4,
       4,     4,     3,     3,     4,     4,     3,     3,     3,     4,
       5,     3,     3,     5,     2,     3,     4,     5,     4,     4,
       4,     3,     3,     0,     0,     2,     0,     2,     0,     2,
       0,     1,     0,     1,     1,     2,     1,     7,     7,     6,
       2,     2,     2,     0,     2,     4,     0,     2,     1,     5,
       3,     5
};

/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const unsigned char yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const unsigned char yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0
};

/* YYDEFACT[S] -- default reduction number in state S.  Performed when
   YYTABLE doesn't specify something else to do.  Zero means the default
   is an error.  */
static const unsigned short int yydefact[] =
{
       0,     0,     0,   198,   373,     0,   198,   304,     0,    34,
     353,     0,     0,     0,     6,   182,   187,   264,   267,   279,
     284,   286,   291,   300,   325,   366,   378,     4,     0,   185,
     271,     0,   185,   272,   199,   270,     0,     0,     0,   365,
     289,     0,   289,     0,   310,     0,    37,    35,     0,    80,
      84,    85,    87,    86,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   363,   364,   344,     0,
     356,     0,     0,    26,     0,     0,   354,    26,   361,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    57,     0,     0,
      53,     1,     0,     0,     2,     0,     0,     0,     0,     0,
     185,     0,   376,     0,   372,   370,   371,     0,     0,     0,
       0,     0,   289,   306,   307,   308,   309,   305,     0,     0,
       0,    38,    39,    43,     7,    41,    57,     0,     0,   108,
       0,   109,    95,    94,     0,     0,     0,     0,     0,     0,
     332,     0,     0,   333,   354,   356,     0,   327,     0,   336,
       0,   337,     0,   341,     0,   358,   351,   354,     0,     0,
       0,     0,    34,     0,     0,     0,    34,    34,    34,    34,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   338,   352,   354,     0,   345,   342,   356,
     356,    56,     0,     0,    49,     0,     0,    45,    47,    48,
       0,    54,     0,     5,     3,     0,     0,   183,     0,   184,
       0,   273,     0,   374,    57,     9,     0,     0,     0,   290,
     287,     0,   288,     0,   311,     0,     0,     0,     0,     0,
       0,    44,    82,    83,   110,     0,     0,     0,     0,   174,
       0,   329,   330,   331,     0,   354,   356,   348,   357,   334,
     335,    27,   339,   355,     0,   349,   356,     0,   154,   152,
     153,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   111,     0,    97,    98,    96,   180,   178,   114,
       0,   112,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    99,   104,   105,   107,    88,    89,    90,    91,    93,
      92,   106,   356,     0,   346,   350,    55,    57,    79,    52,
      65,    70,    64,    68,    74,    69,     0,     0,     0,    66,
       0,     9,    51,     0,   186,     0,   195,     0,     0,   377,
       0,     0,    22,     0,     9,   376,   285,   293,   297,     0,
       0,     0,     0,     0,    40,     0,     0,    42,     0,     0,
       0,   172,     0,     0,   130,   340,   347,     0,   359,   343,
       0,     0,   147,     0,     0,     0,   132,   138,   133,   149,
     155,   151,   139,   134,   140,   135,   141,   136,   142,   137,
     119,   118,     0,     0,   115,   113,     0,     0,   181,   179,
       0,     0,     0,     0,     0,     0,   326,   354,    50,    66,
      66,    66,     0,    59,    46,     0,    67,     0,     0,     0,
     379,     0,    32,     0,   196,   197,     0,     0,   191,    53,
     275,   276,   274,     0,    10,     0,    26,     9,   369,   375,
       0,   299,   298,     0,   292,     0,   302,     0,     0,   302,
       0,    36,     0,     0,     9,   130,   176,     0,   175,     0,
      28,     0,     0,     0,     0,     0,     0,   157,   160,   158,
     159,   156,     0,     0,     0,   126,   122,     0,     0,   116,
       0,     0,     0,   100,   356,    73,    71,    72,     0,     0,
      75,     0,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   200,   195,     0,     0,     0,   367,   368,
     294,   295,     0,     0,     0,   319,   312,     0,   302,   320,
       0,     0,     0,    11,   173,   177,     0,   144,     0,   143,
       0,     0,   161,   162,   150,     0,   120,     0,     0,   128,
     124,   103,   101,   102,   328,    62,    60,     0,     0,    58,
      76,     0,     0,     0,    33,     0,     0,   253,   253,   253,
     242,   253,   232,   235,   253,   253,     0,   253,   253,   253,
     244,   256,   243,   253,   256,   253,     0,   253,   256,   233,
     234,   241,   253,   256,     0,   253,   236,   208,     0,     0,
       0,     0,     0,   195,     0,     0,   193,   194,     0,    23,
      15,     0,   322,   321,     0,     0,   316,   315,     0,   301,
       0,     0,    30,     0,    20,     0,     0,   148,   163,   167,
     164,   165,   166,   171,   169,   168,   170,   127,     0,   123,
       0,     0,    77,     0,    61,    99,   282,     0,     0,     0,
     258,   239,   221,   261,   258,   258,     0,   258,   258,   258,
     257,   261,   258,   261,   258,     0,   258,   261,   258,   261,
       0,   261,   202,     0,     0,     0,     0,     0,   190,   201,
       0,   253,     0,    16,    17,    24,   296,     0,     0,     0,
       0,   313,   281,     0,     0,     0,    22,   146,   145,   121,
     129,   125,     0,     0,     0,   265,     0,   227,   237,   231,
     229,   251,     0,   230,   225,   226,   248,   224,   247,   228,
       0,   223,   246,   222,   245,     0,   238,     0,   215,     0,
       0,   218,   210,     0,     0,     0,     0,   205,   204,     0,
     195,    15,   268,     0,     0,   324,   323,   318,   317,     0,
       0,     0,    18,    13,    21,    26,    78,     0,     0,     0,
     254,   259,   260,     0,     0,     0,   261,   261,   240,   209,
     219,   211,   212,   214,   213,   217,   216,     0,   206,   207,
     203,   192,   277,    25,   303,   314,     0,    31,     0,    12,
       0,     8,   283,     0,     0,     0,   263,   252,   249,   250,
       0,     0,   280,    19,    14,   266,   255,   262,   220,   278
};

/* YYPDEFGOTO[NTERM-NUM].  */
static const short int yydefgoto[] =
{
      -1,    12,    13,    14,   362,   634,   762,   695,   799,   706,
     456,   619,   161,   249,   443,    48,   131,   134,   135,   216,
     217,   218,   222,   214,   219,   348,   437,   349,   432,   569,
     570,   100,   290,   182,   557,   282,   492,   485,   146,    15,
     107,    16,   448,   449,    36,   522,   523,   682,   607,   722,
     660,   671,   717,   718,    17,    18,    37,   358,   452,   692,
      19,    20,    21,   119,    22,   368,   464,    23,   535,    44,
     128,   371,   538,   628,   466,    24,    94,   165,   157,   275,
      95,    96,    25,    38,   117,   233,    26,   351
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -485
static const short int yypact[] =
{
     141,  -306,  -179,   218,  -485,    83,     6,  -485,  -120,    -9,
     634,    -1,   945,  -205,  -485,  -485,  -485,  -485,  -485,  -485,
    -485,  -485,  -485,  -485,  -485,  -485,  -485,  -485,   150,    81,
    -485,    69,    81,  -485,  -485,  -485,    37,   128,    33,  -485,
     146,   270,   146,    61,   208,   276,  -485,   788,   994,   -59,
    -485,  -485,  -485,  -485,   287,  1213,  1242,  1213,  1213,  1026,
      53,   282,   -40,   202,   310,    20,  -485,  -485,  -485,   127,
     315,   337,    42,   234,   268,    74,   269,   234,  -485,   100,
      49,    50,    52,    65,    66,    71,    73,    80,    82,    84,
      88,    92,  1423,  2063,    19,   109,  -235,     2,     7,   219,
     383,  -485,    89,    95,  -485,   327,   419,   435,   436,   458,
      81,   462,   125,     8,  -485,  -485,  -485,   -93,   368,   467,
     313,   473,   146,  -485,  -485,  -485,  -485,  -485,   475,   373,
     140,  -485,  1869,  -485,   -47,   143,  2558,    36,  1213,  1251,
     145,  1251,  -485,  -485,  1213,  2087,   -71,   488,   490,   492,
    -485,   303,   495,  -485,   269,   315,   497,  -485,  -231,  -485,
    1213,  -485,   494,  -485,   501,   491,  -485,   269,  1213,   389,
    1213,  1213,   438,  1213,  1213,  1423,   971,   971,   971,   971,
    1423,    77,   178,  1213,  1213,  1213,  1213,  1213,    14,   180,
     292,  1213,   825,  1213,  1213,  1213,  1213,  1213,  1213,  1213,
    1213,  1213,  1213,  -485,  -485,   269,   413,  -485,  -485,   315,
     315,  -485,   518,   522,  -485,   186,   203,   162,  -485,  -485,
    1213,  -485,   555,  -485,  -485,  1423,   460,  -485,   221,  -485,
     558,   328,   538,  -485,     4,   321,  -212,    -1,   563,  -485,
    -485,   564,  -485,   567,  -140,  1423,  1213,  1213,    -1,   464,
     994,  -485,  -485,  -485,  2602,   303,  2108,   -41,  1213,  -485,
    1213,  -485,  -485,  -485,   232,   269,   315,  -485,  -485,  -485,
    -485,  1916,  -485,  -485,  1213,  -485,   315,  1848,  -485,  -485,
    -485,  1593,  1213,  1958,  1979,   233,   240,  1614,  1635,  2580,
    2000,   262,   263,  1656,   264,  1677,   265,  1698,   266,  1764,
     272,  1423,  -485,   195,  2664,  2683,   526,  1716,  1716,  -485,
      38,  -485,  1058,  1213,  1213,   274,  2529,   277,   278,   279,
    1058,   486,   334,   505,   424,   372,   372,   578,   578,   578,
     578,  -485,   315,   606,  -485,  -485,  -485,    27,  -485,  -485,
    -485,  -485,  -485,  -485,   -57,  -485,    -1,    -1,   485,   454,
    2623,  -194,  -485,   375,  -485,   616,   -65,   -19,   476,  -485,
     201,  1213,   472,    -1,   321,   125,  -485,   302,   -38,   646,
     616,  -167,   404,   316,  -485,    47,    -1,  -485,   317,  1213,
    1213,  -485,  2450,  2129,  -485,  -485,  -485,  1213,  2602,  -485,
    1213,  1213,  -485,  2429,   528,   528,  -485,  -485,  -485,  -485,
      30,  -485,  -485,  -485,  -485,  -485,  -485,  -485,  -485,  -485,
     195,  -485,   314,   644,  -485,  -485,   322,   323,  1716,  1716,
    1058,  1213,   303,   303,   303,   325,  -485,   269,  -485,   454,
     454,   454,   531,   507,  -485,    -1,  -485,   539,   825,  1213,
    -485,   664,   333,   332,  -485,  -485,    26,   670,  -485,   383,
    -485,  -485,  -485,   671,  2602,   628,   234,   321,  -485,  -485,
     674,  -485,  -485,   677,  -485,   661,  -138,   344,   347,   534,
     683,  -485,   678,   541,   321,   571,  2602,  2471,  -485,  1213,
    2602,  1441,  1572,  1213,  1213,   357,   362,  -485,  -485,  -485,
    -485,  -485,   364,  1058,   366,  -485,  -485,   369,   370,   603,
     371,   381,   387,  -485,   315,  -485,  -485,  -485,    -1,  1213,
     -96,    -1,    87,  2644,   374,   616,    51,  2190,   101,   367,
     390,   600,   392,   396,   -62,   303,   397,  1213,  -485,  -485,
    -485,   398,  1082,   577,   735,  -485,  -485,  1162,   534,  -485,
     402,   736,   739,   633,  -485,  2602,  1213,  -485,  1213,  -485,
    1785,  2150,  -485,  -485,  -485,   405,   409,   408,  1058,  -485,
    -485,  -485,  -485,  -485,  -485,  -485,  2602,  1213,   410,  -485,
    -485,   -92,   825,   746,  -485,   731,   593,   415,   415,   415,
    -485,   415,  -485,  -485,   415,   415,   416,   415,   415,   415,
    -485,   712,  -485,   415,   712,   415,   418,   415,   712,  -485,
    -485,  -485,   415,   712,   421,   415,  -485,  -485,   422,   431,
     616,   616,   437,  -103,    26,    26,  -485,  -485,   755,  -485,
    2492,   772,  -485,  2602,   647,   759,   442,  2021,   441,  -485,
     778,   615,  -485,   737,   675,  1806,  1827,  -485,  -485,  -485,
    -485,  -485,  -485,  -485,  -485,  -485,  -485,  -485,  1423,  -485,
     446,   448,  2602,   616,  -485,   231,   607,   793,   796,   795,
    -485,  -485,  -485,  -485,  -485,  -485,   797,  -485,  -485,  -485,
    -485,  -485,  -485,  -485,  -485,   797,  -485,  -485,  -485,  -485,
     798,  -485,   137,   616,   616,   468,   469,   616,  -485,  -485,
     470,   415,   471,  -485,  -485,   466,  -485,   570,  1185,  1162,
    1162,   478,   617,   659,  1213,  1213,   472,  -485,  -485,  -485,
    -485,  -485,   481,   803,   656,  -485,  -105,  -172,   216,  -172,
    -172,  -485,   -50,  -172,  -172,  -172,   216,  -172,   216,  -172,
     -45,  -172,   216,  -172,   216,   487,   216,   669,  -485,   830,
     453,  -485,  -485,   704,  -113,   496,   498,  -485,  -485,   500,
     -99,    -7,  -485,  1213,   646,  -485,  2602,  -485,  -485,   347,
     817,   838,   598,  2042,  2602,   234,  -485,   839,   686,   842,
    -485,  -485,  -485,   654,   849,   850,  -485,  -485,  -485,  -485,
    -485,  -485,  -485,  -485,  -485,  -485,  -485,   616,  -485,  -485,
    -485,  -485,   515,  -485,   517,  -485,   852,  -485,   667,  -485,
    1213,  -485,  -485,   854,   520,   858,  -485,  -485,   216,   216,
     523,   755,  -485,  -485,  -485,  -485,  -485,  -485,  -485,  -485
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -485,  -485,   853,   -90,  -228,  -485,    64,   115,  -485,  -485,
     161,   116,   -74,  -485,  -369,   207,   -98,   618,  -485,   -85,
    -485,    -5,   423,  -119,  -485,  -485,   -77,  -485,  -485,  -485,
     299,  -485,   -10,  -171,   223,  -485,  -485,   480,   728,  -485,
      10,  -485,  -484,  -485,   871,  -266,  -485,  -485,  -485,   204,
    1603,  -275,  -182,  -465,  -485,  -485,  -485,  -485,  -485,    67,
    -485,  -485,  -485,    16,  -485,  -485,  -485,  -485,  -384,  -485,
    -485,  -485,   122,  -332,   129,  -485,  -485,  -141,  -139,  -485,
    -485,  -485,  -485,  -485,   769,   519,  -485,  -485
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -382
static const short int yytable[] =
{
      93,   467,    97,   166,   291,   211,    99,   211,   215,   300,
      97,   234,   461,   266,   237,   444,   267,   251,   786,   444,
     309,   533,   258,   363,    46,   259,   276,     9,   235,   517,
     211,    27,   310,   693,   487,    28,   112,   132,   136,   252,
     616,   212,   109,   212,   414,   139,   141,   142,   143,   145,
     361,   429,   380,   444,   353,   381,   444,   369,   121,   771,
     -29,   264,   253,   567,   332,   209,   212,   567,   269,   270,
     334,   335,   468,   210,   372,    40,   694,    47,   772,   430,
     445,   248,   181,   488,   445,   539,    39,   183,   184,   185,
     186,   187,   188,   189,    45,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   445,   489,
     230,   445,   147,   440,   385,    41,   238,   386,   254,   688,
     411,   431,   104,   490,   256,   518,   458,   389,   243,   568,
     113,   417,     1,   568,   439,   519,   574,   462,   373,   374,
     271,   114,   364,   105,   629,   737,   491,   520,   277,   281,
     283,   284,   287,   288,   289,   378,   293,   295,   297,   299,
     181,   311,   260,   304,   305,   306,   307,   308,   738,     2,
     115,   316,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   426,   739,   415,   521,    42,   106,   370,
     534,     9,   260,     3,   337,   472,   726,   116,   728,   575,
     350,   412,   732,   413,   734,   473,   736,   740,   428,   576,
     608,    34,   416,     4,     5,   340,   787,   359,   108,   529,
     425,     6,   609,   769,  -188,   770,   132,   132,  -189,  -376,
     136,   685,   686,   375,   148,   238,   543,   111,   382,   498,
     383,   110,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   434,   118,   388,     7,   791,   149,   741,   773,
     341,   774,   393,   120,   446,   122,   447,   615,   457,   129,
       8,   469,   137,   342,   712,   150,   504,    29,   775,   123,
     776,   474,   -63,   775,   742,   777,   138,   205,   343,   151,
     463,   450,   451,   418,   419,   313,   314,   743,   315,   152,
     181,   808,   809,   153,   745,   746,   206,   344,   749,   673,
     154,   124,   556,   677,   155,   207,   125,    30,   679,   156,
     497,  -380,   500,   501,   502,     9,   126,  -269,    98,    10,
     158,   433,   -57,   213,   159,   360,    98,    98,   689,   690,
     345,   454,   505,   506,   507,   127,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   564,   744,   757,   758,   476,
     477,   160,   162,    11,   163,   346,   164,   480,   167,   286,
     481,   482,   528,   292,   294,   296,   298,   651,   168,   169,
      31,   170,    49,    50,    51,    52,    53,    54,   198,   199,
     200,   201,   202,   555,   171,   172,    55,    56,   208,    32,
     173,   499,   174,    57,    58,   301,   220,   302,   810,   175,
      33,   176,   221,   177,  -380,  -380,   223,   178,   512,   513,
     510,   179,   224,    34,   225,   617,   278,   226,   227,   228,
      59,    49,    50,    51,    52,    53,    54,    35,   196,   197,
     198,   199,   200,   201,   202,    55,    56,   781,   782,   783,
     784,   229,    57,    58,   285,   231,   232,   239,   650,   545,
     240,    46,   241,   550,   551,  -381,   242,   556,   244,   246,
     245,   250,   719,   720,   255,   723,   724,   725,    62,    59,
     727,   261,   729,   262,   731,   263,   733,     9,   265,   566,
     347,   268,   272,   565,   273,   274,   571,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   620,   303,   312,
     333,   336,   623,   279,    47,   337,   338,   627,   195,   196,
     197,   198,   199,   200,   201,   202,   635,    62,   636,   186,
     187,   188,   189,   339,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   652,   352,   354,
     355,   356,   655,   357,   359,   361,   365,   366,  -381,  -381,
     367,   376,   384,   396,  -130,  -130,  -130,  -130,  -130,  -130,
     397,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,   401,   402,   404,   406,   408,  -130,   202,   427,
    -130,  -130,   410,   420,   280,   435,   422,   423,   424,   442,
     436,   441,  -130,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,  -130,   453,   455,    49,    50,    51,
      52,    53,    54,   460,  -130,  -130,  -130,  -130,  -130,   465,
     470,    55,    56,   493,  -130,   484,   471,   475,    57,    58,
     494,   508,   495,   496,  -130,   503,   509,  -130,   514,   511,
    -130,   515,   516,   524,   526,  -130,   527,   530,  -130,  -130,
     531,   532,  -130,  -130,   536,    59,   537,   540,   756,   627,
     627,   801,  -130,   533,   763,   764,    60,   552,   541,  -130,
     542,  -130,   553,    61,   554,   558,   610,  -130,  -130,   559,
     560,   561,   573,    80,    81,    82,    83,    84,    85,    86,
      87,   562,    88,    89,    90,    91,  -130,   563,    92,   611,
    -130,   612,   613,    62,   614,  -130,   618,   624,   625,   621,
     630,   631,   632,   620,   633,   647,  -130,   648,   649,   653,
     656,   657,   658,    63,   659,   666,   670,   675,   691,  -130,
     680,   683,    80,    81,    82,    83,    84,    85,    86,    87,
     684,    88,    89,    90,    91,   696,   687,    92,   697,   698,
     699,   701,   702,   703,  -130,   704,   710,   705,   711,  -130,
     763,    49,    50,    51,    52,    53,    54,   713,   714,   715,
     716,   721,   754,   735,   753,    55,    56,   760,   747,   748,
     750,   752,    57,    58,  -130,  -130,   759,  -130,   761,  -130,
    -130,   766,  -130,   767,   768,    64,   779,   778,    49,    50,
      51,    52,    53,    54,   780,   785,   788,   796,   789,    59,
     790,   797,    55,    56,   798,   803,   802,   804,    65,    57,
      58,   805,   806,   811,   807,   534,   813,   815,   317,   812,
     816,   817,   318,   818,   814,   103,   792,   765,   377,   793,
     654,   709,   525,   257,  -130,   486,    59,    43,   819,   730,
    -130,   795,   236,   794,   459,     0,     0,    62,     0,     0,
       0,     0,     0,     0,     0,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,     0,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,     0,     0,     0,    66,    67,     0,     0,     0,
       0,     0,     0,    68,    62,     0,     0,     0,     0,    69,
      70,     0,    71,  -360,  -362,    72,     0,    73,    74,    75,
       0,    76,  -362,    77,     0,   101,   102,   130,     0,     0,
       0,     0,     0,     0,     0,     0,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,     0,    88,    89,    90,
      91,     0,     0,    92,    49,    50,    51,    52,    53,    54,
       0,     0,     0,     2,     0,     0,     0,     0,    55,    56,
       0,     0,     0,     0,     0,    57,    58,    49,    50,    51,
      52,    53,    54,     0,    46,     0,     0,     3,     0,     0,
       0,    55,    56,     0,     0,     0,     0,     0,    57,    58,
     133,     0,    59,     0,     0,   319,     0,     4,     5,    49,
      50,    51,    52,    53,    54,     6,     0,     0,     0,     0,
       0,     0,     0,    55,    56,    59,     0,     0,     0,     0,
      57,    58,     0,     0,     0,     0,     0,    47,     0,     0,
       0,    49,    50,    51,    52,    53,    54,     0,     0,     7,
      62,     0,     0,     0,     0,    55,    56,    59,     0,     0,
       0,     0,    57,    58,     8,    49,    50,    51,    52,    53,
      54,     0,     0,    62,     0,     0,     0,     0,     0,    55,
      56,     0,     0,     0,     0,     0,    57,    58,     0,    59,
       0,     0,    80,    81,    82,    83,    84,    85,    86,    87,
       0,    88,    89,    90,    91,    62,     0,    92,     0,     0,
       0,     0,     0,    59,     0,     0,     0,     0,     0,     9,
       0,     0,     0,    10,     0,     0,     0,     0,     0,    80,
      81,    82,    83,    84,    85,    86,    87,    62,    88,    89,
      90,    91,   622,     0,   320,    49,    50,    51,    52,    53,
      54,     0,     0,     0,     0,     0,     0,    11,     0,    55,
      56,    62,     0,     0,     0,     0,    57,    58,    49,    50,
      51,    52,    53,    54,     0,     0,     0,     0,     0,     0,
       0,     0,    55,    56,     0,     0,     0,     0,     0,    57,
      58,     0,     0,    59,     0,     0,    49,    50,    51,    52,
      53,    54,     0,     0,     0,     0,     0,     0,     0,     0,
      55,    56,     0,     0,     0,     0,    59,    57,    58,     0,
       0,     0,   626,     0,     0,    49,    50,    51,    52,    53,
      54,     0,     9,     0,     0,     0,     0,     0,     0,    55,
      56,    62,     0,     0,    59,   755,    57,    58,     0,   144,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,     0,     0,    62,     0,     0,     0,     0,     0,
       0,     0,     0,    59,     0,    80,    81,    82,    83,    84,
      85,    86,    87,     0,    88,    89,    90,    91,     0,     0,
      92,     0,    62,     0,     0,     0,     0,     0,    80,    81,
      82,    83,    84,    85,    86,    87,     0,    88,    89,    90,
      91,     0,     0,    92,     0,     0,     0,     0,     0,     0,
       0,   140,     0,     0,     0,     0,     0,     0,     0,     0,
      80,    81,    82,    83,    84,    85,    86,    87,     0,    88,
      89,    90,    91,     0,     0,    92,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,    81,    82,    83,    84,    85,    86,    87,
       0,    88,    89,    90,    91,     0,     0,   180,     0,     0,
       0,     0,     0,     0,     0,     0,    80,    81,    82,    83,
      84,    85,    86,    87,     0,    88,    89,    90,    91,     0,
       0,    92,     0,     0,     0,     0,    49,    50,    51,    52,
      53,    54,     0,     0,     0,     0,     0,     0,     0,     0,
      55,    56,     0,     0,     0,     0,     0,    57,    58,     0,
       0,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,     0,     0,    59,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,    81,    82,    83,
      84,    85,    86,    87,     0,    88,    89,    90,    91,     0,
       0,    92,     0,     0,     0,     0,     0,     0,     0,    80,
      81,    82,    83,    84,    85,    86,    87,     0,    88,    89,
      90,    91,    62,     0,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,    81,    82,
      83,    84,    85,    86,    87,   546,    88,    89,    90,    91,
       0,     0,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,    81,    82,    83,
      84,    85,    86,    87,     0,    88,    89,    90,    91,     0,
       0,    92,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,  -382,
    -382,  -382,  -382,     0,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,    80,    81,    82,
      83,    84,    85,    86,    87,     0,    88,    89,    90,    91,
       0,     0,   180,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   183,   184,   185,   186,   187,   188,
     189,   547,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     548,     0,   549,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   183,   184,   185,   186,
     187,   188,   189,   392,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,     0,     0,     0,
       0,     0,     0,     0,   398,   390,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   183,   184,
     185,   186,   187,   188,   189,   399,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   183,
     184,   185,   186,   187,   188,   189,   403,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     183,   184,   185,   186,   187,   188,   189,   405,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   183,   184,   185,   186,   187,   188,   189,   407,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,     0,     0,     0,   183,   184,   185,
     186,   187,   188,   189,   409,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   183,   184,
     185,   186,   187,   188,   189,   637,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   183,
     184,   185,   186,   187,   188,   189,   707,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     183,   184,   185,   186,   187,   188,   189,   708,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   661,   662,     0,   663,     0,   391,   664,   665,     0,
     667,   668,   669,     0,     0,     0,   672,     0,   674,     0,
     676,     0,     0,     0,     0,   678,     0,   247,   681,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   638,   639,   640,   641,   642,     0,     0,
       0,     0,     0,   577,   578,   579,   580,     0,     0,     0,
       0,     0,     0,   581,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   387,     0,     0,     0,     0,     0,
       0,   582,   583,     0,     0,     0,     0,     0,   584,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   585,
       0,     0,     0,     0,     0,     0,     0,   586,     0,     0,
       0,     0,     0,   587,   751,     0,   394,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   588,   589,   395,     0,     0,
       0,     0,     0,     0,     0,   643,   379,     0,     0,     0,
     144,     0,     0,     0,   590,   591,     0,     0,   301,   592,
     593,   594,     0,     0,     0,     0,     0,   479,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   700,
       0,     0,     0,     0,     0,     0,   203,     0,   595,     0,
       0,     0,   204,     0,     0,     0,     0,     0,     0,     0,
     800,     0,     0,     0,     0,     0,     0,   596,     0,   597,
       0,     0,     0,     0,     0,     0,     0,     0,   644,   645,
       0,   646,     0,     0,     0,     0,   598,     0,     0,   599,
     600,   601,   602,   603,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     604,   605,     0,     0,     0,     0,     0,     0,   606,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   693,     0,     0,     0,   483,     0,     0,   183,
     184,   185,   186,   187,   188,   189,   478,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
       0,   211,     0,     0,     0,   421,     0,   544,   183,   184,
     185,   186,   187,   188,   189,   694,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,     0,
     183,   184,   185,   186,   187,   188,   189,   212,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,     0,   183,   184,   185,   186,   187,   188,   189,   400,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   438,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   572,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   185,   186,   187,   188,   189,
       0,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const unsigned char yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   231,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    59,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,    69,    71,    73,    75,    77,
       0,    79,    81,    83,    85,    87,    89,    91,    93,    95,
      97,    99,   101,   103,   105,   107,   109,   111,   113,   115,
     117,   119,     0,     0,     0,     0,     0,   121,     0,     0,
     123,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,   133,   135,   137,   139,     0,
       0,     0,     0,     0,   141,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   143,     0,    65,   145,     0,     0,
     147,     0,     0,     0,     0,   149,     0,     0,   151,   153,
       0,     0,   155,   157,     0,     0,     0,     0,     0,     0,
       0,     0,   159,     0,     0,     0,     0,     0,     0,   161,
       0,   163,     0,     0,     0,     0,     0,   165,   167,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   169,     0,     0,     0,
     171,     0,     0,     0,     0,   173,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   175,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   177,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   179,     0,     0,     0,     0,   181,
       0,     1,     3,     5,     7,     9,    11,     0,     0,     0,
       0,     0,     0,     0,     0,    13,    15,     0,     0,     0,
       0,     0,    17,    19,   183,   185,     0,   187,     0,   189,
     191,     0,   193,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   195,     0,     0,     0,     0,     0,
     197,     0,     0,     0,     0,     0,     0,    23,     0,     0,
       0,     0,     0,     0,     0,   199,   201,   203,   205,   207,
     209,   211,   213,     0,   215,   217,   219,   221,   223,   225,
     227,   229,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    27,    29,    31,    33,    35,    37,    39,
       0,    41,    43,    45,    47,     0,     0,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,     0,     0,
       0,     0,     0,    53,    55,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short int yyconfl[] =
{
       0,    35,     0,    35,     0,    35,     0,    35,     0,    35,
       0,    35,     0,    35,     0,    35,     0,    35,     0,    35,
       0,    35,     0,    35,     0,    35,     0,    35,     0,    35,
       0,    35,     0,    35,     0,    35,     0,    35,     0,    35,
       0,    35,     0,    35,     0,    35,     0,    35,     0,    35,
       0,    39,     0,    39,     0,    39,     0,    39,     0,   117,
       0,   376,     0,   117,     0,    59,     0,   131,     0,   131,
       0,   131,     0,   131,     0,   131,     0,   131,     0,   131,
       0,   131,     0,   131,     0,   131,     0,   131,     0,   131,
       0,   131,     0,   131,     0,   131,     0,   131,     0,   131,
       0,   131,     0,   131,     0,   131,     0,   131,     0,   131,
       0,   131,     0,   131,     0,   131,     0,   131,     0,   131,
       0,   131,     0,   131,     0,   131,     0,   131,     0,   131,
       0,   131,     0,   131,     0,   131,     0,   131,     0,   131,
       0,   131,     0,   131,     0,   131,     0,   131,     0,   131,
       0,   131,     0,   131,     0,   131,     0,   131,     0,   131,
       0,   131,     0,   131,     0,   131,     0,   131,     0,   131,
       0,   131,     0,   131,     0,   131,     0,   131,     0,   131,
       0,   131,     0,   131,     0,   131,     0,   131,     0,   131,
       0,   131,     0,   131,     0,   131,     0,   131,     0,   131,
       0,   131,     0,   131,     0,   131,     0,   131,     0,   131,
       0,   131,     0,   131,     0,   131,     0,   131,     0,   131,
       0,   131,     0,   131,     0,   131,     0,   131,     0,   131,
       0,    75,     0
};

static const short int yycheck[] =
{
      10,   370,     3,    77,   175,     3,    11,     3,    98,   180,
       3,     3,    50,   154,   107,   118,   155,   136,   131,   118,
       6,   159,    93,   235,    33,    96,   167,   194,   113,     3,
       3,   337,    18,    40,     4,   214,     3,    47,    48,     3,
     524,    39,    32,    39,     6,    55,    56,    57,    58,    59,
     244,   108,    93,   118,   225,    96,   118,   197,    42,   231,
     107,   151,    26,   159,   205,   300,    39,   159,   299,   300,
     209,   210,   239,   308,   245,    69,    83,    86,   250,   136,
     183,   128,    92,    53,   183,   469,     3,    10,    11,    12,
      13,    14,    15,    16,   214,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,   183,    89,
     110,   183,    69,   351,   265,   119,   338,   266,   138,   613,
     301,   188,   337,   103,   144,   109,   364,   276,   122,   235,
     107,   312,     1,   235,   338,   119,   515,   185,   246,   247,
     160,   118,   237,     3,   538,    18,   126,   131,   168,   169,
     170,   171,   172,   173,   174,   255,   176,   177,   178,   179,
     180,   157,   243,   183,   184,   185,   186,   187,    41,    38,
     147,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   332,    57,   157,   170,   191,   117,   339,
     338,   194,   243,    62,     3,   158,   671,   174,   673,   158,
     220,    16,   677,    18,   679,   168,   681,    80,   337,   168,
     119,   215,   312,    82,    83,    63,   339,    26,   159,   457,
     320,    90,   131,   338,   337,   340,   246,   247,   337,   235,
     250,   610,   611,   248,   191,   338,   474,   119,   258,   420,
     260,   214,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,   347,   117,   274,   124,   750,   214,   131,    53,
     108,    55,   282,     3,   339,   214,   341,   339,   363,     3,
     139,   371,   341,   121,   653,     3,   427,    69,   338,    81,
     340,   376,   130,   338,   157,   340,     9,   278,   136,   339,
     338,   320,   321,   313,   314,    13,    14,   170,    16,   107,
     320,   776,   777,     3,   683,   684,   297,   155,   687,   594,
     300,   113,   493,   598,   197,   306,   118,   109,   603,    14,
     420,   244,   422,   423,   424,   194,   128,   119,   339,   198,
       3,   346,   338,   341,   302,   341,   339,   339,   614,   615,
     188,   361,   429,   430,   431,   147,    22,    23,    24,    25,
      26,    27,    28,    29,    30,   504,   229,   699,   700,   379,
     380,   137,   104,   232,   300,   213,   107,   387,   278,   172,
     390,   391,   456,   176,   177,   178,   179,   558,   339,   339,
     172,   339,     3,     4,     5,     6,     7,     8,    26,    27,
      28,    29,    30,   493,   339,   339,    17,    18,   299,   191,
     339,   421,   339,    24,    25,   338,   197,   340,   787,   339,
     202,   339,    39,   339,   337,   338,   337,   339,   438,   439,
     435,   339,   337,   215,   107,   525,    47,    18,     3,     3,
      51,     3,     4,     5,     6,     7,     8,   229,    24,    25,
      26,    27,    28,    29,    30,    17,    18,     4,     5,     6,
       7,     3,    24,    25,    26,     3,   341,    99,   558,   479,
       3,    33,   159,   483,   484,   244,     3,   648,     3,   339,
     107,   338,   664,   665,   339,   667,   668,   669,    99,    51,
     672,     3,   674,     3,   676,     3,   678,   194,     3,   509,
     338,     4,     8,   508,     3,    14,   511,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,   527,   340,   339,
     107,     3,   532,   134,    86,     3,   340,   537,    23,    24,
      25,    26,    27,    28,    29,    30,   546,    99,   548,    13,
      14,    15,    16,   340,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,   567,     3,    99,
     339,     3,   572,   235,    26,   244,     3,     3,   337,   338,
       3,   107,   340,   340,     3,     4,     5,     6,     7,     8,
     340,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,   340,   340,   340,   340,   340,    36,    30,     3,
      39,    40,   340,   339,   225,   130,   339,   339,   339,     3,
     166,   246,    51,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    63,   159,   164,     3,     4,     5,
       6,     7,     8,   341,    73,    74,    75,    76,    77,     3,
     246,    17,    18,   339,    83,   127,   340,   340,    24,    25,
      16,   130,   340,   340,    93,   340,   159,    96,     4,   130,
      99,   338,   340,     3,     3,   104,    48,     3,   107,   108,
       3,    20,   111,   112,   340,    51,   339,     4,   698,   699,
     700,   765,   121,   159,   704,   705,    62,   340,    20,   128,
     159,   130,   340,    69,   340,   339,   339,   136,   137,   340,
     340,   340,   338,   324,   325,   326,   327,   328,   329,   330,
     331,   340,   333,   334,   335,   336,   155,   340,   339,   339,
     159,   131,   340,    99,   338,   164,   339,   160,     3,   341,
     338,     5,     3,   753,   111,   340,   175,   338,   340,   339,
       4,    20,   159,   119,   339,   339,    44,   339,     3,   188,
     339,   339,   324,   325,   326,   327,   328,   329,   330,   331,
     339,   333,   334,   335,   336,     3,   339,   339,   131,    20,
     338,   340,     4,   168,   213,    48,   340,   112,   340,   218,
     800,     3,     4,     5,     6,     7,     8,   190,     5,     3,
       5,     4,   232,     5,   338,    17,    18,   190,   340,   340,
     340,   340,    24,    25,   243,   244,   338,   246,   159,   248,
     249,   340,   251,    20,   168,   191,   157,   340,     3,     4,
       5,     6,     7,     8,     4,   131,   340,    20,   340,    51,
     340,     3,    17,    18,   246,   159,     7,     5,   214,    24,
      25,   197,     3,   338,     4,   338,   189,     3,    33,     7,
     340,     3,    37,   340,   800,    12,   751,   706,   250,   753,
     571,   648,   449,   145,   303,   395,    51,     6,   811,   675,
     309,   759,   113,   754,   365,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   324,   325,   326,   327,   328,
     329,   330,   331,    -1,   333,   334,   335,   336,   337,   338,
     339,   340,    -1,    -1,    -1,   281,   282,    -1,    -1,    -1,
      -1,    -1,    -1,   289,    99,    -1,    -1,    -1,    -1,   295,
     296,    -1,   298,   299,   300,   301,    -1,   303,   304,   305,
      -1,   307,   308,   309,    -1,     0,     1,   159,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,    -1,   333,   334,   335,
     336,    -1,    -1,   339,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    17,    18,
      -1,    -1,    -1,    -1,    -1,    24,    25,     3,     4,     5,
       6,     7,     8,    -1,    33,    -1,    -1,    62,    -1,    -1,
      -1,    17,    18,    -1,    -1,    -1,    -1,    -1,    24,    25,
      26,    -1,    51,    -1,    -1,   200,    -1,    82,    83,     3,
       4,     5,     6,     7,     8,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    51,    -1,    -1,    -1,    -1,
      24,    25,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    -1,   124,
      99,    -1,    -1,    -1,    -1,    17,    18,    51,    -1,    -1,
      -1,    -1,    24,    25,   139,     3,     4,     5,     6,     7,
       8,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    -1,    -1,    24,    25,    -1,    51,
      -1,    -1,   324,   325,   326,   327,   328,   329,   330,   331,
      -1,   333,   334,   335,   336,    99,    -1,   339,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,   324,
     325,   326,   327,   328,   329,   330,   331,    99,   333,   334,
     335,   336,    80,    -1,   339,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    -1,    -1,    -1,   232,    -1,    17,
      18,    99,    -1,    -1,    -1,    -1,    24,    25,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,    24,
      25,    -1,    -1,    51,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    -1,    51,    24,    25,    -1,
      -1,    -1,    80,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    99,    -1,    -1,    51,    80,    24,    25,    -1,   243,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    -1,   324,   325,   326,   327,   328,
     329,   330,   331,    -1,   333,   334,   335,   336,    -1,    -1,
     339,    -1,    99,    -1,    -1,    -1,    -1,    -1,   324,   325,
     326,   327,   328,   329,   330,   331,    -1,   333,   334,   335,
     336,    -1,    -1,   339,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     324,   325,   326,   327,   328,   329,   330,   331,    -1,   333,
     334,   335,   336,    -1,    -1,   339,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   324,   325,   326,   327,   328,   329,   330,   331,
      -1,   333,   334,   335,   336,    -1,    -1,   339,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   324,   325,   326,   327,
     328,   329,   330,   331,    -1,   333,   334,   335,   336,    -1,
      -1,   339,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    -1,    -1,    24,    25,    -1,
      -1,    10,    11,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   324,   325,   326,   327,
     328,   329,   330,   331,    -1,   333,   334,   335,   336,    -1,
      -1,   339,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,
     325,   326,   327,   328,   329,   330,   331,    -1,   333,   334,
     335,   336,    99,    -1,   339,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,   325,   326,
     327,   328,   329,   330,   331,   104,   333,   334,   335,   336,
      -1,    -1,   339,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   324,   325,   326,   327,
     328,   329,   330,   331,    -1,   333,   334,   335,   336,    -1,
      -1,   339,    10,    11,    12,    13,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    10,    11,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    10,    11,    12,    13,    14,    15,
      16,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    10,    11,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    10,    11,    12,    13,
      14,    15,    16,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    10,    11,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    10,    11,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    13,
      14,    15,    16,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,   324,   325,   326,
     327,   328,   329,   330,   331,    -1,   333,   334,   335,   336,
      -1,    -1,   339,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    10,    11,    12,    13,    14,    15,
      16,   340,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    10,    11,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    10,    11,    12,    13,
      14,    15,    16,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    10,    11,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    10,    11,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    10,
      11,    12,    13,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     338,    -1,   340,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,    13,
      14,    15,    16,   340,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   340,   107,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    11,
      12,    13,    14,    15,    16,   340,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    10,
      11,    12,    13,    14,    15,    16,   340,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      10,    11,    12,    13,    14,    15,    16,   340,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    10,    11,    12,    13,    14,    15,    16,   340,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    10,    11,    12,    13,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    10,    11,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    10,    11,    12,
      13,    14,    15,    16,   340,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    10,    11,
      12,    13,    14,    15,    16,   340,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    10,
      11,    12,    13,    14,    15,    16,   340,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      10,    11,    12,    13,    14,    15,    16,   340,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,   578,   579,    -1,   581,    -1,   338,   584,   585,    -1,
     587,   588,   589,    -1,    -1,    -1,   593,    -1,   595,    -1,
     597,    -1,    -1,    -1,    -1,   602,    -1,   338,   605,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   338,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    72,    -1,    -1,    -1,    -1,    -1,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,
      -1,    -1,    -1,   103,   691,    -1,   338,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   125,   126,   338,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   175,   218,    -1,    -1,    -1,
     243,    -1,    -1,    -1,   144,   145,    -1,    -1,   338,   149,
     150,   151,    -1,    -1,    -1,    -1,    -1,   218,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   338,
      -1,    -1,    -1,    -1,    -1,    -1,   303,    -1,   178,    -1,
      -1,    -1,   309,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     338,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,   199,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   249,
      -1,   251,    -1,    -1,    -1,    -1,   216,    -1,    -1,   219,
     220,   221,   222,   223,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     240,   241,    -1,    -1,    -1,    -1,    -1,    -1,   248,    10,
      11,    12,    13,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      10,    11,    12,    13,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    10,    11,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    10,    11,    12,    13,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    -1,   107,    -1,    -1,    10,
      11,    12,    13,    14,    15,    16,    96,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,     3,    -1,    -1,    -1,    36,    -1,    96,    10,    11,
      12,    13,    14,    15,    16,    83,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      10,    11,    12,    13,    14,    15,    16,    39,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    -1,    10,    11,    12,    13,    14,    15,    16,    39,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    10,    11,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    10,    11,    12,    13,    14,    15,
      16,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    11,    12,    13,    14,    15,
      16,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short int yystos[] =
{
       0,     1,    38,    62,    82,    83,    90,   124,   139,   194,
     198,   232,   343,   344,   345,   381,   383,   396,   397,   402,
     403,   404,   406,   409,   417,   424,   428,   337,   214,    69,
     109,   172,   191,   202,   215,   229,   386,   398,   425,     3,
      69,   119,   191,   386,   411,   214,    33,    86,   357,     3,
       4,     5,     6,     7,     8,    17,    18,    24,    25,    51,
      62,    69,    99,   119,   191,   214,   281,   282,   289,   295,
     296,   298,   301,   303,   304,   305,   307,   309,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   333,   334,
     335,   336,   339,   374,   418,   422,   423,     3,   339,   363,
     373,     0,     1,   344,   337,     3,   117,   382,   159,   382,
     214,   119,     3,   107,   118,   147,   174,   426,   117,   405,
       3,   405,   214,    81,   113,   118,   128,   147,   412,     3,
     159,   358,   374,    26,   359,   360,   374,   341,     9,   374,
      99,   374,   374,   374,   243,   374,   380,    69,   191,   214,
       3,   339,   107,     3,   300,   197,    14,   420,     3,   302,
     137,   354,   104,   300,   107,   419,   354,   278,   339,   339,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   339,
     339,   374,   375,    10,    11,    12,    13,    14,    15,    16,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,   303,   309,   278,   297,   306,   299,   300,
     308,     3,    39,   341,   365,   345,   361,   362,   363,   366,
     197,    39,   364,   337,   337,   107,    18,     3,     3,     3,
     382,     3,   341,   427,     3,   361,   426,   107,   338,    99,
       3,   159,     3,   405,     3,   107,   339,   338,   128,   355,
     338,   365,     3,    26,   374,   339,   374,   380,    93,    96,
     243,     3,     3,     3,   345,     3,   419,   420,     4,   299,
     300,   374,     8,     3,    14,   421,   419,   374,    47,   134,
     225,   374,   377,   374,   374,    26,   357,   374,   374,   374,
     374,   375,   357,   374,   357,   374,   357,   374,   357,   374,
     375,   338,   340,   340,   374,   374,   374,   374,   374,     6,
      18,   157,   339,    13,    14,    16,   374,    33,    37,   200,
     339,   374,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   374,   419,   107,   420,   420,     3,     3,   340,   340,
      63,   108,   121,   136,   155,   188,   213,   338,   367,   369,
     374,   429,     3,   375,    99,   339,     3,   235,   399,    26,
     341,   244,   346,   235,   361,     3,     3,     3,   407,   197,
     339,   413,   375,   358,   358,   363,   107,   359,   345,   218,
      93,    96,   374,   374,   340,   419,   420,   338,   374,   420,
     107,   338,   340,   374,   338,   338,   340,   340,   340,   340,
      39,   340,   340,   340,   340,   340,   340,   340,   340,   340,
     340,   375,    16,    18,     6,   157,   345,   375,   374,   374,
     339,    36,   339,   339,   339,   345,   420,     3,   365,   108,
     136,   188,   370,   363,   361,   130,   166,   368,    20,   338,
     346,   246,     3,   356,   118,   183,   339,   341,   384,   385,
     320,   321,   400,   159,   374,   164,   352,   361,   346,   427,
     341,    50,   185,   338,   408,     3,   416,   356,   239,   345,
     246,   340,   158,   168,   361,   340,   374,   374,    96,   218,
     374,   374,   374,   107,   127,   379,   379,     4,    53,    89,
     103,   126,   378,   339,    16,   340,   340,   345,   375,   374,
     345,   345,   345,   340,   419,   368,   368,   368,   130,   159,
     363,   130,   374,   374,     4,   338,   340,     3,   109,   119,
     131,   170,   387,   388,     3,   364,     3,    48,   354,   346,
       3,     3,    20,   159,   338,   410,   340,   339,   414,   410,
       4,    20,   159,   346,    96,   374,   104,   340,   338,   340,
     374,   374,   340,   340,   340,   345,   375,   376,   339,   340,
     340,   340,   340,   340,   420,   363,   374,   159,   235,   371,
     372,   363,    20,   338,   356,   158,   168,    43,    44,    45,
      46,    53,    71,    72,    78,    89,    97,   103,   125,   126,
     144,   145,   149,   150,   151,   178,   197,   199,   216,   219,
     220,   221,   222,   223,   240,   241,   248,   390,   119,   131,
     339,   339,   131,   340,   338,   339,   384,   345,   339,   353,
     374,   341,    80,   374,   160,     3,    80,   374,   415,   410,
     338,     5,     3,   111,   347,   374,   374,   340,    73,    74,
      75,    76,    77,   175,   248,   249,   251,   340,   338,   340,
     345,   375,   374,   339,   372,   374,     4,    20,   159,   339,
     392,   392,   392,   392,   392,   392,   339,   392,   392,   392,
      44,   393,   392,   393,   392,   339,   392,   393,   392,   393,
     339,   392,   389,   339,   339,   356,   356,   339,   384,   387,
     387,     3,   401,    40,    83,   349,     3,   131,    20,   338,
     338,   340,     4,   168,    48,   112,   351,   340,   340,   376,
     340,   340,   356,   190,     5,     3,     5,   394,   395,   394,
     394,     4,   391,   394,   394,   394,   395,   394,   395,   394,
     391,   394,   395,   394,   395,     5,   395,    18,    41,    57,
      80,   131,   157,   170,   229,   356,   356,   340,   340,   356,
     340,   392,   340,   338,   232,    80,   374,   415,   415,   338,
     190,   159,   348,   374,   374,   352,   340,    20,   168,   338,
     340,   231,   250,    53,    55,   338,   340,   340,   340,   157,
       4,     4,     5,     6,     7,   131,   131,   339,   340,   340,
     340,   384,   349,   353,   416,   414,    20,     3,   246,   350,
     338,   354,     7,   159,     5,   197,     3,     4,   395,   395,
     356,   338,     7,   189,   348,     3,   340,     3,   340,   401
};

/* Error token number */
#define YYTERROR 1


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval)
#endif


#undef yynerrs
#define yynerrs (yystackp->yyerrcnt)
#undef yychar
#define yychar (yystackp->yyrawchar)
#undef yylval
#define yylval (yystackp->yyval)
#undef yylloc
#define yylloc (yystackp->yyloc)


static const int YYEOF = 0;
static const int YYEMPTY = -2;

typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;

#define YYCHK(YYE)                                                           \
   do { YYRESULTTAG yyflag = YYE; if (yyflag != yyok) return yyflag; }       \
   while (YYID (0))

#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, struct ParseResult* result)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (result);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, struct ParseResult* result)
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, result);
  YYFPRINTF (yyoutput, ")");
}

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)          \
do {                                                            \
  if (yydebug)                                                  \
    {                                                           \
      YYFPRINTF (stderr, "%s ", Title);                         \
      yy_symbol_print (stderr, Type, Value, result);        \
      YYFPRINTF (stderr, "\n");                                 \
    }                                                           \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

#else /* !YYDEBUG */

# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)

#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
# if (! defined __cplusplus \
      || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL))
#  define YYSTACKEXPANDABLE 1
# else
#  define YYSTACKEXPANDABLE 0
# endif
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyexpandGLRStack (Yystack);                       \
  } while (YYID (0))
#else
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyMemoryExhausted (Yystack);                      \
  } while (YYID (0))
#endif


#if YYERROR_VERBOSE

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
static size_t
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      size_t yyn = 0;
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
    return strlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

#endif /* !YYERROR_VERBOSE */

/** State numbers, as in LALR(1) machine */
typedef int yyStateNum;

/** Rule numbers, as in LALR(1) machine */
typedef int yyRuleNum;

/** Grammar symbol */
typedef short int yySymbol;

/** Item references, as in LALR(1) machine */
typedef short int yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState {
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yysval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yyStateNum yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the first token produced by my symbol */
  size_t yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  non-terminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yysval;
  } yysemantics;
};

struct yyGLRStateSet {
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  size_t yysize, yycapacity;
};

struct yySemanticOption {
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;


  int yyerrcnt;
  int yyrawchar;
  YYSTYPE yyval;

  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  size_t yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

static void yyFail (yyGLRStack* yystackp, struct ParseResult* result, const char* yymsg)
  __attribute__ ((__noreturn__));
static void
yyFail (yyGLRStack* yystackp, struct ParseResult* result, const char* yymsg)
{
  if (yymsg != YY_NULL)
    yyerror (result, yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

static void yyMemoryExhausted (yyGLRStack* yystackp)
  __attribute__ ((__noreturn__));
static void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

#if YYDEBUG || YYERROR_VERBOSE
/** A printable representation of TOKEN.  */
static inline const char*
yytokenName (yySymbol yytoken)
{
  if (yytoken == YYEMPTY)
    return "";

  return yytname[yytoken];
}
#endif

/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int) __attribute__ ((__unused__));
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  int i;
  yyGLRState *s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
      YYASSERT (s->yyresolved);
      yyvsp[i].yystate.yyresolved = yytrue;
      yyvsp[i].yystate.yysemantics.yysval = s->yysemantics.yysval;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
     __attribute__ ((__unused__));
static inline int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT.  */
/*ARGSUSED*/ static YYRESULTTAG
yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
              yyGLRStack* yystackp,
              YYSTYPE* yyvalp, struct ParseResult* result)
{
  yybool yynormal __attribute__ ((__unused__)) =
    (yystackp->yysplitPoint == YY_NULL);
  int yylow;
  YYUSE (result);
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = YYEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, N, yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)                                              \
  return yyerror (result, YY_("syntax error: cannot back up")),     \
         yyerrok, yyerr

  yylow = 1;
  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;
  switch (yyn)
    {
        case 2:
/* Line 868 of glr.c  */
#line 443 "sql.ypp"
    { 	
		printf("> \n"); 
		((*yyvalp).ast_node)=new AstStmtList(AST_STMT_LIST,(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.ast_node),NULL);
		if (result->error_number == 0) 
		{
			result->ast  = ((*yyvalp).ast_node);
		}
		else
		{
			result->ast  = NULL;
		} 
  						
  	}
    break;

  case 3:
/* Line 868 of glr.c  */
#line 457 "sql.ypp"
    { 	
		printf(">> \n"); 
		((*yyvalp).ast_node)=new AstStmtList(AST_STMT_LIST,(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node));
		if (result->error_number == 0)
		{
			result->ast  = ((*yyvalp).ast_node);
		}
		else
		{
			result->ast  = NULL;
		}
	}
    break;

  case 4:
/* Line 868 of glr.c  */
#line 470 "sql.ypp"
    { 
		printf(">> \n");
		result->ast  = NULL;	
		result->error_number++;	
		//yyerror(result,"First statement discarded, input new statement"); 
		yyclearin;
		yyerrok; 				
	}
    break;

  case 5:
/* Line 868 of glr.c  */
#line 479 "sql.ypp"
    { 
		printf(">> \n"); 
		result->ast  = NULL;	
		result->error_number++;		
		yyclearin;
		yyerrok; 
	}
    break;

  case 6:
/* Line 868 of glr.c  */
#line 490 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node);}
    break;

  case 7:
/* Line 868 of glr.c  */
#line 495 "sql.ypp"
    {
		((*yyvalp).ast_node)=new AstSelectStmt(AST_SELECT_STMT, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node),NULL,NULL,NULL,NULL,NULL,NULL,NULL);
	}
    break;

  case 8:
/* Line 868 of glr.c  */
#line 500 "sql.ypp"
    {
		((*yyvalp).ast_node)=new AstSelectStmt(AST_SELECT_STMT, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (11))].yystate.yysemantics.yysval.ast_node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (11))].yystate.yysemantics.yysval.ast_node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (11))].yystate.yysemantics.yysval.ast_node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (11))].yystate.yysemantics.yysval.ast_node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((8) - (11))].yystate.yysemantics.yysval.ast_node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (11))].yystate.yysemantics.yysval.ast_node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((10) - (11))].yystate.yysemantics.yysval.ast_node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((11) - (11))].yystate.yysemantics.yysval.ast_node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (11))].yystate.yysemantics.yysval.ast_node));
	}
    break;

  case 9:
/* Line 868 of glr.c  */
#line 505 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL;}
    break;

  case 10:
/* Line 868 of glr.c  */
#line 506 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstWhereClause(AST_WHERE_CLAUSE, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node));}
    break;

  case 11:
/* Line 868 of glr.c  */
#line 509 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL;}
    break;

  case 12:
/* Line 868 of glr.c  */
#line 510 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstGroupByClause(AST_GROUPBY_CLAUSE, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.intval));}
    break;

  case 13:
/* Line 868 of glr.c  */
#line 515 "sql.ypp"
    { ((*yyvalp).ast_node)=new AstGroupByList(AST_GROUPBY_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 14:
/* Line 868 of glr.c  */
#line 516 "sql.ypp"
    { ((*yyvalp).ast_node)=new AstGroupByList(AST_GROUPBY_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 15:
/* Line 868 of glr.c  */
#line 518 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 16:
/* Line 868 of glr.c  */
#line 519 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 17:
/* Line 868 of glr.c  */
#line 520 "sql.ypp"
    { ((*yyvalp).intval) = 1; }
    break;

  case 18:
/* Line 868 of glr.c  */
#line 523 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 19:
/* Line 868 of glr.c  */
#line 524 "sql.ypp"
    { ((*yyvalp).intval) = 1; }
    break;

  case 20:
/* Line 868 of glr.c  */
#line 527 "sql.ypp"
    { ((*yyvalp).ast_node)=NULL; }
    break;

  case 21:
/* Line 868 of glr.c  */
#line 528 "sql.ypp"
    { ((*yyvalp).ast_node)=new AstHavingClause(AST_HAVING_CLAUSE, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node));	}
    break;

  case 22:
/* Line 868 of glr.c  */
#line 531 "sql.ypp"
    { ((*yyvalp).ast_node)=NULL; }
    break;

  case 23:
/* Line 868 of glr.c  */
#line 532 "sql.ypp"
    { ((*yyvalp).ast_node)=new AstOrderByClause(AST_ORDERBY_CLAUSE, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 24:
/* Line 868 of glr.c  */
#line 535 "sql.ypp"
    { ((*yyvalp).ast_node)=new AstOrderByList(AST_ORDERBY_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.intval), NULL);}
    break;

  case 25:
/* Line 868 of glr.c  */
#line 536 "sql.ypp"
    { ((*yyvalp).ast_node)=new AstOrderByList(AST_ORDERBY_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 26:
/* Line 868 of glr.c  */
#line 538 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 27:
/* Line 868 of glr.c  */
#line 539 "sql.ypp"
    { ((*yyvalp).ast_node)=new AstLimitClause(AST_LIMIT_CLAUSE, NULL,(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node));}
    break;

  case 28:
/* Line 868 of glr.c  */
#line 540 "sql.ypp"
    { ((*yyvalp).ast_node)=new AstLimitClause(AST_LIMIT_CLAUSE, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval.ast_node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.ast_node));}
    break;

  case 29:
/* Line 868 of glr.c  */
#line 543 "sql.ypp"
    { ((*yyvalp).ast_node)=NULL; }
    break;

  case 30:
/* Line 868 of glr.c  */
#line 544 "sql.ypp"
    { ((*yyvalp).ast_node)= new AstSelectIntoClause(AST_SELECT_INTO_CLAUSE, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval.ast_node), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.strval)),1);}
    break;

  case 31:
/* Line 868 of glr.c  */
#line 546 "sql.ypp"
    { 
		if ((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (8))].yystate.yysemantics.yysval.subtok) != 4) { yyerror(result,"please give a specific number"); } 
		else    { ((*yyvalp).ast_node)= new AstSelectIntoClause(AST_SELECT_INTO_CLAUSE, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (8))].yystate.yysemantics.yysval.ast_node), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((8) - (8))].yystate.yysemantics.yysval.strval)),atoi((((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (8))].yystate.yysemantics.yysval.strval))); }
	}
    break;

  case 32:
/* Line 868 of glr.c  */
#line 553 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstColumn(AST_COLUMN, string("NULL"), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.strval)));}
    break;

  case 33:
/* Line 868 of glr.c  */
#line 554 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstColumn(AST_COLUMN, string("NULL"), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node));}
    break;

  case 34:
/* Line 868 of glr.c  */
#line 569 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 35:
/* Line 868 of glr.c  */
#line 570 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDistinctClause(AST_DISTINCT_CLAUSE, NULL, 1); }
    break;

  case 36:
/* Line 868 of glr.c  */
#line 571 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDistinctClause(AST_DISTINCT_CLAUSE, (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node), 2); }
    break;

  case 37:
/* Line 868 of glr.c  */
#line 572 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDistinctClause(AST_DISTINCT_CLAUSE, NULL, 0); }
    break;

  case 38:
/* Line 868 of glr.c  */
#line 573 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDistinctClause(AST_DISTINCT_CLAUSE, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node), 3); }
    break;

  case 39:
/* Line 868 of glr.c  */
#line 577 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDistinctList(AST_DISTINCT_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 40:
/* Line 868 of glr.c  */
#line 578 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDistinctList(AST_DISTINCT_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 41:
/* Line 868 of glr.c  */
#line 582 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstSelectList(AST_SELECT_LIST, 0,(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node),NULL);}
    break;

  case 42:
/* Line 868 of glr.c  */
#line 583 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstSelectList(AST_SELECT_LIST, 0,(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node));}
    break;

  case 43:
/* Line 868 of glr.c  */
#line 584 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstSelectList(AST_SELECT_LIST, 1,NULL,NULL);}
    break;

  case 44:
/* Line 868 of glr.c  */
#line 588 "sql.ypp"
    {((*yyvalp).ast_node) = new AstSelectExpr(AST_SELECT_EXPR, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.strval)),(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.ast_node));}
    break;

  case 45:
/* Line 868 of glr.c  */
#line 591 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstFromList(AST_FROM_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 46:
/* Line 868 of glr.c  */
#line 592 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstFromList(AST_FROM_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node));}
    break;

  case 47:
/* Line 868 of glr.c  */
#line 596 "sql.ypp"
    { ((*yyvalp).ast_node)=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node); }
    break;

  case 48:
/* Line 868 of glr.c  */
#line 597 "sql.ypp"
    { ((*yyvalp).ast_node)=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node); }
    break;

  case 49:
/* Line 868 of glr.c  */
#line 602 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstTable(AST_TABLE, string("NULL"),string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.strval)),string((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.strval)));}
    break;

  case 50:
/* Line 868 of glr.c  */
#line 604 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstTable(AST_TABLE, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval.strval)),string((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.strval)),string((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.strval))); }
    break;

  case 51:
/* Line 868 of glr.c  */
#line 605 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstSubquery(AST_SUBQUERY, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.strval)),(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 52:
/* Line 868 of glr.c  */
#line 606 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node); }
    break;

  case 55:
/* Line 868 of glr.c  */
#line 613 "sql.ypp"
    { ((*yyvalp).strval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.strval); }
    break;

  case 56:
/* Line 868 of glr.c  */
#line 614 "sql.ypp"
    { ((*yyvalp).strval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.strval); }
    break;

  case 57:
/* Line 868 of glr.c  */
#line 615 "sql.ypp"
    { ((*yyvalp).strval) = "NULL"; }
    break;

  case 58:
/* Line 868 of glr.c  */
#line 630 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstJoin(AST_JOIN, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node));}
    break;

  case 59:
/* Line 868 of glr.c  */
#line 631 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstJoin(AST_JOIN, -1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node), NULL);}
    break;

  case 60:
/* Line 868 of glr.c  */
#line 632 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstJoin(AST_JOIN, -1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node));}
    break;

  case 61:
/* Line 868 of glr.c  */
#line 633 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstJoin(AST_JOIN, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (6))].yystate.yysemantics.yysval.intval) + (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (6))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (6))].yystate.yysemantics.yysval.ast_node));}
    break;

  case 62:
/* Line 868 of glr.c  */
#line 634 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstJoin(AST_JOIN, 32 + (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node), NULL);}
    break;

  case 63:
/* Line 868 of glr.c  */
#line 637 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 64:
/* Line 868 of glr.c  */
#line 638 "sql.ypp"
    { ((*yyvalp).intval) = 1; }
    break;

  case 65:
/* Line 868 of glr.c  */
#line 639 "sql.ypp"
    { ((*yyvalp).intval) = 2; }
    break;

  case 66:
/* Line 868 of glr.c  */
#line 642 "sql.ypp"
    { ((*yyvalp).intval) = 4; }
    break;

  case 67:
/* Line 868 of glr.c  */
#line 643 "sql.ypp"
    { ((*yyvalp).intval) = 4; }
    break;

  case 68:
/* Line 868 of glr.c  */
#line 647 "sql.ypp"
    { ((*yyvalp).intval) = 8; }
    break;

  case 69:
/* Line 868 of glr.c  */
#line 648 "sql.ypp"
    { ((*yyvalp).intval) = 16; }
    break;

  case 70:
/* Line 868 of glr.c  */
#line 649 "sql.ypp"
    { ((*yyvalp).intval) = 64; }
    break;

  case 71:
/* Line 868 of glr.c  */
#line 653 "sql.ypp"
    { ((*yyvalp).intval) = 8 + (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.intval); }
    break;

  case 72:
/* Line 868 of glr.c  */
#line 654 "sql.ypp"
    { ((*yyvalp).intval) = 16 + (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.intval);}
    break;

  case 73:
/* Line 868 of glr.c  */
#line 655 "sql.ypp"
    { ((*yyvalp).intval) = 64 + (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.intval);}
    break;

  case 74:
/* Line 868 of glr.c  */
#line 656 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 75:
/* Line 868 of glr.c  */
#line 659 "sql.ypp"
    {((*yyvalp).ast_node) = NULL;}
    break;

  case 76:
/* Line 868 of glr.c  */
#line 660 "sql.ypp"
    {((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node);}
    break;

  case 77:
/* Line 868 of glr.c  */
#line 668 "sql.ypp"
    {((*yyvalp).ast_node) = new AstJoinCondition(AST_JOIN_CONDITION, "ON", (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 78:
/* Line 868 of glr.c  */
#line 669 "sql.ypp"
    {((*yyvalp).ast_node) = new AstJoinCondition(AST_JOIN_CONDITION, "USING", (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 79:
/* Line 868 of glr.c  */
#line 674 "sql.ypp"
    { ((*yyvalp).ast_node)=(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node); }
    break;

  case 80:
/* Line 868 of glr.c  */
#line 681 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstColumn(AST_COLUMN, string("NULL"),string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.strval)));}
    break;

  case 81:
/* Line 868 of glr.c  */
#line 682 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "CONST",string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.strval))); }
    break;

  case 82:
/* Line 868 of glr.c  */
#line 683 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstColumn(AST_COLUMN, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.strval)),string((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.strval))); }
    break;

  case 83:
/* Line 868 of glr.c  */
#line 684 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstColumn(AST_COLUMN_ALL, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.strval)),string("*"));}
    break;

  case 84:
/* Line 868 of glr.c  */
#line 685 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "CONST_STRING",	string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.strval))); }
    break;

  case 85:
/* Line 868 of glr.c  */
#line 686 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "CONST_INT",		string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.strval))); }
    break;

  case 86:
/* Line 868 of glr.c  */
#line 687 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "CONST_DOUBLE",	string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.strval))); }
    break;

  case 87:
/* Line 868 of glr.c  */
#line 688 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "CONST_BOOL",	string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.strval))); }
    break;

  case 88:
/* Line 868 of glr.c  */
#line 690 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_CAL_BINARY, "+",   (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 89:
/* Line 868 of glr.c  */
#line 691 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_CAL_BINARY, "-",   (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 90:
/* Line 868 of glr.c  */
#line 692 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_CAL_BINARY, "*",   (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 91:
/* Line 868 of glr.c  */
#line 693 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_CAL_BINARY, "/",   (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 92:
/* Line 868 of glr.c  */
#line 694 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_CAL_BINARY, "MOD", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 93:
/* Line 868 of glr.c  */
#line 695 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_CAL_BINARY, "%",   (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 94:
/* Line 868 of glr.c  */
#line 697 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "-", (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 95:
/* Line 868 of glr.c  */
#line 698 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "+", (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 96:
/* Line 868 of glr.c  */
#line 700 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_BOOL_BINARY, "AND", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 97:
/* Line 868 of glr.c  */
#line 701 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_BOOL_BINARY, "OR",  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 98:
/* Line 868 of glr.c  */
#line 702 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_BOOL_BINARY, "XOR", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 99:
/* Line 868 of glr.c  */
#line 704 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCmpBinary(AST_EXPR_CMP_BINARY, "", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.subtok), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 100:
/* Line 868 of glr.c  */
#line 705 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCmpBinary(AST_EXPR_CMP_BINARY, "SUBQUERY", (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval.subtok), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 101:
/* Line 868 of glr.c  */
#line 706 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCmpBinary(AST_EXPR_CMP_BINARY, "ANY",		(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (6))].yystate.yysemantics.yysval.subtok), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 102:
/* Line 868 of glr.c  */
#line 707 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCmpBinary(AST_EXPR_CMP_BINARY, "SOME",		(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (6))].yystate.yysemantics.yysval.subtok), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 103:
/* Line 868 of glr.c  */
#line 708 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCmpBinary(AST_EXPR_CMP_BINARY, "ALL",		(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (6))].yystate.yysemantics.yysval.subtok), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 104:
/* Line 868 of glr.c  */
#line 710 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_CAL_BINARY, "|",	(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 105:
/* Line 868 of glr.c  */
#line 711 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_CAL_BINARY, "&",	(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 106:
/* Line 868 of glr.c  */
#line 712 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_CAL_BINARY, "^",	(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 107:
/* Line 868 of glr.c  */
#line 713 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_CAL_BINARY, SHIFT==1?"LSHIFT":"RSHIFT",(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 108:
/* Line 868 of glr.c  */
#line 715 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "!",	(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 109:
/* Line 868 of glr.c  */
#line 716 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "NOT",	(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 110:
/* Line 868 of glr.c  */
#line 717 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 111:
/* Line 868 of glr.c  */
#line 718 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node); }
    break;

  case 112:
/* Line 868 of glr.c  */
#line 721 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "IS_NULL", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 113:
/* Line 868 of glr.c  */
#line 722 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "IS_NOT_NULL", 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 114:
/* Line 868 of glr.c  */
#line 723 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "IS_BOOL", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 115:
/* Line 868 of glr.c  */
#line 724 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "IS_NOT_BOOL", 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 116:
/* Line 868 of glr.c  */
#line 727 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "BETWEEN_AND", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 117:
/* Line 868 of glr.c  */
#line 730 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprList(AST_EXPR_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node), NULL);}
    break;

  case 118:
/* Line 868 of glr.c  */
#line 731 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprList(AST_EXPR_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 119:
/* Line 868 of glr.c  */
#line 732 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node); }
    break;

  case 120:
/* Line 868 of glr.c  */
#line 735 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprList(AST_EXPR_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 121:
/* Line 868 of glr.c  */
#line 736 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprList(AST_EXPR_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 122:
/* Line 868 of glr.c  */
#line 739 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCmpBinary(AST_EXPR_CMP_BINARY, "EXPR_IN_LIST", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 123:
/* Line 868 of glr.c  */
#line 740 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCmpBinary(AST_EXPR_CMP_BINARY, "LIST_IN_LIST",			(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (7))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (7))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 124:
/* Line 868 of glr.c  */
#line 741 "sql.ypp"
    { AstNode* tmp_node= new AstExprCmpBinary(AST_EXPR_CMP_BINARY, "EXPR_IN_LIST", 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node));
   																		((*yyvalp).ast_node)=new AstExprUnary(AST_EXPR_UNARY, "NOT",	tmp_node);  }
    break;

  case 125:
/* Line 868 of glr.c  */
#line 743 "sql.ypp"
    { AstNode* tmp_node= new AstExprCmpBinary(AST_EXPR_CMP_BINARY, "LIST_IN_LIST", 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (8))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (8))].yystate.yysemantics.yysval.ast_node)); 
   																		((*yyvalp).ast_node)=new AstExprUnary(AST_EXPR_UNARY, "NOT",	tmp_node);  }
    break;

  case 126:
/* Line 868 of glr.c  */
#line 745 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCmpBinary(AST_EXPR_CMP_BINARY, "EXPR_IN_SELECT", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 127:
/* Line 868 of glr.c  */
#line 746 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCmpBinary(AST_EXPR_CMP_BINARY, "LIST_IN_SELECT", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (7))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (7))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 128:
/* Line 868 of glr.c  */
#line 747 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCmpBinary(AST_EXPR_CMP_BINARY, "EXPR_NOT_IN_SELECT", 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 129:
/* Line 868 of glr.c  */
#line 748 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCmpBinary(AST_EXPR_CMP_BINARY, "LIST_NOT_IN_SELECT", 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (8))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (8))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 130:
/* Line 868 of glr.c  */
#line 750 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "EXSIST", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 131:
/* Line 868 of glr.c  */
#line 751 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "NOT_EXSIST", 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 132:
/* Line 868 of glr.c  */
#line 761 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "COUNT_ALL", NULL); }
    break;

  case 133:
/* Line 868 of glr.c  */
#line 762 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "COUNT",	 (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 134:
/* Line 868 of glr.c  */
#line 763 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "SUM",	 	 (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 135:
/* Line 868 of glr.c  */
#line 764 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "AVG",	 	 (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 136:
/* Line 868 of glr.c  */
#line 765 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "MIN",	 	 (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 137:
/* Line 868 of glr.c  */
#line 766 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "MAX",	 	 (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 138:
/* Line 868 of glr.c  */
#line 767 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "COUNT",	 (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 139:
/* Line 868 of glr.c  */
#line 768 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "SUM",	 	 (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 140:
/* Line 868 of glr.c  */
#line 769 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "AVG",	 	 (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 141:
/* Line 868 of glr.c  */
#line 770 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "MIN",	 	 (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 142:
/* Line 868 of glr.c  */
#line 771 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "MAX",	 	 (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 143:
/* Line 868 of glr.c  */
#line 774 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "SUBSTRING_EXPR_EXPR", 				(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node), 	NULL); }
    break;

  case 144:
/* Line 868 of glr.c  */
#line 775 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "SUBSTRING_EXPR_FROM_EXPR", 			(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node), 	NULL);}
    break;

  case 145:
/* Line 868 of glr.c  */
#line 776 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "SUBSTRING_EXPR_EXPR_EXPR", 			(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (8))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (8))].yystate.yysemantics.yysval.ast_node), 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (8))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 146:
/* Line 868 of glr.c  */
#line 777 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "SUBSTRING_EXPR_FROM_EXPR_FOR_EXPR", (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (8))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (8))].yystate.yysemantics.yysval.ast_node), 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (8))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 147:
/* Line 868 of glr.c  */
#line 778 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "TRIM_BOTH", 					 NULL,(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node), 	NULL); }
    break;

  case 148:
/* Line 868 of glr.c  */
#line 779 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (7))].yystate.yysemantics.yysval.strval), 									(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (7))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (7))].yystate.yysemantics.yysval.ast_node), 	NULL); }
    break;

  case 149:
/* Line 868 of glr.c  */
#line 780 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "UPPER", 							(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node), NULL,	NULL); }
    break;

  case 150:
/* Line 868 of glr.c  */
#line 781 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "CAST",								(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node),  	NULL); }
    break;

  case 151:
/* Line 868 of glr.c  */
#line 782 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "COALESCE", 							(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node), NULL, 	NULL); }
    break;

  case 152:
/* Line 868 of glr.c  */
#line 785 "sql.ypp"
    { ((*yyvalp).strval)="TRIM_LEADING"; }
    break;

  case 153:
/* Line 868 of glr.c  */
#line 786 "sql.ypp"
    { ((*yyvalp).strval)="TRIM_TRAILING"; }
    break;

  case 154:
/* Line 868 of glr.c  */
#line 787 "sql.ypp"
    { ((*yyvalp).strval)="TRIM_BOTH"; }
    break;

  case 155:
/* Line 868 of glr.c  */
#line 790 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL;}
    break;

  case 156:
/* Line 868 of glr.c  */
#line 791 "sql.ypp"
    {((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "INT", 	NULL);}
    break;

  case 157:
/* Line 868 of glr.c  */
#line 792 "sql.ypp"
    {((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "STRING", NULL);}
    break;

  case 158:
/* Line 868 of glr.c  */
#line 793 "sql.ypp"
    {((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "DOUBLE", NULL);}
    break;

  case 159:
/* Line 868 of glr.c  */
#line 794 "sql.ypp"
    {((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "FLOAT", 	NULL);}
    break;

  case 160:
/* Line 868 of glr.c  */
#line 795 "sql.ypp"
    {((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "CHAR", 	NULL);}
    break;

  case 161:
/* Line 868 of glr.c  */
#line 798 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "DATE_ADD", (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 162:
/* Line 868 of glr.c  */
#line 799 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "DATE_SUB", (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 163:
/* Line 868 of glr.c  */
#line 803 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "INTERVAL_HOUR", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), NULL, NULL);  }
    break;

  case 164:
/* Line 868 of glr.c  */
#line 804 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "INTERVAL_MICROSECOND", 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), NULL, NULL);  }
    break;

  case 165:
/* Line 868 of glr.c  */
#line 805 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "INTERVAL_MINUTE", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), NULL, NULL);  }
    break;

  case 166:
/* Line 868 of glr.c  */
#line 806 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "INTERVAL_SECOND", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), NULL, NULL);  }
    break;

  case 167:
/* Line 868 of glr.c  */
#line 807 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "INTERVAL_DAY", 			(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), NULL, NULL);  }
    break;

  case 168:
/* Line 868 of glr.c  */
#line 808 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "INTERVAL_MONTH", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), NULL, NULL);  }
    break;

  case 169:
/* Line 868 of glr.c  */
#line 809 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "INTERVAL_YEAR", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), NULL, NULL);  }
    break;

  case 170:
/* Line 868 of glr.c  */
#line 810 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "INTERVAL_WEEK", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), NULL, NULL);  }
    break;

  case 171:
/* Line 868 of glr.c  */
#line 811 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "INTERVAL_QUARTER", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), NULL, NULL);  }
    break;

  case 172:
/* Line 868 of glr.c  */
#line 815 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "CASE1", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval.ast_node), 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 173:
/* Line 868 of glr.c  */
#line 816 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "CASE1_ELSE", 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (6))].yystate.yysemantics.yysval.ast_node), 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 174:
/* Line 868 of glr.c  */
#line 817 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "CASE2", 		NULL,	(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 175:
/* Line 868 of glr.c  */
#line 818 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "CASE2_ELSE", 	NULL, 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 176:
/* Line 868 of glr.c  */
#line 821 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "WHEN", (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 177:
/* Line 868 of glr.c  */
#line 822 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "WHEN", (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 178:
/* Line 868 of glr.c  */
#line 825 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_CAL_BINARY, "LIKE", 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 179:
/* Line 868 of glr.c  */
#line 826 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_CAL_BINARY, "NOT_LIKE", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 180:
/* Line 868 of glr.c  */
#line 829 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_CAL_BINARY, "REGEXP", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 181:
/* Line 868 of glr.c  */
#line 830 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_CAL_BINARY, "NOT_REGEXP", 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 182:
/* Line 868 of glr.c  */
#line 836 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node); }
    break;

  case 183:
/* Line 868 of glr.c  */
#line 840 "sql.ypp"
    { string temp = ((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.strval) == NULL)?"":string((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.strval)); ((*yyvalp).ast_node) = new AstCreateDatabase(AST_CREATE_DATABASE, 1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.intval), temp); }
    break;

  case 184:
/* Line 868 of glr.c  */
#line 841 "sql.ypp"
    { string temp = ((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.strval) == NULL)?"":string((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.strval)); ((*yyvalp).ast_node) = new AstCreateDatabase(AST_CREATE_SCHEMA, 2, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.intval), temp); }
    break;

  case 185:
/* Line 868 of glr.c  */
#line 844 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 186:
/* Line 868 of glr.c  */
#line 845 "sql.ypp"
    { ((*yyvalp).intval) = 1; }
    break;

  case 187:
/* Line 868 of glr.c  */
#line 850 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node);}
    break;

  case 188:
/* Line 868 of glr.c  */
#line 854 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateTable(AST_CREATE_TABLE_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (8))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (8))].yystate.yysemantics.yysval.intval), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (8))].yystate.yysemantics.yysval.strval)), "", (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (8))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 189:
/* Line 868 of glr.c  */
#line 858 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateTable(AST_CREATE_TABLE_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (10))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (10))].yystate.yysemantics.yysval.intval), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (10))].yystate.yysemantics.yysval.strval)), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (10))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (10))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 190:
/* Line 868 of glr.c  */
#line 863 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateTable(AST_CREATE_TABLE_LIST_SEL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (9))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (9))].yystate.yysemantics.yysval.intval), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (9))].yystate.yysemantics.yysval.strval)), "", (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (9))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (9))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 191:
/* Line 868 of glr.c  */
#line 867 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateTable(AST_CREATE_TABLE_SEL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (6))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (6))].yystate.yysemantics.yysval.intval), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.strval)), "", NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (6))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 192:
/* Line 868 of glr.c  */
#line 872 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateTable(AST_CREATE_TABLE_LIST_SEL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (11))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (11))].yystate.yysemantics.yysval.intval), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (11))].yystate.yysemantics.yysval.strval)), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (11))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (11))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((11) - (11))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 193:
/* Line 868 of glr.c  */
#line 876 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateTable(AST_CREATE_TABLE_SEL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (8))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (8))].yystate.yysemantics.yysval.intval), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (8))].yystate.yysemantics.yysval.strval)), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (8))].yystate.yysemantics.yysval.strval)), NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((8) - (8))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 194:
/* Line 868 of glr.c  */
#line 880 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateSelect(AST_CREATE_SEL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.intval), 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 195:
/* Line 868 of glr.c  */
#line 883 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 196:
/* Line 868 of glr.c  */
#line 884 "sql.ypp"
    { ((*yyvalp).intval) = 1; }
    break;

  case 197:
/* Line 868 of glr.c  */
#line 885 "sql.ypp"
    { ((*yyvalp).intval) = 2; }
    break;

  case 198:
/* Line 868 of glr.c  */
#line 888 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 199:
/* Line 868 of glr.c  */
#line 889 "sql.ypp"
    { ((*yyvalp).intval) = 1; }
    break;

  case 200:
/* Line 868 of glr.c  */
#line 892 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateColList(AST_CREATE_COL_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 201:
/* Line 868 of glr.c  */
#line 893 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateColList(AST_CREATE_COL_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 202:
/* Line 868 of glr.c  */
#line 898 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateDef( AST_CREATE_DEF_NAME, 1, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 203:
/* Line 868 of glr.c  */
#line 899 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateDef( AST_CREATE_DEF_PR_KEY, 2, "", NULL, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node));  }
    break;

  case 204:
/* Line 868 of glr.c  */
#line 900 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateDef( AST_CREATE_DEF_KEY, 3, "", NULL, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 205:
/* Line 868 of glr.c  */
#line 901 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateDef( AST_CREATE_DEF_INDEX, 4, "", NULL, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 206:
/* Line 868 of glr.c  */
#line 902 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateDef( AST_CREATE_DEF_FTEXT_INDEX, 5, "", NULL, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 207:
/* Line 868 of glr.c  */
#line 903 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateDef( AST_CREATE_DEF_FTEXT_KEY, 6, "", NULL, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 208:
/* Line 868 of glr.c  */
#line 905 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstColumnAtts(AST_COLUMN_ATTS, 0, 0, 0, "", NULL); }
    break;

  case 209:
/* Line 868 of glr.c  */
#line 906 "sql.ypp"
    { AstColumnAtts* temp = static_cast<AstColumnAtts*>((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node));temp->datatype_ |= 01; ((*yyvalp).ast_node) = temp; }
    break;

  case 210:
/* Line 868 of glr.c  */
#line 907 "sql.ypp"
    { AstColumnAtts* temp = static_cast<AstColumnAtts*>((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.ast_node));temp->datatype_ |= 02; ((*yyvalp).ast_node) = temp; }
    break;

  case 211:
/* Line 868 of glr.c  */
#line 908 "sql.ypp"
    { AstColumnAtts* temp = static_cast<AstColumnAtts*>((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node));temp->datatype_ |= 04; temp->default_string_ = ((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.strval)==NULL)?"":string((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.strval)); ((*yyvalp).ast_node) = temp; }
    break;

  case 212:
/* Line 868 of glr.c  */
#line 909 "sql.ypp"
    { AstColumnAtts* temp = static_cast<AstColumnAtts*>((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node));temp->datatype_ |= 010;temp->int_num_ = atoi((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.strval)); ((*yyvalp).ast_node) = temp; }
    break;

  case 213:
/* Line 868 of glr.c  */
#line 910 "sql.ypp"
    { AstColumnAtts* temp = static_cast<AstColumnAtts*>((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node));temp->datatype_ |= 020; temp->double_num_ = atof((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.strval)); ((*yyvalp).ast_node) = temp; }
    break;

  case 214:
/* Line 868 of glr.c  */
#line 911 "sql.ypp"
    { AstColumnAtts* temp = static_cast<AstColumnAtts*>((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node));temp->datatype_ |= 040; temp->int_num_ = atoi((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.strval)); ((*yyvalp).ast_node) = temp; }
    break;

  case 215:
/* Line 868 of glr.c  */
#line 912 "sql.ypp"
    { AstColumnAtts* temp = static_cast<AstColumnAtts*>((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.ast_node));temp->datatype_ |= 0100; ((*yyvalp).ast_node) = temp; }
    break;

  case 216:
/* Line 868 of glr.c  */
#line 913 "sql.ypp"
    { AstColumnAtts* temp = static_cast<AstColumnAtts*>((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node));temp->datatype_ |= 0200; ((*yyvalp).ast_node) = temp; }
    break;

  case 217:
/* Line 868 of glr.c  */
#line 914 "sql.ypp"
    { AstColumnAtts* temp = static_cast<AstColumnAtts*>((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node));temp->datatype_ |= 0400; ((*yyvalp).ast_node) = temp; }
    break;

  case 218:
/* Line 868 of glr.c  */
#line 915 "sql.ypp"
    { AstColumnAtts* temp = static_cast<AstColumnAtts*>((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.ast_node));temp->datatype_ |= 01000; ((*yyvalp).ast_node) = temp; }
    break;

  case 219:
/* Line 868 of glr.c  */
#line 916 "sql.ypp"
    { AstColumnAtts* temp = static_cast<AstColumnAtts*>((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node));temp->datatype_ |= 02000; ((*yyvalp).ast_node) = temp; }
    break;

  case 220:
/* Line 868 of glr.c  */
#line 917 "sql.ypp"
    { AstColumnAtts* temp = static_cast<AstColumnAtts*>((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node));temp->datatype_ |= 04000; temp->col_list_ = (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node); ((*yyvalp).ast_node) = temp;}
    break;

  case 221:
/* Line 868 of glr.c  */
#line 921 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node), 0, NULL, 0, NULL); }
    break;

  case 222:
/* Line 868 of glr.c  */
#line 922 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 2, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL, 0, NULL); }
    break;

  case 223:
/* Line 868 of glr.c  */
#line 923 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 3, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL, 0, NULL); }
    break;

  case 224:
/* Line 868 of glr.c  */
#line 924 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 4, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL, 0, NULL); }
    break;

  case 225:
/* Line 868 of glr.c  */
#line 925 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 5, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL, 0, NULL); }
    break;

  case 226:
/* Line 868 of glr.c  */
#line 926 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 6, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL, 0, NULL); }
    break;

  case 227:
/* Line 868 of glr.c  */
#line 927 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 7, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL, 0, NULL); }
    break;

  case 228:
/* Line 868 of glr.c  */
#line 928 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 8, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL, 0, NULL); }
    break;

  case 229:
/* Line 868 of glr.c  */
#line 929 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 9, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL, 0, NULL); }
    break;

  case 230:
/* Line 868 of glr.c  */
#line 930 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 10, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL, 0, NULL); }
    break;

  case 231:
/* Line 868 of glr.c  */
#line 931 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 11, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL, 0, NULL); }
    break;

  case 232:
/* Line 868 of glr.c  */
#line 932 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 12, NULL, 0, NULL, 0, NULL); }
    break;

  case 233:
/* Line 868 of glr.c  */
#line 933 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 13, NULL, 0, NULL, 0, NULL); }
    break;

  case 234:
/* Line 868 of glr.c  */
#line 934 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 14, NULL, 0, NULL, 0, NULL); }
    break;

  case 235:
/* Line 868 of glr.c  */
#line 935 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 15, NULL, 0, NULL, 0, NULL); }
    break;

  case 236:
/* Line 868 of glr.c  */
#line 936 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 16, NULL, 0, NULL, 0, NULL); }
    break;

  case 237:
/* Line 868 of glr.c  */
#line 937 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 17, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node), 0, NULL); }
    break;

  case 238:
/* Line 868 of glr.c  */
#line 938 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 18, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node), 0, NULL); }
    break;

  case 239:
/* Line 868 of glr.c  */
#line 939 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 19, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node), 0, NULL, 0, NULL); }
    break;

  case 240:
/* Line 868 of glr.c  */
#line 940 "sql.ypp"
    { AstNode* temp = new AstOptLength(AST_OPT_LENGTH,atoi((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.strval)),NULL); 
                                              ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 20, temp, 0, NULL, 0, NULL); }
    break;

  case 241:
/* Line 868 of glr.c  */
#line 942 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 21, NULL, 0, NULL, 0, NULL); }
    break;

  case 242:
/* Line 868 of glr.c  */
#line 943 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 22, NULL, 0, NULL, 0, NULL); }
    break;

  case 243:
/* Line 868 of glr.c  */
#line 944 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 23, NULL, 0, NULL, 0, NULL); }
    break;

  case 244:
/* Line 868 of glr.c  */
#line 945 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 24, NULL, 0, NULL, 0, NULL); }
    break;

  case 245:
/* Line 868 of glr.c  */
#line 946 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 25, NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.intval), NULL); }
    break;

  case 246:
/* Line 868 of glr.c  */
#line 947 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 26, NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.intval), NULL); }
    break;

  case 247:
/* Line 868 of glr.c  */
#line 948 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 27, NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.intval), NULL); }
    break;

  case 248:
/* Line 868 of glr.c  */
#line 949 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 28, NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.intval), NULL); }
    break;

  case 249:
/* Line 868 of glr.c  */
#line 950 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 29, NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node), 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 250:
/* Line 868 of glr.c  */
#line 951 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 30, NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node), 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 251:
/* Line 868 of glr.c  */
#line 953 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstEnumList( AST_ENUM, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.strval)), NULL); }
    break;

  case 252:
/* Line 868 of glr.c  */
#line 954 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstEnumList( AST_ENUM_LIST, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 253:
/* Line 868 of glr.c  */
#line 957 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 254:
/* Line 868 of glr.c  */
#line 958 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstOptLength (AST_OPT_LENGTH, atoi((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.strval)), 0); }
    break;

  case 255:
/* Line 868 of glr.c  */
#line 959 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstOptLength (AST_OPT_LENGTH, atoi((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval.strval)), atoi((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.strval))); }
    break;

  case 256:
/* Line 868 of glr.c  */
#line 962 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 257:
/* Line 868 of glr.c  */
#line 963 "sql.ypp"
    { ((*yyvalp).intval) = 1; }
    break;

  case 258:
/* Line 868 of glr.c  */
#line 966 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 259:
/* Line 868 of glr.c  */
#line 967 "sql.ypp"
    { ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.intval) | 01; }
    break;

  case 260:
/* Line 868 of glr.c  */
#line 968 "sql.ypp"
    { ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.intval) | 02; }
    break;

  case 261:
/* Line 868 of glr.c  */
#line 971 "sql.ypp"
    { ((*yyvalp).ast_node) =new AstOptCsc(AST_OPT_CSC, 0, "", "");}
    break;

  case 262:
/* Line 868 of glr.c  */
#line 973 "sql.ypp"
    { AstOptCsc* temp=static_cast<AstOptCsc*>((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval.ast_node));temp->data_type_ |= 01; temp->str1_ = string((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.strval)); ((*yyvalp).ast_node) = temp; }
    break;

  case 263:
/* Line 868 of glr.c  */
#line 975 "sql.ypp"
    { AstOptCsc* temp=static_cast<AstOptCsc*>((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node));temp->data_type_ |= 02; temp->str2_ = string((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.strval)); ((*yyvalp).ast_node) = temp; }
    break;

  case 264:
/* Line 868 of glr.c  */
#line 979 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node);/* puts("SQL parser： This is a create_projection statement");*/ }
    break;

  case 265:
/* Line 868 of glr.c  */
#line 983 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateProjection(AST_CREATE_PROJECTION, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (10))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (10))].yystate.yysemantics.yysval.ast_node), 1, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((10) - (10))].yystate.yysemantics.yysval.strval))); }
    break;

  case 266:
/* Line 868 of glr.c  */
#line 985 "sql.ypp"
    { 
		if ((((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (13))].yystate.yysemantics.yysval.subtok) != 4) { yyerror(result,"please give a specific number"); } 
		else                                { ((*yyvalp).ast_node) = new AstCreateProjection(AST_CREATE_PROJECTION_NUM, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (13))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (13))].yystate.yysemantics.yysval.ast_node), atoi((((yyGLRStackItem const *)yyvsp)[YYFILL ((10) - (13))].yystate.yysemantics.yysval.strval)), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((13) - (13))].yystate.yysemantics.yysval.strval))); }
	}
    break;

  case 267:
/* Line 868 of glr.c  */
#line 992 "sql.ypp"
    { ((*yyvalp).ast_node)=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node);}
    break;

  case 268:
/* Line 868 of glr.c  */
#line 997 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateIndex(AST_CREATE_INDEX, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (10))].yystate.yysemantics.yysval.intval), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (10))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (10))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (10))].yystate.yysemantics.yysval.strval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (10))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 269:
/* Line 868 of glr.c  */
#line 1000 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 270:
/* Line 868 of glr.c  */
#line 1001 "sql.ypp"
    { ((*yyvalp).intval) = 1; }
    break;

  case 271:
/* Line 868 of glr.c  */
#line 1002 "sql.ypp"
    { ((*yyvalp).intval) = 2; }
    break;

  case 272:
/* Line 868 of glr.c  */
#line 1003 "sql.ypp"
    { ((*yyvalp).intval) = 3; }
    break;

  case 273:
/* Line 868 of glr.c  */
#line 1006 "sql.ypp"
    { ((*yyvalp).intval) = 0;  }
    break;

  case 274:
/* Line 868 of glr.c  */
#line 1007 "sql.ypp"
    { ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.intval); }
    break;

  case 275:
/* Line 868 of glr.c  */
#line 1010 "sql.ypp"
    { ((*yyvalp).intval) = 1; }
    break;

  case 276:
/* Line 868 of glr.c  */
#line 1011 "sql.ypp"
    { ((*yyvalp).intval) = 2; }
    break;

  case 277:
/* Line 868 of glr.c  */
#line 1014 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstIndexColList(AST_INDEX_COL, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL); }
    break;

  case 278:
/* Line 868 of glr.c  */
#line 1015 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstIndexColList(AST_INDEX_COL_LIST, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 279:
/* Line 868 of glr.c  */
#line 1019 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node);}
    break;

  case 280:
/* Line 868 of glr.c  */
#line 1023 "sql.ypp"
    {
		  if ((((yyGLRStackItem const *)yyvsp)[YYFILL ((11) - (12))].yystate.yysemantics.yysval.subtok) != 4) { yyerror(result,"please give a specific number"); } 
		  else {((*yyvalp).ast_node) = new AstLoadTable(AST_LOAD_TABLE, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (12))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (12))].yystate.yysemantics.yysval.ast_node), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (12))].yystate.yysemantics.yysval.strval)), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (12))].yystate.yysemantics.yysval.strval)), atof((((yyGLRStackItem const *)yyvsp)[YYFILL ((12) - (12))].yystate.yysemantics.yysval.strval)), 1);}
		}
    break;

  case 281:
/* Line 868 of glr.c  */
#line 1027 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstLoadTable(AST_LOAD_TABLE, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (9))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (9))].yystate.yysemantics.yysval.ast_node), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (9))].yystate.yysemantics.yysval.strval)), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (9))].yystate.yysemantics.yysval.strval)), 1.0, 1);}
    break;

  case 282:
/* Line 868 of glr.c  */
#line 1028 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstLoadTable(AST_LOAD_TABLE, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (9))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (9))].yystate.yysemantics.yysval.ast_node), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (9))].yystate.yysemantics.yysval.strval)), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (9))].yystate.yysemantics.yysval.strval)), 1.0, 2);}
    break;

  case 283:
/* Line 868 of glr.c  */
#line 1030 "sql.ypp"
    { if ((((yyGLRStackItem const *)yyvsp)[YYFILL ((11) - (12))].yystate.yysemantics.yysval.subtok) != 4) { yyerror(result,"please give a specific number"); } 
		 else {((*yyvalp).ast_node) = new AstLoadTable(AST_LOAD_TABLE, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (12))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (12))].yystate.yysemantics.yysval.ast_node), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (12))].yystate.yysemantics.yysval.strval)), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (12))].yystate.yysemantics.yysval.strval)), atof((((yyGLRStackItem const *)yyvsp)[YYFILL ((12) - (12))].yystate.yysemantics.yysval.strval)), 2);}
		}
    break;

  case 284:
/* Line 868 of glr.c  */
#line 1036 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node); /*output($$, 1); puts("SQL parser： This is a drop_index statement");*/ }
    break;

  case 285:
/* Line 868 of glr.c  */
#line 1039 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDropIndex(AST_DROP_INDEX, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.strval)), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.strval))); }
    break;

  case 286:
/* Line 868 of glr.c  */
#line 1043 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node);/* output($$, 1); puts("SQL parser： This is a drop_database statement");*/ }
    break;

  case 287:
/* Line 868 of glr.c  */
#line 1047 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDropDatabase(AST_DROP_DB, 1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.intval), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.strval))); }
    break;

  case 288:
/* Line 868 of glr.c  */
#line 1048 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDropDatabase(AST_DROP_SCHEMA, 2, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.intval), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.strval))); }
    break;

  case 289:
/* Line 868 of glr.c  */
#line 1051 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 290:
/* Line 868 of glr.c  */
#line 1052 "sql.ypp"
    { ((*yyvalp).intval) = 1; }
    break;

  case 291:
/* Line 868 of glr.c  */
#line 1056 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node); /*output($$, 1); puts("SQL parser： This is a drop_table statement"); */}
    break;

  case 292:
/* Line 868 of glr.c  */
#line 1060 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDropTable(AST_DROP_TABLE, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (6))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (6))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (6))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 293:
/* Line 868 of glr.c  */
#line 1063 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDropTableList(AST_DROP_TABLE_LIST, "", string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.strval)), NULL); }
    break;

  case 294:
/* Line 868 of glr.c  */
#line 1064 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDropTableList(AST_DROP_TABLE_LIST, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.strval)), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.strval)), NULL); }
    break;

  case 295:
/* Line 868 of glr.c  */
#line 1065 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDropTableList(AST_DROP_TABLE_LIST, "", string((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 296:
/* Line 868 of glr.c  */
#line 1066 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDropTableList(AST_DROP_TABLE_LIST, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.strval)), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 297:
/* Line 868 of glr.c  */
#line 1069 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 298:
/* Line 868 of glr.c  */
#line 1070 "sql.ypp"
    { ((*yyvalp).intval) = 1; }
    break;

  case 299:
/* Line 868 of glr.c  */
#line 1071 "sql.ypp"
    { ((*yyvalp).intval) = 2; }
    break;

  case 300:
/* Line 868 of glr.c  */
#line 1077 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node);}
    break;

  case 301:
/* Line 868 of glr.c  */
#line 1083 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstInsertStmt(AST_INSERT_STMT, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (8))].yystate.yysemantics.yysval.intval), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (8))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (8))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (8))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((8) - (8))].yystate.yysemantics.yysval.ast_node), NULL, NULL); }
    break;

  case 302:
/* Line 868 of glr.c  */
#line 1086 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 303:
/* Line 868 of glr.c  */
#line 1087 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node); }
    break;

  case 304:
/* Line 868 of glr.c  */
#line 1090 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 305:
/* Line 868 of glr.c  */
#line 1091 "sql.ypp"
    { ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.intval) | 01 ; }
    break;

  case 306:
/* Line 868 of glr.c  */
#line 1092 "sql.ypp"
    { ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.intval) | 02 ; }
    break;

  case 307:
/* Line 868 of glr.c  */
#line 1093 "sql.ypp"
    { ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.intval) | 04 ; }
    break;

  case 308:
/* Line 868 of glr.c  */
#line 1094 "sql.ypp"
    { ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.intval) | 010 ; }
    break;

  case 311:
/* Line 868 of glr.c  */
#line 1100 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 312:
/* Line 868 of glr.c  */
#line 1101 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node); }
    break;

  case 313:
/* Line 868 of glr.c  */
#line 1104 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstInsertValList(AST_INSERT_VALUE_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 314:
/* Line 868 of glr.c  */
#line 1105 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstInsertValList(AST_INSERT_VALUE_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 315:
/* Line 868 of glr.c  */
#line 1109 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstInsertVals(AST_INSERT_VALUE,0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 316:
/* Line 868 of glr.c  */
#line 1110 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstInsertVals(AST_INSERT_VALUE,1, NULL, NULL); }
    break;

  case 317:
/* Line 868 of glr.c  */
#line 1111 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstInsertVals(AST_INSERT_VALUE,0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 318:
/* Line 868 of glr.c  */
#line 1112 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstInsertVals(AST_INSERT_VALUE,1, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 319:
/* Line 868 of glr.c  */
#line 1116 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstInsertStmt(AST_INSERT_STMT, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (7))].yystate.yysemantics.yysval.intval), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (7))].yystate.yysemantics.yysval.strval)), NULL, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (7))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (7))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 320:
/* Line 868 of glr.c  */
#line 1120 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstInsertStmt(AST_INSERT_STMT, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (7))].yystate.yysemantics.yysval.intval), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (7))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (7))].yystate.yysemantics.yysval.ast_node), NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (7))].yystate.yysemantics.yysval.ast_node), NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (7))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 321:
/* Line 868 of glr.c  */
#line 1124 "sql.ypp"
    { 
		if((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.subtok) != 4) yyerror(result,"bad insert assignment to %s", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.strval)); 
		else ((*yyvalp).ast_node) = new AstInsertAssignList(AST_INSERT_ASSIGN_LIST, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.strval)), 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 322:
/* Line 868 of glr.c  */
#line 1127 "sql.ypp"
    { 
		if ((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.subtok) != 4) yyerror(result,"bad insert assignment to %s", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.strval));
 		else ((*yyvalp).ast_node) = new AstInsertAssignList(AST_INSERT_ASSIGN_LIST, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.strval)), 1, NULL, NULL); }
    break;

  case 323:
/* Line 868 of glr.c  */
#line 1130 "sql.ypp"
    { 
		if ((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.subtok) != 4) yyerror(result,"bad insert assignment to %s", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node));		 
		else ((*yyvalp).ast_node) = new AstInsertAssignList(AST_INSERT_ASSIGN_LIST, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.strval)), 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 324:
/* Line 868 of glr.c  */
#line 1133 "sql.ypp"
    { 
		if ((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.subtok) != 4) yyerror(result,"bad insert assignment to %s", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node));
		else ((*yyvalp).ast_node) = new AstInsertAssignList(AST_INSERT_ASSIGN_LIST, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.strval)), 1, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 325:
/* Line 868 of glr.c  */
#line 1138 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node); /*output($$, 1); puts("SQL parser： This is a show statement");*/ }
    break;

  case 326:
/* Line 868 of glr.c  */
#line 1141 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstShowStmt(AST_SHOW_STMT,1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval.intval), ((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.intval)==NULL)?"":string((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.intval)), ((((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.strval)==NULL)?"":string((((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.strval))); }
    break;

  case 327:
/* Line 868 of glr.c  */
#line 1142 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 328:
/* Line 868 of glr.c  */
#line 1143 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 329:
/* Line 868 of glr.c  */
#line 1144 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 330:
/* Line 868 of glr.c  */
#line 1145 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 331:
/* Line 868 of glr.c  */
#line 1146 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 332:
/* Line 868 of glr.c  */
#line 1147 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 333:
/* Line 868 of glr.c  */
#line 1148 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 334:
/* Line 868 of glr.c  */
#line 1149 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 335:
/* Line 868 of glr.c  */
#line 1150 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 336:
/* Line 868 of glr.c  */
#line 1151 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 337:
/* Line 868 of glr.c  */
#line 1152 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 338:
/* Line 868 of glr.c  */
#line 1153 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 339:
/* Line 868 of glr.c  */
#line 1154 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 340:
/* Line 868 of glr.c  */
#line 1155 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 341:
/* Line 868 of glr.c  */
#line 1156 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 342:
/* Line 868 of glr.c  */
#line 1157 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 343:
/* Line 868 of glr.c  */
#line 1158 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 344:
/* Line 868 of glr.c  */
#line 1159 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 345:
/* Line 868 of glr.c  */
#line 1160 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 346:
/* Line 868 of glr.c  */
#line 1161 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 347:
/* Line 868 of glr.c  */
#line 1162 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 348:
/* Line 868 of glr.c  */
#line 1163 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 349:
/* Line 868 of glr.c  */
#line 1164 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 350:
/* Line 868 of glr.c  */
#line 1165 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 351:
/* Line 868 of glr.c  */
#line 1166 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 352:
/* Line 868 of glr.c  */
#line 1167 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 353:
/* Line 868 of glr.c  */
#line 1169 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 354:
/* Line 868 of glr.c  */
#line 1173 "sql.ypp"
    { ((*yyvalp).intval) = NULL; }
    break;

  case 355:
/* Line 868 of glr.c  */
#line 1174 "sql.ypp"
    { ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.strval); }
    break;

  case 356:
/* Line 868 of glr.c  */
#line 1177 "sql.ypp"
    { ((*yyvalp).strval) = NULL; }
    break;

  case 357:
/* Line 868 of glr.c  */
#line 1178 "sql.ypp"
    { ((*yyvalp).strval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.strval); }
    break;

  case 362:
/* Line 868 of glr.c  */
#line 1188 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 363:
/* Line 868 of glr.c  */
#line 1189 "sql.ypp"
    { ((*yyvalp).intval) = 1; }
    break;

  case 364:
/* Line 868 of glr.c  */
#line 1190 "sql.ypp"
    { ((*yyvalp).intval) = 2; }
    break;

  case 365:
/* Line 868 of glr.c  */
#line 1193 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDescStmt(AST_DESC_STMT, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.strval)); }
    break;

  case 366:
/* Line 868 of glr.c  */
#line 1196 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node); }
    break;

  case 367:
/* Line 868 of glr.c  */
#line 1200 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDeleteStmt(AST_DELETE_STMT,(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (7))].yystate.yysemantics.yysval.ast_node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (7))].yystate.yysemantics.yysval.ast_node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (7))].yystate.yysemantics.yysval.ast_node) );}
    break;

  case 368:
/* Line 868 of glr.c  */
#line 1204 "sql.ypp"
    { emit("DELETEMULTI %d %d %d", (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (7))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (7))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (7))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 369:
/* Line 868 of glr.c  */
#line 1209 "sql.ypp"
    {}
    break;

  case 370:
/* Line 868 of glr.c  */
#line 1212 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.ast_node) + 01; }
    break;

  case 371:
/* Line 868 of glr.c  */
#line 1213 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.ast_node) + 02; }
    break;

  case 372:
/* Line 868 of glr.c  */
#line 1214 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.ast_node) + 04; }
    break;

  case 373:
/* Line 868 of glr.c  */
#line 1215 "sql.ypp"
    { ((*yyvalp).ast_node) = 0; }
    break;

  case 374:
/* Line 868 of glr.c  */
#line 1219 "sql.ypp"
    {  }
    break;

  case 375:
/* Line 868 of glr.c  */
#line 1220 "sql.ypp"
    {  }
    break;

  case 378:
/* Line 868 of glr.c  */
#line 1227 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node); }
    break;

  case 379:
/* Line 868 of glr.c  */
#line 1230 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstUpdateStmt(AST_UPDATE_STMT, (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 380:
/* Line 868 of glr.c  */
#line 1233 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstUpdateSetList(AST_UPDATE_SET_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 381:
/* Line 868 of glr.c  */
#line 1234 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstUpdateSetList(AST_UPDATE_SET_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;


/* Line 868 of glr.c  */
#line 4687 "sql.tab.cpp"
      default: break;
    }

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


/*ARGSUSED*/ static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YYUSE (yy0);
  YYUSE (yy1);

  switch (yyn)
    {
      
      default: break;
    }
}

                              /* Bison grammar-table manipulation.  */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, struct ParseResult* result)
{
  YYUSE (yyvaluep);
  YYUSE (result);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys, struct ParseResult* result)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yystos[yys->yylrState],
                &yys->yysemantics.yysval, result);
  else
    {
#if YYDEBUG
      if (yydebug)
        {
          if (yys->yysemantics.yyfirstVal)
            YYFPRINTF (stderr, "%s unresolved ", yymsg);
          else
            YYFPRINTF (stderr, "%s incomplete ", yymsg);
          yy_symbol_print (stderr, yystos[yys->yylrState],
                           YY_NULL, result);
          YYFPRINTF (stderr, "\n");
        }
#endif

      if (yys->yysemantics.yyfirstVal)
        {
          yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
          yyGLRState *yyrh;
          int yyn;
          for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
               yyn > 0;
               yyrh = yyrh->yypred, yyn -= 1)
            yydestroyGLRState (yymsg, yyrh, result);
        }
    }
}

/** Left-hand-side symbol for rule #RULE.  */
static inline yySymbol
yylhsNonterm (yyRuleNum yyrule)
{
  return yyr1[yyrule];
}

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-485)))

/** True iff LR state STATE has only a default reduction (regardless
 *  of token).  */
static inline yybool
yyisDefaultedState (yyStateNum yystate)
{
  return yypact_value_is_default (yypact[yystate]);
}

/** The default reduction for STATE, assuming it has one.  */
static inline yyRuleNum
yydefaultAction (yyStateNum yystate)
{
  return yydefact[yystate];
}

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-382)))

/** Set *YYACTION to the action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *CONFLICTS to a pointer into yyconfl to 0-terminated list of
 *  conflicting reductions.
 */
static inline void
yygetLRActions (yyStateNum yystate, int yytoken,
                int* yyaction, const short int** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yypact_value_is_default (yypact[yystate])
      || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyaction = -yydefact[yystate];
      *yyconflicts = yyconfl;
    }
  else if (! yytable_value_is_error (yytable[yyindex]))
    {
      *yyaction = yytable[yyindex];
      *yyconflicts = yyconfl + yyconflp[yyindex];
    }
  else
    {
      *yyaction = 0;
      *yyconflicts = yyconfl + yyconflp[yyindex];
    }
}

static inline yyStateNum
yyLRgotoState (yyStateNum yystate, yySymbol yylhs)
{
  int yyr;
  yyr = yypgoto[yylhs - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yylhs - YYNTOKENS];
}

static inline yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static inline yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

                                /* GLRStates */

/** Return a fresh GLRStackItem.  Callers should call
 * YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 * headroom.  */

static inline yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  RULENUM on the semantic values in RHS to the list of
 *  alternative actions for STATE.  Assumes that RHS comes from
 *  stack #K of *STACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, size_t yyk, yyGLRState* yystate,
                     yyGLRState* rhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  yynewOption->yystate = rhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
    }
  else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

                                /* GLRStacks */

/** Initialize SET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates = (yyGLRState**) YYMALLOC (16 * sizeof yyset->yystates[0]);
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = YY_NULL;
  yyset->yylookaheadNeeds =
    (yybool*) YYMALLOC (16 * sizeof yyset->yylookaheadNeeds[0]);
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize STACK to a single empty stack, with total maximum
 *  capacity for all stacks of SIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, size_t yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems =
    (yyGLRStackItem*) YYMALLOC (yysize * sizeof yystackp->yynextFree[0]);
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULL;
  yystackp->yylastDeleted = YY_NULL;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS,YYTOITEMS,YYX,YYTYPE) \
  &((YYTOITEMS) - ((YYFROMITEMS) - (yyGLRStackItem*) (YYX)))->YYTYPE

/** If STACK is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  size_t yynewSize;
  size_t yyn;
  size_t yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems = (yyGLRStackItem*) YYMALLOC (yynewSize * sizeof yynewItems[0]);
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*(yybool *) yyp0)
        {
          yyGLRState* yys0 = &yyp0->yystate;
          yyGLRState* yys1 = &yyp1->yystate;
          if (yys0->yypred != YY_NULL)
            yys1->yypred =
              YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
          if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULL)
            yys1->yysemantics.yyfirstVal =
              YYRELOC (yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
        }
      else
        {
          yySemanticOption* yyv0 = &yyp0->yyoption;
          yySemanticOption* yyv1 = &yyp1->yyoption;
          if (yyv0->yystate != YY_NULL)
            yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
          if (yyv0->yynext != YY_NULL)
            yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
        }
    }
  if (yystackp->yysplitPoint != YY_NULL)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
                                 yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != YY_NULL)
      yystackp->yytops.yystates[yyn] =
        YYRELOC (yystackp->yyitems, yynewItems,
                 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that S is a GLRState somewhere on STACK, update the
 *  splitpoint of STACK, if needed, so that it is at least as deep as
 *  S.  */
static inline void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != YY_NULL && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #K in STACK.  */
static inline void
yymarkStackDeleted (yyGLRStack* yystackp, size_t yyk)
{
  if (yystackp->yytops.yystates[yyk] != YY_NULL)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = YY_NULL;
}

/** Undelete the last stack that was marked as deleted.  Can only be
    done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == YY_NULL || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YYDPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = YY_NULL;
}

static inline void
yyremoveDeletes (yyGLRStack* yystackp)
{
  size_t yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == YY_NULL)
        {
          if (yyi == yyj)
            {
              YYDPRINTF ((stderr, "Removing dead stacks.\n"));
            }
          yystackp->yytops.yysize -= 1;
        }
      else
        {
          yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
          /* In the current implementation, it's unnecessary to copy
             yystackp->yytops.yylookaheadNeeds[yyi] since, after
             yyremoveDeletes returns, the parser immediately either enters
             deterministic operation or shifts a token.  However, it doesn't
             hurt, and the code might evolve to need it.  */
          yystackp->yytops.yylookaheadNeeds[yyj] =
            yystackp->yytops.yylookaheadNeeds[yyi];
          if (yyj != yyi)
            {
              YYDPRINTF ((stderr, "Rename stack %lu -> %lu.\n",
                          (unsigned long int) yyi, (unsigned long int) yyj));
            }
          yyj += 1;
        }
      yyi += 1;
    }
}

/** Shift to a new state on stack #K of STACK, corresponding to LR state
 * LRSTATE, at input position POSN, with (resolved) semantic value SVAL.  */
static inline void
yyglrShift (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
            size_t yyposn,
            YYSTYPE* yyvalp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yysval = *yyvalp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #K of YYSTACK, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void
yyglrShiftDefer (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
                 size_t yyposn, yyGLRState* rhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = YY_NULL;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, rhs, yyrule);
}

/** Pop the symbols consumed by reduction #RULE from the top of stack
 *  #K of STACK, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *VALP to the resulting value,
 *  and *LOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
            YYSTYPE* yyvalp, struct ParseResult* result)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == YY_NULL)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* rhs = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
      YYASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      return yyuserAction (yyrule, yynrhs, rhs, yystackp,
                           yyvalp, result);
    }
  else
    {
      /* At present, doAction is never called in nondeterministic
       * mode, so this branch is never taken.  It is here in
       * anticipation of a future feature that will allow immediate
       * evaluation of selected actions in nondeterministic mode.  */
      int yyi;
      yyGLRState* yys;
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
        = yystackp->yytops.yystates[yyk];
      for (yyi = 0; yyi < yynrhs; yyi += 1)
        {
          yys = yys->yypred;
          YYASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyvalp, result);
    }
}

#if !YYDEBUG
# define YY_REDUCE_PRINT(Args)
#else
# define YY_REDUCE_PRINT(Args)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print Args;               \
} while (YYID (0))

/*----------------------------------------------------------.
| Report that the RULE is going to be reduced on stack #K.  |
`----------------------------------------------------------*/

/*ARGSUSED*/ static inline void
yy_reduce_print (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
                 YYSTYPE* yyvalp, struct ParseResult* result)
{
  int yynrhs = yyrhsLength (yyrule);
  yybool yynormal __attribute__ ((__unused__)) =
    (yystackp->yysplitPoint == YY_NULL);
  yyGLRStackItem* yyvsp = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
  int yylow = 1;
  int yyi;
  YYUSE (yyvalp);
  YYUSE (result);
  YYFPRINTF (stderr, "Reducing stack %lu by rule %d (line %lu):\n",
             (unsigned long int) yyk, yyrule - 1,
             (unsigned long int) yyrline[yyrule]);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
                       &(((yyGLRStackItem const *)yyvsp)[YYFILL ((yyi + 1) - (yynrhs))].yystate.yysemantics.yysval)
                                              , result);
      YYFPRINTF (stderr, "\n");
    }
}
#endif

/** Pop items off stack #K of STACK according to grammar rule RULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with RULE and store its value with the
 *  newly pushed state, if FORCEEVAL or if STACK is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #K from
 *  the STACK.  In this case, the (necessarily deferred) semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
             yybool yyforceEval, struct ParseResult* result)
{
  size_t yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == YY_NULL)
    {
      YYSTYPE yysval;

      YY_REDUCE_PRINT ((yystackp, yyk, yyrule, &yysval, result));
      YYCHK (yydoAction (yystackp, yyk, yyrule, &yysval, result));
      YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyrule], &yysval, &yyloc);
      yyglrShift (yystackp, yyk,
                  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                 yylhsNonterm (yyrule)),
                  yyposn, &yysval);
    }
  else
    {
      size_t yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yyStateNum yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
           0 < yyn; yyn -= 1)
        {
          yys = yys->yypred;
          YYASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YYDPRINTF ((stderr,
                  "Reduced stack %lu by rule #%d; action deferred.  Now in state %d.\n",
                  (unsigned long int) yyk, yyrule - 1, yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
        if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULL)
          {
            yyGLRState *yysplit = yystackp->yysplitPoint;
            yyGLRState *yyp = yystackp->yytops.yystates[yyi];
            while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
              {
                if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
                  {
                    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                    yymarkStackDeleted (yystackp, yyk);
                    YYDPRINTF ((stderr, "Merging stack %lu into stack %lu.\n",
                                (unsigned long int) yyk,
                                (unsigned long int) yyi));
                    return yyok;
                  }
                yyp = yyp->yypred;
              }
          }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static size_t
yysplitStack (yyGLRStack* yystackp, size_t yyk)
{
  if (yystackp->yysplitPoint == YY_NULL)
    {
      YYASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yysize >= yystackp->yytops.yycapacity)
    {
      yyGLRState** yynewStates;
      yybool* yynewLookaheadNeeds;

      yynewStates = YY_NULL;

      if (yystackp->yytops.yycapacity
          > (YYSIZEMAX / (2 * sizeof yynewStates[0])))
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      yynewStates =
        (yyGLRState**) YYREALLOC (yystackp->yytops.yystates,
                                  (yystackp->yytops.yycapacity
                                   * sizeof yynewStates[0]));
      if (yynewStates == YY_NULL)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yystates = yynewStates;

      yynewLookaheadNeeds =
        (yybool*) YYREALLOC (yystackp->yytops.yylookaheadNeeds,
                             (yystackp->yytops.yycapacity
                              * sizeof yynewLookaheadNeeds[0]));
      if (yynewLookaheadNeeds == YY_NULL)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize-1;
}

/** True iff Y0 and Y1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
           yyn = yyrhsLength (yyy0->yyrule);
           yyn > 0;
           yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
        if (yys0->yyposn != yys1->yyposn)
          return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (Y0,Y1), destructively merge the
 *  alternative semantic values for the RHS-symbols of Y1 and Y0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       yyn > 0;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
        break;
      else if (yys0->yyresolved)
        {
          yys1->yyresolved = yytrue;
          yys1->yysemantics.yysval = yys0->yysemantics.yysval;
        }
      else if (yys1->yyresolved)
        {
          yys0->yyresolved = yytrue;
          yys0->yysemantics.yysval = yys1->yysemantics.yysval;
        }
      else
        {
          yySemanticOption** yyz0p = &yys0->yysemantics.yyfirstVal;
          yySemanticOption* yyz1 = yys1->yysemantics.yyfirstVal;
          while (YYID (yytrue))
            {
              if (yyz1 == *yyz0p || yyz1 == YY_NULL)
                break;
              else if (*yyz0p == YY_NULL)
                {
                  *yyz0p = yyz1;
                  break;
                }
              else if (*yyz0p < yyz1)
                {
                  yySemanticOption* yyz = *yyz0p;
                  *yyz0p = yyz1;
                  yyz1 = yyz1->yynext;
                  (*yyz0p)->yynext = yyz;
                }
              yyz0p = &(*yyz0p)->yynext;
            }
          yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
        }
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
        return 0;
      else
        return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG yyresolveValue (yyGLRState* yys,
                                   yyGLRStack* yystackp, struct ParseResult* result);


/** Resolve the previous N states starting at and including state S.  If result
 *  != yyok, some states may have been left unresolved possibly with empty
 *  semantic option chains.  Regardless of whether result = yyok, each state
 *  has been left with consistent data so that yydestroyGLRState can be invoked
 *  if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
                 yyGLRStack* yystackp, struct ParseResult* result)
{
  if (0 < yyn)
    {
      YYASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp, result));
      if (! yys->yyresolved)
        YYCHK (yyresolveValue (yys, yystackp, result));
    }
  return yyok;
}

/** Resolve the states for the RHS of OPT, perform its user action, and return
 *  the semantic value and location.  Regardless of whether result = yyok, all
 *  RHS states have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
                 YYSTYPE* yyvalp, struct ParseResult* result)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs = yyrhsLength (yyopt->yyrule);
  YYRESULTTAG yyflag =
    yyresolveStates (yyopt->yystate, yynrhs, yystackp, result);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
        yydestroyGLRState ("Cleanup: popping", yys, result);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  {
    int yychar_current = yychar;
    YYSTYPE yylval_current = yylval;
    yychar = yyopt->yyrawchar;
    yylval = yyopt->yyval;
    yyflag = yyuserAction (yyopt->yyrule, yynrhs,
                           yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyvalp, result);
    yychar = yychar_current;
    yylval = yylval_current;
  }
  return yyflag;
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == YY_NULL)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YYFPRINTF (stderr, "%*s%s -> <Rule %d, empty>\n",
               yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
               yyx->yyrule - 1);
  else
    YYFPRINTF (stderr, "%*s%s -> <Rule %d, tokens %lu .. %lu>\n",
               yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
               yyx->yyrule - 1, (unsigned long int) (yys->yyposn + 1),
               (unsigned long int) yyx->yystate->yyposn);
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
        {
          if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
            YYFPRINTF (stderr, "%*s%s <empty>\n", yyindent+2, "",
                       yytokenName (yyrhs[yyprhs[yyx->yyrule]+yyi-1]));
          else
            YYFPRINTF (stderr, "%*s%s <tokens %lu .. %lu>\n", yyindent+2, "",
                       yytokenName (yyrhs[yyprhs[yyx->yyrule]+yyi-1]),
                       (unsigned long int) (yystates[yyi - 1]->yyposn + 1),
                       (unsigned long int) yystates[yyi]->yyposn);
        }
      else
        yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

/*ARGSUSED*/ static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
                   yySemanticOption* yyx1, struct ParseResult* result)
{
  YYUSE (yyx0);
  YYUSE (yyx1);

#if YYDEBUG
  YYFPRINTF (stderr, "Ambiguity detected.\n");
  YYFPRINTF (stderr, "Option 1,\n");
  yyreportTree (yyx0, 2);
  YYFPRINTF (stderr, "\nOption 2,\n");
  yyreportTree (yyx1, 2);
  YYFPRINTF (stderr, "\n");
#endif

  yyerror (result, YY_("syntax is ambiguous"));
  return yyabort;
}

/** Resolve the ambiguity represented in state S, perform the indicated
 *  actions, and set the semantic value of S.  If result != yyok, the chain of
 *  semantic options in S has been cleared instead or it has been left
 *  unmodified except that redundant options may have been removed.  Regardless
 *  of whether result = yyok, S has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp, struct ParseResult* result)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest = yyoptionList;
  yySemanticOption** yypp;
  yybool yymerge = yyfalse;
  YYSTYPE yysval;
  YYRESULTTAG yyflag;

  for (yypp = &yyoptionList->yynext; *yypp != YY_NULL; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
        {
          yymergeOptionSets (yybest, yyp);
          *yypp = yyp->yynext;
        }
      else
        {
          switch (yypreference (yybest, yyp))
            {
            case 0:
              return yyreportAmbiguity (yybest, yyp, result);
              break;
            case 1:
              yymerge = yytrue;
              break;
            case 2:
              break;
            case 3:
              yybest = yyp;
              yymerge = yyfalse;
              break;
            default:
              /* This cannot happen so it is not worth a YYASSERT (yyfalse),
                 but some compilers complain if the default case is
                 omitted.  */
              break;
            }
          yypp = &yyp->yynext;
        }
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yysval, result);
      if (yyflag == yyok)
        for (yyp = yybest->yynext; yyp != YY_NULL; yyp = yyp->yynext)
          {
            if (yyprec == yydprec[yyp->yyrule])
              {
                YYSTYPE yysval_other;
                yyflag = yyresolveAction (yyp, yystackp, &yysval_other, result);
                if (yyflag != yyok)
                  {
                    yydestruct ("Cleanup: discarding incompletely merged value for",
                                yystos[yys->yylrState],
                                &yysval, result);
                    break;
                  }
                yyuserMerge (yymerger[yyp->yyrule], &yysval, &yysval_other);
              }
          }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yysval, result);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yysval = yysval;
    }
  else
    yys->yysemantics.yyfirstVal = YY_NULL;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp, struct ParseResult* result)
{
  if (yystackp->yysplitPoint != YY_NULL)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
           yys != yystackp->yysplitPoint;
           yys = yys->yypred, yyn += 1)
        continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
                             , result));
    }
  return yyok;
}

static void
yycompressStack (yyGLRStack* yystackp)
{
  yyGLRState* yyp, *yyq, *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULL)
    return;

  for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULL;
       yyp != yystackp->yysplitPoint;
       yyr = yyp, yyp = yyq, yyq = yyp->yypred)
    yyp->yypred = yyr;

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = ((yyGLRStackItem*) yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULL;
  yystackp->yylastDeleted = YY_NULL;

  while (yyr != YY_NULL)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
                   size_t yyposn, struct ParseResult* result)
{
  int yyaction;
  const short int* yyconflicts;
  yyRuleNum yyrule;

  while (yystackp->yytops.yystates[yyk] != YY_NULL)
    {
      yyStateNum yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YYDPRINTF ((stderr, "Stack %lu Entering state %d\n",
                  (unsigned long int) yyk, yystate));

      YYASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
        {
          yyrule = yydefaultAction (yystate);
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, "Stack %lu dies.\n",
                          (unsigned long int) yyk));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          YYCHK (yyglrReduce (yystackp, yyk, yyrule, yyfalse, result));
        }
      else
        {
          yySymbol yytoken;
          yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;
          if (yychar == YYEMPTY)
            {
              YYDPRINTF ((stderr, "Reading a token: "));
              yychar = YYLEX;
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

          yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);

          while (*yyconflicts != 0)
            {
              size_t yynewStack = yysplitStack (yystackp, yyk);
              YYDPRINTF ((stderr, "Splitting off stack %lu from %lu.\n",
                          (unsigned long int) yynewStack,
                          (unsigned long int) yyk));
              YYCHK (yyglrReduce (yystackp, yynewStack,
                                  *yyconflicts, yyfalse, result));
              YYCHK (yyprocessOneStack (yystackp, yynewStack,
                                        yyposn, result));
              yyconflicts += 1;
            }

          if (yyisShiftAction (yyaction))
            break;
          else if (yyisErrorAction (yyaction))
            {
              YYDPRINTF ((stderr, "Stack %lu dies.\n",
                          (unsigned long int) yyk));
              yymarkStackDeleted (yystackp, yyk);
              break;
            }
          else
            YYCHK (yyglrReduce (yystackp, yyk, -yyaction,
                                yyfalse, result));
        }
    }
  return yyok;
}

/*ARGSUSED*/ static void
yyreportSyntaxError (yyGLRStack* yystackp, struct ParseResult* result)
{
  if (yystackp->yyerrState != 0)
    return;
#if ! YYERROR_VERBOSE
  yyerror (result, YY_("syntax error"));
#else
  {
  yySymbol yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
  size_t yysize0 = yytnamerr (YY_NULL, yytokenName (yytoken));
  size_t yysize = yysize0;
  yybool yysize_overflow = yyfalse;
  char* yymsg = YY_NULL;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected").  */
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
      int yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
      yyarg[yycount++] = yytokenName (yytoken);
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for this
             state because they are default actions.  */
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
                yyarg[yycount++] = yytokenName (yyx);
                {
                  size_t yysz = yysize + yytnamerr (YY_NULL, yytokenName (yyx));
                  yysize_overflow |= yysz < yysize;
                  yysize = yysz;
                }
              }
        }
    }

  switch (yycount)
    {
#define YYCASE_(N, S)                   \
      case N:                           \
        yyformat = S;                   \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  {
    size_t yysz = yysize + strlen (yyformat);
    yysize_overflow |= yysz < yysize;
    yysize = yysz;
  }

  if (!yysize_overflow)
    yymsg = (char *) YYMALLOC (yysize);

  if (yymsg)
    {
      char *yyp = yymsg;
      int yyi = 0;
      while ((*yyp = *yyformat))
        {
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
      yyerror (result, yymsg);
      YYFREE (yymsg);
    }
  else
    {
      yyerror (result, YY_("syntax error"));
      yyMemoryExhausted (yystackp);
    }
  }
#endif /* YYERROR_VERBOSE */
  yynerrs += 1;
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the lookahead.  */
/*ARGSUSED*/ static void
yyrecoverSyntaxError (yyGLRStack* yystackp, struct ParseResult* result)
{
  size_t yyk;
  int yyj;

  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (YYID (yytrue))
      {
        yySymbol yytoken;
        if (yychar == YYEOF)
          yyFail (yystackp, result, YY_NULL);
        if (yychar != YYEMPTY)
          {
            yytoken = YYTRANSLATE (yychar);
            yydestruct ("Error: discarding",
                        yytoken, &yylval, result);
          }
        YYDPRINTF ((stderr, "Reading a token: "));
        yychar = YYLEX;
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
        yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
        if (yypact_value_is_default (yyj))
          return;
        yyj += yytoken;
        if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
          {
            if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
              return;
          }
        else if (! yytable_value_is_error (yytable[yyj]))
          return;
      }

  /* Reduce to one stack.  */
  for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
    if (yystackp->yytops.yystates[yyk] != YY_NULL)
      break;
  if (yyk >= yystackp->yytops.yysize)
    yyFail (yystackp, result, YY_NULL);
  for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
    yymarkStackDeleted (yystackp, yyk);
  yyremoveDeletes (yystackp);
  yycompressStack (yystackp);

  /* Now pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != YY_NULL)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      yyj = yypact[yys->yylrState];
      if (! yypact_value_is_default (yyj))
        {
          yyj += YYTERROR;
          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYTERROR
              && yyisShiftAction (yytable[yyj]))
            {
              /* Shift the error token.  */
              YY_SYMBOL_PRINT ("Shifting", yystos[yytable[yyj]],
                               &yylval, &yyerrloc);
              yyglrShift (yystackp, 0, yytable[yyj],
                          yys->yyposn, &yylval);
              yys = yystackp->yytops.yystates[0];
              break;
            }
        }
      if (yys->yypred != YY_NULL)
        yydestroyGLRState ("Error: popping", yys, result);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == YY_NULL)
    yyFail (yystackp, result, YY_NULL);
}

#define YYCHK1(YYE)                                                          \
  do {                                                                       \
    switch (YYE) {                                                           \
    case yyok:                                                               \
      break;                                                                 \
    case yyabort:                                                            \
      goto yyabortlab;                                                       \
    case yyaccept:                                                           \
      goto yyacceptlab;                                                      \
    case yyerr:                                                              \
      goto yyuser_error;                                                     \
    default:                                                                 \
      goto yybuglab;                                                         \
    }                                                                        \
  } while (YYID (0))


/*----------.
| yyparse.  |
`----------*/

int
yyparse (struct ParseResult* result)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  size_t yyposn;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;

  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval);
  yyposn = 0;

  while (YYID (yytrue))
    {
      /* For efficiency, we have two loops, the first of which is
         specialized to deterministic operation (single stack, no
         potential ambiguity).  */
      /* Standard mode */
      while (YYID (yytrue))
        {
          yyRuleNum yyrule;
          int yyaction;
          const short int* yyconflicts;

          yyStateNum yystate = yystack.yytops.yystates[0]->yylrState;
          YYDPRINTF ((stderr, "Entering state %d\n", yystate));
          if (yystate == YYFINAL)
            goto yyacceptlab;
          if (yyisDefaultedState (yystate))
            {
              yyrule = yydefaultAction (yystate);
              if (yyrule == 0)
                {

                  yyreportSyntaxError (&yystack, result);
                  goto yyuser_error;
                }
              YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue, result));
            }
          else
            {
              yySymbol yytoken;
              if (yychar == YYEMPTY)
                {
                  YYDPRINTF ((stderr, "Reading a token: "));
                  yychar = YYLEX;
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

              yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
              if (*yyconflicts != 0)
                break;
              if (yyisShiftAction (yyaction))
                {
                  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
                  yychar = YYEMPTY;
                  yyposn += 1;
                  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval);
                  if (0 < yystack.yyerrState)
                    yystack.yyerrState -= 1;
                }
              else if (yyisErrorAction (yyaction))
                {

                  yyreportSyntaxError (&yystack, result);
                  goto yyuser_error;
                }
              else
                YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue, result));
            }
        }

      while (YYID (yytrue))
        {
          yySymbol yytoken_to_shift;
          size_t yys;

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

          /* yyprocessOneStack returns one of three things:

              - An error flag.  If the caller is yyprocessOneStack, it
                immediately returns as well.  When the caller is finally
                yyparse, it jumps to an error label via YYCHK1.

              - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
                (&yystack, yys), which sets the top state of yys to NULL.  Thus,
                yyparse's following invocation of yyremoveDeletes will remove
                the stack.

              - yyok, when ready to shift a token.

             Except in the first case, yyparse will invoke yyremoveDeletes and
             then shift the next token onto all remaining stacks.  This
             synchronization of the shift (that is, after all preceding
             reductions on all stacks) helps prevent double destructor calls
             on yylval in the event of memory exhaustion.  */

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn, result));
          yyremoveDeletes (&yystack);
          if (yystack.yytops.yysize == 0)
            {
              yyundeleteLastStack (&yystack);
              if (yystack.yytops.yysize == 0)
                yyFail (&yystack, result, YY_("syntax error"));
              YYCHK1 (yyresolveStack (&yystack, result));
              YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));

              yyreportSyntaxError (&yystack, result);
              goto yyuser_error;
            }

          /* If any yyglrShift call fails, it will fail after shifting.  Thus,
             a copy of yylval will already be on stack 0 in the event of a
             failure in the following loop.  Thus, yychar is set to YYEMPTY
             before the loop to make sure the user destructor for yylval isn't
             called twice.  */
          yytoken_to_shift = YYTRANSLATE (yychar);
          yychar = YYEMPTY;
          yyposn += 1;
          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            {
              int yyaction;
              const short int* yyconflicts;
              yyStateNum yystate = yystack.yytops.yystates[yys]->yylrState;
              yygetLRActions (yystate, yytoken_to_shift, &yyaction,
                              &yyconflicts);
              /* Note that yyconflicts were handled by yyprocessOneStack.  */
              YYDPRINTF ((stderr, "On stack %lu, ", (unsigned long int) yys));
              YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
              yyglrShift (&yystack, yys, yyaction, yyposn,
                          &yylval);
              YYDPRINTF ((stderr, "Stack %lu now in state #%d\n",
                          (unsigned long int) yys,
                          yystack.yytops.yystates[yys]->yylrState));
            }

          if (yystack.yytops.yysize == 1)
            {
              YYCHK1 (yyresolveStack (&yystack, result));
              YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yycompressStack (&yystack);
              break;
            }
        }
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack, result);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturn;

 yybuglab:
  YYASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturn;

 yyexhaustedlab:
  yyerror (result, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;

 yyreturn:
  if (yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
                YYTRANSLATE (yychar), &yylval, result);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
        {
          size_t yysize = yystack.yytops.yysize;
          size_t yyk;
          for (yyk = 0; yyk < yysize; yyk += 1)
            if (yystates[yyk])
              {
                while (yystates[yyk])
                  {
                    yyGLRState *yys = yystates[yyk];
                  if (yys->yypred != YY_NULL)
                      yydestroyGLRState ("Cleanup: popping", yys, result);
                    yystates[yyk] = yys->yypred;
                    yystack.yynextFree -= 1;
                    yystack.yyspaceLeft += 1;
                  }
                break;
              }
        }
      yyfreeGLRStack (&yystack);
    }

  /* Make sure YYID is used.  */
  return YYID (yyresult);
}

/* DEBUGGING ONLY */
#if YYDEBUG
static void yypstack (yyGLRStack* yystackp, size_t yyk)
  __attribute__ ((__unused__));
static void yypdumpstack (yyGLRStack* yystackp) __attribute__ ((__unused__));

static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      YYFPRINTF (stderr, " -> ");
    }
  YYFPRINTF (stderr, "%d@%lu", yys->yylrState,
             (unsigned long int) yys->yyposn);
}

static void
yypstates (yyGLRState* yyst)
{
  if (yyst == YY_NULL)
    YYFPRINTF (stderr, "<null>");
  else
    yy_yypstack (yyst);
  YYFPRINTF (stderr, "\n");
}

static void
yypstack (yyGLRStack* yystackp, size_t yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

#define YYINDEX(YYX)                                                         \
    ((YYX) == YY_NULL ? -1 : (yyGLRStackItem*) (YYX) - yystackp->yyitems)


static void
yypdumpstack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yyp;
  size_t yyi;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      YYFPRINTF (stderr, "%3lu. ",
                 (unsigned long int) (yyp - yystackp->yyitems));
      if (*(yybool *) yyp)
        {
          YYFPRINTF (stderr, "Res: %d, LR State: %d, posn: %lu, pred: %ld",
                     yyp->yystate.yyresolved, yyp->yystate.yylrState,
                     (unsigned long int) yyp->yystate.yyposn,
                     (long int) YYINDEX (yyp->yystate.yypred));
          if (! yyp->yystate.yyresolved)
            YYFPRINTF (stderr, ", firstVal: %ld",
                       (long int) YYINDEX (yyp->yystate
                                             .yysemantics.yyfirstVal));
        }
      else
        {
          YYFPRINTF (stderr, "Option. rule: %d, state: %ld, next: %ld",
                     yyp->yyoption.yyrule - 1,
                     (long int) YYINDEX (yyp->yyoption.yystate),
                     (long int) YYINDEX (yyp->yyoption.yynext));
        }
      YYFPRINTF (stderr, "\n");
    }
  YYFPRINTF (stderr, "Tops:");
  for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
    YYFPRINTF (stderr, "%lu: %ld; ", (unsigned long int) yyi,
               (long int) YYINDEX (yystackp->yytops.yystates[yyi]));
  YYFPRINTF (stderr, "\n");
}
#endif
/* Line 2575 of glr.c  */
#line 1237 "sql.ypp"


void emit(char *s, ...)
{
 	/*
 	extern int yylineno;
	va_list ap;
  	va_start(ap, s);
  	printf("rpn: ");
  	vfprintf(stdout, s, ap);
  	printf("\n");
  	*/
}

void yyerror(struct ParseResult *pp,const char *  s, ...) {
  va_list ap;
  va_start(ap, s);
  string sql_clause = pp->sql_clause;
  vector<string> tokens;
  boost::split(tokens, sql_clause, boost::is_any_of("\n"));
  ostringstream ostr;
  int columnno = 0;
  int lineno = yyget_lineno(pp->yyscan_info_);
  lineno = lineno % tokens.size();
  lineno++;
  // Because find() can only find the first place where the word appears,
  // so this method may not find the certain place.
  /*
  for (int i = 0; i < tokens.size(); i++) {
    columnno = tokens[i].find(yyget_text(pp->yyscan_info_)) + 1;
    if (-1 != columnno && ((lineno - 1) == i)) {
      cout << "In clause \'"
           << "\e[1m" << tokens[i] << "\e[0m\'" << endl;
      for (int j = 0; j < (columnno + 9); j++) {
        cout << ".";
      }
      cout << "^" << endl;
      ostr << "In clause \'"
           << "\e[1m" << tokens[i] << "\e[0m\'" << endl;
      for (int j = 0; j < (columnno + 9); j++) {
        ostr << ".";
      }
      ostr << "^" << endl;
      break;
    }
  }
  */
  string wrong_clause = tokens[lineno - 1];
  vector<string> words_in_clause;
  boost::split(words_in_clause, tokens[lineno - 1], boost::is_any_of(" "));
  int yyget_col_no = yyget_column(pp->yyscan_info_);
  if (yyget_col_no == 0) {
    yyget_col_no = 1;
  }
  cout << "yyget_col_no = " << yyget_col_no << endl;
  int column_num = 1;
  for (int i = 0; i < words_in_clause.size(); i++) {
    if (i == (yyget_col_no - 1)) {
      cout << "In clause \'"
           << "\e[1m" << tokens[lineno - 1] << "\e[0m\'" << endl;
      ostr << "In clause \'"
           << "\e[1m" << tokens[lineno - 1] << "\e[0m\'" << endl;
      for (int j = 0; j < (column_num + 10); j++) {
        ostr << ".";
        cout << ".";
      }
      cout << "^" << endl;
      ostr << "^" << endl;

      break;
    } else {
      column_num = column_num + words_in_clause[i].size() + 1;
    }
  }
  ostr << "SQL syntax error at \e[1mline: " << lineno << ","
       << "\e[0m near \'\e[1m";
  ostr << yyget_text(pp->yyscan_info_);
  // ostr << "\e[1mLINE: " << lineno << "," << columnno << "\e[0m error: ";
  // ostr << "near \'\e[1m";
  // ostr << yyget_text(pp->yyscan_info_);
  ostr << "\e[0m\'." << endl;
  pp->error_info_ = ostr.str();
  cout << "SQL syntax error at \e[1mline: " << lineno << ","
       << "\e[0m near \'\e[1m";
  cout << yyget_text(pp->yyscan_info_);
  cout << "\e[0m\'." << endl;
  /*
  cout << "\e[1mLINE: " << lineno << "\e[0m error: ";
  cout << "near \'\e[1m";
  cout << yyget_text(pp->yyscan_info_);
  cout << "\e[0m\'." << endl;
  */
  yyset_column(0, pp->yyscan_info_);

  vfprintf(stderr, s, ap);
  fprintf(stderr, "\n");
}
