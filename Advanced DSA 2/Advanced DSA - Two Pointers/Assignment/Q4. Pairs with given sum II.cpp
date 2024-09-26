/*
Problem Description

Given a sorted array of integers (not necessarily distinct) A and an integer B, find and return how many pair of integers ( A[i], A[j] ) such that i != j have sum equal to B.

Since the number of such pairs can be very large, return number of such pairs modulo (109 + 7).



Problem Constraints

1 <= |A| <= 100000

1 <= A[i] <= 10^9

1 <= B <= 10^9



Input Format

The first argument given is the integer array A.

The second argument given is integer B.



Output Format

Return the number of pairs for which sum is equal to B modulo (10^9+7).



Example Input

Input 1:

A = [1, 1, 1]
B = 2
Input 2:

A = [1, 5, 7, 10]
B = 8


Example Output

Output 1:

 3
Output 2:

 1


Example Explanation

Explanation 1:

 The pairs of A[i] and A[j] which sum up to 2 are (0, 1), (0, 2) and (1, 2).
 There are 3 pairs.
Explanation 2:

 There is only one pair, such that i = 0, and j = 2 sums up to 8.


*/

int Solution::solve(vector<int> &A, int B) {
    int m = 1000000007;
    int i = 0;
    int j = A.size() -1;

    long ans = 0; 
    while (i < j) {
        long sum = A[i] + A[j];

        if (sum == B) {
            int num_i = A[i]; 
            int num_j = A[j];
            long count_1 = 0;
            long count_2 = 0;
            while (num_i == A[i]) {count_1++; i++;}
            if (i > j) {
                ans += (count_1 * (count_1-1)) / 2;
                break;
            }
            while (num_j == A[j]) {count_2++; j--;}

            ans += count_1 * count_2;
        }
        else if (sum > B) j--;
        else i++;
    }

    return ans % m;
}
