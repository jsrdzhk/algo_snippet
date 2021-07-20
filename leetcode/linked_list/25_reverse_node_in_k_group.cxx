/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-07-14 09:39:52
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-14 10:08:12
 */
#include "precompiled_headers.h"

ListNode* reverseBetween(ListNode* a, ListNode* b) {
    if (!a || !b) {
        return nullptr;
    }
    ListNode* cur = a;
    ListNode *prev = nullptr, *next = a;
    while (cur != b) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head) {
        return head;
    }
    ListNode *a = head, *b = head;
    for (auto i = 0; i < k; ++i) {
        if (!b) {
            return head;
        }
        b = b->next;
    }
    ListNode* newHead = reverseBetween(a, b);
    a->next = reverseKGroup(b, k);
    return newHead;
}