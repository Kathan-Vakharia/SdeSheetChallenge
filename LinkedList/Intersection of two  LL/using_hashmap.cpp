#include <bits/stdc++.h>
#include "../linkedlist.h"
using namespace std;

/*
-Time:O(max(m,n))
-Space:O(m+n)
*/
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_map<ListNode *, int> seen;

        while (headA != nullptr || headB != nullptr)
        {

            if (headA != nullptr)
            {
                if (seen.count(headA) > 0)
                    return headA;

                seen[headA] = headA->val;
                headA = headA->next;
            }

            if (headB != nullptr)
            {
                if (seen.count(headB) > 0)
                    return headB;

                seen[headB] = headB->val;
                headB = headB->next;
            }
        }

        //if no intersection point
        return nullptr;
    }
};
int main()
{

    return 0;
}