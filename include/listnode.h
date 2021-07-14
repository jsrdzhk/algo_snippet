/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-06-12 07:25:46
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-13 09:07:12
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};