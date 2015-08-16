// https://leetcode.com/problems/string-to-integer-atoi/
// Yang Liuqing
// yllqq@outlook.com

// Carefully consider all possible input cases.
// Overflow needs consider correctly also

#include "header.h"

int myAtoi(char* str) {
  int sign = 1;
  int ret = 0;
  char ch;

  while (*str == ' ') str++;
  if (*str == '-')
  {
    str++;
    sign = -1;
  }
  else if (*str == '+')
  {
    str++;
  }

  while ((ch = *str++) != 0)
  {
    int new_ret;

    if (ch > '9' || ch < '0') break;
    new_ret = ret * 10;
    if ((new_ret / 10) != ret)
      return (sign == 1) ? INT_MAX : INT_MIN;
    new_ret += ch - '0';
    if ((new_ret < 0))
      return (sign == 1) ? INT_MAX : INT_MIN;

    ret = new_ret;
  }

  return ret * sign;
}

void test_atio(char *str)
{
  printf("Return of myAtio(%s) is %d\n", str, myAtoi(str));
}

int main()
{
  test_atio("2147483648");
  test_atio("df");
  test_atio("0");
  test_atio("223");
  test_atio("-332");
  test_atio("11111111111111");
  test_atio("-2222222222222222");
  test_atio("    010");
  test_atio("    +022");
  test_atio("    788asdfsaf");
}
