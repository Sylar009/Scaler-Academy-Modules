/*
Problem Description

Given a graph with A nodes and C weighted edges. Cost of constructing the graph is the sum of weights of all the edges in the graph.

Find the minimum cost of constructing the graph by selecting some given edges such that we can reach every other node from the 1st node.

NOTE: Return the answer modulo 109+7 as the answer can be large.



Problem Constraints

1 <= A <= 100000
0 <= C <= 100000
1 <= B[i][0], B[i][1] <= N
1 <= B[i][2] <= 109



Input Format

First argument is an integer A.
Second argument is a 2-D integer array B of size C*3 denoting edges. B[i][0] and B[i][1] are connected by ith edge with weight B[i][2]



Output Format

Return an integer denoting the minimum construction cost.



Example Input

Input 1:

A = 3
B = [   [1, 2, 14]
        [2, 3, 7]
        [3, 1, 2]   ]
Input 2:

A = 3
B = [   [1, 2, 20]
        [2, 3, 17]  ]


Example Output

Output 1:

9
Output 2:

37


Example Explanation

Explanation 1:

We can take only two edges (2 -> 3 and 3 -> 1) to construct the graph. 
we can reach the 1st node from 2nd and 3rd node using only these two edges.
So, the total cost of costruction is 9.
Explanation 2:

We have to take both the given edges so that we can reach the 1st node from 2nd and 3rd node.


*/

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<pair<int, int>> adj_li[A+1];
    for (auto x : B) {
        adj_li[x[0]].push_back({x[1], x[2]});
        adj_li[x[1]].push_back({x[0], x[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > pq;
    pq.push({0,1});

    vector<int> dist(A+1, INT_MAX);

    while (pq.size() > 0) {
        int el = pq.top().second;
        int wt = pq.top().first;

        pq.pop();
        if (dist[el] != INT_MAX) continue;
        dist[el] = wt;

        for (auto x : adj_li[el]) {
            int n = x.first;
            int w = x.second;
            if (dist[n] == INT_MAX) pq.push({w, n});
        }
    }

    int res = 0;
    for (int i = 1; i <= A; i++) res = (res + dist[i]) % 1000000007;

    return res;
}
