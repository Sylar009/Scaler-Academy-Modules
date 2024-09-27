/*
Given a 2D binary matrix of integers A containing 0's and 1's of size N x M.

Find the largest rectangle containing only 1's and return its area.

Note: Rows are numbered from top to bottom and columns are numbered from left to right.


Input Format

The only argument given is the integer matrix A.
Output Format

Return the area of the largest rectangle containing only 1's.
Constraints

1 <= N, M <= 1000
0 <= A[i] <= 1
For Example

Input 1:
    A = [   [0, 0, 1]
            [0, 1, 1]
            [1, 1, 1]   ]
Output 1:
    4

Input 2:
    A = [   [0, 1, 0, 1]
            [1, 0, 1, 0]    ]
Output 2:
    1
*/

int Solution::solve(vector<vector<int> > &A) {

    int n = A.size();
    if (n == 0) return 0;
    int m = A[0].size();

    vector<int> d(m, 0);
    vector<int> l(m, 0);
    vector<int> r(m, m-1);

    int max_val = INT_MIN;
    for (int i = 0; i < n; i++) {
        int curr_l = 0;
        int curr_r = m-1;

        for (int j = 0; j < m; j++) {
            if (A[i][j] == 0) d[j] = 0;
            else d[j]++; 
        }

        for (int j = 0; j < m; j++) {
            if (A[i][j] == 0) {
                l[j] = 0;
                curr_l = j+ 1;
            }
            else l[j] = max(l[j], curr_l);
        }
        for (int j = m-1; j >= 0; j--) {
            if (A[i][j] == 0) {
                r[j] = m-1;
                curr_r = j -1;
            }
            else r[j] = min(r[j], curr_r);
        }
        for (int j = 0; j < m; j++) {
            max_val = max(max_val,  (r[j] - l[j] + 1) * d[j] );
        }
    }

    return max_val;
}
