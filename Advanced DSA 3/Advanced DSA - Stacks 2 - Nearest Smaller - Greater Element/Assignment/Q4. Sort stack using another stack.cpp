/*
Problem Description

Given a stack of integers A, sort it using another stack.

Return the array of integers after sorting the stack using another stack.



Problem Constraints

1 <= |A| <= 5000


0 <= A[i] <= 109




Input Format

The only argument is a stack given as an integer array A.



Output Format

Return the array of integers after sorting the stack using another stack.



Example Input

Input 1:

 A = [5, 4, 3, 2, 1]
Input 2:

 A = [5, 17, 100, 11]


Example Output

Output 1:

 [1, 2, 3, 4, 5]
Output 2:

 [5, 11, 17, 100]


Example Explanation

Explanation 1:

 Just sort the given numbers.
Explanation 2:

 Just sort the given numbers.

*/

vector<int> Solution::solve(vector<int> &A) {
    stack<int> st_1;
    stack<int> st_2;


    for (int i =0; i < A.size(); i++) st_1.push(A[i]);
    if (st_2.empty()) {
        st_2.push(st_1.top());
        st_1.pop();
    }

    while (!st_1.empty() && st_2.size() != A.size()) {
        int val = st_1.top();
        st_1.pop();
        while (!st_2.empty() && val > st_2.top()) {
            st_1.push(st_2.top());
            st_2.pop(); 
        }
        st_2.push(val);
    }

    int i = 0;
    while (!st_2.empty()) {
        A[i] = st_2.top();
        st_2.pop();
        i++;
    }

    return A;
}


