/*
Problem Description

Given preorder traversal of a binary tree, check if it is possible that it is also a preorder traversal of a Binary Search Tree (BST), where each internal node (non-leaf nodes) have exactly one child.



Problem Constraints

1 <= number of nodes <= 100000



Input Format

First and only argument is an integer array denoting the preorder traversal of binary tree.



Output Format

Return a string "YES" if true else "NO".



Example Input

Input 1:

 A : [4, 10, 5, 8]
Input 2:

 A : [1, 5, 6, 4]


Example Output

Output 1:

 "YES"
Output 2:

 "NO"


Example Explanation

Explanation 1:

 The possible BST is:
            4
             \
             10
             /
             5
              \
              8
Explanation 2:

 There is no possible BST which have the above preorder traversal.


*/

string Solution::solve(vector<int> &A) {
    int n = A.size();
    int min_val = A.size();
    int max_val = A.size();
    if (A[n - 1] > A[n - 2]) {        
        min_val = A[n - 2];
        max_val = A[n - 1];
    }
    else {
        min_val = A[n - 1];
        max_val = A[n - 2];    
    }
    for (int i = n - 3; i >= 0; i--) {
        if (A[i] < min_val) min_val = A[i];
        else if (A[i] > max_val) max_val = A[i];
        else return "NO";
    }

    return "YES";
}
