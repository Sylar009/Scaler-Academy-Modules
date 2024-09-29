/*
Problem Description

Max heap is a special kind of complete binary tree in which, for every node, the value present in that node is greater than the value present in its children nodes.




Given an array A of size N consisting of N - 1 distinct elements. In other words, there is exactly one element that is repeated.
It is given that the element that would repeat would be either the maximum element or the minimum element.

Find the number of structurally different Max heaps possible using all the N elements of the array i.e., Max heap of size N.

As the final answer can be very large return your answer modulo 109 + 7.






Problem Constraints

1 <= N <= 1000



Input Format

The first and only argument is an integer array A.




Output Format

Return an integer denoting the number of structurally different Max heaps possible modulo 109 + 7.



Example Input

Input 1:

 A = [1, 5, 5]
Input 2:

 A = [2, 2, 7]


Example Output

Output 1:

 2
Output 2:

 1


Example Explanation

Explanation 1:

 The possible max heaps using the given elements are:- First: 5 on the root. 1 as the left child of root and 5 as the right child of the root.   
                5
              /   \
            1       5
 Second: 5 on the root. 5 as the left child of root and 1 as the right child of the root.
                5
              /   \
            5       1            
Explanation 2:

 There is only one possible max heaps: 7 on the root. 2 as the left child of root and 2 as the right child of the root.   
                7
              /   \
            2       2

*/

int mod = 1e9+7;
vector<vector<int>> nCr;
vector<long long> dp;

long long combinations(int n, int r) {

    if(r > n) return 0;

    if(n <= 1 || r == 0) return 1;

    if(nCr[n][r] != -1) return nCr[n][r];

    return nCr[n][r] = (combinations(n-1, r-1) + combinations(n-1, r)) % mod;
}

int subSolution1(int A) {

    nCr = vector<vector<int>> (A+1, vector<int>(A+1, -1));
    dp = vector<long long> (A+1, 1);

    int left = 0, right = 0, next = 1;
   
    for(int i = 2; i <= A; i++) {

        if(left < next) left++;

        else if(right == left) {

            next = 2*left+1;
            left++;
        }
       
        else right++;

        dp[i] = (combinations(i-1,left) * dp[left]) % mod;
        dp[i] = (dp[i] * dp[i-left-1]) % mod;
    }

    return dp[A];
}

int subSolution2(int A) {

    nCr = vector<vector<int>> (A+1, vector<int>(A+1, -1));

    int left = 1, right = 0, next = 1;
    vector<long long> dp1(A+1,1);
   
    for(int i = 3; i <= A; i++) {

        if(left < next) left++;

        else if(right == left) {

            next = 2*left+1;
            left++;
        }
       
        else right++;

        long long l = 0, m = 0, r = 0;

        if(left >= 2) {

            l = (combinations(i-3,left-2) * dp1[left]) % mod;
            l = (l * dp[i-left-1])%mod;
        }

        if(left >= 1 && right >= 1) {

            m = (combinations(i-3,left-1) * dp[left]) % mod;
            m = (m * dp[i-left-1]) % mod;
        }

        if(right >= 2) {

            r = (combinations(i-3,left) * dp[left]) % mod;
            r = (r * (dp1[i-left-1])) % mod;
        }

        dp1[i] = (l + m + r) % mod;
    }

    return dp1[A];
}

int Solution::solve(vector<int> &A) {

    int n = A.size();

    if(n <= 1) return n;
    sort(A.begin(), A.end());

    int res = subSolution1(n);

    if(A[n-1] == A[n-2]) return res;

    return subSolution2(n);
}