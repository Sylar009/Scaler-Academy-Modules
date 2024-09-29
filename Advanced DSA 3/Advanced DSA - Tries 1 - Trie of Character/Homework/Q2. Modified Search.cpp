/*
Problem Description

Given two arrays of strings A of size N and B of size M.

Return a binary string C where C[i] = '1' if B[i] can be found in dictionary A using exactly one modification in B[i], Else C[i] = '0'.

NOTE: modification is defined as converting a character into another character.



Problem Constraints

1 <= N <= 30000

1 <= M <= 2500

1 <= length of any string either in A or B <= 20

strings contains only lowercase alphabets



Input Format

First argument is the string arrray A.

Second argument is the string array B.



Output Format

Return a binary string C where C[i] = '1' if B[i] can be found in dictionary A using one modification in B[i], Else C[i] = '0'.



Example Input

Input 1:

 A = [data, circle, cricket]
 B = [date, circel, crikket, data, circl]
Input 2:

 A = [hello, world]
 B = [hella, pello, pella]


Example Output

Output 1:

 "10100"
Output 2:

 "110"


Example Explanation

Explanation 1:

 1. date = dat*(can be found in A)
 2. circel =(cannot be found in A using exactly one modification)
 3. crikket = cri*ket(can be found in A)
 4. data = (cannot be found in A using exactly one modification)
 5. circl = (cannot be found in A using exactly one modification)
Explanation 2:

 Only pella cannot be found in A using only one modification.
*/

class TNode {
    public:
    bool is_end;
    map<char, TNode*> mp;
    TNode() {
        is_end = false;
    }
};

void add_string( TNode* node, string str) {
    int n = str.size();
    for ( int x = 0 ; x < n ; x++) {
        char ch = str[x];
        if ( node->mp.find(ch) != node->mp.end()) {
            node = node->mp[ch];
        } else {
            TNode* nn = new TNode();
            node->mp[ch] = nn;
            node = nn;
        }
    }
    node->is_end = true;
}

bool find_string(TNode* node, int index, string str, bool flag) {
    bool res = false;
    if ( index == str.size()) {
        if ( flag && node->is_end) {
            return true;
        }
        return false;
    }

    char c = str[index];
    if ( flag == 0) {
        for (auto val = node->mp.begin(); val != node->mp.end(); val++) {
            if (val->first == c) {
                res = res | find_string(val->second, index + 1, str, flag);
            } else {
                res = res | find_string(val->second, index + 1, str, 1 - flag);
            }
        }
    } else {
        if (node->mp.find(c) != node-> mp.end()) {
            res = res | find_string(node->mp[c], index + 1, str, flag);
        }
    }
    
    return res;
}

string Solution::solve(vector<string> &A, vector<string> &B) {
    string res = "";
    TNode* node = new TNode();
    for( int x = 0; x < A.size(); x++) {
        add_string(node, A[x]);
    }
    for( int y = 0; y < B.size(); y++) {
        if(find_string(node,0, B[y], 0))  {
            res += "1";
        } else {
            res += "0";
        }
    }

    return res;
}
