#include <bits/stdc++.h> 
using namespace std;

vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    int n = nums.size();
    // Double ended queue to store the indices of the elements
    deque<int> dq;
    vector<int> res;
    for(int i=0; i<n; i++) {
        // Remove the elements which canot be the maximum in the any window
        while(!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        // Add the current element to the queue
        dq.push_back(i);
        
        // Remove the elements which are not in the current window
        if(dq.front() == i - k) {
            dq.pop_front();
        }
        // Add the maximum element in the current window to the result
        // if the window size is equal to k
        // The maximum element is the front element of the queue
        if(i + 1 >= k) {
            res.push_back(nums[dq.front()]);
        }
    }

    // Return the result
    return res;
}