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

class BSTiterator
{
    public:
    
    TreeNode<int> *curr;

    BSTiterator(TreeNode<int> *root)
    {
        curr = root;
    }

    int next()
    {
        // Store the result
        int res = -1;
        // Partial Morris Traversal
        while(curr) {
            // If left is NULL
            if(curr->left == NULL) {
                // Store the current data
                res = curr->data;
                // Move to right
                curr = curr->right;
                // Break as we have found the result
                break;
            } else {
                // Find the inorder predecessor
                TreeNode<int> *pre = curr->left;
                while(pre->right && pre->right != curr) {
                    pre = pre->right;
                }

                // If right of predecessor is NULL
                if(pre->right == NULL) {
                    // Make the current node as right child of predecessor
                    pre->right = curr;
                    // Move to left
                    curr = curr->left;
                } else {
                    // If right of predecessor is not NULL
                    res = curr->data;
                    // Make the right of predecessor as NULL
                    pre->right = NULL;
                    // Move to right
                    curr = curr->right;
                    // Break as we have found the result
                    break;
                }
            }
        }
        // Return the result
        return res;
    }

    bool hasNext()
    {
        // Return true if curr is not NULL
        // If curr is NULL then we have reached the end of the tree
        // curr is used to find the next node to be visited
        return curr != NULL;
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/