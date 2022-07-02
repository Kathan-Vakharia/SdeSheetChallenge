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

        int k; // temporary variable
        int length = 0;
        ListNode *tmp = head;

        //- O(n)
        while (tmp != nullptr)
        {
            length++;
            tmp = tmp->next;
        }

        int mid = length / 2;


        //move a pointer to "mid+2"th if length is odd
        //                  "mid+1"th if length is even
        k = length % 2 == 0 ? mid : mid + 1;
        ListNode *moved = head;
        while (k > 0) //- O(n/2)
        {

            moved = moved->next;
            k--;
        }

        //reverse values till 'mid'th node
        ListNode *cur = head;
        ListNode *prev = nullptr;
        ListNode *nxt = nullptr;
        k = mid;
        while (k > 0) // -O(n/2)
        {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
            k--;
        }

        //start comparing values from both halves
        while (prev != nullptr && moved != nullptr) //-O(n/2)
        {
            if (prev->val != moved->val)
                return false;
            prev = prev->next;
            moved = moved->next;
        }
        return true;
    }
}

;
int main()
{

    return 0;
}