/*
Problem Description
Given two Integers A, B. You have to calculate (A ^ (B!)) % (1e9 + 7).

"^" means power,
"%" means mod, and
"!" means factorial.

Note: Ensure to handle integer overflow when performing the calculations.


Problem Constraints
1 <= A, B <= 5e5



Input Format
First argument is the integer A

Second argument is the integer B



Output Format
Return one integer, the answer to the problem



Example Input
Input 1:

A = 1
B = 1
Input 2:

A = 2
B = 2


Example Output
Output 1:

1
Output 2:

4


Example Explanation
Explanation 1:

 1! = 1. Hence 1^1 = 1.
Explanation 2:

 2! = 2. Hence 2^2 = 4.
*/

int fast_pow(int A, int B, int C) {
    if (A == 0) return 0;
    if (B == 0) return 1;
    if (B == 1) return A;
    long p = fast_pow (A, B/2, C) % C;
    if (B % 2 == 0) return ((p % C) * (p % C)) % C;
    else return ((((p % C) * (p % C) ) % C * (A % C)) % C) % C;
}

int fact (int x ) {
    long pow = 1;
    int m = 1000000006;
    while (x > 0) {
        pow *= x;
        pow %= m;
        --x; 
    }
    return pow;
}

int Solution::solve(int A, int B) {
    int m = 1000000007;
    int pow = fact(B);
    return fast_pow(A,pow,m);
}
