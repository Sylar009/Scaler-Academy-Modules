/*
Problem Description
Given a decimal number A and a base B, convert it into its equivalent number in base B.


Problem Constraints
0 <= A <= 512
2 <= B <= 10


Input Format
The first argument will be decimal number A.
The second argument will be base B.


Output Format
Return the conversion of A in base B.


Example Input
Input 1:
A = 4
B = 3
Input 2:
A = 4
B = 2 


Example Output
Output 1:
11
Output 2:
100


Example Explanation
Explanation 1:
Decimal number 4 in base 3 is 11.
Explanation 2:
Decimal number 4 in base 2 is 100. 
*/

int Solution::DecimalToAnyBase(int A, int B) {
    int ans = 0;

    string s = "";
    int rem = A % B;
    s = s + to_string(rem);
    int que = A / B;

    while (que > 0) {
        rem = que % B;
        s = s + to_string(rem);
        que = que / B; 
    }

    int index = 0;
    for (int i = 0; i < s.size(); i++) {
        int val = (int)(s[i]) - 48;
        ans = ans + val * pow(10, index);
        index++;
    }

    return ans;
}
