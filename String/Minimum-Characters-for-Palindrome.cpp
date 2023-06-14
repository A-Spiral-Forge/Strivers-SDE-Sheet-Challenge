#include <bits/stdc++.h>
using namespace std;

int minCharsforPalindrome(string str) {
	string rev = str;
    // Reverse the string and append it to the original string
	reverse(rev.begin(), rev.end());
	string concat = str + "$" + rev;
	int n = concat.size();

    // Calculate the LPS array for the concatenated string
	vector<int> lps(n, 0);
	int i = 1, len = 0;
	while(i < n) {
		if(concat[i] == concat[len]) {
			len++;
			lps[i] = len;
			i++;
		} else {
			if(len != 0) {
				len = lps[len - 1];
			} else {
				i++;
			}
		}
	}

    // Return the length of the original string minus the 
    // length of the longest prefix which is also a suffix
    // of the concatenated string
	return str.size() - lps[n - 1];
}
