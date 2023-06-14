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

// Postorder Traversal helper function
void helper(TreeNode *root, vector<int> &res) {
    if(!root) {
        return;
    }

    // Push the data in the vector
    // This is the only difference between the three traversals
    // Postorder: Left, Right, Root
    helper(root->left, res);
    helper(root->right, res);
    res.push_back(root->data);
}

vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> res;
    helper(root, res);
    return res;
}