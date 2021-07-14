/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-07-13 09:09:23
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-13 09:54:38
 */
#include "precompiled_headers.h"

ListNode* iterationReverseList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* prev = nullptr;
    while (head) {
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return head;
}

void traverse(ListNode* prev, ListNode* cur, ListNode*& head) {
    if (!cur) {
        head = prev;
        return;
    }
    traverse(cur, cur->next, head);
    cur->next = prev;
}

ListNode* recursiveReverseList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* last = recursiveReverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return last;
}