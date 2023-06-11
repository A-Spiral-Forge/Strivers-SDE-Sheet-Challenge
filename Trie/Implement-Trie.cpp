#include<bits/stdc++.h>
using namespace std;

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

// Class to make Node of Trie
class TrieNode {
    public:
    vector<TrieNode*> children;
    bool isTerminal;

    // Constructor
    TrieNode() {
        children.resize(26, NULL);
        isTerminal = false;
    }
};

// Class to implement Trie
class Trie {
private:
    TrieNode *root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *node = root;
        for(char &ch: word) {
            // If the node for the current character doesn't exist, create it
            if(node->children[ch - 'a'] == NULL) {
                node->children[ch - 'a'] = new TrieNode();
            }
            // Move to the child node
            node = node->children[ch - 'a'];
        }
        // Mark the last node as terminal
        node->isTerminal = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *node = root;
        for(char &ch: word) {
            // If the node for the current character doesn't exist, return false
            if(node->children[ch - 'a'] == NULL) {
                return false;
            }
            // Move to the child node
            node = node->children[ch - 'a'];
        }
        // Return if the last node is terminal
        return node->isTerminal;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for(char &ch: prefix) {
            // If the node for the current character doesn't exist, return false
            if(node->children[ch - 'a'] == NULL) {
                return false;
            }
            // Move to the child node
            node = node->children[ch - 'a'];
        }
        // Return true, if the prefix exists
        return true;
    }
};