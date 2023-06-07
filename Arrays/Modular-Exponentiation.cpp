#include <bits/stdc++.h>
using namespace std;

int modularExponentiation(int x, int n, int m) {
    // Base case
	if(n == 0) {
		return 1;
	}

    // Calculate the value of x^(n/2) modulo m
	int halfExponent = modularExponentiation(x, n/2, m);

    // If n is even, return (x^(n/2) * x^(n/2)) modulo m
    // If n is odd, return (x^(n/2) * x^(n/2) * x) modulo m
	int res = (halfExponent * 1LL * halfExponent) % m;
	if(n & 1) {
		res = (res * 1LL * x) % m;
	}

	return res;
}