/*
Problem Description
You are given a 2D integer matrix A, make all the elements in a row or column zero if the A[i][j] = 0. Specifically, make entire ith row and jth column zero.



Problem Constraints
1 <= A.size() <= 103

1 <= A[i].size() <= 103

0 <= A[i][j] <= 103



Input Format
First argument is a 2D integer matrix A.



Output Format
Return a 2D matrix after doing required operations.



Example Input
Input 1:

[1,2,3,4]
[5,6,7,0]
[9,2,0,4]


Example Output
Output 1:

[1,2,0,0]
[0,0,0,0]
[0,0,0,0]


Example Explanation
Explanation 1:

A[2][4] = A[3][3] = 0, so make 2nd row, 3rd row, 3rd column and 4th column zero.
 */

vector<vector<int> > Solution::solve(vector<vector<int> > &A) {
    vector<vector<int> > result;
    set<int> row;
    set<int> col;

    for (int i = 0 ; i < A.size(); i++) { 
        vector<int > temp; 
        for (int j = 0; j < A[i].size(); j++ ) {
            if (A[i][j] == 0) {
                row.insert(i);
                col.insert(j);
            }
            temp.push_back(A[i][j]);
        }
        result.push_back(temp);
    } 


    for (int a : row ) {
        for (int b = 0 ; b < result[a].size(); b++) {
            result[a][b] = 0;
        }
    }

    for (int x : col) {
        for (int y = 0 ; y < result.size(); y++) {
            result[y][x] = 0;
        }
    }

    return result;
}
