// https://leetcode.com/problems/single-number/
// Yang Liuqing
// yllqq@outlook.com


int singleNumber(int* nums, int numsSize) {
  int ret = 0;
  for (int i = 0; i < numsSize; i++) ret ^= nums[i];
  return ret;
}
