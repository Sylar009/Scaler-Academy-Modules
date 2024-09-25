/*
Problem Description
You are given a 2-D matrix C of size A × B.
You need to build a new 1-D array of size A by taking one element from each row of the 2-D matrix in such a way that the cost of the newly built array is minimized.

The cost of an array is the minimum possible value of the absolute difference between any two adjacent elements of the array.

So if the newly built array is X, the element picked from row 1 will become X[1], element picked from row 2 will become X[2], and so on.

Determine the minimum cost of the newly built array.



Problem Constraints
2 <= A <= 1000
2 <= B <= 1000
1 <= C[i][j] <= 106



Input Format
The first argument is an integer A denoting number of rows in the 2-D array.
The second argument is an integer B denoting number of columns in the 2-D array.
The third argument is a 2-D array C of size A x B.



Output Format
Return an integer denoting the minimum cost of the newly build array.



Example Input
Input 1:

 A = 2
 B = 2
 C = [ [8, 4]
      [6, 8] ]
Input 2:

 A = 3
 B = 2
 C = [ [7, 3]
       [2, 1]
       [4, 9] ]


Example Output
Output 1:

 0
Output 2:

 1


Example Explanation
Explanation 1:

 Newly build array : [8, 8]. The minimum cost will be 0 since the absolute difference will be 0(8-8).
Explanation 2:

 Newly build array : [3, 2, 4]. The minimum cost will be 1 since the minimum absolute difference will be 1(3 - 2).


*/

int get_min_difference(int start, int end, vector<int> &A, int val) {
    int min_val = INT_MAX;
    int max_val = INT_MIN;

    while (start <= end ) {
        int mid = start + (end - start)/2;

        if (val < A[mid]) min_val = min(min_val, A[mid]);
        else if (val >= A[mid]) max_val = max(max_val, A[mid]);
 
        if (A[mid] > val) end = mid -1;
        else start = mid + 1;
    }

    if (max_val == INT_MIN) return (min_val - val);
    else if (min_val == INT_MAX) return (val - max_val);
    else min((val - max_val), (min_val - val));
}

int Solution::solve(int A, int B, vector<vector<int> > &C) {
    for (int a = 0; a < C.size(); a++) sort(C[a].begin(), C[a].end());

    int res = INT_MAX;
    for (int i = 0; i < C.size()-1; i++) {
        for (int j = 0; j < C[i].size(); j++) {
            int left = 0;
            int right = C[i].size()-1;
            int val = C[i][j];
            res = min(res, get_min_difference(left, right, C[i+1], val) );
        }
    }
    return res;
}
