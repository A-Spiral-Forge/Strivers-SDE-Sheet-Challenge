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
    int insert(string &word, int start, int n) {
        TrieNode *node = root;
        int count = 0;
        for(int i=start; i<n; i++) {
            // If the node for the current character doesn't exist, create it
            // and increase the count of new substring
            if(node->children[word[i] - 'a'] == NULL) {
                count++;
                node->children[word[i] - 'a'] = new TrieNode();
            }
            // Move to the child node
            node = node->children[word[i] - 'a'];
        }
        // Mark the last node as terminal
        node->isTerminal = true;
        // Return the count of new substrings
        return count;
    }

    
};

int distinctSubstring(string &word) {
    int n = word.size();
    Trie tree;

    int count = 0;
    // Insert all the suffixes of the string in the trie
    // For each suffix, count the number of new substrings
    for(int i=0; i<n; i++) {
        count += tree.insert(word, i, n);
    }
    // Return the count of new substrings
    return count;
}
