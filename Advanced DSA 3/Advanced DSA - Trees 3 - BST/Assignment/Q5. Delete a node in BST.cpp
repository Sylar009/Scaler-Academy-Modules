/*
Problem Description

Given a Binary Search Tree(BST) A. If there is a node with value B present in the tree delete it and return the tree.

Note - If there are multiple options, always replace a node by its in-order predecessor


Problem Constraints

2 <= No. of nodes in BST <= 105
1 <= value of nodes <= 109
Each node has a unique value


Input Format

The first argument is the root node of a Binary Search Tree A.
The second argument is the value B.


Output Format

Delete the given node if found and return the root of the BST.


Example Input

Input 1:

            15
          /    \
        12      20
        / \    /  \
       10  14  16  27
      /
     8

     B = 10

Input 2:

            8
           / \
          6  21
         / \
        1   7

     B = 6



Example Output

Output 1:

            15
          /    \
        12      20
        / \    /  \
       8  14  16  27

Output 2:

            8
           / \
          1  21
           \
            7



Example Explanation

Explanation 1:

Node with value 10 is deleted 
Explanation 2:

Node with value 6 is deleted 


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
TreeNode* delete_node(TreeNode* A, int  B) {
    if (!A) return nullptr;
    if (A->val > B) A->left = delete_node(A->left, B);
    else if (A->val < B) A->right = delete_node(A->right, B);
    else {
        if (!A->left && !A->right) return nullptr;
        else if (!A->left) return A->right;
        else if (!A->right) return A->left;
        else {
            TreeNode* smallest = A->left;
            while (smallest->right) smallest = smallest->right;
            A->val = smallest->val;
            A->left = delete_node(A->left, smallest->val);
        }
    }

    return A;
}

TreeNode* Solution::solve(TreeNode* A, int B) {
    return delete_node(A, B);
}
