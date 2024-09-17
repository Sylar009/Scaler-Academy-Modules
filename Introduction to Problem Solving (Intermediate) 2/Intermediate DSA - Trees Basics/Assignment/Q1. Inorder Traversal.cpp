/*
Problem Description
Given a binary tree, return the inorder traversal of its nodes' values.



Problem Constraints
1 <= number of nodes <= 105



Input Format
First and only argument is root node of the binary tree, A.



Output Format
Return an integer array denoting the inorder traversal of the given binary tree.



Example Input
Input 1:

   1
    \
     2
    /
   3
Input 2:

   1
  / \
 6   2
    /
   3


Example Output
Output 1:

 [1, 3, 2]
Output 2:

 [6, 1, 3, 2]


Example Explanation
Explanation 1:

 The Inorder Traversal of the given tree is [1, 3, 2].
Explanation 2:

 The Inorder Traversal of the given tree is [6, 1, 3, 2].

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
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> res;
    if (!A) return res;

    TreeNode* curr_node = A;
    while (curr_node) {
        if (!curr_node->left) {
            res.push_back(curr_node->val);
            curr_node = curr_node->right;
        }
        else {
            TreeNode* prev_node = curr_node->left;
            while (prev_node->right && prev_node->right != curr_node){
                prev_node = prev_node->right;
            }

            if (!prev_node->right) {
                prev_node->right = curr_node;
                curr_node = curr_node->left;
            }
            else {
                prev_node->right = NULL;
                res.push_back(curr_node->val);
                curr_node = curr_node->right;
            }
        }
    }

    return res;
}
