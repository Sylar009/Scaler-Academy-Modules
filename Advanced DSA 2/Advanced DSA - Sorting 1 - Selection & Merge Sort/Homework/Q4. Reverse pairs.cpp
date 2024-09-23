/*
Problem Description
Given an array of integers A, we call (i, j) an important reverse pair if i < j and A[i] > 2*A[j].
Return the number of important reverse pairs in the given array A.



Problem Constraints
1 <= length of the array <= 105

-2 * 109 <= A[i] <= 2 * 109



Input Format
The only argument given is the integer array A.



Output Format
Return the number of important reverse pairs in the given array A.



Example Input
Input 1:

 A = [1, 3, 2, 3, 1]
Input 2:

 A = [4, 1, 2]


Example Output
Output 1:

 2
Output 2:

 1


Example Explanation
Explanation 1:

 There are two pairs which are important reverse pair 
 i.e  (1, 4) => A[1] > 2 * A[4] => 3 > 2 * 1 => 3 > 2 and
      (3, 4) => A[3] > 2 * A[4] => 3 > 2 * 1 => 3 > 2.
Explanation 2:

 There is only one pair 
 i.e (0, 1) => A[0] > 2 * A[1] => 4 > 2 * 1 => 4 > 1
*/

int merge (vector<int> &A, int start, int mid,  int end) {
    vector<int> C(end - start +1);
    int P1 = start;
    int P2 = mid+1;
    int P3 = 0;
    int count = 0;
    while (P1 <= mid && P2 <= end) {
        if ((long)A[P1] > (long)2*A[P2]) {
            count += (mid - P1 + 1);
            P2++;
        }
        else P1++;
    }

    P1 = start;
    P2 = mid+1;

    while (P1 <= mid && P2 <= end) {
        if (A[P1] <= A[P2]) {
            C[P3] = A[P1];
            P1++;
            P3++;
        }
        else {
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

    return count;
}

int revesePair(vector<int> &A, int start, int end) {
    if (start >= end) return 0;

    int mid = (start + end ) /2;

    int left = revesePair(A, start, mid);
    int right = revesePair(A , mid+1, end);
    int center = merge(A, start, mid, end);

    return left + right + center ;
}

int Solution::solve(vector<int> &A) {
    return revesePair(A, 0, A.size()-1 );
}
