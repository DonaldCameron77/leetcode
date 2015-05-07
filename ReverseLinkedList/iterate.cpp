/*
    LeetCode - Reverse Linked List - Total Accepted: 3967 Total Submissions: 11086

    Given a linked list, determine if it has a cycle in it.

    Follow up:
    Can you solve it without using extra space?
*/

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#include "linkedlistutils.h"

ListNode * Head = NULL;

// recursive linked list reversal.
// null head -> degenerate empty list case.
// null head->next : base case.
// In each recursion, lop off first element of list
// and recurse to reverse the remainder.

ListNode* reverseList( ListNode* head ) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode * n = head->next;
    head->next = NULL;
    ListNode * new_head = reverseList( n );
    n->next = head;
    return new_head;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        /*
        if (head == NULL || head->next == NULL) {
            return head;
        }
        */
        if (head == NULL) {
            return head;
        }

        ListNode * prev = NULL;
        ListNode * cur = head;
        ListNode * next;

        // head->next = NULL;  // new tail of list

        while ( cur ) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            // at this point prev should head the reversed portion of
            // the list, while cur heads the remaining unreversed
            // portion
        }
        return prev;
    }
};

// make a list of num_nodes nodes (as called for by the input integer)
void make_list( ListNode ** headptr, int num_nodes) {
    for (int i = 0; i < num_nodes; ++i) {
       append(headptr, i + 1);
    }
}

int main(int argc, char *argv[]) {

    ifstream ifs(argv[1]);
    string line;

    getline(ifs, line);
    istringstream iss(line);
    int num;
    iss >> num;
    cout << num << endl;

    make_list( & Head, num);
    print_list( Head );

    Solution s;

    Head = s.reverseList( Head );
    print_list( Head );
}

// EOF


