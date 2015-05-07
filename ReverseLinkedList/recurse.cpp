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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode * n = head->next;
        head->next = NULL;
        ListNode * new_head = reverseList( n );
        n->next = head;
        return new_head;
    }
};

// make a list of num_nodes nodes (as called for by the input integer)
void make_list( ListNode ** headptr, int num_nodes) {
    for (int i = 0; i < num_nodes; ++i) {
       append(headptr, i + 1);
    }
}

/*
void print_list( ListNode * head) {
    ListNode * p = head;
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
}
*/

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


