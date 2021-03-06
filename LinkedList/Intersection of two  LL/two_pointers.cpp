#include <bits/stdc++.h>
#include "../linkedlist.h"
using namespace std;

/*
-Time:O(M+N)
-Space:O(1)
*/
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *pA = headA;
        ListNode *pB = headB;

        while (pA != pB)
        {

            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        // Note: In the case lists do not intersect, the pointers for A and B
        // will still line up in the 2nd iteration, just that here won't be
        // a common node down the list and both will reach their respective ends
        // at the same time. So pA will be NULL in that case.
        return pA; //or pB;
    }
};
int main()
{

    return 0;
}