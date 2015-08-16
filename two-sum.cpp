// https://leetcode.com/problems/two-sum/
// Yang Liuqing
// yllqq@outlook.com

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> retnums = nums;
            vector<int> ret;
            vector<int>::iterator begin_it, end_it;

            // Init
            sort(retnums.begin(), retnums.end());
            begin_it = retnums.begin();
            end_it = retnums.end();
            --end_it;

            // Find loop
            while (begin_it < end_it)
            {
                int sum = *begin_it + *end_it;
                if (sum == target)
                {
                    // Have found
                    int pos1 = find(nums.begin(), nums.end(), *begin_it) - nums.begin();
                    int pos2 = find(nums.rbegin(), nums.rend(), *end_it) - nums.rbegin();

                    pos1 = pos1 + 1;
                    pos2 = nums.size() - pos2;
                    if (pos1 > pos2)
                    {
                        swap(pos1, pos2);
                    }

                    ret.push_back(pos1);
                    ret.push_back(pos2);
                    return ret;
                }
                else if (sum > target)
                {
                    end_it--;
                }
                else
                {
                    begin_it++;
                }
            }

            return ret;
    }
};
