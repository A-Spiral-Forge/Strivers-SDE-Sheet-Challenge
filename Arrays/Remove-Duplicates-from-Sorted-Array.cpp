#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr, int n) {
    // Take two pointers i and j
    // i points to the first element of the array
    // j points to the second element of the array
	int i = 0, j = 1;

    // Iterate over the array till j reaches the end of the array
	while(j < n) {
        // If the elements at i and j are not equal, 
        // then we need to store the element at j at i + 1
        // and increment i
		if(arr[i] != arr[j]) {
			arr[i + 1] = arr[j];
			i++;
		}
        // In any case, we need to increment j
		j++;
	}

    // Return the length of the new array
	return i + 1;
}