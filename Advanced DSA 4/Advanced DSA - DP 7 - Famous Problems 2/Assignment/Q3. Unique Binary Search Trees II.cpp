/*
Problem Description

Given an integer A, how many structurally unique BST's (binary search trees) exist that can store values 1...A?



Problem Constraints

1 <= A <=18



Input Format

First and only argument is the integer A



Output Format

Return a single integer, the answer to the problem



Example Input

Input 1:

 1
Input 2:

 2


Example Output

Output 1:

 1
Output 2:

 2


Example Explanation

Explanation 1:

 Only single node tree is possible.
Explanation 2:

 2 trees are possible, one rooted at 1 and other rooted at 2.


*/

int Solution::numTrees(int A) {
    vector<int> dp(A+1, 1);
    int sum = 0;
    for (int i = 2; i <= A; i++) {
        sum = 0;
        for (int j =1; j <=i; j++) {
            int left = j - 1;
            int right = i - j;
            sum += dp[left] * dp[right];
        }
        dp[i] = sum;
    }
    return dp[A];
}
