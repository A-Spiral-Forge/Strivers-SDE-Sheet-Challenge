#include <bits/stdc++.h>
using namespace std;

// Check if base^exp == ans
// If base^exp > ans, return 2
// If base^exp < ans, return 0
int checkPower(int base, int exp, long ans) {
    long power = 1;
    for(int i=1; i<=exp; i++) {
        power *= base;
        if(power > ans) {
            return 2;
        }
    }

    return power == ans ? 1 : 0;
}

int NthRoot(int n, int m) {
    int low = 1, high = m;

    // Apply binary search from 1 to m
    while(low <= high) {
        // Find mid
        int mid = low + (high - low) / 2;
        // Check if mid is the answer
        int check = checkPower(mid, n, m);

        // If mid is the answer, return mid
        if(check == 1) {
            return mid;
        }

        // If mid is greater than answer, search in left half
        // Else search in right half
        if(check == 2) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    // If no answer found, return -1
    return -1;
}