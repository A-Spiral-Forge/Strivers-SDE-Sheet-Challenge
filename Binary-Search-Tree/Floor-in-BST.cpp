#include <bits/stdc++.h> 
using namespace std;

template <typename T>
class TreeNode {
    public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int floorInBST(TreeNode<int> * root, int X)
{
    // Find parent of X which is either equal to X or just smaller than X
    // which is predecessor of X
    TreeNode<int> *preParent = new TreeNode<int>(-1);
    // While root is not NULL and root data is not equal to X
    while(root && root->val != X) {
        // If root data is less than X
        if(root->val < X) {
            // Update predecessor parent
            preParent = root;
            // Go to right subtree
            root = root->right;
        } else {
            // If root data is greater than X, go to left subtree
            root = root->left;
        }
    }

    // If root is not NULL, means X is present in BST
    if(root) {
        // Return X
        return root->val;
    }

    // If root is NULL, means X is not present in BST
    // Return predecessor parent data
    return preParent->val;
}