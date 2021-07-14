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
public:
    ListNode *getKthFromEnd(ListNode *head, int k)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        std::unordered_map<int, ListNode *> listNodeMap;
        int i = 0;
        while (true)
        {
            listNodeMap[i] = head;
            head = head->next;
            if (head == nullptr)
            {
                break;
            }
            ++i;
        }
        int totoalNodeNum = listNodeMap.size();
        if (k > totoalNodeNum)
        {
            return nullptr;
        }
        else
        {
            return listNodeMap[totoalNodeNum - k];
        }
    }
};