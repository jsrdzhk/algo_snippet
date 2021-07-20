/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-07-14 10:25:48
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-14 10:41:22
 */
#include "precompiled_headers.h"

ListNode* reverseBetween(ListNode* s, ListNode* e) {
    ListNode *cur = s, *next = s;
    ListNode* prev = nullptr;
    while (cur != e) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

bool isPalindrome(ListNode* head) {
    if (!head) {
        return false;
    }
    if (!head->next) {
        return true;
    }
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *s = nullptr, *e = nullptr;
    if (fast) {
        s = slow->next;
    } else {
        s = slow;
    }
    ListNode* newHead = reverseBetween(s, e);
    while (head && newHead) {
        if (head->val != newHead->val) {
            return false;
        } else {
            head = head->next;
            newHead = newHead->next;
        }
    }
    return true;
}