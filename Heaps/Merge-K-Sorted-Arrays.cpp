#include <bits/stdc++.h> 
using namespace std;

// Class to store the value, elementIndex, arrayIndex and arraySize of the element
class Node {
    public:
    int value;
    int elementIndex;
    int arrayIndex;
    int arraySize;

    // Operator overloading to compare the value of the nodes
    bool operator()(Node &a, Node &b) {
        return a.value > b.value;
    }
};

// Function to merge k sorted arrays
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> res;
    // Min heap to store the first element of each array
    priority_queue<Node, vector<Node>, Node> pq;

    // Push the first element of each array into the heap
    for(int i=0; i<k; i++) {
        Node temp = {kArrays[i][0], 0, i, kArrays[i].size()};
        pq.push(temp);
    }

    // Pop the top element from the heap and push the next element of the array
    while(!pq.empty()) {
        Node temp = pq.top();
        pq.pop();
        res.push_back(temp.value);
        
        if(temp.elementIndex + 1 < temp.arraySize) {
            pq.push({
                kArrays[temp.arrayIndex][temp.elementIndex + 1], 
                temp.elementIndex + 1, 
                temp.arrayIndex, 
                temp.arraySize
            });
        }
    }

    // Return the merged array
    return res;
}
