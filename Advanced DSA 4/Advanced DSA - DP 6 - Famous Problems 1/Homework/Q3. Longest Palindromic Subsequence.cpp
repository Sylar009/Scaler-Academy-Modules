/*
Problem Description

Given a string A. Find the longest palindromic subsequence (A subsequence which does not need to be contiguous and is a palindrome).

You need to return the length of longest palindromic subsequence.



Problem Constraints

1 <= length of(A) <= 103



Input Format

First and only integer is a string A.



Output Format

Return an integer denoting the length of longest palindromic subsequence.



Example Input

Input 1:

 A = "bebeeed"
Input 2:

 A = "aedsead"


Example Output

Output 1:

 4
Output 2:

 5


Example Explanation

Explanation 1:

 The longest palindromic subsequence is "eeee", which has a length of 4.
Explanation 2:

 The longest palindromic subsequence is "aedea", which has a length of 5.


*/

int Solution::solve(string A) {
    vector< vector< int> > dp (A.size(), vector<int>(A.size(),-1));
    for (int i = 0; i < A.size(); i++) {
        int j = 0;
        int k = j + i;
        while (k < A.size()) {
            if (A[j] == A[k]) dp[j][k] = (k-j <= 1 ? k-j+1 : dp[j+1][k-1]+2);
            else dp[j][k] = max(dp[j][k-1], dp[j+1][k]);
            j++;
            k++;
        } 
    }

    return dp[0][A.size()-1];
}
