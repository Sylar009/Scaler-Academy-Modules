/*
Problem Description
Given two integers A and B. Find the minimum value (A ⊕ X) + (B ⊕ X) that can be achieved for any X.

where P ⊕ Q is the bitwise XOR operation of the two numbers P and Q.

Note: Bitwise XOR operator will return 1, if both bits are different. If bits are same, it will return 0.


Problem Constraints
1 <= A, B <= 109


Input Format
The first argument is a single integer A.
The second argument is a single integer B.


Output Format
Return the minimum value (A ⊕ X) + (B ⊕ X) that can be achieved for any X.


Example Input
Input 1:-
A = 6
B = 12
Input 2:-
A = 4
B = 9


Example Output
Output 1:-
10
output 2:-
13


Example Explanation
Expanation 1:-
X ^ A + X ^ B = 10 when X = 4
Explanation 2:-
X ^ A + X ^ B = 13 when X = 0

*/
int Solution::solve(int A, int B) {
    return A^B;
}
