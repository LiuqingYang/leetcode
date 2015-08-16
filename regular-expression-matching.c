// https://leetcode.com/problems/regular-expression-matching/
// Yang Liuqing
// yllqq@outlook.com

// Caution to Boundary conditions

#include "header.h"

bool isMatch(char* s, char* p) {
  char last_ch = 0;
  char exp_ch = *p;
  char exp_ch_next = *p;

  while (*s && *p)
  {
    char ch = *s;
    exp_ch = exp_ch_next;
    exp_ch_next = *(p+1);

    if (exp_ch_next != '*')
    {
      if (exp_ch != '.')
      {
          if (exp_ch == '*')
          {
            char* ps = s;
            char* pp = p + 1;

            while (*ps)
            {
              if (last_ch != '.' && *ps != last_ch) break;
              //printf("DEBUG: recursive isMatch(%s, %s)\n", ps, pp);
              if (isMatch(ps, pp)) return true;
              ps++;
            }

            //printf("DEBUG: recursive isMatch(%s, %s)\n", ps, pp);
            if (isMatch(ps, pp)) return true;
            else return false;
          }
          else if (ch != exp_ch) return false;
      }

      s++;
      p++;
    }
    else
    {
        last_ch = exp_ch;
        p++;
    }
  }

  if (*s == *p) return true;
  else if (*s == 0)
  {
    //printf("DEBUG: tail %s\n", p);
    while (*p)
    {
      char exp_ch_next = *(p+1);
      if (exp_ch_next == '*') p += 2;
      else return false;
    }
    return true;
  }

  return false;
}

void test_match(char *s, char *p)
{
  char *result = isMatch(s, p) ? "true" : "false";
  printf("isMatch(\"%s\", \"%s\") -> %s\n", s, p, result);
}

int main()
{
  test_match("a", "ab*");
  test_match("aa", "a");
  test_match("aa", "aa");
  test_match("aaa", "aa");
  test_match("aa", "a*");
  test_match("aa", ".*");
  test_match("ab", ".*");
  test_match("aab", "c*a*b");
}
