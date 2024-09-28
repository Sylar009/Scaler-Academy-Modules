/*
Problem Description

Given preorder and inorder traversal of a tree, construct the binary tree.

NOTE: You may assume that duplicates do not exist in the tree.



Problem Constraints

1 <= number of nodes <= 105



Input Format

First argument is an integer array A denoting the preorder traversal of the tree.

Second argument is an integer array B denoting the inorder traversal of the tree.



Output Format

Return the root node of the binary tree.



Example Input

Input 1:

 A = [1, 2, 3]
 B = [2, 1, 3]
Input 2:

 A = [1, 6, 2, 3]
 B = [6, 1, 3, 2]


Example Output

Output 1:

   1
  / \
 2   3
Output 2:

   1  
  / \
 6   2
    /
   3


Example Explanation

Explanation 1:

 Create the binary tree and return the root node of the tree.

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
TreeNode* create(vector<int>& pre_order, int start1, int end1,
                 vector<int>& inorder, int start2, int end2,
                 unordered_map<int, int> &hm) {

    if (start1 > end1) return nullptr;

    TreeNode* nn = new TreeNode(pre_order[start1]);

    int val = hm[pre_order[start1]] - start2;

    nn->right = create(pre_order, start1 + val + 1, end1, inorder, hm[pre_order[start1]] + 1, end2, hm);

    nn->left = create(pre_order, start1 + 1, start1 + val, inorder, start2, hm[pre_order[start1]] - 1, hm );
    
    return nn;

}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    
    unordered_map<int, int> hm;

    for (int i =0; i < B.size(); i++) hm [B[i]] = i;

    return create(A, 0, A.size()-1, B, 0, B.size()-1, hm);
    
}
