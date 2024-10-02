/*
Problem Description

Given an integer A, representing number of vertices in a graph.

Also you are given a matrix of integers B of size N x 3 where N represents number of Edges in a Graph and Triplet (B[i][0], B[i][1], B[i][2]) implies there is an undirected edge between B[i][0] and B[i][1] and weight of that edge is B[i][2].

Find and return the weight of minimum weighted cycle and if there is no cycle return -1 instead.

NOTE: Graph may contain self loops but does not have duplicate edges.



Problem Constraints

1 <= A <= 1000

1 <= B[i][0], B[i][1] <= A

1 <= B[i][2] <= 100000



Input Format

The first argument given is the integer A.

The second argument given is the integer matrix B.



Output Format

Return the weight of minimum weighted cycle and if there is no cycle return -1 instead.



Example Input

Input 1:

 A = 4
 B = [  [1 ,2 ,2]
        [2 ,3 ,3]
        [3 ,4 ,1]
        [4 ,1 ,4]
        [1 ,3 ,15]  ]
Input 2:

 A = 3
 B = [  [1 ,2 ,2]
        [2 ,3 ,3]  ]


Example Output

Output 1:

 10 
Output 2:

 -1


Example Explanation

Explanation 1:

 Given graph forms 3 cycles
 1. 1 ---> 2 ---> 3 ---> 4 ---> 1 weight = 10
 2. 1 ---> 2 ---> 3 ---> 1 weight = 20
 3. 1 ---> 3---> 4 ---> 1 weight = 20
 so answer would be 10.
Explanation 2:

 Given graph forms 0 cycles so return -1.

*/

void dfs(int idx, int prev, int sum, vector<bool> &cycle, 
vector<vector<pair<int,int>> > &adj, int &res) {
    if (cycle[idx]) {
        res = min(res, sum);
        return;
    }

    cycle[idx] = true;
    for (pair<int,int> n : adj[idx]) {
        if (n.first != prev) {
            dfs(n.first, idx, sum + n.second, cycle, adj, res);
        }
    }
    cycle[idx] = false;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    int res = INT_MAX;
    vector<bool> vis(A+1);
    vector<bool> cycle(A+1);
    vector<vector<pair<int,int>> > adj(A+1, vector<pair<int, int> >());
    for (int i = 0; i < B.size(); i++) {
        adj[B[i][0]].push_back(make_pair(B[i][1], B[i][2]));
        adj[B[i][1]].push_back(make_pair(B[i][0], B[i][2]));
    } 
    for (int i = 1; i <= A; i++) {
        dfs (i, 0 , 0, cycle, adj, res);
    }

    return (res == INT_MAX) ? -1 : res;
}
