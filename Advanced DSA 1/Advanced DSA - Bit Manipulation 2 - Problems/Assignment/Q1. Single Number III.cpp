/*
Problem Description
Given an array of positive integers A, two integers appear only once, and all the other integers appear twice.
Find the two integers that appear only once.

Note: Return the two numbers in ascending order.


Problem Constraints
2 <= |A| <= 100000
1 <= A[i] <= 109



Input Format
The first argument is an array of integers of size N.



Output Format
Return an array of two integers that appear only once.



Example Input
Input 1:
A = [1, 2, 3, 1, 2, 4]
Input 2:

A = [1, 2]


Example Output
Output 1:
[3, 4]
Output 2:

[1, 2]


Example Explanation
Explanation 1:
3 and 4 appear only once.
Explanation 2:

1 and 2 appear only once.

*/

vector<int> Solution::solve(vector<int> &A) {
    int _xor = 0;
    for (int a : A) _xor ^= a;
    int pos = 0;
    for (int k = 0; k < 31; k++) if((_xor & (1<<k))) {pos = k; break;}

    int val_1 = 0;
    int val_2 = 0;

    for (int i = 0; i < A.size(); i++) 
        if ((A[i] & (1<<pos))) val_1 ^= A[i];
        else val_2 ^= A[i];

    vector<int> res;
    res.push_back(val_1);
    res.push_back(val_2);
    sort (res.begin(), res.end());

    return res;
}
