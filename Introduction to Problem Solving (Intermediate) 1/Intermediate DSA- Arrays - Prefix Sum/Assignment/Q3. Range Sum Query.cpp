/*
Problem Description
You are given an integer array A of length N.
You are also given a 2D integer array B with dimensions M x 2, where each row denotes a [L, R] query.
For each query, you have to find the sum of all elements from L to R indices in A (0 - indexed).
More formally, find A[L] + A[L + 1] + A[L + 2] +... + A[R - 1] + A[R] for each query.



Problem Constraints
1 <= N, M <= 105
1 <= A[i] <= 109
0 <= L <= R < N


Input Format
The first argument is the integer array A.
The second argument is the 2D integer array B.


Output Format
Return an integer array of length M where ith element is the answer for ith query in B.


Example Input
Input 1:
A = [1, 2, 3, 4, 5]
B = [[0, 3], [1, 2]]
Input 2:

A = [2, 2, 2]
B = [[0, 0], [1, 2]]


Example Output
Output 1:
[10, 5]
Output 2:

[2, 4]


Example Explanation
Explanation 1:
The sum of all elements of A[0 ... 3] = 1 + 2 + 3 + 4 = 10.
The sum of all elements of A[1 ... 2] = 2 + 3 = 5.
Explanation 2:

The sum of all elements of A[0 ... 0] = 2 = 2.
The sum of all elements of A[1 ... 2] = 2 + 2 = 4.
*/

vector<long long> Solution::rangeSum(vector<int> &A, vector<vector<int> > &B) {
    //creating the prefix sum array
    vector<long long> prefix_arr;
    long long pre_sum = 0;
    prefix_arr.push_back(0);
    for(int i = 0; i < A.size(); i++) {
        pre_sum += A[i];
        prefix_arr.push_back(pre_sum);
    }

    vector<long long> result_arr;
    for(int j = 0; j < B.size(); j++) {
        int x = B[j][0];
        int y = B[j][1];
        long long sum =  prefix_arr[y] - prefix_arr[x-1];
        result_arr.push_back(sum);
    }
    
    return result_arr;
}
