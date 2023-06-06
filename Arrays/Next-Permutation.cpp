#include <bits/stdc++.h> 
using namespace std;

vector<int> nextPermutation(vector<int> &permutation, int n)
{
    // Find the first element from the right which is smaller than its next element
    int pivot = n - 2;
    for(; pivot >= 0; pivot--) {
        if(permutation[pivot] < permutation[pivot + 1]) {
            break;
        }
    }

    // If no such element is found, reverse the array and return
    if(pivot == -1) {
        reverse(permutation.begin(), permutation.end());
        return permutation;
    }

    // Find the first element from the right which is greater than the element at pivot
    // and swap it with the element at pivot
    for(int i=n-1; i>pivot; i--) {
        if(permutation[i] > permutation[pivot]) {
            swap(permutation[i], permutation[pivot]);
            break;
        }
    }

    // Reverse the array from pivot + 1 to the end
    reverse(permutation.begin() + pivot + 1, permutation.end());
    return permutation;
}