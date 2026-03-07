//root se leke ek last leaf tak ek sub tree hua toh saare sub trees ka sum chahiye

class Solution {
public:
    int solve(TreeNode* root, int val){
        if(!root) return 0;
        val = (2*val) + root -> val; //left shift karne ke liye 2 se multipy kia jaata hai or right shift karne ke liye /2
        if(root -> left == NULL && root -> right == NULL) return val;

        return solve(root->left, val) + solve(root->right, val);

    }
    int sumRootToLeaf(TreeNode* root) {
        return solve(root, 0);
    }
};