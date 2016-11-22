#include "header.h"

// one time pass

char buf[10000];
char *p_buf;

bool isValid(char* s) {
    char ch;
    char pair;

    p_buf = buf;
    while ((ch = *s++) != '\0') {
      switch (ch) {
        case '(':
        case '[':
        case '{':
        *p_buf++ = ch;
        break;
        case ')':
        if (*(p_buf - 1) != '(') {
          return false;
        } else {
          p_buf--;
        }
        break;
        case ']':
        if (*(p_buf - 1) != '[') {
          return false;
        } else {
          p_buf--;
        }
        break;
        case '}':
        if (*(p_buf - 1) != '{') {
          return false;
        } else {
          p_buf--;
        }
        break;
        default:
        
        break;
      }
    }
    
    if (p_buf == buf)
      return true;
    else
      return false;
}

int main()
{
  char *tst1 = "()";
  char *tst2 = "()[]{}";
  char *tst3 = "(]";
  char *tst4 = "([)]";
  
  printf("%s is %s\n", tst1, (isValid(tst1) ? "valid" : "not valid"));
  printf("%s is %s\n", tst2, (isValid(tst2) ? "valid" : "not valid"));
  printf("%s is %s\n", tst3, (isValid(tst3) ? "valid" : "not valid"));
  printf("%s is %s\n", tst4, (isValid(tst4) ? "valid" : "not valid"));
}
