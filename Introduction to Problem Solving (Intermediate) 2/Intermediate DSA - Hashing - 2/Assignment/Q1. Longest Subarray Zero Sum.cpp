/*
Problem Description
Given an array A of N integers.
Find the length of the longest subarray in the array which sums to zero.

If there is no subarray which sums to zero then return 0.



Problem Constraints
1 <= N <= 105
-109 <= A[i] <= 109


Input Format
Single argument which is an integer array A.


Output Format
Return an integer.


Example Input
Input 1:

 A = [1, -2, 1, 2]
Input 2:

 A = [3, 2, -1]


Example Output
Output 1:

3
Output 2:

0


Example Explanation
Explanation 1:

 [1, -2, 1] is the largest subarray which sums up to 0.
Explanation 2:

 No subarray sums up to 0.

*/

int Solution::solve(vector<int> &A) {
    int ans = 0;
    long sum = 0;

    unordered_map<long,int> hm;
    for (int i = 0; i < A.size(); i++) {
        sum += A[i];
        if (sum == 0) ans = max(ans, i+1);
        else if (hm.find(sum) != hm.end()) ans = max(ans,i-hm[sum]);
        else hm[sum] = i;
    }

    return ans;
}
