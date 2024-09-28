/*
Problem Description

Given a root of binary tree A, determine if it is height-balanced.

A height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.



Problem Constraints

1 <= size of tree <= 100000



Input Format

First and only argument is the root of the tree A.



Output Format

Return 0 / 1 ( 0 for false, 1 for true ) for this problem.



Example Input

Input 1:

    1
   / \
  2   3
Input 2:

 
       1
      /
     2
    /
   3


Example Output

Output 1:

1
Output 2:

0


Example Explanation

Explanation 1:

It is a complete binary tree.
Explanation 2:

Because for the root node, left subtree has depth 2 and right subtree has depth 0. 
Difference = 2 > 1. 

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
pair<bool,int> post_ordered_traversal(TreeNode* A){
    if(!A){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    pair<bool,int> left = post_ordered_traversal(A->left);
    pair<bool,int> right = post_ordered_traversal(A->right);

    bool left_res = left.first;
    bool right_res = right.first;
    bool diff = abs(left.second - right.second) <=1;

    pair<bool,int> res;
    res.second = max(left.second,right.second) +1;

    if(left_res && right_res && diff){
        res.first = true;
    }
    else{
        res.first = false;
    }

    return res;
}

int Solution::isBalanced(TreeNode* A) {
    int res = post_ordered_traversal(A).first;
    return res;
}
