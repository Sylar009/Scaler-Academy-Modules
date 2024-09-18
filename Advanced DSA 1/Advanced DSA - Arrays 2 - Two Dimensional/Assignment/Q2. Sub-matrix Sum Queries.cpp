/*
Problem Description
Given a matrix of integers A of size N x M and multiple queries Q, for each query, find and return the submatrix sum.

Inputs to queries are top left (b, c) and bottom right (d, e) indexes of submatrix whose sum is to find out.

NOTE:

Rows are numbered from top to bottom, and columns are numbered from left to right.
The sum may be large, so return the answer mod 109 + 7.
Also, select the data type carefully, if you want to store the addition of some elements.
Indexing given in B, C, D, and E arrays is 1-based.
Top Left 0-based index = (B[i] - 1, C[i] - 1)
Bottom Right 0-based index = (D[i] - 1, E[i] - 1)


Problem Constraints
1 <= N, M <= 1000
-100000 <= A[i] <= 100000
1 <= Q <= 100000
1 <= B[i] <= D[i] <= N
1 <= C[i] <= E[i] <= M



Input Format
The first argument given is the integer matrix A.
The second argument given is the integer array B.
The third argument given is the integer array C.
The fourth argument given is the integer array D.
The fifth argument given is the integer array E.
(B[i], C[i]) represents the top left corner of the i'th query.
(D[i], E[i]) represents the bottom right corner of the i'th query.



Output Format
Return an integer array containing the submatrix sum for each query.



Example Input
Input 1:

 A = [   [1, 2, 3]
         [4, 5, 6]
         [7, 8, 9]   ]
 B = [1, 2]
 C = [1, 2]
 D = [2, 3]
 E = [2, 3]
Input 2:

 A = [   [5, 17, 100, 11]
         [0, 0,  2,   8]    ]
 B = [1, 1]
 C = [1, 4]
 D = [2, 2]
 E = [2, 4]


Example Output
Output 1:

 [12, 28]
Output 2:

 [22, 19]


Example Explanation
Explanation 1:

 For query 1: Submatrix contains elements: 1, 2, 4 and 5. So, their sum is 12.
 For query 2: Submatrix contains elements: 5, 6, 8 and 9. So, their sum is 28.
Explanation 2:

 For query 1: Submatrix contains elements: 5, 17, 0 and 0. So, their sum is 22.
 For query 2: Submatrix contains elements: 11 and 8. So, their sum is 19.
 

*/

vector<int> Solution::solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E) {
    int mod = 1000000007;
    for (int i = 0; i < A.size(); i++) {
        long sum = 0;
        for (int j = 0; j < A[0].size(); j++) {
            sum += A[i][j];
            sum = (sum < 0 ) ? (sum + mod) % mod : sum % mod;
            A[i][j] = sum;
        }
    }

    for (int i = 0; i < A[0].size(); i++) {
        long sum = 0;
        for (int j = 0; j < A.size(); j++) {
            sum += A[j][i];
            sum = (sum < 0 ) ? sum = (sum + mod) % mod : sum % mod;
            A[j][i] = sum;
        }
    }

    vector<int> res;

    for (int k = 0; k < B.size(); k++) {
        int a1 = B[k]-1;
        int b1 = C[k]-1;
        int a2 = D[k]-1;
        int b2 = E[k]-1;
        int ans = A[a2][b2];
        if (b1 > 0) ans = (ans -  A[a2][b1-1]) % mod;
        if (a1 > 0) ans = (ans - A[a1-1][b2]) % mod;
        if (a1 > 0 && a2 > 0) ans = (ans + A[a1-1][b1-1] % mod);

        ans = (ans < 0) ?(ans + mod) % mod : ans % mod;
        res.push_back(ans);
    }    
    return res;
}
