/*
Problem Description

You are given a binary tree represented by root A. You need to check if it is a Binary Search Tree or not.


Assume a BST is defined as follows:

1) The left subtree of a node contains only nodes with keys less than the node's key.

2) The right subtree of a node contains only nodes with keys greater than the node's key.

3) Both the left and right subtrees must also be binary search trees.





Problem Constraints

1 <= Number of nodes in binary tree <= 105





0 <= node values <= 232-1





Input Format

First and only argument is head of the binary tree A.



Output Format

Return 0 if false and 1 if true.



Example Input

Input 1:

 
   1
  /  \
 2    3
Input 2:

 
  2
 / \
1   3


Example Output

Output 1:

 0
Output 2:

 1


Example Explanation

Explanation 1:

 2 is not less than 1 but is in left subtree of 1.
Explanation 2:

Satisfies all conditions.


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
bool is_correct_BST(TreeNode* A, long min, long max) {
    if (!A) return true;
    if (A->val < min || A->val > max) return false;

    bool l = is_correct_BST(A->left, min, A->val-1);
    bool r = is_correct_BST(A->right, A->val+1, max);

    return (l && r);   
}

int Solution::isValidBST(TreeNode* A) {
    return is_correct_BST(A, LONG_MIN, LONG_MAX) ? 1 : 0;
}
