/*
Problem Description

Given a matrix of integers A of size N x M consisting of 0, 1 or 2.

Each cell can have three values:

The value 0 representing an empty cell.

The value 1 representing a fresh orange.

The value 2 representing a rotten orange.

Every minute, any fresh orange that is adjacent (Left, Right, Top, or Bottom) to a rotten orange becomes rotten. Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1 instead.

Note: Your solution will run on multiple test cases. If you are using global variables, make sure to clear them.



Problem Constraints

1 <= N, M <= 1000

0 <= A[i][j] <= 2



Input Format

The first argument given is the integer matrix A.



Output Format

Return the minimum number of minutes that must elapse until no cell has a fresh orange.

If this is impossible, return -1 instead.



Example Input

Input 1:


A = [   [2, 1, 1]
        [1, 1, 0]
        [0, 1, 1]   ]


Input 2:


 
A = [   [2, 1, 1]
        [0, 1, 1]
        [1, 0, 1]   ]








Example Output

Output 1:

 4
Output 2:

 -1


Example Explanation

Explanation 1:

Minute 0: [ [2, 1, 1]
            [1, 1, 0]
            [0, 1, 1] ]
Minute 1: [ [2, 2, 1]
            [2, 1, 0]
            [0, 1, 1] ]
Minute 2: [ [2, 2, 2]
            [2, 2, 0]
            [0, 1, 1] ]
Minute 3: [ [2, 2, 2]
            [2, 2, 0]
            [0, 2, 1] ]
Minute 4: [ [2, 2, 2]
            [2, 2, 0]
            [0, 2, 2] ]
At Minute 4, all the oranges are rotten.
Explanation 2:

The fresh orange at 2nd row and 0th column cannot be rotten, So return -1.
*/

bool verify(int x, int y, int n, int m, vector<vector<int> > &A, vector<vector<bool> > &vis) {
    if (x >= 0 && y >= 0 && x < n && y < m && (A[x][y] != 0) && !vis[x][y]) return true;
    return false;
}

int Solution::solve(vector<vector<int> > &A) {
    vector<int> x = {-1, 0, 1, 0};
    vector<int> y = {0, -1, 0, 1};

    queue<pair<int, int> > qu;

    vector<vector<bool> > vis(A.size(), vector<bool>(A[0].size(), false) );
    vector<vector<int> > t(A.size(), vector<int>(A[0].size(), -1));

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            if (A[i][j] == 2) {
                qu.push(make_pair(i, j));
                vis[i][j] = true;
                t[i][j] = 0;
            }
        }
    }

    while (qu.size() > 0) {
        pair<int, int> pr = qu.front();
        qu.pop();
        int _x = pr.first;
        int _y = pr.second;

        for (int k = 0; k < 4; k++) {
            int new_x = _x + x[k];
            int new_y = _y + y[k];
            if (verify(new_x, new_y, A.size(), A[0].size(), A, vis)) {
                vis[new_x][new_y] = true;
                t[new_x][new_y] = t[_x][_y] + 1;
                qu.push(make_pair(new_x, new_y));
            }
        }
    }

    int res = INT_MIN;
    for (int i = 0; i < A.size(); i++){
        for (int j = 0; j < A[0].size(); j++) {
            if (A[i][j] == 1) {
                if (vis[i][j] == false) return -1;
                else res = max(res, t[i][j]);
            }
        }
    }
    return res;
}
