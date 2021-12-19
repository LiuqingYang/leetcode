// https://leetcode.com/problems/numbers-at-most-n-given-digit-set/

#include "header.h"

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int count = digits.size();
        string strn = to_string(n);
        int str_count = strn.size();
        bool need_part = true;
        
        vector<char> nums(count);
        for (int i = 0; i < count; i++) {
            nums[i] = digits[i][0];
        }
        
        int ret = 0;
        for (int i = 0; i < str_count; i++) {
            char c = strn[i];
            auto it = std::lower_bound(nums.begin(), nums.end(), c);
            int multip = 1;
            if (need_part) {
                multip += it - nums.begin();
            }
            ret += pow(count, str_count - 1 - i) * multip;
            need_part = need_part && ((it != nums.end()) && (*it == c));
        }
        if (!need_part) ret -= 1;
        
        return ret;
    }
};

int main() {
    Solution sol;
    vector<string> digits = {"1", "3", "5", "7"};
    sol.atMostNGivenDigitSet(digits, 135);
}