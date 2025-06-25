class Solution {
public:
    string tree2str(TreeNode* root) {
        if(!root){
            return "";
        }

        string result = to_string(root->val); //root(L)(R) just isko follow karo
        string left = tree2str(root->left); //left banao
        string right = tree2str(root->right); //right banao

        if(!root->left && !root->right){
            return result;
        }
        
        if(root->left == NULL){
            return result+"()"+"("+right+")";
        }

        if(root->right == NULL){
            return result+"("+left+")";
        }

        return result+"("+left+")"+"("+right+")";  //root(L)(R) just isko follow kiya
    }
};

//youtube: code story with MIK