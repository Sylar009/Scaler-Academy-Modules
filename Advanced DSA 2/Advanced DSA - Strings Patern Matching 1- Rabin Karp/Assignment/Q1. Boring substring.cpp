/*
Problem Description

You are given a string A of lowercase English alphabets. Rearrange the characters of the given string A such that there is no boring substring in A.


A boring substring has the following properties:

Its length is 2.
Both the characters are consecutive, for example - "ab", "cd", "dc", "zy" etc.(If the first character is C then the next character can be either (C+1) or (C-1)).
Return 1 if it is possible to rearrange the letters of A such that there are no boring substrings in A else, return 0.




Problem Constraints

1 <= |A| <= 105



Input Format

The only argument given is a string A.



Output Format

Return 1 if it is possible to rearrange the letters of A such that there are no boring substrings in A else, return 0.



Example Input

Input 1:


 A = "abcd"
Input 2:

 A = "aab"





Example Output

Output 1:

 1
Output 2:

 0


Example Explanation

Explanation 1:

 String A can be rearranged into "cadb" or "bdac" 
Explanation 2:

 No arrangement of string A can make it free of boring substrings.

*/

int Solution::solve(string A) {
    int odd_min = INT_MAX;
    int odd_max = INT_MIN;
    int even_min = INT_MAX;
    int even_max = INT_MIN;

    for (int i = 0; i < A.size(); i++) {
        char c = A[i];
        if (c%2 ==0) {
            even_min = min(even_min, (int)c);
            even_max = max(even_max, (int)c);
        }
        else {
            odd_min = min(odd_min, (int)c);
            odd_max = max(odd_max, (int)c);
        }
    }

    if ( (odd_min != even_min+1) && (odd_min != even_min-1) ) return 1;
    if ( (odd_max != even_min+1) && (odd_max != even_min-1) ) return 1;
    if ( (odd_min != even_max+1) && (odd_min != even_max-1) ) return 1;
    if ( (odd_max != even_max+1) && (odd_max != even_max-1) ) return 1;

    return 0;
}
