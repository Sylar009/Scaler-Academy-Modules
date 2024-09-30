/*
Problem Description

Given an integer array A of size N denoting collection of numbers , return all possible permutations.

NOTE:

No two entries in the permutation sequence should be the same.
For the purpose of this problem, assume that all the numbers in the collection are unique.
Return the answer in any order
WARNING: DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS. 
Example : next_permutations in C++ / itertools.permutations in python.
If you do, we will disqualify your submission retroactively and give you penalty points.


Problem Constraints

1 <= N <= 9



Input Format

Only argument is an integer array A of size N.



Output Format

Return a 2-D array denoting all possible permutation of the array.



Example Input

A = [1, 2, 3]


Example Output

[ [1, 2, 3]
  [1, 3, 2]
  [2, 1, 3] 
  [2, 3, 1] 
  [3, 1, 2] 
  [3, 2, 1] ]


Example Explanation

All the possible permutation of array [1, 2, 3].


*/

/***********************************************************************
************************************************************************
void permutes(vector<int> & num, int start, vector<vector<int>> & result) {
    if (start == num.size() - 1) {
        result.push_back(num);
        return;
    }
    // try all possible elements for the current position
    for (int i = start; i < num.size(); i++) {
        swap(num[start], num[i]);
        permutes(num, start + 1, result);
        swap(num[start], num[i]);
    }
}

vector<vector<int>> Solution::permute(vector<int> &A) {
    vector<vector<int>> result;
    if (A.size() == 0)
        return result;
    permutes(A, 0, result);
    return result;
}

********************************************************************
*******************************************************************/


void all_permutations(int idx, vector<int> & A, vector<vector<int> > &res) {
    if (idx == A.size()) {
        res.push_back(A);
        return; 
    }

    for (int i = idx; i < A.size(); i++) {
        swap(A[idx], A[i]);
        all_permutations(idx+1, A, res);
        swap(A[idx], A[i]);
    }

    return;
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int> > res;
    all_permutations(0, A, res);
    return res;
}
