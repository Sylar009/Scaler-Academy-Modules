/*
Problem Description
You are given an array A of N integers. Return the count of elements with frequncy 1 in the given array.


Problem Constraints
1 <= N <= 105
1 <= A[i] <= 109


Input Format
First argument A is an array of integers.


Output Format
Return an integer.


Example Input
Input 1:
A = [3, 4, 3, 6, 6]
Input 2:
A = [3, 3, 3, 9, 0, 1, 0]


Example Output
Output 1:
1
Output 2:
2


Example Explanation
Explanation 1:
Only the element 4 has a frequency 1.
Explanation 2:
The elements 9 and 1 has a frequncy 1.

*/

int Solution::solve(vector<int> &A) {
    unordered_map<int,int> hm;
    for(int a : A) {
        if(hm.find(a) != hm.end()) hm[a]++;
        else hm[a] = 1;
    }

    int count = 0;
    for (auto &i : hm) {
        if (i.second == 1) count++;
    }

    return count;
}
