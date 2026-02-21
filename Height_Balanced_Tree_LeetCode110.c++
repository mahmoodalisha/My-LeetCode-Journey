/*
A binary tree is height-balanced if: For every node, the difference between the heights of its left and right subtrees is at most 1

      1
     / \
    2   3
   /
  4

Left height = 2
Right height = 1
Difference = 1 → balanced

What NOT balanced looks like ❌
      1
     /
    2
   /
  3
Left height = 2
Right height = 0
Difference = 2 → NOT balanced

❗ Even if one node breaks the rule → tree is unbalanced.
  */
class Solution {
public:
    int height(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        int left = height(root->left);
        int right = height(root->right);

        if(abs(left - right) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};