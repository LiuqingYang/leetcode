// https://leetcode.com/problems/single-number/
// Yang Liuqing
// yllqq@outlook.com

#include "header.h"

int singleNumber(int* nums, int numsSize) {
  int ret = 0;
  for (int i = 0; i < numsSize; i++) ret ^= nums[i];
  return ret;
}

int main()
{
  int nums[] = {2, 3, 2};
  printf("%d\n", singleNumber(nums, 3));
}
