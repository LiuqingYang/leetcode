// https://leetcode.com/problems/maximum-subarray/

#include "header.h"

/*
[-2,1,-3,4,-1,2,1,-5,4]
[-2,-1,-4,0,-1,1,2,-3,1]
6

[-2,-1,2,0,-1,1,-4,-3,1]
5

[]

[1]
[1]
1

[1, 2]
[1, 3]
3

[2, -1]
[2, 1]
2

[-1, 2]
[-1, 1]
2

[-1, 0]
[-1, -1]
0

[1, 0]
[1, 1]
1

[-2, -1]
[-2, -3]

*/

static int count[100000];
static int *g_num;

int maxSubArray_inn(int* nums, int numsSize) {
    if (numsSize == 1) {
        return g_num[nums-count];
    }
    int max = nums[0];
    int maxpos = 0;
    int min = nums[0]; 
    int minpos = 0;
    int i;
    
    for (i = 1; i < numsSize; i++) {
        if (nums[i] >= max) {
            max = nums[i];
            maxpos = i;
        } else if (nums[i] < min) {
            min = nums[i];
            minpos = i;
        }
    }
    
    if (max == min) {
        return (max > 0) ? max : 0;
    } else if (maxpos > minpos) {
        int ret = max - min;
        if (min == nums[0] && g_num[nums-count] > 0) ret += g_num[nums-count];
        if (ret < max) ret = max;
        return ret;
    } else {
        
        int left = maxSubArray_inn(nums, maxpos + 1);
        int right = maxSubArray_inn(nums + minpos, numsSize - minpos);
        int minlr = (left > right) ? left : right;
        if (minpos - maxpos < 2)
            return minlr;
        else {
            int middle = maxSubArray_inn(nums + maxpos + 1, minpos - maxpos - 1);
            return (minlr > middle) ? minlr : middle;
        }
    }
}

int maxSubArray(int* nums, int numsSize) {
    int i;
    
    count[0] = nums[0];
    for (i = 1; i < numsSize; i++) {
        count[i] = count[i-1] + nums[i];
    }
    g_num = nums;
    return maxSubArray_inn(count, numsSize);
}