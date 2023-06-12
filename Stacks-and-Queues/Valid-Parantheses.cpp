#include<bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string expression)
{
    // Stack to store opening brackets.
    stack<char> st;
    // Iterate through the given expression.
    for(char &ch: expression) {
        // If the current character is an opening bracket, push it into the stack.
        if(ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else {
            // If the current character is a closing bracket
            // If the stack is empty, return false.
            if(st.empty()) {
                return false;
            }
            // If the stack is not empty,
            // Create a string of the top of the stack and the current character.
            string s = {st.top(), ch}; 
            // Check if the top of the stack is the corresponding opening bracket.
            if(s == "()" || s == "{}" || s == "[]") {
                st.pop();
            } else {
                // If the top of the stack is not the corresponding opening bracket, return false.
                return false;
            }
        }
    }

    // If the stack is empty, means all the opening brackets have been closed.
    // return true, else return false.
    return st.empty();
}