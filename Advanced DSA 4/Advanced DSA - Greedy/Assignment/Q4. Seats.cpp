/*
Problem Description

There is a row of seats represented by string A. Assume that it contains N seats adjacent to each other.
There is a group of people who are already seated in that row randomly. i.e. some are sitting together & some are scattered.





An occupied seat is marked with a character 'x' and an unoccupied seat is marked with a dot ('.')

Now your target is to make the whole group sit together i.e. next to each other, without having any vacant seat between them in such a way that the total number of hops or jumps to move them should be minimum.

In one jump a person can move to the adjacent seat (if available).

NOTE: 1. Return your answer modulo 107 + 3.







Problem Constraints

1 <= N <= 1000000
A[i] = 'x' or '.'



Input Format

The first and only argument is a string A of size N.



Output Format

Return an integer denoting the minimum number of jumps required.



Example Input

Input 1:

 A = "....x..xx...x.."
Input 2:

 A = "....xxx"


Example Output

Output 1:

 5
Output 2:

 0


Example Explanation

Explanation 1:

 Here is the row having 15 seats represented by the String (0, 1, 2, 3, ......... , 14) 
                 . . . . x . . x x . . . x . . 
 Now to make them sit together one of approaches is -
                 . . . . . . x x x x . . . . .
 Steps To achieve this:
 1) Move the person sitting at 4th index to 6th index: Number of jumps by him =   (6 - 4) = 2
 2) Bring the person sitting at 12th index to 9th index: Number of jumps by him = (12 - 9) = 3
 So, total number of jumps made: 2 + 3 = 5 which is the minimum possible.

 If we other ways to make them sit together but the number of jumps will exceed 5 and that will not be minimum.
 
Explanation 2:

 They are already together. So, the cost is zero.

*/

int left_check(string A, int m) {
    int c = 0;
    int sum = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == 'x') c++;
        else {
            sum += c;
            sum %= m;
        }
    }

    return sum;
}

int right_check(string A, int m) {
    int c = 0;
    int sum = 0;
    for (int i = A.size()-1; i >= 0; i--) {
        if (A[i] == 'x') c++;
        else {
            sum += c;
            sum %= m;
        }
    }

    return sum;
}

int Solution::seats(string A) {
    int m = 10000003;
    int start = 0;
    int end = A.size()-1;
    while (start < end) {
        char st = A[start];
        char et = A[end];
        if (st == 'x' && et != 'x') end--;
        else if (st != 'x' && et == 'x') start++;
        else { start++; end--; }
    }

    return (left_check(A.substr(0, start), m) + right_check(A.substr(start), m)) % m;
}
