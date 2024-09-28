/*
Problem Description

You are given an integer array A denoting the Level Order Traversal of the Binary Tree.





You have to Deserialize the given Traversal in the Binary Tree and return the root of the Binary Tree.

NOTE:





In the array, the NULL/None child is denoted by -1.
For more clarification check the Example Input.


Problem Constraints

1 <= number of nodes <= 105

-1 <= A[i] <= 105



Input Format

Only argument is an integer array A denoting the Level Order Traversal of the Binary Tree.



Output Format

Return the root node of the Binary Tree.



Example Input

Input 1:

 A = [1, 2, 3, 4, 5, -1, -1, -1, -1, -1, -1]
Input 2:

 A = [1, 2, 3, 4, 5, -1, 6, -1, -1, -1, -1, -1, -1]


Example Output

Output 1:

           1
         /   \
        2     3
       / \
      4   5
Output 2:

            1
          /   \
         2     3
        / \ .   \
       4   5 .   6


Example Explanation

Explanation 1:

 Each element of the array denotes the value of the node. If the val is -1 then it is the NULL/None child.
 Since 3, 4 and 5 each has both NULL child we had represented that using -1.
Explanation 2:

 Each element of the array denotes the value of the node. If the val is -1 then it is the NULL/None child.
 Since 3 has left child as NULL while 4 and 5 each has both NULL child.

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
TreeNode* Solution::solve(vector<int> &A) {

    queue<TreeNode*> qu;

    int i = 0;

    TreeNode* root = new TreeNode(A[0]);

    qu.push(root);

    qu.push(NULL);

    while( (2 * i + 1) < A.size() ) {

        TreeNode* curr = qu.front();

        qu.pop();

        if( curr != nullptr) {

            if(A[2*i + 1] != -1 ) curr->left = new TreeNode(A[2*i + 1]);

            if(A[2*i + 2] != -1) curr->right = new TreeNode(A[2*i + 2]);

            if(curr->left != nullptr) qu.push(curr->left);

            if(curr->right != nullptr) qu.push(curr->right);

            i++;

        }

        else qu.push(NULL);
        
    }
    
    return root;
}
