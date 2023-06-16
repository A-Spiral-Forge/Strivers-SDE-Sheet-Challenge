#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
    ~BinaryTreeNode() {
        if(left) 
            delete left;
        if(right) 
            delete right;
    }
};

// Helper function to check if two trees are mirror of each other
bool helper(BinaryTreeNode<int> *left, BinaryTreeNode<int> *right) {
    // If both are null, they are mirror of each other
    if(!left && !right) {
        return true;
    }
    // If one of them is null, they are not mirror of each other
    if(!left ^ !right) {
        return false;
    }
    // If both are not null, check if their data is same 
    // and their left and right are mirror of each other
    if(left->data != right->data) {
        return false;
    }

    return helper(left->left, right->right) && helper(left->right, right->left);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    // If root is null, it is symmetric
    if(!root) {
        return true;
    }
    // Else check if left and right subtree are mirror of each other
    return helper(root->left, root->right);
}