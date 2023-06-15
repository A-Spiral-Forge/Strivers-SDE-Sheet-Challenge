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

// Helper function to find if a binary tree is height balanced
// Returns a pair of a boolean and an integer
// The boolean value is true if the subtree is height balanced
// The integer value is the height of the subtree
pair<bool, int> solve(BinaryTreeNode<int> *root) {
    // If the root is NULL, return {true, 0}
    if(!root) {
        return {true, 0};
    }

    // Recursively find if the left and right subtrees are height balanced
    pair<bool, int> left = solve(root->left);
    pair<bool, int> right = solve(root->right);
    // Calculate if the current subtree is height balanced
    bool currVal = (abs(left.second - right.second) > 1) ? false : true;

    // Return the boolean value of the current subtree and 
    // the maximum of the heights of the left and right 
    // subtrees plus 1 for the current node
    return {left.first && right.first && currVal, max(left.second, right.second) + 1};
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Call the helper function and return the boolean value
    return solve(root).first;
}