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

void yyerror(struct ParseResult *pp, const char *s, ...);
void emit(char *s, ...);

/* Line 207 of glr.c  */
#line 86 "sql.tab.cpp"

#ifndef YY_NULL
#if defined __cplusplus && 201103L <= __cplusplus
#define YY_NULL nullptr
#else
#define YY_NULL 0
#endif
#endif

#include "sql.tab.hpp"

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
#undef YYERROR_VERBOSE
#define YYERROR_VERBOSE 1
#else
#define YYERROR_VERBOSE 0
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
should replace YYLEX with the following clause in sql.tab.cpp, why so? I don't
know

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
#if defined YYENABLE_NLS && YYENABLE_NLS
#if ENABLE_NLS
#include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#define YY_(Msgid) dgettext("bison-runtime", Msgid)
#endif
#endif
#ifndef YY_
#define YY_(Msgid) Msgid
#endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if !defined lint || defined __GNUC__
#define YYUSE(E) ((void)(E))
#else
#define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
#define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ || defined __cplusplus || \
     defined _MSC_VER)
static int YYID(int i)
#else
static int YYID(i) int i;
#endif
{
  return i;
}
#endif

#ifndef YYFREE
#define YYFREE free
#endif
#ifndef YYMALLOC
#define YYMALLOC malloc
#endif
#ifndef YYREALLOC
#define YYREALLOC realloc
#endif

#define YYSIZEMAX ((size_t)-1)

#ifdef __cplusplus
typedef bool yybool;
#else
typedef unsigned char yybool;
#endif
#define yytrue 1
#define yyfalse 0

#ifndef YYSETJMP
#include <setjmp.h>
#define YYJMP_BUF jmp_buf
#define YYSETJMP(Env) setjmp(Env)
/* Pacify clang.  */
#define YYLONGJMP(Env, Val) (longjmp(Env, Val), YYASSERT(0))
#endif

/*-----------------.
| GCC extensions.  |
`-----------------*/

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
#if (!defined __GNUC__ || __GNUC__ < 2 || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#define __attribute__(Spec) /* empty */
#endif
#endif

#ifndef YYASSERT
#define YYASSERT(Condition) ((void)((Condition) || (abort(), 0)))
#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL 104
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST 2627

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS 342
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS 89
/* YYNRULES -- Number of rules.  */
#define YYNRULES 383
/* YYNRULES -- Number of states.  */
#define YYNSTATES 815
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 13
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYTRANSLATE(X) -- Bison symbol number corresponding to X.  */
#define YYUNDEFTOK 2
#define YYMAXUTOK 582

#define YYTRANSLATE(YYX) \
  ((unsigned int)(YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned short int yytranslate[] = {
    0,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
    2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
    2,   2,   2,   17,  2,   2,   2,   28,  22,  2,   340, 341, 26,  24,  338,
    25,  339, 27,  2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   337,
    2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
    2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
    2,   2,   2,   2,   30,  2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
    2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
    2,   2,   2,   2,   21,  2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
    2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
    2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
    2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
    2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
    2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
    2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
    2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
    2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
    2,   1,   2,   3,   4,   5,   6,   7,   8,   9,   10,  11,  12,  13,  14,
    15,  16,  18,  19,  20,  23,  29,  31,  32,  33,  34,  35,  36,  37,  38,
    39,  40,  41,  42,  43,  44,  45,  46,  47,  48,  49,  50,  51,  52,  53,
    54,  55,  56,  57,  58,  59,  60,  61,  62,  63,  64,  65,  66,  67,  68,
    69,  70,  71,  72,  73,  74,  75,  76,  77,  78,  79,  80,  81,  82,  83,
    84,  85,  86,  87,  88,  89,  90,  91,  92,  93,  94,  95,  96,  97,  98,
    99,  100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113,
    114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128,
    129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143,
    144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158,
    159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173,
    174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188,
    189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203,
    204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218,
    219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233,
    234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248,
    249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263,
    264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278,
    279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293,
    294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, 307, 308,
    309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323,
    324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] = {
    0,    0,    3,    6,    10,   13,   17,   19,   23,   35,   36,   39,
    40,   45,   47,   51,   52,   54,   56,   57,   60,   61,   64,   65,
    69,   72,   77,   78,   81,   86,   87,   90,   92,   96,   97,   100,
    103,  106,  109,  112,  115,  118,  121,  123,  127,  129,  132,  134,
    138,  140,  142,  145,  150,  154,  158,  159,  161,  164,  166,  167,
    173,  177,  183,  190,  196,  197,  199,  201,  202,  204,  206,  208,
    210,  213,  216,  219,  220,  221,  223,  226,  231,  235,  237,  239,
    243,  247,  249,  251,  253,  255,  259,  263,  267,  271,  275,  279,
    282,  285,  289,  293,  297,  301,  307,  314,  321,  328,  332,  336,
    340,  344,  347,  350,  354,  358,  362,  367,  371,  376,  382,  384,
    388,  392,  394,  398,  404,  412,  419,  428,  434,  442,  449,  458,
    463,  469,  474,  479,  484,  489,  494,  499,  506,  513,  522,  531,
    536,  544,  549,  556,  561,  563,  565,  567,  568,  570,  572,  574,
    576,  578,  585,  592,  596,  600,  604,  608,  612,  616,  620,  624,
    628,  633,  640,  644,  650,  655,  661,  665,  670,  674,  679,  681,
    686,  691,  692,  696,  698,  707,  718,  728,  735,  747,  756,  760,
    761,  763,  765,  766,  768,  770,  774,  778,  784,  789,  794,  800,
    806,  807,  811,  814,  818,  822,  826,  830,  833,  837,  841,  844,
    848,  854,  857,  861,  865,  869,  873,  877,  881,  885,  889,  893,
    897,  899,  901,  903,  905,  907,  911,  915,  918,  923,  925,  927,
    929,  931,  935,  939,  943,  947,  953,  959,  961,  965,  966,  970,
    976,  977,  979,  980,  983,  986,  987,  992,  996,  998,  1009, 1023,
    1025, 1036, 1037, 1039, 1041, 1043, 1044, 1047, 1049, 1051, 1055, 1061,
    1063, 1076, 1086, 1096, 1109, 1111, 1117, 1119, 1124, 1129, 1130, 1133,
    1135, 1142, 1144, 1148, 1152, 1158, 1159, 1161, 1163, 1165, 1170, 1176,
    1178, 1182, 1190, 1192, 1201, 1202, 1208, 1209, 1212, 1215, 1218, 1221,
    1223, 1224, 1225, 1229, 1233, 1239, 1241, 1243, 1247, 1251, 1259, 1267,
    1271, 1275, 1281, 1287, 1289, 1295, 1299, 1307, 1312, 1317, 1322, 1326,
    1330, 1335, 1340, 1344, 1348, 1352, 1357, 1363, 1367, 1371, 1377, 1380,
    1384, 1389, 1395, 1400, 1405, 1410, 1414, 1418, 1419, 1420, 1423, 1424,
    1427, 1428, 1431, 1432, 1434, 1435, 1437, 1439, 1442, 1444, 1452, 1460,
    1467, 1470, 1473, 1476, 1477, 1480, 1485, 1486, 1489, 1491, 1497, 1501};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const short int yyrhs[] = {
    343, 0,   -1,  344, 337, -1,  343, 344, 337, -1,  1,   337, -1,  343, 1,
    337, -1,  345, -1,  194, 357, 358, -1,  194, 357, 358, 107, 360, 346, 347,
    351, 352, 354, 355, -1,  -1,  244, 373, -1,  -1,  111, 48,  348, 350, -1,
    373, -1,  373, 338, 348, -1,  -1,  40,  -1,  83,  -1,  -1,  246, 189, -1,
    -1,  112, 373, -1,  -1,  164, 48,  353, -1,  373, 349, -1,  373, 349, 338,
    353, -1,  -1,  137, 373, -1,  137, 373, 338, 373, -1,  -1,  128, 356, -1,
    3,   -1,  3,   338, 356, -1,  -1,  357, 33,  -1,  357, 86,  -1,  357, 87,
    -1,  357, 113, -1,  357, 213, -1,  357, 210, -1,  357, 208, -1,  357, 209,
    -1,  359, -1,  359, 338, 358, -1,  26,  -1,  373, 364, -1,  361, -1,  361,
    338, 360, -1,  362, -1,  365, -1,  3,   364, -1,  3,   339, 3,   364, -1,
    372, 363, 3,   -1,  340, 360, 341, -1,  -1,  39,  -1,  39,  3,   -1,  3,
    -1,  -1,  361, 366, 130, 362, 370, -1,  361, 213, 362, -1,  361, 213, 362,
    159, 373, -1,  361, 368, 367, 130, 362, 371, -1,  361, 155, 369, 130, 362,
    -1,  -1,  121, -1,  63,  -1,  -1,  166, -1,  136, -1,  188, -1,  108, -1,
    136, 367, -1,  188, 367, -1,  108, 367, -1,  -1,  -1,  371, -1,  159, 373,
    -1,  235, 340, 356, 341, -1,  340, 345, 341, -1,  3,   -1,  8,   -1,  3,
    339, 3,   -1,  3,   339, 26,  -1,  4,   -1,  5,   -1,  7,   -1,  6,   -1,
    373, 24,  373, -1,  373, 25,  373, -1,  373, 26,  373, -1,  373, 27,  373,
    -1,  373, 29,  373, -1,  373, 28,  373, -1,  25,  373, -1,  24,  373, -1,
    373, 12,  373, -1,  373, 10,  373, -1,  373, 11,  373, -1,  373, 20,  373,
    -1,  373, 20,  340, 345, 341, -1,  373, 20,  37,  340, 345, 341, -1,  373,
    20,  200, 340, 345, 341, -1,  373, 20,  33,  340, 345, 341, -1,  373, 21,
    373, -1,  373, 22,  373, -1,  373, 30,  373, -1,  373, 23,  373, -1,  17,
    373, -1,  18,  373, -1,  8,   9,   373, -1,  340, 373, 341, -1,  373, 15,
    157, -1,  373, 15,  18,  157, -1,  373, 15,  6,   -1,  373, 15,  18,  6,
    -1,  373, 19,  373, 36,  373, -1,  373, -1,  373, 338, 374, -1,  340, 374,
    341, -1,  374, -1,  374, 338, 375, -1,  373, 16,  340, 374, 341, -1,  340,
    374, 341, 16,  340, 375, 341, -1,  373, 18,  16,  340, 374, 341, -1,  340,
    374, 341, 18,  16,  340, 374, 341, -1,  373, 16,  340, 345, 341, -1,  340,
    374, 341, 16,  340, 345, 341, -1,  373, 18,  16,  340, 345, 341, -1,  340,
    374, 341, 18,  16,  340, 345, 341, -1,  99,  340, 345, 341, -1,  18,  99,
    340, 345, 341, -1,  328, 340, 26,  341, -1,  328, 340, 373, 341, -1,  333,
    340, 373, 341, -1,  334, 340, 373, 341, -1,  335, 340, 373, 341, -1,  336,
    340, 373, 341, -1,  324, 340, 373, 338, 373, 341, -1,  324, 340, 373, 107,
    373, 341, -1,  324, 340, 373, 338, 373, 338, 373, 341, -1,  324, 340, 373,
    107, 373, 104, 373, 341, -1,  325, 340, 373, 341, -1,  325, 340, 376, 373,
    107, 373, 341, -1,  329, 340, 373, 341, -1,  330, 340, 373, 39,  377, 341,
    -1,  331, 340, 374, 341, -1,  134, -1,  225, -1,  47,  -1,  -1,  126, -1,
    4,   -1,  89,  -1,  103, -1,  53,  -1,  326, 340, 373, 338, 378, 341, -1,
    327, 340, 373, 338, 378, 341, -1,  127, 373, 73,  -1,  127, 373, 75,  -1,
    127, 373, 76,  -1,  127, 373, 77,  -1,  127, 373, 74,  -1,  127, 373, 249,
    -1,  127, 373, 248, -1,  127, 373, 251, -1,  127, 373, 175, -1,  51,  373,
    379, 96,  -1,  51,  373, 379, 93,  373, 96,  -1,  51,  379, 96,  -1,  51,
    379, 93,  373, 96,  -1,  243, 373, 218, 373, -1,  379, 243, 373, 218, 373,
    -1,  373, 14,  373, -1,  373, 18,  14,  373, -1,  373, 13,  373, -1,  373,
    18,  13,  373, -1,  380, -1,  62,  69,  381, 3,   -1,  62,  191, 381, 3,
    -1,  -1,  117, 18,  99,  -1,  382, -1,  62,  385, 214, 381, 3,   340, 386,
    341, -1,  62,  385, 214, 381, 3,   339, 3,   340, 386, 341, -1,  62,  385,
    214, 381, 3,   340, 386, 341, 383, -1,  62,  385, 214, 381, 3,   383, -1,
    62,  385, 214, 381, 3,   339, 3,   340, 386, 341, 383, -1,  62,  385, 214,
    381, 3,   339, 3,   383, -1,  384, 363, 345, -1,  -1,  118, -1,  183, -1,
    -1,  215, -1,  387, -1,  387, 338, 386, -1,  3,   389, 388, -1,  170, 131,
    340, 356, 341, -1,  131, 340, 356, 341, -1,  119, 340, 356, 341, -1,  109,
    119, 340, 356, 341, -1,  109, 131, 340, 356, 341, -1,  -1,  388, 18,  157,
    -1,  388, 157, -1,  388, 80,  4,   -1,  388, 80,  5,   -1,  388, 80,  7,
    -1,  388, 80,  6,   -1,  388, 41,  -1,  388, 229, 131, -1,  388, 170, 131,
    -1,  388, 131, -1,  388, 57,  4,   -1,  388, 229, 340, 356, 341, -1,  45,
    391, -1,  222, 391, 393, -1,  199, 391, 393, -1,  150, 391, 393, -1,  125,
    391, 393, -1,  126, 391, 393, -1,  43,  391, 393, -1,  178, 391, 393, -1,
    89,  391, 393, -1,  103, 391, 393, -1,  78,  391, 393, -1,  71,  -1,  219,
    -1,  220, -1,  72,  -1,  248, -1,  53,  391, 394, -1,  241, 391, 394, -1,
    44,  391, -1,  240, 340, 5,   341, -1,  221, -1,  46,  -1,  149, -1,  144,
    -1,  223, 392, 394, -1,  216, 392, 394, -1,  151, 392, 394, -1,  145, 392,
    394, -1,  97,  340, 390, 341, 394, -1,  197, 340, 390, 341, 394, -1,  4,
    -1,  390, 338, 4,   -1,  -1,  340, 5,   341, -1,  340, 5,   338, 5,   341,
    -1,  -1,  44,  -1,  -1,  393, 231, -1,  393, 250, -1,  -1,  394, 53,  197,
    3,   -1,  394, 55,  3,   -1,  395, -1,  62,  172, 159, 3,   340, 356, 341,
    168, 159, 3,   -1,  62,  172, 159, 3,   340, 356, 341, 158, 20,  5,   168,
    159, 3,   -1,  396, -1,  62,  397, 119, 3,   398, 159, 3,   340, 400, 341,
    -1,  -1,  229, -1,  109, -1,  202, -1,  -1,  235, 399, -1,  320, -1,  321,
    -1,  3,   391, 349, -1,  3,   391, 349, 338, 400, -1,  401, -1,  139, 214,
    3,   107, 374, 246, 4,   338, 4,   190, 20,  7,   -1,  139, 214, 3,   107,
    374, 246, 4,   338, 4,   -1,  38,  214, 3,   107, 374, 246, 4,   338, 4,
    -1,  38,  214, 3,   107, 374, 246, 4,   338, 4,   190, 20,  7,   -1,  402,
    -1,  90,  119, 3,   159, 3,   -1,  403, -1,  90,  69,  404, 3,   -1,  90,
    191, 404, 3,   -1,  -1,  117, 99,  -1,  405, -1,  90,  385, 214, 404, 406,
    407, -1,  3,   -1,  3,   339, 3,   -1,  3,   338, 406, -1,  3,   339, 3,
    338, 406, -1,  -1,  185, -1,  50,  -1,  408, -1,  90,  172, 107, 3,   -1,
    90,  172, 5,   107, 3,   -1,  409, -1,  258, 214, 406, -1,  258, 214, 3,
    244, 172, 20,  5,   -1,  410, -1,  124, 412, 413, 3,   414, 239, 415, 411,
    -1,  -1,  159, 160, 131, 232, 417, -1,  -1,  412, 147, -1,  412, 81,  -1,
    412, 113, -1,  412, 118, -1,  128, -1,  -1,  -1,  340, 356, 341, -1,  340,
    416, 341, -1,  340, 416, 341, 338, 415, -1,  373, -1,  80,  -1,  373, 338,
    416, -1,  80,  338, 416, -1,  124, 412, 413, 3,   197, 417, 411, -1,  124,
    412, 413, 3,   414, 345, 411, -1,  3,   20,  373, -1,  3,   20,  80,  -1,
    417, 338, 3,   20,  373, -1,  417, 338, 3,   20,  80,  -1,  418, -1,  198,
    419, 278, 420, 421, -1,  198, 296, 421, -1,  198, 419, 297, 107, 3,   420,
    421, -1,  198, 62,  69,  3,   -1,  198, 62,  191, 3,   -1,  198, 62,  214,
    3,   -1,  198, 69,  3,   -1,  198, 191, 3,   -1,  198, 298, 3,   299, -1,
    198, 298, 3,   300, -1,  198, 301, 302, -1,  198, 303, 354, -1,  198, 373,
    303, -1,  198, 304, 104, 8,   -1,  198, 119, 107, 3,   420, -1,  198, 305,
    300, -1,  198, 423, 299, -1,  198, 323, 278, 420, 421, -1,  198, 289, -1,
    198, 419, 306, -1,  198, 424, 300, 421, -1,  198, 214, 300, 420, 421, -1,
    198, 295, 197, 421, -1,  198, 307, 420, 422, -1,  198, 424, 308, 421, -1,
    198, 309, 354, -1,  198, 373, 309, -1,  -1,  -1,  107, 3,   -1,  -1,  14,
    4,   -1,  -1,  14,  373, -1,  -1,  322, -1,  -1,  281, -1,  282, -1,  83,
    3,   -1,  425, -1,  82,  426, 107, 360, 346, 352, 354, -1,  82,  426, 107,
    427, 235, 360, 346, -1,  82,  426, 427, 107, 360, 346, -1,  426, 147, -1,
    426, 174, -1,  426, 118, -1,  -1,  3,   428, -1,  427, 338, 3,   428, -1,
    -1,  339, 26,  -1,  429, -1,  232, 362, 197, 430, 346, -1,  373, 20,  373,
    -1,  430, 338, 373, 20,  373, -1};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] = {
    0,    445,  445,  459,  472,  481,  493,  497,  501,  508,  509,  512,
    513,  518,  519,  521,  522,  523,  526,  527,  530,  531,  534,  535,
    538,  539,  541,  542,  543,  546,  547,  551,  552,  555,  556,  557,
    558,  559,  560,  561,  562,  563,  567,  568,  569,  573,  576,  577,
    581,  582,  586,  588,  590,  591,  594,  595,  598,  599,  600,  615,
    616,  617,  618,  619,  622,  623,  624,  627,  628,  632,  633,  634,
    638,  639,  640,  641,  644,  645,  653,  654,  659,  666,  667,  668,
    669,  670,  671,  672,  673,  675,  676,  677,  678,  679,  680,  682,
    683,  685,  686,  687,  689,  690,  691,  692,  693,  695,  696,  697,
    698,  700,  701,  702,  703,  706,  707,  708,  709,  712,  715,  716,
    717,  720,  721,  724,  725,  726,  728,  730,  731,  732,  733,  735,
    736,  746,  747,  748,  749,  750,  751,  755,  756,  757,  758,  759,
    760,  761,  762,  763,  766,  767,  768,  771,  772,  773,  774,  775,
    776,  779,  780,  784,  785,  786,  787,  788,  789,  790,  791,  792,
    796,  797,  798,  799,  802,  803,  806,  807,  810,  811,  817,  821,
    822,  825,  826,  831,  834,  838,  842,  847,  851,  856,  860,  864,
    865,  866,  869,  870,  873,  874,  879,  880,  881,  882,  883,  884,
    886,  887,  888,  889,  890,  891,  892,  893,  894,  895,  896,  897,
    898,  902,  903,  904,  905,  906,  907,  908,  909,  910,  911,  912,
    913,  914,  915,  916,  917,  918,  919,  920,  921,  923,  924,  925,
    926,  927,  928,  929,  930,  931,  932,  934,  935,  938,  939,  940,
    943,  944,  947,  948,  949,  952,  953,  955,  960,  963,  965,  973,
    977,  981,  982,  983,  984,  987,  988,  991,  992,  995,  996,  1000,
    1003, 1008, 1009, 1010, 1017, 1020, 1024, 1028, 1029, 1032, 1033, 1037,
    1040, 1044, 1045, 1046, 1047, 1050, 1051, 1052, 1056, 1059, 1060, 1067,
    1070, 1071, 1076, 1079, 1085, 1086, 1089, 1090, 1091, 1092, 1093, 1096,
    1096, 1099, 1100, 1103, 1104, 1108, 1109, 1110, 1111, 1114, 1118, 1123,
    1126, 1129, 1132, 1137, 1140, 1141, 1142, 1143, 1144, 1145, 1146, 1147,
    1148, 1149, 1150, 1151, 1152, 1153, 1154, 1155, 1156, 1157, 1158, 1159,
    1160, 1161, 1162, 1163, 1164, 1165, 1166, 1168, 1172, 1173, 1176, 1177,
    1180, 1181, 1183, 1184, 1187, 1188, 1189, 1192, 1195, 1197, 1202, 1206,
    1211, 1212, 1213, 1214, 1218, 1219, 1222, 1223, 1226, 1229, 1232, 1233};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] = {
    "$end",                 "error",
    "$undefined",           "NAME",
    "STRING",               "INTNUM",
    "BOOL",                 "APPROXNUM",
    "USERVAR",              "ASSIGN",
    "OR",                   "XOR",
    "ANDOP",                "REGEXP",
    "LIKE",                 "IS",
    "IN",                   "'!'",
    "NOT",                  "BETWEEN",
    "COMPARISON",           "'|'",
    "'&'",                  "SHIFT",
    "'+'",                  "'-'",
    "'*'",                  "'/'",
    "'%'",                  "MOD",
    "'^'",                  "UMINUS",
    "ADD",                  "ALL",
    "ALTER",                "ANALYZE",
    "AND",                  "ANY",
    "APPEND",               "AS",
    "ASC",                  "AUTO_INCREMENT",
    "BEFORE",               "BIGINT",
    "BINARY",               "BIT",
    "BLOB",                 "BOTH",
    "BY",                   "CALL",
    "CASCADE",              "CASE",
    "CHANGE",               "CHAR",
    "CHECK",                "COLLATE",
    "COLUMN",               "COMMENT",
    "CONDITION",            "CONSTRAINT",
    "CONTINUE",             "CONVERT",
    "CREATE",               "CROSS",
    "CURRENT_DATE",         "CURRENT_TIME",
    "CURRENT_TIMESTAMP",    "CURRENT_USER",
    "CURSOR",               "DATABASE",
    "DATABASES",            "DATE",
    "DATETIME",             "DAY_HOUR",
    "DAY",                  "DAY_MICROSECOND",
    "DAY_MINUTE",           "DAY_SECOND",
    "DECIMAL",              "DECLARE",
    "DEFAULT",              "DELAYED",
    "DELETE",               "DESC",
    "DESCRIBE",             "DETERMINISTIC",
    "DISTINCT",             "DISTINCTROW",
    "DIV",                  "DOUBLE",
    "DROP",                 "DUAL",
    "EACH",                 "ELSE",
    "ELSEIF",               "ENCLOSED",
    "END",                  "ENUM",
    "ESCAPED",              "EXISTS",
    "EXIT",                 "EXPLAIN",
    "FETCH",                "FLOAT",
    "FOR",                  "FORCE",
    "FOREIGN",              "FROM",
    "FULL",                 "FULLTEXT",
    "GRANT",                "GROUP",
    "HAVING",               "HIGH_PRIORITY",
    "HOUR_MICROSECOND",     "HOUR_MINUTE",
    "HOUR_SECOND",          "IF",
    "IGNORE",               "INDEX",
    "INFILE",               "INNER",
    "INOUT",                "INSENSITIVE",
    "INSERT",               "INT",
    "INTEGER",              "INTERVAL",
    "INTO",                 "ITERATE",
    "JOIN",                 "KEY",
    "KEYS",                 "KILL",
    "LEADING",              "LEAVE",
    "LEFT",                 "LIMIT",
    "LINES",                "LOAD",
    "LOCALTIME",            "LOCALTIMESTAMP",
    "LOCK",                 "LONG",
    "LONGBLOB",             "LONGTEXT",
    "LOOP",                 "LOW_PRIORITY",
    "MATCH",                "MEDIUMBLOB",
    "MEDIUMINT",            "MEDIUMTEXT",
    "MINUTE_MICROSECOND",   "MINUTE_SECOND",
    "MODIFIES",             "NATURAL",
    "NO_WRITE_TO_BINLOG",   "NULLX",
    "NUMBER",               "ON",
    "DUPLICATE",            "OPTIMIZE",
    "OPTION",               "OPTIONALLY",
    "ORDER",                "OUT",
    "OUTER",                "OUTFILE",
    "PARTITIONED",          "PRECISION",
    "PRIMARY",              "PROCEDURE",
    "PROJECTION",           "PURGE",
    "QUICK",                "QUARTER",
    "READ",                 "READS",
    "REAL",                 "REFERENCES",
    "RELEASE",              "RENAME",
    "REPEAT",               "REPLACE",
    "REQUIRE",              "RESTRICT",
    "RETURN",               "REVOKE",
    "RIGHT",                "ROLLUP",
    "SAMPLE",               "SCHEMA",
    "SCHEMAS",              "SECOND_MICROSECOND",
    "SELECT",               "SENSITIVE",
    "SEPARATOR",            "SET",
    "SHOW",                 "SMALLINT",
    "SOME",                 "SONAME",
    "SPATIAL",              "SPECIFIC",
    "SQL",                  "SQLEXCEPTION",
    "SQLSTATE",             "SQLWARNING",
    "SQL_BIG_RESULT",       "SQL_CALC_FOUND_ROWS",
    "SQL_SMALL_RESULT",     "SSL",
    "STARTING",             "STRAIGHT_JOIN",
    "TABLE",                "TEMPORARY",
    "TEXT",                 "TERMINATED",
    "THEN",                 "TIME",
    "TIMESTAMP",            "TINYBLOB",
    "TINYINT",              "TINYTEXT",
    "TO",                   "TRAILING",
    "TRIGGER",              "UNDO",
    "UNION",                "UNIQUE",
    "UNLOCK",               "UNSIGNED",
    "UPDATE",               "USAGE",
    "USE",                  "USING",
    "UTC_DATE",             "UTC_TIME",
    "UTC_TIMESTAMP",        "VALUES",
    "VARBINARY",            "VARCHAR",
    "VARYING",              "WHEN",
    "WHERE",                "WHILE",
    "WITH",                 "WRITE",
    "YEAR",                 "YEAR_MONTH",
    "ZEROFILL",             "WEEK",
    "DO",                   "MAX_QUERIES_PER_HOUR",
    "MAX_UPDATES_PER_HOUR", "MAX_CONNECTIONS_PER_HOUR",
    "MAX_USER_CONNECTIONS", "USER",
    "TRUNCATE",             "FAST",
    "MEDIUM",               "EXTENDED",
    "CHANGED",              "LEAVES",
    "MASTER",               "QUERY",
    "CACHE",                "SLAVE",
    "BEGINT",               "COMMIT",
    "START",                "TRANSACTION",
    "NO",                   "CHAIN",
    "AUTOCOMMIT",           "SAVEPOINT",
    "ROLLBACK",             "LOCAL",
    "TABLES",               "ISOLATION",
    "LEVEL",                "GLOBAL",
    "SESSION",              "UNCOMMITTED",
    "COMMITTED",            "REPEATABLE",
    "SERIALIZABLE",         "IDENTIFIED",
    "PASSWORD",             "PRIVILEGES",
    "BACKUP",               "CHECKSUM",
    "REPAIR",               "USE_FRM",
    "RESTORE",              "CHARACTER",
    "COLLATION",            "COLUMNS",
    "ENGINE",               "LOGS",
    "STATUS",               "STORAGE",
    "ENGINES",              "ERRORS",
    "GRANTS",               "INNODB",
    "PROCESSLIST",          "TRIGGERS",
    "VARIABLES",            "WARNINGS",
    "FLUSH",                "HOSTS",
    "DES_KEY_FILE",         "USER_RESOURCES",
    "CONNECTION",           "RESET",
    "PREPARE",              "DEALLOCATE",
    "EXECUTE",              "WORK",
    "BTREE",                "HASH",
    "BDB",                  "OPEN",
    "FSUBSTRING",           "FTRIM",
    "FDATE_ADD",            "FDATE_SUB",
    "FCOUNT",               "FUPPER",
    "FCAST",                "FCOALESCE",
    "FCONVERT",             "FSUM",
    "FAVG",                 "FMIN",
    "FMAX",                 "';'",
    "','",                  "'.'",
    "'('",                  "')'",
    "$accept",              "stmt_list",
    "stmt",                 "select_stmt",
    "opt_where",            "opt_groupby",
    "groupby_list",         "opt_asc_desc",
    "opt_with_rollup",      "opt_having",
    "opt_orderby",          "orderby_list",
    "opt_limit",            "opt_into_list",
    "column_list",          "select_opts",
    "select_expr_list",     "select_expr",
    "table_references",     "table_reference",
    "table_factor",         "opt_as",
    "opt_as_alias",         "join_table",
    "opt_inner_cross",      "opt_outer",
    "left_right_full",      "opt_left_or_right_outer",
    "opt_join_condition",   "join_condition",
    "table_subquery",       "expr",
    "expr_list",            "opt_expr_list",
    "trim_ltb",             "cast_data_type",
    "interval_exp",         "case_list",
    "create_database_stmt", "opt_if_not_exists",
    "create_table_stmt",    "create_select_statement",
    "opt_ignore_replace",   "opt_temporary",
    "create_col_list",      "create_definition",
    "column_atts",          "data_type",
    "enum_list",            "opt_length",
    "opt_binary",           "opt_uz",
    "opt_csc",              "create_projection_stmt",
    "create_index_stmt",    "index_att",
    "opt_using_type",       "index_type",
    "index_col_list",       "load_table_stmt",
    "drop_index_stmt",      "drop_database_stmt",
    "opt_if_exists",        "drop_table_stmt",
    "table_list",           "opt_rc",
    "drop_projection_stmt", "truncate_table_stmt",
    "insert_stmt",          "opt_ondupupdate",
    "insert_opts",          "opt_into",
    "opt_col_names",        "insert_vals_list",
    "insert_vals",          "insert_asgn_list",
    "show_stmt",            "opt_full",
    "opt_from",             "opt_like_string",
    "opt_like_expr",        "opt_bdb",
    "opt_trans_level",      "delete_stmt",
    "delete_opts",          "delete_list",
    "opt_dot_star",         "update_stmt",
    "update_set_list",      YY_NULL};
#endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short int yyr1[] = {
    0,   342, 343, 343, 343, 343, 344, 345, 345, 346, 346, 347, 347, 348, 348,
    349, 349, 349, 350, 350, 351, 351, 352, 352, 353, 353, 354, 354, 354, 355,
    355, 356, 356, 357, 357, 357, 357, 357, 357, 357, 357, 357, 358, 358, 358,
    359, 360, 360, 361, 361, 362, 362, 362, 362, 363, 363, 364, 364, 364, 365,
    365, 365, 365, 365, 366, 366, 366, 367, 367, 368, 368, 368, 369, 369, 369,
    369, 370, 370, 371, 371, 372, 373, 373, 373, 373, 373, 373, 373, 373, 373,
    373, 373, 373, 373, 373, 373, 373, 373, 373, 373, 373, 373, 373, 373, 373,
    373, 373, 373, 373, 373, 373, 373, 373, 373, 373, 373, 373, 373, 374, 374,
    374, 375, 375, 373, 373, 373, 373, 373, 373, 373, 373, 373, 373, 373, 373,
    373, 373, 373, 373, 373, 373, 373, 373, 373, 373, 373, 373, 373, 376, 376,
    376, 377, 377, 377, 377, 377, 377, 373, 373, 378, 378, 378, 378, 378, 378,
    378, 378, 378, 373, 373, 373, 373, 379, 379, 373, 373, 373, 373, 344, 380,
    380, 381, 381, 344, 382, 382, 382, 382, 382, 382, 383, 384, 384, 384, 385,
    385, 386, 386, 387, 387, 387, 387, 387, 387, 388, 388, 388, 388, 388, 388,
    388, 388, 388, 388, 388, 388, 388, 389, 389, 389, 389, 389, 389, 389, 389,
    389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389,
    389, 389, 389, 389, 389, 389, 389, 390, 390, 391, 391, 391, 392, 392, 393,
    393, 393, 394, 394, 394, 344, 395, 395, 344, 396, 397, 397, 397, 397, 398,
    398, 399, 399, 400, 400, 344, 401, 401, 401, 401, 344, 402, 344, 403, 403,
    404, 404, 344, 405, 406, 406, 406, 406, 407, 407, 407, 344, 408, 408, 344,
    409, 409, 344, 410, 411, 411, 412, 412, 412, 412, 412, 413, 413, 414, 414,
    415, 415, 416, 416, 416, 416, 410, 410, 417, 417, 417, 417, 344, 418, 418,
    418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 418,
    418, 418, 418, 418, 418, 418, 418, 418, 418, 418, 419, 420, 420, 421, 421,
    422, 422, 423, 423, 424, 424, 424, 344, 344, 425, 425, 425, 426, 426, 426,
    426, 427, 427, 428, 428, 344, 429, 430, 430};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] = {
    0,  2,  2, 3,  2,  3, 1, 3, 11, 0,  2, 0,  4, 1, 3, 0, 1, 1, 0, 2, 0, 2, 0,
    3,  2,  4, 0,  2,  4, 0, 2, 1,  3,  0, 2,  2, 2, 2, 2, 2, 2, 2, 1, 3, 1, 2,
    1,  3,  1, 1,  2,  4, 3, 3, 0,  1,  2, 1,  0, 5, 3, 5, 6, 5, 0, 1, 1, 0, 1,
    1,  1,  1, 2,  2,  2, 0, 0, 1,  2,  4, 3,  1, 1, 3, 3, 1, 1, 1, 1, 3, 3, 3,
    3,  3,  3, 2,  2,  3, 3, 3, 3,  5,  6, 6,  6, 3, 3, 3, 3, 2, 2, 3, 3, 3, 4,
    3,  4,  5, 1,  3,  3, 1, 3, 5,  7,  6, 8,  5, 7, 6, 8, 4, 5, 4, 4, 4, 4, 4,
    4,  6,  6, 8,  8,  4, 7, 4, 6,  4,  1, 1,  1, 0, 1, 1, 1, 1, 1, 6, 6, 3, 3,
    3,  3,  3, 3,  3,  3, 3, 4, 6,  3,  5, 4,  5, 3, 4, 3, 4, 1, 4, 4, 0, 3, 1,
    8,  10, 9, 6,  11, 8, 3, 0, 1,  1,  0, 1,  1, 3, 3, 5, 4, 4, 5, 5, 0, 3, 2,
    3,  3,  3, 3,  2,  3, 3, 2, 3,  5,  2, 3,  3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1,
    1,  1,  1, 3,  3,  2, 4, 1, 1,  1,  1, 3,  3, 3, 3, 5, 5, 1, 3, 0, 3, 5, 0,
    1,  0,  2, 2,  0,  4, 3, 1, 10, 13, 1, 10, 0, 1, 1, 1, 0, 2, 1, 1, 3, 5, 1,
    12, 9,  9, 12, 1,  5, 1, 4, 4,  0,  2, 1,  6, 1, 3, 3, 5, 0, 1, 1, 1, 4, 5,
    1,  3,  7, 1,  8,  0, 5, 0, 2,  2,  2, 2,  1, 0, 0, 3, 3, 5, 1, 1, 3, 3, 7,
    7,  3,  3, 5,  5,  1, 5, 3, 7,  4,  4, 4,  3, 3, 4, 4, 3, 3, 3, 4, 5, 3, 3,
    5,  2,  3, 4,  5,  4, 4, 4, 3,  3,  0, 0,  2, 0, 2, 0, 2, 0, 1, 0, 1, 1, 2,
    1,  7,  7, 6,  2,  2, 2, 0, 2,  4,  0, 2,  1, 5, 3, 5};

/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const unsigned char yydprec[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const unsigned char yymerger[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

/* YYDEFACT[S] -- default reduction number in state S.  Performed when
   YYTABLE doesn't specify something else to do.  Zero means the default
   is an error.  */
static const unsigned short int yydefact[] = {
    0,   0,   0,   194, 375, 0,   194, 306, 0,   33,  355, 0,   0,   0,   0,
    6,   178, 183, 260, 263, 275, 280, 282, 287, 296, 299, 302, 327, 368, 380,
    4,   0,   181, 267, 0,   181, 268, 195, 266, 0,   0,   0,   367, 285, 0,
    0,   285, 0,   312, 0,   0,   81,  85,  86,  88,  87,  82,  0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   365, 366, 346, 0,   358, 0,   0,
    26,  0,   0,   356, 26,  363, 0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   58,  0,   0,   54,  0,   1,
    0,   0,   2,   0,   0,   0,   0,   0,   181, 0,   378, 0,   374, 372, 373,
    0,   0,   0,   0,   0,   0,   0,   285, 308, 309, 310, 311, 307, 0,   0,
    44,  34,  35,  36,  37,  40,  41,  39,  38,  7,   42,  58,  0,   0,   109,
    0,   110, 96,  95,  0,   0,   0,   0,   0,   0,   334, 0,   0,   335, 356,
    358, 0,   329, 0,   338, 0,   339, 0,   343, 0,   360, 353, 356, 0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   340, 354, 356, 0,   347, 344, 358, 358, 57,  0,   0,   50,
    0,   0,   46,  48,  49,  0,   55,  0,   289, 300, 5,   3,   0,   0,   179,
    0,   180, 0,   269, 0,   376, 58,  9,   0,   0,   0,   286, 283, 0,   0,
    297, 284, 0,   313, 0,   0,   0,   45,  83,  84,  111, 0,   0,   0,   0,
    170, 0,   331, 332, 333, 0,   356, 358, 350, 359, 336, 337, 27,  341, 357,
    0,   351, 358, 0,   150, 148, 149, 0,   0,   0,   0,   0,   0,   0,   0,
    118, 0,   0,   0,   0,   0,   0,   0,   112, 0,   98,  99,  97,  176, 174,
    115, 0,   113, 0,   0,   0,   0,   0,   0,   0,   0,   0,   100, 105, 106,
    108, 89,  90,  91,  92,  94,  93,  107, 358, 0,   348, 352, 56,  58,  80,
    53,  66,  71,  65,  69,  75,  70,  0,   0,   0,   67,  0,   9,   52,  0,
    0,   0,   0,   182, 0,   191, 0,   0,   379, 0,   0,   22,  0,   9,   378,
    281, 298, 289, 293, 0,   0,   0,   0,   9,   43,  0,   0,   0,   168, 0,
    0,   131, 342, 349, 0,   361, 345, 0,   0,   143, 0,   0,   0,   133, 134,
    145, 151, 147, 135, 136, 137, 138, 120, 119, 0,   0,   116, 114, 0,   0,
    177, 175, 0,   0,   0,   0,   0,   0,   328, 356, 51,  67,  67,  67,  0,
    60,  47,  0,   68,  0,   0,   0,   381, 0,   291, 290, 0,   31,  0,   192,
    193, 0,   0,   187, 54,  271, 272, 270, 0,   10,  0,   26,  9,   371, 377,
    295, 294, 288, 0,   304, 0,   0,   304, 0,   11,  131, 172, 0,   171, 0,
    28,  0,   0,   0,   0,   0,   0,   153, 156, 154, 155, 152, 0,   0,   0,
    127, 123, 0,   0,   117, 0,   0,   0,   101, 358, 74,  72,  73,  0,   0,
    76,  0,   100, 0,   0,   0,   0,   0,   0,   191, 0,   0,   0,   0,   0,
    0,   196, 0,   0,   0,   369, 370, 0,   0,   0,   321, 314, 0,   304, 322,
    0,   0,   20,  169, 173, 0,   140, 0,   139, 0,   0,   157, 158, 146, 0,
    121, 0,   0,   129, 125, 104, 102, 103, 330, 63,  61,  0,   0,   59,  77,
    0,   0,   301, 292, 0,   32,  0,   0,   0,   189, 249, 249, 249, 238, 249,
    228, 231, 249, 249, 0,   249, 249, 249, 240, 252, 239, 249, 252, 249, 0,
    249, 252, 229, 230, 237, 249, 252, 0,   249, 232, 204, 0,   0,   0,   0,
    0,   191, 0,   190, 0,   23,  15,  324, 323, 0,   0,   318, 317, 0,   303,
    0,   0,   0,   22,  0,   0,   144, 159, 163, 160, 161, 162, 167, 165, 164,
    166, 128, 0,   124, 0,   0,   78,  0,   62,  100, 278, 0,   0,   0,   0,
    254, 235, 217, 257, 254, 254, 0,   254, 254, 254, 253, 257, 254, 257, 254,
    0,   254, 257, 254, 257, 0,   257, 198, 0,   0,   0,   0,   0,   186, 197,
    249, 0,   16,  17,  24,  0,   0,   0,   0,   315, 277, 18,  13,  21,  26,
    142, 141, 122, 130, 126, 0,   0,   0,   261, 191, 0,   223, 233, 227, 225,
    247, 0,   226, 221, 222, 244, 220, 243, 224, 0,   219, 242, 218, 241, 0,
    234, 0,   211, 0,   0,   214, 206, 0,   0,   0,   0,   201, 200, 0,   15,
    264, 0,   0,   326, 325, 320, 319, 0,   0,   0,   12,  0,   29,  79,  0,
    0,   188, 0,   250, 255, 256, 0,   0,   0,   257, 257, 236, 205, 215, 207,
    208, 210, 209, 213, 212, 0,   202, 203, 199, 273, 25,  305, 316, 0,   19,
    14,  0,   8,   279, 0,   0,   0,   259, 248, 245, 246, 0,   0,   276, 30,
    262, 251, 258, 216, 274};

/* YYPDEFGOTO[NTERM-NUM].  */
static const short int yydefgoto[] = {
    -1,  13,  14,  15,  371, 542, 701, 694, 760, 633, 461, 620, 171, 797, 448,
    50,  144, 145, 226, 227, 228, 232, 224, 229, 354, 439, 355, 434, 568, 569,
    102, 300, 192, 556, 293, 492, 485, 156, 16,  110, 17,  453, 454, 39,  525,
    526, 682, 610, 721, 660, 671, 716, 717, 18,  19,  40,  367, 457, 691, 20,
    21,  22,  122, 23,  234, 467, 24,  25,  26,  535, 48,  133, 381, 538, 628,
    469, 27,  96,  175, 167, 286, 97,  98,  28,  41,  120, 245, 29,  357};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -537
static const short int yypact[] = {
    255,  -269, -155, 217,  -537, 73,   176,  -537, -85,  -537, 697,  -1,
    -69,  1931, -173, -537, -537, -537, -537, -537, -537, -537, -537, -537,
    -537, -537, -537, -537, -537, -537, -537, 187,  102,  -537, 85,   102,
    -537, -537, -537, 43,   141,  14,   -537, 148,  271,  19,   148,  70,
    293,  291,  720,  -42,  -537, -537, -537, -537, 297,  1098, 1257, 1098,
    1098, 274,  -49,  309,  -21,  222,  329,  40,   -537, -537, -537, 149,
    356,  368,  78,   235,  277,  75,   275,  235,  -537, 107,  46,   52,
    57,   58,   60,   64,   65,   72,   82,   93,   94,   95,   1280, 1900,
    18,   111,  -235, 4,    9,    199,  376,  413,  -537, 81,   104,  -537,
    330,  424,  440,  441,  442,  102,  444,  109,  2,    -537, -537, -537,
    -97,  351,  448,  295,  345,  452,  461,  148,  -537, -537, -537, -537,
    -537, 462,  360,  -537, -537, -537, -537, -537, -537, -537, -537, -537,
    369,  143,  2415, 156,  1098, 928,  139,  928,  -537, -537, 1098, 1935,
    -36,  479,  480,  481,  -537, 294,  482,  -537, 275,  356,  487,  -537,
    -74,  -537, 1098, -537, 484,  -537, 490,  488,  -537, 275,  1098, 28,
    1098, 1098, 805,  1098, 1098, 1280, 1098, 1098, 1098, 1098, 1280, 76,
    153,  1098, 1098, 1098, 1098, 1098, 49,   158,  307,  1098, 453,  1098,
    1098, 1098, 1098, 1098, 1098, 1098, 1098, 1098, 1098, -537, -537, 275,
    394,  -537, -537, 356,  356,  -537, 502,  503,  -537, 166,  167,  100,
    -537, -537, 1098, -537, 506,  -215, -537, -537, -537, 1280, 411,  -537,
    174,  -537, 512,  281,  492,  -537, 27,   276,  -216, -1,   518,  -537,
    -537, 520,  522,  -537, -537, 523,  -174, 1280, -1,   835,  -537, -537,
    -537, 2499, 294,  2063, -32,  1098, -537, 1098, -537, -537, -537, 183,
    275,  356,  -537, -537, -537, -537, 1734, -537, -537, 1098, -537, 356,
    1713, -537, -537, -537, 1429, 1098, 1774, 1816, 189,  1450, 1471, 2450,
    1837, 198,  1492, 1513, 1534, 1611, 200,  1280, -537, 56,   2561, 1753,
    2579, 2597, 2597, -537, 32,   -537, 865,  1098, 1098, 213,  2472, 214,
    215,  218,  865,  1040, 521,  615,  643,  241,  241,  529,  529,  529,
    529,  -537, 356,  557,  -537, -537, -537, 38,   -537, -537, -537, -537,
    -537, -537, 97,   -537, -1,   -1,   432,  397,  2520, -207, -537, 399,
    523,  583,  341,  -537, 585,  -100, -20,  430,  -537, 220,  1098, 427,
    -1,   276,  109,  -537, -537, -34,  -28,  589,  585,  -168, 349,  276,
    -537, 256,  1098, 1098, -537, 2284, 2120, -537, -537, -537, 1098, 2499,
    -537, 1098, 1098, -537, 2217, 469,  469,  -537, -537, -537, 386,  -537,
    -537, -537, -537, -537, 56,   -537, 266,  596,  -537, -537, 272,  278,
    2597, 2597, 865,  1098, 294,  294,  294,  279,  -537, 275,  -537, 397,
    397,  397,  485,  457,  -537, -1,   -537, 493,  453,  1098, -537, 598,
    -537, 287,  628,  296,  292,  -537, -537, 632,  133,  -537, 376,  -537,
    -537, -537, 633,  2499, 600,  235,  276,  -537, -537, -537, -537, -537,
    626,  -134, 308,  311,  495,  648,  544,  554,  2499, 2363, -537, 1098,
    2499, 1314, 1339, 1098, 1098, 315,  316,  -537, -537, -537, -537, -537,
    318,  865,  320,  -537, -537, 322,  323,  987,  333,  335,  336,  -537,
    356,  -537, -537, -537, -1,   1098, -77,  -1,   86,   2541, 673,  523,
    342,  585,  54,   -90,  2123, -92,  339,  352,  550,  344,  355,  294,
    354,  1098, -537, -537, 895,  535,  686,  -537, -537, 919,  495,  -537,
    358,  649,  586,  -537, 2499, 1098, -537, 1098, -537, 1638, 1962, -537,
    -537, -537, 365,  361,  366,  865,  -537, -537, -537, -537, -537, -537,
    -537, 2499, 1098, 370,  -537, -537, -26,  453,  -537, -537, 704,  -537,
    691,  553,  133,  -537, 377,  377,  377,  -537, 377,  -537, -537, 377,
    377,  379,  377,  377,  377,  -537, 672,  -537, 377,  672,  377,  380,
    377,  672,  -537, -537, -537, 377,  672,  390,  377,  -537, -537, 391,
    392,  585,  585,  393,  -105, 133,  -537, 731,  -537, 2384, -537, 2499,
    604,  716,  401,  1858, 402,  -537, 736,  1098, 1098, 427,  1671, 1692,
    -537, -537, -537, -537, -537, -537, -537, -537, -537, -537, -537, 1280,
    -537, 406,  408,  2499, 585,  -537, 125,  560,  747,  751,  414,  752,
    -537, -537, -537, -537, -537, -537, 754,  -537, -537, -537, -537, -537,
    -537, -537, -537, 754,  -537, -537, -537, -537, 755,  -537, 454,  585,
    585,  415,  420,  585,  -537, -537, 377,  422,  -537, -537, 426,  530,
    1068, 919,  919,  431,  575,  524,  1879, 2499, 235,  -537, -537, -537,
    -537, -537, 433,  748,  605,  -537, -64,  -198, -94,  234,  -94,  -94,
    -537, -124, -94,  -94,  -94,  234,  -94,  234,  -94,  -107, -94,  234,
    -94,  234,  434,  234,  619,  -537, 781,  421,  -537, -537, 659,  -116,
    450,  451,  -537, -537, 458,  127,  -537, 1098, 589,  -537, 2499, -537,
    -537, 311,  774,  606,  -537, 1098, 676,  -537, 794,  655,  -537, 810,
    -537, -537, -537, 620,  815,  816,  -537, -537, -537, -537, -537, -537,
    -537, -537, -537, -537, -537, 585,  -537, -537, -537, 483,  -537, 486,
    -537, 818,  -537, -537, 585,  -537, -537, 823,  491,  824,  -537, -537,
    234,  234,  494,  731,  -537, -537, -537, -537, -537, -537, -537};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] = {
    -537, -537, 821,  -91,  -55,  -537, 67,   87,   -537, -537, 204,  96,
    -78,  -537, -376, -537, 584,  -537, -31,  -537, -8,   395,  -130, -537,
    -537, -184, -537, -537, -537, 280,  -537, -10,  -179, 197,  -537, -537,
    446,  696,  -537, 21,   -537, -498, -537, 840,  -536, -537, -537, -537,
    179,  1419, -343, -136, -278, -537, -537, -537, -537, -537, 48,   -537,
    -537, -537, -2,   -537, -243, -537, -537, -537, -537, -403, -537, -537,
    -537, 101,  -347, 110,  -537, -537, 51,   -157, -537, -537, -537, -537,
    -537, 749,  500,  -537, -537};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -384
static const short int yytable[] = {
    95,   176,  99,   101,  470,  246,  301,  221,  278,  225,  249,  306,
    99,   449,  378,  784,  262,  115,  449,  372,  157,  579,  465,  379,
    124,  533,  9,    611,  449,  359,  221,  51,   52,   53,   54,   55,
    56,   370,  416,  612,  146,  221,  658,  222,  126,  57,   58,   149,
    151,  152,  153,  155,  59,   60,   449,  315,  112,  269,  362,  31,
    270,  387,  340,  341,  388,  219,  222,  316,  30,   539,  275,  471,
    414,  220,  415,  289,  42,   222,  450,  61,   382,  689,  566,  450,
    191,  247,  193,  194,  195,  196,  197,  198,  199,  450,  200,  201,
    202,  203,  204,  205,  206,  207,  208,  209,  210,  211,  212,  203,
    204,  205,  206,  207,  208,  209,  210,  211,  212,  444,  688,  450,
    393,  116,  250,  360,  361,  257,  125,  64,   413,  49,   396,  441,
    117,  566,  242,  629,  520,  769,  265,  419,  767,  575,  158,  768,
    267,  103,  203,  204,  205,  206,  207,  208,  209,  210,  211,  212,
    770,  466,  567,  263,  282,  118,  290,  346,  107,  159,  380,  692,
    288,  292,  294,  295,  297,  298,  299,  385,  302,  303,  304,  305,
    191,  428,  264,  310,  311,  312,  313,  314,  119,  417,  108,  322,
    327,  328,  329,  330,  331,  332,  333,  334,  335,  336,  337,  9,
    534,  431,  317,  271,  347,  567,  693,  271,  576,  430,  773,  277,
    766,  774,  373,  109,  356,  348,  577,  343,  785,  280,  281,  418,
    287,  383,  -64,  773,  -184, 432,  775,  427,  349,  685,  686,  451,
    452,  250,  521,  498,  111,  43,   368,  505,  506,  507,  578,  146,
    522,  291,  673,  350,  1,    113,  677,  389,  114,  390,  -378, 679,
    523,  121,  338,  208,  209,  210,  211,  212,  573,  -185, 123,  395,
    710,  51,   52,   53,   54,   55,   56,   400,  127,  433,  32,   771,
    351,  772,  472,  57,   58,   2,    134,  44,   215,  147,  59,   60,
    455,  456,  442,  524,  360,  361,  148,  744,  745,  420,  421,  748,
    160,  352,  555,  216,  191,  3,    463,  161,  319,  320,  436,  321,
    217,  61,   33,   392,  474,  162,  -382, 497,  163,  500,  501,  502,
    -265, 4,    5,    100,  164,  462,  100,  223,  435,  6,    165,  563,
    45,   100,  755,  756,  82,   83,   84,   85,   86,   87,   88,   89,
    459,  90,   91,   92,   93,   -58,  369,  46,   94,   -383, 166,  168,
    170,  64,   128,  173,  476,  477,  650,  7,    169,  172,  174,  530,
    480,  177,  178,  481,  482,  34,   487,  37,   179,  725,  8,    727,
    230,  180,  181,  731,  182,  733,  554,  735,  183,  184,  129,  531,
    35,   806,  218,  130,  185,  499,  307,  231,  233,  308,  235,  36,
    809,  131,  186,  -382, -382, 779,  780,  781,  782,  510,  512,  513,
    37,   187,  188,  189,  618,  237,  353,  488,  132,  236,  238,  239,
    240,  241,  38,   243,  244,  9,    251,  252,  254,  10,   253,  255,
    51,   52,   53,   54,   55,   56,   -383, -383, 256,  258,  649,  259,
    555,  544,  57,   58,   736,  549,  550,  489,  260,  59,   60,   266,
    504,  261,  272,  273,  274,  276,  323,  11,   9,    490,  324,  279,
    283,  284,  309,  737,  804,  805,  318,  565,  564,  339,  285,  570,
    61,   342,  343,  344,  345,  358,  363,  738,  491,  12,   364,  365,
    366,  154,  368,  621,  370,  374,  623,  375,  391,  376,  377,  627,
    718,  719,  403,  722,  723,  724,  739,  634,  726,  635,  728,  407,
    730,  412,  732,  204,  205,  206,  207,  208,  209,  210,  211,  212,
    64,   422,  424,  425,  651,  -131, 426,  212,  429,  654,  437,  438,
    -131, -131, -131, -131, -131, -131, -131, 443,  -131, -131, -131, -131,
    -131, -131, -131, -131, -131, -131, -131, -131, -131, 740,  445,  446,
    447,  458,  -131, 460,  468,  -131, -131, 473,  484,  475,  82,   83,
    84,   85,   86,   87,   88,   89,   493,  90,   91,   92,   93,   741,
    494,  495,  94,   508,  509,  -131, 514,  496,  503,  702,  703,  511,
    742,  515,  762,  -131, -131, -131, -131, -131, 516,  518,  517,  519,
    528,  -131, 205,  206,  207,  208,  209,  210,  211,  212,  532,  -131,
    529,  536,  -131, 537,  540,  325,  533,  541,  551,  552,  -131, 553,
    557,  -131, -131, 558,  559,  -131, -131, 206,  207,  208,  209,  210,
    211,  212,  560,  -131, 561,  562,  572,  613,  574,  615,  -131, 743,
    -131, 616,  754,  627,  627,  625,  -131, -131, 614,  617,  619,  624,
    630,  631,  632,  647,  51,   52,   53,   54,   55,   56,   646,  648,
    655,  -131, 652,  656,  657,  -131, 57,   58,   670,  659,  -131, 666,
    675,  59,   60,   51,   52,   53,   54,   55,   56,   -131, 680,  683,
    684,  687,  690,  695,  696,  57,   58,   697,  700,  621,  -131, 699,
    59,   60,   135,  708,  61,   709,  711,  702,  712,  136,  713,  714,
    746,  715,  720,  62,   734,  747,  752,  750,  751,  758,  63,   -131,
    764,  757,  759,  61,   -131, 765,  763,  776,  777,  82,   83,   84,
    85,   86,   87,   88,   89,   778,  90,   91,   92,   93,   783,  786,
    787,  326,  793,  794,  64,   -131, -131, 788,  -131, 798,  -131, -131,
    796,  -131, 137,  138,  51,   52,   53,   54,   55,   56,   799,  800,
    65,   801,  802,  64,   803,  807,  57,   58,   534,  808,  810,  812,
    795,  59,   60,   296,  811,  139,  106,  813,  789,  704,  51,   52,
    53,   54,   55,   56,   707,  384,  47,   790,  486,  527,  653,  268,
    57,   58,   729,  814,  61,   -131, 792,  59,   60,   135,  791,  -131,
    0,    248,  0,    0,    51,   52,   53,   54,   55,   56,   464,  0,
    0,    0,    0,    0,    0,    0,    57,   58,   0,    0,    61,   0,
    66,   59,   60,   -131, -131, 0,    0,    -131, 0,    0,    51,   52,
    53,   54,   55,   56,   64,   0,    0,    0,    0,    0,    0,    67,
    57,   58,   0,    0,    61,   0,    0,    59,   60,   0,    51,   52,
    53,   54,   55,   56,   140,  141,  142,  0,    0,    143,  64,   0,
    57,   58,   0,    0,    0,    0,    0,    59,   60,   0,    61,   201,
    202,  203,  204,  205,  206,  207,  208,  209,  210,  211,  212,  0,
    0,    0,    0,    0,    64,   0,    0,    0,    0,    0,    61,   0,
    0,    0,    0,    622,  0,    0,    68,   69,   0,    0,    0,    0,
    0,    0,    70,   0,    0,    0,    0,    0,    71,   72,   64,   73,
    -362, -364, 74,   626,  75,   76,   77,   0,    78,   -364, 79,   202,
    203,  204,  205,  206,  207,  208,  209,  210,  211,  212,  64,   80,
    81,   82,   83,   84,   85,   86,   87,   88,   89,   0,    90,   91,
    92,   93,   0,    0,    0,    94,   0,    0,    0,    0,    0,    0,
    82,   83,   84,   85,   86,   87,   88,   89,   0,    90,   91,   92,
    93,   0,    0,    9,    94,   203,  204,  205,  206,  207,  208,  209,
    210,  211,  212,  51,   52,   53,   54,   55,   56,   0,    0,    0,
    0,    0,    0,    0,    0,    57,   58,   0,    0,    0,    0,    0,
    59,   60,   0,    0,    0,    0,    0,    0,    0,    51,   52,   53,
    54,   55,   56,   0,    0,    0,    0,    0,    0,    0,    0,    57,
    58,   0,    0,    61,   0,    0,    59,   60,   0,    0,    0,    0,
    0,    82,   83,   84,   85,   86,   87,   88,   89,   0,    90,   91,
    92,   93,   0,    0,    0,    94,   0,    0,    753,  61,   0,    0,
    0,    0,    0,    0,    0,    0,    0,    82,   83,   84,   85,   86,
    87,   88,   89,   64,   90,   91,   92,   93,   0,    0,    0,    94,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    82,   83,   84,   85,   86,   87,   88,   89,   64,   90,   91,
    92,   93,   0,    0,    0,    190,  0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    82,   83,   84,   85,   86,
    87,   88,   89,   0,    90,   91,   92,   93,   0,    0,    0,    94,
    0,    0,    0,    0,    0,    0,    0,    82,   83,   84,   85,   86,
    87,   88,   89,   0,    90,   91,   92,   93,   0,    0,    0,    94,
    51,   52,   53,   54,   55,   56,   0,    0,    0,    0,    0,    0,
    0,    0,    57,   58,   0,    0,    0,    0,    0,    59,   60,   51,
    52,   53,   54,   55,   56,   0,    0,    0,    0,    0,    0,    0,
    0,    57,   58,   0,    0,    0,    0,    0,    59,   60,   0,    0,
    61,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    193,  194,  195,  196,  197,  198,  199,  61,
    200,  201,  202,  203,  204,  205,  206,  207,  208,  209,  210,  211,
    212,  0,    0,    0,    0,    193,  194,  195,  196,  197,  198,  199,
    150,  200,  201,  202,  203,  204,  205,  206,  207,  208,  209,  210,
    211,  212,  0,    0,    0,    0,    0,    0,    0,    0,    0,    64,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    82,   83,   84,   85,   86,   87,   88,   89,   0,    90,   91,   92,
    93,   0,    0,    0,    94,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    545,  0,    0,    0,    82,   83,   84,   85,   86,   87,
    88,   89,   0,    90,   91,   92,   93,   0,    0,    0,    94,   193,
    194,  195,  196,  197,  198,  199,  0,    200,  201,  202,  203,  204,
    205,  206,  207,  208,  209,  210,  211,  212,  193,  194,  195,  196,
    197,  198,  199,  0,    200,  201,  202,  203,  204,  205,  206,  207,
    208,  209,  210,  211,  212,  193,  194,  195,  196,  197,  198,  199,
    0,    200,  201,  202,  203,  204,  205,  206,  207,  208,  209,  210,
    211,  212,  193,  194,  195,  196,  197,  198,  199,  0,    200,  201,
    202,  203,  204,  205,  206,  207,  208,  209,  210,  211,  212,  193,
    194,  195,  196,  197,  198,  199,  0,    200,  201,  202,  203,  204,
    205,  206,  207,  208,  209,  210,  211,  212,  193,  194,  195,  196,
    197,  198,  199,  0,    200,  201,  202,  203,  204,  205,  206,  207,
    208,  209,  210,  211,  212,  0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    82,   83,   84,
    85,   86,   87,   88,   89,   0,    90,   91,   92,   93,   0,    0,
    0,    94,   0,    0,    0,    0,    0,    0,    82,   83,   84,   85,
    86,   87,   88,   89,   0,    90,   91,   92,   93,   0,    0,    0,
    190,  193,  194,  195,  196,  197,  198,  199,  0,    200,  201,  202,
    203,  204,  205,  206,  207,  208,  209,  210,  211,  212,  0,    0,
    0,    0,    0,    0,    193,  194,  195,  196,  197,  198,  199,  546,
    200,  201,  202,  203,  204,  205,  206,  207,  208,  209,  210,  211,
    212,  0,    0,    0,    0,    0,    0,    0,    0,    547,  0,    0,
    548,  193,  194,  195,  196,  197,  198,  199,  0,    200,  201,  202,
    203,  204,  205,  206,  207,  208,  209,  210,  211,  212,  193,  194,
    195,  196,  197,  198,  199,  0,    200,  201,  202,  203,  204,  205,
    206,  207,  208,  209,  210,  211,  212,  193,  194,  195,  196,  197,
    198,  199,  0,    200,  201,  202,  203,  204,  205,  206,  207,  208,
    209,  210,  211,  212,  193,  194,  195,  196,  197,  198,  199,  0,
    200,  201,  202,  203,  204,  205,  206,  207,  208,  209,  210,  211,
    212,  195,  196,  197,  198,  199,  399,  200,  201,  202,  203,  204,
    205,  206,  207,  208,  209,  210,  211,  212,  193,  194,  195,  196,
    197,  198,  199,  404,  200,  201,  202,  203,  204,  205,  206,  207,
    208,  209,  210,  211,  212,  0,    0,    0,    0,    0,    0,    0,
    405,  0,    0,    0,    0,    0,    0,    0,    397,  0,    0,    0,
    0,    0,    193,  194,  195,  196,  197,  198,  199,  408,  200,  201,
    202,  203,  204,  205,  206,  207,  208,  209,  210,  211,  212,  193,
    194,  195,  196,  197,  198,  199,  409,  200,  201,  202,  203,  204,
    205,  206,  207,  208,  209,  210,  211,  212,  193,  194,  195,  196,
    197,  198,  199,  410,  200,  201,  202,  203,  204,  205,  206,  207,
    208,  209,  210,  211,  212,  193,  194,  195,  196,  197,  198,  199,
    0,    200,  201,  202,  203,  204,  205,  206,  207,  208,  209,  210,
    211,  212,  193,  194,  195,  196,  197,  198,  199,  0,    200,  201,
    202,  203,  204,  205,  206,  207,  208,  209,  210,  211,  212,  104,
    105,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    193,  194,  195,  196,  197,  198,  199,  411,  200,  201,  202,
    203,  204,  205,  206,  207,  208,  209,  210,  211,  212,  0,    0,
    0,    2,    0,    0,    193,  194,  195,  196,  197,  198,  199,  636,
    200,  201,  202,  203,  204,  205,  206,  207,  208,  209,  210,  211,
    212,  3,    0,    0,    0,    0,    0,    0,    661,  662,  0,    663,
    0,    0,    664,  665,  0,    667,  668,  669,  705,  4,    5,    672,
    0,    674,  0,    676,  0,    6,    0,    0,    678,  0,    0,    681,
    0,    0,    0,    0,    0,    706,  0,    637,  638,  639,  640,  641,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    398,
    0,    0,    0,    7,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    8,    0,    394,  193,  194,  195,
    196,  197,  198,  199,  0,    200,  201,  202,  203,  204,  205,  206,
    207,  208,  209,  210,  211,  212,  0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    749,  0,    0,
    401,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    9,    0,    0,    0,    10,   193,  194,  195,  196,  197,  198,
    199,  642,  200,  201,  202,  203,  204,  205,  206,  207,  208,  209,
    210,  211,  212,  0,    0,    0,    402,  0,    0,    0,    0,    0,
    0,    0,    0,    11,   0,    0,    580,  581,  582,  583,  0,    0,
    0,    0,    0,    307,  584,  0,    154,  0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    12,   0,    0,    0,    0,    585,  586,
    698,  0,    0,    0,    0,    587,  0,    213,  0,    0,    0,    0,
    0,    214,  643,  644,  588,  645,  0,    0,    0,    761,  0,    0,
    589,  0,    0,    0,    0,    0,    590,  193,  194,  195,  196,  197,
    198,  199,  0,    200,  201,  202,  203,  204,  205,  206,  207,  208,
    209,  210,  211,  212,  591,  592,  0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    593,
    594,  0,    0,    0,    595,  596,  597,  0,    0,    0,    0,    0,
    0,    386,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    193,  194,  195,  196,  197,  198,  199,  598,  200,  201,
    202,  203,  204,  205,  206,  207,  208,  209,  210,  211,  212,  0,
    0,    0,    0,    0,    599,  0,    600,  0,    483,  0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    479,  601,
    0,    0,    602,  603,  604,  605,  606,  0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    607,
    608,  0,    0,    0,    0,    0,    0,    609,  0,    193,  194,  195,
    196,  197,  198,  199,  478,  200,  201,  202,  203,  204,  205,  206,
    207,  208,  209,  210,  211,  212,  193,  194,  195,  196,  197,  198,
    199,  0,    200,  201,  202,  203,  204,  205,  206,  207,  208,  209,
    210,  211,  212,  0,    0,    0,    221,  0,    0,    0,    0,    0,
    692,  193,  194,  195,  196,  197,  198,  199,  0,    200,  201,  202,
    203,  204,  205,  206,  207,  208,  209,  210,  211,  212,  0,    0,
    0,    0,    0,    0,    0,    0,    222,  0,    0,    0,    0,    543,
    193,  194,  195,  196,  197,  198,  199,  693,  200,  201,  202,  203,
    204,  205,  206,  207,  208,  209,  210,  211,  212,  0,    193,  194,
    195,  196,  197,  198,  199,  406,  200,  201,  202,  203,  204,  205,
    206,  207,  208,  209,  210,  211,  212,  0,    0,    0,    0,    0,
    423,  193,  194,  195,  196,  197,  198,  199,  0,    200,  201,  202,
    203,  204,  205,  206,  207,  208,  209,  210,  211,  212,  193,  194,
    195,  196,  197,  198,  199,  0,    200,  201,  440,  203,  204,  205,
    206,  207,  208,  209,  210,  211,  212,  193,  194,  195,  196,  197,
    198,  199,  0,    200,  201,  571,  203,  204,  205,  206,  207,  208,
    209,  210,  211,  212,  194,  195,  196,  197,  198,  199,  0,    200,
    201,  202,  203,  204,  205,  206,  207,  208,  209,  210,  211,  212,
    196,  197,  198,  199,  0,    200,  201,  202,  203,  204,  205,  206,
    207,  208,  209,  210,  211,  212,  -384, -384, -384, -384, 0,    200,
    201,  202,  203,  204,  205,  206,  207,  208,  209,  210,  211,  212};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const unsigned char yyconflp[] = {
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  131, 0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   3,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   1,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   9,   0,   0,
    0,   0,  0,   0,   11,  13,  15,  17, 19, 21,  23, 0,   25,  27,  29,  31,
    33,  35, 37,  39,  41,  43,  45,  47, 49, 0,   0,  0,   0,   0,   51,  0,
    0,   53, 55,  0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  7,  57,  0,  0,   0,   0,   0,   0,
    0,   0,  0,   59,  61,  63,  65,  67, 0,  0,   0,  0,   0,   69,  0,   0,
    0,   0,  0,   0,   0,   0,   0,   71, 0,  0,   73, 0,   0,   0,   0,   0,
    0,   0,  75,  0,   0,   77,  79,  0,  0,  81,  83, 0,   0,   0,   0,   0,
    0,   0,  0,   85,  0,   0,   0,   0,  0,  0,   87, 0,   89,  0,   0,   0,
    0,   0,  91,  93,  0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   95,  0,   0,  0,  97,  0,  0,   0,   0,   99,  0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  101, 0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   103, 0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   105,
    0,   0,  0,   0,   107, 0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   109, 111, 0,
    113, 0,  115, 117, 0,   119, 0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  121, 0,  0,   0,   0,   0,   123,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  125, 127, 0,   0,   129,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   5,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,  0,   0,   0,   0,   0,
    0,   0,  0,   0};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short int yyconfl[] = {
    0, 118, 0, 378, 0, 118, 0, 60,  0, 132, 0, 132, 0, 132, 0, 132, 0, 132,
    0, 132, 0, 132, 0, 132, 0, 132, 0, 132, 0, 132, 0, 132, 0, 132, 0, 132,
    0, 132, 0, 132, 0, 132, 0, 132, 0, 132, 0, 132, 0, 132, 0, 132, 0, 132,
    0, 132, 0, 132, 0, 132, 0, 132, 0, 132, 0, 132, 0, 132, 0, 132, 0, 132,
    0, 132, 0, 132, 0, 132, 0, 132, 0, 132, 0, 132, 0, 132, 0, 132, 0, 132,
    0, 132, 0, 132, 0, 132, 0, 132, 0, 132, 0, 132, 0, 132, 0, 132, 0, 132,
    0, 132, 0, 132, 0, 132, 0, 132, 0, 132, 0, 132, 0, 132, 0, 132, 0, 132,
    0, 132, 0, 132, 0, 76,  0};

static const short int yycheck[] = {
    10,  79,  3,   11,  380, 3,   185, 3,   165, 100, 107, 190, 3,   118, 257,
    131, 146, 3,   118, 235, 69,  519, 50,  197, 5,   159, 194, 119, 118, 244,
    3,   3,   4,   5,   6,   7,   8,   244, 6,   131, 50,  3,   578, 39,  46,
    17,  18,  57,  58,  59,  60,  61,  24,  25,  118, 6,   35,  93,  237, 214,
    96,  93,  219, 220, 96,  300, 39,  18,  337, 472, 161, 239, 16,  308, 18,
    47,  3,   39,  183, 51,  259, 617, 159, 183, 94,  116, 10,  11,  12,  13,
    14,  15,  16,  183, 18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,
    29,  30,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  360, 616, 183,
    277, 107, 338, 338, 339, 127, 107, 99,  307, 214, 287, 338, 118, 159, 113,
    538, 3,   231, 148, 318, 338, 517, 191, 341, 154, 214, 21,  22,  23,  24,
    25,  26,  27,  28,  29,  30,  250, 185, 235, 3,   170, 147, 134, 63,  337,
    214, 340, 40,  178, 179, 180, 181, 182, 183, 184, 266, 186, 187, 188, 189,
    190, 338, 26,  193, 194, 195, 196, 197, 174, 157, 3,   201, 202, 203, 204,
    205, 206, 207, 208, 209, 210, 211, 212, 194, 338, 108, 157, 243, 108, 235,
    83,  243, 158, 343, 338, 164, 714, 341, 249, 117, 230, 121, 168, 3,   340,
    299, 300, 318, 177, 260, 130, 338, 337, 136, 341, 326, 136, 613, 614, 339,
    340, 338, 109, 422, 159, 69,  26,  431, 432, 433, 340, 261, 119, 225, 597,
    155, 1,   214, 601, 269, 119, 271, 235, 606, 131, 117, 215, 26,  27,  28,
    29,  30,  515, 337, 3,   285, 652, 3,   4,   5,   6,   7,   8,   293, 214,
    188, 69,  53,  188, 55,  381, 17,  18,  38,  3,   119, 278, 339, 24,  25,
    320, 321, 357, 170, 338, 339, 9,   683, 684, 319, 320, 687, 3,   213, 493,
    297, 326, 62,  373, 340, 13,  14,  353, 16,  306, 51,  109, 276, 383, 107,
    244, 422, 3,   424, 425, 426, 119, 82,  83,  340, 300, 372, 340, 339, 352,
    90,  197, 504, 172, 340, 697, 698, 324, 325, 326, 327, 328, 329, 330, 331,
    370, 333, 334, 335, 336, 338, 339, 191, 340, 244, 14,  3,   137, 99,  81,
    300, 386, 387, 557, 124, 302, 104, 107, 461, 394, 278, 340, 397, 398, 172,
    4,   215, 340, 671, 139, 673, 197, 340, 340, 677, 340, 679, 493, 681, 340,
    340, 113, 462, 191, 785, 299, 118, 340, 423, 338, 39,  3,   341, 337, 202,
    796, 128, 340, 337, 338, 4,   5,   6,   7,   437, 440, 441, 215, 340, 340,
    340, 527, 107, 338, 53,  147, 337, 18,  3,   3,   3,   229, 3,   339, 194,
    99,  3,   107, 198, 159, 3,   3,   4,   5,   6,   7,   8,   337, 338, 3,
    3,   557, 107, 647, 479, 17,  18,  18,  483, 484, 89,  107, 24,  25,  340,
    429, 338, 3,   3,   3,   3,   33,  232, 194, 103, 37,  4,   8,   3,   341,
    41,  774, 775, 340, 509, 508, 107, 14,  511, 51,  3,   3,   341, 341, 3,
    99,  57,  126, 258, 340, 3,   235, 243, 26,  529, 244, 3,   532, 3,   341,
    3,   3,   537, 664, 665, 341, 667, 668, 669, 80,  545, 672, 547, 674, 341,
    676, 341, 678, 22,  23,  24,  25,  26,  27,  28,  29,  30,  99,  340, 340,
    340, 566, 3,   340, 30,  3,   571, 130, 166, 10,  11,  12,  13,  14,  15,
    16,  172, 18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,
    131, 3,   246, 3,   159, 36,  164, 3,   39,  40,  246, 127, 341, 324, 325,
    326, 327, 328, 329, 330, 331, 340, 333, 334, 335, 336, 157, 16,  341, 340,
    130, 159, 63,  20,  341, 341, 631, 632, 130, 170, 338, 704, 73,  74,  75,
    76,  77,  4,   341, 338, 3,   3,   83,  23,  24,  25,  26,  27,  28,  29,
    30,  20,  93,  48,  341, 96,  340, 4,   200, 159, 111, 341, 341, 104, 341,
    340, 107, 108, 341, 341, 111, 112, 24,  25,  26,  27,  28,  29,  30,  341,
    121, 341, 341, 5,   340, 338, 131, 128, 229, 130, 341, 696, 697, 698, 3,
    136, 137, 340, 338, 340, 160, 338, 48,  112, 338, 3,   4,   5,   6,   7,
    8,   341, 341, 4,   155, 340, 20,  159, 159, 17,  18,  44,  340, 164, 340,
    340, 24,  25,  3,   4,   5,   6,   7,   8,   175, 340, 340, 340, 340, 3,
    131, 20,  17,  18,  338, 4,   751, 188, 341, 24,  25,  26,  341, 51,  341,
    190, 761, 5,   33,  3,   341, 341, 5,   4,   62,  5,   341, 232, 341, 338,
    190, 69,  213, 20,  338, 246, 51,  218, 168, 341, 341, 157, 324, 325, 326,
    327, 328, 329, 330, 331, 4,   333, 334, 335, 336, 131, 341, 341, 340, 20,
    189, 99,  243, 244, 341, 246, 7,   248, 249, 128, 251, 86,  87,  3,   4,
    5,   6,   7,   8,   159, 5,   119, 197, 3,   99,  4,   338, 17,  18,  338,
    7,   3,   3,   761, 24,  25,  26,  341, 113, 13,  341, 749, 633, 3,   4,
    5,   6,   7,   8,   647, 261, 6,   751, 402, 454, 570, 155, 17,  18,  675,
    807, 51,  303, 757, 24,  25,  26,  752, 309, -1,  116, -1,  -1,  3,   4,
    5,   6,   7,   8,   374, -1,  -1,  -1,  -1,  -1,  -1,  -1,  17,  18,  -1,
    -1,  51,  -1,  191, 24,  25,  337, 338, -1,  -1,  341, -1,  -1,  3,   4,
    5,   6,   7,   8,   99,  -1,  -1,  -1,  -1,  -1,  -1,  214, 17,  18,  -1,
    -1,  51,  -1,  -1,  24,  25,  -1,  3,   4,   5,   6,   7,   8,   208, 209,
    210, -1,  -1,  213, 99,  -1,  17,  18,  -1,  -1,  -1,  -1,  -1,  24,  25,
    -1,  51,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  -1,
    -1,  -1,  -1,  -1,  99,  -1,  -1,  -1,  -1,  -1,  51,  -1,  -1,  -1,  -1,
    80,  -1,  -1,  281, 282, -1,  -1,  -1,  -1,  -1,  -1,  289, -1,  -1,  -1,
    -1,  -1,  295, 296, 99,  298, 299, 300, 301, 80,  303, 304, 305, -1,  307,
    308, 309, 20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  99,  322,
    323, 324, 325, 326, 327, 328, 329, 330, 331, -1,  333, 334, 335, 336, -1,
    -1,  -1,  340, -1,  -1,  -1,  -1,  -1,  -1,  324, 325, 326, 327, 328, 329,
    330, 331, -1,  333, 334, 335, 336, -1,  -1,  194, 340, 21,  22,  23,  24,
    25,  26,  27,  28,  29,  30,  3,   4,   5,   6,   7,   8,   -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  17,  18,  -1,  -1,  -1,  -1,  -1,  24,  25,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  3,   4,   5,   6,   7,   8,   -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  17,  18,  -1,  -1,  51,  -1,  -1,  24,  25,  -1,
    -1,  -1,  -1,  -1,  324, 325, 326, 327, 328, 329, 330, 331, -1,  333, 334,
    335, 336, -1,  -1,  -1,  340, -1,  -1,  80,  51,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  324, 325, 326, 327, 328, 329, 330, 331, 99,  333, 334,
    335, 336, -1,  -1,  -1,  340, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  324, 325, 326, 327, 328, 329, 330, 331, 99,  333, 334,
    335, 336, -1,  -1,  -1,  340, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  324, 325, 326, 327, 328, 329, 330, 331, -1,  333, 334,
    335, 336, -1,  -1,  -1,  340, -1,  -1,  -1,  -1,  -1,  -1,  -1,  324, 325,
    326, 327, 328, 329, 330, 331, -1,  333, 334, 335, 336, -1,  -1,  -1,  340,
    3,   4,   5,   6,   7,   8,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  17,
    18,  -1,  -1,  -1,  -1,  -1,  24,  25,  3,   4,   5,   6,   7,   8,   -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  17,  18,  -1,  -1,  -1,  -1,  -1,  24,
    25,  -1,  -1,  51,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  10,  11,  12,  13,  14,  15,  16,  51,  18,  19,  20,
    21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  -1,  -1,  -1,  -1,  10,
    11,  12,  13,  14,  15,  16,  99,  18,  19,  20,  21,  22,  23,  24,  25,
    26,  27,  28,  29,  30,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  99,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  324, 325, 326,
    327, 328, 329, 330, 331, -1,  333, 334, 335, 336, -1,  -1,  -1,  340, -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  104, -1,  -1,  -1,  324, 325, 326,
    327, 328, 329, 330, 331, -1,  333, 334, 335, 336, -1,  -1,  -1,  340, 10,
    11,  12,  13,  14,  15,  16,  -1,  18,  19,  20,  21,  22,  23,  24,  25,
    26,  27,  28,  29,  30,  10,  11,  12,  13,  14,  15,  16,  -1,  18,  19,
    20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  10,  11,  12,  13,
    14,  15,  16,  -1,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,
    29,  30,  10,  11,  12,  13,  14,  15,  16,  -1,  18,  19,  20,  21,  22,
    23,  24,  25,  26,  27,  28,  29,  30,  10,  11,  12,  13,  14,  15,  16,
    -1,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  10,
    11,  12,  13,  14,  15,  16,  -1,  18,  19,  20,  21,  22,  23,  24,  25,
    26,  27,  28,  29,  30,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  324, 325, 326, 327, 328, 329, 330, 331, -1,
    333, 334, 335, 336, -1,  -1,  -1,  340, -1,  -1,  -1,  -1,  -1,  -1,  324,
    325, 326, 327, 328, 329, 330, 331, -1,  333, 334, 335, 336, -1,  -1,  -1,
    340, 10,  11,  12,  13,  14,  15,  16,  -1,  18,  19,  20,  21,  22,  23,
    24,  25,  26,  27,  28,  29,  30,  -1,  -1,  -1,  -1,  -1,  -1,  10,  11,
    12,  13,  14,  15,  16,  341, 18,  19,  20,  21,  22,  23,  24,  25,  26,
    27,  28,  29,  30,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  338, -1,  -1,
    341, 10,  11,  12,  13,  14,  15,  16,  -1,  18,  19,  20,  21,  22,  23,
    24,  25,  26,  27,  28,  29,  30,  10,  11,  12,  13,  14,  15,  16,  -1,
    18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  10,  11,
    12,  13,  14,  15,  16,  -1,  18,  19,  20,  21,  22,  23,  24,  25,  26,
    27,  28,  29,  30,  10,  11,  12,  13,  14,  15,  16,  -1,  18,  19,  20,
    21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  12,  13,  14,  15,  16,
    341, 18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  10,
    11,  12,  13,  14,  15,  16,  341, 18,  19,  20,  21,  22,  23,  24,  25,
    26,  27,  28,  29,  30,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  341, -1,  -1,
    -1,  -1,  -1,  -1,  -1,  107, -1,  -1,  -1,  -1,  -1,  10,  11,  12,  13,
    14,  15,  16,  341, 18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,
    29,  30,  10,  11,  12,  13,  14,  15,  16,  341, 18,  19,  20,  21,  22,
    23,  24,  25,  26,  27,  28,  29,  30,  10,  11,  12,  13,  14,  15,  16,
    341, 18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  10,
    11,  12,  13,  14,  15,  16,  -1,  18,  19,  20,  21,  22,  23,  24,  25,
    26,  27,  28,  29,  30,  10,  11,  12,  13,  14,  15,  16,  -1,  18,  19,
    20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  0,   1,   -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  10,  11,  12,  13,  14,
    15,  16,  341, 18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,
    30,  -1,  -1,  -1,  38,  -1,  -1,  10,  11,  12,  13,  14,  15,  16,  341,
    18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  62,  -1,
    -1,  -1,  -1,  -1,  -1,  581, 582, -1,  584, -1,  -1,  587, 588, -1,  590,
    591, 592, 341, 82,  83,  596, -1,  598, -1,  600, -1,  90,  -1,  -1,  605,
    -1,  -1,  608, -1,  -1,  -1,  -1,  -1,  341, -1,  73,  74,  75,  76,  77,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  338, -1,  -1,  -1,
    124, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    139, -1,  338, 10,  11,  12,  13,  14,  15,  16,  -1,  18,  19,  20,  21,
    22,  23,  24,  25,  26,  27,  28,  29,  30,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  690, -1,  -1,  338, -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  194, -1,  -1,  -1,  198,
    10,  11,  12,  13,  14,  15,  16,  175, 18,  19,  20,  21,  22,  23,  24,
    25,  26,  27,  28,  29,  30,  -1,  -1,  -1,  338, -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  232, -1,  -1,  43,  44,  45,  46,  -1,  -1,  -1,  -1,  -1,
    338, 53,  -1,  243, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  258,
    -1,  -1,  -1,  -1,  71,  72,  338, -1,  -1,  -1,  -1,  78,  -1,  303, -1,
    -1,  -1,  -1,  -1,  309, 248, 249, 89,  251, -1,  -1,  -1,  338, -1,  -1,
    97,  -1,  -1,  -1,  -1,  -1,  103, 10,  11,  12,  13,  14,  15,  16,  -1,
    18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  125, 126,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  144, 145, -1,  -1,  -1,  149, 150, 151, -1,  -1,  -1,  -1,  -1,
    -1,  218, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  10,
    11,  12,  13,  14,  15,  16,  178, 18,  19,  20,  21,  22,  23,  24,  25,
    26,  27,  28,  29,  30,  -1,  -1,  -1,  -1,  -1,  197, -1,  199, -1,  107,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  218, 216,
    -1,  -1,  219, 220, 221, 222, 223, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  240, 241, -1,  -1,  -1,  -1,  -1,
    -1,  248, -1,  10,  11,  12,  13,  14,  15,  16,  96,  18,  19,  20,  21,
    22,  23,  24,  25,  26,  27,  28,  29,  30,  10,  11,  12,  13,  14,  15,
    16,  -1,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,
    -1,  -1,  -1,  3,   -1,  -1,  -1,  -1,  -1,  40,  10,  11,  12,  13,  14,
    15,  16,  -1,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,
    30,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  39,  -1,  -1,  -1,  -1,  96,
    10,  11,  12,  13,  14,  15,  16,  83,  18,  19,  20,  21,  22,  23,  24,
    25,  26,  27,  28,  29,  30,  -1,  10,  11,  12,  13,  14,  15,  16,  39,
    18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  -1,  -1,
    -1,  -1,  -1,  36,  10,  11,  12,  13,  14,  15,  16,  -1,  18,  19,  20,
    21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  10,  11,  12,  13,  14,
    15,  16,  -1,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,
    30,  10,  11,  12,  13,  14,  15,  16,  -1,  18,  19,  20,  21,  22,  23,
    24,  25,  26,  27,  28,  29,  30,  11,  12,  13,  14,  15,  16,  -1,  18,
    19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  13,  14,  15,
    16,  -1,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,
    13,  14,  15,  16,  -1,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,
    28,  29,  30};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short int yystos[] = {
    0,   1,   38,  62,  82,  83,  90,  124, 139, 194, 198, 232, 258, 343, 344,
    345, 380, 382, 395, 396, 401, 402, 403, 405, 408, 409, 410, 418, 425, 429,
    337, 214, 69,  109, 172, 191, 202, 215, 229, 385, 397, 426, 3,   69,  119,
    172, 191, 385, 412, 214, 357, 3,   4,   5,   6,   7,   8,   17,  18,  24,
    25,  51,  62,  69,  99,  119, 191, 214, 281, 282, 289, 295, 296, 298, 301,
    303, 304, 305, 307, 309, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331,
    333, 334, 335, 336, 340, 373, 419, 423, 424, 3,   340, 362, 372, 214, 0,
    1,   344, 337, 3,   117, 381, 159, 381, 214, 119, 3,   107, 118, 147, 174,
    427, 117, 404, 3,   5,   107, 404, 214, 81,  113, 118, 128, 147, 413, 3,
    26,  33,  86,  87,  113, 208, 209, 210, 213, 358, 359, 373, 339, 9,   373,
    99,  373, 373, 373, 243, 373, 379, 69,  191, 214, 3,   340, 107, 3,   300,
    197, 14,  421, 3,   302, 137, 354, 104, 300, 107, 420, 354, 278, 340, 340,
    340, 340, 340, 340, 340, 340, 340, 340, 340, 340, 340, 373, 374, 10,  11,
    12,  13,  14,  15,  16,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,
    28,  29,  30,  303, 309, 278, 297, 306, 299, 300, 308, 3,   39,  339, 364,
    345, 360, 361, 362, 365, 197, 39,  363, 3,   406, 337, 337, 107, 18,  3,
    3,   3,   381, 3,   339, 428, 3,   360, 427, 107, 338, 99,  3,   159, 107,
    3,   3,   404, 3,   107, 107, 338, 364, 3,   26,  373, 340, 373, 379, 93,
    96,  243, 3,   3,   3,   345, 3,   420, 421, 4,   299, 300, 373, 8,   3,
    14,  422, 420, 373, 47,  134, 225, 373, 376, 373, 373, 26,  373, 373, 373,
    373, 374, 373, 373, 373, 373, 374, 338, 341, 341, 373, 373, 373, 373, 373,
    6,   18,  157, 340, 13,  14,  16,  373, 33,  37,  200, 340, 373, 373, 373,
    373, 373, 373, 373, 373, 373, 373, 373, 420, 107, 421, 421, 3,   3,   341,
    341, 63,  108, 121, 136, 155, 188, 213, 338, 366, 368, 373, 430, 3,   244,
    338, 339, 374, 99,  340, 3,   235, 398, 26,  339, 244, 346, 235, 360, 3,
    3,   3,   3,   406, 197, 340, 414, 374, 360, 358, 345, 218, 93,  96,  373,
    373, 341, 420, 421, 338, 373, 421, 107, 338, 341, 373, 338, 338, 341, 341,
    341, 39,  341, 341, 341, 341, 341, 341, 374, 16,  18,  6,   157, 345, 374,
    373, 373, 340, 36,  340, 340, 340, 345, 421, 3,   364, 108, 136, 188, 369,
    362, 360, 130, 166, 367, 20,  338, 346, 172, 406, 3,   246, 3,   356, 118,
    183, 339, 340, 383, 384, 320, 321, 399, 159, 373, 164, 352, 360, 346, 428,
    50,  185, 407, 3,   417, 356, 239, 345, 246, 346, 341, 373, 373, 96,  218,
    373, 373, 373, 107, 127, 378, 378, 4,   53,  89,  103, 126, 377, 340, 16,
    341, 341, 345, 374, 373, 345, 345, 345, 341, 420, 367, 367, 367, 130, 159,
    362, 130, 373, 373, 20,  338, 4,   338, 341, 3,   3,   109, 119, 131, 170,
    386, 387, 363, 3,   48,  354, 346, 20,  159, 338, 411, 341, 340, 415, 411,
    4,   111, 347, 96,  373, 104, 341, 338, 341, 373, 373, 341, 341, 341, 345,
    374, 375, 340, 341, 341, 341, 341, 341, 421, 362, 373, 159, 235, 370, 371,
    362, 20,  5,   406, 338, 356, 158, 168, 340, 383, 43,  44,  45,  46,  53,
    71,  72,  78,  89,  97,  103, 125, 126, 144, 145, 149, 150, 151, 178, 197,
    199, 216, 219, 220, 221, 222, 223, 240, 241, 248, 389, 119, 131, 340, 340,
    131, 341, 338, 345, 340, 353, 373, 80,  373, 160, 3,   80,  373, 416, 411,
    338, 48,  112, 351, 373, 373, 341, 73,  74,  75,  76,  77,  175, 248, 249,
    251, 341, 338, 341, 345, 374, 373, 340, 371, 373, 4,   20,  159, 386, 340,
    391, 391, 391, 391, 391, 391, 340, 391, 391, 391, 44,  392, 391, 392, 391,
    340, 391, 392, 391, 392, 340, 391, 388, 340, 340, 356, 356, 340, 383, 386,
    3,   400, 40,  83,  349, 131, 20,  338, 338, 341, 4,   348, 373, 373, 352,
    341, 341, 375, 341, 341, 356, 190, 5,   3,   341, 5,   393, 394, 393, 393,
    4,   390, 393, 393, 393, 394, 393, 394, 393, 390, 393, 394, 393, 394, 5,
    394, 18,  41,  57,  80,  131, 157, 170, 229, 356, 356, 341, 341, 356, 391,
    341, 338, 232, 80,  373, 416, 416, 338, 190, 246, 350, 338, 354, 341, 20,
    168, 383, 338, 341, 231, 250, 53,  55,  338, 341, 341, 341, 157, 4,   4,
    5,   6,   7,   131, 131, 340, 341, 341, 341, 349, 353, 417, 415, 20,  189,
    348, 128, 355, 7,   159, 5,   197, 3,   4,   394, 394, 356, 338, 7,   356,
    3,   341, 3,   341, 400};

/* Error token number */
#define YYTERROR 1

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
#define YY_LOCATION_PRINT(File, Loc) ((void)0)
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
#define YYLEX yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX yylex(&yylval)
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

#define YYCHK(YYE)                     \
  do {                                 \
    YYRESULTTAG yyflag = YYE;          \
    if (yyflag != yyok) return yyflag; \
  } while (YYID(0))

#if YYDEBUG

#ifndef YYFPRINTF
#define YYFPRINTF fprintf
#endif

#define YYDPRINTF(Args)          \
  do {                           \
    if (yydebug) YYFPRINTF Args; \
  } while (YYID(0))

/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
static void yy_symbol_value_print(FILE *yyoutput, int yytype,
                                  YYSTYPE const *const yyvaluep,
                                  struct ParseResult *result) {
  FILE *yyo = yyoutput;
  YYUSE(yyo);
  if (!yyvaluep) return;
  YYUSE(result);
#ifdef YYPRINT
  if (yytype < YYNTOKENS) YYPRINT(yyoutput, yytoknum[yytype], *yyvaluep);
#else
  YYUSE(yyoutput);
#endif
  switch (yytype) {
    default:
      break;
  }
}

/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void yy_symbol_print(FILE *yyoutput, int yytype,
                            YYSTYPE const *const yyvaluep,
                            struct ParseResult *result) {
  if (yytype < YYNTOKENS)
    YYFPRINTF(yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF(yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print(yyoutput, yytype, yyvaluep, result);
  YYFPRINTF(yyoutput, ")");
}

#define YY_SYMBOL_PRINT(Title, Type, Value, Location) \
  do {                                                \
    if (yydebug) {                                    \
      YYFPRINTF(stderr, "%s ", Title);                \
      yy_symbol_print(stderr, Type, Value, result);   \
      YYFPRINTF(stderr, "\n");                        \
    }                                                 \
  } while (YYID(0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

#else /* !YYDEBUG */

#define YYDPRINTF(Args)
#define YY_SYMBOL_PRINT(Title, Type, Value, Location)

#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
#define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
#if (!defined __cplusplus || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL))
#define YYSTACKEXPANDABLE 1
#else
#define YYSTACKEXPANDABLE 0
#endif
#endif

#if YYSTACKEXPANDABLE
#define YY_RESERVE_GLRSTACK(Yystack)                                  \
  do {                                                                \
    if (Yystack->yyspaceLeft < YYHEADROOM) yyexpandGLRStack(Yystack); \
  } while (YYID(0))
#else
#define YY_RESERVE_GLRSTACK(Yystack)                                   \
  do {                                                                 \
    if (Yystack->yyspaceLeft < YYHEADROOM) yyMemoryExhausted(Yystack); \
  } while (YYID(0))
#endif

#if YYERROR_VERBOSE

#ifndef yystpcpy
#if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#define yystpcpy stpcpy
#else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *yystpcpy(char *yydest, const char *yysrc) {
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0') continue;

  return yyd - 1;
}
#endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static size_t yytnamerr(char *yyres, const char *yystr) {
  if (*yystr == '"') {
    size_t yyn = 0;
    char const *yyp = yystr;

    for (;;) switch (*++yyp) {
        case '\'':
        case ',':
          goto do_not_strip_quotes;

        case '\\':
          if (*++yyp != '\\') goto do_not_strip_quotes;
        /* Fall through.  */
        default:
          if (yyres) yyres[yyn] = *yyp;
          yyn++;
          break;

        case '"':
          if (yyres) yyres[yyn] = '\0';
          return yyn;
      }
  do_not_strip_quotes:
    ;
  }

  if (!yyres) return strlen(yystr);

  return yystpcpy(yyres, yystr) - yyres;
}
#endif

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
  yyGLRState *yypred;
  /** Source position of the first token produced by my symbol */
  size_t yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  non-terminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption *yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yysval;
  } yysemantics;
};

struct yyGLRStateSet {
  yyGLRState **yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool *yylookaheadNeeds;
  size_t yysize, yycapacity;
};

struct yySemanticOption {
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState *yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption *yynext;
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
  yyGLRStackItem *yyitems;
  yyGLRStackItem *yynextFree;
  size_t yyspaceLeft;
  yyGLRState *yysplitPoint;
  yyGLRState *yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack(yyGLRStack *yystackp);
#endif

static void yyFail(yyGLRStack *yystackp, struct ParseResult *result,
                   const char *yymsg) __attribute__((__noreturn__));
static void yyFail(yyGLRStack *yystackp, struct ParseResult *result,
                   const char *yymsg) {
  if (yymsg != YY_NULL) yyerror(result, yymsg);
  YYLONGJMP(yystackp->yyexception_buffer, 1);
}

static void yyMemoryExhausted(yyGLRStack *yystackp)
    __attribute__((__noreturn__));
static void yyMemoryExhausted(yyGLRStack *yystackp) {
  YYLONGJMP(yystackp->yyexception_buffer, 2);
}

#if YYDEBUG || YYERROR_VERBOSE
/** A printable representation of TOKEN.  */
static inline const char *yytokenName(yySymbol yytoken) {
  if (yytoken == YYEMPTY) return "";

  return yytname[yytoken];
}
#endif

/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin(yyGLRStackItem *, int, int) __attribute__((__unused__));
static void yyfillin(yyGLRStackItem *yyvsp, int yylow0, int yylow1) {
  int i;
  yyGLRState *s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0 - 1; i >= yylow1; i -= 1) {
    YYASSERT(s->yyresolved);
    yyvsp[i].yystate.yyresolved = yytrue;
    yyvsp[i].yystate.yysemantics.yysval = s->yysemantics.yysval;
    s = yyvsp[i].yystate.yypred = s->yypred;
  }
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill(yyGLRStackItem *, int *, int, yybool)
    __attribute__((__unused__));
static inline int yyfill(yyGLRStackItem *yyvsp, int *yylow, int yylow1,
                         yybool yynormal) {
  if (!yynormal && yylow1 < *yylow) {
    yyfillin(yyvsp, *yylow, yylow1);
    *yylow = yylow1;
  }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT.  */
/*ARGSUSED*/ static YYRESULTTAG yyuserAction(yyRuleNum yyn, int yyrhslen,
                                             yyGLRStackItem *yyvsp,
                                             yyGLRStack *yystackp,
                                             YYSTYPE *yyvalp,
                                             struct ParseResult *result) {
  yybool yynormal __attribute__((__unused__)) =
      (yystackp->yysplitPoint == YY_NULL);
  int yylow;
  YYUSE(result);
#undef yyerrok
#define yyerrok (yystackp->yyerrState = 0)
#undef YYACCEPT
#define YYACCEPT return yyaccept
#undef YYABORT
#define YYABORT return yyabort
#undef YYERROR
#define YYERROR return yyerrok, yyerr
#undef YYRECOVERING
#define YYRECOVERING() (yystackp->yyerrState != 0)
#undef yyclearin
#define yyclearin (yychar = YYEMPTY)
#undef YYFILL
#define YYFILL(N) yyfill(yyvsp, &yylow, N, yynormal)
#undef YYBACKUP
#define YYBACKUP(Token, Value) \
  return yyerror(result, YY_("syntax error: cannot back up")), yyerrok, yyerr

  yylow = 1;
  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL(1 - yyrhslen)].yystate.yysemantics.yysval;
  switch (yyn) {
    case 2:
/* Line 868 of glr.c  */
#line 446 "sql.ypp"
    {
      printf("> \n");
      ((*yyvalp).ast_node) = new AstStmtList(
          AST_STMT_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                              .yystate.yysemantics.yysval.ast_node),
          NULL);
      if (result->error_number == 0) {
        result->ast = ((*yyvalp).ast_node);
      } else {
        result->ast = NULL;
      }

    } break;

    case 3:
/* Line 868 of glr.c  */
#line 460 "sql.ypp"
    {
      printf(">> \n");
      ((*yyvalp).ast_node) = new AstStmtList(
          AST_STMT_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                              .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node));
      if (result->error_number == 0) {
        result->ast = ((*yyvalp).ast_node);
      } else {
        result->ast = NULL;
      }
    } break;

    case 4:
/* Line 868 of glr.c  */
#line 473 "sql.ypp"
    {
      printf(">> \n");
      result->ast = NULL;
      result->error_number++;
      // yyerror(result,"First statement discarded, input new statement");
      yyclearin;
      yyerrok;
    } break;

    case 5:
/* Line 868 of glr.c  */
#line 482 "sql.ypp"
    {
      printf(">> \n");
      result->ast = NULL;
      result->error_number++;
      yyclearin;
      yyerrok;
    } break;

    case 6:
/* Line 868 of glr.c  */
#line 493 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 7:
/* Line 868 of glr.c  */
#line 498 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstSelectStmt(
          AST_SELECT_STMT, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                .yystate.yysemantics.yysval.intval),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL, NULL, NULL, NULL, NULL, NULL);
    } break;

    case 8:
/* Line 868 of glr.c  */
#line 503 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstSelectStmt(
          AST_SELECT_STMT, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (11))]
                                .yystate.yysemantics.yysval.intval),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (11))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (11))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((6) - (11))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((7) - (11))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((8) - (11))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((9) - (11))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((10) - (11))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((11) - (11))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 9:
/* Line 868 of glr.c  */
#line 508 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 10:
/* Line 868 of glr.c  */
#line 509 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstWhereClause(
          AST_WHERE_CLAUSE, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (2))]
                                 .yystate.yysemantics.yysval.ast_node));
    } break;

    case 11:
/* Line 868 of glr.c  */
#line 512 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 12:
/* Line 868 of glr.c  */
#line 513 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstGroupByClause(
          AST_GROUPBY_CLAUSE,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (4))].yystate.yysemantics.yysval.intval));
    } break;

    case 13:
/* Line 868 of glr.c  */
#line 518 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstGroupByList(
          AST_GROUPBY_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                 .yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 14:
/* Line 868 of glr.c  */
#line 519 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstGroupByList(
          AST_GROUPBY_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                                 .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 15:
/* Line 868 of glr.c  */
#line 521 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 16:
/* Line 868 of glr.c  */
#line 522 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 17:
/* Line 868 of glr.c  */
#line 523 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 18:
/* Line 868 of glr.c  */
#line 526 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 19:
/* Line 868 of glr.c  */
#line 527 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 20:
/* Line 868 of glr.c  */
#line 530 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 21:
/* Line 868 of glr.c  */
#line 531 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstHavingClause(
          AST_HAVING_CLAUSE, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (2))]
                                  .yystate.yysemantics.yysval.ast_node));
    } break;

    case 22:
/* Line 868 of glr.c  */
#line 534 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 23:
/* Line 868 of glr.c  */
#line 535 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstOrderByClause(
          AST_ORDERBY_CLAUSE,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 24:
/* Line 868 of glr.c  */
#line 538 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstOrderByList(
          AST_ORDERBY_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                 .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (2))].yystate.yysemantics.yysval.intval),
          NULL);
    } break;

    case 25:
/* Line 868 of glr.c  */
#line 539 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstOrderByList(
          AST_ORDERBY_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (4))]
                                 .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (4))].yystate.yysemantics.yysval.intval),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 26:
/* Line 868 of glr.c  */
#line 541 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 27:
/* Line 868 of glr.c  */
#line 542 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstLimitClause(
          AST_LIMIT_CLAUSE, NULL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (2))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 28:
/* Line 868 of glr.c  */
#line 543 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstLimitClause(
          AST_LIMIT_CLAUSE, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (4))]
                                 .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 29:
/* Line 868 of glr.c  */
#line 546 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 30:
/* Line 868 of glr.c  */
#line 547 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 31:
/* Line 868 of glr.c  */
#line 551 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstColumn(
          AST_COLUMN, string("NULL"),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 32:
/* Line 868 of glr.c  */
#line 552 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstColumn(
          AST_COLUMN, string("NULL"),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                      .yystate.yysemantics.yysval.strval)),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 33:
/* Line 868 of glr.c  */
#line 555 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 34:
/* Line 868 of glr.c  */
#line 556 "sql.ypp"
    {
      if (((*yyvalp).intval) & 1) yyerror(result, "duplicate ALL option");
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                .yystate.yysemantics.yysval.intval) |
                           1;
    } break;

    case 35:
/* Line 868 of glr.c  */
#line 557 "sql.ypp"
    {
      if (((*yyvalp).intval) & 2) yyerror(result, "duplicate DISTINCT option");
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                .yystate.yysemantics.yysval.intval) |
                           2;
    } break;

    case 36:
/* Line 868 of glr.c  */
#line 558 "sql.ypp"
    {
      if (((*yyvalp).intval) & 4)
        yyerror(result, "duplicate DISTINCTROW option");
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                .yystate.yysemantics.yysval.intval) |
                           4;
    } break;

    case 37:
/* Line 868 of glr.c  */
#line 559 "sql.ypp"
    {
      if (((*yyvalp).intval) & 8)
        yyerror(result, "duplicate HIGH_PRIORITY option");
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                .yystate.yysemantics.yysval.intval) |
                           8;
    } break;

    case 38:
/* Line 868 of glr.c  */
#line 560 "sql.ypp"
    {
      if (((*yyvalp).intval) & 16)
        yyerror(result, "duplicate STRAIGHT_JOIN option");
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                .yystate.yysemantics.yysval.intval) |
                           16;
    } break;

    case 39:
/* Line 868 of glr.c  */
#line 561 "sql.ypp"
    {
      if (((*yyvalp).intval) & 32)
        yyerror(result, "duplicate SQL_SMALL_RESULT option");
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                .yystate.yysemantics.yysval.intval) |
                           32;
    } break;

    case 40:
/* Line 868 of glr.c  */
#line 562 "sql.ypp"
    {
      if (((*yyvalp).intval) & 64)
        yyerror(result, "duplicate SQL_BIG_RESULT option");
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                .yystate.yysemantics.yysval.intval) |
                           64;
    } break;

    case 41:
/* Line 868 of glr.c  */
#line 563 "sql.ypp"
    {
      if (((*yyvalp).intval) & 128)
        yyerror(result, "duplicate SQL_CALC_FOUND_ROWS option");
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                .yystate.yysemantics.yysval.intval) |
                           128;
    } break;

    case 42:
/* Line 868 of glr.c  */
#line 567 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstSelectList(
          AST_SELECT_LIST, 0,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (1))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 43:
/* Line 868 of glr.c  */
#line 568 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstSelectList(
          AST_SELECT_LIST, 0,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 44:
/* Line 868 of glr.c  */
#line 569 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstSelectList(AST_SELECT_LIST, 1, NULL, NULL);
    } break;

    case 45:
/* Line 868 of glr.c  */
#line 573 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstSelectExpr(
          AST_SELECT_EXPR,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (2))]
                      .yystate.yysemantics.yysval.strval)),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (2))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 46:
/* Line 868 of glr.c  */
#line 576 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstFromList(
          AST_FROM_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                              .yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 47:
/* Line 868 of glr.c  */
#line 577 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstFromList(
          AST_FROM_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                              .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 48:
/* Line 868 of glr.c  */
#line 581 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 49:
/* Line 868 of glr.c  */
#line 582 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 50:
/* Line 868 of glr.c  */
#line 587 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstTable(
          AST_TABLE, string("NULL"),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                      .yystate.yysemantics.yysval.strval)),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (2))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 51:
/* Line 868 of glr.c  */
#line 589 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstTable(
          AST_TABLE, string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (4))]
                                 .yystate.yysemantics.yysval.strval)),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (4))]
                      .yystate.yysemantics.yysval.strval)),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (4))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 52:
/* Line 868 of glr.c  */
#line 590 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstSubquery(
          AST_SUBQUERY,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (3))]
                      .yystate.yysemantics.yysval.strval)),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 53:
/* Line 868 of glr.c  */
#line 591 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 56:
/* Line 868 of glr.c  */
#line 598 "sql.ypp"
    {
      ((*yyvalp).strval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (2))]
                                .yystate.yysemantics.yysval.strval);
    } break;

    case 57:
/* Line 868 of glr.c  */
#line 599 "sql.ypp"
    {
      ((*yyvalp).strval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                .yystate.yysemantics.yysval.strval);
    } break;

    case 58:
/* Line 868 of glr.c  */
#line 600 "sql.ypp"
    {
      ((*yyvalp).strval) = "NULL";
    } break;

    case 59:
/* Line 868 of glr.c  */
#line 615 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstJoin(
          AST_JOIN, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (5))]
                         .yystate.yysemantics.yysval.intval),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (5))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (5))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 60:
/* Line 868 of glr.c  */
#line 616 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstJoin(
          AST_JOIN, -1, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                             .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 61:
/* Line 868 of glr.c  */
#line 617 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstJoin(
          AST_JOIN, -1, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (5))]
                             .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (5))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 62:
/* Line 868 of glr.c  */
#line 618 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstJoin(
          AST_JOIN,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (6))].yystate.yysemantics.yysval.intval) +
              (((yyGLRStackItem const *)
                yyvsp)[YYFILL((3) - (6))].yystate.yysemantics.yysval.intval),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (6))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (6))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((6) - (6))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 63:
/* Line 868 of glr.c  */
#line 619 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstJoin(
          AST_JOIN, 32 + (((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (5))]
                              .yystate.yysemantics.yysval.intval),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (5))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (5))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 64:
/* Line 868 of glr.c  */
#line 622 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 65:
/* Line 868 of glr.c  */
#line 623 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 66:
/* Line 868 of glr.c  */
#line 624 "sql.ypp"
    {
      ((*yyvalp).intval) = 2;
    } break;

    case 67:
/* Line 868 of glr.c  */
#line 627 "sql.ypp"
    {
      ((*yyvalp).intval) = 4;
    } break;

    case 68:
/* Line 868 of glr.c  */
#line 628 "sql.ypp"
    {
      ((*yyvalp).intval) = 4;
    } break;

    case 69:
/* Line 868 of glr.c  */
#line 632 "sql.ypp"
    {
      ((*yyvalp).intval) = 8;
    } break;

    case 70:
/* Line 868 of glr.c  */
#line 633 "sql.ypp"
    {
      ((*yyvalp).intval) = 16;
    } break;

    case 71:
/* Line 868 of glr.c  */
#line 634 "sql.ypp"
    {
      ((*yyvalp).intval) = 64;
    } break;

    case 72:
/* Line 868 of glr.c  */
#line 638 "sql.ypp"
    {
      ((*yyvalp).intval) =
          8 + (((yyGLRStackItem const *)
                yyvsp)[YYFILL((2) - (2))].yystate.yysemantics.yysval.intval);
    } break;

    case 73:
/* Line 868 of glr.c  */
#line 639 "sql.ypp"
    {
      ((*yyvalp).intval) =
          16 + (((yyGLRStackItem const *)
                 yyvsp)[YYFILL((2) - (2))].yystate.yysemantics.yysval.intval);
    } break;

    case 74:
/* Line 868 of glr.c  */
#line 640 "sql.ypp"
    {
      ((*yyvalp).intval) =
          64 + (((yyGLRStackItem const *)
                 yyvsp)[YYFILL((2) - (2))].yystate.yysemantics.yysval.intval);
    } break;

    case 75:
/* Line 868 of glr.c  */
#line 641 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 76:
/* Line 868 of glr.c  */
#line 644 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 77:
/* Line 868 of glr.c  */
#line 645 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 78:
/* Line 868 of glr.c  */
#line 653 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstJoinCondition(
          AST_JOIN_CONDITION, "ON",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (2))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 79:
/* Line 868 of glr.c  */
#line 654 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstJoinCondition(
          AST_JOIN_CONDITION, "USING",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 80:
/* Line 868 of glr.c  */
#line 659 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 81:
/* Line 868 of glr.c  */
#line 666 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstColumn(
          AST_COLUMN, string("NULL"),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 82:
/* Line 868 of glr.c  */
#line 667 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprConst(
          AST_EXPR_CONST, "CONST",
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 83:
/* Line 868 of glr.c  */
#line 668 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstColumn(
          AST_COLUMN, string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                                  .yystate.yysemantics.yysval.strval)),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (3))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 84:
/* Line 868 of glr.c  */
#line 669 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstColumn(
          AST_COLUMN_ALL,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                      .yystate.yysemantics.yysval.strval)),
          string("*"));
    } break;

    case 85:
/* Line 868 of glr.c  */
#line 670 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprConst(
          AST_EXPR_CONST, "CONST_STRING",
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 86:
/* Line 868 of glr.c  */
#line 671 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprConst(
          AST_EXPR_CONST, "CONST_INT",
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 87:
/* Line 868 of glr.c  */
#line 672 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprConst(
          AST_EXPR_CONST, "CONST_DOUBLE",
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 88:
/* Line 868 of glr.c  */
#line 673 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprConst(
          AST_EXPR_CONST, "CONST_BOOL",
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 89:
/* Line 868 of glr.c  */
#line 675 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_CAL_BINARY, "+",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 90:
/* Line 868 of glr.c  */
#line 676 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_CAL_BINARY, "-",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 91:
/* Line 868 of glr.c  */
#line 677 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_CAL_BINARY, "*",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 92:
/* Line 868 of glr.c  */
#line 678 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_CAL_BINARY, "/",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 93:
/* Line 868 of glr.c  */
#line 679 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_CAL_BINARY, "MOD",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 94:
/* Line 868 of glr.c  */
#line 680 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_CAL_BINARY, "%",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 95:
/* Line 868 of glr.c  */
#line 682 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "-",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (2))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 96:
/* Line 868 of glr.c  */
#line 683 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "+",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (2))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 97:
/* Line 868 of glr.c  */
#line 685 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_BOOL_BINARY, "AND",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 98:
/* Line 868 of glr.c  */
#line 686 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_BOOL_BINARY, "OR",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 99:
/* Line 868 of glr.c  */
#line 687 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_BOOL_BINARY, "XOR",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 100:
/* Line 868 of glr.c  */
#line 689 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCmpBinary(
          AST_EXPR_CMP_BINARY, "",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.subtok),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 101:
/* Line 868 of glr.c  */
#line 690 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCmpBinary(
          AST_EXPR_CMP_BINARY, "SUBQUERY",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (5))].yystate.yysemantics.yysval.subtok),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (5))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 102:
/* Line 868 of glr.c  */
#line 691 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCmpBinary(
          AST_EXPR_CMP_BINARY, "ANY",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (6))].yystate.yysemantics.yysval.subtok),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (6))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (6))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 103:
/* Line 868 of glr.c  */
#line 692 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCmpBinary(
          AST_EXPR_CMP_BINARY, "SOME",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (6))].yystate.yysemantics.yysval.subtok),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (6))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (6))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 104:
/* Line 868 of glr.c  */
#line 693 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCmpBinary(
          AST_EXPR_CMP_BINARY, "ALL",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (6))].yystate.yysemantics.yysval.subtok),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (6))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (6))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 105:
/* Line 868 of glr.c  */
#line 695 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_CAL_BINARY, "|",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 106:
/* Line 868 of glr.c  */
#line 696 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_CAL_BINARY, "&",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 107:
/* Line 868 of glr.c  */
#line 697 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_CAL_BINARY, "^",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 108:
/* Line 868 of glr.c  */
#line 698 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_CAL_BINARY, SHIFT == 1 ? "LSHIFT" : "RSHIFT",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 109:
/* Line 868 of glr.c  */
#line 700 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "!",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (2))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 110:
/* Line 868 of glr.c  */
#line 701 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "NOT",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (2))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 111:
/* Line 868 of glr.c  */
#line 702 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 112:
/* Line 868 of glr.c  */
#line 703 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 113:
/* Line 868 of glr.c  */
#line 706 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "IS_NULL",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 114:
/* Line 868 of glr.c  */
#line 707 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "IS_NOT_NULL",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 115:
/* Line 868 of glr.c  */
#line 708 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "IS_BOOL",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 116:
/* Line 868 of glr.c  */
#line 709 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "IS_NOT_BOOL",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 117:
/* Line 868 of glr.c  */
#line 712 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "BETWEEN_AND",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (5))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (5))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 118:
/* Line 868 of glr.c  */
#line 715 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprList(
          AST_EXPR_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                              .yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 119:
/* Line 868 of glr.c  */
#line 716 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprList(
          AST_EXPR_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                              .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 120:
/* Line 868 of glr.c  */
#line 717 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 121:
/* Line 868 of glr.c  */
#line 720 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprList(
          AST_EXPR_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                              .yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 122:
/* Line 868 of glr.c  */
#line 721 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprList(
          AST_EXPR_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                              .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 123:
/* Line 868 of glr.c  */
#line 724 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCmpBinary(
          AST_EXPR_CMP_BINARY, "EXPR_IN_LIST",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (5))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 124:
/* Line 868 of glr.c  */
#line 725 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCmpBinary(
          AST_EXPR_CMP_BINARY, "LIST_IN_LIST",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (7))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((6) - (7))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 125:
/* Line 868 of glr.c  */
#line 726 "sql.ypp"
    {
      AstNode *tmp_node = new AstExprCmpBinary(
          AST_EXPR_CMP_BINARY, "EXPR_IN_LIST",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (6))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (6))].yystate.yysemantics.yysval.ast_node));
      ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "NOT", tmp_node);
    } break;

    case 126:
/* Line 868 of glr.c  */
#line 728 "sql.ypp"
    {
      AstNode *tmp_node = new AstExprCmpBinary(
          AST_EXPR_CMP_BINARY, "LIST_IN_LIST",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (8))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((7) - (8))].yystate.yysemantics.yysval.ast_node));
      ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "NOT", tmp_node);
    } break;

    case 127:
/* Line 868 of glr.c  */
#line 730 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCmpBinary(
          AST_EXPR_CMP_BINARY, "EXPR_IN_SELECT",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (5))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 128:
/* Line 868 of glr.c  */
#line 731 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCmpBinary(
          AST_EXPR_CMP_BINARY, "LIST_IN_SELECT",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (7))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((6) - (7))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 129:
/* Line 868 of glr.c  */
#line 732 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCmpBinary(
          AST_EXPR_CMP_BINARY, "EXPR_NOT_IN_SELECT",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (6))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (6))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 130:
/* Line 868 of glr.c  */
#line 733 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCmpBinary(
          AST_EXPR_CMP_BINARY, "LIST_NOT_IN_SELECT",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (8))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((7) - (8))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 131:
/* Line 868 of glr.c  */
#line 735 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "EXSIST",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 132:
/* Line 868 of glr.c  */
#line 736 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "NOT_EXSIST",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 133:
/* Line 868 of glr.c  */
#line 746 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstExprUnary(AST_EXPR_UNARY, "COUNT_ALL", NULL);
    } break;

    case 134:
/* Line 868 of glr.c  */
#line 747 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "COUNT",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 135:
/* Line 868 of glr.c  */
#line 748 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "SUM",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 136:
/* Line 868 of glr.c  */
#line 749 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "AVG",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 137:
/* Line 868 of glr.c  */
#line 750 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "MIN",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 138:
/* Line 868 of glr.c  */
#line 751 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "MAX",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 139:
/* Line 868 of glr.c  */
#line 755 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "SUBSTRING_EXPR_EXPR",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (6))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (6))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 140:
/* Line 868 of glr.c  */
#line 756 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "SUBSTRING_EXPR_FROM_EXPR",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (6))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (6))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 141:
/* Line 868 of glr.c  */
#line 757 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "SUBSTRING_EXPR_EXPR_EXPR",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (8))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (8))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((7) - (8))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 142:
/* Line 868 of glr.c  */
#line 758 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "SUBSTRING_EXPR_FROM_EXPR_FOR_EXPR",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (8))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (8))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((7) - (8))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 143:
/* Line 868 of glr.c  */
#line 759 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "TRIM_BOTH", NULL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 144:
/* Line 868 of glr.c  */
#line 760 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, (((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (7))]
                              .yystate.yysemantics.yysval.strval),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (7))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((6) - (7))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 145:
/* Line 868 of glr.c  */
#line 761 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "UPPER",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 146:
/* Line 868 of glr.c  */
#line 762 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "CAST",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (6))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (6))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 147:
/* Line 868 of glr.c  */
#line 763 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "COALESCE",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 148:
/* Line 868 of glr.c  */
#line 766 "sql.ypp"
    {
      ((*yyvalp).strval) = "TRIM_LEADING";
    } break;

    case 149:
/* Line 868 of glr.c  */
#line 767 "sql.ypp"
    {
      ((*yyvalp).strval) = "TRIM_TRAILING";
    } break;

    case 150:
/* Line 868 of glr.c  */
#line 768 "sql.ypp"
    {
      ((*yyvalp).strval) = "TRIM_BOTH";
    } break;

    case 151:
/* Line 868 of glr.c  */
#line 771 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 152:
/* Line 868 of glr.c  */
#line 772 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "INT", NULL);
    } break;

    case 153:
/* Line 868 of glr.c  */
#line 773 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "STRING", NULL);
    } break;

    case 154:
/* Line 868 of glr.c  */
#line 774 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "DOUBLE", NULL);
    } break;

    case 155:
/* Line 868 of glr.c  */
#line 775 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "FLOAT", NULL);
    } break;

    case 156:
/* Line 868 of glr.c  */
#line 776 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "CHAR", NULL);
    } break;

    case 157:
/* Line 868 of glr.c  */
#line 779 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "DATE_ADD",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (6))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (6))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 158:
/* Line 868 of glr.c  */
#line 780 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "DATE_SUB",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (6))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (6))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 159:
/* Line 868 of glr.c  */
#line 784 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "INTERVAL_HOUR",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 160:
/* Line 868 of glr.c  */
#line 785 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "INTERVAL_MICROSECOND",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 161:
/* Line 868 of glr.c  */
#line 786 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "INTERVAL_MINUTE",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 162:
/* Line 868 of glr.c  */
#line 787 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "INTERVAL_SECOND",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 163:
/* Line 868 of glr.c  */
#line 788 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "INTERVAL_DAY",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 164:
/* Line 868 of glr.c  */
#line 789 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "INTERVAL_MONTH",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 165:
/* Line 868 of glr.c  */
#line 790 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "INTERVAL_YEAR",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 166:
/* Line 868 of glr.c  */
#line 791 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "INTERVAL_WEEK",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 167:
/* Line 868 of glr.c  */
#line 792 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "INTERVAL_QUARTER",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 168:
/* Line 868 of glr.c  */
#line 796 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "CASE1",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (4))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 169:
/* Line 868 of glr.c  */
#line 797 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "CASE1_ELSE",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (6))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (6))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (6))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 170:
/* Line 868 of glr.c  */
#line 798 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "CASE2", NULL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 171:
/* Line 868 of glr.c  */
#line 799 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "CASE2_ELSE", NULL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (5))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 172:
/* Line 868 of glr.c  */
#line 802 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "WHEN",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (4))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (4))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 173:
/* Line 868 of glr.c  */
#line 803 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "WHEN",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (5))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (5))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 174:
/* Line 868 of glr.c  */
#line 806 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_CAL_BINARY, "LIKE",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 175:
/* Line 868 of glr.c  */
#line 807 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_CAL_BINARY, "NOT_LIKE",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (4))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 176:
/* Line 868 of glr.c  */
#line 810 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_CAL_BINARY, "REGEXP",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 177:
/* Line 868 of glr.c  */
#line 811 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_CAL_BINARY, "NOT_REGEXP",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (4))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 178:
/* Line 868 of glr.c  */
#line 817 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 179:
/* Line 868 of glr.c  */
#line 821 "sql.ypp"
    {
      string temp =
          ((((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (4))]
                .yystate.yysemantics.yysval.strval) == NULL)
              ? ""
              : string((((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (4))]
                            .yystate.yysemantics.yysval.strval));
      ((*yyvalp).ast_node) = new AstCreateDatabase(
          AST_CREATE_DATABASE, 1,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.intval),
          temp);
    } break;

    case 180:
/* Line 868 of glr.c  */
#line 822 "sql.ypp"
    {
      string temp =
          ((((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (4))]
                .yystate.yysemantics.yysval.strval) == NULL)
              ? ""
              : string((((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (4))]
                            .yystate.yysemantics.yysval.strval));
      ((*yyvalp).ast_node) = new AstCreateDatabase(
          AST_CREATE_SCHEMA, 2,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.intval),
          temp);
    } break;

    case 181:
/* Line 868 of glr.c  */
#line 825 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 182:
/* Line 868 of glr.c  */
#line 826 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 183:
/* Line 868 of glr.c  */
#line 831 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 184:
/* Line 868 of glr.c  */
#line 835 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateTable(
          AST_CREATE_TABLE_LIST,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (8))].yystate.yysemantics.yysval.intval),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (8))].yystate.yysemantics.yysval.intval),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((5) - (8))]
                      .yystate.yysemantics.yysval.strval)),
          "", (((yyGLRStackItem const *)
                yyvsp)[YYFILL((7) - (8))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 185:
/* Line 868 of glr.c  */
#line 839 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateTable(
          AST_CREATE_TABLE_LIST,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (10))].yystate.yysemantics.yysval.intval),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (10))].yystate.yysemantics.yysval.intval),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((5) - (10))]
                      .yystate.yysemantics.yysval.strval)),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((7) - (10))]
                      .yystate.yysemantics.yysval.strval)),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((9) - (10))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 186:
/* Line 868 of glr.c  */
#line 844 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateTable(
          AST_CREATE_TABLE_LIST_SEL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (9))].yystate.yysemantics.yysval.intval),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (9))].yystate.yysemantics.yysval.intval),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((5) - (9))]
                      .yystate.yysemantics.yysval.strval)),
          "", (((yyGLRStackItem const *)
                yyvsp)[YYFILL((7) - (9))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((9) - (9))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 187:
/* Line 868 of glr.c  */
#line 848 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateTable(
          AST_CREATE_TABLE_SEL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (6))].yystate.yysemantics.yysval.intval),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (6))].yystate.yysemantics.yysval.intval),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((5) - (6))]
                      .yystate.yysemantics.yysval.strval)),
          "", NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL((6) - (6))]
                         .yystate.yysemantics.yysval.ast_node));
    } break;

    case 188:
/* Line 868 of glr.c  */
#line 853 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateTable(
          AST_CREATE_TABLE_LIST_SEL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (11))].yystate.yysemantics.yysval.intval),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (11))].yystate.yysemantics.yysval.intval),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((5) - (11))]
                      .yystate.yysemantics.yysval.strval)),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((7) - (11))]
                      .yystate.yysemantics.yysval.strval)),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((9) - (11))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((11) - (11))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 189:
/* Line 868 of glr.c  */
#line 857 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateTable(
          AST_CREATE_TABLE_SEL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (8))].yystate.yysemantics.yysval.intval),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (8))].yystate.yysemantics.yysval.intval),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((5) - (8))]
                      .yystate.yysemantics.yysval.strval)),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((7) - (8))]
                      .yystate.yysemantics.yysval.strval)),
          NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL((8) - (8))]
                     .yystate.yysemantics.yysval.ast_node));
    } break;

    case 190:
/* Line 868 of glr.c  */
#line 861 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateSelect(
          AST_CREATE_SEL, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                               .yystate.yysemantics.yysval.intval),
          0, (((yyGLRStackItem const *)
               yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 191:
/* Line 868 of glr.c  */
#line 864 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 192:
/* Line 868 of glr.c  */
#line 865 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 193:
/* Line 868 of glr.c  */
#line 866 "sql.ypp"
    {
      ((*yyvalp).intval) = 2;
    } break;

    case 194:
/* Line 868 of glr.c  */
#line 869 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 195:
/* Line 868 of glr.c  */
#line 870 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 196:
/* Line 868 of glr.c  */
#line 873 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateColList(
          AST_CREATE_COL_LIST,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (1))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 197:
/* Line 868 of glr.c  */
#line 874 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateColList(
          AST_CREATE_COL_LIST,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 198:
/* Line 868 of glr.c  */
#line 879 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateDef(
          AST_CREATE_DEF_NAME, 1,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                      .yystate.yysemantics.yysval.strval)),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 199:
/* Line 868 of glr.c  */
#line 880 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateDef(
          AST_CREATE_DEF_PR_KEY, 2, "", NULL, NULL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 200:
/* Line 868 of glr.c  */
#line 881 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateDef(
          AST_CREATE_DEF_KEY, 3, "", NULL, NULL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 201:
/* Line 868 of glr.c  */
#line 882 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateDef(
          AST_CREATE_DEF_INDEX, 4, "", NULL, NULL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 202:
/* Line 868 of glr.c  */
#line 883 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateDef(
          AST_CREATE_DEF_FTEXT_INDEX, 5, "", NULL, NULL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 203:
/* Line 868 of glr.c  */
#line 884 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateDef(
          AST_CREATE_DEF_FTEXT_KEY, 6, "", NULL, NULL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 204:
/* Line 868 of glr.c  */
#line 886 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstColumnAtts(AST_COLUMN_ATTS, 0, 0, 0, "", NULL);
    } break;

    case 205:
/* Line 868 of glr.c  */
#line 887 "sql.ypp"
    {
      AstColumnAtts *temp = static_cast<AstColumnAtts *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node));
      temp->datatype_ |= 01;
      ((*yyvalp).ast_node) = temp;
    } break;

    case 206:
/* Line 868 of glr.c  */
#line 888 "sql.ypp"
    {
      AstColumnAtts *temp = static_cast<AstColumnAtts *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (2))].yystate.yysemantics.yysval.ast_node));
      temp->datatype_ |= 02;
      ((*yyvalp).ast_node) = temp;
    } break;

    case 207:
/* Line 868 of glr.c  */
#line 889 "sql.ypp"
    {
      AstColumnAtts *temp = static_cast<AstColumnAtts *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node));
      temp->datatype_ |= 04;
      temp->default_string_ =
          ((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (3))]
                .yystate.yysemantics.yysval.strval) == NULL)
              ? ""
              : string((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (3))]
                            .yystate.yysemantics.yysval.strval));
      ((*yyvalp).ast_node) = temp;
    } break;

    case 208:
/* Line 868 of glr.c  */
#line 890 "sql.ypp"
    {
      AstColumnAtts *temp = static_cast<AstColumnAtts *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node));
      temp->datatype_ |= 010;
      temp->int_num_ = atoi((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (3))]
                                 .yystate.yysemantics.yysval.strval));
      ((*yyvalp).ast_node) = temp;
    } break;

    case 209:
/* Line 868 of glr.c  */
#line 891 "sql.ypp"
    {
      AstColumnAtts *temp = static_cast<AstColumnAtts *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node));
      temp->datatype_ |= 020;
      temp->double_num_ =
          atof((((yyGLRStackItem const *)
                 yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.strval));
      ((*yyvalp).ast_node) = temp;
    } break;

    case 210:
/* Line 868 of glr.c  */
#line 892 "sql.ypp"
    {
      AstColumnAtts *temp = static_cast<AstColumnAtts *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node));
      temp->datatype_ |= 040;
      temp->int_num_ = atoi((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (3))]
                                 .yystate.yysemantics.yysval.strval));
      ((*yyvalp).ast_node) = temp;
    } break;

    case 211:
/* Line 868 of glr.c  */
#line 893 "sql.ypp"
    {
      AstColumnAtts *temp = static_cast<AstColumnAtts *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (2))].yystate.yysemantics.yysval.ast_node));
      temp->datatype_ |= 0100;
      ((*yyvalp).ast_node) = temp;
    } break;

    case 212:
/* Line 868 of glr.c  */
#line 894 "sql.ypp"
    {
      AstColumnAtts *temp = static_cast<AstColumnAtts *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node));
      temp->datatype_ |= 0200;
      ((*yyvalp).ast_node) = temp;
    } break;

    case 213:
/* Line 868 of glr.c  */
#line 895 "sql.ypp"
    {
      AstColumnAtts *temp = static_cast<AstColumnAtts *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node));
      temp->datatype_ |= 0400;
      ((*yyvalp).ast_node) = temp;
    } break;

    case 214:
/* Line 868 of glr.c  */
#line 896 "sql.ypp"
    {
      AstColumnAtts *temp = static_cast<AstColumnAtts *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (2))].yystate.yysemantics.yysval.ast_node));
      temp->datatype_ |= 01000;
      ((*yyvalp).ast_node) = temp;
    } break;

    case 215:
/* Line 868 of glr.c  */
#line 897 "sql.ypp"
    {
      AstColumnAtts *temp = static_cast<AstColumnAtts *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node));
      temp->datatype_ |= 02000;
      ((*yyvalp).ast_node) = temp;
    } break;

    case 216:
/* Line 868 of glr.c  */
#line 898 "sql.ypp"
    {
      AstColumnAtts *temp = static_cast<AstColumnAtts *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (5))].yystate.yysemantics.yysval.ast_node));
      temp->datatype_ |= 04000;
      temp->col_list_ = (((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (5))]
                             .yystate.yysemantics.yysval.ast_node);
      ((*yyvalp).ast_node) = temp;
    } break;

    case 217:
/* Line 868 of glr.c  */
#line 902 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 1, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (2))]
                                 .yystate.yysemantics.yysval.ast_node),
          0, NULL, 0, NULL);
    } break;

    case 218:
/* Line 868 of glr.c  */
#line 903 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 2, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                 .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.intval),
          NULL, 0, NULL);
    } break;

    case 219:
/* Line 868 of glr.c  */
#line 904 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 3, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                 .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.intval),
          NULL, 0, NULL);
    } break;

    case 220:
/* Line 868 of glr.c  */
#line 905 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 4, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                 .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.intval),
          NULL, 0, NULL);
    } break;

    case 221:
/* Line 868 of glr.c  */
#line 906 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 5, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                 .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.intval),
          NULL, 0, NULL);
    } break;

    case 222:
/* Line 868 of glr.c  */
#line 907 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 6, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                 .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.intval),
          NULL, 0, NULL);
    } break;

    case 223:
/* Line 868 of glr.c  */
#line 908 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 7, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                 .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.intval),
          NULL, 0, NULL);
    } break;

    case 224:
/* Line 868 of glr.c  */
#line 909 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 8, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                 .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.intval),
          NULL, 0, NULL);
    } break;

    case 225:
/* Line 868 of glr.c  */
#line 910 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 9, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                 .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.intval),
          NULL, 0, NULL);
    } break;

    case 226:
/* Line 868 of glr.c  */
#line 911 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 10, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                  .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.intval),
          NULL, 0, NULL);
    } break;

    case 227:
/* Line 868 of glr.c  */
#line 912 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 11, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                  .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.intval),
          NULL, 0, NULL);
    } break;

    case 228:
/* Line 868 of glr.c  */
#line 913 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstDataType(AST_DATA_TYPE, 12, NULL, 0, NULL, 0, NULL);
    } break;

    case 229:
/* Line 868 of glr.c  */
#line 914 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstDataType(AST_DATA_TYPE, 13, NULL, 0, NULL, 0, NULL);
    } break;

    case 230:
/* Line 868 of glr.c  */
#line 915 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstDataType(AST_DATA_TYPE, 14, NULL, 0, NULL, 0, NULL);
    } break;

    case 231:
/* Line 868 of glr.c  */
#line 916 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstDataType(AST_DATA_TYPE, 15, NULL, 0, NULL, 0, NULL);
    } break;

    case 232:
/* Line 868 of glr.c  */
#line 917 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstDataType(AST_DATA_TYPE, 16, NULL, 0, NULL, 0, NULL);
    } break;

    case 233:
/* Line 868 of glr.c  */
#line 918 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 17, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                  .yystate.yysemantics.yysval.ast_node),
          0, (((yyGLRStackItem const *)
               yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node),
          0, NULL);
    } break;

    case 234:
/* Line 868 of glr.c  */
#line 919 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 18, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                  .yystate.yysemantics.yysval.ast_node),
          0, (((yyGLRStackItem const *)
               yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node),
          0, NULL);
    } break;

    case 235:
/* Line 868 of glr.c  */
#line 920 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 19, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (2))]
                                  .yystate.yysemantics.yysval.ast_node),
          0, NULL, 0, NULL);
    } break;

    case 236:
/* Line 868 of glr.c  */
#line 921 "sql.ypp"
    {
      AstNode *temp = new AstOptLength(
          AST_OPT_LENGTH,
          atoi((((yyGLRStackItem const *)
                 yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.strval)),
          NULL);
      ((*yyvalp).ast_node) =
          new AstDataType(AST_DATA_TYPE, 20, temp, 0, NULL, 0, NULL);
    } break;

    case 237:
/* Line 868 of glr.c  */
#line 923 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstDataType(AST_DATA_TYPE, 21, NULL, 0, NULL, 0, NULL);
    } break;

    case 238:
/* Line 868 of glr.c  */
#line 924 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstDataType(AST_DATA_TYPE, 22, NULL, 0, NULL, 0, NULL);
    } break;

    case 239:
/* Line 868 of glr.c  */
#line 925 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstDataType(AST_DATA_TYPE, 23, NULL, 0, NULL, 0, NULL);
    } break;

    case 240:
/* Line 868 of glr.c  */
#line 926 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstDataType(AST_DATA_TYPE, 24, NULL, 0, NULL, 0, NULL);
    } break;

    case 241:
/* Line 868 of glr.c  */
#line 927 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 25, NULL, 0,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.intval),
          NULL);
    } break;

    case 242:
/* Line 868 of glr.c  */
#line 928 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 26, NULL, 0,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.intval),
          NULL);
    } break;

    case 243:
/* Line 868 of glr.c  */
#line 929 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 27, NULL, 0,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.intval),
          NULL);
    } break;

    case 244:
/* Line 868 of glr.c  */
#line 930 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 28, NULL, 0,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.intval),
          NULL);
    } break;

    case 245:
/* Line 868 of glr.c  */
#line 931 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 29, NULL, 0,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (5))].yystate.yysemantics.yysval.ast_node),
          0, (((yyGLRStackItem const *)
               yyvsp)[YYFILL((3) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 246:
/* Line 868 of glr.c  */
#line 932 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 30, NULL, 0,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (5))].yystate.yysemantics.yysval.ast_node),
          0, (((yyGLRStackItem const *)
               yyvsp)[YYFILL((3) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 247:
/* Line 868 of glr.c  */
#line 934 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstEnumList(
          AST_ENUM, string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                .yystate.yysemantics.yysval.strval)),
          NULL);
    } break;

    case 248:
/* Line 868 of glr.c  */
#line 935 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstEnumList(
          AST_ENUM_LIST,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (3))]
                      .yystate.yysemantics.yysval.strval)),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 249:
/* Line 868 of glr.c  */
#line 938 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 250:
/* Line 868 of glr.c  */
#line 939 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstOptLength(
          AST_OPT_LENGTH,
          atoi((((yyGLRStackItem const *)
                 yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.strval)),
          0);
    } break;

    case 251:
/* Line 868 of glr.c  */
#line 940 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstOptLength(
          AST_OPT_LENGTH,
          atoi((((yyGLRStackItem const *)
                 yyvsp)[YYFILL((2) - (5))].yystate.yysemantics.yysval.strval)),
          atoi((((yyGLRStackItem const *)
                 yyvsp)[YYFILL((4) - (5))].yystate.yysemantics.yysval.strval)));
    } break;

    case 252:
/* Line 868 of glr.c  */
#line 943 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 253:
/* Line 868 of glr.c  */
#line 944 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 254:
/* Line 868 of glr.c  */
#line 947 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 255:
/* Line 868 of glr.c  */
#line 948 "sql.ypp"
    {
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                .yystate.yysemantics.yysval.intval) |
                           01;
    } break;

    case 256:
/* Line 868 of glr.c  */
#line 949 "sql.ypp"
    {
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                .yystate.yysemantics.yysval.intval) |
                           02;
    } break;

    case 257:
/* Line 868 of glr.c  */
#line 952 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstOptCsc(AST_OPT_CSC, 0, "", "");
    } break;

    case 258:
/* Line 868 of glr.c  */
#line 954 "sql.ypp"
    {
      AstOptCsc *temp = static_cast<AstOptCsc *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (4))].yystate.yysemantics.yysval.ast_node));
      temp->data_type_ |= 01;
      temp->str1_ = string((((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (4))]
                                .yystate.yysemantics.yysval.strval));
      ((*yyvalp).ast_node) = temp;
    } break;

    case 259:
/* Line 868 of glr.c  */
#line 956 "sql.ypp"
    {
      AstOptCsc *temp = static_cast<AstOptCsc *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node));
      temp->data_type_ |= 02;
      temp->str2_ = string((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (3))]
                                .yystate.yysemantics.yysval.strval));
      ((*yyvalp).ast_node) = temp;
    } break;

    case 260:
/* Line 868 of glr.c  */
#line 960 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval
                                  .ast_node); /* puts("SQL parser： This is a
                                                 create_projection
                                                 statement");*/
    } break;

    case 261:
/* Line 868 of glr.c  */
#line 964 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateProjection(
          AST_CREATE_PROJECTION,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (10))]
                      .yystate.yysemantics.yysval.strval)),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((6) - (10))].yystate.yysemantics.yysval.ast_node),
          1, string((((yyGLRStackItem const *)yyvsp)[YYFILL((10) - (10))]
                         .yystate.yysemantics.yysval.strval)));
    } break;

    case 262:
/* Line 868 of glr.c  */
#line 966 "sql.ypp"
    {
      if ((((yyGLRStackItem const *)yyvsp)[YYFILL((9) - (13))]
               .yystate.yysemantics.yysval.subtok) != 4) {
        yyerror(result, "please give a specific number");
      } else {
        ((*yyvalp).ast_node) = new AstCreateProjection(
            AST_CREATE_PROJECTION_NUM,
            string((((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (13))]
                        .yystate.yysemantics.yysval.strval)),
            (((yyGLRStackItem const *)
              yyvsp)[YYFILL((6) - (13))].yystate.yysemantics.yysval.ast_node),
            atoi((((yyGLRStackItem const *)yyvsp)[YYFILL((10) - (13))]
                      .yystate.yysemantics.yysval.strval)),
            string((((yyGLRStackItem const *)yyvsp)[YYFILL((13) - (13))]
                        .yystate.yysemantics.yysval.strval)));
      }
    } break;

    case 263:
/* Line 868 of glr.c  */
#line 973 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 264:
/* Line 868 of glr.c  */
#line 978 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateIndex(
          AST_CREATE_INDEX, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (10))]
                                 .yystate.yysemantics.yysval.intval),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (10))]
                      .yystate.yysemantics.yysval.strval)),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (10))].yystate.yysemantics.yysval.intval),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((7) - (10))].yystate.yysemantics.yysval.strval),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((9) - (10))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 265:
/* Line 868 of glr.c  */
#line 981 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 266:
/* Line 868 of glr.c  */
#line 982 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 267:
/* Line 868 of glr.c  */
#line 983 "sql.ypp"
    {
      ((*yyvalp).intval) = 2;
    } break;

    case 268:
/* Line 868 of glr.c  */
#line 984 "sql.ypp"
    {
      ((*yyvalp).intval) = 3;
    } break;

    case 269:
/* Line 868 of glr.c  */
#line 987 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 270:
/* Line 868 of glr.c  */
#line 988 "sql.ypp"
    {
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (2))]
                                .yystate.yysemantics.yysval.intval);
    } break;

    case 271:
/* Line 868 of glr.c  */
#line 991 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 272:
/* Line 868 of glr.c  */
#line 992 "sql.ypp"
    {
      ((*yyvalp).intval) = 2;
    } break;

    case 273:
/* Line 868 of glr.c  */
#line 995 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstIndexColList(
          AST_INDEX_COL,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                      .yystate.yysemantics.yysval.strval)),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.intval),
          NULL);
    } break;

    case 274:
/* Line 868 of glr.c  */
#line 996 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstIndexColList(
          AST_INDEX_COL_LIST,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (5))]
                      .yystate.yysemantics.yysval.strval)),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (5))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (5))].yystate.yysemantics.yysval.intval),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 275:
/* Line 868 of glr.c  */
#line 1000 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 276:
/* Line 868 of glr.c  */
#line 1004 "sql.ypp"
    {
      if ((((yyGLRStackItem const *)yyvsp)[YYFILL((11) - (12))]
               .yystate.yysemantics.yysval.subtok) != 4) {
        yyerror(result, "please give a specific number");
      } else {
        ((*yyvalp).ast_node) = new AstLoadTable(
            AST_LOAD_TABLE,
            string((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (12))]
                        .yystate.yysemantics.yysval.strval)),
            (((yyGLRStackItem const *)
              yyvsp)[YYFILL((5) - (12))].yystate.yysemantics.yysval.ast_node),
            string((((yyGLRStackItem const *)yyvsp)[YYFILL((7) - (12))]
                        .yystate.yysemantics.yysval.strval)),
            string((((yyGLRStackItem const *)yyvsp)[YYFILL((9) - (12))]
                        .yystate.yysemantics.yysval.strval)),
            atof((((yyGLRStackItem const *)yyvsp)[YYFILL((12) - (12))]
                      .yystate.yysemantics.yysval.strval)),
            1);
      }
    } break;

    case 277:
/* Line 868 of glr.c  */
#line 1008 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstLoadTable(
          AST_LOAD_TABLE,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (9))]
                      .yystate.yysemantics.yysval.strval)),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (9))].yystate.yysemantics.yysval.ast_node),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((7) - (9))]
                      .yystate.yysemantics.yysval.strval)),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((9) - (9))]
                      .yystate.yysemantics.yysval.strval)),
          1.0, 1);
    } break;

    case 278:
/* Line 868 of glr.c  */
#line 1009 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstLoadTable(
          AST_LOAD_TABLE,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (9))]
                      .yystate.yysemantics.yysval.strval)),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (9))].yystate.yysemantics.yysval.ast_node),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((7) - (9))]
                      .yystate.yysemantics.yysval.strval)),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((9) - (9))]
                      .yystate.yysemantics.yysval.strval)),
          1.0, 2);
    } break;

    case 279:
/* Line 868 of glr.c  */
#line 1011 "sql.ypp"
    {
      if ((((yyGLRStackItem const *)yyvsp)[YYFILL((11) - (12))]
               .yystate.yysemantics.yysval.subtok) != 4) {
        yyerror(result, "please give a specific number");
      } else {
        ((*yyvalp).ast_node) = new AstLoadTable(
            AST_LOAD_TABLE,
            string((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (12))]
                        .yystate.yysemantics.yysval.strval)),
            (((yyGLRStackItem const *)
              yyvsp)[YYFILL((5) - (12))].yystate.yysemantics.yysval.ast_node),
            string((((yyGLRStackItem const *)yyvsp)[YYFILL((7) - (12))]
                        .yystate.yysemantics.yysval.strval)),
            string((((yyGLRStackItem const *)yyvsp)[YYFILL((9) - (12))]
                        .yystate.yysemantics.yysval.strval)),
            atof((((yyGLRStackItem const *)yyvsp)[YYFILL((12) - (12))]
                      .yystate.yysemantics.yysval.strval)),
            2);
      }
    } break;

    case 280:
/* Line 868 of glr.c  */
#line 1017 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval
                                  .ast_node); /*output($$, 1); puts("SQL
                                                 parser： This is a drop_index
                                                 statement");*/
    } break;

    case 281:
/* Line 868 of glr.c  */
#line 1020 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDropIndex(
          AST_DROP_INDEX,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (5))]
                      .yystate.yysemantics.yysval.strval)),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((5) - (5))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 282:
/* Line 868 of glr.c  */
#line 1024 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval
                                  .ast_node); /* output($$, 1); puts("SQL
                                                 parser： This is a
                                                 drop_database statement");*/
    } break;

    case 283:
/* Line 868 of glr.c  */
#line 1028 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDropDatabase(
          AST_DROP_DB, 1, (((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (4))]
                               .yystate.yysemantics.yysval.intval),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (4))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 284:
/* Line 868 of glr.c  */
#line 1029 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDropDatabase(
          AST_DROP_SCHEMA, 2,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.intval),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (4))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 285:
/* Line 868 of glr.c  */
#line 1032 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 286:
/* Line 868 of glr.c  */
#line 1033 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 287:
/* Line 868 of glr.c  */
#line 1037 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval
                                  .ast_node); /*output($$, 1); puts("SQL
                                                 parser： This is a drop_table
                                                 statement"); */
    } break;

    case 288:
/* Line 868 of glr.c  */
#line 1041 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDropTable(
          AST_DROP_TABLE, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (6))]
                               .yystate.yysemantics.yysval.intval),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (6))].yystate.yysemantics.yysval.intval),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((6) - (6))].yystate.yysemantics.yysval.intval),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (6))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 289:
/* Line 868 of glr.c  */
#line 1044 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDropTableList(
          AST_DROP_TABLE_LIST, "",
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                      .yystate.yysemantics.yysval.strval)),
          NULL);
      puts("1");
    } break;

    case 290:
/* Line 868 of glr.c  */
#line 1045 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDropTableList(
          AST_DROP_TABLE_LIST,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                      .yystate.yysemantics.yysval.strval)),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (3))]
                      .yystate.yysemantics.yysval.strval)),
          NULL);
      puts("2");
    } break;

    case 291:
/* Line 868 of glr.c  */
#line 1046 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDropTableList(
          AST_DROP_TABLE_LIST, "",
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                      .yystate.yysemantics.yysval.strval)),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
      puts("3");
    } break;

    case 292:
/* Line 868 of glr.c  */
#line 1047 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDropTableList(
          AST_DROP_TABLE_LIST,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (5))]
                      .yystate.yysemantics.yysval.strval)),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (5))]
                      .yystate.yysemantics.yysval.strval)),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (5))].yystate.yysemantics.yysval.ast_node));
      puts("4");
    } break;

    case 293:
/* Line 868 of glr.c  */
#line 1050 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 294:
/* Line 868 of glr.c  */
#line 1051 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 295:
/* Line 868 of glr.c  */
#line 1052 "sql.ypp"
    {
      ((*yyvalp).intval) = 2;
    } break;

    case 296:
/* Line 868 of glr.c  */
#line 1056 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval
                                  .ast_node); /*output($$, 1); puts("SQL
                                                 parser： This is a
                                                 drop_projection statement"); */
    } break;

    case 297:
/* Line 868 of glr.c  */
#line 1059 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDropProjection(
          AST_DROP_PROJECTION,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (4))]
                      .yystate.yysemantics.yysval.strval)),
          1, NULL);
    } break;

    case 298:
/* Line 868 of glr.c  */
#line 1061 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDropProjection(
          AST_DROP_PROJECTION,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((5) - (5))]
                      .yystate.yysemantics.yysval.strval)),
          0, atoi((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (5))]
                       .yystate.yysemantics.yysval.strval)));
    } break;

    case 299:
/* Line 868 of glr.c  */
#line 1067 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval
                                  .ast_node); /*output($$, 1); puts("SQL
                                                 parser： This is a truncate
                                                 statement"); */
    } break;

    case 300:
/* Line 868 of glr.c  */
#line 1070 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstTruncateTable(
          AST_TRUNCATE_TABLE,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node),
          "", "");
      puts("5");
    } break;

    case 301:
/* Line 868 of glr.c  */
#line 1071 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstTruncateTable(
          AST_TRUNCATE_TABLE, NULL,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (7))]
                      .yystate.yysemantics.yysval.strval)),
          atoi((((yyGLRStackItem const *)
                 yyvsp)[YYFILL((7) - (7))].yystate.yysemantics.yysval.strval)));
      puts("6");
    } break;

    case 302:
/* Line 868 of glr.c  */
#line 1076 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 303:
/* Line 868 of glr.c  */
#line 1082 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstInsertStmt(
          AST_INSERT_STMT, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (8))]
                                .yystate.yysemantics.yysval.intval),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (8))]
                      .yystate.yysemantics.yysval.strval)),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (8))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((7) - (8))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((8) - (8))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 304:
/* Line 868 of glr.c  */
#line 1085 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 305:
/* Line 868 of glr.c  */
#line 1086 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((5) - (5))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 306:
/* Line 868 of glr.c  */
#line 1089 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 307:
/* Line 868 of glr.c  */
#line 1090 "sql.ypp"
    {
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                .yystate.yysemantics.yysval.intval) |
                           01;
    } break;

    case 308:
/* Line 868 of glr.c  */
#line 1091 "sql.ypp"
    {
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                .yystate.yysemantics.yysval.intval) |
                           02;
    } break;

    case 309:
/* Line 868 of glr.c  */
#line 1092 "sql.ypp"
    {
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                .yystate.yysemantics.yysval.intval) |
                           04;
    } break;

    case 310:
/* Line 868 of glr.c  */
#line 1093 "sql.ypp"
    {
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                .yystate.yysemantics.yysval.intval) |
                           010;
    } break;

    case 313:
/* Line 868 of glr.c  */
#line 1099 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 314:
/* Line 868 of glr.c  */
#line 1100 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 315:
/* Line 868 of glr.c  */
#line 1103 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstInsertValList(
          AST_INSERT_VALUE_LIST,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 316:
/* Line 868 of glr.c  */
#line 1104 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstInsertValList(
          AST_INSERT_VALUE_LIST,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (5))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 317:
/* Line 868 of glr.c  */
#line 1108 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstInsertVals(
          AST_INSERT_VALUE, 0,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (1))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 318:
/* Line 868 of glr.c  */
#line 1109 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstInsertVals(AST_INSERT_VALUE, 1, NULL, NULL);
    } break;

    case 319:
/* Line 868 of glr.c  */
#line 1110 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstInsertVals(
          AST_INSERT_VALUE, 0,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 320:
/* Line 868 of glr.c  */
#line 1111 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstInsertVals(
          AST_INSERT_VALUE, 1, NULL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 321:
/* Line 868 of glr.c  */
#line 1115 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstInsertStmt(
          AST_INSERT_STMT, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (7))]
                                .yystate.yysemantics.yysval.intval),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (7))]
                      .yystate.yysemantics.yysval.strval)),
          NULL, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL((7) - (7))]
                           .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((6) - (7))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 322:
/* Line 868 of glr.c  */
#line 1119 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstInsertStmt(
          AST_INSERT_STMT, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (7))]
                                .yystate.yysemantics.yysval.intval),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (7))]
                      .yystate.yysemantics.yysval.strval)),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (7))].yystate.yysemantics.yysval.ast_node),
          NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL((7) - (7))]
                     .yystate.yysemantics.yysval.ast_node),
          NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL((6) - (7))]
                     .yystate.yysemantics.yysval.ast_node));
    } break;

    case 323:
/* Line 868 of glr.c  */
#line 1123 "sql.ypp"
    {
      if ((((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.subtok) != 4)
        yyerror(result, "bad insert assignment to %s",
                (((yyGLRStackItem const *)
                  yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.strval));
      else
        ((*yyvalp).ast_node) = new AstInsertAssignList(
            AST_INSERT_ASSIGN_LIST,
            string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                        .yystate.yysemantics.yysval.strval)),
            0, (((yyGLRStackItem const *)
                 yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node),
            NULL);
    } break;

    case 324:
/* Line 868 of glr.c  */
#line 1126 "sql.ypp"
    {
      if ((((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.subtok) != 4)
        yyerror(result, "bad insert assignment to %s",
                (((yyGLRStackItem const *)
                  yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.strval));
      else
        ((*yyvalp).ast_node) = new AstInsertAssignList(
            AST_INSERT_ASSIGN_LIST,
            string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                        .yystate.yysemantics.yysval.strval)),
            1, NULL, NULL);
    } break;

    case 325:
/* Line 868 of glr.c  */
#line 1129 "sql.ypp"
    {
      if ((((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (5))].yystate.yysemantics.yysval.subtok) != 4)
        yyerror(result, "bad insert assignment to %s",
                (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (5))]
                     .yystate.yysemantics.yysval.ast_node));
      else
        ((*yyvalp).ast_node) = new AstInsertAssignList(
            AST_INSERT_ASSIGN_LIST,
            string((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (5))]
                        .yystate.yysemantics.yysval.strval)),
            0, (((yyGLRStackItem const *)
                 yyvsp)[YYFILL((5) - (5))].yystate.yysemantics.yysval.ast_node),
            (((yyGLRStackItem const *)
              yyvsp)[YYFILL((1) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 326:
/* Line 868 of glr.c  */
#line 1132 "sql.ypp"
    {
      if ((((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (5))].yystate.yysemantics.yysval.subtok) != 4)
        yyerror(result, "bad insert assignment to %s",
                (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (5))]
                     .yystate.yysemantics.yysval.ast_node));
      else
        ((*yyvalp).ast_node) = new AstInsertAssignList(
            AST_INSERT_ASSIGN_LIST,
            string((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (5))]
                        .yystate.yysemantics.yysval.strval)),
            1, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (5))]
                          .yystate.yysemantics.yysval.ast_node));
    } break;

    case 327:
/* Line 868 of glr.c  */
#line 1137 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval
                                  .ast_node); /*output($$, 1); puts("SQL
                                                 parser： This is a show
                                                 statement");*/
    } break;

    case 328:
/* Line 868 of glr.c  */
#line 1140 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstShowStmt(
          AST_SHOW_STMT, 1, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (5))]
                                 .yystate.yysemantics.yysval.intval),
          ((((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (5))]
                .yystate.yysemantics.yysval.intval) == NULL)
              ? ""
              : string((((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (5))]
                            .yystate.yysemantics.yysval.intval)),
          ((((yyGLRStackItem const *)yyvsp)[YYFILL((5) - (5))]
                .yystate.yysemantics.yysval.strval) == NULL)
              ? ""
              : string((((yyGLRStackItem const *)yyvsp)[YYFILL((5) - (5))]
                            .yystate.yysemantics.yysval.strval)));
    } break;

    case 329:
/* Line 868 of glr.c  */
#line 1141 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 330:
/* Line 868 of glr.c  */
#line 1142 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 331:
/* Line 868 of glr.c  */
#line 1143 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 332:
/* Line 868 of glr.c  */
#line 1144 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 333:
/* Line 868 of glr.c  */
#line 1145 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 334:
/* Line 868 of glr.c  */
#line 1146 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 335:
/* Line 868 of glr.c  */
#line 1147 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 336:
/* Line 868 of glr.c  */
#line 1148 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 337:
/* Line 868 of glr.c  */
#line 1149 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 338:
/* Line 868 of glr.c  */
#line 1150 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 339:
/* Line 868 of glr.c  */
#line 1151 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 340:
/* Line 868 of glr.c  */
#line 1152 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 341:
/* Line 868 of glr.c  */
#line 1153 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 342:
/* Line 868 of glr.c  */
#line 1154 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 343:
/* Line 868 of glr.c  */
#line 1155 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 344:
/* Line 868 of glr.c  */
#line 1156 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 345:
/* Line 868 of glr.c  */
#line 1157 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 346:
/* Line 868 of glr.c  */
#line 1158 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 347:
/* Line 868 of glr.c  */
#line 1159 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 348:
/* Line 868 of glr.c  */
#line 1160 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 349:
/* Line 868 of glr.c  */
#line 1161 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 350:
/* Line 868 of glr.c  */
#line 1162 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 351:
/* Line 868 of glr.c  */
#line 1163 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 352:
/* Line 868 of glr.c  */
#line 1164 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 353:
/* Line 868 of glr.c  */
#line 1165 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 354:
/* Line 868 of glr.c  */
#line 1166 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 355:
/* Line 868 of glr.c  */
#line 1168 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 356:
/* Line 868 of glr.c  */
#line 1172 "sql.ypp"
    {
      ((*yyvalp).intval) = NULL;
    } break;

    case 357:
/* Line 868 of glr.c  */
#line 1173 "sql.ypp"
    {
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (2))]
                                .yystate.yysemantics.yysval.strval);
    } break;

    case 358:
/* Line 868 of glr.c  */
#line 1176 "sql.ypp"
    {
      ((*yyvalp).strval) = NULL;
    } break;

    case 359:
/* Line 868 of glr.c  */
#line 1177 "sql.ypp"
    {
      ((*yyvalp).strval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (2))]
                                .yystate.yysemantics.yysval.strval);
    } break;

    case 364:
/* Line 868 of glr.c  */
#line 1187 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 365:
/* Line 868 of glr.c  */
#line 1188 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 366:
/* Line 868 of glr.c  */
#line 1189 "sql.ypp"
    {
      ((*yyvalp).intval) = 2;
    } break;

    case 367:
/* Line 868 of glr.c  */
#line 1192 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDescStmt(
          AST_DESC_STMT, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (2))]
                              .yystate.yysemantics.yysval.strval));
    } break;

    case 368:
/* Line 868 of glr.c  */
#line 1195 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 369:
/* Line 868 of glr.c  */
#line 1199 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDeleteStmt(
          AST_DELETE_STMT, (((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (7))]
                                .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (7))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (7))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 370:
/* Line 868 of glr.c  */
#line 1203 "sql.ypp"
    {
      emit("DELETEMULTI %d %d %d",
           (((yyGLRStackItem const *)
             yyvsp)[YYFILL((2) - (7))].yystate.yysemantics.yysval.ast_node),
           (((yyGLRStackItem const *)
             yyvsp)[YYFILL((4) - (7))].yystate.yysemantics.yysval.ast_node),
           (((yyGLRStackItem const *)
             yyvsp)[YYFILL((6) - (7))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 371:
/* Line 868 of glr.c  */
#line 1208 "sql.ypp"
    {
    } break;

    case 372:
/* Line 868 of glr.c  */
#line 1211 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                  .yystate.yysemantics.yysval.ast_node) +
                             01;
    } break;

    case 373:
/* Line 868 of glr.c  */
#line 1212 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                  .yystate.yysemantics.yysval.ast_node) +
                             02;
    } break;

    case 374:
/* Line 868 of glr.c  */
#line 1213 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                  .yystate.yysemantics.yysval.ast_node) +
                             04;
    } break;

    case 375:
/* Line 868 of glr.c  */
#line 1214 "sql.ypp"
    {
      ((*yyvalp).ast_node) = 0;
    } break;

    case 376:
/* Line 868 of glr.c  */
#line 1218 "sql.ypp"
    {
    } break;

    case 377:
/* Line 868 of glr.c  */
#line 1219 "sql.ypp"
    {
    } break;

    case 380:
/* Line 868 of glr.c  */
#line 1226 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 381:
/* Line 868 of glr.c  */
#line 1229 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstUpdateStmt(
          AST_UPDATE_STMT, (((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (5))]
                                .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (5))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 382:
/* Line 868 of glr.c  */
#line 1232 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstUpdateSetList(
          AST_UPDATE_SET_LIST,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 383:
/* Line 868 of glr.c  */
#line 1233 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstUpdateSetList(
          AST_UPDATE_SET_LIST,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (5))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (5))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

/* Line 868 of glr.c  */
#line 4659 "sql.tab.cpp"
    default:
      break;
  }

  return yyok;
#undef yyerrok
#undef YYABORT
#undef YYACCEPT
#undef YYERROR
#undef YYBACKUP
#undef yyclearin
#undef YYRECOVERING
}

/*ARGSUSED*/ static void yyuserMerge(int yyn, YYSTYPE *yy0, YYSTYPE *yy1) {
  YYUSE(yy0);
  YYUSE(yy1);

  switch (yyn) {
    default:
      break;
  }
}

/* Bison grammar-table manipulation.  */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
static void yydestruct(const char *yymsg, int yytype, YYSTYPE *yyvaluep,
                       struct ParseResult *result) {
  YYUSE(yyvaluep);
  YYUSE(result);

  if (!yymsg) yymsg = "Deleting";
  YY_SYMBOL_PRINT(yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype) {
    default:
      break;
  }
}

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int yyrhsLength(yyRuleNum yyrule) { return yyr2[yyrule]; }

static void yydestroyGLRState(char const *yymsg, yyGLRState *yys,
                              struct ParseResult *result) {
  if (yys->yyresolved)
    yydestruct(yymsg, yystos[yys->yylrState], &yys->yysemantics.yysval, result);
  else {
#if YYDEBUG
    if (yydebug) {
      if (yys->yysemantics.yyfirstVal)
        YYFPRINTF(stderr, "%s unresolved ", yymsg);
      else
        YYFPRINTF(stderr, "%s incomplete ", yymsg);
      yy_symbol_print(stderr, yystos[yys->yylrState], YY_NULL, result);
      YYFPRINTF(stderr, "\n");
    }
#endif

    if (yys->yysemantics.yyfirstVal) {
      yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
      yyGLRState *yyrh;
      int yyn;
      for (yyrh = yyoption->yystate, yyn = yyrhsLength(yyoption->yyrule);
           yyn > 0; yyrh = yyrh->yypred, yyn -= 1)
        yydestroyGLRState(yymsg, yyrh, result);
    }
  }
}

/** Left-hand-side symbol for rule #RULE.  */
static inline yySymbol yylhsNonterm(yyRuleNum yyrule) { return yyr1[yyrule]; }

#define yypact_value_is_default(Yystate) (!!((Yystate) == (-537)))

/** True iff LR state STATE has only a default reduction (regardless
 *  of token).  */
static inline yybool yyisDefaultedState(yyStateNum yystate) {
  return yypact_value_is_default(yypact[yystate]);
}

/** The default reduction for STATE, assuming it has one.  */
static inline yyRuleNum yydefaultAction(yyStateNum yystate) {
  return yydefact[yystate];
}

#define yytable_value_is_error(Yytable_value) (!!((Yytable_value) == (-384)))

/** Set *YYACTION to the action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *CONFLICTS to a pointer into yyconfl to 0-terminated list of
 *  conflicting reductions.
 */
static inline void yygetLRActions(yyStateNum yystate, int yytoken,
                                  int *yyaction,
                                  const short int **yyconflicts) {
  int yyindex = yypact[yystate] + yytoken;
  if (yypact_value_is_default(yypact[yystate]) || yyindex < 0 ||
      YYLAST < yyindex || yycheck[yyindex] != yytoken) {
    *yyaction = -yydefact[yystate];
    *yyconflicts = yyconfl;
  } else if (!yytable_value_is_error(yytable[yyindex])) {
    *yyaction = yytable[yyindex];
    *yyconflicts = yyconfl + yyconflp[yyindex];
  } else {
    *yyaction = 0;
    *yyconflicts = yyconfl + yyconflp[yyindex];
  }
}

static inline yyStateNum yyLRgotoState(yyStateNum yystate, yySymbol yylhs) {
  int yyr;
  yyr = yypgoto[yylhs - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yylhs - YYNTOKENS];
}

static inline yybool yyisShiftAction(int yyaction) { return 0 < yyaction; }

static inline yybool yyisErrorAction(int yyaction) { return yyaction == 0; }

/* GLRStates */

/** Return a fresh GLRStackItem.  Callers should call
 * YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 * headroom.  */

static inline yyGLRStackItem *yynewGLRStackItem(yyGLRStack *yystackp,
                                                yybool yyisState) {
  yyGLRStackItem *yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  RULENUM on the semantic values in RHS to the list of
 *  alternative actions for STATE.  Assumes that RHS comes from
 *  stack #K of *STACKP. */
static void yyaddDeferredAction(yyGLRStack *yystackp, size_t yyk,
                                yyGLRState *yystate, yyGLRState *rhs,
                                yyRuleNum yyrule) {
  yySemanticOption *yynewOption =
      &yynewGLRStackItem(yystackp, yyfalse)->yyoption;
  yynewOption->yystate = rhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk]) {
    yynewOption->yyrawchar = yychar;
    yynewOption->yyval = yylval;
  } else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK(yystackp);
}

/* GLRStacks */

/** Initialize SET to a singleton set containing an empty stack.  */
static yybool yyinitStateSet(yyGLRStateSet *yyset) {
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates = (yyGLRState **)YYMALLOC(16 * sizeof yyset->yystates[0]);
  if (!yyset->yystates) return yyfalse;
  yyset->yystates[0] = YY_NULL;
  yyset->yylookaheadNeeds =
      (yybool *)YYMALLOC(16 * sizeof yyset->yylookaheadNeeds[0]);
  if (!yyset->yylookaheadNeeds) {
    YYFREE(yyset->yystates);
    return yyfalse;
  }
  return yytrue;
}

static void yyfreeStateSet(yyGLRStateSet *yyset) {
  YYFREE(yyset->yystates);
  YYFREE(yyset->yylookaheadNeeds);
}

/** Initialize STACK to a single empty stack, with total maximum
 *  capacity for all stacks of SIZE.  */
static yybool yyinitGLRStack(yyGLRStack *yystackp, size_t yysize) {
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems =
      (yyGLRStackItem *)YYMALLOC(yysize * sizeof yystackp->yynextFree[0]);
  if (!yystackp->yyitems) return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULL;
  yystackp->yylastDeleted = YY_NULL;
  return yyinitStateSet(&yystackp->yytops);
}

#if YYSTACKEXPANDABLE
#define YYRELOC(YYFROMITEMS, YYTOITEMS, YYX, YYTYPE) \
  &((YYTOITEMS) - ((YYFROMITEMS) - (yyGLRStackItem *)(YYX)))->YYTYPE

/** If STACK is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void yyexpandGLRStack(yyGLRStack *yystackp) {
  yyGLRStackItem *yynewItems;
  yyGLRStackItem *yyp0, *yyp1;
  size_t yynewSize;
  size_t yyn;
  size_t yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize) yyMemoryExhausted(yystackp);
  yynewSize = 2 * yysize;
  if (YYMAXDEPTH < yynewSize) yynewSize = YYMAXDEPTH;
  yynewItems = (yyGLRStackItem *)YYMALLOC(yynewSize * sizeof yynewItems[0]);
  if (!yynewItems) yyMemoryExhausted(yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize; 0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1) {
    *yyp1 = *yyp0;
    if (*(yybool *)yyp0) {
      yyGLRState *yys0 = &yyp0->yystate;
      yyGLRState *yys1 = &yyp1->yystate;
      if (yys0->yypred != YY_NULL)
        yys1->yypred = YYRELOC(yyp0, yyp1, yys0->yypred, yystate);
      if (!yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULL)
        yys1->yysemantics.yyfirstVal =
            YYRELOC(yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
    } else {
      yySemanticOption *yyv0 = &yyp0->yyoption;
      yySemanticOption *yyv1 = &yyp1->yyoption;
      if (yyv0->yystate != YY_NULL)
        yyv1->yystate = YYRELOC(yyp0, yyp1, yyv0->yystate, yystate);
      if (yyv0->yynext != YY_NULL)
        yyv1->yynext = YYRELOC(yyp0, yyp1, yyv0->yynext, yyoption);
    }
  }
  if (yystackp->yysplitPoint != YY_NULL)
    yystackp->yysplitPoint =
        YYRELOC(yystackp->yyitems, yynewItems, yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != YY_NULL)
      yystackp->yytops.yystates[yyn] =
          YYRELOC(yystackp->yyitems, yynewItems, yystackp->yytops.yystates[yyn],
                  yystate);
  YYFREE(yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void yyfreeGLRStack(yyGLRStack *yystackp) {
  YYFREE(yystackp->yyitems);
  yyfreeStateSet(&yystackp->yytops);
}

/** Assuming that S is a GLRState somewhere on STACK, update the
 *  splitpoint of STACK, if needed, so that it is at least as deep as
 *  S.  */
static inline void yyupdateSplit(yyGLRStack *yystackp, yyGLRState *yys) {
  if (yystackp->yysplitPoint != YY_NULL && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #K in STACK.  */
static inline void yymarkStackDeleted(yyGLRStack *yystackp, size_t yyk) {
  if (yystackp->yytops.yystates[yyk] != YY_NULL)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = YY_NULL;
}

/** Undelete the last stack that was marked as deleted.  Can only be
    done once after a deletion, and only when all other stacks have
    been deleted.  */
static void yyundeleteLastStack(yyGLRStack *yystackp) {
  if (yystackp->yylastDeleted == YY_NULL || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YYDPRINTF((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = YY_NULL;
}

static inline void yyremoveDeletes(yyGLRStack *yystackp) {
  size_t yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize) {
    if (yystackp->yytops.yystates[yyi] == YY_NULL) {
      if (yyi == yyj) {
        YYDPRINTF((stderr, "Removing dead stacks.\n"));
      }
      yystackp->yytops.yysize -= 1;
    } else {
      yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
      /* In the current implementation, it's unnecessary to copy
         yystackp->yytops.yylookaheadNeeds[yyi] since, after
         yyremoveDeletes returns, the parser immediately either enters
         deterministic operation or shifts a token.  However, it doesn't
         hurt, and the code might evolve to need it.  */
      yystackp->yytops.yylookaheadNeeds[yyj] =
          yystackp->yytops.yylookaheadNeeds[yyi];
      if (yyj != yyi) {
        YYDPRINTF((stderr, "Rename stack %lu -> %lu.\n", (unsigned long int)yyi,
                   (unsigned long int)yyj));
      }
      yyj += 1;
    }
    yyi += 1;
  }
}

/** Shift to a new state on stack #K of STACK, corresponding to LR state
 * LRSTATE, at input position POSN, with (resolved) semantic value SVAL.  */
static inline void yyglrShift(yyGLRStack *yystackp, size_t yyk,
                              yyStateNum yylrState, size_t yyposn,
                              YYSTYPE *yyvalp) {
  yyGLRState *yynewState = &yynewGLRStackItem(yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yysval = *yyvalp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK(yystackp);
}

/** Shift stack #K of YYSTACK, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void yyglrShiftDefer(yyGLRStack *yystackp, size_t yyk,
                                   yyStateNum yylrState, size_t yyposn,
                                   yyGLRState *rhs, yyRuleNum yyrule) {
  yyGLRState *yynewState = &yynewGLRStackItem(yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = YY_NULL;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction(yystackp, yyk, yynewState, rhs, yyrule);
}

/** Pop the symbols consumed by reduction #RULE from the top of stack
 *  #K of STACK, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *VALP to the resulting value,
 *  and *LOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG yydoAction(yyGLRStack *yystackp, size_t yyk,
                                     yyRuleNum yyrule, YYSTYPE *yyvalp,
                                     struct ParseResult *result) {
  int yynrhs = yyrhsLength(yyrule);

  if (yystackp->yysplitPoint == YY_NULL) {
    /* Standard special case: single stack.  */
    yyGLRStackItem *rhs = (yyGLRStackItem *)yystackp->yytops.yystates[yyk];
    YYASSERT(yyk == 0);
    yystackp->yynextFree -= yynrhs;
    yystackp->yyspaceLeft += yynrhs;
    yystackp->yytops.yystates[0] = &yystackp->yynextFree[-1].yystate;
    return yyuserAction(yyrule, yynrhs, rhs, yystackp, yyvalp, result);
  } else {
    /* At present, doAction is never called in nondeterministic
     * mode, so this branch is never taken.  It is here in
     * anticipation of a future feature that will allow immediate
     * evaluation of selected actions in nondeterministic mode.  */
    int yyi;
    yyGLRState *yys;
    yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
    yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred =
        yystackp->yytops.yystates[yyk];
    for (yyi = 0; yyi < yynrhs; yyi += 1) {
      yys = yys->yypred;
      YYASSERT(yys);
    }
    yyupdateSplit(yystackp, yys);
    yystackp->yytops.yystates[yyk] = yys;
    return yyuserAction(yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                        yystackp, yyvalp, result);
  }
}

#if !YYDEBUG
#define YY_REDUCE_PRINT(Args)
#else
#define YY_REDUCE_PRINT(Args)          \
  do {                                 \
    if (yydebug) yy_reduce_print Args; \
  } while (YYID(0))

/*----------------------------------------------------------.
| Report that the RULE is going to be reduced on stack #K.  |
`----------------------------------------------------------*/

/*ARGSUSED*/ static inline void yy_reduce_print(yyGLRStack *yystackp,
                                                size_t yyk, yyRuleNum yyrule,
                                                YYSTYPE *yyvalp,
                                                struct ParseResult *result) {
  int yynrhs = yyrhsLength(yyrule);
  yybool yynormal __attribute__((__unused__)) =
      (yystackp->yysplitPoint == YY_NULL);
  yyGLRStackItem *yyvsp = (yyGLRStackItem *)yystackp->yytops.yystates[yyk];
  int yylow = 1;
  int yyi;
  YYUSE(yyvalp);
  YYUSE(result);
  YYFPRINTF(stderr, "Reducing stack %lu by rule %d (line %lu):\n",
            (unsigned long int)yyk, yyrule - 1,
            (unsigned long int)yyrline[yyrule]);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++) {
    YYFPRINTF(stderr, "   $%d = ", yyi + 1);
    yy_symbol_print(
        stderr, yyrhs[yyprhs[yyrule] + yyi],
        &(((yyGLRStackItem const *)
           yyvsp)[YYFILL((yyi + 1) - (yynrhs))].yystate.yysemantics.yysval),
        result);
    YYFPRINTF(stderr, "\n");
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
static inline YYRESULTTAG yyglrReduce(yyGLRStack *yystackp, size_t yyk,
                                      yyRuleNum yyrule, yybool yyforceEval,
                                      struct ParseResult *result) {
  size_t yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == YY_NULL) {
    YYSTYPE yysval;

    YY_REDUCE_PRINT((yystackp, yyk, yyrule, &yysval, result));
    YYCHK(yydoAction(yystackp, yyk, yyrule, &yysval, result));
    YY_SYMBOL_PRINT("-> $$ =", yyr1[yyrule], &yysval, &yyloc);
    yyglrShift(yystackp, yyk,
               yyLRgotoState(yystackp->yytops.yystates[yyk]->yylrState,
                             yylhsNonterm(yyrule)),
               yyposn, &yysval);
  } else {
    size_t yyi;
    int yyn;
    yyGLRState *yys, *yys0 = yystackp->yytops.yystates[yyk];
    yyStateNum yynewLRState;

    for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength(yyrule);
         0 < yyn; yyn -= 1) {
      yys = yys->yypred;
      YYASSERT(yys);
    }
    yyupdateSplit(yystackp, yys);
    yynewLRState = yyLRgotoState(yys->yylrState, yylhsNonterm(yyrule));
    YYDPRINTF(
        (stderr,
         "Reduced stack %lu by rule #%d; action deferred.  Now in state %d.\n",
         (unsigned long int)yyk, yyrule - 1, yynewLRState));
    for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
      if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULL) {
        yyGLRState *yysplit = yystackp->yysplitPoint;
        yyGLRState *yyp = yystackp->yytops.yystates[yyi];
        while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn) {
          if (yyp->yylrState == yynewLRState && yyp->yypred == yys) {
            yyaddDeferredAction(yystackp, yyk, yyp, yys0, yyrule);
            yymarkStackDeleted(yystackp, yyk);
            YYDPRINTF((stderr, "Merging stack %lu into stack %lu.\n",
                       (unsigned long int)yyk, (unsigned long int)yyi));
            return yyok;
          }
          yyp = yyp->yypred;
        }
      }
    yystackp->yytops.yystates[yyk] = yys;
    yyglrShiftDefer(yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
  }
  return yyok;
}

static size_t yysplitStack(yyGLRStack *yystackp, size_t yyk) {
  if (yystackp->yysplitPoint == YY_NULL) {
    YYASSERT(yyk == 0);
    yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
  }
  if (yystackp->yytops.yysize >= yystackp->yytops.yycapacity) {
    yyGLRState **yynewStates;
    yybool *yynewLookaheadNeeds;

    yynewStates = YY_NULL;

    if (yystackp->yytops.yycapacity > (YYSIZEMAX / (2 * sizeof yynewStates[0])))
      yyMemoryExhausted(yystackp);
    yystackp->yytops.yycapacity *= 2;

    yynewStates = (yyGLRState **)YYREALLOC(
        yystackp->yytops.yystates,
        (yystackp->yytops.yycapacity * sizeof yynewStates[0]));
    if (yynewStates == YY_NULL) yyMemoryExhausted(yystackp);
    yystackp->yytops.yystates = yynewStates;

    yynewLookaheadNeeds = (yybool *)YYREALLOC(
        yystackp->yytops.yylookaheadNeeds,
        (yystackp->yytops.yycapacity * sizeof yynewLookaheadNeeds[0]));
    if (yynewLookaheadNeeds == YY_NULL) yyMemoryExhausted(yystackp);
    yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
  }
  yystackp->yytops.yystates[yystackp->yytops.yysize] =
      yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize] =
      yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize - 1;
}

/** True iff Y0 and Y1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool yyidenticalOptions(yySemanticOption *yyy0,
                                 yySemanticOption *yyy1) {
  if (yyy0->yyrule == yyy1->yyrule) {
    yyGLRState *yys0, *yys1;
    int yyn;
    for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
        yyn = yyrhsLength(yyy0->yyrule);
         yyn > 0; yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
      if (yys0->yyposn != yys1->yyposn) return yyfalse;
    return yytrue;
  } else
    return yyfalse;
}

/** Assuming identicalOptions (Y0,Y1), destructively merge the
 *  alternative semantic values for the RHS-symbols of Y1 and Y0.  */
static void yymergeOptionSets(yySemanticOption *yyy0, yySemanticOption *yyy1) {
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
      yyn = yyrhsLength(yyy0->yyrule);
       yyn > 0; yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1) {
    if (yys0 == yys1)
      break;
    else if (yys0->yyresolved) {
      yys1->yyresolved = yytrue;
      yys1->yysemantics.yysval = yys0->yysemantics.yysval;
    } else if (yys1->yyresolved) {
      yys0->yyresolved = yytrue;
      yys0->yysemantics.yysval = yys1->yysemantics.yysval;
    } else {
      yySemanticOption **yyz0p = &yys0->yysemantics.yyfirstVal;
      yySemanticOption *yyz1 = yys1->yysemantics.yyfirstVal;
      while (YYID(yytrue)) {
        if (yyz1 == *yyz0p || yyz1 == YY_NULL)
          break;
        else if (*yyz0p == YY_NULL) {
          *yyz0p = yyz1;
          break;
        } else if (*yyz0p < yyz1) {
          yySemanticOption *yyz = *yyz0p;
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
static int yypreference(yySemanticOption *y0, yySemanticOption *y1) {
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1) {
    if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
      return 0;
    else
      return 1;
  }
  if (p0 == 0 || p1 == 0) return 0;
  if (p0 < p1) return 3;
  if (p1 < p0) return 2;
  return 0;
}

static YYRESULTTAG yyresolveValue(yyGLRState *yys, yyGLRStack *yystackp,
                                  struct ParseResult *result);

/** Resolve the previous N states starting at and including state S.  If result
 *  != yyok, some states may have been left unresolved possibly with empty
 *  semantic option chains.  Regardless of whether result = yyok, each state
 *  has been left with consistent data so that yydestroyGLRState can be invoked
 *  if necessary.  */
static YYRESULTTAG yyresolveStates(yyGLRState *yys, int yyn,
                                   yyGLRStack *yystackp,
                                   struct ParseResult *result) {
  if (0 < yyn) {
    YYASSERT(yys->yypred);
    YYCHK(yyresolveStates(yys->yypred, yyn - 1, yystackp, result));
    if (!yys->yyresolved) YYCHK(yyresolveValue(yys, yystackp, result));
  }
  return yyok;
}

/** Resolve the states for the RHS of OPT, perform its user action, and return
 *  the semantic value and location.  Regardless of whether result = yyok, all
 *  RHS states have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG yyresolveAction(yySemanticOption *yyopt,
                                   yyGLRStack *yystackp, YYSTYPE *yyvalp,
                                   struct ParseResult *result) {
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs = yyrhsLength(yyopt->yyrule);
  YYRESULTTAG yyflag =
      yyresolveStates(yyopt->yystate, yynrhs, yystackp, result);
  if (yyflag != yyok) {
    yyGLRState *yys;
    for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
      yydestroyGLRState("Cleanup: popping", yys, result);
    return yyflag;
  }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  {
    int yychar_current = yychar;
    YYSTYPE yylval_current = yylval;
    yychar = yyopt->yyrawchar;
    yylval = yyopt->yyval;
    yyflag = yyuserAction(yyopt->yyrule, yynrhs,
                          yyrhsVals + YYMAXRHS + YYMAXLEFT - 1, yystackp,
                          yyvalp, result);
    yychar = yychar_current;
    yylval = yylval_current;
  }
  return yyflag;
}

#if YYDEBUG
static void yyreportTree(yySemanticOption *yyx, int yyindent) {
  int yynrhs = yyrhsLength(yyx->yyrule);
  int yyi;
  yyGLRState *yys;
  yyGLRState *yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == YY_NULL) {
    yyleftmost_state.yyposn = 0;
    yystates[0] = &yyleftmost_state;
  } else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YYFPRINTF(stderr, "%*s%s -> <Rule %d, empty>\n", yyindent, "",
              yytokenName(yylhsNonterm(yyx->yyrule)), yyx->yyrule - 1);
  else
    YYFPRINTF(stderr, "%*s%s -> <Rule %d, tokens %lu .. %lu>\n", yyindent, "",
              yytokenName(yylhsNonterm(yyx->yyrule)), yyx->yyrule - 1,
              (unsigned long int)(yys->yyposn + 1),
              (unsigned long int)yyx->yystate->yyposn);
  for (yyi = 1; yyi <= yynrhs; yyi += 1) {
    if (yystates[yyi]->yyresolved) {
      if (yystates[yyi - 1]->yyposn + 1 > yystates[yyi]->yyposn)
        YYFPRINTF(stderr, "%*s%s <empty>\n", yyindent + 2, "",
                  yytokenName(yyrhs[yyprhs[yyx->yyrule] + yyi - 1]));
      else
        YYFPRINTF(stderr, "%*s%s <tokens %lu .. %lu>\n", yyindent + 2, "",
                  yytokenName(yyrhs[yyprhs[yyx->yyrule] + yyi - 1]),
                  (unsigned long int)(yystates[yyi - 1]->yyposn + 1),
                  (unsigned long int)yystates[yyi]->yyposn);
    } else
      yyreportTree(yystates[yyi]->yysemantics.yyfirstVal, yyindent + 2);
  }
}
#endif

/*ARGSUSED*/ static YYRESULTTAG yyreportAmbiguity(yySemanticOption *yyx0,
                                                  yySemanticOption *yyx1,
                                                  struct ParseResult *result) {
  YYUSE(yyx0);
  YYUSE(yyx1);

#if YYDEBUG
  YYFPRINTF(stderr, "Ambiguity detected.\n");
  YYFPRINTF(stderr, "Option 1,\n");
  yyreportTree(yyx0, 2);
  YYFPRINTF(stderr, "\nOption 2,\n");
  yyreportTree(yyx1, 2);
  YYFPRINTF(stderr, "\n");
#endif

  yyerror(result, YY_("syntax is ambiguous"));
  return yyabort;
}

/** Resolve the ambiguity represented in state S, perform the indicated
 *  actions, and set the semantic value of S.  If result != yyok, the chain of
 *  semantic options in S has been cleared instead or it has been left
 *  unmodified except that redundant options may have been removed.  Regardless
 *  of whether result = yyok, S has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG yyresolveValue(yyGLRState *yys, yyGLRStack *yystackp,
                                  struct ParseResult *result) {
  yySemanticOption *yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption *yybest = yyoptionList;
  yySemanticOption **yypp;
  yybool yymerge = yyfalse;
  YYSTYPE yysval;
  YYRESULTTAG yyflag;

  for (yypp = &yyoptionList->yynext; *yypp != YY_NULL;) {
    yySemanticOption *yyp = *yypp;

    if (yyidenticalOptions(yybest, yyp)) {
      yymergeOptionSets(yybest, yyp);
      *yypp = yyp->yynext;
    } else {
      switch (yypreference(yybest, yyp)) {
        case 0:
          return yyreportAmbiguity(yybest, yyp, result);
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

  if (yymerge) {
    yySemanticOption *yyp;
    int yyprec = yydprec[yybest->yyrule];
    yyflag = yyresolveAction(yybest, yystackp, &yysval, result);
    if (yyflag == yyok)
      for (yyp = yybest->yynext; yyp != YY_NULL; yyp = yyp->yynext) {
        if (yyprec == yydprec[yyp->yyrule]) {
          YYSTYPE yysval_other;
          yyflag = yyresolveAction(yyp, yystackp, &yysval_other, result);
          if (yyflag != yyok) {
            yydestruct("Cleanup: discarding incompletely merged value for",
                       yystos[yys->yylrState], &yysval, result);
            break;
          }
          yyuserMerge(yymerger[yyp->yyrule], &yysval, &yysval_other);
        }
      }
  } else
    yyflag = yyresolveAction(yybest, yystackp, &yysval, result);

  if (yyflag == yyok) {
    yys->yyresolved = yytrue;
    yys->yysemantics.yysval = yysval;
  } else
    yys->yysemantics.yyfirstVal = YY_NULL;
  return yyflag;
}

static YYRESULTTAG yyresolveStack(yyGLRStack *yystackp,
                                  struct ParseResult *result) {
  if (yystackp->yysplitPoint != YY_NULL) {
    yyGLRState *yys;
    int yyn;

    for (yyn = 0, yys = yystackp->yytops.yystates[0];
         yys != yystackp->yysplitPoint; yys = yys->yypred, yyn += 1)
      continue;
    YYCHK(yyresolveStates(yystackp->yytops.yystates[0], yyn, yystackp, result));
  }
  return yyok;
}

static void yycompressStack(yyGLRStack *yystackp) {
  yyGLRState *yyp, *yyq, *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULL) return;

  for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULL;
       yyp != yystackp->yysplitPoint; yyr = yyp, yyp = yyq, yyq = yyp->yypred)
    yyp->yypred = yyr;

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = ((yyGLRStackItem *)yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULL;
  yystackp->yylastDeleted = YY_NULL;

  while (yyr != YY_NULL) {
    yystackp->yynextFree->yystate = *yyr;
    yyr = yyr->yypred;
    yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
    yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
    yystackp->yynextFree += 1;
    yystackp->yyspaceLeft -= 1;
  }
}

static YYRESULTTAG yyprocessOneStack(yyGLRStack *yystackp, size_t yyk,
                                     size_t yyposn,
                                     struct ParseResult *result) {
  int yyaction;
  const short int *yyconflicts;
  yyRuleNum yyrule;

  while (yystackp->yytops.yystates[yyk] != YY_NULL) {
    yyStateNum yystate = yystackp->yytops.yystates[yyk]->yylrState;
    YYDPRINTF((stderr, "Stack %lu Entering state %d\n", (unsigned long int)yyk,
               yystate));

    YYASSERT(yystate != YYFINAL);

    if (yyisDefaultedState(yystate)) {
      yyrule = yydefaultAction(yystate);
      if (yyrule == 0) {
        YYDPRINTF((stderr, "Stack %lu dies.\n", (unsigned long int)yyk));
        yymarkStackDeleted(yystackp, yyk);
        return yyok;
      }
      YYCHK(yyglrReduce(yystackp, yyk, yyrule, yyfalse, result));
    } else {
      yySymbol yytoken;
      yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;
      if (yychar == YYEMPTY) {
        YYDPRINTF((stderr, "Reading a token: "));
        yychar = YYLEX;
      }

      if (yychar <= YYEOF) {
        yychar = yytoken = YYEOF;
        YYDPRINTF((stderr, "Now at end of input.\n"));
      } else {
        yytoken = YYTRANSLATE(yychar);
        YY_SYMBOL_PRINT("Next token is", yytoken, &yylval, &yylloc);
      }

      yygetLRActions(yystate, yytoken, &yyaction, &yyconflicts);

      while (*yyconflicts != 0) {
        size_t yynewStack = yysplitStack(yystackp, yyk);
        YYDPRINTF((stderr, "Splitting off stack %lu from %lu.\n",
                   (unsigned long int)yynewStack, (unsigned long int)yyk));
        YYCHK(yyglrReduce(yystackp, yynewStack, *yyconflicts, yyfalse, result));
        YYCHK(yyprocessOneStack(yystackp, yynewStack, yyposn, result));
        yyconflicts += 1;
      }

      if (yyisShiftAction(yyaction))
        break;
      else if (yyisErrorAction(yyaction)) {
        YYDPRINTF((stderr, "Stack %lu dies.\n", (unsigned long int)yyk));
        yymarkStackDeleted(yystackp, yyk);
        break;
      } else
        YYCHK(yyglrReduce(yystackp, yyk, -yyaction, yyfalse, result));
    }
  }
  return yyok;
}

/*ARGSUSED*/ static void yyreportSyntaxError(yyGLRStack *yystackp,
                                             struct ParseResult *result) {
  if (yystackp->yyerrState != 0) return;
#if !YYERROR_VERBOSE
  yyerror(result, YY_("syntax error"));
#else
  {
    yySymbol yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE(yychar);
    size_t yysize0 = yytnamerr(YY_NULL, yytokenName(yytoken));
    size_t yysize = yysize0;
    yybool yysize_overflow = yyfalse;
    char *yymsg = YY_NULL;
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
    if (yytoken != YYEMPTY) {
      int yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
      yyarg[yycount++] = yytokenName(yytoken);
      if (!yypact_value_is_default(yyn)) {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for this
           state because they are default actions.  */
        int yyxbegin = yyn < 0 ? -yyn : 0;
        /* Stay within bounds of both yycheck and yytname.  */
        int yychecklim = YYLAST - yyn + 1;
        int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        int yyx;
        for (yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR &&
              !yytable_value_is_error(yytable[yyx + yyn])) {
            if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM) {
              yycount = 1;
              yysize = yysize0;
              break;
            }
            yyarg[yycount++] = yytokenName(yyx);
            {
              size_t yysz = yysize + yytnamerr(YY_NULL, yytokenName(yyx));
              yysize_overflow |= yysz < yysize;
              yysize = yysz;
            }
          }
      }
    }

    switch (yycount) {
#define YYCASE_(N, S) \
  case N:             \
    yyformat = S;     \
    break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(
          5,
          YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

    {
      size_t yysz = yysize + strlen(yyformat);
      yysize_overflow |= yysz < yysize;
      yysize = yysz;
    }

    if (!yysize_overflow) yymsg = (char *)YYMALLOC(yysize);

    if (yymsg) {
      char *yyp = yymsg;
      int yyi = 0;
      while ((*yyp = *yyformat)) {
        if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount) {
          yyp += yytnamerr(yyp, yyarg[yyi++]);
          yyformat += 2;
        } else {
          yyp++;
          yyformat++;
        }
      }
      yyerror(result, yymsg);
      YYFREE(yymsg);
    } else {
      yyerror(result, YY_("syntax error"));
      yyMemoryExhausted(yystackp);
    }
  }
#endif /* YYERROR_VERBOSE */
  yynerrs += 1;
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the lookahead.  */
/*ARGSUSED*/ static void yyrecoverSyntaxError(yyGLRStack *yystackp,
                                              struct ParseResult *result) {
  size_t yyk;
  int yyj;

  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (YYID(yytrue)) {
      yySymbol yytoken;
      if (yychar == YYEOF) yyFail(yystackp, result, YY_NULL);
      if (yychar != YYEMPTY) {
        yytoken = YYTRANSLATE(yychar);
        yydestruct("Error: discarding", yytoken, &yylval, result);
      }
      YYDPRINTF((stderr, "Reading a token: "));
      yychar = YYLEX;
      if (yychar <= YYEOF) {
        yychar = yytoken = YYEOF;
        YYDPRINTF((stderr, "Now at end of input.\n"));
      } else {
        yytoken = YYTRANSLATE(yychar);
        YY_SYMBOL_PRINT("Next token is", yytoken, &yylval, &yylloc);
      }
      yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
      if (yypact_value_is_default(yyj)) return;
      yyj += yytoken;
      if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken) {
        if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0) return;
      } else if (!yytable_value_is_error(yytable[yyj]))
        return;
    }

  /* Reduce to one stack.  */
  for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
    if (yystackp->yytops.yystates[yyk] != YY_NULL) break;
  if (yyk >= yystackp->yytops.yysize) yyFail(yystackp, result, YY_NULL);
  for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
    yymarkStackDeleted(yystackp, yyk);
  yyremoveDeletes(yystackp);
  yycompressStack(yystackp);

  /* Now pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != YY_NULL) {
    yyGLRState *yys = yystackp->yytops.yystates[0];
    yyj = yypact[yys->yylrState];
    if (!yypact_value_is_default(yyj)) {
      yyj += YYTERROR;
      if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYTERROR &&
          yyisShiftAction(yytable[yyj])) {
        /* Shift the error token.  */
        YY_SYMBOL_PRINT("Shifting", yystos[yytable[yyj]], &yylval, &yyerrloc);
        yyglrShift(yystackp, 0, yytable[yyj], yys->yyposn, &yylval);
        yys = yystackp->yytops.yystates[0];
        break;
      }
    }
    if (yys->yypred != YY_NULL)
      yydestroyGLRState("Error: popping", yys, result);
    yystackp->yytops.yystates[0] = yys->yypred;
    yystackp->yynextFree -= 1;
    yystackp->yyspaceLeft += 1;
  }
  if (yystackp->yytops.yystates[0] == YY_NULL)
    yyFail(yystackp, result, YY_NULL);
}

#define YYCHK1(YYE)        \
  do {                     \
    switch (YYE) {         \
      case yyok:           \
        break;             \
      case yyabort:        \
        goto yyabortlab;   \
      case yyaccept:       \
        goto yyacceptlab;  \
      case yyerr:          \
        goto yyuser_error; \
      default:             \
        goto yybuglab;     \
    }                      \
  } while (YYID(0))

/*----------.
| yyparse.  |
`----------*/

int yyparse(struct ParseResult *result) {
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack *const yystackp = &yystack;
  size_t yyposn;

  YYDPRINTF((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;

  if (!yyinitGLRStack(yystackp, YYINITDEPTH)) goto yyexhaustedlab;
  switch (YYSETJMP(yystack.yyexception_buffer)) {
    case 0:
      break;
    case 1:
      goto yyabortlab;
    case 2:
      goto yyexhaustedlab;
    default:
      goto yybuglab;
  }
  yyglrShift(&yystack, 0, 0, 0, &yylval);
  yyposn = 0;

  while (YYID(yytrue)) {
    /* For efficiency, we have two loops, the first of which is
       specialized to deterministic operation (single stack, no
       potential ambiguity).  */
    /* Standard mode */
    while (YYID(yytrue)) {
      yyRuleNum yyrule;
      int yyaction;
      const short int *yyconflicts;

      yyStateNum yystate = yystack.yytops.yystates[0]->yylrState;
      YYDPRINTF((stderr, "Entering state %d\n", yystate));
      if (yystate == YYFINAL) goto yyacceptlab;
      if (yyisDefaultedState(yystate)) {
        yyrule = yydefaultAction(yystate);
        if (yyrule == 0) {
          yyreportSyntaxError(&yystack, result);
          goto yyuser_error;
        }
        YYCHK1(yyglrReduce(&yystack, 0, yyrule, yytrue, result));
      } else {
        yySymbol yytoken;
        if (yychar == YYEMPTY) {
          YYDPRINTF((stderr, "Reading a token: "));
          yychar = YYLEX;
        }

        if (yychar <= YYEOF) {
          yychar = yytoken = YYEOF;
          YYDPRINTF((stderr, "Now at end of input.\n"));
        } else {
          yytoken = YYTRANSLATE(yychar);
          YY_SYMBOL_PRINT("Next token is", yytoken, &yylval, &yylloc);
        }

        yygetLRActions(yystate, yytoken, &yyaction, &yyconflicts);
        if (*yyconflicts != 0) break;
        if (yyisShiftAction(yyaction)) {
          YY_SYMBOL_PRINT("Shifting", yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
          yyposn += 1;
          yyglrShift(&yystack, 0, yyaction, yyposn, &yylval);
          if (0 < yystack.yyerrState) yystack.yyerrState -= 1;
        } else if (yyisErrorAction(yyaction)) {
          yyreportSyntaxError(&yystack, result);
          goto yyuser_error;
        } else
          YYCHK1(yyglrReduce(&yystack, 0, -yyaction, yytrue, result));
      }
    }

    while (YYID(yytrue)) {
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
        YYCHK1(yyprocessOneStack(&yystack, yys, yyposn, result));
      yyremoveDeletes(&yystack);
      if (yystack.yytops.yysize == 0) {
        yyundeleteLastStack(&yystack);
        if (yystack.yytops.yysize == 0)
          yyFail(&yystack, result, YY_("syntax error"));
        YYCHK1(yyresolveStack(&yystack, result));
        YYDPRINTF((stderr, "Returning to deterministic operation.\n"));

        yyreportSyntaxError(&yystack, result);
        goto yyuser_error;
      }

      /* If any yyglrShift call fails, it will fail after shifting.  Thus,
         a copy of yylval will already be on stack 0 in the event of a
         failure in the following loop.  Thus, yychar is set to YYEMPTY
         before the loop to make sure the user destructor for yylval isn't
         called twice.  */
      yytoken_to_shift = YYTRANSLATE(yychar);
      yychar = YYEMPTY;
      yyposn += 1;
      for (yys = 0; yys < yystack.yytops.yysize; yys += 1) {
        int yyaction;
        const short int *yyconflicts;
        yyStateNum yystate = yystack.yytops.yystates[yys]->yylrState;
        yygetLRActions(yystate, yytoken_to_shift, &yyaction, &yyconflicts);
        /* Note that yyconflicts were handled by yyprocessOneStack.  */
        YYDPRINTF((stderr, "On stack %lu, ", (unsigned long int)yys));
        YY_SYMBOL_PRINT("shifting", yytoken_to_shift, &yylval, &yylloc);
        yyglrShift(&yystack, yys, yyaction, yyposn, &yylval);
        YYDPRINTF((stderr, "Stack %lu now in state #%d\n",
                   (unsigned long int)yys,
                   yystack.yytops.yystates[yys]->yylrState));
      }

      if (yystack.yytops.yysize == 1) {
        YYCHK1(yyresolveStack(&yystack, result));
        YYDPRINTF((stderr, "Returning to deterministic operation.\n"));
        yycompressStack(&yystack);
        break;
      }
    }
    continue;
  yyuser_error:
    yyrecoverSyntaxError(&yystack, result);
    yyposn = yystack.yytops.yystates[0]->yyposn;
  }

yyacceptlab:
  yyresult = 0;
  goto yyreturn;

yybuglab:
  YYASSERT(yyfalse);
  goto yyabortlab;

yyabortlab:
  yyresult = 1;
  goto yyreturn;

yyexhaustedlab:
  yyerror(result, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;

yyreturn:
  if (yychar != YYEMPTY)
    yydestruct("Cleanup: discarding lookahead", YYTRANSLATE(yychar), &yylval,
               result);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems) {
    yyGLRState **yystates = yystack.yytops.yystates;
    if (yystates) {
      size_t yysize = yystack.yytops.yysize;
      size_t yyk;
      for (yyk = 0; yyk < yysize; yyk += 1)
        if (yystates[yyk]) {
          while (yystates[yyk]) {
            yyGLRState *yys = yystates[yyk];
            if (yys->yypred != YY_NULL)
              yydestroyGLRState("Cleanup: popping", yys, result);
            yystates[yyk] = yys->yypred;
            yystack.yynextFree -= 1;
            yystack.yyspaceLeft += 1;
          }
          break;
        }
    }
    yyfreeGLRStack(&yystack);
  }

  /* Make sure YYID is used.  */
  return YYID(yyresult);
}

/* DEBUGGING ONLY */
#if YYDEBUG
static void yypstack(yyGLRStack *yystackp, size_t yyk)
    __attribute__((__unused__));
static void yypdumpstack(yyGLRStack *yystackp) __attribute__((__unused__));

static void yy_yypstack(yyGLRState *yys) {
  if (yys->yypred) {
    yy_yypstack(yys->yypred);
    YYFPRINTF(stderr, " -> ");
  }
  YYFPRINTF(stderr, "%d@%lu", yys->yylrState, (unsigned long int)yys->yyposn);
}

static void yypstates(yyGLRState *yyst) {
  if (yyst == YY_NULL)
    YYFPRINTF(stderr, "<null>");
  else
    yy_yypstack(yyst);
  YYFPRINTF(stderr, "\n");
}

static void yypstack(yyGLRStack *yystackp, size_t yyk) {
  yypstates(yystackp->yytops.yystates[yyk]);
}

#define YYINDEX(YYX) \
  ((YYX) == YY_NULL ? -1 : (yyGLRStackItem *)(YYX) - yystackp->yyitems)

static void yypdumpstack(yyGLRStack *yystackp) {
  yyGLRStackItem *yyp;
  size_t yyi;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1) {
    YYFPRINTF(stderr, "%3lu. ", (unsigned long int)(yyp - yystackp->yyitems));
    if (*(yybool *)yyp) {
      YYFPRINTF(stderr, "Res: %d, LR State: %d, posn: %lu, pred: %ld",
                yyp->yystate.yyresolved, yyp->yystate.yylrState,
                (unsigned long int)yyp->yystate.yyposn,
                (long int)YYINDEX(yyp->yystate.yypred));
      if (!yyp->yystate.yyresolved)
        YYFPRINTF(stderr, ", firstVal: %ld",
                  (long int)YYINDEX(yyp->yystate.yysemantics.yyfirstVal));
    } else {
      YYFPRINTF(stderr, "Option. rule: %d, state: %ld, next: %ld",
                yyp->yyoption.yyrule - 1,
                (long int)YYINDEX(yyp->yyoption.yystate),
                (long int)YYINDEX(yyp->yyoption.yynext));
    }
    YYFPRINTF(stderr, "\n");
  }
  YYFPRINTF(stderr, "Tops:");
  for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
    YYFPRINTF(stderr, "%lu: %ld; ", (unsigned long int)yyi,
              (long int)YYINDEX(yystackp->yytops.yystates[yyi]));
  YYFPRINTF(stderr, "\n");
}
#endif
/* Line 2575 of glr.c  */
#line 1236 "sql.ypp"

void emit(char *s, ...) {
  /*
  extern int yylineno;
  va_list ap;
  va_start(ap, s);
  printf("rpn: ");
  vfprintf(stdout, s, ap);
  printf("\n");
  */
}

void yyerror(struct ParseResult *pp, const char *s, ...) {
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
