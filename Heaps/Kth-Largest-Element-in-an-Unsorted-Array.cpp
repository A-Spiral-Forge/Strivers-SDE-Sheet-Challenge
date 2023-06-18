#include <bits/stdc++.h> 
using namespace std;

int kthLargest(vector<int>& arr, int size, int K)
{
    // Min Heap
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i=0; i<size; i++) {
		pq.push(arr[i]);
		// Remove the smallest element if size of heap is greater than K
        if(i >= K) {
			pq.pop();
		}
	}

    // Return the top element of the heap
	return pq.top();
}