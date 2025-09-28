int maxDepth(TreeNode* root) {
    if (root == nullptr) {
        // Agar node NULL hai, iska matlab depth = 0
        return 0;
    }

    // Recursive call left subtree ke liye
    int leftDepth = maxDepth(root->left);

    // Recursive call right subtree ke liye
    int rightDepth = maxDepth(root->right);

    // Current node ka depth = 1 + max(leftDepth, rightDepth)
    return 1 + max(leftDepth, rightDepth);
}
