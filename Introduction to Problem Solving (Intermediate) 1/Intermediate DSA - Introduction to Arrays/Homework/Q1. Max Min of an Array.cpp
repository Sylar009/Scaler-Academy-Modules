/*
    Problem Description
    Given an array A of size N. You need to find the sum of Maximum and 
    Minimum element in the given array.


    Problem Constraints
    1 <= N <= 10^5
    -109 <= A[i] <= 10^9


    Input Format
    First argument A is an integer array.


    Output Format
    Return the sum of maximum and minimum element of the array


    Example Input
    Input 1:

    A = [-2, 1, -4, 5, 3]
    Input 2:

    A = [1, 3, 4, 1]


    Example Output
    Output 1:

    1
    Output 2:

    5


    Example Explanation
    Explanation 1:

    Maximum Element is 5 and Minimum element is -4. (5 + (-4)) = 1. 
    Explanation 2:

    Maximum Element is 4 and Minimum element is 1. (4 + 1) = 5.


*/

int Solution::solve(vector<int> &A) {
    int min_val = INT_MAX;
    int max_val = INT_MIN;

    for (int i = 0; i < A.size(); i++) {
        if ( min_val > A[i])
            min_val = A[i];

        if( max_val < A[i])
            max_val = A[i];
    }

    return (max_val + min_val);
}
