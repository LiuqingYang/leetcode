// https://leetcode.com/problems/same-tree/
// Yang Liuqing
// yllqq@outlook.com


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (!p && !q) {
        return true;
    } else if (!p || !q) {
        return false;
    }

    if ((p->val != q->val) ||
        ((!!p->left) != (!!q->left)) ||
        ((!!p->right) != (!!q->right))) {
            return false;
        }
    if (p->left && !isSameTree(p->left, q->left)) {
        return false;
    }
    if (p->right && !isSameTree(p->right, q->right)) {
        return false;
    }

    return true;
}
