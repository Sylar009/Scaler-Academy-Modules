/*
Problem Description

Given any source point, (C, D) and destination point, (E, F) on a chess board of size A x B, we need to find whether Knight can move to the destination or not.


The above figure details the movements for a knight ( 8 possibilities ).

If yes, then what would be the minimum number of steps for the knight to move to the said point. If knight can not move from the source point to the destination point, then return -1.

NOTE: A knight cannot go out of the board.



Problem Constraints

1 <= A, B <= 500



Input Format

The first argument of input contains an integer A.
The second argument of input contains an integer B.
The third argument of input contains an integer C.
The fourth argument of input contains an integer D.
The fifth argument of input contains an integer E.
The sixth argument of input contains an integer F.



Output Format

If it is possible to reach the destination point, return the minimum number of moves.
Else return -1.



Example Input

Input 1:

 A = 8
 B = 8
 C = 1
 D = 1
 E = 8
 F = 8
Input 2:

 A = 2
 B = 4
 C = 2
 D = 1
 E = 4
 F = 4


Example Output

Output 1:

 6
Output 2:

 -1


Example Explanation

Explanation 1:

 The size of the chessboard is 8x8, the knight is initially at (1, 1) and the knight wants to reach position (8, 8).
 The minimum number of moves required for this is 6.
Explanation 2:

 It is not possible to move knight to position (4, 4) from (2, 1)

*/

struct cell{
    int x,y,dis;
    cell() {} //declaring constructor function
    cell(int x, int y, int dis): x(x), y(y), dis(dis) {} // initializing constructor
};

bool isInside(int x, int y, int N, int M){
    if((x>=1 && x<=N) && (y>=1 && y<=M)) return true;
    return false;
}

int Solution::knight(int N, int M, int x1, int y1, int x2, int y2) {
    // Do not write main() function.
    //Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int dx[]={-2,-1,1,2,-2,-1,1,2};
    int dy[]={-1,-2,-2,-1,1,2,2,1};
    queue<cell> q;
    q.push(cell(x1, y1,0));
    int x, y;
    bool visit[N+1][M+1];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            visit[i][j]=false;
        }
    }
    visit[1][1]= true;
    
    
    while(!q.empty()){
        cell t= q.front();
        q.pop();
        if(t.x==x2 && t.y==y2) return t.dis;
        for(int i=0;i<8;i++){
            x= t.x+ dx[i];
            y= t.y+ dy[i];
            if(isInside(x,y,N,M) && !visit[x][y]){
                q.push(cell(x,y,t.dis+1));
                visit[x][y]=true;
            }
        }
    }
    return -1;
}
