/*
Problem Description

Given two sequences A and B, count number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.

Subsequence : A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).



Problem Constraints

1 <= length(A), length(B) <= 700



Input Format

The first argument of input contains a string A.
The second argument of input contains a string B.



Output Format

Return an integer representing the answer as described in the problem statement.



Example Input

Input 1:

 A = "abc"
 B = "abc"
Input 2:

 A = "rabbbit" 
 B = "rabbit" 


Example Output

Output 1:

 1
Output 2:

 3


Example Explanation

Explanation 1:

 Both the strings are equal.
Explanation 2:

 These are the possible removals of characters:
    => A = "ra_bbit" 
    => A = "rab_bit" 
    => A = "rabb_it"

 Note: "_" marks the removed character.


*/

int Solution::numDistinct(string A, string B) {

    if(B.size() > A.size()){
        return 0;
    }
    
    vector<vector<int> > dp(B.size() + 1, vector<int>(A.size() + 1, 0));
    
    for(int i = 0; i <= A.size(); i++){
        dp[0][i] = 1;
    }
    
    for(int i = 1; i <= B.size(); i++){
        for(int j = i; j <= A.size(); j++){
            if(A[j-1] == B[i-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
            }
            else{
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    
    return dp[B.size()][A.size()];
}
