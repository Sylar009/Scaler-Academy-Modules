/*
Problem Description
Given two sorted integer arrays A and B, merge B and A as one sorted array and return it as an output.

Note: A linear time complexity is expected and you should avoid use of any library function.


Problem Constraints
-2×109 <= A[i], B[i] <= 2×109
1 <= |A|, |B| <= 5×104


Input Format
First Argument is a 1-D array representing  A.
Second Argument is also a 1-D array representing B.


Output Format
Return a 1-D vector which you got after merging A and B.


Example Input
Input 1:

A = [4, 7, 9]
B = [2, 11, 19]
Input 2:

A = [1]
B = [2]


Example Output
Output 1:

[2, 4, 7, 9, 11, 19]
Output 2:

[1, 2]


Example Explanation
Explanation 1:

Merging A and B produces the output as described above.
Explanation 2:

 Merging A and B produces the output as described above.
*/

vector<int> Solution::solve(const vector<int> &A, const vector<int> &B) {
    vector<int> C(A.size()+B.size());
    int P1 = 0;
    int P2 = 0;
    int P3 = 0;
    while (P1 < A.size() && P2 < B.size()) {
        if (A[P1] < B[P2]) {
            C[P3] = A[P1];
            P1++;
            P3++;
        }
        else {
            C[P3] = B[P2];
            P2++;
            P3++;
        }
    }

    while (P1 < A.size()) {
        C[P3] = A[P1];
        P1++;
        P3++;
    }

    while (P2 < B.size()) {
        C[P3] = B[P2];
        P2++;
        P3++;
    }

    return C;
}
