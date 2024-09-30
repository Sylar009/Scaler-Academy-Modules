/*
Problem Description

Write a program to solve a Sudoku puzzle by filling the empty cells. Empty cells are indicated by the character '.' You may assume that there will be only one unique solution.



A sudoku puzzle,



and its solution numbers marked in red.



Problem Constraints

N = 9


Input Format

First argument is an array of array of characters representing the Sudoku puzzle.


Output Format

Modify the given input to the required answer.


Example Input

Input 1:

A = [[53..7....], [6..195...], [.98....6.], [8...6...3], [4..8.3..1], [7...2...6], [.6....28.], [...419..5], [....8..79]]


Example Output

Output 1:

[[534678912], [672195348], [198342567], [859761423], [426853791], [713924856], [961537284], [287419635], [345286179]]


Example Explanation

Explanation 1:

Look at the diagrams given in the question.

*/

bool suduko_helper(int idx, vector<vector<char> > &A,
    vector<vector<bool> > &rows,
    vector<vector<bool> > &cols,
    vector<vector<bool> > &blocks) {
        if (idx >= 81) return true;
        if (A[idx/9][idx%9] != '.') {
            if (suduko_helper(idx+1, A, rows, cols, blocks)) return true;
            return false;
        }

        int row = idx/9;
        int col = idx%9;
        for (int i = 1; i <= 9; i++) {
            if (rows[row][i] && cols[col][i] && blocks[(row/3)*3 + (col/3)][i]) {
                A[row][col] = i + '0';
                rows[row][i] = false;
                cols[col][i] = false;
                blocks[(row/3)*3 + (col/3)][i] = false;

                if (suduko_helper(idx+1, A, rows, cols, blocks)) return true;
                rows[row][i] = true;
                cols[col][i] = true;
                blocks[(row/3)*3 + (col/3)][i] = true;
                A[row][col] = '.';
            }
        }

    return false;
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<bool> > rows(9, vector<bool>(10,true));
    vector<vector<bool> > cols(9, vector<bool>(10,true));
    vector<vector<bool> > blocks(9, vector<bool>(10,true));

    for (int i =0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (A[i][j] != '.') {
                rows[i][(A[i][j]-'0')] = false;
                cols[j][(A[i][j]-'0')] = false;
                blocks[((i/3)*3+(j/3))][(A[i][j]-'0')] = false;
            }
        }
    }

    suduko_helper(0, A, rows, cols, blocks);
}
