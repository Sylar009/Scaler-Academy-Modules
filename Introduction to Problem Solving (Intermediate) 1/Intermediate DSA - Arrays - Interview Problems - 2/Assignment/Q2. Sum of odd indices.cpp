/*
Problem Description
You are given an array A of length N and Q queries given by the 2D array B of size Q*2. Each query consists of two integers B[i][0] and B[i][1].
For every query, the task is to calculate the sum of all odd indices in the range A[B[i][0]…B[i][1]].

Note : Use 0-based indexing


Problem Constraints
1 <= N <= 105
1 <= Q <= 105
1 <= A[i] <= 100
0 <= B[i][0] <= B[i][1] < N


Input Format
First argument A is an array of integers.
Second argument B is a 2D array of integers.


Output Format
Return an array of integers.


Example Input
Input 1:
A = [1, 2, 3, 4, 5]
B = [   [0,2] 
        [1,4]   ]
Input 2:
A = [2, 1, 8, 3, 9]
B = [   [0,3] 
        [2,4]   ]


Example Output
Output 1:
[2, 6]
Output 2:
[4, 3]


Example Explanation
For Input 1:
The subarray for the first query is [1, 2, 3] whose sum of odd indices is 2.
The subarray for the second query is [2, 3, 4, 5] whose sum of odd indices is 6.
For Input 2:
The subarray for the first query is [2, 1, 8, 3] whose sum of odd indices is 4.
The subarray for the second query is [8, 3, 9] whose sum of odd indices is 3.

*/

vector<int> Solution::solve(vector<int> &A, vector<vector<int> > &B) {
    vector<int> pf_odd;
    int sum = 0;
    for (int i = 0; i < A.size(); i++) pf_odd.push_back( (i % 2 == 0 ) ? sum : sum += A[i]);

    vector<int> result;
    for (int j = 0; j < B.size(); j++) {
        int s = B[j][0];
        int e = B[j][1];

        result.push_back((s==0) ? pf_odd[e] : (pf_odd[e] - pf_odd[s-1]) );
    }

    return result;
}