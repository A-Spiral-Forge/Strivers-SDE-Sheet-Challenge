#include <bits/stdc++.h>
using namespace std;

double median(vector<int>& a, vector<int>& b) {
	int n = a.size();
	int m = b.size();

    // If the first array is greater than the second array, then we swap them
	if(m < n) {
		return median(b, a);
	}

    // We are doing binary search on the smaller array
	int low = 0, high = n;
	while(low <= high) {
        // We are finding the mid of the smaller array
		int mid1 = low + (high - low) / 2;
        // We are finding the mid of the larger array
		int mid2 = (m + n + 1) / 2 - mid1;

        // We are finding the left and right elements of the smaller array
		int left1 = (mid1 == 0) ? INT_MIN : a[mid1 - 1];
		int right1 = (mid1 == n) ? INT_MAX : a[mid1];
        // We are finding the left and right elements of the larger array
		int left2 = (mid2 == 0) ? INT_MIN : b[mid2 - 1];
		int right2 = (mid2 == m) ? INT_MAX : b[mid2];

        // If the left elements of the smaller array is less than or equal to 
        // the right elements of the larger array and the left elements of the 
        // larger array is less than or equal to the right elements of the 
        // smaller array, then we have found the median
		if(left1 <= right2 && left2 <= right1) {
			if((n + m) % 2 == 0) {
				return (double)(max(left1, left2) + min(right1, right2)) / 2;
			}
			return (double)(max(left1, left2));
		}
        // If the left elements of the smaller array is greater than the right
        // elements of the larger array, then we move to the left of the smaller
        // array
		if(left1 > right2) {
			high = mid1 - 1;
        // Else we move to the right of the smaller array
		} else {
			low = mid1 + 1;
		}
	}

    // If we reach here, then the arrays are not sorted
	return -1;
}