/*
Problem Description
Imagine a histogram where the bars' heights are given by the array A. Each bar is of uniform width, which is 1 unit. When it rains, water will accumulate in the valleys between the bars.

Your task is to calculate the total amount of water that can be trapped in these valleys.

Example:

The Array A = [5, 4, 1, 4, 3, 2, 7] is visualized as below. The total amount of rain water trapped in A is 11.


Rain Water Trapped




Problem Constraints
1 <= |A| <= 105
0 <= A[i] <= 105



Input Format
First and only argument is the Integer Array, A.



Output Format
Return an Integer, denoting the total amount of water that can be trapped in these valleys



Example Input
Input 1:

 A = [0, 1, 0, 2]
Input 2:

A = [1, 2]


Example Output
Output 1:

1
Output 2:

0


Example Explanation
Explanation 1:

1 unit is trapped on top of the 3rd element.
Rain Water Histogram
Explanation 2:

No water is trapped.

*/

int Solution::trap(const vector<int> &A) {
    vector<int> pf_max(A.size(), 0);
    vector<int> sf_max(A.size(), 0);

    pf_max[0] = A[0];
    for (int i= 1; i < A.size(); i++) pf_max[i] = max(pf_max[i-1], A[i]);

    sf_max[A.size()-1] = A[A.size()-1];
    for (int j = A.size()-2; j >= 0; j--) sf_max[j] = max(sf_max[j+1], A[j]);

    int ans = 0;
    for (int k = 0; k < A.size(); k++) {
        int val = min(pf_max[k], sf_max[k]) - A[k];
        if (val > 0) ans += val;
    }
    
    return ans;
}
