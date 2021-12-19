// https://leetcode.com/problems/decode-string/

#include "header.h"

class Solution {
private:
    string inner(const string& s, int& pos) {
        int count = s.size();
        int repeat = 0;
        string output;
        for (; pos < count; pos++) {
            char c = s[pos];
            if (c >= '0' && c <= '9') {
                repeat = repeat * 10 + c - '0';
            } else if (c >= 'a' && c <= 'z') {
                output += c;
            } else if (c == '[') {
                pos++;
                string out = inner(s, pos);
                for (int i = 0; i < repeat; i++) {
                    output += out;
                }
                repeat = 0;
            } else if (c == ']') {
                break;
            }
        }
        return output;
    }
    
public:
    string decodeString(string s) {
        int pos = 0;
        return inner(s, pos);
    }
};

int main() {
    Solution s;
    s.decodeString("a2[a]");
}