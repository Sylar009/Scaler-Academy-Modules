/*
Problem Description

Given a binary tree, return the preorder traversal of its nodes values.



Problem Constraints

1 <= number of nodes <= 105



Input Format

First and only argument is root node of the binary tree, A.



Output Format

Return an integer array denoting the preorder traversal of the given binary tree.



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

 [1, 2, 3]
Output 2:

 [1, 6, 2, 3]



Example Explanation

Explanation 1:

 The Preoder Traversal of the given tree is [1, 2, 3].
Explanation 2:

 The Preoder Traversal of the given tree is [1, 6, 2, 3].


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
vector<int> Solution::preorderTraversal(TreeNode* A) {    
    vector<int> res;
    TreeNode* curr = A;
    stack<TreeNode*> st;    
    if(A == nullptr) {
        return res;
    }
    
    do {
        if(curr == nullptr) {
            curr = st.top();
            st.pop();
            curr = curr->right;
            if(curr != nullptr) {
                res.push_back(curr->val);
                st.push(curr);
                curr = curr->left;
            }            
        }
        else {
            res.push_back(curr->val);
            st.push(curr);
            curr = curr->left;
        }
    } while(!st.empty());
    
    return res;
}
