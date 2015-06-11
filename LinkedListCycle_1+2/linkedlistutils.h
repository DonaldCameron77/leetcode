
// Linked list utils for leetcode Cycle Detection.
// Based on my routines for HackerRank Mth-to-last-element.
// June 2014

// updated June 2015 to move class Solution to the driver file

/**
 * Definition for singly-linked list.
**/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

extern void insert( ListNode ** head, int data );

// quick and dirty - always walks entire list
extern void append( ListNode ** head, int data );

void print_list( ListNode * p );

