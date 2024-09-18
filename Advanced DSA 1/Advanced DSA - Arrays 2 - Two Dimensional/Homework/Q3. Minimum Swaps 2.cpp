/*
Problem Description
Given an array of integers A of size N that is a permutation of [0, 1, 2, ..., (N-1)].

It is allowed to swap any two elements (not necessarily consecutive).

Find the minimum number of swaps required to sort the array in ascending order.



Problem Constraints
1 <= N <= 100000
0 <= A[i] < N



Input Format
The only argument given is the integer array A.



Output Format
Return the minimum number of swaps.



Example Input
Input 1:

A = [1, 2, 3, 4, 0]
Input 2:

A = [2, 0, 1, 3]


Example Output
Output 1:

4
Output 2:

2


Example Explanation
Explanation 1:

There are many ways, to make the array sorted,
 
One of the sequence of swaps as follow: 
    Initial array   ->   [1, 2, 3, 4, 0]
 swapping (1, 2) becomes [2, 1, 3, 4, 0]
 swapping (2, 3) becomes [3, 1, 2, 4, 0]
 swapping (4, 0) becomes [3, 1, 2, 0, 4]
 swapping (3, 0) becomes [0, 1, 2, 3, 4]. 
Thus the array is sorted in 4 swaps.  It cannot be sorted inlesser than 4 swaps.  
Explanation 2:

One of the sequence of swaps as follow: 
    Initial array  ->    [2, 0, 1, 3]
 swapping (2, 0) becomes [0, 2, 1, 3]
 swapping (1, 2) becomes [0, 1, 2, 3].
 
Thus the array is sorted in 2 swaps. It cannot be sorted in lesser than 4 swaps. 

*/

int Solution::solve(vector<int> &A) {
    int count = 0;
    int i = 0;
    while (i < A.size()) {
        if (A[i] == i) i++;
        else {
            int val = A[i];
            swap(A[i], A[val]);
            count++;
        }
    }

    return count;
}
