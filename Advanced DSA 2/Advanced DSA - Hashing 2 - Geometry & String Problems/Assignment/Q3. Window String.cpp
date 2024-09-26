/*
Problem Description

Given a string A and a string B, find the window with minimum length in A, which will contain all the characters in B in linear time complexity.
Note that when the count of a character c in B is x, then the count of c in the minimum window in A should be at least x.

Note:

If there is no such window in A that covers all characters in B, return the empty string.
If there are multiple such windows, return the first occurring minimum window ( with minimum start index and length )



Problem Constraints

1 <= size(A), size(B) <= 106



Input Format

The first argument is a string A.
The second argument is a string B.



Output Format

Return a string denoting the minimum window.



Example Input

Input 1:

 A = "ADOBECODEBANC"
 B = "ABC"
Input 2:

 A = "Aa91b"
 B = "ab"



Example Output

Output 1:

 "BANC"
Output 2:

 "a91b"


Example Explanation

Explanation 1:

 "BANC" is a substring of A which contains all characters of B.
Explanation 2:

 "a91b" is the substring of A which contains all characters of B.

*/

string Solution::minWindow(string A, string B) {
    unordered_map<char, int> hm_sub;
    unordered_map<char, int> hm_str;

    int left = 0;
    int right = 0;
    int min_len = INT_MAX;
    string res = "";

    for (int i = 0; i < B.size(); i++) 
        if (hm_sub.find(B[i]) != hm_sub.end()) hm_sub[B[i]]++;
        else hm_sub[B[i]] = 1;

    int req = hm_sub.size();
    int curr_sz = 0;

    while (right < A.size()) {
        char c = A[right];
        if (hm_str.find(A[right]) != hm_sub.end()) hm_str[A[right]]++;
        else hm_str[A[right]] = 1;

        if (hm_sub.find(c) != hm_sub.end() && hm_str[c] == hm_sub[c])
            curr_sz++;
        
        while (left <= right && curr_sz == req) {
            c = A[left];
            if ((right -left + 1) < min_len ) {
                min_len = right - left + 1;
                res = A.substr(left, right-left+1);
            }

            hm_str[A[left]]--;
            if (hm_str[A[left]] == 0) hm_str.erase(A[left]);

            if (hm_sub.find(c) != hm_sub.end() && hm_str[c] < hm_sub[c]) curr_sz--;
            
            left++;
        }
        right++;
    }

    return res;
}
