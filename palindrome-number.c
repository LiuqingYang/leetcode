// https://leetcode.com/problems/palindrome-number/
// Yang Liuqing
// yllqq@outlook.com

// First submit success!

#include "header.h"

bool isPalindrome(int x) {
  int tmp_x = x;
  int exp = 1;

  if (x < 0) return false;

  while((tmp_x /= 10) != 0) exp *= 10;

  while (x)
  {
    int first = x / exp;
    int last = x % 10;

    printf("DEBUG:%d %d\n", first, last);
    if (first != last) return false;

    x = (x - first * exp) / 10;
    exp /= 100;
  }

  return true;
}

void test_palindrome(int x) {
  bool out  = isPalindrome(x);
  if (out) printf("%d is palindrome\n", x);
  else printf("%d is not palindrome\n", x);
}

int main()
{
  test_palindrome(1);
  test_palindrome(-1);
  test_palindrome(0);
  test_palindrome(121);
  test_palindrome(1221);

}
