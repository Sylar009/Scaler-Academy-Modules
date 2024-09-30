/*
Problem Description

Given an integer array A of size N. Find the contiguous subarray within the given array (containing at least one number) which has the largest product.

Return an integer corresponding to the maximum product possible.

NOTE: Answer will fit in 32-bit integer value.



Problem Constraints

1 <= N <= 5 * 105

-100 <= A[i] <= 100



Input Format

First and only argument is an integer array A.



Output Format

Return an integer corresponding to the maximum product possible.



Example Input

Input 1:

 A = [4, 2, -5, 1]
Input 2:

 A = [-3, 0, -5, 0]


Example Output

Output 1:

 8
Output 2:

 0


Example Explanation

Explanation 1:

 We can choose the subarray [4, 2] such that the maximum product is 8.
Explanation 2:

 0 will be the maximum product possible.

*/

int Solution::maxProduct(const vector<int> &A) {
    int res = A[0];
    int max_val = res;
    int min_val = res;

    for (int i = 1; i < A.size(); i++) {
        if (A[i] < 0) swap (max_val , min_val);

        max_val = max(A[i], max_val*A[i]);
        min_val = min(A[i], min_val*A[i]);

        res = max(res, max_val);
    }

    return res;
}
