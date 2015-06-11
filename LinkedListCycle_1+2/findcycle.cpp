/*
    LeetCode - Linked List Cycle Total Accepted: 19187 Total Submissions: 54861 

    Given a linked list, determine if it has a cycle in it.

    Follow up:
    Can you solve it without using extra space?
*/

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
#include <iostream>
#include <string> // needed?

#include "linkedlistutils.h"

// shut up clang++ warnings
extern ListNode * head;
extern class Solution s;

using namespace std;

ListNode * head = NULL;

class Solution {
public:

    bool hasCycle( ListNode *head )
    {
        ListNode * slow, * fast; 
        slow = fast = head;

        while (slow != NULL && fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast  = fast->next->next;

            if ( slow == fast ) {
                return true;
            }
        }

        return false;
    }

};

class Solution s;

#ifdef NOT_READY
void make_loop( ListNode * head, int target)
{
    // assumes nodes are sequentially numbered (as given by node->val)
    // starting with 1.  Assumes there may already be a loop in the
    // list, but that it would end with the node having the maximum
    // value, i.e., if node0>val > node->next->val, the loop begins
    // with node->next and ends with node

    ListNode * p = head;

    while (p != NULL && p->next != NULL) {
        if (p->val > p->next->val) {
            p->next = NULL; // break the cycle
            break;
        }
        p = p->next;
    }

    p = head;
    while (p != NULL && p->val != target) {
       p = p->next;
    }
    q = p;
    if (q == NULL) {
        cout << "make_loop: degenerate or unimplemented case - can't make loop\n";
    }
    else {
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
}
#endif

int main()
{
    int inputs[] = { 8, 7, 6, 5, 4, 3, 2, 1 };

    for (unsigned i = 0; i < sizeof(inputs)/sizeof(unsigned); ++i) {
       cout << "inserting ... i = " << i << ", inputs[i] = " << inputs[i] << endl;
       insert (& head, inputs[i]);
    }

    print_list(head);
    
    cout << "list without cycle - should print 'no cycle': " 
         << (s.hasCycle( head ) ? "has cycle" : "no_cycle") << endl;

    int target = 5;  // create cycle pointing to node with value 5

    ListNode * p = head, * q = NULL;
    
    while (p != NULL && p->val != target) {
	p = p-> next;
    }

    if (p == NULL) {
	cout << "degenerate case - value sought is last node or not found\n";
    }
    else {
	q = p;
	while (p->next != NULL) {
	    p = p->next;
	}
	p->next = q; // bingo! cycle created
    }

    cout << "list WITH cycle - should print 'has cycle': "
         << (s.hasCycle( head ) ? "has cycle" : "no_cycle") << endl;

} // EOF

