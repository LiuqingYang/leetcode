// https://leetcode.com/problems/wildcard-matching/

#include "header.h"

// 此匹配可以迭代解决，我的算法随着pattern长度指数增长非常不好

class Solution {
public:
     bool isMatch(const char *s, const char *p) {
        const char* star=NULL;
        const char* ss=s;
        while (*s){
            //advancing both pointers when (both characters match) or ('?' found in pattern)
            //note that *p will not advance beyond its length 
            if ((*p=='?')||(*p==*s)){s++;p++;continue;} 

            // * found in pattern, track index of *, only advancing pattern pointer 
            if (*p=='*'){star=p++; ss=s;continue;} 

            //current characters didn't match, last pattern pointer was *, current pattern pointer is not *
            //reset and advancing string pointer
            if (star){ p = star+1; s=++ss;continue;} 

           //current pattern pointer is not star, last pattern pointer was not *
           //characters do not match
            return false;
        }

       //check for remaining characters in pattern
        while (*p=='*'){p++;}

        return !*p;  
    }
    
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());
    }
};

/*
class Solution {
public:
    bool inner(const string& s, int sp, const string& p, int pp) {
        int count = s.size();
        int pcount = p.size();
        
        int loop_count = pcount - pp;
        int i;
        for (i = 0; i < loop_count; i++) {
            char pc = p[pp + i];
            if (pc == '*') {
                int starcount = 1;
                while (pp + i + starcount < pcount && p[pp + i + starcount] == '*') {
                    starcount++;
                }
                for (int j = sp + i; j <= count; j++) {
                    if (inner(s, j, p, pp + i + starcount)) {
                        return true;
                    }
                }
                return false;
            } else if (sp + i >= count || (pc != '?' && pc != s[sp + i])) {
                return false;
            }
        }
        return sp + i == count;
    }
    
    bool isMatch(string s, string p) {
        return inner(s, 0, p, 0);
    }
};
*/

int main() {
    Solution sol;
    cout << sol.isMatch("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb"
    , "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb");
}
