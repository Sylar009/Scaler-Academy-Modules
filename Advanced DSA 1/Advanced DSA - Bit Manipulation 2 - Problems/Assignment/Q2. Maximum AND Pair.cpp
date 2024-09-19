/*
Problem Description
Given an array A. For every pair of indices i and j (i != j), find the maximum A[i] & A[j].


Problem Constraints
1 <= len(A) <= 105
1 <= A[i] <= 109


Input Format
The first argument is an integer array A.


Output Format
Return a single integer that is the maximum A[i] & A[j].


Example Input
Input 1:-
A = [53, 39, 88]
Input 2:-
A = [38, 44, 84, 12] 


Example Output
Output 1:-
37
Output 2:-
36


Example Explanation
Explanation 1:-
53 & 39 = 37
39 & 88 = 0
53 & 88 = 16
Maximum among all these pairs is 37
Explanation 2:-
Maximum bitwise and among all pairs is (38, 44) = 36

*/

int Solution::solve(vector<int> &A) {
    int res = 0;
    for (int i = 30; i >= 0; i-- ) {
        int count = 0;
        for (int j = 0; j < A.size(); j++ ) if (A[j] & (1 << i)) count++;

        if (count >= 2) {
            res += (1 << i);
            for (int j = 0; j < A.size(); j++ ) if (!(A[j] & (1 << i))) A[j] = 0;
        }
    }

    return res;
}

