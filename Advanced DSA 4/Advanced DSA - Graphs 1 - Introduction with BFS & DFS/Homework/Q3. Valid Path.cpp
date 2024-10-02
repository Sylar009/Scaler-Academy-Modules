/*
Problem Description

There is a rectangle with left bottom as (0, 0) and right up as (x, y).

There are N circles such that their centers are inside the rectangle.

Radius of each circle is R. Now we need to find out if it is possible that we can move from (0, 0) to (x, y) without touching any circle.

Note : We can move from any cell to any of its 8 adjecent neighbours and we cannot move outside the boundary of the rectangle at any point of time.



Problem Constraints

0 <= x , y, R <= 100

1 <= N <= 1000

Center of each circle would lie within the grid



Input Format

1st argument given is an Integer x , denoted by A in input.

2nd argument given is an Integer y, denoted by B in input.

3rd argument given is an Integer N, number of circles, denoted by C in input.

4th argument given is an Integer R, radius of each circle, denoted by D in input.

5th argument given is an Array A of size N, denoted by E in input, where A[i] = x cordinate of ith circle

6th argument given is an Array B of size N, denoted by F in input, where B[i] = y cordinate of ith circle



Output Format

Return YES or NO depending on weather it is possible to reach cell (x,y) or not starting from (0,0).



Example Input

Input 1:

 x = 2
 y = 3
 N = 1
 R = 1
 A = [2]
 B = [3]
Input 2:

 x = 3
 y = 3
 N = 1
 R = 1
 A = [0]
 B = [3]


Example Output

Output 1:

 NO
Output 2:

 YES


Example Explanation

Explanation 1:

 There is NO valid path in this case
Explanation 2:

 There is many valid paths in this case.
 One of the path is (0, 0) -> (1, 0) -> (2, 0) -> (3, 0) -> (3, 1) -> (3, 2) -> (3, 3).


*/

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    int ans[A+1][B+1];
    
    for(int i = 0; i <= A ;i++)
    {
        for(int j = 0; j <= B ;j++)
        ans[i][j]=0;
    }
    
    for(int i = 0; i <= A ; i++)
    {
        for(int j = 0; j <= B ; j++)
        {
            for(int k = 0; k < C ; k++)
            {
                if( sqrt( pow((E[k]-i),2) +  pow((F[k]-j),2) ) <= D )
                ans[i][j]=-1;
            }
            
        }
    }
    
    queue< pair<int,int> > q;
    
    
    pair<int,int> p;
    
    
    if(ans[0][0]==-1)
    return "NO";
    
    q.push({0,0});
    
    ans[0][0]=1;
    
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        
        int a=p.first;
        int b=p.second;
        
        if( a>0 && b>0 && ans[a-1][b-1]==0)
        {
            ans[a-1][b-1]=1;
            q.push({a-1,b-1});
        }
        
        if(a+1 <= A && b+1 <= B && ans[a+1][b+1]==0)
        {
            ans[a+1][b+1]=1;
            q.push({a+1,b+1});
        }
        
        if( a>0 && ans[a-1][b]==0)
        {
            ans[a-1][b]=1;
            
            q.push({a-1,b});
        }
        
        if(b>0 && ans[a][b-1]==0)
        {
            ans[a][b-1]=1;
            q.push({a,b-1});
        }
        
        if(a > 0 && b+1 <= B && ans[a-1][b+1]==0)
        {
            ans[a-1][b+1]=1;
            q.push({a-1,b+1});
        }
        
        if(b+1 <= B && ans[a][b+1]==0)
        {
            ans[a][b+1]=1;
            q.push({a,b+1});
        }
        
        if(a+1 <= A && b>0 && ans[a+1][b-1]==0)
        {
            ans[a+1][b-1]=1;
            q.push({a+1,b-1});
        }
        
        
        if(a+1 <= A && ans[a+1][b]==0)
        {
            ans[a+1][b]=1;
            q.push({a+1,b});
        }
        
    }
        
        if(ans[A][B]==1)
        return "YES";
        else
        return "NO";
}
