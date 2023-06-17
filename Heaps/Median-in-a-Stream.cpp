#include <bits/stdc++.h>
using namespace std;

// Data Stream Class to store the data and find the median
class DataStream {
private:
    // maxHeap stores the smaller half of the data
	priority_queue<int> maxHeap;
    // minHeap stores the larger half of the data
	priority_queue<int, vector<int>, greater<int>> minHeap;
	// Size of the heaps
    int maxHeapSize = 0, minHeapSize = 0;

public:
    // Function to balance the heaps
	void balance() {
        // If the size of the minHeap is greater than the maxHeap
        // This helps in tracking odd number of elements
        // We can find median by the top element of maxHeap, when elements are odd
		if (minHeapSize > maxHeapSize) {
            // Move the top element of minHeap to maxHeap
			maxHeap.push(minHeap.top());
            // Increase the size of maxHeap
			maxHeapSize++;
            // Remove the top element of minHeap
			minHeap.pop();
            // Decrease the size of minHeap
			minHeapSize--;
		}
	}

    // Function to push the data into the heaps
	void push(int num) {
        // Push the data into the maxHeap
		maxHeap.push(num);
        // Increase the size of maxHeap
		maxHeapSize++;
        // Push the top element of maxHeap to minHeap
		minHeap.push(maxHeap.top());
        // Increase the size of minHeap
		minHeapSize++;
        // Remove the top element of maxHeap
		maxHeap.pop();
        // Decrease the size of maxHeap
		maxHeapSize--;
        // Balance the heaps
		balance();
	}

	int getMedian() {
        // If the size of maxHeap is greater than minHeap, means the number of elements is odd
		if (maxHeapSize > minHeapSize) {
            // Return the top element of maxHeap
			return maxHeap.top();
		}
        // Return the average of the top elements of both the heaps
		return (maxHeap.top() + minHeap.top()) / 2;
	}
};

vector<int> findMedian(vector<int> &arr, int n) {
    // DataStream object
	DataStream DS;
    // Vector to store the answer
	vector<int> ans;

    // For each element in the array
	for(auto num: arr) {
        // Push the element into the DataStream
		DS.push(num);
        // Push the median of the DataStream into the answer
		ans.push_back(DS.getMedian());
	}

    // Return the answer
	return ans;
}