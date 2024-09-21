/*
Problem Description
Given an integer array A of size N. You have to delete one element such that the GCD(Greatest common divisor) of the remaining array is maximum.

Find the maximum value of GCD.



Problem Constraints
2 <= N <= 105
1 <= A[i] <= 109



Input Format
First argument is an integer array A.



Output Format
Return an integer denoting the maximum value of GCD.



Example Input
Input 1:

 A = [12, 15, 18]
Input 2:

 A = [5, 15, 30]


Example Output
Output 1:

 6
Output 2:

 15


Example Explanation
Explanation 1:

 If you delete 12, gcd will be 3.
 If you delete 15, gcd will be 6.
 If you delete 18, gcd will 3.
 Maximum value of gcd is 6.
Explanation 2:

 If you delete 5, gcd will be 15.
 If you delete 15, gcd will be 5.
 If you delete 30, gcd will be 5.
 Maximum value of gcd is 15.


*/

int Solution::solve(vector<int> &A) {
    vector<int> suf_gcd(A.size()+1);
    suf_gcd[A.size()-1] = A[A.size()-1];
    for (int i = A.size()-2; i >= 0; i--) suf_gcd[i] = __gcd(suf_gcd[i+1],A[i]);

    int res = INT_MIN;
    int gcd_val = 0;
    for (int j = 0; j < A.size(); j++) {
        res = max(res, __gcd(suf_gcd[j+1],gcd_val));
        gcd_val = __gcd(gcd_val,A[j]);
    }

    res = max(res, gcd_val);

    return res;
}
