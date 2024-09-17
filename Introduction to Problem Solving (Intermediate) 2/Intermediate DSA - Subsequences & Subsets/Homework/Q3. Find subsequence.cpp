/*
Given two strings A and B, find if A is a subsequence of B.

Return "YES" if A is a subsequence of B, else return "NO".


Input Format

The first argument given is the string A.
The second argument given is the string B.
Output Format

Return "YES" if A is a subsequence of B, else return "NO".
Constraints

1 <= lenght(A), length(B) <= 100000
'a' <= A[i], B[i] <= 'z'
For Example

Input 1:
    A = "bit"
    B = "dfbkjijgbbiihbmmt"
Output 1:
    YES

Input 2:
    A = "apple"
    B = "appel"
Output 2:
    "NO"
*/

string Solution::solve(string A, string B) {
    if (A.size() == 0) return "YES";
    bool isSubseq = true;
    int j = 0;
    for (int i = 0; i < B.size() && j < A.size(); i++) {
        if(A[j] == B[i]) j++;
    }
    
    return (A.size() == j) ? "YES" : "NO";
}
