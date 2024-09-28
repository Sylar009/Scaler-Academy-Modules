/*
Problem Description

Given two binary trees, check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.




Problem Constraints

1 <= number of nodes <= 105



Input Format

The first argument is a root node of the first tree, A.

The second argument is a root node of the second tree, B.




Output Format

Return 0 / 1 ( 0 for false, 1 for true ) for this problem.



Example Input

Input 1:

   1       1
  / \     / \
 2   3   2   3
Input 2:

   1       1
  / \     / \
 2   3   3   3


Example Output

Output 1:

 1
Output 2:

 0


Example Explanation

Explanation 1:

 Both trees are structurally identical and the nodes have the same value.
Explanation 2:

 Values of the left child of the root node of the trees are different.

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
int is_same_bt(TreeNode* nd_1, TreeNode* nd_2){
    if(nd_1 == nullptr && nd_2 == nullptr){
        return 1;
    }
    else if((nd_1 == nullptr && nd_2 != nullptr) || (nd_1 != nullptr && nd_2 == nullptr)) {
        return 0;
    }
    else if(nd_1->val == nd_2->val) {
        return min(is_same_bt(nd_1->left, nd_2->left), is_same_bt(nd_1->right, nd_2->right));
    }
    return 0;
} 

int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    return is_same_bt(A, B);
}
