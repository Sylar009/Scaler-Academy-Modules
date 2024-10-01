/*
Problem Description

Given a number A, return number of ways you can draw A chords in a circle with 2 x A points such that no 2 chords intersect.

Two ways are different if there exists a chord which is present in one way and not in other.
Return the answer modulo 109 + 7.



Problem Constraints

1 <= A <= 103



Input Format

The first and the only argument contains the integer A.



Output Format

Return an integer answering the query as described in the problem statement.



Example Input

Input 1:

 A = 1
Input 2:

 A = 2


Example Output

Output 1:

 1
Output 2:

 2


Example Explanation

Explanation 1:

 If points are numbered 1 to 2 in clockwise direction, then different ways to draw chords are: {(1-2)} only. So, we return 1.
Explanation 2:

 If points are numbered 1 to 4 in clockwise direction, then different ways to draw chords are:{(1-2), (3-4)} and {(1-4), (2-3)}.
 So, we return 2.

*/

int Solution::chordCnt(int A) {
    long long int dp[A+1];
    if( A == 0  || A == 1) return 1;
    else if( A == 2 ) return 2;
    else if( A > 2 ) {
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= A; i++){
            dp[i] = 0;
            for(int k = 0; k < i; k++){
                dp[i] = (dp[i] + dp[i-k-1] * dp[k] ) % 1000000007;
            }
        }
       
    }
    
    return dp[A] % 1000000007;
}
