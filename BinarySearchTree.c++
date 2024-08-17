#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        //constructor
        Node(int d) {
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* insertIntoBST(Node* root, int d) {
    //base case
    if (root == NULL) {
        root = new Node(d);  //agar koi root nahi hai toh create kardo
        return root;
    }

    if (d > root-> data) {  //jo data hai, wo root se bada hai, toh right part me inert karna hai
        root->right = insertIntoBST(root->right, d);
    }
    else{
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

void takeinput(Node* &root) {
    int data;
    cin >> data;

    while(data != -1){  //jab tak user -1 nahi daalega main data leta rahunga
        root = insertIntoBST(root, data);
        cin >> data;
    }
    
}

void levelOrderTraversal(Node* root) {
    if (root == NULL) return;
    queue<Node*> q;  //queue bana li node* type ki
    q.push(root);  //sabse pehle ek element daal do , root element hi daal do
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left != NULL) q.push(current->left);
        if (current->right != NULL) q.push(current->right);
    }
}


void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

bool searchInBST(Node* root, int key) {
    // Base case
    if (root == NULL) {
        return false;
    }

    if (root->data == key) {
        return true;
    }

    if (key > root->data) {
        return searchInBST(root->right, key);
    } else {
        return searchInBST(root->left, key);
    }
}

Node* deleteFromBST(Node* root, int val) {
    if (root == NULL){
        return root;

    if (root->data == val){
    //the node that you want to delete has 0 child
    if(root->left == NULL && root->right == NULL){
        delete root;
        return NULL;
    }
    //the node that you want to delete has 1 child
    //now either that 1 child is left o right
    //left child
    if(root->left != NULL && root->right == NULL){
        Node* temp = root->left; //node delete karne se pehle pichle node ko store kara do
        delete root;
        return temp;
    }
    //right child
    if(root->left == NULL && root->right != NULL){
        Node* temp = root->right; //node delete karne se pehle pichle node ko store kara do
        delete root;
        return temp;
    }

    //the node that you want to delete has 2 children
    if(root->left != NULL && root->right !=NULL)  {
        int min = minVal(root->right) ->data;   //right me se ek minimum value ko nikalo aur jo node delete karre hai usse replace kardo
        root->data = min;
        root->right = deleteFromBST(root->right, min);
        return root;
    }    

    } else if (root->data > val){
        root ->left = deleteFromBST(root->left, val);
        return root;
    }
    else{
        root ->right = deleteFromBST(root->right, val);
        return root;
    }
    }
}

int main() {
    Node* root = NULL; // Create a root node
    cout << "Enter data to create BST" << endl;
    takeinput(root); // Build the tree

    cout << "Level Order Traversal of the BST:" << endl;
    levelOrderTraversal(root);

    cout << "Inorder Traversal of the BST:" << endl;
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal of the BST:" << endl;
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal of the BST:" << endl;
    postorderTraversal(root);
    cout << endl;

    // Search for an element
    int key;
    cout << "Enter an element to search in BST: ";
    cin >> key;
    if (searchInBST(root, key)) {
        cout << "Element " << key << " is present in the BST." << endl;
    } else {
        cout << "Element " << key << " is not present in the BST." << endl;
    }

    return 0;
}