/*
Problem Description
You are given an array A of N integers and an integer B. Count the number of pairs (i,j) such that A[i] + A[j] = B and i ≠ j.

Since the answer can be very large, return the remainder after dividing the count with 109+7.

Note - The pair (i,j) is same as the pair (j,i) and we need to count it only once.


Problem Constraints
1 <= N <= 105
1 <= A[i] <= 109
1 <= B <= 109


Input Format
First argument A is an array of integers and second argument B is an integer.


Output Format
Return an integer.


Example Input
Input 1:

A = [3, 5, 1, 2]
B = 8
Input 2:

A = [1, 2, 1, 2]
B = 3


Example Output
Output 1:

1
Output 2:

4


Example Explanation
Example 1:

The only pair is (1, 2) which gives sum 8
Example 2:

The pair which gives sum as 3 are (1, 2), (1, 4), (2, 3) and (3, 4). 
*/

int Solution::solve(vector<int> &A, int B) {
    int count = 0;

    unordered_map<int, int> hm;
    for (int a : A) {
        int y = B - a;
        if (hm.find(y) != hm.end()) {
            count = (count % 1000000007 + hm[y] % 1000000007) % 1000000007; 
        }
        if (hm.find(a) != hm.end()) hm[a]++;
        else hm[a] = 1;
    }

    return count;
}
