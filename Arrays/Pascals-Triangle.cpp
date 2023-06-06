#include <bits/stdc++.h>
using namespace std;

vector<vector<long long int>> printPascal(int n) 
{
    vector<vector<long long>> res;

    // First row of Pascal's Triangle is {1}
    res.push_back({1});
    // If n is 1, return the first row
    if(n == 1) {
      return res;
    }

    // Second row of Pascal's Triangle is {1, 1}
    res.push_back({1, 1});
    // If n is 2, return the second row
    if(n == 2) {
      return res;
    }

    // Iterate over the rows
    for(int i=2; i<n; i++) {
        vector<long long> temp;
        // First element of the current row is 1
        temp.push_back(1);
        // Iterate over the elements of the previous row
        for(int j=1; j<i; j++) {
            // Push the sum of the two consecutive elements of the previous row
            temp.push_back(res[i-1][j] + res[i-1][j-1]);
        }
        // Last element of the current row is 1
        temp.push_back(1);
        // Push the current row to the result
        res.push_back(temp);
    }

    return res;
}
