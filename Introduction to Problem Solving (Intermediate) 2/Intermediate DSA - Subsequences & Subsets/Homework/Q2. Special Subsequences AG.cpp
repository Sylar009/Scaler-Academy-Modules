/*
Problem Description
You have given a string A having Uppercase English letters.

You have to find how many times subsequence "AG" is there in the given string.

NOTE: Return the answer modulo 109 + 7 as the answer can be very large.



Problem Constraints
1 <= length(A) <= 105



Input Format
First and only argument is a string A.



Output Format
Return an integer denoting the answer.



Example Input
Input 1:

 A = "ABCGAG"
Input 2:

 A = "GAB"


Example Output
Output 1:

 3
Output 2:

 0


Example Explanation
Explanation 1:

 Subsequence "AG" is 3 times in given string 
Explanation 2:

 There is no subsequence "AG" in the given string.


*/

int Solution::solve(string A) {
    int sum = 0;
    int mod = 1000000007;
    int a_count = 0;
    for (char a : A) {
        if (a == 'A') a_count++;
        else if (a == 'G' && a_count > 0) sum = (sum % mod + a_count % mod) % mod;
    }

    return sum % mod;
}
