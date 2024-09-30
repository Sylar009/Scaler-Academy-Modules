/*
Problem Description

Find out the number of A digit positive numbers, whose digits on being added equals to a given number B.

Note that a valid number starts from digits 1-9 except the number 0 itself. i.e. leading zeroes are not allowed.

Since the answer can be large, output answer modulo 1000000007



Problem Constraints

1 <= A <= 1000

1 <= B <= 10000



Input Format

First argument is the integer A

Second argument is the integer B



Output Format

Return a single integer, the answer to the problem



Example Input

Input 1:

 A = 2
 B = 4
Input 2:

 A = 1
 B = 3


Example Output

Output 1:

 4
Output 2:

 1


Example Explanation

Explanation 1:

 Valid numbers are {22, 31, 13, 40}
 Hence output 4.
Explanation 2:

 Only valid number is 3
*/

int Solution::solve(int A, int B) {
    vector<int> curr(B+1, 0);
    vector<int> prev(B+1, 0);
    prev[0] = 1;
    curr[0] = 1;

    for (int i = 1; i <= A; i++) {
        for (int j = 1; j <= B; j++) {
            int res = 0;
            for (int k = 0; k <= min(9, j); k++) {
                if (i == A && k == 0) continue;
                res = (res + prev[j-k])% 1000000007;
            }
            curr[j] = res;
        }
        prev = curr;
    }
    return prev[B];
}
