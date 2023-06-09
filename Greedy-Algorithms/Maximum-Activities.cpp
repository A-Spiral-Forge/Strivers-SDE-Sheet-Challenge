#include<bits/stdc++.h>
using namespace std;

// We will use a structure to store the start and end time of the activities
class Activity {
    public:
    int start;
    int end;
};

// We will sort the activities in increasing order of their end time
bool comparator(Activity &a, Activity &b) {
    return a.end < b.end;
}


int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n = start.size();
    
    // We will store the activities in a vector of Activity structure
    vector<Activity> activities;
    for(int i=0; i<n; i++) {
        activities.push_back({start[i], finish[i]});
    }
    sort(activities.begin(), activities.end(), comparator);
    
    // We will store the end time of the last picked activity
    int currEndTime = -1, res = 0;
    // We will start picking the activities from the beginning of the sorted array
    for(int i=0; i<n; i++) {
        // If the current activity can be picked, we will pick it
        if(activities[i].start >= currEndTime) {
            res++;
            // We will update the end time of the last picked activity
            currEndTime = activities[i].end;
        }
    }

    // Return the maximum number of activities that can be picked
    return res;
}