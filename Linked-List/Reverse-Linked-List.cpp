#include <bits/stdc++.h>
using namespace std;

template <typename T>
class LinkedListNode {
public:
    T data;
    LinkedListNode<T> *next;

    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head, LinkedListNode<int> *parent = NULL) 
{
    // If the list is empty or has only one element
    if(!head || !head->next) {
        // If parent exists
        if(parent) {
            // Set parent as child
            head->next = parent;
        }
        // Return head
        return head;
    }

    // Reverse the list from head->next with head as parent
    LinkedListNode<int> *curr = reverseLinkedList(head->next, head);
    // Set parent as child of head
    head->next = parent;

    // Return the new head
    return curr;
}