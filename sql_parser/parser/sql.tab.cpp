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
#include "../ast_node/ast_export_stmt.h"

void yyerror(struct ParseResult *pp, const char *s, ...);
void emit(char *s, ...);

/* Line 207 of glr.c  */
#line 87 "sql.tab.cpp"

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
#line 48 "sql.ypp"

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
#line 133 "sql.tab.cpp"

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
#define YYFINAL 112
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST 2776

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS 344
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS 91
/* YYNRULES -- Number of rules.  */
#define YYNRULES 391
/* YYNRULES -- Number of states.  */
#define YYNSTATES 857
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 13
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYTRANSLATE(X) -- Bison symbol number corresponding to X.  */
#define YYUNDEFTOK 2
#define YYMAXUTOK 584

#define YYTRANSLATE(YYX) \
  ((unsigned int)(YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned short int yytranslate[] = {
    0,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
    2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
    2,   2,   2,   17,  2,   2,   2,   28,  22,  2,   341, 342, 26,  24,  340,
    25,  343, 27,  2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   339,
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
    324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] = {
    0,    0,    3,    6,    10,   13,   17,   19,   31,   32,   35,   36,
    41,   43,   47,   48,   50,   52,   53,   56,   57,   60,   61,   65,
    68,   73,   74,   77,   82,   83,   89,   98,   100,  104,  105,  107,
    113,  115,  118,  120,  124,  126,  130,  132,  135,  137,  141,  143,
    145,  148,  153,  157,  161,  162,  164,  167,  169,  170,  176,  180,
    186,  193,  199,  200,  202,  204,  205,  207,  209,  211,  213,  216,
    219,  222,  223,  224,  226,  229,  234,  238,  240,  242,  246,  250,
    252,  254,  256,  258,  262,  266,  270,  274,  278,  282,  285,  288,
    292,  296,  300,  304,  310,  317,  324,  331,  335,  339,  343,  347,
    350,  353,  357,  361,  365,  370,  374,  379,  385,  387,  391,  395,
    397,  401,  407,  415,  422,  431,  437,  445,  452,  461,  466,  472,
    477,  482,  487,  492,  497,  502,  507,  512,  517,  522,  527,  532,
    537,  544,  551,  560,  569,  574,  582,  587,  594,  599,  601,  603,
    605,  606,  608,  610,  612,  614,  616,  623,  630,  634,  638,  642,
    646,  650,  654,  658,  662,  666,  671,  678,  682,  688,  693,  699,
    703,  708,  712,  717,  719,  724,  729,  730,  734,  736,  745,  756,
    766,  773,  785,  794,  798,  799,  801,  803,  804,  806,  808,  812,
    816,  822,  827,  832,  838,  844,  845,  849,  852,  856,  860,  864,
    868,  871,  875,  879,  882,  886,  892,  895,  899,  903,  907,  911,
    915,  919,  923,  927,  931,  935,  937,  939,  941,  943,  945,  949,
    953,  956,  961,  963,  965,  967,  969,  973,  977,  981,  985,  991,
    997,  999,  1003, 1004, 1008, 1014, 1015, 1017, 1018, 1021, 1024, 1025,
    1030, 1034, 1036, 1047, 1061, 1063, 1074, 1075, 1077, 1079, 1081, 1082,
    1085, 1087, 1089, 1093, 1099, 1101, 1114, 1124, 1134, 1147, 1149, 1159,
    1168, 1170, 1176, 1178, 1183, 1188, 1189, 1192, 1194, 1201, 1203, 1207,
    1211, 1217, 1218, 1220, 1222, 1224, 1229, 1235, 1237, 1241, 1247, 1249,
    1258, 1259, 1265, 1266, 1269, 1272, 1275, 1278, 1280, 1281, 1282, 1286,
    1290, 1296, 1298, 1300, 1304, 1308, 1316, 1324, 1328, 1332, 1338, 1344,
    1346, 1352, 1356, 1364, 1369, 1374, 1379, 1383, 1387, 1392, 1397, 1401,
    1405, 1409, 1414, 1420, 1424, 1428, 1434, 1437, 1441, 1446, 1452, 1457,
    1462, 1467, 1471, 1475, 1476, 1477, 1480, 1481, 1484, 1485, 1488, 1489,
    1491, 1492, 1494, 1496, 1499, 1501, 1509, 1517, 1524, 1527, 1530, 1533,
    1534, 1537, 1542, 1543, 1546, 1548, 1554, 1558};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const short int yyrhs[] = {
    345, 0,   -1,  346, 339, -1,  346, 339, 345, -1,  1,   339, -1,  345, 1,
    339, -1,  347, -1,  195, 359, 361, 357, 108, 363, 348, 349, 353, 354, 356,
    -1,  -1,  245, 376, -1,  -1,  112, 48,  350, 352, -1,  376, -1,  376, 340,
    350, -1,  -1,  40,  -1,  83,  -1,  -1,  247, 190, -1,  -1,  113, 376, -1,
    -1,  165, 48,  355, -1,  376, 351, -1,  376, 351, 340, 355, -1,  -1,  138,
    376, -1,  138, 376, 340, 376, -1,  -1,  129, 365, 169, 160, 3,   -1,  129,
    365, 159, 20,  5,   169, 160, 3,   -1,  3,   -1,  3,   340, 358, -1,  -1,
    86,  -1,  86,  160, 341, 360, 342, -1,  33,  -1,  86,  360, -1,  376, -1,
    376, 340, 360, -1,  362, -1,  362, 340, 361, -1,  26,  -1,  376, 367, -1,
    364, -1,  364, 340, 363, -1,  365, -1,  368, -1,  3,   367, -1,  3,   343,
    3,   367, -1,  375, 366, 3,   -1,  341, 363, 342, -1,  -1,  39,  -1,  39,
    3,   -1,  3,   -1,  -1,  364, 369, 131, 365, 373, -1,  364, 214, 365, -1,
    364, 214, 365, 160, 376, -1,  364, 371, 370, 131, 365, 374, -1,  364, 156,
    372, 131, 365, -1,  -1,  122, -1,  63,  -1,  -1,  167, -1,  137, -1,  189,
    -1,  109, -1,  137, 370, -1,  189, 370, -1,  109, 370, -1,  -1,  -1,  374,
    -1,  160, 376, -1,  236, 341, 358, 342, -1,  341, 347, 342, -1,  3,   -1,
    8,   -1,  3,   343, 3,   -1,  3,   343, 26,  -1,  4,   -1,  5,   -1,  7,
    -1,  6,   -1,  376, 24,  376, -1,  376, 25,  376, -1,  376, 26,  376, -1,
    376, 27,  376, -1,  376, 29,  376, -1,  376, 28,  376, -1,  25,  376, -1,
    24,  376, -1,  376, 12,  376, -1,  376, 10,  376, -1,  376, 11,  376, -1,
    376, 20,  376, -1,  376, 20,  341, 347, 342, -1,  376, 20,  37,  341, 347,
    342, -1,  376, 20,  201, 341, 347, 342, -1,  376, 20,  33,  341, 347, 342,
    -1,  376, 21,  376, -1,  376, 22,  376, -1,  376, 30,  376, -1,  376, 23,
    376, -1,  17,  376, -1,  18,  376, -1,  8,   9,   376, -1,  341, 376, 342,
    -1,  376, 15,  158, -1,  376, 15,  18,  158, -1,  376, 15,  6,   -1,  376,
    15,  18,  6,   -1,  376, 19,  376, 36,  376, -1,  376, -1,  376, 340, 377,
    -1,  341, 377, 342, -1,  377, -1,  377, 340, 378, -1,  376, 16,  341, 377,
    342, -1,  341, 377, 342, 16,  341, 378, 342, -1,  376, 18,  16,  341, 377,
    342, -1,  341, 377, 342, 18,  16,  341, 377, 342, -1,  376, 16,  341, 347,
    342, -1,  341, 377, 342, 16,  341, 347, 342, -1,  376, 18,  16,  341, 347,
    342, -1,  341, 377, 342, 18,  16,  341, 347, 342, -1,  99,  341, 347, 342,
    -1,  18,  99,  341, 347, 342, -1,  329, 341, 26,  342, -1,  329, 341, 376,
    342, -1,  334, 341, 376, 342, -1,  335, 341, 376, 342, -1,  336, 341, 376,
    342, -1,  337, 341, 376, 342, -1,  338, 341, 376, 342, -1,  338, 341, 359,
    342, -1,  329, 341, 359, 342, -1,  334, 341, 359, 342, -1,  335, 341, 359,
    342, -1,  336, 341, 359, 342, -1,  337, 341, 359, 342, -1,  325, 341, 376,
    340, 376, 342, -1,  325, 341, 376, 108, 376, 342, -1,  325, 341, 376, 340,
    376, 340, 376, 342, -1,  325, 341, 376, 108, 376, 105, 376, 342, -1,  326,
    341, 376, 342, -1,  326, 341, 379, 376, 108, 376, 342, -1,  330, 341, 376,
    342, -1,  331, 341, 376, 39,  380, 342, -1,  332, 341, 377, 342, -1,  135,
    -1,  226, -1,  47,  -1,  -1,  127, -1,  4,   -1,  89,  -1,  104, -1,  53,
    -1,  327, 341, 376, 340, 381, 342, -1,  328, 341, 376, 340, 381, 342, -1,
    128, 376, 73,  -1,  128, 376, 75,  -1,  128, 376, 76,  -1,  128, 376, 77,
    -1,  128, 376, 74,  -1,  128, 376, 250, -1,  128, 376, 249, -1,  128, 376,
    252, -1,  128, 376, 176, -1,  51,  376, 382, 96,  -1,  51,  376, 382, 93,
    376, 96,  -1,  51,  382, 96,  -1,  51,  382, 93,  376, 96,  -1,  244, 376,
    219, 376, -1,  382, 244, 376, 219, 376, -1,  376, 14,  376, -1,  376, 18,
    14,  376, -1,  376, 13,  376, -1,  376, 18,  13,  376, -1,  383, -1,  62,
    69,  384, 3,   -1,  62,  192, 384, 3,   -1,  -1,  118, 18,  99,  -1,  385,
    -1,  62,  388, 215, 384, 3,   341, 389, 342, -1,  62,  388, 215, 384, 3,
    343, 3,   341, 389, 342, -1,  62,  388, 215, 384, 3,   341, 389, 342, 386,
    -1,  62,  388, 215, 384, 3,   386, -1,  62,  388, 215, 384, 3,   343, 3,
    341, 389, 342, 386, -1,  62,  388, 215, 384, 3,   343, 3,   386, -1,  387,
    366, 347, -1,  -1,  119, -1,  184, -1,  -1,  216, -1,  390, -1,  390, 340,
    389, -1,  3,   392, 391, -1,  171, 132, 341, 358, 342, -1,  132, 341, 358,
    342, -1,  120, 341, 358, 342, -1,  110, 120, 341, 358, 342, -1,  110, 132,
    341, 358, 342, -1,  -1,  391, 18,  158, -1,  391, 158, -1,  391, 80,  4,
    -1,  391, 80,  5,   -1,  391, 80,  7,   -1,  391, 80,  6,   -1,  391, 41,
    -1,  391, 230, 132, -1,  391, 171, 132, -1,  391, 132, -1,  391, 57,  4,
    -1,  391, 230, 341, 358, 342, -1,  45,  394, -1,  223, 394, 396, -1,  200,
    394, 396, -1,  151, 394, 396, -1,  126, 394, 396, -1,  127, 394, 396, -1,
    43,  394, 396, -1,  179, 394, 396, -1,  89,  394, 396, -1,  104, 394, 396,
    -1,  78,  394, 396, -1,  71,  -1,  220, -1,  221, -1,  72,  -1,  249, -1,
    53,  394, 397, -1,  242, 394, 397, -1,  44,  394, -1,  241, 341, 5,   342,
    -1,  222, -1,  46,  -1,  150, -1,  145, -1,  224, 395, 397, -1,  217, 395,
    397, -1,  152, 395, 397, -1,  146, 395, 397, -1,  97,  341, 393, 342, 397,
    -1,  198, 341, 393, 342, 397, -1,  4,   -1,  393, 340, 4,   -1,  -1,  341,
    5,   342, -1,  341, 5,   340, 5,   342, -1,  -1,  44,  -1,  -1,  396, 232,
    -1,  396, 251, -1,  -1,  397, 53,  198, 3,   -1,  397, 55,  3,   -1,  398,
    -1,  62,  173, 160, 3,   341, 358, 342, 169, 160, 3,   -1,  62,  173, 160,
    3,   341, 358, 342, 159, 20,  5,   169, 160, 3,   -1,  399, -1,  62,  400,
    120, 3,   401, 160, 3,   341, 403, 342, -1,  -1,  230, -1,  110, -1,  203,
    -1,  -1,  236, 402, -1,  321, -1,  322, -1,  3,   394, 351, -1,  3,   394,
    351, 340, 403, -1,  404, -1,  140, 215, 3,   108, 377, 247, 4,   340, 4,
    191, 20,  7,   -1,  140, 215, 3,   108, 377, 247, 4,   340, 4,   -1,  38,
    215, 3,   108, 377, 247, 4,   340, 4,   -1,  38,  215, 3,   108, 377, 247,
    4,   340, 4,   191, 20,  7,   -1,  405, -1,  102, 215, 3,   129, 377, 247,
    4,   340, 4,   -1,  102, 129, 377, 247, 4,   340, 4,   347, -1,  406, -1,
    90,  120, 3,   160, 3,   -1,  407, -1,  90,  69,  408, 3,   -1,  90,  192,
    408, 3,   -1,  -1,  118, 99,  -1,  409, -1,  90,  388, 215, 408, 410, 411,
    -1,  3,   -1,  3,   343, 3,   -1,  3,   340, 410, -1,  3,   343, 3,   340,
    410, -1,  -1,  186, -1,  50,  -1,  412, -1,  90,  173, 108, 3,   -1,  90,
    173, 5,   108, 3,   -1,  413, -1,  259, 215, 410, -1,  259, 173, 5,   108,
    3,   -1,  414, -1,  125, 416, 417, 3,   418, 240, 419, 415, -1,  -1,  160,
    161, 132, 233, 421, -1,  -1,  416, 148, -1,  416, 81,  -1,  416, 114, -1,
    416, 119, -1,  129, -1,  -1,  -1,  341, 358, 342, -1,  341, 420, 342, -1,
    341, 420, 342, 340, 419, -1,  376, -1,  80,  -1,  376, 340, 420, -1,  80,
    340, 420, -1,  125, 416, 417, 3,   198, 421, 415, -1,  125, 416, 417, 3,
    418, 347, 415, -1,  3,   20,  376, -1,  3,   20,  80,  -1,  421, 340, 3,
    20,  376, -1,  421, 340, 3,   20,  80,  -1,  422, -1,  199, 423, 279, 424,
    425, -1,  199, 297, 425, -1,  199, 423, 298, 108, 3,   424, 425, -1,  199,
    62,  69,  3,   -1,  199, 62,  192, 3,   -1,  199, 62,  215, 3,   -1,  199,
    69,  3,   -1,  199, 192, 3,   -1,  199, 299, 3,   300, -1,  199, 299, 3,
    301, -1,  199, 302, 303, -1,  199, 304, 356, -1,  199, 376, 304, -1,  199,
    305, 105, 8,   -1,  199, 120, 108, 3,   424, -1,  199, 306, 301, -1,  199,
    427, 300, -1,  199, 324, 279, 424, 425, -1,  199, 290, -1,  199, 423, 307,
    -1,  199, 428, 301, 425, -1,  199, 215, 301, 424, 425, -1,  199, 296, 198,
    425, -1,  199, 308, 424, 426, -1,  199, 428, 309, 425, -1,  199, 310, 356,
    -1,  199, 376, 310, -1,  -1,  -1,  108, 3,   -1,  -1,  14,  4,   -1,  -1,
    14,  376, -1,  -1,  323, -1,  -1,  282, -1,  283, -1,  83,  3,   -1,  429,
    -1,  82,  430, 108, 363, 348, 354, 356, -1,  82,  430, 108, 431, 236, 363,
    348, -1,  82,  430, 431, 108, 363, 348, -1,  430, 148, -1,  430, 175, -1,
    430, 119, -1,  -1,  3,   432, -1,  431, 340, 3,   432, -1,  -1,  343, 26,
    -1,  433, -1,  233, 365, 198, 434, 348, -1,  376, 20,  376, -1,  434, 340,
    376, 20,  376, -1};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] = {
    0,    449,  449,  463,  476,  485,  497,  506,  513,  514,  517,  518,
    523,  524,  526,  527,  528,  531,  532,  535,  536,  539,  540,  543,
    544,  546,  547,  548,  551,  552,  553,  561,  562,  577,  578,  579,
    580,  581,  585,  586,  590,  591,  592,  596,  599,  600,  604,  605,
    609,  611,  613,  614,  617,  618,  621,  622,  623,  638,  639,  640,
    641,  642,  645,  646,  647,  650,  651,  655,  656,  657,  661,  662,
    663,  664,  667,  668,  676,  677,  682,  689,  690,  691,  692,  693,
    694,  695,  696,  698,  699,  700,  701,  702,  703,  705,  706,  708,
    709,  710,  712,  713,  714,  715,  716,  718,  719,  720,  721,  723,
    724,  725,  726,  729,  730,  731,  732,  735,  738,  739,  740,  743,
    744,  747,  748,  749,  751,  753,  754,  755,  756,  758,  759,  769,
    770,  771,  772,  773,  774,  775,  776,  777,  778,  779,  780,  781,
    784,  785,  786,  787,  788,  789,  790,  791,  792,  795,  796,  797,
    800,  801,  802,  803,  804,  805,  808,  809,  813,  814,  815,  816,
    817,  818,  819,  820,  821,  825,  826,  827,  828,  831,  832,  835,
    836,  839,  840,  846,  850,  851,  854,  855,  860,  863,  867,  871,
    876,  880,  885,  889,  893,  894,  895,  898,  899,  902,  903,  908,
    909,  910,  911,  912,  913,  915,  916,  917,  918,  919,  920,  921,
    922,  923,  924,  925,  926,  927,  931,  932,  933,  934,  935,  936,
    937,  938,  939,  940,  941,  942,  943,  944,  945,  946,  947,  948,
    949,  950,  952,  953,  954,  955,  956,  957,  958,  959,  960,  961,
    963,  964,  967,  968,  969,  972,  973,  976,  977,  978,  981,  982,
    984,  989,  992,  994,  1002, 1006, 1010, 1011, 1012, 1013, 1016, 1017,
    1020, 1021, 1024, 1025, 1029, 1032, 1037, 1038, 1039, 1046, 1049, 1055,
    1062, 1065, 1069, 1073, 1074, 1077, 1078, 1082, 1085, 1089, 1090, 1091,
    1092, 1095, 1096, 1097, 1101, 1104, 1105, 1112, 1115, 1116, 1121, 1124,
    1130, 1131, 1134, 1135, 1136, 1137, 1138, 1141, 1141, 1144, 1145, 1148,
    1149, 1153, 1154, 1155, 1156, 1159, 1163, 1168, 1171, 1174, 1177, 1182,
    1185, 1186, 1187, 1188, 1189, 1190, 1191, 1192, 1193, 1194, 1195, 1196,
    1197, 1198, 1199, 1200, 1201, 1202, 1203, 1204, 1205, 1206, 1207, 1208,
    1209, 1210, 1211, 1213, 1217, 1218, 1221, 1222, 1225, 1226, 1228, 1229,
    1232, 1233, 1234, 1237, 1240, 1242, 1247, 1251, 1256, 1257, 1258, 1259,
    1263, 1264, 1267, 1268, 1271, 1274, 1277, 1278};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] = {
    "$end",                     "error",
    "$undefined",               "NAME",
    "STRING",                   "INTNUM",
    "BOOL",                     "APPROXNUM",
    "USERVAR",                  "ASSIGN",
    "OR",                       "XOR",
    "ANDOP",                    "REGEXP",
    "LIKE",                     "IS",
    "IN",                       "'!'",
    "NOT",                      "BETWEEN",
    "COMPARISON",               "'|'",
    "'&'",                      "SHIFT",
    "'+'",                      "'-'",
    "'*'",                      "'/'",
    "'%'",                      "MOD",
    "'^'",                      "UMINUS",
    "ADD",                      "ALL",
    "ALTER",                    "ANALYZE",
    "AND",                      "ANY",
    "APPEND",                   "AS",
    "ASC",                      "AUTO_INCREMENT",
    "BEFORE",                   "BIGINT",
    "BINARY",                   "BIT",
    "BLOB",                     "BOTH",
    "BY",                       "CALL",
    "CASCADE",                  "CASE",
    "CHANGE",                   "CHAR",
    "CHECK",                    "COLLATE",
    "COLUMN",                   "COMMENT",
    "CONDITION",                "CONSTRAINT",
    "CONTINUE",                 "CONVERT",
    "CREATE",                   "CROSS",
    "CURRENT_DATE",             "CURRENT_TIME",
    "CURRENT_TIMESTAMP",        "CURRENT_USER",
    "CURSOR",                   "DATABASE",
    "DATABASES",                "DATE",
    "DATETIME",                 "DAY_HOUR",
    "DAY",                      "DAY_MICROSECOND",
    "DAY_MINUTE",               "DAY_SECOND",
    "DECIMAL",                  "DECLARE",
    "DEFAULT",                  "DELAYED",
    "DELETE",                   "DESC",
    "DESCRIBE",                 "DETERMINISTIC",
    "DISTINCT",                 "DISTINCTROW",
    "DIV",                      "DOUBLE",
    "DROP",                     "DUAL",
    "EACH",                     "ELSE",
    "ELSEIF",                   "ENCLOSED",
    "END",                      "ENUM",
    "ESCAPED",                  "EXISTS",
    "EXIT",                     "EXPLAIN",
    "EXPORT",                   "FETCH",
    "FLOAT",                    "FOR",
    "FORCE",                    "FOREIGN",
    "FROM",                     "FULL",
    "FULLTEXT",                 "GRANT",
    "GROUP",                    "HAVING",
    "HIGH_PRIORITY",            "HOUR_MICROSECOND",
    "HOUR_MINUTE",              "HOUR_SECOND",
    "IF",                       "IGNORE",
    "INDEX",                    "INFILE",
    "INNER",                    "INOUT",
    "INSENSITIVE",              "INSERT",
    "INT",                      "INTEGER",
    "INTERVAL",                 "INTO",
    "ITERATE",                  "JOIN",
    "KEY",                      "KEYS",
    "KILL",                     "LEADING",
    "LEAVE",                    "LEFT",
    "LIMIT",                    "LINES",
    "LOAD",                     "LOCALTIME",
    "LOCALTIMESTAMP",           "LOCK",
    "LONG",                     "LONGBLOB",
    "LONGTEXT",                 "LOOP",
    "LOW_PRIORITY",             "MATCH",
    "MEDIUMBLOB",               "MEDIUMINT",
    "MEDIUMTEXT",               "MINUTE_MICROSECOND",
    "MINUTE_SECOND",            "MODIFIES",
    "NATURAL",                  "NO_WRITE_TO_BINLOG",
    "NULLX",                    "NUMBER",
    "ON",                       "DUPLICATE",
    "OPTIMIZE",                 "OPTION",
    "OPTIONALLY",               "ORDER",
    "OUT",                      "OUTER",
    "OUTFILE",                  "PARTITIONED",
    "PRECISION",                "PRIMARY",
    "PROCEDURE",                "PROJECTION",
    "PURGE",                    "QUICK",
    "QUARTER",                  "READ",
    "READS",                    "REAL",
    "REFERENCES",               "RELEASE",
    "RENAME",                   "REPEAT",
    "REPLACE",                  "REQUIRE",
    "RESTRICT",                 "RETURN",
    "REVOKE",                   "RIGHT",
    "ROLLUP",                   "SAMPLE",
    "SCHEMA",                   "SCHEMAS",
    "SECOND_MICROSECOND",       "SELECT",
    "SENSITIVE",                "SEPARATOR",
    "SET",                      "SHOW",
    "SMALLINT",                 "SOME",
    "SONAME",                   "SPATIAL",
    "SPECIFIC",                 "SQL",
    "SQLEXCEPTION",             "SQLSTATE",
    "SQLWARNING",               "SQL_BIG_RESULT",
    "SQL_CALC_FOUND_ROWS",      "SQL_SMALL_RESULT",
    "SSL",                      "STARTING",
    "STRAIGHT_JOIN",            "TABLE",
    "TEMPORARY",                "TEXT",
    "TERMINATED",               "THEN",
    "TIME",                     "TIMESTAMP",
    "TINYBLOB",                 "TINYINT",
    "TINYTEXT",                 "TO",
    "TRAILING",                 "TRIGGER",
    "UNDO",                     "UNION",
    "UNIQUE",                   "UNLOCK",
    "UNSIGNED",                 "UPDATE",
    "USAGE",                    "USE",
    "USING",                    "UTC_DATE",
    "UTC_TIME",                 "UTC_TIMESTAMP",
    "VALUES",                   "VARBINARY",
    "VARCHAR",                  "VARYING",
    "WHEN",                     "WHERE",
    "WHILE",                    "WITH",
    "WRITE",                    "YEAR",
    "YEAR_MONTH",               "ZEROFILL",
    "WEEK",                     "DO",
    "MAX_QUERIES_PER_HOUR",     "MAX_UPDATES_PER_HOUR",
    "MAX_CONNECTIONS_PER_HOUR", "MAX_USER_CONNECTIONS",
    "USER",                     "TRUNCATE",
    "FAST",                     "MEDIUM",
    "EXTENDED",                 "CHANGED",
    "LEAVES",                   "MASTER",
    "QUERY",                    "CACHE",
    "SLAVE",                    "BEGINT",
    "COMMIT",                   "START",
    "TRANSACTION",              "NO",
    "CHAIN",                    "AUTOCOMMIT",
    "SAVEPOINT",                "ROLLBACK",
    "LOCAL",                    "TABLES",
    "ISOLATION",                "LEVEL",
    "GLOBAL",                   "SESSION",
    "UNCOMMITTED",              "COMMITTED",
    "REPEATABLE",               "SERIALIZABLE",
    "IDENTIFIED",               "PASSWORD",
    "PRIVILEGES",               "BACKUP",
    "CHECKSUM",                 "REPAIR",
    "USE_FRM",                  "RESTORE",
    "CHARACTER",                "COLLATION",
    "COLUMNS",                  "ENGINE",
    "LOGS",                     "STATUS",
    "STORAGE",                  "ENGINES",
    "ERRORS",                   "GRANTS",
    "INNODB",                   "PROCESSLIST",
    "TRIGGERS",                 "VARIABLES",
    "WARNINGS",                 "FLUSH",
    "HOSTS",                    "DES_KEY_FILE",
    "USER_RESOURCES",           "CONNECTION",
    "RESET",                    "PREPARE",
    "DEALLOCATE",               "EXECUTE",
    "WORK",                     "BTREE",
    "HASH",                     "BDB",
    "OPEN",                     "FSUBSTRING",
    "FTRIM",                    "FDATE_ADD",
    "FDATE_SUB",                "FCOUNT",
    "FUPPER",                   "FCAST",
    "FCOALESCE",                "FCONVERT",
    "FSUM",                     "FAVG",
    "FMIN",                     "FMAX",
    "TO_CHAR",                  "';'",
    "','",                      "'('",
    "')'",                      "'.'",
    "$accept",                  "stmt_list",
    "stmt",                     "select_stmt",
    "opt_where",                "opt_groupby",
    "groupby_list",             "opt_asc_desc",
    "opt_with_rollup",          "opt_having",
    "opt_orderby",              "orderby_list",
    "opt_limit",                "opt_into_list",
    "column_list",              "select_opts",
    "distinct_list",            "select_expr_list",
    "select_expr",              "table_references",
    "table_reference",          "table_factor",
    "opt_as",                   "opt_as_alias",
    "join_table",               "opt_inner_cross",
    "opt_outer",                "left_right_full",
    "opt_left_or_right_outer",  "opt_join_condition",
    "join_condition",           "table_subquery",
    "expr",                     "expr_list",
    "opt_expr_list",            "trim_ltb",
    "cast_data_type",           "interval_exp",
    "case_list",                "create_database_stmt",
    "opt_if_not_exists",        "create_table_stmt",
    "create_select_statement",  "opt_ignore_replace",
    "opt_temporary",            "create_col_list",
    "create_definition",        "column_atts",
    "data_type",                "enum_list",
    "opt_length",               "opt_binary",
    "opt_uz",                   "opt_csc",
    "create_projection_stmt",   "create_index_stmt",
    "index_att",                "opt_using_type",
    "index_type",               "index_col_list",
    "load_table_stmt",          "export_table_stmt",
    "drop_index_stmt",          "drop_database_stmt",
    "opt_if_exists",            "drop_table_stmt",
    "table_list",               "opt_rc",
    "drop_projection_stmt",     "truncate_table_stmt",
    "insert_stmt",              "opt_ondupupdate",
    "insert_opts",              "opt_into",
    "opt_col_names",            "insert_vals_list",
    "insert_vals",              "insert_asgn_list",
    "show_stmt",                "opt_full",
    "opt_from",                 "opt_like_string",
    "opt_like_expr",            "opt_bdb",
    "opt_trans_level",          "delete_stmt",
    "delete_opts",              "delete_list",
    "opt_dot_star",             "update_stmt",
    "update_set_list",          YY_NULL};
#endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short int yyr1[] = {
    0,   344, 345, 345, 345, 345, 346, 347, 348, 348, 349, 349, 350, 350, 351,
    351, 351, 352, 352, 353, 353, 354, 354, 355, 355, 356, 356, 356, 357, 357,
    357, 358, 358, 359, 359, 359, 359, 359, 360, 360, 361, 361, 361, 362, 363,
    363, 364, 364, 365, 365, 365, 365, 366, 366, 367, 367, 367, 368, 368, 368,
    368, 368, 369, 369, 369, 370, 370, 371, 371, 371, 372, 372, 372, 372, 373,
    373, 374, 374, 375, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376,
    376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376,
    376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 377, 377, 377, 378,
    378, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376,
    376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376,
    376, 376, 376, 379, 379, 379, 380, 380, 380, 380, 380, 380, 376, 376, 381,
    381, 381, 381, 381, 381, 381, 381, 381, 376, 376, 376, 376, 382, 382, 376,
    376, 376, 376, 346, 383, 383, 384, 384, 346, 385, 385, 385, 385, 385, 385,
    386, 387, 387, 387, 388, 388, 389, 389, 390, 390, 390, 390, 390, 390, 391,
    391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 392, 392, 392,
    392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392,
    392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 393, 393, 394,
    394, 394, 395, 395, 396, 396, 396, 397, 397, 397, 346, 398, 398, 346, 399,
    400, 400, 400, 400, 401, 401, 402, 402, 403, 403, 346, 404, 404, 404, 404,
    346, 405, 405, 346, 406, 346, 407, 407, 408, 408, 346, 409, 410, 410, 410,
    410, 411, 411, 411, 346, 412, 412, 346, 413, 413, 346, 414, 415, 415, 416,
    416, 416, 416, 416, 417, 417, 418, 418, 419, 419, 420, 420, 420, 420, 414,
    414, 421, 421, 421, 421, 346, 422, 422, 422, 422, 422, 422, 422, 422, 422,
    422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422, 422,
    422, 422, 422, 423, 424, 424, 425, 425, 426, 426, 427, 427, 428, 428, 428,
    346, 346, 429, 429, 429, 430, 430, 430, 430, 431, 431, 432, 432, 346, 433,
    434, 434};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] = {
    0, 2, 2,  3,  2, 3,  1, 11, 0, 2, 0, 4, 1, 3, 0,  1, 1, 0,  2, 0, 2,  0,
    3, 2, 4,  0,  2, 4,  0, 5,  8, 1, 3, 0, 1, 5, 1,  2, 1, 3,  1, 3, 1,  2,
    1, 3, 1,  1,  2, 4,  3, 3,  0, 1, 2, 1, 0, 5, 3,  5, 6, 5,  0, 1, 1,  0,
    1, 1, 1,  1,  2, 2,  2, 0,  0, 1, 2, 4, 3, 1, 1,  3, 3, 1,  1, 1, 1,  3,
    3, 3, 3,  3,  3, 2,  2, 3,  3, 3, 3, 5, 6, 6, 6,  3, 3, 3,  3, 2, 2,  3,
    3, 3, 4,  3,  4, 5,  1, 3,  3, 1, 3, 5, 7, 6, 8,  5, 7, 6,  8, 4, 5,  4,
    4, 4, 4,  4,  4, 4,  4, 4,  4, 4, 4, 4, 6, 6, 8,  8, 4, 7,  4, 6, 4,  1,
    1, 1, 0,  1,  1, 1,  1, 1,  6, 6, 3, 3, 3, 3, 3,  3, 3, 3,  3, 4, 6,  3,
    5, 4, 5,  3,  4, 3,  4, 1,  4, 4, 0, 3, 1, 8, 10, 9, 6, 11, 8, 3, 0,  1,
    1, 0, 1,  1,  3, 3,  5, 4,  4, 5, 5, 0, 3, 2, 3,  3, 3, 3,  2, 3, 3,  2,
    3, 5, 2,  3,  3, 3,  3, 3,  3, 3, 3, 3, 3, 1, 1,  1, 1, 1,  3, 3, 2,  4,
    1, 1, 1,  1,  3, 3,  3, 3,  5, 5, 1, 3, 0, 3, 5,  0, 1, 0,  2, 2, 0,  4,
    3, 1, 10, 13, 1, 10, 0, 1,  1, 1, 0, 2, 1, 1, 3,  5, 1, 12, 9, 9, 12, 1,
    9, 8, 1,  5,  1, 4,  4, 0,  2, 1, 6, 1, 3, 3, 5,  0, 1, 1,  1, 4, 5,  1,
    3, 5, 1,  8,  0, 5,  0, 2,  2, 2, 2, 1, 0, 0, 3,  3, 5, 1,  1, 3, 3,  7,
    7, 3, 3,  5,  5, 1,  5, 3,  7, 4, 4, 4, 3, 3, 4,  4, 3, 3,  3, 4, 5,  3,
    3, 5, 2,  3,  4, 5,  4, 4,  4, 3, 3, 0, 0, 2, 0,  2, 0, 2,  0, 1, 0,  1,
    1, 2, 1,  7,  7, 6,  2, 2,  2, 0, 2, 4, 0, 2, 1,  5, 3, 5};

/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const unsigned char yydprec[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const unsigned char yymerger[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

/* YYDEFACT[S] -- default reduction number in state S.  Performed when
   YYTABLE doesn't specify something else to do.  Zero means the default
   is an error.  */
static const unsigned short int yydefact[] = {
    0,   0,   0,   199, 383, 0,   199, 0,   314, 0,   33,  363, 0,   0,   0,
    0,   6,   183, 188, 265, 268, 280, 285, 288, 290, 295, 304, 307, 310, 335,
    376, 388, 4,   0,   186, 272, 0,   186, 273, 200, 271, 0,   0,   0,   375,
    293, 0,   0,   293, 0,   0,   0,   320, 0,   36,  34,  0,   79,  83,  84,
    86,  85,  80,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   373,
    374, 354, 0,   366, 0,   0,   25,  0,   0,   364, 25,  371, 0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   56,  0,   0,   52,  0,   0,   1,   0,   0,   0,   0,   0,   0,   0,
    186, 0,   386, 0,   382, 380, 381, 0,   0,   0,   0,   0,   0,   0,   293,
    0,   116, 0,   0,   316, 317, 318, 319, 315, 0,   0,   0,   37,  38,  42,
    28,  40,  56,  0,   0,   107, 0,   108, 94,  93,  0,   0,   0,   0,   0,
    0,   342, 0,   0,   343, 364, 366, 0,   337, 0,   346, 0,   347, 0,   351,
    0,   368, 361, 364, 0,   0,   0,   0,   33,  0,   0,   0,   33,  33,  33,
    33,  33,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   348, 362, 364, 0,   355, 352,
    366, 366, 55,  0,   0,   48,  0,   0,   44,  46,  47,  0,   53,  0,   0,
    297, 308, 5,   0,   0,   0,   184, 0,   185, 0,   274, 0,   384, 56,  8,
    0,   0,   0,   294, 291, 0,   0,   305, 292, 0,   0,   0,   0,   0,   321,
    0,   0,   0,   0,   0,   0,   43,  81,  82,  109, 0,   0,   0,   0,   175,
    0,   339, 340, 341, 0,   364, 366, 358, 367, 344, 345, 26,  349, 365, 0,
    359, 366, 0,   155, 153, 154, 0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   110, 0,   96,  97,
    95,  181, 179, 113, 0,   111, 0,   0,   0,   0,   0,   0,   0,   0,   0,
    98,  103, 104, 106, 87,  88,  89,  90,  92,  91,  105, 366, 0,   356, 360,
    54,  56,  78,  51,  64,  69,  63,  67,  73,  68,  0,   0,   0,   65,  0,
    8,   50,  0,   0,   0,   0,   187, 0,   196, 0,   0,   387, 0,   0,   21,
    0,   8,   386, 289, 306, 301, 118, 117, 0,   0,   0,   0,   0,   0,   0,
    39,  0,   0,   41,  0,   0,   0,   173, 0,   0,   129, 350, 357, 0,   369,
    353, 0,   0,   148, 0,   0,   0,   131, 139, 132, 150, 156, 152, 140, 133,
    141, 134, 142, 135, 143, 136, 138, 137, 0,   0,   114, 112, 0,   0,   182,
    180, 0,   0,   0,   0,   0,   0,   336, 364, 49,  65,  65,  65,  0,   58,
    45,  0,   66,  0,   0,   0,   389, 309, 299, 298, 0,   31,  0,   197, 198,
    0,   0,   192, 52,  276, 277, 275, 0,   9,   0,   25,  8,   379, 385, 303,
    302, 296, 0,   0,   0,   312, 0,   0,   312, 0,   35,  0,   0,   8,   129,
    177, 0,   176, 0,   27,  0,   0,   0,   0,   0,   0,   158, 161, 159, 160,
    157, 0,   0,   0,   125, 121, 0,   0,   115, 0,   0,   0,   99,  366, 72,
    70,  71,  0,   0,   74,  0,   98,  0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   201, 196, 0,   0,   0,   377, 378, 0,   0,   0,   0,   0,
    329, 322, 0,   312, 330, 0,   0,   0,   10,  174, 178, 0,   145, 0,   144,
    0,   0,   162, 163, 151, 0,   119, 0,   0,   127, 123, 102, 100, 101, 338,
    61,  59,  0,   0,   57,  75,  0,   0,   300, 0,   32,  0,   0,   254, 254,
    254, 243, 254, 233, 236, 254, 254, 0,   254, 254, 254, 245, 257, 244, 254,
    257, 254, 0,   254, 257, 234, 235, 242, 254, 257, 0,   254, 237, 209, 0,
    0,   0,   0,   0,   196, 0,   0,   194, 195, 0,   22,  14,  287, 0,   332,
    331, 0,   0,   326, 325, 0,   311, 0,   0,   29,  0,   19,  0,   0,   149,
    164, 168, 165, 166, 167, 172, 170, 169, 171, 126, 0,   122, 0,   0,   76,
    0,   60,  98,  283, 0,   0,   0,   259, 240, 222, 262, 259, 259, 0,   259,
    259, 259, 258, 262, 259, 262, 259, 0,   259, 262, 259, 262, 0,   262, 203,
    0,   0,   0,   0,   0,   191, 202, 0,   254, 0,   15,  16,  23,  286, 0,
    0,   0,   0,   323, 282, 0,   0,   0,   21,  147, 146, 120, 128, 124, 0,
    0,   0,   266, 0,   228, 238, 232, 230, 252, 0,   231, 226, 227, 249, 225,
    248, 229, 0,   224, 247, 223, 246, 0,   239, 0,   216, 0,   0,   219, 211,
    0,   0,   0,   0,   206, 205, 0,   196, 14,  269, 0,   0,   334, 333, 328,
    327, 0,   0,   0,   17,  12,  20,  25,  77,  0,   0,   0,   255, 260, 261,
    0,   0,   0,   262, 262, 241, 210, 220, 212, 213, 215, 214, 218, 217, 0,
    207, 208, 204, 193, 278, 24,  313, 324, 0,   30,  0,   11,  0,   7,   284,
    0,   0,   0,   264, 253, 250, 251, 0,   0,   281, 18,  13,  267, 256, 263,
    221, 279};

/* YYPDEFGOTO[NTERM-NUM].  */
static const short int yydefgoto[] = {
    -1,  14,  15,  16,  389, 671, 799, 732, 836, 743, 490, 655, 177,
    274, 477, 56,  147, 150, 151, 232, 233, 234, 238, 230, 235, 372,
    468, 373, 463, 604, 605, 109, 136, 198, 592, 307, 526, 519, 162,
    17,  117, 18,  482, 483, 41,  557, 558, 719, 643, 759, 697, 708,
    754, 755, 19,  20,  42,  385, 486, 729, 21,  22,  23,  24,  129,
    25,  241, 496, 26,  27,  28,  570, 52,  144, 402, 573, 665, 500,
    29,  103, 181, 173, 300, 104, 105, 30,  43,  127, 252, 31,  375};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -519
static const short int yypact[] = {
    2033, -296, -151, 724,  -519, 88,   98,   -82,  -519, -76,  131,  277,
    4,    -1,   227,  -169, -519, -519, -519, -519, -519, -519, -519, -519,
    -519, -519, -519, -519, -519, -519, -519, -519, -519, 221,  123,  -519,
    106,  123,  -519, -519, -519, 91,   173,  138,  -519, 179,  308,  37,
    179,  114,  1388, 355,  272,  380,  -519, 995,  1047, 59,   -519, -519,
    -519, -519, 399,  1437, 1476, 1437, 1437, 1096, -21,  406,  77,   311,
    418,  122,  -519, -519, -519, 229,  414,  427,  152,  319,  351,  164,
    359,  319,  -519, 189,  129,  145,  146,  148,  149,  153,  154,  155,
    156,  157,  159,  160,  162,  1388, 2017, -63,  193,  -78,  1,    14,
    306,  466,  503,  513,  -519, 198,  2050, 433,  525,  542,  543,  544,
    123,  545,  206,  6,    -519, -519, -519, -103, 451,  549,  393,  446,
    552,  555,  179,  1388, 1852, 315,  434,  -519, -519, -519, -519, -519,
    561,  458,  224,  -519, 1873, -519, 439,  231,  2620, 219,  1437, 453,
    228,  453,  -519, -519, 1437, 2196, 54,   572,  577,  581,  -519, 395,
    585,  -519, 359,  414,  588,  -519, -46,  -519, 1437, -519, 586,  -519,
    590,  583,  -519, 359,  1437, 703,  1437, 1437, 807,  1437, 1437, 1388,
    897,  897,  897,  897,  897,  8,    253,  1437, 1437, 1437, 1437, 1437,
    119,  257,  318,  1437, 844,  1437, 1437, 1437, 1437, 1437, 1437, 1437,
    1437, 1437, 1437, -519, -519, 359,  491,  -519, -519, 414,  414,  -519,
    607,  613,  -519, 275,  284,  666,  -519, -519, 1437, -519, 637,  533,
    -174, -519, -519, 323,  1388, 573,  -519, 330,  -519, 639,  437,  648,
    -519, 0,    430,  -177, 4,    674,  -519, -519, 675,  678,  -519, -519,
    513,  340,  1388, 681,  1388, -71,  1388, 1437, 1437, 4,    578,  1047,
    -519, -519, -519, 2704, 395,  2319, 61,   1437, -519, 1437, -519, -519,
    -519, 345,  359,  414,  -519, -519, -519, -519, 1894, -519, -519, 1437,
    -519, 414,  1829, -519, -519, -519, 424,  1437, 1928, 1949, 346,  347,
    499,  609,  2655, 348,  362,  1278, 363,  1519, 370,  1603, 377,  1624,
    390,  1671, -519, 222,  1063, 1138, 2078, 2364, 2364, -519, 10,   -519,
    1185, 1437, 1437, 381,  2677, 394,  396,  397,  1185, 934,  909,  757,
    731,  366,  366,  704,  704,  704,  704,  -519, 414,  737,  -519, -519,
    -519, 212,  -519, -519, -519, -519, -519, -519, 50,   -519, 4,    4,
    610,  575,  2725, -196, -519, 740,  513,  741,  500,  -519, 743,  -54,
    41,   591,  -519, 226,  1437, 598,  4,    430,  206,  -519, -519, -38,
    222,  -519, 425,  517,  764,  743,  18,   521,  428,  -519, -109, 4,
    -519, 431,  1437, 1437, -519, 2471, 2340, -519, -519, -519, 1437, 2704,
    -519, 1437, 1437, -519, 2423, 644,  644,  -519, -519, -519, -519, 299,
    -519, -519, -519, -519, -519, -519, -519, -519, -519, -519, -519, 435,
    758,  -519, -519, 447,  448,  2364, 2364, 1185, 1437, 395,  395,  395,
    449,  -519, 359,  -519, 575,  575,  575,  661,  634,  -519, 4,    -519,
    664,  844,  1437, -519, -519, -519, 459,  794,  461,  462,  -519, -519,
    133,  803,  -519, 466,  -519, -519, -519, 804,  2704, 760,  319,  430,
    -519, -519, -519, -519, -519, 805,  813,  798,  -145, 477,  479,  663,
    817,  -519, 808,  667,  430,  640,  2704, 2568, -519, 1437, 2704, 56,
    82,   1437, 1437, 488,  493,  -519, -519, -519, -519, -519, 494,  1185,
    496,  -519, -519, 497,  501,  672,  504,  511,  514,  -519, 414,  -519,
    -519, -519, 4,    1437, -26,  4,    92,   2746, 513,  502,  743,  -108,
    2328, 101,  516,  519,  713,  522,  523,  -31,  395,  524,  1437, -519,
    -519, 395,  526,  1236, 706,  867,  -519, -519, 1261, 663,  -519, 531,
    868,  869,  762,  -519, 2704, 1437, -519, 1437, -519, 1720, 2054, -519,
    -519, -519, 534,  535,  536,  1185, -519, -519, -519, -519, -519, -519,
    -519, 2704, 1437, 538,  -519, -519, -25,  844,  -519, 878,  -519, 863,
    726,  547,  547,  547,  -519, 547,  -519, -519, 547,  547,  550,  547,
    547,  547,  -519, 850,  -519, 547,  850,  547,  557,  547,  850,  -519,
    -519, -519, 547,  850,  558,  547,  -519, -519, 566,  567,  743,  743,
    568,  -61,  133,  133,  -519, -519, 893,  -519, 2589, -519, 906,  -519,
    2704, 779,  892,  579,  1970, 571,  -519, 913,  749,  -519, 872,  810,
    1769, 1808, -519, -519, -519, -519, -519, -519, -519, -519, -519, -519,
    -519, 1388, -519, 582,  584,  2704, 743,  -519, 344,  734,  923,  938,
    937,  -519, -519, -519, -519, -519, -519, 941,  -519, -519, -519, -519,
    -519, -519, -519, -519, 941,  -519, -519, -519, -519, 942,  -519, 258,
    743,  743,  604,  611,  743,  -519, -519, 631,  547,  642,  -519, -519,
    612,  -519, 716,  1339, 1261, 1261, 645,  795,  827,  1437, 1437, 598,
    -519, -519, -519, -519, -519, 646,  969,  821,  -519, 9,    24,   301,
    24,   24,   -519, 38,   24,   24,   24,   301,  24,   301,  24,   42,
    24,   301,  24,   301,  649,  301,  834,  -519, 989,  457,  -519, -519,
    862,  -122, 653,  655,  -519, -519, 662,  -32,  49,   -519, 1437, 764,
    -519, 2704, -519, -519, 479,  985,  1004, 761,  1996, 2704, 319,  -519,
    1002, 851,  1005, -519, -519, -519, 816,  1012, 1013, -519, -519, -519,
    -519, -519, -519, -519, -519, -519, -519, -519, 743,  -519, -519, -519,
    -519, 676,  -519, 682,  -519, 1011, -519, 831,  -519, 1437, -519, -519,
    1020, 683,  1021, -519, -519, 301,  301,  684,  893,  -519, -519, -519,
    -519, -519, -519, -519, -519};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] = {
    -519, 922,  -519, -94,  -229, -519, 190,  254,  -519, -519, 300,  259,
    -84,  -519, -399, 124,  64,   772,  -519, -98,  -519, -6,   565,  -141,
    -519, -519, -48,  -519, -519, -519, 450,  -519, -11,  -36,  372,  -519,
    -519, 632,  898,  -519, 20,   -519, -518, -519, 1054, -309, -519, -519,
    -519, 349,  1522, -371, -171, -329, -519, -519, -519, -519, -519, 214,
    -519, -519, -519, -519, 78,   -519, -218, -519, -519, -519, -519, -347,
    -519, -519, -519, 267,  -332, 276,  -519, -519, -41,  -163, -519, -519,
    -519, -519, -519, 943,  677,  -519, -519};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -392
static const short int yytable[] = {
    102,  182,  501,  227,  227,  256,  108,  106,  292,  253,  823,  276,
    494,  231,  137,  568,  445,  106,  199,  200,  201,  202,  203,  204,
    205,  254,  206,  207,  208,  209,  210,  211,  212,  213,  214,  215,
    216,  217,  218,  228,  228,  652,  131,  32,   148,  152,  395,  50,
    163,  388,  506,  611,  155,  157,  158,  159,  161,  119,  478,  390,
    507,  612,  358,  359,  33,   478,  199,  200,  201,  202,  203,  204,
    205,  289,  206,  207,  208,  209,  210,  211,  212,  213,  214,  215,
    216,  217,  218,  478,  478,  730,  197,  44,   199,  200,  201,  202,
    203,  204,  205,  265,  206,  207,  208,  209,  210,  211,  212,  213,
    214,  215,  216,  217,  218,  209,  210,  211,  212,  213,  214,  215,
    216,  217,  218,  479,  197,  333,  133,  400,  417,  291,  479,  725,
    731,  51,   602,  602,  552,  334,  420,  53,   249,  122,  301,  279,
    470,  132,  471,  283,  495,  281,  284,  610,  479,  479,  411,  315,
    574,  412,  391,  460,  473,  581,  492,  257,  54,   296,  378,  45,
    446,  379,  114,  164,  110,  302,  306,  308,  309,  312,  313,  314,
    356,  317,  319,  321,  323,  325,  409,  461,  328,  329,  330,  331,
    332,  457,  165,  569,  340,  345,  346,  347,  348,  349,  350,  351,
    352,  353,  354,  355,  380,  10,   603,  603,  264,  10,   111,  227,
    221,  55,   46,   824,  459,  644,  277,  225,  115,  374,  666,  112,
    113,  361,  397,  226,  399,  645,  403,  222,  -386, 257,  443,  462,
    444,  116,  447,  553,  223,  278,  123,  722,  723,  416,  456,  228,
    386,  554,  294,  295,  808,  124,  502,  710,  148,  148,  564,  714,
    152,  555,  118,  406,  716,  828,  401,  47,   413,  465,  414,  809,
    774,  335,  -189, 578,  57,   58,   59,   60,   61,   62,   125,  480,
    419,  481,  48,   749,  491,  121,  63,   64,   424,  128,  285,  775,
    448,  65,   66,   521,  556,  285,  120,  -190, 503,  508,  651,  130,
    311,  126,  39,   776,  316,  318,  320,  322,  324,  782,  783,  -3,
    113,  786,  449,  450,  67,   134,  608,  337,  338,  197,  339,  404,
    405,  -390, 777,  68,   -56,  726,  727,  387,  229,  107,  69,   107,
    266,  806,  326,  807,  522,  139,  810,  107,  811,  531,  138,  534,
    535,  536,  484,  485,  464,  209,  210,  211,  212,  213,  214,  215,
    216,  217,  218,  599,  70,   488,  812,  763,  813,  765,  812,  145,
    814,  769,  140,  771,  523,  773,  778,  141,  214,  215,  216,  217,
    218,  71,   582,  510,  511,  142,  153,  524,  794,  795,  563,  514,
    154,  166,  515,  516,  539,  540,  541,  532,  779,  538,  167,  168,
    143,  169,  583,  170,  584,  847,  525,  171,  172,  780,  174,  -390,
    -390, 590,  199,  200,  201,  202,  203,  204,  205,  533,  206,  207,
    208,  209,  210,  211,  212,  213,  214,  215,  216,  217,  218,  175,
    178,  176,  546,  547,  544,  818,  819,  820,  821,  179,  653,  180,
    183,  72,   184,  657,  207,  208,  209,  210,  211,  212,  213,  214,
    215,  216,  217,  218,  845,  846,  185,  186,  781,  187,  188,  591,
    73,   224,  189,  190,  191,  192,  193,  687,  194,  195,  580,  196,
    236,  237,  585,  586,  239,  199,  200,  201,  202,  203,  204,  205,
    240,  206,  207,  208,  209,  210,  211,  212,  213,  214,  215,  216,
    217,  218,  756,  757,  601,  760,  761,  762,  600,  242,  764,  606,
    766,  244,  768,  245,  770,  246,  247,  248,  250,  251,  258,  656,
    259,  260,  261,  262,  660,  688,  263,  74,   75,   664,  267,  268,
    269,  271,  270,  76,   273,  280,  672,  275,  673,  77,   78,   286,
    79,   -370, -372, 80,   287,  81,   82,   83,   288,  84,   -372, 85,
    290,  -391, 10,   689,  293,  298,  297,  327,  692,  299,  336,  357,
    86,   87,   88,   89,   90,   91,   92,   93,   94,   95,   360,  96,
    97,   98,   99,   100,  361,  362,  101,  199,  200,  201,  202,  203,
    204,  205,  363,  206,  207,  208,  209,  210,  211,  212,  213,  214,
    215,  216,  217,  218,  376,  377,  383,  -129, -129, -129, -129, -129,
    -129, 591,  -129, -129, -129, -129, -129, -129, -129, -129, -129, -129,
    -129, -129, -129, -129, -129, -129, -129, -129, -129, -129, -129, 382,
    381,  384,  386,  388,  -129, 392,  393,  -129, -129, 394,  396,  -391,
    -391, 398,  407,  415,  427,  428,  432,  -129, 208,  209,  210,  211,
    212,  213,  214,  215,  216,  217,  218,  -129, 433,  435,  57,   58,
    59,   60,   61,   62,   437,  -129, -129, -129, -129, -129, 838,  439,
    63,   64,   451,  -129, 793,  664,  664,  65,   66,   364,  800,  801,
    441,  -129, 218,  453,  -129, 454,  455,  -129, 458,  466,  467,  472,
    474,  -129, 476,  475,  -129, -129, 303,  487,  -129, -129, 67,   212,
    213,  214,  215,  216,  217,  218,  -129, 489,  498,  497,  423,  499,
    504,  -129, 505,  -129, 518,  509,  528,  365,  527,  -129, -129, 656,
    211,  212,  213,  214,  215,  216,  217,  218,  366,  529,  530,  537,
    542,  34,   543,  545,  -129, -62,  549,  548,  -129, 550,  70,   367,
    551,  -129, 559,  561,  562,  565,  57,   58,   59,   60,   61,   62,
    -129, 566,  567,  571,  572,  575,  368,  568,  63,   64,   800,  577,
    576,  -129, 587,  65,   66,   310,  35,   588,  589,  593,  304,  594,
    54,   429,  609,  595,  -270, 648,  596,  57,   58,   59,   60,   61,
    62,   597,  -129, 369,  598,  646,  67,   -129, 647,  63,   64,   650,
    649,  654,  658,  661,  65,   66,   662,  667,  669,  668,  670,  685,
    684,  341,  686,  690,  370,  342,  693,  694,  -129, -129, 695,  -129,
    696,  -129, -129, 703,  -129, 55,   707,  67,   728,  36,   712,  717,
    57,   58,   59,   60,   61,   62,   70,   720,  721,  724,  733,  734,
    735,  738,  63,   64,   37,   739,  740,  736,  741,  65,   66,   742,
    747,  750,  748,  38,   751,  305,  54,   210,  211,  212,  213,  214,
    215,  216,  217,  218,  39,   752,  753,  70,   -129, 758,  784,  772,
    67,   791,  -129, 430,  790,  785,  40,   209,  210,  211,  212,  213,
    214,  215,  216,  217,  218,  -129, -129, -129, -129, -129, -129, -129,
    -129, 787,  -129, -129, -129, -129, -129, -129, -129, -129, -129, 55,
    789,  796,  797,  798,  803,  804,  805,  815,  816,  817,  822,  825,
    70,   826,  57,   58,   59,   60,   61,   62,   827,  833,  371,  834,
    835,  839,  841,  840,  63,   64,   842,  843,  848,  844,  849,  65,
    66,   850,  569,  852,  854,  853,  855,  851,  88,   89,   90,   91,
    92,   93,   94,   95,   243,  96,   97,   98,   99,   100,  829,  802,
    101,  343,  67,   408,  560,  830,  57,   58,   59,   60,   61,   62,
    691,  746,  520,  282,  49,   767,  856,  832,  63,   64,   255,  831,
    0,    493,  0,    65,   66,   149,  200,  201,  202,  203,  204,  205,
    0,    206,  207,  208,  209,  210,  211,  212,  213,  214,  215,  216,
    217,  218,  70,   0,    0,    0,    67,   57,   58,   59,   60,   61,
    62,   0,    0,    0,    0,    0,    0,    0,    0,    63,   64,   0,
    0,    0,    0,    0,    65,   66,   0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    88,   89,   90,   91,   92,   93,   94,   95,
    0,    96,   97,   98,   99,   100,  70,   67,   101,  0,    201,  202,
    203,  204,  205,  146,  206,  207,  208,  209,  210,  211,  212,  213,
    214,  215,  216,  217,  218,  88,   89,   90,   91,   92,   93,   94,
    95,   0,    96,   97,   98,   99,   100,  0,    0,    344,  0,    0,
    57,   58,   59,   60,   61,   62,   0,    70,   0,    0,    0,    0,
    0,    0,    63,   64,   0,    0,    0,    0,    0,    65,   66,   0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    88,   89,
    90,   91,   92,   93,   94,   95,   0,    96,   97,   98,   99,   100,
    67,   0,    101,  57,   58,   59,   60,   61,   62,   0,    0,    0,
    0,    0,    0,    0,    0,    63,   64,   0,    0,    0,    0,    0,
    65,   66,   0,    0,    57,   58,   59,   60,   61,   62,   0,    0,
    0,    0,    0,    0,    0,    0,    63,   64,   0,    0,    0,    0,
    70,   65,   66,   67,   199,  200,  201,  202,  203,  204,  205,  0,
    206,  207,  208,  209,  210,  211,  212,  213,  214,  215,  216,  217,
    218,  0,    0,    0,    67,   0,    0,    0,    659,  0,    0,    0,
    88,   89,   90,   91,   92,   93,   94,   95,   0,    96,   97,   98,
    99,   100,  0,    70,   101,  0,    0,    0,    160,  663,  57,   58,
    59,   60,   61,   62,   0,    0,    0,    0,    0,    0,    0,    0,
    63,   64,   0,    0,    70,   0,    0,    65,   66,   0,    0,    0,
    0,    0,    0,    0,    88,   89,   90,   91,   92,   93,   94,   95,
    10,   96,   97,   98,   99,   100,  0,    0,    101,  0,    67,   57,
    58,   59,   60,   61,   62,   0,    0,    0,    0,    0,    0,    0,
    0,    63,   64,   0,    0,    0,    0,    0,    65,   66,   0,    0,
    0,    0,    0,    792,  0,    88,   89,   90,   91,   92,   93,   94,
    95,   0,    96,   97,   98,   99,   100,  0,    0,    101,  70,   67,
    57,   58,   59,   60,   61,   62,   0,    0,    0,    0,    0,    0,
    0,    0,    63,   64,   0,    0,    0,    0,    0,    65,   66,   0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    57,   58,   59,   60,   61,   62,   0,    0,    70,
    67,   0,    0,    0,    0,    63,   64,   0,    0,    0,    0,    0,
    65,   66,   0,    0,    0,    0,    0,    0,    0,    0,    88,   89,
    90,   91,   92,   93,   94,   95,   0,    96,   97,   98,   99,   100,
    0,    0,    135,  67,   0,    199,  200,  201,  202,  203,  204,  205,
    70,   206,  207,  208,  209,  210,  211,  212,  213,  214,  215,  216,
    217,  218,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    88,   89,   90,   91,   92,   93,   94,   95,   0,    96,   97,
    98,   99,   100,  156,  0,    101,  0,    0,    0,    0,    0,    0,
    0,    0,    88,   89,   90,   91,   92,   93,   94,   95,   0,    96,
    97,   98,   99,   100,  0,    0,    101,  0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    199,  200,  201,  202,  203,  204,  205,
    434,  206,  207,  208,  209,  210,  211,  212,  213,  214,  215,  216,
    217,  218,  199,  200,  201,  202,  203,  204,  205,  0,    206,  207,
    208,  209,  210,  211,  212,  213,  214,  215,  216,  217,  218,  0,
    0,    0,    0,    0,    0,    0,    0,    0,    88,   89,   90,   91,
    92,   93,   94,   95,   0,    96,   97,   98,   99,   100,  0,    0,
    101,  199,  200,  201,  202,  203,  204,  205,  0,    206,  207,  208,
    209,  210,  211,  212,  213,  214,  215,  216,  217,  218,  0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    88,   89,   90,
    91,   92,   93,   94,   95,   0,    96,   97,   98,   99,   100,  0,
    0,    135,  199,  200,  201,  202,  203,  204,  205,  0,    206,  207,
    208,  209,  210,  211,  212,  213,  214,  215,  216,  217,  218,  0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    88,   89,
    90,   91,   92,   93,   94,   95,   0,    96,   97,   98,   99,   100,
    0,    0,    101,  199,  200,  201,  202,  203,  204,  205,  0,    206,
    207,  208,  209,  210,  211,  212,  213,  214,  215,  216,  217,  218,
    0,    88,   89,   90,   91,   92,   93,   94,   95,   0,    96,   97,
    98,   99,   100,  0,    0,    101,  199,  200,  201,  202,  203,  204,
    205,  0,    206,  207,  208,  209,  210,  211,  212,  213,  214,  215,
    216,  217,  218,  199,  200,  201,  202,  203,  204,  205,  0,    206,
    207,  208,  209,  210,  211,  212,  213,  214,  215,  216,  217,  218,
    0,    436,  199,  200,  201,  202,  203,  204,  205,  0,    206,  207,
    208,  209,  210,  211,  212,  213,  214,  215,  216,  217,  218,  199,
    200,  201,  202,  203,  204,  205,  0,    206,  207,  208,  209,  210,
    211,  212,  213,  214,  215,  216,  217,  218,  199,  200,  201,  202,
    203,  204,  205,  0,    206,  207,  208,  209,  210,  211,  212,  213,
    214,  215,  216,  217,  218,  0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    421,  199,  200,  201,  202,  203,  204,
    205,  438,  206,  207,  208,  209,  210,  211,  212,  213,  214,  215,
    216,  217,  218,  199,  200,  201,  202,  203,  204,  205,  440,  206,
    207,  208,  209,  210,  211,  212,  213,  214,  215,  216,  217,  218,
    199,  200,  201,  202,  203,  204,  205,  0,    206,  207,  208,  209,
    210,  211,  212,  213,  214,  215,  216,  217,  218,  0,    0,    0,
    0,    0,    199,  200,  201,  202,  203,  204,  205,  442,  206,  207,
    208,  209,  210,  211,  212,  213,  214,  215,  216,  217,  218,  199,
    200,  201,  202,  203,  204,  205,  1,    206,  207,  208,  209,  210,
    211,  212,  213,  214,  215,  216,  217,  218,  0,    0,    -2,   1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    674,  0,
    199,  200,  201,  202,  203,  204,  205,  2,    206,  207,  208,  209,
    210,  211,  212,  213,  214,  215,  216,  217,  218,  0,    0,    0,
    2,    0,    0,    202,  203,  204,  205,  3,    206,  207,  208,  209,
    210,  211,  212,  213,  214,  215,  216,  217,  218,  0,    0,    744,
    3,    0,    0,    4,    5,    0,    0,    0,    0,    0,    0,    6,
    0,    0,    0,    675,  676,  677,  678,  679,  4,    5,    0,    7,
    698,  699,  0,    700,  6,    0,    701,  702,  0,    704,  705,  706,
    0,    0,    745,  709,  7,    711,  0,    713,  0,    0,    8,    0,
    715,  0,    0,    718,  0,    0,    0,    0,    0,    422,  0,    0,
    0,    9,    0,    8,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    9,    0,    266,  0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    199,  200,
    201,  202,  203,  204,  205,  272,  206,  207,  208,  209,  210,  211,
    212,  213,  214,  215,  216,  217,  218,  0,    10,   0,    680,  0,
    11,   0,    418,  0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    10,   0,    0,    0,    11,   788,  0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    12,   0,
    425,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    12,   0,    0,    0,    0,    0,    426,  0,    0,
    13,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    681,
    682,  0,    683,  0,    0,    13,   737,  0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    219,  0,    0,    0,    0,    0,    220,
    0,    199,  200,  201,  202,  203,  204,  205,  837,  206,  207,  208,
    209,  210,  211,  212,  213,  214,  215,  216,  217,  218,  199,  200,
    201,  202,  203,  204,  205,  0,    206,  207,  208,  209,  210,  211,
    212,  213,  214,  215,  216,  217,  218,  613,  614,  615,  616,  0,
    0,    -392, -392, -392, -392, 617,  206,  207,  208,  209,  210,  211,
    212,  213,  214,  215,  216,  217,  218,  0,    0,    0,    0,    618,
    619,  0,    0,    0,    0,    0,    620,  0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    621,  0,    0,    0,    0,    0,    0,
    0,    622,  0,    0,    0,    0,    0,    0,    623,  199,  200,  201,
    202,  203,  204,  205,  160,  206,  207,  208,  209,  210,  211,  212,
    213,  214,  215,  216,  217,  218,  624,  625,  0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    626,  627,  0,    0,    0,    628,  629,  630,  199,  200,  201,
    202,  203,  204,  205,  0,    206,  207,  208,  209,  210,  211,  212,
    213,  214,  215,  216,  217,  218,  0,    0,    0,    0,    0,    631,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    632,  0,    633,  0,    0,    517,
    0,    0,    0,    0,    0,    0,    410,  0,    0,    0,    0,    0,
    0,    634,  0,    0,    635,  636,  637,  638,  639,  0,    0,    0,
    0,    0,    0,    513,  0,    0,    0,    0,    0,    0,    0,    512,
    0,    640,  641,  0,    0,    0,    0,    0,    0,    642,  199,  200,
    201,  202,  203,  204,  205,  0,    206,  207,  208,  209,  210,  211,
    212,  213,  214,  215,  216,  217,  218,  199,  200,  201,  202,  203,
    204,  205,  0,    206,  207,  208,  209,  210,  211,  212,  213,  214,
    215,  216,  217,  218,  0,    0,    0,    227,  0,    0,    0,    0,
    0,    730,  199,  200,  201,  202,  203,  204,  205,  0,    206,  207,
    208,  209,  210,  211,  212,  213,  214,  215,  216,  217,  218,  0,
    0,    0,    0,    0,    0,    0,    0,    228,  0,    0,    0,    0,
    579,  199,  200,  201,  202,  203,  204,  205,  731,  206,  207,  208,
    209,  210,  211,  212,  213,  214,  215,  216,  217,  218,  0,    199,
    200,  201,  202,  203,  204,  205,  431,  206,  207,  208,  209,  210,
    211,  212,  213,  214,  215,  216,  217,  218,  0,    0,    0,    0,
    0,    452,  199,  200,  201,  202,  203,  204,  205,  0,    206,  207,
    208,  209,  210,  211,  212,  213,  214,  215,  216,  217,  218,  199,
    200,  201,  202,  203,  204,  205,  0,    206,  207,  469,  209,  210,
    211,  212,  213,  214,  215,  216,  217,  218,  199,  200,  201,  202,
    203,  204,  205,  0,    206,  207,  607,  209,  210,  211,  212,  213,
    214,  215,  216,  217,  218};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const unsigned char yyconflp[] = {
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   239,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   67,  0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   69,  0,   0,   0,   0,
    0,   0,   0,   0,   0,   65,  0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   73,  75,
    77,  79,  81,  83,  0,   85,  87,  89,  91,  93,  95,  97,  99,  101, 103,
    105, 107, 109, 111, 113, 115, 117, 119, 121, 123, 125, 0,   0,   0,   0,
    0,   127, 0,   0,   129, 131, 0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   133, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   135, 0,
    0,   0,   0,   0,   0,   0,   0,   0,   137, 139, 141, 143, 145, 0,   0,
    0,   0,   0,   147, 0,   0,   0,   0,   0,   0,   0,   0,   0,   149, 0,
    0,   151, 0,   0,   153, 0,   0,   0,   0,   0,   155, 0,   0,   157, 159,
    0,   0,   161, 163, 0,   0,   0,   0,   0,   0,   0,   0,   165, 0,   0,
    0,   0,   0,   0,   167, 0,   169, 0,   0,   0,   0,   0,   171, 173, 0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   71,
    0,   175, 0,   0,   0,   177, 0,   0,   0,   0,   179, 0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   181, 0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   183, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   185,
    0,   0,   0,   0,   187, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   189,
    191, 0,   193, 0,   195, 197, 0,   199, 0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   201,
    0,   0,   0,   0,   0,   203, 0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   205, 207, 209, 211, 213, 215, 217, 219, 0,   221,
    223, 225, 227, 229, 231, 233, 235, 237, 0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   1,   3,   5,   7,   9,   11,  0,
    0,   0,   0,   0,   0,   0,   0,   13,  15,  0,   0,   0,   0,   0,   17,
    19,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   21,  0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   23,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    25,  27,  29,  31,  33,  35,  37,  39,  0,   41,  43,  45,  47,  49,  0,
    0,   51,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   57,  0,   0,   0,   0,   0,   59,  61,  63,  0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   53,  0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   55,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short int yyconfl[] = {
    0, 34,  0, 34,  0, 34,  0, 34,  0, 34,  0, 34,  0, 34,  0, 34,  0, 34,
    0, 34,  0, 34,  0, 34,  0, 34,  0, 34,  0, 34,  0, 34,  0, 34,  0, 34,
    0, 34,  0, 34,  0, 34,  0, 34,  0, 34,  0, 34,  0, 34,  0, 34,  0, 2,
    0, 116, 0, 38,  0, 38,  0, 38,  0, 38,  0, 116, 0, 3,   0, 386, 0, 58,
    0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130,
    0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130,
    0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130,
    0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130,
    0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130,
    0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130,
    0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130,
    0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130,
    0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130,
    0, 130, 0, 130, 0, 74,  0};

static const short int yycheck[] = {
    11,  85,  401, 3,   3,   108, 12,  3,   171, 3,   132, 152, 50,  107, 50,
    160, 6,   3,   10,  11,  12,  13,  14,  15,  16,  123, 18,  19,  20,  21,
    22,  23,  24,  25,  26,  27,  28,  29,  30,  39,  39,  559, 5,   339, 55,
    56,  264, 129, 69,  245, 159, 159, 63,  64,  65,  66,  67,  37,  119, 236,
    169, 169, 225, 226, 215, 119, 10,  11,  12,  13,  14,  15,  16,  167, 18,
    19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  119, 119, 40,
    101, 3,   10,  11,  12,  13,  14,  15,  16,  135, 18,  19,  20,  21,  22,
    23,  24,  25,  26,  27,  28,  29,  30,  21,  22,  23,  24,  25,  26,  27,
    28,  29,  30,  184, 135, 6,   48,  198, 291, 170, 184, 649, 83,  215, 160,
    160, 3,   18,  301, 215, 120, 3,   183, 154, 340, 108, 375, 93,  186, 160,
    96,  550, 184, 184, 93,  191, 503, 96,  256, 109, 378, 105, 391, 340, 33,
    176, 340, 69,  158, 343, 339, 192, 173, 184, 185, 186, 187, 188, 189, 190,
    221, 192, 193, 194, 195, 196, 280, 137, 199, 200, 201, 202, 203, 356, 215,
    340, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 244, 195,
    236, 236, 134, 195, 215, 3,   279, 86,  120, 341, 361, 120, 3,   301, 3,
    236, 573, 0,   1,   3,   266, 309, 268, 132, 270, 298, 236, 340, 16,  189,
    18,  118, 336, 110, 307, 26,  108, 646, 647, 290, 344, 39,  26,  120, 300,
    301, 232, 119, 240, 630, 271, 272, 491, 634, 275, 132, 160, 273, 639, 787,
    341, 173, 283, 371, 285, 251, 18,  158, 339, 508, 3,   4,   5,   6,   7,
    8,   148, 341, 299, 343, 192, 690, 390, 120, 17,  18,  307, 118, 244, 41,
    336, 24,  25,  4,   171, 244, 215, 339, 402, 407, 341, 3,   188, 175, 216,
    57,  192, 193, 194, 195, 196, 720, 721, 0,   1,   724, 337, 338, 51,  215,
    548, 13,  14,  344, 16,  271, 272, 245, 80,  62,  340, 650, 651, 343, 343,
    341, 69,  341, 340, 340, 342, 342, 53,  81,  53,  341, 55,  451, 3,   453,
    454, 455, 321, 322, 370, 21,  22,  23,  24,  25,  26,  27,  28,  29,  30,
    538, 99,  388, 340, 708, 342, 710, 340, 3,   342, 714, 114, 716, 89,  718,
    132, 119, 26,  27,  28,  29,  30,  120, 342, 410, 411, 129, 343, 104, 736,
    737, 490, 418, 9,   3,   421, 422, 460, 461, 462, 451, 158, 458, 341, 108,
    148, 3,   340, 301, 342, 824, 127, 198, 14,  171, 3,   339, 340, 527, 10,
    11,  12,  13,  14,  15,  16,  452, 18,  19,  20,  21,  22,  23,  24,  25,
    26,  27,  28,  29,  30,  303, 105, 138, 469, 470, 466, 4,   5,   6,   7,
    301, 560, 108, 279, 192, 341, 565, 19,  20,  21,  22,  23,  24,  25,  26,
    27,  28,  29,  30,  813, 814, 341, 341, 230, 341, 341, 527, 215, 300, 341,
    341, 341, 341, 341, 593, 341, 341, 513, 341, 198, 39,  517, 518, 5,   10,
    11,  12,  13,  14,  15,  16,  3,   18,  19,  20,  21,  22,  23,  24,  25,
    26,  27,  28,  29,  30,  701, 702, 543, 704, 705, 706, 542, 339, 709, 545,
    711, 108, 713, 18,  715, 3,   3,   3,   3,   343, 99,  562, 3,   160, 108,
    3,   567, 593, 3,   282, 283, 572, 247, 129, 3,   341, 108, 290, 129, 341,
    581, 340, 583, 296, 297, 3,   299, 300, 301, 302, 3,   304, 305, 306, 3,
    308, 309, 310, 3,   245, 195, 602, 4,   3,   8,   342, 607, 14,  341, 108,
    323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 3,   334, 335, 336, 337,
    338, 3,   342, 341, 10,  11,  12,  13,  14,  15,  16,  342, 18,  19,  20,
    21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  3,   108, 3,   3,   4,
    5,   6,   7,   8,   685, 10,  11,  12,  13,  14,  15,  16,  17,  18,  19,
    20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  341, 99,  236, 26,
    245, 36,  3,   3,   39,  40,  3,   342, 339, 340, 4,   108, 342, 342, 342,
    342, 51,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  63,  342,
    342, 3,   4,   5,   6,   7,   8,   342, 73,  74,  75,  76,  77,  802, 342,
    17,  18,  341, 83,  735, 736, 737, 24,  25,  63,  741, 742, 342, 93,  30,
    341, 96,  341, 341, 99,  3,   131, 167, 3,   3,   105, 3,   247, 108, 109,
    47,  160, 112, 113, 51,  24,  25,  26,  27,  28,  29,  30,  122, 165, 247,
    340, 342, 3,   247, 129, 342, 131, 128, 342, 16,  109, 341, 137, 138, 790,
    23,  24,  25,  26,  27,  28,  29,  30,  122, 342, 342, 342, 131, 69,  160,
    131, 156, 131, 4,   340, 160, 340, 99,  137, 342, 165, 3,   3,   48,  4,
    3,   4,   5,   6,   7,   8,   176, 4,   20,  342, 341, 4,   156, 160, 17,
    18,  837, 160, 20,  189, 342, 24,  25,  26,  110, 342, 342, 341, 135, 342,
    33,  342, 340, 342, 120, 132, 342, 3,   4,   5,   6,   7,   8,   342, 214,
    189, 342, 341, 51,  219, 341, 17,  18,  340, 342, 341, 340, 161, 24,  25,
    3,   340, 3,   5,   112, 340, 342, 33,  342, 341, 214, 37,  4,   20,  244,
    245, 160, 247, 341, 249, 250, 341, 252, 86,  44,  51,  3,   173, 341, 341,
    3,   4,   5,   6,   7,   8,   99,  341, 341, 341, 4,   132, 20,  342, 17,
    18,  192, 4,   169, 340, 48,  24,  25,  113, 342, 191, 342, 203, 5,   226,
    33,  22,  23,  24,  25,  26,  27,  28,  29,  30,  216, 3,   5,   99,  304,
    4,   342, 5,   51,  233, 310, 342, 340, 342, 230, 21,  22,  23,  24,  25,
    26,  27,  28,  29,  30,  325, 326, 327, 328, 329, 330, 331, 332, 342, 334,
    335, 336, 337, 338, 339, 340, 341, 342, 86,  342, 340, 191, 160, 342, 20,
    169, 342, 158, 4,   132, 342, 99,  342, 3,   4,   5,   6,   7,   8,   342,
    20,  340, 3,   247, 7,   5,   160, 17,  18,  198, 3,   340, 4,   7,   24,
    25,  190, 340, 3,   3,   342, 342, 837, 325, 326, 327, 328, 329, 330, 331,
    332, 114, 334, 335, 336, 337, 338, 788, 743, 341, 201, 51,  275, 483, 790,
    3,   4,   5,   6,   7,   8,   606, 685, 426, 161, 6,   712, 848, 796, 17,
    18,  123, 791, -1,  392, -1,  24,  25,  26,  11,  12,  13,  14,  15,  16,
    -1,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  99,
    -1,  -1,  -1,  51,  3,   4,   5,   6,   7,   8,   -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  17,  18,  -1,  -1,  -1,  -1,  -1,  24,  25,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  325, 326, 327, 328, 329, 330, 331, 332,
    -1,  334, 335, 336, 337, 338, 99,  51,  341, -1,  12,  13,  14,  15,  16,
    160, 18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  325,
    326, 327, 328, 329, 330, 331, 332, -1,  334, 335, 336, 337, 338, -1,  -1,
    341, -1,  -1,  3,   4,   5,   6,   7,   8,   -1,  99,  -1,  -1,  -1,  -1,
    -1,  -1,  17,  18,  -1,  -1,  -1,  -1,  -1,  24,  25,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  325, 326, 327, 328, 329, 330, 331, 332,
    -1,  334, 335, 336, 337, 338, 51,  -1,  341, 3,   4,   5,   6,   7,   8,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  17,  18,  -1,  -1,  -1,  -1,  -1,
    24,  25,  -1,  -1,  3,   4,   5,   6,   7,   8,   -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  17,  18,  -1,  -1,  -1,  -1,  99,  24,  25,  51,  10,  11,
    12,  13,  14,  15,  16,  -1,  18,  19,  20,  21,  22,  23,  24,  25,  26,
    27,  28,  29,  30,  -1,  -1,  -1,  51,  -1,  -1,  -1,  80,  -1,  -1,  -1,
    325, 326, 327, 328, 329, 330, 331, 332, -1,  334, 335, 336, 337, 338, -1,
    99,  341, -1,  -1,  -1,  244, 80,  3,   4,   5,   6,   7,   8,   -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  17,  18,  -1,  -1,  99,  -1,  -1,  24,  25,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  325, 326, 327, 328, 329, 330, 331, 332,
    195, 334, 335, 336, 337, 338, -1,  -1,  341, -1,  51,  3,   4,   5,   6,
    7,   8,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  17,  18,  -1,  -1,  -1,
    -1,  -1,  24,  25,  -1,  -1,  -1,  -1,  -1,  80,  -1,  325, 326, 327, 328,
    329, 330, 331, 332, -1,  334, 335, 336, 337, 338, -1,  -1,  341, 99,  51,
    3,   4,   5,   6,   7,   8,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  17,
    18,  -1,  -1,  -1,  -1,  -1,  24,  25,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  3,   4,   5,   6,   7,   8,
    -1,  -1,  99,  51,  -1,  -1,  -1,  -1,  17,  18,  -1,  -1,  -1,  -1,  -1,
    24,  25,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  325, 326, 327, 328, 329,
    330, 331, 332, -1,  334, 335, 336, 337, 338, -1,  -1,  341, 51,  -1,  10,
    11,  12,  13,  14,  15,  16,  99,  18,  19,  20,  21,  22,  23,  24,  25,
    26,  27,  28,  29,  30,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  325, 326, 327, 328, 329, 330, 331, 332, -1,  334, 335, 336, 337, 338,
    99,  -1,  341, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  325, 326, 327, 328,
    329, 330, 331, 332, -1,  334, 335, 336, 337, 338, -1,  -1,  341, -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  10,  11,  12,  13,  14,  15,  16,
    342, 18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  10,
    11,  12,  13,  14,  15,  16,  -1,  18,  19,  20,  21,  22,  23,  24,  25,
    26,  27,  28,  29,  30,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  325,
    326, 327, 328, 329, 330, 331, 332, -1,  334, 335, 336, 337, 338, -1,  -1,
    341, 10,  11,  12,  13,  14,  15,  16,  -1,  18,  19,  20,  21,  22,  23,
    24,  25,  26,  27,  28,  29,  30,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  325, 326, 327, 328, 329, 330, 331, 332, -1,  334, 335, 336,
    337, 338, -1,  -1,  341, 10,  11,  12,  13,  14,  15,  16,  -1,  18,  19,
    20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  325, 326, 327, 328, 329, 330, 331, 332,
    -1,  334, 335, 336, 337, 338, -1,  -1,  341, 10,  11,  12,  13,  14,  15,
    16,  -1,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,
    -1,  325, 326, 327, 328, 329, 330, 331, 332, -1,  334, 335, 336, 337, 338,
    -1,  -1,  341, 10,  11,  12,  13,  14,  15,  16,  -1,  18,  19,  20,  21,
    22,  23,  24,  25,  26,  27,  28,  29,  30,  10,  11,  12,  13,  14,  15,
    16,  -1,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,
    -1,  342, 10,  11,  12,  13,  14,  15,  16,  -1,  18,  19,  20,  21,  22,
    23,  24,  25,  26,  27,  28,  29,  30,  10,  11,  12,  13,  14,  15,  16,
    -1,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  10,
    11,  12,  13,  14,  15,  16,  -1,  18,  19,  20,  21,  22,  23,  24,  25,
    26,  27,  28,  29,  30,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  108, 10,  11,  12,  13,  14,  15,  16,  342, 18,  19,  20,  21,
    22,  23,  24,  25,  26,  27,  28,  29,  30,  10,  11,  12,  13,  14,  15,
    16,  342, 18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,
    10,  11,  12,  13,  14,  15,  16,  -1,  18,  19,  20,  21,  22,  23,  24,
    25,  26,  27,  28,  29,  30,  -1,  -1,  -1,  -1,  -1,  10,  11,  12,  13,
    14,  15,  16,  342, 18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,
    29,  30,  10,  11,  12,  13,  14,  15,  16,  1,   18,  19,  20,  21,  22,
    23,  24,  25,  26,  27,  28,  29,  30,  -1,  -1,  0,   1,   -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  342, -1,  10,  11,  12,  13,  14,  15,
    16,  38,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,
    -1,  -1,  -1,  38,  -1,  -1,  13,  14,  15,  16,  62,  18,  19,  20,  21,
    22,  23,  24,  25,  26,  27,  28,  29,  30,  -1,  -1,  342, 62,  -1,  -1,
    82,  83,  -1,  -1,  -1,  -1,  -1,  -1,  90,  -1,  -1,  -1,  73,  74,  75,
    76,  77,  82,  83,  -1,  102, 614, 615, -1,  617, 90,  -1,  620, 621, -1,
    623, 624, 625, -1,  -1,  342, 629, 102, 631, -1,  633, -1,  -1,  125, -1,
    638, -1,  -1,  641, -1,  -1,  -1,  -1,  -1,  340, -1,  -1,  -1,  140, -1,
    125, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    140, -1,  340, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  10,  11,  12,  13,  14,  15,  16,  340, 18,  19,  20,  21,  22,  23,
    24,  25,  26,  27,  28,  29,  30,  -1,  195, -1,  176, -1,  199, -1,  340,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  195, -1,  -1,  -1,  199,
    728, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  233, -1,  340, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  233, -1,  -1,  -1,  -1,  -1,  340, -1,  -1,  259, -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  249, 250, -1,  252, -1,  -1,  259,
    340, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  304, -1,  -1,  -1,
    -1,  -1,  310, -1,  10,  11,  12,  13,  14,  15,  16,  340, 18,  19,  20,
    21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  10,  11,  12,  13,  14,
    15,  16,  -1,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,
    30,  43,  44,  45,  46,  -1,  -1,  13,  14,  15,  16,  53,  18,  19,  20,
    21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  -1,  -1,  -1,  -1,  71,
    72,  -1,  -1,  -1,  -1,  -1,  78,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  89,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  97,  -1,  -1,  -1,  -1,
    -1,  -1,  104, 10,  11,  12,  13,  14,  15,  16,  244, 18,  19,  20,  21,
    22,  23,  24,  25,  26,  27,  28,  29,  30,  126, 127, -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  145, 146,
    -1,  -1,  -1,  150, 151, 152, 10,  11,  12,  13,  14,  15,  16,  -1,  18,
    19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  -1,  -1,  -1,
    -1,  -1,  179, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  198, -1,  200, -1,  -1,  108, -1,  -1,  -1,
    -1,  -1,  -1,  219, -1,  -1,  -1,  -1,  -1,  -1,  217, -1,  -1,  220, 221,
    222, 223, 224, -1,  -1,  -1,  -1,  -1,  -1,  219, -1,  -1,  -1,  -1,  -1,
    -1,  -1,  96,  -1,  241, 242, -1,  -1,  -1,  -1,  -1,  -1,  249, 10,  11,
    12,  13,  14,  15,  16,  -1,  18,  19,  20,  21,  22,  23,  24,  25,  26,
    27,  28,  29,  30,  10,  11,  12,  13,  14,  15,  16,  -1,  18,  19,  20,
    21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  -1,  -1,  -1,  3,   -1,
    -1,  -1,  -1,  -1,  40,  10,  11,  12,  13,  14,  15,  16,  -1,  18,  19,
    20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  39,  -1,  -1,  -1,  -1,  96,  10,  11,  12,  13,  14,
    15,  16,  83,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,
    30,  -1,  10,  11,  12,  13,  14,  15,  16,  39,  18,  19,  20,  21,  22,
    23,  24,  25,  26,  27,  28,  29,  30,  -1,  -1,  -1,  -1,  -1,  36,  10,
    11,  12,  13,  14,  15,  16,  -1,  18,  19,  20,  21,  22,  23,  24,  25,
    26,  27,  28,  29,  30,  10,  11,  12,  13,  14,  15,  16,  -1,  18,  19,
    20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  10,  11,  12,  13,
    14,  15,  16,  -1,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,
    29,  30};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short int yystos[] = {
    0,   1,   38,  62,  82,  83,  90,  102, 125, 140, 195, 199, 233, 259, 345,
    346, 347, 383, 385, 398, 399, 404, 405, 406, 407, 409, 412, 413, 414, 422,
    429, 433, 339, 215, 69,  110, 173, 192, 203, 216, 230, 388, 400, 430, 3,
    69,  120, 173, 192, 388, 129, 215, 416, 215, 33,  86,  359, 3,   4,   5,
    6,   7,   8,   17,  18,  24,  25,  51,  62,  69,  99,  120, 192, 215, 282,
    283, 290, 296, 297, 299, 302, 304, 305, 306, 308, 310, 323, 324, 325, 326,
    327, 328, 329, 330, 331, 332, 334, 335, 336, 337, 338, 341, 376, 423, 427,
    428, 3,   341, 365, 375, 173, 215, 0,   1,   339, 3,   118, 384, 160, 384,
    215, 120, 3,   108, 119, 148, 175, 431, 118, 408, 3,   5,   108, 408, 215,
    341, 376, 377, 3,   81,  114, 119, 129, 148, 417, 3,   160, 360, 376, 26,
    361, 362, 376, 343, 9,   376, 99,  376, 376, 376, 244, 376, 382, 69,  192,
    215, 3,   341, 108, 3,   301, 198, 14,  425, 3,   303, 138, 356, 105, 301,
    108, 424, 356, 279, 341, 341, 341, 341, 341, 341, 341, 341, 341, 341, 341,
    341, 341, 376, 377, 10,  11,  12,  13,  14,  15,  16,  18,  19,  20,  21,
    22,  23,  24,  25,  26,  27,  28,  29,  30,  304, 310, 279, 298, 307, 300,
    301, 309, 3,   39,  343, 367, 347, 363, 364, 365, 368, 198, 39,  366, 5,
    3,   410, 339, 345, 108, 18,  3,   3,   3,   384, 3,   343, 432, 3,   363,
    431, 108, 340, 99,  3,   160, 108, 3,   3,   408, 377, 340, 247, 129, 3,
    108, 341, 340, 129, 357, 340, 367, 3,   26,  376, 341, 376, 382, 93,  96,
    244, 3,   3,   3,   347, 3,   424, 425, 4,   300, 301, 376, 8,   3,   14,
    426, 424, 376, 47,  135, 226, 376, 379, 376, 376, 26,  359, 376, 376, 376,
    377, 359, 376, 359, 376, 359, 376, 359, 376, 359, 376, 342, 342, 376, 376,
    376, 376, 376, 6,   18,  158, 341, 13,  14,  16,  376, 33,  37,  201, 341,
    376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 424, 108, 425, 425,
    3,   3,   342, 342, 63,  109, 122, 137, 156, 189, 214, 340, 369, 371, 376,
    434, 3,   108, 340, 343, 377, 99,  341, 3,   236, 401, 26,  343, 245, 348,
    236, 363, 3,   3,   3,   410, 342, 377, 4,   377, 198, 341, 418, 377, 360,
    360, 365, 108, 361, 347, 219, 93,  96,  376, 376, 342, 424, 425, 340, 376,
    425, 108, 340, 342, 376, 340, 340, 342, 342, 342, 342, 39,  342, 342, 342,
    342, 342, 342, 342, 342, 342, 342, 342, 16,  18,  6,   158, 347, 377, 376,
    376, 341, 36,  341, 341, 341, 347, 425, 3,   367, 109, 137, 189, 372, 365,
    363, 131, 167, 370, 20,  340, 348, 3,   410, 3,   247, 3,   358, 119, 184,
    341, 343, 386, 387, 321, 322, 402, 160, 376, 165, 354, 363, 348, 432, 50,
    186, 411, 340, 247, 3,   421, 358, 240, 347, 247, 342, 159, 169, 363, 342,
    376, 376, 96,  219, 376, 376, 376, 108, 128, 381, 381, 4,   53,  89,  104,
    127, 380, 341, 16,  342, 342, 347, 377, 376, 347, 347, 347, 342, 424, 370,
    370, 370, 131, 160, 365, 131, 376, 376, 340, 4,   340, 342, 3,   110, 120,
    132, 171, 389, 390, 3,   366, 3,   48,  356, 348, 4,   4,   20,  160, 340,
    415, 342, 341, 419, 415, 4,   20,  160, 348, 96,  376, 105, 342, 340, 342,
    376, 376, 342, 342, 342, 347, 377, 378, 341, 342, 342, 342, 342, 342, 425,
    365, 376, 160, 236, 373, 374, 365, 20,  410, 340, 358, 159, 169, 43,  44,
    45,  46,  53,  71,  72,  78,  89,  97,  104, 126, 127, 145, 146, 150, 151,
    152, 179, 198, 200, 217, 220, 221, 222, 223, 224, 241, 242, 249, 392, 120,
    132, 341, 341, 132, 342, 340, 341, 386, 347, 341, 355, 376, 347, 340, 80,
    376, 161, 3,   80,  376, 420, 415, 340, 5,   3,   112, 349, 376, 376, 342,
    73,  74,  75,  76,  77,  176, 249, 250, 252, 342, 340, 342, 347, 377, 376,
    341, 374, 376, 4,   20,  160, 341, 394, 394, 394, 394, 394, 394, 341, 394,
    394, 394, 44,  395, 394, 395, 394, 341, 394, 395, 394, 395, 341, 394, 391,
    341, 341, 358, 358, 341, 386, 389, 389, 3,   403, 40,  83,  351, 4,   132,
    20,  340, 340, 342, 4,   169, 48,  113, 353, 342, 342, 378, 342, 342, 358,
    191, 5,   3,   5,   396, 397, 396, 396, 4,   393, 396, 396, 396, 397, 396,
    397, 396, 393, 396, 397, 396, 397, 5,   397, 18,  41,  57,  80,  132, 158,
    171, 230, 358, 358, 342, 342, 358, 342, 394, 342, 340, 233, 80,  376, 420,
    420, 340, 191, 160, 350, 376, 376, 354, 342, 20,  169, 340, 342, 232, 251,
    53,  55,  340, 342, 342, 342, 158, 4,   4,   5,   6,   7,   132, 132, 341,
    342, 342, 342, 386, 351, 355, 421, 419, 20,  3,   247, 352, 340, 356, 7,
    160, 5,   198, 3,   4,   397, 397, 358, 340, 7,   190, 350, 3,   342, 3,
    342, 403};

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
#line 450 "sql.ypp"
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
#line 464 "sql.ypp"
    {
      printf(">> \n");
      ((*yyvalp).ast_node) = new AstStmtList(
          AST_STMT_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                              .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
      if (result->error_number == 0) {
        result->ast = ((*yyvalp).ast_node);
      } else {
        result->ast = NULL;
      }
    } break;

    case 4:
/* Line 868 of glr.c  */
#line 477 "sql.ypp"
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
#line 486 "sql.ypp"
    {
      printf(">> \n");
      result->ast = NULL;
      result->error_number++;
      yyclearin;
      yyerrok;
    } break;

    case 6:
/* Line 868 of glr.c  */
#line 497 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 7:
/* Line 868 of glr.c  */
#line 508 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstSelectStmt(
          AST_SELECT_STMT, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (11))]
                                .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (11))].yystate.yysemantics.yysval.ast_node),
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
            yyvsp)[YYFILL((11) - (11))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (11))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 8:
/* Line 868 of glr.c  */
#line 513 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 9:
/* Line 868 of glr.c  */
#line 514 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstWhereClause(
          AST_WHERE_CLAUSE, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (2))]
                                 .yystate.yysemantics.yysval.ast_node));
    } break;

    case 10:
/* Line 868 of glr.c  */
#line 517 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 11:
/* Line 868 of glr.c  */
#line 518 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstGroupByClause(
          AST_GROUPBY_CLAUSE,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (4))].yystate.yysemantics.yysval.intval));
    } break;

    case 12:
/* Line 868 of glr.c  */
#line 523 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstGroupByList(
          AST_GROUPBY_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                 .yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 13:
/* Line 868 of glr.c  */
#line 524 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstGroupByList(
          AST_GROUPBY_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                                 .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 14:
/* Line 868 of glr.c  */
#line 526 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 15:
/* Line 868 of glr.c  */
#line 527 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 16:
/* Line 868 of glr.c  */
#line 528 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 17:
/* Line 868 of glr.c  */
#line 531 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 18:
/* Line 868 of glr.c  */
#line 532 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 19:
/* Line 868 of glr.c  */
#line 535 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 20:
/* Line 868 of glr.c  */
#line 536 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstHavingClause(
          AST_HAVING_CLAUSE, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (2))]
                                  .yystate.yysemantics.yysval.ast_node));
    } break;

    case 21:
/* Line 868 of glr.c  */
#line 539 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 22:
/* Line 868 of glr.c  */
#line 540 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstOrderByClause(
          AST_ORDERBY_CLAUSE,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 23:
/* Line 868 of glr.c  */
#line 543 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstOrderByList(
          AST_ORDERBY_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                 .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (2))].yystate.yysemantics.yysval.intval),
          NULL);
    } break;

    case 24:
/* Line 868 of glr.c  */
#line 544 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstOrderByList(
          AST_ORDERBY_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (4))]
                                 .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (4))].yystate.yysemantics.yysval.intval),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 25:
/* Line 868 of glr.c  */
#line 546 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 26:
/* Line 868 of glr.c  */
#line 547 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstLimitClause(
          AST_LIMIT_CLAUSE, NULL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (2))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 27:
/* Line 868 of glr.c  */
#line 548 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstLimitClause(
          AST_LIMIT_CLAUSE, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (4))]
                                 .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 28:
/* Line 868 of glr.c  */
#line 551 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 29:
/* Line 868 of glr.c  */
#line 552 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstSelectIntoClause(
          AST_SELECT_INTO_CLAUSE,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (5))].yystate.yysemantics.yysval.ast_node),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((5) - (5))]
                      .yystate.yysemantics.yysval.strval)),
          1);
    } break;

    case 30:
/* Line 868 of glr.c  */
#line 554 "sql.ypp"
    {
      if ((((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (8))].yystate.yysemantics.yysval.subtok) != 4) {
        yyerror(result, "please give a specific number");
      } else {
        ((*yyvalp).ast_node) = new AstSelectIntoClause(
            AST_SELECT_INTO_CLAUSE,
            (((yyGLRStackItem const *)
              yyvsp)[YYFILL((2) - (8))].yystate.yysemantics.yysval.ast_node),
            string((((yyGLRStackItem const *)yyvsp)[YYFILL((8) - (8))]
                        .yystate.yysemantics.yysval.strval)),
            atoi((((yyGLRStackItem const *)yyvsp)[YYFILL((5) - (8))]
                      .yystate.yysemantics.yysval.strval)));
      }
    } break;

    case 31:
/* Line 868 of glr.c  */
#line 561 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstColumn(
          AST_COLUMN, string("NULL"),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 32:
/* Line 868 of glr.c  */
#line 562 "sql.ypp"
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
#line 577 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 34:
/* Line 868 of glr.c  */
#line 578 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstDistinctClause(AST_DISTINCT_CLAUSE, NULL, 1);
    } break;

    case 35:
/* Line 868 of glr.c  */
#line 579 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDistinctClause(
          AST_DISTINCT_CLAUSE,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (5))].yystate.yysemantics.yysval.ast_node),
          2);
    } break;

    case 36:
/* Line 868 of glr.c  */
#line 580 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstDistinctClause(AST_DISTINCT_CLAUSE, NULL, 0);
    } break;

    case 37:
/* Line 868 of glr.c  */
#line 581 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDistinctClause(
          AST_DISTINCT_CLAUSE,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (2))].yystate.yysemantics.yysval.ast_node),
          3);
    } break;

    case 38:
/* Line 868 of glr.c  */
#line 585 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDistinctList(
          AST_DISTINCT_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 39:
/* Line 868 of glr.c  */
#line 586 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDistinctList(
          AST_DISTINCT_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                                  .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 40:
/* Line 868 of glr.c  */
#line 590 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstSelectList(
          AST_SELECT_LIST, 0,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (1))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 41:
/* Line 868 of glr.c  */
#line 591 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstSelectList(
          AST_SELECT_LIST, 0,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 42:
/* Line 868 of glr.c  */
#line 592 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstSelectList(AST_SELECT_LIST, 1, NULL, NULL);
    } break;

    case 43:
/* Line 868 of glr.c  */
#line 596 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstSelectExpr(
          AST_SELECT_EXPR,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (2))]
                      .yystate.yysemantics.yysval.strval)),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (2))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 44:
/* Line 868 of glr.c  */
#line 599 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstFromList(
          AST_FROM_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                              .yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 45:
/* Line 868 of glr.c  */
#line 600 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstFromList(
          AST_FROM_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                              .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 46:
/* Line 868 of glr.c  */
#line 604 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 47:
/* Line 868 of glr.c  */
#line 605 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 48:
/* Line 868 of glr.c  */
#line 610 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstTable(
          AST_TABLE, string("NULL"),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                      .yystate.yysemantics.yysval.strval)),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (2))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 49:
/* Line 868 of glr.c  */
#line 612 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstTable(
          AST_TABLE, string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (4))]
                                 .yystate.yysemantics.yysval.strval)),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (4))]
                      .yystate.yysemantics.yysval.strval)),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (4))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 50:
/* Line 868 of glr.c  */
#line 613 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstSubquery(
          AST_SUBQUERY,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (3))]
                      .yystate.yysemantics.yysval.strval)),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 51:
/* Line 868 of glr.c  */
#line 614 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 54:
/* Line 868 of glr.c  */
#line 621 "sql.ypp"
    {
      ((*yyvalp).strval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (2))]
                                .yystate.yysemantics.yysval.strval);
    } break;

    case 55:
/* Line 868 of glr.c  */
#line 622 "sql.ypp"
    {
      ((*yyvalp).strval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                .yystate.yysemantics.yysval.strval);
    } break;

    case 56:
/* Line 868 of glr.c  */
#line 623 "sql.ypp"
    {
      ((*yyvalp).strval) = "NULL";
    } break;

    case 57:
/* Line 868 of glr.c  */
#line 638 "sql.ypp"
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

    case 58:
/* Line 868 of glr.c  */
#line 639 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstJoin(
          AST_JOIN, -1, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                             .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 59:
/* Line 868 of glr.c  */
#line 640 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstJoin(
          AST_JOIN, -1, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (5))]
                             .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (5))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 60:
/* Line 868 of glr.c  */
#line 641 "sql.ypp"
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

    case 61:
/* Line 868 of glr.c  */
#line 642 "sql.ypp"
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

    case 62:
/* Line 868 of glr.c  */
#line 645 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 63:
/* Line 868 of glr.c  */
#line 646 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 64:
/* Line 868 of glr.c  */
#line 647 "sql.ypp"
    {
      ((*yyvalp).intval) = 2;
    } break;

    case 65:
/* Line 868 of glr.c  */
#line 650 "sql.ypp"
    {
      ((*yyvalp).intval) = 4;
    } break;

    case 66:
/* Line 868 of glr.c  */
#line 651 "sql.ypp"
    {
      ((*yyvalp).intval) = 4;
    } break;

    case 67:
/* Line 868 of glr.c  */
#line 655 "sql.ypp"
    {
      ((*yyvalp).intval) = 8;
    } break;

    case 68:
/* Line 868 of glr.c  */
#line 656 "sql.ypp"
    {
      ((*yyvalp).intval) = 16;
    } break;

    case 69:
/* Line 868 of glr.c  */
#line 657 "sql.ypp"
    {
      ((*yyvalp).intval) = 64;
    } break;

    case 70:
/* Line 868 of glr.c  */
#line 661 "sql.ypp"
    {
      ((*yyvalp).intval) =
          8 + (((yyGLRStackItem const *)
                yyvsp)[YYFILL((2) - (2))].yystate.yysemantics.yysval.intval);
    } break;

    case 71:
/* Line 868 of glr.c  */
#line 662 "sql.ypp"
    {
      ((*yyvalp).intval) =
          16 + (((yyGLRStackItem const *)
                 yyvsp)[YYFILL((2) - (2))].yystate.yysemantics.yysval.intval);
    } break;

    case 72:
/* Line 868 of glr.c  */
#line 663 "sql.ypp"
    {
      ((*yyvalp).intval) =
          64 + (((yyGLRStackItem const *)
                 yyvsp)[YYFILL((2) - (2))].yystate.yysemantics.yysval.intval);
    } break;

    case 73:
/* Line 868 of glr.c  */
#line 664 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 74:
/* Line 868 of glr.c  */
#line 667 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 75:
/* Line 868 of glr.c  */
#line 668 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 76:
/* Line 868 of glr.c  */
#line 676 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstJoinCondition(
          AST_JOIN_CONDITION, "ON",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (2))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 77:
/* Line 868 of glr.c  */
#line 677 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstJoinCondition(
          AST_JOIN_CONDITION, "USING",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 78:
/* Line 868 of glr.c  */
#line 682 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 79:
/* Line 868 of glr.c  */
#line 689 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstColumn(
          AST_COLUMN, string("NULL"),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 80:
/* Line 868 of glr.c  */
#line 690 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprConst(
          AST_EXPR_CONST, "CONST",
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 81:
/* Line 868 of glr.c  */
#line 691 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstColumn(
          AST_COLUMN, string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                                  .yystate.yysemantics.yysval.strval)),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (3))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 82:
/* Line 868 of glr.c  */
#line 692 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstColumn(
          AST_COLUMN_ALL,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                      .yystate.yysemantics.yysval.strval)),
          string("*"));
    } break;

    case 83:
/* Line 868 of glr.c  */
#line 693 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprConst(
          AST_EXPR_CONST, "CONST_STRING",
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 84:
/* Line 868 of glr.c  */
#line 694 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprConst(
          AST_EXPR_CONST, "CONST_INT",
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 85:
/* Line 868 of glr.c  */
#line 695 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprConst(
          AST_EXPR_CONST, "CONST_DOUBLE",
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 86:
/* Line 868 of glr.c  */
#line 696 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprConst(
          AST_EXPR_CONST, "CONST_BOOL",
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 87:
/* Line 868 of glr.c  */
#line 698 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_CAL_BINARY, "+",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 88:
/* Line 868 of glr.c  */
#line 699 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_CAL_BINARY, "-",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 89:
/* Line 868 of glr.c  */
#line 700 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_CAL_BINARY, "*",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 90:
/* Line 868 of glr.c  */
#line 701 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_CAL_BINARY, "/",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 91:
/* Line 868 of glr.c  */
#line 702 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_CAL_BINARY, "MOD",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 92:
/* Line 868 of glr.c  */
#line 703 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_CAL_BINARY, "%",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 93:
/* Line 868 of glr.c  */
#line 705 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "-",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (2))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 94:
/* Line 868 of glr.c  */
#line 706 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "+",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (2))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 95:
/* Line 868 of glr.c  */
#line 708 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_BOOL_BINARY, "AND",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 96:
/* Line 868 of glr.c  */
#line 709 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_BOOL_BINARY, "OR",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 97:
/* Line 868 of glr.c  */
#line 710 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_BOOL_BINARY, "XOR",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 98:
/* Line 868 of glr.c  */
#line 712 "sql.ypp"
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

    case 99:
/* Line 868 of glr.c  */
#line 713 "sql.ypp"
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

    case 100:
/* Line 868 of glr.c  */
#line 714 "sql.ypp"
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

    case 101:
/* Line 868 of glr.c  */
#line 715 "sql.ypp"
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

    case 102:
/* Line 868 of glr.c  */
#line 716 "sql.ypp"
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

    case 103:
/* Line 868 of glr.c  */
#line 718 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_CAL_BINARY, "|",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 104:
/* Line 868 of glr.c  */
#line 719 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_CAL_BINARY, "&",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 105:
/* Line 868 of glr.c  */
#line 720 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_CAL_BINARY, "^",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 106:
/* Line 868 of glr.c  */
#line 721 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_CAL_BINARY, SHIFT == 1 ? "LSHIFT" : "RSHIFT",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 107:
/* Line 868 of glr.c  */
#line 723 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "!",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (2))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 108:
/* Line 868 of glr.c  */
#line 724 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "NOT",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (2))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 109:
/* Line 868 of glr.c  */
#line 725 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 110:
/* Line 868 of glr.c  */
#line 726 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 111:
/* Line 868 of glr.c  */
#line 729 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "IS_NULL",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 112:
/* Line 868 of glr.c  */
#line 730 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "IS_NOT_NULL",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 113:
/* Line 868 of glr.c  */
#line 731 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "IS_BOOL",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 114:
/* Line 868 of glr.c  */
#line 732 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "IS_NOT_BOOL",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 115:
/* Line 868 of glr.c  */
#line 735 "sql.ypp"
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

    case 116:
/* Line 868 of glr.c  */
#line 738 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprList(
          AST_EXPR_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                              .yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 117:
/* Line 868 of glr.c  */
#line 739 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprList(
          AST_EXPR_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                              .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 118:
/* Line 868 of glr.c  */
#line 740 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 119:
/* Line 868 of glr.c  */
#line 743 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprList(
          AST_EXPR_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                              .yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 120:
/* Line 868 of glr.c  */
#line 744 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprList(
          AST_EXPR_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                              .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 121:
/* Line 868 of glr.c  */
#line 747 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCmpBinary(
          AST_EXPR_CMP_BINARY, "EXPR_IN_LIST",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (5))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 122:
/* Line 868 of glr.c  */
#line 748 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCmpBinary(
          AST_EXPR_CMP_BINARY, "LIST_IN_LIST",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (7))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((6) - (7))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 123:
/* Line 868 of glr.c  */
#line 749 "sql.ypp"
    {
      AstNode *tmp_node = new AstExprCmpBinary(
          AST_EXPR_CMP_BINARY, "EXPR_IN_LIST",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (6))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (6))].yystate.yysemantics.yysval.ast_node));
      ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "NOT", tmp_node);
    } break;

    case 124:
/* Line 868 of glr.c  */
#line 751 "sql.ypp"
    {
      AstNode *tmp_node = new AstExprCmpBinary(
          AST_EXPR_CMP_BINARY, "LIST_IN_LIST",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (8))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((7) - (8))].yystate.yysemantics.yysval.ast_node));
      ((*yyvalp).ast_node) = new AstExprUnary(AST_EXPR_UNARY, "NOT", tmp_node);
    } break;

    case 125:
/* Line 868 of glr.c  */
#line 753 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCmpBinary(
          AST_EXPR_CMP_BINARY, "EXPR_IN_SELECT",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (5))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 126:
/* Line 868 of glr.c  */
#line 754 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCmpBinary(
          AST_EXPR_CMP_BINARY, "LIST_IN_SELECT",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (7))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((6) - (7))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 127:
/* Line 868 of glr.c  */
#line 755 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCmpBinary(
          AST_EXPR_CMP_BINARY, "EXPR_NOT_IN_SELECT",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (6))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (6))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 128:
/* Line 868 of glr.c  */
#line 756 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCmpBinary(
          AST_EXPR_CMP_BINARY, "LIST_NOT_IN_SELECT",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (8))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((7) - (8))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 129:
/* Line 868 of glr.c  */
#line 758 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "EXSIST",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 130:
/* Line 868 of glr.c  */
#line 759 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "NOT_EXSIST",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 131:
/* Line 868 of glr.c  */
#line 769 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstExprUnary(AST_EXPR_UNARY, "COUNT_ALL", NULL);
    } break;

    case 132:
/* Line 868 of glr.c  */
#line 770 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "COUNT",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 133:
/* Line 868 of glr.c  */
#line 771 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "SUM",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 134:
/* Line 868 of glr.c  */
#line 772 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "AVG",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 135:
/* Line 868 of glr.c  */
#line 773 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "MIN",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 136:
/* Line 868 of glr.c  */
#line 774 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "MAX",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 137:
/* Line 868 of glr.c  */
#line 775 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "TO_CHAR",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 138:
/* Line 868 of glr.c  */
#line 776 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "TO_CHAR",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 139:
/* Line 868 of glr.c  */
#line 777 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "COUNT",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 140:
/* Line 868 of glr.c  */
#line 778 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "SUM",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 141:
/* Line 868 of glr.c  */
#line 779 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "AVG",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 142:
/* Line 868 of glr.c  */
#line 780 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "MIN",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 143:
/* Line 868 of glr.c  */
#line 781 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "MAX",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 144:
/* Line 868 of glr.c  */
#line 784 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "SUBSTRING_EXPR_EXPR",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (6))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (6))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 145:
/* Line 868 of glr.c  */
#line 785 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "SUBSTRING_EXPR_FROM_EXPR",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (6))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (6))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 146:
/* Line 868 of glr.c  */
#line 786 "sql.ypp"
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

    case 147:
/* Line 868 of glr.c  */
#line 787 "sql.ypp"
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

    case 148:
/* Line 868 of glr.c  */
#line 788 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "TRIM_BOTH", NULL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 149:
/* Line 868 of glr.c  */
#line 789 "sql.ypp"
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

    case 150:
/* Line 868 of glr.c  */
#line 790 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "UPPER",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 151:
/* Line 868 of glr.c  */
#line 791 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "CAST",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (6))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (6))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 152:
/* Line 868 of glr.c  */
#line 792 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "COALESCE",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 153:
/* Line 868 of glr.c  */
#line 795 "sql.ypp"
    {
      ((*yyvalp).strval) = "TRIM_LEADING";
    } break;

    case 154:
/* Line 868 of glr.c  */
#line 796 "sql.ypp"
    {
      ((*yyvalp).strval) = "TRIM_TRAILING";
    } break;

    case 155:
/* Line 868 of glr.c  */
#line 797 "sql.ypp"
    {
      ((*yyvalp).strval) = "TRIM_BOTH";
    } break;

    case 156:
/* Line 868 of glr.c  */
#line 800 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 157:
/* Line 868 of glr.c  */
#line 801 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "INT", NULL);
    } break;

    case 158:
/* Line 868 of glr.c  */
#line 802 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "STRING", NULL);
    } break;

    case 159:
/* Line 868 of glr.c  */
#line 803 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "DOUBLE", NULL);
    } break;

    case 160:
/* Line 868 of glr.c  */
#line 804 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "FLOAT", NULL);
    } break;

    case 161:
/* Line 868 of glr.c  */
#line 805 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "CHAR", NULL);
    } break;

    case 162:
/* Line 868 of glr.c  */
#line 808 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "DATE_ADD",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (6))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (6))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 163:
/* Line 868 of glr.c  */
#line 809 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "DATE_SUB",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (6))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (6))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 164:
/* Line 868 of glr.c  */
#line 813 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "INTERVAL_HOUR",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 165:
/* Line 868 of glr.c  */
#line 814 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "INTERVAL_MICROSECOND",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 166:
/* Line 868 of glr.c  */
#line 815 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "INTERVAL_MINUTE",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 167:
/* Line 868 of glr.c  */
#line 816 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "INTERVAL_SECOND",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 168:
/* Line 868 of glr.c  */
#line 817 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "INTERVAL_DAY",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 169:
/* Line 868 of glr.c  */
#line 818 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "INTERVAL_MONTH",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 170:
/* Line 868 of glr.c  */
#line 819 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "INTERVAL_YEAR",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 171:
/* Line 868 of glr.c  */
#line 820 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "INTERVAL_WEEK",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 172:
/* Line 868 of glr.c  */
#line 821 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "INTERVAL_QUARTER",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 173:
/* Line 868 of glr.c  */
#line 825 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "CASE1",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (4))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 174:
/* Line 868 of glr.c  */
#line 826 "sql.ypp"
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

    case 175:
/* Line 868 of glr.c  */
#line 827 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "CASE2", NULL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 176:
/* Line 868 of glr.c  */
#line 828 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "CASE2_ELSE", NULL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (5))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 177:
/* Line 868 of glr.c  */
#line 831 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "WHEN",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (4))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (4))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 178:
/* Line 868 of glr.c  */
#line 832 "sql.ypp"
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

    case 179:
/* Line 868 of glr.c  */
#line 835 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_CAL_BINARY, "LIKE",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 180:
/* Line 868 of glr.c  */
#line 836 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_CAL_BINARY, "NOT_LIKE",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (4))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 181:
/* Line 868 of glr.c  */
#line 839 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_CAL_BINARY, "REGEXP",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 182:
/* Line 868 of glr.c  */
#line 840 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprCalBinary(
          AST_EXPR_CAL_BINARY, "NOT_REGEXP",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (4))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 183:
/* Line 868 of glr.c  */
#line 846 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 184:
/* Line 868 of glr.c  */
#line 850 "sql.ypp"
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

    case 185:
/* Line 868 of glr.c  */
#line 851 "sql.ypp"
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

    case 186:
/* Line 868 of glr.c  */
#line 854 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 187:
/* Line 868 of glr.c  */
#line 855 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 188:
/* Line 868 of glr.c  */
#line 860 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 189:
/* Line 868 of glr.c  */
#line 864 "sql.ypp"
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

    case 190:
/* Line 868 of glr.c  */
#line 868 "sql.ypp"
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

    case 191:
/* Line 868 of glr.c  */
#line 873 "sql.ypp"
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

    case 192:
/* Line 868 of glr.c  */
#line 877 "sql.ypp"
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

    case 193:
/* Line 868 of glr.c  */
#line 882 "sql.ypp"
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

    case 194:
/* Line 868 of glr.c  */
#line 886 "sql.ypp"
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

    case 195:
/* Line 868 of glr.c  */
#line 890 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateSelect(
          AST_CREATE_SEL, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                               .yystate.yysemantics.yysval.intval),
          0, (((yyGLRStackItem const *)
               yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 196:
/* Line 868 of glr.c  */
#line 893 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 197:
/* Line 868 of glr.c  */
#line 894 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 198:
/* Line 868 of glr.c  */
#line 895 "sql.ypp"
    {
      ((*yyvalp).intval) = 2;
    } break;

    case 199:
/* Line 868 of glr.c  */
#line 898 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 200:
/* Line 868 of glr.c  */
#line 899 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 201:
/* Line 868 of glr.c  */
#line 902 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateColList(
          AST_CREATE_COL_LIST,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (1))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 202:
/* Line 868 of glr.c  */
#line 903 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateColList(
          AST_CREATE_COL_LIST,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 203:
/* Line 868 of glr.c  */
#line 908 "sql.ypp"
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

    case 204:
/* Line 868 of glr.c  */
#line 909 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateDef(
          AST_CREATE_DEF_PR_KEY, 2, "", NULL, NULL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 205:
/* Line 868 of glr.c  */
#line 910 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateDef(
          AST_CREATE_DEF_KEY, 3, "", NULL, NULL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 206:
/* Line 868 of glr.c  */
#line 911 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateDef(
          AST_CREATE_DEF_INDEX, 4, "", NULL, NULL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 207:
/* Line 868 of glr.c  */
#line 912 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateDef(
          AST_CREATE_DEF_FTEXT_INDEX, 5, "", NULL, NULL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 208:
/* Line 868 of glr.c  */
#line 913 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateDef(
          AST_CREATE_DEF_FTEXT_KEY, 6, "", NULL, NULL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 209:
/* Line 868 of glr.c  */
#line 915 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstColumnAtts(AST_COLUMN_ATTS, 0, 0, 0, "", NULL);
    } break;

    case 210:
/* Line 868 of glr.c  */
#line 916 "sql.ypp"
    {
      AstColumnAtts *temp = static_cast<AstColumnAtts *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node));
      temp->datatype_ |= 01;
      ((*yyvalp).ast_node) = temp;
    } break;

    case 211:
/* Line 868 of glr.c  */
#line 917 "sql.ypp"
    {
      AstColumnAtts *temp = static_cast<AstColumnAtts *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (2))].yystate.yysemantics.yysval.ast_node));
      temp->datatype_ |= 02;
      ((*yyvalp).ast_node) = temp;
    } break;

    case 212:
/* Line 868 of glr.c  */
#line 918 "sql.ypp"
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

    case 213:
/* Line 868 of glr.c  */
#line 919 "sql.ypp"
    {
      AstColumnAtts *temp = static_cast<AstColumnAtts *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node));
      temp->datatype_ |= 010;
      temp->int_num_ = atoi((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (3))]
                                 .yystate.yysemantics.yysval.strval));
      ((*yyvalp).ast_node) = temp;
    } break;

    case 214:
/* Line 868 of glr.c  */
#line 920 "sql.ypp"
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

    case 215:
/* Line 868 of glr.c  */
#line 921 "sql.ypp"
    {
      AstColumnAtts *temp = static_cast<AstColumnAtts *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node));
      temp->datatype_ |= 040;
      temp->int_num_ = atoi((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (3))]
                                 .yystate.yysemantics.yysval.strval));
      ((*yyvalp).ast_node) = temp;
    } break;

    case 216:
/* Line 868 of glr.c  */
#line 922 "sql.ypp"
    {
      AstColumnAtts *temp = static_cast<AstColumnAtts *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (2))].yystate.yysemantics.yysval.ast_node));
      temp->datatype_ |= 0100;
      ((*yyvalp).ast_node) = temp;
    } break;

    case 217:
/* Line 868 of glr.c  */
#line 923 "sql.ypp"
    {
      AstColumnAtts *temp = static_cast<AstColumnAtts *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node));
      temp->datatype_ |= 0200;
      ((*yyvalp).ast_node) = temp;
    } break;

    case 218:
/* Line 868 of glr.c  */
#line 924 "sql.ypp"
    {
      AstColumnAtts *temp = static_cast<AstColumnAtts *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node));
      temp->datatype_ |= 0400;
      ((*yyvalp).ast_node) = temp;
    } break;

    case 219:
/* Line 868 of glr.c  */
#line 925 "sql.ypp"
    {
      AstColumnAtts *temp = static_cast<AstColumnAtts *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (2))].yystate.yysemantics.yysval.ast_node));
      temp->datatype_ |= 01000;
      ((*yyvalp).ast_node) = temp;
    } break;

    case 220:
/* Line 868 of glr.c  */
#line 926 "sql.ypp"
    {
      AstColumnAtts *temp = static_cast<AstColumnAtts *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node));
      temp->datatype_ |= 02000;
      ((*yyvalp).ast_node) = temp;
    } break;

    case 221:
/* Line 868 of glr.c  */
#line 927 "sql.ypp"
    {
      AstColumnAtts *temp = static_cast<AstColumnAtts *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (5))].yystate.yysemantics.yysval.ast_node));
      temp->datatype_ |= 04000;
      temp->col_list_ = (((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (5))]
                             .yystate.yysemantics.yysval.ast_node);
      ((*yyvalp).ast_node) = temp;
    } break;

    case 222:
/* Line 868 of glr.c  */
#line 931 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 1, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (2))]
                                 .yystate.yysemantics.yysval.ast_node),
          0, NULL, 0, NULL);
    } break;

    case 223:
/* Line 868 of glr.c  */
#line 932 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 2, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                 .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.intval),
          NULL, 0, NULL);
    } break;

    case 224:
/* Line 868 of glr.c  */
#line 933 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 3, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                 .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.intval),
          NULL, 0, NULL);
    } break;

    case 225:
/* Line 868 of glr.c  */
#line 934 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 4, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                 .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.intval),
          NULL, 0, NULL);
    } break;

    case 226:
/* Line 868 of glr.c  */
#line 935 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 5, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                 .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.intval),
          NULL, 0, NULL);
    } break;

    case 227:
/* Line 868 of glr.c  */
#line 936 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 6, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                 .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.intval),
          NULL, 0, NULL);
    } break;

    case 228:
/* Line 868 of glr.c  */
#line 937 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 7, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                 .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.intval),
          NULL, 0, NULL);
    } break;

    case 229:
/* Line 868 of glr.c  */
#line 938 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 8, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                 .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.intval),
          NULL, 0, NULL);
    } break;

    case 230:
/* Line 868 of glr.c  */
#line 939 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 9, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                 .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.intval),
          NULL, 0, NULL);
    } break;

    case 231:
/* Line 868 of glr.c  */
#line 940 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 10, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                  .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.intval),
          NULL, 0, NULL);
    } break;

    case 232:
/* Line 868 of glr.c  */
#line 941 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 11, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                  .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.intval),
          NULL, 0, NULL);
    } break;

    case 233:
/* Line 868 of glr.c  */
#line 942 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstDataType(AST_DATA_TYPE, 12, NULL, 0, NULL, 0, NULL);
    } break;

    case 234:
/* Line 868 of glr.c  */
#line 943 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstDataType(AST_DATA_TYPE, 13, NULL, 0, NULL, 0, NULL);
    } break;

    case 235:
/* Line 868 of glr.c  */
#line 944 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstDataType(AST_DATA_TYPE, 14, NULL, 0, NULL, 0, NULL);
    } break;

    case 236:
/* Line 868 of glr.c  */
#line 945 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstDataType(AST_DATA_TYPE, 15, NULL, 0, NULL, 0, NULL);
    } break;

    case 237:
/* Line 868 of glr.c  */
#line 946 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstDataType(AST_DATA_TYPE, 16, NULL, 0, NULL, 0, NULL);
    } break;

    case 238:
/* Line 868 of glr.c  */
#line 947 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 17, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                  .yystate.yysemantics.yysval.ast_node),
          0, (((yyGLRStackItem const *)
               yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node),
          0, NULL);
    } break;

    case 239:
/* Line 868 of glr.c  */
#line 948 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 18, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                  .yystate.yysemantics.yysval.ast_node),
          0, (((yyGLRStackItem const *)
               yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node),
          0, NULL);
    } break;

    case 240:
/* Line 868 of glr.c  */
#line 949 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 19, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (2))]
                                  .yystate.yysemantics.yysval.ast_node),
          0, NULL, 0, NULL);
    } break;

    case 241:
/* Line 868 of glr.c  */
#line 950 "sql.ypp"
    {
      AstNode *temp = new AstOptLength(
          AST_OPT_LENGTH,
          atoi((((yyGLRStackItem const *)
                 yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.strval)),
          NULL);
      ((*yyvalp).ast_node) =
          new AstDataType(AST_DATA_TYPE, 20, temp, 0, NULL, 0, NULL);
    } break;

    case 242:
/* Line 868 of glr.c  */
#line 952 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstDataType(AST_DATA_TYPE, 21, NULL, 0, NULL, 0, NULL);
    } break;

    case 243:
/* Line 868 of glr.c  */
#line 953 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstDataType(AST_DATA_TYPE, 22, NULL, 0, NULL, 0, NULL);
    } break;

    case 244:
/* Line 868 of glr.c  */
#line 954 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstDataType(AST_DATA_TYPE, 23, NULL, 0, NULL, 0, NULL);
    } break;

    case 245:
/* Line 868 of glr.c  */
#line 955 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstDataType(AST_DATA_TYPE, 24, NULL, 0, NULL, 0, NULL);
    } break;

    case 246:
/* Line 868 of glr.c  */
#line 956 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 25, NULL, 0,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.intval),
          NULL);
    } break;

    case 247:
/* Line 868 of glr.c  */
#line 957 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 26, NULL, 0,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.intval),
          NULL);
    } break;

    case 248:
/* Line 868 of glr.c  */
#line 958 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 27, NULL, 0,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.intval),
          NULL);
    } break;

    case 249:
/* Line 868 of glr.c  */
#line 959 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 28, NULL, 0,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.intval),
          NULL);
    } break;

    case 250:
/* Line 868 of glr.c  */
#line 960 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 29, NULL, 0,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (5))].yystate.yysemantics.yysval.ast_node),
          0, (((yyGLRStackItem const *)
               yyvsp)[YYFILL((3) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 251:
/* Line 868 of glr.c  */
#line 961 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 30, NULL, 0,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (5))].yystate.yysemantics.yysval.ast_node),
          0, (((yyGLRStackItem const *)
               yyvsp)[YYFILL((3) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 252:
/* Line 868 of glr.c  */
#line 963 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstEnumList(
          AST_ENUM, string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                .yystate.yysemantics.yysval.strval)),
          NULL);
    } break;

    case 253:
/* Line 868 of glr.c  */
#line 964 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstEnumList(
          AST_ENUM_LIST,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (3))]
                      .yystate.yysemantics.yysval.strval)),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 254:
/* Line 868 of glr.c  */
#line 967 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 255:
/* Line 868 of glr.c  */
#line 968 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstOptLength(
          AST_OPT_LENGTH,
          atoi((((yyGLRStackItem const *)
                 yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.strval)),
          0);
    } break;

    case 256:
/* Line 868 of glr.c  */
#line 969 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstOptLength(
          AST_OPT_LENGTH,
          atoi((((yyGLRStackItem const *)
                 yyvsp)[YYFILL((2) - (5))].yystate.yysemantics.yysval.strval)),
          atoi((((yyGLRStackItem const *)
                 yyvsp)[YYFILL((4) - (5))].yystate.yysemantics.yysval.strval)));
    } break;

    case 257:
/* Line 868 of glr.c  */
#line 972 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 258:
/* Line 868 of glr.c  */
#line 973 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 259:
/* Line 868 of glr.c  */
#line 976 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 260:
/* Line 868 of glr.c  */
#line 977 "sql.ypp"
    {
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                .yystate.yysemantics.yysval.intval) |
                           01;
    } break;

    case 261:
/* Line 868 of glr.c  */
#line 978 "sql.ypp"
    {
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                .yystate.yysemantics.yysval.intval) |
                           02;
    } break;

    case 262:
/* Line 868 of glr.c  */
#line 981 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstOptCsc(AST_OPT_CSC, 0, "", "");
    } break;

    case 263:
/* Line 868 of glr.c  */
#line 983 "sql.ypp"
    {
      AstOptCsc *temp = static_cast<AstOptCsc *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (4))].yystate.yysemantics.yysval.ast_node));
      temp->data_type_ |= 01;
      temp->str1_ = string((((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (4))]
                                .yystate.yysemantics.yysval.strval));
      ((*yyvalp).ast_node) = temp;
    } break;

    case 264:
/* Line 868 of glr.c  */
#line 985 "sql.ypp"
    {
      AstOptCsc *temp = static_cast<AstOptCsc *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node));
      temp->data_type_ |= 02;
      temp->str2_ = string((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (3))]
                                .yystate.yysemantics.yysval.strval));
      ((*yyvalp).ast_node) = temp;
    } break;

    case 265:
/* Line 868 of glr.c  */
#line 989 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval
                                  .ast_node); /* puts("SQL parser： This is a
                                                 create_projection
                                                 statement");*/
    } break;

    case 266:
/* Line 868 of glr.c  */
#line 993 "sql.ypp"
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

    case 267:
/* Line 868 of glr.c  */
#line 995 "sql.ypp"
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

    case 268:
/* Line 868 of glr.c  */
#line 1002 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 269:
/* Line 868 of glr.c  */
#line 1007 "sql.ypp"
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

    case 270:
/* Line 868 of glr.c  */
#line 1010 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 271:
/* Line 868 of glr.c  */
#line 1011 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 272:
/* Line 868 of glr.c  */
#line 1012 "sql.ypp"
    {
      ((*yyvalp).intval) = 2;
    } break;

    case 273:
/* Line 868 of glr.c  */
#line 1013 "sql.ypp"
    {
      ((*yyvalp).intval) = 3;
    } break;

    case 274:
/* Line 868 of glr.c  */
#line 1016 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 275:
/* Line 868 of glr.c  */
#line 1017 "sql.ypp"
    {
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (2))]
                                .yystate.yysemantics.yysval.intval);
    } break;

    case 276:
/* Line 868 of glr.c  */
#line 1020 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 277:
/* Line 868 of glr.c  */
#line 1021 "sql.ypp"
    {
      ((*yyvalp).intval) = 2;
    } break;

    case 278:
/* Line 868 of glr.c  */
#line 1024 "sql.ypp"
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

    case 279:
/* Line 868 of glr.c  */
#line 1025 "sql.ypp"
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

    case 280:
/* Line 868 of glr.c  */
#line 1029 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 281:
/* Line 868 of glr.c  */
#line 1033 "sql.ypp"
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

    case 282:
/* Line 868 of glr.c  */
#line 1037 "sql.ypp"
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

    case 283:
/* Line 868 of glr.c  */
#line 1038 "sql.ypp"
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

    case 284:
/* Line 868 of glr.c  */
#line 1040 "sql.ypp"
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

    case 285:
/* Line 868 of glr.c  */
#line 1046 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 286:
/* Line 868 of glr.c  */
#line 1050 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExportTable(
          AST_EXPORT_TABLE,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (9))]
                      .yystate.yysemantics.yysval.strval)),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (9))].yystate.yysemantics.yysval.ast_node),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((7) - (9))]
                      .yystate.yysemantics.yysval.strval)),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((9) - (9))]
                      .yystate.yysemantics.yysval.strval)),
          NULL);

    } break;

    case 287:
/* Line 868 of glr.c  */
#line 1056 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExportTable(
          AST_EXPORT_TABLE, "",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (8))].yystate.yysemantics.yysval.ast_node),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((5) - (8))]
                      .yystate.yysemantics.yysval.strval)),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((7) - (8))]
                      .yystate.yysemantics.yysval.strval)),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((8) - (8))].yystate.yysemantics.yysval.ast_node));

    } break;

    case 288:
/* Line 868 of glr.c  */
#line 1062 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval
                                  .ast_node); /*output($$, 1); puts("SQL
                                                 parser： This is a drop_index
                                                 statement");*/
    } break;

    case 289:
/* Line 868 of glr.c  */
#line 1065 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDropIndex(
          AST_DROP_INDEX,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (5))]
                      .yystate.yysemantics.yysval.strval)),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((5) - (5))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 290:
/* Line 868 of glr.c  */
#line 1069 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval
                                  .ast_node); /* output($$, 1); puts("SQL
                                                 parser： This is a
                                                 drop_database statement");*/
    } break;

    case 291:
/* Line 868 of glr.c  */
#line 1073 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDropDatabase(
          AST_DROP_DB, 1, (((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (4))]
                               .yystate.yysemantics.yysval.intval),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (4))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 292:
/* Line 868 of glr.c  */
#line 1074 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDropDatabase(
          AST_DROP_SCHEMA, 2,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.intval),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (4))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 293:
/* Line 868 of glr.c  */
#line 1077 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 294:
/* Line 868 of glr.c  */
#line 1078 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 295:
/* Line 868 of glr.c  */
#line 1082 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval
                                  .ast_node); /*output($$, 1); puts("SQL
                                                 parser： This is a drop_table
                                                 statement"); */
    } break;

    case 296:
/* Line 868 of glr.c  */
#line 1086 "sql.ypp"
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

    case 297:
/* Line 868 of glr.c  */
#line 1089 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDropTableList(
          AST_DROP_TABLE_LIST, "",
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                      .yystate.yysemantics.yysval.strval)),
          NULL);
    } break;

    case 298:
/* Line 868 of glr.c  */
#line 1090 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDropTableList(
          AST_DROP_TABLE_LIST,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                      .yystate.yysemantics.yysval.strval)),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (3))]
                      .yystate.yysemantics.yysval.strval)),
          NULL);
    } break;

    case 299:
/* Line 868 of glr.c  */
#line 1091 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDropTableList(
          AST_DROP_TABLE_LIST, "",
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                      .yystate.yysemantics.yysval.strval)),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 300:
/* Line 868 of glr.c  */
#line 1092 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDropTableList(
          AST_DROP_TABLE_LIST,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (5))]
                      .yystate.yysemantics.yysval.strval)),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (5))]
                      .yystate.yysemantics.yysval.strval)),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 301:
/* Line 868 of glr.c  */
#line 1095 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 302:
/* Line 868 of glr.c  */
#line 1096 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 303:
/* Line 868 of glr.c  */
#line 1097 "sql.ypp"
    {
      ((*yyvalp).intval) = 2;
    } break;

    case 304:
/* Line 868 of glr.c  */
#line 1101 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval
                                  .ast_node); /*output($$, 1); puts("SQL
                                                 parser： This is a
                                                 drop_projection statement"); */
    } break;

    case 305:
/* Line 868 of glr.c  */
#line 1104 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDropProjection(
          AST_DROP_PROJECTION,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (4))]
                      .yystate.yysemantics.yysval.strval)),
          1, NULL);
    } break;

    case 306:
/* Line 868 of glr.c  */
#line 1106 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDropProjection(
          AST_DROP_PROJECTION,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((5) - (5))]
                      .yystate.yysemantics.yysval.strval)),
          0, atoi((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (5))]
                       .yystate.yysemantics.yysval.strval)));
    } break;

    case 307:
/* Line 868 of glr.c  */
#line 1112 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval
                                  .ast_node); /*output($$, 1); puts("SQL
                                                 parser： This is a truncate
                                                 statement"); */
    } break;

    case 308:
/* Line 868 of glr.c  */
#line 1115 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstTruncateTable(
          AST_TRUNCATE_TABLE,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node),
          "", "");
    } break;

    case 309:
/* Line 868 of glr.c  */
#line 1116 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstTruncateTable(
          AST_TRUNCATE_TABLE, NULL,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((5) - (5))]
                      .yystate.yysemantics.yysval.strval)),
          atoi((((yyGLRStackItem const *)
                 yyvsp)[YYFILL((3) - (5))].yystate.yysemantics.yysval.strval)));
    } break;

    case 310:
/* Line 868 of glr.c  */
#line 1121 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 311:
/* Line 868 of glr.c  */
#line 1127 "sql.ypp"
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

    case 312:
/* Line 868 of glr.c  */
#line 1130 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 313:
/* Line 868 of glr.c  */
#line 1131 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((5) - (5))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 314:
/* Line 868 of glr.c  */
#line 1134 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 315:
/* Line 868 of glr.c  */
#line 1135 "sql.ypp"
    {
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                .yystate.yysemantics.yysval.intval) |
                           01;
    } break;

    case 316:
/* Line 868 of glr.c  */
#line 1136 "sql.ypp"
    {
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                .yystate.yysemantics.yysval.intval) |
                           02;
    } break;

    case 317:
/* Line 868 of glr.c  */
#line 1137 "sql.ypp"
    {
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                .yystate.yysemantics.yysval.intval) |
                           04;
    } break;

    case 318:
/* Line 868 of glr.c  */
#line 1138 "sql.ypp"
    {
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                .yystate.yysemantics.yysval.intval) |
                           010;
    } break;

    case 321:
/* Line 868 of glr.c  */
#line 1144 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 322:
/* Line 868 of glr.c  */
#line 1145 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 323:
/* Line 868 of glr.c  */
#line 1148 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstInsertValList(
          AST_INSERT_VALUE_LIST,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 324:
/* Line 868 of glr.c  */
#line 1149 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstInsertValList(
          AST_INSERT_VALUE_LIST,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (5))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 325:
/* Line 868 of glr.c  */
#line 1153 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstInsertVals(
          AST_INSERT_VALUE, 0,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (1))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 326:
/* Line 868 of glr.c  */
#line 1154 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstInsertVals(AST_INSERT_VALUE, 1, NULL, NULL);
    } break;

    case 327:
/* Line 868 of glr.c  */
#line 1155 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstInsertVals(
          AST_INSERT_VALUE, 0,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 328:
/* Line 868 of glr.c  */
#line 1156 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstInsertVals(
          AST_INSERT_VALUE, 1, NULL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 329:
/* Line 868 of glr.c  */
#line 1160 "sql.ypp"
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

    case 330:
/* Line 868 of glr.c  */
#line 1164 "sql.ypp"
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

    case 331:
/* Line 868 of glr.c  */
#line 1168 "sql.ypp"
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

    case 332:
/* Line 868 of glr.c  */
#line 1171 "sql.ypp"
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

    case 333:
/* Line 868 of glr.c  */
#line 1174 "sql.ypp"
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

    case 334:
/* Line 868 of glr.c  */
#line 1177 "sql.ypp"
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

    case 335:
/* Line 868 of glr.c  */
#line 1182 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval
                                  .ast_node); /*output($$, 1); puts("SQL
                                                 parser： This is a show
                                                 statement");*/
    } break;

    case 336:
/* Line 868 of glr.c  */
#line 1185 "sql.ypp"
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

    case 337:
/* Line 868 of glr.c  */
#line 1186 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 338:
/* Line 868 of glr.c  */
#line 1187 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 339:
/* Line 868 of glr.c  */
#line 1188 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 340:
/* Line 868 of glr.c  */
#line 1189 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 341:
/* Line 868 of glr.c  */
#line 1190 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 342:
/* Line 868 of glr.c  */
#line 1191 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 343:
/* Line 868 of glr.c  */
#line 1192 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 344:
/* Line 868 of glr.c  */
#line 1193 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 345:
/* Line 868 of glr.c  */
#line 1194 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 346:
/* Line 868 of glr.c  */
#line 1195 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 347:
/* Line 868 of glr.c  */
#line 1196 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 348:
/* Line 868 of glr.c  */
#line 1197 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 349:
/* Line 868 of glr.c  */
#line 1198 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 350:
/* Line 868 of glr.c  */
#line 1199 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 351:
/* Line 868 of glr.c  */
#line 1200 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 352:
/* Line 868 of glr.c  */
#line 1201 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 353:
/* Line 868 of glr.c  */
#line 1202 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 354:
/* Line 868 of glr.c  */
#line 1203 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 355:
/* Line 868 of glr.c  */
#line 1204 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 356:
/* Line 868 of glr.c  */
#line 1205 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 357:
/* Line 868 of glr.c  */
#line 1206 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 358:
/* Line 868 of glr.c  */
#line 1207 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 359:
/* Line 868 of glr.c  */
#line 1208 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 360:
/* Line 868 of glr.c  */
#line 1209 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 361:
/* Line 868 of glr.c  */
#line 1210 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 362:
/* Line 868 of glr.c  */
#line 1211 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 363:
/* Line 868 of glr.c  */
#line 1213 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 364:
/* Line 868 of glr.c  */
#line 1217 "sql.ypp"
    {
      ((*yyvalp).intval) = NULL;
    } break;

    case 365:
/* Line 868 of glr.c  */
#line 1218 "sql.ypp"
    {
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (2))]
                                .yystate.yysemantics.yysval.strval);
    } break;

    case 366:
/* Line 868 of glr.c  */
#line 1221 "sql.ypp"
    {
      ((*yyvalp).strval) = NULL;
    } break;

    case 367:
/* Line 868 of glr.c  */
#line 1222 "sql.ypp"
    {
      ((*yyvalp).strval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (2))]
                                .yystate.yysemantics.yysval.strval);
    } break;

    case 372:
/* Line 868 of glr.c  */
#line 1232 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 373:
/* Line 868 of glr.c  */
#line 1233 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 374:
/* Line 868 of glr.c  */
#line 1234 "sql.ypp"
    {
      ((*yyvalp).intval) = 2;
    } break;

    case 375:
/* Line 868 of glr.c  */
#line 1237 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDescStmt(
          AST_DESC_STMT, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (2))]
                              .yystate.yysemantics.yysval.strval));
    } break;

    case 376:
/* Line 868 of glr.c  */
#line 1240 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 377:
/* Line 868 of glr.c  */
#line 1244 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDeleteStmt(
          AST_DELETE_STMT, (((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (7))]
                                .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (7))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (7))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 378:
/* Line 868 of glr.c  */
#line 1248 "sql.ypp"
    {
      emit("DELETEMULTI %d %d %d",
           (((yyGLRStackItem const *)
             yyvsp)[YYFILL((2) - (7))].yystate.yysemantics.yysval.ast_node),
           (((yyGLRStackItem const *)
             yyvsp)[YYFILL((4) - (7))].yystate.yysemantics.yysval.ast_node),
           (((yyGLRStackItem const *)
             yyvsp)[YYFILL((6) - (7))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 379:
/* Line 868 of glr.c  */
#line 1253 "sql.ypp"
    {
    } break;

    case 380:
/* Line 868 of glr.c  */
#line 1256 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                  .yystate.yysemantics.yysval.ast_node) +
                             01;
    } break;

    case 381:
/* Line 868 of glr.c  */
#line 1257 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                  .yystate.yysemantics.yysval.ast_node) +
                             02;
    } break;

    case 382:
/* Line 868 of glr.c  */
#line 1258 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                  .yystate.yysemantics.yysval.ast_node) +
                             04;
    } break;

    case 383:
/* Line 868 of glr.c  */
#line 1259 "sql.ypp"
    {
      ((*yyvalp).ast_node) = 0;
    } break;

    case 384:
/* Line 868 of glr.c  */
#line 1263 "sql.ypp"
    {
    } break;

    case 385:
/* Line 868 of glr.c  */
#line 1264 "sql.ypp"
    {
    } break;

    case 388:
/* Line 868 of glr.c  */
#line 1271 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 389:
/* Line 868 of glr.c  */
#line 1274 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstUpdateStmt(
          AST_UPDATE_STMT, (((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (5))]
                                .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (5))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 390:
/* Line 868 of glr.c  */
#line 1277 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstUpdateSetList(
          AST_UPDATE_SET_LIST,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 391:
/* Line 868 of glr.c  */
#line 1278 "sql.ypp"
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
#line 4798 "sql.tab.cpp"
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

#define yypact_value_is_default(Yystate) (!!((Yystate) == (-519)))

/** True iff LR state STATE has only a default reduction (regardless
 *  of token).  */
static inline yybool yyisDefaultedState(yyStateNum yystate) {
  return yypact_value_is_default(yypact[yystate]);
}

/** The default reduction for STATE, assuming it has one.  */
static inline yyRuleNum yydefaultAction(yyStateNum yystate) {
  return yydefact[yystate];
}

#define yytable_value_is_error(Yytable_value) (!!((Yytable_value) == (-392)))

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
#line 1281 "sql.ypp"

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
