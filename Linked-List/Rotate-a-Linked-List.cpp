#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

// Function to calculate the size of the list
int sizeOfList(Node* head) {
    if(!head) {
        return 0;
    }
    return sizeOfList(head->next) + 1;
}

// Function to rotate the list by k
Node *rotate(Node *head, int k) {
    // Calcvulate the size of the list
    int size = sizeOfList(head);
    // If k is greater than the size of the list, then we need to rotate the list by k % size
    k %= size;

    // If k is 0, then we don't need to rotate the list
    if(k == 0) {
        return head;
    }

    Node *prev = NULL, *curr = head;
    int counter = 0;
    
    // Move the pointer to the kth node from the end
    while(counter < size - k) {
        counter++;
        prev = curr;
        curr = curr->next;
    }
    // Make the kth node from the end as the head of the list
    prev->next = NULL;
    Node *res = curr;

    // Move the pointer to the end of the list
    while(curr->next) {
        curr = curr->next;
    }
    // Make the end of the list point to the head of the list
    curr->next = head;

    // Return the head of the list
    return res;
}