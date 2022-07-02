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
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        //-O(n/2)
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        //reverse the list from slow till end
        ListNode *prev = nullptr;
        ListNode *nxt = nullptr;
        while (slow != nullptr) //- O(n/2)
        {
            nxt = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nxt;
        }
        //note: now 'prev' points to the first node of right reversed half

        while (prev != nullptr) //- O(n/2)
        {
            if (head->val != prev->val)
                return false;
            head = head->next;
            prev = prev->next;
        }
        return true;
    }
}

;
int main()
{

    return 0;
}