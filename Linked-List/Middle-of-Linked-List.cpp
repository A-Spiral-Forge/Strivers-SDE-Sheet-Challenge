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

Node *findMiddle(Node *head) {
    // Using Floyd's Tortoise and Hare Algorithm
    Node *res = head, *end = head;

    // Iterate over the list
    // When end reaches the end of the list, res will be at the middle of the list
    while(end && end->next) {
        // Move res by one node
        res = res->next;
        // Move end by two nodes
        end = end->next->next;
    }

    // Return the middle node
    return res;
}

