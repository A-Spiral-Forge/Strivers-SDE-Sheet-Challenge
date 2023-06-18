#include <bits/stdc++.h> 
using namespace std;

class Kthlargest {
// Min Heap to store k largest elements
priority_queue<int, vector<int>, greater<int>> pq;
// k is the size of the heap
int k;

public:
    // Constructor
    Kthlargest(int k, vector<int> &arr) {
        this->k = k;
        int n = arr.size();
        // Insert intial array elements into the heap
        for(int i=0; i<n; i++) {
            pq.push(arr[i]);
            // If size of heap is greater than k, pop the smallest element
            if(i >= k) {
                pq.pop();
            }
        }
    }

    // Add a new element to the heap
    void add(int num) {
        pq.push(num);
        // If size of heap is greater than k, pop the smallest element
        pq.pop();
    }

    // Return the kth largest element
    int getKthLargest() {
        return pq.top();
    }
};