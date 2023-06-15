#include <bits/stdc++.h> 
using namespace std;
	
template <typename T>
class TreeNode 
{
    public : 
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val) 
    {
        this -> val = val;
        left = NULL;
        right = NULL;
    }
};

// Helper function to find the maximum sum between two leaves
// and the maximum sum from root to any leaf of current subtree
pair<long long, long long> solve(TreeNode<int> *root) {
    // if root is null, return {-1, -1}
    if(!root) {
        return {-1, -1};
    }
    // if root is a leaf node, return {-1, root->val}
    if(!root->left && !root->right) {
        return {-1, root->val};
    }

    // find the maximum sum between two leaves in left subtree
    pair<long long, long long> left = solve(root->left);
    // find the maximum sum between two leaves in right subtree
    pair<long long, long long> right = solve(root->right);
    // if left subtree is null, return {-1, right.second + root->val}
    if(!root->left) {
        return {-1, right.second + root->val};
    }
    // if right subtree is null, return {-1, left.second + root->val}
    if(!root->right) {
        return {-1, left.second + root->val};
    }

    // find the maximum sum between two leaves in current subtree
    long long curr = left.second + right.second + root->val;
    long long first = max(left.first, max(right.first, curr));
    // find the maximum sum from root to any leaf of current subtree
    long long second = max(left.second, right.second) + root->val;

    // return {first, second}
    return {first, second};
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    // Call the helper function and return the first element of the pair
    return solve(root).first;
}