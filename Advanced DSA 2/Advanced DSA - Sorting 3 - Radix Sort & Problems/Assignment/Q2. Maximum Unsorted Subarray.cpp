/*
Problem Description
Given an array A of non-negative integers of size N. Find the minimum sub-array Al, Al+1 ,..., Ar such that if we sort(in ascending order) that sub-array, then the whole array should get sorted. If A is already sorted, output -1.

Note :
Follow 0-based indexing, while returning the sub-array's starting and ending indexes.



Problem Constraints
1 <= N <= 106
1 <= A[i] <= 106



Input Format
First and only argument is an array of non-negative integers of size N.



Output Format
Return an array of length two where,
the first element denotes the starting index(0-based) and
the second element denotes the ending index(0-based) of the sub-array.
If the array is already sorted, return an array containing only one element i.e. -1.


Example Input
Input 1:

A = [1, 3, 2, 4, 5]
Input 2:

A = [1, 2, 3, 4, 5]


Example Output
Output 1:

[1, 2]
Output 2:

[-1]


Example Explanation
Explanation 1:

If we sort the sub-array [A1, A2] then the whole array A gets sorted.
Explanation 2:

A is already sorted.

*/

vector<int> Solution::subUnsort(vector<int> &A) {
    int leftMax = A[0];
    int rightMin = A[A.size() - 1];
    int r = -1, l = -1;

    for (int i = 0; i < A.size(); ++i)
    {
        if (A[i] < leftMax)
            r = i;
        else
            leftMax = A[i];
    }

    for (int j = A.size() - 2; j >= 0; --j)
    {
        if (A[j] > rightMin)
            l = j;
        else
            rightMin = A[j];
    }

    if (l == -1 || r == -1)
        return {-1};
    return {l, r};
}
