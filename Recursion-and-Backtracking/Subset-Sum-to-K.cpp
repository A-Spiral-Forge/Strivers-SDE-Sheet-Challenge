#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int index, int n, vector<vector<int>> &res, vector<int> &temp, int sum, int k) {
    if(index == n) {
        // If the sum of the current subset is equal to k, we will add it to the result
        if(sum == k) {
            res.push_back(temp);
        }
        return;
    }

    // We will not include the current element in the subset
    solve(arr, index + 1, n, res, temp, sum, k);

    // We will include the current element in the subset
    temp.push_back(arr[index]);
    solve(arr, index + 1, n, res, temp, sum + arr[index], k);
    temp.pop_back();
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> res;
    vector<int> temp;

    // We will call the recursive function to find all the subsets that sum to k
    solve(arr, 0, n, res, temp, 0, k);
    // Return the result
    return res;
}