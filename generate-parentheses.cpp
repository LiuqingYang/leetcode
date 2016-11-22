#include "header.h"

// only for reference:
// https://zh.wikipedia.org/wiki/%E5%8D%A1%E5%A1%94%E5%85%B0%E6%95%B0
//
// if use C++ well, performance can as good as C

class Solution {
private:
  void generateParenthesisInner(vector<string> &ret, string &curr, int pos, int left, int right) {
    if (left == 0 && right == 1) {
      curr[pos] = ')';
      ret.push_back(curr);
    } else if (left == 0) {
      curr[pos] = ')';
      generateParenthesisInner(ret, curr, pos + 1, 0, right - 1);
    } else if (left == right) {
      curr[pos] = '(';
      generateParenthesisInner(ret, curr, pos + 1, left - 1, right);
    } else {
      curr[pos] = '(';
      generateParenthesisInner(ret, curr, pos + 1, left - 1, right);
      curr[pos] = ')';
      generateParenthesisInner(ret, curr, pos + 1, left, right - 1);
    }
  }
  
public:
  vector<string> generateParenthesis(int n) {
    vector<string> ret;
    string curr(2 * n, 'T');  // fill to speed optimize
    
    generateParenthesisInner(ret, curr, 0, n, n);
    return ret;
  }
};

int main()
{
  Solution sol;
  auto ret = sol.generateParenthesis(3);
  for (auto elem : ret) {
    cout << elem << endl;
  }
}
