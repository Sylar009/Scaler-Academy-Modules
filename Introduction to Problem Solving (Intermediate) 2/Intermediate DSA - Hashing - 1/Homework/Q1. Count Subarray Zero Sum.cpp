/*
Problem Description
Given an array A of N integers.

Find the count of the subarrays in the array which sums to zero. Since the answer can be very large, return the remainder on dividing the result with 109+7


Problem Constraints
1 <= N <= 105
-109 <= A[i] <= 109


Input Format
Single argument which is an integer array A.


Output Format
Return an integer.


Example Input
Input 1:

 A = [1, -1, -2, 2]
Input 2:

 A = [-1, 2, -1]


Example Output
Output 1:

3
Output 2:

1


Example Explanation
Explanation 1:

 The subarrays with zero sum are [1, -1], [-2, 2] and [1, -1, -2, 2].
Explanation 2:

 The subarray with zero sum is [-1, 2, -1].


*/
int Solution::solve(vector<int> &A) {
    vector<long long> pf_sum;

    long long total_sum = 0;
    int ans = 0;
    unordered_map<long long, long long> freq_map;
    freq_map[0] = 1;
    for(int a : A) {
        total_sum = (total_sum + a) % 1000000007;
        ans = (ans % 1000000007 + freq_map[total_sum] % 1000000007) % 1000000007;;
        freq_map[total_sum]++;        
    }

    return ans % 1000000007;    
}
