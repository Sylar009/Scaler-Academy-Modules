/*
Problem Description

Given a string A made up of multiple brackets of type "[]" , "()" and "{}" find the length of the longest substring which forms a balanced string .

Conditions for a string to be balanced :

Blank string is balanced ( However blank string will not be provided as a test case ).
If B is balanced : (B) , [B] and {B} are also balanced.
If B1 and B2 are balanced then B1B2 i.e the string formed by concatenating B1 and B2 is also balanced.


Problem Constraints

0 <= |A| <= 106



Input Format

First and only argument is an string A.



Output Format

Return an single integer denoting the lenght of the longest balanced substring.



Example Input

Input 1:

 A = "[()]"
Input 2:

 A = "[(])"


Example Output

Output 1:

 4
Output 2:

 0


Example Explanation

Explanation 1:

 Substring [1:4] i.e "[()]" is the longest balanced substring of length 4.
Explanation 2:

 None of the substring is balanced so answer is 0.

*/

int Solution::LBSlength(const string A) {
    vector<int> dp(A.size());
    stack<pair<int, char> > st;
    int max_len = 0;
    for (int i = 0; i < A.size(); i++) {
        char c = A[i];
        if (c == '(') st.push(make_pair(i, ')'));
        else if (c == '{') st.push(make_pair(i, '}'));
        else if (c == '[') st.push(make_pair(i, ']'));
        else {
            if (!st.empty() && st.top().second == c) {
                pair<int, char> t = st.top(); 
                st.pop();
                int len = i - t.first+1;
                if (t.first > 0) dp[i] = len + dp[t.first-1];
                else dp[i] = len;

                max_len = max(max_len, dp[i]);
            }
            else st.push(make_pair(i, '/'));
        }
    }

    return max_len;
}
