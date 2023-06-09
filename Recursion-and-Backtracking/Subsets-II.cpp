#include <bits/stdc++.h> 
using namespace std;

// Function to calculate all the unique subsets
void solve(vector<int> &arr, int index, int n, vector<vector<int>> &res, vector<int>&temp) {
    // Add the current subset to the result
    res.push_back(temp);

    for(int i=index; i<n; i++) {
        // If the current element is same as the previous element, we will skip it
        if(i > index && arr[i] == arr[i - 1]) {
            continue;
        }

        // We will add the current element to the subset
        temp.push_back(arr[i]);
        // We will call the recursive function to calculate the subsets
        solve(arr, i + 1, n, res, temp);
        // We will backtrack and remove the current element from the subset
        temp.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // We will sort the array to handle the duplicates
    sort(arr.begin(), arr.end());
    
    vector<vector<int>> res;
    // We will use a temporary vector to store the current subset
    vector<int> temp;

    // We will call the recursive function to calculate the subsets
    solve(arr, 0, n, res, temp);

    // Return the result
    return res;
}