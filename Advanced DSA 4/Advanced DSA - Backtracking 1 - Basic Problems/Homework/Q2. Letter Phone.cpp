/*
Problem Description

Given a digit string A, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



The digit 0 maps to 0 itself. The digit 1 maps to 1 itself.

NOTE: Make sure the returned strings are lexicographically sorted.



Problem Constraints

1 <= |A| <= 10



Input Format

The only argument is a digit string A.



Output Format

Return a string array denoting the possible letter combinations.



Example Input

Input 1:

 A = "23"
Input 2:

 A = "012"


Example Output

Output 1:

 ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
Output 2:

 ["01a", "01b", "01c"]


Example Explanation

Explanation 1:

 There are 9 possible letter combinations.
Explanation 2:

 Only 3 possible letter combinations.

*/

/********************************************************************************
********************************************************************************

vector < string > charmap(10);
void generateHelper(string & current, int index, string & digits, vector < string > & ans) {
    if (index == digits.length()) {
        ans.push_back(current);
        return;
    }
    int digit = digits[index] - '0';
    // loop through all possible letters for that index
    for (int i = 0; i < charmap[digit].length(); i++) {
        current.push_back(charmap[digit][i]);
        // recursively call for the next index
        generateHelper(current, index + 1, digits, ans);
        current.pop_back();
    }
    return;
}
vector < string > Solution::letterCombinations(string A) {
    // create mapping of digit to letters
    charmap[0] = "0";
    charmap[1] = "1";
    charmap[2] = "abc";
    charmap[3] = "def";
    charmap[4] = "ghi";
    charmap[5] = "jkl";
    charmap[6] = "mno";
    charmap[7] = "pqrs";
    charmap[8] = "tuv";
    charmap[9] = "wxyz";
    vector < string > ans;
    string current = "";
    generateHelper(current, 0, A, ans);
    return ans;
}

********************************************************************************
********************************************************************************/
void letter_combination(int idx, 
string &str, 
string &curr, 
vector<string> &pl, 
vector<string> &ans) {

    if (idx == str.size() ) {
        ans.push_back(curr);
        return;
    }

    for (int i = 0; i < pl[str[idx]-'0'].size(); i++) {
        curr[idx] = pl[str[idx]-'0'][i];
        letter_combination(idx+1, str, curr, pl, ans);
    }
}

vector<string> Solution::letterCombinations(string A) {
    vector<string> pl(10);
    pl[0] = "0"; 
    pl[1] = "1";
    pl[2] = "abc";
    pl[3] = "def";
    pl[4] = "ghi";
    pl[5] = "jkl";
    pl[6] = "mno";
    pl[7] = "pqrs";
    pl[8] = "tuv";
    pl[9] = "wxyz";

    string curr = A;
    vector<string> ans;
    letter_combination(0,A, curr, pl, ans);
    return ans;

}
