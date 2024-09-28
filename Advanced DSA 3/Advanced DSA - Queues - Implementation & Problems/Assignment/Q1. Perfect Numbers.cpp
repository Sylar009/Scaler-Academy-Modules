/*
Problem Description

Given an integer A, you have to find the Ath Perfect Number.

A Perfect Number has the following properties:

It comprises only 1 and 2.
The number of digits in a Perfect number is even.
It is a palindrome number.
For example, 11, 22, 112211 are Perfect numbers, where 123, 121, 782, 1 are not.





Problem Constraints

1 <= A <= 100000



Input Format

The only argument given is an integer A.



Output Format

Return a string that denotes the Ath Perfect Number.



Example Input

Input 1:

 A = 2
Input 2:

 A = 3


Example Output

Output 1:

 22
Output 2:

 1111


Example Explanation

Explanation 1:

First four perfect numbers are:
1. 11
2. 22
3. 1111
4. 1221
Return the 2nd Perfect number.
Explanation 2:

First four perfect numbers are:
1. 11
2. 22
3. 1111
4. 1221
Return the 3rd Perfect number.

*/

string Solution::solve(int A) {
    queue<string> qu;
    qu.push("11");
    if (A==1) return "11";

    qu.push("22");
    if (A==2) return "22";

    int count = 2;
    while (!qu.empty()) {
        string str1 = qu.front();
        string str2 = qu.front();

        qu.pop();

        int len = str1.size();
        int mid = len/2;

        str1.insert(mid, "11");

        count++;

        if (count == A) return str1;

        str2.insert(mid, "22");
        count++;

        if (count == A) return str2;

        qu.push(str1);
        qu.push(str2);

    }

    return "";
}
