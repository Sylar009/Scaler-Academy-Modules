/*
Problem Description
Given a 2D integer matrix A of size N x N, find a B x B submatrix where B<= N and B>= 1, such that the sum of all the elements in the submatrix is maximum.



Problem Constraints
1 <= N <= 103.

1 <= B <= N

-102 <= A[i][j] <= 102.



Input Format
First arguement is an 2D integer matrix A.

Second argument is an integer B.



Output Format
Return a single integer denoting the maximum sum of submatrix of size B x B.



Example Input
Input 1:

 A = [
        [1, 1, 1, 1, 1]
        [2, 2, 2, 2, 2]
        [3, 8, 6, 7, 3]
        [4, 4, 4, 4, 4]
        [5, 5, 5, 5, 5]
     ]
 B = 3
Input 2:

 A = [
        [2, 2]
        [2, 2]
    ]
 B = 2


Example Output
Output 1:

 48
Output 2:

 8


Example Explanation
Explanation 1:

    Maximum sum 3 x 3 matrix is
    8 6 7
    4 4 4
    5 5 5
    Sum = 48
Explanation 2:

 Maximum sum 2 x 2 matrix is
  2 2
  2 2
  Sum = 8
*/

int Solution::solve(vector<vector<int> > &A, int B) {
    for (int i = 0; i < A.size(); i++) {
        int sum = 0;
        for (int j = 0; j < A[0].size(); j++) {
            sum += A[i][j];
            A[i][j] = sum;
        }
    }

    for (int i = 0; i < A[0].size(); i++) {
        int sum = 0;
        for (int j = 0; j < A.size(); j++) {
            sum += A[j][i];
            A[j][i] = sum;
        }
    }

    int res = INT_MIN;

   for (int i = 0; i < A.size()-B+1; i++) {
        for (int j = 0; j < A[0].size()-B+1; j++) {
            int a1 = i;
            int b1 = j;
            int a2 = i+B-1;
            int b2 = j+B-1;
            int ans = A[a2][b2];
            if (b1 > 0) ans = (ans -  A[a2][b1-1]);
            if (a1 > 0) ans = (ans - A[a1-1][b2]) ;
            if (a1 > 0 && b2 > 0) ans = (ans + A[a1-1][b1-1]);

            res = max(res, ans);
        }
    }    
    return res;
}
