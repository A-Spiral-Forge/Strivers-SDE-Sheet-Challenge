#include <bits/stdc++.h>
using namespace std;

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    // Pointers for arr1 and arr2
	int ptr1 = m - 1, ptr2 = n - 1;
    // Index for arr1
    int index = m + n - 1;

    // Traverse both arrays
    while(ptr1 >= 0 && ptr2 >= 0) {
        //  If current element of first array is smaller than current element of second array
        //  then store first array element and decrement first array index
        if(arr1[ptr1] > arr2[ptr2]) {
            swap(arr1[ptr1], arr1[index]);
            ptr1--;
            index--;
        // Else do same with second array
        } else {
            swap(arr2[ptr2], arr1[index]);
            ptr2--;
            index--;
        }
    }

    // Store remaining elements of second array in first array
    while(ptr2 >= 0) {
        swap(arr2[ptr2], arr1[index]);
        ptr2--;
        index--;
    }

    return arr1;
}