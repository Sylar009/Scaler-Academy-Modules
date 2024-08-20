/*
Problem Description
You are given an array A of length N and Q queries given by the 2D array B of size Q×2.

Each query consists of two integers B[i][0] and B[i][1].

For every query, your task is to find the count of even numbers in the range from A[B[i][0]] to A[B[i][1]].



Problem Constraints
1 <= N <= 105
1 <= Q <= 105
1 <= A[i] <= 109
0 <= B[i][0] <= B[i][1] < N


Input Format
First argument A is an array of integers.
Second argument B is a 2D array of integers.


Output Format
Return an array of integers.


Example Input
Input 1:
A = [1, 2, 3, 4, 5]
B = [   [0, 2] 
        [2, 4]
        [1, 4]   ]
Input 2:
A = [2, 1, 8, 3, 9, 6]
B = [   [0, 3]
        [3, 5]
        [1, 3] 
        [2, 4]   ]


Example Output
Output 1:
[1, 1, 2]
Output 2:
[2, 1, 1, 1]
*/

vector<int> Solution::solve(vector<int> &A, vector<vector<int> > &B) {
    int count = 0;
    vector<int> prefix_arr;    
    for(int i = 0; i < A.size(); i++) {
        if(A[i] % 2 == 0 ) {
            count++;            
        }
        prefix_arr.push_back(count);
    }

    vector<int> result_arr;
    for(int j = 0; j < B.size(); j++) {
        int x = B[j][0];
        int y = B[j][1];
        int ans = (x==0) ?   prefix_arr[y]  : prefix_arr[y] - prefix_arr[x-1];
        result_arr.push_back(ans);
    }
    
    return result_arr;
}
