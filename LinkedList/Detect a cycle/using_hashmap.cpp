#include <bits/stdc++.h>
#include "../linkedlist.h"
using namespace std;

/*
-Time:O(n)
-Space:O(n) for hashmap
*/
/* A note about 'count(Key)'
*Searches the container for elements whose value is k and returns 
*  the number of elements found
*Because unordered_set containers do not allow for duplicate keys,
*   this means that the function actually returns 1 if an element with 
*   that value exists in the container, and zero otherwise.
*/
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {

        unordered_set<ListNode *> nodes_seen;

        while (head != nullptr)
        {
            if (nodes_seen.count(head) > 0)
            {
                return true;
            }

            nodes_seen.insert(head);
            head = head->next;
        }
        return false;
    }
};
int main()
{

    return 0;
}