#include <bits/stdc++.h>
#include "../linkedlist.h"
using namespace std;

/*
-Time:O(1)
-Space:O(1)
*/
class Solution
{
public:
    //! given node isn't the "tail" node
    void deleteNode(ListNode *node)
    {
        ListNode *temp = node->next;

        //I can do this only because node isn't the tail node
        //and "node->next" will not null therefore
        node->val = node->next->val;
        node->next = node->next->next;

        delete temp;
    }
};
int main()
{
    
    return 0;
}