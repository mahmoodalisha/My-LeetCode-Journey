/*
find the second smallest node in the binary tree
*/

class Solution {
public:
    int firstmin;
    long long secondmin;
    void dfs(TreeNode* root){
        if(root == NULL) return;

        if(root->val > firstmin && root->val < secondmin){
            secondmin = root->val;
        }
        dfs(root->left);
        dfs(root->right);
    }

    int findSecondMinimumValue(TreeNode* root) {
        firstmin = root->val;
        secondmin = LLONG_MAX;

        dfs(root);

        if(secondmin == LLONG_MAX){
            return -1;
        }
        return secondmin;
    }
};