// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

#include "header.h"

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string result;
        vector<int> positions;
        int current = 0;
        
        for (char c : s) {
            if (c == '(') {
                positions.push_back(current);
                result.push_back(c);
                current++;
            } else if (c == ')') {
                if (positions.empty()) {
                    continue;
                } else {
                    positions.pop_back();
                    result.push_back(c);
                    current++;
                }
            } else {
                result.push_back(c);
                current++;
            }
        }
        
        if (positions.empty()) {
            return result;
        } 
        for (int pos : positions) {
            result[pos] = '-';
        }
        
        result.erase(std::remove(result.begin(), result.end(), '-'), result.end());
        
        return result;
    }
};