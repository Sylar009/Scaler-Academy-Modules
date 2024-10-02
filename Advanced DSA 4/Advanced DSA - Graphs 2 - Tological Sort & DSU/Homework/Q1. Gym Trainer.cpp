/*
Problem Description

You are the trainer of a gym and there are A people who come to your gym.

Some of them are friends because they walk together, and some of them are friends because they talk together.
But people become possessive about each other, so a person cannot walk with one friend and talk with another. Although he can walk with two or more people or talk with two or more people.

You being the trainer, decided to suggest each one of the 2 possible diets. But friends, being friends will always have the same diet as all the other friends are having.

Find and return the number of ways you can suggest each of them a diet.

As the number of ways can be huge, return the answer modulo 109+7.

NOTE: If there is any person who walks with one person and talks with the another person, then you may return 0.



Problem Constraints

1 <= A, N, M <= 105

1 <= B[i][0], B[i][1], C[i][0], C[i][1] <= A



Input Format

The first argument contains an integer A, representing the number of people.
The second argument contains a 2-D integer array B of size N x 2, where B[i][0] and B[i][1] are friends because they walk together.
The third argument contains a 2-D integer array C of size M x 2, where C[i][0] and C[i][1] are friends because they talk together.



Output Format

Return an integer representing the number of ways to suggest one of the two diets to the people.



Example Input

Input 1:

 A = 4
 B = [
       [1, 2]
     ]
 C = [
       [3, 4]
     ]
Input 2:

 A = 3
 B = [
       [1, 2]
     ]
 C = [
       [1, 3] 
     ]


Example Output

Output 1:

 4
Output 2:

 0


Example Explanation

Explanation 1:

 There are four ways to suggest the diet:
 Diet-1 to (1, 2) and Diet-2 to (3, 4).
 Diet-1 to (1, 2) and Diet-1 to (3, 4).
 Diet-2 to (1, 2) and Diet-1 to (3, 4).
 Diet-2 to (1, 2) and Diet-2 to (3, 4).
 
Explanation 2:

 Person 1 walks with person 2 and talks with person 3. So, we will return 0.

*/

class DSU {

    vector<int> parent;
    
    public:
    int count;

    DSU (int size) {

        parent.resize(size + 1);
        count = size;
        for (int i = 0; i <= size; i++) parent[i] = i;
    }

    int find(int nd) {

        int rt = nd;
        while ( rt != parent[rt]) rt = parent[rt];

        while(nd != rt) {            
            int nxt = parent[nd];
            parent[nd] = rt;
            nd = nxt;
        }
        return rt;

    }

    bool unify (int x , int y) {

        int rt1 = find(x);
        int rt2 = find(y);
        if (rt1 == rt2 ) return false;
        parent[rt1] = rt2;
        count--;
        return true; 
    }

};

int Solution::solve(int A, vector<vector<int> > &B, vector<vector<int> > &C) {
    
    DSU dsu(A);

    vector<char> adj(A + 1, 'O');
    long long res = 1;
    for (auto b : B) adj[b[0]] = adj[b[1]] = 'W';
    for (auto c : C) if (adj[c[0]] == 'W' || adj[c[1]] == 'W') return 0;
    for (auto b : B) dsu.unify(b[0], b[1]);
    for (auto c : C) dsu.unify(c[0], c[1]);

    int ans = dsu.count;

    while (ans) {
        res = (res * 2) % 1000000007;
        ans--;
    }
    return res;
}
