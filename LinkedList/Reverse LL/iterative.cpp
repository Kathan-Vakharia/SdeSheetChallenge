#include <bits/stdc++.h>
#include "../linkedlist.h"

/*
- Time:O(n)
- Space:O(1)
*/

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {

        ListNode *prev = nullptr;
        ListNode *cur = head;
        ListNode *next = nullptr;

        //while cur is pointing to a node
        while (cur)
        {
            //get access to the node ahead
            next = cur->next;

            //break the forward link
            cur->next = prev;

            //moving prev ahead
            prev = cur;

            //updating current node
            cur = next;
        }
        //After the loop, prev will be pointed to the required node
        head = prev;
        return head;
    }
};