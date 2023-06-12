#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> res(n, -1);
    // Stack to store smaller elements
    stack<int> st;

    // Iterate through the array from right to left
    for(int i = n - 1; i >= 0; i--) {
        // Pop all elements from the stack that are greater than the current element
        while(!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }
        // If the stack is empty, means there is no smaller element to the right of the current element
        res[i] = (st.empty() ? -1 : st.top());
        // Push the current element into the stack
        st.push(arr[i]);
    }

    // Return the next smaller element array
    return res;
}