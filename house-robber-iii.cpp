// https://leetcode.com/problems/house-robber-iii/

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

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    struct NodeData {
        int max_rub;
        int max_norub;
    };
    int rob(TreeNode* root) {
        NodeData ret = rob_calc(root);
        return ret.max_rub;
    }
    NodeData rob_calc(TreeNode *node) {
        NodeData left{0, 0};
        NodeData right{0, 0};
        NodeData self;
        
        if (node->left) {
            left = rob_calc(node->left);
        }
        if (node->right) {
            right = rob_calc(node->right);
        }
        self.max_rub = node->val + left.max_norub + right.max_norub;
        self.max_norub = left.max_rub + right.max_rub;
        if (self.max_norub > self.max_rub) {
            self.max_rub = self.max_norub;
        }
        return self;
    }
private:
};