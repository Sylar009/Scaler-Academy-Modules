/*
Problem Description

Given a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).



Problem Constraints

1 <= number of nodes <= 105



Input Format

First and only argument is root node of the binary tree, A.



Output Format

Return a 2D integer array denoting the level order traversal of the given binary tree.



Example Input

Input 1:

    3
   / \
  9  20
    /  \
   15   7
Input 2:

   1
  / \
 6   2
    /
   3


Example Output

Output 1:

 [
   [3],
   [9, 20],
   [15, 7]
 ]
Output 2:

 [ 
   [1]
   [6, 2]
   [3]
 ]


Example Explanation

Explanation 1:

 Return the 2D array. Each row denotes the traversal of each level.

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

vector<vector<int> > Solution::solve(TreeNode* root) {
    queue<TreeNode*> qu;
    vector<vector<int> > res;

    if (!root) return  res; 

    qu.push(root);
    
    while (!qu.empty()) {
        int len = qu.size();
        vector<int> temp;
        for (int i = 0; i < len; i++) {
            TreeNode * nn = qu.front();
            qu.pop();
            temp.push_back(nn->val);
            if (nn->left) qu.push(nn->left);
            if (nn->right) qu.push(nn->right);
        }
        res.push_back(temp);
    }

    return res;
}
