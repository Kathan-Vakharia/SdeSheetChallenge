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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *fast;
        ListNode *slow;
        fast = slow = head;

        //make fast reach the end of the list by moving it double time the slow
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        //* now slow will point to the required node

        return slow;
    }
};
int main()
{

    return 0;
}