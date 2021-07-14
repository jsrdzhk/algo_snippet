/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "precompiled_headers.h"
class Solution
{
public:
    ListNode *deleteNode(ListNode *head, int val)
    {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cur->next)
        {
            if (cur->val != val)
            {
                prev = cur;
                cur = cur->next;
            }
            else
            {
                //delete node is head
                if (prev == nullptr)
                {
                    head = cur->next;
                    cur->next = nullptr;
                }
                else if (cur->next == nullptr)
                {
                    prev->next = nullptr;
                }
                else
                {
                    prev->next = cur->next;
                    cur->next = nullptr;
                }
                return head;
            }
        }
    }
};