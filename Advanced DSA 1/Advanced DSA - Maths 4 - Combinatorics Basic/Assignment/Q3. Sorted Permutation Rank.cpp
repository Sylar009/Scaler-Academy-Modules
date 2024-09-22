/*
Problem Description
Given a string A. Find the rank of the string amongst its permutations sorted lexicographically.
Assume that no characters are repeated.

Note: The answer might not fit in an integer, so return your answer % 1000003



Problem Constraints
1 <= |A| <= 1000



Input Format
First argument is a string A.



Output Format
Return an integer denoting the rank of the given string.



Example Input
Input 1:

A = "acb"
Input 2:

A = "a"


Example Output
Output 1:

2
Output 2:

1


Example Explanation
Explanation 1:

Given A = "acb".
The order permutations with letters 'a', 'c', and 'b' : 
abc
acb
bac
bca
cab
cba
So, the rank of A is 2.
Explanation 2:

Given A = "a".
Rank is clearly 1.
*/

int m = 1000003;
int getLlesserCharacterCount(string &A, int b) {
    int count = 0;
    for (int i = b+1; i < A.size(); i++ ) if (A[b] > A[i]) count++;
    return count % m;
}

vector<int> factorial() {
    vector<int> f(1000, 0);
    f[1]=1;
    for (int i = 2; i<=1000; i++) f[i] = (f[i-1] * i) % m;

    return f;
}
int Solution::findRank(string A) {

    long ros = 0;

    vector<int> fact= factorial();

    for (int i = 0; i < A.size(); i++) {
        long lcor = getLlesserCharacterCount(A, i);
        long pc = fact[A.size() - i -1];
        ros += (lcor * pc ) % m;
    }

    return (ros+1) % m;
 }
