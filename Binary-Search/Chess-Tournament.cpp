#include <bits/stdc++.h> 
using namespace std;

// Check if it is possible place c players such that the minimum distance 
// between any two players is maxDis
bool check(vector<int> &positions, int n, int c, int maxDis) {
    int count = 1, currPos = positions[0];
    for(int i=1; i<n; i++) {
        // If the distance between the current position and the next position is
        // greater than maxDis, then we can place a player at the current position
        if(positions[i] - currPos >= maxDis) {
            count++;
            currPos = positions[i];
        }
    }

    return count >= c;
}

// Find the maximum distance between any two players such that we can place c players
int chessTournament(vector<int> &positions, int n, int c){
    // Sort the positions of the players
	sort(positions.begin(), positions.end());

    // The minimum distance between any two players will be the distance between
    // the two adjacent positions
    // The maximum distance between any two players will be the distance between
    // the first and the last position in the sorted order
    int low = positions[1] - positions[0], high = positions[n - 1] - positions[0];
    for(int i=1; i<n; i++) {
        low = min(low, positions[i] - positions[i - 1]);
    }

    int ans = -1;
    // Binary search for the maximum distance between any two players
    while(low <= high) {
        int mid = low + (high - low) / 2;

        // If it is possible to place c players such that the minimum distance
        // between any two players is mid
        if(check(positions, n, c, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // Return the maximum distance between any two players
    return ans;
}