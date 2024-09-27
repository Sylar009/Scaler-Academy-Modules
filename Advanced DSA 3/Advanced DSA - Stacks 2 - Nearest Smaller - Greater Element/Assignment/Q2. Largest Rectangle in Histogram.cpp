/*
Problem Description

Given an array of integers A.


A represents a histogram i.e A[i] denotes the height of the ith histogram's bar. Width of each bar is 1.

Find the area of the largest rectangle formed by the histogram.




Problem Constraints

1 <= |A| <= 100000


1 <= A[i] <= 10000




Input Format

The only argument given is the integer array A.



Output Format

Return the area of the largest rectangle in the histogram.



Example Input

Input 1:

 A = [2, 1, 5, 6, 2, 3]
Input 2:

 A = [2]


Example Output

Output 1:

 10
Output 2:

 2


Example Explanation

Explanation 1:


The largest rectangle has area = 10 unit. Formed by A[3] to A[4].

Explanation 2:


Largest rectangle has area 2.
*/

vector<int> nearest_smallest_left(vector<int> &A) {
    vector<int> res;
    stack<int> st;

    for (int i = 0; i < A.size(); i++) {
        while (!st.empty() && A[st.top()] >= A[i] ) st.pop();

        if (st.empty()) res.push_back(-1);
        else res.push_back(st.top());

        st.push(i);
    }

    return res;
}

vector<int> nearest_smallest_right(vector<int> &A) {
    vector<int> res(A.size());
    stack<int> st;

    for (int i =  A.size()-1; i >=0 ; i--) {
        while (!st.empty() && A[st.top()] >= A[i] ) st.pop();

        if (st.empty()) res.push_back(A.size());
        else res.push_back(st.top());

        st.push(i);
    }

    reverse (res.begin(), res.end());
    return res;
}

int Solution::largestRectangleArea(vector<int> &A) {
    if (A.size() == 1) return A[0];
    vector<int> nsl = nearest_smallest_left(A);
    vector<int> nsr = nearest_smallest_right(A);

    int max_rect = INT_MIN;
    for (int i=0; i< A.size(); i++) {
        int width = nsr[i] - nsl[i] - 1;
        max_rect = max(max_rect, width*A[i]);
    }

    return max_rect;
}
