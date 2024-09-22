/*
Problem Description
Given a string A, find the rank of the string amongst its permutations sorted lexicographically.

Note that the characters might be repeated. If the characters are repeated, we need to look at the rank in unique permutations.

Look at the example for more details.

NOTE:

The answer might not fit in an integer, so return your answer % 1000003 where 1000003 is a prime number.
String A can consist of both lowercase and uppercase letters. Characters with lesser ASCII values are considered smaller, i.e., 'a' > 'Z'.


Problem Constraints
1 <= len(A) <= 1000000



Input Format
First argument is a string A.



Output Format
Return an integer denoting the rank.



Example Input
Input 1:

 A = "aba"
Input 2:

 A = "bca"


Example Output
Output 1:

 2
Output 2:

 4


Example Explanation
Explanation 1:

 The order permutations with letters 'a', 'a', and 'b' :
    aab
    aba 
    baa
 So, the rank is 2.
Explanation 2:

 The order permutations with letters 'a', 'b', and 'c' :
    abc
    acb 
    bac
    bca
    cab
    cba
 So, the rank is 4.

*/

int m = 1000003;

long power(int n) { 
    long res = 1;
    long no = n;
    int p = m -2;
    while (p > 0) {
        if (p & 1) res = (res * no) % m;
        no = (no * no) % m;
        p >>= 1;
    }

    return res;
}

int indexAt(char a) {
    if (a <= 'Z') return a-'A';
    return a-'a'+26;
}

int Solution::findRank(string A) {
    long rank = 1;
    vector<int> freq_vec(52, 0);
    freq_vec[indexAt(A[A.size()-1])]++;

    long permutation = 1;
    for (int i = A.size()-2; i>=0; i--) {
        int index = indexAt(A[i]);
        freq_vec[index]++;
        for (int j = 0; j < index; j++) {
            if (freq_vec[j] != 0) {
                long temp = (permutation * freq_vec[j]) % m;
                temp = (temp * power(freq_vec[index])) % m;
                rank = (rank + temp) % m;
            }
        }
        permutation = (permutation * (A.size() - i) ) % m;
        permutation = (permutation * power(freq_vec[index]) ) % m;
    }

    return rank;
}
