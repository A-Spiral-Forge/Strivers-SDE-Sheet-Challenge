#include <bits/stdc++.h>
using namespace std;

// This is the same as the combination sum problem
// The only difference is that we have to remove the duplicates
void solve(vector<int> &arr, int index, int n, int target, vector<vector<int>> &res, vector<int> &temp) {
	// If we have reached the target, we will add the current combination to the result
    if(target == 0) {
		res.push_back(temp);
		return;
	}

    // If we have reached the end of the array or the target has become negative, we will return
	if(target < 0) {
		return;
	}

    // We will start from the current index and try to find the combinations
	for(int i=index; i<n; i++) {
        // If the current element is same as the previous element, we will skip it
        // This is done to avoid duplicates
		if(i > index && arr[i] == arr[i - 1]) {
			continue;
		}

        // We will add the current element to the combination
		temp.push_back(arr[i]);
        // We will recursively call the function for the remaining target
		solve(arr, i + 1, n, target - arr[i], res, temp);
        // We will remove the current element from the combination
		temp.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    // We will sort the array to avoid duplicates and return the result in sorted order
	sort(arr.begin(), arr.end());

	vector<vector<int>> res;
	vector<int> temp;

    // We will call the recursive function to find the combinations
	solve(arr, 0, n, target, res, temp);
    // We will return the result
	return res;
}
