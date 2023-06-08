#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
    // Sort the array
	sort(arr.begin(), arr.end());
    // Store the triplets in a vector
	vector<vector<int>> res;

    // Iterate over the array
	int prev = INT_MIN;
	for(int i=0; i<n; i++) {
        // If the current element is equal to the previous element, then we don't need to consider it
		if(arr[i] == prev) {
			continue;
		}

        // Find the pair of elements whose sum is equal to K - arr[i]
		int left = i + 1, right = n - 1;
		while(left < right) {
            // Calculate the sum of the elements
			int sum = arr[i] + arr[left] + arr[right];

            // If the sum is equal to K, then we need to store the triplet
			if(sum == K) {
                // Store the triplet
				res.push_back({arr[i], arr[left], arr[right]});

                // Store the previous elements
				int prevLeft = arr[left], prevRight = arr[right];
                // Move the left pointer to the next distinct element
				while(left < right && arr[left] == prevLeft) { 
					left++;
				}
                // Move the right pointer to the next distinct element
				while(left < right && arr[right] == prevRight) { 
					right--;
				}
			} else if(sum > K) {
                // If the sum is greater than K, then we need to decrease the sum
				right--;
			} else {
                // If the sum is smaller than K, then we need to increase the sum
				left++;
			}
		}
            
        // Store the previous element 
		prev = arr[i];
	}

    // Return the triplets
	return res;
}