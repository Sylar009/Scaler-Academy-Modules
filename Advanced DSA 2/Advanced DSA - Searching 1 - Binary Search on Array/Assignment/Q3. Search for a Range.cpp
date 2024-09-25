/*
Problem Description
Given a sorted array of integers A (0-indexed) of size N, find the left most and the right most index of a given integer B in the array A.

Return an array of size 2, such that 
          First element = Left most index of B in A
          Second element = Right most index of B in A.
If B is not found in A, return [-1, -1].

Note : Note: The time complexity of your algorithm must be O(log n)..


Problem Constraints
1 <= N <= 106
1 <= A[i], B <= 109


Input Format
The first argument given is the integer array A.
The second argument given is the integer B.


Output Format
Return the left most and right most index (0-based) of B in A as a 2-element array. If B is not found in A, return [-1, -1].


Example Input
Input 1:

 A = [5, 7, 7, 8, 8, 10]
 B = 8
Input 2:

 A = [5, 17, 100, 111]
 B = 3


Example Output
Output 1:

 [3, 4]
Output 2:

 [-1, -1]


Example Explanation
Explanation 1:

 The first occurrence of 8 in A is at index 3.
 The last occurrence of 8 in A is at index 4.
 ans = [3, 4]
Explanation 2:

 There is no occurrence of 3 in the array.

*/

vector<int> Solution::searchRange(const vector<int> &A, int B) {

    int start_pos = -1;
    int end_pos = -1;

    int start = 0;
    int end = A.size() - 1;

    while (start <= end) {
        int mid = start + (end -start)/2;

        if (A[mid] == B) {
            start_pos = mid;
            end = mid - 1;
        }
        else if (A[mid] < B) start = mid + 1;
        else end = mid - 1;
    }

    start = 0;
    end = A.size() - 1;

    while (start <= end) {
        int mid = start + (end -start)/2;

        if (A[mid] == B) {
            end_pos = mid;
            start = mid + 1;
        }
        else if (A[mid] < B) start = mid + 1;
        else end = mid - 1;
    } 
    
    return {start_pos, end_pos};
}
