#include <bits/stdc++.h>
using namespace std;

// Kahn's Algorithm
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    // Make adjacency list and indegree array
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);
    for(const pair<int, int> &it: edges) {
        // Push directed edge in adjacency list
        adj[it.first].push_back(it.second);
        // Increase indegree of destination node
        indegree[it.second]++;
    }

    queue<int> q;
    // Count of nodes with indegree 0
    int count = 0;
    // Push all nodes with indegree 0 in queue
    for(int i=1; i<=n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    // BFS
    while(!q.empty()) {
        // Pop node with indegree 0
        int node = q.front();
        q.pop();
        // Increase count of nodes with indegree 0
        count++;
        for(auto &it: adj[node]) {
            // Decrease indegree of all adjacent nodes
            indegree[it]--;
            // If indegree of any adjacent node becomes 0, push it in queue
            if(indegree[it] == 0) {
                q.push(it);
            }
        }
    }

    // If count of nodes with indegree 0 is not equal 
    // to total nodes, then there is a cycle
    return count != n;
}