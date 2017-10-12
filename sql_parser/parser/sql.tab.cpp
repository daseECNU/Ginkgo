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
#include "../ast_node/ast_truncate_stmt.h"

void yyerror(struct ParseResult *pp,const char *s, ...);
void emit(char *s, ...);

/* Line 207 of glr.c  */
#line 86 "sql.tab.cpp"

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
#line 47 "sql.ypp"

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
#line 132 "sql.tab.cpp"

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
#define YYFINAL  108
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2736

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  343
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  90
/* YYNRULES -- Number of rules.  */
#define YYNRULES  389
/* YYNRULES -- Number of states.  */
#define YYNSTATES  841
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 13
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYTRANSLATE(X) -- Bison symbol number corresponding to X.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   583

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned short int yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    17,     2,     2,     2,    28,    22,     2,
     340,   341,    26,    24,   339,    25,   342,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   338,
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
     334,   335,   336,   337
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
     516,   521,   526,   531,   536,   541,   548,   555,   564,   573,
     578,   586,   591,   598,   603,   605,   607,   609,   610,   612,
     614,   616,   618,   620,   627,   634,   638,   642,   646,   650,
     654,   658,   662,   666,   670,   675,   682,   686,   692,   697,
     703,   707,   712,   716,   721,   723,   728,   733,   734,   738,
     740,   749,   760,   770,   777,   789,   798,   802,   803,   805,
     807,   808,   810,   812,   816,   820,   826,   831,   836,   842,
     848,   849,   853,   856,   860,   864,   868,   872,   875,   879,
     883,   886,   890,   896,   899,   903,   907,   911,   915,   919,
     923,   927,   931,   935,   939,   941,   943,   945,   947,   949,
     953,   957,   960,   965,   967,   969,   971,   973,   977,   981,
     985,   989,   995,  1001,  1003,  1007,  1008,  1012,  1018,  1019,
    1021,  1022,  1025,  1028,  1029,  1034,  1038,  1040,  1051,  1065,
    1067,  1078,  1079,  1081,  1083,  1085,  1086,  1089,  1091,  1093,
    1097,  1103,  1105,  1118,  1128,  1138,  1151,  1153,  1159,  1161,
    1166,  1171,  1172,  1175,  1177,  1184,  1186,  1190,  1194,  1200,
    1201,  1203,  1205,  1207,  1212,  1218,  1220,  1224,  1230,  1232,
    1241,  1242,  1248,  1249,  1252,  1255,  1258,  1261,  1263,  1264,
    1265,  1269,  1273,  1279,  1281,  1283,  1287,  1291,  1299,  1307,
    1311,  1315,  1321,  1327,  1329,  1335,  1339,  1347,  1352,  1357,
    1362,  1366,  1370,  1375,  1380,  1384,  1388,  1392,  1397,  1403,
    1407,  1411,  1417,  1420,  1424,  1429,  1435,  1440,  1445,  1450,
    1454,  1458,  1459,  1460,  1463,  1464,  1467,  1468,  1471,  1472,
    1474,  1475,  1477,  1479,  1482,  1484,  1492,  1500,  1507,  1510,
    1513,  1516,  1517,  1520,  1525,  1526,  1529,  1531,  1537,  1541
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const short int yyrhs[] =
{
     344,     0,    -1,   345,   338,    -1,   344,   345,   338,    -1,
       1,   338,    -1,   344,     1,   338,    -1,   346,    -1,   194,
     358,   360,    -1,   194,   358,   360,   356,   107,   362,   347,
     348,   352,   353,   355,    -1,    -1,   244,   375,    -1,    -1,
     111,    48,   349,   351,    -1,   375,    -1,   375,   339,   349,
      -1,    -1,    40,    -1,    83,    -1,    -1,   246,   189,    -1,
      -1,   112,   375,    -1,    -1,   164,    48,   354,    -1,   375,
     350,    -1,   375,   350,   339,   354,    -1,    -1,   137,   375,
      -1,   137,   375,   339,   375,    -1,    -1,   128,   364,   168,
     159,     3,    -1,   128,   364,   158,    20,     5,   168,   159,
       3,    -1,     3,    -1,     3,   339,   357,    -1,    -1,    86,
      -1,    86,   159,   340,   359,   341,    -1,    33,    -1,    86,
     359,    -1,   375,    -1,   375,   339,   359,    -1,   361,    -1,
     361,   339,   360,    -1,    26,    -1,   375,   366,    -1,   363,
      -1,   363,   339,   362,    -1,   364,    -1,   367,    -1,     3,
     366,    -1,     3,   342,     3,   366,    -1,   374,   365,     3,
      -1,   340,   362,   341,    -1,    -1,    39,    -1,    39,     3,
      -1,     3,    -1,    -1,   363,   368,   130,   364,   372,    -1,
     363,   213,   364,    -1,   363,   213,   364,   159,   375,    -1,
     363,   370,   369,   130,   364,   373,    -1,   363,   155,   371,
     130,   364,    -1,    -1,   121,    -1,    63,    -1,    -1,   166,
      -1,   136,    -1,   188,    -1,   108,    -1,   136,   369,    -1,
     188,   369,    -1,   108,   369,    -1,    -1,    -1,   373,    -1,
     159,   375,    -1,   235,   340,   357,   341,    -1,   340,   346,
     341,    -1,     3,    -1,     8,    -1,     3,   342,     3,    -1,
       3,   342,    26,    -1,     4,    -1,     5,    -1,     7,    -1,
       6,    -1,   375,    24,   375,    -1,   375,    25,   375,    -1,
     375,    26,   375,    -1,   375,    27,   375,    -1,   375,    29,
     375,    -1,   375,    28,   375,    -1,    25,   375,    -1,    24,
     375,    -1,   375,    12,   375,    -1,   375,    10,   375,    -1,
     375,    11,   375,    -1,   375,    20,   375,    -1,   375,    20,
     340,   346,   341,    -1,   375,    20,    37,   340,   346,   341,
      -1,   375,    20,   200,   340,   346,   341,    -1,   375,    20,
      33,   340,   346,   341,    -1,   375,    21,   375,    -1,   375,
      22,   375,    -1,   375,    30,   375,    -1,   375,    23,   375,
      -1,    17,   375,    -1,    18,   375,    -1,     8,     9,   375,
      -1,   340,   375,   341,    -1,   375,    15,   157,    -1,   375,
      15,    18,   157,    -1,   375,    15,     6,    -1,   375,    15,
      18,     6,    -1,   375,    19,   375,    36,   375,    -1,   375,
      -1,   375,   339,   376,    -1,   340,   376,   341,    -1,   376,
      -1,   376,   339,   377,    -1,   375,    16,   340,   376,   341,
      -1,   340,   376,   341,    16,   340,   377,   341,    -1,   375,
      18,    16,   340,   376,   341,    -1,   340,   376,   341,    18,
      16,   340,   376,   341,    -1,   375,    16,   340,   346,   341,
      -1,   340,   376,   341,    16,   340,   346,   341,    -1,   375,
      18,    16,   340,   346,   341,    -1,   340,   376,   341,    18,
      16,   340,   346,   341,    -1,    99,   340,   346,   341,    -1,
      18,    99,   340,   346,   341,    -1,   328,   340,    26,   341,
      -1,   328,   340,   375,   341,    -1,   333,   340,   375,   341,
      -1,   334,   340,   375,   341,    -1,   335,   340,   375,   341,
      -1,   336,   340,   375,   341,    -1,   337,   340,   375,   341,
      -1,   337,   340,   358,   341,    -1,   328,   340,   358,   341,
      -1,   333,   340,   358,   341,    -1,   334,   340,   358,   341,
      -1,   335,   340,   358,   341,    -1,   336,   340,   358,   341,
      -1,   324,   340,   375,   339,   375,   341,    -1,   324,   340,
     375,   107,   375,   341,    -1,   324,   340,   375,   339,   375,
     339,   375,   341,    -1,   324,   340,   375,   107,   375,   104,
     375,   341,    -1,   325,   340,   375,   341,    -1,   325,   340,
     378,   375,   107,   375,   341,    -1,   329,   340,   375,   341,
      -1,   330,   340,   375,    39,   379,   341,    -1,   331,   340,
     376,   341,    -1,   134,    -1,   225,    -1,    47,    -1,    -1,
     126,    -1,     4,    -1,    89,    -1,   103,    -1,    53,    -1,
     326,   340,   375,   339,   380,   341,    -1,   327,   340,   375,
     339,   380,   341,    -1,   127,   375,    73,    -1,   127,   375,
      75,    -1,   127,   375,    76,    -1,   127,   375,    77,    -1,
     127,   375,    74,    -1,   127,   375,   249,    -1,   127,   375,
     248,    -1,   127,   375,   251,    -1,   127,   375,   175,    -1,
      51,   375,   381,    96,    -1,    51,   375,   381,    93,   375,
      96,    -1,    51,   381,    96,    -1,    51,   381,    93,   375,
      96,    -1,   243,   375,   218,   375,    -1,   381,   243,   375,
     218,   375,    -1,   375,    14,   375,    -1,   375,    18,    14,
     375,    -1,   375,    13,   375,    -1,   375,    18,    13,   375,
      -1,   382,    -1,    62,    69,   383,     3,    -1,    62,   191,
     383,     3,    -1,    -1,   117,    18,    99,    -1,   384,    -1,
      62,   387,   214,   383,     3,   340,   388,   341,    -1,    62,
     387,   214,   383,     3,   342,     3,   340,   388,   341,    -1,
      62,   387,   214,   383,     3,   340,   388,   341,   385,    -1,
      62,   387,   214,   383,     3,   385,    -1,    62,   387,   214,
     383,     3,   342,     3,   340,   388,   341,   385,    -1,    62,
     387,   214,   383,     3,   342,     3,   385,    -1,   386,   365,
     346,    -1,    -1,   118,    -1,   183,    -1,    -1,   215,    -1,
     389,    -1,   389,   339,   388,    -1,     3,   391,   390,    -1,
     170,   131,   340,   357,   341,    -1,   131,   340,   357,   341,
      -1,   119,   340,   357,   341,    -1,   109,   119,   340,   357,
     341,    -1,   109,   131,   340,   357,   341,    -1,    -1,   390,
      18,   157,    -1,   390,   157,    -1,   390,    80,     4,    -1,
     390,    80,     5,    -1,   390,    80,     7,    -1,   390,    80,
       6,    -1,   390,    41,    -1,   390,   229,   131,    -1,   390,
     170,   131,    -1,   390,   131,    -1,   390,    57,     4,    -1,
     390,   229,   340,   357,   341,    -1,    45,   393,    -1,   222,
     393,   395,    -1,   199,   393,   395,    -1,   150,   393,   395,
      -1,   125,   393,   395,    -1,   126,   393,   395,    -1,    43,
     393,   395,    -1,   178,   393,   395,    -1,    89,   393,   395,
      -1,   103,   393,   395,    -1,    78,   393,   395,    -1,    71,
      -1,   219,    -1,   220,    -1,    72,    -1,   248,    -1,    53,
     393,   396,    -1,   241,   393,   396,    -1,    44,   393,    -1,
     240,   340,     5,   341,    -1,   221,    -1,    46,    -1,   149,
      -1,   144,    -1,   223,   394,   396,    -1,   216,   394,   396,
      -1,   151,   394,   396,    -1,   145,   394,   396,    -1,    97,
     340,   392,   341,   396,    -1,   197,   340,   392,   341,   396,
      -1,     4,    -1,   392,   339,     4,    -1,    -1,   340,     5,
     341,    -1,   340,     5,   339,     5,   341,    -1,    -1,    44,
      -1,    -1,   395,   231,    -1,   395,   250,    -1,    -1,   396,
      53,   197,     3,    -1,   396,    55,     3,    -1,   397,    -1,
      62,   172,   159,     3,   340,   357,   341,   168,   159,     3,
      -1,    62,   172,   159,     3,   340,   357,   341,   158,    20,
       5,   168,   159,     3,    -1,   398,    -1,    62,   399,   119,
       3,   400,   159,     3,   340,   402,   341,    -1,    -1,   229,
      -1,   109,    -1,   202,    -1,    -1,   235,   401,    -1,   320,
      -1,   321,    -1,     3,   393,   350,    -1,     3,   393,   350,
     339,   402,    -1,   403,    -1,   139,   214,     3,   107,   376,
     246,     4,   339,     4,   190,    20,     7,    -1,   139,   214,
       3,   107,   376,   246,     4,   339,     4,    -1,    38,   214,
       3,   107,   376,   246,     4,   339,     4,    -1,    38,   214,
       3,   107,   376,   246,     4,   339,     4,   190,    20,     7,
      -1,   404,    -1,    90,   119,     3,   159,     3,    -1,   405,
      -1,    90,    69,   406,     3,    -1,    90,   191,   406,     3,
      -1,    -1,   117,    99,    -1,   407,    -1,    90,   387,   214,
     406,   408,   409,    -1,     3,    -1,     3,   342,     3,    -1,
       3,   339,   408,    -1,     3,   342,     3,   339,   408,    -1,
      -1,   185,    -1,    50,    -1,   410,    -1,    90,   172,   107,
       3,    -1,    90,   172,     5,   107,     3,    -1,   411,    -1,
     258,   214,   408,    -1,   258,   172,     5,   107,     3,    -1,
     412,    -1,   124,   414,   415,     3,   416,   239,   417,   413,
      -1,    -1,   159,   160,   131,   232,   419,    -1,    -1,   414,
     147,    -1,   414,    81,    -1,   414,   113,    -1,   414,   118,
      -1,   128,    -1,    -1,    -1,   340,   357,   341,    -1,   340,
     418,   341,    -1,   340,   418,   341,   339,   417,    -1,   375,
      -1,    80,    -1,   375,   339,   418,    -1,    80,   339,   418,
      -1,   124,   414,   415,     3,   197,   419,   413,    -1,   124,
     414,   415,     3,   416,   346,   413,    -1,     3,    20,   375,
      -1,     3,    20,    80,    -1,   419,   339,     3,    20,   375,
      -1,   419,   339,     3,    20,    80,    -1,   420,    -1,   198,
     421,   278,   422,   423,    -1,   198,   296,   423,    -1,   198,
     421,   297,   107,     3,   422,   423,    -1,   198,    62,    69,
       3,    -1,   198,    62,   191,     3,    -1,   198,    62,   214,
       3,    -1,   198,    69,     3,    -1,   198,   191,     3,    -1,
     198,   298,     3,   299,    -1,   198,   298,     3,   300,    -1,
     198,   301,   302,    -1,   198,   303,   355,    -1,   198,   375,
     303,    -1,   198,   304,   104,     8,    -1,   198,   119,   107,
       3,   422,    -1,   198,   305,   300,    -1,   198,   425,   299,
      -1,   198,   323,   278,   422,   423,    -1,   198,   289,    -1,
     198,   421,   306,    -1,   198,   426,   300,   423,    -1,   198,
     214,   300,   422,   423,    -1,   198,   295,   197,   423,    -1,
     198,   307,   422,   424,    -1,   198,   426,   308,   423,    -1,
     198,   309,   355,    -1,   198,   375,   309,    -1,    -1,    -1,
     107,     3,    -1,    -1,    14,     4,    -1,    -1,    14,   375,
      -1,    -1,   322,    -1,    -1,   281,    -1,   282,    -1,    83,
       3,    -1,   427,    -1,    82,   428,   107,   362,   347,   353,
     355,    -1,    82,   428,   107,   429,   235,   362,   347,    -1,
      82,   428,   429,   107,   362,   347,    -1,   428,   147,    -1,
     428,   174,    -1,   428,   118,    -1,    -1,     3,   430,    -1,
     429,   339,     3,   430,    -1,    -1,   342,    26,    -1,   431,
      -1,   232,   364,   197,   432,   347,    -1,   375,    20,   375,
      -1,   432,   339,   375,    20,   375,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   446,   446,   460,   473,   482,   494,   498,   502,   509,
     510,   513,   514,   519,   520,   522,   523,   524,   527,   528,
     531,   532,   535,   536,   539,   540,   542,   543,   544,   547,
     548,   549,   557,   558,   573,   574,   575,   576,   577,   581,
     582,   586,   587,   588,   592,   595,   596,   600,   601,   605,
     607,   609,   610,   613,   614,   617,   618,   619,   634,   635,
     636,   637,   638,   641,   642,   643,   646,   647,   651,   652,
     653,   657,   658,   659,   660,   663,   664,   672,   673,   678,
     685,   686,   687,   688,   689,   690,   691,   692,   694,   695,
     696,   697,   698,   699,   701,   702,   704,   705,   706,   708,
     709,   710,   711,   712,   714,   715,   716,   717,   719,   720,
     721,   722,   725,   726,   727,   728,   731,   734,   735,   736,
     739,   740,   743,   744,   745,   747,   749,   750,   751,   752,
     754,   755,   765,   766,   767,   768,   769,   770,   771,   772,
     773,   774,   775,   776,   777,   780,   781,   782,   783,   784,
     785,   786,   787,   788,   791,   792,   793,   796,   797,   798,
     799,   800,   801,   804,   805,   809,   810,   811,   812,   813,
     814,   815,   816,   817,   821,   822,   823,   824,   827,   828,
     831,   832,   835,   836,   842,   846,   847,   850,   851,   856,
     859,   863,   867,   872,   876,   881,   885,   889,   890,   891,
     894,   895,   898,   899,   904,   905,   906,   907,   908,   909,
     911,   912,   913,   914,   915,   916,   917,   918,   919,   920,
     921,   922,   923,   927,   928,   929,   930,   931,   932,   933,
     934,   935,   936,   937,   938,   939,   940,   941,   942,   943,
     944,   945,   946,   948,   949,   950,   951,   952,   953,   954,
     955,   956,   957,   959,   960,   963,   964,   965,   968,   969,
     972,   973,   974,   977,   978,   980,   985,   988,   990,   998,
    1002,  1006,  1007,  1008,  1009,  1012,  1013,  1016,  1017,  1020,
    1021,  1025,  1028,  1033,  1034,  1035,  1042,  1045,  1049,  1053,
    1054,  1057,  1058,  1062,  1065,  1069,  1070,  1071,  1072,  1075,
    1076,  1077,  1081,  1084,  1085,  1092,  1095,  1096,  1101,  1104,
    1110,  1111,  1114,  1115,  1116,  1117,  1118,  1121,  1121,  1124,
    1125,  1128,  1129,  1133,  1134,  1135,  1136,  1139,  1143,  1148,
    1151,  1154,  1157,  1162,  1165,  1166,  1167,  1168,  1169,  1170,
    1171,  1172,  1173,  1174,  1175,  1176,  1177,  1178,  1179,  1180,
    1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,  1190,
    1191,  1193,  1197,  1198,  1201,  1202,  1205,  1206,  1208,  1209,
    1212,  1213,  1214,  1217,  1220,  1222,  1227,  1231,  1236,  1237,
    1238,  1239,  1243,  1244,  1247,  1248,  1251,  1254,  1257,  1258
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
  "FSUM", "FAVG", "FMIN", "FMAX", "TO_CHAR", "';'", "','", "'('", "')'",
  "'.'", "$accept", "stmt_list", "stmt", "select_stmt", "opt_where",
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
  "drop_table_stmt", "table_list", "opt_rc", "drop_projection_stmt",
  "truncate_table_stmt", "insert_stmt", "opt_ondupupdate", "insert_opts",
  "opt_into", "opt_col_names", "insert_vals_list", "insert_vals",
  "insert_asgn_list", "show_stmt", "opt_full", "opt_from",
  "opt_like_string", "opt_like_expr", "opt_bdb", "opt_trans_level",
  "delete_stmt", "delete_opts", "delete_list", "opt_dot_star",
  "update_stmt", "update_set_list", YY_NULL
};
#endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short int yyr1[] =
{
       0,   343,   344,   344,   344,   344,   345,   346,   346,   347,
     347,   348,   348,   349,   349,   350,   350,   350,   351,   351,
     352,   352,   353,   353,   354,   354,   355,   355,   355,   356,
     356,   356,   357,   357,   358,   358,   358,   358,   358,   359,
     359,   360,   360,   360,   361,   362,   362,   363,   363,   364,
     364,   364,   364,   365,   365,   366,   366,   366,   367,   367,
     367,   367,   367,   368,   368,   368,   369,   369,   370,   370,
     370,   371,   371,   371,   371,   372,   372,   373,   373,   374,
     375,   375,   375,   375,   375,   375,   375,   375,   375,   375,
     375,   375,   375,   375,   375,   375,   375,   375,   375,   375,
     375,   375,   375,   375,   375,   375,   375,   375,   375,   375,
     375,   375,   375,   375,   375,   375,   375,   376,   376,   376,
     377,   377,   375,   375,   375,   375,   375,   375,   375,   375,
     375,   375,   375,   375,   375,   375,   375,   375,   375,   375,
     375,   375,   375,   375,   375,   375,   375,   375,   375,   375,
     375,   375,   375,   375,   378,   378,   378,   379,   379,   379,
     379,   379,   379,   375,   375,   380,   380,   380,   380,   380,
     380,   380,   380,   380,   375,   375,   375,   375,   381,   381,
     375,   375,   375,   375,   345,   382,   382,   383,   383,   345,
     384,   384,   384,   384,   384,   384,   385,   386,   386,   386,
     387,   387,   388,   388,   389,   389,   389,   389,   389,   389,
     390,   390,   390,   390,   390,   390,   390,   390,   390,   390,
     390,   390,   390,   391,   391,   391,   391,   391,   391,   391,
     391,   391,   391,   391,   391,   391,   391,   391,   391,   391,
     391,   391,   391,   391,   391,   391,   391,   391,   391,   391,
     391,   391,   391,   392,   392,   393,   393,   393,   394,   394,
     395,   395,   395,   396,   396,   396,   345,   397,   397,   345,
     398,   399,   399,   399,   399,   400,   400,   401,   401,   402,
     402,   345,   403,   403,   403,   403,   345,   404,   345,   405,
     405,   406,   406,   345,   407,   408,   408,   408,   408,   409,
     409,   409,   345,   410,   410,   345,   411,   411,   345,   412,
     413,   413,   414,   414,   414,   414,   414,   415,   415,   416,
     416,   417,   417,   418,   418,   418,   418,   412,   412,   419,
     419,   419,   419,   345,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   421,   422,   422,   423,   423,   424,   424,   425,   425,
     426,   426,   426,   345,   345,   427,   427,   427,   428,   428,
     428,   428,   429,   429,   430,   430,   345,   431,   432,   432
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
       4,     4,     4,     4,     4,     6,     6,     8,     8,     4,
       7,     4,     6,     4,     1,     1,     1,     0,     1,     1,
       1,     1,     1,     6,     6,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     6,     3,     5,     4,     5,
       3,     4,     3,     4,     1,     4,     4,     0,     3,     1,
       8,    10,     9,     6,    11,     8,     3,     0,     1,     1,
       0,     1,     1,     3,     3,     5,     4,     4,     5,     5,
       0,     3,     2,     3,     3,     3,     3,     2,     3,     3,
       2,     3,     5,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     3,
       3,     2,     4,     1,     1,     1,     1,     3,     3,     3,
       3,     5,     5,     1,     3,     0,     3,     5,     0,     1,
       0,     2,     2,     0,     4,     3,     1,    10,    13,     1,
      10,     0,     1,     1,     1,     0,     2,     1,     1,     3,
       5,     1,    12,     9,     9,    12,     1,     5,     1,     4,
       4,     0,     2,     1,     6,     1,     3,     3,     5,     0,
       1,     1,     1,     4,     5,     1,     3,     5,     1,     8,
       0,     5,     0,     2,     2,     2,     2,     1,     0,     0,
       3,     3,     5,     1,     1,     3,     3,     7,     7,     3,
       3,     5,     5,     1,     5,     3,     7,     4,     4,     4,
       3,     3,     4,     4,     3,     3,     3,     4,     5,     3,
       3,     5,     2,     3,     4,     5,     4,     4,     4,     3,
       3,     0,     0,     2,     0,     2,     0,     2,     0,     1,
       0,     1,     1,     2,     1,     7,     7,     6,     2,     2,
       2,     0,     2,     4,     0,     2,     1,     5,     3,     5
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0
};

/* YYDEFACT[S] -- default reduction number in state S.  Performed when
   YYTABLE doesn't specify something else to do.  Zero means the default
   is an error.  */
static const unsigned short int yydefact[] =
{
       0,     0,     0,   200,   381,     0,   200,   312,     0,    34,
     361,     0,     0,     0,     0,     6,   184,   189,   266,   269,
     281,   286,   288,   293,   302,   305,   308,   333,   374,   386,
       4,     0,   187,   273,     0,   187,   274,   201,   272,     0,
       0,     0,   373,   291,     0,     0,   291,     0,   318,     0,
      37,    35,     0,    80,    84,    85,    87,    86,    81,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     371,   372,   352,     0,   364,     0,     0,    26,     0,     0,
     362,    26,   369,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    57,     0,     0,    53,     0,     0,     1,     0,
       0,     2,     0,     0,     0,     0,     0,   187,     0,   384,
       0,   380,   378,   379,     0,     0,     0,     0,     0,     0,
       0,   291,   314,   315,   316,   317,   313,     0,     0,     0,
      38,    39,    43,     7,    41,    57,     0,     0,   108,     0,
     109,    95,    94,     0,     0,     0,     0,     0,     0,   340,
       0,     0,   341,   362,   364,     0,   335,     0,   344,     0,
     345,     0,   349,     0,   366,   359,   362,     0,     0,     0,
       0,    34,     0,     0,     0,    34,    34,    34,    34,    34,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   346,   360,   362,     0,   353,   350,   364,
     364,    56,     0,     0,    49,     0,     0,    45,    47,    48,
       0,    54,     0,     0,   295,   306,     5,     3,     0,     0,
     185,     0,   186,     0,   275,     0,   382,    57,     9,     0,
       0,     0,   292,   289,     0,     0,   303,   290,     0,   319,
       0,     0,     0,     0,     0,     0,    44,    82,    83,   110,
       0,     0,     0,     0,   176,     0,   337,   338,   339,     0,
     362,   364,   356,   365,   342,   343,    27,   347,   363,     0,
     357,   364,     0,   156,   154,   155,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   111,
       0,    97,    98,    96,   182,   180,   114,     0,   112,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    99,   104,
     105,   107,    88,    89,    90,    91,    93,    92,   106,   364,
       0,   354,   358,    55,    57,    79,    52,    65,    70,    64,
      68,    74,    69,     0,     0,     0,    66,     0,     9,    51,
       0,     0,     0,     0,   188,     0,   197,     0,     0,   385,
       0,     0,    22,     0,     9,   384,   287,   304,   299,     0,
       0,     0,     0,     0,    40,     0,     0,    42,     0,     0,
       0,   174,     0,     0,   130,   348,   355,     0,   367,   351,
       0,     0,   149,     0,     0,     0,   132,   140,   133,   151,
     157,   153,   141,   134,   142,   135,   143,   136,   144,   137,
     139,   138,   119,   118,     0,     0,   115,   113,     0,     0,
     183,   181,     0,     0,     0,     0,     0,     0,   334,   362,
      50,    66,    66,    66,     0,    59,    46,     0,    67,     0,
       0,     0,   387,   307,   297,   296,     0,    32,     0,   198,
     199,     0,     0,   193,    53,   277,   278,   276,     0,    10,
       0,    26,     9,   377,   383,   301,   300,   294,     0,   310,
       0,     0,   310,     0,    36,     0,     0,     9,   130,   178,
       0,   177,     0,    28,     0,     0,     0,     0,     0,     0,
     159,   162,   160,   161,   158,     0,     0,     0,   126,   122,
       0,     0,   116,     0,     0,     0,   100,   364,    73,    71,
      72,     0,     0,    75,     0,    99,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   202,   197,     0,
       0,     0,   375,   376,     0,     0,     0,   327,   320,     0,
     310,   328,     0,     0,     0,    11,   175,   179,     0,   146,
       0,   145,     0,     0,   163,   164,   152,     0,   120,     0,
       0,   128,   124,   103,   101,   102,   336,    62,    60,     0,
       0,    58,    76,     0,     0,   298,     0,    33,     0,     0,
     255,   255,   255,   244,   255,   234,   237,   255,   255,     0,
     255,   255,   255,   246,   258,   245,   255,   258,   255,     0,
     255,   258,   235,   236,   243,   255,   258,     0,   255,   238,
     210,     0,     0,     0,     0,     0,   197,     0,     0,   195,
     196,     0,    23,    15,   330,   329,     0,     0,   324,   323,
       0,   309,     0,     0,    30,     0,    20,     0,     0,   150,
     165,   169,   166,   167,   168,   173,   171,   170,   172,   127,
       0,   123,     0,     0,    77,     0,    61,    99,   284,     0,
       0,     0,   260,   241,   223,   263,   260,   260,     0,   260,
     260,   260,   259,   263,   260,   263,   260,     0,   260,   263,
     260,   263,     0,   263,   204,     0,     0,     0,     0,     0,
     192,   203,     0,   255,     0,    16,    17,    24,     0,     0,
       0,     0,   321,   283,     0,     0,     0,    22,   148,   147,
     121,   129,   125,     0,     0,     0,   267,     0,   229,   239,
     233,   231,   253,     0,   232,   227,   228,   250,   226,   249,
     230,     0,   225,   248,   224,   247,     0,   240,     0,   217,
       0,     0,   220,   212,     0,     0,     0,     0,   207,   206,
       0,   197,    15,   270,     0,     0,   332,   331,   326,   325,
       0,     0,     0,    18,    13,    21,    26,    78,     0,     0,
       0,   256,   261,   262,     0,     0,     0,   263,   263,   242,
     211,   221,   213,   214,   216,   215,   219,   218,     0,   208,
     209,   205,   194,   279,    25,   311,   322,     0,    31,     0,
      12,     0,     8,   285,     0,     0,     0,   265,   254,   251,
     252,     0,     0,   282,    19,    14,   268,   257,   264,   222,
     280
};

/* YYPDEFGOTO[NTERM-NUM].  */
static const short int yydefgoto[] =
{
      -1,    13,    14,    15,   382,   656,   783,   717,   820,   727,
     481,   642,   170,   264,   468,    52,   140,   143,   144,   226,
     227,   228,   232,   224,   229,   365,   459,   366,   454,   591,
     592,   105,   305,   192,   579,   297,   515,   508,   155,    16,
     114,    17,   473,   474,    39,   546,   547,   704,   630,   743,
     682,   693,   738,   739,    18,    19,    40,   378,   477,   714,
      20,    21,    22,   126,    23,   235,   487,    24,    25,    26,
     557,    48,   137,   391,   560,   650,   489,    27,    99,   174,
     166,   290,   100,   101,    28,    41,   124,   246,    29,   368
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -577
static const short int yypact[] =
{
    2051,  -294,  -157,   276,  -577,   115,   162,  -577,   -76,    96,
     750,    -2,   -59,  2053,  -174,  -577,  -577,  -577,  -577,  -577,
    -577,  -577,  -577,  -577,  -577,  -577,  -577,  -577,  -577,  -577,
    -577,   211,   119,  -577,    84,   119,  -577,  -577,  -577,    54,
     129,    43,  -577,   140,   273,    34,   140,    66,   247,   283,
    -577,   458,   800,   -49,  -577,  -577,  -577,  -577,   295,  1258,
    1281,  1258,  1258,  1012,   -33,   293,    -3,   218,   336,    47,
    -577,  -577,  -577,   158,   342,   358,    60,   226,   262,    68,
     263,   226,  -577,    91,    32,    36,    38,    39,    41,    42,
      46,    48,    52,    53,    58,    75,    76,  1357,   416,   -74,
      88,   -90,     9,    12,   177,   360,   413,   419,  -577,    85,
      86,  -577,   318,   429,   446,   452,   453,   119,   454,   116,
       2,  -577,  -577,  -577,   -97,   361,   465,   310,   363,   468,
     470,   140,  -577,  -577,  -577,  -577,  -577,   471,   370,   139,
    -577,  1869,  -577,   106,   146,  2567,   137,  1258,   546,   148,
     546,  -577,  -577,  1258,  2050,   -35,   483,   486,   487,  -577,
     304,   501,  -577,   263,   342,   509,  -577,  -167,  -577,  1258,
    -577,   506,  -577,   513,   504,  -577,   263,  1258,   646,  1258,
    1258,   530,  1258,  1258,  1357,  1088,  1088,  1088,  1088,  1088,
    1357,    78,   179,  1258,  1258,  1258,  1258,  1258,    59,   183,
     278,  1258,   989,  1258,  1258,  1258,  1258,  1258,  1258,  1258,
    1258,  1258,  1258,  -577,  -577,   263,   417,  -577,  -577,   342,
     342,  -577,   522,   524,  -577,   187,   189,   351,  -577,  -577,
    1258,  -577,   528,   425,  -127,  -577,  -577,  -577,  1357,   441,
    -577,   202,  -577,   540,   311,   519,  -577,    15,   306,  -211,
      -2,   548,  -577,  -577,   550,   556,  -577,  -577,   419,  -175,
    1357,  1258,  1258,    -2,   455,   800,  -577,  -577,  -577,  2646,
     304,  2212,   -14,  1258,  -577,  1258,  -577,  -577,  -577,   220,
     263,   342,  -577,  -577,  -577,  -577,  1890,  -577,  -577,  1258,
    -577,   342,  1848,  -577,  -577,  -577,  1373,  1258,  1911,  1957,
     236,   237,  1419,  1612,  2597,  1978,   239,   241,  1633,   242,
    1697,   244,  1718,   245,  1743,   252,  1764,   274,  1357,  -577,
     131,  2137,  2388,  1467,  2706,  2706,  -577,    31,  -577,  1139,
    1258,  1258,   279,  2619,   281,   282,   285,  1139,   705,   383,
     813,   674,   604,   604,   588,   588,   588,   588,  -577,   342,
     623,  -577,  -577,  -577,   112,  -577,  -577,  -577,  -577,  -577,
    -577,   -53,  -577,    -2,    -2,   497,   482,  2667,  -219,  -577,
     652,   419,   653,   420,  -577,   659,  -105,   -50,   510,  -577,
     204,  1258,   508,    -2,   306,   116,  -577,  -577,    26,   662,
     659,   -83,   422,   332,  -577,   -22,    -2,  -577,   333,  1258,
    1258,  -577,  2467,  2321,  -577,  -577,  -577,  1258,  2646,  -577,
    1258,  1258,  -577,  2369,   549,   549,  -577,  -577,  -577,  -577,
     270,  -577,  -577,  -577,  -577,  -577,  -577,  -577,  -577,  -577,
    -577,  -577,   131,  -577,   335,   663,  -577,  -577,   337,   340,
    2706,  2706,  1139,  1258,   304,   304,   304,   341,  -577,   263,
    -577,   482,   482,   482,   554,   526,  -577,    -2,  -577,   557,
     989,  1258,  -577,  -577,  -577,   347,   685,   355,   365,  -577,
    -577,    35,   710,  -577,   360,  -577,  -577,  -577,   714,  2646,
     660,   226,   306,  -577,  -577,  -577,  -577,  -577,   698,  -136,
     381,   384,   564,   732,  -577,   717,   579,   306,   584,  2646,
    2488,  -577,  1258,  2646,   287,   933,  1258,  1258,   399,   400,
    -577,  -577,  -577,  -577,  -577,   401,  1139,   404,  -577,  -577,
     405,   406,   616,   408,   409,   410,  -577,   342,  -577,  -577,
    -577,    -2,  1258,  -119,    -2,     5,  2688,   419,   421,   659,
      51,  2227,     3,   412,   423,   630,   424,   427,  -102,   304,
     430,  1258,  -577,  -577,  1174,   602,   766,  -577,  -577,  1197,
     564,  -577,   432,   768,   773,   666,  -577,  2646,  1258,  -577,
    1258,  -577,  1785,  2191,  -577,  -577,  -577,   437,   440,   449,
    1139,  -577,  -577,  -577,  -577,  -577,  -577,  -577,  2646,  1258,
     456,  -577,  -577,   -73,   989,  -577,   777,  -577,   779,   641,
     469,   469,   469,  -577,   469,  -577,  -577,   469,   469,   473,
     469,   469,   469,  -577,   770,  -577,   469,   770,   469,   475,
     469,   770,  -577,  -577,  -577,   469,   770,   476,   469,  -577,
    -577,   480,   481,   659,   659,   489,   -98,    35,    35,  -577,
    -577,   807,  -577,  2522,  -577,  2646,   691,   803,   492,  1999,
     493,  -577,   840,   677,  -577,   798,   735,  1806,  1827,  -577,
    -577,  -577,  -577,  -577,  -577,  -577,  -577,  -577,  -577,  -577,
    1357,  -577,   507,   511,  2646,   659,  -577,    45,   672,   845,
     850,   863,  -577,  -577,  -577,  -577,  -577,  -577,   868,  -577,
    -577,  -577,  -577,  -577,  -577,  -577,  -577,   868,  -577,  -577,
    -577,  -577,   870,  -577,   323,   659,   659,   536,   537,   659,
    -577,  -577,   544,   469,   545,  -577,  -577,   542,   657,  1228,
    1197,  1197,   552,   704,   736,  1258,  1258,   508,  -577,  -577,
    -577,  -577,  -577,   555,   878,   733,  -577,   -85,    14,   172,
      14,    14,  -577,   -64,    14,    14,    14,   172,    14,   172,
      14,   -15,    14,   172,    14,   172,   561,   172,   746,  -577,
     900,   255,  -577,  -577,   774,  -114,   565,   566,  -577,  -577,
     575,   -71,    74,  -577,  1258,   662,  -577,  2646,  -577,  -577,
     384,   906,   924,   682,  2021,  2646,   226,  -577,   922,   771,
     926,  -577,  -577,  -577,   737,   929,   931,  -577,  -577,  -577,
    -577,  -577,  -577,  -577,  -577,  -577,  -577,  -577,   659,  -577,
    -577,  -577,  -577,   594,  -577,   597,  -577,   930,  -577,   749,
    -577,  1258,  -577,  -577,   936,   599,   939,  -577,  -577,   172,
     172,   609,   807,  -577,  -577,  -577,  -577,  -577,  -577,  -577,
    -577
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -577,  -577,   952,   -96,  -258,  -577,   145,   195,  -577,  -577,
     251,   194,   -79,  -577,  -387,   314,    69,   719,  -577,  -111,
    -577,    -5,   495,  -126,  -577,  -577,  -169,  -577,  -577,  -577,
     394,  -577,   -10,  -176,   319,  -577,  -577,   573,   836,  -577,
      28,  -577,  -527,  -577,   985,  -305,  -577,  -577,  -577,   301,
     272,  -348,  -179,  -576,  -577,  -577,  -577,  -577,  -577,   167,
    -577,  -577,  -577,    -1,  -577,  -247,  -577,  -577,  -577,  -577,
    -412,  -577,  -577,  -577,   221,  -385,   225,  -577,  -577,  -120,
    -160,  -577,  -577,  -577,  -577,  -577,   882,   618,  -577,  -577
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -390
static const short int yytable[] =
{
      98,   102,   175,   490,   282,   247,   104,   225,   306,   248,
     250,   388,   221,   469,   317,   102,   469,   807,   221,   266,
     469,   639,   389,   555,   383,   381,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   156,   436,   541,   128,
     589,   141,   145,   281,    30,   130,   119,   469,   222,   148,
     150,   151,   152,   154,   222,   451,   291,    31,   273,   351,
     352,   274,   373,   116,   279,   326,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   485,   327,   470,   400,
     561,   470,   401,   452,   392,   470,   589,   191,   193,   194,
     195,   196,   197,   198,   199,   349,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   710,
     462,     9,   470,   106,   715,   221,   590,   747,    42,   749,
     461,   406,   631,   753,   464,   755,   483,   757,   251,    50,
     258,   409,   284,   285,   632,   453,   495,   269,    49,   384,
     267,   129,   433,   271,   542,   243,   496,   434,   651,   435,
     120,   222,   597,   439,   543,   107,   491,   716,   157,   286,
     405,   121,   590,   268,   111,   390,   544,   292,   296,   298,
     299,   302,   303,   304,   398,   308,   310,   312,   314,   316,
     191,   158,    51,   321,   322,   323,   324,   325,   437,   448,
     122,   333,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   556,   215,   545,     9,   354,   275,   598,
     219,   486,   371,   -29,   112,   372,   328,   123,   220,   599,
     367,   829,   830,   216,   553,   794,   808,   795,   450,   275,
     379,    43,   217,   438,   263,   471,   113,   472,   638,   565,
    -190,   447,   251,   115,   812,   792,   707,   708,   118,  -388,
    -384,   141,   141,   456,   790,   145,   791,   125,   395,   802,
     803,   804,   805,   402,   793,   403,   521,  -191,   117,   695,
     475,   476,   482,   699,   510,   796,   127,   797,   701,   408,
     131,    44,   528,   529,   530,   497,   138,   413,   733,  -389,
     595,   330,   331,   146,   332,   492,   159,   193,   194,   195,
     196,   197,   198,   199,   147,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   766,   767,
     440,   441,   770,   511,   796,   161,   798,   191,   132,   527,
     393,   394,   711,   712,    45,   778,   779,   160,   103,   162,
     578,   758,   103,  -388,  -388,    32,   520,   163,   523,   524,
     525,   223,   103,    46,   -57,   164,   165,   380,   455,   512,
     133,   167,   168,   169,   759,   134,   171,   586,   172,   176,
     173,   479,   177,   513,   230,   135,   178,    37,   179,   180,
     760,   181,   182,  -389,  -389,    33,   183,   218,   184,   499,
     500,   568,   185,   186,   136,  -271,   514,   503,   187,   231,
     504,   505,   552,   761,   673,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   357,   188,   189,   318,   233,   319,
     577,   831,   234,   236,   237,   238,   193,   194,   195,   196,
     197,   198,   199,   522,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   239,    34,   240,
     535,   536,   533,   640,   762,   241,   242,   244,   245,   358,
     252,    53,    54,    55,    56,    57,    58,    35,   253,   254,
     255,   256,   359,   257,   259,    59,    60,   260,    36,   261,
     763,   -63,    61,    62,   672,   265,   276,   360,   270,   277,
     278,    37,   567,   764,   578,   301,   572,   573,     9,   307,
     309,   311,   313,   315,   280,    38,   361,   740,   741,    63,
     744,   745,   746,   283,   287,   748,   288,   750,   289,   752,
     320,   754,   588,   329,   350,   353,   587,   354,   355,   593,
     356,   369,   370,    53,    54,    55,    56,    57,    58,   362,
     374,   643,   375,   376,   645,   379,   377,    59,    60,   649,
     381,   385,   765,   386,    61,    62,   300,    66,   657,   387,
     658,   404,   396,    50,   363,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   416,   417,   674,
     421,    63,   422,   424,   677,   426,   428,  -130,  -130,  -130,
    -130,  -130,  -130,   430,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,   432,    51,   139,   212,   442,
    -130,   444,   445,  -130,  -130,   446,   449,   457,   569,    66,
     208,   209,   210,   211,   212,  -130,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,  -130,   458,    53,
      54,    55,    56,    57,    58,   463,   465,  -130,  -130,  -130,
    -130,  -130,   467,    59,    60,   488,   466,  -130,   493,   478,
      61,    62,   480,   494,   498,   516,   507,  -130,   518,   517,
    -130,   519,   526,  -130,   531,   532,   537,   534,  -130,   538,
     364,  -130,  -130,   293,   539,  -130,  -130,    63,   206,   207,
     208,   209,   210,   211,   212,  -130,   540,   822,   551,   777,
     649,   649,  -130,   548,  -130,   784,   785,   550,   554,   213,
    -130,  -130,   558,   555,   559,   214,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   562,   563,   564,  -130,
     574,   575,   576,  -130,   580,    66,   581,   582,  -130,   583,
     584,   585,   633,    53,    54,    55,    56,    57,    58,  -130,
     596,   635,   646,   634,   643,   636,   637,    59,    60,   647,
     641,   652,  -130,   653,    61,    62,   654,   655,   669,   670,
     294,   678,    84,    85,    86,    87,    88,    89,    90,    91,
     671,    92,    93,    94,    95,    96,   675,  -130,    97,   679,
     680,    63,  -130,    53,    54,    55,    56,    57,    58,   681,
     713,   784,    64,   688,   692,   697,   702,    59,    60,    65,
     705,   706,   718,   719,    61,    62,   142,  -130,  -130,   709,
    -130,   720,  -130,  -130,   722,  -130,   205,   206,   207,   208,
     209,   210,   211,   212,   723,   724,   725,   726,   731,    66,
     735,    63,   732,   736,    84,    85,    86,    87,    88,    89,
      90,    91,   734,    92,    93,    94,    95,    96,   737,    67,
      97,   295,   742,   683,   684,   756,   685,   768,   769,   686,
     687,   774,   689,   690,   691,   771,   773,  -130,   694,   775,
     696,   780,   698,  -130,   781,   782,   787,   700,   788,    66,
     703,   789,   799,   800,   801,   806,   809,   810,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,  -130,   811,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,  -130,   817,   818,   819,   823,
     824,   825,   827,   832,   826,   828,   556,   833,   834,   836,
     837,    68,   838,   193,   194,   195,   196,   197,   198,   199,
     839,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,    69,   110,   835,   813,   814,   549,
      84,    85,    86,    87,    88,    89,    90,    91,   786,    92,
      93,    94,    95,    96,   397,   772,    97,   676,   509,   730,
     272,    47,    53,    54,    55,    56,    57,    58,   751,   840,
     815,   816,   249,   484,     0,     0,    59,    60,     0,     0,
       0,     0,     0,    61,    62,    53,    54,    55,    56,    57,
      58,     0,   334,     0,     0,     0,   335,     0,     0,    59,
      60,    70,    71,     0,     0,     0,    61,    62,     0,    72,
      63,     0,     0,     0,     0,    73,    74,     0,    75,  -368,
    -370,    76,     0,    77,    78,    79,     0,    80,  -370,    81,
       0,     0,     0,    63,     0,     0,     0,     0,     0,     0,
       0,     0,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,     0,    92,    93,    94,    95,    96,    66,     0,
      97,    53,    54,    55,    56,    57,    58,     0,     0,     0,
       0,     0,     0,     0,     0,    59,    60,     0,     0,     0,
       0,    66,    61,    62,     0,     0,     0,     0,     0,     0,
       0,    50,     0,     0,    84,    85,    86,    87,    88,    89,
      90,    91,     0,    92,    93,    94,    95,    96,     0,    63,
      97,     0,    53,    54,    55,    56,    57,    58,     0,     0,
       0,     0,     0,     0,     0,     0,    59,    60,     0,     0,
       0,     0,     0,    61,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    51,     0,     0,    53,    54,    55,
      56,    57,    58,     0,     0,     0,     0,    66,     0,   336,
      63,    59,    60,     0,     0,     0,     0,     0,    61,    62,
      53,    54,    55,    56,    57,    58,     0,     0,     0,     0,
       0,     0,     0,     0,    59,    60,     0,     0,     0,     0,
       0,    61,    62,     0,     0,    63,     0,     0,     0,     0,
       0,    53,    54,    55,    56,    57,    58,     0,    66,     0,
       0,     0,     0,     0,     0,    59,    60,     0,    63,     0,
       0,     0,    61,    62,   644,   153,     0,     0,     0,     0,
       0,    53,    54,    55,    56,    57,    58,     0,     0,     0,
       0,     0,   570,    66,   571,    59,    60,   648,     0,    63,
       0,     0,    61,    62,    53,    54,    55,    56,    57,    58,
       0,     0,     0,     0,     0,     0,    66,     0,    59,    60,
       0,     0,     0,     0,     0,    61,    62,     0,   776,    63,
       0,     0,     0,    84,    85,    86,    87,    88,    89,    90,
      91,     0,    92,    93,    94,    95,    96,    66,     0,   337,
       0,     0,    63,     9,     0,     0,    84,    85,    86,    87,
      88,    89,    90,    91,     0,    92,    93,    94,    95,    96,
       0,     0,    97,     0,     0,     0,     0,    66,     0,     0,
      53,    54,    55,    56,    57,    58,     0,     0,     0,     0,
       0,     0,     0,     0,    59,    60,     0,     0,     0,     0,
     149,    61,    62,   193,   194,   195,   196,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,     0,     0,     0,     0,    63,     0,
       0,     0,    84,    85,    86,    87,    88,    89,    90,    91,
       0,    92,    93,    94,    95,    96,     0,     0,    97,   193,
     194,   195,   196,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
       0,     0,     0,     0,     0,     0,    66,     0,     0,     0,
       0,     0,     0,    84,    85,    86,    87,    88,    89,    90,
      91,     0,    92,    93,    94,    95,    96,     0,     0,   190,
     196,   197,   198,   199,     0,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    84,    85,
      86,    87,    88,    89,    90,    91,     0,    92,    93,    94,
      95,    96,     0,     0,    97,     0,     0,     0,     0,     0,
       0,    84,    85,    86,    87,    88,    89,    90,    91,     0,
      92,    93,    94,    95,    96,     0,     0,    97,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84,    85,    86,    87,    88,    89,    90,    91,
       0,    92,    93,    94,    95,    96,     0,     0,    97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84,    85,    86,    87,    88,    89,    90,    91,
       0,    92,    93,    94,    95,    96,     0,     0,    97,     0,
       0,     0,     0,     0,     0,    84,    85,    86,    87,    88,
      89,    90,    91,     0,    92,    93,    94,    95,    96,     0,
       0,    97,   193,   194,   195,   196,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   193,   194,   195,   196,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,    85,    86,    87,    88,    89,    90,    91,     0,
      92,    93,    94,    95,    96,     0,     0,   190,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   193,   194,   195,
     196,   197,   198,   199,   412,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   193,   194,
     195,   196,   197,   198,   199,     0,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,     0,
       0,     0,     0,   193,   194,   195,   196,   197,   198,   199,
     418,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   193,   194,   195,   196,   197,   198,
     199,     0,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   193,   194,   195,   196,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   193,   194,   195,   196,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   193,   194,   195,
     196,   197,   198,   199,     0,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   193,   194,
     195,   196,   197,   198,   199,     0,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   193,
     194,   195,   196,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     193,   194,   195,   196,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   193,   194,   195,   196,   197,   198,   199,     0,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   419,     0,   410,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   193,   194,   195,
     196,   197,   198,   199,   423,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   193,   194,
     195,   196,   197,   198,   199,     0,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   193,
     194,   195,   196,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
       0,   193,   194,   195,   196,   197,   198,   199,   425,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,     1,   108,   109,     0,     0,     0,     0,   427,
     193,   194,   195,   196,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,     0,     0,     0,   429,     0,     0,     0,     0,     2,
       0,     2,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   431,     0,     0,     0,     0,
       0,     0,     0,     3,     0,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   659,     0,     0,     0,
       0,     0,     0,     4,     5,     4,     5,     0,     0,     0,
       0,     6,     0,     6,     0,     0,     0,   728,   194,   195,
     196,   197,   198,   199,     0,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   729,     0,
       0,     0,     0,     0,     0,     7,     0,     7,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   411,     0,     0,
       8,     0,     8,     0,     0,     0,     0,     0,     0,     0,
       0,   193,   194,   195,   196,   197,   198,   199,   262,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   193,   194,   195,   196,   197,   198,   199,   407,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,     0,     0,     9,     0,     9,     0,    10,
     414,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   660,   661,   662,   663,   664,     0,
     600,   601,   602,   603,     0,     0,     0,     0,     0,     0,
     604,     0,     0,    11,     0,    11,     0,     0,     0,     0,
       0,     0,     0,   153,     0,     0,   415,     0,   605,   606,
       0,     0,     0,     0,     0,   607,     0,     0,     0,    12,
       0,    12,     0,     0,     0,     0,   608,   318,     0,     0,
       0,     0,     0,     0,   609,     0,     0,     0,     0,     0,
     610,   193,   194,   195,   196,   197,   198,   199,   721,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   611,   612,     0,     0,     0,     0,     0,     0,
     821,     0,     0,     0,     0,     0,   665,     0,     0,     0,
       0,   613,   614,     0,     0,     0,   615,   616,   617,   193,
     194,   195,   196,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     195,   196,   197,   198,   199,   618,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,     0,
       0,     0,     0,     0,   619,     0,   620,     0,     0,     0,
     399,     0,     0,     0,     0,     0,     0,     0,     0,   666,
     667,     0,   668,   621,     0,     0,   622,   623,   624,   625,
     626,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   627,   628,     0,
       0,     0,     0,     0,     0,   629,   506,   193,   194,   195,
     196,   197,   198,   199,     0,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   193,   194,
     195,   196,   197,   198,   199,     0,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   193,   194,   195,   196,   197,   198,   199,   502,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   715,   501,     0,     0,     0,     0,     0,     0,
     221,     0,     0,     0,     0,     0,     0,   193,   194,   195,
     196,   197,   198,   199,   566,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,     0,     0,
       0,     0,     0,     0,     0,   716,   222,   193,   194,   195,
     196,   197,   198,   199,     0,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,     0,   193,
     194,   195,   196,   197,   198,   199,   420,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
       0,     0,     0,     0,     0,   443,   193,   194,   195,   196,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   193,   194,   195,
     196,   197,   198,   199,     0,   200,   201,   460,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   193,   194,
     195,   196,   197,   198,   199,     0,   200,   201,   594,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,  -390,
    -390,  -390,  -390,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212
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
     235,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    61,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     3,     5,     7,     9,    11,     0,     0,     0,
       0,     0,     0,     0,     0,    13,    15,     0,     0,     0,
       0,     0,    17,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    69,    71,    73,
      75,    77,    79,     0,    81,    83,    85,    87,    89,    91,
      93,    95,    97,    99,   101,   103,   105,   107,   109,   111,
     113,   115,   117,   119,   121,     0,     0,     0,     0,     0,
     123,     0,     0,   125,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   131,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   133,   135,   137,
     139,   141,     0,     0,     0,     0,     0,   143,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   145,     0,     0,
     147,     0,     0,   149,     0,    67,     0,     0,   151,     0,
       0,   153,   155,     0,     0,   157,   159,     0,     0,     0,
       0,     0,     0,     0,     0,   161,     0,     0,     0,     0,
       0,     0,   163,     0,   165,     0,     0,     0,     0,     0,
     167,   169,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   171,
       0,     0,     0,   173,     0,     0,     0,     0,   175,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   177,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   179,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    27,    29,    31,    33,    35,    37,    39,
       0,    41,    43,    45,    47,    49,     0,   181,    51,     0,
       0,     0,   183,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   185,   187,     0,
     189,     0,   191,   193,     0,   195,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   197,     0,     0,
       0,     0,     0,   199,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   201,   203,
     205,   207,   209,   211,   213,   215,     0,   217,   219,   221,
     223,   225,   227,   229,   231,   233,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,    53,     0,     0,
       0,     0,     0,    55,    57,    59,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,    65,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0
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
       0,    35,     0,    39,     0,    39,     0,    39,     0,    39,
       0,   117,     0,   384,     0,   117,     0,    59,     0,   131,
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
       0,   131,     0,   131,     0,    75,     0
};

static const short int yycheck[] =
{
      10,     3,    81,   390,   164,     3,    11,   103,   184,   120,
     107,   258,     3,   118,   190,     3,   118,   131,     3,   145,
     118,   548,   197,   159,   235,   244,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    69,     6,     3,     5,
     159,    51,    52,   163,   338,    46,     3,   118,    39,    59,
      60,    61,    62,    63,    39,   108,   176,   214,    93,   219,
     220,    96,   238,    35,   160,     6,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    50,    18,   183,    93,
     492,   183,    96,   136,   260,   183,   159,    97,    10,    11,
      12,    13,    14,    15,    16,   215,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,   636,
     368,   194,   183,   172,    40,     3,   235,   693,     3,   695,
     339,   281,   119,   699,   371,   701,   384,   703,   339,    33,
     131,   291,   299,   300,   131,   188,   158,   147,   214,   250,
       3,   107,   318,   153,   109,   117,   168,    16,   560,    18,
     107,    39,   539,   329,   119,   214,   239,    83,   191,   169,
     280,   118,   235,    26,   338,   340,   131,   177,   178,   179,
     180,   181,   182,   183,   270,   185,   186,   187,   188,   189,
     190,   214,    86,   193,   194,   195,   196,   197,   157,   349,
     147,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   339,   278,   170,   194,     3,   243,   158,
     300,   185,   339,   107,     3,   342,   157,   174,   308,   168,
     230,   797,   798,   297,   482,    53,   340,    55,   354,   243,
      26,    69,   306,   329,   128,   340,   117,   342,   340,   497,
     338,   337,   339,   159,   771,   231,   633,   634,   119,   244,
     235,   261,   262,   364,   339,   265,   341,   117,   263,     4,
       5,     6,     7,   273,   250,   275,   442,   338,   214,   617,
     320,   321,   383,   621,     4,   339,     3,   341,   626,   289,
     214,   119,   451,   452,   453,   396,     3,   297,   675,   244,
     537,    13,    14,   342,    16,   391,     3,    10,    11,    12,
      13,    14,    15,    16,     9,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,   705,   706,
     330,   331,   709,    53,   339,   107,   341,   337,    81,   449,
     261,   262,   637,   638,   172,   720,   721,   340,   340,     3,
     516,    18,   340,   338,   339,    69,   442,   300,   444,   445,
     446,   342,   340,   191,   339,   197,    14,   342,   363,    89,
     113,     3,   302,   137,    41,   118,   104,   527,   300,   278,
     107,   381,   340,   103,   197,   128,   340,   215,   340,   340,
      57,   340,   340,   338,   339,   109,   340,   299,   340,   399,
     400,   104,   340,   340,   147,   119,   126,   407,   340,    39,
     410,   411,   481,    80,   580,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    63,   340,   340,   339,     5,   341,
     516,   808,     3,   338,   338,   107,    10,    11,    12,    13,
      14,    15,    16,   443,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    18,   172,     3,
     460,   461,   457,   549,   131,     3,     3,     3,   342,   108,
      99,     3,     4,     5,     6,     7,     8,   191,     3,   159,
     107,     3,   121,     3,     3,    17,    18,   107,   202,   340,
     157,   130,    24,    25,   580,   339,     3,   136,   340,     3,
       3,   215,   502,   170,   670,   181,   506,   507,   194,   185,
     186,   187,   188,   189,     3,   229,   155,   686,   687,    51,
     689,   690,   691,     4,     8,   694,     3,   696,    14,   698,
     341,   700,   532,   340,   107,     3,   531,     3,   341,   534,
     341,     3,   107,     3,     4,     5,     6,     7,     8,   188,
      99,   551,   340,     3,   554,    26,   235,    17,    18,   559,
     244,     3,   229,     3,    24,    25,    26,    99,   568,     3,
     570,   341,   107,    33,   213,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,   341,   341,   589,
     341,    51,   341,   341,   594,   341,   341,     3,     4,     5,
       6,     7,     8,   341,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,   341,    86,   159,    30,   340,
      36,   340,   340,    39,    40,   340,     3,   130,   341,    99,
      26,    27,    28,    29,    30,    51,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    63,   166,     3,
       4,     5,     6,     7,     8,     3,     3,    73,    74,    75,
      76,    77,     3,    17,    18,     3,   246,    83,   246,   159,
      24,    25,   164,   341,   341,   340,   127,    93,   341,    16,
      96,   341,   341,    99,   130,   159,   339,   130,   104,     4,
     339,   107,   108,    47,   339,   111,   112,    51,    24,    25,
      26,    27,    28,    29,    30,   121,   341,   786,    48,   719,
     720,   721,   128,     3,   130,   725,   726,     3,    20,   303,
     136,   137,   341,   159,   340,   309,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,     4,    20,   159,   155,
     341,   341,   341,   159,   340,    99,   341,   341,   164,   341,
     341,   341,   340,     3,     4,     5,     6,     7,     8,   175,
     339,   131,   160,   340,   774,   341,   339,    17,    18,     3,
     340,   339,   188,     5,    24,    25,     3,   111,   341,   339,
     134,     4,   324,   325,   326,   327,   328,   329,   330,   331,
     341,   333,   334,   335,   336,   337,   340,   213,   340,    20,
     159,    51,   218,     3,     4,     5,     6,     7,     8,   340,
       3,   821,    62,   340,    44,   340,   340,    17,    18,    69,
     340,   340,   131,    20,    24,    25,    26,   243,   244,   340,
     246,   339,   248,   249,   341,   251,    23,    24,    25,    26,
      27,    28,    29,    30,     4,   168,    48,   112,   341,    99,
       5,    51,   341,     3,   324,   325,   326,   327,   328,   329,
     330,   331,   190,   333,   334,   335,   336,   337,     5,   119,
     340,   225,     4,   601,   602,     5,   604,   341,   341,   607,
     608,   339,   610,   611,   612,   341,   341,   303,   616,   232,
     618,   339,   620,   309,   190,   159,   341,   625,    20,    99,
     628,   168,   341,   157,     4,   131,   341,   341,   324,   325,
     326,   327,   328,   329,   330,   331,   341,   333,   334,   335,
     336,   337,   338,   339,   340,   341,    20,     3,   246,     7,
     159,     5,     3,   339,   197,     4,   339,     7,   189,     3,
     341,   191,     3,    10,    11,    12,    13,    14,    15,    16,
     341,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,   214,    13,   821,   772,   774,   474,
     324,   325,   326,   327,   328,   329,   330,   331,   727,   333,
     334,   335,   336,   337,   265,   713,   340,   593,   415,   670,
     154,     6,     3,     4,     5,     6,     7,     8,   697,   832,
     775,   780,   120,   385,    -1,    -1,    17,    18,    -1,    -1,
      -1,    -1,    -1,    24,    25,     3,     4,     5,     6,     7,
       8,    -1,    33,    -1,    -1,    -1,    37,    -1,    -1,    17,
      18,   281,   282,    -1,    -1,    -1,    24,    25,    -1,   289,
      51,    -1,    -1,    -1,    -1,   295,   296,    -1,   298,   299,
     300,   301,    -1,   303,   304,   305,    -1,   307,   308,   309,
      -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,    -1,   333,   334,   335,   336,   337,    99,    -1,
     340,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,
      -1,    99,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    -1,    -1,   324,   325,   326,   327,   328,   329,
     330,   331,    -1,   333,   334,   335,   336,   337,    -1,    51,
     340,    -1,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,
      -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    99,    -1,   200,
      51,    17,    18,    -1,    -1,    -1,    -1,    -1,    24,    25,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,
      -1,    24,    25,    -1,    -1,    51,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    51,    -1,
      -1,    -1,    24,    25,    80,   243,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,   339,    99,   341,    17,    18,    80,    -1,    51,
      -1,    -1,    24,    25,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    17,    18,
      -1,    -1,    -1,    -1,    -1,    24,    25,    -1,    80,    51,
      -1,    -1,    -1,   324,   325,   326,   327,   328,   329,   330,
     331,    -1,   333,   334,   335,   336,   337,    99,    -1,   340,
      -1,    -1,    51,   194,    -1,    -1,   324,   325,   326,   327,
     328,   329,   330,   331,    -1,   333,   334,   335,   336,   337,
      -1,    -1,   340,    -1,    -1,    -1,    -1,    99,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,
      99,    24,    25,    10,    11,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    -1,   324,   325,   326,   327,   328,   329,   330,   331,
      -1,   333,   334,   335,   336,   337,    -1,    -1,   340,    10,
      11,    12,    13,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,   324,   325,   326,   327,   328,   329,   330,
     331,    -1,   333,   334,   335,   336,   337,    -1,    -1,   340,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,   324,   325,
     326,   327,   328,   329,   330,   331,    -1,   333,   334,   335,
     336,   337,    -1,    -1,   340,    -1,    -1,    -1,    -1,    -1,
      -1,   324,   325,   326,   327,   328,   329,   330,   331,    -1,
     333,   334,   335,   336,   337,    -1,    -1,   340,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   324,   325,   326,   327,   328,   329,   330,   331,
      -1,   333,   334,   335,   336,   337,    -1,    -1,   340,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   324,   325,   326,   327,   328,   329,   330,   331,
      -1,   333,   334,   335,   336,   337,    -1,    -1,   340,    -1,
      -1,    -1,    -1,    -1,    -1,   324,   325,   326,   327,   328,
     329,   330,   331,    -1,   333,   334,   335,   336,   337,    -1,
      -1,   340,    10,    11,    12,    13,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    10,    11,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   324,   325,   326,   327,   328,   329,   330,   331,    -1,
     333,   334,   335,   336,   337,    -1,    -1,   340,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,
      13,    14,    15,    16,   341,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    10,    11,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    10,    11,    12,    13,    14,    15,    16,
     341,    18,    19,    20,    21,    22,    23,    24,    25,    26,
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
      22,    23,    24,    25,    26,    27,    28,    29,    30,    10,
      11,    12,    13,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      10,    11,    12,    13,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    10,    11,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   341,    -1,   107,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,
      13,    14,    15,    16,   341,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    10,    11,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    10,
      11,    12,    13,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    10,    11,    12,    13,    14,    15,    16,   341,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,     1,     0,     1,    -1,    -1,    -1,    -1,   341,
      10,    11,    12,    13,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    -1,    -1,    -1,   341,    -1,    -1,    -1,    -1,    38,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   341,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   341,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    83,    82,    83,    -1,    -1,    -1,
      -1,    90,    -1,    90,    -1,    -1,    -1,   341,    11,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,   341,    -1,
      -1,    -1,    -1,    -1,    -1,   124,    -1,   124,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   339,    -1,    -1,
     139,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    10,    11,    12,    13,    14,    15,    16,   339,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    10,    11,    12,    13,    14,    15,    16,   339,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,   194,    -1,   194,    -1,   198,
     339,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,    -1,
      43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    -1,    -1,   232,    -1,   232,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,    -1,    -1,   339,    -1,    71,    72,
      -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,   258,
      -1,   258,    -1,    -1,    -1,    -1,    89,   339,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,
     103,    10,    11,    12,    13,    14,    15,    16,   339,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,   125,   126,    -1,    -1,    -1,    -1,    -1,    -1,
     339,    -1,    -1,    -1,    -1,    -1,   175,    -1,    -1,    -1,
      -1,   144,   145,    -1,    -1,    -1,   149,   150,   151,    10,
      11,    12,    13,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      12,    13,    14,    15,    16,   178,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    -1,   197,    -1,   199,    -1,    -1,    -1,
     218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,
     249,    -1,   251,   216,    -1,    -1,   219,   220,   221,   222,
     223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,   241,    -1,
      -1,    -1,    -1,    -1,    -1,   248,   107,    10,    11,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    10,    11,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    10,    11,    12,    13,    14,    15,    16,   218,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    96,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,
      13,    14,    15,    16,    96,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    39,    10,    11,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,    10,
      11,    12,    13,    14,    15,    16,    39,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    36,    10,    11,    12,    13,
      14,    15,    16,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    10,    11,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    10,    11,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    13,
      14,    15,    16,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short int yystos[] =
{
       0,     1,    38,    62,    82,    83,    90,   124,   139,   194,
     198,   232,   258,   344,   345,   346,   382,   384,   397,   398,
     403,   404,   405,   407,   410,   411,   412,   420,   427,   431,
     338,   214,    69,   109,   172,   191,   202,   215,   229,   387,
     399,   428,     3,    69,   119,   172,   191,   387,   414,   214,
      33,    86,   358,     3,     4,     5,     6,     7,     8,    17,
      18,    24,    25,    51,    62,    69,    99,   119,   191,   214,
     281,   282,   289,   295,   296,   298,   301,   303,   304,   305,
     307,   309,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   333,   334,   335,   336,   337,   340,   375,   421,
     425,   426,     3,   340,   364,   374,   172,   214,     0,     1,
     345,   338,     3,   117,   383,   159,   383,   214,   119,     3,
     107,   118,   147,   174,   429,   117,   406,     3,     5,   107,
     406,   214,    81,   113,   118,   128,   147,   415,     3,   159,
     359,   375,    26,   360,   361,   375,   342,     9,   375,    99,
     375,   375,   375,   243,   375,   381,    69,   191,   214,     3,
     340,   107,     3,   300,   197,    14,   423,     3,   302,   137,
     355,   104,   300,   107,   422,   355,   278,   340,   340,   340,
     340,   340,   340,   340,   340,   340,   340,   340,   340,   340,
     340,   375,   376,    10,    11,    12,    13,    14,    15,    16,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,   303,   309,   278,   297,   306,   299,   300,
     308,     3,    39,   342,   366,   346,   362,   363,   364,   367,
     197,    39,   365,     5,     3,   408,   338,   338,   107,    18,
       3,     3,     3,   383,     3,   342,   430,     3,   362,   429,
     107,   339,    99,     3,   159,   107,     3,     3,   406,     3,
     107,   340,   339,   128,   356,   339,   366,     3,    26,   375,
     340,   375,   381,    93,    96,   243,     3,     3,     3,   346,
       3,   422,   423,     4,   299,   300,   375,     8,     3,    14,
     424,   422,   375,    47,   134,   225,   375,   378,   375,   375,
      26,   358,   375,   375,   375,   375,   376,   358,   375,   358,
     375,   358,   375,   358,   375,   358,   375,   376,   339,   341,
     341,   375,   375,   375,   375,   375,     6,    18,   157,   340,
      13,    14,    16,   375,    33,    37,   200,   340,   375,   375,
     375,   375,   375,   375,   375,   375,   375,   375,   375,   422,
     107,   423,   423,     3,     3,   341,   341,    63,   108,   121,
     136,   155,   188,   213,   339,   368,   370,   375,   432,     3,
     107,   339,   342,   376,    99,   340,     3,   235,   400,    26,
     342,   244,   347,   235,   362,     3,     3,     3,   408,   197,
     340,   416,   376,   359,   359,   364,   107,   360,   346,   218,
      93,    96,   375,   375,   341,   422,   423,   339,   375,   423,
     107,   339,   341,   375,   339,   339,   341,   341,   341,   341,
      39,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   376,    16,    18,     6,   157,   346,   376,
     375,   375,   340,    36,   340,   340,   340,   346,   423,     3,
     366,   108,   136,   188,   371,   364,   362,   130,   166,   369,
      20,   339,   347,     3,   408,     3,   246,     3,   357,   118,
     183,   340,   342,   385,   386,   320,   321,   401,   159,   375,
     164,   353,   362,   347,   430,    50,   185,   409,     3,   419,
     357,   239,   346,   246,   341,   158,   168,   362,   341,   375,
     375,    96,   218,   375,   375,   375,   107,   127,   380,   380,
       4,    53,    89,   103,   126,   379,   340,    16,   341,   341,
     346,   376,   375,   346,   346,   346,   341,   422,   369,   369,
     369,   130,   159,   364,   130,   375,   375,   339,     4,   339,
     341,     3,   109,   119,   131,   170,   388,   389,     3,   365,
       3,    48,   355,   347,    20,   159,   339,   413,   341,   340,
     417,   413,     4,    20,   159,   347,    96,   375,   104,   341,
     339,   341,   375,   375,   341,   341,   341,   346,   376,   377,
     340,   341,   341,   341,   341,   341,   423,   364,   375,   159,
     235,   372,   373,   364,    20,   408,   339,   357,   158,   168,
      43,    44,    45,    46,    53,    71,    72,    78,    89,    97,
     103,   125,   126,   144,   145,   149,   150,   151,   178,   197,
     199,   216,   219,   220,   221,   222,   223,   240,   241,   248,
     391,   119,   131,   340,   340,   131,   341,   339,   340,   385,
     346,   340,   354,   375,    80,   375,   160,     3,    80,   375,
     418,   413,   339,     5,     3,   111,   348,   375,   375,   341,
      73,    74,    75,    76,    77,   175,   248,   249,   251,   341,
     339,   341,   346,   376,   375,   340,   373,   375,     4,    20,
     159,   340,   393,   393,   393,   393,   393,   393,   340,   393,
     393,   393,    44,   394,   393,   394,   393,   340,   393,   394,
     393,   394,   340,   393,   390,   340,   340,   357,   357,   340,
     385,   388,   388,     3,   402,    40,    83,   350,   131,    20,
     339,   339,   341,     4,   168,    48,   112,   352,   341,   341,
     377,   341,   341,   357,   190,     5,     3,     5,   395,   396,
     395,   395,     4,   392,   395,   395,   395,   396,   395,   396,
     395,   392,   395,   396,   395,   396,     5,   396,    18,    41,
      57,    80,   131,   157,   170,   229,   357,   357,   341,   341,
     357,   341,   393,   341,   339,   232,    80,   375,   418,   418,
     339,   190,   159,   349,   375,   375,   353,   341,    20,   168,
     339,   341,   231,   250,    53,    55,   339,   341,   341,   341,
     157,     4,     4,     5,     6,     7,   131,   131,   340,   341,
     341,   341,   385,   350,   354,   419,   417,    20,     3,   246,
     351,   339,   355,     7,   159,     5,   197,     3,     4,   396,
     396,   357,   339,     7,   189,   349,     3,   341,     3,   341,
     402
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
#line 447 "sql.ypp"
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
#line 461 "sql.ypp"
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
#line 474 "sql.ypp"
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
#line 483 "sql.ypp"
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
#line 494 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node);}
    break;

  case 7:
/* Line 868 of glr.c  */
#line 499 "sql.ypp"
    {
		((*yyvalp).ast_node)=new AstSelectStmt(AST_SELECT_STMT, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node),NULL,NULL,NULL,NULL,NULL,NULL,NULL);
	}
    break;

  case 8:
/* Line 868 of glr.c  */
#line 504 "sql.ypp"
    {
		((*yyvalp).ast_node)=new AstSelectStmt(AST_SELECT_STMT, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (11))].yystate.yysemantics.yysval.ast_node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (11))].yystate.yysemantics.yysval.ast_node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (11))].yystate.yysemantics.yysval.ast_node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (11))].yystate.yysemantics.yysval.ast_node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((8) - (11))].yystate.yysemantics.yysval.ast_node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (11))].yystate.yysemantics.yysval.ast_node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((10) - (11))].yystate.yysemantics.yysval.ast_node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((11) - (11))].yystate.yysemantics.yysval.ast_node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (11))].yystate.yysemantics.yysval.ast_node));
	}
    break;

  case 9:
/* Line 868 of glr.c  */
#line 509 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL;}
    break;

  case 10:
/* Line 868 of glr.c  */
#line 510 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstWhereClause(AST_WHERE_CLAUSE, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node));}
    break;

  case 11:
/* Line 868 of glr.c  */
#line 513 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL;}
    break;

  case 12:
/* Line 868 of glr.c  */
#line 514 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstGroupByClause(AST_GROUPBY_CLAUSE, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.intval));}
    break;

  case 13:
/* Line 868 of glr.c  */
#line 519 "sql.ypp"
    { ((*yyvalp).ast_node)=new AstGroupByList(AST_GROUPBY_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 14:
/* Line 868 of glr.c  */
#line 520 "sql.ypp"
    { ((*yyvalp).ast_node)=new AstGroupByList(AST_GROUPBY_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 15:
/* Line 868 of glr.c  */
#line 522 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 16:
/* Line 868 of glr.c  */
#line 523 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 17:
/* Line 868 of glr.c  */
#line 524 "sql.ypp"
    { ((*yyvalp).intval) = 1; }
    break;

  case 18:
/* Line 868 of glr.c  */
#line 527 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 19:
/* Line 868 of glr.c  */
#line 528 "sql.ypp"
    { ((*yyvalp).intval) = 1; }
    break;

  case 20:
/* Line 868 of glr.c  */
#line 531 "sql.ypp"
    { ((*yyvalp).ast_node)=NULL; }
    break;

  case 21:
/* Line 868 of glr.c  */
#line 532 "sql.ypp"
    { ((*yyvalp).ast_node)=new AstHavingClause(AST_HAVING_CLAUSE, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node));	}
    break;

  case 22:
/* Line 868 of glr.c  */
#line 535 "sql.ypp"
    { ((*yyvalp).ast_node)=NULL; }
    break;

  case 23:
/* Line 868 of glr.c  */
#line 536 "sql.ypp"
    { ((*yyvalp).ast_node)=new AstOrderByClause(AST_ORDERBY_CLAUSE, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 24:
/* Line 868 of glr.c  */
#line 539 "sql.ypp"
    { ((*yyvalp).ast_node)=new AstOrderByList(AST_ORDERBY_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.intval), NULL);}
    break;

  case 25:
/* Line 868 of glr.c  */
#line 540 "sql.ypp"
    { ((*yyvalp).ast_node)=new AstOrderByList(AST_ORDERBY_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 26:
/* Line 868 of glr.c  */
#line 542 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 27:
/* Line 868 of glr.c  */
#line 543 "sql.ypp"
    { ((*yyvalp).ast_node)=new AstLimitClause(AST_LIMIT_CLAUSE, NULL,(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node));}
    break;

  case 28:
/* Line 868 of glr.c  */
#line 544 "sql.ypp"
    { ((*yyvalp).ast_node)=new AstLimitClause(AST_LIMIT_CLAUSE, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval.ast_node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.ast_node));}
    break;

  case 29:
/* Line 868 of glr.c  */
#line 547 "sql.ypp"
    { ((*yyvalp).ast_node)=NULL; }
    break;

  case 30:
/* Line 868 of glr.c  */
#line 548 "sql.ypp"
    { ((*yyvalp).ast_node)= new AstSelectIntoClause(AST_SELECT_INTO_CLAUSE, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval.ast_node), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.strval)),1);}
    break;

  case 31:
/* Line 868 of glr.c  */
#line 550 "sql.ypp"
    { 
		if ((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (8))].yystate.yysemantics.yysval.subtok) != 4) { yyerror(result,"please give a specific number"); } 
		else    { ((*yyvalp).ast_node)= new AstSelectIntoClause(AST_SELECT_INTO_CLAUSE, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (8))].yystate.yysemantics.yysval.ast_node), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((8) - (8))].yystate.yysemantics.yysval.strval)),atoi((((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (8))].yystate.yysemantics.yysval.strval))); }
	}
    break;

  case 32:
/* Line 868 of glr.c  */
#line 557 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstColumn(AST_COLUMN, string("NULL"), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.strval)));}
    break;

  case 33:
/* Line 868 of glr.c  */
#line 558 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstColumn(AST_COLUMN, string("NULL"), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node));}
    break;

  case 34:
/* Line 868 of glr.c  */
#line 573 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 35:
/* Line 868 of glr.c  */
#line 574 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDistinctClause(AST_DISTINCT_CLAUSE, NULL, 1); }
    break;

  case 36:
/* Line 868 of glr.c  */
#line 575 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDistinctClause(AST_DISTINCT_CLAUSE, (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node), 2); }
    break;

  case 37:
/* Line 868 of glr.c  */
#line 576 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDistinctClause(AST_DISTINCT_CLAUSE, NULL, 0); }
    break;

  case 38:
/* Line 868 of glr.c  */
#line 577 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDistinctClause(AST_DISTINCT_CLAUSE, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node), 3); }
    break;

  case 39:
/* Line 868 of glr.c  */
#line 581 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDistinctList(AST_DISTINCT_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 40:
/* Line 868 of glr.c  */
#line 582 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDistinctList(AST_DISTINCT_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 41:
/* Line 868 of glr.c  */
#line 586 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstSelectList(AST_SELECT_LIST, 0,(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node),NULL);}
    break;

  case 42:
/* Line 868 of glr.c  */
#line 587 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstSelectList(AST_SELECT_LIST, 0,(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node));}
    break;

  case 43:
/* Line 868 of glr.c  */
#line 588 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstSelectList(AST_SELECT_LIST, 1,NULL,NULL);}
    break;

  case 44:
/* Line 868 of glr.c  */
#line 592 "sql.ypp"
    {((*yyvalp).ast_node) = new AstSelectExpr(AST_SELECT_EXPR, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.strval)),(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.ast_node));}
    break;

  case 45:
/* Line 868 of glr.c  */
#line 595 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstFromList(AST_FROM_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 46:
/* Line 868 of glr.c  */
#line 596 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstFromList(AST_FROM_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node));}
    break;

  case 47:
/* Line 868 of glr.c  */
#line 600 "sql.ypp"
    { ((*yyvalp).ast_node)=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node); }
    break;

  case 48:
/* Line 868 of glr.c  */
#line 601 "sql.ypp"
    { ((*yyvalp).ast_node)=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node); }
    break;

  case 49:
/* Line 868 of glr.c  */
#line 606 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstTable(AST_TABLE, string("NULL"),string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.strval)),string((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.strval)));}
    break;

  case 50:
/* Line 868 of glr.c  */
#line 608 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstTable(AST_TABLE, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval.strval)),string((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.strval)),string((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.strval))); }
    break;

  case 51:
/* Line 868 of glr.c  */
#line 609 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstSubquery(AST_SUBQUERY, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.strval)),(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 52:
/* Line 868 of glr.c  */
#line 610 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node); }
    break;

  case 55:
/* Line 868 of glr.c  */
#line 617 "sql.ypp"
    { ((*yyvalp).strval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.strval); }
    break;

  case 56:
/* Line 868 of glr.c  */
#line 618 "sql.ypp"
    { ((*yyvalp).strval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.strval); }
    break;

  case 57:
/* Line 868 of glr.c  */
#line 619 "sql.ypp"
    { ((*yyvalp).strval) = "NULL"; }
    break;

  case 58:
/* Line 868 of glr.c  */
#line 634 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstJoin(AST_JOIN, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node));}
    break;

  case 59:
/* Line 868 of glr.c  */
#line 635 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstJoin(AST_JOIN, -1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node), NULL);}
    break;

  case 60:
/* Line 868 of glr.c  */
#line 636 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstJoin(AST_JOIN, -1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node));}
    break;

  case 61:
/* Line 868 of glr.c  */
#line 637 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstJoin(AST_JOIN, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (6))].yystate.yysemantics.yysval.intval) + (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (6))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (6))].yystate.yysemantics.yysval.ast_node));}
    break;

  case 62:
/* Line 868 of glr.c  */
#line 638 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstJoin(AST_JOIN, 32 + (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node), NULL);}
    break;

  case 63:
/* Line 868 of glr.c  */
#line 641 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 64:
/* Line 868 of glr.c  */
#line 642 "sql.ypp"
    { ((*yyvalp).intval) = 1; }
    break;

  case 65:
/* Line 868 of glr.c  */
#line 643 "sql.ypp"
    { ((*yyvalp).intval) = 2; }
    break;

  case 66:
/* Line 868 of glr.c  */
#line 646 "sql.ypp"
    { ((*yyvalp).intval) = 4; }
    break;

  case 67:
/* Line 868 of glr.c  */
#line 647 "sql.ypp"
    { ((*yyvalp).intval) = 4; }
    break;

  case 68:
/* Line 868 of glr.c  */
#line 651 "sql.ypp"
    { ((*yyvalp).intval) = 8; }
    break;

  case 69:
/* Line 868 of glr.c  */
#line 652 "sql.ypp"
    { ((*yyvalp).intval) = 16; }
    break;

  case 70:
/* Line 868 of glr.c  */
#line 653 "sql.ypp"
    { ((*yyvalp).intval) = 64; }
    break;

  case 71:
/* Line 868 of glr.c  */
#line 657 "sql.ypp"
    { ((*yyvalp).intval) = 8 + (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.intval); }
    break;

  case 72:
/* Line 868 of glr.c  */
#line 658 "sql.ypp"
    { ((*yyvalp).intval) = 16 + (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.intval);}
    break;

  case 73:
/* Line 868 of glr.c  */
#line 659 "sql.ypp"
    { ((*yyvalp).intval) = 64 + (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.intval);}
    break;

  case 74:
/* Line 868 of glr.c  */
#line 660 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 75:
/* Line 868 of glr.c  */
#line 663 "sql.ypp"
    {((*yyvalp).ast_node) = NULL;}
    break;

  case 76:
/* Line 868 of glr.c  */
#line 664 "sql.ypp"
    {((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node);}
    break;

  case 77:
/* Line 868 of glr.c  */
#line 672 "sql.ypp"
    {((*yyvalp).ast_node) = new AstJoinCondition(AST_JOIN_CONDITION, "ON", (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 78:
/* Line 868 of glr.c  */
#line 673 "sql.ypp"
    {((*yyvalp).ast_node) = new AstJoinCondition(AST_JOIN_CONDITION, "USING", (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 79:
/* Line 868 of glr.c  */
#line 678 "sql.ypp"
    { ((*yyvalp).ast_node)=(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node); }
    break;

  case 80:
/* Line 868 of glr.c  */
#line 685 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstColumn(AST_COLUMN, string("NULL"),string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.strval)));}
    break;

  case 81:
/* Line 868 of glr.c  */
#line 686 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "CONST",string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.strval))); }
    break;

  case 82:
/* Line 868 of glr.c  */
#line 687 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstColumn(AST_COLUMN, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.strval)),string((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.strval))); }
    break;

  case 83:
/* Line 868 of glr.c  */
#line 688 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstColumn(AST_COLUMN_ALL, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.strval)),string("*"));}
    break;

  case 84:
/* Line 868 of glr.c  */
#line 689 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "CONST_STRING",	string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.strval))); }
    break;

  case 85:
/* Line 868 of glr.c  */
#line 690 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "CONST_INT",		string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.strval))); }
    break;

  case 86:
/* Line 868 of glr.c  */
#line 691 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "CONST_DOUBLE",	string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.strval))); }
    break;

  case 87:
/* Line 868 of glr.c  */
#line 692 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "CONST_BOOL",	string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.strval))); }
    break;

  case 88:
/* Line 868 of glr.c  */
#line 694 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_CAL_BINARY, "+",   (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 89:
/* Line 868 of glr.c  */
#line 695 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_CAL_BINARY, "-",   (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 90:
/* Line 868 of glr.c  */
#line 696 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_CAL_BINARY, "*",   (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 91:
/* Line 868 of glr.c  */
#line 697 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_CAL_BINARY, "/",   (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 92:
/* Line 868 of glr.c  */
#line 698 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_CAL_BINARY, "MOD", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 93:
/* Line 868 of glr.c  */
#line 699 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_CAL_BINARY, "%",   (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 94:
/* Line 868 of glr.c  */
#line 701 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "-", (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 95:
/* Line 868 of glr.c  */
#line 702 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "+", (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 96:
/* Line 868 of glr.c  */
#line 704 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_BOOL_BINARY, "AND", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 97:
/* Line 868 of glr.c  */
#line 705 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_BOOL_BINARY, "OR",  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 98:
/* Line 868 of glr.c  */
#line 706 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_BOOL_BINARY, "XOR", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 99:
/* Line 868 of glr.c  */
#line 708 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCmpBinary(AST_EXPR_CMP_BINARY, "", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.subtok), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 100:
/* Line 868 of glr.c  */
#line 709 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCmpBinary(AST_EXPR_CMP_BINARY, "SUBQUERY", (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval.subtok), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 101:
/* Line 868 of glr.c  */
#line 710 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCmpBinary(AST_EXPR_CMP_BINARY, "ANY",		(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (6))].yystate.yysemantics.yysval.subtok), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 102:
/* Line 868 of glr.c  */
#line 711 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCmpBinary(AST_EXPR_CMP_BINARY, "SOME",		(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (6))].yystate.yysemantics.yysval.subtok), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 103:
/* Line 868 of glr.c  */
#line 712 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCmpBinary(AST_EXPR_CMP_BINARY, "ALL",		(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (6))].yystate.yysemantics.yysval.subtok), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 104:
/* Line 868 of glr.c  */
#line 714 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_CAL_BINARY, "|",	(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 105:
/* Line 868 of glr.c  */
#line 715 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_CAL_BINARY, "&",	(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 106:
/* Line 868 of glr.c  */
#line 716 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_CAL_BINARY, "^",	(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 107:
/* Line 868 of glr.c  */
#line 717 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_CAL_BINARY, SHIFT==1?"LSHIFT":"RSHIFT",(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 108:
/* Line 868 of glr.c  */
#line 719 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "!",	(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 109:
/* Line 868 of glr.c  */
#line 720 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "NOT",	(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 110:
/* Line 868 of glr.c  */
#line 721 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 111:
/* Line 868 of glr.c  */
#line 722 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node); }
    break;

  case 112:
/* Line 868 of glr.c  */
#line 725 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "IS_NULL", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 113:
/* Line 868 of glr.c  */
#line 726 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "IS_NOT_NULL", 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 114:
/* Line 868 of glr.c  */
#line 727 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "IS_BOOL", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 115:
/* Line 868 of glr.c  */
#line 728 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "IS_NOT_BOOL", 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 116:
/* Line 868 of glr.c  */
#line 731 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "BETWEEN_AND", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 117:
/* Line 868 of glr.c  */
#line 734 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprList(AST_EXPR_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node), NULL);}
    break;

  case 118:
/* Line 868 of glr.c  */
#line 735 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprList(AST_EXPR_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 119:
/* Line 868 of glr.c  */
#line 736 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node); }
    break;

  case 120:
/* Line 868 of glr.c  */
#line 739 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprList(AST_EXPR_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 121:
/* Line 868 of glr.c  */
#line 740 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprList(AST_EXPR_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 122:
/* Line 868 of glr.c  */
#line 743 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCmpBinary(AST_EXPR_CMP_BINARY, "EXPR_IN_LIST", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 123:
/* Line 868 of glr.c  */
#line 744 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCmpBinary(AST_EXPR_CMP_BINARY, "LIST_IN_LIST",			(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (7))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (7))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 124:
/* Line 868 of glr.c  */
#line 745 "sql.ypp"
    { AstNode* tmp_node= new AstExprCmpBinary(AST_EXPR_CMP_BINARY, "EXPR_IN_LIST", 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node));
   																		((*yyvalp).ast_node)=new AstExprUnary(AST_EXPR_UNARY, "NOT",	tmp_node);  }
    break;

  case 125:
/* Line 868 of glr.c  */
#line 747 "sql.ypp"
    { AstNode* tmp_node= new AstExprCmpBinary(AST_EXPR_CMP_BINARY, "LIST_IN_LIST", 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (8))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (8))].yystate.yysemantics.yysval.ast_node)); 
   																		((*yyvalp).ast_node)=new AstExprUnary(AST_EXPR_UNARY, "NOT",	tmp_node);  }
    break;

  case 126:
/* Line 868 of glr.c  */
#line 749 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCmpBinary(AST_EXPR_CMP_BINARY, "EXPR_IN_SELECT", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 127:
/* Line 868 of glr.c  */
#line 750 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCmpBinary(AST_EXPR_CMP_BINARY, "LIST_IN_SELECT", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (7))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (7))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 128:
/* Line 868 of glr.c  */
#line 751 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCmpBinary(AST_EXPR_CMP_BINARY, "EXPR_NOT_IN_SELECT", 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 129:
/* Line 868 of glr.c  */
#line 752 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCmpBinary(AST_EXPR_CMP_BINARY, "LIST_NOT_IN_SELECT", 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (8))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (8))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 130:
/* Line 868 of glr.c  */
#line 754 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "EXSIST", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 131:
/* Line 868 of glr.c  */
#line 755 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "NOT_EXSIST", 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 132:
/* Line 868 of glr.c  */
#line 765 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "COUNT_ALL", NULL); }
    break;

  case 133:
/* Line 868 of glr.c  */
#line 766 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "COUNT",	 (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 134:
/* Line 868 of glr.c  */
#line 767 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "SUM",	 	 (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 135:
/* Line 868 of glr.c  */
#line 768 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "AVG",	 	 (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 136:
/* Line 868 of glr.c  */
#line 769 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "MIN",	 	 (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 137:
/* Line 868 of glr.c  */
#line 770 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "MAX",	 	 (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 138:
/* Line 868 of glr.c  */
#line 771 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "TO_CHAR",	 (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 139:
/* Line 868 of glr.c  */
#line 772 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "TO_CHAR",	 (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 140:
/* Line 868 of glr.c  */
#line 773 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "COUNT",	 (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node));    }
    break;

  case 141:
/* Line 868 of glr.c  */
#line 774 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "SUM",	 	 (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 142:
/* Line 868 of glr.c  */
#line 775 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "AVG",	 	 (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 143:
/* Line 868 of glr.c  */
#line 776 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "MIN",	 	 (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 144:
/* Line 868 of glr.c  */
#line 777 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "MAX",	 	 (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 145:
/* Line 868 of glr.c  */
#line 780 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "SUBSTRING_EXPR_EXPR", 				(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node), 	NULL); }
    break;

  case 146:
/* Line 868 of glr.c  */
#line 781 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "SUBSTRING_EXPR_FROM_EXPR", 			(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node), 	NULL);}
    break;

  case 147:
/* Line 868 of glr.c  */
#line 782 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "SUBSTRING_EXPR_EXPR_EXPR", 			(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (8))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (8))].yystate.yysemantics.yysval.ast_node), 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (8))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 148:
/* Line 868 of glr.c  */
#line 783 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "SUBSTRING_EXPR_FROM_EXPR_FOR_EXPR", (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (8))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (8))].yystate.yysemantics.yysval.ast_node), 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (8))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 149:
/* Line 868 of glr.c  */
#line 784 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "TRIM_BOTH", 					 NULL,(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node), 	NULL); }
    break;

  case 150:
/* Line 868 of glr.c  */
#line 785 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (7))].yystate.yysemantics.yysval.strval), 									(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (7))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (7))].yystate.yysemantics.yysval.ast_node), 	NULL); }
    break;

  case 151:
/* Line 868 of glr.c  */
#line 786 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "UPPER", 							(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node), NULL,	NULL); }
    break;

  case 152:
/* Line 868 of glr.c  */
#line 787 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "CAST",								(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node),  	NULL); }
    break;

  case 153:
/* Line 868 of glr.c  */
#line 788 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "COALESCE", 							(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node), NULL, 	NULL); }
    break;

  case 154:
/* Line 868 of glr.c  */
#line 791 "sql.ypp"
    { ((*yyvalp).strval)="TRIM_LEADING"; }
    break;

  case 155:
/* Line 868 of glr.c  */
#line 792 "sql.ypp"
    { ((*yyvalp).strval)="TRIM_TRAILING"; }
    break;

  case 156:
/* Line 868 of glr.c  */
#line 793 "sql.ypp"
    { ((*yyvalp).strval)="TRIM_BOTH"; }
    break;

  case 157:
/* Line 868 of glr.c  */
#line 796 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL;}
    break;

  case 158:
/* Line 868 of glr.c  */
#line 797 "sql.ypp"
    {((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "INT", 	NULL);}
    break;

  case 159:
/* Line 868 of glr.c  */
#line 798 "sql.ypp"
    {((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "STRING", NULL);}
    break;

  case 160:
/* Line 868 of glr.c  */
#line 799 "sql.ypp"
    {((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "DOUBLE", NULL);}
    break;

  case 161:
/* Line 868 of glr.c  */
#line 800 "sql.ypp"
    {((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "FLOAT", 	NULL);}
    break;

  case 162:
/* Line 868 of glr.c  */
#line 801 "sql.ypp"
    {((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "CHAR", 	NULL);}
    break;

  case 163:
/* Line 868 of glr.c  */
#line 804 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "DATE_ADD", (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 164:
/* Line 868 of glr.c  */
#line 805 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "DATE_SUB", (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 165:
/* Line 868 of glr.c  */
#line 809 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "INTERVAL_HOUR", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), NULL, NULL);  }
    break;

  case 166:
/* Line 868 of glr.c  */
#line 810 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "INTERVAL_MICROSECOND", 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), NULL, NULL);  }
    break;

  case 167:
/* Line 868 of glr.c  */
#line 811 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "INTERVAL_MINUTE", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), NULL, NULL);  }
    break;

  case 168:
/* Line 868 of glr.c  */
#line 812 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "INTERVAL_SECOND", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), NULL, NULL);  }
    break;

  case 169:
/* Line 868 of glr.c  */
#line 813 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "INTERVAL_DAY", 			(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), NULL, NULL);  }
    break;

  case 170:
/* Line 868 of glr.c  */
#line 814 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "INTERVAL_MONTH", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), NULL, NULL);  }
    break;

  case 171:
/* Line 868 of glr.c  */
#line 815 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "INTERVAL_YEAR", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), NULL, NULL);  }
    break;

  case 172:
/* Line 868 of glr.c  */
#line 816 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "INTERVAL_WEEK", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), NULL, NULL);  }
    break;

  case 173:
/* Line 868 of glr.c  */
#line 817 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "INTERVAL_QUARTER", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), NULL, NULL);  }
    break;

  case 174:
/* Line 868 of glr.c  */
#line 821 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "CASE1", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval.ast_node), 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 175:
/* Line 868 of glr.c  */
#line 822 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "CASE1_ELSE", 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (6))].yystate.yysemantics.yysval.ast_node), 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (6))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 176:
/* Line 868 of glr.c  */
#line 823 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "CASE2", 		NULL,	(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 177:
/* Line 868 of glr.c  */
#line 824 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "CASE2_ELSE", 	NULL, 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 178:
/* Line 868 of glr.c  */
#line 827 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "WHEN", (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 179:
/* Line 868 of glr.c  */
#line 828 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprFunc(AST_EXPR_FUNC, "WHEN", (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 180:
/* Line 868 of glr.c  */
#line 831 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_CAL_BINARY, "LIKE", 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 181:
/* Line 868 of glr.c  */
#line 832 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_CAL_BINARY, "NOT_LIKE", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 182:
/* Line 868 of glr.c  */
#line 835 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_CAL_BINARY, "REGEXP", 		(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 183:
/* Line 868 of glr.c  */
#line 836 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstExprCalBinary(AST_EXPR_CAL_BINARY, "NOT_REGEXP", 	(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 184:
/* Line 868 of glr.c  */
#line 842 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node); }
    break;

  case 185:
/* Line 868 of glr.c  */
#line 846 "sql.ypp"
    { string temp = ((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.strval) == NULL)?"":string((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.strval)); ((*yyvalp).ast_node) = new AstCreateDatabase(AST_CREATE_DATABASE, 1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.intval), temp); }
    break;

  case 186:
/* Line 868 of glr.c  */
#line 847 "sql.ypp"
    { string temp = ((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.strval) == NULL)?"":string((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.strval)); ((*yyvalp).ast_node) = new AstCreateDatabase(AST_CREATE_SCHEMA, 2, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.intval), temp); }
    break;

  case 187:
/* Line 868 of glr.c  */
#line 850 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 188:
/* Line 868 of glr.c  */
#line 851 "sql.ypp"
    { ((*yyvalp).intval) = 1; }
    break;

  case 189:
/* Line 868 of glr.c  */
#line 856 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node);}
    break;

  case 190:
/* Line 868 of glr.c  */
#line 860 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateTable(AST_CREATE_TABLE_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (8))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (8))].yystate.yysemantics.yysval.intval), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (8))].yystate.yysemantics.yysval.strval)), "", (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (8))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 191:
/* Line 868 of glr.c  */
#line 864 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateTable(AST_CREATE_TABLE_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (10))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (10))].yystate.yysemantics.yysval.intval), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (10))].yystate.yysemantics.yysval.strval)), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (10))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (10))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 192:
/* Line 868 of glr.c  */
#line 869 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateTable(AST_CREATE_TABLE_LIST_SEL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (9))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (9))].yystate.yysemantics.yysval.intval), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (9))].yystate.yysemantics.yysval.strval)), "", (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (9))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (9))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 193:
/* Line 868 of glr.c  */
#line 873 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateTable(AST_CREATE_TABLE_SEL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (6))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (6))].yystate.yysemantics.yysval.intval), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.strval)), "", NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (6))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 194:
/* Line 868 of glr.c  */
#line 878 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateTable(AST_CREATE_TABLE_LIST_SEL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (11))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (11))].yystate.yysemantics.yysval.intval), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (11))].yystate.yysemantics.yysval.strval)), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (11))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (11))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((11) - (11))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 195:
/* Line 868 of glr.c  */
#line 882 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateTable(AST_CREATE_TABLE_SEL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (8))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (8))].yystate.yysemantics.yysval.intval), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (8))].yystate.yysemantics.yysval.strval)), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (8))].yystate.yysemantics.yysval.strval)), NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((8) - (8))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 196:
/* Line 868 of glr.c  */
#line 886 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateSelect(AST_CREATE_SEL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.intval), 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 197:
/* Line 868 of glr.c  */
#line 889 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 198:
/* Line 868 of glr.c  */
#line 890 "sql.ypp"
    { ((*yyvalp).intval) = 1; }
    break;

  case 199:
/* Line 868 of glr.c  */
#line 891 "sql.ypp"
    { ((*yyvalp).intval) = 2; }
    break;

  case 200:
/* Line 868 of glr.c  */
#line 894 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 201:
/* Line 868 of glr.c  */
#line 895 "sql.ypp"
    { ((*yyvalp).intval) = 1; }
    break;

  case 202:
/* Line 868 of glr.c  */
#line 898 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateColList(AST_CREATE_COL_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 203:
/* Line 868 of glr.c  */
#line 899 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateColList(AST_CREATE_COL_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 204:
/* Line 868 of glr.c  */
#line 904 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateDef( AST_CREATE_DEF_NAME, 1, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 205:
/* Line 868 of glr.c  */
#line 905 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateDef( AST_CREATE_DEF_PR_KEY, 2, "", NULL, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node));  }
    break;

  case 206:
/* Line 868 of glr.c  */
#line 906 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateDef( AST_CREATE_DEF_KEY, 3, "", NULL, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 207:
/* Line 868 of glr.c  */
#line 907 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateDef( AST_CREATE_DEF_INDEX, 4, "", NULL, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 208:
/* Line 868 of glr.c  */
#line 908 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateDef( AST_CREATE_DEF_FTEXT_INDEX, 5, "", NULL, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 209:
/* Line 868 of glr.c  */
#line 909 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateDef( AST_CREATE_DEF_FTEXT_KEY, 6, "", NULL, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 210:
/* Line 868 of glr.c  */
#line 911 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstColumnAtts(AST_COLUMN_ATTS, 0, 0, 0, "", NULL); }
    break;

  case 211:
/* Line 868 of glr.c  */
#line 912 "sql.ypp"
    { AstColumnAtts* temp = static_cast<AstColumnAtts*>((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node));temp->datatype_ |= 01; ((*yyvalp).ast_node) = temp; }
    break;

  case 212:
/* Line 868 of glr.c  */
#line 913 "sql.ypp"
    { AstColumnAtts* temp = static_cast<AstColumnAtts*>((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.ast_node));temp->datatype_ |= 02; ((*yyvalp).ast_node) = temp; }
    break;

  case 213:
/* Line 868 of glr.c  */
#line 914 "sql.ypp"
    { AstColumnAtts* temp = static_cast<AstColumnAtts*>((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node));temp->datatype_ |= 04; temp->default_string_ = ((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.strval)==NULL)?"":string((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.strval)); ((*yyvalp).ast_node) = temp; }
    break;

  case 214:
/* Line 868 of glr.c  */
#line 915 "sql.ypp"
    { AstColumnAtts* temp = static_cast<AstColumnAtts*>((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node));temp->datatype_ |= 010;temp->int_num_ = atoi((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.strval)); ((*yyvalp).ast_node) = temp; }
    break;

  case 215:
/* Line 868 of glr.c  */
#line 916 "sql.ypp"
    { AstColumnAtts* temp = static_cast<AstColumnAtts*>((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node));temp->datatype_ |= 020; temp->double_num_ = atof((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.strval)); ((*yyvalp).ast_node) = temp; }
    break;

  case 216:
/* Line 868 of glr.c  */
#line 917 "sql.ypp"
    { AstColumnAtts* temp = static_cast<AstColumnAtts*>((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node));temp->datatype_ |= 040; temp->int_num_ = atoi((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.strval)); ((*yyvalp).ast_node) = temp; }
    break;

  case 217:
/* Line 868 of glr.c  */
#line 918 "sql.ypp"
    { AstColumnAtts* temp = static_cast<AstColumnAtts*>((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.ast_node));temp->datatype_ |= 0100; ((*yyvalp).ast_node) = temp; }
    break;

  case 218:
/* Line 868 of glr.c  */
#line 919 "sql.ypp"
    { AstColumnAtts* temp = static_cast<AstColumnAtts*>((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node));temp->datatype_ |= 0200; ((*yyvalp).ast_node) = temp; }
    break;

  case 219:
/* Line 868 of glr.c  */
#line 920 "sql.ypp"
    { AstColumnAtts* temp = static_cast<AstColumnAtts*>((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node));temp->datatype_ |= 0400; ((*yyvalp).ast_node) = temp; }
    break;

  case 220:
/* Line 868 of glr.c  */
#line 921 "sql.ypp"
    { AstColumnAtts* temp = static_cast<AstColumnAtts*>((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.ast_node));temp->datatype_ |= 01000; ((*yyvalp).ast_node) = temp; }
    break;

  case 221:
/* Line 868 of glr.c  */
#line 922 "sql.ypp"
    { AstColumnAtts* temp = static_cast<AstColumnAtts*>((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node));temp->datatype_ |= 02000; ((*yyvalp).ast_node) = temp; }
    break;

  case 222:
/* Line 868 of glr.c  */
#line 923 "sql.ypp"
    { AstColumnAtts* temp = static_cast<AstColumnAtts*>((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node));temp->datatype_ |= 04000; temp->col_list_ = (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node); ((*yyvalp).ast_node) = temp;}
    break;

  case 223:
/* Line 868 of glr.c  */
#line 927 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node), 0, NULL, 0, NULL); }
    break;

  case 224:
/* Line 868 of glr.c  */
#line 928 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 2, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL, 0, NULL); }
    break;

  case 225:
/* Line 868 of glr.c  */
#line 929 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 3, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL, 0, NULL); }
    break;

  case 226:
/* Line 868 of glr.c  */
#line 930 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 4, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL, 0, NULL); }
    break;

  case 227:
/* Line 868 of glr.c  */
#line 931 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 5, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL, 0, NULL); }
    break;

  case 228:
/* Line 868 of glr.c  */
#line 932 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 6, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL, 0, NULL); }
    break;

  case 229:
/* Line 868 of glr.c  */
#line 933 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 7, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL, 0, NULL); }
    break;

  case 230:
/* Line 868 of glr.c  */
#line 934 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 8, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL, 0, NULL); }
    break;

  case 231:
/* Line 868 of glr.c  */
#line 935 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 9, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL, 0, NULL); }
    break;

  case 232:
/* Line 868 of glr.c  */
#line 936 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 10, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL, 0, NULL); }
    break;

  case 233:
/* Line 868 of glr.c  */
#line 937 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 11, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL, 0, NULL); }
    break;

  case 234:
/* Line 868 of glr.c  */
#line 938 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 12, NULL, 0, NULL, 0, NULL); }
    break;

  case 235:
/* Line 868 of glr.c  */
#line 939 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 13, NULL, 0, NULL, 0, NULL); }
    break;

  case 236:
/* Line 868 of glr.c  */
#line 940 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 14, NULL, 0, NULL, 0, NULL); }
    break;

  case 237:
/* Line 868 of glr.c  */
#line 941 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 15, NULL, 0, NULL, 0, NULL); }
    break;

  case 238:
/* Line 868 of glr.c  */
#line 942 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 16, NULL, 0, NULL, 0, NULL); }
    break;

  case 239:
/* Line 868 of glr.c  */
#line 943 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 17, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node), 0, NULL); }
    break;

  case 240:
/* Line 868 of glr.c  */
#line 944 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 18, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node), 0, NULL); }
    break;

  case 241:
/* Line 868 of glr.c  */
#line 945 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 19, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.ast_node), 0, NULL, 0, NULL); }
    break;

  case 242:
/* Line 868 of glr.c  */
#line 946 "sql.ypp"
    { AstNode* temp = new AstOptLength(AST_OPT_LENGTH,atoi((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.strval)),NULL); 
                                              ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 20, temp, 0, NULL, 0, NULL); }
    break;

  case 243:
/* Line 868 of glr.c  */
#line 948 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 21, NULL, 0, NULL, 0, NULL); }
    break;

  case 244:
/* Line 868 of glr.c  */
#line 949 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 22, NULL, 0, NULL, 0, NULL); }
    break;

  case 245:
/* Line 868 of glr.c  */
#line 950 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 23, NULL, 0, NULL, 0, NULL); }
    break;

  case 246:
/* Line 868 of glr.c  */
#line 951 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 24, NULL, 0, NULL, 0, NULL); }
    break;

  case 247:
/* Line 868 of glr.c  */
#line 952 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 25, NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.intval), NULL); }
    break;

  case 248:
/* Line 868 of glr.c  */
#line 953 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 26, NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.intval), NULL); }
    break;

  case 249:
/* Line 868 of glr.c  */
#line 954 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 27, NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.intval), NULL); }
    break;

  case 250:
/* Line 868 of glr.c  */
#line 955 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 28, NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.intval), NULL); }
    break;

  case 251:
/* Line 868 of glr.c  */
#line 956 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 29, NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node), 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 252:
/* Line 868 of glr.c  */
#line 957 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDataType (AST_DATA_TYPE, 30, NULL, 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node), 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 253:
/* Line 868 of glr.c  */
#line 959 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstEnumList( AST_ENUM, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.strval)), NULL); }
    break;

  case 254:
/* Line 868 of glr.c  */
#line 960 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstEnumList( AST_ENUM_LIST, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 255:
/* Line 868 of glr.c  */
#line 963 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 256:
/* Line 868 of glr.c  */
#line 964 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstOptLength (AST_OPT_LENGTH, atoi((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.strval)), 0); }
    break;

  case 257:
/* Line 868 of glr.c  */
#line 965 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstOptLength (AST_OPT_LENGTH, atoi((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval.strval)), atoi((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.strval))); }
    break;

  case 258:
/* Line 868 of glr.c  */
#line 968 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 259:
/* Line 868 of glr.c  */
#line 969 "sql.ypp"
    { ((*yyvalp).intval) = 1; }
    break;

  case 260:
/* Line 868 of glr.c  */
#line 972 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 261:
/* Line 868 of glr.c  */
#line 973 "sql.ypp"
    { ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.intval) | 01; }
    break;

  case 262:
/* Line 868 of glr.c  */
#line 974 "sql.ypp"
    { ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.intval) | 02; }
    break;

  case 263:
/* Line 868 of glr.c  */
#line 977 "sql.ypp"
    { ((*yyvalp).ast_node) =new AstOptCsc(AST_OPT_CSC, 0, "", "");}
    break;

  case 264:
/* Line 868 of glr.c  */
#line 979 "sql.ypp"
    { AstOptCsc* temp=static_cast<AstOptCsc*>((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval.ast_node));temp->data_type_ |= 01; temp->str1_ = string((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.strval)); ((*yyvalp).ast_node) = temp; }
    break;

  case 265:
/* Line 868 of glr.c  */
#line 981 "sql.ypp"
    { AstOptCsc* temp=static_cast<AstOptCsc*>((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node));temp->data_type_ |= 02; temp->str2_ = string((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.strval)); ((*yyvalp).ast_node) = temp; }
    break;

  case 266:
/* Line 868 of glr.c  */
#line 985 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node);/* puts("SQL parser： This is a create_projection statement");*/ }
    break;

  case 267:
/* Line 868 of glr.c  */
#line 989 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateProjection(AST_CREATE_PROJECTION, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (10))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (10))].yystate.yysemantics.yysval.ast_node), 1, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((10) - (10))].yystate.yysemantics.yysval.strval))); }
    break;

  case 268:
/* Line 868 of glr.c  */
#line 991 "sql.ypp"
    { 
		if ((((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (13))].yystate.yysemantics.yysval.subtok) != 4) { yyerror(result,"please give a specific number"); } 
		else                                { ((*yyvalp).ast_node) = new AstCreateProjection(AST_CREATE_PROJECTION_NUM, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (13))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (13))].yystate.yysemantics.yysval.ast_node), atoi((((yyGLRStackItem const *)yyvsp)[YYFILL ((10) - (13))].yystate.yysemantics.yysval.strval)), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((13) - (13))].yystate.yysemantics.yysval.strval))); }
	}
    break;

  case 269:
/* Line 868 of glr.c  */
#line 998 "sql.ypp"
    { ((*yyvalp).ast_node)=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node);}
    break;

  case 270:
/* Line 868 of glr.c  */
#line 1003 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstCreateIndex(AST_CREATE_INDEX, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (10))].yystate.yysemantics.yysval.intval), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (10))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (10))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (10))].yystate.yysemantics.yysval.strval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (10))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 271:
/* Line 868 of glr.c  */
#line 1006 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 272:
/* Line 868 of glr.c  */
#line 1007 "sql.ypp"
    { ((*yyvalp).intval) = 1; }
    break;

  case 273:
/* Line 868 of glr.c  */
#line 1008 "sql.ypp"
    { ((*yyvalp).intval) = 2; }
    break;

  case 274:
/* Line 868 of glr.c  */
#line 1009 "sql.ypp"
    { ((*yyvalp).intval) = 3; }
    break;

  case 275:
/* Line 868 of glr.c  */
#line 1012 "sql.ypp"
    { ((*yyvalp).intval) = 0;  }
    break;

  case 276:
/* Line 868 of glr.c  */
#line 1013 "sql.ypp"
    { ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.intval); }
    break;

  case 277:
/* Line 868 of glr.c  */
#line 1016 "sql.ypp"
    { ((*yyvalp).intval) = 1; }
    break;

  case 278:
/* Line 868 of glr.c  */
#line 1017 "sql.ypp"
    { ((*yyvalp).intval) = 2; }
    break;

  case 279:
/* Line 868 of glr.c  */
#line 1020 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstIndexColList(AST_INDEX_COL, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.intval), NULL); }
    break;

  case 280:
/* Line 868 of glr.c  */
#line 1021 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstIndexColList(AST_INDEX_COL_LIST, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 281:
/* Line 868 of glr.c  */
#line 1025 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node);}
    break;

  case 282:
/* Line 868 of glr.c  */
#line 1029 "sql.ypp"
    {
		  if ((((yyGLRStackItem const *)yyvsp)[YYFILL ((11) - (12))].yystate.yysemantics.yysval.subtok) != 4) { yyerror(result,"please give a specific number"); } 
		  else {((*yyvalp).ast_node) = new AstLoadTable(AST_LOAD_TABLE, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (12))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (12))].yystate.yysemantics.yysval.ast_node), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (12))].yystate.yysemantics.yysval.strval)), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (12))].yystate.yysemantics.yysval.strval)), atof((((yyGLRStackItem const *)yyvsp)[YYFILL ((12) - (12))].yystate.yysemantics.yysval.strval)), 1);}
		}
    break;

  case 283:
/* Line 868 of glr.c  */
#line 1033 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstLoadTable(AST_LOAD_TABLE, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (9))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (9))].yystate.yysemantics.yysval.ast_node), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (9))].yystate.yysemantics.yysval.strval)), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (9))].yystate.yysemantics.yysval.strval)), 1.0, 1);}
    break;

  case 284:
/* Line 868 of glr.c  */
#line 1034 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstLoadTable(AST_LOAD_TABLE, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (9))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (9))].yystate.yysemantics.yysval.ast_node), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (9))].yystate.yysemantics.yysval.strval)), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (9))].yystate.yysemantics.yysval.strval)), 1.0, 2);}
    break;

  case 285:
/* Line 868 of glr.c  */
#line 1036 "sql.ypp"
    { if ((((yyGLRStackItem const *)yyvsp)[YYFILL ((11) - (12))].yystate.yysemantics.yysval.subtok) != 4) { yyerror(result,"please give a specific number"); } 
		 else {((*yyvalp).ast_node) = new AstLoadTable(AST_LOAD_TABLE, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (12))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (12))].yystate.yysemantics.yysval.ast_node), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (12))].yystate.yysemantics.yysval.strval)), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (12))].yystate.yysemantics.yysval.strval)), atof((((yyGLRStackItem const *)yyvsp)[YYFILL ((12) - (12))].yystate.yysemantics.yysval.strval)), 2);}
		}
    break;

  case 286:
/* Line 868 of glr.c  */
#line 1042 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node); /*output($$, 1); puts("SQL parser： This is a drop_index statement");*/ }
    break;

  case 287:
/* Line 868 of glr.c  */
#line 1045 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDropIndex(AST_DROP_INDEX, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.strval)), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.strval))); }
    break;

  case 288:
/* Line 868 of glr.c  */
#line 1049 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node);/* output($$, 1); puts("SQL parser： This is a drop_database statement");*/ }
    break;

  case 289:
/* Line 868 of glr.c  */
#line 1053 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDropDatabase(AST_DROP_DB, 1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.intval), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.strval))); }
    break;

  case 290:
/* Line 868 of glr.c  */
#line 1054 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDropDatabase(AST_DROP_SCHEMA, 2, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.intval), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.strval))); }
    break;

  case 291:
/* Line 868 of glr.c  */
#line 1057 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 292:
/* Line 868 of glr.c  */
#line 1058 "sql.ypp"
    { ((*yyvalp).intval) = 1; }
    break;

  case 293:
/* Line 868 of glr.c  */
#line 1062 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node); /*output($$, 1); puts("SQL parser： This is a drop_table statement"); */}
    break;

  case 294:
/* Line 868 of glr.c  */
#line 1066 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDropTable(AST_DROP_TABLE, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (6))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (6))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (6))].yystate.yysemantics.yysval.intval), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 295:
/* Line 868 of glr.c  */
#line 1069 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDropTableList(AST_DROP_TABLE_LIST, "", string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.strval)), NULL); }
    break;

  case 296:
/* Line 868 of glr.c  */
#line 1070 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDropTableList(AST_DROP_TABLE_LIST, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.strval)), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.strval)), NULL); }
    break;

  case 297:
/* Line 868 of glr.c  */
#line 1071 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDropTableList(AST_DROP_TABLE_LIST, "", string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 298:
/* Line 868 of glr.c  */
#line 1072 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDropTableList(AST_DROP_TABLE_LIST, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.strval)), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 299:
/* Line 868 of glr.c  */
#line 1075 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 300:
/* Line 868 of glr.c  */
#line 1076 "sql.ypp"
    { ((*yyvalp).intval) = 1; }
    break;

  case 301:
/* Line 868 of glr.c  */
#line 1077 "sql.ypp"
    { ((*yyvalp).intval) = 2; }
    break;

  case 302:
/* Line 868 of glr.c  */
#line 1081 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node); /*output($$, 1); puts("SQL parser： This is a drop_projection statement"); */}
    break;

  case 303:
/* Line 868 of glr.c  */
#line 1084 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDropProjection(AST_DROP_PROJECTION, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.strval)),1,NULL); }
    break;

  case 304:
/* Line 868 of glr.c  */
#line 1086 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDropProjection(AST_DROP_PROJECTION, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.strval)),0,atoi((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.strval)));}
    break;

  case 305:
/* Line 868 of glr.c  */
#line 1092 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node); /*output($$, 1); puts("SQL parser： This is a truncate statement"); */}
    break;

  case 306:
/* Line 868 of glr.c  */
#line 1095 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstTruncateTable(AST_TRUNCATE_TABLE,(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node),"",""); }
    break;

  case 307:
/* Line 868 of glr.c  */
#line 1096 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstTruncateTable(AST_TRUNCATE_TABLE,NULL,string((((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.strval)),atoi((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.strval))); }
    break;

  case 308:
/* Line 868 of glr.c  */
#line 1101 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node);}
    break;

  case 309:
/* Line 868 of glr.c  */
#line 1107 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstInsertStmt(AST_INSERT_STMT, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (8))].yystate.yysemantics.yysval.intval), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (8))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (8))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (8))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((8) - (8))].yystate.yysemantics.yysval.ast_node), NULL, NULL); }
    break;

  case 310:
/* Line 868 of glr.c  */
#line 1110 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 311:
/* Line 868 of glr.c  */
#line 1111 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node); }
    break;

  case 312:
/* Line 868 of glr.c  */
#line 1114 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 313:
/* Line 868 of glr.c  */
#line 1115 "sql.ypp"
    { ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.intval) | 01 ; }
    break;

  case 314:
/* Line 868 of glr.c  */
#line 1116 "sql.ypp"
    { ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.intval) | 02 ; }
    break;

  case 315:
/* Line 868 of glr.c  */
#line 1117 "sql.ypp"
    { ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.intval) | 04 ; }
    break;

  case 316:
/* Line 868 of glr.c  */
#line 1118 "sql.ypp"
    { ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.intval) | 010 ; }
    break;

  case 319:
/* Line 868 of glr.c  */
#line 1124 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 320:
/* Line 868 of glr.c  */
#line 1125 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node); }
    break;

  case 321:
/* Line 868 of glr.c  */
#line 1128 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstInsertValList(AST_INSERT_VALUE_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 322:
/* Line 868 of glr.c  */
#line 1129 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstInsertValList(AST_INSERT_VALUE_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 323:
/* Line 868 of glr.c  */
#line 1133 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstInsertVals(AST_INSERT_VALUE,0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 324:
/* Line 868 of glr.c  */
#line 1134 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstInsertVals(AST_INSERT_VALUE,1, NULL, NULL); }
    break;

  case 325:
/* Line 868 of glr.c  */
#line 1135 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstInsertVals(AST_INSERT_VALUE,0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 326:
/* Line 868 of glr.c  */
#line 1136 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstInsertVals(AST_INSERT_VALUE,1, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 327:
/* Line 868 of glr.c  */
#line 1140 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstInsertStmt(AST_INSERT_STMT, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (7))].yystate.yysemantics.yysval.intval), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (7))].yystate.yysemantics.yysval.strval)), NULL, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (7))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (7))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 328:
/* Line 868 of glr.c  */
#line 1144 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstInsertStmt(AST_INSERT_STMT, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (7))].yystate.yysemantics.yysval.intval), string((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (7))].yystate.yysemantics.yysval.strval)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (7))].yystate.yysemantics.yysval.ast_node), NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (7))].yystate.yysemantics.yysval.ast_node), NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (7))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 329:
/* Line 868 of glr.c  */
#line 1148 "sql.ypp"
    { 
		if((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.subtok) != 4) yyerror(result,"bad insert assignment to %s", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.strval)); 
		else ((*yyvalp).ast_node) = new AstInsertAssignList(AST_INSERT_ASSIGN_LIST, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.strval)), 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 330:
/* Line 868 of glr.c  */
#line 1151 "sql.ypp"
    { 
		if ((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.subtok) != 4) yyerror(result,"bad insert assignment to %s", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.strval));
 		else ((*yyvalp).ast_node) = new AstInsertAssignList(AST_INSERT_ASSIGN_LIST, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.strval)), 1, NULL, NULL); }
    break;

  case 331:
/* Line 868 of glr.c  */
#line 1154 "sql.ypp"
    { 
		if ((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.subtok) != 4) yyerror(result,"bad insert assignment to %s", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node));		 
		else ((*yyvalp).ast_node) = new AstInsertAssignList(AST_INSERT_ASSIGN_LIST, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.strval)), 0, (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 332:
/* Line 868 of glr.c  */
#line 1157 "sql.ypp"
    { 
		if ((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.subtok) != 4) yyerror(result,"bad insert assignment to %s", (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node));
		else ((*yyvalp).ast_node) = new AstInsertAssignList(AST_INSERT_ASSIGN_LIST, string((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.strval)), 1, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 333:
/* Line 868 of glr.c  */
#line 1162 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node); /*output($$, 1); puts("SQL parser： This is a show statement");*/ }
    break;

  case 334:
/* Line 868 of glr.c  */
#line 1165 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstShowStmt(AST_SHOW_STMT,1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval.intval), ((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.intval)==NULL)?"":string((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.intval)), ((((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.strval)==NULL)?"":string((((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.strval))); }
    break;

  case 335:
/* Line 868 of glr.c  */
#line 1166 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 336:
/* Line 868 of glr.c  */
#line 1167 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 337:
/* Line 868 of glr.c  */
#line 1168 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 338:
/* Line 868 of glr.c  */
#line 1169 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 339:
/* Line 868 of glr.c  */
#line 1170 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 340:
/* Line 868 of glr.c  */
#line 1171 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 341:
/* Line 868 of glr.c  */
#line 1172 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 342:
/* Line 868 of glr.c  */
#line 1173 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 343:
/* Line 868 of glr.c  */
#line 1174 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 344:
/* Line 868 of glr.c  */
#line 1175 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 345:
/* Line 868 of glr.c  */
#line 1176 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 346:
/* Line 868 of glr.c  */
#line 1177 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 347:
/* Line 868 of glr.c  */
#line 1178 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 348:
/* Line 868 of glr.c  */
#line 1179 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 349:
/* Line 868 of glr.c  */
#line 1180 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 350:
/* Line 868 of glr.c  */
#line 1181 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 351:
/* Line 868 of glr.c  */
#line 1182 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 352:
/* Line 868 of glr.c  */
#line 1183 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 353:
/* Line 868 of glr.c  */
#line 1184 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 354:
/* Line 868 of glr.c  */
#line 1185 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 355:
/* Line 868 of glr.c  */
#line 1186 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 356:
/* Line 868 of glr.c  */
#line 1187 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 357:
/* Line 868 of glr.c  */
#line 1188 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 358:
/* Line 868 of glr.c  */
#line 1189 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 359:
/* Line 868 of glr.c  */
#line 1190 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 360:
/* Line 868 of glr.c  */
#line 1191 "sql.ypp"
    { ((*yyvalp).ast_node) = NULL; }
    break;

  case 361:
/* Line 868 of glr.c  */
#line 1193 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 362:
/* Line 868 of glr.c  */
#line 1197 "sql.ypp"
    { ((*yyvalp).intval) = NULL; }
    break;

  case 363:
/* Line 868 of glr.c  */
#line 1198 "sql.ypp"
    { ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.strval); }
    break;

  case 364:
/* Line 868 of glr.c  */
#line 1201 "sql.ypp"
    { ((*yyvalp).strval) = NULL; }
    break;

  case 365:
/* Line 868 of glr.c  */
#line 1202 "sql.ypp"
    { ((*yyvalp).strval) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.strval); }
    break;

  case 370:
/* Line 868 of glr.c  */
#line 1212 "sql.ypp"
    { ((*yyvalp).intval) = 0; }
    break;

  case 371:
/* Line 868 of glr.c  */
#line 1213 "sql.ypp"
    { ((*yyvalp).intval) = 1; }
    break;

  case 372:
/* Line 868 of glr.c  */
#line 1214 "sql.ypp"
    { ((*yyvalp).intval) = 2; }
    break;

  case 373:
/* Line 868 of glr.c  */
#line 1217 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDescStmt(AST_DESC_STMT, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.strval)); }
    break;

  case 374:
/* Line 868 of glr.c  */
#line 1220 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node); }
    break;

  case 375:
/* Line 868 of glr.c  */
#line 1224 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstDeleteStmt(AST_DELETE_STMT,(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (7))].yystate.yysemantics.yysval.ast_node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (7))].yystate.yysemantics.yysval.ast_node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (7))].yystate.yysemantics.yysval.ast_node) );}
    break;

  case 376:
/* Line 868 of glr.c  */
#line 1228 "sql.ypp"
    { emit("DELETEMULTI %d %d %d", (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (7))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (7))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (7))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 377:
/* Line 868 of glr.c  */
#line 1233 "sql.ypp"
    {}
    break;

  case 378:
/* Line 868 of glr.c  */
#line 1236 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.ast_node) + 01; }
    break;

  case 379:
/* Line 868 of glr.c  */
#line 1237 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.ast_node) + 02; }
    break;

  case 380:
/* Line 868 of glr.c  */
#line 1238 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.ast_node) + 04; }
    break;

  case 381:
/* Line 868 of glr.c  */
#line 1239 "sql.ypp"
    { ((*yyvalp).ast_node) = 0; }
    break;

  case 382:
/* Line 868 of glr.c  */
#line 1243 "sql.ypp"
    {  }
    break;

  case 383:
/* Line 868 of glr.c  */
#line 1244 "sql.ypp"
    {  }
    break;

  case 386:
/* Line 868 of glr.c  */
#line 1251 "sql.ypp"
    { ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.ast_node); }
    break;

  case 387:
/* Line 868 of glr.c  */
#line 1254 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstUpdateStmt(AST_UPDATE_STMT, (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;

  case 388:
/* Line 868 of glr.c  */
#line 1257 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstUpdateSetList(AST_UPDATE_SET_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.ast_node), NULL); }
    break;

  case 389:
/* Line 868 of glr.c  */
#line 1258 "sql.ypp"
    { ((*yyvalp).ast_node) = new AstUpdateSetList(AST_UPDATE_SET_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.ast_node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval.ast_node)); }
    break;


/* Line 868 of glr.c  */
#line 4755 "sql.tab.cpp"
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
  (!!((Yystate) == (-577)))

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
  (!!((Yytable_value) == (-390)))

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
#line 1261 "sql.ypp"


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
