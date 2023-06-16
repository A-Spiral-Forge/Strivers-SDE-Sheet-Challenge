#include <bits/stdc++.h> 
using namespace std;

template < typename T >
class BinaryTreeNode
{
public :
    T data;
    BinaryTreeNode < T > *left;
    BinaryTreeNode < T > *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

// Helper function to change the tree
int helper(BinaryTreeNode<int> *root, int value) {
    // If root is NULL, return 0
    if(!root) {
        return 0;
    }

    // Add current root data to value
    value += root->data;
    // Divide value into two parts
    int leftval = value / 2, rightval = value - (value / 2);
    // If left child is NULL, then whole value goes to right child
    if(!root->left) {
        rightval = value;
    }
    // If right child is NULL, then whole value goes to left child
    if(!root->right) {
        leftval = value;
    }

    // Recursively call for left and right child
    int left = helper(root->left, leftval);
    int right = helper(root->right, rightval);

    // Update root data with maximum of value or left + right
    root->data = max(value, left + right);
    // Return updated root data
    return root->data;
}

void changeTree(BinaryTreeNode < int > * root) {
    // If root is NULL, return
    if(!root) {
        return;
    }
    // Call helper function with value 0
    helper(root, 0);
}