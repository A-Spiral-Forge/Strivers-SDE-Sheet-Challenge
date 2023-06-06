#include <bits/stdc++.h>
using namespace std;

void setZeros(vector<vector<int>> &matrix)
{
	int n = matrix.size();
	int m = matrix[0].size();

	// Store if the first column has any zero
	bool colZero = false;

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			// If the current element is zero
			if(matrix[i][j] == 0) {
				// If the current element is in the first column
				if(j == 0) {
					// Set colZero to true
					colZero = true;
				} else {
					// Set the first element of the current column to zero
					matrix[0][j] = 0;
				}
				// Set the first element of the current row to zero
				matrix[i][0] = 0;
			}
		}
	}

	// Iterate over the columns
	for(int j=1; j<m; j++) {
		// If the first element of the current column is zero
		if(matrix[0][j] == 0) {
			// Set the corresponding column to zero
			for(int i=0; i<n; i++) {
				matrix[i][j] = 0;
			}
		}
	}

	// Iterate over the rows
	for(int i=0; i<n; i++) {
		// If the first element of the current row is zero
		if(matrix[i][0] == 0) {
			// Set the corresponding row to zero
			for(int j=0; j<m; j++) {
				matrix[i][j] = 0;
			}
		}
	}

	// If the first column has any zero, set the first column to zero
	if(colZero) {
		for(int i=0; i<n; i++) {
			matrix[i][0] = 0;
		}
	}
}