/*
Problem Description
There are two sorted arrays A and B of sizes N and M respectively.

Find the median of the two sorted arrays ( The median of the array formed by merging both the arrays ).

NOTE:

The overall run time complexity should be O(log(m+n)).
IF the number of elements in the merged array is even, then the median is the average of (n/2)th and (n/2+1)th element. For example, if the array is [1 2 3 4], the median is (2 + 3) / 2.0 = 2.5.


Problem Constraints
1 <= N + M <= 2*106



Input Format
The first argument is an integer array A of size N.
The second argument is an integer array B of size M.



Output Format
Return a decimal value denoting the median of two sorted arrays.



Example Input
Input 1:

 A = [1, 4, 5]
 B = [2, 3]
Input 2:

 A = [1, 2, 3]
 B = [4]


Example Output
Output 1:

 3.0
Output 2:

 2.5


Example Explanation
Explanation 1:

 The median of both the sorted arrays will be 3.0.
Explanation 2:

 The median of both the sorted arrays will be (2+3)/2 = 2.5.

*/

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if (A.size() > B.size()) return findMedianSortedArrays(B, A);
    int n1 = A.size();
    int n2 = B.size();
    int start = 0;
    int end = n1;

    while (start <= end) {
        int mid1 = start + (end - start)/2 ;
        int mid2 = ((n1 + n2 +1) / 2) - mid1;

        int left1 = mid1 == 0 ? INT_MIN : A[mid1-1];
        int left2 = mid2 == 0 ? INT_MIN : B[mid2-1];

        int right1 = mid1 == n1 ? INT_MAX : A[mid1];
        int right2 = mid2 == n2 ? INT_MAX : B[mid2];

        if (left1 <= right2 && left2 <= right1) {
            if ((n1+n2) % 2 == 0) return ((max(left1, left2) + min(right1, right2)) / 2.00);
            else return max(left1, left2);
        }
        else if (left1 > right2) end = mid1 - 1;
        else start = mid1 + 1;
    } 

    return 0.0;
}
