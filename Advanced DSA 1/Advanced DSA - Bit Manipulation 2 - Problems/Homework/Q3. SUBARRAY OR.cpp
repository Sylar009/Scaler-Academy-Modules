/*
Problem Description
You are given an array of integers A of size N.

The value of a subarray is defined as BITWISE OR of all elements in it.

Return the sum of value of all subarrays of A % 109 + 7.



Problem Constraints
1 <= N <= 105

1 <= A[i] <= 108



Input Format
The first argument given is the integer array A.



Output Format
Return the sum of Value of all subarrays of A % 109 + 7.



Example Input
Input 1:

 A = [1, 2, 3, 4, 5]
Input 2:

 A = [7, 8, 9, 10]


Example Output
Output 1:

 71
Output 2:

 110


Example Explanation
Explanation 1:

 Value([1]) = 1
 Value([1, 2]) = 3
 Value([1, 2, 3]) = 3
 Value([1, 2, 3, 4]) = 7
 Value([1, 2, 3, 4, 5]) = 7
 Value([2]) = 2
 Value([2, 3]) = 3
 Value([2, 3, 4]) = 7
 Value([2, 3, 4, 5]) = 7
 Value([3]) = 3
 Value([3, 4]) = 7
 Value([3, 4, 5]) = 7
 Value([4]) = 4
 Value([4, 5]) = 5
 Value([5]) = 5
 Sum of all these values = 71
Explanation 2:

 Sum of value of all subarray is 110.


*/
int Solution::solve(vector<int> &A) {
    long res = 0;
    for(int i = 0; i <= 30; i++ ){
        int cons_0s = 0;
        for(int j = A.size() - 1; j >= 0 ; j--){
            if(!(A[j]  & (1<<i))){
                res += ((1 << i) * ((A.size() - j - 1 - cons_0s) % 1000000007) % 1000000007) % 1000000007;
                cons_0s++;
            } else {
                res += (((1 << i) * ((A.size() - j) % 1000000007))%1000000007) % 1000000007;
                cons_0s = 0;
            }
        }
    }

    return res % 1000000007;
}
