/*
Problem Description
You are given two lowercase strings A and B each of length N. Return 1 if they are anagrams to each other and 0 if not.

Note : Two strings A and B are called anagrams to each other if A can be formed after rearranging the letters of B.


Problem Constraints
1 <= N <= 105
A and B are lowercase strings


Input Format
Both arguments A and B are a string.


Output Format
Return 1 if they are anagrams and 0 if not


Example Input
Input 1:
A = "cat"
B = "bat"
Input 2:
A = "secure"
B = "rescue"


Example Output
Output 1:
0
Output 2:
1


Example Explanation
For Input 1:
The words cannot be rearranged to form the same word. So, they are not anagrams.
For Input 2:
They are an anagram.


*/

int Solution::solve(string A, string B) {
    if (A.size() != B.size()) return 0;

    vector<int> count_arr_A(26,0);
    vector<int> count_arr_B(26,0);

    for (char a : A) if (a >=97 && a <= 122) count_arr_A[a-97]++;
    for (char b : B) if (b >=97 && b <= 122) count_arr_B[b-97]++;

    for (int i = 0; i < 26; i++) if(count_arr_A[i] != count_arr_B[i]) return 0;

    return 1;
}
