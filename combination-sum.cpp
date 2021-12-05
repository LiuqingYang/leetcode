// https://leetcode.com/problems/combination-sum/

#include "header.h"

class Solution {
public:
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        int n = candidates.size();
        vector<int> curr_case = vector<int>(n, 0);
        int curr_num = 0;
        
        while(1)
        {
            if (curr_num == target)
            {
                result.push_back(getCase(candidates, curr_case));
            }
            else if (curr_num > target)
            {
                int pos = n - 1;
                while(curr_case[pos] == 0) pos--;
                if (pos == 0)
                {
                    break;
                }
                
                curr_num = curr_num - candidates[pos] * curr_case[pos] + candidates[pos - 1];
                curr_case[pos - 1] += 1;
                curr_case[pos] = 0;
                continue;
            }

            curr_num += candidates[n - 1];
            curr_case[n - 1] += 1;
        }
        
        return result;
    }
    
    vector<int> getCase(vector<int>& candidates, vector<int>& curr_case) {
        vector<int> result;
        int n = candidates.size();

        for (int i = 0; i < n; i++)
        {
            int count = curr_case[i];
            if (count != 0)
            {
                vector<int> tmp = vector<int>(count, candidates[i]);
                result.insert(result.end(), tmp.begin(), tmp.end());
            }
        }
        
        return result;
    }
};