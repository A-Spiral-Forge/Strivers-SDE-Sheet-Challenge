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
        for(int i=31; i>=0; i--) {
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
        for(int i=31; i>=0; i--) {
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

// Make class to store the queries with their index
// and sort them according to the limit
class QueryNode {
	public:
	int value;
	int limit;
	int index;

	bool operator()(QueryNode &a, QueryNode &b) {
		return a.limit < b.limit;
	}
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	Trie tree;
    // Sort the array of numbers in ascending order
	sort(arr.begin(), arr.end());

    // n stores the size of the array
    // q stores the number of queries
	int n = arr.size(), q = queries.size(); 
    // index stores the index of the current number
	int index = 0;
    // res stores the answer for each query
	vector<int> res(q);
    // query stores the queries with their index
	vector<QueryNode> query;
    // Store the queries with their index
	for(int i=0; i<q; i++) {
		QueryNode temp = {
			queries[i][0],
			queries[i][1],
			i
		};
		query.push_back(temp);
	}
    // Sort the queries according to the limit
	sort(query.begin(), query.end(), QueryNode());

    // Iterate over the queries with their index
	for(QueryNode &it: query) {
        // Insert the numbers in the trie till the limit of the current query
		while(index < n && arr[index] <= it.limit) {
			tree.insert(arr[index]);
			index++;
		}
        // Find the maximum XOR of the current number with any number in the trie
        // As we only inserted numbers less than or equal to the limit of the current query
        // the maximum XOR will be the answer for the current query
        // If no number is inserted in the trie, the answer will be -1
		res[it.index] = index == 0 ? -1 : tree.findMaxXor(it.value);
	}
    // Return the answer
	return res;
}