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
#include "../ast_node/ast_union_stmt.h"

void yyerror(struct ParseResult *pp, const char *s, ...);
void emit(char *s, ...);

/* Line 207 of glr.c  */
#line 88 "sql.tab.cpp"

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
#line 49 "sql.ypp"

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
#line 134 "sql.tab.cpp"

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
#define YYFINAL 113
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST 2774

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS 344
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS 92
/* YYNRULES -- Number of rules.  */
#define YYNRULES 394
/* YYNRULES -- Number of states.  */
#define YYNSTATES 861
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
    1030, 1034, 1036, 1040, 1044, 1046, 1057, 1071, 1073, 1084, 1085, 1087,
    1089, 1091, 1092, 1095, 1097, 1099, 1103, 1109, 1111, 1124, 1134, 1144,
    1157, 1159, 1169, 1178, 1180, 1186, 1188, 1193, 1198, 1199, 1202, 1204,
    1211, 1213, 1217, 1221, 1227, 1228, 1230, 1232, 1234, 1239, 1245, 1247,
    1251, 1257, 1259, 1268, 1269, 1275, 1276, 1279, 1282, 1285, 1288, 1290,
    1291, 1292, 1296, 1300, 1306, 1308, 1310, 1314, 1318, 1326, 1334, 1338,
    1342, 1348, 1354, 1356, 1362, 1366, 1374, 1379, 1384, 1389, 1393, 1397,
    1402, 1407, 1411, 1415, 1419, 1424, 1430, 1434, 1438, 1444, 1447, 1451,
    1456, 1462, 1467, 1472, 1477, 1481, 1485, 1486, 1487, 1490, 1491, 1494,
    1495, 1498, 1499, 1501, 1502, 1504, 1506, 1509, 1511, 1519, 1527, 1534,
    1537, 1540, 1543, 1544, 1547, 1552, 1553, 1556, 1558, 1564, 1568};

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
    -1,  347, 229, 347, -1,  347, 229, 398, -1,  399, -1,  62,  173, 160, 3,
    341, 358, 342, 169, 160, 3,   -1,  62,  173, 160, 3,   341, 358, 342, 159,
    20,  5,   169, 160, 3,   -1,  400, -1,  62,  401, 120, 3,   402, 160, 3,
    341, 404, 342, -1,  -1,  230, -1,  110, -1,  203, -1,  -1,  236, 403, -1,
    321, -1,  322, -1,  3,   394, 351, -1,  3,   394, 351, 340, 404, -1,  405,
    -1,  140, 215, 3,   108, 377, 247, 4,   340, 4,   191, 20,  7,   -1,  140,
    215, 3,   108, 377, 247, 4,   340, 4,   -1,  38,  215, 3,   108, 377, 247,
    4,   340, 4,   -1,  38,  215, 3,   108, 377, 247, 4,   340, 4,   191, 20,
    7,   -1,  406, -1,  102, 215, 3,   129, 377, 247, 4,   340, 4,   -1,  102,
    129, 377, 247, 4,   340, 4,   347, -1,  407, -1,  90,  120, 3,   160, 3,
    -1,  408, -1,  90,  69,  409, 3,   -1,  90,  192, 409, 3,   -1,  -1,  118,
    99,  -1,  410, -1,  90,  388, 215, 409, 411, 412, -1,  3,   -1,  3,   343,
    3,   -1,  3,   340, 411, -1,  3,   343, 3,   340, 411, -1,  -1,  186, -1,
    50,  -1,  413, -1,  90,  173, 108, 3,   -1,  90,  173, 5,   108, 3,   -1,
    414, -1,  259, 215, 411, -1,  259, 173, 5,   108, 3,   -1,  415, -1,  125,
    417, 418, 3,   419, 240, 420, 416, -1,  -1,  160, 161, 132, 233, 422, -1,
    -1,  417, 148, -1,  417, 81,  -1,  417, 114, -1,  417, 119, -1,  129, -1,
    -1,  -1,  341, 358, 342, -1,  341, 421, 342, -1,  341, 421, 342, 340, 420,
    -1,  376, -1,  80,  -1,  376, 340, 421, -1,  80,  340, 421, -1,  125, 417,
    418, 3,   198, 422, 416, -1,  125, 417, 418, 3,   419, 347, 416, -1,  3,
    20,  376, -1,  3,   20,  80,  -1,  422, 340, 3,   20,  376, -1,  422, 340,
    3,   20,  80,  -1,  423, -1,  199, 424, 279, 425, 426, -1,  199, 297, 426,
    -1,  199, 424, 298, 108, 3,   425, 426, -1,  199, 62,  69,  3,   -1,  199,
    62,  192, 3,   -1,  199, 62,  215, 3,   -1,  199, 69,  3,   -1,  199, 192,
    3,   -1,  199, 299, 3,   300, -1,  199, 299, 3,   301, -1,  199, 302, 303,
    -1,  199, 304, 356, -1,  199, 376, 304, -1,  199, 305, 105, 8,   -1,  199,
    120, 108, 3,   425, -1,  199, 306, 301, -1,  199, 428, 300, -1,  199, 324,
    279, 425, 426, -1,  199, 290, -1,  199, 424, 307, -1,  199, 429, 301, 426,
    -1,  199, 215, 301, 425, 426, -1,  199, 296, 198, 426, -1,  199, 308, 425,
    427, -1,  199, 429, 309, 426, -1,  199, 310, 356, -1,  199, 376, 310, -1,
    -1,  -1,  108, 3,   -1,  -1,  14,  4,   -1,  -1,  14,  376, -1,  -1,  323,
    -1,  -1,  282, -1,  283, -1,  83,  3,   -1,  430, -1,  82,  431, 108, 363,
    348, 354, 356, -1,  82,  431, 108, 432, 236, 363, 348, -1,  82,  431, 432,
    108, 363, 348, -1,  431, 148, -1,  431, 175, -1,  431, 119, -1,  -1,  3,
    433, -1,  432, 340, 3,   433, -1,  -1,  343, 26,  -1,  434, -1,  233, 365,
    198, 435, 348, -1,  376, 20,  376, -1,  435, 340, 376, 20,  376, -1};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] = {
    0,    451,  451,  465,  478,  487,  499,  508,  516,  517,  520,  521,
    526,  527,  529,  530,  531,  534,  535,  538,  539,  542,  543,  546,
    547,  549,  550,  551,  554,  555,  556,  564,  565,  580,  581,  582,
    583,  584,  588,  589,  593,  594,  595,  599,  602,  603,  607,  608,
    612,  614,  616,  617,  620,  621,  624,  625,  626,  641,  642,  643,
    644,  645,  648,  649,  650,  653,  654,  658,  659,  660,  664,  665,
    666,  667,  670,  671,  679,  680,  685,  692,  693,  694,  695,  696,
    697,  698,  699,  701,  702,  703,  704,  705,  706,  708,  709,  711,
    712,  713,  715,  716,  717,  718,  719,  721,  722,  723,  724,  726,
    727,  728,  729,  732,  733,  734,  735,  738,  741,  742,  743,  746,
    747,  750,  751,  752,  754,  756,  757,  758,  759,  761,  762,  772,
    773,  774,  775,  776,  777,  778,  779,  780,  781,  782,  783,  784,
    787,  788,  789,  790,  791,  792,  793,  794,  795,  798,  799,  800,
    803,  804,  805,  806,  807,  808,  811,  812,  816,  817,  818,  819,
    820,  821,  822,  823,  824,  828,  829,  830,  831,  834,  835,  838,
    839,  842,  843,  849,  853,  854,  857,  858,  863,  866,  870,  874,
    879,  883,  888,  892,  896,  897,  898,  901,  902,  905,  906,  911,
    912,  913,  914,  915,  916,  918,  919,  920,  921,  922,  923,  924,
    925,  926,  927,  928,  929,  930,  934,  935,  936,  937,  938,  939,
    940,  941,  942,  943,  944,  945,  946,  947,  948,  949,  950,  951,
    952,  953,  955,  956,  957,  958,  959,  960,  961,  962,  963,  964,
    966,  967,  970,  971,  972,  975,  976,  979,  980,  981,  984,  985,
    987,  990,  993,  997,  1004, 1007, 1009, 1017, 1021, 1025, 1026, 1027,
    1028, 1031, 1032, 1035, 1036, 1039, 1040, 1044, 1047, 1052, 1053, 1054,
    1061, 1064, 1070, 1077, 1080, 1084, 1088, 1089, 1092, 1093, 1097, 1100,
    1104, 1105, 1106, 1107, 1110, 1111, 1112, 1116, 1119, 1120, 1127, 1130,
    1131, 1136, 1139, 1145, 1146, 1149, 1150, 1151, 1152, 1153, 1156, 1156,
    1159, 1160, 1163, 1164, 1168, 1169, 1170, 1171, 1174, 1178, 1183, 1186,
    1189, 1192, 1197, 1200, 1201, 1202, 1203, 1204, 1205, 1206, 1207, 1208,
    1209, 1210, 1211, 1212, 1213, 1214, 1215, 1216, 1217, 1218, 1219, 1220,
    1221, 1222, 1223, 1224, 1225, 1226, 1228, 1232, 1233, 1236, 1237, 1240,
    1241, 1243, 1244, 1247, 1248, 1249, 1252, 1255, 1257, 1262, 1266, 1271,
    1272, 1273, 1274, 1278, 1279, 1282, 1283, 1286, 1289, 1292, 1293};
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
    "union_stmt",               "create_projection_stmt",
    "create_index_stmt",        "index_att",
    "opt_using_type",           "index_type",
    "index_col_list",           "load_table_stmt",
    "export_table_stmt",        "drop_index_stmt",
    "drop_database_stmt",       "opt_if_exists",
    "drop_table_stmt",          "table_list",
    "opt_rc",                   "drop_projection_stmt",
    "truncate_table_stmt",      "insert_stmt",
    "opt_ondupupdate",          "insert_opts",
    "opt_into",                 "opt_col_names",
    "insert_vals_list",         "insert_vals",
    "insert_asgn_list",         "show_stmt",
    "opt_full",                 "opt_from",
    "opt_like_string",          "opt_like_expr",
    "opt_bdb",                  "opt_trans_level",
    "delete_stmt",              "delete_opts",
    "delete_list",              "opt_dot_star",
    "update_stmt",              "update_set_list",
    YY_NULL};
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
    399, 346, 400, 401, 401, 401, 401, 402, 402, 403, 403, 404, 404, 346, 405,
    405, 405, 405, 346, 406, 406, 346, 407, 346, 408, 408, 409, 409, 346, 410,
    411, 411, 411, 411, 412, 412, 412, 346, 413, 413, 346, 414, 414, 346, 415,
    416, 416, 417, 417, 417, 417, 417, 418, 418, 419, 419, 420, 420, 421, 421,
    421, 421, 415, 415, 422, 422, 422, 422, 346, 423, 423, 423, 423, 423, 423,
    423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423, 423,
    423, 423, 423, 423, 423, 423, 424, 425, 425, 426, 426, 427, 427, 428, 428,
    429, 429, 429, 346, 346, 430, 430, 430, 431, 431, 431, 431, 432, 432, 433,
    433, 346, 434, 435, 435};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] = {
    0, 2,  2, 3, 2, 3,  1,  11, 0,  2, 0, 4, 1, 3, 0,  1, 1, 0,  2, 0, 2,  0,
    3, 2,  4, 0, 2, 4,  0,  5,  8,  1, 3, 0, 1, 5, 1,  2, 1, 3,  1, 3, 1,  2,
    1, 3,  1, 1, 2, 4,  3,  3,  0,  1, 2, 1, 0, 5, 3,  5, 6, 5,  0, 1, 1,  0,
    1, 1,  1, 1, 2, 2,  2,  0,  0,  1, 2, 4, 3, 1, 1,  3, 3, 1,  1, 1, 1,  3,
    3, 3,  3, 3, 3, 2,  2,  3,  3,  3, 3, 5, 6, 6, 6,  3, 3, 3,  3, 2, 2,  3,
    3, 3,  4, 3, 4, 5,  1,  3,  3,  1, 3, 5, 7, 6, 8,  5, 7, 6,  8, 4, 5,  4,
    4, 4,  4, 4, 4, 4,  4,  4,  4,  4, 4, 4, 6, 6, 8,  8, 4, 7,  4, 6, 4,  1,
    1, 1,  0, 1, 1, 1,  1,  1,  6,  6, 3, 3, 3, 3, 3,  3, 3, 3,  3, 4, 6,  3,
    5, 4,  5, 3, 4, 3,  4,  1,  4,  4, 0, 3, 1, 8, 10, 9, 6, 11, 8, 3, 0,  1,
    1, 0,  1, 1, 3, 3,  5,  4,  4,  5, 5, 0, 3, 2, 3,  3, 3, 3,  2, 3, 3,  2,
    3, 5,  2, 3, 3, 3,  3,  3,  3,  3, 3, 3, 3, 1, 1,  1, 1, 1,  3, 3, 2,  4,
    1, 1,  1, 1, 3, 3,  3,  3,  5,  5, 1, 3, 0, 3, 5,  0, 1, 0,  2, 2, 0,  4,
    3, 1,  3, 3, 1, 10, 13, 1,  10, 0, 1, 1, 1, 0, 2,  1, 1, 3,  5, 1, 12, 9,
    9, 12, 1, 9, 8, 1,  5,  1,  4,  4, 0, 2, 1, 6, 1,  3, 3, 5,  0, 1, 1,  1,
    4, 5,  1, 3, 5, 1,  8,  0,  5,  0, 2, 2, 2, 2, 1,  0, 0, 3,  3, 5, 1,  1,
    3, 3,  7, 7, 3, 3,  5,  5,  1,  5, 3, 7, 4, 4, 4,  3, 3, 4,  4, 3, 3,  3,
    4, 5,  3, 3, 5, 2,  3,  4,  5,  4, 4, 4, 3, 3, 0,  0, 2, 0,  2, 0, 2,  0,
    1, 0,  1, 1, 2, 1,  7,  7,  6,  2, 2, 2, 0, 2, 4,  0, 2, 1,  5, 3, 5};

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
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

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
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

/* YYDEFACT[S] -- default reduction number in state S.  Performed when
   YYTABLE doesn't specify something else to do.  Zero means the default
   is an error.  */
static const unsigned short int yydefact[] = {
    0,   0,   0,   199, 386, 0,   199, 0,   317, 0,   33,  366, 0,   0,   0,
    0,   6,   183, 188, 265, 268, 271, 283, 288, 291, 293, 298, 307, 310, 313,
    338, 379, 391, 4,   0,   186, 275, 0,   186, 276, 200, 274, 0,   0,   0,
    378, 296, 0,   0,   296, 0,   0,   0,   323, 0,   36,  34,  0,   79,  83,
    84,  86,  85,  80,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    376, 377, 357, 0,   369, 0,   0,   25,  0,   0,   367, 25,  374, 0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   56,  0,   0,   52,  0,   0,   1,   0,   0,   0,   0,   0,   0,
    0,   0,   186, 0,   389, 0,   385, 383, 384, 0,   0,   0,   0,   0,   0,
    0,   296, 0,   116, 0,   0,   319, 320, 321, 322, 318, 0,   0,   0,   37,
    38,  42,  28,  40,  56,  0,   0,   107, 0,   108, 94,  93,  0,   0,   0,
    0,   0,   0,   345, 0,   0,   346, 367, 369, 0,   340, 0,   349, 0,   350,
    0,   354, 0,   371, 364, 367, 0,   0,   0,   0,   33,  0,   0,   0,   33,
    33,  33,  33,  33,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   351, 365, 367, 0,
    358, 355, 369, 369, 55,  0,   0,   48,  0,   0,   44,  46,  47,  0,   53,
    0,   0,   300, 311, 5,   0,   266, 267, 0,   0,   184, 0,   185, 0,   277,
    0,   387, 56,  8,   0,   0,   0,   297, 294, 0,   0,   308, 295, 0,   0,
    0,   0,   0,   324, 0,   0,   0,   0,   0,   0,   43,  81,  82,  109, 0,
    0,   0,   0,   175, 0,   342, 343, 344, 0,   367, 369, 361, 370, 347, 348,
    26,  352, 368, 0,   362, 369, 0,   155, 153, 154, 0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    110, 0,   96,  97,  95,  181, 179, 113, 0,   111, 0,   0,   0,   0,   0,
    0,   0,   0,   0,   98,  103, 104, 106, 87,  88,  89,  90,  92,  91,  105,
    369, 0,   359, 363, 54,  56,  78,  51,  64,  69,  63,  67,  73,  68,  0,
    0,   0,   65,  0,   8,   50,  0,   0,   0,   0,   187, 0,   196, 0,   0,
    390, 0,   0,   21,  0,   8,   389, 292, 309, 304, 118, 117, 0,   0,   0,
    0,   0,   0,   0,   39,  0,   0,   41,  0,   0,   0,   173, 0,   0,   129,
    353, 360, 0,   372, 356, 0,   0,   148, 0,   0,   0,   131, 139, 132, 150,
    156, 152, 140, 133, 141, 134, 142, 135, 143, 136, 138, 137, 0,   0,   114,
    112, 0,   0,   182, 180, 0,   0,   0,   0,   0,   0,   339, 367, 49,  65,
    65,  65,  0,   58,  45,  0,   66,  0,   0,   0,   392, 312, 302, 301, 0,
    31,  0,   197, 198, 0,   0,   192, 52,  279, 280, 278, 0,   9,   0,   25,
    8,   382, 388, 306, 305, 299, 0,   0,   0,   315, 0,   0,   315, 0,   35,
    0,   0,   8,   129, 177, 0,   176, 0,   27,  0,   0,   0,   0,   0,   0,
    158, 161, 159, 160, 157, 0,   0,   0,   125, 121, 0,   0,   115, 0,   0,
    0,   99,  369, 72,  70,  71,  0,   0,   74,  0,   98,  0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   201, 196, 0,   0,   0,   380, 381, 0,
    0,   0,   0,   0,   332, 325, 0,   315, 333, 0,   0,   0,   10,  174, 178,
    0,   145, 0,   144, 0,   0,   162, 163, 151, 0,   119, 0,   0,   127, 123,
    102, 100, 101, 341, 61,  59,  0,   0,   57,  75,  0,   0,   303, 0,   32,
    0,   0,   254, 254, 254, 243, 254, 233, 236, 254, 254, 0,   254, 254, 254,
    245, 257, 244, 254, 257, 254, 0,   254, 257, 234, 235, 242, 254, 257, 0,
    254, 237, 209, 0,   0,   0,   0,   0,   196, 0,   0,   194, 195, 0,   22,
    14,  290, 0,   335, 334, 0,   0,   329, 328, 0,   314, 0,   0,   29,  0,
    19,  0,   0,   149, 164, 168, 165, 166, 167, 172, 170, 169, 171, 126, 0,
    122, 0,   0,   76,  0,   60,  98,  286, 0,   0,   0,   259, 240, 222, 262,
    259, 259, 0,   259, 259, 259, 258, 262, 259, 262, 259, 0,   259, 262, 259,
    262, 0,   262, 203, 0,   0,   0,   0,   0,   191, 202, 0,   254, 0,   15,
    16,  23,  289, 0,   0,   0,   0,   326, 285, 0,   0,   0,   21,  147, 146,
    120, 128, 124, 0,   0,   0,   269, 0,   228, 238, 232, 230, 252, 0,   231,
    226, 227, 249, 225, 248, 229, 0,   224, 247, 223, 246, 0,   239, 0,   216,
    0,   0,   219, 211, 0,   0,   0,   0,   206, 205, 0,   196, 14,  272, 0,
    0,   337, 336, 331, 330, 0,   0,   0,   17,  12,  20,  25,  77,  0,   0,
    0,   255, 260, 261, 0,   0,   0,   262, 262, 241, 210, 220, 212, 213, 215,
    214, 218, 217, 0,   207, 208, 204, 193, 281, 24,  316, 327, 0,   30,  0,
    11,  0,   7,   287, 0,   0,   0,   264, 253, 250, 251, 0,   0,   284, 18,
    13,  270, 256, 263, 221, 282};

/* YYPDEFGOTO[NTERM-NUM].  */
static const short int yydefgoto[] = {
    -1,  14,  15,  16,  393, 675, 803, 736, 840, 747, 494, 659, 179, 278,
    481, 57,  149, 152, 153, 234, 235, 236, 240, 232, 237, 376, 472, 377,
    467, 608, 609, 110, 138, 200, 596, 311, 530, 523, 164, 17,  119, 18,
    486, 487, 42,  561, 562, 723, 647, 763, 701, 712, 758, 759, 19,  20,
    21,  43,  389, 490, 733, 22,  23,  24,  25,  131, 26,  243, 500, 27,
    28,  29,  574, 53,  146, 406, 577, 669, 504, 30,  104, 183, 175, 304,
    105, 106, 31,  44,  129, 256, 32,  379};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -571
static const short int yypact[] = {
    2095, -241, -94,  296,  -571, 124,  99,   -81,  -571, -84,  16,   781,
    11,   -121, 103,  -202, -56,  -571, -571, -571, -571, -571, -571, -571,
    -571, -571, -571, -571, -571, -571, -571, -571, -571, -571, 186,  107,
    -571, 86,   107,  -571, -571, -571, 48,   146,  121,  -571, 159,  271,
    35,   159,  75,   1384, 291,  156,  298,  -571, 943,  973,  -30,  -571,
    -571, -571, -571, 317,  1412, 1441, 1412, 1412, 998,  -18,  302,  -5,
    227,  335,  40,   -571, -571, -571, 142,  344,  361,  67,   231,  266,
    71,   265,  231,  -571, 96,   37,   38,   64,   72,   77,   85,   87,
    88,   89,   90,   91,   95,   97,   1384, 1152, -197, 76,   -186, 0,
    25,   191,  368,  403,  409,  -571, 98,   459,  244,  336,  429,  443,
    458,  462,  107,  467,  128,  26,   -571, -571, -571, -101, 373,  473,
    318,  371,  478,  480,  159,  1384, 1959, 237,  356,  -571, -571, -571,
    -571, -571, 489,  387,  162,  -571, 1980, -571, 375,  167,  2612, 66,
    1412, 1031, 168,  1031, -571, -571, 1412, 2203, -32,  505,  510,  511,
    -571, 244,  513,  -571, 265,  344,  514,  -571, -58,  -571, 1412, -571,
    509,  -571, 516,  506,  -571, 265,  1412, 19,   1412, 1412, 416,  1412,
    1412, 1384, 859,  859,  859,  859,  859,  1113, 180,  1412, 1412, 1412,
    1412, 1412, 53,   183,  119,  1412, 820,  1412, 1412, 1412, 1412, 1412,
    1412, 1412, 1412, 1412, 1412, -571, -571, 265,  417,  -571, -571, 344,
    344,  -571, 529,  530,  -571, 192,  193,  -42,  -571, -571, 1412, -571,
    534,  430,  -194, -571, -571, 316,  -56,  -571, 1384, 440,  -571, 203,
    -571, 542,  310,  521,  -571, -1,   303,  -204, 11,   547,  -571, -571,
    548,  549,  -571, -571, 409,  211,  1384, 550,  1384, -120, 1384, 1412,
    1412, 11,   448,  973,  -571, -571, -571, 2683, 244,  2226, -21,  1412,
    -571, 1412, -571, -571, -571, 216,  265,  344,  -571, -571, -571, -571,
    2001, -571, -571, 1412, -571, 344,  372,  -571, -571, -571, 1592, 1412,
    2022, 2043, 220,  221,  1613, 1634, 2634, 222,  224,  1655, 225,  1773,
    226,  1800, 228,  1821, 233,  1842, -571, 210,  1501, 2744, 2247, 2405,
    2405, -571, 12,   -571, 1022, 1412, 1412, 236,  2656, 238,  239,  240,
    1022, 564,  428,  620,  642,  188,  188,  539,  539,  539,  539,  -571,
    344,  570,  -571, -571, -571, 78,   -571, -571, -571, -571, -571, -571,
    -51,  -571, 11,   11,   447,  415,  2704, -212, -571, 594,  409,  595,
    354,  -571, 599,  -110, -3,   444,  -571, 82,   1412, 438,  11,   303,
    128,  -571, -571, -15,  210,  -571, 293,  364,  631,  599,  -135, 388,
    294,  -571, -82,  11,   -571, 295,  1412, 1412, -571, 2504, 2387, -571,
    -571, -571, 1412, 2683, -571, 1412, 1412, -571, 2483, 512,  512,  -571,
    -571, -571, -571, 321,  -571, -571, -571, -571, -571, -571, -571, -571,
    -571, -571, -571, 311,  623,  -571, -571, 314,  315,  2405, 2405, 1022,
    1412, 244,  244,  244,  319,  -571, 265,  -571, 415,  415,  415,  528,
    500,  -571, 11,   -571, 531,  820,  1412, -571, -571, -571, 323,  660,
    334,  331,  -571, -571, 163,  677,  -571, 368,  -571, -571, -571, 678,
    2683, 634,  231,  303,  -571, -571, -571, -571, -571, 679,  680,  666,
    -144, 345,  347,  533,  685,  -571, 670,  536,  303,  602,  2683, 2525,
    -571, 1412, 2683, 1475, 1571, 1412, 1412, 349,  352,  -571, -571, -571,
    -571, -571, 355,  1022, 358,  -571, -571, 360,  362,  1447, 363,  366,
    367,  -571, 344,  -571, -571, -571, 11,   1412, -95,  11,   135,  2725,
    409,  376,  599,  -76,  2243, -44,  359,  365,  571,  377,  380,  -100,
    244,  381,  1412, -571, -571, 244,  383,  1207, 552,  714,  -571, -571,
    1232, 533,  -571, 385,  721,  724,  624,  -571, 2683, 1412, -571, 1412,
    -571, 1863, 2125, -571, -571, -571, 390,  397,  396,  1022, -571, -571,
    -571, -571, -571, -571, -571, 2683, 1412, 408,  -571, -571, -54,  820,
    -571, 751,  -571, 736,  600,  418,  418,  418,  -571, 418,  -571, -571,
    418,  418,  420,  418,  418,  418,  -571, 719,  -571, 418,  719,  418,
    423,  418,  719,  -571, -571, -571, 418,  719,  424,  418,  -571, -571,
    427,  431,  599,  599,  432,  -88,  163,  163,  -571, -571, 763,  -571,
    2546, -571, 765,  -571, 2683, 638,  754,  435,  2064, 434,  -571, 767,
    608,  -571, 731,  667,  1917, 1938, -571, -571, -571, -571, -571, -571,
    -571, -571, -571, -571, -571, 1384, -571, 439,  450,  2683, 599,  -571,
    232,  591,  785,  790,  789,  -571, -571, -571, -571, -571, -571, 791,
    -571, -571, -571, -571, -571, -571, -571, -571, 791,  -571, -571, -571,
    -571, 792,  -571, 425,  599,  599,  454,  460,  599,  -571, -571, 461,
    418,  465,  -571, -571, 464,  -571, 567,  1361, 1232, 1232, 468,  610,
    649,  1412, 1412, 438,  -571, -571, -571, -571, -571, 469,  793,  641,
    -571, -43,  -142, 253,  -142, -142, -571, -31,  -142, -142, -142, 253,
    -142, 253,  -142, -28,  -142, 253,  -142, 253,  470,  253,  656,  -571,
    811,  275,  -571, -571, 686,  -117, 475,  477,  -571, -571, 487,  -72,
    39,   -571, 1412, 631,  -571, 2683, -571, -571, 347,  800,  819,  586,
    2098, 2683, 231,  -571, 827,  675,  831,  -571, -571, -571, 643,  836,
    838,  -571, -571, -571, -571, -571, -571, -571, -571, -571, -571, -571,
    599,  -571, -571, -571, -571, 508,  -571, 515,  -571, 833,  -571, 668,
    -571, 1412, -571, -571, 853,  517,  857,  -571, -571, 253,  253,  519,
    763,  -571, -571, -571, -571, -571, -571, -571, -571};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] = {
    -571, 753,  -571, -96,  -282, -571, 28,   80,   -571, -571, 123,  79,
    -85,  -571, -401, 333,  46,   596,  -571, -91,  -571, -6,   391,  -143,
    -571, -571, -178, -571, -571, -571, 264,  -571, -11,  -38,  190,  -571,
    -571, 451,  722,  -571, 3,    -571, -553, -571, 876,  -326, -571, -571,
    -571, 170,  1546, -527, -219, -570, 771,  -571, -571, -571, -571, -571,
    36,   -571, -571, -571, -571, -7,   -571, -263, -571, -571, -571, -571,
    -457, -571, -571, -571, 93,   -408, 94,   -571, -571, -155, -165, -571,
    -571, -571, -571, -571, 766,  494,  -571, -571};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -395
static const short int yytable[] = {
    103,  184,  229,  229,  505,  399,  109,  260,  296,  482,  656,  280,
    233,  139,  107,  827,  572,  295,  449,  482,  246,  368,  58,   59,
    60,   61,   62,   63,   107,  257,  305,  482,  394,  392,  258,  498,
    64,   65,   230,  230,  133,  121,  135,  66,   67,   150,  154,  482,
    51,   55,   578,  165,  111,  157,  159,  160,  161,  163,  464,  337,
    10,   287,  362,  363,  288,  606,  307,  369,  360,  281,  68,   338,
    415,  293,  483,  416,  648,  510,  404,  734,  370,  229,  223,  615,
    483,  365,  465,  511,  649,  -62,  812,  199,  282,  616,  112,  371,
    483,  475,  33,   269,  729,  224,  56,   113,  114,  506,  606,  714,
    390,  813,  225,  718,  483,  496,  372,  227,  720,  230,  71,   477,
    670,  34,   735,  228,  124,  253,  199,  45,   474,  268,  421,  54,
    341,  342,  52,   343,  261,  115,  466,  420,  424,  607,  767,  134,
    769,  283,  382,  373,  773,  383,  775,  285,  777,  614,  308,  319,
    211,  212,  213,  214,  215,  216,  217,  218,  219,  220,  556,  300,
    46,   395,  450,  499,  374,  116,  166,  306,  310,  312,  313,  316,
    317,  318,  607,  321,  323,  325,  327,  329,  413,  117,  332,  333,
    334,  335,  336,  461,  573,  167,  344,  349,  350,  351,  352,  353,
    354,  355,  356,  357,  358,  359,  384,  339,  289,  568,  216,  217,
    218,  219,  220,  47,   10,   405,  463,  289,  828,  118,  447,  378,
    448,  125,  582,  484,  401,  485,  403,  -389, 407,  141,  832,  261,
    126,  655,  298,  299,  451,  309,  120,  849,  850,  726,  727,  -189,
    460,  211,  212,  213,  214,  215,  216,  217,  218,  219,  220,  122,
    150,  150,  123,  -190, 154,  127,  142,  410,  48,   557,  132,  143,
    417,  130,  418,  822,  823,  824,  825,  558,  469,  144,  543,  544,
    545,  612,  136,  49,   423,  753,  140,  559,  128,  810,  375,  811,
    428,  147,  452,  495,  145,  168,  814,  542,  815,  816,  507,  817,
    816,  155,  818,  40,   -3,   114,  488,  489,  512,  408,  409,  786,
    787,  525,  156,  790,  730,  731,  453,  454,  798,  799,  560,  170,
    169,  199,  171,  -56,  173,  172,  391,  231,  89,   90,   91,   92,
    93,   94,   95,   96,   108,  97,   98,   99,   100,  101,  174,  535,
    102,  538,  539,  540,  176,  35,   108,  108,  468,  178,  177,  180,
    181,  182,  526,  185,  226,  603,  186,  187,  -393, 492,  201,  202,
    203,  204,  205,  206,  207,  238,  208,  209,  210,  211,  212,  213,
    214,  215,  216,  217,  218,  219,  220,  514,  515,  188,  36,   239,
    241,  567,  527,  518,  242,  189,  519,  520,  -273, 536,  190,  58,
    59,   60,   61,   62,   63,   528,  191,  851,  192,  193,  194,  195,
    196,  64,   65,   594,  197,  244,  198,  10,   66,   67,   314,  778,
    248,  537,  250,  249,  529,  55,   212,  213,  214,  215,  216,  217,
    218,  219,  220,  -2,   1,    251,  550,  551,  548,  252,  779,  68,
    657,  37,   254,  255,  262,  661,  -393, -393, 263,  -394, 264,  265,
    425,  266,  780,  267,  271,  272,  760,  761,  38,   764,  765,  766,
    273,  595,  768,  274,  770,  2,    772,  39,   774,  691,  56,   275,
    277,  781,  584,  279,  290,  284,  589,  590,  40,   291,  292,  71,
    294,  301,  297,  302,  303,  3,    331,  315,  340,  361,  41,   320,
    322,  324,  326,  328,  364,  365,  366,  367,  605,  380,  381,  385,
    604,  4,    5,    610,  386,  387,  388,  390,  392,  6,    396,  397,
    398,  400,  402,  660,  411,  782,  419,  692,  664,  7,    431,  432,
    436,  668,  437,  439,  441,  220,  443,  -394, -394, 462,  676,  445,
    677,  455,  470,  457,  458,  459,  471,  783,  8,    211,  212,  213,
    214,  215,  216,  217,  218,  219,  220,  693,  784,  476,  478,  9,
    696,  479,  480,  493,  491,  -129, -129, -129, -129, -129, -129, 502,
    -129, -129, -129, -129, -129, -129, -129, -129, -129, -129, -129, -129,
    -129, -129, -129, -129, -129, -129, -129, -129, -129, 501,  503,  508,
    509,  513,  -129, 532,  522,  -129, -129, 213,  214,  215,  216,  217,
    218,  219,  220,  595,  531,  -129, 10,   785,  533,  534,  11,   546,
    547,  541,  549,  552,  553,  -129, 214,  215,  216,  217,  218,  219,
    220,  555,  554,  -129, -129, -129, -129, -129, 563,  565,  566,  569,
    570,  -129, 571,  575,  576,  579,  580,  591,  12,   572,  592,  -129,
    581,  593,  -129, 597,  650,  -129, 598,  652,  599,  600,  651,  -129,
    601,  602,  -129, -129, 426,  665,  -129, -129, 613,  666,  13,   653,
    654,  842,  658,  662,  -129, 671,  672,  673,  797,  668,  668,  -129,
    688,  -129, 804,  805,  674,  689,  690,  -129, -129, 89,   90,   91,
    92,   93,   94,   95,   96,   694,  97,   98,   99,   100,  101,  697,
    698,  102,  -129, 700,  699,  707,  -129, 711,  716,  721,  732,  -129,
    724,  737,  738,  743,  725,  728,  739,  740,  742,  744,  -129, 745,
    746,  751,  754,  660,  58,   59,   60,   61,   62,   63,   755,  -129,
    752,  756,  757,  762,  788,  776,  64,   65,   795,  801,  789,  791,
    794,  66,   67,   793,  800,  802,  809,  807,  819,  808,  820,  821,
    -129, 829,  826,  830,  837,  -129, 838,  58,   59,   60,   61,   62,
    63,   831,  804,  -129, 68,   839,  843,  844,  845,  64,   65,   847,
    853,  846,  848,  69,   66,   67,   -129, -129, 852,  -129, 70,   -129,
    -129, 345,  -129, 573,  856,  346,  854,  857,  858,  859,  58,   59,
    60,   61,   62,   63,   245,  855,  806,  68,   833,  834,  695,  412,
    64,   65,   564,  750,  71,   524,  50,   66,   67,   286,  771,  247,
    860,  835,  497,  259,  55,   836,  0,    0,    0,    0,    0,    0,
    0,    72,   0,    0,    0,    0,    -129, 0,    0,    0,    68,   0,
    -129, 0,    0,    0,    0,    0,    0,    71,   0,    0,    0,    0,
    0,    0,    0,    -129, -129, -129, -129, -129, -129, -129, -129, 0,
    -129, -129, -129, -129, -129, -129, -129, -129, -129, 56,   58,   59,
    60,   61,   62,   63,   0,    0,    0,    0,    0,    0,    71,   0,
    64,   65,   0,    0,    0,    0,    0,    66,   67,   0,    0,    0,
    0,    73,   0,    0,    58,   59,   60,   61,   62,   63,   0,    0,
    0,    0,    0,    0,    0,    0,    64,   65,   0,    0,    68,   0,
    74,   66,   67,   151,  0,    58,   59,   60,   61,   62,   63,   0,
    0,    0,    0,    0,    0,    0,    0,    64,   65,   0,    0,    0,
    0,    347,  66,   67,   68,   58,   59,   60,   61,   62,   63,   0,
    0,    0,    0,    0,    0,    0,    0,    64,   65,   0,    71,   0,
    0,    0,    66,   67,   0,    68,   209,  210,  211,  212,  213,  214,
    215,  216,  217,  218,  219,  220,  0,    75,   76,   0,    0,    0,
    0,    0,    0,    77,   71,   68,   0,    0,    0,    78,   79,   0,
    80,   -373, -375, 81,   0,    82,   83,   84,   0,    85,   -375, 86,
    0,    0,    0,    0,    0,    71,   0,    0,    0,    0,    0,    148,
    87,   88,   89,   90,   91,   92,   93,   94,   95,   96,   0,    97,
    98,   99,   100,  101,  0,    71,   102,  201,  202,  203,  204,  205,
    206,  207,  0,    208,  209,  210,  211,  212,  213,  214,  215,  216,
    217,  218,  219,  220,  0,    89,   90,   91,   92,   93,   94,   95,
    96,   0,    97,   98,   99,   100,  101,  0,    0,    348,  201,  202,
    203,  204,  205,  206,  207,  0,    208,  209,  210,  211,  212,  213,
    214,  215,  216,  217,  218,  219,  220,  0,    89,   90,   91,   92,
    93,   94,   95,   96,   0,    97,   98,   99,   100,  101,  0,    0,
    102,  0,    0,    0,    0,    0,    0,    0,    0,    0,    58,   59,
    60,   61,   62,   63,   0,    10,   0,    0,    0,    0,    0,    0,
    64,   65,   0,    0,    0,    0,    0,    66,   67,   0,    0,    58,
    59,   60,   61,   62,   63,   0,    162,  0,    0,    0,    0,    0,
    0,    64,   65,   0,    0,    0,    0,    0,    66,   67,   68,   0,
    0,    0,    0,    0,    0,    0,    0,    0,    89,   90,   91,   92,
    93,   94,   95,   96,   0,    97,   98,   99,   100,  101,  0,    68,
    102,  0,    0,    663,  0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    89,   90,   91,   92,   93,   94,   95,   96,   71,   97,
    98,   99,   100,  101,  667,  0,    102,  0,    0,    0,    0,    0,
    0,    0,    0,    89,   90,   91,   92,   93,   94,   95,   96,   71,
    97,   98,   99,   100,  101,  0,    0,    102,  0,    0,    0,    0,
    0,    0,    0,    89,   90,   91,   92,   93,   94,   95,   96,   0,
    97,   98,   99,   100,  101,  0,    0,    137,  58,   59,   60,   61,
    62,   63,   0,    0,    0,    0,    0,    0,    0,    0,    64,   65,
    0,    0,    0,    0,    0,    66,   67,   58,   59,   60,   61,   62,
    63,   0,    0,    0,    0,    0,    0,    0,    0,    64,   65,   0,
    0,    0,    0,    0,    66,   67,   0,    0,    68,   0,    0,    58,
    59,   60,   61,   62,   63,   0,    0,    0,    0,    0,    0,    0,
    0,    64,   65,   0,    0,    0,    0,    68,   66,   67,   0,    0,
    0,    796,  0,    0,    58,   59,   60,   61,   62,   63,   0,    0,
    0,    270,  0,    330,  221,  0,    64,   65,   71,   0,    222,  68,
    0,    66,   67,   210,  211,  212,  213,  214,  215,  216,  217,  218,
    219,  220,  0,    0,    0,    0,    0,    71,   0,    201,  202,  203,
    204,  205,  206,  207,  68,   208,  209,  210,  211,  212,  213,  214,
    215,  216,  217,  218,  219,  220,  0,    0,    0,    0,    0,    71,
    202,  203,  204,  205,  206,  207,  0,    208,  209,  210,  211,  212,
    213,  214,  215,  216,  217,  218,  219,  220,  89,   90,   91,   92,
    93,   94,   95,   96,   158,  97,   98,   99,   100,  101,  0,    0,
    102,  0,    0,    0,    0,    0,    0,    0,    0,    89,   90,   91,
    92,   93,   94,   95,   96,   0,    97,   98,   99,   100,  101,  0,
    0,    102,  0,    0,    0,    0,    0,    0,    585,  201,  202,  203,
    204,  205,  206,  207,  0,    208,  209,  210,  211,  212,  213,  214,
    215,  216,  217,  218,  219,  220,  201,  202,  203,  204,  205,  206,
    207,  0,    208,  209,  210,  211,  212,  213,  214,  215,  216,  217,
    218,  219,  220,  201,  202,  203,  204,  205,  206,  207,  0,    208,
    209,  210,  211,  212,  213,  214,  215,  216,  217,  218,  219,  220,
    201,  202,  203,  204,  205,  206,  207,  0,    208,  209,  210,  211,
    212,  213,  214,  215,  216,  217,  218,  219,  220,  201,  202,  203,
    204,  205,  206,  207,  0,    208,  209,  210,  211,  212,  213,  214,
    215,  216,  217,  218,  219,  220,  89,   90,   91,   92,   93,   94,
    95,   96,   0,    97,   98,   99,   100,  101,  0,    0,    102,  0,
    0,    0,    0,    0,    0,    89,   90,   91,   92,   93,   94,   95,
    96,   0,    97,   98,   99,   100,  101,  0,    0,    137,  0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    89,   90,   91,
    92,   93,   94,   95,   96,   0,    97,   98,   99,   100,  101,  0,
    0,    102,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    89,   90,   91,   92,   93,   94,   95,   96,   0,    97,
    98,   99,   100,  101,  0,    0,    102,  201,  202,  203,  204,  205,
    206,  207,  0,    208,  209,  210,  211,  212,  213,  214,  215,  216,
    217,  218,  219,  220,  0,    0,    0,    0,    0,    0,    201,  202,
    203,  204,  205,  206,  207,  586,  208,  209,  210,  211,  212,  213,
    214,  215,  216,  217,  218,  219,  220,  201,  202,  203,  204,  205,
    206,  207,  0,    208,  209,  210,  211,  212,  213,  214,  215,  216,
    217,  218,  219,  220,  201,  202,  203,  204,  205,  206,  207,  0,
    208,  209,  210,  211,  212,  213,  214,  215,  216,  217,  218,  219,
    220,  201,  202,  203,  204,  205,  206,  207,  0,    208,  209,  210,
    211,  212,  213,  214,  215,  216,  217,  218,  219,  220,  0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    587,  0,    588,  0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    201,  202,  203,  204,  205,
    206,  207,  427,  208,  209,  210,  211,  212,  213,  214,  215,  216,
    217,  218,  219,  220,  201,  202,  203,  204,  205,  206,  207,  433,
    208,  209,  210,  211,  212,  213,  214,  215,  216,  217,  218,  219,
    220,  201,  202,  203,  204,  205,  206,  207,  434,  208,  209,  210,
    211,  212,  213,  214,  215,  216,  217,  218,  219,  220,  201,  202,
    203,  204,  205,  206,  207,  438,  208,  209,  210,  211,  212,  213,
    214,  215,  216,  217,  218,  219,  220,  201,  202,  203,  204,  205,
    206,  207,  0,    208,  209,  210,  211,  212,  213,  214,  215,  216,
    217,  218,  219,  220,  201,  202,  203,  204,  205,  206,  207,  0,
    208,  209,  210,  211,  212,  213,  214,  215,  216,  217,  218,  219,
    220,  201,  202,  203,  204,  205,  206,  207,  0,    208,  209,  210,
    211,  212,  213,  214,  215,  216,  217,  218,  219,  220,  201,  202,
    203,  204,  205,  206,  207,  0,    208,  209,  210,  211,  212,  213,
    214,  215,  216,  217,  218,  219,  220,  0,    1,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    201,  202,  203,  204,
    205,  206,  207,  440,  208,  209,  210,  211,  212,  213,  214,  215,
    216,  217,  218,  219,  220,  0,    0,    0,    0,    2,    0,    201,
    202,  203,  204,  205,  206,  207,  442,  208,  209,  210,  211,  212,
    213,  214,  215,  216,  217,  218,  219,  220,  0,    3,    0,    0,
    0,    0,    0,    444,  702,  703,  0,    704,  0,    0,    705,  706,
    0,    708,  709,  710,  0,    4,    5,    713,  0,    715,  0,    717,
    446,  6,    0,    0,    719,  0,    0,    722,  0,    0,    0,    0,
    0,    7,    679,  680,  681,  682,  683,  0,    0,    678,  0,    0,
    0,    0,    0,    0,    0,    201,  202,  203,  204,  205,  206,  207,
    8,    208,  209,  210,  211,  212,  213,  214,  215,  216,  217,  218,
    219,  220,  0,    9,    201,  202,  203,  204,  205,  206,  207,  0,
    208,  209,  210,  211,  212,  213,  214,  215,  216,  217,  218,  219,
    220,  0,    0,    748,  204,  205,  206,  207,  0,    208,  209,  210,
    211,  212,  213,  214,  215,  216,  217,  218,  219,  220,  792,  0,
    749,  0,    0,    0,    0,    0,    617,  618,  619,  620,  10,   0,
    0,    0,    11,   0,    621,  0,    0,    270,  0,    684,  0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    622,  623,
    0,    0,    0,    0,    276,  624,  0,    0,    0,    0,    0,    0,
    12,   0,    0,    0,    625,  0,    0,    0,    0,    0,    0,    0,
    626,  422,  0,    0,    0,    0,    0,    627,  0,    0,    0,    0,
    0,    0,    13,   0,    0,    0,    0,    0,    0,    0,    429,  0,
    0,    0,    0,    0,    0,    628,  629,  0,    0,    0,    685,  686,
    0,    687,  0,    0,    0,    0,    0,    430,  0,    0,    0,    0,
    630,  631,  0,    0,    0,    632,  633,  634,  0,    201,  202,  203,
    204,  205,  206,  207,  741,  208,  209,  210,  211,  212,  213,  214,
    215,  216,  217,  218,  219,  220,  -395, -395, -395, -395, 635,  208,
    209,  210,  211,  212,  213,  214,  215,  216,  217,  218,  219,  220,
    0,    0,    841,  0,    0,    636,  0,    637,  0,    414,  0,    162,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    638,  0,    0,    639,  640,  641,  642,  643,  0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    644,  645,  0,    0,    0,    0,    0,    0,    646,  201,  202,  203,
    204,  205,  206,  207,  0,    208,  209,  210,  211,  212,  213,  214,
    215,  216,  217,  218,  219,  220,  201,  202,  203,  204,  205,  206,
    207,  0,    208,  209,  210,  211,  212,  213,  214,  215,  216,  217,
    218,  219,  220,  201,  202,  203,  204,  205,  206,  207,  0,    208,
    209,  210,  211,  212,  213,  214,  215,  216,  217,  218,  219,  220,
    201,  202,  203,  204,  205,  206,  207,  0,    208,  209,  210,  211,
    212,  213,  214,  215,  216,  217,  218,  219,  220,  0,    0,    0,
    0,    0,    0,    0,    0,    0,    734,  0,    0,    0,    0,    521,
    0,    0,    0,    0,    0,    0,    0,    0,    516,  0,    0,    0,
    0,    0,    517,  0,    0,    0,    0,    0,    0,    0,    0,    229,
    0,    0,    0,    0,    0,    583,  201,  202,  203,  204,  205,  206,
    207,  735,  208,  209,  210,  211,  212,  213,  214,  215,  216,  217,
    218,  219,  220,  0,    201,  202,  203,  204,  205,  206,  207,  230,
    208,  209,  210,  211,  212,  213,  214,  215,  216,  217,  218,  219,
    220,  0,    201,  202,  203,  204,  205,  206,  207,  435,  208,  209,
    210,  211,  212,  213,  214,  215,  216,  217,  218,  219,  220,  0,
    0,    0,    0,    0,    456,  201,  202,  203,  204,  205,  206,  207,
    0,    208,  209,  210,  211,  212,  213,  214,  215,  216,  217,  218,
    219,  220,  201,  202,  203,  204,  205,  206,  207,  0,    208,  209,
    473,  211,  212,  213,  214,  215,  216,  217,  218,  219,  220,  201,
    202,  203,  204,  205,  206,  207,  0,    208,  209,  611,  211,  212,
    213,  214,  215,  216,  217,  218,  219,  220,  203,  204,  205,  206,
    207,  0,    208,  209,  210,  211,  212,  213,  214,  215,  216,  217,
    218,  219,  220};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const unsigned char yyconflp[] = {
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   241, 0,   0,   0,   0,   0,   0,   0,   0,   0,
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
    0,   0,   67,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   69,  0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   53,  0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   73,  75,  77,  79,  81,  83,  0,   85,  87,  89,
    91,  93,  95,  97,  99,  101, 103, 105, 107, 109, 111, 113, 115, 117, 119,
    121, 123, 125, 0,   0,   0,   0,   0,   127, 0,   0,   129, 131, 0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   133, 0,   0,   0,   0,   0,   0,
    71,  0,   0,   0,   0,   135, 0,   0,   0,   0,   0,   0,   0,   0,   0,
    137, 139, 141, 143, 145, 0,   0,   0,   0,   0,   147, 0,   0,   0,   0,
    0,   0,   0,   0,   0,   149, 0,   0,   151, 0,   0,   153, 0,   0,   0,
    0,   0,   155, 0,   0,   157, 159, 0,   0,   161, 163, 0,   0,   0,   0,
    0,   0,   0,   0,   165, 0,   0,   0,   0,   0,   0,   167, 0,   169, 0,
    0,   0,   0,   0,   171, 173, 0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   175, 0,   0,   0,   177, 0,   0,
    0,   0,   179, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   181, 0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   183, 0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   185, 0,   0,   0,   0,   187, 0,   0,   0,
    0,   0,   0,   0,   0,   0,   189, 0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   191, 193, 0,   195, 0,   197, 199, 0,   201,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   203, 0,   0,   0,   0,   0,   205, 0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   207, 209, 211,
    213, 215, 217, 219, 221, 0,   223, 225, 227, 229, 231, 233, 235, 237, 239,
    0,   1,   3,   5,   7,   9,   11,  0,   0,   0,   0,   0,   0,   0,   0,
    13,  15,  0,   0,   0,   0,   0,   17,  19,  0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   21,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   23,  0,   0,   0,   0,   0,   0,   0,
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
    0,   0,   0,   0,   0,   0,   0,   0,   25,  27,  29,  31,  33,  35,  37,
    39,  0,   41,  43,  45,  47,  49,  0,   0,   51,  0,   0,   0,   0,   0,
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
    65,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
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
    0,   0,   0,   57,  0,   0,   0,   0,   0,   59,  61,  63,  0,   0,   0,
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
    0,   0,   0,   0,   55,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
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
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short int yyconfl[] = {
    0, 34,  0, 34,  0, 34,  0, 34,  0, 34,  0, 34,  0, 34,  0, 34,  0, 34,
    0, 34,  0, 34,  0, 34,  0, 34,  0, 34,  0, 34,  0, 34,  0, 34,  0, 34,
    0, 34,  0, 34,  0, 34,  0, 34,  0, 34,  0, 34,  0, 34,  0, 34,  0, 2,
    0, 116, 0, 38,  0, 38,  0, 38,  0, 38,  0, 116, 0, 3,   0, 389, 0, 58,
    0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130,
    0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130,
    0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130,
    0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130,
    0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130,
    0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130,
    0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130,
    0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130,
    0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130, 0, 130,
    0, 130, 0, 130, 0, 130, 0, 74,  0};

static const short int yycheck[] = {
    11,  86,  3,   3,   405, 268, 12,  108, 173, 119, 563, 154, 108, 51,  3,
    132, 160, 172, 6,   119, 116, 63,  3,   4,   5,   6,   7,   8,   3,   3,
    185, 119, 236, 245, 125, 50,  17,  18,  39,  39,  5,   38,  49,  24,  25,
    56,  57,  119, 129, 33,  507, 69,  173, 64,  65,  66,  67,  68,  109, 6,
    195, 93,  227, 228, 96,  160, 47,  109, 223, 3,   51,  18,  93,  169, 184,
    96,  120, 159, 198, 40,  122, 3,   279, 159, 184, 3,   137, 169, 132, 131,
    232, 102, 26,  169, 215, 137, 184, 379, 339, 137, 653, 298, 86,  0,   1,
    240, 160, 634, 26,  251, 307, 638, 184, 395, 156, 301, 643, 39,  99,  382,
    577, 215, 83,  309, 3,   122, 137, 3,   340, 136, 295, 215, 13,  14,  215,
    16,  340, 339, 189, 294, 305, 236, 712, 108, 714, 156, 340, 189, 718, 343,
    720, 162, 722, 554, 135, 193, 21,  22,  23,  24,  25,  26,  27,  28,  29,
    30,  3,   178, 69,  260, 158, 186, 214, 229, 192, 186, 187, 188, 189, 190,
    191, 192, 236, 194, 195, 196, 197, 198, 284, 3,   201, 202, 203, 204, 205,
    360, 340, 215, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220,
    248, 158, 244, 495, 26,  27,  28,  29,  30,  120, 195, 341, 365, 244, 341,
    118, 16,  238, 18,  108, 512, 341, 270, 343, 272, 236, 274, 81,  791, 340,
    119, 341, 300, 301, 340, 226, 160, 817, 818, 650, 651, 339, 348, 21,  22,
    23,  24,  25,  26,  27,  28,  29,  30,  215, 275, 276, 120, 339, 279, 148,
    114, 277, 173, 110, 3,   119, 287, 118, 289, 4,   5,   6,   7,   120, 375,
    129, 464, 465, 466, 552, 215, 192, 303, 694, 3,   132, 175, 340, 340, 342,
    311, 3,   340, 394, 148, 3,   53,  462, 55,  340, 406, 342, 340, 343, 342,
    216, 0,   1,   321, 322, 411, 275, 276, 724, 725, 4,   9,   728, 654, 655,
    341, 342, 740, 741, 171, 108, 341, 348, 3,   340, 198, 301, 343, 343, 325,
    326, 327, 328, 329, 330, 331, 332, 341, 334, 335, 336, 337, 338, 14,  455,
    341, 457, 458, 459, 3,   69,  341, 341, 374, 138, 303, 105, 301, 108, 53,
    279, 300, 542, 341, 341, 245, 392, 10,  11,  12,  13,  14,  15,  16,  198,
    18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  414, 415,
    341, 110, 39,  5,   494, 89,  422, 3,   341, 425, 426, 120, 455, 341, 3,
    4,   5,   6,   7,   8,   104, 341, 828, 341, 341, 341, 341, 341, 17,  18,
    531, 341, 339, 341, 195, 24,  25,  26,  18,  108, 456, 3,   18,  127, 33,
    22,  23,  24,  25,  26,  27,  28,  29,  30,  0,   1,   3,   473, 474, 470,
    3,   41,  51,  564, 173, 3,   343, 99,  569, 339, 340, 3,   245, 160, 108,
    108, 3,   57,  3,   247, 129, 705, 706, 192, 708, 709, 710, 3,   531, 713,
    108, 715, 38,  717, 203, 719, 597, 86,  341, 129, 80,  517, 340, 3,   341,
    521, 522, 216, 3,   3,   99,  3,   8,   4,   3,   14,  62,  342, 190, 341,
    108, 230, 194, 195, 196, 197, 198, 3,   3,   342, 342, 547, 3,   108, 99,
    546, 82,  83,  549, 341, 3,   236, 26,  245, 90,  3,   3,   3,   342, 4,
    566, 108, 132, 342, 597, 571, 102, 342, 342, 342, 576, 342, 342, 342, 30,
    342, 339, 340, 3,   585, 342, 587, 341, 131, 341, 341, 341, 167, 158, 125,
    21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  606, 171, 3,   3,   140,
    611, 247, 3,   165, 160, 3,   4,   5,   6,   7,   8,   247, 10,  11,  12,
    13,  14,  15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,
    28,  29,  30,  340, 3,   247, 342, 342, 36,  16,  128, 39,  40,  23,  24,
    25,  26,  27,  28,  29,  30,  689, 341, 51,  195, 230, 342, 342, 199, 131,
    160, 342, 131, 340, 4,   63,  24,  25,  26,  27,  28,  29,  30,  342, 340,
    73,  74,  75,  76,  77,  3,   3,   48,  4,   4,   83,  20,  342, 341, 4,
    20,  342, 233, 160, 342, 93,  160, 342, 96,  341, 341, 99,  342, 132, 342,
    342, 341, 105, 342, 342, 108, 109, 340, 161, 112, 113, 340, 3,   259, 342,
    340, 806, 341, 340, 122, 340, 5,   3,   739, 740, 741, 129, 342, 131, 745,
    746, 112, 340, 342, 137, 138, 325, 326, 327, 328, 329, 330, 331, 332, 341,
    334, 335, 336, 337, 338, 4,   20,  341, 156, 341, 160, 341, 160, 44,  341,
    341, 3,   165, 341, 4,   132, 4,   341, 341, 20,  340, 342, 169, 176, 48,
    113, 342, 191, 794, 3,   4,   5,   6,   7,   8,   5,   189, 342, 3,   5,
    4,   342, 5,   17,  18,  233, 191, 342, 342, 340, 24,  25,  342, 340, 160,
    169, 342, 342, 20,  158, 4,   214, 342, 132, 342, 20,  219, 3,   3,   4,
    5,   6,   7,   8,   342, 841, 229, 51,  247, 7,   160, 5,   17,  18,  3,
    7,   198, 4,   62,  24,  25,  244, 245, 340, 247, 69,  249, 250, 33,  252,
    340, 3,   37,  190, 342, 3,   342, 3,   4,   5,   6,   7,   8,   115, 841,
    747, 51,  792, 794, 610, 279, 17,  18,  487, 689, 99,  430, 6,   24,  25,
    163, 716, 116, 852, 795, 396, 125, 33,  800, -1,  -1,  -1,  -1,  -1,  -1,
    -1,  120, -1,  -1,  -1,  -1,  304, -1,  -1,  -1,  51,  -1,  310, -1,  -1,
    -1,  -1,  -1,  -1,  99,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  325, 326, 327,
    328, 329, 330, 331, 332, -1,  334, 335, 336, 337, 338, 339, 340, 341, 342,
    86,  3,   4,   5,   6,   7,   8,   -1,  -1,  -1,  -1,  -1,  -1,  99,  -1,
    17,  18,  -1,  -1,  -1,  -1,  -1,  24,  25,  -1,  -1,  -1,  -1,  192, -1,
    -1,  3,   4,   5,   6,   7,   8,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    17,  18,  -1,  -1,  51,  -1,  215, 24,  25,  26,  -1,  3,   4,   5,   6,
    7,   8,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  17,  18,  -1,  -1,  -1,
    -1,  201, 24,  25,  51,  3,   4,   5,   6,   7,   8,   -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  17,  18,  -1,  99,  -1,  -1,  -1,  24,  25,  -1,  51,
    19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  -1,  282, 283,
    -1,  -1,  -1,  -1,  -1,  -1,  290, 99,  51,  -1,  -1,  -1,  296, 297, -1,
    299, 300, 301, 302, -1,  304, 305, 306, -1,  308, 309, 310, -1,  -1,  -1,
    -1,  -1,  99,  -1,  -1,  -1,  -1,  -1,  160, 323, 324, 325, 326, 327, 328,
    329, 330, 331, 332, -1,  334, 335, 336, 337, 338, -1,  99,  341, 10,  11,
    12,  13,  14,  15,  16,  -1,  18,  19,  20,  21,  22,  23,  24,  25,  26,
    27,  28,  29,  30,  -1,  325, 326, 327, 328, 329, 330, 331, 332, -1,  334,
    335, 336, 337, 338, -1,  -1,  341, 10,  11,  12,  13,  14,  15,  16,  -1,
    18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  -1,  325,
    326, 327, 328, 329, 330, 331, 332, -1,  334, 335, 336, 337, 338, -1,  -1,
    341, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  3,   4,   5,   6,   7,
    8,   -1,  195, -1,  -1,  -1,  -1,  -1,  -1,  17,  18,  -1,  -1,  -1,  -1,
    -1,  24,  25,  -1,  -1,  3,   4,   5,   6,   7,   8,   -1,  244, -1,  -1,
    -1,  -1,  -1,  -1,  17,  18,  -1,  -1,  -1,  -1,  -1,  24,  25,  51,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  325, 326, 327, 328, 329, 330, 331,
    332, -1,  334, 335, 336, 337, 338, -1,  51,  341, -1,  -1,  80,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  325, 326, 327, 328, 329, 330, 331,
    332, 99,  334, 335, 336, 337, 338, 80,  -1,  341, -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  325, 326, 327, 328, 329, 330, 331, 332, 99,  334, 335, 336,
    337, 338, -1,  -1,  341, -1,  -1,  -1,  -1,  -1,  -1,  -1,  325, 326, 327,
    328, 329, 330, 331, 332, -1,  334, 335, 336, 337, 338, -1,  -1,  341, 3,
    4,   5,   6,   7,   8,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  17,  18,
    -1,  -1,  -1,  -1,  -1,  24,  25,  3,   4,   5,   6,   7,   8,   -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  17,  18,  -1,  -1,  -1,  -1,  -1,  24,  25,
    -1,  -1,  51,  -1,  -1,  3,   4,   5,   6,   7,   8,   -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  17,  18,  -1,  -1,  -1,  -1,  51,  24,  25,  -1,  -1,
    -1,  80,  -1,  -1,  3,   4,   5,   6,   7,   8,   -1,  -1,  -1,  340, -1,
    342, 304, -1,  17,  18,  99,  -1,  310, 51,  -1,  24,  25,  20,  21,  22,
    23,  24,  25,  26,  27,  28,  29,  30,  -1,  -1,  -1,  -1,  -1,  99,  -1,
    10,  11,  12,  13,  14,  15,  16,  51,  18,  19,  20,  21,  22,  23,  24,
    25,  26,  27,  28,  29,  30,  -1,  -1,  -1,  -1,  -1,  99,  11,  12,  13,
    14,  15,  16,  -1,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,
    29,  30,  325, 326, 327, 328, 329, 330, 331, 332, 99,  334, 335, 336, 337,
    338, -1,  -1,  341, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  325, 326, 327,
    328, 329, 330, 331, 332, -1,  334, 335, 336, 337, 338, -1,  -1,  341, -1,
    -1,  -1,  -1,  -1,  -1,  105, 10,  11,  12,  13,  14,  15,  16,  -1,  18,
    19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  10,  11,  12,
    13,  14,  15,  16,  -1,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,
    28,  29,  30,  10,  11,  12,  13,  14,  15,  16,  -1,  18,  19,  20,  21,
    22,  23,  24,  25,  26,  27,  28,  29,  30,  10,  11,  12,  13,  14,  15,
    16,  -1,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,
    10,  11,  12,  13,  14,  15,  16,  -1,  18,  19,  20,  21,  22,  23,  24,
    25,  26,  27,  28,  29,  30,  325, 326, 327, 328, 329, 330, 331, 332, -1,
    334, 335, 336, 337, 338, -1,  -1,  341, -1,  -1,  -1,  -1,  -1,  -1,  325,
    326, 327, 328, 329, 330, 331, 332, -1,  334, 335, 336, 337, 338, -1,  -1,
    341, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  325, 326, 327,
    328, 329, 330, 331, 332, -1,  334, 335, 336, 337, 338, -1,  -1,  341, -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  325, 326, 327, 328,
    329, 330, 331, 332, -1,  334, 335, 336, 337, 338, -1,  -1,  341, 10,  11,
    12,  13,  14,  15,  16,  -1,  18,  19,  20,  21,  22,  23,  24,  25,  26,
    27,  28,  29,  30,  -1,  -1,  -1,  -1,  -1,  -1,  10,  11,  12,  13,  14,
    15,  16,  342, 18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,
    30,  10,  11,  12,  13,  14,  15,  16,  -1,  18,  19,  20,  21,  22,  23,
    24,  25,  26,  27,  28,  29,  30,  10,  11,  12,  13,  14,  15,  16,  -1,
    18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  10,  11,
    12,  13,  14,  15,  16,  -1,  18,  19,  20,  21,  22,  23,  24,  25,  26,
    27,  28,  29,  30,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  340, -1,  342, -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  10,  11,  12,  13,  14,  15,  16,  342,
    18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  10,  11,
    12,  13,  14,  15,  16,  342, 18,  19,  20,  21,  22,  23,  24,  25,  26,
    27,  28,  29,  30,  10,  11,  12,  13,  14,  15,  16,  342, 18,  19,  20,
    21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  10,  11,  12,  13,  14,
    15,  16,  342, 18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,
    30,  10,  11,  12,  13,  14,  15,  16,  -1,  18,  19,  20,  21,  22,  23,
    24,  25,  26,  27,  28,  29,  30,  10,  11,  12,  13,  14,  15,  16,  -1,
    18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  10,  11,
    12,  13,  14,  15,  16,  -1,  18,  19,  20,  21,  22,  23,  24,  25,  26,
    27,  28,  29,  30,  10,  11,  12,  13,  14,  15,  16,  -1,  18,  19,  20,
    21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  -1,  1,   -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  10,  11,  12,  13,  14,  15,  16,
    342, 18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  -1,
    -1,  -1,  -1,  38,  -1,  10,  11,  12,  13,  14,  15,  16,  342, 18,  19,
    20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  -1,  62,  -1,  -1,
    -1,  -1,  -1,  342, 618, 619, -1,  621, -1,  -1,  624, 625, -1,  627, 628,
    629, -1,  82,  83,  633, -1,  635, -1,  637, 342, 90,  -1,  -1,  642, -1,
    -1,  645, -1,  -1,  -1,  -1,  -1,  102, 73,  74,  75,  76,  77,  -1,  -1,
    342, -1,  -1,  -1,  -1,  -1,  -1,  -1,  10,  11,  12,  13,  14,  15,  16,
    125, 18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  -1,
    140, 10,  11,  12,  13,  14,  15,  16,  -1,  18,  19,  20,  21,  22,  23,
    24,  25,  26,  27,  28,  29,  30,  -1,  -1,  342, 13,  14,  15,  16,  -1,
    18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  732, -1,
    342, -1,  -1,  -1,  -1,  -1,  43,  44,  45,  46,  195, -1,  -1,  -1,  199,
    -1,  53,  -1,  -1,  340, -1,  176, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  71,  72,  -1,  -1,  -1,  -1,  340, 78,  -1,  -1,  -1,
    -1,  -1,  -1,  233, -1,  -1,  -1,  89,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    97,  340, -1,  -1,  -1,  -1,  -1,  104, -1,  -1,  -1,  -1,  -1,  -1,  259,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  340, -1,  -1,  -1,  -1,  -1,  -1,  126,
    127, -1,  -1,  -1,  249, 250, -1,  252, -1,  -1,  -1,  -1,  -1,  340, -1,
    -1,  -1,  -1,  145, 146, -1,  -1,  -1,  150, 151, 152, -1,  10,  11,  12,
    13,  14,  15,  16,  340, 18,  19,  20,  21,  22,  23,  24,  25,  26,  27,
    28,  29,  30,  13,  14,  15,  16,  179, 18,  19,  20,  21,  22,  23,  24,
    25,  26,  27,  28,  29,  30,  -1,  -1,  340, -1,  -1,  198, -1,  200, -1,
    219, -1,  244, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    217, -1,  -1,  220, 221, 222, 223, 224, -1,  -1,  -1,  -1,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  241, 242, -1,  -1,  -1,  -1,
    -1,  -1,  249, 10,  11,  12,  13,  14,  15,  16,  -1,  18,  19,  20,  21,
    22,  23,  24,  25,  26,  27,  28,  29,  30,  10,  11,  12,  13,  14,  15,
    16,  -1,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,
    10,  11,  12,  13,  14,  15,  16,  -1,  18,  19,  20,  21,  22,  23,  24,
    25,  26,  27,  28,  29,  30,  10,  11,  12,  13,  14,  15,  16,  -1,  18,
    19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  -1,  40,  -1,  -1,  -1,  -1,  108, -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  96,  -1,  -1,  -1,  -1,  -1,  219, -1,  -1,  -1,
    -1,  -1,  -1,  -1,  -1,  3,   -1,  -1,  -1,  -1,  -1,  96,  10,  11,  12,
    13,  14,  15,  16,  83,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,
    28,  29,  30,  -1,  10,  11,  12,  13,  14,  15,  16,  39,  18,  19,  20,
    21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  -1,  10,  11,  12,  13,
    14,  15,  16,  39,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,
    29,  30,  -1,  -1,  -1,  -1,  -1,  36,  10,  11,  12,  13,  14,  15,  16,
    -1,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  10,
    11,  12,  13,  14,  15,  16,  -1,  18,  19,  20,  21,  22,  23,  24,  25,
    26,  27,  28,  29,  30,  10,  11,  12,  13,  14,  15,  16,  -1,  18,  19,
    20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  12,  13,  14,  15,
    16,  -1,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short int yystos[] = {
    0,   1,   38,  62,  82,  83,  90,  102, 125, 140, 195, 199, 233, 259, 345,
    346, 347, 383, 385, 398, 399, 400, 405, 406, 407, 408, 410, 413, 414, 415,
    423, 430, 434, 339, 215, 69,  110, 173, 192, 203, 216, 230, 388, 401, 431,
    3,   69,  120, 173, 192, 388, 129, 215, 417, 215, 33,  86,  359, 3,   4,
    5,   6,   7,   8,   17,  18,  24,  25,  51,  62,  69,  99,  120, 192, 215,
    282, 283, 290, 296, 297, 299, 302, 304, 305, 306, 308, 310, 323, 324, 325,
    326, 327, 328, 329, 330, 331, 332, 334, 335, 336, 337, 338, 341, 376, 424,
    428, 429, 3,   341, 365, 375, 173, 215, 0,   1,   339, 229, 3,   118, 384,
    160, 384, 215, 120, 3,   108, 119, 148, 175, 432, 118, 409, 3,   5,   108,
    409, 215, 341, 376, 377, 3,   81,  114, 119, 129, 148, 418, 3,   160, 360,
    376, 26,  361, 362, 376, 343, 9,   376, 99,  376, 376, 376, 244, 376, 382,
    69,  192, 215, 3,   341, 108, 3,   301, 198, 14,  426, 3,   303, 138, 356,
    105, 301, 108, 425, 356, 279, 341, 341, 341, 341, 341, 341, 341, 341, 341,
    341, 341, 341, 341, 376, 377, 10,  11,  12,  13,  14,  15,  16,  18,  19,
    20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  304, 310, 279, 298,
    307, 300, 301, 309, 3,   39,  343, 367, 347, 363, 364, 365, 368, 198, 39,
    366, 5,   3,   411, 339, 345, 347, 398, 108, 18,  3,   3,   3,   384, 3,
    343, 433, 3,   363, 432, 108, 340, 99,  3,   160, 108, 3,   3,   409, 377,
    340, 247, 129, 3,   108, 341, 340, 129, 357, 340, 367, 3,   26,  376, 341,
    376, 382, 93,  96,  244, 3,   3,   3,   347, 3,   425, 426, 4,   300, 301,
    376, 8,   3,   14,  427, 425, 376, 47,  135, 226, 376, 379, 376, 376, 26,
    359, 376, 376, 376, 377, 359, 376, 359, 376, 359, 376, 359, 376, 359, 376,
    342, 342, 376, 376, 376, 376, 376, 6,   18,  158, 341, 13,  14,  16,  376,
    33,  37,  201, 341, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376,
    425, 108, 426, 426, 3,   3,   342, 342, 63,  109, 122, 137, 156, 189, 214,
    340, 369, 371, 376, 435, 3,   108, 340, 343, 377, 99,  341, 3,   236, 402,
    26,  343, 245, 348, 236, 363, 3,   3,   3,   411, 342, 377, 4,   377, 198,
    341, 419, 377, 360, 360, 365, 108, 361, 347, 219, 93,  96,  376, 376, 342,
    425, 426, 340, 376, 426, 108, 340, 342, 376, 340, 340, 342, 342, 342, 342,
    39,  342, 342, 342, 342, 342, 342, 342, 342, 342, 342, 342, 16,  18,  6,
    158, 347, 377, 376, 376, 341, 36,  341, 341, 341, 347, 426, 3,   367, 109,
    137, 189, 372, 365, 363, 131, 167, 370, 20,  340, 348, 3,   411, 3,   247,
    3,   358, 119, 184, 341, 343, 386, 387, 321, 322, 403, 160, 376, 165, 354,
    363, 348, 433, 50,  186, 412, 340, 247, 3,   422, 358, 240, 347, 247, 342,
    159, 169, 363, 342, 376, 376, 96,  219, 376, 376, 376, 108, 128, 381, 381,
    4,   53,  89,  104, 127, 380, 341, 16,  342, 342, 347, 377, 376, 347, 347,
    347, 342, 425, 370, 370, 370, 131, 160, 365, 131, 376, 376, 340, 4,   340,
    342, 3,   110, 120, 132, 171, 389, 390, 3,   366, 3,   48,  356, 348, 4,
    4,   20,  160, 340, 416, 342, 341, 420, 416, 4,   20,  160, 348, 96,  376,
    105, 342, 340, 342, 376, 376, 342, 342, 342, 347, 377, 378, 341, 342, 342,
    342, 342, 342, 426, 365, 376, 160, 236, 373, 374, 365, 20,  411, 340, 358,
    159, 169, 43,  44,  45,  46,  53,  71,  72,  78,  89,  97,  104, 126, 127,
    145, 146, 150, 151, 152, 179, 198, 200, 217, 220, 221, 222, 223, 224, 241,
    242, 249, 392, 120, 132, 341, 341, 132, 342, 340, 341, 386, 347, 341, 355,
    376, 347, 340, 80,  376, 161, 3,   80,  376, 421, 416, 340, 5,   3,   112,
    349, 376, 376, 342, 73,  74,  75,  76,  77,  176, 249, 250, 252, 342, 340,
    342, 347, 377, 376, 341, 374, 376, 4,   20,  160, 341, 394, 394, 394, 394,
    394, 394, 341, 394, 394, 394, 44,  395, 394, 395, 394, 341, 394, 395, 394,
    395, 341, 394, 391, 341, 341, 358, 358, 341, 386, 389, 389, 3,   404, 40,
    83,  351, 4,   132, 20,  340, 340, 342, 4,   169, 48,  113, 353, 342, 342,
    378, 342, 342, 358, 191, 5,   3,   5,   396, 397, 396, 396, 4,   393, 396,
    396, 396, 397, 396, 397, 396, 393, 396, 397, 396, 397, 5,   397, 18,  41,
    57,  80,  132, 158, 171, 230, 358, 358, 342, 342, 358, 342, 394, 342, 340,
    233, 80,  376, 421, 421, 340, 191, 160, 350, 376, 376, 354, 342, 20,  169,
    340, 342, 232, 251, 53,  55,  340, 342, 342, 342, 158, 4,   4,   5,   6,
    7,   132, 132, 341, 342, 342, 342, 386, 351, 355, 422, 420, 20,  3,   247,
    352, 340, 356, 7,   160, 5,   198, 3,   4,   397, 397, 358, 340, 7,   190,
    350, 3,   342, 3,   342, 404};

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
#line 452 "sql.ypp"
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
#line 466 "sql.ypp"
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
#line 479 "sql.ypp"
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
#line 488 "sql.ypp"
    {
      printf(">> \n");
      result->ast = NULL;
      result->error_number++;
      yyclearin;
      yyerrok;
    } break;

    case 6:
/* Line 868 of glr.c  */
#line 499 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 7:
/* Line 868 of glr.c  */
#line 510 "sql.ypp"
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
#line 516 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 9:
/* Line 868 of glr.c  */
#line 517 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstWhereClause(
          AST_WHERE_CLAUSE, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (2))]
                                 .yystate.yysemantics.yysval.ast_node));
    } break;

    case 10:
/* Line 868 of glr.c  */
#line 520 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 11:
/* Line 868 of glr.c  */
#line 521 "sql.ypp"
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
#line 526 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstGroupByList(
          AST_GROUPBY_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                 .yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 13:
/* Line 868 of glr.c  */
#line 527 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstGroupByList(
          AST_GROUPBY_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                                 .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 14:
/* Line 868 of glr.c  */
#line 529 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 15:
/* Line 868 of glr.c  */
#line 530 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 16:
/* Line 868 of glr.c  */
#line 531 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 17:
/* Line 868 of glr.c  */
#line 534 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 18:
/* Line 868 of glr.c  */
#line 535 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 19:
/* Line 868 of glr.c  */
#line 538 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 20:
/* Line 868 of glr.c  */
#line 539 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstHavingClause(
          AST_HAVING_CLAUSE, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (2))]
                                  .yystate.yysemantics.yysval.ast_node));
    } break;

    case 21:
/* Line 868 of glr.c  */
#line 542 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 22:
/* Line 868 of glr.c  */
#line 543 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstOrderByClause(
          AST_ORDERBY_CLAUSE,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 23:
/* Line 868 of glr.c  */
#line 546 "sql.ypp"
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
#line 547 "sql.ypp"
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
#line 549 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 26:
/* Line 868 of glr.c  */
#line 550 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstLimitClause(
          AST_LIMIT_CLAUSE, NULL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (2))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 27:
/* Line 868 of glr.c  */
#line 551 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstLimitClause(
          AST_LIMIT_CLAUSE, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (4))]
                                 .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 28:
/* Line 868 of glr.c  */
#line 554 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 29:
/* Line 868 of glr.c  */
#line 555 "sql.ypp"
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
#line 557 "sql.ypp"
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
#line 564 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstColumn(
          AST_COLUMN, string("NULL"),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 32:
/* Line 868 of glr.c  */
#line 565 "sql.ypp"
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
#line 580 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 34:
/* Line 868 of glr.c  */
#line 581 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstDistinctClause(AST_DISTINCT_CLAUSE, NULL, 1);
    } break;

    case 35:
/* Line 868 of glr.c  */
#line 582 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDistinctClause(
          AST_DISTINCT_CLAUSE,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (5))].yystate.yysemantics.yysval.ast_node),
          2);
    } break;

    case 36:
/* Line 868 of glr.c  */
#line 583 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstDistinctClause(AST_DISTINCT_CLAUSE, NULL, 0);
    } break;

    case 37:
/* Line 868 of glr.c  */
#line 584 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDistinctClause(
          AST_DISTINCT_CLAUSE,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (2))].yystate.yysemantics.yysval.ast_node),
          3);
    } break;

    case 38:
/* Line 868 of glr.c  */
#line 588 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDistinctList(
          AST_DISTINCT_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 39:
/* Line 868 of glr.c  */
#line 589 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDistinctList(
          AST_DISTINCT_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                                  .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 40:
/* Line 868 of glr.c  */
#line 593 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstSelectList(
          AST_SELECT_LIST, 0,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (1))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 41:
/* Line 868 of glr.c  */
#line 594 "sql.ypp"
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
#line 595 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstSelectList(AST_SELECT_LIST, 1, NULL, NULL);
    } break;

    case 43:
/* Line 868 of glr.c  */
#line 599 "sql.ypp"
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
#line 602 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstFromList(
          AST_FROM_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                              .yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 45:
/* Line 868 of glr.c  */
#line 603 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstFromList(
          AST_FROM_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                              .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 46:
/* Line 868 of glr.c  */
#line 607 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 47:
/* Line 868 of glr.c  */
#line 608 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 48:
/* Line 868 of glr.c  */
#line 613 "sql.ypp"
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
#line 615 "sql.ypp"
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
#line 616 "sql.ypp"
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
#line 617 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 54:
/* Line 868 of glr.c  */
#line 624 "sql.ypp"
    {
      ((*yyvalp).strval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (2))]
                                .yystate.yysemantics.yysval.strval);
    } break;

    case 55:
/* Line 868 of glr.c  */
#line 625 "sql.ypp"
    {
      ((*yyvalp).strval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                .yystate.yysemantics.yysval.strval);
    } break;

    case 56:
/* Line 868 of glr.c  */
#line 626 "sql.ypp"
    {
      ((*yyvalp).strval) = "NULL";
    } break;

    case 57:
/* Line 868 of glr.c  */
#line 641 "sql.ypp"
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
#line 642 "sql.ypp"
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
#line 643 "sql.ypp"
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
#line 644 "sql.ypp"
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
#line 645 "sql.ypp"
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
#line 648 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 63:
/* Line 868 of glr.c  */
#line 649 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 64:
/* Line 868 of glr.c  */
#line 650 "sql.ypp"
    {
      ((*yyvalp).intval) = 2;
    } break;

    case 65:
/* Line 868 of glr.c  */
#line 653 "sql.ypp"
    {
      ((*yyvalp).intval) = 4;
    } break;

    case 66:
/* Line 868 of glr.c  */
#line 654 "sql.ypp"
    {
      ((*yyvalp).intval) = 4;
    } break;

    case 67:
/* Line 868 of glr.c  */
#line 658 "sql.ypp"
    {
      ((*yyvalp).intval) = 8;
    } break;

    case 68:
/* Line 868 of glr.c  */
#line 659 "sql.ypp"
    {
      ((*yyvalp).intval) = 16;
    } break;

    case 69:
/* Line 868 of glr.c  */
#line 660 "sql.ypp"
    {
      ((*yyvalp).intval) = 64;
    } break;

    case 70:
/* Line 868 of glr.c  */
#line 664 "sql.ypp"
    {
      ((*yyvalp).intval) =
          8 + (((yyGLRStackItem const *)
                yyvsp)[YYFILL((2) - (2))].yystate.yysemantics.yysval.intval);
    } break;

    case 71:
/* Line 868 of glr.c  */
#line 665 "sql.ypp"
    {
      ((*yyvalp).intval) =
          16 + (((yyGLRStackItem const *)
                 yyvsp)[YYFILL((2) - (2))].yystate.yysemantics.yysval.intval);
    } break;

    case 72:
/* Line 868 of glr.c  */
#line 666 "sql.ypp"
    {
      ((*yyvalp).intval) =
          64 + (((yyGLRStackItem const *)
                 yyvsp)[YYFILL((2) - (2))].yystate.yysemantics.yysval.intval);
    } break;

    case 73:
/* Line 868 of glr.c  */
#line 667 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 74:
/* Line 868 of glr.c  */
#line 670 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 75:
/* Line 868 of glr.c  */
#line 671 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 76:
/* Line 868 of glr.c  */
#line 679 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstJoinCondition(
          AST_JOIN_CONDITION, "ON",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (2))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 77:
/* Line 868 of glr.c  */
#line 680 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstJoinCondition(
          AST_JOIN_CONDITION, "USING",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 78:
/* Line 868 of glr.c  */
#line 685 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 79:
/* Line 868 of glr.c  */
#line 692 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstColumn(
          AST_COLUMN, string("NULL"),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 80:
/* Line 868 of glr.c  */
#line 693 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprConst(
          AST_EXPR_CONST, "CONST",
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 81:
/* Line 868 of glr.c  */
#line 694 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstColumn(
          AST_COLUMN, string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                                  .yystate.yysemantics.yysval.strval)),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (3))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 82:
/* Line 868 of glr.c  */
#line 695 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstColumn(
          AST_COLUMN_ALL,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                      .yystate.yysemantics.yysval.strval)),
          string("*"));
    } break;

    case 83:
/* Line 868 of glr.c  */
#line 696 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprConst(
          AST_EXPR_CONST, "CONST_STRING",
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 84:
/* Line 868 of glr.c  */
#line 697 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprConst(
          AST_EXPR_CONST, "CONST_INT",
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 85:
/* Line 868 of glr.c  */
#line 698 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprConst(
          AST_EXPR_CONST, "CONST_DOUBLE",
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 86:
/* Line 868 of glr.c  */
#line 699 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprConst(
          AST_EXPR_CONST, "CONST_BOOL",
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 87:
/* Line 868 of glr.c  */
#line 701 "sql.ypp"
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
#line 702 "sql.ypp"
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
#line 703 "sql.ypp"
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
#line 704 "sql.ypp"
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
#line 705 "sql.ypp"
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
#line 706 "sql.ypp"
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
#line 708 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "-",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (2))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 94:
/* Line 868 of glr.c  */
#line 709 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "+",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (2))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 95:
/* Line 868 of glr.c  */
#line 711 "sql.ypp"
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
#line 712 "sql.ypp"
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
#line 713 "sql.ypp"
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
#line 715 "sql.ypp"
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
#line 716 "sql.ypp"
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
#line 717 "sql.ypp"
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
#line 718 "sql.ypp"
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
#line 719 "sql.ypp"
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
#line 721 "sql.ypp"
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
#line 722 "sql.ypp"
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
#line 723 "sql.ypp"
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
#line 724 "sql.ypp"
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
#line 726 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "!",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (2))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 108:
/* Line 868 of glr.c  */
#line 727 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "NOT",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (2))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 109:
/* Line 868 of glr.c  */
#line 728 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 110:
/* Line 868 of glr.c  */
#line 729 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 111:
/* Line 868 of glr.c  */
#line 732 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "IS_NULL",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 112:
/* Line 868 of glr.c  */
#line 733 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "IS_NOT_NULL",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 113:
/* Line 868 of glr.c  */
#line 734 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "IS_BOOL",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 114:
/* Line 868 of glr.c  */
#line 735 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "IS_NOT_BOOL",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 115:
/* Line 868 of glr.c  */
#line 738 "sql.ypp"
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
#line 741 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprList(
          AST_EXPR_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                              .yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 117:
/* Line 868 of glr.c  */
#line 742 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprList(
          AST_EXPR_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                              .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 118:
/* Line 868 of glr.c  */
#line 743 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 119:
/* Line 868 of glr.c  */
#line 746 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprList(
          AST_EXPR_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                              .yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 120:
/* Line 868 of glr.c  */
#line 747 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprList(
          AST_EXPR_LIST, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                              .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 121:
/* Line 868 of glr.c  */
#line 750 "sql.ypp"
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
#line 751 "sql.ypp"
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
#line 752 "sql.ypp"
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
#line 754 "sql.ypp"
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
#line 756 "sql.ypp"
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
#line 757 "sql.ypp"
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
#line 758 "sql.ypp"
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
#line 759 "sql.ypp"
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
#line 761 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "EXSIST",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 130:
/* Line 868 of glr.c  */
#line 762 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "NOT_EXSIST",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 131:
/* Line 868 of glr.c  */
#line 772 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstExprUnary(AST_EXPR_UNARY, "COUNT_ALL", NULL);
    } break;

    case 132:
/* Line 868 of glr.c  */
#line 773 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "COUNT",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 133:
/* Line 868 of glr.c  */
#line 774 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "SUM",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 134:
/* Line 868 of glr.c  */
#line 775 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "AVG",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 135:
/* Line 868 of glr.c  */
#line 776 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "MIN",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 136:
/* Line 868 of glr.c  */
#line 777 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "MAX",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 137:
/* Line 868 of glr.c  */
#line 778 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "TO_CHAR",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 138:
/* Line 868 of glr.c  */
#line 779 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "TO_CHAR",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 139:
/* Line 868 of glr.c  */
#line 780 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "COUNT",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 140:
/* Line 868 of glr.c  */
#line 781 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "SUM",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 141:
/* Line 868 of glr.c  */
#line 782 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "AVG",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 142:
/* Line 868 of glr.c  */
#line 783 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "MIN",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 143:
/* Line 868 of glr.c  */
#line 784 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprUnary(
          AST_EXPR_UNARY, "MAX",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 144:
/* Line 868 of glr.c  */
#line 787 "sql.ypp"
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
#line 788 "sql.ypp"
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
#line 789 "sql.ypp"
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
#line 790 "sql.ypp"
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
#line 791 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "TRIM_BOTH", NULL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 149:
/* Line 868 of glr.c  */
#line 792 "sql.ypp"
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
#line 793 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "UPPER",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 151:
/* Line 868 of glr.c  */
#line 794 "sql.ypp"
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
#line 795 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "COALESCE",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 153:
/* Line 868 of glr.c  */
#line 798 "sql.ypp"
    {
      ((*yyvalp).strval) = "TRIM_LEADING";
    } break;

    case 154:
/* Line 868 of glr.c  */
#line 799 "sql.ypp"
    {
      ((*yyvalp).strval) = "TRIM_TRAILING";
    } break;

    case 155:
/* Line 868 of glr.c  */
#line 800 "sql.ypp"
    {
      ((*yyvalp).strval) = "TRIM_BOTH";
    } break;

    case 156:
/* Line 868 of glr.c  */
#line 803 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 157:
/* Line 868 of glr.c  */
#line 804 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "INT", NULL);
    } break;

    case 158:
/* Line 868 of glr.c  */
#line 805 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "STRING", NULL);
    } break;

    case 159:
/* Line 868 of glr.c  */
#line 806 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "DOUBLE", NULL);
    } break;

    case 160:
/* Line 868 of glr.c  */
#line 807 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "FLOAT", NULL);
    } break;

    case 161:
/* Line 868 of glr.c  */
#line 808 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprConst(AST_EXPR_CONST, "CHAR", NULL);
    } break;

    case 162:
/* Line 868 of glr.c  */
#line 811 "sql.ypp"
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
#line 812 "sql.ypp"
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
#line 816 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "INTERVAL_HOUR",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 165:
/* Line 868 of glr.c  */
#line 817 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "INTERVAL_MICROSECOND",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 166:
/* Line 868 of glr.c  */
#line 818 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "INTERVAL_MINUTE",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 167:
/* Line 868 of glr.c  */
#line 819 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "INTERVAL_SECOND",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 168:
/* Line 868 of glr.c  */
#line 820 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "INTERVAL_DAY",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 169:
/* Line 868 of glr.c  */
#line 821 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "INTERVAL_MONTH",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 170:
/* Line 868 of glr.c  */
#line 822 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "INTERVAL_YEAR",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 171:
/* Line 868 of glr.c  */
#line 823 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "INTERVAL_WEEK",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 172:
/* Line 868 of glr.c  */
#line 824 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "INTERVAL_QUARTER",
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL, NULL);
    } break;

    case 173:
/* Line 868 of glr.c  */
#line 828 "sql.ypp"
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
#line 829 "sql.ypp"
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
#line 830 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstExprFunc(
          AST_EXPR_FUNC, "CASE2", NULL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 176:
/* Line 868 of glr.c  */
#line 831 "sql.ypp"
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
#line 834 "sql.ypp"
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
#line 835 "sql.ypp"
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
#line 838 "sql.ypp"
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
#line 839 "sql.ypp"
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
#line 842 "sql.ypp"
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
#line 843 "sql.ypp"
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
#line 849 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 184:
/* Line 868 of glr.c  */
#line 853 "sql.ypp"
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
#line 854 "sql.ypp"
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
#line 857 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 187:
/* Line 868 of glr.c  */
#line 858 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 188:
/* Line 868 of glr.c  */
#line 863 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 189:
/* Line 868 of glr.c  */
#line 867 "sql.ypp"
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
#line 871 "sql.ypp"
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
#line 876 "sql.ypp"
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
#line 880 "sql.ypp"
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
#line 885 "sql.ypp"
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
#line 889 "sql.ypp"
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
#line 893 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateSelect(
          AST_CREATE_SEL, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                               .yystate.yysemantics.yysval.intval),
          0, (((yyGLRStackItem const *)
               yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 196:
/* Line 868 of glr.c  */
#line 896 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 197:
/* Line 868 of glr.c  */
#line 897 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 198:
/* Line 868 of glr.c  */
#line 898 "sql.ypp"
    {
      ((*yyvalp).intval) = 2;
    } break;

    case 199:
/* Line 868 of glr.c  */
#line 901 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 200:
/* Line 868 of glr.c  */
#line 902 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 201:
/* Line 868 of glr.c  */
#line 905 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateColList(
          AST_CREATE_COL_LIST,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (1))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 202:
/* Line 868 of glr.c  */
#line 906 "sql.ypp"
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
#line 911 "sql.ypp"
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
#line 912 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateDef(
          AST_CREATE_DEF_PR_KEY, 2, "", NULL, NULL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 205:
/* Line 868 of glr.c  */
#line 913 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateDef(
          AST_CREATE_DEF_KEY, 3, "", NULL, NULL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 206:
/* Line 868 of glr.c  */
#line 914 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateDef(
          AST_CREATE_DEF_INDEX, 4, "", NULL, NULL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 207:
/* Line 868 of glr.c  */
#line 915 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateDef(
          AST_CREATE_DEF_FTEXT_INDEX, 5, "", NULL, NULL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 208:
/* Line 868 of glr.c  */
#line 916 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstCreateDef(
          AST_CREATE_DEF_FTEXT_KEY, 6, "", NULL, NULL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((4) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 209:
/* Line 868 of glr.c  */
#line 918 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstColumnAtts(AST_COLUMN_ATTS, 0, 0, 0, "", NULL);
    } break;

    case 210:
/* Line 868 of glr.c  */
#line 919 "sql.ypp"
    {
      AstColumnAtts *temp = static_cast<AstColumnAtts *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node));
      temp->datatype_ |= 01;
      ((*yyvalp).ast_node) = temp;
    } break;

    case 211:
/* Line 868 of glr.c  */
#line 920 "sql.ypp"
    {
      AstColumnAtts *temp = static_cast<AstColumnAtts *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (2))].yystate.yysemantics.yysval.ast_node));
      temp->datatype_ |= 02;
      ((*yyvalp).ast_node) = temp;
    } break;

    case 212:
/* Line 868 of glr.c  */
#line 921 "sql.ypp"
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
#line 922 "sql.ypp"
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
#line 923 "sql.ypp"
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
#line 924 "sql.ypp"
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
#line 925 "sql.ypp"
    {
      AstColumnAtts *temp = static_cast<AstColumnAtts *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (2))].yystate.yysemantics.yysval.ast_node));
      temp->datatype_ |= 0100;
      ((*yyvalp).ast_node) = temp;
    } break;

    case 217:
/* Line 868 of glr.c  */
#line 926 "sql.ypp"
    {
      AstColumnAtts *temp = static_cast<AstColumnAtts *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node));
      temp->datatype_ |= 0200;
      ((*yyvalp).ast_node) = temp;
    } break;

    case 218:
/* Line 868 of glr.c  */
#line 927 "sql.ypp"
    {
      AstColumnAtts *temp = static_cast<AstColumnAtts *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node));
      temp->datatype_ |= 0400;
      ((*yyvalp).ast_node) = temp;
    } break;

    case 219:
/* Line 868 of glr.c  */
#line 928 "sql.ypp"
    {
      AstColumnAtts *temp = static_cast<AstColumnAtts *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (2))].yystate.yysemantics.yysval.ast_node));
      temp->datatype_ |= 01000;
      ((*yyvalp).ast_node) = temp;
    } break;

    case 220:
/* Line 868 of glr.c  */
#line 929 "sql.ypp"
    {
      AstColumnAtts *temp = static_cast<AstColumnAtts *>(
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node));
      temp->datatype_ |= 02000;
      ((*yyvalp).ast_node) = temp;
    } break;

    case 221:
/* Line 868 of glr.c  */
#line 930 "sql.ypp"
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
#line 934 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 1, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (2))]
                                 .yystate.yysemantics.yysval.ast_node),
          0, NULL, 0, NULL);
    } break;

    case 223:
/* Line 868 of glr.c  */
#line 935 "sql.ypp"
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
#line 936 "sql.ypp"
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
#line 937 "sql.ypp"
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
#line 938 "sql.ypp"
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
#line 939 "sql.ypp"
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
#line 940 "sql.ypp"
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
#line 941 "sql.ypp"
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
#line 942 "sql.ypp"
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
#line 943 "sql.ypp"
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
#line 944 "sql.ypp"
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
#line 945 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstDataType(AST_DATA_TYPE, 12, NULL, 0, NULL, 0, NULL);
    } break;

    case 234:
/* Line 868 of glr.c  */
#line 946 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstDataType(AST_DATA_TYPE, 13, NULL, 0, NULL, 0, NULL);
    } break;

    case 235:
/* Line 868 of glr.c  */
#line 947 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstDataType(AST_DATA_TYPE, 14, NULL, 0, NULL, 0, NULL);
    } break;

    case 236:
/* Line 868 of glr.c  */
#line 948 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstDataType(AST_DATA_TYPE, 15, NULL, 0, NULL, 0, NULL);
    } break;

    case 237:
/* Line 868 of glr.c  */
#line 949 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstDataType(AST_DATA_TYPE, 16, NULL, 0, NULL, 0, NULL);
    } break;

    case 238:
/* Line 868 of glr.c  */
#line 950 "sql.ypp"
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
#line 951 "sql.ypp"
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
#line 952 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDataType(
          AST_DATA_TYPE, 19, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (2))]
                                  .yystate.yysemantics.yysval.ast_node),
          0, NULL, 0, NULL);
    } break;

    case 241:
/* Line 868 of glr.c  */
#line 953 "sql.ypp"
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
#line 955 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstDataType(AST_DATA_TYPE, 21, NULL, 0, NULL, 0, NULL);
    } break;

    case 243:
/* Line 868 of glr.c  */
#line 956 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstDataType(AST_DATA_TYPE, 22, NULL, 0, NULL, 0, NULL);
    } break;

    case 244:
/* Line 868 of glr.c  */
#line 957 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstDataType(AST_DATA_TYPE, 23, NULL, 0, NULL, 0, NULL);
    } break;

    case 245:
/* Line 868 of glr.c  */
#line 958 "sql.ypp"
    {
      ((*yyvalp).ast_node) =
          new AstDataType(AST_DATA_TYPE, 24, NULL, 0, NULL, 0, NULL);
    } break;

    case 246:
/* Line 868 of glr.c  */
#line 959 "sql.ypp"
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
#line 960 "sql.ypp"
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
#line 961 "sql.ypp"
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
#line 962 "sql.ypp"
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
#line 963 "sql.ypp"
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
#line 964 "sql.ypp"
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
#line 966 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstEnumList(
          AST_ENUM, string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                .yystate.yysemantics.yysval.strval)),
          NULL);
    } break;

    case 253:
/* Line 868 of glr.c  */
#line 967 "sql.ypp"
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
#line 970 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 255:
/* Line 868 of glr.c  */
#line 971 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstOptLength(
          AST_OPT_LENGTH,
          atoi((((yyGLRStackItem const *)
                 yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.strval)),
          0);
    } break;

    case 256:
/* Line 868 of glr.c  */
#line 972 "sql.ypp"
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
#line 975 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 258:
/* Line 868 of glr.c  */
#line 976 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 259:
/* Line 868 of glr.c  */
#line 979 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 260:
/* Line 868 of glr.c  */
#line 980 "sql.ypp"
    {
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                .yystate.yysemantics.yysval.intval) |
                           01;
    } break;

    case 261:
/* Line 868 of glr.c  */
#line 981 "sql.ypp"
    {
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                .yystate.yysemantics.yysval.intval) |
                           02;
    } break;

    case 262:
/* Line 868 of glr.c  */
#line 984 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstOptCsc(AST_OPT_CSC, 0, "", "");
    } break;

    case 263:
/* Line 868 of glr.c  */
#line 986 "sql.ypp"
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
#line 988 "sql.ypp"
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
#line 990 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 266:
/* Line 868 of glr.c  */
#line 994 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstUnionStmt(
          AST_UNION_STMT, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                               .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 267:
/* Line 868 of glr.c  */
#line 998 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstUnionStmt(
          AST_UNION_STMT, (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                               .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 268:
/* Line 868 of glr.c  */
#line 1004 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval
                                  .ast_node); /* puts("SQL parser： This is a
                                                 create_projection
                                                 statement");*/
    } break;

    case 269:
/* Line 868 of glr.c  */
#line 1008 "sql.ypp"
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

    case 270:
/* Line 868 of glr.c  */
#line 1010 "sql.ypp"
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

    case 271:
/* Line 868 of glr.c  */
#line 1017 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 272:
/* Line 868 of glr.c  */
#line 1022 "sql.ypp"
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

    case 273:
/* Line 868 of glr.c  */
#line 1025 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 274:
/* Line 868 of glr.c  */
#line 1026 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 275:
/* Line 868 of glr.c  */
#line 1027 "sql.ypp"
    {
      ((*yyvalp).intval) = 2;
    } break;

    case 276:
/* Line 868 of glr.c  */
#line 1028 "sql.ypp"
    {
      ((*yyvalp).intval) = 3;
    } break;

    case 277:
/* Line 868 of glr.c  */
#line 1031 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 278:
/* Line 868 of glr.c  */
#line 1032 "sql.ypp"
    {
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (2))]
                                .yystate.yysemantics.yysval.intval);
    } break;

    case 279:
/* Line 868 of glr.c  */
#line 1035 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 280:
/* Line 868 of glr.c  */
#line 1036 "sql.ypp"
    {
      ((*yyvalp).intval) = 2;
    } break;

    case 281:
/* Line 868 of glr.c  */
#line 1039 "sql.ypp"
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

    case 282:
/* Line 868 of glr.c  */
#line 1040 "sql.ypp"
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

    case 283:
/* Line 868 of glr.c  */
#line 1044 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 284:
/* Line 868 of glr.c  */
#line 1048 "sql.ypp"
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

    case 285:
/* Line 868 of glr.c  */
#line 1052 "sql.ypp"
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

    case 286:
/* Line 868 of glr.c  */
#line 1053 "sql.ypp"
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

    case 287:
/* Line 868 of glr.c  */
#line 1055 "sql.ypp"
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

    case 288:
/* Line 868 of glr.c  */
#line 1061 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 289:
/* Line 868 of glr.c  */
#line 1065 "sql.ypp"
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

    case 290:
/* Line 868 of glr.c  */
#line 1071 "sql.ypp"
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

    case 291:
/* Line 868 of glr.c  */
#line 1077 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval
                                  .ast_node); /*output($$, 1); puts("SQL
                                                 parser： This is a drop_index
                                                 statement");*/
    } break;

    case 292:
/* Line 868 of glr.c  */
#line 1080 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDropIndex(
          AST_DROP_INDEX,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (5))]
                      .yystate.yysemantics.yysval.strval)),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((5) - (5))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 293:
/* Line 868 of glr.c  */
#line 1084 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval
                                  .ast_node); /* output($$, 1); puts("SQL
                                                 parser： This is a
                                                 drop_database statement");*/
    } break;

    case 294:
/* Line 868 of glr.c  */
#line 1088 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDropDatabase(
          AST_DROP_DB, 1, (((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (4))]
                               .yystate.yysemantics.yysval.intval),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (4))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 295:
/* Line 868 of glr.c  */
#line 1089 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDropDatabase(
          AST_DROP_SCHEMA, 2,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (4))].yystate.yysemantics.yysval.intval),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (4))]
                      .yystate.yysemantics.yysval.strval)));
    } break;

    case 296:
/* Line 868 of glr.c  */
#line 1092 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 297:
/* Line 868 of glr.c  */
#line 1093 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 298:
/* Line 868 of glr.c  */
#line 1097 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval
                                  .ast_node); /*output($$, 1); puts("SQL
                                                 parser： This is a drop_table
                                                 statement"); */
    } break;

    case 299:
/* Line 868 of glr.c  */
#line 1101 "sql.ypp"
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

    case 300:
/* Line 868 of glr.c  */
#line 1104 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDropTableList(
          AST_DROP_TABLE_LIST, "",
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                      .yystate.yysemantics.yysval.strval)),
          NULL);
    } break;

    case 301:
/* Line 868 of glr.c  */
#line 1105 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDropTableList(
          AST_DROP_TABLE_LIST,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                      .yystate.yysemantics.yysval.strval)),
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (3))]
                      .yystate.yysemantics.yysval.strval)),
          NULL);
    } break;

    case 302:
/* Line 868 of glr.c  */
#line 1106 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDropTableList(
          AST_DROP_TABLE_LIST, "",
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (3))]
                      .yystate.yysemantics.yysval.strval)),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 303:
/* Line 868 of glr.c  */
#line 1107 "sql.ypp"
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

    case 304:
/* Line 868 of glr.c  */
#line 1110 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 305:
/* Line 868 of glr.c  */
#line 1111 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 306:
/* Line 868 of glr.c  */
#line 1112 "sql.ypp"
    {
      ((*yyvalp).intval) = 2;
    } break;

    case 307:
/* Line 868 of glr.c  */
#line 1116 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval
                                  .ast_node); /*output($$, 1); puts("SQL
                                                 parser： This is a
                                                 drop_projection statement"); */
    } break;

    case 308:
/* Line 868 of glr.c  */
#line 1119 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDropProjection(
          AST_DROP_PROJECTION,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (4))]
                      .yystate.yysemantics.yysval.strval)),
          1, NULL);
    } break;

    case 309:
/* Line 868 of glr.c  */
#line 1121 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDropProjection(
          AST_DROP_PROJECTION,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((5) - (5))]
                      .yystate.yysemantics.yysval.strval)),
          0, atoi((((yyGLRStackItem const *)yyvsp)[YYFILL((3) - (5))]
                       .yystate.yysemantics.yysval.strval)));
    } break;

    case 310:
/* Line 868 of glr.c  */
#line 1127 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval
                                  .ast_node); /*output($$, 1); puts("SQL
                                                 parser： This is a truncate
                                                 statement"); */
    } break;

    case 311:
/* Line 868 of glr.c  */
#line 1130 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstTruncateTable(
          AST_TRUNCATE_TABLE,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node),
          "", "");
    } break;

    case 312:
/* Line 868 of glr.c  */
#line 1131 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstTruncateTable(
          AST_TRUNCATE_TABLE, NULL,
          string((((yyGLRStackItem const *)yyvsp)[YYFILL((5) - (5))]
                      .yystate.yysemantics.yysval.strval)),
          atoi((((yyGLRStackItem const *)
                 yyvsp)[YYFILL((3) - (5))].yystate.yysemantics.yysval.strval)));
    } break;

    case 313:
/* Line 868 of glr.c  */
#line 1136 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 314:
/* Line 868 of glr.c  */
#line 1142 "sql.ypp"
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

    case 315:
/* Line 868 of glr.c  */
#line 1145 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 316:
/* Line 868 of glr.c  */
#line 1146 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((5) - (5))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 317:
/* Line 868 of glr.c  */
#line 1149 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 318:
/* Line 868 of glr.c  */
#line 1150 "sql.ypp"
    {
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                .yystate.yysemantics.yysval.intval) |
                           01;
    } break;

    case 319:
/* Line 868 of glr.c  */
#line 1151 "sql.ypp"
    {
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                .yystate.yysemantics.yysval.intval) |
                           02;
    } break;

    case 320:
/* Line 868 of glr.c  */
#line 1152 "sql.ypp"
    {
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                .yystate.yysemantics.yysval.intval) |
                           04;
    } break;

    case 321:
/* Line 868 of glr.c  */
#line 1153 "sql.ypp"
    {
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                .yystate.yysemantics.yysval.intval) |
                           010;
    } break;

    case 324:
/* Line 868 of glr.c  */
#line 1159 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 325:
/* Line 868 of glr.c  */
#line 1160 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (3))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 326:
/* Line 868 of glr.c  */
#line 1163 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstInsertValList(
          AST_INSERT_VALUE_LIST,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 327:
/* Line 868 of glr.c  */
#line 1164 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstInsertValList(
          AST_INSERT_VALUE_LIST,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (5))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 328:
/* Line 868 of glr.c  */
#line 1168 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstInsertVals(
          AST_INSERT_VALUE, 0,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (1))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 329:
/* Line 868 of glr.c  */
#line 1169 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstInsertVals(AST_INSERT_VALUE, 1, NULL, NULL);
    } break;

    case 330:
/* Line 868 of glr.c  */
#line 1170 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstInsertVals(
          AST_INSERT_VALUE, 0,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 331:
/* Line 868 of glr.c  */
#line 1171 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstInsertVals(
          AST_INSERT_VALUE, 1, NULL,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 332:
/* Line 868 of glr.c  */
#line 1175 "sql.ypp"
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

    case 333:
/* Line 868 of glr.c  */
#line 1179 "sql.ypp"
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

    case 334:
/* Line 868 of glr.c  */
#line 1183 "sql.ypp"
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

    case 335:
/* Line 868 of glr.c  */
#line 1186 "sql.ypp"
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

    case 336:
/* Line 868 of glr.c  */
#line 1189 "sql.ypp"
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

    case 337:
/* Line 868 of glr.c  */
#line 1192 "sql.ypp"
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

    case 338:
/* Line 868 of glr.c  */
#line 1197 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval
                                  .ast_node); /*output($$, 1); puts("SQL
                                                 parser： This is a show
                                                 statement");*/
    } break;

    case 339:
/* Line 868 of glr.c  */
#line 1200 "sql.ypp"
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

    case 340:
/* Line 868 of glr.c  */
#line 1201 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 341:
/* Line 868 of glr.c  */
#line 1202 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 342:
/* Line 868 of glr.c  */
#line 1203 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 343:
/* Line 868 of glr.c  */
#line 1204 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 344:
/* Line 868 of glr.c  */
#line 1205 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 345:
/* Line 868 of glr.c  */
#line 1206 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 346:
/* Line 868 of glr.c  */
#line 1207 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 347:
/* Line 868 of glr.c  */
#line 1208 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 348:
/* Line 868 of glr.c  */
#line 1209 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 349:
/* Line 868 of glr.c  */
#line 1210 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 350:
/* Line 868 of glr.c  */
#line 1211 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 351:
/* Line 868 of glr.c  */
#line 1212 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 352:
/* Line 868 of glr.c  */
#line 1213 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 353:
/* Line 868 of glr.c  */
#line 1214 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 354:
/* Line 868 of glr.c  */
#line 1215 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 355:
/* Line 868 of glr.c  */
#line 1216 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 356:
/* Line 868 of glr.c  */
#line 1217 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 357:
/* Line 868 of glr.c  */
#line 1218 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 358:
/* Line 868 of glr.c  */
#line 1219 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 359:
/* Line 868 of glr.c  */
#line 1220 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 360:
/* Line 868 of glr.c  */
#line 1221 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 361:
/* Line 868 of glr.c  */
#line 1222 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 362:
/* Line 868 of glr.c  */
#line 1223 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 363:
/* Line 868 of glr.c  */
#line 1224 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 364:
/* Line 868 of glr.c  */
#line 1225 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 365:
/* Line 868 of glr.c  */
#line 1226 "sql.ypp"
    {
      ((*yyvalp).ast_node) = NULL;
    } break;

    case 366:
/* Line 868 of glr.c  */
#line 1228 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 367:
/* Line 868 of glr.c  */
#line 1232 "sql.ypp"
    {
      ((*yyvalp).intval) = NULL;
    } break;

    case 368:
/* Line 868 of glr.c  */
#line 1233 "sql.ypp"
    {
      ((*yyvalp).intval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (2))]
                                .yystate.yysemantics.yysval.strval);
    } break;

    case 369:
/* Line 868 of glr.c  */
#line 1236 "sql.ypp"
    {
      ((*yyvalp).strval) = NULL;
    } break;

    case 370:
/* Line 868 of glr.c  */
#line 1237 "sql.ypp"
    {
      ((*yyvalp).strval) = (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (2))]
                                .yystate.yysemantics.yysval.strval);
    } break;

    case 375:
/* Line 868 of glr.c  */
#line 1247 "sql.ypp"
    {
      ((*yyvalp).intval) = 0;
    } break;

    case 376:
/* Line 868 of glr.c  */
#line 1248 "sql.ypp"
    {
      ((*yyvalp).intval) = 1;
    } break;

    case 377:
/* Line 868 of glr.c  */
#line 1249 "sql.ypp"
    {
      ((*yyvalp).intval) = 2;
    } break;

    case 378:
/* Line 868 of glr.c  */
#line 1252 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDescStmt(
          AST_DESC_STMT, (((yyGLRStackItem const *)yyvsp)[YYFILL((2) - (2))]
                              .yystate.yysemantics.yysval.strval));
    } break;

    case 379:
/* Line 868 of glr.c  */
#line 1255 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 380:
/* Line 868 of glr.c  */
#line 1259 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstDeleteStmt(
          AST_DELETE_STMT, (((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (7))]
                                .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (7))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (7))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 381:
/* Line 868 of glr.c  */
#line 1263 "sql.ypp"
    {
      emit("DELETEMULTI %d %d %d",
           (((yyGLRStackItem const *)
             yyvsp)[YYFILL((2) - (7))].yystate.yysemantics.yysval.ast_node),
           (((yyGLRStackItem const *)
             yyvsp)[YYFILL((4) - (7))].yystate.yysemantics.yysval.ast_node),
           (((yyGLRStackItem const *)
             yyvsp)[YYFILL((6) - (7))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 382:
/* Line 868 of glr.c  */
#line 1268 "sql.ypp"
    {
    } break;

    case 383:
/* Line 868 of glr.c  */
#line 1271 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                  .yystate.yysemantics.yysval.ast_node) +
                             01;
    } break;

    case 384:
/* Line 868 of glr.c  */
#line 1272 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                  .yystate.yysemantics.yysval.ast_node) +
                             02;
    } break;

    case 385:
/* Line 868 of glr.c  */
#line 1273 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (2))]
                                  .yystate.yysemantics.yysval.ast_node) +
                             04;
    } break;

    case 386:
/* Line 868 of glr.c  */
#line 1274 "sql.ypp"
    {
      ((*yyvalp).ast_node) = 0;
    } break;

    case 387:
/* Line 868 of glr.c  */
#line 1278 "sql.ypp"
    {
    } break;

    case 388:
/* Line 868 of glr.c  */
#line 1279 "sql.ypp"
    {
    } break;

    case 391:
/* Line 868 of glr.c  */
#line 1286 "sql.ypp"
    {
      ((*yyvalp).ast_node) = (((yyGLRStackItem const *)yyvsp)[YYFILL((1) - (1))]
                                  .yystate.yysemantics.yysval.ast_node);
    } break;

    case 392:
/* Line 868 of glr.c  */
#line 1289 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstUpdateStmt(
          AST_UPDATE_STMT, (((yyGLRStackItem const *)yyvsp)[YYFILL((4) - (5))]
                                .yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((2) - (5))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((5) - (5))].yystate.yysemantics.yysval.ast_node));
    } break;

    case 393:
/* Line 868 of glr.c  */
#line 1292 "sql.ypp"
    {
      ((*yyvalp).ast_node) = new AstUpdateSetList(
          AST_UPDATE_SET_LIST,
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((1) - (3))].yystate.yysemantics.yysval.ast_node),
          (((yyGLRStackItem const *)
            yyvsp)[YYFILL((3) - (3))].yystate.yysemantics.yysval.ast_node),
          NULL);
    } break;

    case 394:
/* Line 868 of glr.c  */
#line 1293 "sql.ypp"
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
#line 4825 "sql.tab.cpp"
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

#define yypact_value_is_default(Yystate) (!!((Yystate) == (-571)))

/** True iff LR state STATE has only a default reduction (regardless
 *  of token).  */
static inline yybool yyisDefaultedState(yyStateNum yystate) {
  return yypact_value_is_default(yypact[yystate]);
}

/** The default reduction for STATE, assuming it has one.  */
static inline yyRuleNum yydefaultAction(yyStateNum yystate) {
  return yydefact[yystate];
}

#define yytable_value_is_error(Yytable_value) (!!((Yytable_value) == (-395)))

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
#line 1296 "sql.ypp"

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
