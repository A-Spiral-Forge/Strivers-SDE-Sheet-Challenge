#include<bits/stdc++.h>
using namespace std;

int getMedian(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int low = matrix[0][0], high = matrix[0][m - 1];

    // Finding the minimum and maximum element in the matrix
    for(int i=0; i<n; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][m - 1]);
    }

    // Calculating the median position
    int median = (m * n + 1) / 2;

    while(low < high) {
        // Calculating the mid element
        int mid = low + (high - low) / 2;
        int count = 0;
        // Calculating the number of elements less than or equal to mid
        for(int i=0; i<n; i++) {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }

        // If the count is less than the median, then we need to increase the mid
        if(count < median) {
            low = mid + 1;
        // If the count is greater than the median, then we need to decrease the mid
        } else {
            high = mid;
        }
    }

    // Returning the median
    return low;
}