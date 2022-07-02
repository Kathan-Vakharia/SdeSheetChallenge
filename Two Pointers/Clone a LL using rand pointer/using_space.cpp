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
-Space:O(n)
*/
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return nullptr;

        //HashMap
        unordered_map<Node *, Node *> mp;
        Node *cur = head;
        while (cur != nullptr)
        {
            mp[cur] = new Node(cur->val);
            cur = cur->next;
        }

        //creating a deep copy
        cur = head;
        while (cur != nullptr)
        {
            //* updating links of corresponding new nodes

            if (cur->next != nullptr)
                mp[cur]->next = mp[cur->next];
            if (cur->random != nullptr)
                mp[cur]->random = mp[cur->random];
            cur = cur->next;
        }
        return mp[head];
    }
};

int main()
{

    return 0;
}