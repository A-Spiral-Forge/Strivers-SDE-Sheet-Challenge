#include <bits/stdc++.h>
using namespace std;

// DFS Traversal
void dfs(vector<vector<int>> &adj, vector<bool> &vis, vector<int> &traversal, int node) {
    // Push the current node into the traversal
    traversal.push_back(node);
    // Traverse all the adjacent nodes of the current node
    for(int &child: adj[node]) {
        // If the adjacent node is not visited, then visit it
        if(!vis[child]) {
            // Mark the adjacent node as visited
            vis[child] = true;
            // Traverse the adjacent node
            dfs(adj, vis, traversal, child);
        }
    }
}

// Function to return a list containing the DFS traversal of the graph.
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Make an adjacency list
    vector<vector<int>> adj(V);
    for(const vector<int> &it: edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    // Make a visited array
    vector<vector<int>> res;
    vector<bool> vis(V, false);
    // Traverse all the nodes of the graph
    for(int i=0; i<V; i++) {
        // If the current node is not visited, then visit it
        if(!vis[i]) {
            // Make a traversal vector
            vector<int> traversal;
            // Mark the current node as visited
            vis[i] = true;
            // Traverse the current node
            dfs(adj, vis, traversal, i);
            // Push the traversal into the result
            res.push_back(traversal);
        }
    }
    // Return the result
    return res;
}