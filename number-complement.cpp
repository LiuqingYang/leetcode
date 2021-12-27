// https://leetcode.com/problems/number-complement/

class Solution {
public:
    int findComplement(int num) {
        unsigned int ret = 0;
        unsigned int multip = 1;
        while (num != 0) {
            int i = num % 2;
            ret += multip * (1 - i);
            multip *= 2;
            num /= 2;
        }
        return ret;
    }
};