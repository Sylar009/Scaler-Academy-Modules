/*
Problem Description

Given a linked list A, swap every two adjacent nodes and return its head.



NOTE: Your algorithm should use only constant space. You may not modify the values in the list; only nodes themselves can be changed.





Problem Constraints

1 <= |A| <= 106



Input Format

The first and the only argument of input contains a pointer to the head of the given linked list.



Output Format

Return a pointer to the head of the modified linked list.



Example Input

Input 1:

 A = 1 -> 2 -> 3 -> 4
Input 2:

 A = 7 -> 2 -> 1


Example Output

Output 1:

 2 -> 1 -> 4 -> 3
Output 2:

 2 -> 7 -> 1


Example Explanation

Explanation 1:

 In the first example (1, 2) and (3, 4) are the adjacent nodes. Swapping them will result in 2 -> 1 -> 4 -> 3
Explanation 2:

 In the second example, 3rd element i.e. 1 does not have an adjacent node, so it won't be swapped. 

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode * Solution::swapPairs(ListNode * head) {
    if (!head || !head->next) return head;

    ListNode * first = head;
    ListNode * second = head->next;
    first->next = second->next;

    head = second;
    second->next = first;

    ListNode * tmp = head->next;
    while(tmp && tmp->next && tmp->next->next){
        ListNode * tmp1 = tmp->next;
        ListNode * tmp2 = tmp->next->next;
        tmp1->next = tmp2->next;
        tmp->next = tmp2;
        tmp2->next = tmp1;
        tmp = tmp->next->next;
    }

    return head;
}
