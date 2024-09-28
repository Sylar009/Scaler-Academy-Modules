/*
Problem Description

Given a binary tree T, find the maximum path sum.

The path may start and end at any node in the tree.

Note: A maximum sum path is any path which has the maximum sum of the nodes lying on the path.



Problem Constraints

1 <= Number of Nodes <= 7e4

-1000 <= Value of Node in T <= 1000



Input Format

The first and the only argument contains a pointer to the root of T, A.



Output Format

Return an integer representing the maximum sum path.



Example Input

Input 1:

  
    1
   / \
  2   3
Input 2:

       20
      /  \
   -10   20
        /  \
      -10  -50


Example Output

Output 1:

 6
Output 2:

 40


Example Explanation

Explanation 1:

     The path with maximum sum is: 2 -> 1 -> 3
Explanation 2:

     The path with maximum sum is: 20 -> 20


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
int dfs(TreeNode* A, int & res) {
    if (A == nullptr) return 0;
    int max_val = INT_MIN;
    int node_max_val = 0;
    int left = dfs(A->left, res);
    int right = dfs(A->right, res);
    max_val = max(max_val, left + A->val);
    max_val = max(max_val, right + A->val);
    max_val = max(max_val, A->val);
    node_max_val = max_val;
    max_val = max( left + right + A->val, max_val);
    res = max(res, max_val);
    return node_max_val;
}

int Solution::maxPathSum(TreeNode* A) {    
    int res = INT_MIN;    
    dfs(A, res);    
    return res;
}
