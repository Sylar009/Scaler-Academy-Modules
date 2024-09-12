/*
Problem Description
Given an array with N objects colored red, white, or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will represent the colors as,

red -> 0
white -> 1
blue -> 2

Note: Using the library sort function is not allowed.



Problem Constraints
1 <= N <= 1000000
0 <= A[i] <= 2


Input Format
First and only argument of input contains an integer array A.


Output Format
Return an integer array in asked order


Example Input
Input 1 :
    A = [0, 1, 2, 0, 1, 2]
Input 2:

    A = [0]


Example Output
Output 1:
    [0, 0, 1, 1, 2, 2]
Output 2:

    [0]


Example Explanation
Explanation 1:
    [0, 0, 1, 1, 2, 2] is the required order.
Explanation 2:
    [0] is the required order
*/

vector<int> Solution::sortColors(vector<int> &A) {
    vector<int> result;
    int zero_count = 0;
    int one_count = 0;
    int two_count = 0;
    for (int a : A) {
        if (a == 0) zero_count++;
        else if (a == 1) one_count++;
        else two_count++;
    }
    int i = A.size();
    while (i > 0) {
        if (zero_count > 0) {
            result.push_back(0);
            --zero_count;
        }
        else if (one_count > 0) {
            result.push_back(1);
            --one_count;
        }
        else if (two_count > 0) {
            result.push_back(2);
            --two_count;
        }
        --i;
    }
    return result;
}
