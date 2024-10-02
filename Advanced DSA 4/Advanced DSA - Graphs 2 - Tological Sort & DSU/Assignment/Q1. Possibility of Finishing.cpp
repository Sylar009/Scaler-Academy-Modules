/*
Problem Description

There are a total of A courses you have to take, labeled from 1 to A.

Some courses may have prerequisites, for example to take course 2 you have to first take course 1, which is expressed as a pair: [1,2].

So you are given two integer array B and C of same size where for each i (B[i], C[i]) denotes a pair.

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Return 1 if it is possible to finish all the courses, or 0 if it is not possible to finish all the courses.



Problem Constraints

1 <= A <= 6*104

1 <= length(B) = length(C) <= 105

1 <= B[i], C[i] <= A



Input Format

The first argument of input contains an integer A, representing the number of courses.

The second argument of input contains an integer array, B.

The third argument of input contains an integer array, C.



Output Format

Return 1 if it is possible to finish all the courses, or 0 if it is not possible to finish all the courses.



Example Input

Input 1:

 A = 3
 B = [1, 2]
 C = [2, 3]
Input 2:

 A = 2
 B = [1, 2]
 C = [2, 1]


Example Output

Output 1:

 1
Output 2:

 0


Example Explanation

Explanation 1:

 It is possible to complete the courses in the following order:
    1 -> 2 -> 3
Explanation 2:

 It is not possible to complete all the courses.
*/

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    vector<vector< int> > adj(A+1);
    vector<int> indegree(A+1);

    for (int i = 0; i < B.size(); i++) {
        int u = B[i];
        int v = C[i];

        adj[u].push_back(v);
        indegree[v]++;
    }

    int count = 0;
    priority_queue<int> qu;

    for (int i = 1; i <= A; i++) {
        if (indegree[i] == 0) qu.push(i);
    }

    while (!qu.empty()) {
        int curr = qu.top(); 
        qu.pop();
        count++;
        for (int x : adj[curr]) {
            indegree[x]--;
            if (indegree[x] == 0) qu.push(x);
        }
    }

    if (count == A) return 1;
    else return 0;

}
