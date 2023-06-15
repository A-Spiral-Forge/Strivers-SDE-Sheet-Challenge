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

// Helper function to find path from root to a destination node
bool getPath(TreeNode<int> *root, vector<int> &path, int dest) {
    // If the root is NULL, return false
    if(!root) {
        return false;
    }

    // Push the root's data into the path vector
    path.push_back(root->data);
    // If the root's data is equal to the destination, return true
    if(root->data == dest) {
        return true;
    }

    // Recursively find the path from the root's left and right subtrees
    if(getPath(root->left, path, dest)) {
        return true;
    }
    if(getPath(root->right, path, dest)) {
        return true;
    }

    // If the destination is not found, pop the root's data from the path vector
    path.pop_back();
    return false;
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    // Find the paths from the root to the nodes with data x and y
	vector<int> pathx, pathy;
    getPath(root, pathx, x);
    getPath(root, pathy, y);

    // Calculate the lengths of the paths
    int lenx = pathx.size(), leny = pathy.size();

    int res = -1;
    // Compare the paths
    for(int i=0; i<min(lenx, leny); i++) {
        // If the nodes are not equal, return the last common node
        if(pathx[i] != pathy[i]) {
            return res;
        }

        // Update the last common node
        res = pathx[i];
    }

    // Return the last common node
    return res;
}