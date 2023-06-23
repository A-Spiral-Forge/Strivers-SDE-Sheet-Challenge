#include <bits/stdc++.h> 
using namespace std;

// Doubly Linked List Node
class DLL {
    public:
    // key, value and frequency of the key
    int key;
    int value;
    int count;
    // prev and next pointers
    DLL *prev;
    DLL *next;

    DLL(int key, int value, int count) {
        this->key = key;
        this->value = value;
        this->count = count;
        this->prev = NULL;
        this->next = NULL;
    }
};

// LFU Cache
class LFUCache
{
private:
    // map of frequency to DLL node list
    map<int, DLL*> keysWithFreq;
    // map of key to DLL node
    map<int, DLL*> keysWithNode;
    // size and capacity of cache
    int size, capacity;

public:
    // Constructor
    LFUCache(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
    }

    // Add a node to the DLL node list
    void addNode(int key, int value, int count) {
        // Make a new node with given key, value and count
        DLL *node = new DLL(key, value, count);
        // Add the node to the map of key to DLL node
        keysWithNode[key] = node;
        // If the frequency is not present in the map of frequency to DLL node list
        if(keysWithFreq.find(count) == keysWithFreq.end()) {
            // Add the node to the map of frequency to DLL node list
            keysWithFreq[count] = node;
        } else {
            // If the frequency is present in the map of frequency to DLL node list
            // Add the node to the end of the DLL node list
            DLL *prevNode = keysWithFreq[count];
            prevNode->next = node;
            node->prev = prevNode;
        }
    }

    // Delete a node from the DLL node list
    // If add is true, add a new node with the given key,
    // new value and one greater frequency than the deleted node
    // Else we only delete the node
    void deleteNode(int key, bool add = false, int newVal = -1) {
        // Get the node from the map of key to DLL node
        DLL *node = keysWithNode[key];
        // Get the frequency of the node
        int nodeFreq = node->count;
        // Remove the node from the map of key to DLL node
        keysWithNode.erase(key);
        // If the node is the only node in the frequency DLL node list
        if(!node->next && !node->prev) {
            // Remove the frequency from the map of frequency to DLL node list
            keysWithFreq.erase(node->count);
        // If the node is the last node in the frequency DLL node list
        } else if(!node->next) {
            // Remove the node from the frequency DLL node list
            node->prev->next = NULL;
        // If the node is the first node in the frequency DLL node list
        } else if(!node->prev) {
            // Make the next node as the first node in the frequency DLL node list
            keysWithFreq[node->count] = node->next;
            // Remove the node from the frequency DLL node list
            node->next->prev = NULL;
        // If the node is neither the first nor the last node in the frequency DLL node list
        } else {
            // Remove the node from the frequency DLL node list
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->prev = NULL;
            node->next = NULL;
        }
        // Delete the node from the memory
        delete node;
        // If add is true, add a new node with the given key,
        // new value and one greater frequency than the deleted node
        if(add) {
            addNode(key, newVal, nodeFreq + 1);
        }
    }

    // Get the value of the key
    int get(int key)
    {
        // If the key is not present in the map of key to DLL node
        if(keysWithNode.find(key) == keysWithNode.end()) {
            // Return -1
            return -1;
        }
        // Get the node from the map of key to DLL node
        DLL *curr = keysWithNode[key];
        // Get the value of the node
        int value = curr->value;
        // Delete the node from the DLL node list with add as true
        // and new value as the current value of the node
        deleteNode(key, true, curr->value);
        // Return the value
        return value;
    }

    // Put the key and value in the cache
    void put(int key, int value)
    {
        // If key is already present in the map of key to DLL node
        if(keysWithNode.find(key) != keysWithNode.end()) {
            // Get the node from the map of key to DLL node
            DLL *curr = keysWithNode[key];
            // Delete the node from the DLL node list with add as true
            // and new value as the given value
            deleteNode(key, true, value);
            // Return
            return;
        }

        // If the size is equal to the capacity
        if(size == capacity) {
            // Get the first node from the of least frequency DLL node list
            auto it = keysWithFreq.begin();
            // Get the node from the map of key to DLL node
            deleteNode(it->second->key);
            // Decrease the size
            size--;
        }
        // Add the node to the DLL node list with frequency as 1
        addNode(key, value, 1);
        // Increase the size
        size++;
    }
};
