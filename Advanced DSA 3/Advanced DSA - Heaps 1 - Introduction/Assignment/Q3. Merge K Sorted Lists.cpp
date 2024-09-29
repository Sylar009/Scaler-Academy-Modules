/*
Problem Description

Given a list containing head pointers of N sorted linked lists.
Merge these given sorted linked lists and return them as one sorted list.



Problem Constraints

1 <= total number of elements in given linked lists <= 100000



Input Format

The first and only argument is a list containing N head pointers.



Output Format

Return a pointer to the head of the sorted linked list after merging all the given linked lists.



Example Input

Input 1:

 1 -> 10 -> 20
 4 -> 11 -> 13
 3 -> 8 -> 9
Input 2:

 10 -> 12
 13
 5 -> 6


Example Output

Output 1:

 1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20
Output 2:

 5 -> 6 -> 10 -> 12 ->13


Example Explanation

Explanation 1:

 The resulting sorted Linked List formed after merging is 1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20.
Explanation 2:

 The resulting sorted Linked List formed after merging is 5 -> 6 -> 10 -> 12 ->13.


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    priority_queue<int, vector<int>, greater<int>> pq;
    if (A.size() == 0) return nullptr;
    ListNode* rn = nullptr;
    ListNode* t = nullptr;
    for (int i = 0; i < A.size(); i++) {
        ListNode* temp = A[i];
        while (temp) {
            pq.emplace(temp->val);
            temp = temp->next;
        }
    }

    if (!pq.empty()) {
        rn = new ListNode(pq.top());
        t = rn;
        pq.pop();
    }

    while (!pq.empty()) {
        t->next = new ListNode(pq.top());
        pq.pop();
        t = t->next;
    }

    return rn;
}
