/*
Problem Description

Given an array A of size N denoting collection of numbers that might contain duplicates, return all possible unique permutations.

NOTE: No 2 entries in the permutation sequence should be the same.

WARNING: DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS. 
Example : next_permutations in C++ / itertools.permutations in python.
If you do, we will disqualify your submission retroactively and give you penalty points.


Problem Constraints

1 <= |A| <= 9

0 <= A[i] <= 10



Input Format

Only argument is an integer array A of size N.



Output Format

Return a 2-D array denoting all possible unique permutation of the array.



Example Input

Input 1:

A = [1, 1, 2]
Input 2:

A = [1, 2]


Example Output

Output 1:

[ [1,1,2]
  [1,2,1]
  [2,1,1] ]
Output 2:

[ [1, 2]
  [2, 1] ]


Example Explanation

Explanation 1:

 All the possible unique permutation of array [1, 1, 2].
Explanation 2:

 All the possible unique permutation of array [1, 2].
*/

/************************************************************************
*************************************************************************

void rec(vector<vector<int>> & result, vector<int>& hash, vector<int> current, int n) {
    if (current.size() == n) {
        result.push_back(current);
    }
    // try all possible elements for the current position
    for (int i = 0; i <= 10; i++) {
        if (hash[i] != 0) {
            hash[i]--;
            current.push_back(i);
            rec(result, hash, current, n);
            hash[i]++;
            current.pop_back();
        }
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> result;
    vector<int> hash(11);
    for (int x: A)
        hash[x]++;
    vector<int> current;
    rec(result, hash, current, A.size());
    return result;
}

****************************************************************************
***************************************************************************/

void find_permutations(int N, vector<int> &temp, vector<vector<int> > &res, unordered_map<int,int> &hm) {
    if (temp.size() == N) res.push_back(temp);
    for (auto [key, value] : hm) {
        if (value > 0) {
            temp.push_back(key);
            hm[key]--;
            find_permutations(N, temp, res, hm);
            temp.pop_back();
            hm[key]++;
        }
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    unordered_map<int, int> hm;
    vector<int> temp;
    vector<vector<int> > res;
    for(int i = 0; i < A.size(); i++) hm[A[i]]++;

    find_permutations(A.size(), temp, res, hm);

    return res;
}
