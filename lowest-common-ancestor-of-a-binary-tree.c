// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// Yang Liuqing
// yllqq@outlook.com

#include "header.h"

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
 int val;
 struct TreeNode *left;
 struct TreeNode *right;
};

struct TreeNode* lowestCommonAncestor_v2(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
  struct TreeNode *p_path[10000];
  int p_path_depth = 0;
  int p_done = 0;
  struct TreeNode *q_path[10000];
  int q_path_depth = 0;
  int q_done = 0;
  struct TreeNode *curr_path[10000];
  int curr_path_depth = 0;

  struct TreeNode *ret = root;
  int i;

  curr_path[0] = root;

  while (1) {
    if (!p_done && curr_path[curr_path_depth] == p) {
      memcpy(p_path, curr_path, sizeof(struct TreeNode*) * (curr_path_depth + 1));
      p_path_depth = curr_path_depth;
      p_done = 1;
    }
    if (!q_done && curr_path[curr_path_depth] == q) {
      memcpy(q_path, curr_path, sizeof(struct TreeNode*) * (curr_path_depth + 1));
      q_path_depth = curr_path_depth;
      q_done = 1;
    }

    if (p_done && q_done) break;

    if (curr_path[curr_path_depth]->left) {
      curr_path[curr_path_depth+1] = curr_path[curr_path_depth]->left;
      curr_path_depth++;
    } else if (curr_path[curr_path_depth]->right) {
      curr_path[curr_path_depth+1] = curr_path[curr_path_depth]->right;
      curr_path_depth++;
    } else if (curr_path_depth != 0) {
      while (1) {
        if (curr_path[curr_path_depth-1]->left == curr_path[curr_path_depth]
            && curr_path[curr_path_depth-1]->right != NULL) {
          curr_path[curr_path_depth] = curr_path[curr_path_depth-1]->right;
          break;
        } else {
          curr_path_depth--;
        }
      }
    }
  }

  for (i = 0; i < 10000; i++) {
    if (p_path_depth < i || q_path_depth < i)
      break;
    if (p_path[i] != q_path[i])
      break;
    ret = p_path[i];
  }
  return ret;
}

bool findNode(struct TreeNode* root, struct TreeNode* node)
{
  if (!root) return false;

  if (root == node) {
    return true;
  } else if (findNode(root->left, node)) {
    return true;
  } else if (findNode(root->right, node)) {
    return true;
  } else {
    return false;
  }
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
  struct TreeNode* ret;
  int left = 0;
  int right = 0;

  // lowest
  if (root->left) {
    ret = lowestCommonAncestor(root->left, p, q);
    if (ret)
      return ret;
  }
  if (root->right) {
    ret = lowestCommonAncestor(root->right, p, q);
    if (ret)
      return ret;
  }
  // find p
  if (root != p) {
    if (!findNode(root->left, p)) {
      if (!findNode(root->right, p)) {
        return NULL;
      } else {
        right = 1;
      }
    } else {
      left = 1;
    }
  }

  // find q
  if (root != q) {
    if (!findNode(root->left, q)) {
      if (!findNode(root->right, q)) {
        return NULL;
      } else {
        right = 1;
      }
    } else {
      left = 1;
    }
  }

  return root;
}

/*
_______3______
/              \
___5__          ___1__
/      \        /      \
6      _2       0       8
      /  \
     7   4
 */

//[-1,0,3,-2,4,null,null,8]

int main()
{
  struct TreeNode n0, n1, n2, n3, n4, n5, n6, n7, n8;
  struct TreeNode *ret;

  n3.val = 100;
  n3.left = NULL;
  n3.right = NULL;

  n5.val = 100;
  n5.left = NULL;
  n5.right = NULL;

  n6.val = 6;
  n6.left = &n3;
  n6.right = &n5;

  n2.val = 0;
  n2.left = &n4;
  n2.right = &n5;

  n7.val = 7;
  n7.left = NULL;
  n7.right = NULL;

  n4.val = -2;
  n4.left = &n8;
  n4.right = NULL;

  n1.val = -1;
  n1.left = &n2;
  n1.right = &n3;

  n0.val = 0;
  n0.left = NULL;
  n0.right = NULL;

  n8.val = 8;
  n8.left = NULL;
  n8.right = NULL;

  ret = lowestCommonAncestor(&n6, &n3, &n5);
  printf("%d\n", ret->val);
}
