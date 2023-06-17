#include <bits/stdc++.h> 
using namespace std;

template <typename T>
class BinaryTreeNode {
    public: 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

class BSTiterator
{
    public:
    // Stack to store inorder traversal and reverse inorder traversal
    stack<BinaryTreeNode<int>*> start, end;

    BSTiterator(BinaryTreeNode<int> *root)
    {   
        BinaryTreeNode<int> *curr = root;
        // Push left nodes in start stack till left node exists
        while(curr) {
            start.push(curr);
            curr = curr->left;
        }

        curr = root;
        // Push right nodes in end stack till right node exists
        while(curr) {
            end.push(curr);
            curr = curr->right;
        }
    }

    BinaryTreeNode<int> *getStart()
    {
        // Return top of start stack
        // Top of start stack is the left pointer in two pointer approach
        return start.top();
    }
    
    bool hasNext()
    {
        // If start stack is empty, return false
        // We have reached end of inorder traversal
        return !start.empty();
    }

    void popStart() {
        // Pop top of start stack
        BinaryTreeNode<int> *curr = start.top();
        start.pop();

        // If right node exists, push it and all its left nodes in start stack
        if(curr->right) {
            start.push(curr->right);
            curr = curr->right;
            while(curr->left) {
                start.push(curr->left);
                curr = curr->left;
            }
        }
    }

    BinaryTreeNode<int> *getEnd() {
        // Return top of end stack
        // Top of end stack is the right pointer in two pointer approach
        return end.top();
    }

    void popEnd() {
        // Pop top of end stack
        BinaryTreeNode<int> *curr = end.top();
        end.pop();

        // If left node exists, push it and all its right nodes in end stack
        if(curr->left) {
            end.push(curr->left);
            curr = curr->left;
            while(curr->right) {
                end.push(curr->right);
                curr = curr->right;
            }
        }
    }

    bool hasPrev() {
        // If end stack is empty, return false
        // We have reached start of inorder traversal
        return !end.empty();
    }
};

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Create iterator object
    BSTiterator *it = new BSTiterator(root);
    // Two pointer approach
    // While start and end pointers exist
    while(it->hasNext() && it->hasPrev()) {
        // Get start and end pointers
        BinaryTreeNode<int> *a = it->getStart(), *b = it->getEnd();
        // If start and end pointers are same, return false
        if(a == b) {
            return false;
        }

        // If sum of start and end pointers is k, return true
        if(a->data + b->data == k) {
            return true;
        }
        // If sum of start and end pointers is greater than k, pop end pointer
        if(a->data + b->data > k) {
            it->popEnd();
        // If sum of start and end pointers is less than k, pop start pointer
        } else {
            it->popStart();
        }
    }
    // If sum of any two nodes is not k, return false
    return false;
}