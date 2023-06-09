#include <bits/stdc++.h> 
using namespace std;

bool comparator(vector<int> &a, vector<int> &b) {
    // Sort jobs according to their deadlines
    return a[0] < b[0];
}

int jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), comparator);
    // Store profit of top jobs which can be done within deadline
    priority_queue<int, vector<int>, greater<int>> pq;

    for(const vector<int> &it: jobs) {
        // Push profit of job in priority queue
        pq.push(it[1]);
        // If size of priority queue is greater than deadline of job
        // then pop the job with least profit
        if(pq.size() > it[0]) {
            pq.pop();
        }
    }

    int res = 0;
    // Calculate total profit
    while(!pq.empty()) {
        res += pq.top();
        pq.pop();
    }

    // Return total profit
    return res;
}
