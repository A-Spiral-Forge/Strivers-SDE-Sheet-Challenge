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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> res;
    // If root is null return empty vector
    if(!root) {
        return res;
    }

    // Create a queue and push root node
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    // Create a levelIndex variable to keep track of level
    int levelIndex = 0;

    // Run a loop until queue is empty
    while(!q.empty()) {
        // Get the size of queue
        int qs = q.size();
        // Create a vector to store the level elements
        vector<int> level;
        // Traverse the level
        while(qs--) {
            // Get the front element of queue
            BinaryTreeNode<int> *node = q.front();
            q.pop();

            // Push the element in level vector
            level.push_back(node->data);
            // Push the left and right child of node if exists
            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push(node->right);
            }
        }

        // If levelIndex is odd then reverse the level vector
        if(levelIndex % 2 == 1) {
            reverse(level.begin(), level.end());
        }
        // Push the level vector in result vector
        for(int &it: level) {
            res.push_back(it);
        }
        // Increment the levelIndex
        levelIndex++;
    }
    
    // Return the result vector
    return res;
}
