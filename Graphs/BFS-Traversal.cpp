#include <bits/stdc++.h> 
using namespace std;

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Make adjacency list
    vector<vector<int>> adj(vertex);
    for(const pair<int, int> &it: edges) {
        adj[it.first].push_back(it.second);
        adj[it.second].push_back(it.first);
    }
    // Sort the adjacency list
    for(vector<int> &it: adj) {
        sort(it.begin(), it.end());
    }
    // Make a visited array
    vector<bool> vis(vertex, false);
    vector<int> res;
    // Traverse the nodes
    for(int i=0; i<vertex; i++) {
        // Skip if already visited
        if(vis[i]) {
            continue;
        }
        // Make a queue for BFS
        queue<int> q;
        // Push the current node
        q.push(i);
        // Mark the current node as visited
        vis[i] = true;
        // Traverse the graph
        while(!q.empty()) {
            // Pop the front node
            int node = q.front();
            q.pop();
            // Push the node to the result
            res.push_back(node);
            // Push the adjacent nodes to the queue
            for(int &it: adj[node]) {
                // Skip if already visited
                if(!vis[it]) {
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
    }
    
    // Return the result
    return res;
}