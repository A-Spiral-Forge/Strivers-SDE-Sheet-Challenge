#include <bits/stdc++.h>
using namespace std;

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Make adjacency list
    vector<vector<int>> adj(n + 1);
    for(const vector<int> &it: edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    // Make a visited array
    vector<bool> vis(n + 1, false);

    // Traverse the nodes
    for(int i=1; i<=n; i++) {
        // Skip if already visited
        if(vis[i]) {
            continue;
        }
        // Make a queue for BFS
        queue<pair<int, int>> q;
        // Push the current node and its parent
        q.push({i, -1});
        // Mark the current node as visited
        vis[i] = true;
        // Traverse the graph
        while(!q.empty()) {
            // Pop the front node
            pair<int, int> node = q.front();
            q.pop();
            // Push the adjacent nodes to the queue
            for(int &it: adj[node.first]) {
                // Skip if already visited
                if(vis[it]) {
                    // If visited and not the parent of the current node
                    if(it != node.second) {
                        // Cycle detected
                        return "Yes";
                    }
                    // Skip if the node is the parent of the current node
                    continue;
                }
                // Mark the node as visited
                vis[it] = true;
                // Push the node and its parent to the queue
                q.push({it, node.first});
            }
        }
    }
    // No cycle detected
    return "No";
}
