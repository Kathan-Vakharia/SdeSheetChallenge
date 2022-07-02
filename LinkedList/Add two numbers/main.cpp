#include <bits/stdc++.h>
#include "../linkedlist.h"
using namespace std;

/*
-Time:O(max(n1, n2))
-Space:O(max(n1,n2) + 1)
*/
class Solution
{
public:
    //! Here we have to return the reversed list only
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *start = new ListNode();
        ListNode *temp = start;

        //starting carry is zero
        int carry = 0;

        //go through both lists and create a new node untill
        //nodes exist in any of the lists or carry is 1
        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {

            int sum = 0;

            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            sum = sum + carry;
            carry = sum / 10; //updating carry for next digit sum

            //note: We take modulo with 10
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }

        return start->next;
    }
};

int main()
{

    return 0;
}