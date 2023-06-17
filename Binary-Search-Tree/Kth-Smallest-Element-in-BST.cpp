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

int kthSmallest(TreeNode<int> *root, int k)
{
    TreeNode<int> *curr = root;
    // Store the answer
    int ans = 0;
    // Count to keep track of number of nodes visited
    int count = 0;
    // Traverse the tree
	while(curr) {
        // If left child is NULL
        if(curr->left == NULL) {
            // Increment count
            count++;
            // If count is equal to k, store current node data in ans
            if(count == k) {
                ans = curr->data;
            }
            // Move to right child
            curr = curr->right;
        } else {
            // Find inorder predecessor of current node
            TreeNode<int> *pre = curr->left;
            while(pre->right && pre->right != curr) {
                pre = pre->right;
            }

            // If right child of inorder predecessor is NULL
            if(pre->right == NULL) {
                // Set right child of inorder predecessor to current node
                pre->right = curr;
                // Move to left child
                curr = curr->left;
            } else {
                // Set right child of inorder predecessor to NULL
                pre->right = NULL;
                // Increment count
                count++;
                // If count is equal to k, store current node data in ans
                if(count == k) {
                    ans = curr->data;
                }
                // Move to right child
                curr = curr->right;
            }
        }
    }

    // Return the answer
    return ans;
}