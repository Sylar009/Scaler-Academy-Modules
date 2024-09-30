/*
Problem Description

Given a M x N grid A of integers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Return the minimum sum of the path.

NOTE: You can only move either down or right at any point in time.



Problem Constraints

1 <= M, N <= 2000

-1000 <= A[i][j] <= 1000



Input Format

First and only argument is a 2-D grid A.



Output Format

Return an integer denoting the minimum sum of the path.



Example Input

Input 1:

 A = [
       [1, 3, 2]
       [4, 3, 1]
       [5, 6, 1]
     ]
Input 2:

 A = [
       [1, -3, 2]
       [2, 5, 10]
       [5, -5, 1]
     ]


Example Output

Output 1:

 8
Output 2:

 -1


Example Explanation

Explanation 1:

 The path will be: 1 -> 3 -> 2 -> 1 -> 1.
Input 2:

 The path will be: 1 -> -3 -> 5 -> -5 -> 1.

*/

int Solution::minPathSum(vector<vector<int> > &A) {
    int s = A.size();
    int t = A[0].size();
    vector<vector<int> > dp(s, vector<int>(t, 0));

    dp[0][0] = A[0][0];

    for (int i = 1; i < t; i++) {
        dp[0][i] = A[0][i]  + dp[0][i-1];
    } 

    for (int j = 1; j < s; j++) {
        dp[j][0] = A[j][0] + dp[j-1][0];
    }

    for (int k = 1; k < s; k++) {
        for (int l = 1;  l < t; l++) {
            dp[k][l] = A[k][l] + min(dp[k][l-1], dp[k-1][l]); 
        }
    }

    return dp[s-1][t-1];
}
