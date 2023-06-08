#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

// Function to detect cycle in a linked list
bool detectCycle(Node *head)
{
    // Using Floyd's Cycle Detection Algorithm
	Node *slow = head, *fast = head;

    // Move fast pointer until it reaches the end of the linked list
    while(fast && fast->next) {
        // Move the slow pointer by one node
        slow = slow->next;
        // Move the fast pointer by two nodes
        fast = fast->next->next;

        // If the slow and fast pointers meet
        if(slow == fast) {
            // Return true
            return true;
        }
    }

    // Return false
    return false;
}