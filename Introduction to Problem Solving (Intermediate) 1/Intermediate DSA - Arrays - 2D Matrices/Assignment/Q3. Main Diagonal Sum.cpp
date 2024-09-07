/*
Problem Description
You are given a N X N integer matrix. You have to find the sum of all the main diagonal elements of A.

Main diagonal of a matrix A is a collection of elements A[i, j] such that i = j.


Problem Constraints
1 <= N <= 103

-1000 <= A[i][j] <= 1000



Input Format
There are 1 lines in the input. First 2 integers R, C are the number of rows and columns. Then R * C integers follow corresponding to the rowwise numbers in the 2D array A.



Output Format
Return an integer denoting the sum of main diagonal elements.



Example Input
Input 1:

3 3 1 -2 -3 -4 5 -6 -7 -8 9
Input 2:

2 2 3 2 2 3


Example Output
Output 1:

 15 
Output 2:

 6 

*/

int Solution::solve(const vector<vector<int> > &A) {
    int sum = 0;
    for (int i = 0; i < A.size(); i++ ) {
        sum += A[i][i];
    }

    return sum;
}
