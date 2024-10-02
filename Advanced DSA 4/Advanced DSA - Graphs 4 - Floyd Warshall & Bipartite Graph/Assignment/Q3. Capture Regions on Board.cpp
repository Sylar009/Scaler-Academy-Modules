/*
Problem Description

Given a 2-D board A of size N x M containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.



Problem Constraints

1 <= N, M <= 1000



Input Format

First and only argument is a N x M character matrix A.



Output Format

Return nothing. Make changes to the the input only as matrix is passed by reference.



Example Input

Input 1:

 A = [ 
       [X, X, X, X],
       [X, O, O, X],
       [X, X, O, X],
       [X, O, X, X] 
     ]
Input 2:

 A = [
       [X, O, O],
       [X, O, X],
       [O, O, O]
     ]


Example Output

Output 1:

 After running your function, the board should be:
 A = [
       [X, X, X, X],
       [X, X, X, X],
       [X, X, X, X],
       [X, O, X, X]
     ]
Output 2:

 After running your function, the board should be:
 A = [
       [X, O, O],
       [X, O, X],
       [O, O, O]
     ]


Example Explanation

Explanation 1:

 O in (4,2) is not surrounded by X from below.
Explanation 2:

 No O's are surrounded.
*/

void dfs(vector<vector<char> > &A, vector<vector<int>> &vis, int i, int j, vector<vector<int>> &dir) {
    int n = A.size();
    int m = A[0].size();

    vis[i][j] = 1;
    A[i][j] = 'Y';

    for (int k = 0; k < dir.size(); k++) {
        int new_i = i + dir[k][0];
        int new_j = j + dir[k][1];

        if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m &&
        vis[new_i][new_j] == 0 && A[new_i][new_j] == 'O') {
            dfs(A, vis, new_i, new_j, dir);
        }
    }
}

void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();
    int m = A[0].size();

    if (!(n == 1 && m == 1 && A[0][0] == 'O')) {
        vector<vector<int>> dir = {{0,-1}, {0,1}, {-1,0}, {1,0}};
        vector<vector<int>> vis(n, vector<int>(m));

        int i = 0;
        int j = 0;

        for (; j < m-1; j++) {
            if (A[i][j] == 'O') dfs(A, vis, i, j, dir);
        }
        
        for (; i < n-1; i++) {
            if (A[i][j] == 'O') dfs(A, vis, i, j, dir);
        }
        
        for (; j > 0; j--) {
            if (A[i][j] == 'O') dfs(A, vis, i, j, dir);
        }
        
        for (; i >0; i--) {
            if (A[i][j] == 'O') dfs(A, vis, i, j, dir);
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (A[i][j] == 'O') A[i][j] = 'X';
            }
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (A[i][j] == 'Y') A[i][j] = 'O';
            }
        }
    }
}
