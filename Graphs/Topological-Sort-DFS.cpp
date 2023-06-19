#include <bits/stdc++.h> 
using namespace std;

// Topological Sort using DFS
void dfs(vector<vector<int>> &adj, vector<bool> &vis, stack<int> &topoSort, int node) {
    // Traverse all the children of the current node
    for(int &child: adj[node]) {
        // If the child is not visited, visit it
        if(!vis[child]) {
            vis[child] = true;
            dfs(adj, vis, topoSort, child);
        }
    }
    // Push the current node to the stack when backtracking
    topoSort.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Create the adjacency list
    vector<vector<int>> adj(v); 
    for(const vector<int> &it: edges) {
        adj[it[0]].push_back(it[1]);
    }

    // Make a stack to store the reverse topological sort
    stack<int> topoSort;
    // Make a visited array
    vector<bool> vis(v, false);
    // Traverse all the nodes
    for(int i=0; i<v; i++) {
        // If the node is already visited, continue
        if(vis[i]) {
            continue;
        }
        // Else visit the node
        vis[i] = true;
        // Call the dfs function
        dfs(adj, vis, topoSort, i);
    }

    // Make a vector to store the topological sort
    vector<int> res;
    // Pop the elements from the stack and store them in the vector
    while(!topoSort.empty()) {
        res.push_back(topoSort.top());
        topoSort.pop();
    }
    // Return the topological sort
    return res;
}