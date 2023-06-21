#include <bits/stdc++.h> 
using namespace std;

// Find parent of a node in Disjoint Set
int findParent(vector<int> &parent, int node) {
	// If node is parent of itself
	if(parent[node] == node) {
		// Return node
		return node;
	}
	// Else find parent of parent of node and return it
	return parent[node] = findParent(parent, parent[node]);
}

// Union two nodes in Disjoint Set
void unionNodes(vector<int> &parent, int node1, int node2) {
	// Make parent of node1 as parent of node2
	parent[node1] = node2;
}

// Comparator function for sorting edges in increasing order of weight
bool comp(vector<int> &a, vector<int> &b) {
	return a[2] < b[2];
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	// Sort edges in increasing order of weight
	sort(graph.begin(), graph.end(), comp);
	// Initialize parent array
	vector<int> parent(n + 1, 0);
	// Initialize parent of each node as itself
	for(int i=1; i<=n; i++) {
		parent[i] = i;
	}
	// Initialize sum of weights of MST
	int sum = 0;
	// Iterate over all edges
	for(int i=0; i<m; i++) {
		// Find parent of node1 and node2
		int parentu = findParent(parent, graph[i][0]);
		int parentv = findParent(parent, graph[i][1]);
		// If parent of node1 and node2 are same,
		// then both nodes are already in same component
		if(parentu == parentv) {
			continue;
		}
		// Else add weight of edge to sum
		sum += graph[i][2];
		// Union node1 and node2, merge their components
		unionNodes(parent, parentu, parentv);
	}
	// Return sum of weights of MST
	return sum;
}