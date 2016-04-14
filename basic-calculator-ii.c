#include "header.h"

/* submit code start */

int calc(int a, int b, char op) {
  if (op == '+') return a + b;
  else if (op == '-') return a - b;
  else if (op == '*') return a * b;
  else if (op == '/') return a / b;
  return -1;  //indicate a error
}

int calculate(char* s) {
  char *p = s;
  char pending_op = 0;  //0 or +-*/ level 1
  int pending_num = 0;
  char pending_op2 = 0;  //0 or +-  level 2
  int pending_num2 = 0;
  int num = 0;  // current buffer

  while (*p != 0) {
    char ch = *p;

    if (ch >= '0' && ch <= '9') {
      num = num * 10 + ch - '0';
    } else if (ch == '+' || ch == '-') {
      int result;

      if (pending_op != 0) {
        result = calc(pending_num, num, pending_op);

        if (pending_op2 != 0) {
          result = calc(pending_num2, result, pending_op2);
          pending_op2 = 0;
          pending_num2 = 0;
        }
      } else {
        result = num;
      }

      pending_op = ch;
      pending_num = result;
      num = 0;
    } else if (ch == '*' || ch == '/') {
      if (pending_op == '+' || pending_op == '-') {
        pending_op2 = pending_op;
        pending_num2 = pending_num;

        pending_op = ch;
        pending_num = num;
        num = 0;
      } else if (pending_op == '*' || pending_op == '/') {
        int result = calc(pending_num, num, pending_op);
        pending_op = ch;
        pending_num = result;
        num = 0;
      } else {
        pending_op = ch;
        pending_num = num;
        num = 0;
      }
    }

    p++;
  }

  if (pending_op != 0) {
    num = calc(pending_num, num, pending_op);
  }
  if (pending_op2 != 0) {
    num = calc(pending_num2, num, pending_op2);
  }

  return num;
}

/* submit code end */

/* unit test start */
int main()
{
  int ret;
  ret = calculate("3+2*2");
  printf("ret=%d\n", ret);  // 7
  ret = calculate(" 3/2 ");
  printf("ret=%d\n", ret);  // 1
  ret = calculate(" 3+5 / 2 +1");
  printf("ret=%d\n", ret);  // 6
  ret = calculate(" 3+5 / 2 +1 * 3 * 6 / 7 + 2 - 1 ");
  printf("ret=%d\n", ret);  // 8
}
/* unit test end */
