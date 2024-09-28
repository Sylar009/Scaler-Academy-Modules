/*
Problem Description

Given an array A of both positive and negative integers.



Your task is to compute the sum of minimum and maximum elements of all sub-array of size B.

NOTE: Since the answer can be very large, you are required to return the sum modulo 109 + 7.





Problem Constraints

1 <= size of array A <= 105

-109 <= A[i] <= 109

1 <= B <= size of array



Input Format

The first argument denotes the integer array A.
The second argument denotes the value B



Output Format

Return an integer that denotes the required value.



Example Input

Input 1:

 A = [2, 5, -1, 7, -3, -1, -2]
 B = 4
Input 2:

 A = [2, -1, 3]
 B = 2


Example Output

Output 1:

 18
Output 2:

 3


Example Explanation

Explanation 1:

 Subarrays of size 4 are : 
    [2, 5, -1, 7],   min + max = -1 + 7 = 6
    [5, -1, 7, -3],  min + max = -3 + 7 = 4      
    [-1, 7, -3, -1], min + max = -3 + 7 = 4
    [7, -3, -1, -2], min + max = -3 + 7 = 4   
    Sum of all min & max = 6 + 4 + 4 + 4 = 18 
Explanation 2:

 Subarrays of size 2 are : 
    [2, -1],   min + max = -1 + 2 = 1
    [-1, 3],   min + max = -1 + 3 = 2
    Sum of all min & max = 1 + 2 = 3 

*/

int Solution::solve(vector<int> &A, int B) {
    deque<int> dqMax;
    deque<int> dqMin;
    vector<int> maxArr;
    vector<int> minArr;
    for(int i=0;i<B;i++){
        while(!dqMax.empty() && A[dqMax.back()]<=A[i]) dqMax.pop_back();
        if(dqMax.empty() || A[dqMax.back()]>A[i])      dqMax.push_back(i);

        while(!dqMin.empty() && A[dqMin.back()]>=A[i]) dqMin.pop_back();
        if(dqMin.empty() || A[dqMin.back()]<A[i])      dqMin.push_back(i);
    }

    maxArr.push_back(A[dqMax.front()]);
    minArr.push_back(A[dqMin.front()]);
    
    for(int i=B;i<A.size();i++){
        if(dqMax.front()<=i-B) dqMax.pop_front();
        if(dqMin.front()<=i-B) dqMin.pop_front();

        while(!dqMax.empty() && A[dqMax.back()]<=A[i]) dqMax.pop_back();
        if(dqMax.empty() || A[dqMax.back()]>A[i])      dqMax.push_back(i);

        while(!dqMin.empty() && A[dqMin.back()]>=A[i]) dqMin.pop_back();
        if(dqMin.empty() || A[dqMin.back()]<A[i])      dqMin.push_back(i);

        maxArr.push_back(A[dqMax.front()]);
        minArr.push_back(A[dqMin.front()]);
    }
    
    long long ans = 0;

    for(int i=0;i<maxArr.size();i++){
        ans += (maxArr[i] + minArr[i] + 1000000007);
        ans %= 1000000007;
    }
    return ans;
}
