/*
Problem Description

Given A, B, C find whether C is formed by the interleaving of A and B.



Problem Constraints

1 <= length(A), length(B) <= 100

1 <= length(C) <= 200



Input Format

The first argument of input contains a string, A.
The second argument of input contains a string, B.
The third argument of input contains a string, C.



Output Format

Return 1 if string C is formed by interleaving of A and B else 0.



Example Input

Input 1:

 A = "aabcc"
 B = "dbbca"
 C = "aadbbcbcac"
Input 2:

 A = "aabcc"
 B = "dbbca"
 C = "aadbbbaccc"


Example Output

Output 1:

 1
Output 2:

 0


Example Explanation

Explanation 1:

 "aa" (from A) + "dbbc" (from B) + "bc" (from A) + "a" (from B) + "c" (from A)



Explanation 2:

 It is not possible to get C by interleaving A and B.


*/

int Solution::isInterleave(string A, string B, string C) {
    vector<vector< bool> > dp(A.size()+1, vector<bool>(B.size()+1, false));
    dp[0][0] = true;

    for (int i = 1; i <= A.size(); i++) {
        dp[i][0] = (C[i-1] == A[i-1] && dp[i-1][0] == true) ? true : false;
    }

    for (int i = 1; i <= B.size(); i++) {
        dp[0][i] = (C[i-1] == B[i-1] && dp[0][i-1] == true) ? true : false;
    }

    for (int i = 1; i <= A.size(); i++) {
        for (int j = 1; j <= B.size(); j++) {
            dp[i][j] = (C[i+j-1] == A[i-1] && dp[i-1][j] == true)
                            ? true 
                            : (C[i+j-1] == B[j-1] && dp[i][j-1] == true)
                                        ? true 
                                        : false;
        }
    }

    return dp[A.size()][B.size()];
}
