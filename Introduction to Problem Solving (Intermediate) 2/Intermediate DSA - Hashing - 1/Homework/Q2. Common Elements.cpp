/*
Problem Description
Given two integer arrays, A and B of size N and M, respectively. Your task is to find all the common elements in both the array.

NOTE:

Each element in the result should appear as many times as it appears in both arrays.
The result can be in any order.


Problem Constraints
1 <= N, M <= 105

1 <= A[i] <= 109



Input Format
First argument is an integer array A of size N.

Second argument is an integer array B of size M.



Output Format
Return an integer array denoting the common elements.



Example Input
Input 1:

 A = [1, 2, 2, 1]
 B = [2, 3, 1, 2]
Input 2:

 A = [2, 1, 4, 10]
 B = [3, 6, 2, 10, 10]


Example Output
Output 1:

 [1, 2, 2]
Output 2:

 [2, 10]


Example Explanation
Explanation 1:

 Elements (1, 2, 2) appears in both the array. Note 2 appears twice in both the array.
Explantion 2:

 Elements (2, 10) appears in both the array.


*/

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    vector<int> result;

    unordered_map<int, int> freq_map_A;
    for (int a : A) {
        if (auto search = freq_map_A.find(a); search != freq_map_A.end()) 
            freq_map_A.at(a)++;
        else freq_map_A[a] = 1;
    }

    unordered_map<int, int> freq_map_B;
    for (int b : B) {
        if (auto search = freq_map_B.find(b); search != freq_map_B.end()) 
            freq_map_B.at(b)++;
        else freq_map_B[b] = 1;
    }

    for (auto &i : freq_map_A) {
        if (auto search = freq_map_B.find(i.first); search != freq_map_B.end()) {
            int val = min(i.second, freq_map_B[i.first]);
            while (val > 0) {
                result.push_back(i.first);
                val--;
            }
        }
    }

    return result;
}
