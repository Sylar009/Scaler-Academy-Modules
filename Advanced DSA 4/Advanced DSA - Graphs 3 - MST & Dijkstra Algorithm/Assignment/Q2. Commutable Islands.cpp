/*
Problem Description

There are A islands and there are M bridges connecting them. Each bridge has some cost attached to it.

We need to find bridges with minimal cost such that all islands are connected.

It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each other.



Problem Constraints

1 <= A, M <= 6*104

1 <= B[i][0], B[i][1] <= A

1 <= B[i][2] <= 103



Input Format

The first argument contains an integer, A, representing the number of islands.

The second argument contains an 2-d integer matrix, B, of size M x 3 where Island B[i][0] and B[i][1] are connected using a bridge of cost B[i][2].



Output Format

Return an integer representing the minimal cost required.



Example Input

Input 1:

 A = 4
 B = [  [1, 2, 1]
        [2, 3, 4]
        [1, 4, 3]
        [4, 3, 2]
        [1, 3, 10]  ]
Input 2:

 A = 4
 B = [  [1, 2, 1]
        [2, 3, 2]
        [3, 4, 4]
        [1, 4, 3]   ]


Example Output

Output 1:

 6
Output 2:

 6


Example Explanation

Explanation 1:

 We can choose bridges (1, 2, 1), (1, 4, 3) and (4, 3, 2), where the total cost incurred will be (1 + 3 + 2) = 6.
Explanation 2:

 We can choose bridges (1, 2, 1), (2, 3, 2) and (1, 4, 3), where the total cost incurred will be (1 + 2 + 3) = 6.


*/

bool comparator_func(vector<int> &A, vector<int> &B) {
    return A[2] < B[2];
}

int get_parent(int node, vector<int> &parent) {
    if (parent[node] == node) return node;
    return get_parent(parent[node], parent);
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> parent(A+1);
    for (int i = 0; i <= A; i++) parent[i] = i;

    int res = 0;
    sort(B.begin(), B.end(), comparator_func);
    for (int i = 0; i < B.size(); i++) {
        int p1 = get_parent(B[i][0], parent);
        int p2 = get_parent(B[i][1], parent);
        if (p1 != p2) {
            res += B[i][2];
            parent[max(p1, p2)] = min(p1, p2);
        }
    }

    return res;
}
