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

// Class to store information of at current binary tree node
class Node {
    public:
    // Stores the minimum value in the binary tree
    int leftlim;
    // Stores the maximum value in the binary tree
    int rightlim;
    // Stores the size of largest BST in the binary tree
    int ans;
    // Stores the size of current BST
    int curr;

    // Parameterized Constructor
    Node(int leftlim, int rightlim, int ans, int curr) {
        this->leftlim = leftlim;
        this->rightlim = rightlim;
        this->ans = ans;
        this->curr = curr;
    }
};

// Function to find the size of largest BST in the binary tree
Node *isBST(TreeNode<int> *root) {
    // If the binary tree is empty
    // then return a node with minimum value as INT_MAX,
    // maximum value as INT_MIN, size as 0 and current as 0
    if(!root) {
        return new Node(INT_MAX, INT_MIN, 0, 0);
    }

    // Recursively traverse the left subtree
    Node *left = isBST(root->left);
    // Recursively traverse the right subtree
    Node *right = isBST(root->right);

    // If left or right subtree is not BST
    if(left->curr == -1 || right->curr == -1) {
        // Return a node with current as -1, ans as maximum of left and right subtrees
        int f = min(root->data, left->leftlim);
        int s = max(root->data, right->rightlim);
        int ans = max(left->ans, right->ans);
        return new Node(f, s, ans, -1);
    }

    // If the current node's data is greater than the maximum value in the left subtree
    // and less than the minimum value in the right subtree
    // then the current node is a part of BST
    // so return a node with minimum value as minimum value of left subtree,
    // maximum value as maximum value of right subtree,
    // size as size of left subtree + size of right subtree + 1 and 
    // current as size of left subtree + size of right subtree + 1
    if(root->data >= left->rightlim && root->data <= right->leftlim) {
        int f = min(root->data, left->leftlim);
        int s = max(root->data, right->rightlim);
        int ans = left->curr + right->curr + 1;
        int curr = left->curr + right->curr + 1;

        return new Node(f, s, ans, curr);
    }

    // Else the current node is not a part of BST
    // return a node with current as -1, ans as maximum of left and right subtrees
    // and ans as maximum of left and right subtrees
    int f = min(root->data, left->leftlim);
    int s = max(root->data, right->rightlim);
    int ans = max(left->ans, right->ans);
    return new Node(f, s, ans, -1);
}

int largestBST(TreeNode<int>* root) 
{
    // Call the recursive function to find the size of largest BST in the binary tree
    return isBST(root)->ans;
}