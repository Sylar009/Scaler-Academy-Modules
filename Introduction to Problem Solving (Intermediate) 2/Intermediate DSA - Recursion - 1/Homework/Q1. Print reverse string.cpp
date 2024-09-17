/*
Problem Description
Write a recursive function that takes a string, S, as input and prints the characters of S in reverse order.



Problem Constraints
1 <= |s| <= 1000



Input Format
First line of input contains a string S.



Output Format
Print the character of the string S in reverse order.



Example Input
Input 1:

 scaleracademy
Input 2:

 cool


Example Output
Output 1:

 ymedacarelacs
Output 2:

 looc


Example Explanation
Explanation:

 Print the reverse of the string in a single line.

*/

#include<iostream>

using namespace std;

void solve(string &str, int pos) {
    if (pos < 0) return;
    cout << str[pos];
    solve(str, --pos);
}

int main()  {
    // YOUR CODE GOES HERE
    // Please take input and print output to standard input/output (stdin/stdout)
    // E.g. 'cin' for input & 'cout' for output
    string str;
    cin >> str;
    solve(str, str.size()-1);
    return 0;
}