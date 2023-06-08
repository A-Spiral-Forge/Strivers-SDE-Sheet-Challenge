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

// Function to calculate the size of the linked list
int sizeOfList(Node* head) {
    if(!head) {
        return 0;
    }

    return sizeOfList(head->next) + 1;
}

// Function to find the intersection of two linked lists
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    // Calculating the size of the linked lists
    int sizeFirst = sizeOfList(firstHead);
    int sizeSecond = sizeOfList(secondHead);

    // Calculating the difference in size of the linked lists
    int diff = sizeFirst - sizeSecond;
    // If the first linked list is greater than the second linked list
    if(diff > 0) {
        // Move the first linked list pointer by the difference
        while(diff > 0) {
            firstHead = firstHead->next;
            diff--;
        }
    // If the second linked list is greater than the first linked list
    } else if(diff < 0) {
        diff = -diff;
        // Move the second linked list pointer by the difference
        while(diff > 0) {
            secondHead = secondHead->next;
            diff--;
        }
    }

    // Move both the pointers until they are equal
    while(firstHead && secondHead && firstHead != secondHead) {
        firstHead = firstHead->next;
        secondHead = secondHead->next;
    }

    return firstHead;
}