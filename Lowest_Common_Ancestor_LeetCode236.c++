//Company Tags: Accolite, Amazon, American Express, Expedia,
//MakeMyTrip, Microsoft, PayU, SnapDeal

//root ke left right jaake dhundo p aur q ko recursively
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;

        if(root == p || root == q) return root;

        TreeNode* leftN = lowestCommonAncestor(root->left, p, q);     //root ke left hand side se p ya q mila
        TreeNode* rightN = lowestCommonAncestor(root->right, p, q);  //root ke right hand side se p ya q mila

        if(leftN != NULL && rightN != NULL) return root; //dono side se root hi ancestor hai example 1 ka case jisme output 3 hai dono p aur q ka ancestor

        if(leftN != NULL) return leftN;

        return rightN;
    }
};