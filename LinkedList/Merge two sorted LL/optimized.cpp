#include "../linkedlist.h"
#include <bits/stdc++.h>
using namespace std;

/* Inplace Merging
- Time:O(m+n)
- Space:O(1)
note: m = l1.length and n = l2.length
*/
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *start = new ListNode();
        ListNode *cur_node = start;

        while (l1 != nullptr && l2 != nullptr)
        {

            if (l1->val <= l2->val)
            {
                cur_node->next = l1;
                l1 = l1->next;
            }
            else // l1->val > l2->val
            {
                cur_node->next = l2;
                l2 = l2->next;
            }

            cur_node = cur_node->next;
        }

        if (l1 != nullptr)
        {
            cur_node->next = l1;
        }

        if (l2 != nullptr)
        {
            cur_node->next = l2;
        }

        return start->next;
    }
};
int main()
{

    return 0;
}