/*
Problem Description

Given a weighted undirected graph having A nodes, a source node C and destination node D.

Find the shortest distance from C to D and if it is impossible to reach node D from C then return -1.

You are expected to do it in Time Complexity of O(A + M).

Note:

There are no self-loops in the graph.

No multiple edges between two pair of vertices.

The graph may or may not be connected.

Nodes are Numbered from 0 to A-1.

Your solution will run on multiple testcases. If you are using global variables make sure to clear them.



Problem Constraints

1 <= A <= 105

0 <= B[i][0], B[i][1] < A

1 <= B[i][2] <= 2

0 <= C < A

0 <= D < A



Input Format

The first argument given is an integer A, representing the number of nodes.

The second argument given is the matrix B, where B[i][0] and B[i][1] are connected through an edge of weight B[i][2].

The third argument given is an integer C, representing the source node.

The fourth argument is an integer D, representing the destination node.

Note: B[i][2] will be either 1 or 2.



Output Format

Return the shortest distance from C to D. If it is impossible to reach node D from C then return -1.



Example Input

Input 1:

 
A = 6
B = [   [2, 5, 1]
        [1, 3, 1] 
        [0, 5, 2] 
        [0, 2, 2] 
        [1, 4, 1] 
        [0, 1, 1] ] 
C = 3
D = 2
Input 2:

A = 2
B = [   [0, 1, 1]
    ] 
C = 0
D = 1


Example Output

Output 1:

 4
Output 2:

 1


Example Explanation

Explanation 1:

The path to be followed will be:
    3 -> 1 (Edge weight : 1)
    1 -> 0 (Edge weight : 1)
    0 -> 2 (Edge weight : 2)
Total length of path = 1 + 1 + 2 = 4.
Explanation 2:

 Path will be 0-> 1.

*/

/*******************************************************************
It is given that the weight of the edge can either be 1 or 2, so if we split the
 edge having weight 2 with into two edges, the shortest distance could be found
 using BFS.
Make an adjacency matrix from the given edges and if the weight of the edge (u,v)
 is 2, split the edge into two with a temp node such that (u,temp) and (temp, v)
  are new edges with weight 1. Since all weights are 1, it need not be maintained.

Make an array to store the distance from the source, initialise it with -1.
Initialise distance array of source as 0, and push source node into queue.
Perform BFS and return the distance of destination.

TC: O(E+V) : traversing over edges
SC: O(2E+2V) = O(E+V) : space for adjacency list, distance array and queue

**************************************************************************/

int Solution::solve(int A, vector<vector<int> > &B, int C, int D) {
    int n = (B.size() > A) ? B.size() : A;
    vector<vector<int> > adj(2*n);
    vector<int> dist(2*n, -1);
    queue<int> qu;

    for (int i= 0; i < B.size(); i++) {
        if (B[i][2] == 2) {
            adj[B[i][0]].push_back(A+i);
            adj[A+i].push_back(B[i][1]);

            adj[B[i][1]].push_back(A+i);
            adj[A+i].push_back(B[i][0]);
        }
        else {
            adj[B[i][0]].push_back(B[i][1]);
            adj[B[i][1]].push_back(B[i][0]);
        }
    }

    dist[C] = 0;

    qu.push(C);

    while(!qu.empty()) {
        int u = qu.front();
        qu.pop();

        if (u == D) break;

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                qu.push(v);
            }
        }
    }

    return dist[D];
}
