/*
Problem Description
Given an array of integers A and multiple values in B, which represents the number of times array A needs to be left rotated.

Find the rotated array for each value and return the result in the from of a matrix where ith row represents the rotated array for the ith value in B.



Problem Constraints
1 <= length of both arrays <= 2000 -10^9 <= A[i] <= 10^9 0 <= B[i] <= 2000


Input Format
The first argument given is the integer array A.
The second argument given is the integer array B.


Output Format
Return the resultant matrix.


Example Input
Input 1:
 
    A = [1, 2, 3, 4, 5]
    B = [2, 3]

Input 2:

  
    A = [5, 17, 100, 11]
    B = [1]




Example Output
Output 1:
 
    [ [3, 4, 5, 1, 2]
     [4, 5, 1, 2, 3] ]


Output 2:

    
    [ [17, 100, 11, 5] ]



Example Explanation
for input 1 -> B[0] = 2 which requires 2 times left rotations

1: [2, 3, 4, 5, 1]

2: [3, 4, 5, 1, 2]

B[1] = 3 which requires 3 times left rotation

1: [2, 3, 4, 5, 1]

2: [3, 4, 5, 1, 2]

2: [4, 5, 1, 2, 4]


*/

vector<vector<int> > Solution::solve(vector<int> &A, vector<int> &B) {
   vector<vector<int> > result;

    int n = A.size();
    for (int b : B) {        
        vector<int> temp = A;        
        b = b % n;

        // reversing the Whole array
        int i = 0;
        int j = n-1;
        while (i < j) {
            swap(temp[i], temp[j]);
            i++; j--;
        }

        // reversing the array from 0 to n-b-1
        // which is 0 to b less than from  the end
        i = 0;
        j = n-b-1;
        while (i < j) {
            swap(temp[i], temp[j]);
            i++; j--;
        }

        // reversing the array from n-b to n-1

        i = n-b;
        j = n-1;
        while (i < j) {
            swap(temp[i], temp[j]);
            i++; j--;
        }

        result.push_back(temp);
    }

    return result;
}
