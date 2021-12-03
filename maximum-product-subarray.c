// https://leetcode.com/problems/maximum-product-subarray/
// Yang Liuqing
// yllqq@outlook.com

#include "header.h"

int maxProduct(int* nums, int numsSize){
    int max = nums[0];
    int curr = 1;
    for (int i = 0; i < numsSize; i++) {
        curr *= nums[i];
        if (curr > max) {
            max = curr;
        }
        if (curr == 0) {
            curr = 1;
        }
    }
    
    curr = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        curr *= nums[i];
        if (curr > max) {
            max = curr;
        }
        if (curr == 0) {
            curr = 1;
        }
    }
    return max;
}
