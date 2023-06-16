#include<bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode { 
    public:
    T data; 
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) 
    { 
        this -> data = data; 
        left = NULL; 
        right = NULL; 
    }
};

TreeNode<int> *solve(vector<int> &postOrder, vector<int> &inOrder, map<int, int> &mappings, int n, int inStart, int inEnd, int &postIdx) {
    // If postIdx < 0, then there are no more elements in postOrder
    if(postIdx < 0) {
        // Return NULL
        return NULL;
    }

    // If inStart > inEnd, then subtree is empty
    if(inStart > inEnd) {
        // Since we are decrementing postIdx, we need to increment it here
        postIdx++;
        // Return NULL
        return NULL;
    }

    // Create a new node with the data at postIdx
    TreeNode<int> *root = new TreeNode<int>(postOrder[postIdx]);
    // Get the index of the root in inOrder
    int inIdx = mappings[postOrder[postIdx]];

    // Decrement postIdx
    postIdx--;
    // Recursively call solve for the right subtree
    root->right = solve(postOrder, inOrder, mappings, n, inIdx + 1, inEnd, postIdx);
    // Decrement postIdx
    postIdx--;
    // Recursively call solve for the left subtree
    root->left = solve(postOrder, inOrder, mappings, n, inStart, inIdx - 1, postIdx);
    
    // Return the root
    return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
    int n = postOrder.size();
    // Create a map to store the indices of the elements in inOrder
    map<int, int> mappings;
    for(int i=0; i<n; i++) {
        mappings[inOrder[i]] = i;
    }

    // Create a variable to store the index of the current element in postOrder
    int postIdx = n - 1;
    // Call the recursive function
    return solve(postOrder, inOrder, mappings, n, 0, n - 1, postIdx);
}
