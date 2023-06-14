#include <bits/stdc++.h>
using namespace std;

// Generate Z-Array
void generateZArray(string &concat, int len, vector<int> &zarr) {
	// L and R are the left and right indices of the Z-box resp.
	int L = 0, R = 0;

	// Iterate over the string
	for(int i = 1; i < len; i++) {
		// If i > R nothing matches so we will calculate
		// Z-Value using naive way.
		if(i > R) {
			L = R = i;

			// Starting from 0 index we will match the string.
			while(R < len && concat[R - L] == concat[R]) {
				// Increment the right index.
				R++;
			}
			// Now we will get the Z-Value, which is R - L.
			zarr[i] = R - L;
			// Decrement the right index.
			R--;
		// If i <= R, then there is some prefix substring matches.
		} else {
			// k = i - L, so k corresponds to number which matches in [L, R] interval.
			int k = i - L;

			// If zarr[k] is less than remaining interval then Z-Value will be equal to Z-Value of k.
			if(zarr[k] < R - i + 1) {
				// Z-Value will be equal to Z-Value of k.
				zarr[i] = zarr[k];
			} else {
				// If zarr[k] is greater than remaining interval.
				// Then we have to start matching from R+1, which is same as saying L = i.
				L = i;
				// Now we will start matching from R+1.
				while(R < len && concat[R - L] == concat[R]) {
					// Increment the right index.
					R++;
				}
				// Now we will get the Z-Value, which is R - L.
				zarr[i] = R - L;
				// Decrement the right index.
				R--;
			}
		}
	}
}

int zAlgorithm(string s, string p, int n, int m)
{
	// Concatenate the pattern and string.
	string concat = p + "$" + s;
	// Length of the concatenated string.
	int len = n + m + 1;
	// Z-Array.
	vector<int> zarr(len, 0);

	// Generate the Z-Array.
	generateZArray(concat, len, zarr);

	int count = 0;
	// Count the number of times the pattern occurs in the string.
	for(int i=0; i<len; i++) {
		// If Z-Value is equal to length of the pattern.
		if(zarr[i] == m) {
			// Increment the count.
			count++;
		}
	}
	// Return the count.
	return count;
}