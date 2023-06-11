#include <bits/stdc++.h> 
using namespace std;

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Store the frequency of each element in a map
    map<int, int> m;
    for(int &it: arr) {
        m[it]++;
    }

    // Store the elements in a priority queue with their frequency as the key
    priority_queue<pair<int, int>> pq;
    for(const pair<int, int> &it: m) {
        pq.push({it.second, it.first});
    }

    vector<int> res;
    int count = 0;
    // Pop the top k elements from the priority queue
    // and store them in the result vector
    while(!pq.empty()) {
        pair<int, int> temp = pq.top();
        pq.pop();

        res.push_back(temp.second);
        count++;
        if(count == k) {
            break;
        }
    }

    // Sort the result vector and return it
    sort(res.begin(), res.end());
    return res;
}