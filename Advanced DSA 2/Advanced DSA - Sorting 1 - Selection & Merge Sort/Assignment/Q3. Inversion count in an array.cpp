/*
Problem Description
Given an array of integers A. If i < j and A[i] > A[j], then the pair (i, j) is called an inversion of A. Find the total number of inversions of A modulo (109 + 7).



Problem Constraints
1 <= length of the array <= 105

1 <= A[i] <= 109



Input Format
The only argument given is the integer array A.



Output Format
Return the number of inversions of A modulo (109 + 7).



Example Input
Input 1:

A = [1, 3, 2]
Input 2:

A = [3, 4, 1, 2]


Example Output
Output 1:

1
Output 2:

4


Example Explanation
Explanation 1:

The pair (1, 2) is an inversion as 1 < 2 and A[1] > A[2]
Explanation 2:

The pair (0, 2) is an inversion as 0 < 2 and A[0] > A[2]
The pair (0, 3) is an inversion as 0 < 3 and A[0] > A[3]
The pair (1, 2) is an inversion as 1 < 2 and A[1] > A[2]
The pair (1, 3) is an inversion as 1 < 3 and A[1] > A[3]


*/

int mod = 1000000007; 
int merge (vector<int> &A, int start, int mid,  int end) {
    vector<int> C(end - start +1);
    int P1 = start;
    int P2 = mid+1;
    int P3 = 0;
    int count = 0;
    while (P1 <= mid && P2 <= end) {
        if (A[P1] <= A[P2]) {
            C[P3] = A[P1];
            P1++;
            P3++;
        }
        else {
            count += (mid - P1 + 1) % mod;
            C[P3] = A[P2];
            P2++;
            P3++;
        }
    }

    while (P1 <= mid) {
        C[P3] = A[P1];
        P1++;
        P3++;
    }

    while (P2 <= end) {
        C[P3] = A[P2];
        P2++;
        P3++;
    }

    for (int i =0 ; i <= end - start; i++) {
        A[start+i] = C[i];
    }

    return count % mod;
}

int invert(vector<int> &A, int start, int end) {
    if (start >= end) return 0;

    int mid = (start + end ) /2;

    int left = invert(A, start, mid)% mod;
    int right = invert(A , mid+1, end)% mod;
    int center = merge(A, start, mid, end)% mod;

    long ans = (left + right + center )  % mod;
    return ans;
}

int Solution::solve(vector<int> &A) {
    return invert(A, 0, A.size()-1);
}
