/*
Problem Description

You are given two linked lists, A and B, representing two non-negative numbers.



The digits are stored in reverse order, and each of their nodes contains a single digit.

Add the two numbers and return it as a linked list.





Problem Constraints

1 <= |A|, |B| <= 105



Input Format

The first argument of input contains a pointer to the head of linked list A.

The second argument of input contains a pointer to the head of linked list B.



Output Format

Return a pointer to the head of the required linked list.



Example Input

Input 1:

 
 A = [2, 4, 3]
 B = [5, 6, 4]
Input 2:

 
 A = [9, 9]
 B = [1]


Example Output

Output 1:

 
 [7, 0, 8]
Output 2:

 
 [0, 0, 1]


Example Explanation

Explanation 1:

 A = 342 and B = 465. A + B = 807. 
Explanation 2:

 A = 99 and B = 1. A + B = 100. 

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int calculate (ListNode* A, ListNode* B, int carry, ListNode* temp){
    int val=0;
    if(!A) val = B->val;
    else if(!B) val= A->val;
    else val = A->val + B->val;
       
    ListNode * s = new ListNode((val+carry) % 10);
    temp->next = s;
    temp = s;
           
    carry = (val+carry) / 10;
    return carry;    
}

ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode * a = A;
    ListNode * b = B;
    ListNode * res = new ListNode(0);
    ListNode * temp = res;
    int carry = 0;
    while(a && b) {
        carry = calculate(a, b, carry, temp);
        a = a->next;
        b = b->next;
        temp = temp->next;
    }

    while(a) {
        carry = calculate(a, b, carry, temp);
        a = a->next;
        temp = temp->next;
    }
    while(b) {
        carry = calculate(a, b, carry, temp);
        b = b->next;
        temp = temp->next;
    }
    
    if( carry != 0) {
        ListNode * s = new ListNode(carry);
        temp->next = s;
    }
    
    return res->next;    
}
