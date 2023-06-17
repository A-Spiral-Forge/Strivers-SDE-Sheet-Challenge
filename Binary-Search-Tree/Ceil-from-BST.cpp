#include <bits/stdc++.h> 
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    
    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    
    ~BinaryTreeNode() {
        if (left) {
            delete left;
        }
        if (right) {
            delete right;
        }
    }
};

int findCeil(BinaryTreeNode<int> *root, int X){
    // Find the successor parent node
    BinaryTreeNode<int> *succParent = new BinaryTreeNode<int>(-1);
    // Traverse the tree
    while(root && root->data != X) {
        // If root data is less than X, go to right subtree
        if(root->data < X) {
            root = root->right;
        } else {
            // If root data is greater than X, go to left subtree
            // Update the successor parent node
            succParent = root;
            root = root->left;
        }
    }
    // If root is not NULL, return root data
    if(root) {
        return root->data;
    }
    // If root is NULL, return successor parent data
    return succParent->data;
}