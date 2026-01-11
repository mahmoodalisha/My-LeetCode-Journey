/*
Return the smallest subtree such that it contains all the deepest nodes in the original tree.
example 1 me sabse deepest node 7 aur 4 hai uska common parent 2 hai bas yahi sub tree return kardo !!
*/
class Solution {
public:
        pair<int, TreeNode*> solve(TreeNode* root){
            if(root == NULL){
                return {0, NULL};
            }
            auto l = solve(root->left);
            auto r = solve(root->right);

            if(l.first == r.first){
                return {l.first+1, root};
            }
            else if(l.first > r.first){
                return {l.first+1, l.second};
            }
            else{
                return {r.first+1, r.second};
            }
        }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return solve(root).second;
    }
};