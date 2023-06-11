#include <bits/stdc++.h> 
using namespace std;

// Check if it is possible to divide the books in 'days' days 
// such that each day the student reads at most 'hours' hours
bool check(vector<int> &time, int chapters, int days, long long hours) {
	int count = 0;
	long long temp = 0;

    // Greedily assign chapters to each day
	for(int i=0; i<chapters; i++) {
		temp += time[i];
        // If the time exceeds the limit, assign the chapter to the next day
		if(temp >= hours) {
			count++;
			temp = temp > hours ? time[i] : 0;
		}
	}

    // If there are chapters left, assign them to the next day
	if(temp > 0) {
		count++; 
	}

    // If the number of days is less than or equal to the given days, return true
	return count <= days;
}

long long ayushGivesNinjatest(int n, int m, vector<int> &time) 
{	
	long long low = 0, high = 0;
    // Assing low as the maximum time taken by a chapter and high as the sum of all the chapters
	for(int i=0; i<m; i++) {
		low = max(low, time[i] * 1LL);
		high += time[i];
	}

    // Binary search for the minimum time
	while(low < high) {
		long long mid = low + (high - low) / 2;
		// If it is possible to divide the books in 'mid' hours, then search for a smaller time
        if(check(time, m, n, mid)) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}

    // Return the minimum time
	return low;
}