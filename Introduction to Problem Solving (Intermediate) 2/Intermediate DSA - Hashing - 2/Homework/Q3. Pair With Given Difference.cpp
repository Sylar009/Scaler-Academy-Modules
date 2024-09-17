/*
Problem Description
Given an one-dimensional unsorted array A containing N integers.

You are also given an integer B, find if there exists a pair of elements in the array whose difference is B.

Return 1 if any such pair exists else return 0.



Problem Constraints
1 <= N <= 105
-103 <= A[i] <= 103
-105 <= B <= 105


Input Format
First argument is an integer array A of size N.

Second argument is an integer B.



Output Format
Return 1 if any such pair exists else return 0.



Example Input
Input 1:

 A = [5, 10, 3, 2, 50, 80]
 B = 78
Input 2:

 A = [-10, 20]
 B = 30
Input 2=3:

 A = [-100, 20, 80]
 B = 9


Example Output
Output 1:

 1
Output 2:

 1
Output 3:

 0


Example Explanation
Explanation 1:

 Pair (80, 2) gives a difference of 78.
Explanation 2:

 Pair (20, -10) gives a difference of 30 i.e 20 - (-10) => 20 + 10 => 30
Explanation 3:

 There is no such pairs, that has a difference of 9.

*/

int Solution::solve(vector<int> &A, int B) {

    unordered_set<int> hs;
    int y = 0;
    for (int a : A) {
        if (hs.find(B+a) != hs.end()) return 1;
        else if (hs.find(a-B) != hs.end()) return 1;
        else hs.insert(a);
    }

    return 0;
}
