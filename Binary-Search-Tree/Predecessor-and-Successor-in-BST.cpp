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

    ~BinaryTreeNode() {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Store the parent, they can be predecessor and successor
    BinaryTreeNode<int> *preParent = new BinaryTreeNode<int>(-1);
    BinaryTreeNode<int> *succParent = new BinaryTreeNode<int>(-1);

    // Search for the key
    while(root && root->data != key) {
        // If root data is greater than key, 
        // update parent which can be successor
        // and search in left subtree
        if(root->data > key) {
            succParent = root;
            root = root->left;
        } else {
        // If root data is less than key,
        // update parent which can be predecessor
        // and search in right subtree
            preParent = root;
            root = root->right;
        }
    }

    // If key is not present in the tree
    if(!root) {
        // Return {-1, -1}
        return {-1, -1};
    }

    // If key is present in the tree
    BinaryTreeNode<int> *pre = root->left, *succ = root->right;
    // Find the predecessor and successor
    while(pre && pre->right) {
        pre = pre->right;
    }
    while(succ && succ->left) {
        succ = succ->left;
    }

    // Initialize the answer as parent predecessor and successor
    pair<int, int> ans = {preParent->data, succParent->data};
    
    // If predecessor is not NULL, update the answer
    if(pre) {
        ans.first = pre->data;
    }
    // If successor is not NULL, update the answer
    if(succ) {
        ans.second = succ->data;
    }
    // Return the answer
    return ans;
}
