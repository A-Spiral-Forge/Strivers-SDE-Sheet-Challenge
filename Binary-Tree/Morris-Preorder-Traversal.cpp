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

// Morris Preorder Traversal
vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> res;

    // While there are nodes to process
    while(root) {
        // If left child is NULL, print the current node data. Move to right child.
        if(!root->left) {
            res.push_back(root->data);
            root = root->right;
        } else {
            // Find inorder predecessor
            TreeNode *inorderPredecessor = root->left;
            while(inorderPredecessor->right && inorderPredecessor->right != root) {
                inorderPredecessor = inorderPredecessor->right;
            }

            // If the right child of inorder predecessor is NULL, 
            // push the current node data and link the right child to current node,
            // then go left after establishing link from predecessor to root.
            if(inorderPredecessor->right == NULL) {
                res.push_back(root->data);
                inorderPredecessor->right = root;
                root = root->left;
            } else {
                // If right child already points to the current node, then break the link.
                // Move to right child of current node.
                inorderPredecessor->right = NULL;
                root = root->right;
            }
        }
    }

    // Return the result
    return res;
}