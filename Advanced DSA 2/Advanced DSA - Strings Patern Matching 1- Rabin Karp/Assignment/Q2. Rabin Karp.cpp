/*
Problem Description

Given two string A and B of length N and M respectively consisting of lowercase letters. Find the number of occurrences of B in A.


Problem Constraints

1 <= M <= N <= 105



Input Format

Two argument A and B are strings


Output Format

Return an integer denoting the number of occurrences of B in A


Example Input

Input 1:
A = "acbac"
B = "ac"
Input 2:
A = "aaaa"
B = "aa"


Example Output

Output 1:
2
Output 2:
3


Example Explanation

For Input 1:
The string "ac" occurs twice in "acbac".
For Input 2:
The string "aa" occurs thrice in "aaaa".
*/

int Solution::solve(string A, string B) {
    int ans = 0;
    int hash_B = 0;
    int hash_A = 0;
    int p = 1;
    int m = 1e9+7;

    for (int i =0; i < B.size()-1; i++) {
        hash_B = (hash_B*29 + (B[i] -'a')) % m;
        hash_A = (hash_A*29 + (A[i] -'a')) % m;

        p = (p*29) % m;
    }

    hash_B = (hash_B*29 + (B[B.size()-1] -'a')) % m;
    hash_A = (hash_A*29 + (A[B.size()-1] -'a')) % m;

    if (hash_A == hash_B) ans++;


    for (int j = B.size(); j < A.size(); j++) {
        hash_A = ((hash_A - p * (A[j-B.size()]-'a')) * 29 + (A[j]-'a') + m ) % m;
        if (hash_A == hash_B) ans++; 
    }

    return ans;
}
