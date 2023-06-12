#include <bits/stdc++.h> 
using namespace std;

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
    void insert(string &word) {
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
    bool search(string &word) {
        TrieNode *node = root;
        for(char &ch: word) {
            // If the node for the current character doesn't exist, return false
            if(node->children[ch - 'a'] == NULL) {
                return false;
            }
            // Move to the child node
            node = node->children[ch - 'a'];
            if(!node->isTerminal) {
                return false;
            }
        }
        // Return if the last node is terminal
        return true;
    }
};

// Function to compare two strings
string compare(string &a, string &b) {
    int as = a.size(), bs = b.size();
    if(as > bs) {
        return a;
    }
    if(as < bs) {
        return b;
    }

    return min(a, b);
}

string completeString(int n, vector<string> &a){
    Trie tree;
    // Insert all the strings in the trie
    for(string &s: a) {
        tree.insert(s);
    }

    string res = "";
    // Find the lexicographically smallest string for which all the 
    // prefixes are present in the array
    for(string &s: a) {
        if(tree.search(s)) {
            // Compare the current string with the result
            res = compare(res, s);
        }
    }

    return res == "" ? "None" : res;
}