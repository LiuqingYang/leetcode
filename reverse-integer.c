// https://leetcode.com/problems/reverse-integer/
// Yang Liuqing
// yllqq@outlook.com

//Be careful about int overflow

#include <stdio.h>
#include <stdint.h>

int reverse(int x) {
    int sign_ret;
    int64_t ret = 0;

    if (x > 0)
    {
        sign_ret = 1;
    }
    else
    {
        sign_ret = -1;
        x = -x;
    }

    while (x)
    {
        ret = ret * 10 + (x % 10);
        x = x / 10;
    }
    ret = ret * sign_ret;

    if ((int)ret != ret)
    {
      //printf("Overflow\n");
      ret = 0;
    }

    return ret;
}

void test_reverse(int x)
{
  int rever = reverse(x);
  printf("Reverse of %d is %d\n", x, rever);
}

int main()
{
  test_reverse(1);
  test_reverse(123);
  test_reverse(-123);
  test_reverse(-1);
  test_reverse(1534236469);
}
