#include <bits/stdc++.h> 
using namespace std;

vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Map to store the frequency of each element of the window
    map<int, int> m;
    // Count of distinct elements in the window
    int countDist = 0, n = arr.size();
    vector<int> res;

    for(int i=0; i<n; i++) {
        // Insert the current element into the map
        m[arr[i]]++;
        // If the frequency of the current element is 1, 
        // then increment the count of distinct elements
        if(m[arr[i]] == 1) {
            countDist++;
        }
        // If the size of the window is k, 
        // then remove the first element of the window
        if(i >= k) {
            // If the frequency of the first element of the window is 1,
            if(m[arr[i - k]] == 1) {
                // then decrement the count of distinct elements
                countDist--;
                // and remove the element from the map
                m.erase(arr[i - k]);
            } else {
                // else decrement the frequency of the first element of the window
                m[arr[i - k]]--;
            }
        }
        // If the size of the window is k,
        if(i >= k - 1) {
            // then store the count of distinct elements in the result
            res.push_back(countDist);
        }
    }
    // Return the result
    return res;
}