// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

// careful boundary of input and array

#include "header.h"

/**
 * Modify current to next combinations to target, return 0 if it is target
 */
int moveForward(char *current, const char *target, size_t len) {
  int i;

  for (i = len - 1; i >= 0; i--) {
    if (current[i] != target[i]) {
      current[i]++;
      break;
    }
  }
  if (i < 0) {
    return 0;
  }

  for (i++; i < len; i++) {
    current[i] = 0;
  }

  return 1;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
  // start from 2
  const char *table[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

  size_t len = strlen(digits);
  char **array;
  int count = 1;
  char *target;
  char *current;
  int current_str = 0;

  int i;

  if (len == 0) {
    *returnSize = 0;
    return NULL;
  }

  target = malloc(sizeof(char) * len);
  current = malloc(sizeof(char) * len);
  memset(current, 0x00, len);

  for(i = 0; i < len; i++) {
    char digit = digits[i];
    target[i] = strlen(table[digit - '2']) - 1;
    count *= strlen(table[digit - '2']);
  }

  array = malloc(sizeof(char*) * count);
  for(i = 0; i < count; i++) {
    char *str = malloc(sizeof(char) * (len + 1));
    str[len] = '\0';
    array[i] = str;
  }

  do {
    char *str = array[current_str];

    for (i = 0; i < len; i++) {
      char digit = digits[i];

      str[i] = *(table[digit - '2'] + current[i]);
    }

    current_str++;
  } while(moveForward(current, target, len));

  free(target);
  free(current);

  *returnSize = count;
  return array;
}

void moveForward_test() {
  size_t len = 5;
  char *target;
  char *current;

  target = malloc(sizeof(char) * len);
  current = malloc(sizeof(char) * len);
  memset(current, 0x00, len);
  target[0] = 2;
  target[1] = 1;
  target[2] = 2;
  target[3] = 1;
  target[4] = 2;

  do {
    int i;

    for (i = 0; i < 5; i++) {
      printf("%d", current[i]);
    }
    printf("\n");
  } while(moveForward(current, target, len));
}

void letterCombinations_test() {
  const char *str = "8";
  int returnSize;
  char **ret;
  int i;

  ret = letterCombinations((char *)str, &returnSize);

  for (i = 0; i < returnSize; i++) {
    printf("%s\n", ret[i]);
    free(ret[i]);
  }
  free(ret);
}

int main() {
  letterCombinations_test();
}
