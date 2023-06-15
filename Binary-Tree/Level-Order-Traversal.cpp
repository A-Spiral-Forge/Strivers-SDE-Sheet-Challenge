#include <bits/stdc++.h> 
using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
    T val;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int> res;
    // If root is null return empty vector
    if(!root) {
        return res;
    }

    // Queue for level order traversal
    queue<BinaryTreeNode<int>*> q;
    // Push the root
    q.push(root);

    // Do level order traversal
    while(!q.empty()) {
        // Pop the front element
        BinaryTreeNode<int> *temp = q.front();
        q.pop();
        // Push the value of the current node
        res.push_back(temp->val);

        // Push the children of the current node
        if(temp->left) {
            q.push(temp->left);
        }
        if(temp->right) {
            q.push(temp->right);
        }
    }
    // Return the level order traversal
    return res;
}