#include <bits/stdc++.h> 
using namespace std;

// Function to color the node with given color and check if the coloring is possible
bool solve(vector<vector<int>> &adj, int node, int m, vector<int> &colored) {
    for(int &child: adj[node]) {
        // We will check if the current node is already colored
        if(colored[child] != -1) {
            // If the current node is already colored and the color of the 
            // current node and the child node is same, we will return false
            if(colored[node] == colored[child]) {
                return false;
            }
        } else {
            bool flag = false;
            // If the current node is not colored, we will color it with a color
            for(int i=0; i<m; i++) {
                // We will check if the current color is same as the color of the parent node
                if(i == colored[node]) {
                    continue;
                }

                // We will color the child node with the current color
                colored[child] = i;
                // We will recursively call the function for the child node
                if(solve(adj, child, m, colored)) {
                    // If the coloring is possible, we will break the loop
                    flag = true;
                    break;
                }

                // If the coloring is not possible, we will remove the color of the child node
                colored[child] = -1;
            }
            // If any color is not possible on child, we will return false
            if(!flag) {
                return false;
            }
        }
    }

    // If the coloring is possible, we will return true
    return true;
} 

string graphColoring(vector<vector<int>> &mat, int m) {
    int n = mat.size();
    vector<vector<int>> adj(n);

    // We will create the adjacency list for the graph
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(mat[i][j] == 1) {
                adj[i].push_back(j);
            }
        }
    }

    vector<int> colored(n, -1);
    for(int i=0; i<n; i++) {
        // We will check if the current node is already colored
        if(colored[i] == -1) {
            // We will color the first node with the first color
            colored[i] = 0;
            // We will recursively call the function for the current node
            if(!solve(adj, i, m, colored)) {
                // If the coloring is not possible, we will return "NO"
                return "NO";
            }
        }
    }

    // If the coloring is possible, we will return "YES"
    return "YES";
}