/*
Problem Description
Given an array of integers A and an integer B, find and return the maximum value K such that there is no subarray in A of size K with the sum of elements greater than B.



Problem Constraints
1 <= |A| <= 100000
1 <= A[i] <= 10^9

1 <= B <= 10^9



Input Format
The first argument given is the integer array A.

The second argument given is integer B.



Output Format
Return the maximum value of K (sub array length).



Example Input
Input 1:

A = [1, 2, 3, 4, 5]
B = 10
Input 2:

A = [5, 17, 100, 11]
B = 130


Example Output
Output 1:

 2
Output 2:

 3


Example Explanation
Explanation 1:

For K = 5, There are subarrays [1, 2, 3, 4, 5] which has a sum > B
For K = 4, There are subarrays [1, 2, 3, 4], [2, 3, 4, 5] which has a sum > B
For K = 3, There is a subarray [3, 4, 5] which has a sum > B
For K = 2, There were no subarray which has a sum > B.
Constraints are satisfied for maximal value of 2.
Explanation 2:

For K = 4, There are subarrays [5, 17, 100, 11] which has a sum > B
For K = 3, There were no subarray which has a sum > B.
Constraints are satisfied for maximal value of 3.

*/

// Checks if there is a subarray of size s whose sum is greater than sm in linear time
bool check(int s, vector<long long> &arr, long long sm){
    bool flag = false;
    for(int i = s - 1; i < arr.size(); ++i){
        flag = (i == s - 1 and arr[i] > sm ? true : arr[i] - arr[i - s] > sm ? true : false);
        if(flag)
            return flag;
    }
    return flag;
}
void prefix_function(vector<long long> &prefix, vector<int> &A){
    // calculating the prefix sum;
    for(int i = 0; i < A.size(); ++i){
        prefix[i] = A[i];
        if(i > 0)
            prefix[i] += prefix[i - 1];
    }
}
int Solution::solve(vector<int> &A, int B) {
    vector<long long> prefix(A.size());
    prefix_function(prefix, A);
    // Binary search for the length 
    int lo = 1; int hi = A.size(); int ans = 0;
    while(lo <= hi){
        int mid = (hi - lo) / 2 + lo; // to keep our mid towards the right
        if(check(mid, prefix, (long long)B)){
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
            ans = mid;
        }
    }
    return ans;
}


/*********************************************

int Solution::solve(vector<int> &A, int B) {
    int left = 0;
    int res = A.size();
    int sum = 0;

    for (int i = 0; i < A.size(); i++) {
        sum += A[i];
        while (sum > B) {
            sum -= A[left];
            left++;
            res = min (res, i-left+1);
        }
    }

    return res;
}

**********************submission ***************
************************************************/