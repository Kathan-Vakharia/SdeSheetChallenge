#include <bits/stdc++.h>
#include "../linkedlist.h"
using namespace std;

/*
-Time:O(N) wher N:size of linkedlist
-Space:O(1)
*/
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        //! list is never empty

        //- initializing pointers
        ListNode *start = new ListNode();
        start->next = head;
        ListNode *fast = start;
        ListNode *slow = start;

        //make fast point to the nth node
        for (int i = 1; i <= n; i++)
        {
            fast = fast->next;
        }

        //move "slow" ahead untill "fast" points to the last node
        //i.e point "slow" to one node preceding the required node
        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        //deleting the nth node from end or n-k+1th node from begin
        ListNode *t = slow->next;
        slow->next = slow->next->next;
        delete t;

        return start->next;
    }
};
int main()
{

    return 0;
}