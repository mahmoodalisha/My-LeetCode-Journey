//Question: Given a binary tree with N nodes, check if that input tree is BST or not. If yes return true, return false otherwise

bool isBST(BinaryTreeNode<int> *root, int min, int max) {
    //this is recursive function
    //base case
    if (root == NULL){
        return true;
    }
    if (root->data >= min && root->data <= max) {  //ek particular node ko check kiya maine, baaki saare nodes recursive call se check honge
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, max, root->data)
        return left && right;
    }
    else{
        return false;
    }
}

bool validateBST(BinaryTreeNode<int> *root){
    return isBST(root, INT_MIN, INT_MAX);
}