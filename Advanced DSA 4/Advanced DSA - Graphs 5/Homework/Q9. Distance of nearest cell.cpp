/*
Problem Description

Given a matrix of integers A of size N x M consisting of 0 or 1.

For each cell of the matrix find the distance of nearest 1 in the matrix.

Distance between two cells (x1, y1) and (x2, y2) is defined as |x1 - x2| + |y1 - y2|.

Find and return a matrix B of size N x M which defines for each cell in A distance of nearest 1 in the matrix A.

NOTE: There is atleast one 1 is present in the matrix.



Problem Constraints

1 <= N, M <= 1000

0 <= A[i][j] <= 1



Input Format

The first argument given is the integer matrix A.



Output Format

Return the matrix B.



Example Input

Input 1:

 A = [
       [0, 0, 0, 1]
       [0, 0, 1, 1] 
       [0, 1, 1, 0]
     ]
Input 2:

 A = [
       [1, 0, 0]
       [0, 0, 0]
       [0, 0, 0]  
     ]


Example Output

Output 1:

 [ 
   [3, 2, 1, 0]
   [2, 1, 0, 0]
   [1, 0, 0, 1]   
 ]
Output 2:

 [
   [0, 1, 2]
   [1, 2, 3]
   [2, 3, 4] 
 ]


Example Explanation

Explanation 1:

 A[0][0], A[0][1], A[0][2] will be nearest to A[0][3].
 A[1][0], A[1][1] will be nearest to A[1][2].
 A[2][0] will be nearest to A[2][1] and A[2][3] will be nearest to A[2][2].
Explanation 2:

 There is only a single 1. Fill the distance from that 1.
*/

vector<vector<int> > Solution::solve(vector<vector<int> > &A) {
    queue<pair<int, int> > qu;
    vector<pair<int, int> > dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    vector<vector<int> > res(A.size(), vector<int>(A[0].size(), INT_MAX));

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            if (A[i][j] == 1) {
                res[i][j] = 0;
                qu.push({i, j});
            }
        }
    }

    while (qu.size() > 0) {
        int size = qu.size();
        while (size--) {
            pair<int, int> pr = qu.front();
            qu.pop();

            for (int k = 0; k < 4; k++) {
                int dx = pr.first + dir[k].first;
                int dy = pr.second + dir[k].second;
                if (dx < A.size() && dx >= 0 && dy < A[0].size() && dy >= 0) {
                    if (res[dx][dy] > res[pr.first][pr.second]) {
                        res[dx][dy] = res[pr.first][pr.second] + 1;
                        qu.push({dx,dy});
                    }
                }
            }
        }
    }

    return res;
}
