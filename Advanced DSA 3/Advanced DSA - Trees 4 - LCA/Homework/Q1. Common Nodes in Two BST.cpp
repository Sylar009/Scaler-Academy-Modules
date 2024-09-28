/*
Problem Description

Given two BST's A and B, return the (sum of all common nodes in both A and B) % (109 +7) .

In case there is no common node, return 0.

NOTE:

Try to do it one pass through the trees.



Problem Constraints

1 <= Number of nodes in the tree A and B <= 105

1 <= Node values <= 106



Input Format

First argument represents the root of BST A.

Second argument represents the root of BST B.



Output Format

Return an integer denoting the (sum of all common nodes in both BST's A and B) % (109 +7) .



Example Input

Input 1:

 Tree A:
    5
   / \
  2   8
   \   \
    3   15
        /
        9

 Tree B:
    7
   / \
  1  10
   \   \
    2  15
       /
      11
Input 2:

  Tree A:
    7
   / \
  1   10
   \   \
    2   15
        /
       11

 Tree B:
    7
   / \
  1  10
   \   \
    2  15
       /
      11


Example Output

Output 1:

 17
Output 2:

 46


Example Explanation

Explanation 1:

 Common Nodes are : 2, 15
 So answer is 2 + 15 = 17
Explanation 2:

 Common Nodes are : 7, 2, 1, 10, 15, 11
 So answer is 7 + 2 + 1 + 10 + 15 + 11 = 46

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
int print_common(TreeNode* A, TreeNode* B) {

    stack<TreeNode*> st_1;
    stack<TreeNode*> st_2;

    long sum = 0;

    while (true) {
        if (A != nullptr) {
            st_1.push(A);
            A = A->left;
        }
        else if (B != nullptr) {
            st_2.push(B);
            B = B->left;
        }
        else if (!st_1.empty() && !st_2.empty()) {
            A = st_1.top();
            B = st_2.top();

            if (A->val == B->val) {
                sum = (sum + A->val ) % 1000000007;
                st_1.pop();
                st_2.pop();

                A = A->right;
                B = B->right;
            }
            else if (A->val < B->val) {
                st_1.pop();
                A = A->right;
                B = nullptr;
            }
            else if (A->val > B->val) {
                st_2.pop();
                B = B->right;
                A = nullptr;
            }
        }
        else break;
    }

    return sum%1000000007;

}

int Solution::solve(TreeNode* A, TreeNode* B) {
    return print_common(A, B);
}
