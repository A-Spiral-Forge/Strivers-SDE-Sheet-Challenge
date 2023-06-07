#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElementII(vector<int> &arr)
{
    int n = arr.size();
    // Required count for majority element is n/3 + 1
    int requiredCount = (n / 3) + 1;

    vector<int> res;
    // Store the count of each element in the array
    map<int, int> count;
    // Iterate over the array and increment the count of each element
    for(auto &it: arr) {
        count[it]++;
        // If the count of any element becomes equal to required count
        if(count[it] == requiredCount) {
            // Add it to the result
            res.push_back(it);
        }
    }
    
    // Return the result
    return res;
}