// https://leetcode.com/problems/complement-of-base-10-integer/

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int ret = 0;
        int multip = 1;
        while (n != 0) {
            int i = n % 2;
            ret += multip * (1 - i);
            multip *= 2;
            n /= 2;
        }
        return ret;
    }
};