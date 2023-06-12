#include <bits/stdc++.h> 
using namespace std;

class Stack {
    queue<int> q;
    int size = 0;

    public:
    Stack() {
    }

    /*----------------- Public Functions of Stack -----------------*/   

    // Return the size of stack
    int getSize() {
        return size;
    }

    // Check if stack is empty or not
    bool isEmpty() {
        return size == 0;
    }

    // Push an element on the stack
    void push(int element) {
        // Add the new element to the back of the queue
        q.push(element);
        // Rotate the queue till the new element is at the front
        for(int i=0; i<size; i++) {
            q.push(q.front());
            q.pop();
        }
        size++;
    }

    // Pop the top element
    int pop() {
        // Return -1 if stack is empty
        if(size == 0) {
            return -1;
        }
        // Remove the front element, as it is the top element
        int res = q.front();
        q.pop(); size--;
        return res;
    }

    int top() {
        // Return -1 if stack is empty
        // Otherwise return the front element
        return size == 0 ? -1 : q.front();
    }
};