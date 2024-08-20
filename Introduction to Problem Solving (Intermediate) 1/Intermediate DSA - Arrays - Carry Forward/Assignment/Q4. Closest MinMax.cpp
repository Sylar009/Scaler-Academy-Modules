/*
Problem Description
Given an array A, find the size of the smallest subarray such that it contains at least one occurrence of the maximum value of the array

and at least one occurrence of the minimum value of the array.



Problem Constraints
1 <= |A| <= 2000



Input Format
First and only argument is vector A



Output Format
Return the length of the smallest subarray which has at least one occurrence of minimum and maximum element of the array



Example Input
Input 1:

A = [1, 3, 2]
Input 2:

A = [2, 6, 1, 6, 9]


Example Output
Output 1:

 2
Output 2:

 3


Example Explanation
Explanation 1:

 Take the 1st and 2nd elements as they are the minimum and maximum elements respectievly.
Explanation 2:

 Take the last 3 elements of the array.
*/
int Solution::solve(vector<int> &A) {
    int min_val = INT_MAX;
    int max_val = INT_MIN;

    for (int i = 0; i < A.size(); i++) {
        min_val = min (min_val, A[i]);
        max_val = max (max_val, A[i]);
    }

    if (min_val == max_val) return 1;

    int len = A.size() + 1;
    int max_index = -1;
    int min_index = -1;
    for (int j = 0; j < A.size(); j++) {
        if (A[j] == max_val) {
            max_index = j;
            if(min_index >= 0) len = min(len, max_index - min_index + 1);
        }
        if (A[j] == min_val) {
            min_index = j;
            if(max_index >= 0) len = min(len, min_index - max_index + 1);
        }
    }

    return len;
}

