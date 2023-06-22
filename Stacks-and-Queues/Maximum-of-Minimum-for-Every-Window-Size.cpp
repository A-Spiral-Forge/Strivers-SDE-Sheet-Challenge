#include <bits/stdc++.h> 
using namespace std;

vector<int> maxMinWindow(vector<int> a, int n) {
    stack<int> st1, st2;
    // Store indexes of next smaller and previous smaller for all array elements
    vector<int> leftSmaller(n + 1, -1), rightSmaller(n + 1, n);

    // Find indexes of previous smaller values of a[i]
    for(int i=0; i<n; i++) {
        while(!st1.empty() && a[st1.top()] >= a[i]) {
            st1.pop();
        }
        if(!st1.empty()) {
            leftSmaller[i] = st1.top();
        }
        st1.push(i);
    }
    // Find indexes of next smaller values of a[i]
    for(int i=n-1; i>=0; i--) {
        while(!st2.empty() && a[st2.top()] >= a[i]) {
            st2.pop();
        }
        if(!st2.empty()) {
            rightSmaller[i] = st2.top();
        }
        st2.push(i);
    }

    // Create and initialize answer array
    vector<int> res(n + 1, INT_MIN);
    // Fill answer array by comparing minimums of all
    for(int i=0; i<n; i++) {
        int len = rightSmaller[i] - leftSmaller[i] - 1;
        // If arr[i] is more than max of previous minimums, then update it
        res[len] = max(res[len], a[i]);
    }
    // Some entries in res[] may not be filled yet. 
    // Fill them by taking values from right side of res[]
    for(int i=n-1; i>=0; i--) {
        res[i] = max(res[i], res[i + 1]);
    }
    // Remove 0th entry as we don't need it
    res.erase(res.begin());
    // Return result
    return res;
}