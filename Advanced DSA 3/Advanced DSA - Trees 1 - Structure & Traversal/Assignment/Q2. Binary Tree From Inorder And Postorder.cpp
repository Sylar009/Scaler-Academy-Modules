/*
Problem Description

Given the inorder and postorder traversal of a tree, construct the binary tree.



NOTE: You may assume that duplicates do not exist in the tree.





Problem Constraints

1 <= number of nodes <= 105



Input Format

First argument is an integer array A denoting the inorder traversal of the tree.

Second argument is an integer array B denoting the postorder traversal of the tree.



Output Format

Return the root node of the binary tree.



Example Input

Input 1:

 A = [2, 1, 3]
 B = [2, 3, 1]
Input 2:

 A = [6, 1, 3, 2]
 B = [6, 3, 2, 1]


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
TreeNode* create(vector<int>& post_order, int start1, int end1,
                 vector<int>& inorder, int start2, int end2,
                 unordered_map<int, int> &hm) {

    if (start1 > end1) return nullptr;

    TreeNode* nn = new TreeNode(post_order[start1]);
    int val = end2 - hm[post_order[start1]];
    nn->right = create(post_order, start1+1, start1+val, inorder, hm[post_order[start1]]+1, end2, hm );
    nn->left = create(post_order, start1+val+1, end1, inorder, start2, hm[post_order[start1]]-1, hm);

    return nn;
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    unordered_map<int, int> hm;
    for (int i =0; i < A.size(); i++) hm [A[i]] = i;

    reverse(B.begin(), B.end());

    return create(B, 0, B.size()-1, A, 0, A.size()-1, hm);
}
