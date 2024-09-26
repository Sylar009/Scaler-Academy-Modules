/*
Problem Description

Given a binary string A of size N. There are Q queries given by the 2-D array B of size Q x 2.

Each query has 2 integers :-

First integer denotes the type of query. Type of query can be either 1 or 2.
Second integer denotes index x.
If type = 1, Flip the value at index x.

If type = 2, Find the index of the nearest 1 to the left or right of index x in the array. If there are multiple indices has the same distance from x, return the index with the lower value. If there is no occurrence of 1 in the array, return -1.

Note :
We use 1-based indexing



Problem Constraints

1 <= N <= 105

1 <= Q <= 105

1 <= B[i][0] <= 2

1 <= B[i][1] <= N



Input Format

First argument A is a string.

Second argument B is a 2D array of integers describing the queries.



Output Format

Return an array of integers denoting the answers to each query of type 2.



Example Input

Input 1:
A = "10010"
B = [[1, 2]
     [2, 3]]
Input 2:
A = "010000100"
B = [[2, 5]
     [1, 7]
     [2, 9]]


Example Output

Output 1:
[2]
Output 2:
[7, 2]


Example Explanation

For Input 1:
After first query, A = "11010".
For second query, X = 3. Both index 2 and index 4 are at the same 
distance but we choose the lower index.
For Input 2:
For first query, the index 2 is at a distance 3 and index 7 is at a distance 2. So we choose
index 7.
After second query, A = "010000000"
For third query, the only index with '1' is 2.

*/

vector<int> Solution::solve(string A, vector<vector<int> > &B) {
    vector<int> res;

    set<int> hs;

    for (int i = 0; i < A.size(); i++) if(A[i] == '1') hs.insert(i);

    for (int j =0; j < B.size(); j++) {
        int a = B[j][0];
        int b = B[j][1]-1;

        if (a == 1) {
            if (hs.find(b) != hs.end() ) hs.erase(b);
            else hs.insert(b);
        }
        else {
            if (hs.empty() ) {
                res.push_back(-1);
                continue;
            }

            auto val = hs.lower_bound(b);
 
            if (val == hs.begin()) res.push_back((*val)+1);
            else if (val == hs.end()) res.push_back((*(--val))+1);
            else {
                int end = *val;
                int start = *(--val);
                if (end-b >= b - start) res.push_back(start+1);
                else res.push_back(end+1);
            }
        }
    }

    return res;
}
