
/*
//      Linked List Utilities
//      Donald Cameron
//      June 2014
//
//  Herewith some highly simplified linked list declarations and
//  routines.  Lists of integers only for now dcc 2014-06.
*/

// Updated June 2015 to use C++ I/O and memory allocation

#include <iostream>

#include "linkedlistutils.h"

using namespace std;

// insert new elements at front
void insert( ListNode ** head, int data) {
    ListNode * tmp = new ListNode(data);
    // ListNode * tmp = (ListNode *) malloc(sizeof(ListNode));
    // tmp->val = data;
    tmp->next = * head;
    * head = tmp;
}

// Append new elements at end of 1-way list - quick and dirty method
// To do it right, keep a pointer to last element.
void append( ListNode ** head, int data) {
    if (* head == NULL) {
	insert(head, data);
    }
    else {
	ListNode * p = *head;
	while (p->next != NULL) {
	    p = p->next;
	}
	// ListNode * tmp = (ListNode *) malloc(sizeof(ListNode));
	// tmp->val = data;
	// tmp->next = NULL;
        ListNode * tmp = new ListNode(data);
	p->next = tmp;
    }
}

void print_list( ListNode * p ) {
    for (ListNode * q = p; q != NULL; q = q->next) {
	// printf("%d ", q->val);
        cout << q->val << ' ';
    }
    cout << endl;
}

