#include <bits/stdc++.h> 
using namespace std;

template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> res;

    // If root is null
    if(!root) {
        return res;
    }
    // Map to store the horizontal distance and their nodes
    map<int, vector<int>> m;
    // Queue to store the node and its horizontal distance
    queue<pair<TreeNode<int>*, int>> q;
    // Push the root node with horizontal distance 0
    q.push({root, 0});

    while(!q.empty()) {
        // Pop the front element
        pair<TreeNode<int>*, int> temp = q.front();
        q.pop();
        // Push the in map on the horizontal distance
        m[temp.second].push_back(temp.first->data);

        // Push the left and right child of the node with horizontal distance
        if(temp.first->left) {
            q.push({temp.first->left, temp.second - 1});
        }
        if(temp.first->right) {
            q.push({temp.first->right, temp.second + 1});
        }
    }

    // Traverse the map and push the node data in the vector
    // starting from the left most horizontal distance
    for(const pair<int, vector<int>> &it: m) {
        for(const int &it2: it.second) {
            res.push_back(it2);
        }
    }
    // Return the vector
    return res;
}