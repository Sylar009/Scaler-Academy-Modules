/*
Problem Description

You are given an array A. You need to find the length of the Longest Increasing Subsequence in the array.

In other words, you need to find a subsequence of array A in which the elements are in sorted order, (strictly increasing) and as long as possible.



Problem Constraints

1 ≤ length(A), A[i] ≤ 105



Input Format

The first and only argument of the input is the array A.



Output Format

Output a single integer, the length of the longest increasing subsequence in array A.



Example Input

Input 1:

A: [2, 1, 4, 3]
Input 2:

A: [5, 6, 3, 7, 9]


Example Output

Output 1:

2
Output 2:

4


Example Explanation

Explanation 1:

 [2, 4] and [1, 3] are the longest increasing sequences of size 2. 
Explanation 2:

The longest increasing subsequence we can get is [5, 6, 7, 9] of size 4.


*/

int Solution::findLIS(vector<int> &A) {
    vector <int> lis;
    lis.push_back(A[0]);
    for (int i = 1; i < A.size(); i++) {
        if (A[i] > lis.back()) lis.push_back(A[i]);
        else {
            int idx = lower_bound(lis.begin(), lis.end(), A[i])-lis.begin();
            lis[idx] = A[i];
        }
    }

    return lis.size();
}
