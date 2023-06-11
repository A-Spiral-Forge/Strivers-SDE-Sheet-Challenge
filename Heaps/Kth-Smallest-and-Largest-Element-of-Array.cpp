#include<bits/stdc++.h>
using namespace std;

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    // We make two heaps for getting the kth smallest and largest element
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;

	int counter = 0;
	for(int &it: arr) {
        // We push the elements in both the heaps
		maxHeap.push(it);
		minHeap.push(it);

		counter++;
        // We pop the elements from the heap if the counter is greater than k
		if(counter > k) {
			maxHeap.pop();
			minHeap.pop();
		}
	}

    // We return the top of both the heaps
	return {maxHeap.top(), minHeap.top()};
}