#include <bits/stdc++.h> 
using namespace std;

template <typename T>
class BinaryTreeNode
{
public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};


// Inorder Traversal helper function
void inorder(BinaryTreeNode<int> *root, vector<int> &res) {
    if(!root) {
        return;
    }

    inorder(root->left, res);
    // Push the data in the vector
    // This is the only difference between the three traversals
    // Inorder: Left, Root, Right
    res.push_back(root->data);
    inorder(root->right, res);
}

// Preorder Traversal helper function
void preorder(BinaryTreeNode<int> *root, vector<int> &res) {
    if(!root) {
        return;
    }

    // Push the data in the vector
    // This is the only difference between the three traversals
    // Preorder: Root, Left, Right
    res.push_back(root->data);
    preorder(root->left, res);
    preorder(root->right, res);
}

// Postorder Traversal helper function
void postorder(BinaryTreeNode<int> *root, vector<int> &res) {
    if(!root) {
        return;
    }

    // Push the data in the vector
    // This is the only difference between the three traversals
    // Postorder: Left, Right, Root
    postorder(root->left, res);
    postorder(root->right, res);
    res.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> res(3);
    inorder(root, res[0]);
    preorder(root, res[1]);
    postorder(root, res[2]);
    return res;
}