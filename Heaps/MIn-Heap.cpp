#include <bits/stdc++.h>
using namespace std;

// Min-Heap class
class MinHeap {
    public:
    // Pointer to array of elements
    int *arr;
    // Maximum possible size of min heap
    int capacity;
    // Current number of elements in min heap
    int size;

    // Constructor
    MinHeap(int capacity) {
        // Initialize the size and capacity
        size = 0;
        this->capacity = capacity;
        // Initialize the array
        arr = new int[capacity];
    }

    // Function to get the index of the parent of the node at index i
    int parent(int i) {
        return (i - 1) / 2;
    }

    // Function to get the index of the left child of the node at index i
    int left(int i) {
        return (2 * i) + 1;
    }

    // Function to get the index of the right child of the node at index i
    int right(int i) {
        return (2 * i) + 2;
    }

    // Function to insert a new element into the min heap
    void insert(int num) {
        // If the size is equal to the capacity, return
        if(size == capacity) {
            return;
        }

        // Insert the new element at the end
        arr[size] = num;
        // Increment the size
        size++;

        // Fix the min heap property if it is violated
        int i = size - 1;
        while(i != 0 && arr[parent(i)] > arr[i]) {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    // Function to heapify the min heap
    void heapify(int i) {
        // Get the index of the left and right child of the node at index i
        int l = left(i);
        int r = right(i);

        // Initialize the index of the smallest element
        int smallest = i;

        // If the left child is smaller than the current smallest element
        if(l < size && arr[l] < arr[smallest]) {
            // Update the index of the smallest element
            smallest = l;
        }

        // If the right child is smaller than the current smallest element
        if(r < size && arr[r] < arr[smallest]) {
            // Update the index of the smallest element
            smallest = r;
        }

        // If the smallest element is not the current element
        if(smallest != i) {
            // Swap the smallest element with the current element
            swap(arr[i], arr[smallest]);
            // Heapify the subtree
            heapify(smallest);
        }
    }

    // Function to extract the minimum element from the min heap
    int extractMin() {
        // If the size is equal to 0, return INT_MAX
        if(size == 0) {
            return INT_MAX;
        }

        // If the size is equal to 1
        if(size == 1) {
            // Decrement the size
            size--;
            // Return the only element
            return arr[0];
        }

        // Store the minimum element
        int root = arr[0];
        // Replace the minimum element with the last element
        arr[0] = arr[size - 1];
        // Decrement the size
        size--;
        // Heapify the root
        heapify(0);

        // Return the minimum element
        return root;
    }

    // Function to get the minimum element from the min heap
    int getMin() {
        // If the size is equal to 0, return INT_MAX
        if(size == 0) {
            return INT_MAX;
        }

        // Return the minimum element
        return arr[0];
    }

    // Function to delete an element from the min heap
    void deleteKey(int i) {
        // If the index is invalid, return
        if(i >= size) {
            return;
        }

        // Replace the element with INT_MIN
        arr[i] = INT_MIN;

        // Fix the min heap property if it is violated
        while(i != 0 && arr[parent(i)] > arr[i]) {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }

        // Extract the minimum element
        extractMin();
    }
};

// Function to print the elements of the min heap
void print(MinHeap minHeap) {
    // Print the elements
    for(int i = 0; i < minHeap.size; i++) {
        cout << minHeap.arr[i] << " ";
    }
    cout << endl;
}