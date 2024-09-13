/*
Problem Description
Given the array of strings A, you need to find the longest string S, which is the prefix of ALL the strings in the array.

The longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.

Example: the longest common prefix of "abcdefgh" and "abcefgh" is "abc".



Problem Constraints
0 <= sum of length of all strings <= 1000000



Input Format
The only argument given is an array of strings A.



Output Format
Return the longest common prefix of all strings in A.



Example Input
Input 1:

A = ["abcdefgh", "aefghijk", "abcefgh"]
Input 2:

A = ["abab", "ab", "abcd"];


Example Output
Output 1:

"a"
Output 2:

"ab"


Example Explanation
Explanation 1:

Longest common prefix of all the strings is "a".
Explanation 2:

Longest common prefix of all the strings is "ab".
*/

string Solution::longestCommonPrefix(vector<string> &A) {
    if (A.size() == 1) return A[0];
    else if (A.size() == 0) return "";

    string result = "";
    int min_len_str = INT_MAX;
    
    for (int i = 0; i < A.size(); i++) {
        int str_len = A[i].size();
        min_len_str = min(min_len_str, str_len);
    }

    int index = 0;
    while (index < min_len_str) {
        char a = A[0][index];
        bool flag = true;
        for (int j = 1; j < A.size(); j++) {
            if (a != A[j][index]) {
                flag = false;
                break;
            }
        }
        if (flag) result += a;
        else break;
        index++;
    }

    return result;
}
