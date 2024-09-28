/*
Problem Description

Given a binary tree, return the zigzag level order traversal of its nodes values. (ie, from left to right, then right to left for the next level and alternate between).



Problem Constraints

1 <= number of nodes <= 105



Input Format

First and only argument is root node of the binary tree, A.



Output Format

Return a 2D integer array denoting the zigzag level order traversal of the given binary tree.



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
   [20, 9],
   [15, 7]
 ]
Output 2:

 [ 
   [1]
   [2, 6]
   [3]
 ]


Example Explanation

Explanation 1:

 Return the 2D array. Each row denotes the zigzag traversal of each level.
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
void zig_zag(TreeNode* A, vector<vector<int> >& res, bool is_left, int level){
    
    if(A == nullptr) {
        return;
    }
    
    if(res.size() < level) {
        vector<int> x;
        res.push_back(x);
    }

    if(is_left) {
        res[level - 1].push_back( A->val );
    }
    else {
        res[level - 1].insert( res[ level - 1 ].begin(), A->val);
    }
    
    zig_zag(A->left, res, !is_left, level+1);
    zig_zag(A->right, res, !is_left, level+1);    
}

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    
    vector<vector<int> > res;
    
    zig_zag(A, res, true, 1);
    
    return res;
}
