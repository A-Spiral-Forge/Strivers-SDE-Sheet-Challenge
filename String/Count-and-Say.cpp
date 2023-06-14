#include <bits/stdc++.h> 
using namespace std;

string writeAsYouSpeak(int n) 
{
    // Base case
	if(n == 1) {
		return "1";
	}

    // Recursive call to get the previous string
	string prev = writeAsYouSpeak(n - 1);

	int count = 1, m = prev.size();
	string res = "";
    // Count the number of times a character is repeated
    // and append it to the result string
	for(int i=1; i<m; i++) {
		if(prev[i] != prev[i - 1]) {
			res += to_string(count);
			res += prev[i - 1];
			count = 1;
		} else {
			count++;
		}
	}
    // Append the last character and its count
	res += to_string(count);
	res += prev[m - 1];

    // Return the result string
	return res;
}