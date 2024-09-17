/*
Problem Description

Little Ponny has been given a string A, and he wants to find out the lexicographically minimum subsequence from it of size >= 2. Can you help him?

A string a is lexicographically smaller than string b, if the first different letter in a and b is smaller in a. For example, "abc" is lexicographically smaller than "acc" because the first different letter is 'b' and 'c' which is smaller in "abc".

 



Problem Constraints

1 <= |A| <= 105

A only contains lowercase alphabets.



Input Format

The first and the only argument of input contains the string, A.



Output Format

Return a string representing the answer.



Example Input

Input 1:

 A = "abcdsfhjagj" 
Input 2:

 A = "ksdjgha" 


Example Output

Output 1:

 "aa" 
Output 2:

 "da" 


Example Explanation

Explanation 1:

 "aa" is the lexicographically minimum subsequence from A. 
Explanation 2:

 "da" is the lexicographically minimum subsequence from A. 

*/

string Solution::solve(string A) {
    char min_val = 'z';
    char max_val = 'z';

    int pos;
    for (int i = 0; i < A.size(); i++) {
        if ( ( A[i] < min_val) && (i != A.size() - 1) ) {
            pos = i;
            min_val = A[i];
        }

        if (( A[i] < max_val) && (i != 0)  && (i != pos)) 
            max_val = A[i];
    }
    string result = "";
    result += min_val;
    result += max_val;
    return result;
}
