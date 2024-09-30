/*
Problem Description

The N-queens puzzle is the problem of placing N queens on an N×N chessboard such that no two queens attack each other.







Given an integer A denoting the value of N, return all distinct solutions to the N-queens puzzle.

Each solution contains a distinct board configuration of the N-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
The final list should be generated in such a way that the indices of the queens in each list should be in reverse lexicographical order.







Problem Constraints

1 <= A <= 10



Input Format

First argument is an integer A denoting the size of chessboard



Output Format

Return an array consisting of all distinct solutions in which each element is a 2d char array representing a unique solution.



Example Input

Input 1:

A = 4
Input 2:

A = 1


Example Output

Output 1:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Output 1:

[
 [Q]
]


Example Explanation

Explanation 1:

There exist only two distinct solutions to the 4-queens puzzle:
Explanation 1:

There exist only one distinct solutions to the 1-queens puzzle:
*/

// aman solution is better
bool is_safe(int row, int col, vector<string> &board) {
    for (int i = 0; i < board.size(); i++) if (board[i][col] == 'Q') return false;
    for (int i = row, j = col; j >= 0 && i >= 0; i--, j--) if (board[i][j] == 'Q') return false;
    for (int i = row, j = col; j < board.size() && i >= 0; i--, j++) if (board[i][j] == 'Q') return false;
    return true;
}

void queen_helper(int row, vector<string> &board, vector<vector<string> > &res) {
    if (row == board.size() ) {
        res.push_back(board);
        return;
    }

    for (int i = 0; i < board.size(); i++) {
        if (is_safe(row, i, board)){
            vector<string> t = board;
            t[row] = t[row].substr(0,i) + "Q" + t[row].substr(i+1);
            queen_helper(row+1, t, res);
        }
    }
}
vector<vector<string> > Solution::solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<string> board;
    
    for (int i = 0; i < A; i++) {
        string t;
        for (int j = 0; j < A; j++) t += ".";
        board.push_back(t);
    }

    vector<vector<string> > res;
    
    queen_helper(0, board, res);
    return res;
}
