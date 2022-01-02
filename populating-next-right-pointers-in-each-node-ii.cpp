// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

#include "header.h"

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// 使用广度优先搜索更加直观

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        vector<Node*> curr;
        vector<Node*> next;
        curr.push_back(root);
        while (!curr.empty()) {
            for (int i=0; i<curr.size(); i++) {
                Node* n = curr[i];
                if (n->left) next.push_back(n->left);
                if (n->right) next.push_back(n->right);
                if (i < curr.size() - 1) {
                    n->next = curr[i+1];
                }
            }
            swap(curr, next);
            next.clear();
        }
        return root;
    }
};