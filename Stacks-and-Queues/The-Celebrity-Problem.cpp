#include <bits/stdc++.h> 
using namespace std;
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

bool knows(int a, int b);

int findCelebrity(int n) {
	stack<int> st;
    // Store all the people in the stack
	for(int i=0; i<n; i++) {
		st.push(i);
	}

	while(st.size() > 1) {
        // Pop two people at a time and check if they know each other
		int a = st.top();
		st.pop();
		int b = st.top();
		st.pop();

        // If a knows b, then a cannot be a celebrity
		if(knows(a, b)) {
			st.push(b);
        // If a doesn't know b, then b cannot be a celebrity
		} else {
			st.push(a);
		}
	}

    // Check if the last person in the stack is a celebrity
	for(int i=0; i<n; i++) {
        // If the last person doesn't know anyone, then he/she is a celebrity
		if(i != st.top() && !knows(i, st.top())) {
			return -1;
		}

        // If someone doesn't know the last person, then he/she is not a celebrity
		if(knows(st.top(), i)) {
			return -1;
		}
    }

    // Return the celebrity
	return st.top();
}