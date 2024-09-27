/*
Problem Description

Given an integer array A of size N. You have to generate it's all subarrays having a size greater than 1.


Then for each subarray, find Bitwise XOR of its maximum and second maximum element.

Find and return the maximum value of XOR among all subarrays.




Problem Constraints

2 <= N <= 105

1 <= A[i] <= 107



Input Format

The only argument is an integer array A.



Output Format

Return an integer, i.e., the maximum value of XOR of maximum and 2nd maximum element among all subarrays.



Example Input

Input 1:

 A = [2, 3, 1, 4]
Input 2:

 A = [1, 3]


Example Output

Output 1:

 7
Outnput 2:

 2


Example Explanation

Explanation 1:


 All subarrays of A having size greater than 1 are:
 Subarray            XOR of maximum and 2nd maximum no.
 1. [2, 3]           1
 2. [2, 3, 1]        1
 3. [2, 3, 1, 4]     7
 4. [3, 1]           2
 5. [3, 1, 4]        7
 6. [1, 4]           5
 So maximum value of Xor among all subarrays is 7.
Explanation 2:

 Only subarray is [1, 3] and XOR of maximum and 2nd maximum is 2.


*/

int Solution::solve(vector<int> &A) {
    int res = 0;

    stack<int> st;
    st.push(0);

    for(int i = 0; i < A.size(); i++) {
        while(!st.empty()) {
            res = max(res, A[st.top()] ^ A[i] );
        
            if (A[st.top() ] > A[i]) break;
            st.pop();
        }
        st.push(i);
    }

    return res;
}
