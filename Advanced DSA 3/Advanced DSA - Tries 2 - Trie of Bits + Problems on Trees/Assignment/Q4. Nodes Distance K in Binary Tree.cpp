/*
Problem Description

Given the root of a binary tree A, the value of a target node B, and an integer C.

Return an array of the values of all nodes that have a distance C from the target node B.

Note :- The target node B always exist. All the nodes has unique value



Problem Constraints

1 <= number of nodes <= 105

1 <= B <= 105

1 <= C <= 105



Input Format

First argument is the root node of the binary tree, A.

Second argument is an integer denoting the value of the target node B.

Third argument is an integer denoting C.



Output Format

Return an integer array denoting the nodes at a distance C from targer node B




Example Input

Input 1:

A = 1
     \
      2
     /
    3

B = 2
C = 1
Input 2:

A = 1
   / \
  6   2
     /
    3

B = 6
C = 2


Example Output

Output 1:

 [1, 3]
Output 2:

 [2]


Example Explanation

Explanation 1:

 The nodes 1 and 3 are at a distance 1 from node 2.
Explanation 2:

 The node 2 is at a distance 2 from node 6.


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
TreeNode* tn;

TreeNode* search_target(TreeNode* A, int B) {
    if (!A) return nullptr;
    if (A->val == B) tn = A;

    search_target(A->left, B);
    search_target(A->right, B);

    return tn;
} 

void mark_parents(TreeNode* A, 
                unordered_map<TreeNode*, TreeNode*> &hm, 
                TreeNode* tar) {
    queue<TreeNode*> qu;
    qu.push(A);
    while (!qu.empty()) {
        TreeNode* cur = qu.front();
        qu.pop();
        if (cur->left) {
            hm[cur->left] = cur;
            qu.push(cur->left);
        } 

        if (cur->right) {
            hm[cur->right] = cur;
            qu.push(cur->right);
        }   
    }                    
}


vector<int> Solution::solve(TreeNode* A, int B, int C) {
    if (C == 0) return {B};

    TreeNode* tar = search_target(A, B);

    unordered_map<TreeNode*, TreeNode*> hm;
    mark_parents(A, hm, tar);

    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode* > qu;

    qu.push(tar);
    visited[tar] = true;
    int dist = 0;

    while (!qu.empty()) {
        int sz = qu.size();
        if (dist == C) break;
        dist++;

        for (int i = 0; i < sz; i++) {
            TreeNode* cur = qu.front();
            qu.pop();
            if (cur->left && !visited[cur->left]) {
                qu.push(cur->left);
                visited[cur->left] = true;
            }

            if (cur->right && !visited[cur->right]) {
                qu.push(cur->right);
                visited[cur->right] = true;
            }

            if (hm[cur] && !visited[hm[cur]]) {
                qu.push(hm[cur]);
                visited[hm[cur]] = true;
            }
        }
    }

    vector<int> res;
    while (!qu.empty()) {
        TreeNode* cur = qu.front();
        qu.pop();
        res.push_back(cur->val);
    }

    return res;
}
