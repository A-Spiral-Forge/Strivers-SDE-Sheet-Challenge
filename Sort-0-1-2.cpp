#include <bits/stdc++.h> 
using namespace std;

void sort012(int *arr, int n)
{
    // Sort the array using Dutch National Flag Algorithm
    int low = 0, curr = 0, high = n - 1;

    // Iterate till all the elements are sorted
    while(curr <= high) {
        // If the current element is 1, increment curr
        if(arr[curr] == 1) {
            curr++;
        // If the current element is 0, swap it with the element at low and increment low and curr
        } else if(arr[curr] == 0) {
            swap(arr[low], arr[curr]);
            low++;
            curr++;
        // If the current element is 2, swap it with the element at high and decrement high
        } else {
            swap(arr[curr], arr[high]);
            high--;
        }
   }
}