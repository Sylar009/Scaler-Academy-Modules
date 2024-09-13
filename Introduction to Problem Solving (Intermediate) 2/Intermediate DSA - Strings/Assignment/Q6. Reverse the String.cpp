/*
Problem Description
You are given a string A of size N.

Return the string A after reversing the string word by word.

NOTE:

A sequence of non-space characters constitutes a word.
Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
If there are multiple spaces between words, reduce them to a single space in the reversed string.


Problem Constraints
1 <= N <= 3 * 105



Input Format
The only argument given is string A.



Output Format
Return the string A after reversing the string word by word.



Example Input
Input 1:
A = "the sky is blue"
Input 2:
A = "this is ib"


Example Output
Output 1:
"blue is sky the"
Output 2:
"ib is this"    


Example Explanation
Explanation 1:
We reverse the string word by word so the string becomes "blue is sky the".
Explanation 2:
We reverse the string word by word so the string becomes "ib is this".


*/
void reverse(string &A, int start, int end) {
    while(start < end) {
        swap(A[start], A[end]);
        start++;
        end--;
    }
}

string Solution::solve(string A) {

    //reverse the complete string
    reverse(A, 0, A.size()-1);

    //reverse word wise
    int start = 0, end = 0;
    for(int i=0; i < A.size(); i++) {
        if(A[i] == 32) {
            reverse(A, start, end-1);
            end++;
            start = end;
        } else if(end+1 == A.size()) {
            reverse(A, start, end);
        }else {
            end++;
        }
    }

    //Remove trailing spaces (starting multiple spaces)
    start = 0;
    while(start < A.size() && A[start] == 32) {
        start++;
    }

    //Removing Ending multiple spaces
    end = A.size()-1;
    while(end >= 0 && A[end] == 32) {
        end--;
    }
    A = A.substr(start, end-start+1);


    //Removing multiple spaces between the words and keeping only one space
    for(int i = 0; i < A.size(); i++) {
        int count = 0, j=i;
        while(A[j] == 32) {
            count++;
            j++;
        }
        if(count > 1) {
            int k = i+1;
            for(; j< A.size(); j++) {
                A[k] = A[j];
                k++;
            }
            A[j-1] = '\0';
        }
    }
    return A;
}