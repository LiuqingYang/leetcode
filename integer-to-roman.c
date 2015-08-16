// https://leetcode.com/problems/integer-to-roman/
// Yang Liuqing
// yllqq@outlook.com

// Careful about array out of bound

#include "header.h"

char* intToRoman(int num) {
  static char symbols[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M', 'e'};
  static char numerals[9][5] = {{0, -1}, {0, 0, -1}, {0, 0, 0, -1}, {0, 1, -1},
    {1, -1}, {1, 0, -1}, {1, 0, 0, -1}, {1, 0, 0, 0, -1}, {0, 2, -1}};

  char *ret = malloc(20);
  char *p = ret;
  int m = 1000;
  int n = 6;

  while (m != 0)
  {
    if (num >= m)
    {
      int value = num / m - 1;
      char *add_array = numerals[value];
      char *sym_array = symbols + n;

      while (*add_array != -1)
      {
        *p++ = sym_array[*add_array++];
      }
      num -= (num / m) * m;
    }

    m /= 10;
    n -= 2;
  }

  *p++ = '\0';
  return ret;
}

void test_itr(int num)
{
  printf("%d to Roman is %s\n", num, intToRoman(num));
}

int main()
{
  test_itr(1954);
  test_itr(1990);
  test_itr(2014);

}
