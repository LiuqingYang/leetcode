// https://leetcode.com/problems/permutation-sequence/

#include "header.h"

class Solution {
private:
public:
    string getPermutation(int n, int k) {
        string ret;
        string nums;
        vector<int> divs;   // 1, 2, 6, 24, ... n!
        
        ret.resize(n);
        for (int i = 0; i < n; i++) {
            nums.push_back(i + '1');
        }
        divs.push_back(1);
        for (int i = 1; i < n - 1; i++) {
            divs.push_back(divs[i - 1] * (i + 1));
        }
        
        k -= 1;
        for (int i = 0; i < n - 1; i++) {
            int seq = k / divs[n - i - 2];
            ret[i] = nums[seq];
            nums.erase(nums.begin() + seq);
            k = k % divs[n - i - 2];
        }
        ret[n-1] = nums.front();
        return ret;
    }
};

int main() {
    Solution sol;
    sol.getPermutation(3, 3);
}