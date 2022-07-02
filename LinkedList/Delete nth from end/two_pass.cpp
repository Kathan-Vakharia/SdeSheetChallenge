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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        //- if LL is empty
        if (!head)
            return head;

        //note: first pass : O(n)
        //- getting length of LL 
        int cnt = 0;
        ListNode *temp = head;
        while (temp)
        {
            cnt++;
            temp = temp->next;
        }

        //* Standard Procedure to delete (k+1)th node from beginning
        
        //note: Required Node: (cnt - n +1)th node
        //note: we have to go "cnt-n" times deep to stand at required node
        int k = cnt - n;
        ListNode *cur = head;
        ListNode *prev = nullptr; //it will point one node preceding to cur

        //note: second pass :O(n)
        while (k > 0)
        {
            prev = cur;
            cur = cur->next;
            k--;
        }

        //- first node of the LL is to be deleted
        if (!prev)
        {
            temp = cur;
            cur = cur->next;
            delete temp;
            head = cur; //! cur is the new head
        }
        else
        {
            prev->next = cur->next;
            delete cur;
        }
        return head;
    }
};
int main()
{

    return 0;
}