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

// LCA of two nodes in a BST
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    // If Node P is greater than Node Q, swap them
    if(P->data > Q->data) {
        return LCAinaBST(root, Q, P);
    }
    // If root is NULL, return NULL
	if(!root) {
        return NULL;
    }
    // If root data is equal to P or Q, return root
    // because one of them is the LCA
    if(root->data == P->data || root->data == Q->data) {
        return root;
    }
    // If root data is greater than P and less than Q, return root
    // because root is the LCA
    // Both nodes are opposite sides of the root
    if(root->data > P->data && root->data < Q->data) {
        return root;
    }

    // If root data is greater than P and Q, search in left subtree
    if(root->data > P->data) {
        return LCAinaBST(root->left, P, Q);
    }
    // If root data is less than P and Q, search in right subtree
    return LCAinaBST(root->right, P, Q);
}
