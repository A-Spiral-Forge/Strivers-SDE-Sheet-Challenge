#include <bits/stdc++.h>
using namespace std;

// Check if a graph is bipartite or not
bool isGraphBirpatite(vector<vector<int>> &edges) {
    // Number of nodes
	int n = edges.size();
    // Adjacency list
	vector<vector<int>> adj(n);
    // Make Adjacency list
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
            // If there is an edge between i and j
			if(edges[i][j] == 1) {
                // Add j to the adjacency list of i
				adj[i].push_back(j);
                // Add i to the adjacency list of j
				adj[j].push_back(i);
			}
		}
	}

    // Color of each node
	vector<int> color(n, 0);
    // 0: Not visited
    // 1: Color 1
    // -1: Color 2
    // Check for each node
	for(int i=0; i<n; i++) {
        // If the node is already colored, skip it
		if(color[i] != 0) {
			continue;
		}
        // Queue for BFS
		queue<int> q;
		q.push(i);
        // Color the node with 1
		color[i] = 1;
		// BFS
		while(!q.empty()) {
            // Get the front node
			int node = q.front();
			q.pop();
            // Check for all the adjacent nodes
			for(int &it: adj[node]) {
                // If the node is not visited
				if(color[it] == 0) {
                    // Color the node with opposite color of the current node
					color[it] = -color[node];
                    // Push the node to the queue
					q.push(it);
				} else {
                    // If the node is already visited and the color is same as the current node
					if(color[it] == color[node]) {
                        // The graph is not bipartite
						return false;
					}
				}
			}
		}
	}
    // The graph is bipartite, if can be colored with 2 colors
	return true;
}