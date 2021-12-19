// https://leetcode.com/problems/group-anagrams/

#include "header.h"

// unordered_map 略快于map

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> strmap;
        
        for (auto& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            strmap[key].push_back(str);
        }
        
        vector<vector<string>> ret;
        ret.resize(strmap.size());
        int i = 0;
        for (auto it = strmap.begin(); it != strmap.end(); ++it) {
            ret[i].swap(it->second);
            i++;
        }
        return ret;
    }
};
