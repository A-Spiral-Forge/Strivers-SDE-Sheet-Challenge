#include <bits/stdc++.h> 
using namespace std;

template <typename T>
class TreeNode {
    public :
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};

// Function to store left boundary of a binary tree
void leftBoundaryTraversal(TreeNode<int> *root, vector<int> &res) {
    // If root is null, return
    if(!root) {
        return;
    }
    // If root is not leaf node, return
    if(!root->left && !root->right) {
        return;
    }

    // Push the current node's data in vector
    res.push_back(root->data);
    // If left child not present, recur for right child
    if(!root->left) {
        leftBoundaryTraversal(root->right, res);
    }
    // Else recur for left child
    leftBoundaryTraversal(root->left, res);
}

// Function to store leaf nodes of a binary tree
void leafBoundaryTraversal(TreeNode<int> *root, vector<int> &res) {
    // If root is null, return
    if(!root) {
        return;
    }
    // If root is leaf node, store its data
    if(!root->left && !root->right) {
        res.push_back(root->data);
        return;
    }

    // Recur for left and right subtrees
    leafBoundaryTraversal(root->left, res);
    leafBoundaryTraversal(root->right, res);
}

// Function to store right boundary of a binary tree
void rightBoundaryTraversal(TreeNode<int> *root, vector<int> &res) {
    // If root is null, return
    if(!root) {
        return;
    }
    // If root is leaf node, return
    if(!root->left && !root->right) {
        return;
    }

    // If right child is not present, recur for left child
    if(!root->right) {
        rightBoundaryTraversal(root->left, res);
    }
    // Else recur for right child
    rightBoundaryTraversal(root->right, res);
    // Push the current node's data in vector
    res.push_back(root->data);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    // If root is null, return
    if(!root) {
        return {};
    }

    vector<int> left, leaf, right;
    // Store the left boundary in vector left
    leftBoundaryTraversal(root->left, left);
    // Store the leaf nodes in vector leaf
    leafBoundaryTraversal(root->left, leaf);
    leafBoundaryTraversal(root->right, leaf);
    // Store the right boundary in vector right
    rightBoundaryTraversal(root->right, right);

    vector<int> res;
    // Push the root's data in vector
    res.push_back(root->data);
    // Push the left boundary in vector
    for(int &it: left) {
        res.push_back(it);
    }
    // Push the leaf nodes in vector
    for(int &it: leaf) {
        res.push_back(it);
    }
    // Push the right boundary in vector
    for(int &it: right) {
        res.push_back(it);
    }

    // Return the final vector
    return res;
}