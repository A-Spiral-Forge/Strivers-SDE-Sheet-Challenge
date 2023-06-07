#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node() {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    Node (int data, Node *next) {
        this->data = data;
        this->next = next;
    }
};

// Add two numbers represented by linked list
Node *addTwoNumbers(Node *num1, Node *num2, int carry = 0)
{
    // If both numbers are NULL
    if(!num1 && !num2) {
        // If carry is greater than 0, return a new node with carry as data
        if(carry > 0) {
            return new Node(carry);
        }
        // Else return NULL
        return NULL;
    }

    // If first number is NULL
    if(!num1) {
        // Add carry to the other number
        int temp = num2->data + carry;
        // Update the data of the other number
        num2->data = (temp % 10);
        // Add the remaining carry to the next node
        num2->next = addTwoNumbers(num1, num2->next, temp / 10);
        // Return the other number
        return num2;
    }

    // If second number is NULL
    if(!num2) {
        // Add carry to the first number
        int temp = num1->data + carry;
        // Update the data of the first number
        num1->data = (temp % 10);
        // Add the remaining carry to the next node
        num1->next = addTwoNumbers(num1->next, num2, temp / 10);
        // Return the first number
        return num1;
    }

    // If both numbers are not NULL
    // Add carry to the sum of both numbers
    int temp = num1->data + num2->data + carry;
    // Update the data of the first number
    num1->data = (temp % 10);
    // Add the remaining carry to the next node
    num1->next = addTwoNumbers(num1->next, num2->next, temp / 10);
    // Return the first number
    return num1;
}
