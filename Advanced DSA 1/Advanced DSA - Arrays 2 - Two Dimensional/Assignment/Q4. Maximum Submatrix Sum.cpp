/*
Problem Description
Given a row-wise and column-wise sorted matrix A of size N * M.
Return the maximum non-empty submatrix sum of this matrix.


Problem Constraints
1 <= N, M <= 1000
-109 <= A[i][j] <= 109


Input Format
The first argument is a 2D integer array A.


Output Format
Return a single integer that is the maximum non-empty submatrix sum of this matrix.


Example Input
Input 1:-
    -5 -4 -3
A = -1  2  3
     2  2  4
Input 2:-
    1 2 3
A = 4 5 6
    7 8 9


Example Output
Output 1:-
12
Output 2:-
45


Example Explanation
Expanation 1:-
The submatrix with max sum is 
-1 2 3
 2 2 4
 Sum is 12.
Explanation 2:-
The largest submatrix with max sum is 
1 2 3
4 5 6
7 8 9
The sum is 45.

*/
long Solution::solve(vector<vector<int> > &A) {
    vector<vector<long> > temp(A.size(), vector<long> (A[0].size(),0));
     for (int i = 0; i < A.size(); i++) {
        long sum = 0;
        for (int j = 0; j < A[0].size(); j++) {
            sum += A[i][j];
            temp[i][j] = sum;
        }
    }

    for (int i = 0; i < temp[0].size(); i++) {
        long sum = 0;
        for (int j = 0; j < temp.size(); j++) {
            sum += temp[j][i];
            temp[j][i] = sum;
        }
    }

    long ans = LONG_MIN;
    for (int i = 0; i < temp.size(); i++) {
        for (int j = 0; j < temp[0].size(); j++) {
            int a1 = i;
            int b1 = j;
            int a2 = temp.size()-1;
            int b2 = temp[0].size()-1;
            long temp_ans = temp[a2][b2];
            if (b1 > 0) temp_ans = (temp_ans -  temp[a2][b1-1]);
            if (a1 > 0) temp_ans = (temp_ans - temp[a1-1][b2]);
            if (a1 > 0 && b1 > 0) temp_ans = (temp_ans + temp[a1-1][b1-1]);
            ans = max(ans, temp_ans);
        }
    }

    return ans;
}
