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

vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int> > res;
    sort (A.begin(), A.end());

    int size = (1 << A.size());
    for (int i = 0; i < size; i++) {
        vector<int> temp;
        for (int j = 0; j < A.size(); j++) {
            if (((i>>j) & 1) == 1) temp.push_back(A[j]);
        }
        res.push_back(temp);
    }

    sort (res.begin(), res.end());

    return res;
}
