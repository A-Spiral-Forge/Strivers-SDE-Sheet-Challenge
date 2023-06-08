#include <bits/stdc++.h>
using namespace std;

int calculateMinPatforms(int at[], int dt[], int n) {
    // Sort the arrival and departure times
    sort(at, at + n);
    sort(dt, dt + n);

    // Calculate the minimum number of platforms required
    int res = 0, currPlatforms = 0;
    int departureIndex = 0;

    // Traverse the arrival times
    for(int i=0; i<n; i++) {
        // If the departure time of the already occupied platform is less 
        // than the arrival time of the current train,
        // then we can use the same platform for the next train
        while(dt[departureIndex] < at[i]) {
            departureIndex++;
            // Free the platform
            currPlatforms--;
        }

        // Occupy the platform
        currPlatforms++;
        // Update the minimum number of platforms required
        res = max(currPlatforms, res);
    }

    // Return the minimum number of platforms required
    return res;
}