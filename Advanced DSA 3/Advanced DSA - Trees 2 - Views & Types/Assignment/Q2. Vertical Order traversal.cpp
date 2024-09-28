/*
Problem Description

Given a binary tree, return a 2-D array with vertical order traversal of it. Go through the example and image for more details.


NOTE: If 2 Tree Nodes shares the same vertical level then the one with lesser depth will come first.



Problem Constraints

0 <= number of nodes <= 105



Input Format

First and only arument is a pointer to the root node of binary tree, A.



Output Format

Return a 2D array denoting the vertical order traversal of tree as shown.



Example Input

Input 1:

      6
    /   \
   3     7
  / \     \
 2   5     9
Input 2:

      1
    /   \
   3     7
  /       \
 2         9


Example Output

Output 1:

 [
    [2],
    [3],
    [6, 5],
    [7],
    [9]
 ]
Output 2:

 [
    [2],
    [3],
    [1],
    [7],
    [9]
 ]


Example Explanation

Explanation 1:

 First row represent the verical line 1 and so on.


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
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector<vector <int> > res;
    map<int, vector<int> > hm;
    queue<pair<int, TreeNode*> > qu;

    qu.push({0, A});

    while (!qu.empty()) {
        auto itr = qu.front();
        qu.pop();
        int val = itr.first;
        TreeNode* nn = itr.second;
        hm[val].push_back(nn->val);
        if (nn->left) qu.push({val-1, nn->left});
        if (nn->right) qu.push({val+1, nn->right});
    }

    for (auto i : hm) res.push_back(i.second);

    return res;
}
