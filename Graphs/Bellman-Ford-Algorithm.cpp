#include <bits/stdc++.h> 
using namespace std;

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Intialize distance array
    vector<int> dist(n + 1, 1e9);
    // Distance of source node from itself is 0
    dist[src] = 0;

    // Relax all edges n - 1 times
    for(int i=1; i<n; i++) {
        // Relax all edges
        for(const vector<int> &it: edges) {
            // If distance of node from source is not infinity and 
            // distance of node + weight of edge is less than 
            // distance of destination node
            if(dist[it[0]] != 1e9 && dist[it[0]] + it[2] < dist[it[1]]) {
                // Update distance of destination node
                dist[it[1]] = dist[it[0]] + it[2];
            }
        }
    }

    // Check for negative weight cycle
    for(const vector<int> &it: edges) {
        // If distance of node from source is not infinity and 
        // distance of node + weight of edge is less than 
        // distance of destination node
        if(dist[it[0]] != 1e9 && dist[it[0]] + it[2] < dist[it[1]]) {
            // Negative weight cycle exists
            return 1e9;
        }
    }

    // If distance of destination node is infinity
    return dist[dest];
}