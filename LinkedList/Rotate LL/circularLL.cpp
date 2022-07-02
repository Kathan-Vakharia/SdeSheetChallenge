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
    ListNode *rotateRight(ListNode *head, int k)
    {

        if (head == nullptr || head->next == nullptr)
            return head;

        //*Find Length : O(n)
        int len = 0;
        ListNode *t = head;
        while (t != nullptr)
        {
            len++;
            t = t->next;
        }

        //rounding down k
        k = k % len;
        if (k == 0) //return the same list
            return head;

        //*make last node point to the first : O(n)
        t = head;
        while (t->next != nullptr)
            t = t->next;
        t->next = head;

        //*move 't' "len - k" steps ahead : O(n-k)
        //i.e. make t point to a node preceding "k" nodes
        for (int i = 1; i <= len - k; i++)
            t = t->next;

        //updating head
        head = t->next;
        t->next = nullptr;

        return head;
    }
};

int main()
{

    return 0;
}