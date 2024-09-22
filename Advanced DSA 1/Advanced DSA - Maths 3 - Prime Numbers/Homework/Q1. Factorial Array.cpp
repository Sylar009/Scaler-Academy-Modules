/*
Problem Description
Groot has an array A of size N. However, seeking excitement, Groot embarked on constructing an equally-sized array B with a unique definition for each of its elements:

B[i] = factorial of A[i] for every i such that 1<= i <= N.

Now Groot is interested in the total number of non-empty subsequences of array B such that every element in the subsequence has the same non-empty set of prime factors.

Since the number can be huge, return it modulo 109 + 7.

NOTE:

Factorial of a number X denotes (1 x 2 x 3 x 4......(X-1) x (X)).
A set is a data structure having only distinct elements. E.g : the set of prime factors of Y=12 will be {2,3} and not {2,2,3}


Problem Constraints
1 <= N <= 105
1 <= A[i] <= 106



Input Format
Only argument is an integer array A of size N.



Output Format
Return an integer deonting the total number of non-empty subsequences of array B such that every element in the subsequence has the same set of prime factors modulo 109+7.



Example Input
Input 1:

 A = [2, 3, 2, 3]
Input 2:

 A = [2, 3, 4]


Example Output
Output 1:

 6
Output 2:

 4


Example Explanation
Explanation 1:

 Array B will be : [2, 6, 2, 6]
 The total possible subsequences are 6 : [2], [2], [2, 2], [6], [6], [6, 6].
Explanation 2:

 Array B will be : [2, 6, 24]
 The total possible subsequences are 4 : [2], [6], [24], [6, 24].


*/

int Solution::solve(vector<int> &A) {
    int res = 0;

    // find max_val
    int max_val = *max_element(A.begin(), A.end());

    // declare the spf array
    vector<int> spf_vec(max_val+1, 1);
    int pre_val = 1;

    // finding and filling spf vector
    for (int i = 2; i*i <= max_val; i++) 
        if (spf_vec[i] == 1) 
            for (int j = i*i; j <= max_val; j += i) 
                spf_vec[j] = 0;

    for (int b = 2; b <= max_val; b++) {
        if (spf_vec[b] == 1) pre_val = b;
        spf_vec[b] = pre_val;
    }

    unordered_map<int, int> hm;
    for (int a : A) {
        if ( a == 1) continue;
        if (hm.find(spf_vec[a]) != hm.end()) hm[spf_vec[a]]++;
        else hm[spf_vec[a]] = 1;
        res += (1<<(hm[spf_vec[a]])-1);
    }

    return res;
}

