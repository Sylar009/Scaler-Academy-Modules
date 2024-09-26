/*
Problem Description

Given an array of positive integers A and an integer B, find and return first continuous subarray which adds to B.






If the answer does not exist return an array with a single integer "-1".

First sub-array means the sub-array for which starting index in minimum.








Problem Constraints

1 <= length of the array <= 100000
1 <= A[i] <= 109
1 <= B <= 109



Input Format

The first argument given is the integer array A.

The second argument given is integer B.



Output Format

Return the first continuous sub-array which adds to B and if the answer does not exist return an array with a single integer "-1".



Example Input

Input 1:

 A = [1, 2, 3, 4, 5]
 B = 5
Input 2:

 A = [5, 10, 20, 100, 105]
 B = 110


Example Output

Output 1:





 [2, 3]
Output 2:

 [-1]






Example Explanation

Explanation 1:

 [2, 3] sums up to 5.
Explanation 2:

 No subarray sums up to required number.

*/

vector<int> Solution::solve(vector<int> &A, int B) {
    vector<int > res;
    int i = 0;
    int j = 0;
    int sum = A[0];
    while (j < A.size() ) {

        if(sum == B) {
            while (i <= j) {
                res.push_back(A[i]);
                i++;
            }
            return res;
        }
        else if (sum < B) {
            j++;
            if (j == A.size()) break;            
            sum += A[j];
        }
        else {
            sum -= A[i];
            i++;
        }
    }

    return {-1};
}
