#include "../linkedlist.h"
#include <bits/stdc++.h>
/*
- Time:O(n)
- Space:O(n)
*/
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        /*
        *Approach
            -Let's say list is n0 -> n1 ->... "nk" -> nk+1 -> ...n->null
            -when we are on nk, we assume nk+1 <-...n i.e. the list ahead is reversed 
        */

       //* When 1. list contains 0 or 1 node, 
       //* 2. head is pointing last node
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *last = reverseList(head->next);

        //note: To make sure this works, we need to make sure:
        //> head->next and head exits (base condition)
        head->next->next = head; //! crux

        head->next = nullptr;
        
        return last;
    }
};