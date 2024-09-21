/*
Problem Description
Given an array of integers A and an integer B, find and return the number of pairs in A whose sum is divisible by B.

Since the answer may be large, return the answer modulo (109 + 7).

Note: Ensure to handle integer overflow when performing the calculations.


Problem Constraints
1 <= length of the array <= 100000
1 <= A[i] <= 109
1 <= B <= 106



Input Format
The first argument given is the integer array A.
The second argument given is the integer B.



Output Format
Return the total number of pairs for which the sum is divisible by B modulo (109 + 7).



Example Input
Input 1:

 A = [1, 2, 3, 4, 5]
 B = 2
Input 2:

 A = [5, 17, 100, 11]
 B = 28


Example Output
Output 1:

 4
Output 2:

 1


Example Explanation
Explanation 1:
 All pairs which are divisible by 2 are (1,3), (1,5), (2,4), (3,5). 
 So total 4 pairs.
Explanation 2:
 There is only one pair which is divisible by 28 is (17, 11)
*/

int Solution::solve(vector<int> &A, int B) {
    unordered_map<int, int> hm;
    int count = 0;
    int m = 1000000007;
    for (int i = 0; i < A.size(); i++) {
        int mod_no = A[i] % B;
        if (hm.find(B-mod_no) != hm.end()) count = ((count % m) + (hm[B-mod_no] % m)) % m;
        if (mod_no == 0 && hm.find(0) != hm.end()) count =  ((count % m) + (hm[0] % m)) % m;
        if (hm.find(mod_no) != hm.end()) hm[mod_no]++;
        else hm[mod_no] = 1; 
    }
    return count  % m;
}
