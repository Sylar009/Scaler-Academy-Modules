/*
Problem Description

Given an array A of N integers, find three integers in A such that the sum is closest to a given number B. Return the sum of those three integers.

Assume that there will only be one solution.



Problem Constraints

-108 <= B <= 108
1 <= N <= 104
-108 <= A[i] <= 108


Input Format

First argument is an integer array A of size N.

Second argument is an integer B denoting the sum you need to get close to.



Output Format

Return a single integer denoting the sum of three integers which is closest to B.



Example Input

Input 1:

A = [-1, 2, 1, -4]
B = 1
Input 2:

 
A = [1, 2, 3]
B = 6


Example Output

Output 1:

2
Output 2:

6


Example Explanation

Explanation 1:

 The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)
Explanation 2:

 Take all elements to get exactly 6.


*/

int Solution::threeSumClosest(vector<int> &A, int B) {
    if (A.size() < 3) -1;
    sort(A.begin(), A.end());
    int difference = INT_MAX;
    int res = A[0] + A[1] + A[2];

    for (int i =0; i < A.size(); i++) {
        int x = i + 1; 
        int y = A.size() - 1;

        while (x < y) {
            int sum = A[i] + A[x] + A[y];
            if (sum < B) {
                if (difference > (B-sum)) {
                    difference = B - sum;
                    res = sum;
                }
                x++;
            }
            else if (sum > B) {
                if (difference > (sum - B)) {
                    res = sum;
                    difference = sum - B;
                }
                y--;
            }

            else return B;
        }
    }

    return res;
}
