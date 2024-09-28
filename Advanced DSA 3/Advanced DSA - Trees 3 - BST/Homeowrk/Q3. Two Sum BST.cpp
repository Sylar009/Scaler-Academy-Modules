/*
Problem Description

Given a binary search tree A, where each node contains a positive integer, and an integer B, you have to find whether or not there exist two different nodes X and Y such that X.value + Y.value = B.

Return 1 to denote that two such nodes exist. Return 0, otherwise.



Problem Constraints

1 <= size of tree <= 100000

1 <= B <= 109



Input Format

First argument is the head of the tree A.

Second argument is the integer B.



Output Format

Return 1 if such a pair can be found, 0 otherwise.



Example Input

Input 1:

         10
         / \
        9   20

B = 19
Input 2:

 
          10
         / \
        9   20

B = 40


Example Output

Output 1:

 1
Output 2:

 0


Example Explanation

Explanation 1:

 10 + 9 = 19. Hence 1 is returned.
Explanation 2:

 No such pair exists.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::t2Sum(TreeNode* A, int B) {

    int val_1 = 0;    
    int val_2 = 0;    
    int done_1 = 0;    
    int done_2 = 0;
    TreeNode* curr_1 = A;    
    TreeNode* curr_2 = A;
    stack<TreeNode*> st_1;
    stack<TreeNode*> st_2;    
    while( true ) {
        while(done_1 == 0) {
            if(curr_1 != nullptr) {
                st_1.push( curr_1 );
                curr_1 = curr_1->left;
            }
            else {
                if(st_1.empty()) {
                    done_1 = 1;
                }
                else {
                    curr_1 = st_1.top();
                    val_1 = curr_1->val;
                    st_1.pop();
                    curr_1 = curr_1->right;
                    done_1 = 1;
                }
            }
        }        
        while(done_2 == 0) {
            if(curr_2 != NULL) {
                st_2.push(curr_2);
                curr_2 = curr_2->right;
            }
            else {
                if(st_2.empty()) {
                    done_2 = 1;
                }
                else {
                    curr_2 = st_2.top();
                    st_2.pop();
                    val_2 = curr_2->val;
                    curr_2 = curr_2->left;
                    done_2 = 1;
                }
            }
        }
        
        if( ( (val_1 + val_2) == B) && (val_1 != val_2) ) {
            return 1;
        }

        else if( (val_1 + val_2) < B) {            
            done_1 = 0;
        }

        else if((val_1 + val_2) > B) {
            done_2 = 0;
        }
        
        if(val_1 >= val_2) {
            return 0;
        }

    }
    
    return 0;
    
}
