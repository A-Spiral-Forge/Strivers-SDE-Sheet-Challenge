#include <bits/stdc++.h> 
using namespace std;

template <typename T>
class BinaryTreeNode {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        BinaryTreeNode<T> *next;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
            next = NULL;
        }
};

void connectNodes(BinaryTreeNode< int > *root) {
    // If root is NULL, return
    if(root == NULL) {
        return;
    }

    // Create a queue and push root to it
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    // While queue is not empty
    while(!q.empty()) {
        // Get the size of queue, current level size
        int qs = q.size();
        // Traverse the level
        for(int i=qs-1; i>=0; i--) {
            // Get the front node
            BinaryTreeNode<int> *node = q.front();
            q.pop();
            // If curent node is not the last node of the level
            // then connect it to the next node
            if(i > 0) {
                node->next = q.front();
            }

            // Rest of the code is same as level order traversal
            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push(node->right);
            }
        }
    }
}