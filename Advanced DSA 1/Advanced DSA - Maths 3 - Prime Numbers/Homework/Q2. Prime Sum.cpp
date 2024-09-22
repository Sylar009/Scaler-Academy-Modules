/*
Problem Description
Given an even number A ( greater than 2 ), return two prime numbers whose sum will be equal to the given number.

If there is more than one solution possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b, and [c,d] is another solution with c <= d, then 
[a, b] < [c, d], If a < c OR a==c AND b < d. 
NOTE: A solution will always exist. Read Goldbach's conjecture.



Problem Constraints
4 <= A <= 2*107



Input Format
First and only argument of input is an even number A.



Output Format
Return a integer array of size 2 containing primes whose sum will be equal to given number.



Example Input
 4


Example Output
 [2, 2]


Example Explanation
 There is only 1 solution for A = 4.
*/

vector<int> Solution::primesum(int A) {
vector<bool> spf_vec (A+1,true);
    spf_vec[0]=0;
    spf_vec[1]=1;
    for(int i = 2; i*i<= A; i++){
        if(spf_vec[i]){
            for(int j = i*i;j<= A;j += i){
                spf_vec[j]=false;
            }
        }
    }

    vector<int> res;
    for(int i=2; i<=A; i++) {
        if(spf_vec[i] && spf_vec[A-i]) {
            res.push_back(min(i,A-i));
            res.push_back(max(i,A-i));
            return res;
        }
    }

    return res;
}
