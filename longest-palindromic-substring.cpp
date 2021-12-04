// https://leetcode.com/problems/longest-palindromic-substring/

#include "header.h"

class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ret;
        int longest = 0;
        int count = s.size();
        
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        for (int i = 0; i < count; i++) {
            int start = -1;
            int end = -1;
            for (int j = i; j < count; j++) {
                int rev_pos = j - i;
                if (s[j] == rev[rev_pos]) {
                    if (start == -1) start = j;
                    end = j;
                    continue;
                } else if (end != -1 && (count - (end - i) - 1) == start) {
                    int len = end - start + 1;
                    if (len > longest) {
                        longest = len;
                        ret = s.substr(start, len);
                    }
                }
                start = -1;
                end = -1;
            }
            if (end != -1 && (count - (end - i) - 1) == start) {
                int len = end - start + 1;
                if (len > longest) {
                    longest = len;
                    ret = s.substr(start, len);
                    start = -1;
                    end = -1;
                }
            }
        }
        for (int i = 0; i < count; i++) {
            int start = -1;
            int end = -1;
            for (int j = i; j < count; j++) {
                int rev_pos = j - i;
                if (rev[j] == s[rev_pos]) {
                    if (start == -1) start = j;
                    end = j;
                    continue;
                } else if (end != -1 && (count - (end - i) - 1) == start) {
                    int len = end - start + 1;
                    if (len > longest) {
                        longest = len;
                        ret = rev.substr(start, len);
                    }
                }
                start = -1;
                end = -1;
            }
            if (end != -1 && (count - (end - i) - 1) == start) {
                int len = end - start + 1;
                if (len > longest) {
                    longest = len;
                    ret = rev.substr(start, len);
                    start = -1;
                    end = -1;
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution sol;
    cout << sol.longestPalindrome("aab");
}
