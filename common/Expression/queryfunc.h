/*
 * queryfunc.h
 *
 *  Created on: Aug 6, 2014
 *      Author: imdb
 */

#ifndef QUERYFUNC_H_
#define QUERYFUNC_H_
#include "qnode.h"
#include "../../common/data_type.h"
#include "../../common/Logging.h"
#define OPER_TYPE_NUM 100
#define DATA_TYPE_NUM 30
#include <string.h>
#include <math.h>
#include "boost/date_time/gregorian/parsers.hpp"
#include <boost/date_time/gregorian/greg_duration.hpp>
#include "boost/date_time/gregorian/formatters.hpp"
#define DELTA 1e-8
class ExectorFunction {
 public:
  static ExecFunc operator_function[DATA_TYPE_NUM][OPER_TYPE_NUM];
  static AvgDivideOld avg_divide_old[DATA_TYPE_NUM];
};

#define NextByte(p, plen) ((p)++, (plen)--)
#define NextChar(p, plen) NextByte((p), (plen))
#define LIKE_FALSE 0
#define LIKE_TRUE 1
#define LIKE_ABORT -1
#define GETCHAR(t) (t)
/*
 * stolen from pg
 */
static int MatchText(char *t, int tlen, char *p, int plen) {
  /* Fast path for match-everything pattern */
  if (plen == 1 && *p == '%') return LIKE_TRUE;

  /*
   * In this loop, we advance by char when matching wildcards (and thus on
   * recursive entry to this function we are properly char-synced). On other
   * occasions it is safe to advance by byte, as the text and pattern will
   * be in lockstep. This allows us to perform all comparisons between the
   * text and pattern on a byte by byte basis, even for multi-byte
   * encodings.
   */
  while (tlen > 0 && plen > 0) {
    if (*p == '\\') {
      //			/* Next pattern byte must match literally,
      // whatever it is */
      //			NextByte(p, plen);
      //			/* ... and there had better be one, per SQL
      // standard */
      //			if (plen <= 0)
      //				ereport(ERROR,
      //						(errcode(ERRCODE_INVALID_ESCAPE_SEQUENCE),
      //				 errmsg("LIKE pattern must not end with
      // escape character")));
      //			if (GETCHAR(*p) != GETCHAR(*t))
      //				return LIKE_FALSE;
    } else if (*p == '%') {
      char firstpat;

      /*
       * % processing is essentially a search for a text position at
       * which the remainder of the text matches the remainder of the
       * pattern, using a recursive call to check each potential match.
       *
       * If there are wildcards immediately following the %, we can skip
       * over them first, using the idea that any sequence of N _'s and
       * one or more %'s is equivalent to N _'s and one % (ie, it will
       * match any sequence of at least N text characters).  In this way
       * we will always run the recursive search loop using a pattern
       * fragment that begins with a literal character-to-match, thereby
       * not recursing more than we have to.
       */
      NextByte(p, plen);

      while (plen > 0) {
        if (*p == '%')
          NextByte(p, plen);
        else if (*p == '_') {
          /* If not enough text left to match the pattern, ABORT */
          if (tlen <= 0) return LIKE_ABORT;
          NextChar(t, tlen);
          NextByte(p, plen);
        } else
          break; /* Reached a non-wildcard pattern char */
      }

      /*
       * If we're at end of pattern, match: we have a trailing % which
       * matches any remaining text string.
       */
      if (plen <= 0) return LIKE_TRUE;

      /*
       * Otherwise, scan for a text position at which we can match the
       * rest of the pattern.  The first remaining pattern char is known
       * to be a regular or escaped literal character, so we can compare
       * the first pattern byte to each text byte to avoid recursing
       * more than we have to.  This fact also guarantees that we don't
       * have to consider a match to the zero-length substring at the
       * end of the text.
       */
      if (*p == '\\') {
        //				if (plen < 2)
        //					ereport(ERROR,
        //							(errcode(ERRCODE_INVALID_ESCAPE_SEQUENCE),
        //							 errmsg("LIKE
        // pattern
        // must
        // not end with escape character")));
        //				firstpat = GETCHAR(p[1]);
      } else
        firstpat = GETCHAR(*p);

      while (tlen > 0) {
        if (GETCHAR(*t) == firstpat) {
          int matched = MatchText(t, tlen, p, plen);

          if (matched != LIKE_FALSE) return matched; /* TRUE or ABORT */
        }

        NextChar(t, tlen);
      }

      /*
       * End of text with no match, so no point in trying later places
       * to start matching this pattern.
       */
      return LIKE_ABORT;
    } else if (*p == '_') {
      /* _ matches any single character, and we know there is one */
      NextChar(t, tlen);
      NextByte(p, plen);
      continue;
    } else if (GETCHAR(*p) != GETCHAR(*t)) {
      /* non-wildcard pattern char fails to match text char */
      return LIKE_FALSE;
    }

    /*
     * Pattern and text match, so advance.
     *
     * It is safe to use NextByte instead of NextChar here, even for
     * multi-byte character sets, because we are not following immediately
     * after a wildcard character. If we are in the middle of a multibyte
     * character, we must already have matched at least one byte of the
     * character from both text and pattern; so we cannot get out-of-sync
     * on character boundaries.  And we know that no backend-legal
     * encoding allows ASCII characters such as '%' to appear as non-first
     * bytes of characters, so we won't mistakenly detect a new wildcard.
     */
    NextByte(t, tlen);
    NextByte(p, plen);
  }

  if (tlen > 0) return LIKE_FALSE; /* end of pattern, but not of text */

  /*
   * End of text, but perhaps not of pattern.  Match iff the remaining
   * pattern can match a zero-length string, ie, it's zero or more %'s.
   */
  while (plen > 0 && *p == '%') NextByte(p, plen);
  if (plen <= 0) return LIKE_TRUE;

  /*
   * End of text with no match, so no point in trying later places to start
   * matching this pattern.
   */
  return LIKE_ABORT;
} /* MatchText() */

inline void oper_not_support_old(FuncCallInfo fcinfo) {
  SQLParse_elog("This oper_functions is not supported now!!!!!!!!!!!!!");
  assert(false);
}
/*******************int*************************/
inline void int_add_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(int *)fcinfo->results =
      (*(int *)fcinfo->args[0] + (*(int *)fcinfo->args[1]));
}
inline void int_minus_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(int *)fcinfo->results =
      (*(int *)fcinfo->args[0] - (*(int *)fcinfo->args[1]));
}
inline void int_multiply_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(int *)fcinfo->results =
      (*(int *)fcinfo->args[0] * (*(int *)fcinfo->args[1]));
}
inline void int_divide_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  int val = *(int *)fcinfo->args[1];
  if (val == 0) {
    SQLParse_elog("error:The int_divide_old divided =0!!!!!");
    assert(val != 0);
  }
  *(int *)fcinfo->results =
      (*(int *)fcinfo->args[0] / (*(int *)fcinfo->args[1]));
}
inline void int_mod_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(int *)fcinfo->results =
      (*(int *)fcinfo->args[0] % (*(int *)fcinfo->args[1]));
}
inline void int_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(int *)fcinfo->args[0]) == (*(int *)fcinfo->args[1]);
}
inline void int_not_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(int *)fcinfo->args[0]) != (*(int *)fcinfo->args[1]);
}
inline void int_great_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(int *)fcinfo->args[0]) >= (*(int *)fcinfo->args[1]);
}
inline void int_less_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(int *)fcinfo->args[0]) < (*(int *)fcinfo->args[1]);
}
inline void int_less_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(int *)fcinfo->args[0]) <= (*(int *)fcinfo->args[1]);
}
inline void int_negative_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 1);
  *(int *)fcinfo->results = (*(int *)fcinfo->args[0] * (-1));
}
/*******************int*************************/

/*******************u_long*************************/

inline void u_long_add_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(unsigned long *)fcinfo->results = ((*(unsigned long *)fcinfo->args[0]) +
                                       (*(unsigned long *)fcinfo->args[1]));
}
inline void u_long_minus_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(unsigned long *)fcinfo->results = ((*(unsigned long *)fcinfo->args[0]) -
                                       (*(unsigned long *)fcinfo->args[1]));
}
inline void u_long_multiply_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(unsigned long *)fcinfo->results = ((*(unsigned long *)fcinfo->args[0]) *
                                       (*(unsigned long *)fcinfo->args[1]));
}
inline void u_long_divide_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  unsigned long val = *(unsigned long *)fcinfo->args[1];
  if (val == 0) {
    SQLParse_elog("The u_long_divide_old divided = 0");
    assert(false);
  }
  *(unsigned long *)fcinfo->results = ((*(unsigned long *)fcinfo->args[0]) /
                                       (*(unsigned long *)fcinfo->args[1]));
}
inline void u_long_mod_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  unsigned long val = *(unsigned long *)fcinfo->args[1];
  if (val == 0) {
    SQLParse_elog("The u_long_mod_old moded = 0");
    assert(false);
  }
  *(unsigned long *)fcinfo->results = ((*(unsigned long *)fcinfo->args[0]) %
                                       (*(unsigned long *)fcinfo->args[1]));
}
inline void u_long_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(unsigned long *)fcinfo->args[0] == *(unsigned long *)fcinfo->args[1]);
}
inline void u_long_not_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results = (*(unsigned long *)fcinfo->args[0]) !=
                             (*(unsigned long *)fcinfo->args[1]);
}
inline void u_long_great_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(unsigned long *)fcinfo->args[0]) > (*(unsigned long *)fcinfo->args[1]);
}
inline void u_long_great_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results = (*(unsigned long *)fcinfo->args[0]) >=
                             (*(unsigned long *)fcinfo->args[1]);
}
inline void u_long_less_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(unsigned long *)fcinfo->args[0]) < (*(unsigned long *)fcinfo->args[1]);
}
inline void u_long_less_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results = (*(unsigned long *)fcinfo->args[0]) <=
                             (*(unsigned long *)fcinfo->args[1]);
}
/*******************u_long*************************/

/*******************float*************************/
inline void float_add_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(float *)fcinfo->results =
      ((*(float *)fcinfo->args[0]) + (*(float *)fcinfo->args[1]));
}
inline void float_minus_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(float *)fcinfo->results =
      ((*(float *)fcinfo->args[0]) - (*(float *)fcinfo->args[1]));
}
inline void float_multiply_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(float *)fcinfo->results =
      ((*(float *)fcinfo->args[0]) * (*(float *)fcinfo->args[1]));
}
inline void float_divide_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  float val = *(float *)fcinfo->args[1];
  if (val == 0) {
    SQLParse_elog("The float_divide_old divided = 0");
    assert(false);
  }
  *(float *)fcinfo->results =
      ((*(float *)fcinfo->args[0]) / (*(float *)fcinfo->args[1]));
}

inline void float_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      fabs(double((*(float *)fcinfo->args[0]) - (*(float *)fcinfo->args[1]))) <
      DELTA;
}
inline void float_not_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  float_equal_old(fcinfo);
  *(bool *)fcinfo->results = !(*(bool *)fcinfo->results);
}
inline void float_great_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(float *)fcinfo->args[0]) > (*(float *)fcinfo->args[1]);
}
inline void float_great_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(float *)fcinfo->args[0]) >= (*(float *)fcinfo->args[1]);
}
inline void float_less_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(float *)fcinfo->args[0]) < (*(float *)fcinfo->args[1]);
}
inline void float_less_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(float *)fcinfo->args[0]) <= (*(float *)fcinfo->args[1]);
}
inline void float_negative_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 1);
  *(float *)fcinfo->results = ((*(float *)fcinfo->args[0]) * (-1));
}
/*******************float*************************/

/*******************double*************************/

inline void double_add(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(double *)fcinfo->results =
      ((*(double *)fcinfo->args[0]) + (*(double *)fcinfo->args[1]));
}
inline void double_minus(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(double *)fcinfo->results =
      ((*(double *)fcinfo->args[0]) - (*(double *)fcinfo->args[1]));
}
inline void double_multiply(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(double *)fcinfo->results =
      ((*(double *)fcinfo->args[0]) * (*(double *)fcinfo->args[1]));
}
inline void double_divide(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  double val = *(double *)fcinfo->args[1];
  if (val == 0) {
    SQLParse_elog("The double_divide divided = 0");
    assert(false);
  }
  *(double *)fcinfo->results =
      ((*(double *)fcinfo->args[0]) / (*(double *)fcinfo->args[1]));
}

inline void double_equal(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      fabs(*(double *)fcinfo->args[0] - *(double *)fcinfo->args[1]) < DELTA;
}
inline void double_not_equal(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  double_equal(fcinfo);
  *(bool *)fcinfo->results = !(*(bool *)fcinfo->results);
}
inline void double_great(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(double *)fcinfo->args[0] > *(double *)fcinfo->args[1]);
}
inline void double_great_equal(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(double *)fcinfo->args[0] >= *(double *)fcinfo->args[1]);
}
inline void double_less(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  bool ans = 1;
  *(bool *)fcinfo->results =
      (*(double *)fcinfo->args[0] < *(double *)fcinfo->args[1]);
}
inline void double_less_equal(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(double *)fcinfo->args[0] <= *(double *)fcinfo->args[1]);
}
inline void double_negative_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 1);
  *(double *)fcinfo->results = ((*(double *)fcinfo->args[0]) * (-1));
}
/*******************double*************************/

/*******************smallInt*************************/

inline void smallInt_add_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(short int *)fcinfo->results =
      (*(short int *)fcinfo->args[0]) + (*(short int *)fcinfo->args[1]);
}
inline void smallInt_minus_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(short int *)fcinfo->results =
      (*(short int *)fcinfo->args[0]) - (*(short int *)fcinfo->args[1]);
}
inline void smallInt_multiply_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(short int *)fcinfo->results =
      (*(short int *)fcinfo->args[0]) * (*(short int *)fcinfo->args[1]);
}
inline void smallInt_divide_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  short int val = *(short int *)fcinfo->args[1];
  if (val == 0) {
    SQLParse_elog("The smallInt_divide_old divided = 0");
    assert(false);
  }
  *(short int *)fcinfo->results =
      (*(short int *)fcinfo->args[0]) / (*(short int *)fcinfo->args[1]);
}
inline void smallInt_mod_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  short int val = *(short int *)fcinfo->args[1];
  if (val == 0) {
    SQLParse_elog("The smallInt_mod_old moded = 0");
    assert(false);
  }
  *(short int *)fcinfo->results =
      (*(short int *)fcinfo->args[0] % (*(short int *)fcinfo->args[1]));
}
inline void smallInt_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(short int *)fcinfo->args[0] == *(short int *)fcinfo->args[1]);
}
inline void smallInt_not_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(short int *)fcinfo->args[0] != *(short int *)fcinfo->args[1]);
}
inline void smallInt_great_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(short int *)fcinfo->args[0] > *(short int *)fcinfo->args[1]);
}
inline void smallInt_great_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(short int *)fcinfo->args[0] >= *(short int *)fcinfo->args[1]);
}
inline void smallInt_less_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(short int *)fcinfo->args[0] < *(short int *)fcinfo->args[1]);
}
inline void smallInt_less_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(short int *)fcinfo->args[0] <= *(short int *)fcinfo->args[1]);
}
inline void smallInt_negative_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 1);
  *(short int *)fcinfo->results = (*(short int *)fcinfo->args[0] * (-1));
}
/*******************smallInt*************************/

/*****************boolean********************/

inline void boolean_and_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      ((*(bool *)fcinfo->args[0]) && (*(bool *)fcinfo->args[1]));
}
inline void boolean_or_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      ((*(bool *)fcinfo->args[0]) || (*(bool *)fcinfo->args[1]));
}
inline void boolean_xor_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      ((*(bool *)fcinfo->args[0]) ^ (*(bool *)fcinfo->args[1]));
}
inline void boolean_not_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 1);
  *(bool *)fcinfo->results = (!(*(bool *)fcinfo->args[0]));
}
inline void boolean_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(bool *)fcinfo->args[0] == *(bool *)fcinfo->args[1]);
}
inline void boolean_not_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(bool *)fcinfo->args[0] != *(bool *)fcinfo->args[1]);
}
inline void boolean_great_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(bool *)fcinfo->args[0] > *(bool *)fcinfo->args[1]);
}
inline void boolean_great_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(bool *)fcinfo->args[0] >= *(bool *)fcinfo->args[1]);
}
inline void boolean_less_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(bool *)fcinfo->args[0] < *(bool *)fcinfo->args[1]);
}
inline void boolean_less_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(bool *)fcinfo->args[0] <= *(bool *)fcinfo->args[1]);
}
/*****************boolean********************/

/*****************decimal********************/
inline void decimal_add_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(NValue *)fcinfo->results =
      (*(NValue *)fcinfo->args[0]).op_add(*(NValue *)fcinfo->args[1]);
}
inline void decimal_minus_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(NValue *)fcinfo->results =
      (*(NValue *)fcinfo->args[0]).op_subtract(*(NValue *)fcinfo->args[1]);
}
inline void decimal_multiply_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(NValue *)fcinfo->results =
      (*(NValue *)fcinfo->args[0]).op_multiply(*(NValue *)fcinfo->args[1]);
}
inline void decimal_divide_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(NValue *)fcinfo->results =
      (*(NValue *)fcinfo->args[0]).op_divide(*(NValue *)fcinfo->args[1]);
}
inline void decimal_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(NValue *)fcinfo->args[0]).op_equals(*(NValue *)fcinfo->args[1]);
}
inline void decimal_not_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(NValue *)fcinfo->args[0]).op_not_equals(*(NValue *)fcinfo->args[1]);
}
inline void decimal_great_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(NValue *)fcinfo->args[0]).op_great(*(NValue *)fcinfo->args[1]);
}
inline void decimal_great_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(NValue *)fcinfo->args[0]).op_great_equals(*(NValue *)fcinfo->args[1]);
}
inline void decimal_less_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(NValue *)fcinfo->args[0]).op_less(*(NValue *)fcinfo->args[1]);
}
inline void decimal_less_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(NValue *)fcinfo->args[0]).op_less_equals(*(NValue *)fcinfo->args[1]);
}
inline void decimal_negative_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 1);
  *(NValue *)fcinfo->results = (*(NValue *)fcinfo->args[0]).op_multiply(
      NValue::getDecimalValueFromString("-1"));
}
/*****************decimal********************/

/*****************string********************/
// the limit is the left should be column

inline void string_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (strcmp((char *)fcinfo->args[0], (char *)fcinfo->args[1]) == 0);
}
inline void string_not_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (strcmp((char *)fcinfo->args[0], (char *)fcinfo->args[1]) != 0);
}
inline void string_great_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (strcmp((char *)fcinfo->args[0], (char *)fcinfo->args[1]) > 0);
}
inline void string_great_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (strcmp((char *)fcinfo->args[0], (char *)fcinfo->args[1]) >= 0);
}
inline void string_less_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (strcmp((char *)fcinfo->args[0], (char *)fcinfo->args[1]) < 0);
}
inline void string_less_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (strcmp((char *)fcinfo->args[0], (char *)fcinfo->args[1]) <= 0);
}
inline void string_both_trim_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  int begin = 0, end = strlen((char *)fcinfo->args[1]) - 1;
  for (; ((char *)fcinfo->args[1])[begin] == ((char *)fcinfo->args[0])[0] &&
             ((char *)fcinfo->args[1])[begin] != '\0';
       begin++)
    ;
  if (end > begin)
    for (; ((char *)fcinfo->args[1])[end] == ((char *)fcinfo->args[0])[0] &&
               end >= 0;
         end--)
      ;
  strncpy((char *)fcinfo->results, (char *)fcinfo->args[1] + begin,
          end - begin + 1);
  ((char *)fcinfo->results)[end - begin + 1] = '\0';
}
inline void string_leading_trim_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  int begin = 0, end = strlen((char *)fcinfo->args[1]) - 1;
  for (; ((char *)fcinfo->args[1])[begin] == ((char *)fcinfo->args[0])[0] &&
             ((char *)fcinfo->args[1])[begin] != '\0';
       begin++)
    ;
  strncpy((char *)fcinfo->results, (char *)fcinfo->args[1] + begin,
          end - begin + 1);
  ((char *)fcinfo->results)[end - begin + 1] = '\0';
}
inline void string_trailing_trim_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  int begin = 0, end = strlen((char *)fcinfo->args[1]) - 1;
  for (; ((char *)fcinfo->args[1])[end] == ((char *)fcinfo->args[0])[0] &&
             end >= 0;
       end--)
    ;
  strncpy((char *)fcinfo->results, (char *)fcinfo->args[1] + begin,
          end - begin + 1);
  ((char *)fcinfo->results)[end - begin + 1] = '\0';
}
inline void string_like_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (MatchText((char *)fcinfo->args[0], strlen((char *)fcinfo->args[0]),
                 (char *)fcinfo->args[1],
                 strlen((char *)fcinfo->args[1])) == 1);
}
inline void string_not_like_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (MatchText((char *)fcinfo->args[0], strlen((char *)fcinfo->args[0]),
                 (char *)fcinfo->args[1],
                 strlen((char *)fcinfo->args[1])) != 1);
}
inline void string_upper_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 1);
  strcpy((char *)fcinfo->results, (char *)fcinfo->args[0]);
  int len = strlen((char *)fcinfo->args[0]);
  for (int i = 0; i < len; i++) {
    if (((char *)fcinfo->results)[i] >= 'a' &&
        ((char *)fcinfo->results)[i] <= 'z')
      ((char *)fcinfo->results)[i] -= 32;
  }
  ((char *)fcinfo->results)[len] = '\0';
}
inline void string_substring_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 3);
  strncpy((char *)fcinfo->results,
          ((char *)fcinfo->args[0]) + (*(int *)fcinfo->args[1]),
          (*(int *)fcinfo->args[2]) - (*(int *)fcinfo->args[1]));
}

/*****************string********************/

/*****************date********************/
inline void date_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(date *)fcinfo->args[0] == *(date *)fcinfo->args[1]);
}
inline void date_not_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(date *)fcinfo->args[0] != *(date *)fcinfo->args[1]);
}
inline void date_great_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(date *)fcinfo->args[0] > *(date *)fcinfo->args[1]);
}
inline void date_great_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(date *)fcinfo->args[0] >= *(date *)fcinfo->args[1]);
}
inline void date_less_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(date *)fcinfo->args[0] < *(date *)fcinfo->args[1]);
}
inline void date_less_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(date *)fcinfo->args[0] <= *(date *)fcinfo->args[1]);
}

inline void date_add_day_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(date *)fcinfo->results =
      (*(date *)fcinfo->args[0]) + (*(date_duration *)fcinfo->args[1]);
}
inline void date_add_week_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  // *(date *)fcinfo->results=(*(date *)fcinfo->args[0])+(*(weeks
  // *)fcinfo->args[1]);
}

inline void date_add_month_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  // *(date *)fcinfo->results=(*(date *)fcinfo->args[0])+(*(months
  // *)fcinfo->args[1]);
}

inline void date_add_year_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  // *(date *)fcinfo->results=(*(date *)fcinfo->args[0])+(*(years
  // *)fcinfo->args[1]);
}

inline void date_sub_day_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(date *)fcinfo->results =
      (*(date *)fcinfo->args[0]) - (*(date_duration *)fcinfo->args[1]);
}
inline void date_sub_week_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  // *(date *)fcinfo->results=(*(date *)fcinfo->args[0])-(*(weeks
  // *)fcinfo->args[1]);
}
inline void date_sub_month_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  // *(date *)fcinfo->results=(*(date *)fcinfo->args[0])-(*(months
  // *)fcinfo->args[1]);
}
inline void date_sub_year_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  // *(date *)fcinfo->results=(*(date *)fcinfo->args[0])-(*(years
  // *)fcinfo->args[1]);
}

/*****************date********************/

/*****************time********************/
inline void time_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(time_duration *)fcinfo->args[0] == *(time_duration *)fcinfo->args[1]);
}
inline void time_not_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(time_duration *)fcinfo->args[0] != *(time_duration *)fcinfo->args[1]);
}
inline void time_great_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(time_duration *)fcinfo->args[0] > *(time_duration *)fcinfo->args[1]);
}
inline void time_great_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(time_duration *)fcinfo->args[0] >= *(time_duration *)fcinfo->args[1]);
}
inline void time_less_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(time_duration *)fcinfo->args[0] < *(time_duration *)fcinfo->args[1]);
}
inline void time_less_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(time_duration *)fcinfo->args[0] <= *(time_duration *)fcinfo->args[1]);
}
/*****************time********************/

/*****************datetime********************/
inline void datetime_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(ptime *)fcinfo->args[0] == *(ptime *)fcinfo->args[1]);
}
inline void datetime_not_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(ptime *)fcinfo->args[0] != *(ptime *)fcinfo->args[1]);
}
inline void datetime_great_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(ptime *)fcinfo->args[0] > *(ptime *)fcinfo->args[1]);
}
inline void datetime_great_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(ptime *)fcinfo->args[0] >= *(ptime *)fcinfo->args[1]);
}
inline void datetime_less_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(ptime *)fcinfo->args[0] < *(ptime *)fcinfo->args[1]);
}
inline void datetime_less_equal_old(FuncCallInfo fcinfo) {
  assert(fcinfo->nargs == 2);
  *(bool *)fcinfo->results =
      (*(ptime *)fcinfo->args[0] <= *(ptime *)fcinfo->args[1]);
}
/*****************datetime********************/
inline void initialize_operator_function() {
  for (int i = 0; i < DATA_TYPE_NUM; i++)
    for (int j = 0; j < OPER_TYPE_NUM; j++)
      ExectorFunction::operator_function[i][j] = oper_not_support_old;
  /*****************int********************/
  ExectorFunction::operator_function[t_int][oper_add_old] = int_add_old;
  ExectorFunction::operator_function[t_int][oper_minus_old] = int_minus_old;
  ExectorFunction::operator_function[t_int][oper_multiply_old] =
      int_multiply_old;
  ExectorFunction::operator_function[t_int][oper_divide_old] = int_divide_old;
  ExectorFunction::operator_function[t_int][oper_mod_old] = int_mod_old;
  ExectorFunction::operator_function[t_int][oper_and_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_int][oper_or_old] = oper_not_support_old;
  ExectorFunction::operator_function[t_int][oper_xor_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_int][oper_not_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_int][oper_equal_old] = int_equal_old;
  ExectorFunction::operator_function[t_int][oper_not_equal_old] =
      int_not_equal_old;
  ExectorFunction::operator_function[t_int][oper_great_old] = int_not_equal_old;
  ExectorFunction::operator_function[t_int][oper_great_equal_old] =
      int_great_equal_old;
  ExectorFunction::operator_function[t_int][oper_less_old] = int_less_old;
  ExectorFunction::operator_function[t_int][oper_less_equal_old] =
      int_less_equal_old;
  ExectorFunction::operator_function[t_int][oper_negative_old] =
      int_negative_old;

  /*****************int********************/

  /*****************ulong********************/
  ExectorFunction::operator_function[t_u_long][oper_add_old] = u_long_add_old;
  ExectorFunction::operator_function[t_u_long][oper_minus_old] =
      u_long_minus_old;
  ExectorFunction::operator_function[t_u_long][oper_multiply_old] =
      u_long_multiply_old;
  ExectorFunction::operator_function[t_u_long][oper_divide_old] =
      u_long_divide_old;
  ExectorFunction::operator_function[t_u_long][oper_mod_old] = u_long_mod_old;
  ExectorFunction::operator_function[t_u_long][oper_and_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_u_long][oper_or_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_u_long][oper_xor_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_u_long][oper_not_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_u_long][oper_equal_old] =
      u_long_equal_old;
  ExectorFunction::operator_function[t_u_long][oper_not_equal_old] =
      u_long_not_equal_old;
  ExectorFunction::operator_function[t_u_long][oper_great_old] =
      u_long_great_old;
  ExectorFunction::operator_function[t_u_long][oper_great_equal_old] =
      u_long_great_equal_old;
  ExectorFunction::operator_function[t_u_long][oper_less_old] = u_long_less_old;
  ExectorFunction::operator_function[t_u_long][oper_less_equal_old] =
      u_long_less_equal_old;
  ExectorFunction::operator_function[t_u_long][oper_negative_old] =
      oper_not_support_old;

  /*****************ulong********************/

  /*****************float********************/
  ExectorFunction::operator_function[t_float][oper_add_old] = float_add_old;
  ExectorFunction::operator_function[t_float][oper_minus_old] = float_minus_old;
  ExectorFunction::operator_function[t_float][oper_multiply_old] =
      float_multiply_old;
  ExectorFunction::operator_function[t_float][oper_divide_old] =
      float_divide_old;
  ExectorFunction::operator_function[t_float][oper_mod_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_float][oper_and_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_float][oper_or_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_float][oper_xor_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_float][oper_not_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_float][oper_equal_old] = float_equal_old;
  ExectorFunction::operator_function[t_float][oper_not_equal_old] =
      float_not_equal_old;
  ExectorFunction::operator_function[t_float][oper_great_old] = float_great_old;
  ExectorFunction::operator_function[t_float][oper_great_equal_old] =
      float_great_equal_old;
  ExectorFunction::operator_function[t_float][oper_less_old] = float_less_old;
  ExectorFunction::operator_function[t_float][oper_less_equal_old] =
      float_less_equal_old;
  ExectorFunction::operator_function[t_float][oper_negative_old] =
      float_negative_old;

  /*****************float********************/

  /*****************double********************/

  ExectorFunction::operator_function[t_double][oper_add_old] = double_add;
  ExectorFunction::operator_function[t_double][oper_minus_old] = double_minus;
  ExectorFunction::operator_function[t_double][oper_multiply_old] =
      double_multiply;
  ExectorFunction::operator_function[t_double][oper_divide_old] = double_divide;
  ExectorFunction::operator_function[t_double][oper_mod_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_double][oper_and_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_double][oper_or_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_double][oper_xor_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_double][oper_not_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_double][oper_equal_old] = double_equal;
  ExectorFunction::operator_function[t_double][oper_not_equal_old] =
      double_not_equal;
  ExectorFunction::operator_function[t_double][oper_great_old] = double_great;
  ExectorFunction::operator_function[t_double][oper_great_equal_old] =
      double_great_equal;
  ExectorFunction::operator_function[t_double][oper_less_old] = double_less;
  ExectorFunction::operator_function[t_double][oper_less_equal_old] =
      double_less_equal;
  ExectorFunction::operator_function[t_double][oper_negative_old] =
      double_negative_old;

  /*****************double********************/

  /*****************smallInt********************/
  ExectorFunction::operator_function[t_smallInt][oper_add_old] =
      smallInt_add_old;
  ExectorFunction::operator_function[t_smallInt][oper_minus_old] =
      smallInt_minus_old;
  ExectorFunction::operator_function[t_smallInt][oper_multiply_old] =
      smallInt_multiply_old;
  ExectorFunction::operator_function[t_smallInt][oper_divide_old] =
      smallInt_divide_old;
  ExectorFunction::operator_function[t_smallInt][oper_mod_old] =
      smallInt_mod_old;
  ExectorFunction::operator_function[t_smallInt][oper_and_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_smallInt][oper_or_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_smallInt][oper_xor_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_smallInt][oper_not_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_smallInt][oper_equal_old] =
      smallInt_equal_old;
  ExectorFunction::operator_function[t_smallInt][oper_not_equal_old] =
      smallInt_not_equal_old;
  ExectorFunction::operator_function[t_smallInt][oper_great_old] =
      smallInt_great_old;
  ExectorFunction::operator_function[t_smallInt][oper_great_equal_old] =
      smallInt_great_equal_old;
  ExectorFunction::operator_function[t_smallInt][oper_less_old] =
      smallInt_less_old;
  ExectorFunction::operator_function[t_smallInt][oper_less_equal_old] =
      smallInt_less_equal_old;
  ExectorFunction::operator_function[t_smallInt][oper_negative_old] =
      smallInt_negative_old;

  /*****************smallInt********************/

  /*****************boolean********************/
  ExectorFunction::operator_function[t_boolean][oper_add_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_boolean][oper_minus_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_boolean][oper_multiply_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_boolean][oper_divide_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_boolean][oper_mod_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_boolean][oper_and_old] = boolean_and_old;
  ExectorFunction::operator_function[t_boolean][oper_or_old] = boolean_or_old;
  ExectorFunction::operator_function[t_boolean][oper_xor_old] = boolean_xor_old;
  ExectorFunction::operator_function[t_boolean][oper_not_old] = boolean_not_old;
  ExectorFunction::operator_function[t_boolean][oper_equal_old] =
      boolean_equal_old;
  ExectorFunction::operator_function[t_boolean][oper_not_equal_old] =
      boolean_not_equal_old;
  ExectorFunction::operator_function[t_boolean][oper_great_old] =
      boolean_great_old;
  ExectorFunction::operator_function[t_boolean][oper_great_equal_old] =
      boolean_great_equal_old;
  ExectorFunction::operator_function[t_boolean][oper_less_old] =
      boolean_less_old;
  ExectorFunction::operator_function[t_boolean][oper_less_equal_old] =
      boolean_less_equal_old;
  ExectorFunction::operator_function[t_boolean][oper_negative_old] =
      oper_not_support_old;

  /*****************boolean********************/

  /*****************decimal********************/

  ExectorFunction::operator_function[t_decimal][oper_add_old] = decimal_add_old;
  ExectorFunction::operator_function[t_decimal][oper_minus_old] =
      decimal_minus_old;
  ExectorFunction::operator_function[t_decimal][oper_multiply_old] =
      decimal_multiply_old;
  ExectorFunction::operator_function[t_decimal][oper_divide_old] =
      decimal_divide_old;
  ExectorFunction::operator_function[t_decimal][oper_mod_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_decimal][oper_and_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_decimal][oper_or_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_decimal][oper_xor_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_decimal][oper_not_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_decimal][oper_equal_old] =
      decimal_equal_old;
  ExectorFunction::operator_function[t_decimal][oper_not_equal_old] =
      decimal_not_equal_old;
  ExectorFunction::operator_function[t_decimal][oper_great_old] =
      decimal_great_old;
  ExectorFunction::operator_function[t_decimal][oper_great_equal_old] =
      decimal_great_equal_old;
  ExectorFunction::operator_function[t_decimal][oper_less_old] =
      decimal_less_old;
  ExectorFunction::operator_function[t_decimal][oper_less_equal_old] =
      decimal_less_equal_old;
  ExectorFunction::operator_function[t_decimal][oper_negative_old] =
      decimal_negative_old;

  /*****************decimal********************/

  /*****************string********************/
  ExectorFunction::operator_function[t_string][oper_add_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_string][oper_minus_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_string][oper_multiply_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_string][oper_divide_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_string][oper_mod_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_string][oper_and_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_string][oper_or_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_string][oper_xor_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_string][oper_not_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_string][oper_equal_old] =
      string_equal_old;
  ExectorFunction::operator_function[t_string][oper_not_equal_old] =
      string_not_equal_old;
  ExectorFunction::operator_function[t_string][oper_great_old] =
      string_great_old;
  ExectorFunction::operator_function[t_string][oper_great_equal_old] =
      string_great_equal_old;
  ExectorFunction::operator_function[t_string][oper_less_old] = string_less_old;
  ExectorFunction::operator_function[t_string][oper_less_equal_old] =
      string_less_equal_old;

  ExectorFunction::operator_function[t_string][oper_both_trim_old] =
      string_both_trim_old;
  ExectorFunction::operator_function[t_string][oper_leading_trim_old] =
      string_leading_trim_old;
  ExectorFunction::operator_function[t_string][oper_trailing_trim_old] =
      string_trailing_trim_old;
  ExectorFunction::operator_function[t_string][oper_like_old] = string_like_old;
  ExectorFunction::operator_function[t_string][oper_not_like_old] =
      string_not_like_old;
  ExectorFunction::operator_function[t_string][oper_upper_old] =
      string_upper_old;
  ExectorFunction::operator_function[t_string][oper_substring_old] =
      string_substring_old;

  /*****************string********************/

  /*****************date********************/
  ExectorFunction::operator_function[t_date][oper_add_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_date][oper_minus_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_date][oper_multiply_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_date][oper_divide_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_date][oper_mod_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_date][oper_and_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_date][oper_or_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_date][oper_xor_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_date][oper_not_old] =
      oper_not_support_old;
  ExectorFunction::operator_function[t_date][oper_equal_old] = date_equal_old;
  ExectorFunction::operator_function[t_date][oper_not_equal_old] =
      date_not_equal_old;
  ExectorFunction::operator_function[t_date][oper_great_old] = date_great_old;
  ExectorFunction::operator_function[t_date][oper_great_equal_old] =
      date_great_equal_old;
  ExectorFunction::operator_function[t_date][oper_less_old] = date_less_old;
  ExectorFunction::operator_function[t_date][oper_less_equal_old] =
      date_less_equal_old;
  ExectorFunction::operator_function[t_date][oper_negative_old] =
      oper_not_support_old;

  ExectorFunction::operator_function[t_date][oper_date_add_day_old] =
      date_add_day_old;
  ExectorFunction::operator_function[t_date][oper_date_add_week_old] =
      date_add_week_old;
  ExectorFunction::operator_function[t_date][oper_date_add_month_old] =
      date_add_month_old;
  ExectorFunction::operator_function[t_date][oper_date_add_year_old] =
      date_add_year_old;
  ExectorFunction::operator_function[t_date][oper_date_sub_day_old] =
      date_sub_day_old;
  ExectorFunction::operator_function[t_date][oper_date_sub_week_old] =
      date_sub_week_old;
  ExectorFunction::operator_function[t_date][oper_date_sub_month_old] =
      date_sub_month_old;
  ExectorFunction::operator_function[t_date][oper_date_sub_year_old] =
      date_sub_year_old;

  /*****************date********************/

  /*****************time********************/
  ExectorFunction::operator_function[t_time][oper_equal_old] = time_equal_old;
  ExectorFunction::operator_function[t_time][oper_not_equal_old] =
      time_not_equal_old;
  ExectorFunction::operator_function[t_time][oper_great_old] = time_great_old;
  ExectorFunction::operator_function[t_time][oper_great_equal_old] =
      time_great_equal_old;
  ExectorFunction::operator_function[t_time][oper_less_old] = time_less_old;
  ExectorFunction::operator_function[t_time][oper_less_equal_old] =
      time_less_equal_old;

  /*****************time********************/

  /*****************datetime********************/
  ExectorFunction::operator_function[t_datetime][oper_equal_old] =
      datetime_equal_old;
  ExectorFunction::operator_function[t_datetime][oper_not_equal_old] =
      datetime_not_equal_old;
  ExectorFunction::operator_function[t_datetime][oper_great_old] =
      datetime_great_old;
  ExectorFunction::operator_function[t_datetime][oper_great_equal_old] =
      datetime_great_equal_old;
  ExectorFunction::operator_function[t_datetime][oper_less_old] =
      datetime_less_old;
  ExectorFunction::operator_function[t_datetime][oper_less_equal_old] =
      datetime_less_equal_old;
  /*****************datetime********************/
}
inline void avg_error_divide_old(void *sum_value, unsigned long tuple_number,
                                 void *result) {
  SQLParse_elog("This oper_functions is not supported now!!!!!!!!!!!!!");
  assert(false);
}
inline void avg_int_divide_old(void *sum_value, unsigned long tuple_number,
                               void *result) {
  *(int *)result = (*(int *)sum_value / tuple_number);
}
inline void avg_float_divide_old(void *sum_value, unsigned long tuple_number,
                                 void *result) {
  *(float *)result = *(float *)sum_value / tuple_number;
}
inline void avg_double_divide_old(void *sum_value, unsigned long tuple_number,
                                  void *result) {
  *(double *)result = *(double *)sum_value / tuple_number;
}
inline void avg_ulong_divide_old(void *sum_value, unsigned long tuple_number,
                                 void *result) {
  *(unsigned long *)result = *(unsigned long *)sum_value / tuple_number;
}
inline void avg_smallint_divide_old(void *sum_value, unsigned long tuple_number,
                                    void *result) {
  *(short *)result = (*(short *)sum_value / tuple_number);
}
inline void avg_usmallint_divide_old(void *sum_value,
                                     unsigned long tuple_number, void *result) {
  *(unsigned short *)result = (*(unsigned short *)sum_value / tuple_number);
}
inline void avg_decimal_divide_old(void *sum_value, unsigned long tuple_number,
                                   void *result) {
  *(NValue *)result = *(NValue *)sum_value;
  stringstream ss;
  ss << tuple_number;
  *(NValue *)result = (*(NValue *)result).op_divide(
      (*(NValue *)result).getDecimalValueFromString(ss.str()));
}

/*
 *avg=sum/tuple_number, use avg_divid[type] to avoid switching among all types
 *typedef void (*AvgDivide)(void *sum_value,unsigned long tuple_number,void
 **result); in qnode.h
 *AvgDivide ExectorFunction::avg_divide[DATA_TYPE_NUM]; in queryfunc.h
 */
inline void InitAvgDivide() {
  for (int i = 0; i < DATA_TYPE_NUM; i++)
    ExectorFunction::avg_divide_old[i] = avg_error_divide_old;
  ExectorFunction::avg_divide_old[t_int] = avg_int_divide_old;
  ExectorFunction::avg_divide_old[t_float] = avg_float_divide_old;
  ExectorFunction::avg_divide_old[t_double] = avg_double_divide_old;
  ExectorFunction::avg_divide_old[t_u_long] = avg_ulong_divide_old;
  ExectorFunction::avg_divide_old[t_smallInt] = avg_smallint_divide_old;
  ExectorFunction::avg_divide_old[t_u_smallInt] = avg_usmallint_divide_old;
  ExectorFunction::avg_divide_old[t_decimal] = avg_decimal_divide_old;
}
#endif /* QUERYFUNC_H_ */
