#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
    public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Helper function to find the diameter and height of a binary subtree
// Returns a pair of the diameter and height of the subtree
pair<int, int> solve(TreeNode<int> *root) {
    // If the root is NULL, return {0, 0}
    if(!root) {
        return {0, 0};
    }

    // Recursively find the diameter and height of the left and right subtrees
    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);
    // Calculate the diameter of the current subtree
    int currdia = left.second + right.second;

    // Return the maximum of the diameter of the current subtree 
    // and the diameters of the left and right subtrees
    // Also return the maximum of the heights of the left and right subtrees
    // plus 1 for the current node
    return {max({left.first, right.first, currdia}), max(left.second, right.second) + 1};
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    // Call the helper function and return the diameter of the binary tree
	return solve(root).first;
}
