/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-06-20 12:49:50
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-06-20 13:15:54
 */
#include "precompiled_headers.h"

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
        {
            return nullptr;
        }
        std::unordered_map<Node *, Node *> nodeMap;
        Node *old = head;
        Node *newHead = new Node(head->val);
        nodeMap[head] = newHead;
        Node *n = newHead;
        while (old)
        {
            if (old->random)
            {
                if (!nodeMap.count(old->random))
                {
                    n->random = new Node(old->random->val);
                    nodeMap[old->random] = n->random;
                }
                else
                {
                    n->random = nodeMap[old->random];
                }
            }
            if (old->next)
            {
                if (!nodeMap.count(old->next))
                {
                    n->next = new Node(old->next->val);
                    nodeMap[old->next] = n->next;
                }
                else
                {
                    n->next = nodeMap[old->next];
                }
            }
            old = old->next;
            n = n->next;
        }
        return newHead;
    }
};