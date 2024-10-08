/*
Problem Description

We want to make a custom contacts finder applications as part of our college project. The application must perform two types of operations:

Type 1: Add name B[i] ,denoted by 0 in vector A where B[i] is a string in vector B denoting a contact name. This must store B[i] as a new contact in the application.

Type 2: Find partial for B[i] ,denoted by 1 in vector A where B[i] is a string in vector B denoting a partial name to search the application for. It must count the number of contacts starting with B[i].

You have been given sequential add and find operations. You need to perform each operation in order.

And return as an array of integers, answers for each query of type 2(denoted by 1 in A) .



Problem Constraints

1 <= |A| <= 10000

1 <= |length of strings in B| <= 10



Input Format

First argument is the vector A, which denotes the type of query.

Second argument is the vector B, which denotes the string for corresponding query.



Output Format

Return an array of integers, denoting answers for each query of type 1.



Example Input

Input 1:

A = [0, 0, 1, 1]
B = ["hack", "hacker", "hac", "hak"]
Input 2:

A = [0, 1]
B = ["abcde", "abc"]


Example Output

Output 1:

 
[2, 0]
Output 2:

[1]


Example Explanation

Explanation 1:

 
We perform the following sequence of operations:
Add a contact named "hack".
Add a contact named "hacker".
Find the number of contact names beginning with "hac". There are currently two contact names in the application and both of them start with "hac", so we have 2.
Find the number of contact names beginning with "hak". There are currently two contact names in the application but neither of them start with "hak", so we get0.
Explanation 2:

 
Add "abcde"
Find words with prefix "abc". We have answer as 1.

*/

typedef struct TNode {
    bool is_end;
    int freq;
    unordered_map<char, TNode*> hm;

    TNode(): is_end(false), freq(0) {}
} TNode;


void add_word(string str, TNode* node) {
    for(int i = 0; i < str.size(); i++) {
        char ch = str[i];

        if(node->hm.find(ch) == node->hm.end())
            node->hm[ch] = new TNode();
       
        node->hm[ch]->freq++;
        node = node->hm[ch];
    }
    node->is_end = true;
}


int contacts_with_pf(string pf, TNode* node) {
    for(int i = 0; i < pf.size(); i++ ) {
        char ch = pf[i];

        if(node->hm.find(ch) == node->hm.end())
            return 0;
       
        node = node->hm[ch];
    }
   
    return node->freq;
}


vector<int> Solution::solve(vector<int> &A, vector<string> &B) {
    vector<int> res;
    TNode *node = new TNode();

    for(int i = 0; i < A.size(); i++) {
        if(A[i] == 0)
            add_word(B[i], node);
        else
            res.push_back(contacts_with_pf(B[i], node));
    }

    return res;
}

