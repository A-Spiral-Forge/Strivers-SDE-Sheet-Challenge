#include <bits/stdc++.h> 
using namespace std;

// Node to store the range of the current node and the value of the node
class Node {
	public:
	int val;
	int rangeMin;
	int rangeMax;
};

int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
    // Store the indices of the value in the inorder traversal
	map<int, int> inorderIndices;
	for(int i=0; i<N; i++) {
		inorderIndices[inorder[i]] = i;
	}
	
    // Store the level order traversal index
	int levelIndex = 0;
    // Queue to store the current node and the range of the node
	queue<Node> q;
    // Push the root node
	q.push({levelOrder[levelIndex], 0, N - 1});
	// Increment the level index
    levelIndex++;
    // Store the maximum height of the tree
	int res = 0;

    // Iterate while the queue is not empty
	while(!q.empty()) {
        // Curent size of the queue
		int qs = q.size();
        // Iterate over the current level
		while(qs--) {
            // Pop the front node
			Node temp = q.front();
			q.pop();

            // Get the index of the current node in the inorder traversal
			int index = inorderIndices[temp.val];
            // Check if the current node is the left child of the parent
			if(index == temp.rangeMin) {
                // Check if the right child exists
				if(levelIndex < N && index < temp.rangeMax) {
                    // Push the right child
					q.push({levelOrder[levelIndex], index + 1, temp.rangeMax});
					// Increment the level index
                    levelIndex++;
				}
            // Check if the current node is the right child of the parent
			} else if(index == temp.rangeMax) {
                // Check if the left child exists
				if(levelIndex < N && index > temp.rangeMin) {
                    // Push the left child
					q.push({levelOrder[levelIndex], temp.rangeMin, index - 1});
					// Increment the level index
                    levelIndex++;
				}
            // If both the children exist
			} else {
                // Check if the left child exists
				if(levelIndex < N && index > temp.rangeMin) {
                    // Push the left child
					q.push({levelOrder[levelIndex], temp.rangeMin, index - 1});
					// Increment the level index
                    levelIndex++;
				}
                // Check if the right child exists
				if(levelIndex < N && index < temp.rangeMax) {
                    // Push the right child
					q.push({levelOrder[levelIndex], index + 1, temp.rangeMax});
					// Increment the level index
                    levelIndex++;
				}
			}
		}
        // Increment the height of the tree
		res++;
	}
    // Return the height of the tree
	return res - 1;
}