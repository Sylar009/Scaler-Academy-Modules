/*
Problem Description

Given a rod of length N units and an array A of size N denotes prices that contains prices of all pieces of size 1 to N.

Find and return the maximum value that can be obtained by cutting up the rod and selling the pieces.



Problem Constraints

1 <= N <= 1000

0 <= A[i] <= 106



Input Format

First and only argument is an integer array A of size N.



Output Format

Return an integer denoting the maximum value that can be obtained by cutting up the rod and selling the pieces.



Example Input

Input 1:

 A = [3, 4, 1, 6, 2]
Input 2:

 A = [1, 5, 2, 5, 6]


Example Output

Output 1:

 15
Output 2:

 11


Example Explanation

Explanation 1:

 Cut the rod of length 5 into 5 rods of length (1, 1, 1, 1, 1) and sell them for (3 + 3 + 3 + 3 + 3) = 15.
Explanation 2:

 Cut the rod of length 5 into 3 rods of length (2, 2, 1) and sell them for (5 + 5 + 1) = 11.


*/

int Solution::solve(vector<int> &A) {
    int len = A.size();
    vector< vector< int> > dp(2, vector<int>(len+1, 0));
    for (int i = 1; i<= len; i++) {
        for (int j = 1; j <= len; j++) {
            if (j-i >= 0) {
                dp[i%2][j] = max(dp[(i-1)%2][j], dp[i%2][j-i] + A[i-1]);
            }
            else {
                dp[i%2][j] = dp[(i-1)%2][j];
            }
        }
    }
    return dp[len%2][len];
}
