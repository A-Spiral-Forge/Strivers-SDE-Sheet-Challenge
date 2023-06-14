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

// Morris Inorder Traversal
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> res;
    
    // While root is not NULL
    while(root) {
        // If left child is NULL, print the current node data and move to right child
        if(!root->left) {
            res.push_back(root->data);
            root = root->right;
        } else {
            // Find inorder predecessor
            TreeNode *inorderPredecessor = root->left;
            // To find inorder predecessor keep moving right until right node 
            // is not NULL or right node is not current node
            while(inorderPredecessor->right && inorderPredecessor->right != root) {
                inorderPredecessor = inorderPredecessor->right;
            }

            // If right node is NULL then go left after establishing link from
            // inorder predecessor to current node
            if(inorderPredecessor->right == NULL) {
                inorderPredecessor->right = root;
                root = root->left;
            } else {
                // If right node is not NULL then remove link from inorder predecessor
                // to current node, print the current node data and move to right child
                // of current node
                res.push_back(root->data);
                inorderPredecessor->right = NULL;
                root = root->right;
            }
        }
    }

    // Return the inorder traversal
    return res;
}