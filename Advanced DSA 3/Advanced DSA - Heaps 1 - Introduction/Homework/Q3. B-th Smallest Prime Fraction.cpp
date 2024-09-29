/*
Problem Description

Given a sorted array of integers A which contains 1 and some number of primes.
Then, for every p < q in the list, we consider the fraction p / q.



What is the B-th smallest fraction considered?

Return your answer as an array of integers, where answer[0] = p and answer[1] = q.





Problem Constraints

1 <= length(A) <= 2000
1 <= A[i] <= 30000
1 <= B <= length(A)*(length(A) - 1)/2



Input Format

The first argument of input contains the integer array, A.
The second argument of input contains an integer B.



Output Format

Return an array of two integers, where answer[0] = p and answer[1] = q.



Example Input

Input 1:

 A = [1, 2, 3, 5]
 B = 3
Input 2:

 A = [1, 7]
 B = 1


Example Output

Output 1:

 [2, 5]
Output 2:

 [1, 7]


Example Explanation

Explanation 1:

 The fractions to be considered in sorted order are:
 [1/5, 1/3, 2/5, 1/2, 3/5, 2/3]
 The third fraction is 2/5.
Explanation 2:

 The fractions to be considered in sorted order are:
 [1/7]
 The first fraction is 1/7.
*/

#define y second.second
#define x second.first

vector<int> Solution::solve(vector<int> &A, int B) {
    int K = B;
    priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>> q;
    unordered_map<int,int> nxt;
    for(int i = A.size()-1;i > 0;i--)
        nxt[A[i]] = A[i-1];

    double last = A[A.size()-1],d;
    nxt[1] = 0;

    for(int i = 0;i < A.size();i++){
        d = (double)A[i]/last;
        q.push(make_pair(d,make_pair(A[i],last)));
    }
    
    while(q.size() && K){
        K--;
        if(K == 0) break;

        pair<double,pair<int,int>> p = q.top();q.pop();
        if(nxt[p.y] != 0){
            p.y = nxt[p.y];
            d = (double)p.x/(double)p.y;
            q.push(make_pair(d,p.second));
        }
    }
    
    vector<int> ret(2);
    ret[0] = q.top().second.first;
    ret[1] = q.top().second.second;
    
    return ret;
}