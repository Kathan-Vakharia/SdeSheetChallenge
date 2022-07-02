#include <bits/stdc++.h>
#include "../linkedlist.h"
using namespace std;

/*
-Time:O(n)
-Space:O(n)
*/
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> values;
        ListNode *tmp = head;

        //storing node values
        while (tmp)
        {
            values.push_back(tmp->val);
            tmp = tmp->next;
        }

        int last_index = values.size() - 1;
        tmp = head;

        //-comparing first with last
        // -         second with second last
        // -         third with third last and so on..
        while (tmp)
        {

            if (tmp->val != values[last_index])
                return false;

            //update index and tmp
            last_index--;
            tmp = tmp->next;
        }

        return true;
    }
};
int main()
{

    return 0;
}