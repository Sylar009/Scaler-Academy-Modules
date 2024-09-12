/*
Problem Description
Given an integer array A of size N. You can remove any element from the array in one operation.
The cost of this operation is the sum of all elements in the array present before this operation.

Find the minimum cost to remove all elements from the array.



Problem Constraints
0 <= N <= 1000
1 <= A[i] <= 103



Input Format
First and only argument is an integer array A.



Output Format
Return an integer denoting the total cost of removing all elements from the array.



Example Input
Input 1:

 A = [2, 1]
Input 2:

 A = [5]


Example Output
Output 1:

 4
Output 2:

 5
*/

int Solution::solve(vector<int> &A) {
    sort(A.begin(), A.end(), greater<>() );
    int cost = 0;
    int i = 1;
    for(int a : A) {
        cost += i * A[i-1];
        i++;
    }
    return cost;
}

