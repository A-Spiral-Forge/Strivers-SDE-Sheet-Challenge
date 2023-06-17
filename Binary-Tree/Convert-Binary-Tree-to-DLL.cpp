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

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // If tree is empty, return NULL.
    if(!root) {
        return NULL;
    }

    // If tree is non-empty, convert it.
    // Find the leftmost node in BT, which will be the head of DLL.
    BinaryTreeNode<int> *res = root;
    while(res->left) {
        res = res->left;
    }

    // Now convert the tree to DLL using Morris Traversal.
    while(root) {
        // If left child is NULL
        if(root->left == NULL) {
            // If right child is not NULL
            if(root->right) {
                // Find the inorder successor of root
                BinaryTreeNode<int> *succ = root->right;
                while(succ->left && succ->left != root) {
                    succ = succ->left;
                }
                
                BinaryTreeNode<int> *right = root->right;
                // Make the right child of root point to the successor
                root->right = succ;
                // Make the successor's left child point to root
                succ->left = root;
                // Take root to its right child
                root = right;
            } else {
                // If right child is NULL, take root to its right child
                root = root->right;
            }
        } else {
            // If left child is not NULL
            // Find the inorder predecessor of root
            BinaryTreeNode<int> *pre = root->left;
            while(pre->right && pre->right != root) {
                pre = pre->right;
            }

            // If the right child of predecessor is NULL
            if(pre->right == NULL) {
                // Make the right child of predecessor point to root
                pre->right = root;
                BinaryTreeNode<int> *left = root->left;
                // Make the left child of root point to predecessor
                root->left = pre;
                // Take root to its left child
                root = left;
            } else {
                // If the right child of predecessor is not NULL
                // If right child of root is not NULL
                if(root->right) {
                    // Find the inorder successor of root
                    BinaryTreeNode<int> *succ = root->right;
                    while(succ->left && succ->left != root) {
                        succ = succ->left;
                    }
                    
                    BinaryTreeNode<int> *right = root->right;
                    // Make the right child of root point to the successor
                    root->right = succ;
                    // Make the successor's left child point to root
                    succ->left = root;
                    // Take root to its right child
                    root = right;
                } else {
                    // If right child of root is NULL, take root to its right child
                    root = root->right;
                }
            }
        }
    }

    // Return the head of DLL
    return res;
}