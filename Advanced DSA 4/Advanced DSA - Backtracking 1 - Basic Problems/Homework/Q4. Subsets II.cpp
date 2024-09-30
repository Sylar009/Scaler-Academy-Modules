/*
Problem Description

Given a collection of integers denoted by array A of size N that might contain duplicates, return all possible subsets.

NOTE:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
The subsets must be sorted lexicographically.


Problem Constraints

0 <= N <= 16



Input Format

Only argument is an integer array A of size N.



Output Format

Return a 2-D vector denoting all the possible subsets.



Example Input

Input 1:

 A = [1, 2, 2]
Input 2:

 A = [1, 1]


Example Output

Output 1:

 [
    [],
    [1],
    [1, 2],
    [1, 2, 2],
    [2],
    [2, 2]
 ]
Output 2:

 [
    [],
    [1],
    [1, 1]
 ]


Example Explanation

Explanation 1:

All the subsets of the array [1, 2, 2] in lexicographically sorted order.
*/
void subset_dupes(vector<int> &A, int i, vector<int> &temp, vector<vector<int > > &res) {
    if (i >= A.size()) return;

    temp.push_back(A[i]);
    res.push_back(temp);
    subset_dupes(A, i+1, temp, res);

    int x = temp[temp.size()-1]; 
    temp.pop_back();
    while (i<A.size() -1 && x==A[i+1]) i= i+1;
    subset_dupes(A, i+1, temp, res);
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    vector<vector<int > > res;
    sort(A.begin(), A.end());
    vector<int > temp;
    res.push_back(temp);
    subset_dupes(A, 0, temp, res);
    return res;
}
