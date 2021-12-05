// https://leetcode.com/problems/stream-of-characters/

#include "header.h"

// Timeout

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        m_words = words;
        m_count = words.size();
        m_pos.resize(m_count);
        
        m_pos_jump.resize(m_count);
        for (int i = 0; i < m_count; i++) {
            string &word = m_words[i];
            
            m_pos_jump[i].resize(word.size());
            for (int j = 0; j < word.size(); j++) {
                vector<int> &table = m_pos_jump[i][j];
                table.resize(26);
                for (int k = 0; k < 26; k++) {
                    table[k] = longestSubfix(word, j, k);
                }
            }
        }
    }
    
    bool query(char letter) {
        int ret = false;
        for (int i = 0; i < m_count; i++) {
            string &word = m_words[i];
            int pos = m_pos[i];
            if (letter == word[pos]) {
                if (pos + 1 == word.size()) {
                    ret = true;
                    if (m_pos_jump[i].size() > 0 && pos < word.size() && pos > 0) {
                        m_pos[i] = m_pos_jump[i][pos][letter - 'a'];
                    } else {
                        m_pos[i] = 0;
                    }
                } else {
                    m_pos[i]++;
                }
            } else {
                if (m_pos_jump[i].size() > 0 && pos < word.size() && pos > 0) {
                    m_pos[i] = m_pos_jump[i][pos][letter - 'a'];
                } else {
                    m_pos[i] = 0;
                }
            }
        }
        cout << ret << ' ';
        return ret;
    }
private:
    int longestSubfix(string &word, int count, int pos) {
        char c = 'a' + pos;
        
        for (int i = count; i > 0; i--) {
            if (c == word[i - 1]) {
                bool ok = true;
                for (int j = 0; j < i - 1; j++) {
                    if (word[j] != word[j - i + count + 1]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    return i;
                }
            }
        }
        
        return 0;
    }
    vector<string> m_words;
    vector<int> m_pos;
    vector<vector<vector<int>>> m_pos_jump;
    int m_count;
};

int main() {
    vector<string> words = {"abba", "abaab", "aabbb", "bab", "ab"};
    //  vector<string> words = {"abaab"};
    StreamChecker checker(words);
    checker.query('a');
    checker.query('a');
    checker.query('b');
    checker.query('b');
    checker.query('b');

    checker.query('a');
    checker.query('a');
    checker.query('b');
    checker.query('b');
    checker.query('a');

    checker.query('a');
    checker.query('a');
    checker.query('a');
}

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */