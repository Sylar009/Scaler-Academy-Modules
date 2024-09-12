/*
Problem Description
Given an array A of non-negative integers, arrange them such that they form the largest number.

Note: The result may be very large, so you need to return a string instead of an integer.



Problem Constraints
1 <= len(A) <= 100000
0 <= A[i] <= 2*109



Input Format
The first argument is an array of integers.



Output Format
Return a string representing the largest number.



Example Input
Input 1:

 A = [3, 30, 34, 5, 9]
Input 2:

 A = [2, 3, 9, 0]


Example Output
Output 1:

 "9534330"
Output 2:

 "9320"


Example Explanation
Explanation 1:

Reorder the numbers to [9, 5, 34, 3, 30] to form the largest number.
Explanation 2:

Reorder the numbers to [9, 3, 2, 0] to form the largest number 9320.
*/

bool comparatorFunc(int x, int y) {
    string x_yStr = to_string(x) + to_string(y);
    string y_xStr = to_string(y) + to_string(x);
    if(x_yStr.compare(y_xStr) > 0) return true;
    else return false;
}

string Solution::largestNumber(const vector<int> &A) {
    vector<int> B = A;
    sort(B.begin(), B.end(), comparatorFunc);

    string ans = "";
    for (int b : B) {
        if (b == 0 && ans == "0") ans = "0";
        else ans += to_string(b);
    }

    return ans;
}
