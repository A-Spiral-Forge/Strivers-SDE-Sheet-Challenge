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
};

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // If root is NULL, return false
    if(!root) {
        return false;
    }

    // If root data is equal to x, return true
    // We have found the element
    if(root->data == x) {
        return true;
    }

    // If root data is less than x, search in right subtree
    if(root->data < x) {
        return searchInBST(root->right, x);
    }
    // If root data is greater than x, search in left subtree
    return searchInBST(root->left, x);
}