/*
Problem Description

Given an integer, A. Find and Return first positive A integers in ascending order containing only digits 1, 2, and 3.


NOTE: All the A integers will fit in 32-bit integers.




Problem Constraints

1 <= A <= 29500



Input Format

The only argument given is integer A.



Output Format

Return an integer array denoting the first positive A integers in ascending order containing only digits 1, 2 and 3.



Example Input

Input 1:

 A = 3
Input 2:

 A = 7


Example Output

Output 1:

 [1, 2, 3]
Output 2:

 [1, 2, 3, 11, 12, 13, 21]


Example Explanation

Explanation 1:

 Output denotes the first 3 integers that contains only digits 1, 2 and 3.
Explanation 2:

 Output denotes the first 7 integers that contains only digits 1, 2 and 3.

*/

bool check(int num);
vector<int> Solution::solve(int A) {
    vector<int> res;
    for (int i =1; ; i++) {
        if (check(i)) res.push_back(i);
        if (res.size() == A || res.size() == 12) break;
    }

    int prev_size = 3;
    int key = 2;
    while (A > res.size()) {
        int n = res.size();
        int val = pow(10, key);
        for (int i = prev_size; i < n; i++) {
            for (int j =1; j<=3; j++) {
                res.push_back(res[i]*10 + j);
                if (res.size() == A) break;
            }

            if (res.size() == A) break;
        }
        prev_size = n;
        key++;
    }

    return res;
}

bool check(int num) {
    while(num != 0) {
        int k = num % 10;
        if (k == 1 || k == 2 || k == 3) {
            num = num / 10;
            continue;
        }
        else return false;
    }

    return true;
}