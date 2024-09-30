/*
Problem Description

Given a string A, partition A such that every string of the partition is a palindrome.

Return all possible palindrome partitioning of A.

Ordering the results in the answer : Entry i will come before Entry j if :

len(Entryi[0]) < len(Entryj[0]) OR
(len(Entryi[0]) == len(Entryj[0]) AND len(Entryi[1]) < len(Entryj[1])) OR * * *
(len(Entryi[0]) == len(Entryj[0]) AND ... len(Entryi[k] < len(Entryj[k]))


Problem Constraints

1 <= len(A) <= 15



Input Format

First argument is a string A of lowercase characters.



Output Format

Return a list of all possible palindrome partitioning of s.



Example Input

Input 1:

A = "aab"
Input 2:

A = "a"


Example Output

Output 1:

 [
    ["a","a","b"]
    ["aa","b"],
  ]
Output 2:

 [
    ["a"]
  ]


Example Explanation

Explanation 1:

In the given example, ["a", "a", "b"] comes before ["aa", "b"] because len("a") < len("aa").
Explanation 2:

In the given example, only partition possible is "a" .

*/


bool pal(string s){ //to check palindrome
    int n=s.length();bool cond=true;
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-1-i]){
            cond=false;
        }
    }
    if(n==0){
        return false;
    }
    return cond;
}
vector<vector<string> >ans; 

void backtrack(string s, int l, int n, vector<string> v){

    if(l >= n){ //base case
        ans.push_back(v);
        return ;
    }
    for(int i=l;i<=n;i++){
        string temp = s.substr(l,i-l); //partitioning palindrome from left side
        if(pal(temp)){
            v.push_back(temp);
            backtrack(s, i, n, v); // recursive call 
            v.pop_back();       // 
        }
    }
}

vector<vector<string> > Solution::partition(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    ans.clear();
    vector<string>v;
    backtrack(A , 0 , A.size(), v); 
    return ans;
}
