#include "precompiled_headers.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
private:
    std::stack<ListNode *> nodeStack;

public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        for (; head; head = head->next)
        {
            nodeStack.push(head);
        }
        ListNode *new_head = nodeStack.top();
        for (ListNode *node = new_head; !nodeStack.empty(); node = nodeStack.top())
        {
            nodeStack.pop();
            if (nodeStack.empty())
            {
                node->next = nullptr;
                break;
            }
            else
            {
                node->next = nodeStack.top();
            }
            node = node->next;
        }
        return new_head;
    }
};