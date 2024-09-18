/*
Problem Description
Given 4 array of integers A, B, C and D of same size, find and return the maximum value of | A [ i ] - A [ j ] | + | B [ i ] - B [ j ] | + | C [ i ] - C [ j ] | + | D [ i ] - D [ j ] | + | i - j| where i != j and |x| denotes the absolute value of x.



Problem Constraints
2 <= length of the array A, B, C, D <= 100000
-106 <= A[i] <= 106



Input Format
The arguments given are the integer arrays A, B, C, D.



Output Format
Return the maximum value of | A [ i ] - A [ j ] | + | B [ i ] - B [ j ] | + | C [ i ] - C [ j ] | + | D [ i ] - D [ j ] | + | i - j|



Example Input
Input 1:

 A = [1, 2, 3, 4]
 B = [-1, 4, 5, 6]
 C = [-10, 5, 3, -8]
 D = [-1, -9, -6, -10]
Input 2:

 A = [1, 2]
 B = [3, 6]
 C = [10, 11]
 D = [1, 6]


Example Output
Output 1:

 30
Output 2:

 11


Example Explanation
Explanation 1:

 Maximum value occurs for i = 0 and j = 1.
Explanation 2:

There is only one possibility for i, j as there are only two elements in the array.

*/

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
    int ans = INT_MIN;
    int sign[2] = {1,-1};

    for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
            for (int c = 0; c < 2; c++) {
                for (int d = 0; d < 2; d++) {
                    int sum = 0;
                    int curr_max = INT_MIN;
                    int curr_min = INT_MAX;

                    for (int i =0; i < A.size(); i++) {
                        sum = sign[a]*A[i] + sign[b]*B[i] + sign[c]*C[i] + sign[d]*D[i] + i;
                        curr_max = max(curr_max, sum);
                        curr_min = min(curr_min, sum);

                        ans = max (ans, curr_max-curr_min);
                    }
                }
            }
        }
    }
    return ans;
}
