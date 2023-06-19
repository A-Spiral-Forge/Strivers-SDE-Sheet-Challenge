#include <bits/stdc++.h> 
using namespace std;

// Kahn's Algorithm for Topological Sort
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Create the adjacency list
    vector<vector<int>> adj(v); 
    // Create the indegree array
    vector<int> indegree(v, 0);
    for(const vector<int> &it: edges) {
        adj[it[0]].push_back(it[1]);
        indegree[it[1]]++;
    }

    // Make a queue to store the nodes with indegree 0
    queue<int> q;
    for(int i=0; i<v; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    // Make a vector to store the topological sort
    vector<int> res;
    // Traverse the queue
    while(!q.empty()) {
        // Pop the front element
        int node = q.front();
        q.pop();
        // Push the node to the vector
        res.push_back(node);

        // Traverse all the children of the current node
        for(int &child: adj[node]) {
            // Decrement the indegree of the child
            indegree[child]--;
            // If the indegree of the child is 0, push it to the queue
            if(indegree[child] == 0) {
                q.push(child);
            }
        }
    }

    // Return the topological sort
    return res;
}