/*
Problem Description
Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order and return the generated square matrix.



Problem Constraints
1 <= A <= 1000



Input Format
First and only argument is integer A


Output Format
Return a 2-D matrix which consists of the elements added in spiral order.



Example Input
Input 1:

1
Input 2:

2
Input 3:

5


Example Output
Output 1:

[ [1] ]
Output 2:

[ [1, 2], 
  [4, 3] ]
Output 3:

[ [1,   2,  3,  4, 5], 
  [16, 17, 18, 19, 6], 
  [15, 24, 25, 20, 7], 
  [14, 23, 22, 21, 8], 
  [13, 12, 11, 10, 9] ]


Example Explanation
Explanation 1:

Only 1 is to be arranged.
Explanation 2:

1 --> 2
      |
      |
4<--- 3
Explanation 3:




*/

vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int> > result(A , vector<int> (A, 0));
    
    int num = 1;

    if (A == 1) {
        result[0][0] = num;
        return result;
    }


    int top = 0;
    int bottom  = A - 1;
    int left = 0 ;
    int right = A - 1;
    while ((left < right) && (top < bottom) ) {
        for (int i = left; i < right; i++) {
            result[top][i] = num;
            num++;
        }

        for (int j = top; j < bottom; j++) {
            result[j][right] = num;
            num++; 
        }

        for (int k = right; k > left; k--) {
            result[bottom][k] = num;
            num++;
        }
        
        for (int l = bottom; l > top; l--) {
            result[l][left] = num;
            num++;
        }

        top++; bottom--;
        left++; right--;

        if(left == right && top == bottom) result[left][right] = num;
    }

    return result;
}
