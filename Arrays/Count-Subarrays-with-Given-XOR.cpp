#include <bits/stdc++.h>
using namespace std;

int subarraysXor(vector<int> &arr, int x)
{
    // Store the prefix XOR and its count
    map<int, int> prefixXORWithIndex;
    // Initialize the prefix XOR with 0 with count 1
    prefixXORWithIndex[0] = 1;
    int n = arr.size();

    int XOR = 0, res = 0;
    // Iterate over the array
    for(int i=0; i<n; i++) {
        // Calculate the prefix XOR
        XOR ^= arr[i];
        // Add the count of prefix (XOR ^ x) to the result
        res += prefixXORWithIndex[XOR ^ x];
        // Increment the count of prefix XOR
        prefixXORWithIndex[XOR]++;
    }

    // Return the result
    return res;
}