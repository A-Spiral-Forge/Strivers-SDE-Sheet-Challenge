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

int getMaxWidth(TreeNode<int> *root)
{
    // If root is null return 0
    if(!root) {
        return 0;
    }

    int res = 0;
    queue<TreeNode<int>*> q;
    q.push(root);

    // Else do level order traversal keeping track of max width
    while(!q.empty()) {
        // Get the size of the queue - current width
        int qs = q.size();
        // Update max width
        res = max(res, qs);
        // Traverse the current level
        while(qs--) {
            TreeNode<int> *temp = q.front();
            q.pop();

            // Push the children of the current node
            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }

    // Return the max width
    return res;
}