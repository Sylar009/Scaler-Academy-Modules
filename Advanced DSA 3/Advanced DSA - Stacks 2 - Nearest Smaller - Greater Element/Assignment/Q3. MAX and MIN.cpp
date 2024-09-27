/*
Problem Description

Given an array of integers A.


The value of an array is computed as the difference between the maximum element in the array and the minimum element in the array A.

Calculate and return the sum of values of all possible subarrays of A modulo 109+7.





Problem Constraints

1 <= |A| <= 100000


1 <= A[i] <= 1000000




Input Format

The first and only argument given is the integer array A.



Output Format

Return the sum of values of all possible subarrays of A modulo 109+7.



Example Input

Input 1:


 A = [1]

Input 2:


 A = [4, 7, 3, 8]



Example Output

Output 1:

 0
Output 2:

 26


Example Explanation

Explanation 1:

Only 1 subarray exists. Its value is 0.
Explanation 2:

value ( [4] ) = 4 - 4 = 0
value ( [7] ) = 7 - 7 = 0
value ( [3] ) = 3 - 3 = 0
value ( [8] ) = 8 - 8 = 0
value ( [4, 7] ) = 7 - 4 = 3
value ( [7, 3] ) = 7 - 3 = 4
value ( [3, 8] ) = 8 - 3 = 5
value ( [4, 7, 3] ) = 7 - 3 = 4
value ( [7, 3, 8] ) = 8 - 3 = 5
value ( [4, 7, 3, 8] ) = 8 - 3 = 5
sum of values % 10^9+7 = 26

*/

int Solution::solve(vector<int> &A) {

    vector<int> ngl(A.size(), -1);
    vector<int> ngr(A.size(), A.size());
    vector<int> nsl(A.size(), -1);
    vector<int> nsr(A.size(), A.size());
    stack<int> st;
    int m = 1000000007;

    for(int i=0;i<A.size();i++){
        while(!st.empty() && A[st.top()]<=A[i]) st.pop();
        if(!st.empty() && A[st.top()]>A[i]) ngl[i] = st.top();
        st.push(i);
    }
    
    st = {};
    
    for(int i=A.size()-1;i>=0;i--){
        while(!st.empty() && A[st.top()]<=A[i]) st.pop();
        if(!st.empty() && A[st.top()]>A[i]) ngr[i] = st.top();
        st.push(i);
    }

    st = {};

    for(int i=0;i<A.size();i++){
        while(!st.empty() && A[st.top()]>=A[i]) st.pop();
        if(!st.empty() && A[st.top()]<A[i]) nsl[i] = st.top();
        st.push(i);
    }
    
    st = {};

    for(int i=A.size()-1;i>=0;i--){
        while(!st.empty() && A[st.top()]>=A[i]) st.pop();
        if(!st.empty() && A[st.top()]<A[i]) nsr[i] = st.top();
        st.push(i); 
    }

    long res = 0;
    long left = 0, right = 0;

    for(int i=0;i<A.size();i++){
        left = i - ngl[i];
        right = ngr[i] - i;
        
        res += (((left*right)%m)*A[i])%m;
        res %= m;
        
        left = i - nsl[i];
        right = nsr[i] - i;

        res -= (((left*right)%m)*A[i])%m;
        res += m;
        res %= m;
    }
    
    return res;

}
