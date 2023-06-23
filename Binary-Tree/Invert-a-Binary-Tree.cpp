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

// Function to get the path from root to given leaf node
bool getPath(TreeNode<int> *root, TreeNode<int> *leaf, stack<TreeNode<int>*> &path) {
    // If root is NULL, return false
    if(!root) {
        return false;
    }
    // Push the root to the stack
    path.push(root);
    // If root is the leaf node
    if(!root->left && !root->right) {
        // If root is the given leaf node, return true
        if(root->data == leaf->data) {
            return true;
        }
        // Else, pop the root from the stack and return false
        path.pop();
        return false;
    }
    // If left subtree has the leaf node, return true
    if(getPath(root->left, leaf, path)) {
        return true;
    }
    // If right subtree has the leaf node, return true
    if(getPath(root->right, leaf, path)) {
        return true;
    }
    // If the leaf node is not present in the subtree, 
    // pop the root from the stack and return false
    path.pop();
    return false;
}

// Function to invert a binary tree
TreeNode<int> * invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf) {
    // If root is NULL, return NULL
	if(!root) {
        return root;
    }
    // Get the path from root to the given leaf node
    stack<TreeNode<int>*> path;
    getPath(root, leaf, path);

    // Get the root of the inverted binary tree
    // which is given leaf node of the original binary tree
    // and top of the stack
    TreeNode<int> *res = path.top();
    // Pop the top of the stack
    path.pop();
    // Get the parent of the root of the inverted binary tree
    TreeNode<int> *parent = res;
    // While the stack is not empty
    while(!path.empty()) {
        // Get the top of the stack
        TreeNode<int> *node = path.top();
        // Pop the top of the stack
        path.pop();
        // If node is the right child of the parent
        if(node->right == parent) {
            // Set the right child of the node to left child of the node
            node->right = node->left;
            // Set the left child of the node to NULL
            node->left = NULL;
        // If node is the not right child of the parent
        } else {
            // Set the left child of the node to NULL
            node->left = NULL;
        }

        // Set the left child of the parent to the node
        parent->left = node;
        // Set the parent of the node to the parent
        parent = node;
    }
    // Return the root of the inverted binary tree
    return res;
}
