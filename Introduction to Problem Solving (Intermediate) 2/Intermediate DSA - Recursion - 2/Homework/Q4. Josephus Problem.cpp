/*
Problem Description
Given the total number of person A and a number B which indicates that B-1 persons are skipped and the Bth person is killed in a circle. Find the last person standing in the circle. As an example, for A = 12, and B = 2,



Problem Constraints
1 <= A <= 104
2 <= B <= A



Input Format
First argument A is an integer.
Second argument B is an integer.


Output Format
Return an integer.


Example Input
Input 1:
A = 4
B = 2
Input 2:
A = 5
B = 3


Example Output
Output 1:
1
Output 2:
4


Example Explanation
For Input 1:
Firstly, the person at position 2 is killed, then the person at position 4 is killed,
then the person at position 3 is killed. So the person at position 1 survives. 
For Input 2:
Firstly, the person at position 3, then the person at position 1 is killed, 
then the person at position 5 is killed. Finally, the person at position 2 is killed. 
So the person at position 4 survives. 


*/

int Solution::solve(int A, int B) {
    if (A == 1) return 1;
    return (solve(A-1, B) + B-1) % A + 1; 
    // adding B-1 because we are skipping B-1
    // people in between and killing the next person by adding one
}


