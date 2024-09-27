/*
Problem Description

Given string A denoting an infix expression. Convert the infix expression into a postfix expression.


String A consists of ^, /, *, +, -, (, ) and lowercase English alphabets where lowercase English alphabets are operands and ^, /, *, +, - are operators.

Find and return the postfix expression of A.

NOTE:

^ has the highest precedence.
/ and * have equal precedence but greater than + and -.
+ and - have equal precedence and lowest precedence among given operators.



Problem Constraints

1 <= length of the string <= 500000



Input Format

The only argument given is string A.



Output Format

Return a string denoting the postfix conversion of A.



Example Input

Input 1:

 A = "x^y/(a*z)+b"
Input 2:

 A = "a+b*(c^d-e)^(f+g*h)-i"


Example Output

Output 1:

 "xy^az*`/b+"
Output 2:

 "abcd^e-fgh*+^*+i-"


Example Explanation

Explanation 1:

 Ouput dentotes the postfix expression of the given input.


*/

int prec(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

string infixToPostfix (string A) {
    stack<char> st;
    st.push('N');
    string res;
    for (int i = 0; i < A.size(); i++) {
        if ((A[i] >= 'a' && A[i] <= 'z') || (A[i] >= 'A' && A[i] <= 'Z')) res += A[i];
        else if (A[i] == '(') st.push('(');
        else if (A[i] == ')') {
            while (st.top() != 'N' && st.top() != '(') {
                char c = st.top();
                st.pop();
                res += c;
            }
            if (st.top() =='(') {
                char c = st.top();
                st.pop();
            }
        }
        else {
            while (st.top() != 'N' && prec(A[i]) <= prec(st.top())) {
                char c = st.top();
                st.pop();
                res += c;
            }
            st.push(A[i]);
        }
    }

    while (st.top() != 'N') {
        char c = st.top();
        st.pop();
        res += c;
    }

    return res;
}


string Solution::solve(string A) {
    return infixToPostfix(A);
}

