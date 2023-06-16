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

TreeNode<int> *helper(vector<int> &arr, int low, int high) {
    // If low is greater than high, return NULL
    if(low > high) {
        return NULL;
    }

    // Find the middle element
    int mid = low + (high - low) / 2;
    // Create a new node with the middle element
    TreeNode<int> *root = new TreeNode<int>(arr[mid]);

    // Recursively call helper function for left and right subtrees
    root->left = helper(arr, low, mid - 1);
    root->right = helper(arr, mid + 1, high);

    // Return the root
    return root;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Call helper function
    return helper(arr, 0, n - 1);
}