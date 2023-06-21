#include <bits/stdc++.h>
using namespace std;

// Kosaraju's Algorithm
// Function to store the nodes according to their finishing time (in topological sort order)
void makeVisitedTime(vector<vector<int>> &adj, stack<int> &nodes, vector<bool> &vis, int node) {
    // Mark the current node as visited
    vis[node] = true;
    // Traverse for all its children
    for(int &it: adj[node]) {
        // If child is visited, skip
        if(vis[it]) {
            continue;
        }
        // Else, traverse for the child
        makeVisitedTime(adj, nodes, vis, it);
    }
    // Push the current node into the stack
    nodes.push(node);
}
// Function to traverse the graph in reverse direction
void traverseSCC(vector<vector<int>> &adj, vector<bool> &vis, int node, vector<int> &current) {
    // Mark the current node as visited
    vis[node] = true;
    // Push the current node into the current SCC
    current.push_back(node);
    // Traverse for all its children
    for(int &child: adj[node]) {
        // If child is visited, skip
        if(vis[child]) {
            continue;
        }
        // Else, traverse for the child
        traverseSCC(adj, vis, child, current);
    }
}
// Function to find the strongly connected components
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Create the adjacency list and reverse adjacency list
    vector<vector<int>> adj(n);
    vector<vector<int>> revAdj(n);
    // Fill the adjacency list and reverse adjacency list
    for(const vector<int> &it: edges) {
        adj[it[0]].push_back(it[1]);
        revAdj[it[1]].push_back(it[0]);
    }

    vector<bool> vis(n, false);
    // Create a stack to store the nodes according to their finishing 
    // time (in topological sort order)
    stack<int> nodes;
    // Traverse the graph and store the nodes according to their finishing time
    for(int i=0; i<n; i++) {
        if(vis[i]) {
            continue;
        }
        makeVisitedTime(adj, nodes, vis, i);
    }
    // Clear the visited array
    vis.assign(n, false);
    // Create a vector to store the strongly connected components
    vector<vector<int>> res;
    // Traverse the stack
    while(!nodes.empty()) {
        // Get the top node
        int node = nodes.top();
        nodes.pop();
        // If node is visited, skip
        if(vis[node]) {
            continue;
        }
        // Else, traverse the graph in reverse direction
        vector<int> current;
        traverseSCC(revAdj, vis, node, current);
        // Push the current SCC into the result
        res.push_back(current);
    }
    // Return the result
    return res;
}