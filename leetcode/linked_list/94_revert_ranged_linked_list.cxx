/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-07-13 10:00:02
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-13 10:45:42
 */
#include "precompiled_headers.h"

ListNode* reverseBetweenImpl(ListNode* head, int left, int right, int idx,
                             ListNode* preHead, ListNode* postHead) {
    if (idx == left - 1) {
        preHead = head;
        head->next->next = preHead;
    } else if (idx == right) {
        postHead = head->next;
        return head;
    }
    ListNode* last =
        reverseBetweenImpl(head->next, left, right, idx + 1, preHead, postHead);
    head->next->next = head;
    head->next = postHead;
    if (!preHead) {
        return last;
    } else {
        return head;
    }
}

ListNode* reversePrevN(ListNode* head, ListNode* postHead, int n) {
    if (n == 1) {
        postHead = head->next;
        return head;
    }
    ListNode* last = reversePrevN(head->next, postHead, n - 1);
    head->next->next = head;
    head->next = postHead;
    return last;
}

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* postHead = nullptr;
    if (left == 1) {
        return reversePrevN(head, postHead, right);
    }
    head->next = reverseBetween(head->next, left - 1, right - 1);
    return head;
}