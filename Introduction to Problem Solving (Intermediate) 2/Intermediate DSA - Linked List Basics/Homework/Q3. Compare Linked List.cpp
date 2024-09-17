/*
Problem Description
Given heads of two linked lists A and B, check if they are identical i.e. each of their corresponding nodes should contain the same data. The two given linked lists may or may not be of the same length.


Problem Constraints
1 <= size of linked lists <= 105

1 <= value of each node <= 109



Input Format
You are given the head of two linked lists A and B.


Output Format
Return 1 if both the linked lists are identical and 0 otherwise


Example Input
Input 1:
A = 1 -> 2 -> 3
B = 1 -> 2 -> 3
Input 2:
A = 4 -> 3 -> 2 -> 1
B = 4 -> 2 -> 3 -> 1


Example Output
Output 1:
1
Output 2:
0


Example Explanation
For Input 1:
Both the linked lists are identical
For Input 2:
The value in the second node of both the linked lists
are different.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A, ListNode* B) {
    ListNode* temp_A = A;
    ListNode* temp_B = B;
    while (temp_A &&  temp_B) {
        if(temp_A->val != temp_B->val) return 0;
        temp_A = temp_A->next;
        temp_B = temp_B->next;
    }

    if(temp_A || temp_B) return 0;

    return 1;
}
