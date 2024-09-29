/*
Problem Description

Given an array of integers A of size N.





A triplet (i, j, k), i < j <= k is called a power triplet if A[i] ^ A[i+1] ^....A[j-1] = A[j] ^.....^A[k].

Where, ^ denotes bitwise xor.

Return the count of all possible power triplets. Since the answer could be large return answer % 109 +7.






Problem Constraints

1 <= N <= 100000
1 <= A[i] <= 100000



Input Format

The first argument given is the integer array A.



Output Format

Return the count of all possible power triplets % 109 + 7.



Example Input

Input 1:

 A = [5, 2, 7]
Input 2:

 A = [1, 2, 3]


Example Output

Output 1:

 2
Output 2:

 2


Example Explanation

Explanation 1:

 All possible power triplets are:
    1. (1, 2, 3) ->  A[1] = A[2] ^ A[3]
    2. (1, 3, 3) ->  A[1] ^ A[2] = A[3]
Explanation 2:

 All possible power triplets are:
    1. (1, 2, 3) ->  A[1] = A[2] ^ A[3]
    2. (1, 3, 3) ->  A[1] ^ A[2] = A[3]

*/

class TrieNode {
public:
    int no;
    int sum;
    TrieNode* child[2];
   
    TrieNode() : no(0), sum(0) {
        child[0] = NULL;
        child[1] = NULL;
    }
};

void add_number(TrieNode* A, int num, int index){
    for( int x = 31; x >= 0; x--) {
       
        int bit = 1 & (num >> x) ;
       
        if ( A->child[bit] == nullptr){
            A->child[bit] = new TrieNode();
        }
        A = A->child[bit];
    }
    
    A->sum += index;
    A->no++;
}

int calculate_index_pair(TrieNode* A, int num, int index) {
    for( int x = 31; x >= 0; x--){
        int bit = 1 & (num >> x);
       
        if (A->child[bit] == nullptr) return 0;

        A = A->child[bit];
    }

    return (((A->no) * index) - (A->sum) );
}

int Solution::solve(vector<int> &A) {
    long long res = 0;
    
    int _xor = 0;

    TrieNode* root = new TrieNode();
   
    for ( int x = 0 ; x < A.size(); x++){
        add_number(root, _xor, x);

        _xor ^= A[x];
        res = (res + calculate_index_pair(root, _xor, x)) % 1000000007;
    }

    return res;
}

