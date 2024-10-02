/*
Problem Description

You are given an undirected unweighted graph consisting of A vertices and M edges given in a form of 2D Matrix B of size M x 2 where (B[i][0], B][i][1]) denotes two nodes connected by an edge.

You have to write a number on each vertex of the graph. Each number should be 1, 2 or 3. The graph becomes Poisonous if for each edge the sum of numbers on vertices connected by this edge is odd.

Calculate the number of possible ways to write numbers 1, 2 or 3 on vertices so the graph becomes poisonous. Since this number may be large, return it modulo 998244353.

NOTE:

Note that you have to write exactly one number on each vertex.
The graph does not have any self-loops or multiple edges.
Nodes are labelled from 1 to A.


Problem Constraints

1 <= A <= 3*105

0 <= M <= 3*105

1 <= B[i][0], B[i][1] <= A

B[i][0] != B[i][1]



Input Format

First argument is an integer A denoting the number of nodes.

Second argument is an 2D Matrix B of size M x 2 denoting the M edges.



Output Format

Return one integer denoting the number of possible ways to write numbers 1, 2 or 3 on the vertices of given graph so it becomes Poisonous . Since answer may be large, print it modulo 998244353.



Example Input

Input 1:

 A = 2
 B = [  [1, 2]
     ]
Input 2:

 A = 4
 B = [  [1, 2]
        [1, 3]
        [1, 4]
        [2, 3]
        [2, 4]
        [3, 4]
    ]


Example Output

Output 1:

 4
Output 2:

 0


Example Explanation

Explanation 1:

 There are 4 ways to make the graph poisonous. i.e, writing number on node 1 and 2 as,
    [1, 2] , [3, 2], [2, 1] or [2, 3] repsectively.
Explanation 2:

 There is no way to make the graph poisonous.
*/

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<long> two(A+1);
    two[0] = 1;

  // Stored the pre computed power of 2 as required in question 
  // For each connected component in the graph the combinations
        // will be 2^EvenNode + 2^OddNodes (Considering it is a bipertate graph)
        // If the graph is not bipertate at any moment just return 0;
        // We have to multiply outcome of all the connected components in graph to get the answer
    for (int i = 1; i <= A; i++) two[i] = (two[i-1]*2) % 998244353;

 // HashSet that will have left and right set for bipertate graph
    unordered_set<int> left_hs;
    unordered_set<int> right_hs;

// Queue to run bfs on connected components of a graph
    queue<pair<int, bool> > qu;
    // HashMap to store graph edges for each node
    unordered_map<int, vector<int> > hm;
    for (int i = 1; i <= A; i++) hm[i] = {};
    for (int i = 0; i < B.size(); i++) {
        int nd_1 = B[i][0];
        int nd_2 = B[i][1];
        hm[nd_1].push_back(nd_2);
        hm[nd_2].push_back(nd_1);
    }

// Initial ans as 1 because we have to multiply with other connected components
    long res = 1;
     // Visited array for all nodes.
    vector<bool> vis(A+1);
    //for each node we will try to start a dfs if it is not visited
        // It is possible if we have n or more connected graph in the whole graph

    for (int i = 1; i <= A; i++) {
        // By default false but will set true if we find a new not visited connected graph
        bool nc = false;
        if (!vis[i]) {
             // Clearing all the left and right sets for the new graph
            left_hs.clear();
            right_hs.clear();
            while(!qu.empty()) qu.pop();
            qu.push(make_pair(i, true));
            nc = true;
            // Run DFS and store the graph node in two sets left and right
            // to determine if we have a bipertate graph
            while (!qu.empty()) {
                pair<int, bool> pr = qu.front();
                qu.pop();

                vis[pr.first] = true;
                if (pr.second) { 
                    left_hs.insert(pr.first);
                    for (auto x : hm[pr.first]) {
                        if (!vis[x]) {
                            qu.push(make_pair(x, false));
                            right_hs.insert(x);
                            // If we have a poisonous graph or non-bipertate connected graph
                            // just return 0 as the answer as desired in question
                            if (left_hs.find(x) != left_hs.end()) return 0;
                        }
                    }
                }
                else {
                    right_hs.insert(pr.first);
                    for (auto x : hm[pr.first]) {
                        if (!vis[x]) {
                            qu.push(make_pair(x, true));
                            left_hs.insert(x);
                            // If we have a poisonous graph or non-bipertate connected graph
                            // just return 0 as the answer as desired in question              
                            if (right_hs.find(x) != right_hs.end()) return 0;
                        }
                    }
                }
            }
        }
        if (nc) res = (res * (two[left_hs.size()] + two[right_hs.size()]) ) % 998244353;
    }

    if (res == 1) return 0;

    return (int) res;
}
