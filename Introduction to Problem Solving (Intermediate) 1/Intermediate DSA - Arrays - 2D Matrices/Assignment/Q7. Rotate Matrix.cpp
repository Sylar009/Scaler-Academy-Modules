/*
Problem Description
You are given a n x n 2D matrix A representing an image.

Rotate the image by 90 degrees (clockwise).

You need to do this in place.

Note: If you end up using an additional array, you will only receive partial score.



Problem Constraints
1 <= n <= 1000



Input Format
First argument is a 2D matrix A of integers



Output Format
Return the 2D rotated matrix.



Example Input
Input 1:

 [
    [1, 2],
    [3, 4]
 ]
Input 2:

 [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
 ]


Example Output
Output 1:

 [
    [3, 1],
    [4, 2]
 ]
Output 2:

 [
    [7, 4, 1],
    [8, 5, 2],
    [9, 6, 3]
 ]

*/

void Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            swap (A[i][j], A[j][i]);
        }
    }

    for (int k = 0; k < n; k++) {
        int x = 0;
        int y = n -1;
        while (x < y) {
             swap (A[k][x], A[k][y]);
             x++;
             y--;
        }
    }
}
