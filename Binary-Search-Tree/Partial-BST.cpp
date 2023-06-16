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

// Helper function to check if a binary tree is a BST
bool helper(BinaryTreeNode<int> *root, int minRange, int maxRange) {
    // If root is NULL, return true
    if(!root) {
        return true;
    }

    // If root data is less than minRange or greater than maxRange, return false
    if(root->data < minRange || root->data > maxRange) {
        return false;
    }

    // Check if left subtree is BST and right subtree is BST
    return helper(root->left, minRange, root->data) && helper(root->right, root->data, maxRange);
}

bool validateBST(BinaryTreeNode<int> *root) {
    // Call helper function with INT_MIN and INT_MAX as minRange and maxRange
    return helper(root, INT_MIN, INT_MAX);
}