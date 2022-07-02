#include "../linkedlist.h"

/*
- Time:O(3n/2) = O(n)
- Space:O(1)
*/
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *temp = head;
        int count = 0;

        //- finding length of LL : O(n)
        while (temp)
        {
            count++;
            temp = temp->next;
        }

        //pointing temp to head again
        temp = head;
        int nodeNo = count / 2 + 1; //doesn't matter if count is odd or even

        //-Time: O(k-1)
        //If I want to reach kth node, I need to go k-1 deep
        for (int i = 1; i <= nodeNo - 1; i++)
        {

            temp = temp->next;
        }
        head = temp;
        return head;
    }
};