/*
Problem Description
Surprisingly, in an alien language, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given an array of words A of size N written in the alien language, and the order of the alphabet denoted by string B of size 26, return 1 if and only if the given words are sorted lexicographically in this alien language else, return 0.



Problem Constraints
1 <= N, length of each word <= 105

Sum of the length of all words <= 2 * 106



Input Format
The first argument is a string array A of size N.

The second argument is a string B of size 26, denoting the order.



Output Format
Return 1 if and only if the given words are sorted lexicographically in this alien language else, return 0.



Example Input
Input 1:

 A = ["hello", "scaler", "interviewbit"]
 B = "adhbcfegskjlponmirqtxwuvzy"
Input 2:

 A = ["fine", "none", "bush"]
 B = "qwertyuiopasdfghjklzxcvbnm"


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 The order shown in string B is: h < s < i (adhbcfegskjlponmirqtxwuvzy) for the given words. 
 So, Return 1.
Explanation 2:

 "none" should be present after "bush", Since b < n (qwertyuiopasdfghjklzxcvbnm). 
 So, Return 0.

*/

int Solution::solve(vector<string> &A, string B) {
    unordered_map<char,int> hm;
    int freq = 1;
    for (char b : B){
        hm[b] = freq;
        freq++;
    }

    for (int i = 0; i < A.size() - 1; i++) {
        if (hm[A[i][0]] > hm[A[i+1][0]]) return 0;
        else if (hm[A[i][0]] == hm[A[i+1][0]]) {
            int min_len = min(A[i].size(), A[i+1].size());
            for (int j =0; j < min_len; j++) {
                if (hm[A[i][j]] != hm[A[i+1][j]] ) {
                    if(hm[A[i][j]] > hm[A[i+1][j]]) return 0;
                    else break;
                }                    
                else continue;
            }
            if (A[i].size() != A[i+1].size() && A[i+1].size() == min_len) return 0;
        }
        else continue;
    }

    return 1;
}
