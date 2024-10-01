/*
Problem Description

Given two strings A and B. Find the longest common subsequence ( A sequence which does not need to be contiguous), which is common in both the strings.

You need to return the length of such longest common subsequence.



Problem Constraints

1 <= Length of A, B <= 1005



Input Format

First argument is a string A.
Second argument is a string B.



Output Format

Return an integer denoting the length of the longest common subsequence.



Example Input

Input 1:

 A = "abbcdgf"
 B = "bbadcgf"
Input 2:

 A = "aaaaaa"
 B = "ababab"


Example Output

Output 1:

 5
Output 2:

 3


Example Explanation

Explanation 1:

 The longest common subsequence is "bbcgf", which has a length of 5.
Explanation 2:

 The longest common subsequence is "aaa", which has a length of 3.

*/

int Solution::solve(string A, string B) {
    vector<vector<int> > dp (A.size()+1, vector<int>(B.size()+1,-1));
    for (int i = 0; i <= A.size(); i++) {
        for (int j = 0; j<= B.size(); j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
            else if (A[i-1] == B[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[A.size()][B.size()];
}
