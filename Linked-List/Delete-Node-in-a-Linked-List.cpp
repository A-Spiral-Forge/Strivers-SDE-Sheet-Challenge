#include <bits/stdc++.h>
using namespace std;

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Delete a node from a linked list given only access to that node
void deleteNode(LinkedListNode<int> * node) {
    // As we have access to only the node to be deleted, we cannot access the previous node
    // The given condition is that the node to be deleted is not the last node
    // So we copy the data of the next node to the current node and delete the next node
    // Copy the data of the next node to the current node
    node->data = node->next->data;
    // Point the next pointer of the current node to the next of the next node
    node->next = node->next->next;
}