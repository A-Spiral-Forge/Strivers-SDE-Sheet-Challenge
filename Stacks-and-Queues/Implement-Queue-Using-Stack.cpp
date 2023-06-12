#include<bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> s1, s2;
    
    public:
    Queue() {
    }

    // Insert an element into the queue.
    void enQueue(int val) {
        // Move all elements from s1 to s2
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        // Push the new element into s1
        s1.push(val);
        // Move all elements from s2 to s1
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        // Now the new element is at the bottom of s1
    }

    // Remove front element from the queue and return it
    int deQueue() {
        // Return -1 if queue is empty
        if(s1.empty()) {
            return -1;
        }

        // Remove the top element from s1
        int res = s1.top();
        s1.pop();
        return res;
    }

    // Return the front of the queue
    int peek() {
        return s1.empty() ? -1 : s1.top();
    }

    // Return true if the queue is empty, otherwise return false
    bool isEmpty() {
        return s1.empty();
    }
};