#include "../linkedlist.h"
#include <bits/stdc++.h>
using namespace std;

/*
-Time:O(n)
-Space:O(1)
*/

class Solution
{
public:
    void deleteNode(ListNode *cur)
    {

        //points to one one preceding "curr"
        ListNode *prev = nullptr;

        while (cur->next != nullptr)
        {
            prev = cur;
            cur->val = cur->next->val;
            cur = cur->next;
        }

        //break the link of repeated "tail" node
        prev->next = nullptr;
        delete cur;
    }
};
int main()
{

    return 0;
}