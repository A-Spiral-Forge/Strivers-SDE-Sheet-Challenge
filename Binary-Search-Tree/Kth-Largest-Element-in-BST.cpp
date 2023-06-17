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

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // If root is NULL, return -1
    if (!root) {
        return -1;
    }

    // Morris Reverse Inorder Traversal
    TreeNode<int> *curr = root;
    // Count to keep track of number of nodes visited
    int count = 0;
    // Traverse the tree
    while (curr) {
        // If right child is NULL
        if (curr->right == NULL) {
            // Increment count
            count++;
            // If count is equal to k, return current node data
            if (count == k) {
                return curr->data;
            }
            // Move to left child
            curr = curr->left;
        } else {
            // Find inorder successor of current node
            TreeNode<int> *node = curr->right;
            while (node->left != NULL and node->left != curr) {
                node = node->left;
            }

            // If left child of inorder successor is NULL
            if (node->left == NULL) {
                // Set left child of inorder successor to current node
                node->left = curr;
                // Move to right child
                curr = curr->right;
            } else {
                // If left child of inorder successor is not NULL
                node->left = NULL;
                // Increment count
                count++;
                // If count is equal to k, return current node data
                if (count == k) {
                    // Return current node data
                    return curr->data;
                }
                // Move to left child
                curr = curr->left;
            }
        }
    }

    // if k is greater than number of nodes in BST
    // return -1
    return -1;
}
