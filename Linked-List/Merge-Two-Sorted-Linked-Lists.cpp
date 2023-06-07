#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T data) {
        next = NULL;
        this->data = data;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(!first) {
        return second;
    }
    if(!second) {
        return first;
    }

    if(first->data < second->data) {
        first->next = sortTwoLists(first->next, second);
        return first;
    }

    second->next = sortTwoLists(first, second->next);
    return second;
}
