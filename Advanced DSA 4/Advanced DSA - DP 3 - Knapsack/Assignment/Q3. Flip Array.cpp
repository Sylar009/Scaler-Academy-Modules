/*
Problem Description

Given an array A of positive elements, you have to flip the sign of some of its elements such that the resultant sum of the elements of array should be minimum non-negative(as close to zero as possible).

Return the minimum number of elements whose sign needs to be flipped such that the resultant sum is minimum non-negative.



Problem Constraints

1 <= length of(A) <= 100

Sum of all the elements will not exceed 10,000.



Input Format

First and only argument is an integer array A.



Output Format

Return an integer denoting the minimum number of elements whose sign needs to be flipped.



Example Input

Input 1:

 A = [15, 10, 6]
Input 2:

 A = [14, 10, 4]


Example Output

Output 1:

 1
Output 2:

 1


Example Explanation

Explanation 1:

 Here, we will flip the sign of 15 and the resultant sum will be 1.
Explanation 2:

 Here, we will flip the sign of 14 and the resultant sum will be 0.
 Note that flipping the sign of 10 and 4 also gives the resultant sum 0 but flippings there sign are not minimum.
*/

int Solution::solve(const vector<int> &A) {
    int sum = 0;
    for (int i = 0; i < A.size(); i++) sum += A[i];

    int half_sum = sum /2;

    vector<vector<int> > dp(A.size()+1, vector<int>(half_sum+1, 0));

    for (int i = 1; i <= half_sum; i++) {
        dp[0][i] = INT_MAX-1;
    }

    for (int i = 1; i <= A.size(); i++)  {
        for (int j = 1; j<= half_sum; j++) {
            dp[i][j] = (j >= A[i-1]) ?
                 min( dp[i-1][j], dp[i-1][j-A[i-1]] + 1) :
                 dp[i-1][j];
        }
    }

    while (half_sum > 0 && dp[A.size()][half_sum] >= (INT_MAX-1)) half_sum--;

    return dp[A.size()][half_sum];
}
