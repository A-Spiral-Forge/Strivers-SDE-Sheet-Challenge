#include <bits/stdc++.h>
using namespace std;

template <typename T>   
class LinkedListNode
{
    public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode<T> *random;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Function to clone a linked list with random pointers
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Mappping from the original list to the cloned list
    map<LinkedListNode<int>*, LinkedListNode<int>*> mapping;
    
    LinkedListNode<int> *temp = head;
    while(temp) {
        // Create a new node with the same data as the current node
        // and store the mapping from the current node to the new node
        mapping[temp] = new LinkedListNode<int>(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp) {
        // Set the next and random pointers of the new node
        // to the corresponding nodes in the cloned list
        mapping[temp]->next = mapping[temp->next];
        mapping[temp]->random = mapping[temp->random];
        temp = temp->next;
    }

    // Return the head of the cloned list
    return mapping[head];
}
