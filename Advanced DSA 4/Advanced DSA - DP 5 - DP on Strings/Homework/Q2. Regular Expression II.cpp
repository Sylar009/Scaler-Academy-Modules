/*
Problem Description

Implement wildcard pattern matching with support for ' ? ' and ' * ' for strings A and B.

' . ' : Matches any single character.
' * ' : Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).



Problem Constraints

1 <= length(A), length(B) <= 104



Input Format

The first argument of input contains a string A.
The second argument of input contains a string B denoting the pattern.



Output Format

Return 1 if the patterns match else return 0.



Example Input

Input 1:

 A = "aab"
 B = "c*a*b"
Input 2:

 A = "acz"
 B = "a.a"


Example Output

Output 1:

 1
Output 2:

 0


Example Explanation

Explanation 1:

 'c' can be repeated 0 times, 'a' can be repeated 1 time. Therefore, it matches "aab".
 So, return 1.
Explanation 2:

 '.' matches any single character. First two character in string A will be match. 
 But the last character i.e 'z' != 'a'. Return 0.

*/

int Solution::isMatch(const string A, const string B) {
    vector<int> prev(B.size() + 1, 0);
    prev[0] = 1;
    for(int j = 1; j <= B.size(); j++){
        if(B[j-1] == '.') prev[j] = 0;
        else if(B[j-1] == '*') prev[j] = (j-2>=0)? prev[j-2]:0;
        else prev[j] = 0;
    }
    vector<int> curr(B.size() + 1, 0);
    for(int i = 1; i <= A.size(); i++){
        curr[0] = 0;
        for(int j = 1; j <= B.size(); j++){
            if(A[i-1] == B[j-1]) curr[j] = prev[j-1];
            else{
                if(B[j-1] == '.') curr[j] = prev[j-1];
                else if(B[j-1] == '*'){
                    if(j-2>=0){
                        if(B[j-2] == A[i-1]) curr[j] = curr[j-2]||prev[j];
                        else{
                            if(B[j-2] == '.') curr[j] = prev[j]||curr[j-2];
                            else curr[j] = curr[j-2];
                        }
                    }
                }
                else curr[j] = 0;
            }
        }
        prev = curr;
    }
    return prev[B.size()];
}
