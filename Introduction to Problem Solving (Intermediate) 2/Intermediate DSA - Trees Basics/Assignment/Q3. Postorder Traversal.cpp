/*
Problem Description
Given a binary tree, return the Postorder traversal of its nodes values.



Problem Constraints
1 <= number of nodes <= 105



Input Format
First and only argument is root node of the binary tree, A.



Output Format
Return an integer array denoting the Postorder traversal of the given binary tree.



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

 [3, 2, 1]
Output 2:

 [6, 3, 2, 1]


Example Explanation
Explanation 1:

 The Preoder Traversal of the given tree is [3, 2, 1].
Explanation 2:

 The Preoder Traversal of the given tree is [6, 3, 2, 1].


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
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> res;

    if (!A) return res;

    TreeNode* curr_node = A;
    while (curr_node) {
        if (!curr_node->right) {
            res.push_back(curr_node->val);
            curr_node = curr_node->left;
        }
        else {
            TreeNode* prev_node = curr_node->right;
            while (prev_node->left && prev_node->left != curr_node) {
                prev_node = prev_node->left;
            }

            if (!prev_node->left) {
                prev_node->left = curr_node;
                res.push_back(curr_node->val);
                curr_node = curr_node->right;
            }
            else {
                prev_node->left = NULL;
                curr_node = curr_node->left;
            }
        }
    }

    reverse(res.begin(), res.end());
    return res;
}
