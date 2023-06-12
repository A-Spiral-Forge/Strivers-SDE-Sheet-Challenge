#include <bits/stdc++.h>
using namespace std;

// Doubly Linked List Node
class DLL {
    public:
    int key;
    int value;
    DLL *prev, *next;

    // Constructor
    DLL(int key, int val, DLL *prev = NULL, DLL *next = NULL) {
        this->key = key;
        this->value = val;
        this->prev = prev;
        this->next = next;
    }
};

class LRUCache
{
private:
    // Front and back pointers of the doubly linked list 
    DLL *front, *back;
    int size, capacity;
    // Map to store the key and the corresponding node in the doubly linked list
    map<int, DLL*> m;

public:
    LRUCache(int capacity)
    {
        this->size = 0;
        this->capacity = capacity;
        // Create a dummy node at the front and back of the doubly linked list
        this->front = new DLL(-1, -1);
        this->back = new DLL(-1, -1);
        // Link the dummy nodes
        front->next = back;
        back->prev = front;
    }

    // Add a node to the back of the doubly linked list
    void addNode(int key, int value) {
        DLL *newNode = new DLL(key, value, back->prev, back);
        m[key] = newNode;
        back->prev->next = newNode;
        back->prev = newNode;
    }

    // Delete a node from the doubly linked list
    void deleteNode(int key) {
        DLL *node = m[key];
        m.erase(key);

        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

    // Get the value of the key if the key exists in the cache, otherwise return -1.
    int get(int key)
    {
        if(m.find(key) == m.end()) {
            return -1;
        }

        int value = m[key]->value;
        deleteNode(key);
        addNode(key, value);
        return value;
    }

    // Set or insert the value if the key is not already present.
    void put(int key, int value)
    {
        // If the key is already present, delete the node and
        // add a new node to the back of the doubly linked list
        if(m.find(key) != m.end()) {
            deleteNode(key);
            size--;
        }
        addNode(key, value);
        size++;
        // If the size of the cache exceeds the capacity, delete the front node
        if(size > capacity) {
            deleteNode(front->next->key);
            size--;
        }
    }
};
