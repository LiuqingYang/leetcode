//https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Yang Liuqing
// yllqq@outlook.com


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
            int pos_array[256];
            int max_length = 0;
            string::const_iterator prev_it = s.begin(); // point to the first letter in this substring

            if (s.length() == 0)
                return 0;

            memset(pos_array, 0xff, sizeof(pos_array));

            for (string::const_iterator it = s.begin(); it != s.end(); ++it)
            {
                char c = *it;
                int length = it - prev_it;

                if (pos_array[c] < (prev_it - s.begin()))
                {   // have not meet this letter & not meet this letter in current substring
                    if (length > max_length)
                        max_length = length;
                }
                else
                {   // have meet this letter in current substring
                    prev_it = s.begin() + pos_array[c] + 1;
                }

                pos_array[c] = it - s.begin();
            }

            return max_length + 1;
    }
};
