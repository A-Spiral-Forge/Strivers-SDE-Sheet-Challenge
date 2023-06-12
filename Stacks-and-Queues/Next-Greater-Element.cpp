#include <bits/stdc++.h> 
using namespace std;

vector<int> nextGreater(vector<int> &arr, int n) {
    vector<int> res(n, -1);
    // Stack to store greater elements
    stack<int> st;

    // Iterate through the array from right to left
    for(int i = n - 1; i >= 0; i--) {
        // Pop all elements from the stack that are smaller than the current element
        while(!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        // If the stack is empty, means there is no greater element to the right of the current element
        // Else, the top of the stack is the next greater element to the right of the current element
        res[i] = (st.empty() ? -1 : st.top());
        // Push the current element into the stack
        st.push(arr[i]);
    }
    // Return the next greater element array
    return res;
}