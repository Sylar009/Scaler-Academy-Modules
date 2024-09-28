/*
Problem Description

Given a binary search tree.
Return the distance between two nodes with given two keys B and C. It may be assumed that both keys exist in BST.

NOTE: Distance between two nodes is number of edges between them.



Problem Constraints

1 <= Number of nodes in binary tree <= 1000000

0 <= node values <= 109



Input Format

First argument is a root node of the binary tree, A.

Second argument is an integer B.

Third argument is an integer C.



Output Format

Return an integer denoting the distance between two nodes with given two keys B and C



Example Input

Input 1:

    
         5
       /   \
      2     8
     / \   / \
    1   4 6   11
 B = 2
 C = 11
Input 2:

    
         6
       /   \
      2     9
     / \   / \
    1   4 7   10
 B = 2
 C = 6


Example Output

Output 1:

 3
Output 2:

 1


Example Explanation

Explanation 1:

 Path between 2 and 11 is: 2 -> 5 -> 8 -> 11. Distance will be 3.
Explanation 2:

 Path between 2 and 6 is: 2 -> 6. Distance will be 1



*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int dist_from_root(TreeNode* A, int B) {
    if (A->val == B) return 0;
    else if (A->val > B) return 1 + dist_from_root(A->left, B);
    else return 1 + dist_from_root(A->right, B);
}

int dist_bw_2(TreeNode* A, int B, int C) {
    if(A == nullptr) return 0;

    if (A->val > B && A->val > C) return dist_bw_2(A->left, B, C);

    if (A->val < B && A->val < C) return dist_bw_2(A->right, B, C);

    if (A->val >= B && A->val <= C) return dist_from_root(A, B) + dist_from_root(A, C);
}
int Solution::solve(TreeNode* A, int B, int C) {
    if(B > C) swap(B, C);

    return dist_bw_2(A, B, C);
}
