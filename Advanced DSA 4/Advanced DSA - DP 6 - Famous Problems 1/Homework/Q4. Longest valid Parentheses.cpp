/*
Problem Description

Given a string A containing just the characters '(' and ')'.

Find the length of the longest valid (well-formed) parentheses substring.



Problem Constraints

1 <= length(A) <= 750000



Input Format

The only argument given is string A.



Output Format

Return the length of the longest valid (well-formed) parentheses substring.



Example Input

Input 1:

 A = "(()"
Input 2:

 A = ")()())"


Example Output

Output 1:

 2
Output 2:

 4


Example Explanation

Explanation 1:

 The longest valid parentheses substring is "()", which has length = 2.
Explanation 2:

 The longest valid parentheses substring is "()()", which has length = 4.

*/

int Solution::longestValidParentheses(string A) {
    vector<int> dp(A.size());
    stack<int> st;
    for (int i = 0; i< A.size(); i++) {
        char c = A[i];
        if (c == '(') st.push(i);
        else {
            if (!st.empty()) {
                int idx = st.top();
                st.pop();
                int len = i - idx + 1;
                if (idx > 0) dp[i] = dp[idx-1] + len;
                else dp[i] = len;
            }
        }
    }

    int max_len = INT_MIN;
    for (int a : dp) max_len = max(max_len, a);

    return max_len; 
}
