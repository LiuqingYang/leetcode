// https://leetcode.com/problems/jump-game-iii/

#include "header.h"

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int count = arr.size();
        vector<int> stack;
        
        while (1) {
            int current = arr[start];
            int prev = start - current;
            int next = start + current;
            if (current == 0) {
                return true;
            }
            arr[start] = -1;
            if (prev >= 0 && arr[prev] >= 0) {
                if (next < count && arr[next] >= 0) {
                    stack.push_back(next);
                }
                start = prev;
                continue;
            } else {
                if (next < count && arr[next] >= 0) {
                    start = next;
                    continue;
                }
            }
            if (stack.size() == 0) {
                return false;
            } else {
                start = stack.back();
                stack.pop_back();
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {0,1};
    sol.canReach(arr, 1);
}