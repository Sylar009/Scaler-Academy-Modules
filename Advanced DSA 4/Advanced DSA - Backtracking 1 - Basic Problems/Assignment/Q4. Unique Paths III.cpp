/*
Problem Description

Given a matrix of integers A of size N x M . There are 4 types of squares in it:






1. 1 represents the starting square.  There is exactly one starting square.
2. 2 represents the ending square.  There is exactly one ending square.
3. 0 represents empty squares we can walk over.
4. -1 represents obstacles that we cannot walk over.
Find and return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

Note: Rows are numbered from top to bottom and columns are numbered from left to right.








Problem Constraints

2 <= N * M <= 20
-1 <= A[i] <= 2



Input Format

The first argument given is the integer matrix A.



Output Format

Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.



Example Input

Input 1:

A = [   [1, 0, 0, 0]
        [0, 0, 0, 0]
        [0, 0, 2, -1]   ]
Input 2:

A = [   [0, 1]
        [2, 0]    ]


Example Output

Output 1:

2
Output 2:

0


Example Explanation

Explanation 1:

We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
Explanation 1:

There are no such paths.
*/

/****************************************************************************
*****************************************************************************

int n, m, ans;
int xx[4] = {1, 0, 0, -1};
int yy[4] = {0, 1, -1, 0};

bool isV(int u, int v, vector < vector < int > > A) {
    // checks if it is possible to walk over the square (u, v)
    return 0 <= u && u < n && 0 <= v && v < m && A[u][v] != -1;
}

void recursion(int x, int y, int cnt, vector < vector < int > > & A) {
    if (A[x][y] == 2) {
        // checks if every non-obstacle square has been covered
        if (cnt == 0) ans++;
        return;
    }
    A[x][y] = -1;
    // traverse all the directions
    for (int i = 0; i < 4; i++) {
        int u = x + xx[i];
        int v = y + yy[i];
        if (isV(u, v, A)) {
            recursion(u, v, cnt - 1, A);
        }
    }
    A[x][y] = 0;
}

int Solution::solve(vector < vector < int > > & A) {
    n = A.size();
    m = A[0].size();
    ans = 0;
    int u = -1, v = -1, cnt = 0;
    // find starting point and count number of non-obstacle squares
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == 1) {
                u = i;
                v = j;
            } else if (A[i][j] == 0) 
                cnt++;
        }
    }
    // Ending square is also counted in cnt so pass cnt + 1
    recursion(u, v, cnt + 1, A);
    return ans;
}


*****************************************************************************
****************************************************************************/

void generate (vector<vector<int> > &A, int row, int col, int x, int y, int count,
 int len, int &res) {
    if (x < 0 || x >= row || y < 0 || y >= col || A[x][y] == -1) return;

    if (A[x][y] == 2) {
        if (len == count+1) res++;
        return;
    } 

    int t = A[x][y];
    A[x][y] = -1;
    generate(A, row, col, x+1, y, count, len+1, res);
    generate(A, row, col, x-1, y, count, len+1, res);
    generate(A, row, col, x, y+1, count, len+1, res);
    generate(A, row, col, x, y-1, count, len+1, res);
    A[x][y] = t;
}

int Solution::solve(vector<vector<int> > &A) {
    int res = 0;
    int count = 0;
    int si = -1;
    int sj = -1;

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            if (A[i][j] == 1) {
                si = i;
                sj = j;
            }
            if (A[i][j] == 0) count++; 
        }
    }
    generate(A, A.size(), A[0].size(), si, sj , count, 0, res);
    return res;
}
