#include <bits/stdc++.h>
#include "../linkedlist.h"
using namespace std;
/* Idea
 *We reverse each of the 'k' groups by following condtions:
 - When we are starting to reverse a group,
 -  we make "cur" point to the first node of the group

 - After a group is reversed(inner loop terminates),
 - "cur" points to the last node(first node) of the "reversed group"(orginal group resp.)
 -  and "line 65" implies "prev" points to the "last node" of just "reversed group"
 -  OR "first node" of the "orginal group"
 !  and "prev->next" points to the first node of following group(bcz of line 52)

*/
/*
-Time:O(N) [N + (N/k) * k]
-Space:O(1)
*/
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        //Edge case : Empty or singleton list
        if (head == nullptr || head->next == nullptr)
            return head;

        int len = 0;
        ListNode *cur = head;
        while (cur != nullptr)
        {
            len++;
            cur = cur->next;
        }

        ListNode *start = new ListNode(0, head);
        ListNode *prev;
        ListNode *nxt;
        prev = nxt = cur = start;

        //! initially, "prev-next" points to the first node of LL
        while (len >= k)
        {
            //*make "cur" point to first node of the group
            cur = prev->next;
            nxt = cur->next;

            //reverse 'k-1' links in the group of size k
            for (int i = 1; i <= k - 1; i++)
            {
                
                cur->next = nxt->next;

                //prev->next points to the previous "nxt" node
                nxt->next = prev->next;

                //updating prev->next for following iteration
                prev->next = nxt;

                nxt = cur->next;
            }
            //By the end of the loop'cur' points to the last node of orignal group
            //or first node of the just reversed group

            prev = cur; //make prev point to the last node of just reversed group
            len -= k;
        }

        return start->next;
    }
};
int main()
{

    return 0;
}