#include <bits/stdc++.h> 
using namespace std;

// Function to calculate sum of all subsets
void solve(vector<int> &nums, int index, int &n, vector<int> &res, int sum) {
    // If we have reached the end of the array, we will add the sum to the result
    if(index == n) {
        res.push_back(sum);
        return;
    }

    // We will not pick the current element
    solve(nums, index + 1, n, res, sum);
    // We will pick the current element
    solve(nums, index + 1, n, res, sum + nums[index]);
}

vector<int> subsetSum(vector<int> &num)
{
    int n = num.size();
    vector<int> res;

    // We will call the recursive function to calculate sum of all subsets   
    solve(num, 0, n, res, 0);
    // We will sort the result in non-decreasing order
    sort(res.begin(), res.end());

    // Return the result
    return res;
}