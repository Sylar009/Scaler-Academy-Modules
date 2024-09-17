/*
Problem Description
You are given the head of a linked list A and an integer B, check if there is any node which contains this value B.

Return 1 if such a node is present else return 0.



Problem Constraints
1 <= size of linked list <= 105
1 <= value of nodes <= 109
1 <= B <= 109



Input Format
The first argument A is the head of a linked list.

The second arguement B is an integer.



Output Format
Return 1 if such a node is present otherwise return 0.


Example Input
Input 1:
A = 1 -> 2 -> 3
B = 4
Input 2:
A = 4 -> 3 -> 2 -> 1
B = 4


Example Output
Output 1:
0
Output 2:
1


Example Explanation
For Input 1:
None of the nodes have a value 4.
For Input 2:
The first node has a value 4.

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
    ListNode *temp = A;
    while (temp) {
        if (temp->val == B) return 1;
        temp = temp->next;
    }
    return 0;
}

