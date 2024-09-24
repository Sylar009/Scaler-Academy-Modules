/*
Problem Description
You are given an array A of N elements. You have to make all elements unique. To do so, in one step you can increase any number by one.

Find the minimum number of steps.



Problem Constraints
1 <= N <= 105
1 <= A[i] <= 109



Input Format
The only argument given is an Array A, having N integers.



Output Format
Return the minimum number of steps required to make all elements unique.



Example Input
Input 1:

 A = [1, 1, 3]
Input 2:

 A = [2, 4, 5]


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 We can increase the value of 1st element by 1 in 1 step and will get all unique elements. i.e [2, 1, 3].
Explanation 2:

 All elements are distinct.

*/

int Solution::solve(vector<int> &A) {
    sort(A.begin(), A.end());

    int count = 0;
    for (int i = 1; i < A.size(); i++) {
        if (A[i] <= A[i-1]) {
            int sub = A[i-1]-A[i];
            A[i] += sub+1; 
            count += sub+1; 
        }
    }

    return count;
}