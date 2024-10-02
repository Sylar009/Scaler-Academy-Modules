/*
Problem Description

Find largest distance Given an arbitrary unweighted rooted tree which consists of N (2 <= N <= 40000) nodes.

The goal of the problem is to find largest distance between two nodes in a tree. Distance between two nodes is a number of edges on a path between the nodes (there will be a unique path between any pair of nodes since it is a tree).

The nodes will be numbered 0 through N - 1.

The tree is given as an array A, there is an edge between nodes A[i] and i (0 <= i < N). Exactly one of the i's will have A[i] equal to -1, it will be root node.



Problem Constraints

2 <= |A| <= 40000



Input Format

First and only argument is vector A



Output Format

Return the length of the longest path



Example Input

Input 1:

 
A = [-1, 0]
Input 2:

 
A = [-1, 0, 0]


Example Output

Output 1:

 1
Output 2:

 2


Example Explanation

Explanation 1:

 Path is 0 -> 1.
Explanation 2:

 Path is 1 -> 0 -> 2.
*/

int max_height_of_tree(int idx, vector<vector<int> > &li, int & res) {
    int max_1 = 0;
    int max_2 = 0;
    for (int i = 0; i < li[idx].size(); i++) {
        int t = max_height_of_tree(li[idx][i], li, res);
        if (t >= max_1) {
            max_2 = max_1;
            max_1 = t;
        }
        if (t > max_2 && t != max_1) max_2 = t;
    }

    res = max(res, 1 + max_1 + max_2);
    return 1 + max(max_1, max_2);
}
int Solution::solve(vector<int> &A) {
    int res = 0;
    vector<vector<int> > li(A.size(), vector<int>());
    int idx = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == -1) idx = i;
        else li[A[i]].push_back(i);
    }

    max_height_of_tree(idx, li, res);

    return res-1;
}
