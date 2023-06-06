#include <bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int rowStart = 0, rowEnd = n - 1;
    int colStart = 0, colEnd = m - 1;

    while(rowStart < rowEnd && colStart < colEnd) {
        // Element to be replaced
        int curr = mat[rowStart][colStart];

        // Iterate the first row and swap element
        for(int i=colStart+1; i<=colEnd; i++) {
            swap(curr, mat[rowStart][i]);
        }

        // Iterate the last column and swap element
        for(int i=rowStart + 1; i<=rowEnd; i++) {
            swap(curr, mat[i][colEnd]);
        }

        // Iterate the last row and swap element
        for(int i=colEnd - 1; i>=colStart; i--) {
            swap(curr, mat[rowEnd][i]);
        }

        // Iterate the first column and swap element
        for(int i=rowEnd - 1; i>=rowStart; i--) {
            swap(curr, mat[i][colStart]);
        }

        // Update the range of matrix
        rowStart++; colStart++;
        rowEnd--; colEnd--;
    }
}