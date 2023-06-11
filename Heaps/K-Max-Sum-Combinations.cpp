#include <bits/stdc++.h> 
using namespace std;

// Since the size of arrays is very small, we can use the 
// brute force approach of finding all the possible sums.
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	priority_queue<int> pq;

    // Store all the possible sums in a max heap.
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            pq.push(a[i] + b[j]);
        }
    }

    // Pop the top k elements from the heap and return them as the answer.
    vector<int> res;
    for(int i=0; i<k; i++) {
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}