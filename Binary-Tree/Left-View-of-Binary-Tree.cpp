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


vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> res;
    queue<TreeNode<int>*> q;
    // Push the root node
    if(root) {
        q.push(root);
    }

    // Level order traversal
    while(!q.empty()) {
        int qs = q.size();
        // Traverse the current level
        for(int i=0; i<qs; i++) {
            // Front of the queue
            TreeNode<int> *node = q.front();
            q.pop();

            // Push the first node of the current level
            if(i == 0) {
                res.push_back(node->data);
            }

            // Push the left and right child of the current node, if exists
            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push(node->right);
            }
        }
    }

    // Return the result
    return res;
}