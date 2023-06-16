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

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int> *current = root;
    // While current is not NULL
    while(current) {
        // If current has no left child, move to right
        if(!current->left) {
            current = current->right;
        } else {
            // Find inorder predecessor of current
            TreeNode<int> *inorderPredecessor = current->left;
            while(inorderPredecessor->right && inorderPredecessor->right != current) {
                inorderPredecessor = inorderPredecessor->right;
            }

            // If inorder predecessor's right is current
            if(inorderPredecessor->right) {
                // Make current's right child as inorder predecessor's right child
                inorderPredecessor->right = current->right;
                // Make current's left child as its right child
                current->right = current->left;
                // Make current's left child as NULL
                current->left = NULL;
                // Move current to its right child
                current = current->right;
            // If inorder predecessor's right is NULL
            } else {
                // Make current as inorder predecessor's right child
                inorderPredecessor->right = current;
            }
        }
    }

    // Return root after flattening
    return root;
}