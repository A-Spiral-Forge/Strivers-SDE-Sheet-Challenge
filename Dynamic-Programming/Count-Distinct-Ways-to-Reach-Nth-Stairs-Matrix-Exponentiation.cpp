#include <bits/stdc++.h> 
using namespace std;
int mod = 1e9 + 7;

vector<vector<int>> multiply(vector<vector<int>> &a, vector<vector<int>> &b) {
    vector<vector<int>> res(2, vector<int>(2, 0));
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            for(int x = 0; x < 2; x++) {
                res[i][j] = (res[i][j] + (a[i][x] * 1LL * b[x][j]) % mod) % mod;
            }
        }
    }
    return res;
}

vector<vector<int>> powern(vector<vector<int>> &mat, int n) {
    vector<vector<int>> res = {
        {1, 0},
        {0, 1}
    };
    while(n > 0) {
        if(n % 2 == 1) {
            res = multiply(res, mat);
        }
        mat = multiply(mat, mat);
        n >>= 1;
    }
    return res;
}

int countDistinctWays(int nStairs) {
    vector<vector<int>> fib = {
        {0, 1},
        {1, 1}
    };

    vector<vector<int>> finalMatrix = powern(fib, nStairs + 2);
    return finalMatrix[0][0];
}