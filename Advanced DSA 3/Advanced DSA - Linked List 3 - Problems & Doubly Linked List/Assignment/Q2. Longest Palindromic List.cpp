/*
Problem Description

Given a linked list of integers. Find and return the length of the longest palindrome list that exists in that linked list.

A palindrome list is a list that reads the same backward and forward.

Expected memory complexity : O(1)



Problem Constraints

1 <= length of the linked list <= 2000

1 <= Node value <= 100



Input Format

The only argument given is head pointer of the linked list.



Output Format

Return the length of the longest palindrome list.



Example Input

Input 1:

 2 -> 3 -> 3 -> 3
Input 2:

 2 -> 1 -> 2 -> 1 ->  2 -> 2 -> 1 -> 3 -> 2 -> 2


Example Output

Output 1:

 3
Output 2:

 5


Example Explanation

Explanation 1:

 3 -> 3 -> 3 is largest palindromic sublist
Explanation 2:

 2 -> 1 -> 2 -> 1 -> 2 is largest palindromic sublist.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int count_match(ListNode* A, ListNode* B) {
    ListNode* x = A;
    ListNode* y = B;

    int count = 0;
    while (x && y) {
        if (x->val == y->val) count++;
        else break;

        x = x->next;
        y = y->next;
    }

    return count;
}

int Solution::solve(ListNode* A) {
    ListNode* prev = nullptr;
    ListNode* curr = A;
    int res = 0;

    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        int count = count_match(prev, next);
        res = max (res, 2*count+1);
        count = count_match(curr, next);
        res = max (res, 2*count);
        prev = curr;
        curr = next;
    }

    return res;
}
