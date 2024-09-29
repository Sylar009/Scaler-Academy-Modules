/*
Problem Description

Flipkart is currently dealing with the difficulty of precisely estimating and displaying the expected delivery time for orders to a specific pin code. The existing method relies on historical delivery time data for that pin code, using the median value as the expected delivery time. As the order history expands with new entries, Flipkart aims to enhance this process by dynamically updating the expected delivery time whenever a new delivery time is added. The objective is to find the expected delivery time after each new element is incorporated into the list of delivery times. End Goal: With every addition of new delivery time, requirement is to find the median value.

Why Median ? The median is calculated because it provides a more robust measure of the expected delivery time The median is less sensitive to outliers or extreme values than the mean. In the context of delivery times, this is crucial because occasional delays or unusually fast deliveries (outliers) can skew the mean significantly, leading to inaccurate estimations.


Given an array of integers, A denoting the delivery times for each order. New arrays of integer B and C are formed, each time a new delivery data is encountered, append it at the end of B and append the median of array B at the end of C. Your task is to find and return the array C.

NOTE:

If the number of elements is N in B and N is odd, then consider the median as B[N/2] ( B must be in sorted order).
If the number of elements is N in B and N is even, then consider the median as B[N/2-1]. ( B must be in sorted order).



Problem Constraints

1 <= length of the array <= 100000
1 <= A[i] <= 109



Input Format

The only argument given is the integer array A.



Output Format

Return an integer array C, C[i] denotes the median of the first i delivery times.



Example Input

Input 1:

 A = [1, 2, 5, 4, 3]
Input 2:

 A = [5, 17, 100, 11]




Example Output

Output 1:

 [1, 1, 2, 2, 3]
Output 2:

 [5, 5, 17, 11]




Example Explanation

Explanation 1:



 Delivery Times      median
 [1]                   1
 [1, 2]                1
 [1, 2, 5]             2 
 [1, 2, 5, 4]          2
 [1, 2, 5, 4, 3]       3
Explanation 2:

 Delivery Times     median
 [5]                  5
 [5, 17]              5
 [5, 17, 100]         17
 [5, 17, 100, 11]     11 



*/

vector<int> Solution::solve(vector<int> &A) {
    vector<int> res;
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int> > min_pq;
    for (int i = 0; i < A.size(); i++) {
        if (max_pq.empty() && min_pq.empty()) max_pq.push(A[i]);
        else if (max_pq.size() == min_pq.size()) {
            if (A[i] > min_pq.top()) {
                max_pq.push(min_pq.top());
                min_pq.pop();
                min_pq.push(A[i]);
            } else max_pq.push(A[i]);
        } 
        else {
            if (A[i] < max_pq.top()) {
                min_pq.push(max_pq.top());
                max_pq.pop();
                max_pq.push(A[i]);
            } else min_pq.push(A[i]);
        }
        res.push_back(max_pq.top());
    }

    return res;
}
