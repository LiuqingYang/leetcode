// https://leetcode.com/problems/roman-to-integer/
// Yang Liuqing
// yllqq@outlook.com

// Careful about array out of bound

#include "header.h"

int romanToInt(char* s) {
  static char symbols[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M', 'e', 'e'};

  int ret = 0;
  int m = 1000;
  int n = 6;

  while (m != 0) {
    char *sym_array = symbols + n;
    int prefix = 0;
    int suffix = 0;
    int num = 0;

    while (*s == sym_array[0]) {
      prefix++;
      s++;
    }

    if (*s == sym_array[1]) {
      s++;
      while (*s == sym_array[0]) {
        suffix++;
        s++;
      }
      num = 5 - prefix + suffix;
    }
    else if (*s == sym_array[2]) {
      s++;
      num = 10 - prefix;
    }
    else {
      num = prefix;
    }

    ret += m * num;
    m /= 10;
    n -= 2;
  }

  return ret;
}

void test_rti(char *s)
{
  printf("%s to int is: %d\n", s, romanToInt(s));
}

int main()
{
  test_rti("MCMLIV");
  test_rti("MCMXC");
  test_rti("MMXIV");
  test_rti("MMM");
}
