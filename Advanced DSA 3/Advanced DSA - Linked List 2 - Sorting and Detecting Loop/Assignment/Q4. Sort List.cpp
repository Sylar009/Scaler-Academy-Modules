/*
Problem Description

Sort a linked list, A in O(n log n) time.



Problem Constraints

0 <= |A| = 105



Input Format

The first and the only arugment of input contains a pointer to the head of the linked list, A.



Output Format

Return a pointer to the head of the sorted linked list.



Example Input

Input 1:

A = [3, 4, 2, 8]
Input 2:

A = [1]


Example Output

Output 1:

[2, 3, 4, 8]
Output 2:

[1]


Example Explanation

Explanation 1:

 The sorted form of [3, 4, 2, 8] is [2, 3, 4, 8].
Explanation 2:

 The sorted form of [1] is [1].

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

ListNode* merge(ListNode* A, ListNode* B) {
    if (!A) return B;
    if (!B) return A;

    ListNode* head , *tail;

    if (A->val < B->val) {
        head = A;
        tail = A;
        A = A->next;
    }
    else {
        head = B;
        tail = B;
        B = B->next;
    }

    while (A && B) {
        if (A->val < B->val) {
            tail->next = A;
            A = A->next;
            tail = tail->next;
        }
        else {
            tail->next = B;
            B = B->next;
            tail = tail->next;
        }
    }

    if (A) tail->next = A;
    if (B) tail->next = B;

    return head;
}

ListNode* merge_sort(ListNode* A) {
    
    if (!A || !A->next) return A;

    ListNode* mid = get_middle(A);
    ListNode* B = mid->next;
    mid->next = nullptr;

    ListNode* tempA = merge_sort(A);
    ListNode* tempB = merge_sort(B);

    ListNode* res = merge(tempA, tempB);

    return res;
}

ListNode* Solution::sortList(ListNode* A) {
    if (!A || !A->next) return A;
    return merge_sort(A);
}
