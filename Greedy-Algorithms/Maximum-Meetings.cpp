#include <bits/stdc++.h> 
using namespace std;

// Structure to store the start time, end time and index of the meeting
class Meeting {
    public:
    int start;
    int end;
    int index;
};

// Comparator function to sort the meetings in ascending order of their end time
bool comparator(Meeting a, Meeting b) {
    // If the end time of the meetings is equal, then sort them in ascending order of their index
    if(a.end == b.end) {
        return a.index < b.index;
    }

    return a.end < b.end;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    vector<Meeting> meetings;
    int n = start.size();
    
    // Store the start time, end time and index of the meeting in a vector
    for(int i=0; i<n; i++) {
        meetings.push_back({start[i], end[i], i + 1});
    }
    // Sort the meetings in ascending order of their end time
    sort(meetings.begin(), meetings.end(), comparator);

    // Store the end time of the current meeting
    int currEndTime = -1;
    vector<int> res;

    // Traverse the meetings
    for(int i=0; i<n; i++) {
        // If the start time of the current meeting is greater than the end time of the previous meeting, then we can attend the current meeting
        if(meetings[i].start > currEndTime) {
            res.push_back(meetings[i].index);
            // Update the end time of the current meeting
            currEndTime = meetings[i].end;
        }
    }

    // Return the indices of the meetings we can attend
    return res;
}