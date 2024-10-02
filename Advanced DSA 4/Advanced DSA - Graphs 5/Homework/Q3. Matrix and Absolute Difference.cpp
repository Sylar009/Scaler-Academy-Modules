/*
Problem Description

Given a matrix C of integers, of dimension A x B.

For any given K, you are not allowed to travel between cells that have an absolute difference greater than K.

Return the minimum value of K such that it is possible to travel between any pair of cells in the grid through a path of adjacent cells.

NOTE:

Adjacent cells are those cells that share a side with the current cell.


Problem Constraints

1 <= A, B <= 102

1 <= C[i][j] <= 109



Input Format

The first argument given is A.

The second argument give is B.

The third argument given is the integer matrix C.



Output Format

Return a single integer, the minimum value of K.



Example Input

Input 1:

 A = 3
 B = 3
 C = [  [1, 5, 6]
        [10, 7, 2]
        [3, 6, 9]   ]


Example Output

Output 1:

 4


Example Explanation

Explanation 1:

 
 It is possible to travel between any pair of cells through a path of adjacent cells that do not have an absolute
 difference in value greater than 4. e.g. : A path from (0, 0) to (2, 2) may look like this:
 => (0, 0) -> (0, 1) -> (1, 1) -> (2, 1) -> (2, 2)

*/

bool possible_to_visit_all(int diff, vector<vector<int> > C) {
    vector<int> row = {-1, 1, 0, 0};
    vector<int> col = {0, 0, -1, 1};
    queue<pair<int, int> > qu;
    vector<vector<bool> > vis(C.size(), vector<bool>(C[0].size(), false));

    qu.push(make_pair(0, 0));
    vis[0][0] = true;
    while (!qu.empty()) {
        pair<int, int> p = qu.front();
        qu.pop();

        int f = p.first;
        int s = p.second;

        for (int i = 0; i < 4; i++) {
            int x = f + row[i];
            int y = s + col[i];

            if (x >= 0 && y >= 0 && x < C.size() &&
             y < C[0].size() && vis[x][y] == false &&
              abs(C[f][s] - C[x][y]) <= diff) {
                  vis[x][y] = true;
                  qu.push(make_pair(x, y));
            }
        }
    }

    for (int x = 0;  x < C.size(); x++) {
        for (int y = 0; y < C[0].size(); y++) {
            if (vis[x][y] == false) return false;
        }
    }

    return true;

 }

int Solution::solve(int A, int B, vector<vector<int> > &C) {
    int left = 0, right = INT_MAX;
    int res = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (possible_to_visit_all(mid, C)) {
            res  = mid;
            right = mid - 1;
        }
        else left = mid + 1; 
    }

    return res;
}
