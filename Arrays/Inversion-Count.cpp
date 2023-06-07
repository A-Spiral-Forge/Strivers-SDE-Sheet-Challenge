#include <bits/stdc++.h> 
using namespace std;

// Merge step - Count the number of inversions while merging the two sorted arrays
long long merge(long long *arr, int left, int mid, int right) {
    // Create a temporary array to store the sorted array
    vector<long long> temp;
    // Pointers to iterate over the two halves
    int ptr1 = left, ptr2 = mid;
    // Variable to store the number of inversions
    long long res = 0;

    // Merge the two halves
    while(ptr1 < mid && ptr2 < right) {
        // If the element in the left half is smaller than the element in the right half
        if(arr[ptr1] < arr[ptr2]) {
            temp.push_back(arr[ptr1]);
            ptr1++;
        // If the element in the right half is smaller than the element in the left half
        } else {
            temp.push_back(arr[ptr2]);
            ptr2++;
            // Since the element in the right half is smaller than the element in the left half,
            // all the elements from the current pointer to the middle pointer in the left half
            // will be greater than the element in the right half. These are the inversions. 
            res += (mid - ptr1);
        }
    }

    // If there are any elements left in the left half, add them to the temporary array
    while(ptr1 < mid) {
        temp.push_back(arr[ptr1]);
        ptr1++;
    }

    // If there are any elements left in the right half, add them to the temporary array
    while(ptr2 < right) {
        temp.push_back(arr[ptr2]);
        ptr2++;
    }

    // Copy the sorted array to the original array
    for(int i=left; i<right; i++) {
        arr[i] = temp[i - left];
    }

    // Return the number of inversions
    return res;
}

// Divide and Conquer approach
long long divide(long long *arr, int left, int right) {
    // Base case, if the array has less than or equal to one element
    if(left + 1 >= right) {
        return 0;
    }

    // Find the middle index
    long long mid = left + (right - left) / 2;
    // Count inversions in the left half
    long long leftInversions = divide(arr, left, mid);
    // Count inversions in the right half
    long long rightInversions = divide(arr, mid, right);
    // Count inversions in the merge step
    long long currInversions = merge(arr, left, mid, right);

    // Return the total number of inversions
    return leftInversions + rightInversions + currInversions;
}

long long getInversions(long long *arr, int n){
    return divide(arr, 0, n);
}