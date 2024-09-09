/*
Problem Description
There are A people standing in a circle. Person 1 kills their immediate clockwise neighbour and pass the knife to the next person standing in circle. This process continues till there is only 1 person remaining. Find the last person standing in the circle.



Problem Constraints
1 <= A <= 105


Input Format
First argument A is an integer.


Output Format
Return an integer.


Example Input
Input 1:
A = 4
Input 2:
A = 5


Example Output
Output 1:
1
Output 2:
3
*/
int Solution::solve(int A) {
    int ans = 0;
    int cp = 1;
    while (cp < A) {
        cp *= 2;
    }

    // if (CP == A) than 2^x is always 1
    if (cp == A) ans = 1;
    // Else :: cp is greater than A so divide by 2
    // the diff is multiple by 2 and add one 
    else ans = (A - (cp / 2)) * 2 + 1 ;  

    return ans;
}
