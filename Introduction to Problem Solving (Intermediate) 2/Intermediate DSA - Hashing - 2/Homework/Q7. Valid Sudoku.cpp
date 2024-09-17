/*
Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.



The input corresponding to the above configuration :



["53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"]
A partially filled sudoku which is valid.

Note:

A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/

int Solution::isValidSudoku(const vector<string> &A) {
    int ans = 0;
    vector<string> col_str(9,"");
    vector<string> block_str(9,"");
    int j = 0;
    for (string str : A) {
        unordered_set<char> hs;
        int i = 0;
        for (char n : str) {
            if (n == '.') { i++; continue; }
            else if (hs.find(n) != hs.end() ) return 0;
            else {
                if (n < 48 || n > 57) return 0;
                hs.insert(n);
                col_str[i] += n;
                if (i <= 2  && j <= 2) block_str[0] += n;
                else if(i <= 5 && j <= 2) block_str[1] += n;
                else if(i <= 8 && j <= 2) block_str[2] += n;
                else if(i <= 2 && j <= 5) block_str[3] += n;
                else if(i <= 5 && j <= 5) block_str[4] += n;
                else if(i <= 8 && j <= 5) block_str[5] += n;
                else if(i <= 2 && j <= 8) block_str[6] += n;
                else if(i <= 5 && j <= 8) block_str[7] += n;
                else if(i <= 8 && j <= 8) block_str[8] += n;
            }
            i++;
        }
        j++;
    }

    for (string str : col_str) {
        unordered_set<char> hs;
         for (char n : str) {
            if (hs.find(n) != hs.end() ) return 0;
            else hs.insert(n);
         }
    }

    for (string str : block_str) {
        unordered_set<char> hs;
         for (char n : str) {
            if (hs.find(n) != hs.end() ) return 0;
            else hs.insert(n);
         }
    }

    return 1;
}
