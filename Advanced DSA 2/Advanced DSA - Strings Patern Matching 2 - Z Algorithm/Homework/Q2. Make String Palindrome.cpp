/*
Problem Description

Given a string A of size N consisting only of lowercase alphabets. The only operation allowed is to insert characters in the beginning of the string.


Find and return how many minimum characters are needed to be inserted to make the string a palindrome string.




Problem Constraints

1 <= N <= 106



Input Format

The only argument given is a string A.



Output Format

Return an integer denoting the minimum characters needed to be inserted in the beginning to make the string a palindrome string.



Example Input

Input 1:

 A = "abc"
Input 2:

 A = "bb"


Example Output

Output 1:

 2
Output 2:

 0


Example Explanation

Explanation 1:

 Insert 'b' at beginning, string becomes: "babc".
 Insert 'c' at beginning, string becomes: "cbabc".
Explanation 2:

 There is no need to insert any character at the beginning as the string is already a palindrome. 

*/

int Solution::solve(string A) {
    string str = A + "#" + string(A.rbegin(), A.rend());

    vector<int> z_arr(str.size());

    int left = 0;
    int right = 0;

    for (int i = 1; i < str.size(); i++) {
        if (i > right) {
            left = right = i;
            while (right < str.size() && str[right] == str[right-left]) right++;
            z_arr[i] = right-left;
            right--;
        }
        else {
            if (i + z_arr[i-left] <= right) z_arr[i] = z_arr[i-left];
            else {
                left = i;
                while (right < str.size() && str[right] == str[right-left]) right++;
                z_arr[i] = right-left;
                right--;
            } 
        }
    }

    int ans = 0;
    int start = 0;
    for (int i = 1; i < z_arr.size(); i++) {
        if (str[i] == '#') start = i;
        else if (start != 0 ) {
            if ((i-start+z_arr[i])*2 >= str.size()) return ans;
            ans++;
        }
    }

    return -1;
}

