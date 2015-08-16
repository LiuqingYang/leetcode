// This is the reverse answer

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* convert(char* s, int numRows)
{
  size_t len;
  int offset;
  int group_len;
  char **groups;
  char *retStr, *pStr;
  int currGrp, direction;

  len = strlen(s);
  group_len = numRows * 2 - 2;
  groups = malloc(sizeof(char*) * numRows);
  retStr = malloc(sizeof(char) * (len + 1));
  retStr[len] = '\0';
  pStr = retStr;

  groups[0] = s;
  offset = (len + group_len - 1) / group_len;
  for (int i = 1; i < numRows; i++)
  {
    groups[i] = s + offset;
    offset += (len + group_len - 1 - i) / group_len;
    offset += (len + i - 1) / group_len;
  }

  for (int i = 0; i < numRows; i++)
  {
    printf("%ld\n", groups[i] - s);
  }

  currGrp = 0;
  direction = 0;
  while(pStr - retStr < len)
  {
    if (direction == 0)
    {
      if (currGrp != numRows)
      {
        *pStr++ = *groups[currGrp]++;
        currGrp++;
      }
      else
      {
        direction = 1;
        currGrp -= 2;
      }
    }
    else
    {
      if (currGrp != -1)
      {
        *pStr++ = *groups[currGrp]++;
        currGrp--;
      }
      else
      {
        direction = 0;
        currGrp = 1;
      }
    }
  }

  return retStr;
}

int main()
{
  printf("%s\n", convert("PAHNAPLSIIGYIR", 3));
}
