
/*
//      Linked List Utilities
//      Donald Cameron
//      June 2014
//
//  Herewith some highly simplified linked list declarations and
//  routines.  Lists of integers only for now dcc 2014-06.
*/

// #include <stdlib.h>
// #include <stdio.h>

#include <iostream>

#include "linkedlistutils.h"

using namespace std;


// insert new elements at front
void insert( ListNode ** headptr, int data) {
    // ListNode * tmp = (ListNode *) malloc(sizeof(ListNode));
    ListNode * tmp = new ListNode(data);
    tmp->next = * headptr;
    * headptr = tmp;
}

// Append new elements at end of 1-way list - quick and dirty method
// To do it right, keep a pointer to last element.
void append( ListNode ** headptr, int data) {
    if (* headptr == NULL) {
	insert(headptr, data);
    }
    else {
	ListNode * p = *headptr;
	while (p->next != NULL) {
	    p = p->next;
	}
	// ListNode * tmp = (ListNode *) malloc(sizeof(ListNode));
	ListNode * tmp = new ListNode(data);
	tmp->val = data;
	tmp->next = NULL;
	p->next = tmp;
    }
}

// quick and dirty - leaks memory
void delete_list( ListNode ** headptr ) {
    // muah ha ha so evil!! <grin>
    * headptr = NULL;
}

void print_list( ListNode * p, bool extra_newline ) {
    for (ListNode * q = p; q != NULL; q = q->next) {
	// printf("%d ", q->val);
        cout << q->val << " ";
    }
    // printf("\n");
    cout << "\n";
    if (extra_newline) {
        // printf("\n");
        cout << "\n";
    }
}

