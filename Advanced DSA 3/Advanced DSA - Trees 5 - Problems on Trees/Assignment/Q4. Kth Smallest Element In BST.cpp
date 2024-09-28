/*
Problem Description

Given a binary search tree represented by root A, write a function to find the Bth smallest element in the tree.



Problem Constraints

1 <= Number of nodes in binary tree <= 100000

0 <= node values <= 10^9



Input Format

First and only argument is head of the binary tree A.



Output Format

Return an integer, representing the Bth element.



Example Input

Input 1:

 
            2
          /   \
         1    3
B = 2
Input 2:

 
            3
           /
          2
         /
        1
B = 1



Example Output

Output 1:

 2
Output 2:

 1


Example Explanation

Explanation 1:

2nd element is 2.
Explanation 2:

1st element is 1.

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
void inorder (TreeNode* A, int &res, int &count, int B) {
    if ( !A) return;
    inorder(A->left, res, count, B);
    count++;
    if(count == B) {
        res = A->val;
        return;
    }
    inorder(A->right, res, count, B);
}
int Solution::kthsmallest(TreeNode* A, int B) {
    int res = 0;
    int count  = 0;
    inorder(A, res, count, B);
    return res;
}
