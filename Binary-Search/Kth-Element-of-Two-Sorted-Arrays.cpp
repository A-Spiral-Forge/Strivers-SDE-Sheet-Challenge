#include <bits/stdc++.h>
using namespace std;

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    // If size of row2 is greater than row1, swap them
    if(m < n) {
        return ninjaAndLadoos(row2, row1, n, m, k);
    }

    // Set low as maximum of 0 and k - size of smaller row
    // Set high as minimum of k and size of greater row
    int low = max(0, k - n), high = min(k, m);
    // Binary search
    while(low <= high) {
        // Cut1 is number of elements from row1 to be taken
        int cut1 = (low + high) / 2;
        // Cut2 is number of elements from row2 to be taken
        int cut2 = k - cut1;
        
        // Take two elements from row1 and row2 where cut1 and cut2
        int left1 = (cut1 == 0) ? INT_MIN : row1[cut1 - 1];
        int right1 = (cut1 == m) ? INT_MAX : row1[cut1];
        int left2 = (cut2 == 0) ? INT_MIN : row2[cut2 - 1];
        int right2 = (cut2 == n) ? INT_MAX : row2[cut2];
    
        // If left1 <= right2 and left2 <= right1, we have found the kth element
        if(left1 <= right2 && left2 <= right1) {
            return max(left1, left2);
        }

        // If left1 > right2, we need to decrease cut1
        if(left1 > right2) {
            high = cut1 - 1;
        // Else, we need to increase cut1
        } else {
            low = cut1 + 1;
        }
    }

    // If we reach here, it means that k is greater than combined size of row1 and row2
    return -1;
}