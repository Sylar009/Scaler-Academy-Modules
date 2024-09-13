/*
Problem Description
Given a string A of size N, find and return the longest palindromic substring in A.

Substring of string A is A[i...j] where 0 <= i <= j < len(A)

Palindrome string:
A string which reads the same backwards. More formally, A is palindrome if reverse(A) = A.

Incase of conflict, return the substring which occurs first ( with the least starting index).



Problem Constraints
1 <= N <= 6000



Input Format
First and only argument is a string A.



Output Format
Return a string denoting the longest palindromic substring of string A.



Example Input
Input 1:
A = "aaaabaaa"
Input 2:
A = "abba


Example Output
Output 1:
"aaabaaa"
Output 2:
"abba"


Example Explanation
Explanation 1:
We can see that longest palindromic substring is of length 7 and the string is "aaabaaa".
Explanation 2:
We can see that longest palindromic substring is of length 4 and the string is "abba".

*/
string expand(string A, int L, int R) {
    while(L >= 0 && R<A.length()) {
        if(A[L] != A[R]) {
            break;
        }
        L--;
        R++;
    }
    if(R-L-1 == 0) {
        return "";
    }
    //L and R will stop when A[L]!=A[R] hence to we need to increase L so we get A[L] == A[R]
    return A.substr(L+1, R-L-1);
}

string Solution::longestPalindrome(string A) {
    string ans="";
    int maxlen = 0;
    for(int i=0; i<A.length(); i++) {
        string ans1, ans2;

        //Finding longest palindromic substring for Odd length

        ans1 = expand(A, i-1, i+1);
        if(i < A.length()-1) {
            //Finding longest palindromic substring for Even length
            ans2 = expand(A, i, i+1);
        }
        if(ans1.length() > ans2.length()) {
            if(ans1.length() > ans.length()) {
                ans = ans1;
            }
        } else {
            if(ans2.length() > ans.length()) {
                ans = ans2;
            }
        }
    }
    return ans;
}