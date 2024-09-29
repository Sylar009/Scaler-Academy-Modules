/*
Problem Description

Given an array of words A (dictionary) and another array B (which contain some words).












You have to return the binary array (of length |B|) as the answer where 1 denotes that the word is present in the dictionary and 0 denotes it is not present.

Formally, for each word in B, you need to return 1 if it is present in Dictionary and 0 if not.

Such problems can be seen in real life when we work on any online editor (like Google Documnet), if the word is not valid it is underlined by a red line.

NOTE: Try to do this in O(n) time complexity.




Problem Constraints

1 <= |A| <= 1000

1 <= sum of all strings in A <= 50000

1 <= |B| <= 1000



Input Format

First argument is array of strings A.

First argument is array of strings B.



Output Format

Return the binary array of integers according to the given format.



Example Input

Input 1:

A = [ "hat", "cat", "rat" ]
B = [ "cat", "ball" ]
Input 2:

A = [ "tape", "bcci" ]
B = [ "table", "cci" ]


Example Output

Output 1:

[1, 0]
Output 2:

[0, 0]


Example Explanation

Explanation 1:

Only "cat" is present in the dictionary.
Explanation 2:

None of the words are present in the dictionary.
*/

class Node{
    public:
        char val;
        Node* childrens[26];
        bool is_word;
        Node(char value, bool flag=false){
            this->val = value;
            this->is_word = flag;
            for(int i=0;i<26;i++) childrens[i] = nullptr;
    }
};

vector<int> Solution::solve(vector<string> &A, vector<string> &B) {
    vector<int> res;

    Node* root = new Node('#');
    Node* curr = root;

    for(int i=0;i<A.size();i++){
        curr = root;
        for(int j=0;j<A[i].length();j++){
            if(curr->childrens[A[i][j] - 'a']==NULL) {
                Node* newNode = new Node(A[i][j]);
                curr->childrens[A[i][j] - 'a'] = newNode;
            }
            curr = curr->childrens[A[i][j] - 'a'];
        }
        curr->is_word = true;
    }

    for(int i=0;i<B.size();i++){
        curr = root;
        for(int j=0;j<B[i].length();j++){
            if(curr->childrens[B[i][j]-'a']!=NULL);
            else{
                break;
            }
            curr = curr->childrens[B[i][j]-'a'];
        }
        if(curr->is_word) res.push_back(1);
        else res.push_back(0);
    }
    return res;
}
