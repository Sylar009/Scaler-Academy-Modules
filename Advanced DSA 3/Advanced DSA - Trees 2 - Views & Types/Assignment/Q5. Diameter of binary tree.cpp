/*
Problem Description

Given a Binary Tree A consisting of N integer nodes, you need to find the diameter of the tree.

The diameter of a tree is the number of edges on the longest path between two nodes in the tree.



Problem Constraints

0 <= N <= 105



Input Format

First and only Argument represents the root of binary tree A.



Output Format

Return an single integer denoting the diameter of the tree.



Example Input

Input 1:

           1
         /   \
        2     3
       / \
      4   5
Input 2:

            1
          /   \
         2     3
        / \     \
       4   5     6


Example Output

Output 1:

 3
Output 2:

 4


Example Explanation

Explanation 1:

 Longest Path in the tree is 4 -> 2 -> 1 -> 3 and the number of edges in this path is 3 so diameter is 3.
Explanation 2:

 Longest Path in the tree is 4 -> 2 -> 1 -> 3 -> 6 and the number of edges in this path is 4 so diameter is 4.
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

int pre_ordered_traversal(TreeNode* A, int& max_val) {
    if(!A) return -1;
    int left = pre_ordered_traversal(A->left, max_val);
    int right = pre_ordered_traversal(A->right, max_val);
    max_val = max(max_val, left+right+2);
    return max(left, right) + 1;
}
int Solution::solve(TreeNode* A) {
    int max_of_all_nodes = 0;
    pre_ordered_traversal(A, max_of_all_nodes);
    return max_of_all_nodes;
}
