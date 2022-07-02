#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
/*
-Time:O(n)
-Space:O(1)
*/
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return head;

        //Step1: Associate original nodes with new copied nodes
        //? Otherwise we have no way to update random of copied nodes
        Node *cur = head;
        Node *nex = nullptr;
        while (cur != nullptr)
        {
            nex = cur->next;
            cur->next = new Node(cur->val);
            cur->next->next = nex;
            //move "cur" to next node in "original" list
            cur = nex;
        }

        //Step2: Update "random" pointers of copied nodes
        cur = head;
        while (cur != nullptr)
        {
            //! "cur->next" always exist when cur!=nullptr
            nex = cur->next->next;
            //updating copy's random
            if (cur->random != nullptr)
                cur->next->random = cur->random->next;
            //move "cur" to next node in "original" list
            cur = nex;
        }
        //Head of new copied list
        Node *nHead = head->next;

        //Step3: Update "next" links of both lists
        cur = head;
        while (cur != nullptr)
        {
            nex = cur->next->next;
            //update copy node's link if it isn't "tail"
            if (nex != nullptr)
                cur->next->next = nex->next;
            cur->next = nex;
            //move "cur" to next node in "original" list
            cur = nex;
        }

        return nHead;
    }
};

int main()
{

    return 0;
}