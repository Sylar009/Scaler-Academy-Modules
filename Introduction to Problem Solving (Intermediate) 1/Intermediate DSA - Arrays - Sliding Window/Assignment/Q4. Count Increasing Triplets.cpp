/*
Problem Description
You are given an array A of N elements. Find the number of triplets i,j and k such that i<j<k and A[i]<A[j]<A[k]


Problem Constraints
1 <= N <= 103
1 <= A[i] <= 109


Input Format
First argument A is an array of integers.


Output Format
Return an integer.


Example Input
Input 1:
A = [1, 2, 4, 3]
Input 2:
A = [2, 1, 2, 3]


Example Output
Output 1:
2
Output 2:
1


Example Explanation
For Input 1:
The triplets that satisfy the conditions are [1, 2, 3] and [1, 2, 4].
For Input 2:
 
The triplet that satisfy the conditions is [1, 2, 3].
*/

int Solution::solve(vector<int> &A) {
    int count = 0;

    for (int j = 1; j < A.size() - 1; j++) {
        int left = 0;
        for (int i = j-1; i >= 0; i--) if (A[i] < A[j] ) left++;

        int right = 0;
        for (int k = j+1; k < A.size(); k++) if (A[k] > A[j] ) right++;

        count += (left * right);
    }

    return count;
}
