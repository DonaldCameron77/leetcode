/*
    LeetCode - Linked List Cycle II

    Given a linked list, determine if it has a cycle in it, and find
    where the cycle starts

    Theory of operation:

      Part 1:
        Floyd’s cycle detection algorithm. Use two pointers, t and h,
        and let h (the hare) move twice as fast as t (the tortoise).  If
        there is no cycle t will run into the end of the list.  If there
        is one, t will eventually become equal to h.

      Logic of Part II - understanding where we are in the loop when h and t meet.
        Now, suppose that the unlooped part of the list is of length k.
        In that case, in Part 1 when t has reached the start of the
        cycle, it has moved k positions, while h has moved 2k positions
        and has moved k positions into the loop.  t is k positions
        behind h, but conversely, h is (LS-k) positions behind t (where
        LS is Loop Size).  They continue moving at their same rate - for
        each step t takes, h takes 2 steps.  Where will t be when h
        catches up?

        Summarizing:
            1. t is 0 steps into the loop
            2. h is k steps into the loop
            3. h is k steps ahead of t, but conversely
            4. t is (LOOP-SIZE - k) steps ahead of h
            5. Since h will narrow the distance to t by 1 at each iteration, it will
            take LOOP_SIZE - k iterations for them to meet, at which time t will
            have travelled LOOP_SIZE - k positions, putting him k positions from the
            start of the loops.

      Part II: algorithm.  Leave h at the collision point and set t back to
        HEAD.  Now move them together at unit pace.  When they meet, the node
        they point to is the start of the cycle.

      Bugs:
          what if the entire loop is a cycle, i.e., head points to the first
          node of the loop?
*/

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
#include <iostream>
#include <string> // needed?

#include "linkedlistutils.h"

using namespace std;

ListNode * head = NULL;

class Solution {
private:

    // return canonical node in cycle (k positions from
    // start of loop, where k is also the distance from
    // the first node to the loop start.
    // returns NULL if no loop exists.

    ListNode * get_node_in_cycle( ListNode *head )
    {
        ListNode * slow = head, * fast = head;

        while (slow != NULL && fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return slow;
            }
        }
        
        return NULL;
    }

public:

    ListNode * detectCycle(ListNode *head)
    {
        ListNode * cycle_node = get_node_in_cycle(head);
        if (cycle_node == NULL) return NULL;
        ListNode * t = cycle_node;
        ListNode * h = head;
        while (t != h) {
            t = t->next;
            h = h->next;
        }
        return h;
    }
};

/*
    Credit: Geeks4geeks: Find any node in the cycle, call it *p;
    Starting from that node, determine the length of the cycle.
    Now walk that number of nodes from the head with ptr k
    Finally walk from head (with q) and from k at unit pace.
    Where they meet will be the start node

    Not sure about these efficient solutions.  The brute force
    solution will work.  In any solution, beware if the whole
    list is a cycle (starting at node HEAD points to).
*/
    

class Solution s;

int main()
{
    int inputs[] = { 8, 7, 6, 5, 4, 3, 2, 1 };

    for (unsigned i = 0; i < sizeof(inputs)/sizeof(unsigned); ++i) {
       cout << "inserting ... i = " << i << ", inputs[i] = " << inputs[i] << endl;
       insert (& head, inputs[i]);
    }

    print_list(head);
    
    cout << "list without cycle - should print 'no cycle': ";
    ListNode * tmp = s.detectCycle( head );
    if (tmp == NULL) {
        cout << "No cycle";
    }
    else {
        cout << "Cycle starting at node " << tmp->val;
    }
    cout << endl;

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

    cout << "list WITH cycle - should print 'Cycle starting at node '" << target << endl;
    tmp = s.detectCycle( head );
    if (tmp == NULL) {
        cout << "No cycle";
    }
    else {
        cout << "Cycle starting at node " << tmp->val;
    }
    cout << endl;

} // EOF

