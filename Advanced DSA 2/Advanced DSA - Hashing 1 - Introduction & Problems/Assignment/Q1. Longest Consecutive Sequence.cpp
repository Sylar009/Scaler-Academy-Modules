/*
Problem Description

Given an unsorted integer array A of size N.


Find the length of the longest set of consecutive elements from array A.




Problem Constraints

1 <= N <= 106

-106 <= A[i] <= 106



Input Format

First argument is an integer array A of size N.



Output Format

Return an integer denoting the length of the longest set of consecutive elements from the array A.



Example Input

Input 1:

A = [100, 4, 200, 1, 3, 2]
Input 2:

A = [2, 1]


Example Output

Output 1:

 4
Output 2:

 2


Example Explanation

Explanation 1:

 The set of consecutive elements will be [1, 2, 3, 4].
Explanation 2:

 The set of consecutive elements will be [1, 2].

*/

int Solution::longestConsecutive(const vector<int> &A) {
    unordered_set<int> hs;

    for(int a : A) hs.insert(a);

    int ans = INT_MIN;
    for (int i = 0; i < A.size(); i++) {
        if (hs.find(A[i]-1) != hs.end()) continue;
        else {
            int temp = 1;
            int val = A[i];
            while (true) {
                if (hs.find(val+1) != hs.end()) { temp++; val++; }
                else break;
            }
            ans = max(ans, temp);            
        }
    }
    return ans;
}
