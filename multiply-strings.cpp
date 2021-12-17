// https://leetcode.com/problems/multiply-strings/

#include "header.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        int count1 = num1.size();
        int count2 = num2.size();
        vector<int> result(count1 + count2, 0);
                
        for (int i = 0; i < count1; i++) {
            for (int j = 0; j < count2; j++) {
                int num = (num1[count1 - i - 1] - '0') * (num2[count2 - j - 1] - '0');
                result[i + j] += num;
            }
        }
        
        int loop_count = count1 + count2 - 1;
        for (int i = 0; i < loop_count; i++) {
            int num = result[i];
            result[i + 1] += num / 10;
            result[i] = num % 10;
        }
        
        string ret;
        bool have_value = false;
        for (int i = count1 + count2 - 1; i >= 0; i--) {
            int num = result[i];
            if (num != 0 || have_value) {
                ret.push_back(num + '0');
                have_value = true;
            }
        }
        if (ret.size() == 0) return "0";
        return ret;
    }
};
