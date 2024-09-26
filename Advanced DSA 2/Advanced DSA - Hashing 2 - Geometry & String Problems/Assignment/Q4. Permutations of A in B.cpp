/*
Problem Description

You are given two strings, A and B, of size N and M, respectively.

You have to find the count of all permutations of A present in B as a substring. You can assume a string will have only lowercase letters.




Problem Constraints

1 <= N < M <= 105



Input Format

Given two arguments, A and B of type String.



Output Format

Return a single integer, i.e., number of permutations of A present in B as a substring.



Example Input

Input 1:

 A = "abc"
 B = "abcbacabc"
Input 2:

 A = "aca"
 B = "acaa"





Example Output

Output 1:

 5
Output 2:

 2


Example Explanation

Explanation 1:

 Permutations of A that are present in B as substring are:
    1. abc
    2. cba
    3. bac
    4. cab
    5. abc
    So ans is 5.
Explanation 2:

 Permutations of A that are present in B as substring are:
    1. aca
    2. caa 

*/

int Solution::solve(string A, string B) {
    if (B.size() < A.size() ) return 0;

    int left =0;
    int right = 0;
    int ans = 0;

    map<char, int> hm1;
    for (char a : A) {
        if(hm1.find(a) != hm1.end() ) hm1[a]++;
        else hm1[a] = 1;
    }

    map<char, int> hm2;
    while (right < B.size() ){
        if (hm1.find(B[right]) != hm1.end() ) hm2[B[right]]++;

        if (right - left + 1 == A.size()) {
            if (hm1 == hm2) ans++;
            if (hm2.find(B[left]) != hm2.end()) hm2[B[left]]--;
            left++;
        } 
        right++;
    }

    return ans;
}
