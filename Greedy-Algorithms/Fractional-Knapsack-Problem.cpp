#include <bits/stdc++.h> 
using namespace std;

bool comparator(pair<int, int> &a, pair<int, int> &b) {
    // We will sort the items in decreasing order of their value/weight ratio
    // Note that we are not using divide operation to avoid floating point numbers
    // We are using corss multiplication to compare the ratios
    return (a.first * b.second) < (b.first * a.second);
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Sort the items in decreasing order of their value/weight ratio
    sort(items.begin(), items.end(), comparator);
    
    double res = 0;
    int i = 0;
    // Now we will start picking the items from the beginning of the sorted array
    while(i < n && w >= items[i].first) {
        // If the current item can be picked completely, we will pick it
        res += items[i].second;
        // We will reduce the remaining weight by the weight of the item
        w -= items[i].first;
        i++;
    }

    // If we have not picked all the items, we will pick the fraction of the next item
    if(i < n) {
        // We will pick the fraction of the item which cannot be picked completely
        res += ((double)w * items[i].second) / items[i].first;
    }

    // Return the maximum value of the items that can be picked
    return res;
}