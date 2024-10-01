/*
Given a string A consisting of lowercase English alphabets. Your task is to find how many substrings of A are palindrome.

The substrings with different start indexes or end indexes are counted as different substrings even if they consist of same characters.

Return the count of palindromic substrings.

Note: A string is palindrome if it reads the same from backward and forward.


Input Format

The only argument given is string A.
Output Format

Return the count of palindromic substrings.
Constraints

1 <= length of the array <= 1000
For Example

Input 1:
    A = "abab"
Output 1:
    6
Explanation 1:
    6 palindromic substrings are:
    "a", "aba", "b", "bab", "a" and "b".

Input 2:
    A = "ababa"
Output 2:
    9
Explanation 9:
    9 palindromic substrings are:
    "a", "a", "a", "b", "b" , "aba" ,"bab", "aba" and "ababa".
*/

int Solution::solve(string A) {
    int res = 0;
    vector<vector<bool> > dp(A.size(), vector<bool> (A.size(), false));

    for (int g = 0; g < A.size(); g++) {
        for (int i = 0, j = g; j < A.size(); i++, j++) {
            if (g == 0) dp[i][j] = true;
            else if (g == 1) dp[i][j] = (A[i] == A[j]);
            else dp[i][j] = (A[i] == A[j]) && (dp[i+1][j-1]);

            if (dp[i][j]) res++;
        }
    }

    return res;
}
