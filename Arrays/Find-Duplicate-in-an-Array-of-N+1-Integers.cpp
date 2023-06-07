#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr, int n){
    // Floyd's Tortoise and Hare (Cycle Detection)
    // Declare two pointers slow and fast and initialize both of them to arr[0]
	int slow = arr[0], fast = arr[0];

	while(true) {
        // Move slow one step forward
		slow = arr[slow];
        // Move fast two steps forward
		fast = arr[arr[fast]];

        // If slow and fast meet at some point then there is a loop
		if(slow == fast) {
			break;
		}
	}

    // Find the starting point of the loop
    // Move fast to arr[0] and keep slow at the meeting point
    // Move both slow and fast one step forward and they will meet at the starting point of the loop
	fast = arr[0];
	while(slow != fast) {
		slow = arr[slow];
		fast = arr[fast];
	}
	return slow;
}
