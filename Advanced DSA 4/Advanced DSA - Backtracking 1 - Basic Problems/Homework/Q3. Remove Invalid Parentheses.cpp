/*
Problem Description

Given a string A consisting of lowercase English alphabets and parentheses '(' and ')'. Remove the minimum number of invalid parentheses in order to make the input string valid.

Return all possible results.

You can return the results in any order.



Problem Constraints

1 <= length of the string <= 20



Input Format

The only argument given is string A.



Output Format

Return all possible strings after removing the minimum number of invalid parentheses.



Example Input

Input 1:

 A = "()())()"
Input 2:

 A = "(a)())()"


Example Output

Output 1:

 ["()()()", "(())()"]
Output 2:

 ["(a)()()", "(a())()"]


Example Explanation

Explanation 1:

 By removing 1 parentheses we can make the string valid.
        1. Remove the parentheses at index 4 then string becomes : "()()()"
        2. Remove the parentheses at index 2 then string becomes : "(())()"
Explanation 2:

 By removing 1 parentheses we can make the string valid.
        1. Remove the parentheses at index 5 then string becomes : "(a)()()"
        2. Remove the parentheses at index 2 then string becomes : "(a())()"
*/
int get_invalid_para(string A) {
    int open = 0;
    int count = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] =='(') open++;
        else if (A[i] ==')' ){
            if (open == 0) count++; 
            else open --;
        }
    }

    return open+count;
}

void helper(string A, int n, int index, int remove, int open, string temp, set<string>&res) {
    if (index == n) {
        if (remove == 0 && open == 0) {
            res.insert(temp);
        }
        return;
    }

    if (A[index] =='(') {
        helper(A, n, index+1, remove, open+1, temp+'(', res);
        helper(A, n, index+1, remove-1, open, temp, res);
    }
    else if (A[index] == ')') {
        if (open > 0) {
            helper(A, n, index+1, remove, open-1, temp+')', res);
        }
        helper(A, n, index+1, remove-1, open, temp, res);
    }
    else {
        helper(A, n, index+1, remove, open, temp+A[index], res);
    }
}

vector<string> Solution::solve(string A) {
    int min_paran = get_invalid_para(A);
    set<string> res; 
    helper(A, A.size(), 0, min_paran, 0, "", res);
    vector<string> ans;
    for (auto it : res) ans.push_back(it);
    return ans;
}
