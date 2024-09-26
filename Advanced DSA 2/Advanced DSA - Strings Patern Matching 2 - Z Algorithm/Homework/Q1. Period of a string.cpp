/*
Problem Description

You are given a string A of length N consisting of lowercase alphabets. Find the period of the string.


Period of the string is the minimum value of k (k >= 1), that satisfies A[i] = A[i % k] for all valid i.




Problem Constraints

1 <= N <= 106



Input Format

First and only argument is a string A of length N.



Output Format

Return an integer, denoting the period of the string.



Example Input

Input 1:

 A = "abababab"
Input 2:

 A = "aaaa"


Example Output

Output 1:

 2
Output 2:

 1


Example Explanation

Explanation 1:

 Period of the string will be 2: 
 Since, for all i, A[i] = A[i%2]. 
Explanation 2:

 Period of the string will be 1.

*/

int Solution::solve(string A) {
    vector<int> z_arr(A.size());

    int left = 0;
    int right = 0;

    for (int i = 1; i < A.size(); i++) {
        if (i > right) {
            left = right = i;
            while (right < A.size() && A[right] == A[right-left]) right++;
            z_arr[i] = right-left;
            right--;
        }
        else {
            if (i + z_arr[i-left] <= right) z_arr[i] = z_arr[i-left];
            else {
                left = i;
                while (right < A.size() && A[right] == A[right-left]) right++;
                z_arr[i] = right-left;
                right--;
            } 
        }
    }


    for (int i =1; i < A.size(); i++) if (i+z_arr[i] == A.size()) return i;

    return A.size();
}
