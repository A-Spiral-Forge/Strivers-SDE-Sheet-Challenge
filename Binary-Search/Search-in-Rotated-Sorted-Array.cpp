#include <bits/stdc++.h>
using namespace std;

int search(int* arr, int n, int key) {
    int low = 0, high = n - 1;
    // Find the pivot
    while(low < high) {
        int mid = low + (high - low) / 2;
        // If mid is greater than high, then pivot is in the right half
        if(arr[mid] <= arr[low] && arr[mid] < arr[high]) {
            high = mid;
        // If mid is less than low, then pivot is in the left half
        } else {
            low = mid + 1;
        }
    }

    // low is the pivot
    int pivot = low;

    // If key is less than or equal to the last element, then it is in the right half
    if(arr[n - 1] >= key) {
        low = pivot; high = n - 1;
        // Binary search in the right half
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] == key) {
                return mid;
            }
            if(arr[mid] > key) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }

    // If key is greater than the last element, then it is in the left half
    low = 0; high = pivot - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == key) {
            return mid;
        }
        if(arr[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    // If key is not found
    return -1;
}