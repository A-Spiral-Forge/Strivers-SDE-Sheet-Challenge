#include <bits/stdc++.h> 
using namespace std;

// Class to represent Trie Node
class TrieNode {
    public:
    vector<TrieNode*> children;
    bool isTerminal;

    TrieNode() {
        this->children.resize(26, NULL);
        this->isTerminal = false;
    }
};

// Class to represent Trie
class Trie {
    private:
    // Root of Trie
    TrieNode *root = new TrieNode();

    public:
    // Insert a word into Trie
    void insert(string &word) {
        TrieNode *node = root;
        for(char &ch: word) {
            if(!node->children[ch - 'a']) {
                node->children[ch - 'a'] = new TrieNode();
            }
            node = node->children[ch - 'a'];
        }
        node->isTerminal = true;
    }

    // Search if part of word (from start to end) is present in Trie
    bool search(string &word, int start, int end) {
        TrieNode *node = root;
        for(int i=start; i<=end; i++) {
            if(!node->children[word[i] - 'a']) {
                return false;
            }
            node = node->children[word[i] - 'a'];
        }
        return node->isTerminal;
    }
};

bool solve(string &target, Trie &tree, int idx, int m, vector<int> &dp) {
    // If we have reached the end of target string
    // then we have found a valid word break
    if(idx == m) {
        return true;
    }
    // If we have already solved this subproblem
    // then return the answer
    if(dp[idx] != -1) {
        return dp[idx];
    }
    bool res = false;
    // Try to find a valid word break from idx to m
    for(int j=idx; j<m; j++) {
        // If we have found a valid word break from idx to j
        if(tree.search(target, idx, j)) {
            // Try to find a valid word break from j + 1 to m
            res = res || solve(target, tree, j + 1, m, dp);
        }
    }
    // Store the answer for this subproblem
    return dp[idx] = res;
}

// Function to return true if target string can be broken into words present in arr
bool wordBreak(vector < string > & arr, int n, string & target) {
    // Build a Trie of all the words present in arr
    Trie tree;
    for(string &word: arr) {
        tree.insert(word);
    }
    // m is the length of target string
    int m = target.size();
    // dp[i] stores if target[i...m-1] can be broken into words present in arr
    vector<int> dp(m + 1, -1);
    // Return the answer for the subproblem target[0...m-1]
    return solve(target, tree, 0, m, dp);
}