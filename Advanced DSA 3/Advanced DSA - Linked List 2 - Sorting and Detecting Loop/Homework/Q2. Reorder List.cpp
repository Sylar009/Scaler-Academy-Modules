/*
Problem Description

Given a singly linked list A

 A: A0 → A1 → … → An-1 → An 
reorder it to:

 A0 → An → A1 → An-1 → A2 → An-2 → … 
You must do this in-place without altering the nodes' values.



Problem Constraints

1 <= |A| <= 106



Input Format

The first and the only argument of input contains a pointer to the head of the linked list A.



Output Format

Return a pointer to the head of the modified linked list.



Example Input

Input 1:

 A = [1, 2, 3, 4, 5] 
Input 2:

 A = [1, 2, 3, 4] 


Example Output

Output 1:

 [1, 5, 2, 4, 3] 
Output 2:

 [1, 4, 2, 3] 


Example Explanation

Explanation 1:

 The array will be arranged to [A0, An, A1, An-1, A2].
Explanation 2:

 The array will be arranged to [A0, An, A1, An-1, A2].
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* get_middle(ListNode* A) {
    ListNode* slow = A;
    ListNode* fast = A;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode* reverseList(ListNode* A) {
    ListNode* curr, *prev, *next;
    curr = A;
    next = curr->next;
    prev = nullptr;

    while (next) {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = curr->next;
    }
    curr->next = prev;

    A = curr;
    return A;
}

ListNode* Solution::reorderList(ListNode* A) {
    if(!A || !A->next) return A;

    ListNode* mid = get_middle(A);
    
    ListNode* B = mid->next;
    mid->next = nullptr;

    B = reverseList(B);
    

    ListNode* head = A;

    ListNode* tmpA, *tmpB;
    while(A && B) {
        tmpA = A->next;
        tmpB = B->next;
        B->next = A->next;
        A->next = B;
        A = tmpA;
        B = tmpB;
    }

    return head;
}
