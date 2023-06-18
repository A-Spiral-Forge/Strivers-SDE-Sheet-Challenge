#include <bits/stdc++.h>
using namespace std;

// Detect cycle in a directed graph using DFS
bool dfs(vector<vector<int>> &adj, vector<bool> &vis, set<int> &path, int node, int parent) {
    for(int &child: adj[node]) {
        // If the node is present in the path, then there is a cycle
        if(path.find(child) != path.end()) {
            return true;
        }
        // If the node is already visited, then skip it
        if(vis[child]) {
            continue;
        }
        // Mark the node as visited and add it to the path
        vis[child] = true;
        path.insert(child);
        // If there is a cycle in the subtree, then return true
        if(dfs(adj, vis, path, child, node)) {
            return true;
        }
        // Remove the node from the path, as we are backtracking
        path.erase(child);
    }

    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    // Make an adjacency list
    vector<vector<int>> adj(n + 1);
    for(const pair<int, int> &it: edges) {
        adj[it.first].push_back(it.second);
    }
    // Make a visited array to keep track of visited nodes
    vector<bool> vis(n + 1, false);
    // For each node, check if there is a cycle in the subtree
    for(int i=1; i<=n; i++) {
        // If the node is already visited, then skip it
        if(vis[i]) {
            continue;
        }
        // Make a path set to keep track of nodes in the path
        set<int> path;
        // Mark the node as visited and add it to the path
        path.insert(i);
        vis[i] = true;
        // If there is a cycle in the subtree, then return true
        if(dfs(adj, vis, path, i, -1)) {
            return 1;
        }
    }
    // If there is no cycle, then return false
    return 0;
}