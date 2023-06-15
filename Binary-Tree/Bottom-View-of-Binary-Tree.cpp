#include <bits/stdc++.h> 
using namespace std;

template <typename T>
class BinaryTreeNode 
{
public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

// Bottom View of Binary Tree
vector<int> bottomView(BinaryTreeNode<int> * root){
    vector<int> res;

    // If root is null
    if(!root) {
        return res;
    }
    // Map to store the horizontal distance and the node data
    map<int, int> m;
    // Queue to store the node and its horizontal distance
    queue<pair<BinaryTreeNode<int>*, int>> q;
    // Push the root node with horizontal distance 0
    q.push({root, 0});

    while(!q.empty()) {
        // Pop the front element
        pair<BinaryTreeNode<int>*, int> temp = q.front();
        q.pop();
        // Update the map with the horizontal distance and the node data
        m[temp.second] = temp.first->data;

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
