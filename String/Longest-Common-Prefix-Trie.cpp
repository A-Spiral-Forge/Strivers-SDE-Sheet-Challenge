#include <bits/stdc++.h>
using namespace std;

// Trie Node class
class TrieNode {
    public:
    char value;
    TrieNode* child;
    int count;

    // Constructor
    TrieNode(char value = '0') {
        this->value = value;
        this->child = NULL;
        this->count = 0;
    }
};

class Trie {
    private:
    // Root node
    TrieNode *root = new TrieNode();
    // Total words in the trie
    int words = 0;

    public:
    // Insert a word in the trie
    void insert(string &word) {
        TrieNode *node = root;
        // Increment total words
        words++;
        // Traverse the word
        for(char &ch: word) {
            // If the child node is present
            if(node->child) {
                // If the child node is not equal to the current character
                if(node->child->value != ch) {
                    // break the loop
                    break;
                }
            // If the child node is not present
            } else {
                // Create a new child node
                node->child = new TrieNode(ch);
            }
            // Move to the child node
            node = node->child;
            // Increment the count of the node
            node->count++;
        }
    }

    // Get the longest common prefix
    string getLongestCommonPrefix() {
        TrieNode* node = root;
        string res = "";
        // If the child node exists and the count of the child node is equal to the total words
        // then add the character to the result and move to the child node
        while(node->child && node->child->count == words) {
            res += node->child->value;
            node = node->child;
        }
        // Return the result
        return res;
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Create a trie
    Trie tree;
    // Insert all the words in the trie
    for(string &word: arr) {
        tree.insert(word);
    }

    // Return the longest common prefix
    return tree.getLongestCommonPrefix();
}