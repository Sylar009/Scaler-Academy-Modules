/*
Problem Description

Given character matrix A of dimensions N×M consisting of O's and X's, where O = white, X = black.








Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)





Problem Constraints

1 <= N, M <= 1000








A[i][j] = 'X' or 'O'





Input Format

The First and only argument is character matrix A.



Output Format

Return a single integer denoting number of black shapes.



Example Input

Input 1:

 A = [ [X, X, X], [X, X, X], [X, X, X] ]
Input 2:

 A = [ [X, O], [O, X] ]


Example Output

Output 1:

 1
Output 2:

 2


Example Explanation

Explanation 1:

 All X's belong to single shapes
Explanation 2:

 Both X's belong to different shapes
*/

void dfs(vector<string> A, int i, int j, vector<vector<bool> >& visited, vector<vector<int> >& check){
    if(i < 0 || i >= A.size()){
        return;
    }
    if(j < 0 || j >= A[0].size()){
        return;
    }
    if(check[i][j] == 0 || visited[i][j]){
        return;
    }
    
    visited[i][j] = true;
    
    dfs(A, i-1, j, visited, check);
    dfs(A, i+1, j, visited, check);
    dfs(A, i, j-1, visited, check);
    dfs(A, i, j+1, visited, check);
}

int Solution::black(vector<string> &A) {
    if(A.size() == 0){
        return 0;
    }
    
    vector<vector<int> > check(A.size(), vector<int> (A[0].size(), 0));
    vector<vector<bool> > visited(A.size(), vector<bool> (A[0].size(), false));
    
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < A[0].size(); j++){
            if(A[i][j] == 'X'){
                check[i][j] = 1;
            }
        }
    }
    
    
    int sol = 0;
    
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < A[i].size(); j++){
            if(A[i][j] == 'X' && !visited[i][j]){
                dfs(A, i, j, visited, check);
                sol++;
            }
        }
    }
    
    return sol;
}
