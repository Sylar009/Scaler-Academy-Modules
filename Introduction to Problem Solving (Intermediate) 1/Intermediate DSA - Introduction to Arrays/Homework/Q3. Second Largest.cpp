/*
    Problem Description
    You are given an integer array A. You have to find the second largest 
    element/value in the array or report that no such element exists.


    Problem Constraints
    1 <= |A| <= 10^5

    0 <= A[i] <= 10^9



    Input Format
    The first argument is an integer array A.



    Output Format
    Return the second largest element. If no such element exist then return -1.



    Example Input
    Input 1:

    A = [2, 1, 2] 
    Input 2:

    A = [2]


    Example Output
    Output 1:

    1 
    Output 2:

    -1 


    Example Explanation
    Explanation 1:

    First largest element = 2
    Second largest element = 1
    Explanation 2:

    There is no second largest element in the array.


*/

int Solution::solve(vector<int> &A) {
    int sec_largest = -1;
    int largest = A[0];

    for(int i = 1 ; i< A.size(); i++) {
        if (largest < A[i]) {
            sec_largest = largest;
            largest = A[i];
        }
        if (A[i] > sec_largest && A[i] < largest) {
            sec_largest = A[i];
        }
    }

    return sec_largest;
}S