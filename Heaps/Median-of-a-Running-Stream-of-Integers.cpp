#include<bits/stdc++.h>
using namespace std;

// Class to find median of a running stream of integers
class StreamMedian {
    // multiset is used to store the elements in sorted order
    // multiset is used because it allows duplicate elements
    multiset<int> ms;
    // iterator to the middle element of the multiset
    multiset<int>::iterator it;
    int size;

    public:
    // Constructor
    StreamMedian() {
        size = 0;
        ms.insert(0);
        it = ms.begin();
    }

    // Function to insert a new element into the multiset
    void insert(int num) {
        // insert the new element
        ms.insert(num);
        // increment the size
        size++;
        // if the new element is less than or equal to the middle element
        if((*it) <= num) {
            // if the size is odd, increment the iterator
            if(size % 2 == 1) {
                it++;
            }
        // if the new element is greater than the middle element
        } else {
            // if the size is even, decrement the iterator
            if(size % 2 == 0) {
                it--;
            }
        }
    }

    // Function to return the median of the running stream
    int getMedian() {
        // if the size is odd, return the middle element
        if(size % 2 == 1) {
            return (*it);
        }

        // if the size is even, return the average of the middle two elements
        multiset<int>::iterator it2 = it;
        it2++;
        return ((*it) + (*it2)) / 2;
    }
};

void findMedian(int *arr, int n)
{
    // Create a StreamMedian object
    StreamMedian *sm = new StreamMedian();
    // Iterate over the array
    for(int i=0; i<n; i++) {
        // Insert the current element into the StreamMedian object
        sm->insert(arr[i]);
        // Print the median of the running stream
        cout<< sm->getMedian()<< " ";
    }
    cout<< endl;
}