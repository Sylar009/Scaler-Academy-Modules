/*
Problem Description
You are given an integer array C of size A. Now you need to find a subarray (contiguous elements) so that the sum of contiguous elements is maximum.
But the sum must not exceed B.


Problem Constraints
1 <= A <= 103
1 <= B <= 109
1 <= C[i] <= 106


Input Format
The first argument is the integer A.
The second argument is the integer B.
The third argument is the integer array C.


Output Format
Return a single integer which denotes the maximum sum.


Example Input
Input 1:
A = 5
B = 12
C = [2, 1, 3, 4, 5]
Input 2:

A = 3
B = 1
C = [2, 2, 2]


Example Output
Output 1:
12
Output 2:

0
*/

int Solution::maxSubarray(int A, int B, vector<int> &C) {
    int maxSum = 0;
    for (int i = 0; i < A; i++) {
        int sum = 0;
        for (int j = i; j < A; j++) {
            sum += C[j];
            int temp = max(maxSum, sum);
            maxSum = (temp <= B) ? temp : maxSum;
        }
    }

    return maxSum;
}
