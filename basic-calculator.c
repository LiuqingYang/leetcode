// https://leetcode.com/problems/basic-calculator/

#include "header.h"

int calc(int a, int b, char op) {
  if (op == '+') return a + b;
  else if (op == '-') return a - b;
  else if (op == '*') return a * b;
  else if (op == '/') return a / b;
  return -1;  //indicate a error
}

int calculate_internal(char* s, char exitch, char ** endp) {
  char *p = s;
  char pending_op = 0;  //0 or +-*/ level 1
  int pending_num = 0;
  char pending_op2 = 0;  //0 or +-  level 2
  int pending_num2 = 0;
  int num = 0;  // current buffer

  //printf("in: %s %c\n", s, exitch);

  while (*p != exitch) {
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
    } else if (ch == '(') {
      char *endp;

      num = calculate_internal(p + 1, ')', &endp);
      p = endp;
    }

    p++;
  }

  if (pending_op != 0) {
    num = calc(pending_num, num, pending_op);
  }
  if (pending_op2 != 0) {
    num = calc(pending_num2, num, pending_op2);
  }

  if (endp != NULL) *endp = p;  // point to )
  //printf("result:%d\n", num);
  return num;
}

int calculate(char* s) {
  return calculate_internal(s, '\0', NULL);
}
