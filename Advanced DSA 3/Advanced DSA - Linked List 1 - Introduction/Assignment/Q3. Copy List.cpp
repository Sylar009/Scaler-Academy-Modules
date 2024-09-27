/*
Problem Description

You are given a linked list A
Each node in the linked list contains two pointers: a next pointer and a random pointer
The next pointer points to the next node in the list
The random pointer can point to any node in the list, or it can be NULL
Your task is to create a deep copy of the linked list A
The copied list should be a completely separate linked list from the original list, but with the same node values and random pointer connections as the original list
You should create a new linked list B, where each node in B has the same value as the corresponding node in A
The next and random pointers of each node in B should point to the corresponding nodes in B (rather than A)


Problem Constraints

0 <= |A| <= 106



Input Format

The first argument of input contains a pointer to the head of linked list A.



Output Format

Return a pointer to the head of the required linked list.



Example Input

Given list
   1 -> 2 -> 3
with random pointers going from
  1 -> 3
  2 -> 1
  3 -> 1
  


Example Output

   1 -> 2 -> 3
with random pointers going from
  1 -> 3
  2 -> 1
  3 -> 1
  


Example Explanation

You should return a deep copy of the list. The returned answer should not contain the same node as the original list, but a copy of them. The pointers in the returned list should not link to any node in the original input list.


*/

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    RandomListNode* next, *curr = A;
    //Create Copy of each node

    while(curr) {
        next = curr->next;
        curr->next = new RandomListNode(curr->label);
        curr->next->next = next;
        curr = next;
    }
    curr = A;

    //Add random pointer same as original

    while(curr) {
        if(curr->random) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }
    curr = A;
    RandomListNode *dup_Head = new RandomListNode(0);
    RandomListNode *dup_Curr = dup_Head;

    //detach original and deep copy

    while(curr) {
        next = curr->next->next;
        dup_Curr->next = curr->next;
        curr->next = next;
        dup_Curr = dup_Curr->next;
        curr = next;
    }
    return dup_Head->next;
}
