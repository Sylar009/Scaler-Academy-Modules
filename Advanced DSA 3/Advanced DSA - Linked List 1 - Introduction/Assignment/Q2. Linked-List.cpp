/*
Problem Description

Design and implement a Linked List data structure.
A node in a linked list should have the following attributes - an integer value and a pointer to the next node.

It should support the following operations:

insert_node(position, value) - To insert the input value at the given position in the linked list.
delete_node(position) - Delete the value at the given position from the linked list.
print_ll() - Print the entire linked list, such that each element is followed by a single space (no trailing spaces).
Note:

If an input position does not satisfy the constraint, no action is required.
Each print query has to be executed in a new line.


Problem Constraints

1 <= value <= 105
1 <= position <= n where, n is the size of the linked-list.



Input Format

First line contains an integer denoting number of cases, let's say t. Next t line denotes the cases.


Output Format

When there is a case of print_ll(), Print the entire linked list, such that each element is followed by a single space.

There should not be any trailing space.

NOTE: You don't need to return anything.


Example Input

Input 1:
5
i 1 23
i 2 24
p
d 1
p
Input 2:
3
i 1 54
d 10
p


Example Output

Output 1:
23 24
24
Output 2:
54


Example Explanation

Explanation 1:
After first two cases linked list contains two elements 23 and 24.
At third case print: 23 24.
At fourth case delete value at first position, only one element left 24.
At fifth case print: 24.
Explanation 2:
After the first case,  linked list contains: 54

At second case delete value at 10th position,  
Since the position is higher than the length of the linkedlist. 
It does not satisfy the constraint, So no action is required.

At third case print: 54.

*/

#include<iostream>
using namespace std;

static int length = 0;
class node
{
    public:
          int data ;
          node * next;
               
            node (int val)
            {
                data = val;
                next = NULL;
            }
};
node * head = NULL;
void insert_node(int position, int value) {
    node * temp = new node(value);
    if(position == 1)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        int counter = 1;
        node * curr = head;
        while(counter < position -1)
        {
            curr = curr->next;
            counter++;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
    length++;
    // @params position, integer
    // @params value, integer
}

void delete_node(int position)
{
    if(position >length)
    {
        return;
    }
    if(position == 1)
    {
        head = head->next;
    }
    else
    {
        int counter =1;
        node * curr = head;
        while(counter<position-1)
        {
            counter++;
            curr = curr->next;
        }
        curr->next = curr->next->next;
    }
    length--;
    // @params position, integer
}


void print_ll() {
    // Output each element followed by a space
    if(length == 0)
    {
        return;
    }
    node *temp = head;
    while(temp->next != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data;
    return ;
}
