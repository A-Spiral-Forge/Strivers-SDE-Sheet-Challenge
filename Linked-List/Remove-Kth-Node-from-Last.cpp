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

Node* removeKthNode(Node* head, int K)
{
    // Create a dummy node and point it to the head
    Node* newHead = new Node(0);
    // Point the next of dummy node to the head
    newHead->next = head;

    // Create two pointers left and right and point them to dummy node and head respectively
    Node* left = newHead, *right = head;
    int counter = 0;

    // Iterate over the list until right becomes NULL
    while(right) {
        right = right->next;
        // When counter becomes greater than or equal to K, start moving left pointer
        if(counter >= K) {
            left = left->next;
        }
        // Increment the counter
        counter++;
    }

    // Remove the Kth node from the last, which is the node pointed by 
    // next pointer of left pointer
    left->next = left->next->next;

    // Return the head of the list
    return newHead->next;
}
