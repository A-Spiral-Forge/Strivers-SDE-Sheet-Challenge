#include <bits/stdc++.h> 
using namespace std;

template <typename T>
class TreeNode {
    public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Helper function to create current subtree
TreeNode<int> *solve(vector<int> &inorder, vector<int> &preorder, map<int, int> &mappings, int n, int inStart, int inEnd, int &preIdx) {
    // If all the elements in preorder traversal are traversed
    if(preIdx >= n) {
        // Return NULL
        return NULL;
    }

    // If the current subtree is empty
    if(inStart > inEnd) {
        // Decrement preIdx as it was incremented in the previous call
        preIdx--;
        // Return NULL
        return NULL;
    }

    // Create the root of current subtree
    TreeNode<int> *root = new TreeNode<int>(preorder[preIdx]);

    // Find the index of current root in inorder traversal
    int inIdx = mappings[preorder[preIdx]];
    // Increment preIdx
    preIdx++;
    // Create the left subtree
    root->left = solve(inorder, preorder, mappings, n, inStart, inIdx - 1, preIdx);
    preIdx++;
    // Create the right subtree
    root->right = solve(inorder, preorder, mappings, n, inIdx + 1, inEnd, preIdx);
    // Return the root of current subtree
    return root;
}

// Main function
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    int n = inorder.size();
	// Map to store the index of each element in inorder traversal
    map<int, int> mappings;
    for(int i=0; i<n; i++) {
        mappings[inorder[i]] = i;
    }
    // preIdx is used to keep track of the current element in preorder traversal
    int preIdx = 0;
    // Call the helper function
    return solve(inorder, preorder, mappings, n, 0, n - 1, preIdx);
}