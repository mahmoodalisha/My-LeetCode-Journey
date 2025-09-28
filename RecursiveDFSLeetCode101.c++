class Solution {
public:
    bool isMirror(TreeNode* t1, TreeNode* t2){
        if(!t1 && !t2) return true; // dono NULL → symmetric
        if(!t1 || !t2) return false; // sirf ek NULL → asymmetric

        return (t1->val == t2->val) && // current node values same hone chahiye
        isMirror(t1 -> left, t2->right) && // left subtree ka left vs right subtree ka right
        isMirror(t2 -> left, t1->right); // left subtree ka right vs right subtree ka left
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isMirror(root->left, root->right);
    }
};

/* Example 1: Input: root = [1,2,2,3,4,4,3]
isSymmetric(root) → calls isMirror(root->left, root->right)
root->left = 2 (left)
root->right = 2 (right)
isMirror(2, 2)

values same → check children recursively:
isMirror(2->left, 2->right) → isMirror(3, 3)
values same → children are NULL → return true
isMirror(2->right, 2->left) → isMirror(4, 4)
values same → children are NULL → return true

Both left and right checks returned true → isMirror(2,2) returns true
Finally isSymmetric(root) returns true → tree symmetric
 */
 
 //t1 → left subtree ka current node
 //t2 → right subtree ka current node

 /* Call Sequence of Example 1
isMirror(root->left, root->right) → t1 = 2 (left), t2 = 2 (right)
isMirror(t1->left, t2->right) → t1 = 3, t2 = 3
isMirror(t1->right, t2->left) → t1 = 4, t2 = 4
  */