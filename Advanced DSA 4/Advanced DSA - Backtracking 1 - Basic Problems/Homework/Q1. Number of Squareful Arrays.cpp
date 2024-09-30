/*
Problem Description

Given an array of integers A, the array is squareful if for every pair of adjacent elements, their sum is a perfect square.

Find and return the number of permutations of A that are squareful. Two permutations A1 and A2 differ if and only if there is some index i such that A1[i] != A2[i].



Problem Constraints

1 <= length of the array <= 12

1 <= A[i] <= 109



Input Format

The only argument given is the integer array A.



Output Format

Return the number of permutations of A that are squareful.



Example Input

Input 1:

 A = [2, 2, 2]
Input 2:

 A = [1, 17, 8]


Example Output

Output 1:

 1
Output 2:

 2


Example Explanation

Explanation 1:

 Only permutation is [2, 2, 2], the sum of adjacent element is 4 and 4 and both are perfect square.
Explanation 2:

 Permutation are [1, 8, 17] and [17, 8, 1].


*/

/***************************************************************
****************************************************************

bool isPerfectSquare(int x) {
    int n = (int) sqrt(x);
    return pow(n, 2) == x;
}

void backtrack(map < int, set < int > > & graph, map < int, int > & count, int n, int value, vector < int > temp, vector < vector < int > > & res) {
    if (count[value] == 0) {
        return;
    }
    if (graph.find(value) == graph.end()) {
        return;
    }
    count[value]--;
    temp.push_back(value);
    if (temp.size() == n) {
        res.push_back(vector < int > (temp.begin(), temp.end()));
    } else {
        for (auto i: graph[value]) {
            // traverse all adjacent vertices
            backtrack(graph, count, n, i, temp, res);
        }
    }
    temp.pop_back();
    count[value]++;
}

int Solution::solve(vector < int > & A) {
    map < int, int > count;
    int i, j, n = A.size();
    for (i = 0; i < n; i++) {
        count[A[i]]++;
    }
    map < int, set < int > > graph;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (isPerfectSquare(A[i] + A[j])) {
                // add an edge from i to j and j to i
                set < int > s = graph[A[i]];
                if (s.find(A[j]) == s.end()) {
                    s.insert(A[j]);
                    graph[A[i]] = s;
                }
                s = graph[A[j]];
                if (s.find(A[i]) == s.end()) {
                    s.insert(A[i]);
                    graph[A[j]] = s;
                }
            }
        }
    }
    vector < vector < int > > res;
    for (auto i: count) {
        vector < int > v;
        backtrack(graph, count, n, i.first, v, res);
    }
    return res.size();
}


****************************************************************
***************************************************************/
bool is_perfect_sq(long no) {
    long n = no;
    long low = 1;
    long high = no;

    if (no == 1) return true;

    while (low <= high) {
        long mid = (high + low) / 2;

        if (mid * mid == no) return true;

        if (mid * mid > no) high = mid - 1;
        else if (mid * mid < no) low = mid + 1;        
    }

    return false;
}
void prem_prefect_sq(vector<int> &A, unordered_map<int, int> &hm,
vector<int> & temp, int &count, int idx) {
    if (idx == A.size()) {
        count++;
        return;
    }

    for (auto[key, freq] : hm) {
        if (freq == 0) continue;

        if ((temp.size() > 0) && 
        !(is_perfect_sq(temp[idx-1] + 0L + key)) ) continue;

        temp.push_back(key);
        hm[key]--;

        prem_prefect_sq(A, hm, temp, count, idx+1);
        temp.pop_back();
        hm[key]++;
    }
}

int Solution::solve(vector<int> &A) {
    vector<int> temp;
    unordered_map<int, int> hm;

    if (A.size() == 1) return 0;

    for (int i = 0; i < A.size(); i++) hm[A[i]]++;

    int idx = 0;
    int count = 0;

    prem_prefect_sq(A, hm, temp, count, idx);
    return count;
}
