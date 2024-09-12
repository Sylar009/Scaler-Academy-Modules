/*
Problem Description
Given an integer array A, find if an integer p exists in the array such that the number of integers greater than p in the array equals p.



Problem Constraints
1 <= |A| <= 2*105
-108 <= A[i] <= 108


Input Format
First and only argument is an integer array A.



Output Format
Return 1 if any such integer p is present else, return -1.



Example Input
Input 1:

 A = [3, 2, 1, 3]
Input 2:

 A = [1, 1, 3, 3]


Example Output
Output 1:

 1
Output 2:

 -1


Example Explanation
Explanation 1:

 For integer 2, there are 2 greater elements in the array..
Explanation 2:

 There exist no integer satisfying the required conditions.

*/

int Solution::solve(vector<int> &A) {
    sort(A.begin(), A.end(), greater<>() );
    int count = -1;
    
    if (A[0] == 0) return 1;

    for (int i = 1; i < A.size(); i++) {
        if (A[i] != A[i-1] && A[i] == i) return 1;
    }

    return -1;
}
