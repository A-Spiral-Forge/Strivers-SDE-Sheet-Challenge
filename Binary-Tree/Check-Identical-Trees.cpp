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

// Check if two binary trees are identical or not.
bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // If both trees are empty, return true
    if(!root1 && !root2) {
        return true;
    }

    // If one of the trees is empty, return false
    if(!root1 ^ !root2) {
        return false;
    }

    // If data of both trees is not same, return false
    if(root1->data != root2->data) {
        return false;
    }

    // Check if left and right subtrees are identical
    bool left = identicalTrees(root1->left, root2->left);
    bool right = identicalTrees(root1->right, root2->right);

    // Return true if both trees are identical
    return left && right;
}