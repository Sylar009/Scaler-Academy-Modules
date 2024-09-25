/*
Problem Description
Given an array of integers A of size N and an integer B.

In a single operation, any one element of the array can be increased by 1. You are allowed to do at most B such operations.

Find the number with the maximum number of occurrences and return an array C of size 2, where C[0] is the number of occurrences, and C[1] is the number with maximum occurrence.
If there are several such numbers, your task is to find the minimum one.



Problem Constraints
1 <= N <= 105

-109 <= A[i] <= 109

0 <= B <= 109



Input Format
The first argument given is the integer array A.
The second argument given is the integer B.



Output Format
Return an array C of size 2, where C[0] is number of occurence and C[1] is the number with maximum occurence.



Example Input
Input 1:

 A = [3, 1, 2, 2, 1]
 B = 3
Input 2:

 A = [5, 5, 5]
 B = 3


Example Output
Output 1:

 [4, 2]
Output 2:

 [3, 5]


Example Explanation
Explanation 1:

 Apply operations on A[2] and A[4]
 A = [3, 2, 2, 2, 2]
 Maximum occurence =  4
 Minimum value of element with maximum occurence = 2
Explanation 2:

 A = [5, 5, 5]
 Maximum occurence =  3
 Minimum value of element with maximum occurence = 5
*/

vector<int> Solution::solve(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    vector<long> pf;
    pf.push_back(A[0]);
    for (int i = 1; i < A.size(); i++){
        pf.push_back(A[i]+pf[i-1]);
    }
    
    int max_occ = INT_MIN;
    int max_val = 0;

    for (int i = 1; i < A.size(); i++) {
        int start = 1;
        int end = i+1;

        while (start <= end) {
            int mid = ((start+end) >> 1);

            long x = A[i];
            long y = pf[i];
            long z = (i - mid) < 0 ? 0 : pf[i-mid];

            long num = (mid * x) - (y - z);

            if(num <= B) {
                if (mid > max_occ) {
                    max_occ = mid;
                    max_val = A[i];
                }
                start = mid + 1;
            } else { 
                end = mid - 1;
            }
        }
    }

    return {max_occ, max_val};
}
