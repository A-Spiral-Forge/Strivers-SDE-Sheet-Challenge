#include <bits/stdc++.h> 
using namespace std;

int compareVersions(string a, string b) 
{
    // Add '.' at the end of the string
    a += '.'; b += '.';
    // Store the version numbers in a vector in integer form
    vector<long long> versionA, versionB;
    
    int lena = 0, lenb = 0;
    long long num = 0;
    // for version A
    for(char &ch: a) {
        // if '.' is encountered, push the number in the vector
        if(ch == '.') {
            versionA.push_back(num);
            lena++;
            num = 0;
        } else {
            num = (num * 10) + (ch - '0');
        }
    }

    // for version B
    for(char &ch: b) {
        // if '.' is encountered, push the number in the vector
        if(ch == '.') {
            versionB.push_back(num);
            lenb++;
            num = 0;
        } else {
            num = (num * 10) + (ch - '0');
        }
    }
    
    // if the length of the version numbers are not equal, add 0 at the end of the smaller one
    while(lena < lenb) {
        versionA.push_back(0);
        lena++;
    }
    while(lenb < lena) {
        versionB.push_back(0);
        lenb++;
    }

    // Compare the version numbers
    for(int i=0; i<lena; i++) {
        // if the version numbers are not equal, return 1 if versionA is greater, else return -1
        if(versionA[i] != versionB[i]) {
            return versionA[i] > versionB[i] ? 1 : -1;
        }
    }

    // if the version numbers are equal, return 0
    return 0;
}