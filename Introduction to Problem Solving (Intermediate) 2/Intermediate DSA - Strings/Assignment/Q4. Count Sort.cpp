/*
Problem Description
Given an array A. Sort this array using Count Sort Algorithm and return the sorted array.


Problem Constraints
1 <= |A| <= 105
1 <= A[i] <= 105


Input Format
The first argument is an integer array A.


Output Format
Return an integer array that is the sorted array A.


Example Input
Input 1:
A = [1, 3, 1]
Input 2:
A = [4, 2, 1, 3]


Example Output
Output 1:
[1, 1, 3]
Output 2:
[1, 2, 3, 4]


Example Explanation
For Input 1:
The array in sorted order is [1, 1, 3].
For Input 2:
The array in sorted order is [1, 2, 3, 4].


*/

vector<int> Solution::solve(vector<int> &A) {
    int max_ele = INT_MIN;
    for (int a : A) max_ele = max(max_ele, a);

    vector<int> count_vec(max_ele + 1, 0);

    for (int a : A) count_vec[a]++;

    int index = 0;
    for (int i = 1 ; i < count_vec.size(); i++) {
        int count = count_vec[i];
        while (count > 0) {
            A[index] = i;
            index++; count--;
        }
    }

    return A;

}

