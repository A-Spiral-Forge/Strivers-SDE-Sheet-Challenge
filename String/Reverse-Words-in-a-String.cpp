#include <bits/stdc++.h>
using namespace std;

string reverseString(string &str){
    // Vector to store words
	vector<string> splitted;
	string temp = "";
	int start = 0, n = str.size();

    // Splitting the string
	for(int i=0; i<n; i++) {
        // If space is found
		if(str[i] == ' ') {
            // If there is a word before the space
			if(i > start) {
                // Push the word into the vector
				splitted.push_back(temp);
			}
            // Update the start index
			start = i + 1;
			temp = "";
		} else {
            // If there is no space
            // Append the character to the temp string
			temp += str[i];
		}
	}
    // If there is a word after the last space
	if(start < n) {
        // Push the word into the vector
		splitted.push_back(temp);
	}
	
	string res = "";
    // Start from the last word
	vector<string>::reverse_iterator it = splitted.rbegin();
	// Append the words in reverse order
    while(it != splitted.rend()) {
		res += (*it);
		res += ' ';
        // Move to the previous word
		it++;
	}
    // Remove the last space
	res.pop_back();
    // Return the reversed string
	return res;
}