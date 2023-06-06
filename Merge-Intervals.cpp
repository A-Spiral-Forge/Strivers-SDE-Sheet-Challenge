#include <bits/stdc++.h> 
using namespace std;
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Sort the intervals based on start point
    sort(intervals.begin(), intervals.end());
    
    vector<vector<int>> res;
    vector<int> currInterval = intervals[0];

    for(const vector<int> &interval: intervals) {
        // If the current interval overlaps with the previous one
        if(interval[0] <= currInterval[1]) {
            // Merge the two intervals
            currInterval[1] = max(currInterval[1], interval[1]);
        } else {
            // Add the previous interval and update the current interval
            res.push_back(currInterval);
            currInterval = interval;
        }
    }
    // Add the last interval
    res.push_back(currInterval);

    return res;
}
