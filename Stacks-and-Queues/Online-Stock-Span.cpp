#include <bits/stdc++.h> 
using namespace std;

vector<int> findSpans(vector<int> &price) {
    // Stack to store indices of prices with previous greater price
    stack<int> st;
    int n = price.size();

    // Vector to store span values
    vector<int> res(n, 0);
    for(int i=0; i<n; i++) {
        // Pop elements from stack while stack is not empty 
        // and price at top of stack is smaller than or equal to price[i]
        while(!st.empty() && price[st.top()] <= price[i]) {
            st.pop();
        }
        
        // If stack becomes empty, then price[i] is greater than all elements on left of it
        // Else price[i] is greater than elements after top of stack
        res[i] = st.empty() ? i + 1 : (i - st.top());
        // Push this element to stack
        st.push(i);
    }

    // Return the calculated span values
    return res;
}