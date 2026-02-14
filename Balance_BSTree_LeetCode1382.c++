//Binary Search Tree de dega input me, usko balance karo
//depth matlab jaha khade ho waha se edges count karo
//jis node/root pe khade ho uske left ke saare edges minus right ke saare edges not more than 1 hona chahiye
//Inorder traversal karne se BST full sorted order me milega, isko array me store karlo
//ab isi array ke mid me split maaro, balanced BST mil jayega !!

class Solution {
public:
    void inOrder(TreeNode* root, vector<int>& vec){
        if(root == NULL) return;

        inOrder(root->left, vec);
        vec.push_back(root->val);
        inOrder(root->right, vec);
    }

    TreeNode* construct(int left, int right, vector<int>& vec){
        if(left>right){
            return NULL;
        }

        int mid = (left+right)/2;
        TreeNode* root = new TreeNode(vec[mid]); //mid ko root bana diya
        root->left = construct(left, mid-1, vec);
        root->right = construct(mid+1, right, vec);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vec;
        inOrder(root, vec);

        int left = 0;
        int right = vec.size()-1;
        return construct(left, right, vec);
    }
};