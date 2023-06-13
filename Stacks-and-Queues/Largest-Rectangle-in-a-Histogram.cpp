#include<bits/stdc++.h>
using namespace std;

int largestRectangle(vector < int > & heights) {
    int res = 0;
    int n = heights.size();
    // stack stores the index of the previous smaller element
    stack<int> st;
    
    for(int i=0; i<=n; i++) {
        // While the current element is smaller than the previous element
        while(!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
            // Calculate the area of the rectangle with the top of the stack as the smallest element
            int height = heights[st.top()];
            st.pop();
            // If the stack is empty, then current element is the smallest element
            // If the stack is not empty, then we calculate the width of the rectangle
            // as the difference between the current index and the index of the previous smaller element
            int width = st.empty() ? i : (i - st.top() - 1);

            res = max(res, height * width);
        }
        // Push the current index to the stack
        st.push(i);
    }

    // Return the maximum area
    return res;
}