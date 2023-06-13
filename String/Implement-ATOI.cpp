#include <bits/stdc++.h> 
using namespace std;

int atoi(string str) {
    int res = 0;
    int sign = 1, n = str.size();

    for(int i=0; i<n; i++) {
        // If there is a digit, append it to result
        if(str[i] >= '0' && str[i] <= '9') {
            res = (res * 10) + (str[i] - '0');
        }
    }

    // If there is a negative sign at start,
    // change the sign of number
    if(str[0] == '-') {
        sign = -1;
    }

    // Return the result
    return sign * res;
}