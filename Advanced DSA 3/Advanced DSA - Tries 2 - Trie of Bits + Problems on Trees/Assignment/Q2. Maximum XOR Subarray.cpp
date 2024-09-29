/*
Problem Description

Given an array, A of integers of size N. Find the subarray AL, AL+1, AL+2, ... AR with 1<=L<=R<=N, which has maximum XOR value.






NOTE: If there are multiple subarrays with the same maximum value, return the subarray with minimum length. If the length is the same, return the subarray with the minimum starting index.








Problem Constraints

1 <= N <= 100000
0 <= A[i] <= 109



Input Format

First and only argument is an integer array A.



Output Format

Return an integer array B of size 2. B[0] is the starting index(1-based) of the subarray and B[1] is the ending index(1-based) of the subarray.



Example Input

Input 1:

 A = [1, 4, 3]
Input 2:

 A = [8]


Example Output

Output 1:

 [2, 3]
Output 2:

 [1, 1]


Example Explanation

Explanation 1:

 There are 6 possible subarrays of A:
 subarray            XOR value
 [1]                     1
 [4]                     4
 [3]                     3
 [1, 4]                  5 (1^4)
 [4, 3]                  7 (4^3)
 [1, 4, 3]               6 (1^4^3)

 [4, 3] subarray has maximum XOR value. So, return [2, 3].
Explanation 2:

 There is only one element in the array. So, the maximum XOR value is equal to 8 and the only possible subarray is [1, 1]. 

*/

class Node {
    public:
    Node* child[2];
    Node () {
        child[0] = nullptr;
        child[1] = nullptr;
    }
};

vector<int> Solution::solve(vector<int> &A) {
    vector<int> pf_xor;
    unordered_map<int, int> hm;

    pf_xor.push_back(A[0]);
    Node* rn = new Node();

    int max_xor = A[0];
    int left_idx = 0;
    int right_idx = 0;
    int size = 31;
    for (int i = 1; i < A.size(); i++) {
        if (A[i] > max_xor){
            max_xor = A[i];
            left_idx = i;
            right_idx = i;
        }

        pf_xor.push_back(pf_xor[i-1]^A[i]);

        if(pf_xor[i] > max_xor) {
            max_xor = pf_xor[i];
            left_idx = 0;
            right_idx = i;
        }
    }

    for (int i = 0; i < pf_xor.size(); i++)
        if (hm.find(pf_xor[i]) == hm.end()) hm.insert({pf_xor[i], i});

    for (int i = 0; i < pf_xor.size(); i++) {
        Node* curr = rn;
        for (int j = size; j >= 0; j--) {
            if (pf_xor[i] & (1<<j)) {
                if (!curr->child[1]) curr->child[1] = new Node();
                curr = curr->child[1]; 
            }
            else {
                if (!curr->child[0]) curr->child[0] = new Node();
                curr = curr->child[0];
            }
        }
    }

    for (int i = 0; i < pf_xor.size(); i++) {
        Node* curr = rn;
        int curr_xor = 0;


        for (int j = size; j >= 0; j--) {

            if(pf_xor[i] & (1 << j)) {
                if (curr->child[0]) curr = curr->child[0];
                else {
                    curr = curr->child[1];
                    curr_xor |= (1 << j);
                }
            }
            else {
                if (curr->child[1]) {
                    curr = curr->child[1];
                    curr_xor |= (1 << j);
                }
                else curr = curr->child[0];
            }
        }

        if ( ((pf_xor[i]^curr_xor) > max_xor) || 
        ( (max_xor <= (pf_xor[i]^curr_xor)) && 
        ((max(i+1, hm[curr_xor]) - min(i+1, hm[curr_xor])) 
        < (right_idx-left_idx)) ) ) {
            max_xor = (pf_xor[i]^curr_xor);
            left_idx = min(i+1, hm[curr_xor]);
            right_idx = max(i+1, hm[curr_xor]);
        }
    }

    return {left_idx+1, right_idx+1};
}
