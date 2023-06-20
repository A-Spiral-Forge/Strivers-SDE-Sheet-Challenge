#include <bits/stdc++.h> 
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Make Adjacency List
    vector<vector<pair<int, int>>> adj(vertices);
    for(const vector<int> &it: vec) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    // Set to store {distance, node}
    set<pair<int, int>> st;
    // Result vector to store shortest distance from source to all nodes
    vector<int> res(vertices, INT_MAX);
    // Push source node to set
    st.insert({0, source});
    // Distance of source node from itself is 0
    res[source] = 0;
    // While set is not empty
    while(!st.empty()) {
        // Get the node with minimum distance from source (first element of set)
        pair<int, int> node = (*st.begin());
        // Remove the node from set
        st.erase(st.begin());
        // Traverse all the adjacent nodes of the current node
        for(const pair<int, int> &it: adj[node.first]) {
            // If distance of adjacent node from source is greater
            // than distance of current node from source + edge weight
            if(res[it.first] > node.second + it.second) {
                // Remove the adjacent node from set
                res[it.first] = node.second + it.second;
                // Push the adjacent node to set
                st.insert({it.first, res[it.first]});
            }
        }
    }
    // Return the result vector
    return res;
}
