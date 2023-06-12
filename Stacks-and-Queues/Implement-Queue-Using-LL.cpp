#include <bits/stdc++.h> 
using namespace std;

// Class for making a node of the linked list
class LinkedListNode {
    public:
    int data;
    LinkedListNode *next;

    // Constructor
    LinkedListNode(int data) {
        this->data= data;
        this->next = NULL;
    }
};

// Class to implement Queue using Linked List
class Queue {
private:
    // Pointer to the front and back of the queue 
    LinkedListNode *frontNode, *back;

public:
    // Constructor
    Queue() {
        frontNode = back = NULL;
    }

    /*----------------- Public Functions of Queue -----------------*/


    bool isEmpty() {
        // If the front node is NULL, the queue is empty
        return frontNode == NULL;
    }

    void enqueue(int data) {
        // If the queue is empty, create a new node and make it the front node
        if(frontNode == NULL) {
            frontNode = new LinkedListNode(data);
            // Make the back node same as the front node
            back = frontNode;
            return;
        }

        // Else, create a new node and make it the next node of the back node
        back->next = new LinkedListNode(data);
        back = back->next;
    }

    int dequeue() {
        // If the queue is empty, return -1
        if(frontNode == NULL) {
            return -1;
        }
        // Else, store the data of the front node in a temporary variable
        int res = frontNode->data;
        // Move the front node one step ahead
        frontNode = frontNode->next;
        return res;
    }

    int front() {
        // If the queue is empty, return -1
        if(frontNode == NULL) {
            return -1;
        }
        // Else, return the data of the front node
        int res = frontNode->data;
        return res;
    }
};