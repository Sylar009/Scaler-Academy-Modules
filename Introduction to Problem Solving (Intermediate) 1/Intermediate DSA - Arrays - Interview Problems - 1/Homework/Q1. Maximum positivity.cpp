/*
Problem Description
Given an array of integers A, of size N.

Return the maximum size subarray of A having only non-negative elements. If there are more than one such subarray, return the one having the smallest starting index in A.

NOTE: It is guaranteed that an answer always exists.



Problem Constraints
1 <= N <= 105

-109 <= A[i] <= 109



Input Format
The first and only argument given is the integer array A.



Output Format
Return maximum size subarray of A having only non-negative elements. If there are more than one such subarrays, return the one having earliest starting index in A.



Example Input
Input 1:

 A = [5, 6, -1, 7, 8]
Input 2:

 A = [1, 2, 3, 4, 5, 6]


Example Output
Output 1:

 [5, 6]
Output 2:

 [1, 2, 3, 4, 5, 6]


Example Explanation
Explanation 1:

 There are two subarrays of size 2 having only non-negative elements.
 1. [5, 6]  starting point  = 0
 2. [7, 8]  starting point  = 3
 As starting point of 1 is smaller, return [5, 6]
Explanation 2:

 There is only one subarray of size 6 having only non-negative elements:
 [1, 2, 3, 4, 5, 6]
*/

vector<int> Solution::solve(vector<int> &A) {
    vector<int> result;
    
    int s = 0;
    int e = 0;

    int final_sp = 0;
    int final_ep = 0;

    int maxSubArrayLen = 0; 
    
    int count = 0;
    for (int a : A) if (a < 0) count++;
    if (count == A.size()) return result;

    while (e < A.size()){
        if (A[e] >= 0) { 
            e++;
            if (maxSubArrayLen < (e - s)) {
                maxSubArrayLen = (e - s);
                final_sp = s;
                final_ep = e-1;
            } 
        }
        else {
            s = e + 1;
            e = e + 1;
        }
    }

    while (final_sp <= final_ep) {
        result.push_back(A[final_sp]);
        final_sp++;
    }
    
    return result;
}
