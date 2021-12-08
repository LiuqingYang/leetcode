// https://leetcode.com/problems/combination-sum-ii/

#include "header.h"

// 在终点增加计算结果会更快

class Solution {
public:
    vector<vector<int>> sum(vector<int>& vec, int pos, int target) {
        if (target == 0 || pos >= vec.size()) return {};
        if (pos == vec.size() - 1) {
            if (vec[pos] == target) {
                return {{target}};
            } else {
                return {};
            }
        }
        
        int val = vec[pos];
        int times = 1;
        int count = vec.size();
        while ((times + pos) < count && vec[times + pos] == val) times++;
        
        vector<vector<int>> result;
        for (int i = 0; i <= times; i++) {
            int current_target = target - val * i;
            if (current_target < 0) break;
            auto current = sum(vec, pos + times, current_target);
            if (target == val * i) {
                current.push_back({});
            }
            for (auto& item : current) {
                for (int k = 0; k < i; k++) {
                    item.push_back(val);
                }
            }
            std::move(current.begin(), current.end(), std::back_inserter(result));
        }
        
        return result;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.size() == 0) return {};
        
        sort(candidates.begin(), candidates.end());
        
        return sum(candidates, 0, target);
    }
};

int main() {
    Solution sol;
    vector<int> input = {10,1,2,7,6,1,5};
    sol.combinationSum2(input, 8);
}
