#include <bits/stdc++.h>
#include "../linkedlist.h"
using namespace std;

/*
-Time:O(n) : m (#non-loop-nodes steps + almost #cycle-nodes steps)
-Space:O(1)
*/

/* Intuition
* Let's say there's a cycle,
* Now let's say hare is one node behind tortoise,
 * Then it will definitely meet the tortoise in next iteration.
- Extending the above idea, if hare is 2 node behind, it will
 - catch up the tortoise after two iterations.
*/
class Solution
{
public:
    //* Floyd's Hare and Tortoise Algorithm
    bool hasCycle(ListNode *head)
    {
        ListNode *hare;
        ListNode *tortoise;
        hare = tortoise = head;

        while (tortoise != nullptr && hare != nullptr && hare->next != nullptr)
        {

            tortoise = tortoise->next;
            hare = hare->next->next;

            //! Order matters: since both will be equal to head in first iteration
            if (tortoise == hare)
                return true;
        }
        return false;
    }
};
int main()
{

    return 0;
}