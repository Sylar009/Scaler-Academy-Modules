/*
Problem Description

You are given a matrix A of size N x 2 which represents different operations.
Assume initially you have a stack-like data structure you have to perform operations on it.

Operations are of two types:


1 x: push an integer x onto the stack and return -1.

2 0: remove and return the most frequent element in the stack. This basically means the element which has the highest count among all the elements currently in the stack.

If there is a tie for the most frequent element, the element closest to the top of the stack is removed and returned.

A[i][0] describes the type of operation to be performed. A[i][1] describe the element x or 0 corresponding to the operation performed.




Problem Constraints

1 <= N <= 100000

1 <= A[i][0] <= 2

0 <= A[i][1] <= 109



Input Format

The only argument given is the integer array A.



Output Format

Return the array of integers denoting the answer to each operation.



Example Input

Input 1:







A = [
            [1, 5]
            [1, 7]
            [1, 5]
            [1, 7]
            [1, 4]
            [1, 5]
            [2, 0]
            [2, 0]
            [2, 0]
            [2, 0]  ]


Input 2:











 A =  [   
        [1, 5]
        [2, 0]
        [1, 4]   ]








Example Output

Output 1:

 [-1, -1, -1, -1, -1, -1, 5, 7, 5, 4]
Output 2:

 [-1, 5, -1]


Example Explanation

Explanation 1:







 Just simulate given operations.


Explanation 2:











 Just simulate given operations.
*/

vector<int> Solution::solve(vector<vector<int> > &A) {
    map<int,int>map1;
    map<int,stack<int>>map2;
    vector<int>res;
    int maxfreq=0;
    for(int i=0;i<A.size();i++)
    {
        int operation= A[i][0];
        int ele = A[i][1];
        if(operation == 1)
        {
            res.push_back(-1);
            map1[ele]++;
            map2[map1[ele]].push(ele);

            maxfreq = max(maxfreq,map1[ele]);
        }
        else
        {
           res.push_back(map2[maxfreq].top());
           map1[map2[maxfreq].top()]--;
           map2[maxfreq].pop();

           if(map2[maxfreq].empty())maxfreq--;
        }
    }
    return res;
}
