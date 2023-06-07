#include <bits/stdc++.h> 
using namespace std;

// Function to count the number of reverse pairs in the range
long long merge(vector<int> &arr, int left, int mid, int right) {
    // Create a temporary array to store the sorted subarray
    vector<int> temp;
    // Pointers to iterate over the left and right subarray
    int ptr1 = left, ptr2 = mid;
    // Variable to store the number of reverse pairs
    long long res = 0;

    // Iterate over the left and right subarray
    while(ptr1 < mid && ptr2 < right) {
        // If the element in the left subarray is smaller than the element in the right subarray
        if(arr[ptr1] < arr[ptr2]) {
            // Add the element in the left subarray to the temporary array
            temp.push_back(arr[ptr1]);
            ptr1++;
        // If the element in the left subarray is greater than in the right subarray
        } else {
            // Add the element in the right subarray to the temporary array
            temp.push_back(arr[ptr2]);
            // Increment the number of reverse pairs by the number of elements
            // in the left subarray which are greater than twice the element in the right subarray
            // We will search in only remaining elements in the left subarray using binary search
            res += (mid - (upper_bound(arr.begin() + left, arr.begin() + mid, 2 * arr[ptr2]) - arr.begin()));
            ptr2++;
        }
    }

    // Add the remaining elements in the left subarray to the temporary array
    while(ptr1 < mid) {
        temp.push_back(arr[ptr1]);
        ptr1++;
    }

    // Add the remaining elements in the right subarray to the temporary array
    while(ptr2 < right) {
        temp.push_back(arr[ptr2]);
        ptr2++;
    }

    // Copy the sorted subarray to the original array
    for(int i=left; i<right; i++) {
        arr[i] = temp[i - left];
    }

    // Return the number of reverse pairs
    return res;
}

// Function to divide the array into two halves and merge them
long long divide(vector<int> &arr, int left, int right) {
    // If the size of the array is 1, return 0
    if(left + 1 >= right) {
        return 0;
    }

    // Find the middle index
    long long mid = left + (right - left) / 2;
    // Recursively divide the array into two halves
    long long leftInversions = divide(arr, left, mid);
    long long rightInversions = divide(arr, mid, right);
    // Merge the two sorted halves and return the number of reverse pairs
    long long currInversions = merge(arr, left, mid, right);

    return leftInversions + rightInversions + currInversions;
}

int reversePairs(vector<int> &arr, int n){
	return divide(arr, 0, n);
}