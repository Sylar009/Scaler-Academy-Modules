/*
Problem Description

Find the lowest common ancestor in an unordered binary tree A, given two values, B and C, in the tree.


Lowest common ancestor: the lowest common ancestor (LCA) of two nodes and w in a tree or directed acyclic graph (DAG) is the lowest (i.e., deepest) node that has both v and w as descendants.




Problem Constraints

1 <= size of tree <= 100000

1 <= B, C <= 109



Input Format

First argument is head of tree A.

Second argument is integer B.

Third argument is integer C.



Output Format

Return the LCA.



Example Input

Input 1:

 
      1
     /  \
    2    3
B = 2
C = 3
Input 2:

      1
     /  \
    2    3
   / \
  4   5
B = 4
C = 5


Example Output

Output 1:

 1
Output 2:

 2


Example Explanation

Explanation 1:

 LCA is 1.
Explanation 2:

 LCA is 2.

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

bool get_path(TreeNode* A, int B, vector<TreeNode* > &C) {
    if (!A) return false;

    if (A->val == B) {
        C.push_back(A);
        return true;
    }

    if (get_path(A->right, B, C)) {
        C.push_back(A);
        return true;
    }

    if (get_path(A->left, B, C)) {
        C.push_back(A);
        return true;
    }

    return false;
}

int Solution::lca(TreeNode* A, int B, int C) {
    int res = -1;
    vector<TreeNode* > x;
    vector<TreeNode* > y;

    get_path(A, B, x);
    get_path(A, C, y);

    unordered_map<int, int> hm;
    for (int i = 0; i < y.size(); i++) hm[y[i]->val] = 1;
    for (int j = x.size()-1; j >= 0; j--) if (hm.find(x[j]->val) != hm.end()) res = x[j]->val;

    return res;

}
