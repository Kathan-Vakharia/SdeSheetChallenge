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
    //note: Aim is to connect 'big' to it's correct link from back
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {

        //edge case: When any any one or both list is/are empty
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;

        //head pointer of the merged list
        ListNode *start = nullptr;
        ListNode *small = nullptr;
        ListNode *big = nullptr;
        if (l1->val <= l2->val)
        {
            start = l1;
            small = l1;
            big = l2;
        }
        else
        {
            start = l2;
            small = l2;
            big = l1;
        }

        //node pointing to preceding node of 'small'
        ListNode *sprev;
        while (big != nullptr)
        {

            sprev = nullptr;

            while (small != nullptr && small->val <= big->val)
            {
                sprev = small;
                small = small->next;
            }

            //connecting correct link to big (from back)
            sprev->next = big;

            //making sure "small" starts from smallest node
            //! when "small" is null => big's value will be null and main loop ends
            swap(small, big);
        }

        return start;
    }
};
int main()
{

    return 0;
}