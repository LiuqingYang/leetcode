// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

#include "header.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    pair<int, int> inner(TreeNode* node) {
        pair<int, int> ret = make_pair(node->val, node->val);   // min, max
        int diff = 0;
        if (node->left) {
            pair<int, int> l = inner(node->left);
            diff = max(diff, abs(node->val - l.first));
            diff = max(diff, abs(node->val - l.second));
            ret.first = min(ret.first, l.first);
            ret.second = max(ret.second, l.second);
        }
        if (node->right) {
            pair<int, int> r = inner(node->right);
            diff = max(diff, abs(node->val - r.first));
            diff = max(diff, abs(node->val - r.second));
            ret.first = min(ret.first, r.first);
            ret.second = max(ret.second, r.second);
        }
        m = max(m, diff);
        return ret;
    }
    
    int m = 0;
public:
    int maxAncestorDiff(TreeNode* root) {
        m = 0;
        inner(root);
        return m;
    }
};