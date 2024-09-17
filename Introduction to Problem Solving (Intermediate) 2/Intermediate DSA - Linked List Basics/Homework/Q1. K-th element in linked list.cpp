/*
Problem Description
You are given the head of a linked list A and an integer B. You need to find the B-th element of the linked list and return its value.

Note : Follow 0-based indexing for the node numbering.



Problem Constraints
1 <= size of linked list <= 105

1 <= value of nodes <= 109

0 <= B < size of linked list



Input Format
The first argument A is the head of a linked list.

The second arguement B is an integer.



Output Format
Return an integer.



Example Input
Input 1:
A = 1 -> 2 -> 3
B = 0
Input 2:
A = 4 -> 3 -> 2 -> 1
B = 1


Example Output
Output 1:
1
Output 2:
3


Example Explanation
For Input 1:
The 0-th element of the linked list is 1.
For Input 2:
The 1-st element of the linked list is 3.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A, int B) {
    ListNode * temp = A;
    for (int i = 0; i < B && temp; i++) {
        temp = temp->next;
    }

    return temp->val;
}

