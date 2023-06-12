#include <bits/stdc++.h> 
using namespace std;

// Helper function to insert an element into the stack at its correct position
void helper(stack<int> &st, int element) {
    // If the stack is empty or the top of the stack is less than or equal to the element,
    // push the element into the stack and return
	if(st.empty() || st.top() <= element) {
		st.push(element);
		return;
	}

    // If the top of the stack is greater than the element,
    // pop the top of the stack and call the helper function again
	int curr = st.top();
	st.pop();
	helper(st, element);
    // Push the popped element back into the stack
	st.push(curr);
}

void sortStack(stack<int> &st)
{
    // If the stack is empty, return (Base Case)
	if(st.empty()) {
		return;
	}

    // Pop the top of the stack and call the sortStack function again
	int curr = st.top();
	st.pop();

	sortStack(st);
    // Call the helper function to insert the popped element into the stack at its correct position
	helper(st, curr);
}