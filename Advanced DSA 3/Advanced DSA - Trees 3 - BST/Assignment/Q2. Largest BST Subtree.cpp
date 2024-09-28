/*
Problem Description

You are given a Binary Tree A with N nodes.


Write a function that returns the size of the largest subtree, which is also a Binary Search Tree (BST).

If the complete Binary Tree is BST, then return the size of the whole tree.

NOTE:

The largest subtree is the subtree with the most number of nodes.



Problem Constraints

1 <= N <= 105



Input Format

First and only argument is an pointer to root of the binary tree A.



Output Format

Return an single integer denoting the size of the largest subtree which is also a BST.



Example Input

Input 1:

     10
    / \
   5  15
  / \   \ 
 1   8   7
Input 2:

     5
    / \
   3   8
  / \ / \
 1  4 7  9


Example Output

Output 1:

 3
Output 2:

 7


Example Explanation

Explanation 1:

 Largest BST subtree is
                            5
                           / \
                          1   8
Explanation 2:

 Given binary tree itself is BST.
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
struct pair1 {
public:
    int max;
    int min;
    int size;
    bool validBst;
};

pair1 helper(TreeNode* A) {
    if (!A) {
        pair1 bp;
        bp.max = INT_MIN;
        bp.min = INT_MAX;
        bp.size = 0;
        bp.validBst = true;
        return bp;
    }

    pair1 lp = helper(A->left);
    pair1 rp = helper(A->right);

    pair1 mp;
    mp.max = max(A->val, max(lp.max, rp.max));
    mp.min = min(A->val, max(lp.min, rp.min));

    if (!lp.validBst || !rp.validBst) {
        mp.size = max(lp.size, rp.size);
        mp.validBst = false;
        return mp;
    }
    else if (A->val < lp.max || A->val > rp.min){
        mp.size = max(lp.size, rp.size);
        mp.validBst = false;
        return mp;
    }
    else {
        mp.validBst = true;
        mp.size = lp.size + rp.size + 1;
        return mp;
    }
}

int Solution::solve(TreeNode* A) {
    return helper(A).size;
}
