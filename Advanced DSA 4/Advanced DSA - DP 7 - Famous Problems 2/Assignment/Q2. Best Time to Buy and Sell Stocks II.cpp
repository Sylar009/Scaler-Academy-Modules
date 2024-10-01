/*
Problem Description

Say you have an array, A, for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit.

You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).



Problem Constraints

0 <= len(A) <= 1e5
1 <= A[i] <= 1e7


Input Format

The first and the only argument is an array of integer, A.


Output Format

Return an integer, representing the maximum possible profit.


Example Input

Input 1:
A = [1, 2, 3]
Input 2:
A = [5, 2, 10]


Example Output

Output 1:
2
Output 2:
8


Example Explanation

Explanation 1:
    => Buy a stock on day 0.
    => Sell the stock on day 1. (Profit +1)
    => Buy a stock on day 1.
    => Sell the stock on day 2. (Profit +1)

    Overall profit = 2
Explanation 2:
    => Buy a stock on day 1.
    => Sell the stock on on day 2. (Profit +8)

    Overall profit = 8


*/
int helper (const vector<int> &A) {
    vector<int> curr(2, 0);
    vector<int> next(2, 0);

    for (int i = A.size()-1; i >= 0; i--){
        for (int j = 0; j<= 1; j++){
            int profit =0;
            if(j) {
                int buy = -A[i] + next[0];
                int skip = 0 + next[1];
                profit = max(buy, skip);
            }
            else {
                int sell = A[i] + next[1];
                int skip = 0 + next[0];
                profit = max(sell , skip);
            }

            curr[j] = profit;
        }
        next = curr;
    }

    return next[1];
}

int Solution::maxProfit(const vector<int> &A) {
    return helper(A);
}
