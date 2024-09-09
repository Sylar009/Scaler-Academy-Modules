/*
Problem Description

Given an array of integers A and an integer B, find and return the minimum number of swaps required to bring all the numbers less than or equal to B together.

Note: It is possible to swap any two elements, not necessarily consecutive.



Problem Constraints

1 <= length of the array <= 100000
-109 <= A[i], B <= 109



Input Format

The first argument given is the integer array A.
The second argument given is the integer B.



Output Format

Return the minimum number of swaps.



Example Input

Input 1:

 A = [1, 12, 10, 3, 14, 10, 5]
 B = 8
Input 2:

 A = [5, 17, 100, 11]
 B = 20


Example Output

Output 1:

 2
Output 2:

 1


Example Explanation

Explanation 1:

 A = [1, 12, 10, 3, 14, 10, 5]
 After swapping  12 and 3, A => [1, 3, 10, 12, 14, 10, 5].
 After swapping  the first occurence of 10 and 5, A => [1, 3, 5, 12, 14, 10, 10].
 Now, all elements less than or equal to 8 are together.
Explanation 2:

 A = [5, 17, 100, 11]
 After swapping 100 and 11, A => [5, 17, 11, 100].
 Now, all elements less than or equal to 20 are together.
 


*/

int Solution::solve(vector<int> &A, int B) {
    // count number of elements less than equals to B in the array A
    // range : count 
    int count = 0;
    for (int a : A) if (a <= B) count++;

    if (count == 0 || count == 1) return 0;

    // count the bad elements for the first subarray range 
    // bad elements : elements which are greater than B
    int bad = 0;
    for (int i = 0; i < count; i++) if (A[i] > B ) bad++;

    // find the min number of swaps required
    int minSwap = bad;
    int s = 1;
    int e = count;
    while (e < A.size() ) {
        if (A[s-1] > B ) bad--;
        if (A[e] > B) bad++;

        minSwap = min (bad , minSwap);
        s++, e++;
    }

    return minSwap;
}
