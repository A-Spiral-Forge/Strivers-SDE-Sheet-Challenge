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

// Function to find the first node of the cycle in the linked list
Node *firstNode(Node *head)
{
    // Floyd's Cycle Detection Algorithm
    Node *slow = head, *fast = head;
    bool f = true;
    // Find the cycle in the linked list
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            f = false;
            break;
        }
    }

    // If the cycle is not present, then return NULL
    if(slow != fast || f) {
        return NULL;
    }

    // Move the slow pointer to the head of the list
    slow = head;
    // Find the first node of the cycle
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    // Return the first node of the cycle
    return slow;
}