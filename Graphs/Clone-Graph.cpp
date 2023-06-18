#include <bits/stdc++.h> 
using namespace std;

class graphNode
{
    public:
        int data;
    vector<graphNode *> neighbours;
    graphNode()
    {
        data = 0;
        neighbours = vector<graphNode *>();
    }

    graphNode(int val)
    {
        data = val;
        neighbours = vector<graphNode *>();
    }

    graphNode(int val, vector<graphNode *> neighbours)
    {
        data = val;
        this->neighbours = neighbours;
    }
};

// Helper function to perform DFS traversal and create a copy of the graph
graphNode *helper(graphNode *node, map<graphNode*, graphNode*> &mapping) {
    // If the node is NULL, return NULL
	if(!node) {
		return NULL;
	}
    // If the node is already visited, return the corresponding node from the map
	if(mapping.find(node) != mapping.end()) {
		return mapping[node];
	}
    // Create a copy of the current node
	graphNode *root = new graphNode(node->data);
    // Add the current node to the map
	mapping[node] = root;
    // Traverse the neighbours of the current node and 
    // add them to the neighbours of the copy of the current node
	for(int i=0; i<node->neighbours.size(); i++) {
		root->neighbours.push_back(helper(node->neighbours[i], mapping));
	}
    // Return the copy of the current node
	return root;
}

// Function to clone a graph. It takes the head node of the graph as input
graphNode *cloneGraph(graphNode *node)
{
    // Store the mapping of the nodes of the original 
    // graph to the nodes of the cloned graph
    map<graphNode*, graphNode*> mapping;
    // Call the helper function to perform DFS 
    // traversal and create a copy of the graph
	return helper(node, mapping);
}