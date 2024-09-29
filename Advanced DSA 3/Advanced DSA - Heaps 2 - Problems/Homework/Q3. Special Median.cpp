/*
Problem Description

You are given an array A containing N numbers. This array is called special if it satisfies one of the following properties:


There exists an element A[i] in the array such that A[i] is equal to the median of elements [A[0], A[1], ...., A[i-1]]
There exists an element A[i] in the array such that A[i] is equal to the median of elements [A[i+1], A[i+2], ...., A[N-1]]
The Median is the middle element in the sorted list of elements. If the number of elements is even then the median will be (sum of both middle elements) / 2.

Return 1 if the array is special else return 0.

NOTE:


Do not neglect decimal point while calculating the median
For A[0] consider only the median of elements [A[1], A[2], ..., A[N-1]] (as there are no elements to the left of it)
For A[N-1] consider only the median of elements [A[0], A[1], ...., A[N-2]]


Problem Constraints

1 <= N <= 1000000.
A[i] is in the range of a signed 32-bit integer.



Input Format

The first and only argument is an integer array A.



Output Format

Return 1 if the given array is special else return 0.



Example Input

Input 1:

 A = [4, 6, 8, 4]
Input 2:

 A = [2, 7, 3, 1]


Example Output

Output 1:

 1
Output 2:

 0


Example Explanation

Explantion 1:

 Here, 6 is equal to the median of [8, 4].
Explanation 2:

 No element satisfies any condition.
*/

int Solution::solve(vector<int> &A) {
    priority_queue<int> pq_max;
    priority_queue<int, vector<int>, greater<int> > pq_min;

    pq_max.push(A[0]);
    for (int i = 1; i < A.size(); i++) {
        int val = pq_max.top();

        if (pq_min.size() == pq_max.size()) {
            if (A[i] == ((double)pq_max.top() + pq_min.top())/2) return 1;
        }
        else if (A[i] == pq_max.top()) return 1;

        if (A[i] <= val ) {
            pq_max.push(A[i]);
            if (pq_max.size() - pq_min.size() > 1) {
                pq_min.push(pq_max.top());
                pq_max.pop();
            } 
        }
        else {
            pq_min.push(A[i]);
            if (pq_min.size() - pq_max.size() >= 1) {
                pq_max.push(pq_min.top());
                pq_min.pop();
            }
        }
    }

    int n = A.size();
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int> > min_pq;
    max_pq.push(A[n-1]);
    for (int i = n-2; i >= 0; i--) {
        int val = max_pq.top();

        if (min_pq.size() == max_pq.size()) {
            if (A[i] == ((double)max_pq.top() + min_pq.top())/2) return 1;
        }
        else if (A[i] == max_pq.top()) return 1;

        if (A[i] <= val ) {
            max_pq.push(A[i]);
            if (max_pq.size() - min_pq.size() > 1) {
                min_pq.push(max_pq.top());
                max_pq.pop();
            } 
        }
        else {
            min_pq.push(A[i]);
            if (min_pq.size() - max_pq.size() >= 1) {
                max_pq.push(min_pq.top());
                min_pq.pop();
            }
        }
    }

    return 0;
}

