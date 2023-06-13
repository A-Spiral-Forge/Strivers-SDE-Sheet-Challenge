#include <bits/stdc++.h> 
using namespace std;

int romanToInt(string s) {
    int res = 0;
    int index = 0, n = s.size();

    /*
    * Roman numerals are usually written largest to smallest from left to right.
    * However, the numeral for four is not IIII. Instead, the number four is written as IV.
    * Because the one is before the five we subtract it making four. 
    * The same principle applies to the number nine, which is written as IX.
    * There are six instances where subtraction is used:
    * I can be placed before V (5) and X (10) to make 4 and 9.
    * X can be placed before L (50) and C (100) to make 40 and 90.
    * C can be placed before D (500) and M (1000) to make 400 and 900.
    * D, L and V can never be repeated.
    * I, X, C, and M can be repeated up to three times in succession.
    */
    
    while(index < n && s[index] == 'M') {
        res += 1000;
        index++;
    }
    if(index < n - 1 && s[index] == 'C' && s[index + 1] == 'M') {
        res += 900;
        index += 2;
    }
    if(index < n && s[index] == 'D') {
        res += 500;
        index++;
    }
    if(index < n - 1 && s[index] == 'C' && s[index + 1] == 'D') {
        res += 400;
        index += 2;
    }

    while(index < n && s[index] == 'C') {
        res += 100;
        index++;
    }
    if(index < n - 1 && s[index] == 'X' && s[index + 1] == 'C') {
        res += 90;
        index += 2;
    }
    if(index < n && s[index] == 'L') {
        res += 50;
        index++;
    }
    if(index < n - 1 && s[index] == 'X' && s[index + 1] == 'L') {
        res += 40;
        index += 2;
    }

    while(index < n && s[index] == 'X') {
        res += 10;
        index++;
    }
    if(index < n - 1 && s[index] == 'I' && s[index + 1] == 'X') {
        res += 9;
        index += 2;
    }
    if(index < n && s[index] == 'V') {
        res += 5;
        index++;
    }
    if(index < n - 1 && s[index] == 'I' && s[index + 1] == 'V') {
        res += 4;
        index += 2;
    }

    while(index < n && s[index] == 'I') {
        res += 1;
        index++;
    }
    return res;
}
