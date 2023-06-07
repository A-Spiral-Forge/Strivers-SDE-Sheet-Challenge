#include <bits/stdc++.h>
using namespace std;

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    // Calculate the sum of all numbers from 1 to N using formula 
    // S = N(N+1)/2
	long long linearSum = (n * 1LL * (n + 1)) / 2;
    // Calculate the sum of squares all numbers from 1 to N using formula 
    // S = N(N+1)(2N+1)/6
	long long squaredSum = (n * 1LL * (n + 1) * 1LL * (2 * n + 1)) / 6;

	for(long long it: arr) {
        // Subtract the sum of all numbers from 1 to N from the 
        // sum of all elements of the array
        // This will give us A - B
		linearSum -= it;
        // Subtract the sum of squares of all numbers from 1 to N from the 
        // sum of squares of all elements of the array
        // This will give us A^2 - B^2
		squaredSum -= (it * it);
        // Here A is the missing number and B is the repeating number
	}
    // We have two equations now
    // linearSum = A - B
    // squaredSum = A^2 - B^2
    // We can calculate A + B using by dividing ((A^2 - B^2) by (A - B))
    // as A^2 - B^2 = (A - B)(A + B)
	int sumOfTwoNumbers = (squaredSum / linearSum);

    // Now we have A + B and A - B. We can calculate A and B
	int missingNumber = (sumOfTwoNumbers + linearSum) / 2;
	int repeatingNumber = (sumOfTwoNumbers - linearSum) / 2;
    // Return the missing and repeating number
	return {missingNumber, repeatingNumber};
}
