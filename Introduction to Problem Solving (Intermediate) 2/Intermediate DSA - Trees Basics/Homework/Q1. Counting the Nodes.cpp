/*
Problem Description
Given the root of a tree A with each node having a certain value, find the count of nodes with more value than all its ancestors.

Ancestor means that every node that occurs before the current node in the path from root to the node.



Problem Constraints
1 <= Number of Nodes <= 200000

1 <= Value of Nodes <= 2000000000



Input Format
The first and only argument of input is a tree node.



Output Format
Return a single integer denoting the count of nodes that have more value than all of its ancestors.



Example Input
Input 1:

 
     3
Input 2:

 
    4
   / \
  5   2
     / \
    3   6


Example Output
Output 1:

 1 
Output 2:

 3


Example Explanation
Explanation 1:

 There's only one node in the tree that is the valid node.
Explanation 2:

 The valid nodes are 4, 5 and 6.


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

int find_count(TreeNode* A, int old_max) {
    if (!A) return 0;

    int new_max =max(A->val, old_max);

    return find_count(A->left, new_max) + find_count(A->right, new_max) + (A->val > old_max);
}

int Solution::solve(TreeNode* A) {
    if (!A) return 0;

    return find_count(A, A->val) + 1;
}
