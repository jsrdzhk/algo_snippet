/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-06-12 07:21:47
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-06-12 08:01:07
 */
#include "precompiled_headers.h"

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        std::vector<ListNode *> nodeVec;
        ListNode *l1Current = l1;
        ListNode *l2Current = l2;
        while (l1Current || l2Current)
        {
            if (l1Current == nullptr)
            {
                if (l2Current)
                {
                    nodeVec.push_back(l2Current);
                    l2Current = l2Current->next;
                }
            }
            else if (l2Current == nullptr)
            {
                if(l1Current){
                    nodeVec.push_back(l1Current);
                    l1Current=l1Current->next;
                }
            }
            else if (l1Current->val > l2Current->val)
            {
                nodeVec.push_back(l2Current);
                l2Current=l2Current->next;
            }
            else
            {
                nodeVec.push_back(l1Current);
                l1Current=l1Current->next;
            }
        }
        return nodeMerge(nodeVec);
    }

private:
    ListNode *nodeMerge(const std::vector<ListNode *> &nodeVec)
    {
        if (nodeVec.empty())
        {
            return nullptr;
        }
        ListNode *head = nodeVec[0];
        ListNode *cur = head;
        for (int i = 1; i < nodeVec.size(); ++i)
        {
            cur->next = nodeVec[i];
            cur = cur->next;
        }
        return head;
    }
};