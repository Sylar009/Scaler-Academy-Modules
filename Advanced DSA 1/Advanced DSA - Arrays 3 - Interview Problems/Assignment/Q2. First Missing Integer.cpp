/*
Problem Description
Given an unsorted integer array, A of size N. Find the first missing positive integer.

Note: Your algorithm should run in O(n) time and use constant space.



Problem Constraints
1 <= N <= 1000000

-109 <= A[i] <= 109



Input Format
First argument is an integer array A.



Output Format
Return an integer denoting the first missing positive integer.



Example Input
Input 1:

[1, 2, 0]
Input 2:

[3, 4, -1, 1]
Input 3:

[-8, -7, -6]


Example Output
Output 1:

3
Output 2:

2
Output 3:

1


Example Explanation
Explanation 1:

A = [1, 2, 0]
First positive integer missing from the array is 3.
Explanation 2:

A = [3, 4, -1, 1]
First positive integer missing from the array is 2.
Explanation 3:

A = [-8, -7, -6]
First positive integer missing from the array is 1.

*/

int Solution::firstMissingPositive(vector<int> &A) {
    int i = 0;
    while (i < A.size()) {
        int val = A[i];
        if (val > 0 && val <= A.size() && val != A[val-1]) swap(A[i], A[val-1]);
        else i++;
    }

    for (int j = 0; j < A.size(); j++) if (A[j] != j+1) return j+1;

    return A.size() + 1;
}
