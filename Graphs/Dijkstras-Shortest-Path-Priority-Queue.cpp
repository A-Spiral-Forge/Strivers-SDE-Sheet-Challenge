#include <bits/stdc++.h> 
using namespace std;

// Dijkstra's Shortest Path Algorithm using Adjacency List and Priority Queue
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Make Adjacency List
    vector<vector<pair<int, int>>> adj(vertices);
    for(const vector<int> &it: vec) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    // Priority Queue to store {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // Result vector to store shortest distance from source to all nodes
    vector<int> res(vertices, INT_MAX);
    // Push source node to priority queue
    pq.push({0, source});
    // Distance of source node from itself is 0
    res[source] = 0;

    while(!pq.empty()) {
        // Get the node with minimum distance from source
        pair<int, int> node = pq.top();
        // Remove the node from priority queue
        pq.pop();
        // Traverse all the adjacent nodes of the current node
        for(const pair<int, int> &it: adj[node.first]) {
            // If distance of adjacent node from source is greater 
            // than distance of current node from source + edge weight
            if(res[it.first] > node.second + it.second) {
                // Update the distance of adjacent node from source
                res[it.first] = node.second + it.second;
                // Push the adjacent node to priority queue
                pq.push({it.first, res[it.first]});
            }
        }
    }
    // Return the result vector
    return res;
}
