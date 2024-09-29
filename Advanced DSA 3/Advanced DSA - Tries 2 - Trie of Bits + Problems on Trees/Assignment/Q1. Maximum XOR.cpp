/*
Problem Description

Given an array of integers A, find and return the maximum result of A[i] XOR A[j], where i, j are the indexes of the array.



Problem Constraints

1 <= length of the array <= 100000
0 <= A[i] <= 109



Input Format

The only argument given is the integer array A.



Output Format

Return an integer denoting the maximum result of A[i] XOR A[j].



Example Input

Input 1:

 A = [1, 2, 3, 4, 5]
Input 2:

 A = [5, 17, 100, 11]


Example Output

Output 1:

 7
Output 2:

 117


Example Explanation

Explanation 1:

 Maximum XOR occurs between element of indicies(0-based) 1 and 4 i.e. 2 ^ 5 = 7.
Explanation 2:

 Maximum XOR occurs between element of indicies(0-based) 1 and 2 i.e. 17 ^ 100 = 117.


*/

class Node {
    public:
    Node* child[2];

    Node() {
        child[0] = nullptr;
        child[1] = nullptr;
    }    
};

Node* insert(Node* rn, int val) {
    Node* t = rn;
    for (int i = 31; i>=0; i--) {
        int bit = ((1<<i) & val) == 0 ? 0 : 1;
        if (!t->child[bit]) t->child[bit] = new Node();
        t = t->child[bit];
    }
    return rn;
}

void find_max_xor(Node* rn, int val, int &mx) {
    int res = 0;
    Node* t = rn;
    for (int i =31; i >=0; i--) {
        int bit = (1<<i) & val;
        if (bit == 0) {
            if (t->child[1]) {
                res |= (1<<i);
                t = t->child[1];
            }
            else t = t->child[0];
        }
        else {
            if (t->child[0]) t = t->child[0];
            else {
                t = t->child[1];
                res |= (1 << i);
            }
        }
    }

    mx = max(mx, val^res);
}

int Solution::solve(vector<int> &A) {
    int max_xor = INT_MIN;
    Node* rn = new Node();
    for (int x : A) rn = insert(rn, x);
    for (int x : A) find_max_xor(rn, x, max_xor);

    return max_xor;
}
