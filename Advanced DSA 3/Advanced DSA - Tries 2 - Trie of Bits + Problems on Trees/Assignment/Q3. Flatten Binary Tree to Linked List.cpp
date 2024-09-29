/*
Problem Description

Given a binary tree A, flatten it to a linked list in-place.

The left child of all nodes should be NULL.



Problem Constraints

1 <= size of tree <= 100000



Input Format

First and only argument is the head of tree A.



Output Format

Return the linked-list after flattening.



Example Input

Input 1:

     1
    / \
   2   3
Input 2:

         1
        / \
       2   5
      / \   \
     3   4   6


Example Output

Output 1:

1
 \
  2
   \
    3
Output 2:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6


Example Explanation

Explanation 1:

 Tree flattening looks like this.
Explanation 2:

 Tree flattening looks like this.

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
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    TreeNode* temp = A;
    while(temp) {
        if (temp->left) {
            TreeNode* right_most = temp->left;
            while(right_most->right) right_most = right_most->right;

            right_most->right = temp->right;
            temp->right = temp->left;
            temp->left = nullptr;
        }
        temp = temp->right;
    }

    return A;
}
