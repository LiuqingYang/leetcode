// https://leetcode.com/problems/binary-tree-tilt/

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
public:
    int ans = 0;
    int findTiltSum(TreeNode* node) {
        if (node == nullptr) return 0;
        
        int left = findTiltSum(node->left);
        int right = findTiltSum(node->right);
        
        int tilt = abs(left - right);
        ans += tilt;
        return left + right + node->val;
    }

    int findTilt(TreeNode* root) {
        ans = 0;
        findTiltSum(root);
        return ans;
    }    
};
