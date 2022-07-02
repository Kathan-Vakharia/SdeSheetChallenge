#include <bits/stdc++.h>
#include "../linkedlist.h"
using namespace std;

/*
-Time:O(n)
-Space:O(n)
*/
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {

        unordered_set<ListNode *> nodes_seen;

        while (head != nullptr)
        {

            //cycle found
            if (nodes_seen.count(head) > 0)
            {
                return head;
            }

            nodes_seen.insert(head);
            head = head->next;
        }

        //no cycle in the list
        return nullptr;
    }
};

int main()
{

    return 0;
}