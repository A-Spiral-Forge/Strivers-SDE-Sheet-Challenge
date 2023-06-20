#include <bits/stdc++.h> 
using namespace std;

// Node class for priority queue
class Node {
    public:
    int weight;
    int dest;
    int parent;

    bool operator()(Node &a, Node &b) {
        return a.weight > b.weight;
    }
};

// Prims Algorithm to find MST of a graph
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Adjacency list
    vector<vector<pair<int, int>>> adj(n + 1);
    for(const pair<pair<int, int>, int> &it: g) {
        adj[it.first.first].push_back({it.first.second, it.second});
        adj[it.first.second].push_back({it.first.first, it.second});
    }

    // Result vector
    vector<pair<pair<int, int>, int>> res;
    // Priority queue to store the edges in increasing order of weight
    priority_queue<Node, vector<Node>, Node> pq;
    // Visited array
    vector<bool> vis(n + 1, false);
    // Pushing the first node in the priority queue
    pq.push({weight: 0, dest: 1, parent: 0});
    // Looping till the priority queue is empty
    while(!pq.empty()) {
        // Getting the top element
        Node temp = pq.top();
        pq.pop();
        // If node is not visited and is valid edge, then push it in the result vector
        if(temp.parent > 0 && !vis[temp.dest]) {
            res.push_back({{temp.parent, temp.dest}, temp.weight});
        }
        if(vis[temp.dest]) {
            continue;
        }
        // Make the node visited
        vis[temp.dest] = true;
        // Push all the edges of the node in the priority queue
        for(const pair<int, int> &it: adj[temp.dest]) {
            // If the node is already visited, then continue
            if(vis[it.first]) {
                continue;
            }
            // Push the edge in the priority queue
            pq.push({weight: it.second, dest: it.first, parent: temp.dest});
        }
    }
    // Return the result vector
    return res;
}
