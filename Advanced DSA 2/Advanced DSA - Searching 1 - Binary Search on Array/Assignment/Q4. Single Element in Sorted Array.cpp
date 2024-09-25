/*
Problem Description
Given a sorted array of integers A where every element appears twice except for one element which appears once, find and return this single element that appears only once.

Elements which are appearing twice are adjacent to each other.

NOTE: Users are expected to solve this in O(log(N)) time.



Problem Constraints
1 <= |A| <= 100000

1 <= A[i] <= 10^9



Input Format
The only argument given is the integer array A.



Output Format
Return the single element that appears only once.



Example Input
Input 1:

A = [1, 1, 7]
Input 2:

A = [2, 3, 3]


Example Output
Output 1:

 7
Output 2:

 2


Example Explanation
Explanation 1:

 7 appears once
Explanation 2:

 2 appears once


*/

int Solution::solve(vector<int> &A) {
    
    if (A.size() == 1 || A[0] != A[1]) return A[0];
    if (A[A.size()-1] != A[A.size()-2]) return A[A.size()-1];

    int start = 0;
    int end = A.size() - 1;

    while (start <= end) {
        int mid = start + (end - start)/2;

        if (A[mid] != A[mid-1] && A[mid] != A[mid+1]) return A[mid];
        if (A[mid] == A[mid-1]) mid = mid - 1;
        
        if (mid % 2 == 0) start = mid + 2;
        else end = mid - 1;
    } 
    
    return A[start];
}


