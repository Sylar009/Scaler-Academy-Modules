/*
Problem Description
Given three integers A, B, and C, where A represents n, B represents r, and C represents p and p is a prime number greater than equal to n, find and return the value of nCr % p where nCr % p = (n! / ((n-r)! * r!)) % p.

x! means factorial of x i.e. x! = 1 * 2 * 3... * x.

NOTE: For this problem, we are considering 1 as a prime.



Problem Constraints
1 <= A <= 106
1 <= B <= A
A <= C <= 109+7


Input Format
The first argument given is the integer A ( = n).
The second argument given is the integer B ( = r).
The third argument given is the integer C ( = p).



Output Format
Return the value of nCr % p.



Example Input
Input 1:

 A = 5
 B = 2
 C = 13
Input 2:

 A = 6
 B = 2
 C = 13


Example Output
Output 1:

 10
Output 2:

 2


Example Explanation
Explanation 1:

 nCr( n=5 and r=2) = 10.
 p=13. Therefore, nCr%p = 10.

*/

int pow(int A, int B, int C) {
    if (A == 0) return 0;
    if (B == 0) return 1;
    long p = pow (A, B/2, C);
    if (B % 2 == 0) return (p * p) % C;
    else return (((p * p) % C * A) % C + C) % C;
}

int Solution::solve(int A, int B, int C) {
     /* Note - Why couldn't we use the previous problem method here?

        Previous method was based on n * r appraoch and per the contraints n * r won't cross the 10 ^ 6.
        In this case the n is <= 10 ^ 6 and r is <= 10 ^ 6. Hence, we can use the same as it crosses 10 ^ 12. which is more than
        10 ^ 8 iterations.

        So, we need to optimize it a little more and should be able to solve it under <= 10 ^ 8 iterations.

        Approach - First, we calculate the fatorial till 10^6 and store it in an array.
        Calculate the (N!)%C & (1/(N-r)! * r!) % p
       
        As per little fermat's theorem, d^-1 % p = d ^ (p - 2);
        If we apply the same formulae above
            ((n - r)! * r!) ^ p - 2

    */
    vector<int> vec(A+1, 0);

    vec[0] = 1;

    for (int i = 1; i <= A; i++)
        vec[i] = ((1L * i * vec[i-1]) + C) % C;

    int temp = ((1L * vec[A-B] * vec[B]) + C) % C;

    // (n - r)! r!
    temp = pow(temp, C-2, C);

    return ((1L * vec[A] * temp) + C) % C;
}
