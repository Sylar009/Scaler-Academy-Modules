/*
Problem Description

Given two strings A and B, determine if they are isomorphic.


A and B are called isomorphic strings if all occurrences of each character in A can be replaced with another character to get B and vice-versa.




Problem Constraints

1 <= |A| <= 100000

1 <= |B| <= 100000

A and B contain only lowercase characters.



Input Format

The first Argument is string A.


The second Argument is string B.




Output Format

Return 1 if strings are isomorphic, 0 otherwise.



Example Input

Input 1:

A = "aba"
B = "xyx"
Input 2:

A = "cvv"
B = "xyx"


Example Output

Output 1:

 1
Output 2:

 0


Example Explanation

Explanation 1:

 Replace 'a' with 'x', 'b' with 'y'.
Explanation 2:

 A cannot be converted to B.

*/

int Solution::solve(string A, string B) {
    if (A.size() != B.size() ) return 0;

    unordered_map<char, int> hm_a;
    unordered_map<char, int> hm_b;

    for (int i=0; i < A.size(); i++) {
        if (hm_a.find(A[i]) != hm_a.end()) hm_a[A[i]]++;
        else hm_a[A[i]] = 1;

        if (hm_b.find(B[i]) != hm_b.end()) hm_b[B[i]]++;
        else hm_b[B[i]] = 1;
    }

    for (int j =0; j < A.size(); j++) 
        if (hm_a[A[j]] != hm_b[B[j]]) return 0;

    return 1;
}
