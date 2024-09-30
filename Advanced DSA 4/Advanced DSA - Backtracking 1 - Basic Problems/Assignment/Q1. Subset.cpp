/*
Problem Description

Given a set of distinct integers A, return all possible subsets.






NOTE:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The initial list is not necessarily sorted.


Problem Constraints

1 <= |A| <= 16
INTMIN <= A[i] <= INTMAX


Input Format

First and only argument of input contains a single integer array A.



Output Format

Return a vector of vectors denoting the answer.



Example Input

Input 1:

A = [1]
Input 2:

A = [1, 2, 3]


Example Output

Output 1:

[
    []
    [1]
]
Output 2:

[
 []
 [1]
 [1, 2]
 [1, 2, 3]
 [1, 3]
 [2]
 [2, 3]
 [3]
]


Example Explanation

Explanation 1:

 You can see that these are all possible subsets.
Explanation 2:

You can see that these are all possible subsets.

*/

/**
void subset(vector < int > & A, vector < vector < int >> & ans, vector < int > temp, int index) {
    // insert the current subset to our answer
    ans.push_back(temp);
    for (int i = index; i < A.size(); i++) {
        // for every element we can either take it or skip it
        temp.push_back(A[i]);
        subset(A, ans, temp, i + 1);
        temp.pop_back();
    }
    return;
}
vector < vector < int > > Solution::subsets(vector < int > & A) {
    vector < vector < int >> ans;
    sort(A.begin(), A.end());
    int index = 0;
    vector < int > temp;
    subset(A, ans, temp, index);
    return ans;
}
**/

void generate(int N, vector<int> &A, vector<int> &temp, vector<vector<int> > &res, int idx) {
    if (idx >= N) {
        res.push_back(temp);
        return;
    }

    temp.push_back(A[idx]);
    generate(N, A, temp, res, idx+1);
    temp.pop_back();
    generate(N, A, temp, res, idx+1);
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<int> temp;
    vector<vector<int> > res;
    generate(A.size(), A, temp, res, 0);
    sort(res.begin(), res.end());
    return res;
}
