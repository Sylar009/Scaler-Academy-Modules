/*
    Problem Description
    You will be given an integer n. You need to return the count of prime numbers less than or equal to n.


    Problem Constraints
    0 <= n <= 10^3


    Input Format
    Single input parameter n in function.


    Output Format
    Return the count of prime numbers less than or equal to n.


    Example Input
    Input 1:
    19
    Input 2:
    1


    Example Output
    Output 1:
    8
    Output 2:
    0


    Example Explanation
    Explanation 1:
    Primes <= 19 are 2, 3, 5, 7, 11, 13, 17, 19
    Explanation 2:
    There are no primes <= 1
*/

int solve(int A) {
    int x = 1;
    int count = 0;
    while (x <= A) {
        int subcount = 0;
        for (int i = 1; i*i <= x ; i++) {
            if (x % i == 0) {
                if (i == x/i) 
                    subcount = subcount + 1;
                else 
                    subcount = subcount + 2;
            }
        }
        if (subcount == 2) 
            count = count + 1;
        x++;
    }
    return count;
}
