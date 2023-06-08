#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node *next;
		Node *child;
	Node() : data(0), next(nullptr), child(nullptr){};
	Node(int x) : data(x), next(nullptr), child(nullptr) {}
	Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};

// Function to merge two sorted linked lists
Node* merge(Node* curr, Node* next) {
    // If the current node is NULL, then return the next node
	if(!curr) {
		return next;
	}
    // If the next node is NULL, then return the current node
	if(!next) {
		return curr;
	}

    // If the current node is smaller than the next node
    // call merge on the child of the current node and the next node
	if(curr->data <= next->data) {
		curr->child = merge(curr->child, next);
		return curr;
	}
	
    // If the next node is smaller than the current node
    // call merge on the current node and the child of the next node
	next->child = merge(curr, next->child);
	return next;
}


Node* flattenLinkedList(Node* head) 
{
	if(!head || !head->next) {
		return head;
	}

    // Store the next node
	Node* root = head->next;
	head->next = NULL;
    // Flatten the next node
	root = flattenLinkedList(root);

    // Merge the current node and the next node
	head = merge(head, root);
	return head;
}
