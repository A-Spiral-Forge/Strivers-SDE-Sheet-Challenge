#include <bits/stdc++.h> 
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

// Preorder Traversal helper function
void helper(TreeNode *root, vector<int> &res) {
    if(!root) {
        return;
    }

    // Push the data in the vector
    // This is the only difference between the three traversals
    // Preorder: Root, Left, Right
    res.push_back(root->data);
    helper(root->left, res);
    helper(root->right, res);
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> res;
    helper(root, res);
    return res;
}