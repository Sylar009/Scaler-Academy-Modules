/*
Problem Description

Implement wildcard pattern matching with support for ' ? ' and ' * ' for strings A and B.

' ? ' : Matches any single character.
' * ' : Matches any sequence of characters (including the empty sequence).



The matching should cover the entire input string (not partial).






Problem Constraints

1 <= length(A), length(B) <= 104



Input Format

The first argument of input contains a string A.
The second argument of input contains a string B.



Output Format

Return 1 if the patterns match else return 0.



Example Input

Input 1:

 A = "aaa"
 B = "a*"
Input 2:

 A = "acz"
 B = "a?a"


Example Output

Output 1:

 1
Output 2:

 0


Example Explanation

Explanation 1:

 Since '*' matches any sequence of characters. Last two 'a' in string A will be match by '*'.
 So, the pattern matches we return 1.
Explanation 2:

 '?' matches any single character. First two character in string A will be match. 
 But the last character i.e 'z' != 'a'. Return 0.


*/

int Solution::isMatch(const string A, const string B) {
    vector<vector<int> > dp(2, vector<int> (B.size()+1,2));
    dp[0][0] = 1;
    int flag = 0;

    for (int i = 1; i <= B.size(); i++) {
        if (B[i-1] == '*' && flag == 0 ) dp[0][i] = 1;
        else {
            flag = 1;
            dp[0][i] = 0;
        }
    }

    for (int i = 1; i <= A.size(); i++) {
        dp[i%2][0] = 0;
        for (int j = 1; j <= B.size(); j++) {
            if (A[i-1] == B[j-1]) dp[i%2][j] = dp[(i-1)%2][j-1];
            else {
                if (B[j-1] == '*') dp[i%2][j] = dp[(i-1)%2][j] || dp[i%2][j-1];
                else if (B[j-1] == '?') dp[i%2][j] = dp[(i-1)%2][j-1];
                else dp[i%2][j] = 0;
            }
        }
    }

    return dp[A.size()%2][B.size()];
}
