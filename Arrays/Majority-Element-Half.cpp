#include <bits/stdc++.h>
using namespace std;

int findMajorityElement(int arr[], int n) {
	int count = 0, curr = arr[0];
	for(int i=0; i<n; i++) {
		if(count < 0) {
			curr = arr[i];
			count = 0;
		}
		if(curr == arr[i]) {
			count++;
		} else {
			count--;
		}
	}

	count = 0;
	for(int i=0; i<n; i++) {
		if(curr == arr[i]) {
			count++;
		} else {
			count--;
		}
	}

	return count > 0 ? curr : -1;
}