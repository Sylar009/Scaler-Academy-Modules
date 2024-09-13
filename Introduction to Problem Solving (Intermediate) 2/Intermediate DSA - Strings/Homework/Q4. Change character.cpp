/*
Problem Description
You are given a string A of size N consisting of lowercase alphabets.

You can change at most B characters in the given string to any other lowercase alphabet such that the number of distinct characters in the string is minimized.

Find the minimum number of distinct characters in the resulting string.



Problem Constraints
1 <= N <= 100000

0 <= B <= N



Input Format
The first argument is a string A.

The second argument is an integer B.



Output Format
Return an integer denoting the minimum number of distinct characters in the string.



Example Input
A = "abcabbccd"
B = 3



Example Output
2



Example Explanation
We can change both 'a' and one 'd' into 'b'.So the new string becomes "bbcbbbccb".
So the minimum number of distinct character will be 2.


*/
int Solution::solve(string A, int B) {
    if (A.size() == 1) return 1;

    int ans = 0;
    vector<int> count_arr(26,0);
    
    for (char a : A) count_arr[a-97]++;

    sort(count_arr.begin(), count_arr.end());
    for (int i = 0 ; i < 26; i++) {
        if (count_arr[i] > 0 && count_arr[i] <= B) {
            B -= count_arr[i];
            count_arr[i] = (B > 0) ? 0 : (-1)*B;
        }
    }

    for (int y : count_arr) ans = y > 0 ? ++ans : ans;

    return ans;
}
    