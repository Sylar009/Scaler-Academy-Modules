/*
Problem Description
Given a matrix of integers A of size N x M and an integer B. Write an efficient algorithm that searches for integer B in matrix A.

This matrix A has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than or equal to the last integer of the previous row.
Return 1 if B is present in A, else return 0.

NOTE: Rows are numbered from top to bottom, and columns are from left to right.



Problem Constraints
1 <= N, M <= 1000
1 <= A[i][j], B <= 106



Input Format
The first argument given is the integer matrix A.
The second argument given is the integer B.



Output Format
Return 1 if B is present in A else, return 0.



Example Input
Input 1:

A = [ 
      [1,   3,  5,  7]
      [10, 11, 16, 20]
      [23, 30, 34, 50]  
    ]
B = 3
Input 2:

A = [   
      [5, 17, 100, 111]
      [119, 120, 127, 131]    
    ]
B = 3


Example Output
Output 1:

1
Output 2:

0


Example Explanation
Explanation 1:

 3 is present in the matrix at A[0][1] position so return 1.
Explanation 2:

 3 is not present in the matrix so return 0.


*/

int Solution::searchMatrix(vector<vector<int> > &A, int B) {

    int row = A.size();
    int col = A[0].size();

    int row_start = 0;
    int row_end = row-1;

    int sus_row = -1;

    while (row_start <= row_end) {

        int row_mid = row_start + (row_end - row_start) / 2;

        if (A[row_mid][0] <= B && A[row_mid][col-1] >= B) { sus_row = row_mid; break;}
        else if (A[row_mid][0] > B) row_end = row_mid - 1;
        else row_start = row_mid + 1;
    }

    if (sus_row == -1) return 0; 

    int col_start = 0;
    int col_end = col-1;

    while (col_start <= col_end) {
        int col_mid = col_start + (col_end - col_start) / 2;

        if (A[sus_row][col_mid] == B ) return 1;
        else if (A[sus_row][col_mid] > B) col_end = col_mid - 1;
        else col_start = col_mid + 1;
    }

    return 0;
}
