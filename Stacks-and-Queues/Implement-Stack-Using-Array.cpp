#include <bits/stdc++.h> 
using namespace std;

// Stack class.
class Stack {
private:
    vector<int> st;
    int sz, index;

public:
    // Constructor to initialize the stack.
    Stack(int capacity) {
        st.resize(capacity);
        index = 0;
        sz = capacity;
    }

    // Pushes the given number into the stack.
    void push(int num) {
        // If the stack is full, we will not push the number.
        if(index == sz) {
            return;
        }
        st[index] = num;
        index++;
    }

    // Pops the top element from the stack.
    int pop() {
        // If the stack is empty, we will return -1.
        if(index == 0) {
            return -1;
        }
        index--;
        return st[index];
    }
    
    // Returns the top element of the stack.
    int top() {
        // If the stack is empty, we will return -1.
        if(index == 0) {
            return -1;
        }
        return st[index - 1];
    }
    
    // Returns 1 if the stack is empty, 0 otherwise.
    int isEmpty() {
        return index == 0;
    }
    
    // Returns 1 if the stack is full, 0 otherwise.
    int isFull() {
        return index == sz;
    }
    
};