/*
Problem Description
Given an array, arr[] of size N, the task is to find the count of array indices such that removing an element from these indices makes the sum of even-indexed and odd-indexed array elements equal.



Problem Constraints
1 <= N <= 105
-105 <= A[i] <= 105
Sum of all elements of A <= 109


Input Format
First argument contains an array A of integers of size N


Output Format
Return the count of array indices such that removing an element from these indices makes the sum of even-indexed and odd-indexed array elements equal.



Example Input
Input 1:
A = [2, 1, 6, 4]
Input 2:

A = [1, 1, 1]


Example Output
Output 1:
1
Output 2:

3


Example Explanation
Explanation 1:
Removing arr[1] from the array modifies arr[] to { 2, 6, 4 } such that, arr[0] + arr[2] = arr[1]. 
Therefore, the required output is 1. 
Explanation 2:

Removing arr[0] from the given array modifies arr[] to { 1, 1 } such that arr[0] = arr[1] 
Removing arr[1] from the given array modifies arr[] to { 1, 1 } such that arr[0] = arr[1] 
Removing arr[2] from the given array modifies arr[] to { 1, 1 } such that arr[0] = arr[1] 
Therefore, the required output is 3.
*/
int Solution::solve(vector<int> &A) {
    int res = 0;
    
    vector<int> pf_even;
    int sum1 = 0;

    vector<int> pf_odd;
    int sum2 = 0;
    for (int i = 0; i < A.size(); i++) {
        pf_even.push_back( (i % 2 == 0 ) ? sum1 += A[i] : sum1);
        pf_odd.push_back( (i % 2 == 0 ) ? sum2 : sum2 += A[i]);
    }

    for (int j = 0; j < A.size(); j++) {
        int sum_even = (j == 0) ?
        pf_odd[A.size() -1] - pf_odd[j] :
        pf_even[j-1] + pf_odd[A.size() -1] - pf_odd[j];

        int sum_odd = (j == 0) ? 
        pf_even[A.size() -1] - pf_even[j] :
        pf_odd[j-1] + pf_even[A.size() -1] - pf_even[j];

        if (sum_even == sum_odd) res++;
    }

    return res;
}
