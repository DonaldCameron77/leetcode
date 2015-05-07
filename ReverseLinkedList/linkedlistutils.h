
// Linked list utils for leetcode Cycle Detection.
// Based on my routines for HackerRank Mth-to-last-element.
// June 2014

/**
 * Definition for singly-linked list.
**/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// extern ListNode * head;

extern void insert( ListNode ** headptr, int data );

// quick and dirty - always walks entire list
extern void append( ListNode ** headptr, int data );

// quick and dirty, leaks memory
extern void delete_list( ListNode ** headptr );

void print_list( ListNode * p, bool extra_newline = false );

