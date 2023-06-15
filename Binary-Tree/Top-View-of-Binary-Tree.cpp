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

// Top View of Binary Tree
vector<int> getTopView(TreeNode<int> *root) {
    vector<int> res;

    // If root is null
    if(!root) {
        return res;
    }
    // Map to store the horizontal distance and the node data
    map<int, int> m;
    // Queue to store the node and its horizontal distance
    queue<pair<TreeNode<int>*, int>> q;
    // Push the root node with horizontal distance 0
    q.push({root, 0});

    while(!q.empty()) {
        // Pop the front element
        pair<TreeNode<int>*, int> temp = q.front();
        q.pop();
        
        // If the horizontal distance is not present in the map
        // then add the node data in the map
        if(m.find(temp.second) == m.end()) {
            m[temp.second] = temp.first->val;
        }

        // Push the left and right child of the node with horizontal distance
        if(temp.first->left) {
            q.push({temp.first->left, temp.second - 1});
        }
        if(temp.first->right) {
            q.push({temp.first->right, temp.second + 1});
        }
    }

    // Traverse the map and push the node data in the vector
    for(const pair<int, int> &it: m) {
        res.push_back(it.second);
    }
    // Return the vector
    return res;
}