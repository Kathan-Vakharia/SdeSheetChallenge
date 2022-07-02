#include <bits/stdc++.h>
#include "../linkedlist.h"
using namespace std;

/*
-Time:O(n)
-Space:O(1)
*/
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head; //tortoise
        ListNode *fast = head; //hare
        ListNode *entry = head;

        while (slow != nullptr && //list empty
               fast != nullptr && 
               fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            //cycle found
            if (slow == fast)
            {
                //find entry of the cyle
                while (entry != slow)
                {
                    entry = entry->next;
                    slow = slow->next;
                }

                return slow;
            }
        }

        //if cycle not found
        return nullptr;
    }
};
int main()
{

    return 0;
}