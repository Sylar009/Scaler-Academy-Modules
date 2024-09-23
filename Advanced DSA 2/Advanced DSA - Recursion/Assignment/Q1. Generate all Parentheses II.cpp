/*
Problem Description
Given an integer A pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*A.



Problem Constraints
1 <= A <= 10



Input Format
First and only argument is integer A.



Output Format
Return a sorted list of all possible parenthesis.



Example Input
Input 1:

A = 3
Input 2:

A = 1


Example Output
Output 1:

[ "((()))", "(()())", "(())()", "()(())", "()()()" ]
Output 2:

[ "()" ]


Example Explanation
Explanation 1:

 All paranthesis are given in the output list.
Explanation 2:

 All paranthesis are given in the output list.

*/

void generateParenthesisHelper (int A, int B, string S, vector<string> &res) {
    if (A < 0 || B < 0) return;
    if (A == 0 && B == 0) {
        res.push_back(S);
        return;
    }

    if (A == B) generateParenthesisHelper(A-1, B, S+"(", res);
    else {
        generateParenthesisHelper(A-1, B, S+"(", res);
        generateParenthesisHelper(A, B-1, S+")", res);
    }
}
vector<string> Solution::generateParenthesis(int A) {
    vector< string > res;
    generateParenthesisHelper(A, A, "", res);

    return res;
}
