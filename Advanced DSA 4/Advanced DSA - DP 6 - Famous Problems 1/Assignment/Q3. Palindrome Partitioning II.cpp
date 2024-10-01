/*
Problem Description

Given a string A, partition A such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of A.



Problem Constraints

1 <= length(A) <= 501



Input Format

The first and the only argument contains the string A.



Output Format

Return an integer, representing the minimum cuts needed.



Example Input

Input 1:

 A = "aba"
Input 2:

 A = "aab"


Example Output

Output 1:

 0
Output 2:

 1


Example Explanation

Explanation 1:

 "aba" is already a palindrome, so no cuts are needed.
Explanation 2:

 Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

void check_pal(string A, vector<vector<int> > &B) {
    for (int i = 1; i <= A.size(); i++) {
        for (int j = 0; j < A.size(); j++) {
            int k = i + j -1;
            if (k >= A.size()) break;
            if (i == 1) B[j][k] = 1;
            else if (i == 2) {
                if (A[j] == A[k]) B[j][k] = 1;
                else B[j][k] = 0;
            }
            else B[j][k] = (A[j] == A[k]) && B[j+1][k-1];
        }
    }
}

void pal_part(string A, vector<vector<int> > &B, vector<int> &C) {
    for (int i = 0; i < A.size(); i++) {
        if (B[0][i] == 1) C[i] = 0;
        else {
            C[i] = INT_MAX;
            for (int j = 0; j < i; j++) {
                if (B[j+1][i] == 1 && (1 + C[j]) < C[i]) C[i] = 1 + C[j];
            }
        }
    }
}
int Solution::minCut(string A) {
    vector<vector<int> > dp(A.size(), vector<int>(A.size(), -1));
    check_pal(A,dp);
    vector<int> dp_part(A.size(), -1);
    pal_part(A, dp, dp_part);

    return dp_part[A.size()-1];
}
