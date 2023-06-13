#include <bits/stdc++.h> 
using namespace std;
// Implement class for minStack.
class minStack
{
    // Declare a stack of pairs to store the elements and their minimums.
	stack<pair<int, int>> st;
	
	public:
		
		// Constructor
		minStack() 
		{ 
			
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
            // If the stack is empty, push the element as it is.
			if(st.empty()) {
				st.push({num, num});
				return;
			}
            // If the stack is not empty, push the element along with the 
            // minimum till now and the element itself.
			st.push({num, min(st.top().second, num)});
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
            // If the stack is empty, return -1.
			if(st.empty()) {
				return -1;
			}
            // If the stack is not empty, remove the top element and return it.
			int res = st.top().first;
			st.pop();
			return res;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
            // If the stack is empty, return -1.
			if(st.empty()) {
				return -1;
			}
            // If the stack is not empty, return the top element.
			int res = st.top().first;
			return res;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
            // If the stack is empty, return -1.
			if(st.empty()) {
				return -1;
			}
            // If the stack is not empty, return the minimum element till now.
			int res = st.top().second;
			return res;
		}
};