/*
Problem Description

Two elements of a Binary Search Tree (BST), represented by root A are swapped by mistake. Tell us the 2 values, when swapped, will restore the Binary Search Tree (BST).

A solution using O(n) space is pretty straightforward. Could you devise a constant space solution?

Note: The 2 values must be returned in ascending order



Problem Constraints

1 <= size of tree <= 100000



Input Format

First and only argument is the head of the tree,A



Output Format

Return the 2 elements which need to be swapped.



Example Input

Input 1:

         1 
        / \ 
       2   3
Input 2:

 
         2
        / \
       3   1



Example Output

Output 1:

 [2, 1]
Output 2:

 [3, 1]


Example Explanation

Explanation 1:

Swapping 1 and 2 will change the BST to be 
         2
        / \
       1   3
which is a valid BST 
Explanation 2:

Swapping 1 and 3 will change the BST to be 
         2
        / \
       1   3
which is a valid BST 
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
vector<int> Solution::recoverTree(TreeNode* A) {
    int prev = INT_MIN;
    int f = -1;
    int s = -1;

    TreeNode* curr = A;
    while (curr) {
        if (prev > curr->val) {
            if (f == -1) {
                f = prev;
                s = curr->val;
            }
            else s = curr->val;
        }

        if (!curr->left) {
            prev = curr->val;
            curr = curr->right;
        }
        else {
            TreeNode* temp = curr->left;

            while(temp->right && temp->right != curr) temp = temp->right;

            if (!temp->right) {
                temp->right = curr;
                curr = curr->left;
            }
            else {
                temp->right = nullptr;
                prev = curr->val;
                curr = curr->right;
            }
        }
    }

    return {s, f};
}
