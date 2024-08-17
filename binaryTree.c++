//Lecture 62 Love Babbar
#include<iostream>
#include <queue>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

        node(int d) {   //user-defined constructor for the class named node
            this -> data = d;  //this is a pointer to the current object (the object that is being created).
            this -> left = NULL;
            this -> right = NULL;
        }
};

node* buildTree(node* root) {
    cout << "Enter the data: " << endl; //root node ka data user enter karega
    int data;
    cin >> data;
    root = new node(data);   //constructor call hoga

    if(data == -1){
        return NULL;
    }
    cout << "Enter data for inserting in the left of " << data << endl;
    root->left = buildTree(root->left);  //root ke left me saare nodes create honge
    cout << "Enter data for inserting in the right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

//level order traversal or BFS traversal
void levelOrderTraversal(node* root) {
    if (root == NULL) return;
    queue<node*> q;  //queue bana li node* type ki
    q.push(root);  //sabse pehle ek element daal do , root element hi daal do
    while (!q.empty()) {
        node* current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left != NULL) q.push(current->left);
        if (current->right != NULL) q.push(current->right);
    }
}

void inorderTraversal(node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(node* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}



int main() {
    node* root = NULL;
    // Creating a tree
    root = buildTree(root);

    cout << "\nLevel Order Traversal: " << endl;
    levelOrderTraversal(root);

    cout << "\nInorder Traversal: " << endl;
    inorderTraversal(root);

    cout << "\nPreorder Traversal: " << endl;
    preorderTraversal(root);

    cout << "\nPostorder Traversal: " << endl;
    postorderTraversal(root);

    return 0;
}