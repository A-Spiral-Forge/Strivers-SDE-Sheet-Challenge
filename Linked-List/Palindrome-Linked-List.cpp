#include <bits/stdc++.h> 
using namespace std;

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Function to check if the given linked list is a palindrome or not
bool isPalindrome(LinkedListNode<int> *head) {
    // Stack to store the first half of the list
    stack<int> st;
    // Two pointers to find the middle of the list
    LinkedListNode<int> *slow = head, *fast = head;

    // Find the middle of the list
    while(fast && fast->next) {
        st.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }
    // If the list is odd, then move to the next element
    if(fast) {
        slow = slow->next;
    }
    
    // Compare the first half of the list with the second half
    while(slow && !st.empty()) {
        // If the elements are not equal, then the list is not a palindrome
        if(slow->data != st.top()) {
            return false;
        }
        slow = slow->next;
        st.pop();
    }
    // If the list is a palindrome, then return true
    return true;
}