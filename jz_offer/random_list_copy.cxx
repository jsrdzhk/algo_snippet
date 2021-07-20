/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-06-20 12:49:50
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-15 09:30:54
 */
#include "precompiled_headers.h"

class Solution
{
public:
    RandomNode *copyRandomList(RandomNode *head)
    {
        if (!head)
        {
            return nullptr;
        }
        std::unordered_map<RandomNode *, RandomNode *> nodeMap;
        RandomNode *old = head;
        RandomNode *newHead = new RandomNode(head->val);
        nodeMap[head] = newHead;
        RandomNode *n = newHead;
        while (old)
        {
            if (old->random)
            {
                if (!nodeMap.count(old->random))
                {
                    n->random = new RandomNode(old->random->val);
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
                    n->next = new RandomNode(old->next->val);
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