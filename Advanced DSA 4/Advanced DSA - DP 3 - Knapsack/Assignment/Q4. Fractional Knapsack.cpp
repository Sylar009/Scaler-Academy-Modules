/*
Problem Description

Given two integer arrays A and B of size N each which represent values and weights associated with N items respectively.

Also given an integer C which represents knapsack capacity.

Find out the maximum total value that we can fit in the knapsack. If the maximum total value is ans, then return ⌊ans × 100⌋ , i.e., floor of (ans × 100).

NOTE:

You can break an item for maximizing the total value of the knapsack



Problem Constraints

1 <= N <= 105

1 <= A[i], B[i] <= 103

1 <= C <= 103




Input Format

First argument is an integer array A of size N denoting the values on N items.

Second argument is an integer array B of size N denoting the weights on N items.

Third argument is an integer C denoting the knapsack capacity.




Output Format

Return a single integer denoting the maximum total value of A such that sum of the weights of this subset is smaller than or equal to C.



Example Input

Input 1:

 A = [60, 100, 120]
 B = [10, 20, 30]
 C = 50
Input 2:

 A = [10, 20, 30, 40]
 B = [12, 13, 15, 19]
 C = 10


Example Output

Output 1:

 24000
Output 2:

 2105


Example Explanation

Explanation 1:

Taking the full items with weight 10 and 20 and 2/3 of the item with weight 30 will give us 
the maximum value i.e 60 + 100 + 80 = 240. So we return 24000.
Explanation 2:

Taking 10/19 the fourth item gives us the maximum value i.e. 21.0526. So we return 2105.

*/

struct Item
{
    int Value;
    int Weight;
};

bool compare(Item i1, Item i2)
{
    double r1 = (double)i1.Value / (double)i1.Weight;
    double r2 = (double)i2.Value / (double)i2.Weight;
    return r1 > r2;
}

int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n = A.size();
    struct Item items[n];

    for (int i = 0; i < n; i++)
    {
        items[i].Value = A[i];
        items[i].Weight = B[i];
    }

    // Sort in descending order of value of Value/Weight
    sort(items, items + n, compare);

    int curWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (items[i].Weight + curWeight <= C)
        {
            curWeight += items[i].Weight;
            finalValue += items[i].Value;
        }
        else
        {
            int remainingWeight = C - curWeight;
            finalValue += (items[i].Value / (double)items[i].Weight) * (double)remainingWeight;
            break;
        }
    }
    return finalValue*100;
}
