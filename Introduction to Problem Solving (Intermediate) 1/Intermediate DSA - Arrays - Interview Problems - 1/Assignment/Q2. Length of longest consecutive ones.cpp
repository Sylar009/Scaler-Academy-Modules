/*
Given a binary string A. It is allowed to do at most one swap between any 0 and 1. Find and return the length of the longest consecutive 1’s that can be achieved.


Input Format

The only argument given is string A.
Output Format

Return the length of the longest consecutive 1’s that can be achieved.
Constraints

1 <= length of string <= 1000000
A contains only characters 0 and 1.
For Example

Input 1:
    A = "111000"
Output 1:
    3

Input 2:
    A = "111011101"
Output 2:
    7
*/

int Solution::solve(string A) {
    int ans = 0;
    int count  = 0;
    for (char a : A) if (a == '1') count++;

    if (count == A.size()) return count;

    int left = 0;
    int right = 0;

    for(int i = 0; i < A.size(); i++ ) {
        if (A[i] == '0') {
            int left = 0;
            for (int j = i-1; j >=0; j--)
                if (A[j] == '1') left++;
                else break;
            
            int right = 0;
            for (int k = i+1; k < A.size(); k++)
                if (A[k] == '1') right++;
                else break;

            if (count > (left + right)) ans = max (ans, (left + right +1));
            else ans = max (ans, (left + right));
        }        
    }

    return ans;
}
