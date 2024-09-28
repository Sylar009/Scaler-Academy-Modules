/*
Problem Description

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.



Problem Constraints

1 <= number of nodes <= 105

-100000 <= B, value of nodes <= 100000



Input Format

First argument is a root node of the binary tree, A.

Second argument is an integer B denoting the sum.



Output Format

Return 1, if there exist root-to-leaf path such that adding up all the values along the path equals the given sum. Else, return 0.



Example Input

Input 1:

 Tree:    5
         / \
        4   8
       /   / \
      11  13  4
     /  \      \
    7    2      1

 B = 22
Input 2:

 Tree:    5
         / \
        4   8
       /   / \
     -11 -13  4

 B = -1


Example Output

Output 1:

 1
Output 2:

 0


Example Explanation

Explanation 1:

 There exist a root-to-leaf path 5 -> 4 -> 11 -> 2 which has sum 22. So, return 1.
Explanation 2:

 There is no path which has sum -1.

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
void is_path_exist (TreeNode* A, int B, int C, int &D) {
    if (D == 0) {
        if (A == nullptr) return;
        C += A->val;
        if (A->left == nullptr && A->right == nullptr && C == B) D = 1;
        is_path_exist(A->left, B, C, D);
        is_path_exist(A->right, B, C, D);
    }
} 
int Solution::hasPathSum(TreeNode* A, int B) {
    int is_path_sum = 0;
    is_path_exist(A, B, 0, is_path_sum);
    return is_path_sum;
}
