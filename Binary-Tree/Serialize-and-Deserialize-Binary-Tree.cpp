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

string serializeTree(TreeNode<int> *root)
{
    // If root is NULL, return empty string
    if(!root) {
        return "";
    }

    // Else, do level order traversal
    string res = "";
    queue<TreeNode<int>*> q;
    q.push(root);

    // Add root to string with a delimiter
    res += to_string(root->data) + "#";
    // Level order traversal
    while(!q.empty()) {
        // Pop the front element
        TreeNode<int> *curr = q.front();
        q.pop();

        // If left child exists, add it to string with a delimiter
        // and push it to queue
        if(curr->left) {
            q.push(curr->left);
            res += to_string(curr->left->data) + "#";
        // Else, add a N (for NULL) to string with a delimiter
        } else {
            res += "N#";
        }

        // If right child exists, add it to string with a delimiter
        // and push it to queue
        if(curr->right) {
            q.push(curr->right);
            res += to_string(curr->right->data) + "#";
        // Else, add a N (for NULL) to string with a delimiter
        } else {
            res += "N#";
        }
    }

    // Return the string
    return res;
}

TreeNode<int>* deserializeTree(string &serialized)
{
    int n = serialized.size();
    // If string is empty, return NULL
    if(n == 0) {
        return NULL;
    }

    queue<TreeNode<int>*> q;
    int i = 0;
    // Get the root value
    string gtemp = "";
    // Traverse till delimiter
    while(serialized[i] != '#') {
        gtemp += serialized[i];
        i++;
    }

    // Create root node
    TreeNode<int> *root = new TreeNode<int>(stoi(gtemp));
    // Push root to queue
    q.push(root);
    // Do level order traversal
    while(!q.empty()) {
        // Pop the front element
        TreeNode<int> *curr = q.front();
        q.pop();

        // Get left and right child values
        string left = "", right = "";
        // Increment i to skip delimiter
        i++;
        // Traverse till delimiter for left child
        while(serialized[i] != '#') {
            left += serialized[i];
            i++;
        }
        // Increment i to skip delimiter
        i++;
        // Traverse till delimiter for right child
        while(serialized[i] != '#') {
            right += serialized[i];
            i++;
        }

        // If left child is NULL, set it to NULL
        if(left == "N") {
            curr->left = NULL;
        // Else, create a new node and push it to queue
        } else {
            curr->left = new TreeNode<int>(stoi(left));
            q.push(curr->left);
        }

        // If right child is NULL, set it to NULL
        if(right == "N") {
            curr->right = NULL;
        // Else, create a new node and push it to queue
        } else {
            curr->right = new TreeNode<int>(stoi(right));
            q.push(curr->right);
        }
    }

    // Return the root
    return root;
}