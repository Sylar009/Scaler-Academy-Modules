/*
Problem Description

Determine the "GOOD"ness of a given string A, where the "GOOD"ness is defined by the length of the longest substring that contains no repeating characters. The greater the length of this unique-character substring, the higher the "GOOD"ness of the string.

Your task is to return an integer representing the "GOOD"ness of string A.

Note: The solution should be achieved in O(N) time complexity, where N is the length of the string.



Problem Constraints

1 <= size(A) <= 106

String consists of lowerCase,upperCase characters and digits are also present in the string A.



Input Format

Single Argument representing string A.



Output Format

Return an integer denoting the maximum possible length of substring without repeating characters.



Example Input

Input 1:

 A = "abcabcbb"
Input 2:

 A = "AaaA"


Example Output

Output 1:

 3
Output 2:

 2


Example Explanation

Explanation 1:

 Substring "abc" is the longest substring without repeating characters in string A.
Explanation 2:

 Substring "Aa" or "aA" is the longest substring without repeating characters in string A.
*/

int Solution::lengthOfLongestSubstring(string A) {

    int res = 0;
    int left = 0;
    int right = 0;

    unordered_set<char> hs;
    while (right < A.size()) {
        if (hs.find(A[right]) != hs.end()) {
            hs.erase(A[left]);
            left++;
        }
        else {
            hs.insert(A[right]);
            right++;
            int size = hs.size();
            res = max(res, size);
        }
    }

    return res;
}
