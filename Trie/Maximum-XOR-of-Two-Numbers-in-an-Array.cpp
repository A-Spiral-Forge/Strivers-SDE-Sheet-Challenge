#include <bits/stdc++.h> 
using namespace std;

// Class to make Node of Trie
class TrieNode {
    public:
    vector<TrieNode*> children;

    TrieNode() {
        children.resize(2, NULL);
    }
};

// Class to implement Trie
class Trie {
    private:
    TrieNode *root = new TrieNode();

    public:
    // Inserts a number into the trie
    void insert(int num) {
        TrieNode *node = root;
        for(int i=29; i>=0; i--) {
            // If the bit is set
            if(num & (1 << i)) {
                // If the node for the current bit doesn't exist, create it
                if(node->children[1] == NULL) {
                    node->children[1] = new TrieNode();
                }
                // Move to the child node
                node = node->children[1];
            // If the bit is not set
            } else {
                // If the node for the current bit doesn't exist, create it
                if(node->children[0] == NULL) {
                    node->children[0] = new TrieNode();
                }
                // Move to the child node
                node = node->children[0];
            }
        }
    }

    // Finds the maximum XOR of the given number with any number in the trie
    // having index less than or equal to the given number
    int findMaxXor(int num) {
        TrieNode *node = root;
        // Stores the answer
        int ans = 0;
        for(int i=29; i>=0; i--) {
            // Left shift the answer by 1
            ans <<= 1;
            // If the bit is set
            if(num & (1 << i)) {
                // If the node for the opposite bit not exist, 
                // move to the node for the same bit
                if(node->children[0] == NULL) {
                    node = node->children[1];
                } else {
                    node = node->children[0];
                    // Set the last bit of the answer if the node for the opposite bit exists
                    ans = ans | 1;
                }
            } else {
                // If the node for the opposite bit not exist, 
                // move to the node for the same bit
                if(node->children[1] == NULL) {
                    node = node->children[0];
                } else {
                    node = node->children[1];
                    // Set the last bit of the answer if the node for the opposite bit exists
                    ans = ans | 1;
                }
            }
        }
        // Return the answer
        return ans;
    }
};

int maximumXor(vector<int> A)
{
    int res = 0;
    Trie tree;
    for(int &it: A) {
        // Insert elemtns in the trie and find the maximum XOR
        tree.insert(it);
        res = max(res, tree.findMaxXor(it));
    }
    // Return the answer
    return res;
}