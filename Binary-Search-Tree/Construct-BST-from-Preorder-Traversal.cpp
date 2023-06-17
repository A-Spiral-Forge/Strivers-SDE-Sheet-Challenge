#include <bits/stdc++.h> 
using namespace std;

template <typename T>
class TreeNode{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~TreeNode() {
        if (left){
            delete left;
        }
        if (right){
            delete right;
        }
    }
};

// Function to construct BST from inorder traversal
TreeNode<int> *solve(vector<int> &preOrder, int start, int end) {
    // If start is greater than end, return NULL
    if(start > end) {
        return NULL;
    }

    // Find the mid element
    int mid = (start + end) / 2;
    // Create a new node with mid element
    TreeNode<int> *root = new TreeNode<int>(preOrder[mid]);
    // Call the solve function recursively for left and right subtrees
    root->left = solve(preOrder, start, mid - 1);
    root->right = solve(preOrder, mid + 1, end);
    // Return the root
    return root;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    int n = preOrder.size();
    // Sort the preorder array, to get inorder array
    // as the tree is a BST
    sort(preOrder.begin(), preOrder.end());
    // Call the solve function
    return solve(preOrder, 0, n - 1);
}