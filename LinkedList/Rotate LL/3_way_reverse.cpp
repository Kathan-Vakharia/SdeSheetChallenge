#include <bits/stdc++.h>
#include "../linkedlist.h"
using namespace std;

/*
-Time:O(n) [n + n + k + n-k]
-Space:O(1)
*/
class Solution
{
public:
    ListNode *reverse(ListNode *cur)
    {
        ListNode *prev = nullptr;
        ListNode *nxt = nullptr;

        while (cur)
        {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }

        return prev;
    }
    ListNode *reverseK(ListNode *cur, int k)
    {
        ListNode *prev = nullptr;
        ListNode *nxt = nullptr;

        for (int i = 1; i <= k; i++)
        {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
    int lengthLL(ListNode *head)
    {
        int l = 0;
        while (head != nullptr)
        {
            head = head->next;
            l++;
        }
        return l;
    }
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        int length = lengthLL(head);

        k = k % length; //rounding down k
        if (k == 0)     // => list doesn't change
            return head;

        // I will need this pointer to connect two reversed parts in following steps
        ListNode *rhead = reverse(head);

        //get a pointer to "k+1" node
        ListNode *t = rhead;
        for (int i = 1; i <= k; i++)
        {
            t = t->next;
        }

        ListNode *left_half = reverseK(rhead, k);
        ListNode *right_half = reverseK(t, length - k);
        rhead->next = right_half; //connecting two reversed parts

        return left_half;
    }
};

int main()
{

    return 0;
}