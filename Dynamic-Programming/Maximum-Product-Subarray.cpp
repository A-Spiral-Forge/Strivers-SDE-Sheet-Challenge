#include <bits/stdc++.h> 
using namespace std;

int maximumProduct(vector<int> &arr, int n)
{
    // Make two variables to store the maximum and minimum product
    // till the ith index, assign the first element to both of them
	int res = arr[0], maxProd = arr[0], minProd = arr[0];
    // Iterate from the second element to the last element
	for(int i = 1; i < n; i++) {
        // If the current element is negative, swap the maximum and minimum
        // product because the maximum product till the previous element
        // will become the minimum product and the minimum product
        // till the previous element will become the maximum product
		if(arr[i] < 0) {
			swap(maxProd, minProd);
		}
        // Update the maximum and minimum product till the ith index
		maxProd = max(arr[i], maxProd * arr[i]);
		minProd = min(arr[i], minProd * arr[i]);
        // Update the result
		res = max(res, maxProd);
	}
    // Return the result
	return res;
}
