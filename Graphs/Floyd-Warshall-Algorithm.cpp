#include <bits/stdc++.h>
using namespace std;

// Floyd Warshall Algorithm
int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Make a 2D matrix of size n+1 x n+1
    // dist[i][j] = distance from i to j
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, 1e9));
    // Initialize the diagonal elements to 0
    for(int i=0; i<=n; i++) {
        dist[i][i] = 0;
    }
    // Initialize the edges
    for(const vector<int> &it: edges) {
        dist[it[0]][it[1]] = it[2];
    }
    // Floyd Warshall Algorithm
    // via = intermediate node
    for(int via = 1; via <= n; via++) {
        // from = source node
        for(int from = 1; from <= n; from++) {
            // to = destination node
            for(int to = 1; to <= n; to++) {
                // If the distance from source to intermediate node or
                // intermediate node to destination node is infinite,
                // then we will not update the distance from source to destination
                if(dist[from][via] == 1e9 || dist[via][to] == 1e9) {
                    continue;
                }
                // Update the distance from source to destination
                // if the distance from source to intermediate node +
                // intermediate node to destination node is less than
                // the distance from source to destination
                dist[from][to] = min(dist[from][to], 
                dist[from][via] + dist[via][to]);
            }
        }
    }

    // Check for negative weight cycle
    for(int i=1; i<=n; i++) {
        if(dist[i][i] < 0) {
            cout << "Negative weight cycle found\n";
            return -1;
        }
    }

    // Return the distance from source to destination
    return dist[src][dest];
}