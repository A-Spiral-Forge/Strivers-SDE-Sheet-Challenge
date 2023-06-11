#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& arr)
{
	int n = arr.size();
	int low = 0, high = n - 1;

    // If array has only one element. then while loop will not execute
	while(low < high) {
        // Calculate mid
		int mid = low + (high - low) / 2;

        // Checking for corner cases
        // If mid is 0 and mid + 1 element is not equal to mid element then mid element is the answer
		if(mid == 0 && arr[mid] != arr[mid + 1]) {
			return arr[mid];
		}
        // If mid is last index and mid - 1 element is not equal to mid element then mid element is the answer
		if(mid == n - 1 && arr[mid] != arr[mid - 1]) {
			return arr[mid];
		}
        // If mid element is not equal to mid - 1 and mid + 1 element then mid element is the answer
		if(arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) {
			return arr[mid];
		}

        // If mid is even and mid + 1 element is equal to mid element then answer lies in right half
		if(mid % 2 == 0) {
			if(arr[mid] == arr[mid + 1]) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
        // If mid is odd and mid + 1 element is equal to mid element then answer lies in left half
		} else {
			if(arr[mid] == arr[mid + 1]) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
	}

    // Return the element at low index
	return arr[low];
}