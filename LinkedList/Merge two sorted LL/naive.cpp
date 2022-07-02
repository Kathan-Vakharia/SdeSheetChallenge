#include "../linkedlist.h"
/*
- Time:O(m+n)
- Space:O(m+n)
note: m = l1.length and n = l2.length
*/
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        //case when any one of the list is emtpy
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;

        //-Merge Procedure used in mergesort
        ListNode *temp = nullptr;
        ListNode *head = nullptr;

        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                if (temp == nullptr)
                {
                    temp = new ListNode(l1->val);
                    head = temp;
                    l1 = l1->next;
                }
                else
                {
                    temp->next = new ListNode(l1->val);
                    temp = temp->next;
                    l1 = l1->next;
                }
            }
            else //l1->val >= l2->val
            {
                if (temp == nullptr)
                {
                    temp = new ListNode(l2->val);
                    head = temp;
                    l2 = l2->next;
                }
                else
                {
                    temp->next = new ListNode(l2->val);
                    temp = temp->next;
                    l2 = l2->next;
                }
            }
        }

        //append remaining list
        if (l1 != nullptr)
            temp->next = l1;
        if (l2 != nullptr)
            temp->next = l2;

        return head;
    }
};
