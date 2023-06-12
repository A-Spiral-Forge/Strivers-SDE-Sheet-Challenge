#include <bits/stdc++.h> 
using namespace std;

// Class for Trie Node
class TrieNode {
    public:
    // Children of Trie Node
    vector<TrieNode*> children;
    // Count of words passing through this node
    int count;
    // Is this node a terminal node
    bool isTerminal;

    // Constructor
    TrieNode() {
        children.resize(26, NULL);
        count = 0;
        isTerminal = false;
    }
};

// Class to implement Trie
class Trie{
    private:
    TrieNode *root;

    public:
    Trie(){
        // Initialize root node
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(string &word){
        TrieNode *node = root;
        for(char &ch: word) {
            // If the child node doesn't exist, create a new node
            if(node->children[ch - 'a'] == NULL) {
                node->children[ch - 'a'] = new TrieNode();
            }
            // Move to the child node
            node = node->children[ch - 'a'];
            // Increment the count of words passing through this node
            node->count++;
        }
        // Mark the last node as a terminal node
        node->isTerminal = true;
    }

    // Count the number of words equal to a given word
    int countWordsEqualTo(string &word){
        TrieNode *node = root;
        // Traverse the Trie
        for(char &ch: word) {
            if(node->children[ch - 'a'] == NULL) {
                return 0;
            }
            // Move to the child node
            node = node->children[ch - 'a'];
        }

        // Count of words passing through this node
        int res = node->count;
        for(int i=0; i<26; i++) {
            // Subtract the count of words passing through the node
            // which are not equal to the given word
            if(node->children[i] != NULL) {
                res -= node->children[i]->count;
            }
        }
        // Return the count of words equal to the given word
        return res;
    }

    int countWordsStartingWith(string &word){
        TrieNode *node = root;
        // Traverse the Trie
        for(char &ch: word) {
            // If the child node doesn't exist, return 0
            if(node->children[ch - 'a'] == NULL) {
                return 0;
            }
            // Move to the child node
            node = node->children[ch - 'a'];
        }
        // Return the count of words passing through this node
        return node->count;
    }

    void erase(string &word){
        TrieNode *node = root;
        // Traverse the Trie
        for(char &ch: word) {
            // If the child node doesn't exist, return here
            if(node->children[ch - 'a'] == NULL) {
                return;
            }
            // Move to the child node
            node = node->children[ch - 'a'];
            // Decrement the count of words passing through this node
            node->count--;
        }

        // Count words ending at this node
        int res = node->count;
        for(int i=0; i<26; i++) {
            if(node->children[i] != NULL) {
                res -= node->children[i]->count;
            }
        }

        // If the count of words passing through this node is greater than 0
        // then unmark this node as a terminal node
        if(res > 0) {
            node->isTerminal = false;
        }
    }
};
