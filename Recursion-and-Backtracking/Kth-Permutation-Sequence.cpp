#include <bits/stdc++.h>
using namespace std;

string kthPermutation(int n, int k) {
    // We will store the factorials of all the numbers from 0 to n
    vector<int> factorial(n + 1, 1);
    // We will store the numbers from 1 to n in a vector
    vector<char> nums;

    for(int i=1; i<=n; i++) {
        factorial[i] = factorial[i-1] * i;
        nums.push_back((char)(i + 48));
    }

    // We will store the result in a string
    string res = "";
    // We will decrement k by 1 because we are using 0-based indexing
    k--;

    // We will start from the n
    for(int i = n - 1; i >= 0; i--) {
        // We will find the index of the number which will be at the current position
        int numberIndex = (k / factorial[i]);
        // We will update k
        k %= factorial[i];

        // We will append the number at the current index to the result
        res += nums[numberIndex];
        // We will remove the number from the vector
        nums.erase(nums.begin() + numberIndex);
    }

    // Return the result
    return res;
}
