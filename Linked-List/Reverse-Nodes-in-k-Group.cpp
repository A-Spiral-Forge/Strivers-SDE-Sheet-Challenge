#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Function to reverse the nodes in k groups and
// return the pointer to the new head node.
Node* solve(Node *head, int idx, int n, int b[]) {
    // If the list is empty or the index is equal to n
	if(!head || idx == n) {
		return head;
	}

    // If the current k is 0, then we don't need to reverse the list
    // Move to the next k
	if(b[idx] == 0) {
		return solve(head, idx + 1, n, b);
	}

    // Reverse the list
	Node* temp = head; Node* prev = NULL;
    // Store the first k elements in a stack
	stack<int> st;
	int sz = 0;
    // Reverse the first k elements
	while(temp && sz < b[idx]) {
        // Push the elements in the stack
		st.push(temp->data);
		sz++;
        // Move to the next element
		prev = temp;
		temp = temp->next;
	}
	
    // If the list is smaller than k, then we don't need to reverse the list
	if(!prev) {
		return head;
	}
    // If the list is greater than k, then we need to reverse the list
	prev->next = solve(temp, idx + 1, n, b);

    // Pop the elements from the stack and store them in the list
	temp = head;
	while(!st.empty()) {
		temp->data = st.top();
		st.pop();
		temp = temp->next;
	}
    
    // Return the head of the list
	return head;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	return solve(head, 0, n, b);
}