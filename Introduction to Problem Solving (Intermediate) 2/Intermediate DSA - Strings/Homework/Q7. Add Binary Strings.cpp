/*
Problem Description
Given two binary strings A and B. Return their sum (also a binary string).


Problem Constraints
1 <= length of A <= 105

1 <= length of B <= 105

A and B are binary strings



Input Format
The two argument A and B are binary strings.



Output Format
Return a binary string denoting the sum of A and B



Example Input
Input 1:
A = "100"
B = "11"
Input 2:
A = "110"
B = "10"


Example Output
Output 1:
"111"
Output 2:
"1000"


Example Explanation
For Input 1:
The sum of 100 and 11 is 111.
For Input 2:
 
The sum of 110 and 10 is 1000.


*/

string Solution::addBinary(string A, string B) {
    string result = "";
    // padding
    if (A.size() != B.size()) {
        int pad_val = 0;
        if (A.size() < B.size()) {
            pad_val = B.size() - A.size();
            string str(pad_val,'0');
            A = str + A;
        }
        else {
            pad_val = A.size() - B.size();
            string str(pad_val,'0');
            B = str + B;
        }
    }

    int carry = 0;
    for (int i = A.size() - 1; i >= 0; i--) {
        if (A[i] == '0' && B[i] == '0') {
            result = (carry == 1) ? '1' + result : '0' + result;
            carry = 0;
        }
        else if (A[i] == '1' && B[i] == '1') {
            result = (carry == 1) ? '1' + result : '0' + result;
            carry = 1;
        }
        else if (A[i] != B[i]) {
            result = (carry == 1) ? '0' + result : '1' + result;
        }
    }

    if (carry == 1) result = '1' + result;

    return result;
}
