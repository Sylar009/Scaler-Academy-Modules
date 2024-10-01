/*
Problem Description

Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character


Problem Constraints

1 <= length(A), length(B) <= 450



Input Format

The first argument of input contains a string, A.
The second argument of input contains a string, B.



Output Format

Return an integer, representing the minimum number of steps required.



Example Input

Input 1:

 A = "abad"
 B = "abac"
Input 2:

 A = "Anshuman"
 B = "Antihuman


Example Output

Output 1:

 1
Output 2:

 2


Example Explanation

Exlanation 1:

 A = "abad" and B = "abac"
 After applying operation: Replace d with c. We get A = B.
 
Explanation 2:

 A = "Anshuman" and B = "Antihuman"
 After applying operations: Replace s with t and insert i before h. We get A = B.


*/


int Solution::minDistance(string A, string B) {
    vector<vector<int> > dp(A.size()+1, vector<int>(B.size()+1, 0));

    for (int i = 0; i <= A.size(); i++) dp[i][0] = i;

    for (int i = 0; i <= B.size(); i++) dp[0][i] = i;

    for (int s = 1; s < A.size()+1; s++) {
        for (int e = 1; e < B.size()+1; e++) {
            if (A[s-1] == B[e-1]) dp[s][e] = dp[s-1][e-1];
            else dp[s][e] = 1 + min(dp[s-1][e-1], min(dp[s-1][e], dp[s][e-1]));
        }
    }

    return dp[A.size()][B.size()];
}
